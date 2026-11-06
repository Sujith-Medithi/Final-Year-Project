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
struct AudioFrame_R000114_1413_0
{
  int envelope;
  short sample_rate;
  short peak;
  unsigned char rms;
  int buffer[3];
};
struct StreamBuffer_R000114_1413_1
{
  short checksum;
  int state;
  int watermark;
  short capacity;
  short tail;
  unsigned char head;
  int buffer[3];
};
struct Transaction_R000114_1413_2
{
  int status;
  int rate;
  unsigned char balance;
  short auth_code;
  int account_id;
  int buffer[3];
};
union PacketPayload_R000114_1413_0
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
void fn_R000114_1413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_12_1 > 42)
  {
    acc_1 = ((acc_1 + (quotient_12_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_12_2 > 42)
  {
    acc_2 = ((acc_2 + (quotient_12_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_27_1) & 63;
  aux_2 = (aux_2 + index_reg_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_70_1 = local_arr_1[aux_1 % 3];
  int residue_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_70_2 * 2)) & 127;
  int metric_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_64_1)
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

  switch (metric_64_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_12_1 == quotient_12_2);
  assert(index_reg_27_1 == index_reg_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_70_1 == residue_70_2);
  assert(metric_64_1 == metric_64_2);
}

int fn_R000114_1413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_12 > 42)
  {
    acc = ((acc + (quotient_12 * 2)) + 5) & 127;
    aux ^= quotient_12 & 15;
  }
  else
  {
    acc = ((acc - quotient_12) + 11) & 127;
    aux += 3;
  }
  int index_reg_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_27) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_70 = local_arr[aux % 3];
  acc = (acc + (residue_70 * 2)) & 127;
  int metric_64 = (aux + st.buffer[1]) & 3;
  switch (metric_64)
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

void fn_R000114_1413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_57_1 = local_arr_1[aux_1 % 3];
  int sample_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_57_2 * 2)) & 127;
  int segment_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_59_1) & 63;
  aux_2 = (aux_2 + segment_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_57_1 == sample_57_2);
  assert(segment_59_1 == segment_59_2);
}

int fn_R000114_1413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_57 = local_arr[aux % 3];
  acc = (acc + (sample_57 * 2)) & 127;
  int segment_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st_1 = {0};
  struct AudioFrame_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int window_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_31_1) & 63;
  aux_2 = (aux_2 + window_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_46_1 > 21)
  {
    acc_1 = ((acc_1 + (delta_46_1 * 2)) + 5) & 127;
    aux_1 ^= delta_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_46_2 > 21)
  {
    acc_2 = ((acc_2 + (delta_46_2 * 2)) + 5) & 127;
    aux_2 ^= delta_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_28_1 = local_arr_1[aux_1 % 3];
  int factor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_31_1 == window_31_2);
  assert(delta_46_1 == delta_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_28_1 == factor_28_2);
}

int fn_R000114_1413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_31) & 63;
  acc ^= aux;
  int delta_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_46 > 21)
  {
    acc = ((acc + (delta_46 * 2)) + 5) & 127;
    aux ^= delta_46 & 15;
  }
  else
  {
    acc = ((acc - delta_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_28 = local_arr[aux % 3];
  acc = (acc + (factor_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_97_1)
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

  switch (anchor_97_2)
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

  int accumulator_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_65_1) & 63;
  aux_2 = (aux_2 + accumulator_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_97_1 == anchor_97_2);
  assert(accumulator_65_1 == accumulator_65_2);
}

int fn_R000114_1413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_97 = (aux + st.buffer[1]) & 3;
  switch (anchor_97)
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

  int accumulator_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_58_1) & 63;
  aux_2 = (aux_2 + stride_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_37_1 > 30)
  {
    acc_1 = ((acc_1 + (tally_37_1 * 2)) + 5) & 127;
    aux_1 ^= tally_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_37_2 > 30)
  {
    acc_2 = ((acc_2 + (tally_37_2 * 2)) + 5) & 127;
    aux_2 ^= tally_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_74_1)
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

  switch (cursor_74_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_58_1 == stride_58_2);
  assert(tally_37_1 == tally_37_2);
  assert(cursor_74_1 == cursor_74_2);
}

int fn_R000114_1413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_58) & 63;
  acc ^= aux;
  int tally_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_37 > 30)
  {
    acc = ((acc + (tally_37 * 2)) + 5) & 127;
    aux ^= tally_37 & 15;
  }
  else
  {
    acc = ((acc - tally_37) + 11) & 127;
    aux += 3;
  }
  int cursor_74 = (aux + st.buffer[1]) & 3;
  switch (cursor_74)
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

void fn_R000114_1413_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_81_1)
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

  switch (damping_81_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_77_1 = local_arr_1[aux_1 % 3];
  int cursor_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_81_1 == damping_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_77_1 == cursor_77_2);
}

int fn_R000114_1413_5(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_81 = (aux + st.buffer[1]) & 3;
  switch (damping_81)
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

  int local_arr[3] = {4, 9, 15};
  int cursor_77 = local_arr[aux % 3];
  acc = (acc + (cursor_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_64_1 = local_arr_1[aux_1 % 3];
  int checksum_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_64_2 * 2)) & 127;
  int phase_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_61_1 > 22)
  {
    acc_1 = ((acc_1 + (phase_61_1 * 2)) + 5) & 127;
    aux_1 ^= phase_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_61_2 > 22)
  {
    acc_2 = ((acc_2 + (phase_61_2 * 2)) + 5) & 127;
    aux_2 ^= phase_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_55_1) & 63;
  aux_2 = (aux_2 + margin_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_64_1 == checksum_64_2);
  assert(phase_61_1 == phase_61_2);
  assert(margin_55_1 == margin_55_2);
}

int fn_R000114_1413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_64 = local_arr[aux % 3];
  acc = (acc + (checksum_64 * 2)) & 127;
  int phase_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_61 > 22)
  {
    acc = ((acc + (phase_61 * 2)) + 5) & 127;
    aux ^= phase_61 & 15;
  }
  else
  {
    acc = ((acc - phase_61) + 11) & 127;
    aux += 3;
  }
  int margin_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_79_1 = local_arr_1[aux_1 % 3];
  int coefficient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_79_2 * 2)) & 127;
  int parity_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_39_1)
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

  switch (parity_39_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
  assert(parity_39_1 == parity_39_2);
}

int fn_R000114_1413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int coefficient_79 = local_arr[aux % 3];
  acc = (acc + (coefficient_79 * 2)) & 127;
  int parity_39 = (aux + st.buffer[1]) & 3;
  switch (parity_39)
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

void fn_R000114_1413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_43_1) & 63;
  aux_2 = (aux_2 + window_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
}

int fn_R000114_1413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_43) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st_1 = {0};
  struct AudioFrame_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_50_1) & 63;
  aux_2 = (aux_2 + sample_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_54_1 > 13)
  {
    acc_1 = ((acc_1 + (delta_54_1 * 2)) + 5) & 127;
    aux_1 ^= delta_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_54_2 > 13)
  {
    acc_2 = ((acc_2 + (delta_54_2 * 2)) + 5) & 127;
    aux_2 ^= delta_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_52_1 = local_arr_1[aux_1 % 3];
  int bound_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_52_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_50_1 == sample_50_2);
  assert(delta_54_1 == delta_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_52_1 == bound_52_2);
}

