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
struct AudioFrame_R001305_513_0
{
  unsigned char channels;
  int gain;
  short peak;
  int buffer[3];
};
struct FilterState_R001305_513_1
{
  int prev_out;
  short cutoff;
  short damping;
  unsigned char gain_db;
  unsigned char mode;
  int prev_in;
  int buffer[3];
};
struct StreamBuffer_R001305_513_2
{
  int capacity;
  short checksum;
  short head;
  unsigned char tail;
  unsigned char state;
  int watermark;
  int buffer[3];
};
union TelemetryField_R001305_513_0
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
void fn_R001305_513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 49)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 49)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_47_1 = 0;
  int stride_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_47_1 = ((stride_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_47_2 = ((stride_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_47_1) & 127;
    acc_2 = (acc_2 + stride_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_31_1 == stride_31_2);
  assert(stride_47_1 == stride_47_2);
}

int fn_R001305_513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 49)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  int stride_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_47 = ((stride_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001305_513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st_1 = {0};
  struct StreamBuffer_R001305_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_92_1 > 32)
  {
    acc_1 = ((acc_1 + (mask_92_1 * 2)) + 5) & 127;
    aux_1 ^= mask_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_92_2 > 32)
  {
    acc_2 = ((acc_2 + (mask_92_2 * 2)) + 5) & 127;
    aux_2 ^= mask_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_72_1 = 0;
  int factor_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_72_1 = ((factor_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_72_2 = ((factor_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_72_1) & 127;
    acc_2 = (acc_2 + factor_72_2) & 127;
  }

  int window_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_76_1)
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

  switch (window_76_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_92_1 == mask_92_2);
  assert(factor_72_1 == factor_72_2);
  assert(window_76_1 == window_76_2);
}

int fn_R001305_513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_92 > 32)
  {
    acc = ((acc + (mask_92 * 2)) + 5) & 127;
    aux ^= mask_92 & 15;
  }
  else
  {
    acc = ((acc - mask_92) + 11) & 127;
    aux += 3;
  }
  int factor_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_72 = ((factor_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_72) & 127;
  }

  int window_76 = (aux + st.buffer[1]) & 3;
  switch (window_76)
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

void fn_R001305_513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st_1 = {0};
  struct StreamBuffer_R001305_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_99_1 = local_arr_1[aux_1 % 3];
  int vector_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_99_2 * 2)) & 127;
  int pivot_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_59_1) & 63;
  aux_2 = (aux_2 + pivot_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_99_1 == vector_99_2);
  assert(pivot_59_1 == pivot_59_2);
}

int fn_R001305_513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int vector_99 = local_arr[aux % 3];
  acc = (acc + (vector_99 * 2)) & 127;
  int pivot_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001305_513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st_1 = {0};
  struct FilterState_R001305_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_69_1 = local_arr_1[aux_1 % 3];
  int margin_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_69_2 * 2)) & 127;
  int quantum_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_23_1) & 63;
  aux_2 = (aux_2 + quantum_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_12_1 = 0;
  int index_reg_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_12_1 = ((index_reg_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_12_2 = ((index_reg_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_12_1) & 127;
    acc_2 = (acc_2 + index_reg_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_69_1 == margin_69_2);
  assert(quantum_23_1 == quantum_23_2);
  assert(index_reg_12_1 == index_reg_12_2);
}

int fn_R001305_513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int margin_69 = local_arr[aux % 3];
  acc = (acc + (margin_69 * 2)) & 127;
  int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_23) & 63;
  acc ^= aux;
  int index_reg_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_12 = ((index_reg_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001305_513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_91_1 = local_arr_1[aux_1 % 3];
  int sample_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_91_2 * 2)) & 127;
  int bound_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_71_1) & 63;
  aux_2 = (aux_2 + bound_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_74_1 = 0;
  int phase_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_74_1 = ((phase_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_74_2 = ((phase_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_74_1) & 127;
    acc_2 = (acc_2 + phase_74_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_91_1 == sample_91_2);
  assert(bound_71_1 == bound_71_2);
  assert(phase_74_1 == phase_74_2);
}

int fn_R001305_513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int sample_91 = local_arr[aux % 3];
  acc = (acc + (sample_91 * 2)) & 127;
  int bound_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_71) & 63;
  acc ^= aux;
  int phase_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_74 = ((phase_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_74) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001305_513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st_1 = {0};
  struct StreamBuffer_R001305_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_33_1) & 63;
  aux_2 = (aux_2 + segment_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_53_1)
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

  switch (quantum_53_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_33_1 == segment_33_2);
  assert(quantum_53_1 == quantum_53_2);
}

int fn_R001305_513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_33) & 63;
  acc ^= aux;
  int quantum_53 = (aux + st.buffer[1]) & 3;
  switch (quantum_53)
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

void fn_R001305_513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int pivot_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_58_1)
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

  switch (pivot_58_2)
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

  int phase_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_72_1 > 18)
  {
    acc_1 = ((acc_1 + (phase_72_1 * 2)) + 5) & 127;
    aux_1 ^= phase_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_72_2 > 18)
  {
    acc_2 = ((acc_2 + (phase_72_2 * 2)) + 5) & 127;
    aux_2 ^= phase_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_73_1 = local_arr_1[aux_1 % 3];
  int index_reg_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_58_1 == pivot_58_2);
  assert(phase_72_1 == phase_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_73_1 == index_reg_73_2);
}

