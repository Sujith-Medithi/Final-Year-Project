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
struct Vector3D_R000052_5213_0
{
  unsigned char coord_z;
  int coord_y;
  unsigned char pitch;
  short norm_sq;
  int buffer[3];
};
struct StreamBuffer_R000052_5213_1
{
  unsigned char checksum;
  int state;
  unsigned char capacity;
  int watermark;
  int buffer[3];
};
struct SensorNode_R000052_5213_2
{
  short offset;
  int calib;
  short threshold;
  int status;
  unsigned char gain;
  int buffer[3];
};
struct AudioFrame_R000052_5213_3
{
  int gain;
  short rms;
  unsigned char envelope;
  int peak;
  int sample_rate;
  int buffer[3];
};
union PacketPayload_R000052_5213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000052_5213_1
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
void fn_R000052_5213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000052_5213_2 st_1 = {0};
  struct SensorNode_R000052_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int factor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_52_1) & 63;
  aux_2 = (aux_2 + factor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_57_1)
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

  switch (phase_57_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_52_1 == factor_52_2);
  assert(phase_57_1 == phase_57_2);
}

int fn_R000052_5213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000052_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int factor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_52) & 63;
  acc ^= aux;
  int phase_57 = (aux + st.buffer[1]) & 3;
  switch (phase_57)
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

void fn_R000052_5213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_71_1 > 46)
  {
    acc_1 = ((acc_1 + (sample_71_1 * 2)) + 5) & 127;
    aux_1 ^= sample_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_71_2 > 46)
  {
    acc_2 = ((acc_2 + (sample_71_2 * 2)) + 5) & 127;
    aux_2 ^= sample_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_33_1) & 63;
  aux_2 = (aux_2 + checksum_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_71_1 == sample_71_2);
  assert(checksum_33_1 == checksum_33_2);
}

int fn_R000052_5213_1(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_71 > 46)
  {
    acc = ((acc + (sample_71 * 2)) + 5) & 127;
    aux ^= sample_71 & 15;
  }
  else
  {
    acc = ((acc - sample_71) + 11) & 127;
    aux += 3;
  }
  int checksum_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_33) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
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
  int stride_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_14_1)
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

  switch (stride_14_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_14_1 == stride_14_2);
}

int fn_R000052_5213_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_14 = (aux + st.buffer[1]) & 3;
  switch (stride_14)
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

void fn_R000052_5213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st_1 = {0};
  struct AudioFrame_R000052_5213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_26_1)
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

  switch (metric_26_2)
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

  int metric_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_68_1) & 63;
  aux_2 = (aux_2 + metric_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_26_1 == metric_26_2);
  assert(metric_68_1 == metric_68_2);
}

