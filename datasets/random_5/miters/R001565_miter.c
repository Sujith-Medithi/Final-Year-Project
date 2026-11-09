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
struct StreamBuffer_R001565_6513_0
{
  int watermark;
  int checksum;
  int capacity;
  int head;
  int buffer[3];
};
struct SensorNode_R001565_6513_1
{
  unsigned char status;
  unsigned char calib;
  unsigned char gain;
  int threshold;
  unsigned char offset;
  int buffer[3];
};
union ColorPixel_R001565_6513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001565_6513_1
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
void fn_R001565_6513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int index_reg_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_25_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_25_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_25_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_25_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_35_1 = local_arr_1[aux_1 % 3];
  int segment_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_25_1 == index_reg_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_35_1 == segment_35_2);
}

int fn_R001565_6513_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int index_reg_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_25 > 33)
  {
    acc = ((acc + (index_reg_25 * 2)) + 5) & 127;
    aux ^= index_reg_25 & 15;
  }
  else
  {
    acc = ((acc - index_reg_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_35 = local_arr[aux % 3];
  acc = (acc + (segment_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001565_6513_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_52_1 = local_arr_1[aux_1 % 3];
  int residue_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_52_2 * 2)) & 127;
  int checksum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_40_1)
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

  switch (checksum_40_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_52_1 == residue_52_2);
  assert(checksum_40_1 == checksum_40_2);
}

int fn_R001565_6513_1(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int residue_52 = local_arr[aux % 3];
  acc = (acc + (residue_52 * 2)) & 127;
  int checksum_40 = (aux + st.buffer[1]) & 3;
  switch (checksum_40)
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

void fn_R001565_6513_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_53_1)
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

  switch (anchor_53_2)
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

  int stride_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_38_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_38_1 * 2)) + 5) & 127;
    aux_1 ^= stride_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_38_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_38_2 * 2)) + 5) & 127;
    aux_2 ^= stride_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_76_1 = local_arr_1[aux_1 % 3];
  int segment_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_53_1 == anchor_53_2);
  assert(stride_38_1 == stride_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_76_1 == segment_76_2);
}