int fn_R000114_1413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_50) & 63;
  acc ^= aux;
  int delta_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_54 > 13)
  {
    acc = ((acc + (delta_54 * 2)) + 5) & 127;
    aux ^= delta_54 & 15;
  }
  else
  {
    acc = ((acc - delta_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_52 = local_arr[aux % 3];
  acc = (acc + (bound_52 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
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
  int scale_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_74_1)
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

  switch (scale_74_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_63_1 = local_arr_1[aux_1 % 3];
  int mask_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_74_1 == scale_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_63_1 == mask_63_2);
}

int fn_R000114_1413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_74 = (aux + st.buffer[1]) & 3;
  switch (scale_74)
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

  int local_arr[3] = {4, 9, 15};
  int mask_63 = local_arr[aux % 3];
  acc = (acc + (mask_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_18_1 > 36)
  {
    acc_1 = ((acc_1 + (weight_18_1 * 2)) + 5) & 127;
    aux_1 ^= weight_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_18_2 > 36)
  {
    acc_2 = ((acc_2 + (weight_18_2 * 2)) + 5) & 127;
    aux_2 ^= weight_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_64_1 = local_arr_1[aux_1 % 3];
  int quotient_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_64_2 * 2)) & 127;
  int weight_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_96_1)
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

  switch (weight_96_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_18_1 == weight_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_64_1 == quotient_64_2);
  assert(weight_96_1 == weight_96_2);
}

int fn_R000114_1413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_18 > 36)
  {
    acc = ((acc + (weight_18 * 2)) + 5) & 127;
    aux ^= weight_18 & 15;
  }
  else
  {
    acc = ((acc - weight_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_64 = local_arr[aux % 3];
  acc = (acc + (quotient_64 * 2)) & 127;
  int weight_96 = (aux + st.buffer[1]) & 3;
  switch (weight_96)
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

void fn_R000114_1413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st_1 = {0};
  struct AudioFrame_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_87_1 > 48)
  {
    acc_1 = ((acc_1 + (cursor_87_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_87_2 > 48)
  {
    acc_2 = ((acc_2 + (cursor_87_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_11_1 = local_arr_1[aux_1 % 3];
  int bound_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_11_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_24_1) & 63;
  aux_2 = (aux_2 + checksum_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_87_1 == cursor_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_11_1 == bound_11_2);
  assert(checksum_24_1 == checksum_24_2);
}

int fn_R000114_1413_12(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_87 > 48)
  {
    acc = ((acc + (cursor_87 * 2)) + 5) & 127;
    aux ^= cursor_87 & 15;
  }
  else
  {
    acc = ((acc - cursor_87) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_11 = local_arr[aux % 3];
  acc = (acc + (bound_11 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int stride_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_67_1)
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

  switch (stride_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_98_1 = local_arr_1[aux_1 % 3];
  int sample_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_98_2 * 2)) & 127;
  int pivot_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_39_1) & 63;
  aux_2 = (aux_2 + pivot_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_67_1 == stride_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_98_1 == sample_98_2);
  assert(pivot_39_1 == pivot_39_2);
}

int fn_R000114_1413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int stride_67 = (aux + st.buffer[1]) & 3;
  switch (stride_67)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_98 = local_arr[aux % 3];
  acc = (acc + (sample_98 * 2)) & 127;
  int pivot_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st_1 = {0};
  struct AudioFrame_R000114_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int damping_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_83_1) & 63;
  aux_2 = (aux_2 + damping_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_15_1)
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

  switch (tracker_15_2)
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
  int threshold_21_1 = local_arr_1[aux_1 % 3];
  int threshold_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_83_1 == damping_83_2);
  assert(tracker_15_1 == tracker_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_21_1 == threshold_21_2);
}

int fn_R000114_1413_14(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000114_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int damping_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_83) & 63;
  acc ^= aux;
  int tracker_15 = (aux + st.buffer[1]) & 3;
  switch (tracker_15)
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
  int threshold_21 = local_arr[aux % 3];
  acc = (acc + (threshold_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_70_1 = local_arr_1[aux_1 % 3];
  int coefficient_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_70_2 * 2)) & 127;
  int index_reg_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_34_1)
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

  switch (index_reg_34_2)
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

  int checksum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_37_1 > 29)
  {
    acc_1 = ((acc_1 + (checksum_37_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_37_2 > 29)
  {
    acc_2 = ((acc_2 + (checksum_37_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
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

  assert(coefficient_70_1 == coefficient_70_2);
  assert(index_reg_34_1 == index_reg_34_2);
  assert(checksum_37_1 == checksum_37_2);
}

int fn_R000114_1413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int coefficient_70 = local_arr[aux % 3];
  acc = (acc + (coefficient_70 * 2)) & 127;
  int index_reg_34 = (aux + st.buffer[1]) & 3;
  switch (index_reg_34)
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

  int checksum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_37 > 29)
  {
    acc = ((acc + (checksum_37 * 2)) + 5) & 127;
    aux ^= checksum_37 & 15;
  }
  else
  {
    acc = ((acc - checksum_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int coefficient_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_73_1)
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

  switch (coefficient_73_2)
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

  int sample_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_88_1) & 63;
  aux_2 = (aux_2 + sample_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_73_1 == coefficient_73_2);
  assert(sample_88_1 == sample_88_2);
}

int fn_R000114_1413_16(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int coefficient_73 = (aux + st.buffer[1]) & 3;
  switch (coefficient_73)
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

  int sample_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_72_1 = local_arr_1[aux_1 % 3];
  int window_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_72_2 * 2)) & 127;
  int threshold_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_14_1)
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

  switch (threshold_14_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_72_1 == window_72_2);
  assert(threshold_14_1 == threshold_14_2);
}

int fn_R000114_1413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000114_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int window_72 = local_arr[aux % 3];
  acc = (acc + (window_72 * 2)) & 127;
  int threshold_14 = (aux + st.buffer[1]) & 3;
  switch (threshold_14)
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

void fn_R000114_1413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_92_1 = local_arr_1[aux_1 % 3];
  int pivot_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_92_2 * 2)) & 127;
  int residue_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_92_1) & 63;
  aux_2 = (aux_2 + residue_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
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

  assert(pivot_92_1 == pivot_92_2);
  assert(residue_92_1 == residue_92_2);
}

int fn_R000114_1413_18(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_92 = local_arr[aux % 3];
  acc = (acc + (pivot_92 * 2)) & 127;
  int residue_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000114_1413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_13_1)
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

  switch (pivot_13_2)
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

  int cursor_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_37_1) & 63;
  aux_2 = (aux_2 + cursor_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_17_1 = local_arr_1[aux_1 % 3];
  int anchor_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_13_1 == pivot_13_2);
  assert(cursor_37_1 == cursor_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_17_1 == anchor_17_2);
}

int fn_R000114_1413_19(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_13 = (aux + st.buffer[1]) & 3;
  switch (pivot_13)
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

  int cursor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_17 = local_arr[aux % 3];
  acc = (acc + (anchor_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_24_1) & 63;
  aux_2 = (aux_2 + vector_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_80_1)
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

  switch (damping_80_2)
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
  int bound_54_1 = local_arr_1[aux_1 % 3];
  int bound_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_24_1 == vector_24_2);
  assert(damping_80_1 == damping_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_54_1 == bound_54_2);
}

