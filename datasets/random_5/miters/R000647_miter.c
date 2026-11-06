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
struct MatrixBlock_R000647_4713_0
{
  unsigned char dim;
  int trace;
  unsigned char determinant;
  int scale;
  int stride;
  unsigned char density;
  int buffer[3];
};
struct StreamBuffer_R000647_4713_1
{
  short head;
  int watermark;
  unsigned char state;
  short checksum;
  int buffer[3];
};
struct SensorNode_R000647_4713_2
{
  short reading;
  int status;
  short threshold;
  int calib;
  int buffer[3];
};
struct FilterState_R000647_4713_3
{
  int cutoff;
  int prev_out;
  unsigned char damping;
  unsigned char gain_db;
  int mode;
  short prev_in;
  int buffer[3];
};
union PacketPayload_R000647_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000647_4713_1
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
void fn_R000647_4713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_97_1 > 21)
  {
    acc_1 = ((acc_1 + (quotient_97_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_97_2 > 21)
  {
    acc_2 = ((acc_2 + (quotient_97_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_61_1)
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

  switch (segment_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_97_1 == quotient_97_2);
  assert(segment_61_1 == segment_61_2);
}

int fn_R000647_4713_0(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_97 > 21)
  {
    acc = ((acc + (quotient_97 * 2)) + 5) & 127;
    aux ^= quotient_97 & 15;
  }
  else
  {
    acc = ((acc - quotient_97) + 11) & 127;
    aux += 3;
  }
  int segment_61 = (aux + st.buffer[1]) & 3;
  switch (segment_61)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000647_4713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_51_1) & 63;
  aux_2 = (aux_2 + pivot_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_14_1 > 49)
  {
    acc_1 = ((acc_1 + (sample_14_1 * 2)) + 5) & 127;
    aux_1 ^= sample_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_14_2 > 49)
  {
    acc_2 = ((acc_2 + (sample_14_2 * 2)) + 5) & 127;
    aux_2 ^= sample_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_48_1)
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

  switch (vector_48_2)
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
  int sample_73_1 = local_arr_1[aux_1 % 3];
  int sample_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_51_1 == pivot_51_2);
  assert(sample_14_1 == sample_14_2);
  assert(vector_48_1 == vector_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_73_1 == sample_73_2);
}

int fn_R000647_4713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_51) & 63;
  acc ^= aux;
  int sample_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_14 > 49)
  {
    acc = ((acc + (sample_14 * 2)) + 5) & 127;
    aux ^= sample_14 & 15;
  }
  else
  {
    acc = ((acc - sample_14) + 11) & 127;
    aux += 3;
  }
  int vector_48 = (aux + st.buffer[1]) & 3;
  switch (vector_48)
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
  int sample_73 = local_arr[aux % 3];
  acc = (acc + (sample_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000647_4713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tracker_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_59_1 > 35)
  {
    acc_1 = ((acc_1 + (tracker_59_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_59_2 > 35)
  {
    acc_2 = ((acc_2 + (tracker_59_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_59_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_73_1 = local_arr_1[aux_1 % 3];
  int weight_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_73_2 * 2)) & 127;
  int residue_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_51_1)
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

  switch (residue_51_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_59_1 == tracker_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_73_1 == weight_73_2);
  assert(residue_51_1 == residue_51_2);
}

int fn_R000647_4713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tracker_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_59 > 35)
  {
    acc = ((acc + (tracker_59 * 2)) + 5) & 127;
    aux ^= tracker_59 & 15;
  }
  else
  {
    acc = ((acc - tracker_59) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_73 = local_arr[aux % 3];
  acc = (acc + (weight_73 * 2)) & 127;
  int residue_51 = (aux + st.buffer[1]) & 3;
  switch (residue_51)
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

void fn_R000647_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_62_1)
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

  switch (sample_62_2)
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
  int cursor_77_1 = local_arr_1[aux_1 % 3];
  int cursor_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_62_1 == sample_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_77_1 == cursor_77_2);
}

int fn_R000647_4713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_62 = (aux + st.buffer[1]) & 3;
  switch (sample_62)
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
  int cursor_77 = local_arr[aux % 3];
  acc = (acc + (cursor_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000647_4713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st_1 = {0};
  struct FilterState_R000647_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_49_1 = local_arr_1[aux_1 % 3];
  int checksum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_49_2 * 2)) & 127;
  int stride_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_37_1)
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

  switch (stride_37_2)
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

  int threshold_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_90_1 > 29)
  {
    acc_1 = ((acc_1 + (threshold_90_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_90_2 > 29)
  {
    acc_2 = ((acc_2 + (threshold_90_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
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

  assert(checksum_49_1 == checksum_49_2);
  assert(stride_37_1 == stride_37_2);
  assert(threshold_90_1 == threshold_90_2);
}

int fn_R000647_4713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_49 = local_arr[aux % 3];
  acc = (acc + (checksum_49 * 2)) & 127;
  int stride_37 = (aux + st.buffer[1]) & 3;
  switch (stride_37)
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

  int threshold_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_90 > 29)
  {
    acc = ((acc + (threshold_90 * 2)) + 5) & 127;
    aux ^= threshold_90 & 15;
  }
  else
  {
    acc = ((acc - threshold_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000647_4713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_73_1) & 63;
  aux_2 = (aux_2 + pivot_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_46_1)
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

  switch (delta_46_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_73_1 == pivot_73_2);
  assert(delta_46_1 == delta_46_2);
}

int fn_R000647_4713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_73) & 63;
  acc ^= aux;
  int delta_46 = (aux + st.buffer[1]) & 3;
  switch (delta_46)
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

void fn_R000647_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_17_1 = local_arr_1[aux_1 % 3];
  int tally_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_17_2 * 2)) & 127;
  int coefficient_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_12_1)
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

  switch (coefficient_12_2)
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

  int margin_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_14_1) & 63;
  aux_2 = (aux_2 + margin_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_17_1 == tally_17_2);
  assert(coefficient_12_1 == coefficient_12_2);
  assert(margin_14_1 == margin_14_2);
}