int fn_R001565_6513_2(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_53 = (aux + st.buffer[1]) & 3;
  switch (anchor_53)
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

  int stride_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_38 > 45)
  {
    acc = ((acc + (stride_38 * 2)) + 5) & 127;
    aux ^= stride_38 & 15;
  }
  else
  {
    acc = ((acc - stride_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_76 = local_arr[aux % 3];
  acc = (acc + (segment_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001565_6513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_66_1 = local_arr_1[aux_1 % 3];
  int scale_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_66_2 * 2)) & 127;
  int index_reg_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_72_1)
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

  switch (index_reg_72_2)
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

  int residue_83_1 = 0;
  int residue_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_83_1 = ((residue_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_83_2 = ((residue_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_83_1) & 127;
    acc_2 = (acc_2 + residue_83_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_66_1 == scale_66_2);
  assert(index_reg_72_1 == index_reg_72_2);
  assert(residue_83_1 == residue_83_2);
}

int fn_R001565_6513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int scale_66 = local_arr[aux % 3];
  acc = (acc + (scale_66 * 2)) & 127;
  int index_reg_72 = (aux + st.buffer[1]) & 3;
  switch (index_reg_72)
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

  int residue_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_83 = ((residue_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_83) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001565_6513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_46_1) & 63;
  aux_2 = (aux_2 + parity_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_39_1 > 42)
  {
    acc_1 = ((acc_1 + (checksum_39_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_39_2 > 42)
  {
    acc_2 = ((acc_2 + (checksum_39_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_46_1 == parity_46_2);
  assert(checksum_39_1 == checksum_39_2);
}

int fn_R001565_6513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_46) & 63;
  acc ^= aux;
  int checksum_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_39 > 42)
  {
    acc = ((acc + (checksum_39 * 2)) + 5) & 127;
    aux ^= checksum_39 & 15;
  }
  else
  {
    acc = ((acc - checksum_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001565_6513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_93_1 = local_arr_1[aux_1 % 3];
  int segment_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_10_1)
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

  switch (offset_10_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_93_1 == segment_93_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R001565_6513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int segment_93 = local_arr[aux % 3];
  acc = (acc + (segment_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_10 = (aux + st.buffer[1]) & 3;
  switch (offset_10)
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

void fn_R001565_6513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_15_1 = 0;
  int margin_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_15_1 = ((margin_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_15_2 = ((margin_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_15_1) & 127;
    acc_2 = (acc_2 + margin_15_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_79_1 = local_arr_1[aux_1 % 3];
  int pivot_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_79_2 * 2)) & 127;
  int factor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_69_1) & 63;
  aux_2 = (aux_2 + factor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_74_1)
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

  switch (sample_74_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_15_1 == margin_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_79_1 == pivot_79_2);
  assert(factor_69_1 == factor_69_2);
  assert(sample_74_1 == sample_74_2);
}

int fn_R001565_6513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_15 = ((margin_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_15) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_79 = local_arr[aux % 3];
  acc = (acc + (pivot_79 * 2)) & 127;
  int factor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_69) & 63;
  acc ^= aux;
  int sample_74 = (aux + st.buffer[1]) & 3;
  switch (sample_74)
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

void fn_R001565_6513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_33_1) & 63;
  aux_2 = (aux_2 + vector_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_66_1 = local_arr_1[aux_1 % 3];
  int weight_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_66_2 * 2)) & 127;
  int offset_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_41_1)
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

  switch (offset_41_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_33_1 == vector_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_66_1 == weight_66_2);
  assert(offset_41_1 == offset_41_2);
}

int fn_R001565_6513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_66 = local_arr[aux % 3];
  acc = (acc + (weight_66 * 2)) & 127;
  int offset_41 = (aux + st.buffer[1]) & 3;
  switch (offset_41)
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

void fn_R001565_6513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_70_1)
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

  switch (checksum_70_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_70_1 == checksum_70_2);
}

int fn_R001565_6513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_70 = (aux + st.buffer[1]) & 3;
  switch (checksum_70)
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

void fn_R001565_6513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_29_1) & 63;
  aux_2 = (aux_2 + sample_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_18_1 = local_arr_1[aux_1 % 3];
  int offset_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_29_1 == sample_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_18_1 == offset_18_2);
}

int fn_R001565_6513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_29) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_18 = local_arr[aux % 3];
  acc = (acc + (offset_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001565_6513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_20_1 > 18)
  {
    acc_1 = ((acc_1 + (checksum_20_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_20_2 > 18)
  {
    acc_2 = ((acc_2 + (checksum_20_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_39_1)
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

  switch (coefficient_39_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R001565_6513_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_20 > 18)
  {
    acc = ((acc + (checksum_20 * 2)) + 5) & 127;
    aux ^= checksum_20 & 15;
  }
  else
  {
    acc = ((acc - checksum_20) + 11) & 127;
    aux += 3;
  }
  int coefficient_39 = (aux + st.buffer[1]) & 3;
  switch (coefficient_39)
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

void fn_R001565_6513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_42_1 > 20)
  {
    acc_1 = ((acc_1 + (scale_42_1 * 2)) + 5) & 127;
    aux_1 ^= scale_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_42_2 > 20)
  {
    acc_2 = ((acc_2 + (scale_42_2 * 2)) + 5) & 127;
    aux_2 ^= scale_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_42_1 == scale_42_2);
}

int fn_R001565_6513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_42 > 20)
  {
    acc = ((acc + (scale_42 * 2)) + 5) & 127;
    aux ^= scale_42 & 15;
  }
  else
  {
    acc = ((acc - scale_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001565_6513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
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
  int delta_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_30_1) & 63;
  aux_2 = (aux_2 + delta_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_77_1 = local_arr_1[aux_1 % 3];
  int scale_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_30_1 == delta_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_77_1 == scale_77_2);
}

int fn_R001565_6513_12(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_77 = local_arr[aux % 3];
  acc = (acc + (scale_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001565_6513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_86_1 = local_arr_1[aux_1 % 3];
  int tracker_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_86_2 * 2)) & 127;
  int window_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_35_1)
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

  switch (window_35_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_86_1 == tracker_86_2);
  assert(window_35_1 == window_35_2);
}

int fn_R001565_6513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int tracker_86 = local_arr[aux % 3];
  acc = (acc + (tracker_86 * 2)) & 127;
  int window_35 = (aux + st.buffer[1]) & 3;
  switch (window_35)
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

void fn_R001565_6513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tracker_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_45_1 > 40)
  {
    acc_1 = ((acc_1 + (tracker_45_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_45_2 > 40)
  {
    acc_2 = ((acc_2 + (tracker_45_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_61_1) & 63;
  aux_2 = (aux_2 + bound_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_65_1)
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

  switch (delta_65_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_45_1 == tracker_45_2);
  assert(bound_61_1 == bound_61_2);
  assert(delta_65_1 == delta_65_2);
}

int fn_R001565_6513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001565_6513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tracker_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_45 > 40)
  {
    acc = ((acc + (tracker_45 * 2)) + 5) & 127;
    aux ^= tracker_45 & 15;
  }
  else
  {
    acc = ((acc - tracker_45) + 11) & 127;
    aux += 3;
  }
  int bound_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_61) & 63;
  acc ^= aux;
  int delta_65 = (aux + st.buffer[1]) & 3;
  switch (delta_65)
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

void fn_R001565_6513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int mask_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_72_1)
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

  switch (mask_72_2)
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

  int quotient_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_42_1 > 25)
  {
    acc_1 = ((acc_1 + (quotient_42_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_42_2 > 25)
  {
    acc_2 = ((acc_2 + (quotient_42_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_72_1 == mask_72_2);
  assert(quotient_42_1 == quotient_42_2);
}

int fn_R001565_6513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int mask_72 = (aux + st.buffer[1]) & 3;
  switch (mask_72)
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

  int quotient_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_42 > 25)
  {
    acc = ((acc + (quotient_42 * 2)) + 5) & 127;
    aux ^= quotient_42 & 15;
  }
  else
  {
    acc = ((acc - quotient_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001565_6513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st_1 = {0};
  struct SensorNode_R001565_6513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_25_1 = local_arr_1[aux_1 % 3];
  int quantum_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_25_2 * 2)) & 127;
  int anchor_29_1 = 0;
  int anchor_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_29_1 = ((anchor_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_29_2 = ((anchor_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_29_1) & 127;
    acc_2 = (acc_2 + anchor_29_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_25_1 == quantum_25_2);
  assert(anchor_29_1 == anchor_29_2);
}

int fn_R001565_6513_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001565_6513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quantum_25 = local_arr[aux % 3];
  acc = (acc + (quantum_25 * 2)) & 127;
  int anchor_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_29 = ((anchor_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_29) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001565_0_1;
  int sec_r001565_0_2;
  int sec_r001565_1_1;
  int sec_r001565_1_2;
  int sec_r001565_2_1;
  int sec_r001565_2_2;
  int sec_r001565_3_1;
  int sec_r001565_3_2;
  int sec_r001565_4_1;
  int sec_r001565_4_2;
  int sec_r001565_5_1;
  int sec_r001565_5_2;
  int sec_r001565_6_1;
  int sec_r001565_6_2;
  int sec_r001565_7_1;
  int sec_r001565_7_2;
  int sec_r001565_8_1;
  int sec_r001565_8_2;
  int sec_r001565_9_1;
  int sec_r001565_9_2;
  int sec_r001565_10_1;
  int sec_r001565_10_2;
  int sec_r001565_11_1;
  int sec_r001565_11_2;
  int sec_r001565_12_1;
  int sec_r001565_12_2;
  int sec_r001565_13_1;
  int sec_r001565_13_2;
  int sec_r001565_14_1;
  int sec_r001565_14_2;
  int sec_r001565_15_1;
  int sec_r001565_15_2;
  int pub_r001565_0_1;
  int pub_r001565_0_2;
  int pub_r001565_1_1;
  int pub_r001565_1_2;
  int pub_r001565_2_1;
  int pub_r001565_2_2;
  int pub_r001565_3_1;
  int pub_r001565_3_2;
  int pub_r001565_4_1;
  int pub_r001565_4_2;
  int pub_r001565_5_1;
  int pub_r001565_5_2;
  int pub_r001565_6_1;
  int pub_r001565_6_2;
  int pub_r001565_7_1;
  int pub_r001565_7_2;
  int pub_r001565_8_1;
  int pub_r001565_8_2;
  int pub_r001565_9_1;
  int pub_r001565_9_2;
  int pub_r001565_10_1;
  int pub_r001565_10_2;
  int pub_r001565_11_1;
  int pub_r001565_11_2;
  int pub_r001565_12_1;
  int pub_r001565_12_2;
  int pub_r001565_13_1;
  int pub_r001565_13_2;
  int pub_r001565_14_1;
  int pub_r001565_14_2;
  int pub_r001565_15_1;
  int pub_r001565_15_2;
  int pub_r001565_16_1;
  int pub_r001565_16_2;
  int pub_r001565_17_1;
  int pub_r001565_17_2;
  int pub_r001565_18_1;
  int pub_r001565_18_2;
  int pub_r001565_19_1;
  int pub_r001565_19_2;
  int pub_r001565_20_1;
  int pub_r001565_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001565_0_1 >= (-100)) && (pub_r001565_0_1 <= 100));
  __CPROVER_assume((pub_r001565_0_2 >= (-100)) && (pub_r001565_0_2 <= 100));
  __CPROVER_assume((pub_r001565_1_1 >= (-100)) && (pub_r001565_1_1 <= 100));
  __CPROVER_assume((pub_r001565_1_2 >= (-100)) && (pub_r001565_1_2 <= 100));
  __CPROVER_assume((pub_r001565_2_1 >= (-100)) && (pub_r001565_2_1 <= 100));
  __CPROVER_assume((pub_r001565_2_2 >= (-100)) && (pub_r001565_2_2 <= 100));
  __CPROVER_assume((pub_r001565_3_1 >= (-100)) && (pub_r001565_3_1 <= 100));
  __CPROVER_assume((pub_r001565_3_2 >= (-100)) && (pub_r001565_3_2 <= 100));
  __CPROVER_assume((pub_r001565_4_1 >= (-100)) && (pub_r001565_4_1 <= 100));
  __CPROVER_assume((pub_r001565_4_2 >= (-100)) && (pub_r001565_4_2 <= 100));
  __CPROVER_assume((pub_r001565_5_1 >= (-100)) && (pub_r001565_5_1 <= 100));
  __CPROVER_assume((pub_r001565_5_2 >= (-100)) && (pub_r001565_5_2 <= 100));
  __CPROVER_assume((pub_r001565_6_1 >= (-100)) && (pub_r001565_6_1 <= 100));
  __CPROVER_assume((pub_r001565_6_2 >= (-100)) && (pub_r001565_6_2 <= 100));
  __CPROVER_assume((pub_r001565_7_1 >= (-100)) && (pub_r001565_7_1 <= 100));
  __CPROVER_assume((pub_r001565_7_2 >= (-100)) && (pub_r001565_7_2 <= 100));
  __CPROVER_assume((pub_r001565_8_1 >= (-100)) && (pub_r001565_8_1 <= 100));
  __CPROVER_assume((pub_r001565_8_2 >= (-100)) && (pub_r001565_8_2 <= 100));
  __CPROVER_assume((pub_r001565_9_1 >= (-100)) && (pub_r001565_9_1 <= 100));
  __CPROVER_assume((pub_r001565_9_2 >= (-100)) && (pub_r001565_9_2 <= 100));
  __CPROVER_assume((pub_r001565_10_1 >= (-100)) && (pub_r001565_10_1 <= 100));
  __CPROVER_assume((pub_r001565_10_2 >= (-100)) && (pub_r001565_10_2 <= 100));
  __CPROVER_assume((pub_r001565_11_1 >= (-100)) && (pub_r001565_11_1 <= 100));
  __CPROVER_assume((pub_r001565_11_2 >= (-100)) && (pub_r001565_11_2 <= 100));
  __CPROVER_assume((pub_r001565_12_1 >= (-100)) && (pub_r001565_12_1 <= 100));
  __CPROVER_assume((pub_r001565_12_2 >= (-100)) && (pub_r001565_12_2 <= 100));
  __CPROVER_assume((pub_r001565_13_1 >= (-100)) && (pub_r001565_13_1 <= 100));
  __CPROVER_assume((pub_r001565_13_2 >= (-100)) && (pub_r001565_13_2 <= 100));
  __CPROVER_assume((pub_r001565_14_1 >= (-100)) && (pub_r001565_14_1 <= 100));
  __CPROVER_assume((pub_r001565_14_2 >= (-100)) && (pub_r001565_14_2 <= 100));
  __CPROVER_assume((pub_r001565_15_1 >= (-100)) && (pub_r001565_15_1 <= 100));
  __CPROVER_assume((pub_r001565_15_2 >= (-100)) && (pub_r001565_15_2 <= 100));
  __CPROVER_assume((pub_r001565_16_1 >= (-100)) && (pub_r001565_16_1 <= 100));
  __CPROVER_assume((pub_r001565_16_2 >= (-100)) && (pub_r001565_16_2 <= 100));
  __CPROVER_assume((pub_r001565_17_1 >= (-100)) && (pub_r001565_17_1 <= 100));
  __CPROVER_assume((pub_r001565_17_2 >= (-100)) && (pub_r001565_17_2 <= 100));
  __CPROVER_assume((pub_r001565_18_1 >= (-100)) && (pub_r001565_18_1 <= 100));
  __CPROVER_assume((pub_r001565_18_2 >= (-100)) && (pub_r001565_18_2 <= 100));
  __CPROVER_assume((pub_r001565_19_1 >= (-100)) && (pub_r001565_19_1 <= 100));
  __CPROVER_assume((pub_r001565_19_2 >= (-100)) && (pub_r001565_19_2 <= 100));
  __CPROVER_assume((pub_r001565_20_1 >= (-100)) && (pub_r001565_20_1 <= 100));
  __CPROVER_assume((pub_r001565_20_2 >= (-100)) && (pub_r001565_20_2 <= 100));
  __CPROVER_assume((sec_r001565_0_1 >= 0) && (sec_r001565_0_1 <= 255));
  __CPROVER_assume((sec_r001565_0_2 >= 0) && (sec_r001565_0_2 <= 255));
  __CPROVER_assume((sec_r001565_1_1 >= 0) && (sec_r001565_1_1 <= 255));
  __CPROVER_assume((sec_r001565_1_2 >= 0) && (sec_r001565_1_2 <= 255));
  __CPROVER_assume((sec_r001565_2_1 >= 0) && (sec_r001565_2_1 <= 255));
  __CPROVER_assume((sec_r001565_2_2 >= 0) && (sec_r001565_2_2 <= 255));
  __CPROVER_assume((sec_r001565_3_1 >= 0) && (sec_r001565_3_1 <= 255));
  __CPROVER_assume((sec_r001565_3_2 >= 0) && (sec_r001565_3_2 <= 255));
  __CPROVER_assume((sec_r001565_4_1 >= 0) && (sec_r001565_4_1 <= 255));
  __CPROVER_assume((sec_r001565_4_2 >= 0) && (sec_r001565_4_2 <= 255));
  __CPROVER_assume((sec_r001565_5_1 >= 0) && (sec_r001565_5_1 <= 255));
  __CPROVER_assume((sec_r001565_5_2 >= 0) && (sec_r001565_5_2 <= 255));
  __CPROVER_assume((sec_r001565_6_1 >= 0) && (sec_r001565_6_1 <= 255));
  __CPROVER_assume((sec_r001565_6_2 >= 0) && (sec_r001565_6_2 <= 255));
  __CPROVER_assume((sec_r001565_7_1 >= 0) && (sec_r001565_7_1 <= 255));
  __CPROVER_assume((sec_r001565_7_2 >= 0) && (sec_r001565_7_2 <= 255));
  __CPROVER_assume((sec_r001565_8_1 >= 0) && (sec_r001565_8_1 <= 255));
  __CPROVER_assume((sec_r001565_8_2 >= 0) && (sec_r001565_8_2 <= 255));
  __CPROVER_assume((sec_r001565_9_1 >= 0) && (sec_r001565_9_1 <= 255));
  __CPROVER_assume((sec_r001565_9_2 >= 0) && (sec_r001565_9_2 <= 255));
  __CPROVER_assume((sec_r001565_10_1 >= 0) && (sec_r001565_10_1 <= 255));
  __CPROVER_assume((sec_r001565_10_2 >= 0) && (sec_r001565_10_2 <= 255));
  __CPROVER_assume((sec_r001565_11_1 >= 0) && (sec_r001565_11_1 <= 255));
  __CPROVER_assume((sec_r001565_11_2 >= 0) && (sec_r001565_11_2 <= 255));
  __CPROVER_assume((sec_r001565_12_1 >= 0) && (sec_r001565_12_1 <= 255));
  __CPROVER_assume((sec_r001565_12_2 >= 0) && (sec_r001565_12_2 <= 255));
  __CPROVER_assume((sec_r001565_13_1 >= 0) && (sec_r001565_13_1 <= 255));
  __CPROVER_assume((sec_r001565_13_2 >= 0) && (sec_r001565_13_2 <= 255));
  __CPROVER_assume((sec_r001565_14_1 >= 0) && (sec_r001565_14_1 <= 255));
  __CPROVER_assume((sec_r001565_14_2 >= 0) && (sec_r001565_14_2 <= 255));
  __CPROVER_assume((sec_r001565_15_1 >= 0) && (sec_r001565_15_1 <= 255));
  __CPROVER_assume((sec_r001565_15_2 >= 0) && (sec_r001565_15_2 <= 255));
  struct StreamBuffer_R001565_6513_0 st_var_0_1 = {0};
  struct StreamBuffer_R001565_6513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001565_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001565_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001565_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001565_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001565_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001565_0_2 + 7) & 15;
  struct SensorNode_R001565_6513_1 st_var_1_1 = {0};
  struct SensorNode_R001565_6513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001565_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001565_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001565_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001565_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001565_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001565_0_2 + 9) & 15;
  union ColorPixel_R001565_6513_0 u_var_1;
  union ColorPixel_R001565_6513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001565_6513_0(sec_r001565_0_1, pub_r001565_1_1, pub_r001565_2_1, pub_r001565_3_1, pub_r001565_4_1);
  int helper_flow_0_2 = fn_R001565_6513_0(sec_r001565_0_2, pub_r001565_1_2, pub_r001565_2_2, pub_r001565_3_2, pub_r001565_4_2);
  fn_R001565_6513_0_2(sec_r001565_0_1, pub_r001565_1_1, pub_r001565_2_1, pub_r001565_3_1, pub_r001565_4_1, sec_r001565_0_2, pub_r001565_1_2, pub_r001565_2_2, pub_r001565_3_2, pub_r001565_4_2);
  int helper_flow_1_1 = fn_R001565_6513_1(sec_r001565_1_1, pub_r001565_2_1);
  int helper_flow_1_2 = fn_R001565_6513_1(sec_r001565_1_2, pub_r001565_2_2);
  fn_R001565_6513_1_2(sec_r001565_1_1, pub_r001565_2_1, sec_r001565_1_2, pub_r001565_2_2);
  int helper_flow_2_1 = fn_R001565_6513_2(sec_r001565_2_1, sec_r001565_3_1);
  int helper_flow_2_2 = fn_R001565_6513_2(sec_r001565_2_2, sec_r001565_3_2);
  fn_R001565_6513_2_2(sec_r001565_2_1, sec_r001565_3_1, sec_r001565_2_2, sec_r001565_3_2);
  int helper_flow_3_1 = fn_R001565_6513_3(sec_r001565_3_1, pub_r001565_4_1, pub_r001565_5_1);
  int helper_flow_3_2 = fn_R001565_6513_3(sec_r001565_3_2, pub_r001565_4_2, pub_r001565_5_2);
  fn_R001565_6513_3_2(sec_r001565_3_1, pub_r001565_4_1, pub_r001565_5_1, sec_r001565_3_2, pub_r001565_4_2, pub_r001565_5_2);
  int helper_flow_4_1 = fn_R001565_6513_4(sec_r001565_4_1, sec_r001565_5_1, pub_r001565_6_1);
  int helper_flow_4_2 = fn_R001565_6513_4(sec_r001565_4_2, sec_r001565_5_2, pub_r001565_6_2);
  fn_R001565_6513_4_2(sec_r001565_4_1, sec_r001565_5_1, pub_r001565_6_1, sec_r001565_4_2, sec_r001565_5_2, pub_r001565_6_2);
  int helper_flow_5_1 = fn_R001565_6513_5(sec_r001565_5_1, sec_r001565_6_1, pub_r001565_7_1);
  int helper_flow_5_2 = fn_R001565_6513_5(sec_r001565_5_2, sec_r001565_6_2, pub_r001565_7_2);
  fn_R001565_6513_5_2(sec_r001565_5_1, sec_r001565_6_1, pub_r001565_7_1, sec_r001565_5_2, sec_r001565_6_2, pub_r001565_7_2);
  int helper_flow_6_1 = fn_R001565_6513_6(sec_r001565_6_1, pub_r001565_7_1, pub_r001565_8_1, pub_r001565_9_1);
  int helper_flow_6_2 = fn_R001565_6513_6(sec_r001565_6_2, pub_r001565_7_2, pub_r001565_8_2, pub_r001565_9_2);
  fn_R001565_6513_6_2(sec_r001565_6_1, pub_r001565_7_1, pub_r001565_8_1, pub_r001565_9_1, sec_r001565_6_2, pub_r001565_7_2, pub_r001565_8_2, pub_r001565_9_2);
  int helper_flow_7_1 = fn_R001565_6513_7(sec_r001565_7_1, pub_r001565_8_1, pub_r001565_9_1);
  int helper_flow_7_2 = fn_R001565_6513_7(sec_r001565_7_2, pub_r001565_8_2, pub_r001565_9_2);
  fn_R001565_6513_7_2(sec_r001565_7_1, pub_r001565_8_1, pub_r001565_9_1, sec_r001565_7_2, pub_r001565_8_2, pub_r001565_9_2);
  int helper_flow_8_1 = fn_R001565_6513_8(sec_r001565_8_1, sec_r001565_9_1, pub_r001565_10_1, pub_r001565_11_1);
  int helper_flow_8_2 = fn_R001565_6513_8(sec_r001565_8_2, sec_r001565_9_2, pub_r001565_10_2, pub_r001565_11_2);
  fn_R001565_6513_8_2(sec_r001565_8_1, sec_r001565_9_1, pub_r001565_10_1, pub_r001565_11_1, sec_r001565_8_2, sec_r001565_9_2, pub_r001565_10_2, pub_r001565_11_2);
  int stage_v_0_1 = ((pub_r001565_5_1 * 2) + 16) & 63;
  int stage_v_0_2 = ((pub_r001565_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001565_9_1 * 2) + 15) & 63;
  int stage_v_1_2 = ((pub_r001565_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((helper_flow_0_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_2_2 = ((helper_flow_0_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001565_3_1 * 2) + 38) & 63;
  int stage_v_3_2 = ((pub_r001565_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001565_12_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001565_12_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001565_16_1 * 2) + 37) & 63;
  int stage_v_5_2 = ((pub_r001565_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001565_13_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001565_13_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((sec_r001565_0_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_7_2 = ((sec_r001565_0_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((sec_r001565_5_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001565_5_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((helper_flow_3_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_9_2 = ((helper_flow_3_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((stage_v_7_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((stage_v_7_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((sec_r001565_1_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001565_1_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((stage_v_11_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_12_2 = ((stage_v_11_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((pub_r001565_16_1 * 2) + 45) & 63;
  int stage_v_13_2 = ((pub_r001565_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001565_10_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001565_10_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((pub_r001565_4_1 * 2) + 30) & 63;
  int stage_v_15_2 = ((pub_r001565_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((helper_flow_0_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_16_2 = ((helper_flow_0_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((pub_r001565_16_1 * 2) + 37) & 63;
  int stage_v_17_2 = ((pub_r001565_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((helper_flow_0_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_18_2 = ((helper_flow_0_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((sec_r001565_6_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_19_2 = ((sec_r001565_6_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001565_7_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001565_7_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((stage_v_10_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_21_2 = ((stage_v_10_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((pub_r001565_0_1 * 2) + 5) & 63;
  int stage_v_22_2 = ((pub_r001565_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_19_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_19_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((sec_r001565_12_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001565_12_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((pub_r001565_13_1 * 2) + 28) & 63;
  int stage_v_25_2 = ((pub_r001565_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001565_1_1 * 2) + 10) & 63;
  int stage_v_26_2 = ((pub_r001565_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001565_0_1 * 2) + 42) & 63;
  int stage_v_27_2 = ((pub_r001565_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001565_1_1 * 2) + 31) & 63;
  int stage_v_28_2 = ((pub_r001565_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001565_9_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_29_2 = ((sec_r001565_9_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001565_9_1 * 2) + 26) & 63;
  int stage_v_30_2 = ((pub_r001565_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001565_5_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_31_2 = ((sec_r001565_5_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((sec_r001565_8_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001565_8_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((stage_v_7_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_33_2 = ((stage_v_7_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((stage_v_8_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_34_2 = ((stage_v_8_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001565_5_1 * 2) + 16) & 63;
  int stage_v_35_2 = ((pub_r001565_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001565_13_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001565_13_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((stage_v_16_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_37_2 = ((stage_v_16_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((helper_flow_6_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_38_2 = ((helper_flow_6_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_20_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_20_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((stage_v_20_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_40_2 = ((stage_v_20_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((pub_r001565_17_1 * 2) + 47) & 63;
  int stage_v_41_2 = ((pub_r001565_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001565_11_1 * 2) + 40) & 63;
  int stage_v_42_2 = ((pub_r001565_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((sec_r001565_11_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_43_2 = ((sec_r001565_11_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((sec_r001565_10_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_44_2 = ((sec_r001565_10_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001565_9_1 * 2) + 23) & 63;
  int stage_v_45_2 = ((pub_r001565_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_43_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_43_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001565_17_1 * 2) + 31) & 63;
  int stage_v_47_2 = ((pub_r001565_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((helper_flow_3_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_48_2 = ((helper_flow_3_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((sec_r001565_10_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001565_10_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001565_8_1 * 2) + 20) & 63;
  int stage_v_50_2 = ((pub_r001565_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((helper_flow_0_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_51_2 = ((helper_flow_0_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((stage_v_8_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_52_2 = ((stage_v_8_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001565_5_1 * 2) + 25) & 63;
  int stage_v_53_2 = ((pub_r001565_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((helper_flow_1_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_54_2 = ((helper_flow_1_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((stage_v_11_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_55_2 = ((stage_v_11_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((stage_v_19_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_19_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((pub_r001565_4_1 * 2) + 42) & 63;
  int stage_v_57_2 = ((pub_r001565_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((helper_flow_2_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_58_2 = ((helper_flow_2_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((stage_v_43_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_59_2 = ((stage_v_43_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((helper_flow_0_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_60_2 = ((helper_flow_0_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((helper_flow_4_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_61_2 = ((helper_flow_4_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_33_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_33_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((pub_r001565_17_1 * 2) + 49) & 63;
  int stage_v_63_2 = ((pub_r001565_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_10_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_64_2 = ((stage_v_10_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((stage_v_40_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_40_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001565_16_1 * 2) + 45) & 63;
  int stage_v_66_2 = ((pub_r001565_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001565_2_1 * 2) + 30) & 63;
  int stage_v_67_2 = ((pub_r001565_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001565_0_1 * 2) + 31) & 63;
  int stage_v_68_2 = ((pub_r001565_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_33_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_33_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((pub_r001565_3_1 * 2) + 7) & 63;
  int stage_v_70_2 = ((pub_r001565_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_7_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_71_2 = ((stage_v_7_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((pub_r001565_13_1 * 2) + 45) & 63;
  int stage_v_72_2 = ((pub_r001565_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((sec_r001565_14_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_73_2 = ((sec_r001565_14_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((stage_v_7_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_74_2 = ((stage_v_7_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((pub_r001565_11_1 * 2) + 31) & 63;
  int stage_v_75_2 = ((pub_r001565_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_62_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_62_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((sec_r001565_6_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_77_2 = ((sec_r001565_6_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001565_6_1 * 2) + 5) & 63;
  int stage_v_78_2 = ((pub_r001565_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((sec_r001565_14_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_79_2 = ((sec_r001565_14_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((stage_v_24_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_24_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((pub_r001565_14_1 * 2) + 48) & 63;
  int stage_v_81_2 = ((pub_r001565_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_51_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_51_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((stage_v_65_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_83_2 = ((stage_v_65_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((pub_r001565_12_1 * 2) + 19) & 63;
  int stage_v_84_2 = ((pub_r001565_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001565_14_1 * 2) + 9) & 63;
  int stage_v_85_2 = ((pub_r001565_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001565_15_1 * 2) + 20) & 63;
  int stage_v_86_2 = ((pub_r001565_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_6_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_87_2 = ((stage_v_6_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((stage_v_69_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_88_2 = ((stage_v_69_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((stage_v_54_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_54_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((stage_v_33_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_33_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((stage_v_31_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_91_2 = ((stage_v_31_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((pub_r001565_9_1 * 2) + 11) & 63;
  int stage_v_92_2 = ((pub_r001565_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_44_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_44_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((stage_v_20_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_20_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((stage_v_46_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_95_2 = ((stage_v_46_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((sec_r001565_5_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_96_2 = ((sec_r001565_5_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((stage_v_55_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_55_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((stage_v_12_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_12_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001565_18_1 * 2) + 24) & 63;
  int stage_v_99_2 = ((pub_r001565_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001565_13_1 * 2) + 11) & 63;
  int stage_v_100_2 = ((pub_r001565_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_19_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_19_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((pub_r001565_4_1 * 2) + 44) & 63;
  int stage_v_102_2 = ((pub_r001565_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((sec_r001565_1_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_103_2 = ((sec_r001565_1_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((stage_v_88_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_88_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001565_14_1 * 2) + 23) & 63;
  int stage_v_105_2 = ((pub_r001565_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001565_20_1 * 2) + 34) & 63;
  int stage_v_106_2 = ((pub_r001565_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001565_17_1 * 2) + 33) & 63;
  int stage_v_107_2 = ((pub_r001565_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_93_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_108_2 = ((stage_v_93_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((stage_v_61_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_61_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001565_12_1 * 2) + 5) & 63;
  int stage_v_110_2 = ((pub_r001565_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((helper_flow_4_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_111_2 = ((helper_flow_4_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((pub_r001565_14_1 * 2) + 7) & 63;
  int stage_v_112_2 = ((pub_r001565_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001565_10_1 * 2) + 8) & 63;
  int stage_v_113_2 = ((pub_r001565_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_91_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_114_2 = ((stage_v_91_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_31_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_31_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001565_2_1 * 2) + 10) & 63;
  int stage_v_116_2 = ((pub_r001565_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001565_0_1 * 2) + 13) & 63;
  int stage_v_117_2 = ((pub_r001565_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001565_6_1 * 2) + 45) & 63;
  int stage_v_118_2 = ((pub_r001565_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_104_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_119_2 = ((stage_v_104_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((stage_v_108_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_108_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((sec_r001565_13_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_121_2 = ((sec_r001565_13_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((stage_v_98_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_98_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_4_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_4_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001565_16_1 * 2) + 42) & 63;
  int stage_v_124_2 = ((pub_r001565_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001565_0_1 * 2) + 37) & 63;
  int stage_v_125_2 = ((pub_r001565_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_115_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_115_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((stage_v_34_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_34_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((pub_r001565_19_1 * 2) + 50) & 63;
  int stage_v_128_2 = ((pub_r001565_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_111_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_111_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((stage_v_12_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_12_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((stage_v_87_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_87_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001565_9_1 * 2) + 25) & 63;
  int stage_v_132_2 = ((pub_r001565_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001565_9_1 * 2) + 26) & 63;
  int stage_v_133_2 = ((pub_r001565_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001565_8_1 * 2) + 50) & 63;
  int stage_v_134_2 = ((pub_r001565_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001565_7_1 * 2) + 40) & 63;
  int stage_v_135_2 = ((pub_r001565_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001565_12_1 * 2) + 5) & 63;
  int stage_v_136_2 = ((pub_r001565_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_7_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_7_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((pub_r001565_12_1 * 2) + 49) & 63;
  int stage_v_138_2 = ((pub_r001565_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001565_17_1 * 2) + 40) & 63;
  int stage_v_139_2 = ((pub_r001565_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001565_9_1 * 2) + 28) & 63;
  int stage_v_140_2 = ((pub_r001565_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001565_5_1 * 2) + 33) & 63;
  int stage_v_141_2 = ((pub_r001565_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001565_14_1 * 2) + 47) & 63;
  int stage_v_142_2 = ((pub_r001565_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001565_18_1 * 2) + 48) & 63;
  int stage_v_143_2 = ((pub_r001565_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_73_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_73_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_39_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_39_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((pub_r001565_4_1 * 2) + 41) & 63;
  int stage_v_146_2 = ((pub_r001565_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_83_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_83_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001565_14_1 * 2) + 16) & 63;
  int stage_v_148_2 = ((pub_r001565_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001565_3_1 * 2) + 40) & 63;
  int stage_v_149_2 = ((pub_r001565_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001565_0_1 * 2) + 42) & 63;
  int stage_v_150_2 = ((pub_r001565_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001565_20_1 * 2) + 19) & 63;
  int stage_v_151_2 = ((pub_r001565_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_77_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_77_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001565_2_1 * 2) + 15) & 63;
  int stage_v_153_2 = ((pub_r001565_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001565_7_1 * 2) + 19) & 63;
  int stage_v_154_2 = ((pub_r001565_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_59_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_59_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001565_8_1 * 2) + 47) & 63;
  int stage_v_156_2 = ((pub_r001565_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001565_17_1 * 2) + 29) & 63;
  int stage_v_157_2 = ((pub_r001565_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_4_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_4_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((sec_r001565_15_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_159_2 = ((sec_r001565_15_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001565_13_1 * 2) + 21) & 63;
  int stage_v_160_2 = ((pub_r001565_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001565_0_1 * 2) + 44) & 63;
  int stage_v_161_2 = ((pub_r001565_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001565_11_1 * 2) + 28) & 63;
  int stage_v_162_2 = ((pub_r001565_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_61_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_61_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((stage_v_46_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_46_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((stage_v_18_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_18_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((pub_r001565_0_1 * 2) + 42) & 63;
  int stage_v_166_2 = ((pub_r001565_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((helper_flow_2_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_167_2 = ((helper_flow_2_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((pub_r001565_11_1 * 2) + 33) & 63;
  int stage_v_168_2 = ((pub_r001565_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001565_16_1 * 2) + 47) & 63;
  int stage_v_169_2 = ((pub_r001565_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001565_20_1 * 2) + 33) & 63;
  int stage_v_170_2 = ((pub_r001565_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((helper_flow_8_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_171_2 = ((helper_flow_8_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001565_6_1 * 2) + 26) & 63;
  int stage_v_172_2 = ((pub_r001565_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001565_20_1 * 2) + 21) & 63;
  int stage_v_173_2 = ((pub_r001565_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001565_20_1 * 2) + 15) & 63;
  int stage_v_174_2 = ((pub_r001565_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001565_4_1 * 2) + 41) & 63;
  int stage_v_175_2 = ((pub_r001565_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((stage_v_12_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_12_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((stage_v_14_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_177_2 = ((stage_v_14_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((stage_v_61_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_61_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_24_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_24_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001565_4_1 * 2) + 41) & 63;
  int stage_v_180_2 = ((pub_r001565_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001565_6_1 * 2) + 20) & 63;
  int stage_v_181_2 = ((pub_r001565_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001565_14_1 * 2) + 41) & 63;
  int stage_v_182_2 = ((pub_r001565_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001565_15_1 * 2) + 39) & 63;
  int stage_v_183_2 = ((pub_r001565_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001565_20_1 * 2) + 16) & 63;
  int stage_v_184_2 = ((pub_r001565_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001565_3_1 * 2) + 10) & 63;
  int stage_v_185_2 = ((pub_r001565_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((sec_r001565_3_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_186_2 = ((sec_r001565_3_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_186_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_186_2 + 1) & 15;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = ((stage_v_73_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_73_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_97_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_97_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001565_9_1 * 2) + 22) & 63;
  int stage_v_189_2 = ((pub_r001565_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001565_2_1 * 2) + 15) & 63;
  int stage_v_190_2 = ((pub_r001565_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001565_3_1 * 2) + 46) & 63;
  int stage_v_191_2 = ((pub_r001565_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001565_0_1 * 2) + 6) & 63;
  int stage_v_192_2 = ((pub_r001565_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001565_12_1 * 2) + 41) & 63;
  int stage_v_193_2 = ((pub_r001565_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_95_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_95_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((stage_v_29_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_29_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_98_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_98_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_62_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_62_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((sec_r001565_3_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_198_2 = ((sec_r001565_3_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_127_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_127_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((stage_v_20_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_20_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001565_11_1 * 2) + 19) & 63;
  int stage_v_201_2 = ((pub_r001565_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001565_12_1 * 2) + 48) & 63;
  int stage_v_202_2 = ((pub_r001565_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_29_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_29_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((pub_r001565_19_1 * 2) + 44) & 63;
  int stage_v_204_2 = ((pub_r001565_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001565_7_1 * 2) + 41) & 63;
  int stage_v_205_2 = ((pub_r001565_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((stage_v_10_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_206_2 = ((stage_v_10_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001565_19_1 * 2) + 36) & 63;
  int stage_v_207_2 = ((pub_r001565_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_49_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_49_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_104_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_104_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((stage_v_10_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_10_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_127_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_127_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((sec_r001565_3_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_212_2 = ((sec_r001565_3_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((stage_v_64_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_64_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_200_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_200_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001565_3_1 * 2) + 13) & 63;
  int stage_v_215_2 = ((pub_r001565_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001565_9_1 * 2) + 27) & 63;
  int stage_v_216_2 = ((pub_r001565_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_176_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_176_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((pub_r001565_9_1 * 2) + 21) & 63;
  int stage_v_218_2 = ((pub_r001565_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_115_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_115_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((stage_v_90_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_90_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_40_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_40_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((pub_r001565_15_1 * 2) + 8) & 63;
  int stage_v_222_2 = ((pub_r001565_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001565_1_1 * 2) + 17) & 63;
  int stage_v_223_2 = ((pub_r001565_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001565_19_1 * 2) + 47) & 63;
  int stage_v_224_2 = ((pub_r001565_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001565_14_1 * 2) + 20) & 63;
  int stage_v_225_2 = ((pub_r001565_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001565_12_1 * 2) + 6) & 63;
  int stage_v_226_2 = ((pub_r001565_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((sec_r001565_12_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_227_2 = ((sec_r001565_12_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((pub_r001565_8_1 * 2) + 14) & 63;
  int stage_v_228_2 = ((pub_r001565_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((stage_v_46_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_46_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((helper_flow_3_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_230_2 = ((helper_flow_3_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((stage_v_21_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_21_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((pub_r001565_18_1 * 2) + 42) & 63;
  int stage_v_232_2 = ((pub_r001565_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((sec_r001565_6_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_233_2 = ((sec_r001565_6_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((pub_r001565_1_1 * 2) + 21) & 63;
  int stage_v_234_2 = ((pub_r001565_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001565_12_1 * 2) + 10) & 63;
  int stage_v_235_2 = ((pub_r001565_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001565_9_1 * 2) + 33) & 63;
  int stage_v_236_2 = ((pub_r001565_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((stage_v_221_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_237_2 = ((stage_v_221_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((helper_flow_7_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_238_2 = ((helper_flow_7_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((pub_r001565_7_1 * 2) + 31) & 63;
  int stage_v_239_2 = ((pub_r001565_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_179_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_179_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((stage_v_219_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_219_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((stage_v_159_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_159_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((sec_r001565_5_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_243_2 = ((sec_r001565_5_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001565_15_1 * 2) + 35) & 63;
  int stage_v_244_2 = ((pub_r001565_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((helper_flow_8_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_245_2 = ((helper_flow_8_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001565_2_1 * 2) + 44) & 63;
  int stage_v_246_2 = ((pub_r001565_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001565_3_1 * 2) + 18) & 63;
  int stage_v_247_2 = ((pub_r001565_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((stage_v_52_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_52_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_62_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_62_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001565_1_1 * 2) + 47) & 63;
  int stage_v_250_2 = ((pub_r001565_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_96_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_96_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((pub_r001565_15_1 * 2) + 17) & 63;
  int stage_v_252_2 = ((pub_r001565_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_44_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_44_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001565_3_1 * 2) + 50) & 63;
  int stage_v_254_2 = ((pub_r001565_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((helper_flow_6_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_255_2 = ((helper_flow_6_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_33_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_33_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_49_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_49_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_103_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_103_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((stage_v_101_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_101_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001565_2_1 * 2) + 37) & 63;
  int stage_v_260_2 = ((pub_r001565_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001565_13_1 * 2) + 9) & 63;
  int stage_v_261_2 = ((pub_r001565_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001565_5_1 * 2) + 22) & 63;
  int stage_v_262_2 = ((pub_r001565_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((stage_v_120_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_120_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001565_17_1 * 2) + 20) & 63;
  int stage_v_264_2 = ((pub_r001565_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((helper_flow_7_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_265_2 = ((helper_flow_7_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001565_9_1 * 2) + 42) & 63;
  int stage_v_266_2 = ((pub_r001565_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001565_19_1 * 2) + 25) & 63;
  int stage_v_267_2 = ((pub_r001565_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((sec_r001565_0_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_268_2 = ((sec_r001565_0_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_268_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_268_2 + 1) & 15;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = ((helper_flow_4_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_269_2 = ((helper_flow_4_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((pub_r001565_4_1 * 2) + 20) & 63;
  int stage_v_270_2 = ((pub_r001565_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001565_17_1 * 2) + 9) & 63;
  int stage_v_271_2 = ((pub_r001565_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_24_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_24_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_144_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_144_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_98_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_98_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((pub_r001565_7_1 * 2) + 49) & 63;
  int stage_v_275_2 = ((pub_r001565_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((helper_flow_8_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_276_2 = ((helper_flow_8_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((pub_r001565_20_1 * 2) + 24) & 63;
  int stage_v_277_2 = ((pub_r001565_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001565_9_1 * 2) + 29) & 63;
  int stage_v_278_2 = ((pub_r001565_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001565_17_1 * 2) + 30) & 63;
  int stage_v_279_2 = ((pub_r001565_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((stage_v_71_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_71_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((stage_v_120_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_120_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((stage_v_19_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_19_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_253_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_253_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_16_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_16_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001565_0_1 * 2) + 24) & 63;
  int stage_v_285_2 = ((pub_r001565_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001565_13_1 * 2) + 26) & 63;
  int stage_v_286_2 = ((pub_r001565_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_24_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_24_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001565_1_1 * 2) + 48) & 63;
  int stage_v_288_2 = ((pub_r001565_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_114_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_114_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((sec_r001565_0_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_290_2 = ((sec_r001565_0_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001565_16_1 * 2) + 20) & 63;
  int stage_v_291_2 = ((pub_r001565_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((stage_v_210_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_210_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((stage_v_282_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_282_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((stage_v_256_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_256_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((pub_r001565_1_1 * 2) + 44) & 63;
  int stage_v_295_2 = ((pub_r001565_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((stage_v_130_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_130_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((sec_r001565_14_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_297_2 = ((sec_r001565_14_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((pub_r001565_6_1 * 2) + 31) & 63;
  int stage_v_298_2 = ((pub_r001565_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001565_9_1 * 2) + 42) & 63;
  int stage_v_299_2 = ((pub_r001565_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001565_6_1 * 2) + 35) & 63;
  int stage_v_300_2 = ((pub_r001565_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_109_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_109_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((pub_r001565_18_1 * 2) + 10) & 63;
  int stage_v_302_2 = ((pub_r001565_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((sec_r001565_7_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_303_2 = ((sec_r001565_7_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((stage_v_24_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_24_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((pub_r001565_15_1 * 2) + 7) & 63;
  int stage_v_305_2 = ((pub_r001565_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001565_17_1 * 2) + 19) & 63;
  int stage_v_306_2 = ((pub_r001565_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001565_12_1 * 2) + 22) & 63;
  int stage_v_307_2 = ((pub_r001565_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_65_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_65_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_91_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_91_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((pub_r001565_7_1 * 2) + 30) & 63;
  int stage_v_310_2 = ((pub_r001565_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((helper_flow_2_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_311_2 = ((helper_flow_2_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_114_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_114_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_292_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_292_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((stage_v_59_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_314_2 = ((stage_v_59_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_314_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_314_2 + 1) & 15;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = ((stage_v_88_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_88_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((stage_v_200_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_200_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((stage_v_179_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_179_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((sec_r001565_10_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_318_2 = ((sec_r001565_10_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((pub_r001565_5_1 * 2) + 19) & 63;
  int stage_v_319_2 = ((pub_r001565_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((helper_flow_5_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_320_2 = ((helper_flow_5_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001565_14_1 * 2) + 42) & 63;
  int stage_v_321_2 = ((pub_r001565_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001565_15_1 * 2) + 14) & 63;
  int stage_v_322_2 = ((pub_r001565_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001565_1_1 * 2) + 48) & 63;
  int stage_v_323_2 = ((pub_r001565_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((helper_flow_5_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_324_2 = ((helper_flow_5_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((pub_r001565_11_1 * 2) + 9) & 63;
  int stage_v_325_2 = ((pub_r001565_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001565_19_1 * 2) + 9) & 63;
  int stage_v_326_2 = ((pub_r001565_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((stage_v_195_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_195_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((pub_r001565_6_1 * 2) + 17) & 63;
  int stage_v_328_2 = ((pub_r001565_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((stage_v_101_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_101_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((stage_v_272_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_272_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_18_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_18_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((pub_r001565_7_1 * 2) + 17) & 63;
  int stage_v_332_2 = ((pub_r001565_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001565_1_1 * 2) + 22) & 63;
  int stage_v_333_2 = ((pub_r001565_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001565_9_1 * 2) + 28) & 63;
  int stage_v_334_2 = ((pub_r001565_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_220_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_220_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001565_9_1 * 2) + 32) & 63;
  int stage_v_336_2 = ((pub_r001565_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((stage_v_312_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_337_2 = ((stage_v_312_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((pub_r001565_15_1 * 2) + 28) & 63;
  int stage_v_338_2 = ((pub_r001565_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((stage_v_313_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_313_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((stage_v_194_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_194_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_21_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_21_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((pub_r001565_11_1 * 2) + 18) & 63;
  int stage_v_342_2 = ((pub_r001565_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((stage_v_309_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_309_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001565_19_1 * 2) + 35) & 63;
  int stage_v_344_2 = ((pub_r001565_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((stage_v_96_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_96_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((stage_v_317_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_317_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001565_19_1 * 2) + 27) & 63;
  int stage_v_347_2 = ((pub_r001565_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001565_18_1 * 2) + 15) & 63;
  int stage_v_348_2 = ((pub_r001565_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((stage_v_311_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_311_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((pub_r001565_8_1 * 2) + 29) & 63;
  int stage_v_350_2 = ((pub_r001565_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001565_5_1 * 2) + 6) & 63;
  int stage_v_351_2 = ((pub_r001565_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((stage_v_19_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_19_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((pub_r001565_16_1 * 2) + 50) & 63;
  int stage_v_353_2 = ((pub_r001565_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((sec_r001565_8_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_354_2 = ((sec_r001565_8_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((stage_v_131_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_131_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((pub_r001565_13_1 * 2) + 29) & 63;
  int stage_v_356_2 = ((pub_r001565_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((stage_v_212_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_212_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001565_17_1 * 2) + 17) & 63;
  int stage_v_358_2 = ((pub_r001565_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((stage_v_147_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_147_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((helper_flow_5_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_360_2 = ((helper_flow_5_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((stage_v_208_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_361_2 = ((stage_v_208_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_361_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_361_2 + 1) & 15;
  out_sink_1 ^= stage_v_361_1 & 63;
  out_sink_2 ^= stage_v_361_2 & 63;
  int stage_v_362_1 = ((stage_v_52_1 << 1) ^ (pub_r001565_12_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_52_2 << 1) ^ (pub_r001565_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((helper_flow_6_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_363_2 = ((helper_flow_6_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_176_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_176_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_18_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_18_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_317_1 << 1) ^ (pub_r001565_4_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_317_2 << 1) ^ (pub_r001565_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((helper_flow_3_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_367_2 = ((helper_flow_3_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((stage_v_10_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_10_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((stage_v_240_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_240_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((pub_r001565_18_1 * 2) + 30) & 63;
  int stage_v_370_2 = ((pub_r001565_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001565_17_1 * 2) + 49) & 63;
  int stage_v_371_2 = ((pub_r001565_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((stage_v_123_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_123_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((stage_v_283_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_283_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_292_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_292_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((stage_v_349_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_375_2 = ((stage_v_349_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((pub_r001565_13_1 * 2) + 28) & 63;
  int stage_v_376_2 = ((pub_r001565_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001565_3_1 * 2) + 46) & 63;
  int stage_v_377_2 = ((pub_r001565_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_11_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_11_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_77_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_77_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((pub_r001565_13_1 * 2) + 34) & 63;
  int stage_v_380_2 = ((pub_r001565_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001565_18_1 * 2) + 9) & 63;
  int stage_v_381_2 = ((pub_r001565_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001565_19_1 * 2) + 27) & 63;
  int stage_v_382_2 = ((pub_r001565_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001565_12_1 * 2) + 31) & 63;
  int stage_v_383_2 = ((pub_r001565_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001565_20_1 * 2) + 39) & 63;
  int stage_v_384_2 = ((pub_r001565_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((stage_v_203_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_203_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_230_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_230_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((stage_v_44_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_44_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001565_9_1 * 2) + 36) & 63;
  int stage_v_388_2 = ((pub_r001565_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001565_13_1 * 2) + 6) & 63;
  int stage_v_389_2 = ((pub_r001565_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((stage_v_8_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_390_2 = ((stage_v_8_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_390_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_390_2 + 1) & 15;
  out_sink_1 ^= stage_v_390_1 & 63;
  out_sink_2 ^= stage_v_390_2 & 63;
  int stage_v_391_1 = ((pub_r001565_3_1 * 2) + 11) & 63;
  int stage_v_391_2 = ((pub_r001565_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((stage_v_238_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_238_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((pub_r001565_12_1 * 2) + 20) & 63;
  int stage_v_393_2 = ((pub_r001565_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((stage_v_249_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_249_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001565_0_1 * 2) + 40) & 63;
  int stage_v_395_2 = ((pub_r001565_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001565_4_1 * 2) + 16) & 63;
  int stage_v_396_2 = ((pub_r001565_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((stage_v_131_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_131_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((stage_v_152_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_152_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((pub_r001565_20_1 * 2) + 48) & 63;
  int stage_v_399_2 = ((pub_r001565_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001565_14_1 * 2) + 28) & 63;
  int stage_v_400_2 = ((pub_r001565_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001565_18_1 * 2) + 18) & 63;
  int stage_v_401_2 = ((pub_r001565_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001565_20_1 * 2) + 23) & 63;
  int stage_v_402_2 = ((pub_r001565_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((stage_v_331_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_331_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_59_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_59_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001565_7_1 * 2) + 25) & 63;
  int stage_v_405_2 = ((pub_r001565_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_20_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_20_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((pub_r001565_20_1 * 2) + 44) & 63;
  int stage_v_407_2 = ((pub_r001565_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001565_20_1 * 2) + 10) & 63;
  int stage_v_408_2 = ((pub_r001565_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((stage_v_171_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_171_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((pub_r001565_9_1 * 2) + 39) & 63;
  int stage_v_410_2 = ((pub_r001565_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001565_15_1 * 2) + 37) & 63;
  int stage_v_411_2 = ((pub_r001565_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001565_19_1 * 2) + 41) & 63;
  int stage_v_412_2 = ((pub_r001565_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((stage_v_56_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_56_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((helper_flow_8_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_414_2 = ((helper_flow_8_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((pub_r001565_12_1 * 2) + 35) & 63;
  int stage_v_415_2 = ((pub_r001565_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001565_1_1 * 2) + 15) & 63;
  int stage_v_416_2 = ((pub_r001565_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((sec_r001565_2_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_417_2 = ((sec_r001565_2_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_417_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_417_2 + 1) & 15;
  out_sink_1 ^= stage_v_417_1 & 63;
  out_sink_2 ^= stage_v_417_2 & 63;
  int stage_v_418_1 = ((pub_r001565_20_1 * 2) + 47) & 63;
  int stage_v_418_2 = ((pub_r001565_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001565_16_1 * 2) + 47) & 63;
  int stage_v_419_2 = ((pub_r001565_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001565_12_1 * 2) + 39) & 63;
  int stage_v_420_2 = ((pub_r001565_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((stage_v_145_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_145_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((pub_r001565_7_1 * 2) + 17) & 63;
  int stage_v_422_2 = ((pub_r001565_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001565_15_1 * 2) + 35) & 63;
  int stage_v_423_2 = ((pub_r001565_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((stage_v_421_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_424_2 = ((stage_v_421_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_424_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_424_2 + 1) & 15;
  out_sink_1 ^= stage_v_424_1 & 63;
  out_sink_2 ^= stage_v_424_2 & 63;
  int stage_v_425_1 = ((pub_r001565_1_1 * 2) + 7) & 63;
  int stage_v_425_2 = ((pub_r001565_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((stage_v_54_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_54_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((pub_r001565_7_1 * 2) + 21) & 63;
  int stage_v_427_2 = ((pub_r001565_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((stage_v_301_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_428_2 = ((stage_v_301_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_428_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_428_2 + 1) & 15;
  out_sink_1 ^= stage_v_428_1 & 63;
  out_sink_2 ^= stage_v_428_2 & 63;
  int stage_v_429_1 = ((stage_v_233_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_233_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_104_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_104_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((stage_v_32_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_431_2 = ((stage_v_32_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((stage_v_253_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_432_2 = ((stage_v_253_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_432_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_432_2 + 1) & 15;
  out_sink_1 ^= stage_v_432_1 & 63;
  out_sink_2 ^= stage_v_432_2 & 63;
  int stage_v_433_1 = ((pub_r001565_9_1 * 2) + 29) & 63;
  int stage_v_433_2 = ((pub_r001565_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((stage_v_77_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_434_2 = ((stage_v_77_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_434_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_434_2 + 1) & 15;
  out_sink_1 ^= stage_v_434_1 & 63;
  out_sink_2 ^= stage_v_434_2 & 63;
  int stage_v_435_1 = ((pub_r001565_14_1 * 2) + 12) & 63;
  int stage_v_435_2 = ((pub_r001565_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001565_15_1 * 2) + 34) & 63;
  int stage_v_436_2 = ((pub_r001565_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001565_1_1 * 2) + 12) & 63;
  int stage_v_437_2 = ((pub_r001565_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001565_19_1 * 2) + 45) & 63;
  int stage_v_438_2 = ((pub_r001565_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((stage_v_314_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_439_2 = ((stage_v_314_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((pub_r001565_12_1 * 2) + 17) & 63;
  int stage_v_440_2 = ((pub_r001565_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001565_4_1 * 2) + 36) & 63;
  int stage_v_441_2 = ((pub_r001565_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001565_20_1 * 2) + 43) & 63;
  int stage_v_442_2 = ((pub_r001565_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001565_3_1 * 2) + 22) & 63;
  int stage_v_443_2 = ((pub_r001565_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001565_19_1 * 2) + 33) & 63;
  int stage_v_444_2 = ((pub_r001565_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001565_16_1 * 2) + 31) & 63;
  int stage_v_445_2 = ((pub_r001565_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001565_6_1 * 2) + 38) & 63;
  int stage_v_446_2 = ((pub_r001565_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((stage_v_361_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_447_2 = ((stage_v_361_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_447_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_447_2 + 1) & 15;
  out_sink_1 ^= stage_v_447_1 & 63;
  out_sink_2 ^= stage_v_447_2 & 63;
  int stage_v_448_1 = ((pub_r001565_2_1 * 2) + 18) & 63;
  int stage_v_448_2 = ((pub_r001565_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((stage_v_318_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_449_2 = ((stage_v_318_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_449_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_449_2 + 1) & 15;
  out_sink_1 ^= stage_v_449_1 & 63;
  out_sink_2 ^= stage_v_449_2 & 63;
  int stage_v_450_1 = ((stage_v_265_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_450_2 = ((stage_v_265_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_450_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_450_2 + 1) & 15;
  out_sink_1 ^= stage_v_450_1 & 63;
  out_sink_2 ^= stage_v_450_2 & 63;
  int stage_v_451_1 = ((sec_r001565_0_1 << 1) ^ (pub_r001565_16_1 >> 1)) & 127;
  int stage_v_451_2 = ((sec_r001565_0_2 << 1) ^ (pub_r001565_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_451_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_451_2 + 1) & 15;
  out_sink_1 ^= stage_v_451_1 & 63;
  out_sink_2 ^= stage_v_451_2 & 63;
  int stage_v_452_1 = ((pub_r001565_20_1 * 2) + 44) & 63;
  int stage_v_452_2 = ((pub_r001565_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((stage_v_428_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_453_2 = ((stage_v_428_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_453_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_453_2 + 1) & 15;
  out_sink_1 ^= stage_v_453_1 & 63;
  out_sink_2 ^= stage_v_453_2 & 63;
  int stage_v_454_1 = ((pub_r001565_1_1 * 2) + 34) & 63;
  int stage_v_454_2 = ((pub_r001565_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((stage_v_314_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_455_2 = ((stage_v_314_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_455_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_455_2 + 1) & 15;
  out_sink_1 ^= stage_v_455_1 & 63;
  out_sink_2 ^= stage_v_455_2 & 63;
  int stage_v_456_1 = ((stage_v_245_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_456_2 = ((stage_v_245_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_456_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_456_2 + 1) & 15;
  out_sink_1 ^= stage_v_456_1 & 63;
  out_sink_2 ^= stage_v_456_2 & 63;
  int stage_v_457_1 = ((stage_v_83_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_457_2 = ((stage_v_83_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_457_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_457_2 + 1) & 15;
  out_sink_1 ^= stage_v_457_1 & 63;
  out_sink_2 ^= stage_v_457_2 & 63;
  int stage_v_458_1 = ((pub_r001565_13_1 * 2) + 35) & 63;
  int stage_v_458_2 = ((pub_r001565_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001565_4_1 * 2) + 9) & 63;
  int stage_v_459_2 = ((pub_r001565_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001565_19_1 * 2) + 45) & 63;
  int stage_v_460_2 = ((pub_r001565_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001565_5_1 * 2) + 20) & 63;
  int stage_v_461_2 = ((pub_r001565_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((stage_v_313_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_462_2 = ((stage_v_313_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_462_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_462_2 + 1) & 15;
  out_sink_1 ^= stage_v_462_1 & 63;
  out_sink_2 ^= stage_v_462_2 & 63;
  int stage_v_463_1 = ((stage_v_122_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_463_2 = ((stage_v_122_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_463_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_463_2 + 1) & 15;
  out_sink_1 ^= stage_v_463_1 & 63;
  out_sink_2 ^= stage_v_463_2 & 63;
  int stage_v_464_1 = ((stage_v_430_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_464_2 = ((stage_v_430_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_464_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_464_2 + 1) & 15;
  out_sink_1 ^= stage_v_464_1 & 63;
  out_sink_2 ^= stage_v_464_2 & 63;
  int stage_v_465_1 = ((stage_v_367_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_465_2 = ((stage_v_367_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_465_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_465_2 + 1) & 15;
  out_sink_1 ^= stage_v_465_1 & 63;
  out_sink_2 ^= stage_v_465_2 & 63;
  int stage_v_466_1 = ((stage_v_354_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_466_2 = ((stage_v_354_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_466_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_466_2 + 1) & 15;
  out_sink_1 ^= stage_v_466_1 & 63;
  out_sink_2 ^= stage_v_466_2 & 63;
  int stage_v_467_1 = ((stage_v_177_1 << 1) ^ (pub_r001565_0_1 >> 1)) & 127;
  int stage_v_467_2 = ((stage_v_177_2 << 1) ^ (pub_r001565_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_467_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_467_2 + 1) & 15;
  out_sink_1 ^= stage_v_467_1 & 63;
  out_sink_2 ^= stage_v_467_2 & 63;
  int stage_v_468_1 = ((stage_v_465_1 << 1) ^ (pub_r001565_11_1 >> 1)) & 127;
  int stage_v_468_2 = ((stage_v_465_2 << 1) ^ (pub_r001565_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_468_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_468_2 + 1) & 15;
  out_sink_1 ^= stage_v_468_1 & 63;
  out_sink_2 ^= stage_v_468_2 & 63;
  int stage_v_469_1 = ((stage_v_385_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_469_2 = ((stage_v_385_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_469_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_469_2 + 1) & 15;
  out_sink_1 ^= stage_v_469_1 & 63;
  out_sink_2 ^= stage_v_469_2 & 63;
  int stage_v_470_1 = ((pub_r001565_1_1 * 2) + 13) & 63;
  int stage_v_470_2 = ((pub_r001565_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001565_11_1 * 2) + 40) & 63;
  int stage_v_471_2 = ((pub_r001565_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001565_2_1 * 2) + 30) & 63;
  int stage_v_472_2 = ((pub_r001565_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((stage_v_269_1 << 1) ^ (pub_r001565_15_1 >> 1)) & 127;
  int stage_v_473_2 = ((stage_v_269_2 << 1) ^ (pub_r001565_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_473_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_473_2 + 1) & 15;
  out_sink_1 ^= stage_v_473_1 & 63;
  out_sink_2 ^= stage_v_473_2 & 63;
  int stage_v_474_1 = ((pub_r001565_16_1 * 2) + 28) & 63;
  int stage_v_474_2 = ((pub_r001565_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((stage_v_91_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_475_2 = ((stage_v_91_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_475_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_475_2 + 1) & 15;
  out_sink_1 ^= stage_v_475_1 & 63;
  out_sink_2 ^= stage_v_475_2 & 63;
  int stage_v_476_1 = ((pub_r001565_10_1 * 2) + 41) & 63;
  int stage_v_476_2 = ((pub_r001565_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((stage_v_313_1 << 1) ^ (pub_r001565_3_1 >> 1)) & 127;
  int stage_v_477_2 = ((stage_v_313_2 << 1) ^ (pub_r001565_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_477_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_477_2 + 1) & 15;
  out_sink_1 ^= stage_v_477_1 & 63;
  out_sink_2 ^= stage_v_477_2 & 63;
  int stage_v_478_1 = ((pub_r001565_12_1 * 2) + 50) & 63;
  int stage_v_478_2 = ((pub_r001565_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001565_7_1 * 2) + 43) & 63;
  int stage_v_479_2 = ((pub_r001565_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001565_12_1 * 2) + 5) & 63;
  int stage_v_480_2 = ((pub_r001565_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((stage_v_257_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_481_2 = ((stage_v_257_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_481_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_481_2 + 1) & 15;
  out_sink_1 ^= stage_v_481_1 & 63;
  out_sink_2 ^= stage_v_481_2 & 63;
  int stage_v_482_1 = ((pub_r001565_5_1 * 2) + 50) & 63;
  int stage_v_482_2 = ((pub_r001565_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((stage_v_355_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_483_2 = ((stage_v_355_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_483_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_483_2 + 1) & 15;
  out_sink_1 ^= stage_v_483_1 & 63;
  out_sink_2 ^= stage_v_483_2 & 63;
  int stage_v_484_1 = ((sec_r001565_9_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_484_2 = ((sec_r001565_9_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_484_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_484_2 + 1) & 15;
  out_sink_1 ^= stage_v_484_1 & 63;
  out_sink_2 ^= stage_v_484_2 & 63;
  int stage_v_485_1 = ((stage_v_481_1 << 1) ^ (pub_r001565_19_1 >> 1)) & 127;
  int stage_v_485_2 = ((stage_v_481_2 << 1) ^ (pub_r001565_19_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_485_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_485_2 + 1) & 15;
  out_sink_1 ^= stage_v_485_1 & 63;
  out_sink_2 ^= stage_v_485_2 & 63;
  int stage_v_486_1 = ((stage_v_33_1 << 1) ^ (pub_r001565_20_1 >> 1)) & 127;
  int stage_v_486_2 = ((stage_v_33_2 << 1) ^ (pub_r001565_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_486_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_486_2 + 1) & 15;
  out_sink_1 ^= stage_v_486_1 & 63;
  out_sink_2 ^= stage_v_486_2 & 63;
  int stage_v_487_1 = ((stage_v_354_1 << 1) ^ (pub_r001565_17_1 >> 1)) & 127;
  int stage_v_487_2 = ((stage_v_354_2 << 1) ^ (pub_r001565_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_487_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_487_2 + 1) & 15;
  out_sink_1 ^= stage_v_487_1 & 63;
  out_sink_2 ^= stage_v_487_2 & 63;
  int stage_v_488_1 = ((pub_r001565_1_1 * 2) + 20) & 63;
  int stage_v_488_2 = ((pub_r001565_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((stage_v_79_1 << 1) ^ (pub_r001565_7_1 >> 1)) & 127;
  int stage_v_489_2 = ((stage_v_79_2 << 1) ^ (pub_r001565_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_489_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_489_2 + 1) & 15;
  out_sink_1 ^= stage_v_489_1 & 63;
  out_sink_2 ^= stage_v_489_2 & 63;
  int stage_v_490_1 = ((pub_r001565_20_1 * 2) + 28) & 63;
  int stage_v_490_2 = ((pub_r001565_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001565_2_1 * 2) + 48) & 63;
  int stage_v_491_2 = ((pub_r001565_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((stage_v_296_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_492_2 = ((stage_v_296_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_492_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_492_2 + 1) & 15;
  out_sink_1 ^= stage_v_492_1 & 63;
  out_sink_2 ^= stage_v_492_2 & 63;
  int stage_v_493_1 = ((stage_v_203_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_493_2 = ((stage_v_203_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_493_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_493_2 + 1) & 15;
  out_sink_1 ^= stage_v_493_1 & 63;
  out_sink_2 ^= stage_v_493_2 & 63;
  int stage_v_494_1 = ((stage_v_97_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_494_2 = ((stage_v_97_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_494_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_494_2 + 1) & 15;
  out_sink_1 ^= stage_v_494_1 & 63;
  out_sink_2 ^= stage_v_494_2 & 63;
  int stage_v_495_1 = ((pub_r001565_11_1 * 2) + 10) & 63;
  int stage_v_495_2 = ((pub_r001565_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = ((stage_v_243_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_496_2 = ((stage_v_243_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_496_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_496_2 + 1) & 15;
  out_sink_1 ^= stage_v_496_1 & 63;
  out_sink_2 ^= stage_v_496_2 & 63;
  int stage_v_497_1 = ((pub_r001565_3_1 * 2) + 10) & 63;
  int stage_v_497_2 = ((pub_r001565_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((pub_r001565_7_1 * 2) + 26) & 63;
  int stage_v_498_2 = ((pub_r001565_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = ((stage_v_451_1 << 1) ^ (pub_r001565_5_1 >> 1)) & 127;
  int stage_v_499_2 = ((stage_v_451_2 << 1) ^ (pub_r001565_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_499_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_499_2 + 1) & 15;
  out_sink_1 ^= stage_v_499_1 & 63;
  out_sink_2 ^= stage_v_499_2 & 63;
  int stage_v_500_1 = ((stage_v_23_1 << 1) ^ (pub_r001565_2_1 >> 1)) & 127;
  int stage_v_500_2 = ((stage_v_23_2 << 1) ^ (pub_r001565_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_500_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_500_2 + 1) & 15;
  out_sink_1 ^= stage_v_500_1 & 63;
  out_sink_2 ^= stage_v_500_2 & 63;
  int stage_v_501_1 = ((sec_r001565_14_1 << 1) ^ (pub_r001565_6_1 >> 1)) & 127;
  int stage_v_501_2 = ((sec_r001565_14_2 << 1) ^ (pub_r001565_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_501_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_501_2 + 1) & 15;
  out_sink_1 ^= stage_v_501_1 & 63;
  out_sink_2 ^= stage_v_501_2 & 63;
  int stage_v_502_1 = ((stage_v_467_1 << 1) ^ (pub_r001565_14_1 >> 1)) & 127;
  int stage_v_502_2 = ((stage_v_467_2 << 1) ^ (pub_r001565_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_502_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_502_2 + 1) & 15;
  out_sink_1 ^= stage_v_502_1 & 63;
  out_sink_2 ^= stage_v_502_2 & 63;
  int stage_v_503_1 = ((pub_r001565_14_1 * 2) + 10) & 63;
  int stage_v_503_2 = ((pub_r001565_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = ((pub_r001565_1_1 * 2) + 32) & 63;
  int stage_v_504_2 = ((pub_r001565_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = ((pub_r001565_9_1 * 2) + 23) & 63;
  int stage_v_505_2 = ((pub_r001565_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_505_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_505_2) & 127;
  int stage_v_506_1 = ((pub_r001565_17_1 * 2) + 39) & 63;
  int stage_v_506_2 = ((pub_r001565_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_506_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_506_2) & 127;
  int stage_v_507_1 = ((pub_r001565_5_1 * 2) + 24) & 63;
  int stage_v_507_2 = ((pub_r001565_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_507_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_507_2) & 127;
  int stage_v_508_1 = ((stage_v_280_1 << 1) ^ (pub_r001565_9_1 >> 1)) & 127;
  int stage_v_508_2 = ((stage_v_280_2 << 1) ^ (pub_r001565_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_508_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_508_2 + 1) & 15;
  out_sink_1 ^= stage_v_508_1 & 63;
  out_sink_2 ^= stage_v_508_2 & 63;
  int stage_v_509_1 = ((stage_v_429_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_509_2 = ((stage_v_429_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_509_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_509_2 + 1) & 15;
  out_sink_1 ^= stage_v_509_1 & 63;
  out_sink_2 ^= stage_v_509_2 & 63;
  int stage_v_510_1 = ((stage_v_103_1 << 1) ^ (pub_r001565_13_1 >> 1)) & 127;
  int stage_v_510_2 = ((stage_v_103_2 << 1) ^ (pub_r001565_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_510_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_510_2 + 1) & 15;
  out_sink_1 ^= stage_v_510_1 & 63;
  out_sink_2 ^= stage_v_510_2 & 63;
  int stage_v_511_1 = ((pub_r001565_5_1 * 2) + 20) & 63;
  int stage_v_511_2 = ((pub_r001565_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((stage_v_214_1 << 1) ^ (pub_r001565_18_1 >> 1)) & 127;
  int stage_v_512_2 = ((stage_v_214_2 << 1) ^ (pub_r001565_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_512_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_512_2 + 1) & 15;
  out_sink_1 ^= stage_v_512_1 & 63;
  out_sink_2 ^= stage_v_512_2 & 63;
  int stage_v_513_1 = ((pub_r001565_19_1 * 2) + 21) & 63;
  int stage_v_513_2 = ((pub_r001565_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_513_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_513_2) & 127;
  int stage_v_514_1 = ((stage_v_251_1 << 1) ^ (pub_r001565_8_1 >> 1)) & 127;
  int stage_v_514_2 = ((stage_v_251_2 << 1) ^ (pub_r001565_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_514_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_514_2 + 1) & 15;
  out_sink_1 ^= stage_v_514_1 & 63;
  out_sink_2 ^= stage_v_514_2 & 63;
  int stage_v_515_1 = ((stage_v_209_1 << 1) ^ (pub_r001565_10_1 >> 1)) & 127;
  int stage_v_515_2 = ((stage_v_209_2 << 1) ^ (pub_r001565_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_515_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_515_2 + 1) & 15;
  out_sink_1 ^= stage_v_515_1 & 63;
  out_sink_2 ^= stage_v_515_2 & 63;
  int stage_v_516_1 = ((pub_r001565_8_1 * 2) + 21) & 63;
  int stage_v_516_2 = ((pub_r001565_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_516_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_516_2) & 127;
  int stage_v_517_1 = ((stage_v_155_1 << 1) ^ (pub_r001565_1_1 >> 1)) & 127;
  int stage_v_517_2 = ((stage_v_155_2 << 1) ^ (pub_r001565_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_517_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_517_2 + 1) & 15;
  out_sink_1 ^= stage_v_517_1 & 63;
  out_sink_2 ^= stage_v_517_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001565_0_1 != sec_r001565_0_2);
  __CPROVER_assume(pub_r001565_12_1 == pub_r001565_12_2);
  __CPROVER_assume(pub_r001565_16_1 == pub_r001565_16_2);
  __CPROVER_assume(pub_r001565_10_1 == pub_r001565_10_2);
  __CPROVER_assume(sec_r001565_13_1 != sec_r001565_13_2);
  __CPROVER_assume(sec_r001565_10_1 != sec_r001565_10_2);
  __CPROVER_assume(sec_r001565_4_1 != sec_r001565_4_2);
  __CPROVER_assume(pub_r001565_5_1 == pub_r001565_5_2);
  __CPROVER_assume(sec_r001565_14_1 != sec_r001565_14_2);
  __CPROVER_assume(pub_r001565_13_1 == pub_r001565_13_2);
  __CPROVER_assume(pub_r001565_0_1 == pub_r001565_0_2);
  __CPROVER_assume(pub_r001565_11_1 == pub_r001565_11_2);
  __CPROVER_assume(sec_r001565_7_1 != sec_r001565_7_2);
  __CPROVER_assume(pub_r001565_8_1 == pub_r001565_8_2);
  __CPROVER_assume(pub_r001565_7_1 == pub_r001565_7_2);
  __CPROVER_assume(pub_r001565_9_1 == pub_r001565_9_2);
  __CPROVER_assume(sec_r001565_9_1 != sec_r001565_9_2);
  __CPROVER_assume(sec_r001565_11_1 != sec_r001565_11_2);
  __CPROVER_assume(pub_r001565_15_1 == pub_r001565_15_2);
  __CPROVER_assume(pub_r001565_1_1 == pub_r001565_1_2);
  __CPROVER_assume(pub_r001565_2_1 == pub_r001565_2_2);
  __CPROVER_assume(pub_r001565_3_1 == pub_r001565_3_2);
  __CPROVER_assume(sec_r001565_15_1 != sec_r001565_15_2);
  __CPROVER_assume(pub_r001565_19_1 == pub_r001565_19_2);
  __CPROVER_assume(sec_r001565_5_1 != sec_r001565_5_2);
  __CPROVER_assume(pub_r001565_20_1 == pub_r001565_20_2);
  __CPROVER_assume(sec_r001565_2_1 != sec_r001565_2_2);
  __CPROVER_assume(sec_r001565_6_1 != sec_r001565_6_2);
  __CPROVER_assume(pub_r001565_14_1 == pub_r001565_14_2);
  __CPROVER_assume(pub_r001565_17_1 == pub_r001565_17_2);
  __CPROVER_assume(sec_r001565_8_1 != sec_r001565_8_2);
  __CPROVER_assume(pub_r001565_4_1 == pub_r001565_4_2);
  __CPROVER_assume(sec_r001565_1_1 != sec_r001565_1_2);
  __CPROVER_assume(pub_r001565_6_1 == pub_r001565_6_2);
  __CPROVER_assume(sec_r001565_12_1 != sec_r001565_12_2);
  __CPROVER_assume(sec_r001565_3_1 != sec_r001565_3_2);
  __CPROVER_assume(pub_r001565_18_1 == pub_r001565_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
  assert(stage_v_510_1 == stage_v_510_2);
  assert(stage_v_511_1 == stage_v_511_2);
  assert(stage_v_512_1 == stage_v_512_2);
  assert(stage_v_513_1 == stage_v_513_2);
  assert(stage_v_514_1 == stage_v_514_2);
  assert(stage_v_515_1 == stage_v_515_2);
  assert(stage_v_516_1 == stage_v_516_2);
  assert(stage_v_517_1 == stage_v_517_2);
}