int fn_R000114_1413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_24) & 63;
  acc ^= aux;
  int damping_80 = (aux + st.buffer[1]) & 3;
  switch (damping_80)
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
  int bound_54 = local_arr[aux % 3];
  acc = (acc + (bound_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000114_1413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st_1 = {0};
  struct Transaction_R000114_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_42_1 = local_arr_1[aux_1 % 3];
  int coefficient_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_42_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
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

  assert(coefficient_42_1 == coefficient_42_2);
}

int fn_R000114_1413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000114_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int coefficient_42 = local_arr[aux % 3];
  acc = (acc + (coefficient_42 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000114_0_1;
  int sec_r000114_0_2;
  int sec_r000114_1_1;
  int sec_r000114_1_2;
  int sec_r000114_2_1;
  int sec_r000114_2_2;
  int sec_r000114_3_1;
  int sec_r000114_3_2;
  int sec_r000114_4_1;
  int sec_r000114_4_2;
  int sec_r000114_5_1;
  int sec_r000114_5_2;
  int sec_r000114_6_1;
  int sec_r000114_6_2;
  int sec_r000114_7_1;
  int sec_r000114_7_2;
  int sec_r000114_8_1;
  int sec_r000114_8_2;
  int sec_r000114_9_1;
  int sec_r000114_9_2;
  int sec_r000114_10_1;
  int sec_r000114_10_2;
  int sec_r000114_11_1;
  int sec_r000114_11_2;
  int sec_r000114_12_1;
  int sec_r000114_12_2;
  int sec_r000114_13_1;
  int sec_r000114_13_2;
  int sec_r000114_14_1;
  int sec_r000114_14_2;
  int sec_r000114_15_1;
  int sec_r000114_15_2;
  int sec_r000114_16_1;
  int sec_r000114_16_2;
  int sec_r000114_17_1;
  int sec_r000114_17_2;
  int sec_r000114_18_1;
  int sec_r000114_18_2;
  int sec_r000114_19_1;
  int sec_r000114_19_2;
  int sec_r000114_20_1;
  int sec_r000114_20_2;
  int pub_r000114_0_1;
  int pub_r000114_0_2;
  int pub_r000114_1_1;
  int pub_r000114_1_2;
  int pub_r000114_2_1;
  int pub_r000114_2_2;
  int pub_r000114_3_1;
  int pub_r000114_3_2;
  int pub_r000114_4_1;
  int pub_r000114_4_2;
  int pub_r000114_5_1;
  int pub_r000114_5_2;
  int pub_r000114_6_1;
  int pub_r000114_6_2;
  int pub_r000114_7_1;
  int pub_r000114_7_2;
  int pub_r000114_8_1;
  int pub_r000114_8_2;
  int pub_r000114_9_1;
  int pub_r000114_9_2;
  int pub_r000114_10_1;
  int pub_r000114_10_2;
  int pub_r000114_11_1;
  int pub_r000114_11_2;
  int pub_r000114_12_1;
  int pub_r000114_12_2;
  int pub_r000114_13_1;
  int pub_r000114_13_2;
  int pub_r000114_14_1;
  int pub_r000114_14_2;
  int pub_r000114_15_1;
  int pub_r000114_15_2;
  int pub_r000114_16_1;
  int pub_r000114_16_2;
  int pub_r000114_17_1;
  int pub_r000114_17_2;
  int pub_r000114_18_1;
  int pub_r000114_18_2;
  int pub_r000114_19_1;
  int pub_r000114_19_2;
  int pub_r000114_20_1;
  int pub_r000114_20_2;
  int pub_r000114_21_1;
  int pub_r000114_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000114_0_1 >= (-100)) && (pub_r000114_0_1 <= 100));
  __CPROVER_assume((pub_r000114_0_2 >= (-100)) && (pub_r000114_0_2 <= 100));
  __CPROVER_assume((pub_r000114_1_1 >= (-100)) && (pub_r000114_1_1 <= 100));
  __CPROVER_assume((pub_r000114_1_2 >= (-100)) && (pub_r000114_1_2 <= 100));
  __CPROVER_assume((pub_r000114_2_1 >= (-100)) && (pub_r000114_2_1 <= 100));
  __CPROVER_assume((pub_r000114_2_2 >= (-100)) && (pub_r000114_2_2 <= 100));
  __CPROVER_assume((pub_r000114_3_1 >= (-100)) && (pub_r000114_3_1 <= 100));
  __CPROVER_assume((pub_r000114_3_2 >= (-100)) && (pub_r000114_3_2 <= 100));
  __CPROVER_assume((pub_r000114_4_1 >= (-100)) && (pub_r000114_4_1 <= 100));
  __CPROVER_assume((pub_r000114_4_2 >= (-100)) && (pub_r000114_4_2 <= 100));
  __CPROVER_assume((pub_r000114_5_1 >= (-100)) && (pub_r000114_5_1 <= 100));
  __CPROVER_assume((pub_r000114_5_2 >= (-100)) && (pub_r000114_5_2 <= 100));
  __CPROVER_assume((pub_r000114_6_1 >= (-100)) && (pub_r000114_6_1 <= 100));
  __CPROVER_assume((pub_r000114_6_2 >= (-100)) && (pub_r000114_6_2 <= 100));
  __CPROVER_assume((pub_r000114_7_1 >= (-100)) && (pub_r000114_7_1 <= 100));
  __CPROVER_assume((pub_r000114_7_2 >= (-100)) && (pub_r000114_7_2 <= 100));
  __CPROVER_assume((pub_r000114_8_1 >= (-100)) && (pub_r000114_8_1 <= 100));
  __CPROVER_assume((pub_r000114_8_2 >= (-100)) && (pub_r000114_8_2 <= 100));
  __CPROVER_assume((pub_r000114_9_1 >= (-100)) && (pub_r000114_9_1 <= 100));
  __CPROVER_assume((pub_r000114_9_2 >= (-100)) && (pub_r000114_9_2 <= 100));
  __CPROVER_assume((pub_r000114_10_1 >= (-100)) && (pub_r000114_10_1 <= 100));
  __CPROVER_assume((pub_r000114_10_2 >= (-100)) && (pub_r000114_10_2 <= 100));
  __CPROVER_assume((pub_r000114_11_1 >= (-100)) && (pub_r000114_11_1 <= 100));
  __CPROVER_assume((pub_r000114_11_2 >= (-100)) && (pub_r000114_11_2 <= 100));
  __CPROVER_assume((pub_r000114_12_1 >= (-100)) && (pub_r000114_12_1 <= 100));
  __CPROVER_assume((pub_r000114_12_2 >= (-100)) && (pub_r000114_12_2 <= 100));
  __CPROVER_assume((pub_r000114_13_1 >= (-100)) && (pub_r000114_13_1 <= 100));
  __CPROVER_assume((pub_r000114_13_2 >= (-100)) && (pub_r000114_13_2 <= 100));
  __CPROVER_assume((pub_r000114_14_1 >= (-100)) && (pub_r000114_14_1 <= 100));
  __CPROVER_assume((pub_r000114_14_2 >= (-100)) && (pub_r000114_14_2 <= 100));
  __CPROVER_assume((pub_r000114_15_1 >= (-100)) && (pub_r000114_15_1 <= 100));
  __CPROVER_assume((pub_r000114_15_2 >= (-100)) && (pub_r000114_15_2 <= 100));
  __CPROVER_assume((pub_r000114_16_1 >= (-100)) && (pub_r000114_16_1 <= 100));
  __CPROVER_assume((pub_r000114_16_2 >= (-100)) && (pub_r000114_16_2 <= 100));
  __CPROVER_assume((pub_r000114_17_1 >= (-100)) && (pub_r000114_17_1 <= 100));
  __CPROVER_assume((pub_r000114_17_2 >= (-100)) && (pub_r000114_17_2 <= 100));
  __CPROVER_assume((pub_r000114_18_1 >= (-100)) && (pub_r000114_18_1 <= 100));
  __CPROVER_assume((pub_r000114_18_2 >= (-100)) && (pub_r000114_18_2 <= 100));
  __CPROVER_assume((pub_r000114_19_1 >= (-100)) && (pub_r000114_19_1 <= 100));
  __CPROVER_assume((pub_r000114_19_2 >= (-100)) && (pub_r000114_19_2 <= 100));
  __CPROVER_assume((pub_r000114_20_1 >= (-100)) && (pub_r000114_20_1 <= 100));
  __CPROVER_assume((pub_r000114_20_2 >= (-100)) && (pub_r000114_20_2 <= 100));
  __CPROVER_assume((pub_r000114_21_1 >= (-100)) && (pub_r000114_21_1 <= 100));
  __CPROVER_assume((pub_r000114_21_2 >= (-100)) && (pub_r000114_21_2 <= 100));
  __CPROVER_assume((sec_r000114_0_1 >= 0) && (sec_r000114_0_1 <= 255));
  __CPROVER_assume((sec_r000114_0_2 >= 0) && (sec_r000114_0_2 <= 255));
  __CPROVER_assume((sec_r000114_1_1 >= 0) && (sec_r000114_1_1 <= 255));
  __CPROVER_assume((sec_r000114_1_2 >= 0) && (sec_r000114_1_2 <= 255));
  __CPROVER_assume((sec_r000114_2_1 >= 0) && (sec_r000114_2_1 <= 255));
  __CPROVER_assume((sec_r000114_2_2 >= 0) && (sec_r000114_2_2 <= 255));
  __CPROVER_assume((sec_r000114_3_1 >= 0) && (sec_r000114_3_1 <= 255));
  __CPROVER_assume((sec_r000114_3_2 >= 0) && (sec_r000114_3_2 <= 255));
  __CPROVER_assume((sec_r000114_4_1 >= 0) && (sec_r000114_4_1 <= 255));
  __CPROVER_assume((sec_r000114_4_2 >= 0) && (sec_r000114_4_2 <= 255));
  __CPROVER_assume((sec_r000114_5_1 >= 0) && (sec_r000114_5_1 <= 255));
  __CPROVER_assume((sec_r000114_5_2 >= 0) && (sec_r000114_5_2 <= 255));
  __CPROVER_assume((sec_r000114_6_1 >= 0) && (sec_r000114_6_1 <= 255));
  __CPROVER_assume((sec_r000114_6_2 >= 0) && (sec_r000114_6_2 <= 255));
  __CPROVER_assume((sec_r000114_7_1 >= 0) && (sec_r000114_7_1 <= 255));
  __CPROVER_assume((sec_r000114_7_2 >= 0) && (sec_r000114_7_2 <= 255));
  __CPROVER_assume((sec_r000114_8_1 >= 0) && (sec_r000114_8_1 <= 255));
  __CPROVER_assume((sec_r000114_8_2 >= 0) && (sec_r000114_8_2 <= 255));
  __CPROVER_assume((sec_r000114_9_1 >= 0) && (sec_r000114_9_1 <= 255));
  __CPROVER_assume((sec_r000114_9_2 >= 0) && (sec_r000114_9_2 <= 255));
  __CPROVER_assume((sec_r000114_10_1 >= 0) && (sec_r000114_10_1 <= 255));
  __CPROVER_assume((sec_r000114_10_2 >= 0) && (sec_r000114_10_2 <= 255));
  __CPROVER_assume((sec_r000114_11_1 >= 0) && (sec_r000114_11_1 <= 255));
  __CPROVER_assume((sec_r000114_11_2 >= 0) && (sec_r000114_11_2 <= 255));
  __CPROVER_assume((sec_r000114_12_1 >= 0) && (sec_r000114_12_1 <= 255));
  __CPROVER_assume((sec_r000114_12_2 >= 0) && (sec_r000114_12_2 <= 255));
  __CPROVER_assume((sec_r000114_13_1 >= 0) && (sec_r000114_13_1 <= 255));
  __CPROVER_assume((sec_r000114_13_2 >= 0) && (sec_r000114_13_2 <= 255));
  __CPROVER_assume((sec_r000114_14_1 >= 0) && (sec_r000114_14_1 <= 255));
  __CPROVER_assume((sec_r000114_14_2 >= 0) && (sec_r000114_14_2 <= 255));
  __CPROVER_assume((sec_r000114_15_1 >= 0) && (sec_r000114_15_1 <= 255));
  __CPROVER_assume((sec_r000114_15_2 >= 0) && (sec_r000114_15_2 <= 255));
  __CPROVER_assume((sec_r000114_16_1 >= 0) && (sec_r000114_16_1 <= 255));
  __CPROVER_assume((sec_r000114_16_2 >= 0) && (sec_r000114_16_2 <= 255));
  __CPROVER_assume((sec_r000114_17_1 >= 0) && (sec_r000114_17_1 <= 255));
  __CPROVER_assume((sec_r000114_17_2 >= 0) && (sec_r000114_17_2 <= 255));
  __CPROVER_assume((sec_r000114_18_1 >= 0) && (sec_r000114_18_1 <= 255));
  __CPROVER_assume((sec_r000114_18_2 >= 0) && (sec_r000114_18_2 <= 255));
  __CPROVER_assume((sec_r000114_19_1 >= 0) && (sec_r000114_19_1 <= 255));
  __CPROVER_assume((sec_r000114_19_2 >= 0) && (sec_r000114_19_2 <= 255));
  __CPROVER_assume((sec_r000114_20_1 >= 0) && (sec_r000114_20_1 <= 255));
  __CPROVER_assume((sec_r000114_20_2 >= 0) && (sec_r000114_20_2 <= 255));
  struct AudioFrame_R000114_1413_0 st_var_0_1 = {0};
  struct AudioFrame_R000114_1413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000114_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000114_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000114_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000114_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000114_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000114_0_2 + 7) & 15;
  struct StreamBuffer_R000114_1413_1 st_var_1_1 = {0};
  struct StreamBuffer_R000114_1413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000114_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000114_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000114_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000114_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000114_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000114_0_2 + 9) & 15;
  struct Transaction_R000114_1413_2 st_var_2_1 = {0};
  struct Transaction_R000114_1413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000114_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000114_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000114_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000114_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000114_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000114_0_2 + 11) & 15;
  union PacketPayload_R000114_1413_0 u_var_1;
  union PacketPayload_R000114_1413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 6) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
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
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 55)
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
  if (stage_v_13_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 55)
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
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 23) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
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
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 53)
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
  if (stage_v_36_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 53)
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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 50)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 50)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 52) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (st_var_1_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_1_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 42)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 42)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 64) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
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
  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = ((st_var_2_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_2_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 33)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 33)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = ((st_var_0_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_0_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 44)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 44)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = ((st_var_1_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_1_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 38)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 38)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 72) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = (st_var_1_1.buffer[0] ^ 76) & 3;
  int stage_v_73_2 = (st_var_1_2.buffer[0] ^ 76) & 3;
  switch (stage_v_73_1)
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

  switch (stage_v_73_2)
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

  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = ((st_var_1_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_1_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 29)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 29)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = (st_var_2_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_2_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 79) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_12_1) + 34) & 127;
  int stage_v_80_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((stage_v_80_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_4_1) + 20) & 127;
  int stage_v_81_2 = ((((stage_v_80_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_18_1) + 3) & 127;
  int stage_v_82_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((sec_r000114_8_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_20_1) + 15) & 127;
  int stage_v_83_2 = ((((sec_r000114_8_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_81_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_16_1) + 27) & 127;
  int stage_v_84_2 = ((((stage_v_81_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_10_1) + 33) & 127;
  int stage_v_85_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_21_1) + 10) & 127;
  int stage_v_86_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_21_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_13_1) + 26) & 127;
  int stage_v_87_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_85_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_3_1) + 34) & 127;
  int stage_v_88_2 = ((((stage_v_85_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((sec_r000114_9_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_6_1) + 25) & 127;
  int stage_v_89_2 = ((((sec_r000114_9_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_86_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_20_1) + 22) & 127;
  int stage_v_90_2 = ((((stage_v_86_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((sec_r000114_17_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_3_1) + 31) & 127;
  int stage_v_91_2 = ((((sec_r000114_17_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_90_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_2_1) + 13) & 127;
  int stage_v_92_2 = ((((stage_v_90_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_84_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_6_1) + 29) & 127;
  int stage_v_93_2 = ((((stage_v_84_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_89_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_1_1) + 16) & 127;
  int stage_v_94_2 = ((((stage_v_89_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_10_1) + 10) & 127;
  int stage_v_95_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_83_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_5_1) + 3) & 127;
  int stage_v_96_2 = ((((stage_v_83_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_86_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_7_1) + 25) & 127;
  int stage_v_97_2 = ((((stage_v_86_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_97_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_13_1) + 3) & 127;
  int stage_v_98_2 = ((((stage_v_97_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_81_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_2_1) + 5) & 127;
  int stage_v_99_2 = ((((stage_v_81_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_83_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_11_1) + 8) & 127;
  int stage_v_100_2 = ((((stage_v_83_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((sec_r000114_9_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_15_1) + 16) & 127;
  int stage_v_101_2 = ((((sec_r000114_9_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_3_1) + 18) & 127;
  int stage_v_102_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_2_1) + 23) & 127;
  int stage_v_103_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((sec_r000114_16_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_15_1) + 12) & 127;
  int stage_v_104_2 = ((((sec_r000114_16_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_12_1) + 13) & 127;
  int stage_v_105_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_94_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_2_1) + 7) & 127;
  int stage_v_106_2 = ((((stage_v_94_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((stage_v_82_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_13_1) + 5) & 127;
  int stage_v_107_2 = ((((stage_v_82_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_97_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_14_1) + 22) & 127;
  int stage_v_108_2 = ((((stage_v_97_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_106_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_10_1) + 10) & 127;
  int stage_v_109_2 = ((((stage_v_106_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_81_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_16_1) + 23) & 127;
  int stage_v_110_2 = ((((stage_v_81_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_96_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_10_1) + 37) & 127;
  int stage_v_111_2 = ((((stage_v_96_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((sec_r000114_3_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_1_1) + 27) & 127;
  int stage_v_112_2 = ((((sec_r000114_3_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_105_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_4_1) + 3) & 127;
  int stage_v_113_2 = ((((stage_v_105_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_1_1) + 11) & 127;
  int stage_v_114_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_9_1) + 35) & 127;
  int stage_v_115_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000114_18_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_17_1) + 16) & 127;
  int stage_v_116_2 = ((((sec_r000114_18_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_99_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_8_1) + 34) & 127;
  int stage_v_117_2 = ((((stage_v_99_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_82_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_4_1) + 24) & 127;
  int stage_v_118_2 = ((((stage_v_82_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_89_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_4_1) + 27) & 127;
  int stage_v_119_2 = ((((stage_v_89_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_91_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_2_1) + 14) & 127;
  int stage_v_120_2 = ((((stage_v_91_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_91_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_2_1) + 35) & 127;
  int stage_v_121_2 = ((((stage_v_91_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_2_1) + 36) & 127;
  int stage_v_122_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_108_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_20_1) + 27) & 127;
  int stage_v_123_2 = ((((stage_v_108_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_99_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_7_1) + 3) & 127;
  int stage_v_124_2 = ((((stage_v_99_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_0_1) + 3) & 127;
  int stage_v_125_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_103_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_15_1) + 4) & 127;
  int stage_v_126_2 = ((((stage_v_103_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((sec_r000114_18_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_10_1) + 37) & 127;
  int stage_v_127_2 = ((((sec_r000114_18_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_123_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_7_1) + 14) & 127;
  int stage_v_128_2 = ((((stage_v_123_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_91_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_21_1) + 28) & 127;
  int stage_v_129_2 = ((((stage_v_91_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_21_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_112_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_1_1) + 25) & 127;
  int stage_v_130_2 = ((((stage_v_112_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_8_1) + 13) & 127;
  int stage_v_131_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_83_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_20_1) + 5) & 127;
  int stage_v_132_2 = ((((stage_v_83_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_110_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_8_1) + 18) & 127;
  int stage_v_133_2 = ((((stage_v_110_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((sec_r000114_17_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_12_1) + 11) & 127;
  int stage_v_134_2 = ((((sec_r000114_17_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_128_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_12_1) + 14) & 127;
  int stage_v_135_2 = ((((stage_v_128_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000114_3_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_17_1) + 25) & 127;
  int stage_v_136_2 = ((((sec_r000114_3_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_87_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_10_1) + 34) & 127;
  int stage_v_137_2 = ((((stage_v_87_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_127_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_5_1) + 37) & 127;
  int stage_v_138_2 = ((((stage_v_127_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_126_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_18_1) + 19) & 127;
  int stage_v_139_2 = ((((stage_v_126_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_126_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_12_1) + 33) & 127;
  int stage_v_140_2 = ((((stage_v_126_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_119_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_19_1) + 16) & 127;
  int stage_v_141_2 = ((((stage_v_119_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_116_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_9_1) + 17) & 127;
  int stage_v_142_2 = ((((stage_v_116_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_135_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_19_1) + 19) & 127;
  int stage_v_143_2 = ((((stage_v_135_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((sec_r000114_3_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_16_1) + 27) & 127;
  int stage_v_144_2 = ((((sec_r000114_3_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_10_1) + 22) & 127;
  int stage_v_145_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_128_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_12_1) + 26) & 127;
  int stage_v_146_2 = ((((stage_v_128_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((stage_v_142_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_1_1) + 9) & 127;
  int stage_v_147_2 = ((((stage_v_142_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_97_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_4_1) + 14) & 127;
  int stage_v_148_2 = ((((stage_v_97_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_148_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_5_1) + 26) & 127;
  int stage_v_149_2 = ((((stage_v_148_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_106_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_1_1) + 35) & 127;
  int stage_v_150_2 = ((((stage_v_106_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_109_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_21_1) + 30) & 127;
  int stage_v_151_2 = ((((stage_v_109_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_134_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_5_1) + 3) & 127;
  int stage_v_152_2 = ((((stage_v_134_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((sec_r000114_13_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_6_1) + 15) & 127;
  int stage_v_153_2 = ((((sec_r000114_13_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_130_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_7_1) + 13) & 127;
  int stage_v_154_2 = ((((stage_v_130_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((sec_r000114_19_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_2_1) + 32) & 127;
  int stage_v_155_2 = ((((sec_r000114_19_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_111_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_7_1) + 21) & 127;
  int stage_v_156_2 = ((((stage_v_111_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_107_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_19_1) + 24) & 127;
  int stage_v_157_2 = ((((stage_v_107_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_90_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_1_1) + 20) & 127;
  int stage_v_158_2 = ((((stage_v_90_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_81_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_19_1) + 21) & 127;
  int stage_v_159_2 = ((((stage_v_81_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_139_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_13_1) + 28) & 127;
  int stage_v_160_2 = ((((stage_v_139_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_153_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_13_1) + 33) & 127;
  int stage_v_161_2 = ((((stage_v_153_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_90_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_12_1) + 35) & 127;
  int stage_v_162_2 = ((((stage_v_90_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((sec_r000114_11_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_12_1) + 6) & 127;
  int stage_v_163_2 = ((((sec_r000114_11_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_92_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_3_1) + 17) & 127;
  int stage_v_164_2 = ((((stage_v_92_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((sec_r000114_14_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_3_1) + 24) & 127;
  int stage_v_165_2 = ((((sec_r000114_14_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((sec_r000114_1_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_2_1) + 32) & 127;
  int stage_v_166_2 = ((((sec_r000114_1_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_104_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_21_1) + 16) & 127;
  int stage_v_167_2 = ((((stage_v_104_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000114_14_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_21_1) + 29) & 127;
  int stage_v_168_2 = ((((sec_r000114_14_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_116_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_2_1) + 10) & 127;
  int stage_v_169_2 = ((((stage_v_116_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_155_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_6_1) + 33) & 127;
  int stage_v_170_2 = ((((stage_v_155_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_21_1) + 31) & 127;
  int stage_v_171_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000114_9_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_12_1) + 37) & 127;
  int stage_v_172_2 = ((((sec_r000114_9_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_148_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_5_1) + 3) & 127;
  int stage_v_173_2 = ((((stage_v_148_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_159_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_18_1) + 27) & 127;
  int stage_v_174_2 = ((((stage_v_159_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_19_1) + 3) & 127;
  int stage_v_175_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_162_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_2_1) + 14) & 127;
  int stage_v_176_2 = ((((stage_v_162_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_84_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_10_1) + 15) & 127;
  int stage_v_177_2 = ((((stage_v_84_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_5_1) + 6) & 127;
  int stage_v_178_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_177_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_7_1) + 27) & 127;
  int stage_v_179_2 = ((((stage_v_177_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_110_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_16_1) + 32) & 127;
  int stage_v_180_2 = ((((stage_v_110_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_124_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_1_1) + 37) & 127;
  int stage_v_181_2 = ((((stage_v_124_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_174_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_12_1) + 14) & 127;
  int stage_v_182_2 = ((((stage_v_174_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_119_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_19_1) + 33) & 127;
  int stage_v_183_2 = ((((stage_v_119_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_146_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_20_1) + 25) & 127;
  int stage_v_184_2 = ((((stage_v_146_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_7_1) + 21) & 127;
  int stage_v_185_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((sec_r000114_14_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_7_1) + 3) & 127;
  int stage_v_186_2 = ((((sec_r000114_14_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((sec_r000114_5_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_13_1) + 20) & 127;
  int stage_v_187_2 = ((((sec_r000114_5_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_185_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_5_1) + 13) & 127;
  int stage_v_188_2 = ((((stage_v_185_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_186_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_18_1) + 28) & 127;
  int stage_v_189_2 = ((((stage_v_186_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((sec_r000114_11_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_20_1) + 8) & 127;
  int stage_v_190_2 = ((((sec_r000114_11_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_103_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_12_1) + 28) & 127;
  int stage_v_191_2 = ((((stage_v_103_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_89_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_12_1) + 34) & 127;
  int stage_v_192_2 = ((((stage_v_89_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_17_1) + 32) & 127;
  int stage_v_193_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_167_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_5_1) + 24) & 127;
  int stage_v_194_2 = ((((stage_v_167_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_91_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_8_1) + 22) & 127;
  int stage_v_195_2 = ((((stage_v_91_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_191_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_1_1) + 16) & 127;
  int stage_v_196_2 = ((((stage_v_191_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000114_13_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_9_1) + 26) & 127;
  int stage_v_197_2 = ((((sec_r000114_13_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((sec_r000114_5_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_8_1) + 27) & 127;
  int stage_v_198_2 = ((((sec_r000114_5_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_90_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_17_1) + 14) & 127;
  int stage_v_199_2 = ((((stage_v_90_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_96_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_11_1) + 16) & 127;
  int stage_v_200_2 = ((((stage_v_96_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_142_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_15_1) + 3) & 127;
  int stage_v_201_2 = ((((stage_v_142_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_17_1) + 31) & 127;
  int stage_v_202_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_161_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_0_1) + 17) & 127;
  int stage_v_203_2 = ((((stage_v_161_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_105_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_9_1) + 28) & 127;
  int stage_v_204_2 = ((((stage_v_105_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((sec_r000114_14_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_12_1) + 25) & 127;
  int stage_v_205_2 = ((((sec_r000114_14_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_180_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_19_1) + 5) & 127;
  int stage_v_206_2 = ((((stage_v_180_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((sec_r000114_17_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_20_1) + 14) & 127;
  int stage_v_207_2 = ((((sec_r000114_17_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_194_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_3_1) + 37) & 127;
  int stage_v_208_2 = ((((stage_v_194_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_107_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_5_1) + 37) & 127;
  int stage_v_209_2 = ((((stage_v_107_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000114_8_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_5_1) + 8) & 127;
  int stage_v_210_2 = ((((sec_r000114_8_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_20_1) + 21) & 127;
  int stage_v_211_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((sec_r000114_16_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_11_1) + 16) & 127;
  int stage_v_212_2 = ((((sec_r000114_16_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((stage_v_130_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_15_1) + 11) & 127;
  int stage_v_213_2 = ((((stage_v_130_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_147_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_13_1) + 33) & 127;
  int stage_v_214_2 = ((((stage_v_147_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((sec_r000114_17_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_8_1) + 14) & 127;
  int stage_v_215_2 = ((((sec_r000114_17_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_107_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_11_1) + 15) & 127;
  int stage_v_216_2 = ((((stage_v_107_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_5_1) + 5) & 127;
  int stage_v_217_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_114_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_4_1) + 14) & 127;
  int stage_v_218_2 = ((((stage_v_114_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_145_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_16_1) + 27) & 127;
  int stage_v_219_2 = ((((stage_v_145_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((sec_r000114_2_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_6_1) + 25) & 127;
  int stage_v_220_2 = ((((sec_r000114_2_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_154_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_21_1) + 15) & 127;
  int stage_v_221_2 = ((((stage_v_154_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((sec_r000114_18_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_11_1) + 36) & 127;
  int stage_v_222_2 = ((((sec_r000114_18_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_218_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_3_1) + 12) & 127;
  int stage_v_223_2 = ((((stage_v_218_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_131_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_1_1) + 31) & 127;
  int stage_v_224_2 = ((((stage_v_131_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_10_1) + 14) & 127;
  int stage_v_225_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_216_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_12_1) + 37) & 127;
  int stage_v_226_2 = ((((stage_v_216_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((sec_r000114_11_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_5_1) + 24) & 127;
  int stage_v_227_2 = ((((sec_r000114_11_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_97_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_6_1) + 4) & 127;
  int stage_v_228_2 = ((((stage_v_97_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((stage_v_158_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_13_1) + 15) & 127;
  int stage_v_229_2 = ((((stage_v_158_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((sec_r000114_6_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_18_1) + 13) & 127;
  int stage_v_230_2 = ((((sec_r000114_6_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_186_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_4_1) + 6) & 127;
  int stage_v_231_2 = ((((stage_v_186_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_3_1) + 17) & 127;
  int stage_v_232_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_0_1) + 33) & 127;
  int stage_v_233_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_233_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_15_1) + 21) & 127;
  int stage_v_234_2 = ((((stage_v_233_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_166_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_8_1) + 5) & 127;
  int stage_v_235_2 = ((((stage_v_166_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((stage_v_214_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_6_1) + 9) & 127;
  int stage_v_236_2 = ((((stage_v_214_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_18_1) + 29) & 127;
  int stage_v_237_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000114_15_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_14_1) + 34) & 127;
  int stage_v_238_2 = ((((sec_r000114_15_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((sec_r000114_9_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_20_1) + 20) & 127;
  int stage_v_239_2 = ((((sec_r000114_9_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((sec_r000114_5_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_7_1) + 26) & 127;
  int stage_v_240_2 = ((((sec_r000114_5_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_213_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_13_1) + 8) & 127;
  int stage_v_241_2 = ((((stage_v_213_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_12_1) + 14) & 127;
  int stage_v_242_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_155_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_14_1) + 16) & 127;
  int stage_v_243_2 = ((((stage_v_155_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_225_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_10_1) + 37) & 127;
  int stage_v_244_2 = ((((stage_v_225_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_185_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_5_1) + 15) & 127;
  int stage_v_245_2 = ((((stage_v_185_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_147_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_2_1) + 19) & 127;
  int stage_v_246_2 = ((((stage_v_147_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_179_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_5_1) + 11) & 127;
  int stage_v_247_2 = ((((stage_v_179_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_165_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_10_1) + 35) & 127;
  int stage_v_248_2 = ((((stage_v_165_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_176_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_2_1) + 29) & 127;
  int stage_v_249_2 = ((((stage_v_176_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_142_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_17_1) + 16) & 127;
  int stage_v_250_2 = ((((stage_v_142_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000114_19_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_19_1) + 31) & 127;
  int stage_v_251_2 = ((((sec_r000114_19_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_9_1) + 15) & 127;
  int stage_v_252_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_1_1) + 29) & 127;
  int stage_v_253_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000114_1_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_6_1) + 33) & 127;
  int stage_v_254_2 = ((((sec_r000114_1_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_146_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_14_1) + 15) & 127;
  int stage_v_255_2 = ((((stage_v_146_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_164_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_19_1) + 33) & 127;
  int stage_v_256_2 = ((((stage_v_164_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_191_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_11_1) + 35) & 127;
  int stage_v_257_2 = ((((stage_v_191_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_20_1) + 10) & 127;
  int stage_v_258_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_9_1) + 17) & 127;
  int stage_v_259_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_110_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_21_1) + 30) & 127;
  int stage_v_260_2 = ((((stage_v_110_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_215_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_3_1) + 3) & 127;
  int stage_v_261_2 = ((((stage_v_215_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_141_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_19_1) + 22) & 127;
  int stage_v_262_2 = ((((stage_v_141_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_200_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_21_1) + 37) & 127;
  int stage_v_263_2 = ((((stage_v_200_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_10_1) + 7) & 127;
  int stage_v_264_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_98_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_12_1) + 25) & 127;
  int stage_v_265_2 = ((((stage_v_98_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000114_12_1 * 3) + (sec_r000114_12_1 * 2)) - pub_r000114_10_1) + 36) & 127;
  int stage_v_266_2 = ((((sec_r000114_12_2 * 3) + (sec_r000114_12_2 * 2)) - pub_r000114_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_223_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_3_1) + 7) & 127;
  int stage_v_267_2 = ((((stage_v_223_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_180_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_2_1) + 17) & 127;
  int stage_v_268_2 = ((((stage_v_180_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_94_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_19_1) + 36) & 127;
  int stage_v_269_2 = ((((stage_v_94_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_128_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_19_1) + 31) & 127;
  int stage_v_270_2 = ((((stage_v_128_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_197_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_1_1) + 32) & 127;
  int stage_v_271_2 = ((((stage_v_197_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_98_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_18_1) + 26) & 127;
  int stage_v_272_2 = ((((stage_v_98_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000114_18_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_19_1) + 25) & 127;
  int stage_v_273_2 = ((((sec_r000114_18_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_19_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_241_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_19_1) + 15) & 127;
  int stage_v_274_2 = ((((stage_v_241_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((sec_r000114_2_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_17_1) + 10) & 127;
  int stage_v_275_2 = ((((sec_r000114_2_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((sec_r000114_11_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_1_1) + 23) & 127;
  int stage_v_276_2 = ((((sec_r000114_11_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_261_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_5_1) + 33) & 127;
  int stage_v_277_2 = ((((stage_v_261_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_190_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_2_1) + 18) & 127;
  int stage_v_278_2 = ((((stage_v_190_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((sec_r000114_6_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_18_1) + 4) & 127;
  int stage_v_279_2 = ((((sec_r000114_6_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_167_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_10_1) + 21) & 127;
  int stage_v_280_2 = ((((stage_v_167_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_105_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_8_1) + 23) & 127;
  int stage_v_281_2 = ((((stage_v_105_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000114_4_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_5_1) + 34) & 127;
  int stage_v_282_2 = ((((sec_r000114_4_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((sec_r000114_6_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_3_1) + 30) & 127;
  int stage_v_283_2 = ((((sec_r000114_6_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000114_19_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_0_1) + 11) & 127;
  int stage_v_284_2 = ((((sec_r000114_19_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_181_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_12_1) + 27) & 127;
  int stage_v_285_2 = ((((stage_v_181_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_195_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_14_1) + 26) & 127;
  int stage_v_286_2 = ((((stage_v_195_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((sec_r000114_16_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_14_1) + 27) & 127;
  int stage_v_287_2 = ((((sec_r000114_16_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((sec_r000114_17_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_14_1) + 11) & 127;
  int stage_v_288_2 = ((((sec_r000114_17_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_138_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_8_1) + 30) & 127;
  int stage_v_289_2 = ((((stage_v_138_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_208_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_10_1) + 20) & 127;
  int stage_v_290_2 = ((((stage_v_208_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_102_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_7_1) + 37) & 127;
  int stage_v_291_2 = ((((stage_v_102_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((sec_r000114_6_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_16_1) + 25) & 127;
  int stage_v_292_2 = ((((sec_r000114_6_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_212_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_18_1) + 5) & 127;
  int stage_v_293_2 = ((((stage_v_212_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_198_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_20_1) + 19) & 127;
  int stage_v_294_2 = ((((stage_v_198_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_136_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_15_1) + 8) & 127;
  int stage_v_295_2 = ((((stage_v_136_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000114_13_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_12_1) + 29) & 127;
  int stage_v_296_2 = ((((sec_r000114_13_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((sec_r000114_7_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_21_1) + 27) & 127;
  int stage_v_297_2 = ((((sec_r000114_7_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_6_1) + 21) & 127;
  int stage_v_298_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_132_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_9_1) + 34) & 127;
  int stage_v_299_2 = ((((stage_v_132_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_254_1 * 3) + (sec_r000114_4_1 * 2)) - pub_r000114_8_1) + 5) & 127;
  int stage_v_300_2 = ((((stage_v_254_2 * 3) + (sec_r000114_4_2 * 2)) - pub_r000114_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_251_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_7_1) + 3) & 127;
  int stage_v_301_2 = ((((stage_v_251_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_285_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_1_1) + 21) & 127;
  int stage_v_302_2 = ((((stage_v_285_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((sec_r000114_3_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_12_1) + 9) & 127;
  int stage_v_303_2 = ((((sec_r000114_3_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((sec_r000114_11_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_14_1) + 11) & 127;
  int stage_v_304_2 = ((((sec_r000114_11_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_213_1 * 3) + (sec_r000114_14_1 * 2)) - pub_r000114_13_1) + 34) & 127;
  int stage_v_305_2 = ((((stage_v_213_2 * 3) + (sec_r000114_14_2 * 2)) - pub_r000114_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_147_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_5_1) + 17) & 127;
  int stage_v_306_2 = ((((stage_v_147_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_120_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_21_1) + 27) & 127;
  int stage_v_307_2 = ((((stage_v_120_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((sec_r000114_5_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_14_1) + 12) & 127;
  int stage_v_308_2 = ((((sec_r000114_5_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000114_1_1 * 3) + (sec_r000114_1_1 * 2)) - pub_r000114_19_1) + 22) & 127;
  int stage_v_309_2 = ((((sec_r000114_1_2 * 3) + (sec_r000114_1_2 * 2)) - pub_r000114_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_136_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_21_1) + 24) & 127;
  int stage_v_310_2 = ((((stage_v_136_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_292_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_15_1) + 24) & 127;
  int stage_v_311_2 = ((((stage_v_292_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_247_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_7_1) + 30) & 127;
  int stage_v_312_2 = ((((stage_v_247_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_272_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_7_1) + 37) & 127;
  int stage_v_313_2 = ((((stage_v_272_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_282_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_0_1) + 5) & 127;
  int stage_v_314_2 = ((((stage_v_282_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((stage_v_306_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_20_1) + 17) & 127;
  int stage_v_315_2 = ((((stage_v_306_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_20_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_16_1) + 32) & 127;
  int stage_v_316_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((stage_v_175_1 * 3) + (sec_r000114_17_1 * 2)) - pub_r000114_8_1) + 18) & 127;
  int stage_v_317_2 = ((((stage_v_175_2 * 3) + (sec_r000114_17_2 * 2)) - pub_r000114_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000114_20_1 * 3) + (sec_r000114_20_1 * 2)) - pub_r000114_16_1) + 7) & 127;
  int stage_v_318_2 = ((((sec_r000114_20_2 * 3) + (sec_r000114_20_2 * 2)) - pub_r000114_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_303_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_15_1) + 6) & 127;
  int stage_v_319_2 = ((((stage_v_303_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_300_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_20_1) + 13) & 127;
  int stage_v_320_2 = ((((stage_v_300_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_20_1) + 10) & 127;
  int stage_v_321_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_150_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_13_1) + 32) & 127;
  int stage_v_322_2 = ((((stage_v_150_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_278_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_6_1) + 17) & 127;
  int stage_v_323_2 = ((((stage_v_278_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_269_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_1_1) + 14) & 127;
  int stage_v_324_2 = ((((stage_v_269_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((sec_r000114_16_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_18_1) + 14) & 127;
  int stage_v_325_2 = ((((sec_r000114_16_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_221_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_14_1) + 7) & 127;
  int stage_v_326_2 = ((((stage_v_221_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((stage_v_264_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_18_1) + 3) & 127;
  int stage_v_327_2 = ((((stage_v_264_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((stage_v_244_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_4_1) + 20) & 127;
  int stage_v_328_2 = ((((stage_v_244_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((stage_v_207_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_17_1) + 17) & 127;
  int stage_v_329_2 = ((((stage_v_207_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((stage_v_104_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_2_1) + 11) & 127;
  int stage_v_330_2 = ((((stage_v_104_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_264_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_2_1) + 13) & 127;
  int stage_v_331_2 = ((((stage_v_264_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((stage_v_308_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_20_1) + 27) & 127;
  int stage_v_332_2 = ((((stage_v_308_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((sec_r000114_9_1 * 3) + (sec_r000114_9_1 * 2)) - pub_r000114_5_1) + 8) & 127;
  int stage_v_333_2 = ((((sec_r000114_9_2 * 3) + (sec_r000114_9_2 * 2)) - pub_r000114_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_103_1 * 3) + (sec_r000114_15_1 * 2)) - pub_r000114_16_1) + 7) & 127;
  int stage_v_334_2 = ((((stage_v_103_2 * 3) + (sec_r000114_15_2 * 2)) - pub_r000114_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((sec_r000114_2_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_6_1) + 25) & 127;
  int stage_v_335_2 = ((((sec_r000114_2_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_199_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_5_1) + 11) & 127;
  int stage_v_336_2 = ((((stage_v_199_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((((sec_r000114_0_1 * 3) + (sec_r000114_0_1 * 2)) - pub_r000114_20_1) + 8) & 127;
  int stage_v_337_2 = ((((sec_r000114_0_2 * 3) + (sec_r000114_0_2 * 2)) - pub_r000114_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_337_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_337_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((((stage_v_264_1 * 3) + (sec_r000114_7_1 * 2)) - pub_r000114_12_1) + 35) & 127;
  int stage_v_338_2 = ((((stage_v_264_2 * 3) + (sec_r000114_7_2 * 2)) - pub_r000114_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_338_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_338_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((((sec_r000114_5_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_6_1) + 25) & 127;
  int stage_v_339_2 = ((((sec_r000114_5_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_339_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_339_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((((stage_v_188_1 * 3) + (sec_r000114_18_1 * 2)) - pub_r000114_19_1) + 15) & 127;
  int stage_v_340_2 = ((((stage_v_188_2 * 3) + (sec_r000114_18_2 * 2)) - pub_r000114_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_340_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_340_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((((sec_r000114_19_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_8_1) + 33) & 127;
  int stage_v_341_2 = ((((sec_r000114_19_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_341_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_341_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((((stage_v_311_1 * 3) + (sec_r000114_11_1 * 2)) - pub_r000114_8_1) + 16) & 127;
  int stage_v_342_2 = ((((stage_v_311_2 * 3) + (sec_r000114_11_2 * 2)) - pub_r000114_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_342_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_342_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((((stage_v_176_1 * 3) + (sec_r000114_3_1 * 2)) - pub_r000114_15_1) + 15) & 127;
  int stage_v_343_2 = ((((stage_v_176_2 * 3) + (sec_r000114_3_2 * 2)) - pub_r000114_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_343_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_343_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((((stage_v_125_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_15_1) + 8) & 127;
  int stage_v_344_2 = ((((stage_v_125_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_344_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_344_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((((stage_v_224_1 * 3) + (sec_r000114_13_1 * 2)) - pub_r000114_12_1) + 30) & 127;
  int stage_v_345_2 = ((((stage_v_224_2 * 3) + (sec_r000114_13_2 * 2)) - pub_r000114_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_345_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_345_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((((stage_v_180_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_15_1) + 13) & 127;
  int stage_v_346_2 = ((((stage_v_180_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_346_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_346_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((((stage_v_104_1 * 3) + (sec_r000114_19_1 * 2)) - pub_r000114_15_1) + 20) & 127;
  int stage_v_347_2 = ((((stage_v_104_2 * 3) + (sec_r000114_19_2 * 2)) - pub_r000114_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_347_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_347_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((((sec_r000114_6_1 * 3) + (sec_r000114_6_1 * 2)) - pub_r000114_3_1) + 33) & 127;
  int stage_v_348_2 = ((((sec_r000114_6_2 * 3) + (sec_r000114_6_2 * 2)) - pub_r000114_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_348_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_348_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((((stage_v_196_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_12_1) + 18) & 127;
  int stage_v_349_2 = ((((stage_v_196_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_349_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_349_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((((stage_v_184_1 * 3) + (sec_r000114_8_1 * 2)) - pub_r000114_15_1) + 15) & 127;
  int stage_v_350_2 = ((((stage_v_184_2 * 3) + (sec_r000114_8_2 * 2)) - pub_r000114_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_350_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_350_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((((stage_v_228_1 * 3) + (sec_r000114_5_1 * 2)) - pub_r000114_4_1) + 12) & 127;
  int stage_v_351_2 = ((((stage_v_228_2 * 3) + (sec_r000114_5_2 * 2)) - pub_r000114_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_351_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_351_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((((sec_r000114_2_1 * 3) + (sec_r000114_2_1 * 2)) - pub_r000114_18_1) + 12) & 127;
  int stage_v_352_2 = ((((sec_r000114_2_2 * 3) + (sec_r000114_2_2 * 2)) - pub_r000114_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_352_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_352_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((((sec_r000114_16_1 * 3) + (sec_r000114_16_1 * 2)) - pub_r000114_12_1) + 19) & 127;
  int stage_v_353_2 = ((((sec_r000114_16_2 * 3) + (sec_r000114_16_2 * 2)) - pub_r000114_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_353_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_353_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((((sec_r000114_10_1 * 3) + (sec_r000114_10_1 * 2)) - pub_r000114_11_1) + 19) & 127;
  int stage_v_354_2 = ((((sec_r000114_10_2 * 3) + (sec_r000114_10_2 * 2)) - pub_r000114_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_354_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_354_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000114_10_1 == pub_r000114_10_2);
  __CPROVER_assume(pub_r000114_20_1 == pub_r000114_20_2);
  __CPROVER_assume(sec_r000114_19_1 != sec_r000114_19_2);
  __CPROVER_assume(sec_r000114_13_1 != sec_r000114_13_2);
  __CPROVER_assume(pub_r000114_5_1 == pub_r000114_5_2);
  __CPROVER_assume(sec_r000114_4_1 != sec_r000114_4_2);
  __CPROVER_assume(pub_r000114_3_1 == pub_r000114_3_2);
  __CPROVER_assume(pub_r000114_9_1 == pub_r000114_9_2);
  __CPROVER_assume(pub_r000114_18_1 == pub_r000114_18_2);
  __CPROVER_assume(sec_r000114_10_1 != sec_r000114_10_2);
  __CPROVER_assume(pub_r000114_12_1 == pub_r000114_12_2);
  __CPROVER_assume(pub_r000114_19_1 == pub_r000114_19_2);
  __CPROVER_assume(pub_r000114_16_1 == pub_r000114_16_2);
  __CPROVER_assume(sec_r000114_11_1 != sec_r000114_11_2);
  __CPROVER_assume(sec_r000114_3_1 != sec_r000114_3_2);
  __CPROVER_assume(sec_r000114_2_1 != sec_r000114_2_2);
  __CPROVER_assume(sec_r000114_15_1 != sec_r000114_15_2);
  __CPROVER_assume(pub_r000114_14_1 == pub_r000114_14_2);
  __CPROVER_assume(sec_r000114_12_1 != sec_r000114_12_2);
  __CPROVER_assume(sec_r000114_5_1 != sec_r000114_5_2);
  __CPROVER_assume(pub_r000114_2_1 == pub_r000114_2_2);
  __CPROVER_assume(pub_r000114_8_1 == pub_r000114_8_2);
  __CPROVER_assume(pub_r000114_17_1 == pub_r000114_17_2);
  __CPROVER_assume(sec_r000114_18_1 != sec_r000114_18_2);
  __CPROVER_assume(pub_r000114_13_1 == pub_r000114_13_2);
  __CPROVER_assume(sec_r000114_17_1 != sec_r000114_17_2);
  __CPROVER_assume(sec_r000114_6_1 != sec_r000114_6_2);
  __CPROVER_assume(pub_r000114_21_1 == pub_r000114_21_2);
  __CPROVER_assume(pub_r000114_0_1 == pub_r000114_0_2);
  __CPROVER_assume(pub_r000114_1_1 == pub_r000114_1_2);
  __CPROVER_assume(pub_r000114_11_1 == pub_r000114_11_2);
  __CPROVER_assume(sec_r000114_0_1 != sec_r000114_0_2);
  __CPROVER_assume(sec_r000114_20_1 != sec_r000114_20_2);
  __CPROVER_assume(pub_r000114_4_1 == pub_r000114_4_2);
  __CPROVER_assume(pub_r000114_7_1 == pub_r000114_7_2);
  __CPROVER_assume(sec_r000114_8_1 != sec_r000114_8_2);
  __CPROVER_assume(sec_r000114_14_1 != sec_r000114_14_2);
  __CPROVER_assume(sec_r000114_7_1 != sec_r000114_7_2);
  __CPROVER_assume(pub_r000114_6_1 == pub_r000114_6_2);
  __CPROVER_assume(sec_r000114_9_1 != sec_r000114_9_2);
  __CPROVER_assume(sec_r000114_1_1 != sec_r000114_1_2);
  __CPROVER_assume(sec_r000114_16_1 != sec_r000114_16_2);
  __CPROVER_assume(pub_r000114_15_1 == pub_r000114_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.head == st_var_1_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
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
}