int fn_R000647_4713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int tally_17 = local_arr[aux % 3];
  acc = (acc + (tally_17 * 2)) & 127;
  int coefficient_12 = (aux + st.buffer[1]) & 3;
  switch (coefficient_12)
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

  int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000647_4713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st_1 = {0};
  struct FilterState_R000647_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_74_1) & 63;
  aux_2 = (aux_2 + segment_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_60_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_60_1 * 2)) + 5) & 127;
    aux_1 ^= sample_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_60_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_60_2 * 2)) + 5) & 127;
    aux_2 ^= sample_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_16_1)
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

  switch (weight_16_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_74_1 == segment_74_2);
  assert(sample_60_1 == sample_60_2);
  assert(weight_16_1 == weight_16_2);
}

int fn_R000647_4713_7(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_74) & 63;
  acc ^= aux;
  int sample_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_60 > 25)
  {
    acc = ((acc + (sample_60 * 2)) + 5) & 127;
    aux ^= sample_60 & 15;
  }
  else
  {
    acc = ((acc - sample_60) + 11) & 127;
    aux += 3;
  }
  int weight_16 = (aux + st.buffer[1]) & 3;
  switch (weight_16)
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

void fn_R000647_4713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st_1 = {0};
  struct FilterState_R000647_4713_3 st_2 = {0};
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
  int checksum_19_1 = local_arr_1[aux_1 % 3];
  int checksum_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_19_2 * 2)) & 127;
  int tracker_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_84_1)
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

  switch (tracker_84_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
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

  assert(checksum_19_1 == checksum_19_2);
  assert(tracker_84_1 == tracker_84_2);
}

int fn_R000647_4713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_19 = local_arr[aux % 3];
  acc = (acc + (checksum_19 * 2)) & 127;
  int tracker_84 = (aux + st.buffer[1]) & 3;
  switch (tracker_84)
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

void fn_R000647_4713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st_1 = {0};
  struct SensorNode_R000647_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_23_1) & 63;
  aux_2 = (aux_2 + metric_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_23_1 == metric_23_2);
}

int fn_R000647_4713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000647_4713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_64_1)
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

  switch (accumulator_64_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_64_1 == accumulator_64_2);
}

int fn_R000647_4713_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_64 = (aux + st.buffer[1]) & 3;
  switch (accumulator_64)
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

void fn_R000647_4713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st_1 = {0};
  struct SensorNode_R000647_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_99_1 > 10)
  {
    acc_1 = ((acc_1 + (weight_99_1 * 2)) + 5) & 127;
    aux_1 ^= weight_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_99_2 > 10)
  {
    acc_2 = ((acc_2 + (weight_99_2 * 2)) + 5) & 127;
    aux_2 ^= weight_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_88_1 = local_arr_1[aux_1 % 3];
  int margin_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_99_1 == weight_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_88_1 == margin_88_2);
}

