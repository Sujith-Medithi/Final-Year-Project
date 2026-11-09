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
struct SensorNode_R001863_6313_0
{
  int offset;
  int status;
  short reading;
  short gain;
  int buffer[3];
};
struct DeviceConfig_R001863_6313_1
{
  unsigned char parity;
  int baud_rate;
  int stop_bits;
  short port;
  unsigned char timeout;
  int buffer[3];
};
struct Vector3D_R001863_6313_2
{
  int norm_sq;
  int pitch;
  int coord_x;
  short coord_y;
  int buffer[3];
};
struct StreamBuffer_R001863_6313_3
{
  unsigned char tail;
  int capacity;
  short state;
  int checksum;
  int watermark;
  int buffer[3];
};
union PacketPayload_R001863_6313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001863_6313_1
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
void fn_R001863_6313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_49_1 = local_arr_1[aux_1 % 3];
  int parity_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_49_2 * 2)) & 127;
  int segment_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_16_1) & 63;
  aux_2 = (aux_2 + segment_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_30_1 = 0;
  int checksum_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_30_1 = ((checksum_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_30_2 = ((checksum_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_30_1) & 127;
    acc_2 = (acc_2 + checksum_30_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_49_1 == parity_49_2);
  assert(segment_16_1 == segment_16_2);
  assert(checksum_30_1 == checksum_30_2);
}

int fn_R001863_6313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int parity_49 = local_arr[aux % 3];
  acc = (acc + (parity_49 * 2)) & 127;
  int segment_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_16) & 63;
  acc ^= aux;
  int checksum_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_30 = ((checksum_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_30) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001863_6313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st_1 = {0};
  struct SensorNode_R001863_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_45_1 = local_arr_1[aux_1 % 3];
  int cursor_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_45_2 * 2)) & 127;
  int offset_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_56_1) & 63;
  aux_2 = (aux_2 + offset_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_29_1 > 18)
  {
    acc_1 = ((acc_1 + (damping_29_1 * 2)) + 5) & 127;
    aux_1 ^= damping_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_29_2 > 18)
  {
    acc_2 = ((acc_2 + (damping_29_2 * 2)) + 5) & 127;
    aux_2 ^= damping_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_45_1 == cursor_45_2);
  assert(offset_56_1 == offset_56_2);
  assert(damping_29_1 == damping_29_2);
}

int fn_R001863_6313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int cursor_45 = local_arr[aux % 3];
  acc = (acc + (cursor_45 * 2)) & 127;
  int offset_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_56) & 63;
  acc ^= aux;
  int damping_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_29 > 18)
  {
    acc = ((acc + (damping_29 * 2)) + 5) & 127;
    aux ^= damping_29 & 15;
  }
  else
  {
    acc = ((acc - damping_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001863_6313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st_1 = {0};
  struct StreamBuffer_R001863_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_18_1)
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

  switch (residue_18_2)
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

  int stride_55_1 = 0;
  int stride_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_55_1 = ((stride_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_55_2 = ((stride_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_55_1) & 127;
    acc_2 = (acc_2 + stride_55_2) & 127;
  }

  int factor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_77_1 > 38)
  {
    acc_1 = ((acc_1 + (factor_77_1 * 2)) + 5) & 127;
    aux_1 ^= factor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_77_2 > 38)
  {
    acc_2 = ((acc_2 + (factor_77_2 * 2)) + 5) & 127;
    aux_2 ^= factor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_18_1 == residue_18_2);
  assert(stride_55_1 == stride_55_2);
  assert(factor_77_1 == factor_77_2);
}

int fn_R001863_6313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_18 = (aux + st.buffer[1]) & 3;
  switch (residue_18)
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

  int stride_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_55 = ((stride_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_55) & 127;
  }

  int factor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_77 > 38)
  {
    acc = ((acc + (factor_77 * 2)) + 5) & 127;
    aux ^= factor_77 & 15;
  }
  else
  {
    acc = ((acc - factor_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001863_6313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_74_1)
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

  switch (weight_74_2)
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

  int checksum_64_1 = 0;
  int checksum_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_64_1 = ((checksum_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_64_2 = ((checksum_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_64_1) & 127;
    acc_2 = (acc_2 + checksum_64_2) & 127;
  }

  int segment_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_20_1) & 63;
  aux_2 = (aux_2 + segment_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_74_1 == weight_74_2);
  assert(checksum_64_1 == checksum_64_2);
  assert(segment_20_1 == segment_20_2);
}

int fn_R001863_6313_3(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_74 = (aux + st.buffer[1]) & 3;
  switch (weight_74)
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

  int checksum_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_64 = ((checksum_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_64) & 127;
  }

  int segment_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001863_6313_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st_1 = {0};
  struct DeviceConfig_R001863_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_15_1 > 14)
  {
    acc_1 = ((acc_1 + (margin_15_1 * 2)) + 5) & 127;
    aux_1 ^= margin_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_15_2 > 14)
  {
    acc_2 = ((acc_2 + (margin_15_2 * 2)) + 5) & 127;
    aux_2 ^= margin_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_40_1)
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

  switch (cursor_40_2)
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

  int pivot_29_1 = 0;
  int pivot_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_29_1 = ((pivot_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_29_2 = ((pivot_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_29_1) & 127;
    acc_2 = (acc_2 + pivot_29_2) & 127;
  }

  int quotient_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_22_1) & 63;
  aux_2 = (aux_2 + quotient_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_15_1 == margin_15_2);
  assert(cursor_40_1 == cursor_40_2);
  assert(pivot_29_1 == pivot_29_2);
  assert(quotient_22_1 == quotient_22_2);
}

int fn_R001863_6313_4(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_15 > 14)
  {
    acc = ((acc + (margin_15 * 2)) + 5) & 127;
    aux ^= margin_15 & 15;
  }
  else
  {
    acc = ((acc - margin_15) + 11) & 127;
    aux += 3;
  }
  int cursor_40 = (aux + st.buffer[1]) & 3;
  switch (cursor_40)
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

  int pivot_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_29 = ((pivot_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_29) & 127;
  }

  int quotient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001863_6313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_86_1 = local_arr_1[aux_1 % 3];
  int threshold_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_86_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_49_1) & 63;
  aux_2 = (aux_2 + tally_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_86_1 == threshold_86_2);
  assert(tally_49_1 == tally_49_2);
}

int fn_R001863_6313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int threshold_86 = local_arr[aux % 3];
  acc = (acc + (threshold_86 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001863_6313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st_1 = {0};
  struct DeviceConfig_R001863_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int phase_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_46_1 > 32)
  {
    acc_1 = ((acc_1 + (phase_46_1 * 2)) + 5) & 127;
    aux_1 ^= phase_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_46_2 > 32)
  {
    acc_2 = ((acc_2 + (phase_46_2 * 2)) + 5) & 127;
    aux_2 ^= phase_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_66_1) & 63;
  aux_2 = (aux_2 + tracker_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_46_1 == phase_46_2);
  assert(tracker_66_1 == tracker_66_2);
}

int fn_R001863_6313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int phase_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_46 > 32)
  {
    acc = ((acc + (phase_46 * 2)) + 5) & 127;
    aux ^= phase_46 & 15;
  }
  else
  {
    acc = ((acc - phase_46) + 11) & 127;
    aux += 3;
  }
  int tracker_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001863_6313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st_1 = {0};
  struct SensorNode_R001863_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_27_1 = local_arr_1[aux_1 % 3];
  int checksum_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_27_1 == checksum_27_2);
}

int fn_R001863_6313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_27 = local_arr[aux % 3];
  acc = (acc + (checksum_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001863_6313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st_1 = {0};
  struct StreamBuffer_R001863_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int cursor_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_39_1)
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

  switch (cursor_39_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_39_1 == cursor_39_2);
}

int fn_R001863_6313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int cursor_39 = (aux + st.buffer[1]) & 3;
  switch (cursor_39)
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

void fn_R001863_6313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st_1 = {0};
  struct StreamBuffer_R001863_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_62_1 > 36)
  {
    acc_1 = ((acc_1 + (bound_62_1 * 2)) + 5) & 127;
    aux_1 ^= bound_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_62_2 > 36)
  {
    acc_2 = ((acc_2 + (bound_62_2 * 2)) + 5) & 127;
    aux_2 ^= bound_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_62_1)
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

  switch (weight_62_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_62_1 == bound_62_2);
  assert(weight_62_1 == weight_62_2);
}

int fn_R001863_6313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_62 > 36)
  {
    acc = ((acc + (bound_62 * 2)) + 5) & 127;
    aux ^= bound_62 & 15;
  }
  else
  {
    acc = ((acc - bound_62) + 11) & 127;
    aux += 3;
  }
  int weight_62 = (aux + st.buffer[1]) & 3;
  switch (weight_62)
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