int fn_R000052_5213_3(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_26 = (aux + st.buffer[1]) & 3;
  switch (metric_26)
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

  int metric_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000052_5213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_82_1 = local_arr_1[aux_1 % 3];
  int offset_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_82_2 * 2)) & 127;
  int cursor_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_97_1)
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

  switch (cursor_97_2)
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

  int index_reg_22_1 = 0;
  int index_reg_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_22_1 = ((index_reg_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_22_2 = ((index_reg_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_22_1) & 127;
    acc_2 = (acc_2 + index_reg_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_82_1 == offset_82_2);
  assert(cursor_97_1 == cursor_97_2);
  assert(index_reg_22_1 == index_reg_22_2);
}

int fn_R000052_5213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int offset_82 = local_arr[aux % 3];
  acc = (acc + (offset_82 * 2)) & 127;
  int cursor_97 = (aux + st.buffer[1]) & 3;
  switch (cursor_97)
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

  int index_reg_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_22 = ((index_reg_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st_1 = {0};
  struct AudioFrame_R000052_5213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_33_1 = local_arr_1[aux_1 % 3];
  int anchor_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_33_2 * 2)) & 127;
  int accumulator_65_1 = 0;
  int accumulator_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_65_1 = ((accumulator_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_65_2 = ((accumulator_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_65_1) & 127;
    acc_2 = (acc_2 + accumulator_65_2) & 127;
  }

  int residue_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_96_1) & 63;
  aux_2 = (aux_2 + residue_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_33_1 == anchor_33_2);
  assert(accumulator_65_1 == accumulator_65_2);
  assert(residue_96_1 == residue_96_2);
}

int fn_R000052_5213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int anchor_33 = local_arr[aux % 3];
  acc = (acc + (anchor_33 * 2)) & 127;
  int accumulator_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_65 = ((accumulator_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_65) & 127;
  }

  int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000052_5213_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_94_1 = 0;
  int weight_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_94_1 = ((weight_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_94_2 = ((weight_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_94_1) & 127;
    acc_2 = (acc_2 + weight_94_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_31_1)
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

  switch (sample_31_2)
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

  int coefficient_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_30_1 > 37)
  {
    acc_1 = ((acc_1 + (coefficient_30_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_30_2 > 37)
  {
    acc_2 = ((acc_2 + (coefficient_30_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_94_1 == weight_94_2);
  assert(sample_31_1 == sample_31_2);
  assert(coefficient_30_1 == coefficient_30_2);
}

int fn_R000052_5213_6(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_94 = ((weight_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_94) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_31 = (aux + st.buffer[1]) & 3;
  switch (sample_31)
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

  int coefficient_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_30 > 37)
  {
    acc = ((acc + (coefficient_30 * 2)) + 5) & 127;
    aux ^= coefficient_30 & 15;
  }
  else
  {
    acc = ((acc - coefficient_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000052_5213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_81_1) & 63;
  aux_2 = (aux_2 + quotient_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_35_1 = 0;
  int factor_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_35_1 = ((factor_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_35_2 = ((factor_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_35_1) & 127;
    acc_2 = (acc_2 + factor_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_81_1 == quotient_81_2);
  assert(factor_35_1 == factor_35_2);
}

int fn_R000052_5213_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_81) & 63;
  acc ^= aux;
  int factor_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_35 = ((factor_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000052_5213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st_1 = {0};
  struct AudioFrame_R000052_5213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_79_1 = 0;
  int weight_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_79_1 = ((weight_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_79_2 = ((weight_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_79_1) & 127;
    acc_2 = (acc_2 + weight_79_2) & 127;
  }

  int threshold_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_81_1) & 63;
  aux_2 = (aux_2 + threshold_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_79_1 == weight_79_2);
  assert(threshold_81_1 == threshold_81_2);
}

int fn_R000052_5213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_79 = ((weight_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_79) & 127;
  }

  int threshold_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000052_5213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_82_1)
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

  switch (segment_82_2)
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
  int quantum_48_1 = local_arr_1[aux_1 % 3];
  int quantum_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_61_1) & 63;
  aux_2 = (aux_2 + margin_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_82_1 == segment_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_48_1 == quantum_48_2);
  assert(margin_61_1 == margin_61_2);
}

int fn_R000052_5213_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_82 = (aux + st.buffer[1]) & 3;
  switch (segment_82)
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
  int quantum_48 = local_arr[aux % 3];
  acc = (acc + (quantum_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000052_5213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_65_1)
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

  switch (mask_65_2)
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

  int stride_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_63_1 > 26)
  {
    acc_1 = ((acc_1 + (stride_63_1 * 2)) + 5) & 127;
    aux_1 ^= stride_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_63_2 > 26)
  {
    acc_2 = ((acc_2 + (stride_63_2 * 2)) + 5) & 127;
    aux_2 ^= stride_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(stride_63_1 == stride_63_2);
}

int fn_R000052_5213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_65 = (aux + st.buffer[1]) & 3;
  switch (mask_65)
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

  int stride_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_63 > 26)
  {
    acc = ((acc + (stride_63 * 2)) + 5) & 127;
    aux ^= stride_63 & 15;
  }
  else
  {
    acc = ((acc - stride_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000052_5213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_21_1) & 63;
  aux_2 = (aux_2 + sample_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_87_1 > 10)
  {
    acc_1 = ((acc_1 + (metric_87_1 * 2)) + 5) & 127;
    aux_1 ^= metric_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_87_2 > 10)
  {
    acc_2 = ((acc_2 + (metric_87_2 * 2)) + 5) & 127;
    aux_2 ^= metric_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_55_1 = 0;
  int weight_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_55_1 = ((weight_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_55_2 = ((weight_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_55_1) & 127;
    acc_2 = (acc_2 + weight_55_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_15_1 = local_arr_1[aux_1 % 3];
  int segment_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_21_1 == sample_21_2);
  assert(metric_87_1 == metric_87_2);
  assert(weight_55_1 == weight_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_15_1 == segment_15_2);
}

int fn_R000052_5213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_21) & 63;
  acc ^= aux;
  int metric_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_87 > 10)
  {
    acc = ((acc + (metric_87 * 2)) + 5) & 127;
    aux ^= metric_87 & 15;
  }
  else
  {
    acc = ((acc - metric_87) + 11) & 127;
    aux += 3;
  }
  int weight_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_55 = ((weight_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_55) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_15 = local_arr[aux % 3];
  acc = (acc + (segment_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_20_1 = local_arr_1[aux_1 % 3];
  int factor_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_20_2 * 2)) & 127;
  int checksum_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_28_1)
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

  switch (checksum_28_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_20_1 == factor_20_2);
  assert(checksum_28_1 == checksum_28_2);
}

int fn_R000052_5213_12(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int factor_20 = local_arr[aux % 3];
  acc = (acc + (factor_20 * 2)) & 127;
  int checksum_28 = (aux + st.buffer[1]) & 3;
  switch (checksum_28)
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

void fn_R000052_5213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st_1 = {0};
  struct AudioFrame_R000052_5213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_18_1 = local_arr_1[aux_1 % 3];
  int mask_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_87_1)
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

  switch (coefficient_87_2)
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

  int factor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_70_1) & 63;
  aux_2 = (aux_2 + factor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_18_1 == mask_18_2);
  assert(coefficient_87_1 == coefficient_87_2);
  assert(factor_70_1 == factor_70_2);
}

int fn_R000052_5213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int mask_18 = local_arr[aux % 3];
  acc = (acc + (mask_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_87 = (aux + st.buffer[1]) & 3;
  switch (coefficient_87)
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

  int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000052_5213_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st_1 = {0};
  struct AudioFrame_R000052_5213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_88_1 = local_arr_1[aux_1 % 3];
  int tracker_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_88_2 * 2)) & 127;
  int segment_38_1 = 0;
  int segment_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_38_1 = ((segment_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_38_2 = ((segment_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_38_1) & 127;
    acc_2 = (acc_2 + segment_38_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_88_1 == tracker_88_2);
  assert(segment_38_1 == segment_38_2);
}

int fn_R000052_5213_14(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000052_5213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int tracker_88 = local_arr[aux % 3];
  acc = (acc + (tracker_88 * 2)) & 127;
  int segment_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_38 = ((segment_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_38) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_67_1)
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

  switch (quantum_67_2)
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

  int scale_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_57_1 > 46)
  {
    acc_1 = ((acc_1 + (scale_57_1 * 2)) + 5) & 127;
    aux_1 ^= scale_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_57_2 > 46)
  {
    acc_2 = ((acc_2 + (scale_57_2 * 2)) + 5) & 127;
    aux_2 ^= scale_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_33_1) & 63;
  aux_2 = (aux_2 + delta_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_18_1 = 0;
  int phase_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_18_1 = ((phase_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_18_2 = ((phase_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_18_1) & 127;
    acc_2 = (acc_2 + phase_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_67_1 == quantum_67_2);
  assert(scale_57_1 == scale_57_2);
  assert(delta_33_1 == delta_33_2);
  assert(phase_18_1 == phase_18_2);
}

int fn_R000052_5213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_67 = (aux + st.buffer[1]) & 3;
  switch (quantum_67)
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

  int scale_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_57 > 46)
  {
    acc = ((acc + (scale_57 * 2)) + 5) & 127;
    aux ^= scale_57 & 15;
  }
  else
  {
    acc = ((acc - scale_57) + 11) & 127;
    aux += 3;
  }
  int delta_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_33) & 63;
  acc ^= aux;
  int phase_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_18 = ((phase_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000052_5213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int weight_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_46_1) & 63;
  aux_2 = (aux_2 + weight_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_46_1 = local_arr_1[aux_1 % 3];
  int parity_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_46_2 * 2)) & 127;
  int mask_39_1 = 0;
  int mask_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_39_1 = ((mask_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_39_2 = ((mask_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_39_1) & 127;
    acc_2 = (acc_2 + mask_39_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_46_1 == weight_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_46_1 == parity_46_2);
  assert(mask_39_1 == mask_39_2);
}

int fn_R000052_5213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_46 = local_arr[aux % 3];
  acc = (acc + (parity_46 * 2)) & 127;
  int mask_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_39 = ((mask_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_39) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_35_1 = local_arr_1[aux_1 % 3];
  int factor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_35_1 == factor_35_2);
}

int fn_R000052_5213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_35 = local_arr[aux % 3];
  acc = (acc + (factor_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_66_1 > 41)
  {
    acc_1 = ((acc_1 + (margin_66_1 * 2)) + 5) & 127;
    aux_1 ^= margin_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_66_2 > 41)
  {
    acc_2 = ((acc_2 + (margin_66_2 * 2)) + 5) & 127;
    aux_2 ^= margin_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_70_1 = local_arr_1[aux_1 % 3];
  int bound_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_70_2 * 2)) & 127;
  int mask_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_13_1)
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

  switch (mask_13_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_66_1 == margin_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_70_1 == bound_70_2);
  assert(mask_13_1 == mask_13_2);
}

int fn_R000052_5213_18(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_66 > 41)
  {
    acc = ((acc + (margin_66 * 2)) + 5) & 127;
    aux ^= margin_66 & 15;
  }
  else
  {
    acc = ((acc - margin_66) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_70 = local_arr[aux % 3];
  acc = (acc + (bound_70 * 2)) & 127;
  int mask_13 = (aux + st.buffer[1]) & 3;
  switch (mask_13)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int metric_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_84_1 > 47)
  {
    acc_1 = ((acc_1 + (metric_84_1 * 2)) + 5) & 127;
    aux_1 ^= metric_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_84_2 > 47)
  {
    acc_2 = ((acc_2 + (metric_84_2 * 2)) + 5) & 127;
    aux_2 ^= metric_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_20_1) & 63;
  aux_2 = (aux_2 + delta_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_68_1 = local_arr_1[aux_1 % 3];
  int coefficient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  assert(delta_20_1 == delta_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_68_1 == coefficient_68_2);
}

int fn_R000052_5213_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000052_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int metric_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_84 > 47)
  {
    acc = ((acc + (metric_84 * 2)) + 5) & 127;
    aux ^= metric_84 & 15;
  }
  else
  {
    acc = ((acc - metric_84) + 11) & 127;
    aux += 3;
  }
  int delta_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_68 = local_arr[aux % 3];
  acc = (acc + (coefficient_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000052_5213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st_1 = {0};
  struct Vector3D_R000052_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_19_1)
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

  switch (phase_19_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_19_1 == phase_19_2);
}

int fn_R000052_5213_20(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000052_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_19 = (aux + st.buffer[1]) & 3;
  switch (phase_19)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000052_0_1;
  int sec_r000052_0_2;
  int sec_r000052_1_1;
  int sec_r000052_1_2;
  int sec_r000052_2_1;
  int sec_r000052_2_2;
  int sec_r000052_3_1;
  int sec_r000052_3_2;
  int sec_r000052_4_1;
  int sec_r000052_4_2;
  int sec_r000052_5_1;
  int sec_r000052_5_2;
  int sec_r000052_6_1;
  int sec_r000052_6_2;
  int sec_r000052_7_1;
  int sec_r000052_7_2;
  int sec_r000052_8_1;
  int sec_r000052_8_2;
  int sec_r000052_9_1;
  int sec_r000052_9_2;
  int sec_r000052_10_1;
  int sec_r000052_10_2;
  int sec_r000052_11_1;
  int sec_r000052_11_2;
  int sec_r000052_12_1;
  int sec_r000052_12_2;
  int sec_r000052_13_1;
  int sec_r000052_13_2;
  int sec_r000052_14_1;
  int sec_r000052_14_2;
  int sec_r000052_15_1;
  int sec_r000052_15_2;
  int pub_r000052_0_1;
  int pub_r000052_0_2;
  int pub_r000052_1_1;
  int pub_r000052_1_2;
  int pub_r000052_2_1;
  int pub_r000052_2_2;
  int pub_r000052_3_1;
  int pub_r000052_3_2;
  int pub_r000052_4_1;
  int pub_r000052_4_2;
  int pub_r000052_5_1;
  int pub_r000052_5_2;
  int pub_r000052_6_1;
  int pub_r000052_6_2;
  int pub_r000052_7_1;
  int pub_r000052_7_2;
  int pub_r000052_8_1;
  int pub_r000052_8_2;
  int pub_r000052_9_1;
  int pub_r000052_9_2;
  int pub_r000052_10_1;
  int pub_r000052_10_2;
  int pub_r000052_11_1;
  int pub_r000052_11_2;
  int pub_r000052_12_1;
  int pub_r000052_12_2;
  int pub_r000052_13_1;
  int pub_r000052_13_2;
  int pub_r000052_14_1;
  int pub_r000052_14_2;
  int pub_r000052_15_1;
  int pub_r000052_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000052_0_1 >= (-100)) && (pub_r000052_0_1 <= 100));
  __CPROVER_assume((pub_r000052_0_2 >= (-100)) && (pub_r000052_0_2 <= 100));
  __CPROVER_assume((pub_r000052_1_1 >= (-100)) && (pub_r000052_1_1 <= 100));
  __CPROVER_assume((pub_r000052_1_2 >= (-100)) && (pub_r000052_1_2 <= 100));
  __CPROVER_assume((pub_r000052_2_1 >= (-100)) && (pub_r000052_2_1 <= 100));
  __CPROVER_assume((pub_r000052_2_2 >= (-100)) && (pub_r000052_2_2 <= 100));
  __CPROVER_assume((pub_r000052_3_1 >= (-100)) && (pub_r000052_3_1 <= 100));
  __CPROVER_assume((pub_r000052_3_2 >= (-100)) && (pub_r000052_3_2 <= 100));
  __CPROVER_assume((pub_r000052_4_1 >= (-100)) && (pub_r000052_4_1 <= 100));
  __CPROVER_assume((pub_r000052_4_2 >= (-100)) && (pub_r000052_4_2 <= 100));
  __CPROVER_assume((pub_r000052_5_1 >= (-100)) && (pub_r000052_5_1 <= 100));
  __CPROVER_assume((pub_r000052_5_2 >= (-100)) && (pub_r000052_5_2 <= 100));
  __CPROVER_assume((pub_r000052_6_1 >= (-100)) && (pub_r000052_6_1 <= 100));
  __CPROVER_assume((pub_r000052_6_2 >= (-100)) && (pub_r000052_6_2 <= 100));
  __CPROVER_assume((pub_r000052_7_1 >= (-100)) && (pub_r000052_7_1 <= 100));
  __CPROVER_assume((pub_r000052_7_2 >= (-100)) && (pub_r000052_7_2 <= 100));
  __CPROVER_assume((pub_r000052_8_1 >= (-100)) && (pub_r000052_8_1 <= 100));
  __CPROVER_assume((pub_r000052_8_2 >= (-100)) && (pub_r000052_8_2 <= 100));
  __CPROVER_assume((pub_r000052_9_1 >= (-100)) && (pub_r000052_9_1 <= 100));
  __CPROVER_assume((pub_r000052_9_2 >= (-100)) && (pub_r000052_9_2 <= 100));
  __CPROVER_assume((pub_r000052_10_1 >= (-100)) && (pub_r000052_10_1 <= 100));
  __CPROVER_assume((pub_r000052_10_2 >= (-100)) && (pub_r000052_10_2 <= 100));
  __CPROVER_assume((pub_r000052_11_1 >= (-100)) && (pub_r000052_11_1 <= 100));
  __CPROVER_assume((pub_r000052_11_2 >= (-100)) && (pub_r000052_11_2 <= 100));
  __CPROVER_assume((pub_r000052_12_1 >= (-100)) && (pub_r000052_12_1 <= 100));
  __CPROVER_assume((pub_r000052_12_2 >= (-100)) && (pub_r000052_12_2 <= 100));
  __CPROVER_assume((pub_r000052_13_1 >= (-100)) && (pub_r000052_13_1 <= 100));
  __CPROVER_assume((pub_r000052_13_2 >= (-100)) && (pub_r000052_13_2 <= 100));
  __CPROVER_assume((pub_r000052_14_1 >= (-100)) && (pub_r000052_14_1 <= 100));
  __CPROVER_assume((pub_r000052_14_2 >= (-100)) && (pub_r000052_14_2 <= 100));
  __CPROVER_assume((pub_r000052_15_1 >= (-100)) && (pub_r000052_15_1 <= 100));
  __CPROVER_assume((pub_r000052_15_2 >= (-100)) && (pub_r000052_15_2 <= 100));
  __CPROVER_assume((sec_r000052_0_1 >= 0) && (sec_r000052_0_1 <= 255));
  __CPROVER_assume((sec_r000052_0_2 >= 0) && (sec_r000052_0_2 <= 255));
  __CPROVER_assume((sec_r000052_1_1 >= 0) && (sec_r000052_1_1 <= 255));
  __CPROVER_assume((sec_r000052_1_2 >= 0) && (sec_r000052_1_2 <= 255));
  __CPROVER_assume((sec_r000052_2_1 >= 0) && (sec_r000052_2_1 <= 255));
  __CPROVER_assume((sec_r000052_2_2 >= 0) && (sec_r000052_2_2 <= 255));
  __CPROVER_assume((sec_r000052_3_1 >= 0) && (sec_r000052_3_1 <= 255));
  __CPROVER_assume((sec_r000052_3_2 >= 0) && (sec_r000052_3_2 <= 255));
  __CPROVER_assume((sec_r000052_4_1 >= 0) && (sec_r000052_4_1 <= 255));
  __CPROVER_assume((sec_r000052_4_2 >= 0) && (sec_r000052_4_2 <= 255));
  __CPROVER_assume((sec_r000052_5_1 >= 0) && (sec_r000052_5_1 <= 255));
  __CPROVER_assume((sec_r000052_5_2 >= 0) && (sec_r000052_5_2 <= 255));
  __CPROVER_assume((sec_r000052_6_1 >= 0) && (sec_r000052_6_1 <= 255));
  __CPROVER_assume((sec_r000052_6_2 >= 0) && (sec_r000052_6_2 <= 255));
  __CPROVER_assume((sec_r000052_7_1 >= 0) && (sec_r000052_7_1 <= 255));
  __CPROVER_assume((sec_r000052_7_2 >= 0) && (sec_r000052_7_2 <= 255));
  __CPROVER_assume((sec_r000052_8_1 >= 0) && (sec_r000052_8_1 <= 255));
  __CPROVER_assume((sec_r000052_8_2 >= 0) && (sec_r000052_8_2 <= 255));
  __CPROVER_assume((sec_r000052_9_1 >= 0) && (sec_r000052_9_1 <= 255));
  __CPROVER_assume((sec_r000052_9_2 >= 0) && (sec_r000052_9_2 <= 255));
  __CPROVER_assume((sec_r000052_10_1 >= 0) && (sec_r000052_10_1 <= 255));
  __CPROVER_assume((sec_r000052_10_2 >= 0) && (sec_r000052_10_2 <= 255));
  __CPROVER_assume((sec_r000052_11_1 >= 0) && (sec_r000052_11_1 <= 255));
  __CPROVER_assume((sec_r000052_11_2 >= 0) && (sec_r000052_11_2 <= 255));
  __CPROVER_assume((sec_r000052_12_1 >= 0) && (sec_r000052_12_1 <= 255));
  __CPROVER_assume((sec_r000052_12_2 >= 0) && (sec_r000052_12_2 <= 255));
  __CPROVER_assume((sec_r000052_13_1 >= 0) && (sec_r000052_13_1 <= 255));
  __CPROVER_assume((sec_r000052_13_2 >= 0) && (sec_r000052_13_2 <= 255));
  __CPROVER_assume((sec_r000052_14_1 >= 0) && (sec_r000052_14_1 <= 255));
  __CPROVER_assume((sec_r000052_14_2 >= 0) && (sec_r000052_14_2 <= 255));
  __CPROVER_assume((sec_r000052_15_1 >= 0) && (sec_r000052_15_1 <= 255));
  __CPROVER_assume((sec_r000052_15_2 >= 0) && (sec_r000052_15_2 <= 255));
  struct Vector3D_R000052_5213_0 st_var_0_1 = {0};
  struct Vector3D_R000052_5213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000052_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000052_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000052_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000052_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000052_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000052_0_2 + 7) & 15;
  struct StreamBuffer_R000052_5213_1 st_var_1_1 = {0};
  struct StreamBuffer_R000052_5213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000052_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000052_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000052_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000052_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000052_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000052_0_2 + 9) & 15;
  struct SensorNode_R000052_5213_2 st_var_2_1 = {0};
  struct SensorNode_R000052_5213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000052_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000052_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000052_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000052_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000052_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000052_0_2 + 11) & 15;
  struct AudioFrame_R000052_5213_3 st_var_3_1 = {0};
  struct AudioFrame_R000052_5213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000052_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000052_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000052_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000052_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000052_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000052_0_2 + 13) & 15;
  union PacketPayload_R000052_5213_0 u_var_1;
  union PacketPayload_R000052_5213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 46)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 46)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 27)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 27)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
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
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 45)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 45)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 42)
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
  if (stage_v_28_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 42)
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
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
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
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 43) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 48)
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
  if (stage_v_43_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 48)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 45) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 48) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 56) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = (st_var_1_1.buffer[0] ^ 60) & 3;
  int stage_v_57_2 = (st_var_1_2.buffer[0] ^ 60) & 3;
  switch (stage_v_57_1)
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

  switch (stage_v_57_2)
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

  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 30)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 30)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (st_var_2_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_2_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (st_var_3_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_3_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 50)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 50)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 34)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 34)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 80) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 86) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 86) & 15;
  int stage_v_85_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_85_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= stage_v_85_1;
  chk_sum_2 ^= stage_v_85_2;
  int stage_v_86_1 = (st_var_2_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_2_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  if (stage_v_89_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_89_1) - 5) & 255;
    if (stage_v_89_1 > 27)
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
  if (stage_v_89_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_89_2) - 5) & 255;
    if (stage_v_89_2 > 27)
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
  int stage_v_90_1 = ((st_var_2_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_2_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 26)
    {
      chk_sum_1 ^= stage_v_90_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_90_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 26)
    {
      chk_sum_2 ^= stage_v_90_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 96) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 96) & 15;
  int stage_v_95_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_95_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= stage_v_95_1;
  chk_sum_2 ^= stage_v_95_2;
  int stage_v_96_1 = (st_var_0_1.buffer[0] ^ 99) & 3;
  int stage_v_96_2 = (st_var_0_2.buffer[0] ^ 99) & 3;
  switch (stage_v_96_1)
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

  switch (stage_v_96_2)
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

  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_99_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_100_1 = ((st_var_0_1.buffer[1] * 2) + 307) & 63;
  int stage_v_100_2 = ((st_var_0_2.buffer[1] * 2) + 307) & 63;
  if (stage_v_100_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_100_1) - 5) & 255;
    if (stage_v_100_1 > 42)
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
  if (stage_v_100_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_100_2) - 5) & 255;
    if (stage_v_100_2 > 42)
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
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 103) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = ((st_var_3_1.buffer[1] * 2) + 316) & 63;
  int stage_v_103_2 = ((st_var_3_2.buffer[1] * 2) + 316) & 63;
  if (stage_v_103_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 42)
    {
      chk_sum_1 ^= stage_v_103_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_103_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 42)
    {
      chk_sum_2 ^= stage_v_103_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

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
  int stage_v_107_1 = ((st_var_3_1.buffer[2] * 2) + 328) & 63;
  int stage_v_107_2 = ((st_var_3_2.buffer[2] * 2) + 328) & 63;
  if (stage_v_107_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_107_1) - 5) & 255;
    if (stage_v_107_1 > 51)
    {
      chk_sum_1 ^= stage_v_107_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_107_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_107_2) - 5) & 255;
    if (stage_v_107_2 > 51)
    {
      chk_sum_2 ^= stage_v_107_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  int stage_v_110_1 = ((st_var_2_1.buffer[2] * 2) + 337) & 63;
  int stage_v_110_2 = ((st_var_2_2.buffer[2] * 2) + 337) & 63;
  if (stage_v_110_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_110_1) - 5) & 255;
    if (stage_v_110_1 > 45)
    {
      chk_sum_1 ^= stage_v_110_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_110_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_110_2) - 5) & 255;
    if (stage_v_110_2 > 45)
    {
      chk_sum_2 ^= stage_v_110_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_112_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 114) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 114) & 15;
  int stage_v_113_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_113_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= stage_v_113_1;
  chk_sum_2 ^= stage_v_113_2;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
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
  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_121_1 = table_1[1];
  int stage_v_121_2 = table_2[1];
  table_1[1] = (table_1[2] + 243) & 63;
  table_2[1] = (table_2[2] + 243) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (127 & 31);
  int stage_v_122_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (127 & 31);
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= (stage_v_122_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_122_2 << 1) & 127;
  int stage_v_123_1 = (st_var_3_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_3_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 125) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  int stage_v_125_1 = table_1[1];
  int stage_v_125_2 = table_2[1];
  table_1[1] = (table_1[2] + 251) & 63;
  table_2[1] = (table_2[2] + 251) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (st_var_2_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_2_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 129) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = table_1[3];
  int stage_v_131_2 = table_2[3];
  table_1[3] = (table_1[0] + 263) & 63;
  table_2[3] = (table_2[0] + 263) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  if (stage_v_137_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 41)
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
  if (stage_v_137_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 41)
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
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = ((st_var_0_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_0_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 47)
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
  if (stage_v_140_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 47)
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

  switch (stage_v_141_2)
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

  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 143) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_144_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (149 & 31);
  int stage_v_144_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (149 & 31);
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= (stage_v_144_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_144_2 << 1) & 127;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = ((st_var_2_1.buffer[2] * 2) + 445) & 63;
  int stage_v_146_2 = ((st_var_2_2.buffer[2] * 2) + 445) & 63;
  if (stage_v_146_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_146_1) - 5) & 255;
    if (stage_v_146_1 > 30)
    {
      chk_sum_1 ^= stage_v_146_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_146_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_146_2) - 5) & 255;
    if (stage_v_146_2 > 30)
    {
      chk_sum_2 ^= stage_v_146_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (st_var_2_1.buffer[0] ^ 153) & 3;
  int stage_v_150_2 = (st_var_2_2.buffer[0] ^ 153) & 3;
  switch (stage_v_150_1)
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

  switch (stage_v_150_2)
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

  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 153) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (st_var_2_1.buffer[0] ^ 157) & 3;
  int stage_v_154_2 = (st_var_2_2.buffer[0] ^ 157) & 3;
  switch (stage_v_154_1)
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

  switch (stage_v_154_2)
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

  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 52)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 52)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 54)
    {
      chk_sum_1 ^= stage_v_157_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_157_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 54)
    {
      chk_sum_2 ^= stage_v_157_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 159) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (164 & 31);
  int stage_v_159_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (164 & 31);
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= (stage_v_159_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_159_2 << 1) & 127;
  int stage_v_160_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (165 & 31);
  int stage_v_160_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (165 & 31);
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= (stage_v_160_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_160_2 << 1) & 127;
  int stage_v_161_1 = (st_var_1_1.buffer[0] ^ 164) & 3;
  int stage_v_161_2 = (st_var_1_2.buffer[0] ^ 164) & 3;
  switch (stage_v_161_1)
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

  switch (stage_v_161_2)
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

  int stage_v_162_1 = ((st_var_2_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_2_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 43)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 43)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 165) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 165) & 15;
  int stage_v_164_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_164_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= stage_v_164_1;
  chk_sum_2 ^= stage_v_164_2;
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 168) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 169) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 169) & 15;
  int stage_v_168_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_168_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= stage_v_168_1;
  chk_sum_2 ^= stage_v_168_2;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((st_var_3_1.buffer[0] * 2) + 520) & 63;
  int stage_v_171_2 = ((st_var_3_2.buffer[0] * 2) + 520) & 63;
  if (stage_v_171_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_171_1) - 5) & 255;
    if (stage_v_171_1 > 55)
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
  if (stage_v_171_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_171_2) - 5) & 255;
    if (stage_v_171_2 > 55)
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
  int stage_v_172_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (177 & 31);
  int stage_v_172_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (177 & 31);
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  chk_sum_1 ^= (stage_v_172_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_172_2 << 1) & 127;
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = (st_var_2_1.buffer[0] ^ 177) & 3;
  int stage_v_174_2 = (st_var_2_2.buffer[0] ^ 177) & 3;
  switch (stage_v_174_1)
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

  switch (stage_v_174_2)
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

  int stage_v_175_1 = (st_var_3_1.buffer[0] ^ 178) & 3;
  int stage_v_175_2 = (st_var_3_2.buffer[0] ^ 178) & 3;
  switch (stage_v_175_1)
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

  switch (stage_v_175_2)
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

  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 26)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 26)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 178) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 178) & 15;
  int stage_v_177_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_177_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= stage_v_177_1;
  chk_sum_2 ^= stage_v_177_2;
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
  int stage_v_179_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_179_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_180_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (185 & 31);
  int stage_v_180_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (185 & 31);
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  chk_sum_1 ^= (stage_v_180_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_180_2 << 1) & 127;
  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((st_var_2_1.buffer[2] * 2) + 553) & 63;
  int stage_v_182_2 = ((st_var_2_2.buffer[2] * 2) + 553) & 63;
  if (stage_v_182_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_182_1) - 5) & 255;
    if (stage_v_182_1 > 51)
    {
      chk_sum_1 ^= stage_v_182_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_182_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_182_2) - 5) & 255;
    if (stage_v_182_2 > 51)
    {
      chk_sum_2 ^= stage_v_182_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int dead_sec_0_1 = ((sec_r000052_12_1 << 2) ^ (sec_r000052_12_1 << 2)) * 0;
  int dead_sec_0_2 = ((sec_r000052_12_2 << 2) ^ (sec_r000052_12_2 << 2)) * 0;
  int dead_sec_1_1 = (sec_r000052_15_1 & 0) * 0;
  int dead_sec_1_2 = (sec_r000052_15_2 & 0) * 0;
  int dead_sec_2_1 = (sec_r000052_12_1 ^ sec_r000052_12_1) * 0;
  int dead_sec_2_2 = (sec_r000052_12_2 ^ sec_r000052_12_2) * 0;
  int dead_sec_3_1 = ((sec_r000052_15_1 << 2) ^ (sec_r000052_15_1 << 2)) * 0;
  int dead_sec_3_2 = ((sec_r000052_15_2 << 2) ^ (sec_r000052_15_2 << 2)) * 0;
  out_sink_1 = ((((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) + dead_sec_2_1) + dead_sec_3_1) & 255;
  out_sink_2 = ((((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) + dead_sec_2_2) + dead_sec_3_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000052_1_1 == pub_r000052_1_2);
  __CPROVER_assume(pub_r000052_3_1 == pub_r000052_3_2);
  __CPROVER_assume(sec_r000052_13_1 != sec_r000052_13_2);
  __CPROVER_assume(pub_r000052_0_1 == pub_r000052_0_2);
  __CPROVER_assume(pub_r000052_13_1 == pub_r000052_13_2);
  __CPROVER_assume(pub_r000052_12_1 == pub_r000052_12_2);
  __CPROVER_assume(pub_r000052_5_1 == pub_r000052_5_2);
  __CPROVER_assume(sec_r000052_7_1 != sec_r000052_7_2);
  __CPROVER_assume(sec_r000052_10_1 != sec_r000052_10_2);
  __CPROVER_assume(sec_r000052_9_1 != sec_r000052_9_2);
  __CPROVER_assume(sec_r000052_4_1 != sec_r000052_4_2);
  __CPROVER_assume(sec_r000052_12_1 != sec_r000052_12_2);
  __CPROVER_assume(sec_r000052_14_1 != sec_r000052_14_2);
  __CPROVER_assume(sec_r000052_1_1 != sec_r000052_1_2);
  __CPROVER_assume(pub_r000052_4_1 == pub_r000052_4_2);
  __CPROVER_assume(sec_r000052_0_1 != sec_r000052_0_2);
  __CPROVER_assume(sec_r000052_3_1 != sec_r000052_3_2);
  __CPROVER_assume(pub_r000052_7_1 == pub_r000052_7_2);
  __CPROVER_assume(sec_r000052_5_1 != sec_r000052_5_2);
  __CPROVER_assume(pub_r000052_6_1 == pub_r000052_6_2);
  __CPROVER_assume(pub_r000052_11_1 == pub_r000052_11_2);
  __CPROVER_assume(sec_r000052_8_1 != sec_r000052_8_2);
  __CPROVER_assume(pub_r000052_2_1 == pub_r000052_2_2);
  __CPROVER_assume(pub_r000052_14_1 == pub_r000052_14_2);
  __CPROVER_assume(sec_r000052_11_1 != sec_r000052_11_2);
  __CPROVER_assume(sec_r000052_15_1 != sec_r000052_15_2);
  __CPROVER_assume(sec_r000052_6_1 != sec_r000052_6_2);
  __CPROVER_assume(sec_r000052_2_1 != sec_r000052_2_2);
  __CPROVER_assume(pub_r000052_10_1 == pub_r000052_10_2);
  __CPROVER_assume(pub_r000052_8_1 == pub_r000052_8_2);
  __CPROVER_assume(pub_r000052_15_1 == pub_r000052_15_2);
  __CPROVER_assume(pub_r000052_9_1 == pub_r000052_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
  assert(dead_sec_2_1 == dead_sec_2_2);
  assert(dead_sec_3_1 == dead_sec_3_2);
}


