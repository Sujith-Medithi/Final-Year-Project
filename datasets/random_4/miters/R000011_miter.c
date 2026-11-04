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
struct Vector3D_R000011_1113_0
{
  int norm_sq;
  int coord_z;
  int heading;
  int buffer[3];
};
struct EventLog_R000011_1113_1
{
  unsigned char severity;
  int signature;
  unsigned char timestamp;
  int facility;
  int buffer[3];
};
struct StreamBuffer_R000011_1113_2
{
  int checksum;
  short head;
  short tail;
  int state;
  int buffer[3];
};
union ColorPixel_R000011_1113_0
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
void fn_R000011_1113_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int anchor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_42_1 > 13)
  {
    acc_1 = ((acc_1 + (anchor_42_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_42_2 > 13)
  {
    acc_2 = ((acc_2 + (anchor_42_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_51_1)
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

  switch (tally_51_2)
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

  int accumulator_84_1 = 0;
  int accumulator_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_84_1 = ((accumulator_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_84_2 = ((accumulator_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_84_1) & 127;
    acc_2 = (acc_2 + accumulator_84_2) & 127;
  }

  int coefficient_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_39_1) & 63;
  aux_2 = (aux_2 + coefficient_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_42_1 == anchor_42_2);
  assert(tally_51_1 == tally_51_2);
  assert(accumulator_84_1 == accumulator_84_2);
  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R000011_1113_0(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int anchor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_42 > 13)
  {
    acc = ((acc + (anchor_42 * 2)) + 5) & 127;
    aux ^= anchor_42 & 15;
  }
  else
  {
    acc = ((acc - anchor_42) + 11) & 127;
    aux += 3;
  }
  int tally_51 = (aux + st.buffer[1]) & 3;
  switch (tally_51)
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

  int accumulator_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_84 = ((accumulator_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_84) & 127;
  }

  int coefficient_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int checksum_27_1 = 0;
  int checksum_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_27_1 = ((checksum_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_27_2 = ((checksum_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_27_1) & 127;
    acc_2 = (acc_2 + checksum_27_2) & 127;
  }

  int residue_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_82_1) & 63;
  aux_2 = (aux_2 + residue_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_27_1 == checksum_27_2);
  assert(residue_82_1 == residue_82_2);
}

int fn_R000011_1113_1(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int checksum_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_27 = ((checksum_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_27) & 127;
  }

  int residue_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_43_1 > 40)
  {
    acc_1 = ((acc_1 + (vector_43_1 * 2)) + 5) & 127;
    aux_1 ^= vector_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_43_2 > 40)
  {
    acc_2 = ((acc_2 + (vector_43_2 * 2)) + 5) & 127;
    aux_2 ^= vector_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_18_1 = 0;
  int tracker_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_18_1 = ((tracker_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_18_2 = ((tracker_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_18_1) & 127;
    acc_2 = (acc_2 + tracker_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_43_1 == vector_43_2);
  assert(tracker_18_1 == tracker_18_2);
}

int fn_R000011_1113_2(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_43 > 40)
  {
    acc = ((acc + (vector_43 * 2)) + 5) & 127;
    aux ^= vector_43 & 15;
  }
  else
  {
    acc = ((acc - vector_43) + 11) & 127;
    aux += 3;
  }
  int tracker_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_18 = ((tracker_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_60_1 = local_arr_1[aux_1 % 3];
  int scale_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_60_2 * 2)) & 127;
  int weight_50_1 = 0;
  int weight_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_50_1 = ((weight_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_50_2 = ((weight_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_50_1) & 127;
    acc_2 = (acc_2 + weight_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_60_1 == scale_60_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R000011_1113_3(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int scale_60 = local_arr[aux % 3];
  acc = (acc + (scale_60 * 2)) & 127;
  int weight_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_50 = ((weight_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int sample_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_88_1) & 63;
  aux_2 = (aux_2 + sample_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_20_1)
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

  switch (checksum_20_2)
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
  int vector_53_1 = local_arr_1[aux_1 % 3];
  int vector_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_88_1 == sample_88_2);
  assert(checksum_20_1 == checksum_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_53_1 == vector_53_2);
}

int fn_R000011_1113_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int sample_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_88) & 63;
  acc ^= aux;
  int checksum_20 = (aux + st.buffer[1]) & 3;
  switch (checksum_20)
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
  int vector_53 = local_arr[aux % 3];
  acc = (acc + (vector_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000011_1113_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_27_1)
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

  switch (cursor_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_83_1 = 0;
  int accumulator_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_83_1 = ((accumulator_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_83_2 = ((accumulator_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_83_1) & 127;
    acc_2 = (acc_2 + accumulator_83_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_27_1 == cursor_27_2);
  assert(accumulator_83_1 == accumulator_83_2);
}

int fn_R000011_1113_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_27 = (aux + st.buffer[1]) & 3;
  switch (cursor_27)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_83 = ((accumulator_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_83) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_69_1 = local_arr_1[aux_1 % 3];
  int margin_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_69_2 * 2)) & 127;
  int damping_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_51_1) & 63;
  aux_2 = (aux_2 + damping_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_69_1 == margin_69_2);
  assert(damping_51_1 == damping_51_2);
}

int fn_R000011_1113_6(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int margin_69 = local_arr[aux % 3];
  acc = (acc + (margin_69 * 2)) & 127;
  int damping_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_51) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000011_1113_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_43_1 = 0;
  int quantum_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_43_1 = ((quantum_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_43_2 = ((quantum_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_43_1) & 127;
    acc_2 = (acc_2 + quantum_43_2) & 127;
  }

  int anchor_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_95_1) & 63;
  aux_2 = (aux_2 + anchor_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_31_1 = local_arr_1[aux_1 % 3];
  int delta_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_31_2 * 2)) & 127;
  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 11)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 11)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_43_1 == quantum_43_2);
  assert(anchor_95_1 == anchor_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_31_1 == delta_31_2);
  assert(residue_99_1 == residue_99_2);
}

int fn_R000011_1113_7(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_43 = ((quantum_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_43) & 127;
  }

  int anchor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_31 = local_arr[aux % 3];
  acc = (acc + (delta_31 * 2)) & 127;
  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 11)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000011_1113_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_52_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_52_1 * 2)) + 5) & 127;
    aux_1 ^= factor_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_52_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_52_2 * 2)) + 5) & 127;
    aux_2 ^= factor_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_50_1)
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

  switch (pivot_50_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_52_1 == factor_52_2);
  assert(pivot_50_1 == pivot_50_2);
}

int fn_R000011_1113_8(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_52 > 48)
  {
    acc = ((acc + (factor_52 * 2)) + 5) & 127;
    aux ^= factor_52 & 15;
  }
  else
  {
    acc = ((acc - factor_52) + 11) & 127;
    aux += 3;
  }
  int pivot_50 = (aux + st.buffer[1]) & 3;
  switch (pivot_50)
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

void fn_R000011_1113_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_91_1)
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

  switch (index_reg_91_2)
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
  int residue_94_1 = local_arr_1[aux_1 % 3];
  int residue_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_94_2 * 2)) & 127;
  int bound_42_1 = 0;
  int bound_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_42_1 = ((bound_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_42_2 = ((bound_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_42_1) & 127;
    acc_2 = (acc_2 + bound_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_91_1 == index_reg_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_94_1 == residue_94_2);
  assert(bound_42_1 == bound_42_2);
}

int fn_R000011_1113_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_91 = (aux + st.buffer[1]) & 3;
  switch (index_reg_91)
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
  int residue_94 = local_arr[aux % 3];
  acc = (acc + (residue_94 * 2)) & 127;
  int bound_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_42 = ((bound_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int phase_68_1 = 0;
  int phase_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_68_1 = ((phase_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_68_2 = ((phase_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_68_1) & 127;
    acc_2 = (acc_2 + phase_68_2) & 127;
  }

  int bound_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_81_1) & 63;
  aux_2 = (aux_2 + bound_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_68_1 == phase_68_2);
  assert(bound_81_1 == bound_81_2);
}

int fn_R000011_1113_10(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int phase_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_68 = ((phase_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_68) & 127;
  }

  int bound_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_82_1 = 0;
  int weight_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_82_1 = ((weight_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_82_2 = ((weight_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_82_1) & 127;
    acc_2 = (acc_2 + weight_82_2) & 127;
  }

  int offset_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_39_1) & 63;
  aux_2 = (aux_2 + offset_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_82_1 == weight_82_2);
  assert(offset_39_1 == offset_39_2);
}

int fn_R000011_1113_11(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_82 = ((weight_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_82) & 127;
  }

  int offset_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_74_1 > 42)
  {
    acc_1 = ((acc_1 + (stride_74_1 * 2)) + 5) & 127;
    aux_1 ^= stride_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_74_2 > 42)
  {
    acc_2 = ((acc_2 + (stride_74_2 * 2)) + 5) & 127;
    aux_2 ^= stride_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_25_1 = local_arr_1[aux_1 % 3];
  int threshold_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_74_1 == stride_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_25_1 == threshold_25_2);
}

int fn_R000011_1113_12(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_74 > 42)
  {
    acc = ((acc + (stride_74 * 2)) + 5) & 127;
    aux ^= stride_74 & 15;
  }
  else
  {
    acc = ((acc - stride_74) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_25 = local_arr[aux % 3];
  acc = (acc + (threshold_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000011_1113_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_10_1 = 0;
  int metric_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_10_1 = ((metric_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_10_2 = ((metric_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_10_1) & 127;
    acc_2 = (acc_2 + metric_10_2) & 127;
  }

  int accumulator_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_95_1) & 63;
  aux_2 = (aux_2 + accumulator_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_45_1)
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

  switch (phase_45_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_10_1 == metric_10_2);
  assert(accumulator_95_1 == accumulator_95_2);
  assert(phase_45_1 == phase_45_2);
}

int fn_R000011_1113_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_10 = ((metric_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_10) & 127;
  }

  int accumulator_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_95) & 63;
  acc ^= aux;
  int phase_45 = (aux + st.buffer[1]) & 3;
  switch (phase_45)
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

void fn_R000011_1113_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_66_1 = local_arr_1[aux_1 % 3];
  int mask_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_66_2 * 2)) & 127;
  int accumulator_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_92_1 > 43)
  {
    acc_1 = ((acc_1 + (accumulator_92_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_92_2 > 43)
  {
    acc_2 = ((acc_2 + (accumulator_92_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_93_1 = 0;
  int tracker_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_93_1 = ((tracker_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_93_2 = ((tracker_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_93_1) & 127;
    acc_2 = (acc_2 + tracker_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_66_1 == mask_66_2);
  assert(accumulator_92_1 == accumulator_92_2);
  assert(tracker_93_1 == tracker_93_2);
}

int fn_R000011_1113_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int mask_66 = local_arr[aux % 3];
  acc = (acc + (mask_66 * 2)) & 127;
  int accumulator_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_92 > 43)
  {
    acc = ((acc + (accumulator_92 * 2)) + 5) & 127;
    aux ^= accumulator_92 & 15;
  }
  else
  {
    acc = ((acc - accumulator_92) + 11) & 127;
    aux += 3;
  }
  int tracker_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_93 = ((tracker_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_93_1 > 24)
  {
    acc_1 = ((acc_1 + (quotient_93_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_93_2 > 24)
  {
    acc_2 = ((acc_2 + (quotient_93_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_86_1) & 63;
  aux_2 = (aux_2 + tracker_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_93_1 == quotient_93_2);
  assert(tracker_86_1 == tracker_86_2);
}

int fn_R000011_1113_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_93 > 24)
  {
    acc = ((acc + (quotient_93 * 2)) + 5) & 127;
    aux ^= quotient_93 & 15;
  }
  else
  {
    acc = ((acc - quotient_93) + 11) & 127;
    aux += 3;
  }
  int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_51_1 = 0;
  int margin_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_51_1 = ((margin_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_51_2 = ((margin_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_51_1) & 127;
    acc_2 = (acc_2 + margin_51_2) & 127;
  }

  int anchor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_57_1)
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

  switch (anchor_57_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_51_1 == margin_51_2);
  assert(anchor_57_1 == anchor_57_2);
}

int fn_R000011_1113_16(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_51 = ((margin_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_51) & 127;
  }

  int anchor_57 = (aux + st.buffer[1]) & 3;
  switch (anchor_57)
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

void fn_R000011_1113_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_45_1 = local_arr_1[aux_1 % 3];
  int vector_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_45_2 * 2)) & 127;
  int tally_77_1 = 0;
  int tally_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_77_1 = ((tally_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_77_2 = ((tally_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_77_1) & 127;
    acc_2 = (acc_2 + tally_77_2) & 127;
  }

  int margin_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_86_1 > 25)
  {
    acc_1 = ((acc_1 + (margin_86_1 * 2)) + 5) & 127;
    aux_1 ^= margin_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_86_2 > 25)
  {
    acc_2 = ((acc_2 + (margin_86_2 * 2)) + 5) & 127;
    aux_2 ^= margin_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_45_1 == vector_45_2);
  assert(tally_77_1 == tally_77_2);
  assert(margin_86_1 == margin_86_2);
}

int fn_R000011_1113_17(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int vector_45 = local_arr[aux % 3];
  acc = (acc + (vector_45 * 2)) & 127;
  int tally_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_77 = ((tally_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_77) & 127;
  }

  int margin_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_86 > 25)
  {
    acc = ((acc + (margin_86 * 2)) + 5) & 127;
    aux ^= margin_86 & 15;
  }
  else
  {
    acc = ((acc - margin_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000011_1113_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
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
  int quantum_71_1 = 0;
  int quantum_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_71_1 = ((quantum_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_71_2 = ((quantum_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_71_1) & 127;
    acc_2 = (acc_2 + quantum_71_2) & 127;
  }

  int bound_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_74_1 > 39)
  {
    acc_1 = ((acc_1 + (bound_74_1 * 2)) + 5) & 127;
    aux_1 ^= bound_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_74_2 > 39)
  {
    acc_2 = ((acc_2 + (bound_74_2 * 2)) + 5) & 127;
    aux_2 ^= bound_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_30_1)
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

  switch (stride_30_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_71_1 == quantum_71_2);
  assert(bound_74_1 == bound_74_2);
  assert(stride_30_1 == stride_30_2);
}

int fn_R000011_1113_18(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_71 = ((quantum_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_71) & 127;
  }

  int bound_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_74 > 39)
  {
    acc = ((acc + (bound_74 * 2)) + 5) & 127;
    aux ^= bound_74 & 15;
  }
  else
  {
    acc = ((acc - bound_74) + 11) & 127;
    aux += 3;
  }
  int stride_30 = (aux + st.buffer[1]) & 3;
  switch (stride_30)
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

  return (acc + aux) & 255;
}

void fn_R000011_1113_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_29_1 = local_arr_1[aux_1 % 3];
  int metric_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_29_2 * 2)) & 127;
  int checksum_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_85_1) & 63;
  aux_2 = (aux_2 + checksum_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_29_1 == metric_29_2);
  assert(checksum_85_1 == checksum_85_2);
}

int fn_R000011_1113_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int metric_29 = local_arr[aux % 3];
  acc = (acc + (metric_29 * 2)) & 127;
  int checksum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000011_1113_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int window_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_74_1)
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

  switch (window_74_2)
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
  int metric_26_1 = local_arr_1[aux_1 % 3];
  int metric_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_26_2 * 2)) & 127;
  int mask_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_76_1) & 63;
  aux_2 = (aux_2 + mask_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_82_1 = 0;
  int window_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_82_1 = ((window_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_82_2 = ((window_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_82_1) & 127;
    acc_2 = (acc_2 + window_82_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_74_1 == window_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_26_1 == metric_26_2);
  assert(mask_76_1 == mask_76_2);
  assert(window_82_1 == window_82_2);
}

int fn_R000011_1113_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int window_74 = (aux + st.buffer[1]) & 3;
  switch (window_74)
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
  int metric_26 = local_arr[aux % 3];
  acc = (acc + (metric_26 * 2)) & 127;
  int mask_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_76) & 63;
  acc ^= aux;
  int window_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_82 = ((window_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_82) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int offset_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_37_1)
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

  switch (offset_37_2)
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

  int cursor_48_1 = 0;
  int cursor_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_48_1 = ((cursor_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_48_2 = ((cursor_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_48_1) & 127;
    acc_2 = (acc_2 + cursor_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_37_1 == offset_37_2);
  assert(cursor_48_1 == cursor_48_2);
}

int fn_R000011_1113_21(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000011_1113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int offset_37 = (aux + st.buffer[1]) & 3;
  switch (offset_37)
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

  int cursor_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_48 = ((cursor_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000011_1113_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st_1 = {0};
  struct EventLog_R000011_1113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int residue_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_89_1) & 63;
  aux_2 = (aux_2 + residue_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_75_1)
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

  switch (factor_75_2)
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

  int mask_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_67_1 > 44)
  {
    acc_1 = ((acc_1 + (mask_67_1 * 2)) + 5) & 127;
    aux_1 ^= mask_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_67_2 > 44)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_89_1 == residue_89_2);
  assert(factor_75_1 == factor_75_2);
  assert(mask_67_1 == mask_67_2);
}

int fn_R000011_1113_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000011_1113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int residue_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_89) & 63;
  acc ^= aux;
  int factor_75 = (aux + st.buffer[1]) & 3;
  switch (factor_75)
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

  int mask_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_67 > 44)
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

void fn_R000011_1113_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int weight_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_80_1)
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

  switch (weight_80_2)
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
  int quotient_47_1 = local_arr_1[aux_1 % 3];
  int quotient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_80_1 == weight_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_47_1 == quotient_47_2);
}

int fn_R000011_1113_23(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int weight_80 = (aux + st.buffer[1]) & 3;
  switch (weight_80)
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
  int quotient_47 = local_arr[aux % 3];
  acc = (acc + (quotient_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000011_1113_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st_1 = {0};
  struct Vector3D_R000011_1113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_38_1 = local_arr_1[aux_1 % 3];
  int bound_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_38_2 * 2)) & 127;
  int phase_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_65_1) & 63;
  aux_2 = (aux_2 + phase_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_90_1)
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

  switch (margin_90_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_38_1 == bound_38_2);
  assert(phase_65_1 == phase_65_2);
  assert(margin_90_1 == margin_90_2);
}

int fn_R000011_1113_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000011_1113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_38 = local_arr[aux % 3];
  acc = (acc + (bound_38 * 2)) & 127;
  int phase_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_65) & 63;
  acc ^= aux;
  int margin_90 = (aux + st.buffer[1]) & 3;
  switch (margin_90)
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
  int sec_r000011_0_1;
  int sec_r000011_0_2;
  int sec_r000011_1_1;
  int sec_r000011_1_2;
  int sec_r000011_2_1;
  int sec_r000011_2_2;
  int sec_r000011_3_1;
  int sec_r000011_3_2;
  int sec_r000011_4_1;
  int sec_r000011_4_2;
  int sec_r000011_5_1;
  int sec_r000011_5_2;
  int sec_r000011_6_1;
  int sec_r000011_6_2;
  int sec_r000011_7_1;
  int sec_r000011_7_2;
  int sec_r000011_8_1;
  int sec_r000011_8_2;
  int sec_r000011_9_1;
  int sec_r000011_9_2;
  int sec_r000011_10_1;
  int sec_r000011_10_2;
  int sec_r000011_11_1;
  int sec_r000011_11_2;
  int sec_r000011_12_1;
  int sec_r000011_12_2;
  int sec_r000011_13_1;
  int sec_r000011_13_2;
  int sec_r000011_14_1;
  int sec_r000011_14_2;
  int sec_r000011_15_1;
  int sec_r000011_15_2;
  int sec_r000011_16_1;
  int sec_r000011_16_2;
  int pub_r000011_0_1;
  int pub_r000011_0_2;
  int pub_r000011_1_1;
  int pub_r000011_1_2;
  int pub_r000011_2_1;
  int pub_r000011_2_2;
  int pub_r000011_3_1;
  int pub_r000011_3_2;
  int pub_r000011_4_1;
  int pub_r000011_4_2;
  int pub_r000011_5_1;
  int pub_r000011_5_2;
  int pub_r000011_6_1;
  int pub_r000011_6_2;
  int pub_r000011_7_1;
  int pub_r000011_7_2;
  int pub_r000011_8_1;
  int pub_r000011_8_2;
  int pub_r000011_9_1;
  int pub_r000011_9_2;
  int pub_r000011_10_1;
  int pub_r000011_10_2;
  int pub_r000011_11_1;
  int pub_r000011_11_2;
  int pub_r000011_12_1;
  int pub_r000011_12_2;
  int pub_r000011_13_1;
  int pub_r000011_13_2;
  int pub_r000011_14_1;
  int pub_r000011_14_2;
  int pub_r000011_15_1;
  int pub_r000011_15_2;
  int pub_r000011_16_1;
  int pub_r000011_16_2;
  int pub_r000011_17_1;
  int pub_r000011_17_2;
  int pub_r000011_18_1;
  int pub_r000011_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000011_0_1 >= (-100)) && (pub_r000011_0_1 <= 100));
  __CPROVER_assume((pub_r000011_0_2 >= (-100)) && (pub_r000011_0_2 <= 100));
  __CPROVER_assume((pub_r000011_1_1 >= (-100)) && (pub_r000011_1_1 <= 100));
  __CPROVER_assume((pub_r000011_1_2 >= (-100)) && (pub_r000011_1_2 <= 100));
  __CPROVER_assume((pub_r000011_2_1 >= (-100)) && (pub_r000011_2_1 <= 100));
  __CPROVER_assume((pub_r000011_2_2 >= (-100)) && (pub_r000011_2_2 <= 100));
  __CPROVER_assume((pub_r000011_3_1 >= (-100)) && (pub_r000011_3_1 <= 100));
  __CPROVER_assume((pub_r000011_3_2 >= (-100)) && (pub_r000011_3_2 <= 100));
  __CPROVER_assume((pub_r000011_4_1 >= (-100)) && (pub_r000011_4_1 <= 100));
  __CPROVER_assume((pub_r000011_4_2 >= (-100)) && (pub_r000011_4_2 <= 100));
  __CPROVER_assume((pub_r000011_5_1 >= (-100)) && (pub_r000011_5_1 <= 100));
  __CPROVER_assume((pub_r000011_5_2 >= (-100)) && (pub_r000011_5_2 <= 100));
  __CPROVER_assume((pub_r000011_6_1 >= (-100)) && (pub_r000011_6_1 <= 100));
  __CPROVER_assume((pub_r000011_6_2 >= (-100)) && (pub_r000011_6_2 <= 100));
  __CPROVER_assume((pub_r000011_7_1 >= (-100)) && (pub_r000011_7_1 <= 100));
  __CPROVER_assume((pub_r000011_7_2 >= (-100)) && (pub_r000011_7_2 <= 100));
  __CPROVER_assume((pub_r000011_8_1 >= (-100)) && (pub_r000011_8_1 <= 100));
  __CPROVER_assume((pub_r000011_8_2 >= (-100)) && (pub_r000011_8_2 <= 100));
  __CPROVER_assume((pub_r000011_9_1 >= (-100)) && (pub_r000011_9_1 <= 100));
  __CPROVER_assume((pub_r000011_9_2 >= (-100)) && (pub_r000011_9_2 <= 100));
  __CPROVER_assume((pub_r000011_10_1 >= (-100)) && (pub_r000011_10_1 <= 100));
  __CPROVER_assume((pub_r000011_10_2 >= (-100)) && (pub_r000011_10_2 <= 100));
  __CPROVER_assume((pub_r000011_11_1 >= (-100)) && (pub_r000011_11_1 <= 100));
  __CPROVER_assume((pub_r000011_11_2 >= (-100)) && (pub_r000011_11_2 <= 100));
  __CPROVER_assume((pub_r000011_12_1 >= (-100)) && (pub_r000011_12_1 <= 100));
  __CPROVER_assume((pub_r000011_12_2 >= (-100)) && (pub_r000011_12_2 <= 100));
  __CPROVER_assume((pub_r000011_13_1 >= (-100)) && (pub_r000011_13_1 <= 100));
  __CPROVER_assume((pub_r000011_13_2 >= (-100)) && (pub_r000011_13_2 <= 100));
  __CPROVER_assume((pub_r000011_14_1 >= (-100)) && (pub_r000011_14_1 <= 100));
  __CPROVER_assume((pub_r000011_14_2 >= (-100)) && (pub_r000011_14_2 <= 100));
  __CPROVER_assume((pub_r000011_15_1 >= (-100)) && (pub_r000011_15_1 <= 100));
  __CPROVER_assume((pub_r000011_15_2 >= (-100)) && (pub_r000011_15_2 <= 100));
  __CPROVER_assume((pub_r000011_16_1 >= (-100)) && (pub_r000011_16_1 <= 100));
  __CPROVER_assume((pub_r000011_16_2 >= (-100)) && (pub_r000011_16_2 <= 100));
  __CPROVER_assume((pub_r000011_17_1 >= (-100)) && (pub_r000011_17_1 <= 100));
  __CPROVER_assume((pub_r000011_17_2 >= (-100)) && (pub_r000011_17_2 <= 100));
  __CPROVER_assume((pub_r000011_18_1 >= (-100)) && (pub_r000011_18_1 <= 100));
  __CPROVER_assume((pub_r000011_18_2 >= (-100)) && (pub_r000011_18_2 <= 100));
  __CPROVER_assume((sec_r000011_0_1 >= 0) && (sec_r000011_0_1 <= 255));
  __CPROVER_assume((sec_r000011_0_2 >= 0) && (sec_r000011_0_2 <= 255));
  __CPROVER_assume((sec_r000011_1_1 >= 0) && (sec_r000011_1_1 <= 255));
  __CPROVER_assume((sec_r000011_1_2 >= 0) && (sec_r000011_1_2 <= 255));
  __CPROVER_assume((sec_r000011_2_1 >= 0) && (sec_r000011_2_1 <= 255));
  __CPROVER_assume((sec_r000011_2_2 >= 0) && (sec_r000011_2_2 <= 255));
  __CPROVER_assume((sec_r000011_3_1 >= 0) && (sec_r000011_3_1 <= 255));
  __CPROVER_assume((sec_r000011_3_2 >= 0) && (sec_r000011_3_2 <= 255));
  __CPROVER_assume((sec_r000011_4_1 >= 0) && (sec_r000011_4_1 <= 255));
  __CPROVER_assume((sec_r000011_4_2 >= 0) && (sec_r000011_4_2 <= 255));
  __CPROVER_assume((sec_r000011_5_1 >= 0) && (sec_r000011_5_1 <= 255));
  __CPROVER_assume((sec_r000011_5_2 >= 0) && (sec_r000011_5_2 <= 255));
  __CPROVER_assume((sec_r000011_6_1 >= 0) && (sec_r000011_6_1 <= 255));
  __CPROVER_assume((sec_r000011_6_2 >= 0) && (sec_r000011_6_2 <= 255));
  __CPROVER_assume((sec_r000011_7_1 >= 0) && (sec_r000011_7_1 <= 255));
  __CPROVER_assume((sec_r000011_7_2 >= 0) && (sec_r000011_7_2 <= 255));
  __CPROVER_assume((sec_r000011_8_1 >= 0) && (sec_r000011_8_1 <= 255));
  __CPROVER_assume((sec_r000011_8_2 >= 0) && (sec_r000011_8_2 <= 255));
  __CPROVER_assume((sec_r000011_9_1 >= 0) && (sec_r000011_9_1 <= 255));
  __CPROVER_assume((sec_r000011_9_2 >= 0) && (sec_r000011_9_2 <= 255));
  __CPROVER_assume((sec_r000011_10_1 >= 0) && (sec_r000011_10_1 <= 255));
  __CPROVER_assume((sec_r000011_10_2 >= 0) && (sec_r000011_10_2 <= 255));
  __CPROVER_assume((sec_r000011_11_1 >= 0) && (sec_r000011_11_1 <= 255));
  __CPROVER_assume((sec_r000011_11_2 >= 0) && (sec_r000011_11_2 <= 255));
  __CPROVER_assume((sec_r000011_12_1 >= 0) && (sec_r000011_12_1 <= 255));
  __CPROVER_assume((sec_r000011_12_2 >= 0) && (sec_r000011_12_2 <= 255));
  __CPROVER_assume((sec_r000011_13_1 >= 0) && (sec_r000011_13_1 <= 255));
  __CPROVER_assume((sec_r000011_13_2 >= 0) && (sec_r000011_13_2 <= 255));
  __CPROVER_assume((sec_r000011_14_1 >= 0) && (sec_r000011_14_1 <= 255));
  __CPROVER_assume((sec_r000011_14_2 >= 0) && (sec_r000011_14_2 <= 255));
  __CPROVER_assume((sec_r000011_15_1 >= 0) && (sec_r000011_15_1 <= 255));
  __CPROVER_assume((sec_r000011_15_2 >= 0) && (sec_r000011_15_2 <= 255));
  __CPROVER_assume((sec_r000011_16_1 >= 0) && (sec_r000011_16_1 <= 255));
  __CPROVER_assume((sec_r000011_16_2 >= 0) && (sec_r000011_16_2 <= 255));
  struct Vector3D_R000011_1113_0 st_var_0_1 = {0};
  struct Vector3D_R000011_1113_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000011_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000011_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000011_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000011_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000011_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000011_0_2 + 7) & 15;
  struct EventLog_R000011_1113_1 st_var_1_1 = {0};
  struct EventLog_R000011_1113_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000011_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000011_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000011_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000011_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000011_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000011_0_2 + 9) & 15;
  struct StreamBuffer_R000011_1113_2 st_var_2_1 = {0};
  struct StreamBuffer_R000011_1113_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000011_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000011_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000011_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000011_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000011_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000011_0_2 + 11) & 15;
  union ColorPixel_R000011_1113_0 u_var_1;
  union ColorPixel_R000011_1113_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 34)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 34)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
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

  int stage_v_10_1 = ((st_var_1_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_1_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 29)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 29)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 30)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 30)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 41)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 41)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 52)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 52)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 39)
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
  if (stage_v_21_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 39)
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
  int stage_v_22_1 = (st_var_1_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_1_2.buffer[0] ^ 25) & 3;
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

  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (st_var_1_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_1_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 55)
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
  if (stage_v_29_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 55)
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
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 43)
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
  if (stage_v_31_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 43)
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
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (st_var_1_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_1_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = (st_var_2_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_2_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 31)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 31)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = ((st_var_1_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_1_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 53)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 53)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 57) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 33)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 33)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = ((st_var_0_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_0_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 28)
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
  if (stage_v_69_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 28)
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
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 46)
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
  if (stage_v_73_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 46)
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
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = (st_var_0_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_0_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_2_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_2_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 28)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 28)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (st_var_1_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_1_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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

  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
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

  switch (stage_v_84_2)
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

  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = ((st_var_0_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_0_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 29)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 29)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_88_1 = (st_var_1_1.buffer[0] ^ 91) & 3;
  int stage_v_88_2 = (st_var_1_2.buffer[0] ^ 91) & 3;
  switch (stage_v_88_1)
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

  switch (stage_v_88_2)
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

  int stage_v_89_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_89_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  int stage_v_91_1 = ((st_var_1_1.buffer[1] * 2) + 280) & 63;
  int stage_v_91_2 = ((st_var_1_2.buffer[1] * 2) + 280) & 63;
  if (stage_v_91_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_91_1) - 5) & 255;
    if (stage_v_91_1 > 50)
    {
      chk_sum_1 ^= stage_v_91_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_91_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_91_2) - 5) & 255;
    if (stage_v_91_2 > 50)
    {
      chk_sum_2 ^= stage_v_91_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 96) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 96) & 15;
  int stage_v_95_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_95_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= stage_v_95_1;
  chk_sum_2 ^= stage_v_95_2;
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_97_1 = (st_var_1_1.buffer[0] ^ 100) & 3;
  int stage_v_97_2 = (st_var_1_2.buffer[0] ^ 100) & 3;
  switch (stage_v_97_1)
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

  switch (stage_v_97_2)
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

  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 47)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 47)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 55)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 55)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = ((st_var_1_1.buffer[1] * 2) + 307) & 63;
  int stage_v_100_2 = ((st_var_1_2.buffer[1] * 2) + 307) & 63;
  if (stage_v_100_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_100_1) - 5) & 255;
    if (stage_v_100_1 > 45)
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
  if (stage_v_100_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_100_2) - 5) & 255;
    if (stage_v_100_2 > 45)
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
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_104_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_105_1 = ((st_var_0_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_0_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 43)
    {
      chk_sum_1 ^= stage_v_105_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_105_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 43)
    {
      chk_sum_2 ^= stage_v_105_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_106_1 = ((st_var_1_1.buffer[1] * 2) + 325) & 63;
  int stage_v_106_2 = ((st_var_1_2.buffer[1] * 2) + 325) & 63;
  if (stage_v_106_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_106_1) - 5) & 255;
    if (stage_v_106_1 > 37)
    {
      chk_sum_1 ^= stage_v_106_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_106_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_106_2) - 5) & 255;
    if (stage_v_106_2 > 37)
    {
      chk_sum_2 ^= stage_v_106_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_107_1 = table_1[3];
  int stage_v_107_2 = table_2[3];
  table_1[3] = (table_1[0] + 215) & 63;
  table_2[3] = (table_2[0] + 215) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
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
  if (stage_v_109_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_109_1) - 5) & 255;
    if (stage_v_109_1 > 45)
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
  if (stage_v_109_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_109_2) - 5) & 255;
    if (stage_v_109_2 > 45)
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
  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = ((st_var_2_1.buffer[2] * 2) + 355) & 63;
  int stage_v_116_2 = ((st_var_2_2.buffer[2] * 2) + 355) & 63;
  if (stage_v_116_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_116_1) - 5) & 255;
    if (stage_v_116_1 > 41)
    {
      chk_sum_1 ^= stage_v_116_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_116_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_116_2) - 5) & 255;
    if (stage_v_116_2 > 41)
    {
      chk_sum_2 ^= stage_v_116_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 118) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
  int stage_v_118_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (123 & 31);
  int stage_v_118_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (123 & 31);
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= (stage_v_118_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_118_2 << 1) & 127;
  int stage_v_119_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_119_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 40)
    {
      chk_sum_1 ^= stage_v_121_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_121_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 40)
    {
      chk_sum_2 ^= stage_v_121_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_122_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (127 & 31);
  int stage_v_122_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (127 & 31);
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= (stage_v_122_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_122_2 << 1) & 127;
  int stage_v_123_1 = (st_var_0_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_0_2.buffer[0] ^ 126) & 3;
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

  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 126) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = ((st_var_0_1.buffer[0] * 2) + 385) & 63;
  int stage_v_126_2 = ((st_var_0_2.buffer[0] * 2) + 385) & 63;
  if (stage_v_126_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_126_1) - 5) & 255;
    if (stage_v_126_1 > 53)
    {
      chk_sum_1 ^= stage_v_126_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_126_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_126_2) - 5) & 255;
    if (stage_v_126_2 > 53)
    {
      chk_sum_2 ^= stage_v_126_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  int stage_v_128_1 = ((st_var_2_1.buffer[2] * 2) + 391) & 63;
  int stage_v_128_2 = ((st_var_2_2.buffer[2] * 2) + 391) & 63;
  if (stage_v_128_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_128_1) - 5) & 255;
    if (stage_v_128_1 > 44)
    {
      chk_sum_1 ^= stage_v_128_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_128_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_128_2) - 5) & 255;
    if (stage_v_128_2 > 44)
    {
      chk_sum_2 ^= stage_v_128_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_129_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (134 & 31);
  int stage_v_129_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (134 & 31);
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= (stage_v_129_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_129_2 << 1) & 127;
  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((st_var_2_1.buffer[2] * 2) + 400) & 63;
  int stage_v_131_2 = ((st_var_2_2.buffer[2] * 2) + 400) & 63;
  if (stage_v_131_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_131_1) - 5) & 255;
    if (stage_v_131_1 > 34)
    {
      chk_sum_1 ^= stage_v_131_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_131_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_131_2) - 5) & 255;
    if (stage_v_131_2 > 34)
    {
      chk_sum_2 ^= stage_v_131_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (st_var_2_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_2_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  int stage_v_135_1 = ((st_var_0_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_0_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 32)
    {
      chk_sum_1 ^= stage_v_135_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_135_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 32)
    {
      chk_sum_2 ^= stage_v_135_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  int stage_v_137_1 = ((st_var_2_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_2_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 42)
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
  if (stage_v_137_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 42)
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
  int dead_sec_0_1 = ((sec_r000011_15_1 + 9) - (sec_r000011_15_1 + 9)) * 0;
  int dead_sec_0_2 = ((sec_r000011_15_2 + 9) - (sec_r000011_15_2 + 9)) * 0;
  int dead_sec_1_1 = (sec_r000011_4_1 & 0) * 0;
  int dead_sec_1_2 = (sec_r000011_4_2 & 0) * 0;
  int dead_sec_2_1 = ((sec_r000011_16_1 << 2) ^ (sec_r000011_16_1 << 2)) * 0;
  int dead_sec_2_2 = ((sec_r000011_16_2 << 2) ^ (sec_r000011_16_2 << 2)) * 0;
  int dead_sec_3_1 = ((sec_r000011_15_1 + 19) - (sec_r000011_15_1 + 19)) * 0;
  int dead_sec_3_2 = ((sec_r000011_15_2 + 19) - (sec_r000011_15_2 + 19)) * 0;
  out_sink_1 = ((((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) + dead_sec_2_1) + dead_sec_3_1) & 255;
  out_sink_2 = ((((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) + dead_sec_2_2) + dead_sec_3_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000011_3_1 != sec_r000011_3_2);
  __CPROVER_assume(sec_r000011_15_1 != sec_r000011_15_2);
  __CPROVER_assume(pub_r000011_7_1 == pub_r000011_7_2);
  __CPROVER_assume(sec_r000011_4_1 != sec_r000011_4_2);
  __CPROVER_assume(pub_r000011_3_1 == pub_r000011_3_2);
  __CPROVER_assume(pub_r000011_8_1 == pub_r000011_8_2);
  __CPROVER_assume(sec_r000011_7_1 != sec_r000011_7_2);
  __CPROVER_assume(pub_r000011_15_1 == pub_r000011_15_2);
  __CPROVER_assume(pub_r000011_10_1 == pub_r000011_10_2);
  __CPROVER_assume(sec_r000011_10_1 != sec_r000011_10_2);
  __CPROVER_assume(sec_r000011_6_1 != sec_r000011_6_2);
  __CPROVER_assume(pub_r000011_11_1 == pub_r000011_11_2);
  __CPROVER_assume(pub_r000011_4_1 == pub_r000011_4_2);
  __CPROVER_assume(pub_r000011_13_1 == pub_r000011_13_2);
  __CPROVER_assume(sec_r000011_2_1 != sec_r000011_2_2);
  __CPROVER_assume(pub_r000011_16_1 == pub_r000011_16_2);
  __CPROVER_assume(pub_r000011_1_1 == pub_r000011_1_2);
  __CPROVER_assume(sec_r000011_12_1 != sec_r000011_12_2);
  __CPROVER_assume(pub_r000011_17_1 == pub_r000011_17_2);
  __CPROVER_assume(sec_r000011_11_1 != sec_r000011_11_2);
  __CPROVER_assume(sec_r000011_16_1 != sec_r000011_16_2);
  __CPROVER_assume(pub_r000011_14_1 == pub_r000011_14_2);
  __CPROVER_assume(sec_r000011_8_1 != sec_r000011_8_2);
  __CPROVER_assume(pub_r000011_18_1 == pub_r000011_18_2);
  __CPROVER_assume(sec_r000011_13_1 != sec_r000011_13_2);
  __CPROVER_assume(sec_r000011_1_1 != sec_r000011_1_2);
  __CPROVER_assume(pub_r000011_0_1 == pub_r000011_0_2);
  __CPROVER_assume(sec_r000011_0_1 != sec_r000011_0_2);
  __CPROVER_assume(sec_r000011_14_1 != sec_r000011_14_2);
  __CPROVER_assume(pub_r000011_6_1 == pub_r000011_6_2);
  __CPROVER_assume(pub_r000011_2_1 == pub_r000011_2_2);
  __CPROVER_assume(pub_r000011_5_1 == pub_r000011_5_2);
  __CPROVER_assume(pub_r000011_12_1 == pub_r000011_12_2);
  __CPROVER_assume(pub_r000011_9_1 == pub_r000011_9_2);
  __CPROVER_assume(sec_r000011_5_1 != sec_r000011_5_2);
  __CPROVER_assume(sec_r000011_9_1 != sec_r000011_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.state == st_var_2_2.state);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
  assert(dead_sec_2_1 == dead_sec_2_2);
  assert(dead_sec_3_1 == dead_sec_3_2);
}