int fn_R001305_513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int pivot_58 = (aux + st.buffer[1]) & 3;
  switch (pivot_58)
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

  int phase_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_72 > 18)
  {
    acc = ((acc + (phase_72 * 2)) + 5) & 127;
    aux ^= phase_72 & 15;
  }
  else
  {
    acc = ((acc - phase_72) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_73 = local_arr[aux % 3];
  acc = (acc + (index_reg_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001305_513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_19_1 > 22)
  {
    acc_1 = ((acc_1 + (quotient_19_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_19_2 > 22)
  {
    acc_2 = ((acc_2 + (quotient_19_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_51_1 = local_arr_1[aux_1 % 3];
  int vector_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_19_1 == quotient_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_51_1 == vector_51_2);
}

int fn_R001305_513_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_19 > 22)
  {
    acc = ((acc + (quotient_19 * 2)) + 5) & 127;
    aux ^= quotient_19 & 15;
  }
  else
  {
    acc = ((acc - quotient_19) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_51 = local_arr[aux % 3];
  acc = (acc + (vector_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001305_513_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st_1 = {0};
  struct StreamBuffer_R001305_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_19_1)
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

  switch (weight_19_2)
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
  int quotient_46_1 = local_arr_1[aux_1 % 3];
  int quotient_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_46_2 * 2)) & 127;
  int checksum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_60_1) & 63;
  aux_2 = (aux_2 + checksum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_19_1 == weight_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_46_1 == quotient_46_2);
  assert(checksum_60_1 == checksum_60_2);
}

int fn_R001305_513_8(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_19 = (aux + st.buffer[1]) & 3;
  switch (weight_19)
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
  int quotient_46 = local_arr[aux % 3];
  acc = (acc + (quotient_46 * 2)) & 127;
  int checksum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001305_513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quotient_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_70_1)
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

  switch (quotient_70_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_28_1 = 0;
  int anchor_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_28_1 = ((anchor_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_28_2 = ((anchor_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_28_1) & 127;
    acc_2 = (acc_2 + anchor_28_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_90_1 = local_arr_1[aux_1 % 3];
  int quantum_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_70_1 == quotient_70_2);
  assert(anchor_28_1 == anchor_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_90_1 == quantum_90_2);
}

int fn_R001305_513_9(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quotient_70 = (aux + st.buffer[1]) & 3;
  switch (quotient_70)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_28 = ((anchor_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_28) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quantum_90 = local_arr[aux % 3];
  acc = (acc + (quantum_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001305_513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  int residue_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_82_1) & 63;
  aux_2 = (aux_2 + residue_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_65_1)
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

  switch (index_reg_65_2)
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

  int delta_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_30_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_30_1 * 2)) + 5) & 127;
    aux_1 ^= delta_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_30_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_30_2 * 2)) + 5) & 127;
    aux_2 ^= delta_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(residue_82_1 == residue_82_2);
  assert(index_reg_65_1 == index_reg_65_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R001305_513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  int residue_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_82) & 63;
  acc ^= aux;
  int index_reg_65 = (aux + st.buffer[1]) & 3;
  switch (index_reg_65)
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

  int delta_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_30 > 26)
  {
    acc = ((acc + (delta_30 * 2)) + 5) & 127;
    aux ^= delta_30 & 15;
  }
  else
  {
    acc = ((acc - delta_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001305_513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st_1 = {0};
  struct FilterState_R001305_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int accumulator_50_1 = 0;
  int accumulator_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_50_1 = ((accumulator_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_50_2 = ((accumulator_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_50_1) & 127;
    acc_2 = (acc_2 + accumulator_50_2) & 127;
  }

  int sample_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_89_1)
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

  switch (sample_89_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_50_1 == accumulator_50_2);
  assert(sample_89_1 == sample_89_2);
}

int fn_R001305_513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int accumulator_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_50 = ((accumulator_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_50) & 127;
  }

  int sample_89 = (aux + st.buffer[1]) & 3;
  switch (sample_89)
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

void fn_R001305_513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st_1 = {0};
  struct FilterState_R001305_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_58_1)
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

  switch (offset_58_2)
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

  int mask_75_1 = 0;
  int mask_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_75_1 = ((mask_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_75_2 = ((mask_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_75_1) & 127;
    acc_2 = (acc_2 + mask_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_58_1 == offset_58_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R001305_513_12(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001305_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_58 = (aux + st.buffer[1]) & 3;
  switch (offset_58)
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

  int mask_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_75 = ((mask_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001305_513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st_1 = {0};
  struct AudioFrame_R001305_513_0 st_2 = {0};
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
  int tracker_50_1 = 0;
  int tracker_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_50_1 = ((tracker_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_50_2 = ((tracker_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_50_1) & 127;
    acc_2 = (acc_2 + tracker_50_2) & 127;
  }

  int residue_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_64_1 > 19)
  {
    acc_1 = ((acc_1 + (residue_64_1 * 2)) + 5) & 127;
    aux_1 ^= residue_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_64_2 > 19)
  {
    acc_2 = ((acc_2 + (residue_64_2 * 2)) + 5) & 127;
    aux_2 ^= residue_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_50_1 == tracker_50_2);
  assert(residue_64_1 == residue_64_2);
}

int fn_R001305_513_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001305_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_50 = ((tracker_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_50) & 127;
  }

  int residue_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_64 > 19)
  {
    acc = ((acc + (residue_64 * 2)) + 5) & 127;
    aux ^= residue_64 & 15;
  }
  else
  {
    acc = ((acc - residue_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001305_513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st_1 = {0};
  struct StreamBuffer_R001305_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_75_1 = 0;
  int weight_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_75_1 = ((weight_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_75_2 = ((weight_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_75_1) & 127;
    acc_2 = (acc_2 + weight_75_2) & 127;
  }

  int delta_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_30_1 > 30)
  {
    acc_1 = ((acc_1 + (delta_30_1 * 2)) + 5) & 127;
    aux_1 ^= delta_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_30_2 > 30)
  {
    acc_2 = ((acc_2 + (delta_30_2 * 2)) + 5) & 127;
    aux_2 ^= delta_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R001305_513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001305_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_75 = ((weight_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_75) & 127;
  }

  int delta_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_30 > 30)
  {
    acc = ((acc + (delta_30 * 2)) + 5) & 127;
    aux ^= delta_30 & 15;
  }
  else
  {
    acc = ((acc - delta_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001305_0_1;
  int sec_r001305_0_2;
  int sec_r001305_1_1;
  int sec_r001305_1_2;
  int sec_r001305_2_1;
  int sec_r001305_2_2;
  int sec_r001305_3_1;
  int sec_r001305_3_2;
  int sec_r001305_4_1;
  int sec_r001305_4_2;
  int sec_r001305_5_1;
  int sec_r001305_5_2;
  int sec_r001305_6_1;
  int sec_r001305_6_2;
  int sec_r001305_7_1;
  int sec_r001305_7_2;
  int sec_r001305_8_1;
  int sec_r001305_8_2;
  int sec_r001305_9_1;
  int sec_r001305_9_2;
  int sec_r001305_10_1;
  int sec_r001305_10_2;
  int sec_r001305_11_1;
  int sec_r001305_11_2;
  int sec_r001305_12_1;
  int sec_r001305_12_2;
  int sec_r001305_13_1;
  int sec_r001305_13_2;
  int sec_r001305_14_1;
  int sec_r001305_14_2;
  int sec_r001305_15_1;
  int sec_r001305_15_2;
  int sec_r001305_16_1;
  int sec_r001305_16_2;
  int sec_r001305_17_1;
  int sec_r001305_17_2;
  int sec_r001305_18_1;
  int sec_r001305_18_2;
  int pub_r001305_0_1;
  int pub_r001305_0_2;
  int pub_r001305_1_1;
  int pub_r001305_1_2;
  int pub_r001305_2_1;
  int pub_r001305_2_2;
  int pub_r001305_3_1;
  int pub_r001305_3_2;
  int pub_r001305_4_1;
  int pub_r001305_4_2;
  int pub_r001305_5_1;
  int pub_r001305_5_2;
  int pub_r001305_6_1;
  int pub_r001305_6_2;
  int pub_r001305_7_1;
  int pub_r001305_7_2;
  int pub_r001305_8_1;
  int pub_r001305_8_2;
  int pub_r001305_9_1;
  int pub_r001305_9_2;
  int pub_r001305_10_1;
  int pub_r001305_10_2;
  int pub_r001305_11_1;
  int pub_r001305_11_2;
  int pub_r001305_12_1;
  int pub_r001305_12_2;
  int pub_r001305_13_1;
  int pub_r001305_13_2;
  int pub_r001305_14_1;
  int pub_r001305_14_2;
  int pub_r001305_15_1;
  int pub_r001305_15_2;
  int pub_r001305_16_1;
  int pub_r001305_16_2;
  int pub_r001305_17_1;
  int pub_r001305_17_2;
  int pub_r001305_18_1;
  int pub_r001305_18_2;
  int pub_r001305_19_1;
  int pub_r001305_19_2;
  int pub_r001305_20_1;
  int pub_r001305_20_2;
  int pub_r001305_21_1;
  int pub_r001305_21_2;
  int pub_r001305_22_1;
  int pub_r001305_22_2;
  int pub_r001305_23_1;
  int pub_r001305_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001305_0_1 >= (-100)) && (pub_r001305_0_1 <= 100));
  __CPROVER_assume((pub_r001305_0_2 >= (-100)) && (pub_r001305_0_2 <= 100));
  __CPROVER_assume((pub_r001305_1_1 >= (-100)) && (pub_r001305_1_1 <= 100));
  __CPROVER_assume((pub_r001305_1_2 >= (-100)) && (pub_r001305_1_2 <= 100));
  __CPROVER_assume((pub_r001305_2_1 >= (-100)) && (pub_r001305_2_1 <= 100));
  __CPROVER_assume((pub_r001305_2_2 >= (-100)) && (pub_r001305_2_2 <= 100));
  __CPROVER_assume((pub_r001305_3_1 >= (-100)) && (pub_r001305_3_1 <= 100));
  __CPROVER_assume((pub_r001305_3_2 >= (-100)) && (pub_r001305_3_2 <= 100));
  __CPROVER_assume((pub_r001305_4_1 >= (-100)) && (pub_r001305_4_1 <= 100));
  __CPROVER_assume((pub_r001305_4_2 >= (-100)) && (pub_r001305_4_2 <= 100));
  __CPROVER_assume((pub_r001305_5_1 >= (-100)) && (pub_r001305_5_1 <= 100));
  __CPROVER_assume((pub_r001305_5_2 >= (-100)) && (pub_r001305_5_2 <= 100));
  __CPROVER_assume((pub_r001305_6_1 >= (-100)) && (pub_r001305_6_1 <= 100));
  __CPROVER_assume((pub_r001305_6_2 >= (-100)) && (pub_r001305_6_2 <= 100));
  __CPROVER_assume((pub_r001305_7_1 >= (-100)) && (pub_r001305_7_1 <= 100));
  __CPROVER_assume((pub_r001305_7_2 >= (-100)) && (pub_r001305_7_2 <= 100));
  __CPROVER_assume((pub_r001305_8_1 >= (-100)) && (pub_r001305_8_1 <= 100));
  __CPROVER_assume((pub_r001305_8_2 >= (-100)) && (pub_r001305_8_2 <= 100));
  __CPROVER_assume((pub_r001305_9_1 >= (-100)) && (pub_r001305_9_1 <= 100));
  __CPROVER_assume((pub_r001305_9_2 >= (-100)) && (pub_r001305_9_2 <= 100));
  __CPROVER_assume((pub_r001305_10_1 >= (-100)) && (pub_r001305_10_1 <= 100));
  __CPROVER_assume((pub_r001305_10_2 >= (-100)) && (pub_r001305_10_2 <= 100));
  __CPROVER_assume((pub_r001305_11_1 >= (-100)) && (pub_r001305_11_1 <= 100));
  __CPROVER_assume((pub_r001305_11_2 >= (-100)) && (pub_r001305_11_2 <= 100));
  __CPROVER_assume((pub_r001305_12_1 >= (-100)) && (pub_r001305_12_1 <= 100));
  __CPROVER_assume((pub_r001305_12_2 >= (-100)) && (pub_r001305_12_2 <= 100));
  __CPROVER_assume((pub_r001305_13_1 >= (-100)) && (pub_r001305_13_1 <= 100));
  __CPROVER_assume((pub_r001305_13_2 >= (-100)) && (pub_r001305_13_2 <= 100));
  __CPROVER_assume((pub_r001305_14_1 >= (-100)) && (pub_r001305_14_1 <= 100));
  __CPROVER_assume((pub_r001305_14_2 >= (-100)) && (pub_r001305_14_2 <= 100));
  __CPROVER_assume((pub_r001305_15_1 >= (-100)) && (pub_r001305_15_1 <= 100));
  __CPROVER_assume((pub_r001305_15_2 >= (-100)) && (pub_r001305_15_2 <= 100));
  __CPROVER_assume((pub_r001305_16_1 >= (-100)) && (pub_r001305_16_1 <= 100));
  __CPROVER_assume((pub_r001305_16_2 >= (-100)) && (pub_r001305_16_2 <= 100));
  __CPROVER_assume((pub_r001305_17_1 >= (-100)) && (pub_r001305_17_1 <= 100));
  __CPROVER_assume((pub_r001305_17_2 >= (-100)) && (pub_r001305_17_2 <= 100));
  __CPROVER_assume((pub_r001305_18_1 >= (-100)) && (pub_r001305_18_1 <= 100));
  __CPROVER_assume((pub_r001305_18_2 >= (-100)) && (pub_r001305_18_2 <= 100));
  __CPROVER_assume((pub_r001305_19_1 >= (-100)) && (pub_r001305_19_1 <= 100));
  __CPROVER_assume((pub_r001305_19_2 >= (-100)) && (pub_r001305_19_2 <= 100));
  __CPROVER_assume((pub_r001305_20_1 >= (-100)) && (pub_r001305_20_1 <= 100));
  __CPROVER_assume((pub_r001305_20_2 >= (-100)) && (pub_r001305_20_2 <= 100));
  __CPROVER_assume((pub_r001305_21_1 >= (-100)) && (pub_r001305_21_1 <= 100));
  __CPROVER_assume((pub_r001305_21_2 >= (-100)) && (pub_r001305_21_2 <= 100));
  __CPROVER_assume((pub_r001305_22_1 >= (-100)) && (pub_r001305_22_1 <= 100));
  __CPROVER_assume((pub_r001305_22_2 >= (-100)) && (pub_r001305_22_2 <= 100));
  __CPROVER_assume((pub_r001305_23_1 >= (-100)) && (pub_r001305_23_1 <= 100));
  __CPROVER_assume((pub_r001305_23_2 >= (-100)) && (pub_r001305_23_2 <= 100));
  __CPROVER_assume((sec_r001305_0_1 >= 0) && (sec_r001305_0_1 <= 255));
  __CPROVER_assume((sec_r001305_0_2 >= 0) && (sec_r001305_0_2 <= 255));
  __CPROVER_assume((sec_r001305_1_1 >= 0) && (sec_r001305_1_1 <= 255));
  __CPROVER_assume((sec_r001305_1_2 >= 0) && (sec_r001305_1_2 <= 255));
  __CPROVER_assume((sec_r001305_2_1 >= 0) && (sec_r001305_2_1 <= 255));
  __CPROVER_assume((sec_r001305_2_2 >= 0) && (sec_r001305_2_2 <= 255));
  __CPROVER_assume((sec_r001305_3_1 >= 0) && (sec_r001305_3_1 <= 255));
  __CPROVER_assume((sec_r001305_3_2 >= 0) && (sec_r001305_3_2 <= 255));
  __CPROVER_assume((sec_r001305_4_1 >= 0) && (sec_r001305_4_1 <= 255));
  __CPROVER_assume((sec_r001305_4_2 >= 0) && (sec_r001305_4_2 <= 255));
  __CPROVER_assume((sec_r001305_5_1 >= 0) && (sec_r001305_5_1 <= 255));
  __CPROVER_assume((sec_r001305_5_2 >= 0) && (sec_r001305_5_2 <= 255));
  __CPROVER_assume((sec_r001305_6_1 >= 0) && (sec_r001305_6_1 <= 255));
  __CPROVER_assume((sec_r001305_6_2 >= 0) && (sec_r001305_6_2 <= 255));
  __CPROVER_assume((sec_r001305_7_1 >= 0) && (sec_r001305_7_1 <= 255));
  __CPROVER_assume((sec_r001305_7_2 >= 0) && (sec_r001305_7_2 <= 255));
  __CPROVER_assume((sec_r001305_8_1 >= 0) && (sec_r001305_8_1 <= 255));
  __CPROVER_assume((sec_r001305_8_2 >= 0) && (sec_r001305_8_2 <= 255));
  __CPROVER_assume((sec_r001305_9_1 >= 0) && (sec_r001305_9_1 <= 255));
  __CPROVER_assume((sec_r001305_9_2 >= 0) && (sec_r001305_9_2 <= 255));
  __CPROVER_assume((sec_r001305_10_1 >= 0) && (sec_r001305_10_1 <= 255));
  __CPROVER_assume((sec_r001305_10_2 >= 0) && (sec_r001305_10_2 <= 255));
  __CPROVER_assume((sec_r001305_11_1 >= 0) && (sec_r001305_11_1 <= 255));
  __CPROVER_assume((sec_r001305_11_2 >= 0) && (sec_r001305_11_2 <= 255));
  __CPROVER_assume((sec_r001305_12_1 >= 0) && (sec_r001305_12_1 <= 255));
  __CPROVER_assume((sec_r001305_12_2 >= 0) && (sec_r001305_12_2 <= 255));
  __CPROVER_assume((sec_r001305_13_1 >= 0) && (sec_r001305_13_1 <= 255));
  __CPROVER_assume((sec_r001305_13_2 >= 0) && (sec_r001305_13_2 <= 255));
  __CPROVER_assume((sec_r001305_14_1 >= 0) && (sec_r001305_14_1 <= 255));
  __CPROVER_assume((sec_r001305_14_2 >= 0) && (sec_r001305_14_2 <= 255));
  __CPROVER_assume((sec_r001305_15_1 >= 0) && (sec_r001305_15_1 <= 255));
  __CPROVER_assume((sec_r001305_15_2 >= 0) && (sec_r001305_15_2 <= 255));
  __CPROVER_assume((sec_r001305_16_1 >= 0) && (sec_r001305_16_1 <= 255));
  __CPROVER_assume((sec_r001305_16_2 >= 0) && (sec_r001305_16_2 <= 255));
  __CPROVER_assume((sec_r001305_17_1 >= 0) && (sec_r001305_17_1 <= 255));
  __CPROVER_assume((sec_r001305_17_2 >= 0) && (sec_r001305_17_2 <= 255));
  __CPROVER_assume((sec_r001305_18_1 >= 0) && (sec_r001305_18_1 <= 255));
  __CPROVER_assume((sec_r001305_18_2 >= 0) && (sec_r001305_18_2 <= 255));
  struct AudioFrame_R001305_513_0 st_var_0_1 = {0};
  struct AudioFrame_R001305_513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001305_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001305_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001305_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001305_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001305_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001305_0_2 + 7) & 15;
  struct FilterState_R001305_513_1 st_var_1_1 = {0};
  struct FilterState_R001305_513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001305_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001305_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001305_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001305_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001305_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001305_0_2 + 9) & 15;
  struct StreamBuffer_R001305_513_2 st_var_2_1 = {0};
  struct StreamBuffer_R001305_513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001305_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001305_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001305_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001305_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001305_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001305_0_2 + 11) & 15;
  union TelemetryField_R001305_513_0 u_var_1;
  union TelemetryField_R001305_513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001305_513_0(sec_r001305_0_1, pub_r001305_1_1, pub_r001305_2_1);
  int helper_flow_0_2 = fn_R001305_513_0(sec_r001305_0_2, pub_r001305_1_2, pub_r001305_2_2);
  fn_R001305_513_0_2(sec_r001305_0_1, pub_r001305_1_1, pub_r001305_2_1, sec_r001305_0_2, pub_r001305_1_2, pub_r001305_2_2);
  int helper_flow_1_1 = fn_R001305_513_1(sec_r001305_1_1, pub_r001305_2_1, pub_r001305_3_1);
  int helper_flow_1_2 = fn_R001305_513_1(sec_r001305_1_2, pub_r001305_2_2, pub_r001305_3_2);
  fn_R001305_513_1_2(sec_r001305_1_1, pub_r001305_2_1, pub_r001305_3_1, sec_r001305_1_2, pub_r001305_2_2, pub_r001305_3_2);
  int helper_flow_2_1 = fn_R001305_513_2(sec_r001305_2_1, pub_r001305_3_1, pub_r001305_4_1);
  int helper_flow_2_2 = fn_R001305_513_2(sec_r001305_2_2, pub_r001305_3_2, pub_r001305_4_2);
  fn_R001305_513_2_2(sec_r001305_2_1, pub_r001305_3_1, pub_r001305_4_1, sec_r001305_2_2, pub_r001305_3_2, pub_r001305_4_2);
  int helper_flow_3_1 = fn_R001305_513_3(sec_r001305_3_1, sec_r001305_4_1, pub_r001305_5_1, pub_r001305_6_1);
  int helper_flow_3_2 = fn_R001305_513_3(sec_r001305_3_2, sec_r001305_4_2, pub_r001305_5_2, pub_r001305_6_2);
  fn_R001305_513_3_2(sec_r001305_3_1, sec_r001305_4_1, pub_r001305_5_1, pub_r001305_6_1, sec_r001305_3_2, sec_r001305_4_2, pub_r001305_5_2, pub_r001305_6_2);
  int helper_flow_4_1 = fn_R001305_513_4(sec_r001305_4_1, pub_r001305_5_1, pub_r001305_6_1, pub_r001305_7_1, pub_r001305_8_1);
  int helper_flow_4_2 = fn_R001305_513_4(sec_r001305_4_2, pub_r001305_5_2, pub_r001305_6_2, pub_r001305_7_2, pub_r001305_8_2);
  fn_R001305_513_4_2(sec_r001305_4_1, pub_r001305_5_1, pub_r001305_6_1, pub_r001305_7_1, pub_r001305_8_1, sec_r001305_4_2, pub_r001305_5_2, pub_r001305_6_2, pub_r001305_7_2, pub_r001305_8_2);
  int helper_flow_5_1 = fn_R001305_513_5(sec_r001305_5_1, pub_r001305_6_1, pub_r001305_7_1);
  int helper_flow_5_2 = fn_R001305_513_5(sec_r001305_5_2, pub_r001305_6_2, pub_r001305_7_2);
  fn_R001305_513_5_2(sec_r001305_5_1, pub_r001305_6_1, pub_r001305_7_1, sec_r001305_5_2, pub_r001305_6_2, pub_r001305_7_2);
  int helper_flow_6_1 = fn_R001305_513_6(sec_r001305_6_1, sec_r001305_7_1, pub_r001305_8_1, pub_r001305_9_1);
  int helper_flow_6_2 = fn_R001305_513_6(sec_r001305_6_2, sec_r001305_7_2, pub_r001305_8_2, pub_r001305_9_2);
  fn_R001305_513_6_2(sec_r001305_6_1, sec_r001305_7_1, pub_r001305_8_1, pub_r001305_9_1, sec_r001305_6_2, sec_r001305_7_2, pub_r001305_8_2, pub_r001305_9_2);
  int helper_flow_7_1 = fn_R001305_513_7(sec_r001305_7_1, pub_r001305_8_1, pub_r001305_9_1, pub_r001305_10_1, pub_r001305_11_1);
  int helper_flow_7_2 = fn_R001305_513_7(sec_r001305_7_2, pub_r001305_8_2, pub_r001305_9_2, pub_r001305_10_2, pub_r001305_11_2);
  fn_R001305_513_7_2(sec_r001305_7_1, pub_r001305_8_1, pub_r001305_9_1, pub_r001305_10_1, pub_r001305_11_1, sec_r001305_7_2, pub_r001305_8_2, pub_r001305_9_2, pub_r001305_10_2, pub_r001305_11_2);
  int helper_flow_8_1 = fn_R001305_513_8(sec_r001305_8_1, pub_r001305_9_1);
  int helper_flow_8_2 = fn_R001305_513_8(sec_r001305_8_2, pub_r001305_9_2);
  fn_R001305_513_8_2(sec_r001305_8_1, pub_r001305_9_1, sec_r001305_8_2, pub_r001305_9_2);
  int stage_v_0_1 = ((pub_r001305_6_1 * 2) + 44) & 63;
  int stage_v_0_2 = ((pub_r001305_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((helper_flow_0_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_1_2 = ((helper_flow_0_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((sec_r001305_6_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001305_6_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001305_12_1 * 2) + 36) & 63;
  int stage_v_3_2 = ((pub_r001305_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001305_13_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001305_13_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001305_4_1 * 2) + 10) & 63;
  int stage_v_5_2 = ((pub_r001305_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001305_0_1 * 2) + 44) & 63;
  int stage_v_6_2 = ((pub_r001305_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001305_0_1 * 2) + 50) & 63;
  int stage_v_7_2 = ((pub_r001305_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001305_6_1 * 2) + 6) & 63;
  int stage_v_8_2 = ((pub_r001305_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001305_2_1 * 2) + 16) & 63;
  int stage_v_9_2 = ((pub_r001305_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001305_16_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001305_16_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((helper_flow_1_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_11_2 = ((helper_flow_1_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((helper_flow_8_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_12_2 = ((helper_flow_8_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((sec_r001305_3_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_13_2 = ((sec_r001305_3_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((sec_r001305_6_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001305_6_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((stage_v_1_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_15_2 = ((stage_v_1_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001305_18_1 * 2) + 40) & 63;
  int stage_v_16_2 = ((pub_r001305_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001305_13_1 * 2) + 26) & 63;
  int stage_v_17_2 = ((pub_r001305_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((stage_v_13_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_18_2 = ((stage_v_13_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((stage_v_1_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_1_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((pub_r001305_23_1 * 2) + 15) & 63;
  int stage_v_20_2 = ((pub_r001305_23_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((sec_r001305_15_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_21_2 = ((sec_r001305_15_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((sec_r001305_9_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_22_2 = ((sec_r001305_9_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((stage_v_14_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_14_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((stage_v_22_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_24_2 = ((stage_v_22_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((sec_r001305_12_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001305_12_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((sec_r001305_10_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_26_2 = ((sec_r001305_10_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((stage_v_1_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_27_2 = ((stage_v_1_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((stage_v_4_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_28_2 = ((stage_v_4_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001305_5_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001305_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001305_17_1 * 2) + 23) & 63;
  int stage_v_30_2 = ((pub_r001305_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001305_20_1 * 2) + 36) & 63;
  int stage_v_31_2 = ((pub_r001305_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_4_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_32_2 = ((helper_flow_4_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((sec_r001305_2_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_33_2 = ((sec_r001305_2_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((pub_r001305_21_1 * 2) + 40) & 63;
  int stage_v_34_2 = ((pub_r001305_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001305_17_1 * 2) + 15) & 63;
  int stage_v_35_2 = ((pub_r001305_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001305_15_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001305_15_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001305_11_1 * 2) + 5) & 63;
  int stage_v_37_2 = ((pub_r001305_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001305_10_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_38_2 = ((sec_r001305_10_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_38_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_38_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001305_23_1 * 2) + 15) & 63;
  int stage_v_40_2 = ((pub_r001305_23_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_26_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_26_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_25_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_25_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((pub_r001305_11_1 * 2) + 32) & 63;
  int stage_v_43_2 = ((pub_r001305_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001305_6_1 * 2) + 40) & 63;
  int stage_v_44_2 = ((pub_r001305_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001305_20_1 * 2) + 35) & 63;
  int stage_v_45_2 = ((pub_r001305_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_11_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_11_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001305_0_1 * 2) + 26) & 63;
  int stage_v_47_2 = ((pub_r001305_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_41_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_48_2 = ((stage_v_41_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((stage_v_41_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_41_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001305_12_1 * 2) + 43) & 63;
  int stage_v_50_2 = ((pub_r001305_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001305_22_1 * 2) + 20) & 63;
  int stage_v_51_2 = ((pub_r001305_22_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_15_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_52_2 = ((stage_v_15_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((sec_r001305_6_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001305_6_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((pub_r001305_5_1 * 2) + 26) & 63;
  int stage_v_54_2 = ((pub_r001305_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((sec_r001305_0_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_55_2 = ((sec_r001305_0_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((pub_r001305_17_1 * 2) + 32) & 63;
  int stage_v_56_2 = ((pub_r001305_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001305_18_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_57_2 = ((sec_r001305_18_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((pub_r001305_18_1 * 2) + 23) & 63;
  int stage_v_58_2 = ((pub_r001305_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001305_6_1 * 2) + 32) & 63;
  int stage_v_59_2 = ((pub_r001305_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001305_14_1 * 2) + 48) & 63;
  int stage_v_60_2 = ((pub_r001305_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((helper_flow_7_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_61_2 = ((helper_flow_7_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((sec_r001305_15_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_62_2 = ((sec_r001305_15_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((stage_v_32_1 << 1) ^ (pub_r001305_7_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_32_2 << 1) ^ (pub_r001305_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((pub_r001305_12_1 * 2) + 33) & 63;
  int stage_v_64_2 = ((pub_r001305_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001305_21_1 * 2) + 15) & 63;
  int stage_v_65_2 = ((pub_r001305_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((helper_flow_7_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_66_2 = ((helper_flow_7_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((pub_r001305_15_1 * 2) + 33) & 63;
  int stage_v_67_2 = ((pub_r001305_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_46_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_68_2 = ((stage_v_46_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((pub_r001305_4_1 * 2) + 44) & 63;
  int stage_v_69_2 = ((pub_r001305_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((sec_r001305_1_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_70_2 = ((sec_r001305_1_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001305_23_1 * 2) + 45) & 63;
  int stage_v_71_2 = ((pub_r001305_23_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((helper_flow_6_1 << 1) ^ (pub_r001305_7_1 >> 1)) & 127;
  int stage_v_72_2 = ((helper_flow_6_2 << 1) ^ (pub_r001305_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001305_15_1 * 2) + 6) & 63;
  int stage_v_73_2 = ((pub_r001305_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((sec_r001305_10_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_74_2 = ((sec_r001305_10_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((stage_v_26_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_26_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((sec_r001305_7_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_76_2 = ((sec_r001305_7_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((stage_v_57_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_77_2 = ((stage_v_57_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001305_3_1 * 2) + 23) & 63;
  int stage_v_78_2 = ((pub_r001305_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001305_13_1 * 2) + 33) & 63;
  int stage_v_79_2 = ((pub_r001305_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((sec_r001305_17_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_80_2 = ((sec_r001305_17_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((sec_r001305_7_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_81_2 = ((sec_r001305_7_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((pub_r001305_9_1 * 2) + 49) & 63;
  int stage_v_82_2 = ((pub_r001305_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((helper_flow_6_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_83_2 = ((helper_flow_6_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((stage_v_81_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_81_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((pub_r001305_18_1 * 2) + 28) & 63;
  int stage_v_85_2 = ((pub_r001305_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_38_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_38_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001305_16_1 * 2) + 16) & 63;
  int stage_v_87_2 = ((pub_r001305_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_77_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_88_2 = ((stage_v_77_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((pub_r001305_19_1 * 2) + 50) & 63;
  int stage_v_89_2 = ((pub_r001305_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001305_7_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_90_2 = ((sec_r001305_7_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((pub_r001305_6_1 * 2) + 43) & 63;
  int stage_v_91_2 = ((pub_r001305_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_62_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_62_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((sec_r001305_4_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_93_2 = ((sec_r001305_4_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((stage_v_81_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_81_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((stage_v_53_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_95_2 = ((stage_v_53_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((stage_v_19_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_19_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001305_13_1 * 2) + 28) & 63;
  int stage_v_97_2 = ((pub_r001305_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001305_7_1 * 2) + 38) & 63;
  int stage_v_98_2 = ((pub_r001305_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_21_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_21_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((stage_v_52_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_52_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((stage_v_15_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_15_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((sec_r001305_15_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_102_2 = ((sec_r001305_15_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001305_5_1 * 2) + 12) & 63;
  int stage_v_103_2 = ((pub_r001305_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_32_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_32_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((sec_r001305_8_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_105_2 = ((sec_r001305_8_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((pub_r001305_21_1 * 2) + 39) & 63;
  int stage_v_106_2 = ((pub_r001305_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001305_8_1 * 2) + 39) & 63;
  int stage_v_107_2 = ((pub_r001305_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_32_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_108_2 = ((stage_v_32_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((sec_r001305_1_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_109_2 = ((sec_r001305_1_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((stage_v_12_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_12_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((helper_flow_6_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_111_2 = ((helper_flow_6_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((stage_v_99_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_112_2 = ((stage_v_99_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((pub_r001305_10_1 * 2) + 49) & 63;
  int stage_v_113_2 = ((pub_r001305_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_21_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_114_2 = ((stage_v_21_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_53_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_53_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001305_22_1 * 2) + 6) & 63;
  int stage_v_116_2 = ((pub_r001305_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((sec_r001305_1_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001305_1_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((stage_v_38_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_38_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((stage_v_114_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_119_2 = ((stage_v_114_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001305_10_1 * 2) + 50) & 63;
  int stage_v_120_2 = ((pub_r001305_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_75_1 << 1) ^ (pub_r001305_7_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_75_2 << 1) ^ (pub_r001305_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((pub_r001305_17_1 * 2) + 21) & 63;
  int stage_v_122_2 = ((pub_r001305_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((sec_r001305_12_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_123_2 = ((sec_r001305_12_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001305_14_1 * 2) + 21) & 63;
  int stage_v_124_2 = ((pub_r001305_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_27_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_27_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((pub_r001305_3_1 * 2) + 40) & 63;
  int stage_v_126_2 = ((pub_r001305_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_12_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_12_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_11_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_11_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001305_0_1 * 2) + 42) & 63;
  int stage_v_129_2 = ((pub_r001305_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((sec_r001305_12_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_130_2 = ((sec_r001305_12_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((stage_v_19_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_19_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((helper_flow_7_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_132_2 = ((helper_flow_7_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((stage_v_96_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_96_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001305_4_1 * 2) + 29) & 63;
  int stage_v_134_2 = ((pub_r001305_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_10_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_135_2 = ((stage_v_10_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_21_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_21_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001305_10_1 * 2) + 36) & 63;
  int stage_v_137_2 = ((pub_r001305_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_32_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_32_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001305_14_1 * 2) + 28) & 63;
  int stage_v_139_2 = ((pub_r001305_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001305_7_1 * 2) + 47) & 63;
  int stage_v_140_2 = ((pub_r001305_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001305_21_1 * 2) + 5) & 63;
  int stage_v_141_2 = ((pub_r001305_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_112_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_112_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001305_16_1 * 2) + 32) & 63;
  int stage_v_143_2 = ((pub_r001305_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001305_4_1 * 2) + 11) & 63;
  int stage_v_144_2 = ((pub_r001305_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001305_3_1 * 2) + 12) & 63;
  int stage_v_145_2 = ((pub_r001305_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_92_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_92_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((pub_r001305_9_1 * 2) + 5) & 63;
  int stage_v_147_2 = ((pub_r001305_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001305_22_1 * 2) + 27) & 63;
  int stage_v_148_2 = ((pub_r001305_22_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((sec_r001305_12_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_149_2 = ((sec_r001305_12_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((stage_v_83_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_83_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((pub_r001305_20_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001305_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_42_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_42_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((stage_v_4_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_4_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((stage_v_2_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_2_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((pub_r001305_23_1 * 2) + 17) & 63;
  int stage_v_155_2 = ((pub_r001305_23_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_123_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_123_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((stage_v_48_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_48_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_146_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_146_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((sec_r001305_2_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_159_2 = ((sec_r001305_2_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_32_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_32_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((pub_r001305_5_1 * 2) + 38) & 63;
  int stage_v_161_2 = ((pub_r001305_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_158_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_158_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001305_4_1 * 2) + 9) & 63;
  int stage_v_163_2 = ((pub_r001305_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_86_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_86_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001305_18_1 * 2) + 14) & 63;
  int stage_v_165_2 = ((pub_r001305_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001305_19_1 * 2) + 39) & 63;
  int stage_v_166_2 = ((pub_r001305_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_128_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_128_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((stage_v_108_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_108_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((pub_r001305_10_1 * 2) + 20) & 63;
  int stage_v_169_2 = ((pub_r001305_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001305_12_1 * 2) + 45) & 63;
  int stage_v_170_2 = ((pub_r001305_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001305_7_1 * 2) + 43) & 63;
  int stage_v_171_2 = ((pub_r001305_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_52_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_172_2 = ((stage_v_52_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((stage_v_75_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_75_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((stage_v_125_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_125_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((pub_r001305_2_1 * 2) + 18) & 63;
  int stage_v_175_2 = ((pub_r001305_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001305_23_1 * 2) + 5) & 63;
  int stage_v_176_2 = ((pub_r001305_23_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001305_17_1 * 2) + 48) & 63;
  int stage_v_177_2 = ((pub_r001305_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((sec_r001305_11_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_178_2 = ((sec_r001305_11_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_135_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_135_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001305_20_1 * 2) + 5) & 63;
  int stage_v_180_2 = ((pub_r001305_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001305_6_1 * 2) + 12) & 63;
  int stage_v_181_2 = ((pub_r001305_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_112_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_112_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((pub_r001305_14_1 * 2) + 12) & 63;
  int stage_v_183_2 = ((pub_r001305_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_127_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_127_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((stage_v_39_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_39_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((stage_v_111_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_186_2 = ((stage_v_111_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_186_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_186_2 + 1) & 15;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = ((stage_v_4_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_4_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((sec_r001305_3_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_188_2 = ((sec_r001305_3_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((stage_v_157_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_189_2 = ((stage_v_157_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((pub_r001305_12_1 * 2) + 9) & 63;
  int stage_v_190_2 = ((pub_r001305_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((helper_flow_8_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_191_2 = ((helper_flow_8_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_1_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_1_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((sec_r001305_0_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_193_2 = ((sec_r001305_0_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((helper_flow_6_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_194_2 = ((helper_flow_6_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((stage_v_84_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_84_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_132_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_132_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_48_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_48_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001305_20_1 * 2) + 21) & 63;
  int stage_v_198_2 = ((pub_r001305_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_48_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_48_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((stage_v_38_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_38_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((stage_v_36_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_36_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((helper_flow_8_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_202_2 = ((helper_flow_8_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001305_1_1 * 2) + 10) & 63;
  int stage_v_203_2 = ((pub_r001305_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_157_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_157_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((stage_v_110_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_110_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((pub_r001305_11_1 * 2) + 5) & 63;
  int stage_v_206_2 = ((pub_r001305_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001305_10_1 * 2) + 38) & 63;
  int stage_v_207_2 = ((pub_r001305_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((helper_flow_6_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_208_2 = ((helper_flow_6_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((pub_r001305_13_1 * 2) + 49) & 63;
  int stage_v_209_2 = ((pub_r001305_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001305_0_1 * 2) + 40) & 63;
  int stage_v_210_2 = ((pub_r001305_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001305_0_1 * 2) + 40) & 63;
  int stage_v_211_2 = ((pub_r001305_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_28_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_28_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((pub_r001305_17_1 * 2) + 21) & 63;
  int stage_v_213_2 = ((pub_r001305_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001305_5_1 * 2) + 44) & 63;
  int stage_v_214_2 = ((pub_r001305_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001305_21_1 * 2) + 21) & 63;
  int stage_v_215_2 = ((pub_r001305_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((helper_flow_3_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_216_2 = ((helper_flow_3_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_27_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_27_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((stage_v_26_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_26_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((pub_r001305_11_1 * 2) + 27) & 63;
  int stage_v_219_2 = ((pub_r001305_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001305_20_1 * 2) + 16) & 63;
  int stage_v_220_2 = ((pub_r001305_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((sec_r001305_2_1 << 1) ^ (pub_r001305_7_1 >> 1)) & 127;
  int stage_v_221_2 = ((sec_r001305_2_2 << 1) ^ (pub_r001305_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_189_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_189_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((stage_v_199_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_223_2 = ((stage_v_199_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_223_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_223_2 + 1) & 15;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = ((sec_r001305_16_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_224_2 = ((sec_r001305_16_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((stage_v_186_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_186_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((sec_r001305_2_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_226_2 = ((sec_r001305_2_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((pub_r001305_21_1 * 2) + 17) & 63;
  int stage_v_227_2 = ((pub_r001305_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((helper_flow_0_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_228_2 = ((helper_flow_0_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((stage_v_226_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_226_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((pub_r001305_2_1 * 2) + 28) & 63;
  int stage_v_230_2 = ((pub_r001305_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_77_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_77_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((stage_v_212_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_212_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((stage_v_53_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_53_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((stage_v_123_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_123_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((pub_r001305_21_1 * 2) + 33) & 63;
  int stage_v_235_2 = ((pub_r001305_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((stage_v_76_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_76_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001305_16_1 * 2) + 45) & 63;
  int stage_v_237_2 = ((pub_r001305_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((helper_flow_1_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_238_2 = ((helper_flow_1_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((pub_r001305_6_1 * 2) + 7) & 63;
  int stage_v_239_2 = ((pub_r001305_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001305_7_1 * 2) + 40) & 63;
  int stage_v_240_2 = ((pub_r001305_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((stage_v_72_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_72_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((stage_v_75_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_75_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_19_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_19_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001305_20_1 * 2) + 12) & 63;
  int stage_v_244_2 = ((pub_r001305_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((helper_flow_8_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_245_2 = ((helper_flow_8_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001305_19_1 * 2) + 31) & 63;
  int stage_v_246_2 = ((pub_r001305_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001305_18_1 * 2) + 40) & 63;
  int stage_v_247_2 = ((pub_r001305_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001305_15_1 * 2) + 18) & 63;
  int stage_v_248_2 = ((pub_r001305_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001305_13_1 * 2) + 37) & 63;
  int stage_v_249_2 = ((pub_r001305_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001305_15_1 * 2) + 18) & 63;
  int stage_v_250_2 = ((pub_r001305_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001305_5_1 * 2) + 29) & 63;
  int stage_v_251_2 = ((pub_r001305_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((sec_r001305_14_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_252_2 = ((sec_r001305_14_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_191_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_191_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001305_14_1 * 2) + 12) & 63;
  int stage_v_254_2 = ((pub_r001305_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((stage_v_222_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_222_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((pub_r001305_9_1 * 2) + 6) & 63;
  int stage_v_256_2 = ((pub_r001305_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((stage_v_57_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_57_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_228_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_228_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((pub_r001305_13_1 * 2) + 36) & 63;
  int stage_v_259_2 = ((pub_r001305_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001305_15_1 * 2) + 36) & 63;
  int stage_v_260_2 = ((pub_r001305_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001305_18_1 * 2) + 39) & 63;
  int stage_v_261_2 = ((pub_r001305_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((helper_flow_5_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_262_2 = ((helper_flow_5_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((stage_v_23_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_23_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001305_14_1 * 2) + 15) & 63;
  int stage_v_264_2 = ((pub_r001305_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001305_19_1 * 2) + 20) & 63;
  int stage_v_265_2 = ((pub_r001305_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001305_22_1 * 2) + 28) & 63;
  int stage_v_266_2 = ((pub_r001305_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_28_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_28_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001305_21_1 * 2) + 43) & 63;
  int stage_v_268_2 = ((pub_r001305_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001305_12_1 * 2) + 50) & 63;
  int stage_v_269_2 = ((pub_r001305_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((helper_flow_7_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_270_2 = ((helper_flow_7_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((stage_v_104_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_104_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((stage_v_119_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_119_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((sec_r001305_5_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_273_2 = ((sec_r001305_5_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_102_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_102_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_63_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_63_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((helper_flow_1_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_276_2 = ((helper_flow_1_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((pub_r001305_23_1 * 2) + 14) & 63;
  int stage_v_277_2 = ((pub_r001305_23_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((stage_v_62_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_62_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((stage_v_19_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_19_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((sec_r001305_16_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_280_2 = ((sec_r001305_16_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001305_7_1 * 2) + 33) & 63;
  int stage_v_281_2 = ((pub_r001305_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_49_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_49_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((pub_r001305_19_1 * 2) + 29) & 63;
  int stage_v_283_2 = ((pub_r001305_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001305_1_1 * 2) + 28) & 63;
  int stage_v_284_2 = ((pub_r001305_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001305_22_1 * 2) + 28) & 63;
  int stage_v_285_2 = ((pub_r001305_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001305_7_1 * 2) + 43) & 63;
  int stage_v_286_2 = ((pub_r001305_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_228_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_228_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((stage_v_245_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_288_2 = ((stage_v_245_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_288_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_288_2 + 1) & 15;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = ((sec_r001305_7_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_289_2 = ((sec_r001305_7_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((stage_v_55_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_55_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001305_12_1 * 2) + 25) & 63;
  int stage_v_291_2 = ((pub_r001305_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001305_22_1 * 2) + 45) & 63;
  int stage_v_292_2 = ((pub_r001305_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001305_20_1 * 2) + 11) & 63;
  int stage_v_293_2 = ((pub_r001305_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001305_10_1 * 2) + 42) & 63;
  int stage_v_294_2 = ((pub_r001305_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((stage_v_28_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_28_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001305_15_1 * 2) + 22) & 63;
  int stage_v_296_2 = ((pub_r001305_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((helper_flow_2_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_297_2 = ((helper_flow_2_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_132_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_132_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_21_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_21_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((pub_r001305_22_1 * 2) + 15) & 63;
  int stage_v_300_2 = ((pub_r001305_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_172_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_172_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((stage_v_226_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_302_2 = ((stage_v_226_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((pub_r001305_0_1 * 2) + 22) & 63;
  int stage_v_303_2 = ((pub_r001305_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((stage_v_131_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_131_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((stage_v_135_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_135_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((stage_v_61_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_61_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001305_14_1 * 2) + 45) & 63;
  int stage_v_307_2 = ((pub_r001305_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_208_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_208_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_201_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_201_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_159_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_159_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((pub_r001305_8_1 * 2) + 7) & 63;
  int stage_v_311_2 = ((pub_r001305_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((stage_v_189_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_189_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_199_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_199_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((stage_v_302_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_314_2 = ((stage_v_302_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_314_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_314_2 + 1) & 15;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = ((stage_v_70_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_70_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((stage_v_191_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_191_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((stage_v_312_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_312_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_86_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_86_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((pub_r001305_16_1 * 2) + 26) & 63;
  int stage_v_319_2 = ((pub_r001305_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001305_13_1 * 2) + 35) & 63;
  int stage_v_320_2 = ((pub_r001305_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001305_14_1 * 2) + 45) & 63;
  int stage_v_321_2 = ((pub_r001305_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((helper_flow_5_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_322_2 = ((helper_flow_5_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_80_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_80_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((stage_v_81_1 << 1) ^ (pub_r001305_7_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_81_2 << 1) ^ (pub_r001305_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((pub_r001305_11_1 * 2) + 46) & 63;
  int stage_v_325_2 = ((pub_r001305_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((stage_v_222_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_222_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((stage_v_245_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_245_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((stage_v_297_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_297_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((stage_v_189_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_189_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((pub_r001305_12_1 * 2) + 17) & 63;
  int stage_v_330_2 = ((pub_r001305_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((stage_v_217_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_217_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_267_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_267_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((pub_r001305_2_1 * 2) + 35) & 63;
  int stage_v_333_2 = ((pub_r001305_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((stage_v_191_1 << 1) ^ (pub_r001305_12_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_191_2 << 1) ^ (pub_r001305_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((pub_r001305_13_1 * 2) + 20) & 63;
  int stage_v_335_2 = ((pub_r001305_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((stage_v_10_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_10_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((sec_r001305_1_1 << 1) ^ (pub_r001305_6_1 >> 1)) & 127;
  int stage_v_337_2 = ((sec_r001305_1_2 << 1) ^ (pub_r001305_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((stage_v_123_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_123_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((stage_v_274_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_274_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((stage_v_83_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_83_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((pub_r001305_1_1 * 2) + 17) & 63;
  int stage_v_341_2 = ((pub_r001305_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001305_7_1 * 2) + 11) & 63;
  int stage_v_342_2 = ((pub_r001305_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((stage_v_339_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_339_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((stage_v_234_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_234_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_150_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_150_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((pub_r001305_17_1 * 2) + 26) & 63;
  int stage_v_346_2 = ((pub_r001305_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((stage_v_226_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_226_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((pub_r001305_22_1 * 2) + 47) & 63;
  int stage_v_348_2 = ((pub_r001305_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001305_6_1 * 2) + 34) & 63;
  int stage_v_349_2 = ((pub_r001305_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001305_23_1 * 2) + 9) & 63;
  int stage_v_350_2 = ((pub_r001305_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001305_18_1 * 2) + 44) & 63;
  int stage_v_351_2 = ((pub_r001305_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((sec_r001305_4_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_352_2 = ((sec_r001305_4_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_340_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_340_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((pub_r001305_21_1 * 2) + 14) & 63;
  int stage_v_354_2 = ((pub_r001305_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((stage_v_66_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_66_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((stage_v_15_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_15_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((sec_r001305_16_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_357_2 = ((sec_r001305_16_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((sec_r001305_11_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_358_2 = ((sec_r001305_11_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((sec_r001305_2_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_359_2 = ((sec_r001305_2_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((pub_r001305_12_1 * 2) + 14) & 63;
  int stage_v_360_2 = ((pub_r001305_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((stage_v_188_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_361_2 = ((stage_v_188_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_361_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_361_2 + 1) & 15;
  out_sink_1 ^= stage_v_361_1 & 63;
  out_sink_2 ^= stage_v_361_2 & 63;
  int stage_v_362_1 = ((stage_v_276_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_276_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((pub_r001305_3_1 * 2) + 31) & 63;
  int stage_v_363_2 = ((pub_r001305_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((sec_r001305_0_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_364_2 = ((sec_r001305_0_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_168_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_168_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((pub_r001305_5_1 * 2) + 47) & 63;
  int stage_v_366_2 = ((pub_r001305_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001305_7_1 * 2) + 7) & 63;
  int stage_v_367_2 = ((pub_r001305_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001305_3_1 * 2) + 42) & 63;
  int stage_v_368_2 = ((pub_r001305_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((stage_v_178_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_178_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((stage_v_299_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_299_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001305_22_1 * 2) + 14) & 63;
  int stage_v_371_2 = ((pub_r001305_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((stage_v_195_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_195_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((stage_v_15_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_15_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((pub_r001305_18_1 * 2) + 49) & 63;
  int stage_v_374_2 = ((pub_r001305_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001305_7_1 * 2) + 15) & 63;
  int stage_v_375_2 = ((pub_r001305_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_63_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_63_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((sec_r001305_9_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_377_2 = ((sec_r001305_9_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((pub_r001305_7_1 * 2) + 8) & 63;
  int stage_v_378_2 = ((pub_r001305_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((stage_v_146_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_146_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((pub_r001305_14_1 * 2) + 21) & 63;
  int stage_v_380_2 = ((pub_r001305_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((stage_v_48_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_48_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_358_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_358_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_158_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_158_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((pub_r001305_21_1 * 2) + 11) & 63;
  int stage_v_384_2 = ((pub_r001305_21_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((stage_v_267_1 << 1) ^ (pub_r001305_3_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_267_2 << 1) ^ (pub_r001305_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_299_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_299_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((stage_v_27_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_27_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001305_20_1 * 2) + 18) & 63;
  int stage_v_388_2 = ((pub_r001305_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_168_1 << 1) ^ (pub_r001305_15_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_168_2 << 1) ^ (pub_r001305_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001305_14_1 * 2) + 32) & 63;
  int stage_v_390_2 = ((pub_r001305_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_152_1 << 1) ^ (pub_r001305_11_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_152_2 << 1) ^ (pub_r001305_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_204_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_204_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((stage_v_149_1 << 1) ^ (pub_r001305_20_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_149_2 << 1) ^ (pub_r001305_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((stage_v_146_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_146_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((stage_v_343_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_395_2 = ((stage_v_343_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_395_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_395_2 + 1) & 15;
  out_sink_1 ^= stage_v_395_1 & 63;
  out_sink_2 ^= stage_v_395_2 & 63;
  int stage_v_396_1 = ((stage_v_369_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_369_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((stage_v_86_1 << 1) ^ (pub_r001305_17_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_86_2 << 1) ^ (pub_r001305_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((stage_v_336_1 << 1) ^ (pub_r001305_2_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_336_2 << 1) ^ (pub_r001305_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((stage_v_194_1 << 1) ^ (pub_r001305_16_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_194_2 << 1) ^ (pub_r001305_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((stage_v_347_1 << 1) ^ (pub_r001305_1_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_347_2 << 1) ^ (pub_r001305_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((pub_r001305_22_1 * 2) + 18) & 63;
  int stage_v_401_2 = ((pub_r001305_22_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((stage_v_125_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_125_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((pub_r001305_4_1 * 2) + 26) & 63;
  int stage_v_403_2 = ((pub_r001305_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001305_18_1 * 2) + 31) & 63;
  int stage_v_404_2 = ((pub_r001305_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001305_6_1 * 2) + 17) & 63;
  int stage_v_405_2 = ((pub_r001305_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001305_23_1 * 2) + 31) & 63;
  int stage_v_406_2 = ((pub_r001305_23_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((stage_v_316_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_316_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_153_1 << 1) ^ (pub_r001305_10_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_153_2 << 1) ^ (pub_r001305_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((pub_r001305_4_1 * 2) + 48) & 63;
  int stage_v_409_2 = ((pub_r001305_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((stage_v_39_1 << 1) ^ (pub_r001305_4_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_39_2 << 1) ^ (pub_r001305_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((helper_flow_3_1 << 1) ^ (pub_r001305_23_1 >> 1)) & 127;
  int stage_v_411_2 = ((helper_flow_3_2 << 1) ^ (pub_r001305_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_411_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_411_2 + 1) & 15;
  out_sink_1 ^= stage_v_411_1 & 63;
  out_sink_2 ^= stage_v_411_2 & 63;
  int stage_v_412_1 = ((pub_r001305_7_1 * 2) + 13) & 63;
  int stage_v_412_2 = ((pub_r001305_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001305_9_1 * 2) + 45) & 63;
  int stage_v_413_2 = ((pub_r001305_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((stage_v_4_1 << 1) ^ (pub_r001305_5_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_4_2 << 1) ^ (pub_r001305_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((pub_r001305_5_1 * 2) + 48) & 63;
  int stage_v_415_2 = ((pub_r001305_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((stage_v_399_1 << 1) ^ (pub_r001305_18_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_399_2 << 1) ^ (pub_r001305_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((stage_v_271_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_417_2 = ((stage_v_271_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_417_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_417_2 + 1) & 15;
  out_sink_1 ^= stage_v_417_1 & 63;
  out_sink_2 ^= stage_v_417_2 & 63;
  int stage_v_418_1 = ((stage_v_370_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_370_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((stage_v_133_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_133_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((pub_r001305_23_1 * 2) + 8) & 63;
  int stage_v_420_2 = ((pub_r001305_23_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001305_2_1 * 2) + 20) & 63;
  int stage_v_421_2 = ((pub_r001305_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((stage_v_101_1 << 1) ^ (pub_r001305_0_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_101_2 << 1) ^ (pub_r001305_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((stage_v_234_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_423_2 = ((stage_v_234_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((pub_r001305_13_1 * 2) + 17) & 63;
  int stage_v_424_2 = ((pub_r001305_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_362_1 << 1) ^ (pub_r001305_13_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_362_2 << 1) ^ (pub_r001305_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  int stage_v_426_1 = ((stage_v_81_1 << 1) ^ (pub_r001305_9_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_81_2 << 1) ^ (pub_r001305_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((pub_r001305_13_1 * 2) + 5) & 63;
  int stage_v_427_2 = ((pub_r001305_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001305_13_1 * 2) + 12) & 63;
  int stage_v_428_2 = ((pub_r001305_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((stage_v_381_1 << 1) ^ (pub_r001305_14_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_381_2 << 1) ^ (pub_r001305_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_86_1 << 1) ^ (pub_r001305_8_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_86_2 << 1) ^ (pub_r001305_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((stage_v_231_1 << 1) ^ (pub_r001305_19_1 >> 1)) & 127;
  int stage_v_431_2 = ((stage_v_231_2 << 1) ^ (pub_r001305_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((pub_r001305_23_1 * 2) + 10) & 63;
  int stage_v_432_2 = ((pub_r001305_23_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001305_0_1 * 2) + 47) & 63;
  int stage_v_433_2 = ((pub_r001305_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((stage_v_386_1 << 1) ^ (pub_r001305_21_1 >> 1)) & 127;
  int stage_v_434_2 = ((stage_v_386_2 << 1) ^ (pub_r001305_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_434_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_434_2 + 1) & 15;
  out_sink_1 ^= stage_v_434_1 & 63;
  out_sink_2 ^= stage_v_434_2 & 63;
  int stage_v_435_1 = ((pub_r001305_20_1 * 2) + 31) & 63;
  int stage_v_435_2 = ((pub_r001305_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001305_18_1 * 2) + 15) & 63;
  int stage_v_436_2 = ((pub_r001305_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((stage_v_329_1 << 1) ^ (pub_r001305_22_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_329_2 << 1) ^ (pub_r001305_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001305_12_1 == pub_r001305_12_2);
  __CPROVER_assume(pub_r001305_18_1 == pub_r001305_18_2);
  __CPROVER_assume(sec_r001305_17_1 != sec_r001305_17_2);
  __CPROVER_assume(pub_r001305_20_1 == pub_r001305_20_2);
  __CPROVER_assume(pub_r001305_22_1 == pub_r001305_22_2);
  __CPROVER_assume(pub_r001305_2_1 == pub_r001305_2_2);
  __CPROVER_assume(pub_r001305_0_1 == pub_r001305_0_2);
  __CPROVER_assume(pub_r001305_4_1 == pub_r001305_4_2);
  __CPROVER_assume(pub_r001305_10_1 == pub_r001305_10_2);
  __CPROVER_assume(pub_r001305_14_1 == pub_r001305_14_2);
  __CPROVER_assume(sec_r001305_9_1 != sec_r001305_9_2);
  __CPROVER_assume(pub_r001305_7_1 == pub_r001305_7_2);
  __CPROVER_assume(sec_r001305_11_1 != sec_r001305_11_2);
  __CPROVER_assume(sec_r001305_13_1 != sec_r001305_13_2);
  __CPROVER_assume(pub_r001305_1_1 == pub_r001305_1_2);
  __CPROVER_assume(sec_r001305_12_1 != sec_r001305_12_2);
  __CPROVER_assume(sec_r001305_4_1 != sec_r001305_4_2);
  __CPROVER_assume(pub_r001305_3_1 == pub_r001305_3_2);
  __CPROVER_assume(pub_r001305_16_1 == pub_r001305_16_2);
  __CPROVER_assume(pub_r001305_6_1 == pub_r001305_6_2);
  __CPROVER_assume(sec_r001305_2_1 != sec_r001305_2_2);
  __CPROVER_assume(sec_r001305_18_1 != sec_r001305_18_2);
  __CPROVER_assume(sec_r001305_14_1 != sec_r001305_14_2);
  __CPROVER_assume(sec_r001305_8_1 != sec_r001305_8_2);
  __CPROVER_assume(sec_r001305_1_1 != sec_r001305_1_2);
  __CPROVER_assume(pub_r001305_13_1 == pub_r001305_13_2);
  __CPROVER_assume(pub_r001305_8_1 == pub_r001305_8_2);
  __CPROVER_assume(sec_r001305_10_1 != sec_r001305_10_2);
  __CPROVER_assume(sec_r001305_3_1 != sec_r001305_3_2);
  __CPROVER_assume(sec_r001305_6_1 != sec_r001305_6_2);
  __CPROVER_assume(pub_r001305_23_1 == pub_r001305_23_2);
  __CPROVER_assume(pub_r001305_9_1 == pub_r001305_9_2);
  __CPROVER_assume(sec_r001305_15_1 != sec_r001305_15_2);
  __CPROVER_assume(sec_r001305_16_1 != sec_r001305_16_2);
  __CPROVER_assume(sec_r001305_7_1 != sec_r001305_7_2);
  __CPROVER_assume(sec_r001305_5_1 != sec_r001305_5_2);
  __CPROVER_assume(pub_r001305_5_1 == pub_r001305_5_2);
  __CPROVER_assume(pub_r001305_17_1 == pub_r001305_17_2);
  __CPROVER_assume(sec_r001305_0_1 != sec_r001305_0_2);
  __CPROVER_assume(pub_r001305_11_1 == pub_r001305_11_2);
  __CPROVER_assume(pub_r001305_19_1 == pub_r001305_19_2);
  __CPROVER_assume(pub_r001305_21_1 == pub_r001305_21_2);
  __CPROVER_assume(pub_r001305_15_1 == pub_r001305_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
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
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
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