int fn_R000647_4713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_99 > 10)
  {
    acc = ((acc + (weight_99 * 2)) + 5) & 127;
    aux ^= weight_99 & 15;
  }
  else
  {
    acc = ((acc - weight_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_88 = local_arr[aux % 3];
  acc = (acc + (margin_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000647_4713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_25_1 > 23)
  {
    acc_1 = ((acc_1 + (offset_25_1 * 2)) + 5) & 127;
    aux_1 ^= offset_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_25_2 > 23)
  {
    acc_2 = ((acc_2 + (offset_25_2 * 2)) + 5) & 127;
    aux_2 ^= offset_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_25_1 == offset_25_2);
}

int fn_R000647_4713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_25 > 23)
  {
    acc = ((acc + (offset_25 * 2)) + 5) & 127;
    aux ^= offset_25 & 15;
  }
  else
  {
    acc = ((acc - offset_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000647_4713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_16_1 = local_arr_1[aux_1 % 3];
  int index_reg_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_16_2 * 2)) & 127;
  int tracker_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_35_1 > 10)
  {
    acc_1 = ((acc_1 + (tracker_35_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_35_2 > 10)
  {
    acc_2 = ((acc_2 + (tracker_35_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_16_1 == index_reg_16_2);
  assert(tracker_35_1 == tracker_35_2);
}

int fn_R000647_4713_13(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int index_reg_16 = local_arr[aux % 3];
  acc = (acc + (index_reg_16 * 2)) & 127;
  int tracker_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_35 > 10)
  {
    acc = ((acc + (tracker_35 * 2)) + 5) & 127;
    aux ^= tracker_35 & 15;
  }
  else
  {
    acc = ((acc - tracker_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000647_4713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st_1 = {0};
  struct SensorNode_R000647_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_42_1)
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

  switch (phase_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_74_1 > 19)
  {
    acc_1 = ((acc_1 + (pivot_74_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_74_2 > 19)
  {
    acc_2 = ((acc_2 + (pivot_74_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_42_1 == phase_42_2);
  assert(pivot_74_1 == pivot_74_2);
}

int fn_R000647_4713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000647_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_42 = (aux + st.buffer[1]) & 3;
  switch (phase_42)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_74 > 19)
  {
    acc = ((acc + (pivot_74 * 2)) + 5) & 127;
    aux ^= pivot_74 & 15;
  }
  else
  {
    acc = ((acc - pivot_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000647_4713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_41_1 = local_arr_1[aux_1 % 3];
  int stride_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_41_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_61_1) & 63;
  aux_2 = (aux_2 + coefficient_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
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

  assert(stride_41_1 == stride_41_2);
  assert(coefficient_61_1 == coefficient_61_2);
}

int fn_R000647_4713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_41 = local_arr[aux % 3];
  acc = (acc + (stride_41 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000647_4713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st_1 = {0};
  struct FilterState_R000647_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_61_1 > 31)
  {
    acc_1 = ((acc_1 + (scale_61_1 * 2)) + 5) & 127;
    aux_1 ^= scale_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_61_2 > 31)
  {
    acc_2 = ((acc_2 + (scale_61_2 * 2)) + 5) & 127;
    aux_2 ^= scale_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_80_1)
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

  switch (weight_80_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_61_1 == scale_61_2);
  assert(weight_80_1 == weight_80_2);
}

int fn_R000647_4713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000647_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_61 > 31)
  {
    acc = ((acc + (scale_61 * 2)) + 5) & 127;
    aux ^= scale_61 & 15;
  }
  else
  {
    acc = ((acc - scale_61) + 11) & 127;
    aux += 3;
  }
  int weight_80 = (aux + st.buffer[1]) & 3;
  switch (weight_80)
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

void fn_R000647_4713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_63_1)
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

  switch (checksum_63_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_63_1 == checksum_63_2);
}

int fn_R000647_4713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_63 = (aux + st.buffer[1]) & 3;
  switch (checksum_63)
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

void fn_R000647_4713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_56_1 = local_arr_1[aux_1 % 3];
  int accumulator_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_64_1)
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

  switch (coefficient_64_2)
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

  int bound_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_97_1 > 22)
  {
    acc_1 = ((acc_1 + (bound_97_1 * 2)) + 5) & 127;
    aux_1 ^= bound_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_97_2 > 22)
  {
    acc_2 = ((acc_2 + (bound_97_2 * 2)) + 5) & 127;
    aux_2 ^= bound_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
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

  assert(accumulator_56_1 == accumulator_56_2);
  assert(coefficient_64_1 == coefficient_64_2);
  assert(bound_97_1 == bound_97_2);
}

int fn_R000647_4713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000647_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int accumulator_56 = local_arr[aux % 3];
  acc = (acc + (accumulator_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_64 = (aux + st.buffer[1]) & 3;
  switch (coefficient_64)
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

  int bound_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_97 > 22)
  {
    acc = ((acc + (bound_97 * 2)) + 5) & 127;
    aux ^= bound_97 & 15;
  }
  else
  {
    acc = ((acc - bound_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000647_4713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tally_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_23_1) & 63;
  aux_2 = (aux_2 + tally_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_64_1)
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

  switch (tracker_64_2)
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

  int cursor_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_27_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_27_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_27_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_27_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(tracker_64_1 == tracker_64_2);
  assert(cursor_27_1 == cursor_27_2);
}

int fn_R000647_4713_19(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000647_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tally_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_23) & 63;
  acc ^= aux;
  int tracker_64 = (aux + st.buffer[1]) & 3;
  switch (tracker_64)
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

  int cursor_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_27 > 19)
  {
    acc = ((acc + (cursor_27 * 2)) + 5) & 127;
    aux ^= cursor_27 & 15;
  }
  else
  {
    acc = ((acc - cursor_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000647_0_1;
  int sec_r000647_0_2;
  int sec_r000647_1_1;
  int sec_r000647_1_2;
  int sec_r000647_2_1;
  int sec_r000647_2_2;
  int sec_r000647_3_1;
  int sec_r000647_3_2;
  int sec_r000647_4_1;
  int sec_r000647_4_2;
  int sec_r000647_5_1;
  int sec_r000647_5_2;
  int sec_r000647_6_1;
  int sec_r000647_6_2;
  int sec_r000647_7_1;
  int sec_r000647_7_2;
  int sec_r000647_8_1;
  int sec_r000647_8_2;
  int sec_r000647_9_1;
  int sec_r000647_9_2;
  int sec_r000647_10_1;
  int sec_r000647_10_2;
  int sec_r000647_11_1;
  int sec_r000647_11_2;
  int sec_r000647_12_1;
  int sec_r000647_12_2;
  int sec_r000647_13_1;
  int sec_r000647_13_2;
  int sec_r000647_14_1;
  int sec_r000647_14_2;
  int sec_r000647_15_1;
  int sec_r000647_15_2;
  int sec_r000647_16_1;
  int sec_r000647_16_2;
  int sec_r000647_17_1;
  int sec_r000647_17_2;
  int sec_r000647_18_1;
  int sec_r000647_18_2;
  int sec_r000647_19_1;
  int sec_r000647_19_2;
  int sec_r000647_20_1;
  int sec_r000647_20_2;
  int sec_r000647_21_1;
  int sec_r000647_21_2;
  int pub_r000647_0_1;
  int pub_r000647_0_2;
  int pub_r000647_1_1;
  int pub_r000647_1_2;
  int pub_r000647_2_1;
  int pub_r000647_2_2;
  int pub_r000647_3_1;
  int pub_r000647_3_2;
  int pub_r000647_4_1;
  int pub_r000647_4_2;
  int pub_r000647_5_1;
  int pub_r000647_5_2;
  int pub_r000647_6_1;
  int pub_r000647_6_2;
  int pub_r000647_7_1;
  int pub_r000647_7_2;
  int pub_r000647_8_1;
  int pub_r000647_8_2;
  int pub_r000647_9_1;
  int pub_r000647_9_2;
  int pub_r000647_10_1;
  int pub_r000647_10_2;
  int pub_r000647_11_1;
  int pub_r000647_11_2;
  int pub_r000647_12_1;
  int pub_r000647_12_2;
  int pub_r000647_13_1;
  int pub_r000647_13_2;
  int pub_r000647_14_1;
  int pub_r000647_14_2;
  int pub_r000647_15_1;
  int pub_r000647_15_2;
  int pub_r000647_16_1;
  int pub_r000647_16_2;
  int pub_r000647_17_1;
  int pub_r000647_17_2;
  int pub_r000647_18_1;
  int pub_r000647_18_2;
  int pub_r000647_19_1;
  int pub_r000647_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000647_0_1 >= (-100)) && (pub_r000647_0_1 <= 100));
  __CPROVER_assume((pub_r000647_0_2 >= (-100)) && (pub_r000647_0_2 <= 100));
  __CPROVER_assume((pub_r000647_1_1 >= (-100)) && (pub_r000647_1_1 <= 100));
  __CPROVER_assume((pub_r000647_1_2 >= (-100)) && (pub_r000647_1_2 <= 100));
  __CPROVER_assume((pub_r000647_2_1 >= (-100)) && (pub_r000647_2_1 <= 100));
  __CPROVER_assume((pub_r000647_2_2 >= (-100)) && (pub_r000647_2_2 <= 100));
  __CPROVER_assume((pub_r000647_3_1 >= (-100)) && (pub_r000647_3_1 <= 100));
  __CPROVER_assume((pub_r000647_3_2 >= (-100)) && (pub_r000647_3_2 <= 100));
  __CPROVER_assume((pub_r000647_4_1 >= (-100)) && (pub_r000647_4_1 <= 100));
  __CPROVER_assume((pub_r000647_4_2 >= (-100)) && (pub_r000647_4_2 <= 100));
  __CPROVER_assume((pub_r000647_5_1 >= (-100)) && (pub_r000647_5_1 <= 100));
  __CPROVER_assume((pub_r000647_5_2 >= (-100)) && (pub_r000647_5_2 <= 100));
  __CPROVER_assume((pub_r000647_6_1 >= (-100)) && (pub_r000647_6_1 <= 100));
  __CPROVER_assume((pub_r000647_6_2 >= (-100)) && (pub_r000647_6_2 <= 100));
  __CPROVER_assume((pub_r000647_7_1 >= (-100)) && (pub_r000647_7_1 <= 100));
  __CPROVER_assume((pub_r000647_7_2 >= (-100)) && (pub_r000647_7_2 <= 100));
  __CPROVER_assume((pub_r000647_8_1 >= (-100)) && (pub_r000647_8_1 <= 100));
  __CPROVER_assume((pub_r000647_8_2 >= (-100)) && (pub_r000647_8_2 <= 100));
  __CPROVER_assume((pub_r000647_9_1 >= (-100)) && (pub_r000647_9_1 <= 100));
  __CPROVER_assume((pub_r000647_9_2 >= (-100)) && (pub_r000647_9_2 <= 100));
  __CPROVER_assume((pub_r000647_10_1 >= (-100)) && (pub_r000647_10_1 <= 100));
  __CPROVER_assume((pub_r000647_10_2 >= (-100)) && (pub_r000647_10_2 <= 100));
  __CPROVER_assume((pub_r000647_11_1 >= (-100)) && (pub_r000647_11_1 <= 100));
  __CPROVER_assume((pub_r000647_11_2 >= (-100)) && (pub_r000647_11_2 <= 100));
  __CPROVER_assume((pub_r000647_12_1 >= (-100)) && (pub_r000647_12_1 <= 100));
  __CPROVER_assume((pub_r000647_12_2 >= (-100)) && (pub_r000647_12_2 <= 100));
  __CPROVER_assume((pub_r000647_13_1 >= (-100)) && (pub_r000647_13_1 <= 100));
  __CPROVER_assume((pub_r000647_13_2 >= (-100)) && (pub_r000647_13_2 <= 100));
  __CPROVER_assume((pub_r000647_14_1 >= (-100)) && (pub_r000647_14_1 <= 100));
  __CPROVER_assume((pub_r000647_14_2 >= (-100)) && (pub_r000647_14_2 <= 100));
  __CPROVER_assume((pub_r000647_15_1 >= (-100)) && (pub_r000647_15_1 <= 100));
  __CPROVER_assume((pub_r000647_15_2 >= (-100)) && (pub_r000647_15_2 <= 100));
  __CPROVER_assume((pub_r000647_16_1 >= (-100)) && (pub_r000647_16_1 <= 100));
  __CPROVER_assume((pub_r000647_16_2 >= (-100)) && (pub_r000647_16_2 <= 100));
  __CPROVER_assume((pub_r000647_17_1 >= (-100)) && (pub_r000647_17_1 <= 100));
  __CPROVER_assume((pub_r000647_17_2 >= (-100)) && (pub_r000647_17_2 <= 100));
  __CPROVER_assume((pub_r000647_18_1 >= (-100)) && (pub_r000647_18_1 <= 100));
  __CPROVER_assume((pub_r000647_18_2 >= (-100)) && (pub_r000647_18_2 <= 100));
  __CPROVER_assume((pub_r000647_19_1 >= (-100)) && (pub_r000647_19_1 <= 100));
  __CPROVER_assume((pub_r000647_19_2 >= (-100)) && (pub_r000647_19_2 <= 100));
  __CPROVER_assume((sec_r000647_0_1 >= 0) && (sec_r000647_0_1 <= 255));
  __CPROVER_assume((sec_r000647_0_2 >= 0) && (sec_r000647_0_2 <= 255));
  __CPROVER_assume((sec_r000647_1_1 >= 0) && (sec_r000647_1_1 <= 255));
  __CPROVER_assume((sec_r000647_1_2 >= 0) && (sec_r000647_1_2 <= 255));
  __CPROVER_assume((sec_r000647_2_1 >= 0) && (sec_r000647_2_1 <= 255));
  __CPROVER_assume((sec_r000647_2_2 >= 0) && (sec_r000647_2_2 <= 255));
  __CPROVER_assume((sec_r000647_3_1 >= 0) && (sec_r000647_3_1 <= 255));
  __CPROVER_assume((sec_r000647_3_2 >= 0) && (sec_r000647_3_2 <= 255));
  __CPROVER_assume((sec_r000647_4_1 >= 0) && (sec_r000647_4_1 <= 255));
  __CPROVER_assume((sec_r000647_4_2 >= 0) && (sec_r000647_4_2 <= 255));
  __CPROVER_assume((sec_r000647_5_1 >= 0) && (sec_r000647_5_1 <= 255));
  __CPROVER_assume((sec_r000647_5_2 >= 0) && (sec_r000647_5_2 <= 255));
  __CPROVER_assume((sec_r000647_6_1 >= 0) && (sec_r000647_6_1 <= 255));
  __CPROVER_assume((sec_r000647_6_2 >= 0) && (sec_r000647_6_2 <= 255));
  __CPROVER_assume((sec_r000647_7_1 >= 0) && (sec_r000647_7_1 <= 255));
  __CPROVER_assume((sec_r000647_7_2 >= 0) && (sec_r000647_7_2 <= 255));
  __CPROVER_assume((sec_r000647_8_1 >= 0) && (sec_r000647_8_1 <= 255));
  __CPROVER_assume((sec_r000647_8_2 >= 0) && (sec_r000647_8_2 <= 255));
  __CPROVER_assume((sec_r000647_9_1 >= 0) && (sec_r000647_9_1 <= 255));
  __CPROVER_assume((sec_r000647_9_2 >= 0) && (sec_r000647_9_2 <= 255));
  __CPROVER_assume((sec_r000647_10_1 >= 0) && (sec_r000647_10_1 <= 255));
  __CPROVER_assume((sec_r000647_10_2 >= 0) && (sec_r000647_10_2 <= 255));
  __CPROVER_assume((sec_r000647_11_1 >= 0) && (sec_r000647_11_1 <= 255));
  __CPROVER_assume((sec_r000647_11_2 >= 0) && (sec_r000647_11_2 <= 255));
  __CPROVER_assume((sec_r000647_12_1 >= 0) && (sec_r000647_12_1 <= 255));
  __CPROVER_assume((sec_r000647_12_2 >= 0) && (sec_r000647_12_2 <= 255));
  __CPROVER_assume((sec_r000647_13_1 >= 0) && (sec_r000647_13_1 <= 255));
  __CPROVER_assume((sec_r000647_13_2 >= 0) && (sec_r000647_13_2 <= 255));
  __CPROVER_assume((sec_r000647_14_1 >= 0) && (sec_r000647_14_1 <= 255));
  __CPROVER_assume((sec_r000647_14_2 >= 0) && (sec_r000647_14_2 <= 255));
  __CPROVER_assume((sec_r000647_15_1 >= 0) && (sec_r000647_15_1 <= 255));
  __CPROVER_assume((sec_r000647_15_2 >= 0) && (sec_r000647_15_2 <= 255));
  __CPROVER_assume((sec_r000647_16_1 >= 0) && (sec_r000647_16_1 <= 255));
  __CPROVER_assume((sec_r000647_16_2 >= 0) && (sec_r000647_16_2 <= 255));
  __CPROVER_assume((sec_r000647_17_1 >= 0) && (sec_r000647_17_1 <= 255));
  __CPROVER_assume((sec_r000647_17_2 >= 0) && (sec_r000647_17_2 <= 255));
  __CPROVER_assume((sec_r000647_18_1 >= 0) && (sec_r000647_18_1 <= 255));
  __CPROVER_assume((sec_r000647_18_2 >= 0) && (sec_r000647_18_2 <= 255));
  __CPROVER_assume((sec_r000647_19_1 >= 0) && (sec_r000647_19_1 <= 255));
  __CPROVER_assume((sec_r000647_19_2 >= 0) && (sec_r000647_19_2 <= 255));
  __CPROVER_assume((sec_r000647_20_1 >= 0) && (sec_r000647_20_1 <= 255));
  __CPROVER_assume((sec_r000647_20_2 >= 0) && (sec_r000647_20_2 <= 255));
  __CPROVER_assume((sec_r000647_21_1 >= 0) && (sec_r000647_21_1 <= 255));
  __CPROVER_assume((sec_r000647_21_2 >= 0) && (sec_r000647_21_2 <= 255));
  struct MatrixBlock_R000647_4713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000647_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000647_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000647_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000647_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000647_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000647_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000647_0_2 + 7) & 15;
  struct StreamBuffer_R000647_4713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000647_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000647_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000647_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000647_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000647_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000647_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000647_0_2 + 9) & 15;
  struct SensorNode_R000647_4713_2 st_var_2_1 = {0};
  struct SensorNode_R000647_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000647_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000647_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000647_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000647_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000647_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000647_0_2 + 11) & 15;
  struct FilterState_R000647_4713_3 st_var_3_1 = {0};
  struct FilterState_R000647_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000647_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000647_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000647_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000647_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000647_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000647_0_2 + 13) & 15;
  union PacketPayload_R000647_4713_0 u_var_1;
  union PacketPayload_R000647_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
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
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
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
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 26)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 26)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 25)
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
  if (stage_v_21_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 25)
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
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 43)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 43)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 52)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 52)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 32)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 32)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

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
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
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
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 30)
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
  if (stage_v_43_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 30)
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
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = (st_var_3_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_3_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 54) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (st_var_1_1.buffer[0] ^ 60) & 3;
  int stage_v_57_2 = (st_var_1_2.buffer[0] ^ 60) & 3;
  switch (stage_v_57_1)
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

  switch (stage_v_57_2)
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

  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (st_var_3_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_3_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 29)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 29)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 64) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = ((st_var_2_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_2_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 26)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 26)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 47)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 47)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 35)
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
  if (stage_v_73_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 35)
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
  if ((sec_r000647_10_1 & 1) != 0)
  {
    if ((sec_r000647_11_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((sec_r000647_10_2 & 1) != 0)
  {
    if ((sec_r000647_11_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000647_2_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000647_19_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000647_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000647_19_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000647_2_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000647_19_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000647_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000647_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000647_0_1 & 1) != 0)
  {
    if ((sec_r000647_17_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000647_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000647_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000647_16_1 + 7) & 127;
  }
  if ((sec_r000647_0_2 & 1) != 0)
  {
    if ((sec_r000647_17_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000647_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000647_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000647_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000647_9_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000647_17_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000647_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000647_17_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000647_9_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000647_17_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000647_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000647_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000647_16_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000647_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000647_16_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000647_16_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000647_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000647_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000647_9_1 & 1) != 0)
  {
    if ((sec_r000647_21_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000647_11_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000647_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000647_11_1 + 7) & 127;
  }
  if ((sec_r000647_9_2 & 1) != 0)
  {
    if ((sec_r000647_21_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000647_11_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000647_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000647_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000647_7_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000647_17_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000647_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000647_17_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000647_7_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000647_17_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000647_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000647_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000647_4_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((sec_r000647_4_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000647_14_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000647_14_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000647_5_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000647_15_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000647_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000647_15_1 + 7) & 127;
  }
  if ((sec_r000647_5_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000647_15_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000647_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000647_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000647_15_1 & 1) != 0)
  {
    if ((sec_r000647_0_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000647_12_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000647_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000647_12_1 + 7) & 127;
  }
  if ((sec_r000647_15_2 & 1) != 0)
  {
    if ((sec_r000647_0_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000647_12_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000647_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000647_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000647_10_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000647_16_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000647_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000647_16_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000647_10_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000647_16_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000647_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000647_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000647_7_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((sec_r000647_7_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000647_7_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000647_16_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000647_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000647_16_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000647_7_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000647_16_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000647_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000647_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000647_5_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((sec_r000647_5_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000647_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000647_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000647_10_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000647_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000647_10_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000647_10_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000647_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000647_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000647_17_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000647_11_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000647_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000647_11_1 + 7) & 127;
  }
  if ((sec_r000647_17_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000647_11_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000647_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000647_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000647_9_1 & 1) != 0)
  {
    if ((sec_r000647_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000647_6_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000647_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000647_6_1 + 7) & 127;
  }
  if ((sec_r000647_9_2 & 1) != 0)
  {
    if ((sec_r000647_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000647_6_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000647_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000647_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000647_2_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000647_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000647_2_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000647_2_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000647_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000647_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000647_2_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000647_1_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000647_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000647_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000647_2_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000647_1_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000647_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000647_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000647_5_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000647_3_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000647_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000647_3_1 + 7) & 127;
  }
  if ((sec_r000647_5_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000647_3_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000647_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000647_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000647_10_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((sec_r000647_10_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000647_0_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((sec_r000647_0_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000647_6_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000647_8_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000647_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000647_8_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000647_6_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000647_8_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000647_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000647_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000647_3_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000647_3_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000647_1_1 & 1) != 0)
  {
    if ((sec_r000647_12_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000647_19_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000647_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000647_19_1 + 7) & 127;
  }
  if ((sec_r000647_1_2 & 1) != 0)
  {
    if ((sec_r000647_12_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000647_19_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000647_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000647_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000647_4_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((sec_r000647_4_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000647_21_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000647_14_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000647_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000647_14_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000647_21_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000647_14_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000647_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000647_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000647_14_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000647_6_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000647_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000647_6_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000647_14_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000647_6_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000647_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000647_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000647_20_1 & 1) != 0)
  {
    if ((sec_r000647_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000647_3_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000647_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000647_3_1 + 7) & 127;
  }
  if ((sec_r000647_20_2 & 1) != 0)
  {
    if ((sec_r000647_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000647_3_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000647_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000647_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000647_3_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000647_3_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000647_19_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000647_11_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000647_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000647_11_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000647_19_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000647_11_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000647_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000647_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000647_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000647_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000647_6_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000647_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000647_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000647_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000647_18_1 & 1) != 0)
  {
    if ((sec_r000647_17_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((sec_r000647_18_2 & 1) != 0)
  {
    if ((sec_r000647_17_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000647_11_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000647_11_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000647_11_1 & 1) != 0)
  {
    if ((sec_r000647_21_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000647_15_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000647_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000647_15_1 + 7) & 127;
  }
  if ((sec_r000647_11_2 & 1) != 0)
  {
    if ((sec_r000647_21_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000647_15_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000647_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000647_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000647_19_1 & 1) != 0)
  {
    if ((sec_r000647_2_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000647_8_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000647_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000647_8_1 + 7) & 127;
  }
  if ((sec_r000647_19_2 & 1) != 0)
  {
    if ((sec_r000647_2_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000647_8_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000647_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000647_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000647_7_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000647_15_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000647_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000647_15_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000647_7_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000647_15_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000647_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000647_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000647_3_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000647_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000647_3_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000647_3_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000647_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000647_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000647_6_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000647_6_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000647_0_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000647_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000647_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000647_6_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000647_0_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000647_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000647_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000647_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000647_0_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((sec_r000647_0_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000647_10_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000647_6_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000647_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000647_6_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000647_10_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000647_6_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000647_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000647_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000647_21_1 & 1) != 0)
  {
    if ((sec_r000647_17_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000647_19_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000647_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000647_19_1 + 7) & 127;
  }
  if ((sec_r000647_21_2 & 1) != 0)
  {
    if ((sec_r000647_17_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000647_19_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000647_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000647_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000647_10_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000647_10_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000647_11_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000647_13_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000647_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000647_13_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000647_11_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000647_13_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000647_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000647_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000647_10_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000647_12_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000647_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000647_12_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000647_10_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000647_12_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000647_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000647_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000647_10_1 & 1) != 0)
  {
    if ((sec_r000647_13_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000647_8_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000647_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000647_8_1 + 7) & 127;
  }
  if ((sec_r000647_10_2 & 1) != 0)
  {
    if ((sec_r000647_13_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000647_8_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000647_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000647_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000647_20_1 & 1) != 0)
  {
    if ((sec_r000647_12_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000647_10_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000647_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000647_10_1 + 7) & 127;
  }
  if ((sec_r000647_20_2 & 1) != 0)
  {
    if ((sec_r000647_12_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000647_10_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000647_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000647_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000647_0_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000647_19_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000647_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000647_19_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000647_0_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000647_19_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000647_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000647_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000647_4_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000647_4_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000647_12_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000647_2_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000647_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000647_2_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000647_12_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000647_2_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000647_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000647_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000647_13_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000647_13_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000647_11_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000647_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000647_11_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000647_11_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000647_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000647_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000647_21_1 & 1) != 0)
  {
    if ((sec_r000647_9_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((sec_r000647_21_2 & 1) != 0)
  {
    if ((sec_r000647_9_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000647_19_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000647_15_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000647_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000647_15_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000647_19_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000647_15_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000647_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000647_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000647_11_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000647_11_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000647_12_1 & 1) != 0)
  {
    if ((sec_r000647_12_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((sec_r000647_12_2 & 1) != 0)
  {
    if ((sec_r000647_12_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000647_10_1 & 1) != 0)
  {
    if ((sec_r000647_3_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000647_18_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000647_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000647_18_1 + 7) & 127;
  }
  if ((sec_r000647_10_2 & 1) != 0)
  {
    if ((sec_r000647_3_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000647_18_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000647_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000647_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000647_0_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000647_16_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000647_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000647_16_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000647_0_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000647_16_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000647_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000647_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000647_13_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((sec_r000647_13_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000647_17_1 & 1) != 0)
  {
    if ((sec_r000647_18_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000647_14_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000647_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000647_14_1 + 7) & 127;
  }
  if ((sec_r000647_17_2 & 1) != 0)
  {
    if ((sec_r000647_18_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000647_14_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000647_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000647_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000647_10_1 & 1) != 0)
  {
    if ((sec_r000647_18_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000647_10_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000647_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000647_10_1 + 7) & 127;
  }
  if ((sec_r000647_10_2 & 1) != 0)
  {
    if ((sec_r000647_18_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000647_10_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000647_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000647_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000647_3_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000647_5_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000647_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000647_5_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000647_3_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000647_5_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000647_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000647_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000647_20_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000647_4_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000647_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000647_4_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000647_20_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000647_4_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000647_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000647_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000647_11_1 & 1) != 0)
  {
    if ((sec_r000647_1_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000647_17_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000647_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000647_17_1 + 7) & 127;
  }
  if ((sec_r000647_11_2 & 1) != 0)
  {
    if ((sec_r000647_1_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000647_17_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000647_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000647_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000647_18_1 & 1) != 0)
  {
    if ((sec_r000647_15_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000647_8_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000647_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000647_8_1 + 7) & 127;
  }
  if ((sec_r000647_18_2 & 1) != 0)
  {
    if ((sec_r000647_15_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000647_8_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000647_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000647_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000647_9_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000647_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000647_9_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000647_9_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000647_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000647_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000647_1_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000647_1_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000647_18_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000647_8_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000647_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000647_8_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000647_18_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000647_8_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000647_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000647_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000647_17_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000647_14_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000647_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000647_14_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000647_17_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000647_14_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000647_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000647_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000647_14_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000647_1_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000647_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000647_1_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000647_14_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000647_1_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000647_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000647_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000647_20_1 & 1) != 0)
  {
    if ((sec_r000647_20_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000647_10_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000647_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000647_10_1 + 7) & 127;
  }
  if ((sec_r000647_20_2 & 1) != 0)
  {
    if ((sec_r000647_20_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000647_10_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000647_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000647_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000647_16_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000647_1_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000647_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000647_1_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000647_16_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000647_1_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000647_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000647_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000647_13_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000647_12_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000647_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000647_12_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000647_13_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000647_12_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000647_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000647_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000647_6_1 & 1) != 0)
  {
    if ((sec_r000647_5_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((sec_r000647_6_2 & 1) != 0)
  {
    if ((sec_r000647_5_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000647_11_1 & 1) != 0)
  {
    if ((sec_r000647_21_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000647_1_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000647_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000647_1_1 + 7) & 127;
  }
  if ((sec_r000647_11_2 & 1) != 0)
  {
    if ((sec_r000647_21_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000647_1_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000647_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000647_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000647_1_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000647_11_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000647_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000647_11_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000647_1_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000647_11_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000647_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000647_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((sec_r000647_4_1 & 1) != 0)
  {
    if ((sec_r000647_14_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000647_15_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000647_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000647_15_1 + 7) & 127;
  }
  if ((sec_r000647_4_2 & 1) != 0)
  {
    if ((sec_r000647_14_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000647_15_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000647_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000647_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000647_14_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000647_3_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000647_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000647_3_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000647_14_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000647_3_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000647_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000647_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000647_18_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000647_0_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000647_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000647_0_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000647_18_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000647_0_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000647_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000647_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000647_1_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000647_7_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000647_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000647_7_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000647_1_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000647_7_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000647_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000647_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((sec_r000647_12_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000647_1_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000647_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000647_1_1 + 7) & 127;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((sec_r000647_12_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000647_1_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000647_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000647_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000647_18_1 != sec_r000647_18_2);
  __CPROVER_assume(sec_r000647_14_1 != sec_r000647_14_2);
  __CPROVER_assume(pub_r000647_14_1 == pub_r000647_14_2);
  __CPROVER_assume(sec_r000647_0_1 != sec_r000647_0_2);
  __CPROVER_assume(sec_r000647_16_1 != sec_r000647_16_2);
  __CPROVER_assume(sec_r000647_3_1 != sec_r000647_3_2);
  __CPROVER_assume(sec_r000647_7_1 != sec_r000647_7_2);
  __CPROVER_assume(sec_r000647_11_1 != sec_r000647_11_2);
  __CPROVER_assume(sec_r000647_19_1 != sec_r000647_19_2);
  __CPROVER_assume(pub_r000647_5_1 == pub_r000647_5_2);
  __CPROVER_assume(pub_r000647_6_1 == pub_r000647_6_2);
  __CPROVER_assume(pub_r000647_10_1 == pub_r000647_10_2);
  __CPROVER_assume(pub_r000647_19_1 == pub_r000647_19_2);
  __CPROVER_assume(sec_r000647_12_1 != sec_r000647_12_2);
  __CPROVER_assume(sec_r000647_13_1 != sec_r000647_13_2);
  __CPROVER_assume(sec_r000647_2_1 != sec_r000647_2_2);
  __CPROVER_assume(sec_r000647_5_1 != sec_r000647_5_2);
  __CPROVER_assume(pub_r000647_3_1 == pub_r000647_3_2);
  __CPROVER_assume(pub_r000647_15_1 == pub_r000647_15_2);
  __CPROVER_assume(pub_r000647_11_1 == pub_r000647_11_2);
  __CPROVER_assume(pub_r000647_7_1 == pub_r000647_7_2);
  __CPROVER_assume(sec_r000647_17_1 != sec_r000647_17_2);
  __CPROVER_assume(sec_r000647_20_1 != sec_r000647_20_2);
  __CPROVER_assume(pub_r000647_12_1 == pub_r000647_12_2);
  __CPROVER_assume(sec_r000647_4_1 != sec_r000647_4_2);
  __CPROVER_assume(sec_r000647_6_1 != sec_r000647_6_2);
  __CPROVER_assume(sec_r000647_15_1 != sec_r000647_15_2);
  __CPROVER_assume(sec_r000647_21_1 != sec_r000647_21_2);
  __CPROVER_assume(pub_r000647_8_1 == pub_r000647_8_2);
  __CPROVER_assume(pub_r000647_2_1 == pub_r000647_2_2);
  __CPROVER_assume(sec_r000647_10_1 != sec_r000647_10_2);
  __CPROVER_assume(pub_r000647_1_1 == pub_r000647_1_2);
  __CPROVER_assume(pub_r000647_18_1 == pub_r000647_18_2);
  __CPROVER_assume(pub_r000647_17_1 == pub_r000647_17_2);
  __CPROVER_assume(pub_r000647_9_1 == pub_r000647_9_2);
  __CPROVER_assume(pub_r000647_16_1 == pub_r000647_16_2);
  __CPROVER_assume(pub_r000647_4_1 == pub_r000647_4_2);
  __CPROVER_assume(sec_r000647_9_1 != sec_r000647_9_2);
  __CPROVER_assume(sec_r000647_1_1 != sec_r000647_1_2);
  __CPROVER_assume(sec_r000647_8_1 != sec_r000647_8_2);
  __CPROVER_assume(pub_r000647_0_1 == pub_r000647_0_2);
  __CPROVER_assume(pub_r000647_13_1 == pub_r000647_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.damping == st_var_3_2.damping);
  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
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
}