void fn_R001863_6313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int coefficient_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_15_1 > 46)
  {
    acc_1 = ((acc_1 + (coefficient_15_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_15_2 > 46)
  {
    acc_2 = ((acc_2 + (coefficient_15_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_48_1 = local_arr_1[aux_1 % 3];
  int pivot_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_48_2 * 2)) & 127;
  int margin_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_72_1)
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

  switch (margin_72_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_48_1 == pivot_48_2);
  assert(margin_72_1 == margin_72_2);
}

int fn_R001863_6313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int coefficient_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_15 > 46)
  {
    acc = ((acc + (coefficient_15 * 2)) + 5) & 127;
    aux ^= coefficient_15 & 15;
  }
  else
  {
    acc = ((acc - coefficient_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_48 = local_arr[aux % 3];
  acc = (acc + (pivot_48 * 2)) & 127;
  int margin_72 = (aux + st.buffer[1]) & 3;
  switch (margin_72)
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

void fn_R001863_6313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st_1 = {0};
  struct DeviceConfig_R001863_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int residue_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_32_1)
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

  switch (residue_32_2)
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

  int delta_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_66_1) & 63;
  aux_2 = (aux_2 + delta_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_26_1 = 0;
  int damping_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_26_1 = ((damping_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_26_2 = ((damping_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_26_1) & 127;
    acc_2 = (acc_2 + damping_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_32_1 == residue_32_2);
  assert(delta_66_1 == delta_66_2);
  assert(damping_26_1 == damping_26_2);
}

int fn_R001863_6313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int residue_32 = (aux + st.buffer[1]) & 3;
  switch (residue_32)
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

  int delta_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_66) & 63;
  acc ^= aux;
  int damping_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_26 = ((damping_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001863_6313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st_1 = {0};
  struct SensorNode_R001863_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_56_1 = local_arr_1[aux_1 % 3];
  int segment_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_56_2 * 2)) & 127;
  int threshold_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_16_1) & 63;
  aux_2 = (aux_2 + threshold_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_31_1 > 11)
  {
    acc_1 = ((acc_1 + (pivot_31_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_31_2 > 11)
  {
    acc_2 = ((acc_2 + (pivot_31_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_56_1 = 0;
  int accumulator_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_56_1 = ((accumulator_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_56_2 = ((accumulator_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_56_1) & 127;
    acc_2 = (acc_2 + accumulator_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_56_1 == segment_56_2);
  assert(threshold_16_1 == threshold_16_2);
  assert(pivot_31_1 == pivot_31_2);
  assert(accumulator_56_1 == accumulator_56_2);
}

int fn_R001863_6313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001863_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int segment_56 = local_arr[aux % 3];
  acc = (acc + (segment_56 * 2)) & 127;
  int threshold_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_16) & 63;
  acc ^= aux;
  int pivot_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_31 > 11)
  {
    acc = ((acc + (pivot_31 * 2)) + 5) & 127;
    aux ^= pivot_31 & 15;
  }
  else
  {
    acc = ((acc - pivot_31) + 11) & 127;
    aux += 3;
  }
  int accumulator_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_56 = ((accumulator_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001863_6313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st_1 = {0};
  struct DeviceConfig_R001863_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_51_1 = 0;
  int weight_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_51_1 = ((weight_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_51_2 = ((weight_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_51_1) & 127;
    acc_2 = (acc_2 + weight_51_2) & 127;
  }

  int offset_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_93_1)
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

  switch (offset_93_2)
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
  int parity_79_1 = local_arr_1[aux_1 % 3];
  int parity_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_51_1 == weight_51_2);
  assert(offset_93_1 == offset_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_79_1 == parity_79_2);
}

int fn_R001863_6313_13(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001863_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_51 = ((weight_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_51) & 127;
  }

  int offset_93 = (aux + st.buffer[1]) & 3;
  switch (offset_93)
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
  int parity_79 = local_arr[aux % 3];
  acc = (acc + (parity_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001863_6313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_79_1 = 0;
  int pivot_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_79_1 = ((pivot_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_79_2 = ((pivot_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_79_1) & 127;
    acc_2 = (acc_2 + pivot_79_2) & 127;
  }

  int phase_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_52_1) & 63;
  aux_2 = (aux_2 + phase_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_79_1 == pivot_79_2);
  assert(phase_52_1 == phase_52_2);
}

int fn_R001863_6313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_79 = ((pivot_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_79) & 127;
  }

  int phase_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001863_6313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_65_1 = local_arr_1[aux_1 % 3];
  int damping_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_65_2 * 2)) & 127;
  int parity_98_1 = 0;
  int parity_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_98_1 = ((parity_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_98_2 = ((parity_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_98_1) & 127;
    acc_2 = (acc_2 + parity_98_2) & 127;
  }

  int bound_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_27_1)
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

  switch (bound_27_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_65_1 == damping_65_2);
  assert(parity_98_1 == parity_98_2);
  assert(bound_27_1 == bound_27_2);
}

int fn_R001863_6313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int damping_65 = local_arr[aux % 3];
  acc = (acc + (damping_65 * 2)) & 127;
  int parity_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_98 = ((parity_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_98) & 127;
  }

  int bound_27 = (aux + st.buffer[1]) & 3;
  switch (bound_27)
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
  return (acc + aux) & 255;
}

void fn_R001863_6313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st_1 = {0};
  struct StreamBuffer_R001863_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_27_1) & 63;
  aux_2 = (aux_2 + metric_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_15_1 = 0;
  int tracker_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_15_1 = ((tracker_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_15_2 = ((tracker_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_15_1) & 127;
    acc_2 = (acc_2 + tracker_15_2) & 127;
  }

  int accumulator_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_37_1)
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

  switch (accumulator_37_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_27_1 == metric_27_2);
  assert(tracker_15_1 == tracker_15_2);
  assert(accumulator_37_1 == accumulator_37_2);
}

int fn_R001863_6313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001863_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_15 = ((tracker_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_15) & 127;
  }

  int accumulator_37 = (aux + st.buffer[1]) & 3;
  switch (accumulator_37)
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

void fn_R001863_6313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st_1 = {0};
  struct Vector3D_R001863_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int weight_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_53_1) & 63;
  aux_2 = (aux_2 + weight_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_82_1 = local_arr_1[aux_1 % 3];
  int quotient_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_82_2 * 2)) & 127;
  int parity_82_1 = 0;
  int parity_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_82_1 = ((parity_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_82_2 = ((parity_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_82_1) & 127;
    acc_2 = (acc_2 + parity_82_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_53_1 == weight_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_82_1 == quotient_82_2);
  assert(parity_82_1 == parity_82_2);
}

int fn_R001863_6313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001863_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int weight_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_53) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_82 = local_arr[aux % 3];
  acc = (acc + (quotient_82 * 2)) & 127;
  int parity_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_82 = ((parity_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_82) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001863_0_1;
  int sec_r001863_0_2;
  int sec_r001863_1_1;
  int sec_r001863_1_2;
  int sec_r001863_2_1;
  int sec_r001863_2_2;
  int sec_r001863_3_1;
  int sec_r001863_3_2;
  int sec_r001863_4_1;
  int sec_r001863_4_2;
  int sec_r001863_5_1;
  int sec_r001863_5_2;
  int sec_r001863_6_1;
  int sec_r001863_6_2;
  int sec_r001863_7_1;
  int sec_r001863_7_2;
  int sec_r001863_8_1;
  int sec_r001863_8_2;
  int sec_r001863_9_1;
  int sec_r001863_9_2;
  int sec_r001863_10_1;
  int sec_r001863_10_2;
  int sec_r001863_11_1;
  int sec_r001863_11_2;
  int sec_r001863_12_1;
  int sec_r001863_12_2;
  int sec_r001863_13_1;
  int sec_r001863_13_2;
  int sec_r001863_14_1;
  int sec_r001863_14_2;
  int sec_r001863_15_1;
  int sec_r001863_15_2;
  int sec_r001863_16_1;
  int sec_r001863_16_2;
  int sec_r001863_17_1;
  int sec_r001863_17_2;
  int sec_r001863_18_1;
  int sec_r001863_18_2;
  int sec_r001863_19_1;
  int sec_r001863_19_2;
  int sec_r001863_20_1;
  int sec_r001863_20_2;
  int sec_r001863_21_1;
  int sec_r001863_21_2;
  int sec_r001863_22_1;
  int sec_r001863_22_2;
  int sec_r001863_23_1;
  int sec_r001863_23_2;
  int pub_r001863_0_1;
  int pub_r001863_0_2;
  int pub_r001863_1_1;
  int pub_r001863_1_2;
  int pub_r001863_2_1;
  int pub_r001863_2_2;
  int pub_r001863_3_1;
  int pub_r001863_3_2;
  int pub_r001863_4_1;
  int pub_r001863_4_2;
  int pub_r001863_5_1;
  int pub_r001863_5_2;
  int pub_r001863_6_1;
  int pub_r001863_6_2;
  int pub_r001863_7_1;
  int pub_r001863_7_2;
  int pub_r001863_8_1;
  int pub_r001863_8_2;
  int pub_r001863_9_1;
  int pub_r001863_9_2;
  int pub_r001863_10_1;
  int pub_r001863_10_2;
  int pub_r001863_11_1;
  int pub_r001863_11_2;
  int pub_r001863_12_1;
  int pub_r001863_12_2;
  int pub_r001863_13_1;
  int pub_r001863_13_2;
  int pub_r001863_14_1;
  int pub_r001863_14_2;
  int pub_r001863_15_1;
  int pub_r001863_15_2;
  int pub_r001863_16_1;
  int pub_r001863_16_2;
  int pub_r001863_17_1;
  int pub_r001863_17_2;
  int pub_r001863_18_1;
  int pub_r001863_18_2;
  int pub_r001863_19_1;
  int pub_r001863_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001863_0_1 >= (-100)) && (pub_r001863_0_1 <= 100));
  __CPROVER_assume((pub_r001863_0_2 >= (-100)) && (pub_r001863_0_2 <= 100));
  __CPROVER_assume((pub_r001863_1_1 >= (-100)) && (pub_r001863_1_1 <= 100));
  __CPROVER_assume((pub_r001863_1_2 >= (-100)) && (pub_r001863_1_2 <= 100));
  __CPROVER_assume((pub_r001863_2_1 >= (-100)) && (pub_r001863_2_1 <= 100));
  __CPROVER_assume((pub_r001863_2_2 >= (-100)) && (pub_r001863_2_2 <= 100));
  __CPROVER_assume((pub_r001863_3_1 >= (-100)) && (pub_r001863_3_1 <= 100));
  __CPROVER_assume((pub_r001863_3_2 >= (-100)) && (pub_r001863_3_2 <= 100));
  __CPROVER_assume((pub_r001863_4_1 >= (-100)) && (pub_r001863_4_1 <= 100));
  __CPROVER_assume((pub_r001863_4_2 >= (-100)) && (pub_r001863_4_2 <= 100));
  __CPROVER_assume((pub_r001863_5_1 >= (-100)) && (pub_r001863_5_1 <= 100));
  __CPROVER_assume((pub_r001863_5_2 >= (-100)) && (pub_r001863_5_2 <= 100));
  __CPROVER_assume((pub_r001863_6_1 >= (-100)) && (pub_r001863_6_1 <= 100));
  __CPROVER_assume((pub_r001863_6_2 >= (-100)) && (pub_r001863_6_2 <= 100));
  __CPROVER_assume((pub_r001863_7_1 >= (-100)) && (pub_r001863_7_1 <= 100));
  __CPROVER_assume((pub_r001863_7_2 >= (-100)) && (pub_r001863_7_2 <= 100));
  __CPROVER_assume((pub_r001863_8_1 >= (-100)) && (pub_r001863_8_1 <= 100));
  __CPROVER_assume((pub_r001863_8_2 >= (-100)) && (pub_r001863_8_2 <= 100));
  __CPROVER_assume((pub_r001863_9_1 >= (-100)) && (pub_r001863_9_1 <= 100));
  __CPROVER_assume((pub_r001863_9_2 >= (-100)) && (pub_r001863_9_2 <= 100));
  __CPROVER_assume((pub_r001863_10_1 >= (-100)) && (pub_r001863_10_1 <= 100));
  __CPROVER_assume((pub_r001863_10_2 >= (-100)) && (pub_r001863_10_2 <= 100));
  __CPROVER_assume((pub_r001863_11_1 >= (-100)) && (pub_r001863_11_1 <= 100));
  __CPROVER_assume((pub_r001863_11_2 >= (-100)) && (pub_r001863_11_2 <= 100));
  __CPROVER_assume((pub_r001863_12_1 >= (-100)) && (pub_r001863_12_1 <= 100));
  __CPROVER_assume((pub_r001863_12_2 >= (-100)) && (pub_r001863_12_2 <= 100));
  __CPROVER_assume((pub_r001863_13_1 >= (-100)) && (pub_r001863_13_1 <= 100));
  __CPROVER_assume((pub_r001863_13_2 >= (-100)) && (pub_r001863_13_2 <= 100));
  __CPROVER_assume((pub_r001863_14_1 >= (-100)) && (pub_r001863_14_1 <= 100));
  __CPROVER_assume((pub_r001863_14_2 >= (-100)) && (pub_r001863_14_2 <= 100));
  __CPROVER_assume((pub_r001863_15_1 >= (-100)) && (pub_r001863_15_1 <= 100));
  __CPROVER_assume((pub_r001863_15_2 >= (-100)) && (pub_r001863_15_2 <= 100));
  __CPROVER_assume((pub_r001863_16_1 >= (-100)) && (pub_r001863_16_1 <= 100));
  __CPROVER_assume((pub_r001863_16_2 >= (-100)) && (pub_r001863_16_2 <= 100));
  __CPROVER_assume((pub_r001863_17_1 >= (-100)) && (pub_r001863_17_1 <= 100));
  __CPROVER_assume((pub_r001863_17_2 >= (-100)) && (pub_r001863_17_2 <= 100));
  __CPROVER_assume((pub_r001863_18_1 >= (-100)) && (pub_r001863_18_1 <= 100));
  __CPROVER_assume((pub_r001863_18_2 >= (-100)) && (pub_r001863_18_2 <= 100));
  __CPROVER_assume((pub_r001863_19_1 >= (-100)) && (pub_r001863_19_1 <= 100));
  __CPROVER_assume((pub_r001863_19_2 >= (-100)) && (pub_r001863_19_2 <= 100));
  __CPROVER_assume((sec_r001863_0_1 >= 0) && (sec_r001863_0_1 <= 255));
  __CPROVER_assume((sec_r001863_0_2 >= 0) && (sec_r001863_0_2 <= 255));
  __CPROVER_assume((sec_r001863_1_1 >= 0) && (sec_r001863_1_1 <= 255));
  __CPROVER_assume((sec_r001863_1_2 >= 0) && (sec_r001863_1_2 <= 255));
  __CPROVER_assume((sec_r001863_2_1 >= 0) && (sec_r001863_2_1 <= 255));
  __CPROVER_assume((sec_r001863_2_2 >= 0) && (sec_r001863_2_2 <= 255));
  __CPROVER_assume((sec_r001863_3_1 >= 0) && (sec_r001863_3_1 <= 255));
  __CPROVER_assume((sec_r001863_3_2 >= 0) && (sec_r001863_3_2 <= 255));
  __CPROVER_assume((sec_r001863_4_1 >= 0) && (sec_r001863_4_1 <= 255));
  __CPROVER_assume((sec_r001863_4_2 >= 0) && (sec_r001863_4_2 <= 255));
  __CPROVER_assume((sec_r001863_5_1 >= 0) && (sec_r001863_5_1 <= 255));
  __CPROVER_assume((sec_r001863_5_2 >= 0) && (sec_r001863_5_2 <= 255));
  __CPROVER_assume((sec_r001863_6_1 >= 0) && (sec_r001863_6_1 <= 255));
  __CPROVER_assume((sec_r001863_6_2 >= 0) && (sec_r001863_6_2 <= 255));
  __CPROVER_assume((sec_r001863_7_1 >= 0) && (sec_r001863_7_1 <= 255));
  __CPROVER_assume((sec_r001863_7_2 >= 0) && (sec_r001863_7_2 <= 255));
  __CPROVER_assume((sec_r001863_8_1 >= 0) && (sec_r001863_8_1 <= 255));
  __CPROVER_assume((sec_r001863_8_2 >= 0) && (sec_r001863_8_2 <= 255));
  __CPROVER_assume((sec_r001863_9_1 >= 0) && (sec_r001863_9_1 <= 255));
  __CPROVER_assume((sec_r001863_9_2 >= 0) && (sec_r001863_9_2 <= 255));
  __CPROVER_assume((sec_r001863_10_1 >= 0) && (sec_r001863_10_1 <= 255));
  __CPROVER_assume((sec_r001863_10_2 >= 0) && (sec_r001863_10_2 <= 255));
  __CPROVER_assume((sec_r001863_11_1 >= 0) && (sec_r001863_11_1 <= 255));
  __CPROVER_assume((sec_r001863_11_2 >= 0) && (sec_r001863_11_2 <= 255));
  __CPROVER_assume((sec_r001863_12_1 >= 0) && (sec_r001863_12_1 <= 255));
  __CPROVER_assume((sec_r001863_12_2 >= 0) && (sec_r001863_12_2 <= 255));
  __CPROVER_assume((sec_r001863_13_1 >= 0) && (sec_r001863_13_1 <= 255));
  __CPROVER_assume((sec_r001863_13_2 >= 0) && (sec_r001863_13_2 <= 255));
  __CPROVER_assume((sec_r001863_14_1 >= 0) && (sec_r001863_14_1 <= 255));
  __CPROVER_assume((sec_r001863_14_2 >= 0) && (sec_r001863_14_2 <= 255));
  __CPROVER_assume((sec_r001863_15_1 >= 0) && (sec_r001863_15_1 <= 255));
  __CPROVER_assume((sec_r001863_15_2 >= 0) && (sec_r001863_15_2 <= 255));
  __CPROVER_assume((sec_r001863_16_1 >= 0) && (sec_r001863_16_1 <= 255));
  __CPROVER_assume((sec_r001863_16_2 >= 0) && (sec_r001863_16_2 <= 255));
  __CPROVER_assume((sec_r001863_17_1 >= 0) && (sec_r001863_17_1 <= 255));
  __CPROVER_assume((sec_r001863_17_2 >= 0) && (sec_r001863_17_2 <= 255));
  __CPROVER_assume((sec_r001863_18_1 >= 0) && (sec_r001863_18_1 <= 255));
  __CPROVER_assume((sec_r001863_18_2 >= 0) && (sec_r001863_18_2 <= 255));
  __CPROVER_assume((sec_r001863_19_1 >= 0) && (sec_r001863_19_1 <= 255));
  __CPROVER_assume((sec_r001863_19_2 >= 0) && (sec_r001863_19_2 <= 255));
  __CPROVER_assume((sec_r001863_20_1 >= 0) && (sec_r001863_20_1 <= 255));
  __CPROVER_assume((sec_r001863_20_2 >= 0) && (sec_r001863_20_2 <= 255));
  __CPROVER_assume((sec_r001863_21_1 >= 0) && (sec_r001863_21_1 <= 255));
  __CPROVER_assume((sec_r001863_21_2 >= 0) && (sec_r001863_21_2 <= 255));
  __CPROVER_assume((sec_r001863_22_1 >= 0) && (sec_r001863_22_1 <= 255));
  __CPROVER_assume((sec_r001863_22_2 >= 0) && (sec_r001863_22_2 <= 255));
  __CPROVER_assume((sec_r001863_23_1 >= 0) && (sec_r001863_23_1 <= 255));
  __CPROVER_assume((sec_r001863_23_2 >= 0) && (sec_r001863_23_2 <= 255));
  struct SensorNode_R001863_6313_0 st_var_0_1 = {0};
  struct SensorNode_R001863_6313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001863_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001863_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001863_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001863_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001863_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001863_0_2 + 7) & 15;
  struct DeviceConfig_R001863_6313_1 st_var_1_1 = {0};
  struct DeviceConfig_R001863_6313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001863_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001863_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001863_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001863_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001863_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001863_0_2 + 9) & 15;
  struct Vector3D_R001863_6313_2 st_var_2_1 = {0};
  struct Vector3D_R001863_6313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001863_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001863_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001863_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001863_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001863_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001863_0_2 + 11) & 15;
  struct StreamBuffer_R001863_6313_3 st_var_3_1 = {0};
  struct StreamBuffer_R001863_6313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001863_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001863_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001863_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001863_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001863_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001863_0_2 + 13) & 15;
  union PacketPayload_R001863_6313_0 u_var_1;
  union PacketPayload_R001863_6313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001863_6313_0(sec_r001863_0_1, sec_r001863_1_1, pub_r001863_2_1, pub_r001863_3_1, pub_r001863_4_1);
  int helper_flow_0_2 = fn_R001863_6313_0(sec_r001863_0_2, sec_r001863_1_2, pub_r001863_2_2, pub_r001863_3_2, pub_r001863_4_2);
  fn_R001863_6313_0_2(sec_r001863_0_1, sec_r001863_1_1, pub_r001863_2_1, pub_r001863_3_1, pub_r001863_4_1, sec_r001863_0_2, sec_r001863_1_2, pub_r001863_2_2, pub_r001863_3_2, pub_r001863_4_2);
  int helper_flow_1_1 = fn_R001863_6313_1(sec_r001863_1_1, pub_r001863_2_1, pub_r001863_3_1);
  int helper_flow_1_2 = fn_R001863_6313_1(sec_r001863_1_2, pub_r001863_2_2, pub_r001863_3_2);
  fn_R001863_6313_1_2(sec_r001863_1_1, pub_r001863_2_1, pub_r001863_3_1, sec_r001863_1_2, pub_r001863_2_2, pub_r001863_3_2);
  int helper_flow_2_1 = fn_R001863_6313_2(sec_r001863_2_1, pub_r001863_3_1, pub_r001863_4_1);
  int helper_flow_2_2 = fn_R001863_6313_2(sec_r001863_2_2, pub_r001863_3_2, pub_r001863_4_2);
  fn_R001863_6313_2_2(sec_r001863_2_1, pub_r001863_3_1, pub_r001863_4_1, sec_r001863_2_2, pub_r001863_3_2, pub_r001863_4_2);
  int helper_flow_3_1 = fn_R001863_6313_3(sec_r001863_3_1, pub_r001863_4_1);
  int helper_flow_3_2 = fn_R001863_6313_3(sec_r001863_3_2, pub_r001863_4_2);
  fn_R001863_6313_3_2(sec_r001863_3_1, pub_r001863_4_1, sec_r001863_3_2, pub_r001863_4_2);
  int helper_flow_4_1 = fn_R001863_6313_4(sec_r001863_4_1, pub_r001863_5_1, pub_r001863_6_1);
  int helper_flow_4_2 = fn_R001863_6313_4(sec_r001863_4_2, pub_r001863_5_2, pub_r001863_6_2);
  fn_R001863_6313_4_2(sec_r001863_4_1, pub_r001863_5_1, pub_r001863_6_1, sec_r001863_4_2, pub_r001863_5_2, pub_r001863_6_2);
  int helper_flow_5_1 = fn_R001863_6313_5(sec_r001863_5_1, pub_r001863_6_1, pub_r001863_7_1, pub_r001863_8_1);
  int helper_flow_5_2 = fn_R001863_6313_5(sec_r001863_5_2, pub_r001863_6_2, pub_r001863_7_2, pub_r001863_8_2);
  fn_R001863_6313_5_2(sec_r001863_5_1, pub_r001863_6_1, pub_r001863_7_1, pub_r001863_8_1, sec_r001863_5_2, pub_r001863_6_2, pub_r001863_7_2, pub_r001863_8_2);
  int helper_flow_6_1 = fn_R001863_6313_6(sec_r001863_6_1, sec_r001863_7_1, pub_r001863_8_1, pub_r001863_9_1, pub_r001863_10_1);
  int helper_flow_6_2 = fn_R001863_6313_6(sec_r001863_6_2, sec_r001863_7_2, pub_r001863_8_2, pub_r001863_9_2, pub_r001863_10_2);
  fn_R001863_6313_6_2(sec_r001863_6_1, sec_r001863_7_1, pub_r001863_8_1, pub_r001863_9_1, pub_r001863_10_1, sec_r001863_6_2, sec_r001863_7_2, pub_r001863_8_2, pub_r001863_9_2, pub_r001863_10_2);
  int helper_flow_7_1 = fn_R001863_6313_7(sec_r001863_7_1, pub_r001863_8_1, pub_r001863_9_1, pub_r001863_10_1, pub_r001863_11_1);
  int helper_flow_7_2 = fn_R001863_6313_7(sec_r001863_7_2, pub_r001863_8_2, pub_r001863_9_2, pub_r001863_10_2, pub_r001863_11_2);
  fn_R001863_6313_7_2(sec_r001863_7_1, pub_r001863_8_1, pub_r001863_9_1, pub_r001863_10_1, pub_r001863_11_1, sec_r001863_7_2, pub_r001863_8_2, pub_r001863_9_2, pub_r001863_10_2, pub_r001863_11_2);
  int helper_flow_8_1 = fn_R001863_6313_8(sec_r001863_8_1, sec_r001863_9_1, pub_r001863_10_1, pub_r001863_11_1, pub_r001863_12_1);
  int helper_flow_8_2 = fn_R001863_6313_8(sec_r001863_8_2, sec_r001863_9_2, pub_r001863_10_2, pub_r001863_11_2, pub_r001863_12_2);
  fn_R001863_6313_8_2(sec_r001863_8_1, sec_r001863_9_1, pub_r001863_10_1, pub_r001863_11_1, pub_r001863_12_1, sec_r001863_8_2, sec_r001863_9_2, pub_r001863_10_2, pub_r001863_11_2, pub_r001863_12_2);
  int stage_v_0_1 = ((pub_r001863_13_1 * 2) + 23) & 63;
  int stage_v_0_2 = ((pub_r001863_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001863_22_1 * 3) + pub_r001863_11_1) + 17) & 127;
  int stage_v_1_2 = (((sec_r001863_22_2 * 3) + pub_r001863_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((stage_v_1_1 * 3) + pub_r001863_15_1) + 23) & 127;
  int stage_v_2_2 = (((stage_v_1_2 * 3) + pub_r001863_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001863_2_1 * 3) + pub_r001863_4_1) + 39) & 127;
  int stage_v_3_2 = (((sec_r001863_2_2 * 3) + pub_r001863_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001863_23_1 * 3) + pub_r001863_15_1) + 28) & 127;
  int stage_v_4_2 = (((sec_r001863_23_2 * 3) + pub_r001863_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001863_17_1 * 2) + 9) & 63;
  int stage_v_5_2 = ((pub_r001863_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001863_4_1 * 2) + 46) & 63;
  int stage_v_6_2 = ((pub_r001863_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001863_0_1 * 2) + 12) & 63;
  int stage_v_7_2 = ((pub_r001863_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001863_9_1 * 3) + pub_r001863_9_1) + 14) & 127;
  int stage_v_8_2 = (((sec_r001863_9_2 * 3) + pub_r001863_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001863_17_1 * 3) + pub_r001863_19_1) + 36) & 127;
  int stage_v_9_2 = (((sec_r001863_17_2 * 3) + pub_r001863_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001863_14_1 * 2) + 8) & 63;
  int stage_v_10_2 = ((pub_r001863_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001863_14_1 * 3) + pub_r001863_1_1) + 38) & 127;
  int stage_v_11_2 = (((sec_r001863_14_2 * 3) + pub_r001863_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((helper_flow_4_1 * 3) + pub_r001863_7_1) + 23) & 127;
  int stage_v_12_2 = (((helper_flow_4_2 * 3) + pub_r001863_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001863_22_1 * 3) + pub_r001863_1_1) + 20) & 127;
  int stage_v_13_2 = (((sec_r001863_22_2 * 3) + pub_r001863_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((stage_v_12_1 * 3) + pub_r001863_1_1) + 4) & 127;
  int stage_v_14_2 = (((stage_v_12_2 * 3) + pub_r001863_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001863_10_1 * 2) + 35) & 63;
  int stage_v_15_2 = ((pub_r001863_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001863_3_1 * 3) + pub_r001863_19_1) + 40) & 127;
  int stage_v_16_2 = (((sec_r001863_3_2 * 3) + pub_r001863_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((helper_flow_5_1 * 3) + pub_r001863_14_1) + 21) & 127;
  int stage_v_17_2 = (((helper_flow_5_2 * 3) + pub_r001863_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001863_7_1 * 2) + 24) & 63;
  int stage_v_18_2 = ((pub_r001863_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001863_9_1 * 2) + 13) & 63;
  int stage_v_19_2 = ((pub_r001863_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001863_2_1 * 2) + 35) & 63;
  int stage_v_20_2 = ((pub_r001863_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001863_10_1 * 2) + 31) & 63;
  int stage_v_21_2 = ((pub_r001863_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001863_14_1 * 2) + 21) & 63;
  int stage_v_22_2 = ((pub_r001863_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001863_0_1 * 3) + pub_r001863_5_1) + 39) & 127;
  int stage_v_23_2 = (((sec_r001863_0_2 * 3) + pub_r001863_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_3_1 * 3) + pub_r001863_9_1) + 17) & 127;
  int stage_v_24_2 = (((stage_v_3_2 * 3) + pub_r001863_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001863_14_1 * 3) + pub_r001863_14_1) + 34) & 127;
  int stage_v_25_2 = (((sec_r001863_14_2 * 3) + pub_r001863_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001863_0_1 * 3) + pub_r001863_11_1) + 45) & 127;
  int stage_v_26_2 = (((sec_r001863_0_2 * 3) + pub_r001863_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_1_1 * 3) + pub_r001863_3_1) + 10) & 127;
  int stage_v_27_2 = (((stage_v_1_2 * 3) + pub_r001863_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001863_11_1 * 2) + 26) & 63;
  int stage_v_28_2 = ((pub_r001863_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_25_1 * 3) + pub_r001863_17_1) + 13) & 127;
  int stage_v_29_2 = (((stage_v_25_2 * 3) + pub_r001863_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((helper_flow_8_1 * 3) + pub_r001863_2_1) + 19) & 127;
  int stage_v_30_2 = (((helper_flow_8_2 * 3) + pub_r001863_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_12_1 * 3) + pub_r001863_13_1) + 24) & 127;
  int stage_v_31_2 = (((stage_v_12_2 * 3) + pub_r001863_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001863_14_1 * 2) + 19) & 63;
  int stage_v_32_2 = ((pub_r001863_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((helper_flow_4_1 * 3) + pub_r001863_14_1) + 27) & 127;
  int stage_v_33_2 = (((helper_flow_4_2 * 3) + pub_r001863_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001863_0_1 * 2) + 36) & 63;
  int stage_v_34_2 = ((pub_r001863_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_11_1 * 3) + pub_r001863_17_1) + 13) & 127;
  int stage_v_35_2 = (((stage_v_11_2 * 3) + pub_r001863_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((sec_r001863_14_1 * 3) + pub_r001863_9_1) + 27) & 127;
  int stage_v_36_2 = (((sec_r001863_14_2 * 3) + pub_r001863_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((helper_flow_5_1 * 3) + pub_r001863_7_1) + 30) & 127;
  int stage_v_37_2 = (((helper_flow_5_2 * 3) + pub_r001863_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001863_11_1 * 2) + 43) & 63;
  int stage_v_38_2 = ((pub_r001863_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001863_9_1 * 2) + 32) & 63;
  int stage_v_39_2 = ((pub_r001863_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_4_1 * 3) + pub_r001863_1_1) + 31) & 127;
  int stage_v_40_2 = (((helper_flow_4_2 * 3) + pub_r001863_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((helper_flow_5_1 * 3) + pub_r001863_10_1) + 41) & 127;
  int stage_v_41_2 = (((helper_flow_5_2 * 3) + pub_r001863_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001863_1_1 * 2) + 8) & 63;
  int stage_v_42_2 = ((pub_r001863_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001863_4_1 * 2) + 31) & 63;
  int stage_v_43_2 = ((pub_r001863_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001863_12_1 * 3) + pub_r001863_6_1) + 9) & 127;
  int stage_v_44_2 = (((sec_r001863_12_2 * 3) + pub_r001863_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001863_4_1 * 2) + 16) & 63;
  int stage_v_45_2 = ((pub_r001863_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001863_6_1 * 2) + 20) & 63;
  int stage_v_46_2 = ((pub_r001863_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001863_15_1 * 2) + 50) & 63;
  int stage_v_47_2 = ((pub_r001863_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_31_1 * 3) + pub_r001863_15_1) + 16) & 127;
  int stage_v_48_2 = (((stage_v_31_2 * 3) + pub_r001863_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_23_1 * 3) + pub_r001863_13_1) + 35) & 127;
  int stage_v_49_2 = (((stage_v_23_2 * 3) + pub_r001863_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_12_1 * 3) + pub_r001863_6_1) + 23) & 127;
  int stage_v_50_2 = (((stage_v_12_2 * 3) + pub_r001863_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_3_1 * 3) + pub_r001863_10_1) + 45) & 127;
  int stage_v_51_2 = (((stage_v_3_2 * 3) + pub_r001863_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001863_1_1 * 2) + 33) & 63;
  int stage_v_52_2 = ((pub_r001863_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001863_6_1 * 3) + pub_r001863_12_1) + 33) & 127;
  int stage_v_53_2 = (((sec_r001863_6_2 * 3) + pub_r001863_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((stage_v_44_1 * 3) + pub_r001863_11_1) + 9) & 127;
  int stage_v_54_2 = (((stage_v_44_2 * 3) + pub_r001863_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001863_4_1 * 2) + 50) & 63;
  int stage_v_55_2 = ((pub_r001863_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001863_5_1 * 2) + 35) & 63;
  int stage_v_56_2 = ((pub_r001863_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_8_1 * 3) + pub_r001863_0_1) + 43) & 127;
  int stage_v_57_2 = (((stage_v_8_2 * 3) + pub_r001863_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_50_1 * 3) + pub_r001863_9_1) + 31) & 127;
  int stage_v_58_2 = (((stage_v_50_2 * 3) + pub_r001863_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_2_1 * 3) + pub_r001863_12_1) + 44) & 127;
  int stage_v_59_2 = (((stage_v_2_2 * 3) + pub_r001863_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((stage_v_2_1 * 3) + pub_r001863_14_1) + 31) & 127;
  int stage_v_60_2 = (((stage_v_2_2 * 3) + pub_r001863_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001863_13_1 * 2) + 37) & 63;
  int stage_v_61_2 = ((pub_r001863_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((sec_r001863_21_1 * 3) + pub_r001863_19_1) + 23) & 127;
  int stage_v_62_2 = (((sec_r001863_21_2 * 3) + pub_r001863_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001863_16_1 * 3) + pub_r001863_7_1) + 22) & 127;
  int stage_v_63_2 = (((sec_r001863_16_2 * 3) + pub_r001863_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_62_1 * 3) + pub_r001863_19_1) + 42) & 127;
  int stage_v_64_2 = (((stage_v_62_2 * 3) + pub_r001863_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_16_1 * 3) + pub_r001863_17_1) + 40) & 127;
  int stage_v_65_2 = (((stage_v_16_2 * 3) + pub_r001863_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001863_10_1 * 2) + 5) & 63;
  int stage_v_66_2 = ((pub_r001863_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_58_1 * 3) + pub_r001863_18_1) + 15) & 127;
  int stage_v_67_2 = (((stage_v_58_2 * 3) + pub_r001863_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001863_16_1 * 2) + 5) & 63;
  int stage_v_68_2 = ((pub_r001863_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_12_1 * 3) + pub_r001863_19_1) + 15) & 127;
  int stage_v_69_2 = (((stage_v_12_2 * 3) + pub_r001863_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001863_5_1 * 2) + 6) & 63;
  int stage_v_70_2 = ((pub_r001863_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_13_1 * 3) + pub_r001863_4_1) + 40) & 127;
  int stage_v_71_2 = (((stage_v_13_2 * 3) + pub_r001863_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001863_11_1 * 2) + 38) & 63;
  int stage_v_72_2 = ((pub_r001863_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_69_1 * 3) + pub_r001863_13_1) + 10) & 127;
  int stage_v_73_2 = (((stage_v_69_2 * 3) + pub_r001863_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001863_11_1 * 2) + 50) & 63;
  int stage_v_74_2 = ((pub_r001863_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001863_19_1 * 2) + 48) & 63;
  int stage_v_75_2 = ((pub_r001863_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001863_4_1 * 2) + 8) & 63;
  int stage_v_76_2 = ((pub_r001863_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001863_11_1 * 2) + 25) & 63;
  int stage_v_77_2 = ((pub_r001863_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((helper_flow_3_1 * 3) + pub_r001863_8_1) + 17) & 127;
  int stage_v_78_2 = (((helper_flow_3_2 * 3) + pub_r001863_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001863_16_1 * 2) + 43) & 63;
  int stage_v_79_2 = ((pub_r001863_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_65_1 * 3) + pub_r001863_8_1) + 4) & 127;
  int stage_v_80_2 = (((stage_v_65_2 * 3) + pub_r001863_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((sec_r001863_17_1 * 3) + pub_r001863_18_1) + 3) & 127;
  int stage_v_81_2 = (((sec_r001863_17_2 * 3) + pub_r001863_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001863_5_1 * 2) + 5) & 63;
  int stage_v_82_2 = ((pub_r001863_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001863_1_1 * 2) + 33) & 63;
  int stage_v_83_2 = ((pub_r001863_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001863_18_1 * 3) + pub_r001863_3_1) + 16) & 127;
  int stage_v_84_2 = (((sec_r001863_18_2 * 3) + pub_r001863_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_23_1 * 3) + pub_r001863_18_1) + 44) & 127;
  int stage_v_85_2 = (((stage_v_23_2 * 3) + pub_r001863_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001863_16_1 * 2) + 22) & 63;
  int stage_v_86_2 = ((pub_r001863_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((helper_flow_0_1 * 3) + pub_r001863_18_1) + 35) & 127;
  int stage_v_87_2 = (((helper_flow_0_2 * 3) + pub_r001863_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001863_5_1 * 2) + 27) & 63;
  int stage_v_88_2 = ((pub_r001863_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((sec_r001863_13_1 * 3) + pub_r001863_16_1) + 25) & 127;
  int stage_v_89_2 = (((sec_r001863_13_2 * 3) + pub_r001863_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_73_1 * 3) + pub_r001863_11_1) + 26) & 127;
  int stage_v_90_2 = (((stage_v_73_2 * 3) + pub_r001863_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((sec_r001863_3_1 * 3) + pub_r001863_3_1) + 28) & 127;
  int stage_v_91_2 = (((sec_r001863_3_2 * 3) + pub_r001863_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_85_1 * 3) + pub_r001863_15_1) + 10) & 127;
  int stage_v_92_2 = (((stage_v_85_2 * 3) + pub_r001863_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001863_17_1 * 2) + 8) & 63;
  int stage_v_93_2 = ((pub_r001863_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001863_4_1 * 3) + pub_r001863_12_1) + 13) & 127;
  int stage_v_94_2 = (((sec_r001863_4_2 * 3) + pub_r001863_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_9_1 * 3) + pub_r001863_3_1) + 3) & 127;
  int stage_v_95_2 = (((stage_v_9_2 * 3) + pub_r001863_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001863_16_1 * 2) + 9) & 63;
  int stage_v_96_2 = ((pub_r001863_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001863_13_1 * 2) + 33) & 63;
  int stage_v_97_2 = ((pub_r001863_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_48_1 * 3) + pub_r001863_5_1) + 40) & 127;
  int stage_v_98_2 = (((stage_v_48_2 * 3) + pub_r001863_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((sec_r001863_13_1 * 3) + pub_r001863_9_1) + 28) & 127;
  int stage_v_99_2 = (((sec_r001863_13_2 * 3) + pub_r001863_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_2_1 * 3) + pub_r001863_17_1) + 14) & 127;
  int stage_v_100_2 = (((stage_v_2_2 * 3) + pub_r001863_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_73_1 * 3) + pub_r001863_11_1) + 41) & 127;
  int stage_v_101_2 = (((stage_v_73_2 * 3) + pub_r001863_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001863_8_1 * 2) + 7) & 63;
  int stage_v_102_2 = ((pub_r001863_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_69_1 * 3) + pub_r001863_12_1) + 19) & 127;
  int stage_v_103_2 = (((stage_v_69_2 * 3) + pub_r001863_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((sec_r001863_23_1 * 3) + pub_r001863_5_1) + 14) & 127;
  int stage_v_104_2 = (((sec_r001863_23_2 * 3) + pub_r001863_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001863_11_1 * 2) + 6) & 63;
  int stage_v_105_2 = ((pub_r001863_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_63_1 * 3) + pub_r001863_6_1) + 11) & 127;
  int stage_v_106_2 = (((stage_v_63_2 * 3) + pub_r001863_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((sec_r001863_4_1 * 3) + pub_r001863_1_1) + 26) & 127;
  int stage_v_107_2 = (((sec_r001863_4_2 * 3) + pub_r001863_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_104_1 * 3) + pub_r001863_3_1) + 13) & 127;
  int stage_v_108_2 = (((stage_v_104_2 * 3) + pub_r001863_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_71_1 * 3) + pub_r001863_5_1) + 37) & 127;
  int stage_v_109_2 = (((stage_v_71_2 * 3) + pub_r001863_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001863_14_1 * 2) + 23) & 63;
  int stage_v_110_2 = ((pub_r001863_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_85_1 * 3) + pub_r001863_5_1) + 16) & 127;
  int stage_v_111_2 = (((stage_v_85_2 * 3) + pub_r001863_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001863_5_1 * 2) + 47) & 63;
  int stage_v_112_2 = ((pub_r001863_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((sec_r001863_12_1 * 3) + pub_r001863_9_1) + 12) & 127;
  int stage_v_113_2 = (((sec_r001863_12_2 * 3) + pub_r001863_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_57_1 * 3) + pub_r001863_3_1) + 26) & 127;
  int stage_v_114_2 = (((stage_v_57_2 * 3) + pub_r001863_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((sec_r001863_23_1 * 3) + pub_r001863_0_1) + 22) & 127;
  int stage_v_115_2 = (((sec_r001863_23_2 * 3) + pub_r001863_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001863_15_1 * 2) + 42) & 63;
  int stage_v_116_2 = ((pub_r001863_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((sec_r001863_16_1 * 3) + pub_r001863_8_1) + 21) & 127;
  int stage_v_117_2 = (((sec_r001863_16_2 * 3) + pub_r001863_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_99_1 * 3) + pub_r001863_16_1) + 4) & 127;
  int stage_v_118_2 = (((stage_v_99_2 * 3) + pub_r001863_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_30_1 * 3) + pub_r001863_6_1) + 25) & 127;
  int stage_v_119_2 = (((stage_v_30_2 * 3) + pub_r001863_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001863_16_1 * 3) + pub_r001863_7_1) + 39) & 127;
  int stage_v_120_2 = (((sec_r001863_16_2 * 3) + pub_r001863_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001863_10_1 * 2) + 27) & 63;
  int stage_v_121_2 = ((pub_r001863_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001863_3_1 * 2) + 44) & 63;
  int stage_v_122_2 = ((pub_r001863_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001863_5_1 * 2) + 44) & 63;
  int stage_v_123_2 = ((pub_r001863_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((helper_flow_4_1 * 3) + pub_r001863_18_1) + 21) & 127;
  int stage_v_124_2 = (((helper_flow_4_2 * 3) + pub_r001863_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_95_1 * 3) + pub_r001863_5_1) + 24) & 127;
  int stage_v_125_2 = (((stage_v_95_2 * 3) + pub_r001863_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001863_5_1 * 2) + 32) & 63;
  int stage_v_126_2 = ((pub_r001863_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_115_1 * 3) + pub_r001863_2_1) + 41) & 127;
  int stage_v_127_2 = (((stage_v_115_2 * 3) + pub_r001863_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001863_0_1 * 2) + 26) & 63;
  int stage_v_128_2 = ((pub_r001863_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_16_1 * 3) + pub_r001863_14_1) + 7) & 127;
  int stage_v_129_2 = (((stage_v_16_2 * 3) + pub_r001863_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((sec_r001863_0_1 * 3) + pub_r001863_6_1) + 13) & 127;
  int stage_v_130_2 = (((sec_r001863_0_2 * 3) + pub_r001863_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001863_3_1 * 2) + 23) & 63;
  int stage_v_131_2 = ((pub_r001863_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001863_4_1 * 2) + 16) & 63;
  int stage_v_132_2 = ((pub_r001863_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001863_20_1 * 3) + pub_r001863_10_1) + 9) & 127;
  int stage_v_133_2 = (((sec_r001863_20_2 * 3) + pub_r001863_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001863_7_1 * 2) + 17) & 63;
  int stage_v_134_2 = ((pub_r001863_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001863_11_1 * 2) + 25) & 63;
  int stage_v_135_2 = ((pub_r001863_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001863_11_1 * 2) + 11) & 63;
  int stage_v_136_2 = ((pub_r001863_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001863_10_1 * 2) + 50) & 63;
  int stage_v_137_2 = ((pub_r001863_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((sec_r001863_3_1 * 3) + pub_r001863_14_1) + 22) & 127;
  int stage_v_138_2 = (((sec_r001863_3_2 * 3) + pub_r001863_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_113_1 * 3) + pub_r001863_14_1) + 27) & 127;
  int stage_v_139_2 = (((stage_v_113_2 * 3) + pub_r001863_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_17_1 * 3) + pub_r001863_19_1) + 4) & 127;
  int stage_v_140_2 = (((stage_v_17_2 * 3) + pub_r001863_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_91_1 * 3) + pub_r001863_19_1) + 27) & 127;
  int stage_v_141_2 = (((stage_v_91_2 * 3) + pub_r001863_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((sec_r001863_23_1 * 3) + pub_r001863_19_1) + 44) & 127;
  int stage_v_142_2 = (((sec_r001863_23_2 * 3) + pub_r001863_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((sec_r001863_10_1 * 3) + pub_r001863_9_1) + 8) & 127;
  int stage_v_143_2 = (((sec_r001863_10_2 * 3) + pub_r001863_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_120_1 * 3) + pub_r001863_6_1) + 29) & 127;
  int stage_v_144_2 = (((stage_v_120_2 * 3) + pub_r001863_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((sec_r001863_14_1 * 3) + pub_r001863_13_1) + 37) & 127;
  int stage_v_145_2 = (((sec_r001863_14_2 * 3) + pub_r001863_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001863_9_1 * 2) + 37) & 63;
  int stage_v_146_2 = ((pub_r001863_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((helper_flow_8_1 * 3) + pub_r001863_10_1) + 23) & 127;
  int stage_v_147_2 = (((helper_flow_8_2 * 3) + pub_r001863_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001863_17_1 * 2) + 16) & 63;
  int stage_v_148_2 = ((pub_r001863_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((helper_flow_1_1 * 3) + pub_r001863_5_1) + 33) & 127;
  int stage_v_149_2 = (((helper_flow_1_2 * 3) + pub_r001863_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((sec_r001863_20_1 * 3) + pub_r001863_17_1) + 8) & 127;
  int stage_v_150_2 = (((sec_r001863_20_2 * 3) + pub_r001863_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_141_1 * 3) + pub_r001863_14_1) + 23) & 127;
  int stage_v_151_2 = (((stage_v_141_2 * 3) + pub_r001863_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_95_1 * 3) + pub_r001863_15_1) + 41) & 127;
  int stage_v_152_2 = (((stage_v_95_2 * 3) + pub_r001863_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_149_1 * 3) + pub_r001863_7_1) + 18) & 127;
  int stage_v_153_2 = (((stage_v_149_2 * 3) + pub_r001863_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_149_1 * 3) + pub_r001863_16_1) + 23) & 127;
  int stage_v_154_2 = (((stage_v_149_2 * 3) + pub_r001863_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((sec_r001863_13_1 * 3) + pub_r001863_3_1) + 35) & 127;
  int stage_v_155_2 = (((sec_r001863_13_2 * 3) + pub_r001863_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_115_1 * 3) + pub_r001863_7_1) + 22) & 127;
  int stage_v_156_2 = (((stage_v_115_2 * 3) + pub_r001863_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_65_1 * 3) + pub_r001863_12_1) + 39) & 127;
  int stage_v_157_2 = (((stage_v_65_2 * 3) + pub_r001863_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_155_1 * 3) + pub_r001863_8_1) + 23) & 127;
  int stage_v_158_2 = (((stage_v_155_2 * 3) + pub_r001863_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001863_19_1 * 2) + 11) & 63;
  int stage_v_159_2 = ((pub_r001863_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_78_1 * 3) + pub_r001863_6_1) + 8) & 127;
  int stage_v_160_2 = (((stage_v_78_2 * 3) + pub_r001863_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((sec_r001863_16_1 * 3) + pub_r001863_7_1) + 18) & 127;
  int stage_v_161_2 = (((sec_r001863_16_2 * 3) + pub_r001863_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((helper_flow_3_1 * 3) + pub_r001863_14_1) + 43) & 127;
  int stage_v_162_2 = (((helper_flow_3_2 * 3) + pub_r001863_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001863_10_1 * 2) + 27) & 63;
  int stage_v_163_2 = ((pub_r001863_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_62_1 * 3) + pub_r001863_10_1) + 11) & 127;
  int stage_v_164_2 = (((stage_v_62_2 * 3) + pub_r001863_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_50_1 * 3) + pub_r001863_15_1) + 7) & 127;
  int stage_v_165_2 = (((stage_v_50_2 * 3) + pub_r001863_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001863_14_1 * 2) + 37) & 63;
  int stage_v_166_2 = ((pub_r001863_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001863_5_1 * 2) + 7) & 63;
  int stage_v_167_2 = ((pub_r001863_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((sec_r001863_17_1 * 3) + pub_r001863_6_1) + 16) & 127;
  int stage_v_168_2 = (((sec_r001863_17_2 * 3) + pub_r001863_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001863_15_1 * 2) + 43) & 63;
  int stage_v_169_2 = ((pub_r001863_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((sec_r001863_20_1 * 3) + pub_r001863_12_1) + 9) & 127;
  int stage_v_170_2 = (((sec_r001863_20_2 * 3) + pub_r001863_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_115_1 * 3) + pub_r001863_15_1) + 44) & 127;
  int stage_v_171_2 = (((stage_v_115_2 * 3) + pub_r001863_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_40_1 * 3) + pub_r001863_5_1) + 26) & 127;
  int stage_v_172_2 = (((stage_v_40_2 * 3) + pub_r001863_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001863_2_1 * 2) + 31) & 63;
  int stage_v_173_2 = ((pub_r001863_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((sec_r001863_11_1 * 3) + pub_r001863_18_1) + 42) & 127;
  int stage_v_174_2 = (((sec_r001863_11_2 * 3) + pub_r001863_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_29_1 * 3) + pub_r001863_13_1) + 41) & 127;
  int stage_v_175_2 = (((stage_v_29_2 * 3) + pub_r001863_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001863_19_1 * 2) + 12) & 63;
  int stage_v_176_2 = ((pub_r001863_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001863_19_1 * 2) + 40) & 63;
  int stage_v_177_2 = ((pub_r001863_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001863_18_1 * 2) + 50) & 63;
  int stage_v_178_2 = ((pub_r001863_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001863_17_1 * 2) + 20) & 63;
  int stage_v_179_2 = ((pub_r001863_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_3_1 * 3) + pub_r001863_5_1) + 10) & 127;
  int stage_v_180_2 = (((stage_v_3_2 * 3) + pub_r001863_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_113_1 * 3) + pub_r001863_8_1) + 30) & 127;
  int stage_v_181_2 = (((stage_v_113_2 * 3) + pub_r001863_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001863_1_1 * 2) + 27) & 63;
  int stage_v_182_2 = ((pub_r001863_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_118_1 * 3) + pub_r001863_19_1) + 10) & 127;
  int stage_v_183_2 = (((stage_v_118_2 * 3) + pub_r001863_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_152_1 * 3) + pub_r001863_9_1) + 6) & 127;
  int stage_v_184_2 = (((stage_v_152_2 * 3) + pub_r001863_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_16_1 * 3) + pub_r001863_19_1) + 38) & 127;
  int stage_v_185_2 = (((stage_v_16_2 * 3) + pub_r001863_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_111_1 * 3) + pub_r001863_14_1) + 14) & 127;
  int stage_v_186_2 = (((stage_v_111_2 * 3) + pub_r001863_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_130_1 * 3) + pub_r001863_11_1) + 42) & 127;
  int stage_v_187_2 = (((stage_v_130_2 * 3) + pub_r001863_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001863_12_1 * 2) + 7) & 63;
  int stage_v_188_2 = ((pub_r001863_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001863_18_1 * 2) + 21) & 63;
  int stage_v_189_2 = ((pub_r001863_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001863_0_1 * 3) + pub_r001863_4_1) + 4) & 127;
  int stage_v_190_2 = (((sec_r001863_0_2 * 3) + pub_r001863_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001863_7_1 * 2) + 16) & 63;
  int stage_v_191_2 = ((pub_r001863_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001863_6_1 * 2) + 30) & 63;
  int stage_v_192_2 = ((pub_r001863_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001863_3_1 * 2) + 14) & 63;
  int stage_v_193_2 = ((pub_r001863_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_175_1 * 3) + pub_r001863_5_1) + 27) & 127;
  int stage_v_194_2 = (((stage_v_175_2 * 3) + pub_r001863_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001863_1_1 * 2) + 21) & 63;
  int stage_v_195_2 = ((pub_r001863_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001863_10_1 * 2) + 37) & 63;
  int stage_v_196_2 = ((pub_r001863_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_161_1 * 3) + pub_r001863_4_1) + 21) & 127;
  int stage_v_197_2 = (((stage_v_161_2 * 3) + pub_r001863_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001863_18_1 * 2) + 7) & 63;
  int stage_v_198_2 = ((pub_r001863_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_117_1 * 3) + pub_r001863_5_1) + 24) & 127;
  int stage_v_199_2 = (((stage_v_117_2 * 3) + pub_r001863_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001863_14_1 * 2) + 30) & 63;
  int stage_v_200_2 = ((pub_r001863_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_95_1 * 3) + pub_r001863_3_1) + 28) & 127;
  int stage_v_201_2 = (((stage_v_95_2 * 3) + pub_r001863_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_170_1 * 3) + pub_r001863_2_1) + 8) & 127;
  int stage_v_202_2 = (((stage_v_170_2 * 3) + pub_r001863_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_171_1 * 3) + pub_r001863_12_1) + 41) & 127;
  int stage_v_203_2 = (((stage_v_171_2 * 3) + pub_r001863_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001863_15_1 * 2) + 29) & 63;
  int stage_v_204_2 = ((pub_r001863_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001863_16_1 * 2) + 43) & 63;
  int stage_v_205_2 = ((pub_r001863_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_164_1 * 3) + pub_r001863_17_1) + 29) & 127;
  int stage_v_206_2 = (((stage_v_164_2 * 3) + pub_r001863_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001863_2_1 * 2) + 34) & 63;
  int stage_v_207_2 = ((pub_r001863_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001863_17_1 * 2) + 21) & 63;
  int stage_v_208_2 = ((pub_r001863_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_80_1 * 3) + pub_r001863_11_1) + 6) & 127;
  int stage_v_209_2 = (((stage_v_80_2 * 3) + pub_r001863_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001863_5_1 * 2) + 29) & 63;
  int stage_v_210_2 = ((pub_r001863_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_190_1 * 3) + pub_r001863_2_1) + 37) & 127;
  int stage_v_211_2 = (((stage_v_190_2 * 3) + pub_r001863_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((helper_flow_8_1 * 3) + pub_r001863_18_1) + 9) & 127;
  int stage_v_212_2 = (((helper_flow_8_2 * 3) + pub_r001863_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_130_1 * 3) + pub_r001863_16_1) + 17) & 127;
  int stage_v_213_2 = (((stage_v_130_2 * 3) + pub_r001863_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001863_3_1 * 2) + 50) & 63;
  int stage_v_214_2 = ((pub_r001863_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001863_18_1 * 3) + pub_r001863_1_1) + 23) & 127;
  int stage_v_215_2 = (((sec_r001863_18_2 * 3) + pub_r001863_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_101_1 * 3) + pub_r001863_13_1) + 18) & 127;
  int stage_v_216_2 = (((stage_v_101_2 * 3) + pub_r001863_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((stage_v_211_1 * 3) + pub_r001863_5_1) + 45) & 127;
  int stage_v_217_2 = (((stage_v_211_2 * 3) + pub_r001863_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_168_1 * 3) + pub_r001863_15_1) + 11) & 127;
  int stage_v_218_2 = (((stage_v_168_2 * 3) + pub_r001863_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((helper_flow_5_1 * 3) + pub_r001863_1_1) + 15) & 127;
  int stage_v_219_2 = (((helper_flow_5_2 * 3) + pub_r001863_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001863_6_1 * 2) + 18) & 63;
  int stage_v_220_2 = ((pub_r001863_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001863_11_1 * 2) + 33) & 63;
  int stage_v_221_2 = ((pub_r001863_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_172_1 * 3) + pub_r001863_17_1) + 25) & 127;
  int stage_v_222_2 = (((stage_v_172_2 * 3) + pub_r001863_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_209_1 * 3) + pub_r001863_16_1) + 29) & 127;
  int stage_v_223_2 = (((stage_v_209_2 * 3) + pub_r001863_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_57_1 * 3) + pub_r001863_3_1) + 23) & 127;
  int stage_v_224_2 = (((stage_v_57_2 * 3) + pub_r001863_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_27_1 * 3) + pub_r001863_17_1) + 27) & 127;
  int stage_v_225_2 = (((stage_v_27_2 * 3) + pub_r001863_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001863_10_1 * 2) + 46) & 63;
  int stage_v_226_2 = ((pub_r001863_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001863_13_1 * 2) + 35) & 63;
  int stage_v_227_2 = ((pub_r001863_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001863_1_1 * 2) + 43) & 63;
  int stage_v_228_2 = ((pub_r001863_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_95_1 * 3) + pub_r001863_16_1) + 39) & 127;
  int stage_v_229_2 = (((stage_v_95_2 * 3) + pub_r001863_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_127_1 * 3) + pub_r001863_10_1) + 7) & 127;
  int stage_v_230_2 = (((stage_v_127_2 * 3) + pub_r001863_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_130_1 * 3) + pub_r001863_4_1) + 33) & 127;
  int stage_v_231_2 = (((stage_v_130_2 * 3) + pub_r001863_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001863_3_1 * 2) + 42) & 63;
  int stage_v_232_2 = ((pub_r001863_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001863_0_1 * 2) + 44) & 63;
  int stage_v_233_2 = ((pub_r001863_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001863_4_1 * 2) + 45) & 63;
  int stage_v_234_2 = ((pub_r001863_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001863_16_1 * 2) + 23) & 63;
  int stage_v_235_2 = ((pub_r001863_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001863_10_1 * 2) + 10) & 63;
  int stage_v_236_2 = ((pub_r001863_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001863_3_1 * 2) + 27) & 63;
  int stage_v_237_2 = ((pub_r001863_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001863_4_1 * 2) + 47) & 63;
  int stage_v_238_2 = ((pub_r001863_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001863_3_1 * 2) + 37) & 63;
  int stage_v_239_2 = ((pub_r001863_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((helper_flow_6_1 * 3) + pub_r001863_9_1) + 10) & 127;
  int stage_v_240_2 = (((helper_flow_6_2 * 3) + pub_r001863_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_138_1 * 3) + pub_r001863_13_1) + 22) & 127;
  int stage_v_241_2 = (((stage_v_138_2 * 3) + pub_r001863_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001863_15_1 * 2) + 45) & 63;
  int stage_v_242_2 = ((pub_r001863_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001863_14_1 * 2) + 32) & 63;
  int stage_v_243_2 = ((pub_r001863_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001863_14_1 * 2) + 50) & 63;
  int stage_v_244_2 = ((pub_r001863_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001863_8_1 * 2) + 15) & 63;
  int stage_v_245_2 = ((pub_r001863_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_94_1 * 3) + pub_r001863_7_1) + 39) & 127;
  int stage_v_246_2 = (((stage_v_94_2 * 3) + pub_r001863_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001863_8_1 * 2) + 30) & 63;
  int stage_v_247_2 = ((pub_r001863_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001863_3_1 * 2) + 24) & 63;
  int stage_v_248_2 = ((pub_r001863_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_57_1 * 3) + pub_r001863_3_1) + 42) & 127;
  int stage_v_249_2 = (((stage_v_57_2 * 3) + pub_r001863_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001863_11_1 * 2) + 22) & 63;
  int stage_v_250_2 = ((pub_r001863_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((sec_r001863_12_1 * 3) + pub_r001863_2_1) + 23) & 127;
  int stage_v_251_2 = (((sec_r001863_12_2 * 3) + pub_r001863_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001863_3_1 * 2) + 19) & 63;
  int stage_v_252_2 = ((pub_r001863_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001863_8_1 * 2) + 15) & 63;
  int stage_v_253_2 = ((pub_r001863_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((helper_flow_5_1 * 3) + pub_r001863_11_1) + 5) & 127;
  int stage_v_254_2 = (((helper_flow_5_2 * 3) + pub_r001863_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001863_0_1 * 2) + 49) & 63;
  int stage_v_255_2 = ((pub_r001863_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_161_1 * 3) + pub_r001863_18_1) + 3) & 127;
  int stage_v_256_2 = (((stage_v_161_2 * 3) + pub_r001863_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((stage_v_81_1 * 3) + pub_r001863_13_1) + 37) & 127;
  int stage_v_257_2 = (((stage_v_81_2 * 3) + pub_r001863_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_155_1 * 3) + pub_r001863_4_1) + 6) & 127;
  int stage_v_258_2 = (((stage_v_155_2 * 3) + pub_r001863_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001863_6_1 * 2) + 45) & 63;
  int stage_v_259_2 = ((pub_r001863_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001863_7_1 * 2) + 19) & 63;
  int stage_v_260_2 = ((pub_r001863_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_109_1 * 3) + pub_r001863_1_1) + 9) & 127;
  int stage_v_261_2 = (((stage_v_109_2 * 3) + pub_r001863_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001863_8_1 * 2) + 40) & 63;
  int stage_v_262_2 = ((pub_r001863_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_222_1 * 3) + pub_r001863_12_1) + 39) & 127;
  int stage_v_263_2 = (((stage_v_222_2 * 3) + pub_r001863_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001863_3_1 * 2) + 39) & 63;
  int stage_v_264_2 = ((pub_r001863_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_73_1 * 3) + pub_r001863_19_1) + 44) & 127;
  int stage_v_265_2 = (((stage_v_73_2 * 3) + pub_r001863_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001863_4_1 * 2) + 15) & 63;
  int stage_v_266_2 = ((pub_r001863_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_65_1 * 3) + pub_r001863_4_1) + 36) & 127;
  int stage_v_267_2 = (((stage_v_65_2 * 3) + pub_r001863_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((helper_flow_3_1 * 3) + pub_r001863_17_1) + 34) & 127;
  int stage_v_268_2 = (((helper_flow_3_2 * 3) + pub_r001863_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_67_1 * 3) + pub_r001863_5_1) + 39) & 127;
  int stage_v_269_2 = (((stage_v_67_2 * 3) + pub_r001863_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_258_1 * 3) + pub_r001863_17_1) + 21) & 127;
  int stage_v_270_2 = (((stage_v_258_2 * 3) + pub_r001863_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_3_1 * 3) + pub_r001863_1_1) + 34) & 127;
  int stage_v_271_2 = (((stage_v_3_2 * 3) + pub_r001863_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001863_3_1 * 2) + 41) & 63;
  int stage_v_272_2 = ((pub_r001863_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001863_6_1 * 2) + 38) & 63;
  int stage_v_273_2 = ((pub_r001863_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001863_0_1 * 2) + 34) & 63;
  int stage_v_274_2 = ((pub_r001863_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_184_1 * 3) + pub_r001863_18_1) + 42) & 127;
  int stage_v_275_2 = (((stage_v_184_2 * 3) + pub_r001863_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_108_1 * 3) + pub_r001863_5_1) + 16) & 127;
  int stage_v_276_2 = (((stage_v_108_2 * 3) + pub_r001863_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_158_1 * 3) + pub_r001863_0_1) + 9) & 127;
  int stage_v_277_2 = (((stage_v_158_2 * 3) + pub_r001863_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_277_1 * 3) + pub_r001863_14_1) + 5) & 127;
  int stage_v_278_2 = (((stage_v_277_2 * 3) + pub_r001863_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((helper_flow_0_1 * 3) + pub_r001863_11_1) + 4) & 127;
  int stage_v_279_2 = (((helper_flow_0_2 * 3) + pub_r001863_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001863_5_1 * 2) + 11) & 63;
  int stage_v_280_2 = ((pub_r001863_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_58_1 * 3) + pub_r001863_17_1) + 45) & 127;
  int stage_v_281_2 = (((stage_v_58_2 * 3) + pub_r001863_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_160_1 * 3) + pub_r001863_15_1) + 33) & 127;
  int stage_v_282_2 = (((stage_v_160_2 * 3) + pub_r001863_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001863_1_1 * 2) + 33) & 63;
  int stage_v_283_2 = ((pub_r001863_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001863_14_1 * 2) + 13) & 63;
  int stage_v_284_2 = ((pub_r001863_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_119_1 * 3) + pub_r001863_11_1) + 19) & 127;
  int stage_v_285_2 = (((stage_v_119_2 * 3) + pub_r001863_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001863_1_1 * 2) + 15) & 63;
  int stage_v_286_2 = ((pub_r001863_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_81_1 * 3) + pub_r001863_10_1) + 8) & 127;
  int stage_v_287_2 = (((stage_v_81_2 * 3) + pub_r001863_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_271_1 * 3) + pub_r001863_12_1) + 6) & 127;
  int stage_v_288_2 = (((stage_v_271_2 * 3) + pub_r001863_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_170_1 * 3) + pub_r001863_14_1) + 3) & 127;
  int stage_v_289_2 = (((stage_v_170_2 * 3) + pub_r001863_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_203_1 * 3) + pub_r001863_1_1) + 45) & 127;
  int stage_v_290_2 = (((stage_v_203_2 * 3) + pub_r001863_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_87_1 * 3) + pub_r001863_5_1) + 3) & 127;
  int stage_v_291_2 = (((stage_v_87_2 * 3) + pub_r001863_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001863_3_1 * 2) + 17) & 63;
  int stage_v_292_2 = ((pub_r001863_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_8_1 * 3) + pub_r001863_17_1) + 41) & 127;
  int stage_v_293_2 = (((stage_v_8_2 * 3) + pub_r001863_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_23_1 * 3) + pub_r001863_19_1) + 38) & 127;
  int stage_v_294_2 = (((stage_v_23_2 * 3) + pub_r001863_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001863_9_1 * 2) + 10) & 63;
  int stage_v_295_2 = ((pub_r001863_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_57_1 * 3) + pub_r001863_7_1) + 32) & 127;
  int stage_v_296_2 = (((stage_v_57_2 * 3) + pub_r001863_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_281_1 * 3) + pub_r001863_5_1) + 32) & 127;
  int stage_v_297_2 = (((stage_v_281_2 * 3) + pub_r001863_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_206_1 * 3) + pub_r001863_2_1) + 19) & 127;
  int stage_v_298_2 = (((stage_v_206_2 * 3) + pub_r001863_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_44_1 * 3) + pub_r001863_16_1) + 11) & 127;
  int stage_v_299_2 = (((stage_v_44_2 * 3) + pub_r001863_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_298_1 * 3) + pub_r001863_4_1) + 28) & 127;
  int stage_v_300_2 = (((stage_v_298_2 * 3) + pub_r001863_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001863_16_1 * 2) + 16) & 63;
  int stage_v_301_2 = ((pub_r001863_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001863_12_1 * 2) + 36) & 63;
  int stage_v_302_2 = ((pub_r001863_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001863_14_1 * 2) + 36) & 63;
  int stage_v_303_2 = ((pub_r001863_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_230_1 * 3) + pub_r001863_2_1) + 23) & 127;
  int stage_v_304_2 = (((stage_v_230_2 * 3) + pub_r001863_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = (((stage_v_294_1 * 3) + pub_r001863_4_1) + 31) & 127;
  int stage_v_305_2 = (((stage_v_294_2 * 3) + pub_r001863_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = (((stage_v_190_1 * 3) + pub_r001863_0_1) + 4) & 127;
  int stage_v_306_2 = (((stage_v_190_2 * 3) + pub_r001863_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001863_16_1 * 2) + 25) & 63;
  int stage_v_307_2 = ((pub_r001863_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((helper_flow_8_1 * 3) + pub_r001863_5_1) + 43) & 127;
  int stage_v_308_2 = (((helper_flow_8_2 * 3) + pub_r001863_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_84_1 * 3) + pub_r001863_3_1) + 20) & 127;
  int stage_v_309_2 = (((stage_v_84_2 * 3) + pub_r001863_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001863_3_1 * 2) + 27) & 63;
  int stage_v_310_2 = ((pub_r001863_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001863_16_1 * 2) + 9) & 63;
  int stage_v_311_2 = ((pub_r001863_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001863_6_1 * 2) + 33) & 63;
  int stage_v_312_2 = ((pub_r001863_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_24_1 * 3) + pub_r001863_12_1) + 39) & 127;
  int stage_v_313_2 = (((stage_v_24_2 * 3) + pub_r001863_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_92_1 * 3) + pub_r001863_15_1) + 12) & 127;
  int stage_v_314_2 = (((stage_v_92_2 * 3) + pub_r001863_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_197_1 * 3) + pub_r001863_11_1) + 25) & 127;
  int stage_v_315_2 = (((stage_v_197_2 * 3) + pub_r001863_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_104_1 * 3) + pub_r001863_11_1) + 45) & 127;
  int stage_v_316_2 = (((stage_v_104_2 * 3) + pub_r001863_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_152_1 * 3) + pub_r001863_19_1) + 39) & 127;
  int stage_v_317_2 = (((stage_v_152_2 * 3) + pub_r001863_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_99_1 * 3) + pub_r001863_13_1) + 42) & 127;
  int stage_v_318_2 = (((stage_v_99_2 * 3) + pub_r001863_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001863_17_1 * 2) + 34) & 63;
  int stage_v_319_2 = ((pub_r001863_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001863_8_1 * 2) + 22) & 63;
  int stage_v_320_2 = ((pub_r001863_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_216_1 * 3) + pub_r001863_15_1) + 12) & 127;
  int stage_v_321_2 = (((stage_v_216_2 * 3) + pub_r001863_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_265_1 * 3) + pub_r001863_15_1) + 7) & 127;
  int stage_v_322_2 = (((stage_v_265_2 * 3) + pub_r001863_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001863_13_1 * 2) + 29) & 63;
  int stage_v_323_2 = ((pub_r001863_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_4_1 * 3) + pub_r001863_1_1) + 16) & 127;
  int stage_v_324_2 = (((stage_v_4_2 * 3) + pub_r001863_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((sec_r001863_6_1 * 3) + pub_r001863_15_1) + 37) & 127;
  int stage_v_325_2 = (((sec_r001863_6_2 * 3) + pub_r001863_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((helper_flow_2_1 * 3) + pub_r001863_4_1) + 7) & 127;
  int stage_v_326_2 = (((helper_flow_2_2 * 3) + pub_r001863_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_104_1 * 3) + pub_r001863_6_1) + 20) & 127;
  int stage_v_327_2 = (((stage_v_104_2 * 3) + pub_r001863_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_124_1 * 3) + pub_r001863_4_1) + 45) & 127;
  int stage_v_328_2 = (((stage_v_124_2 * 3) + pub_r001863_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_157_1 * 3) + pub_r001863_10_1) + 11) & 127;
  int stage_v_329_2 = (((stage_v_157_2 * 3) + pub_r001863_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001863_7_1 * 2) + 33) & 63;
  int stage_v_330_2 = ((pub_r001863_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001863_0_1 * 2) + 19) & 63;
  int stage_v_331_2 = ((pub_r001863_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_184_1 * 3) + pub_r001863_0_1) + 42) & 127;
  int stage_v_332_2 = (((stage_v_184_2 * 3) + pub_r001863_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((sec_r001863_14_1 * 3) + pub_r001863_9_1) + 25) & 127;
  int stage_v_333_2 = (((sec_r001863_14_2 * 3) + pub_r001863_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_185_1 * 3) + pub_r001863_10_1) + 21) & 127;
  int stage_v_334_2 = (((stage_v_185_2 * 3) + pub_r001863_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001863_17_1 * 2) + 41) & 63;
  int stage_v_335_2 = ((pub_r001863_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_29_1 * 3) + pub_r001863_3_1) + 45) & 127;
  int stage_v_336_2 = (((stage_v_29_2 * 3) + pub_r001863_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_231_1 * 3) + pub_r001863_8_1) + 44) & 127;
  int stage_v_337_2 = (((stage_v_231_2 * 3) + pub_r001863_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_84_1 * 3) + pub_r001863_12_1) + 44) & 127;
  int stage_v_338_2 = (((stage_v_84_2 * 3) + pub_r001863_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_223_1 * 3) + pub_r001863_0_1) + 31) & 127;
  int stage_v_339_2 = (((stage_v_223_2 * 3) + pub_r001863_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001863_0_1 * 2) + 25) & 63;
  int stage_v_340_2 = ((pub_r001863_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_115_1 * 3) + pub_r001863_9_1) + 39) & 127;
  int stage_v_341_2 = (((stage_v_115_2 * 3) + pub_r001863_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_296_1 * 3) + pub_r001863_4_1) + 36) & 127;
  int stage_v_342_2 = (((stage_v_296_2 * 3) + pub_r001863_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001863_7_1 * 2) + 10) & 63;
  int stage_v_343_2 = ((pub_r001863_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001863_5_1 * 2) + 50) & 63;
  int stage_v_344_2 = ((pub_r001863_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_109_1 * 3) + pub_r001863_5_1) + 18) & 127;
  int stage_v_345_2 = (((stage_v_109_2 * 3) + pub_r001863_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_197_1 * 3) + pub_r001863_5_1) + 45) & 127;
  int stage_v_346_2 = (((stage_v_197_2 * 3) + pub_r001863_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001863_9_1 * 2) + 34) & 63;
  int stage_v_347_2 = ((pub_r001863_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001863_19_1 * 2) + 48) & 63;
  int stage_v_348_2 = ((pub_r001863_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001863_16_1 * 2) + 5) & 63;
  int stage_v_349_2 = ((pub_r001863_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_306_1 * 3) + pub_r001863_8_1) + 41) & 127;
  int stage_v_350_2 = (((stage_v_306_2 * 3) + pub_r001863_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001863_5_1 * 2) + 15) & 63;
  int stage_v_351_2 = ((pub_r001863_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_194_1 * 3) + pub_r001863_1_1) + 5) & 127;
  int stage_v_352_2 = (((stage_v_194_2 * 3) + pub_r001863_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001863_13_1 * 2) + 49) & 63;
  int stage_v_353_2 = ((pub_r001863_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001863_1_1 * 2) + 29) & 63;
  int stage_v_354_2 = ((pub_r001863_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_308_1 * 3) + pub_r001863_15_1) + 32) & 127;
  int stage_v_355_2 = (((stage_v_308_2 * 3) + pub_r001863_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001863_17_1 * 2) + 33) & 63;
  int stage_v_356_2 = ((pub_r001863_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_11_1 * 3) + pub_r001863_18_1) + 11) & 127;
  int stage_v_357_2 = (((stage_v_11_2 * 3) + pub_r001863_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_84_1 * 3) + pub_r001863_13_1) + 39) & 127;
  int stage_v_358_2 = (((stage_v_84_2 * 3) + pub_r001863_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_270_1 * 3) + pub_r001863_8_1) + 28) & 127;
  int stage_v_359_2 = (((stage_v_270_2 * 3) + pub_r001863_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001863_10_1 * 2) + 45) & 63;
  int stage_v_360_2 = ((pub_r001863_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_69_1 * 3) + pub_r001863_10_1) + 30) & 127;
  int stage_v_361_2 = (((stage_v_69_2 * 3) + pub_r001863_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001863_12_1 * 2) + 19) & 63;
  int stage_v_362_2 = ((pub_r001863_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001863_5_1 * 2) + 43) & 63;
  int stage_v_363_2 = ((pub_r001863_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001863_4_1 * 2) + 6) & 63;
  int stage_v_364_2 = ((pub_r001863_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((helper_flow_5_1 * 3) + pub_r001863_12_1) + 34) & 127;
  int stage_v_365_2 = (((helper_flow_5_2 * 3) + pub_r001863_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001863_16_1 * 2) + 50) & 63;
  int stage_v_366_2 = ((pub_r001863_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_149_1 * 3) + pub_r001863_10_1) + 40) & 127;
  int stage_v_367_2 = (((stage_v_149_2 * 3) + pub_r001863_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_53_1 * 3) + pub_r001863_10_1) + 36) & 127;
  int stage_v_368_2 = (((stage_v_53_2 * 3) + pub_r001863_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_94_1 * 3) + pub_r001863_12_1) + 6) & 127;
  int stage_v_369_2 = (((stage_v_94_2 * 3) + pub_r001863_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_326_1 * 3) + pub_r001863_13_1) + 15) & 127;
  int stage_v_370_2 = (((stage_v_326_2 * 3) + pub_r001863_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_2_1 * 3) + pub_r001863_8_1) + 20) & 127;
  int stage_v_371_2 = (((stage_v_2_2 * 3) + pub_r001863_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001863_13_1 * 2) + 46) & 63;
  int stage_v_372_2 = ((pub_r001863_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001863_17_1 * 2) + 6) & 63;
  int stage_v_373_2 = ((pub_r001863_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001863_3_1 * 2) + 15) & 63;
  int stage_v_374_2 = ((pub_r001863_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_315_1 * 3) + pub_r001863_1_1) + 31) & 127;
  int stage_v_375_2 = (((stage_v_315_2 * 3) + pub_r001863_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001863_8_1 * 2) + 36) & 63;
  int stage_v_376_2 = ((pub_r001863_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001863_10_1 * 2) + 45) & 63;
  int stage_v_377_2 = ((pub_r001863_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_85_1 * 3) + pub_r001863_8_1) + 9) & 127;
  int stage_v_378_2 = (((stage_v_85_2 * 3) + pub_r001863_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_297_1 * 3) + pub_r001863_11_1) + 45) & 127;
  int stage_v_379_2 = (((stage_v_297_2 * 3) + pub_r001863_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_64_1 * 3) + pub_r001863_14_1) + 10) & 127;
  int stage_v_380_2 = (((stage_v_64_2 * 3) + pub_r001863_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_67_1 * 3) + pub_r001863_8_1) + 17) & 127;
  int stage_v_381_2 = (((stage_v_67_2 * 3) + pub_r001863_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001863_7_1 * 2) + 8) & 63;
  int stage_v_382_2 = ((pub_r001863_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((stage_v_281_1 * 3) + pub_r001863_4_1) + 8) & 127;
  int stage_v_383_2 = (((stage_v_281_2 * 3) + pub_r001863_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_371_1 * 3) + pub_r001863_10_1) + 26) & 127;
  int stage_v_384_2 = (((stage_v_371_2 * 3) + pub_r001863_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001863_18_1 * 2) + 9) & 63;
  int stage_v_385_2 = ((pub_r001863_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001863_6_1 * 2) + 49) & 63;
  int stage_v_386_2 = ((pub_r001863_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001863_0_1 * 2) + 35) & 63;
  int stage_v_387_2 = ((pub_r001863_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001863_8_1 * 2) + 18) & 63;
  int stage_v_388_2 = ((pub_r001863_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001863_8_1 * 2) + 30) & 63;
  int stage_v_389_2 = ((pub_r001863_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_44_1 * 3) + pub_r001863_8_1) + 42) & 127;
  int stage_v_390_2 = (((stage_v_44_2 * 3) + pub_r001863_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_41_1 * 3) + pub_r001863_11_1) + 20) & 127;
  int stage_v_391_2 = (((stage_v_41_2 * 3) + pub_r001863_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_187_1 * 3) + pub_r001863_6_1) + 20) & 127;
  int stage_v_392_2 = (((stage_v_187_2 * 3) + pub_r001863_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_350_1 * 3) + pub_r001863_4_1) + 13) & 127;
  int stage_v_393_2 = (((stage_v_350_2 * 3) + pub_r001863_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001863_17_1 * 2) + 50) & 63;
  int stage_v_394_2 = ((pub_r001863_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001863_16_1 * 2) + 25) & 63;
  int stage_v_395_2 = ((pub_r001863_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_60_1 * 3) + pub_r001863_14_1) + 7) & 127;
  int stage_v_396_2 = (((stage_v_60_2 * 3) + pub_r001863_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((helper_flow_3_1 * 3) + pub_r001863_11_1) + 42) & 127;
  int stage_v_397_2 = (((helper_flow_3_2 * 3) + pub_r001863_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001863_2_1 * 2) + 10) & 63;
  int stage_v_398_2 = ((pub_r001863_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001863_5_1 * 2) + 31) & 63;
  int stage_v_399_2 = ((pub_r001863_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_230_1 * 3) + pub_r001863_17_1) + 4) & 127;
  int stage_v_400_2 = (((stage_v_230_2 * 3) + pub_r001863_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((sec_r001863_7_1 * 3) + pub_r001863_18_1) + 30) & 127;
  int stage_v_401_2 = (((sec_r001863_7_2 * 3) + pub_r001863_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_44_1 * 3) + pub_r001863_1_1) + 36) & 127;
  int stage_v_402_2 = (((stage_v_44_2 * 3) + pub_r001863_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001863_2_1 * 2) + 22) & 63;
  int stage_v_403_2 = ((pub_r001863_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_369_1 * 3) + pub_r001863_9_1) + 21) & 127;
  int stage_v_404_2 = (((stage_v_369_2 * 3) + pub_r001863_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_130_1 * 3) + pub_r001863_9_1) + 29) & 127;
  int stage_v_405_2 = (((stage_v_130_2 * 3) + pub_r001863_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_334_1 * 3) + pub_r001863_18_1) + 10) & 127;
  int stage_v_406_2 = (((stage_v_334_2 * 3) + pub_r001863_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_91_1 * 3) + pub_r001863_1_1) + 35) & 127;
  int stage_v_407_2 = (((stage_v_91_2 * 3) + pub_r001863_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_190_1 * 3) + pub_r001863_8_1) + 29) & 127;
  int stage_v_408_2 = (((stage_v_190_2 * 3) + pub_r001863_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001863_9_1 * 2) + 15) & 63;
  int stage_v_409_2 = ((pub_r001863_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_111_1 * 3) + pub_r001863_10_1) + 23) & 127;
  int stage_v_410_2 = (((stage_v_111_2 * 3) + pub_r001863_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = (((stage_v_113_1 * 3) + pub_r001863_18_1) + 16) & 127;
  int stage_v_411_2 = (((stage_v_113_2 * 3) + pub_r001863_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = (((stage_v_263_1 * 3) + pub_r001863_12_1) + 15) & 127;
  int stage_v_412_2 = (((stage_v_263_2 * 3) + pub_r001863_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001863_18_1 == pub_r001863_18_2);
  __CPROVER_assume(pub_r001863_16_1 == pub_r001863_16_2);
  __CPROVER_assume(pub_r001863_14_1 == pub_r001863_14_2);
  __CPROVER_assume(sec_r001863_1_1 != sec_r001863_1_2);
  __CPROVER_assume(pub_r001863_1_1 == pub_r001863_1_2);
  __CPROVER_assume(sec_r001863_21_1 != sec_r001863_21_2);
  __CPROVER_assume(sec_r001863_7_1 != sec_r001863_7_2);
  __CPROVER_assume(pub_r001863_17_1 == pub_r001863_17_2);
  __CPROVER_assume(sec_r001863_11_1 != sec_r001863_11_2);
  __CPROVER_assume(sec_r001863_14_1 != sec_r001863_14_2);
  __CPROVER_assume(sec_r001863_20_1 != sec_r001863_20_2);
  __CPROVER_assume(pub_r001863_12_1 == pub_r001863_12_2);
  __CPROVER_assume(sec_r001863_8_1 != sec_r001863_8_2);
  __CPROVER_assume(sec_r001863_9_1 != sec_r001863_9_2);
  __CPROVER_assume(pub_r001863_15_1 == pub_r001863_15_2);
  __CPROVER_assume(pub_r001863_0_1 == pub_r001863_0_2);
  __CPROVER_assume(pub_r001863_9_1 == pub_r001863_9_2);
  __CPROVER_assume(sec_r001863_16_1 != sec_r001863_16_2);
  __CPROVER_assume(pub_r001863_13_1 == pub_r001863_13_2);
  __CPROVER_assume(sec_r001863_22_1 != sec_r001863_22_2);
  __CPROVER_assume(pub_r001863_2_1 == pub_r001863_2_2);
  __CPROVER_assume(sec_r001863_0_1 != sec_r001863_0_2);
  __CPROVER_assume(sec_r001863_10_1 != sec_r001863_10_2);
  __CPROVER_assume(sec_r001863_4_1 != sec_r001863_4_2);
  __CPROVER_assume(sec_r001863_2_1 != sec_r001863_2_2);
  __CPROVER_assume(sec_r001863_13_1 != sec_r001863_13_2);
  __CPROVER_assume(pub_r001863_11_1 == pub_r001863_11_2);
  __CPROVER_assume(pub_r001863_7_1 == pub_r001863_7_2);
  __CPROVER_assume(sec_r001863_17_1 != sec_r001863_17_2);
  __CPROVER_assume(pub_r001863_5_1 == pub_r001863_5_2);
  __CPROVER_assume(pub_r001863_8_1 == pub_r001863_8_2);
  __CPROVER_assume(sec_r001863_19_1 != sec_r001863_19_2);
  __CPROVER_assume(sec_r001863_3_1 != sec_r001863_3_2);
  __CPROVER_assume(sec_r001863_15_1 != sec_r001863_15_2);
  __CPROVER_assume(sec_r001863_6_1 != sec_r001863_6_2);
  __CPROVER_assume(pub_r001863_6_1 == pub_r001863_6_2);
  __CPROVER_assume(pub_r001863_10_1 == pub_r001863_10_2);
  __CPROVER_assume(sec_r001863_5_1 != sec_r001863_5_2);
  __CPROVER_assume(sec_r001863_12_1 != sec_r001863_12_2);
  __CPROVER_assume(sec_r001863_23_1 != sec_r001863_23_2);
  __CPROVER_assume(pub_r001863_3_1 == pub_r001863_3_2);
  __CPROVER_assume(pub_r001863_19_1 == pub_r001863_19_2);
  __CPROVER_assume(sec_r001863_18_1 != sec_r001863_18_2);
  __CPROVER_assume(pub_r001863_4_1 == pub_r001863_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.capacity == st_var_3_2.capacity);
  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.checksum == st_var_3_2.checksum);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
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
}


