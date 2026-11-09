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
struct StreamBuffer_R001716_1613_0
{
  unsigned char checksum;
  int head;
  short state;
  unsigned char capacity;
  unsigned char tail;
  int buffer[3];
};
struct Vector3D_R001716_1613_1
{
  int norm_sq;
  int coord_y;
  int heading;
  unsigned char coord_z;
  short pitch;
  short coord_x;
  int buffer[3];
};
union TelemetryField_R001716_1613_0
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
void fn_R001716_1613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_63_1 = 0;
  int scale_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_63_1 = ((scale_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_63_2 = ((scale_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_63_1) & 127;
    acc_2 = (acc_2 + scale_63_2) & 127;
  }

  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 33)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 33)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_81_1 = local_arr_1[aux_1 % 3];
  int index_reg_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_63_1 == scale_63_2);
  assert(residue_99_1 == residue_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_81_1 == index_reg_81_2);
}

int fn_R001716_1613_0(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_63 = ((scale_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_63) & 127;
  }

  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 33)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_81 = local_arr[aux % 3];
  acc = (acc + (index_reg_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int scale_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_78_1) & 63;
  aux_2 = (aux_2 + scale_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_94_1)
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

  switch (quotient_94_2)
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
  int factor_85_1 = local_arr_1[aux_1 % 3];
  int factor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_78_1 == scale_78_2);
  assert(quotient_94_1 == quotient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_85_1 == factor_85_2);
}

int fn_R001716_1613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int scale_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_78) & 63;
  acc ^= aux;
  int quotient_94 = (aux + st.buffer[1]) & 3;
  switch (quotient_94)
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
  int factor_85 = local_arr[aux % 3];
  acc = (acc + (factor_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_16_1) & 63;
  aux_2 = (aux_2 + coefficient_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_16_1 == coefficient_16_2);
}

int fn_R001716_1613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_39_1) & 63;
  aux_2 = (aux_2 + pivot_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_39_1 == pivot_39_2);
}

int fn_R001716_1613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001716_1613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_62_1) & 63;
  aux_2 = (aux_2 + scale_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_31_1)
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

  switch (stride_31_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_62_1 == scale_62_2);
  assert(stride_31_1 == stride_31_2);
}

int fn_R001716_1613_4(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_62) & 63;
  acc ^= aux;
  int stride_31 = (aux + st.buffer[1]) & 3;
  switch (stride_31)
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

void fn_R001716_1613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_38_1)
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

  switch (tracker_38_2)
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

  int quantum_14_1 = 0;
  int quantum_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_14_1 = ((quantum_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_14_2 = ((quantum_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_14_1) & 127;
    acc_2 = (acc_2 + quantum_14_2) & 127;
  }

  int offset_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_51_1) & 63;
  aux_2 = (aux_2 + offset_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_38_1 == tracker_38_2);
  assert(quantum_14_1 == quantum_14_2);
  assert(offset_51_1 == offset_51_2);
}

int fn_R001716_1613_5(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_38 = (aux + st.buffer[1]) & 3;
  switch (tracker_38)
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

  int quantum_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_14 = ((quantum_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_14) & 127;
  }

  int offset_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001716_1613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_34_1 = local_arr_1[aux_1 % 3];
  int segment_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_34_2 * 2)) & 127;
  int bound_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_18_1) & 63;
  aux_2 = (aux_2 + bound_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_18_1 = 0;
  int vector_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_18_1 = ((vector_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_18_2 = ((vector_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_18_1) & 127;
    acc_2 = (acc_2 + vector_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_34_1 == segment_34_2);
  assert(bound_18_1 == bound_18_2);
  assert(vector_18_1 == vector_18_2);
}

int fn_R001716_1613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_34 = local_arr[aux % 3];
  acc = (acc + (segment_34 * 2)) & 127;
  int bound_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_18) & 63;
  acc ^= aux;
  int vector_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_18 = ((vector_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001716_1613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_98_1) & 63;
  aux_2 = (aux_2 + quotient_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_17_1 = 0;
  int mask_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_17_1 = ((mask_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_17_2 = ((mask_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_17_1) & 127;
    acc_2 = (acc_2 + mask_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_98_1 == quotient_98_2);
  assert(mask_17_1 == mask_17_2);
}

int fn_R001716_1613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_98) & 63;
  acc ^= aux;
  int mask_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_17 = ((mask_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001716_1613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_10_1 = 0;
  int parity_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_10_1 = ((parity_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_10_2 = ((parity_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_10_1) & 127;
    acc_2 = (acc_2 + parity_10_2) & 127;
  }

  int vector_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_41_1)
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

  switch (vector_41_2)
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

  int factor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_17_1 > 29)
  {
    acc_1 = ((acc_1 + (factor_17_1 * 2)) + 5) & 127;
    aux_1 ^= factor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_17_2 > 29)
  {
    acc_2 = ((acc_2 + (factor_17_2 * 2)) + 5) & 127;
    aux_2 ^= factor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  assert(vector_41_1 == vector_41_2);
  assert(factor_17_1 == factor_17_2);
}

int fn_R001716_1613_8(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_10 = ((parity_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_10) & 127;
  }

  int vector_41 = (aux + st.buffer[1]) & 3;
  switch (vector_41)
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

  int factor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_17 > 29)
  {
    acc = ((acc + (factor_17 * 2)) + 5) & 127;
    aux ^= factor_17 & 15;
  }
  else
  {
    acc = ((acc - factor_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001716_1613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_53_1) & 63;
  aux_2 = (aux_2 + pivot_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_37_1 = local_arr_1[aux_1 % 3];
  int threshold_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  assert(offset_58_1 == offset_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_37_1 == threshold_37_2);
}

int fn_R001716_1613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_53) & 63;
  acc ^= aux;
  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 24)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_37 = local_arr[aux % 3];
  acc = (acc + (threshold_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int segment_27_1 = 0;
  int segment_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_27_1 = ((segment_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_27_2 = ((segment_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_27_1) & 127;
    acc_2 = (acc_2 + segment_27_2) & 127;
  }

  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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

  int sample_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_84_1) & 63;
  aux_2 = (aux_2 + sample_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_27_1 == segment_27_2);
  assert(damping_50_1 == damping_50_2);
  assert(sample_84_1 == sample_84_2);
}

int fn_R001716_1613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int segment_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_27 = ((segment_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_27) & 127;
  }

  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

  int sample_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_84) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int mask_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_96_1)
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

  switch (mask_96_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_37_1 = 0;
  int accumulator_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_37_1 = ((accumulator_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_37_2 = ((accumulator_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_37_1) & 127;
    acc_2 = (acc_2 + accumulator_37_2) & 127;
  }

  int scale_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_53_1 > 48)
  {
    acc_1 = ((acc_1 + (scale_53_1 * 2)) + 5) & 127;
    aux_1 ^= scale_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_53_2 > 48)
  {
    acc_2 = ((acc_2 + (scale_53_2 * 2)) + 5) & 127;
    aux_2 ^= scale_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_96_1 == mask_96_2);
  assert(accumulator_37_1 == accumulator_37_2);
  assert(scale_53_1 == scale_53_2);
}

int fn_R001716_1613_11(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int mask_96 = (aux + st.buffer[1]) & 3;
  switch (mask_96)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_37 = ((accumulator_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_37) & 127;
  }

  int scale_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_53 > 48)
  {
    acc = ((acc + (scale_53 * 2)) + 5) & 127;
    aux ^= scale_53 & 15;
  }
  else
  {
    acc = ((acc - scale_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001716_1613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_93_1 > 18)
  {
    acc_1 = ((acc_1 + (anchor_93_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_93_2 > 18)
  {
    acc_2 = ((acc_2 + (anchor_93_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_48_1)
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

  switch (coefficient_48_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_93_1 == anchor_93_2);
  assert(coefficient_48_1 == coefficient_48_2);
}

int fn_R001716_1613_12(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_93 > 18)
  {
    acc = ((acc + (anchor_93 * 2)) + 5) & 127;
    aux ^= anchor_93 & 15;
  }
  else
  {
    acc = ((acc - anchor_93) + 11) & 127;
    aux += 3;
  }
  int coefficient_48 = (aux + st.buffer[1]) & 3;
  switch (coefficient_48)
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

void fn_R001716_1613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_37_1 = local_arr_1[aux_1 % 3];
  int anchor_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_37_2 * 2)) & 127;
  int index_reg_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_79_1)
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

  switch (index_reg_79_2)
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

  int pivot_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_92_1 > 27)
  {
    acc_1 = ((acc_1 + (pivot_92_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_92_2 > 27)
  {
    acc_2 = ((acc_2 + (pivot_92_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_25_1 = 0;
  int margin_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_25_1 = ((margin_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_25_2 = ((margin_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_25_1) & 127;
    acc_2 = (acc_2 + margin_25_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_37_1 == anchor_37_2);
  assert(index_reg_79_1 == index_reg_79_2);
  assert(pivot_92_1 == pivot_92_2);
  assert(margin_25_1 == margin_25_2);
}

int fn_R001716_1613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int anchor_37 = local_arr[aux % 3];
  acc = (acc + (anchor_37 * 2)) & 127;
  int index_reg_79 = (aux + st.buffer[1]) & 3;
  switch (index_reg_79)
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

  int pivot_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_92 > 27)
  {
    acc = ((acc + (pivot_92 * 2)) + 5) & 127;
    aux ^= pivot_92 & 15;
  }
  else
  {
    acc = ((acc - pivot_92) + 11) & 127;
    aux += 3;
  }
  int margin_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_25 = ((margin_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_25) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001716_1613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_72_1) & 63;
  aux_2 = (aux_2 + scale_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_89_1 = 0;
  int phase_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_89_1 = ((phase_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_89_2 = ((phase_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_89_1) & 127;
    acc_2 = (acc_2 + phase_89_2) & 127;
  }

  int quotient_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_33_1)
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

  switch (quotient_33_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_72_1 == scale_72_2);
  assert(phase_89_1 == phase_89_2);
  assert(quotient_33_1 == quotient_33_2);
}

int fn_R001716_1613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_72) & 63;
  acc ^= aux;
  int phase_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_89 = ((phase_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_89) & 127;
  }

  int quotient_33 = (aux + st.buffer[1]) & 3;
  switch (quotient_33)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_62_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_62_1 * 2)) + 5) & 127;
    aux_1 ^= offset_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_62_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_62_2 * 2)) + 5) & 127;
    aux_2 ^= offset_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_13_1 = local_arr_1[aux_1 % 3];
  int vector_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_13_2 * 2)) & 127;
  int pivot_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_79_1) & 63;
  aux_2 = (aux_2 + pivot_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_41_1 = 0;
  int vector_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_41_1 = ((vector_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_41_2 = ((vector_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_41_1) & 127;
    acc_2 = (acc_2 + vector_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_62_1 == offset_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_13_1 == vector_13_2);
  assert(pivot_79_1 == pivot_79_2);
  assert(vector_41_1 == vector_41_2);
}

int fn_R001716_1613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_62 > 26)
  {
    acc = ((acc + (offset_62 * 2)) + 5) & 127;
    aux ^= offset_62 & 15;
  }
  else
  {
    acc = ((acc - offset_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_13 = local_arr[aux % 3];
  acc = (acc + (vector_13 * 2)) & 127;
  int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_79) & 63;
  acc ^= aux;
  int vector_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_41 = ((vector_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001716_1613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int vector_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_44_1) & 63;
  aux_2 = (aux_2 + vector_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_90_1 = local_arr_1[aux_1 % 3];
  int checksum_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_44_1 == vector_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_90_1 == checksum_90_2);
}

int fn_R001716_1613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_90 = local_arr[aux % 3];
  acc = (acc + (checksum_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int accumulator_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_49_1)
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

  switch (accumulator_49_2)
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

  int coefficient_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_77_1) & 63;
  aux_2 = (aux_2 + coefficient_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_49_1 == accumulator_49_2);
  assert(coefficient_77_1 == coefficient_77_2);
}

int fn_R001716_1613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int accumulator_49 = (aux + st.buffer[1]) & 3;
  switch (accumulator_49)
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

  int coefficient_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001716_1613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_31_1 > 49)
  {
    acc_1 = ((acc_1 + (cursor_31_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_31_2 > 49)
  {
    acc_2 = ((acc_2 + (cursor_31_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_46_1)
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

  switch (residue_46_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_31_1 == cursor_31_2);
  assert(residue_46_1 == residue_46_2);
}

int fn_R001716_1613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_31 > 49)
  {
    acc = ((acc + (cursor_31 * 2)) + 5) & 127;
    aux ^= cursor_31 & 15;
  }
  else
  {
    acc = ((acc - cursor_31) + 11) & 127;
    aux += 3;
  }
  int residue_46 = (aux + st.buffer[1]) & 3;
  switch (residue_46)
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

void fn_R001716_1613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_47_1 = 0;
  int mask_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_47_1 = ((mask_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_47_2 = ((mask_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_47_1) & 127;
    acc_2 = (acc_2 + mask_47_2) & 127;
  }

  int coefficient_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_56_1)
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

  switch (coefficient_56_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_47_1 == mask_47_2);
  assert(coefficient_56_1 == coefficient_56_2);
}

int fn_R001716_1613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_47 = ((mask_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_47) & 127;
  }

  int coefficient_56 = (aux + st.buffer[1]) & 3;
  switch (coefficient_56)
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

void fn_R001716_1613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_40_1 > 49)
  {
    acc_1 = ((acc_1 + (damping_40_1 * 2)) + 5) & 127;
    aux_1 ^= damping_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_40_2 > 49)
  {
    acc_2 = ((acc_2 + (damping_40_2 * 2)) + 5) & 127;
    aux_2 ^= damping_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_92_1)
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

  switch (weight_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_40_1 == damping_40_2);
  assert(weight_92_1 == weight_92_2);
}

int fn_R001716_1613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_40 > 49)
  {
    acc = ((acc + (damping_40 * 2)) + 5) & 127;
    aux ^= damping_40 & 15;
  }
  else
  {
    acc = ((acc - damping_40) + 11) & 127;
    aux += 3;
  }
  int weight_92 = (aux + st.buffer[1]) & 3;
  switch (weight_92)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_51_1 = 0;
  int delta_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_51_1 = ((delta_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_51_2 = ((delta_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_51_1) & 127;
    acc_2 = (acc_2 + delta_51_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_51_1 == delta_51_2);
}

int fn_R001716_1613_21(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001716_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_51 = ((delta_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_51) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001716_1613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st_1 = {0};
  struct Vector3D_R001716_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int delta_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_41_1 > 33)
  {
    acc_1 = ((acc_1 + (delta_41_1 * 2)) + 5) & 127;
    aux_1 ^= delta_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_41_2 > 33)
  {
    acc_2 = ((acc_2 + (delta_41_2 * 2)) + 5) & 127;
    aux_2 ^= delta_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_45_1 = 0;
  int stride_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_45_1 = ((stride_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_45_2 = ((stride_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_45_1) & 127;
    acc_2 = (acc_2 + stride_45_2) & 127;
  }

  int factor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_33_1)
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

  switch (factor_33_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_41_1 == delta_41_2);
  assert(stride_45_1 == stride_45_2);
  assert(factor_33_1 == factor_33_2);
}

int fn_R001716_1613_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001716_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int delta_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_41 > 33)
  {
    acc = ((acc + (delta_41 * 2)) + 5) & 127;
    aux ^= delta_41 & 15;
  }
  else
  {
    acc = ((acc - delta_41) + 11) & 127;
    aux += 3;
  }
  int stride_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_45 = ((stride_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_45) & 127;
  }

  int factor_33 = (aux + st.buffer[1]) & 3;
  switch (factor_33)
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

void main()
{
  int sec_r001716_0_1;
  int sec_r001716_0_2;
  int sec_r001716_1_1;
  int sec_r001716_1_2;
  int sec_r001716_2_1;
  int sec_r001716_2_2;
  int sec_r001716_3_1;
  int sec_r001716_3_2;
  int sec_r001716_4_1;
  int sec_r001716_4_2;
  int sec_r001716_5_1;
  int sec_r001716_5_2;
  int sec_r001716_6_1;
  int sec_r001716_6_2;
  int sec_r001716_7_1;
  int sec_r001716_7_2;
  int sec_r001716_8_1;
  int sec_r001716_8_2;
  int sec_r001716_9_1;
  int sec_r001716_9_2;
  int sec_r001716_10_1;
  int sec_r001716_10_2;
  int sec_r001716_11_1;
  int sec_r001716_11_2;
  int sec_r001716_12_1;
  int sec_r001716_12_2;
  int sec_r001716_13_1;
  int sec_r001716_13_2;
  int sec_r001716_14_1;
  int sec_r001716_14_2;
  int sec_r001716_15_1;
  int sec_r001716_15_2;
  int sec_r001716_16_1;
  int sec_r001716_16_2;
  int sec_r001716_17_1;
  int sec_r001716_17_2;
  int pub_r001716_0_1;
  int pub_r001716_0_2;
  int pub_r001716_1_1;
  int pub_r001716_1_2;
  int pub_r001716_2_1;
  int pub_r001716_2_2;
  int pub_r001716_3_1;
  int pub_r001716_3_2;
  int pub_r001716_4_1;
  int pub_r001716_4_2;
  int pub_r001716_5_1;
  int pub_r001716_5_2;
  int pub_r001716_6_1;
  int pub_r001716_6_2;
  int pub_r001716_7_1;
  int pub_r001716_7_2;
  int pub_r001716_8_1;
  int pub_r001716_8_2;
  int pub_r001716_9_1;
  int pub_r001716_9_2;
  int pub_r001716_10_1;
  int pub_r001716_10_2;
  int pub_r001716_11_1;
  int pub_r001716_11_2;
  int pub_r001716_12_1;
  int pub_r001716_12_2;
  int pub_r001716_13_1;
  int pub_r001716_13_2;
  int pub_r001716_14_1;
  int pub_r001716_14_2;
  int pub_r001716_15_1;
  int pub_r001716_15_2;
  int pub_r001716_16_1;
  int pub_r001716_16_2;
  int pub_r001716_17_1;
  int pub_r001716_17_2;
  int pub_r001716_18_1;
  int pub_r001716_18_2;
  int pub_r001716_19_1;
  int pub_r001716_19_2;
  int pub_r001716_20_1;
  int pub_r001716_20_2;
  int pub_r001716_21_1;
  int pub_r001716_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001716_0_1 >= (-100)) && (pub_r001716_0_1 <= 100));
  __CPROVER_assume((pub_r001716_0_2 >= (-100)) && (pub_r001716_0_2 <= 100));
  __CPROVER_assume((pub_r001716_1_1 >= (-100)) && (pub_r001716_1_1 <= 100));
  __CPROVER_assume((pub_r001716_1_2 >= (-100)) && (pub_r001716_1_2 <= 100));
  __CPROVER_assume((pub_r001716_2_1 >= (-100)) && (pub_r001716_2_1 <= 100));
  __CPROVER_assume((pub_r001716_2_2 >= (-100)) && (pub_r001716_2_2 <= 100));
  __CPROVER_assume((pub_r001716_3_1 >= (-100)) && (pub_r001716_3_1 <= 100));
  __CPROVER_assume((pub_r001716_3_2 >= (-100)) && (pub_r001716_3_2 <= 100));
  __CPROVER_assume((pub_r001716_4_1 >= (-100)) && (pub_r001716_4_1 <= 100));
  __CPROVER_assume((pub_r001716_4_2 >= (-100)) && (pub_r001716_4_2 <= 100));
  __CPROVER_assume((pub_r001716_5_1 >= (-100)) && (pub_r001716_5_1 <= 100));
  __CPROVER_assume((pub_r001716_5_2 >= (-100)) && (pub_r001716_5_2 <= 100));
  __CPROVER_assume((pub_r001716_6_1 >= (-100)) && (pub_r001716_6_1 <= 100));
  __CPROVER_assume((pub_r001716_6_2 >= (-100)) && (pub_r001716_6_2 <= 100));
  __CPROVER_assume((pub_r001716_7_1 >= (-100)) && (pub_r001716_7_1 <= 100));
  __CPROVER_assume((pub_r001716_7_2 >= (-100)) && (pub_r001716_7_2 <= 100));
  __CPROVER_assume((pub_r001716_8_1 >= (-100)) && (pub_r001716_8_1 <= 100));
  __CPROVER_assume((pub_r001716_8_2 >= (-100)) && (pub_r001716_8_2 <= 100));
  __CPROVER_assume((pub_r001716_9_1 >= (-100)) && (pub_r001716_9_1 <= 100));
  __CPROVER_assume((pub_r001716_9_2 >= (-100)) && (pub_r001716_9_2 <= 100));
  __CPROVER_assume((pub_r001716_10_1 >= (-100)) && (pub_r001716_10_1 <= 100));
  __CPROVER_assume((pub_r001716_10_2 >= (-100)) && (pub_r001716_10_2 <= 100));
  __CPROVER_assume((pub_r001716_11_1 >= (-100)) && (pub_r001716_11_1 <= 100));
  __CPROVER_assume((pub_r001716_11_2 >= (-100)) && (pub_r001716_11_2 <= 100));
  __CPROVER_assume((pub_r001716_12_1 >= (-100)) && (pub_r001716_12_1 <= 100));
  __CPROVER_assume((pub_r001716_12_2 >= (-100)) && (pub_r001716_12_2 <= 100));
  __CPROVER_assume((pub_r001716_13_1 >= (-100)) && (pub_r001716_13_1 <= 100));
  __CPROVER_assume((pub_r001716_13_2 >= (-100)) && (pub_r001716_13_2 <= 100));
  __CPROVER_assume((pub_r001716_14_1 >= (-100)) && (pub_r001716_14_1 <= 100));
  __CPROVER_assume((pub_r001716_14_2 >= (-100)) && (pub_r001716_14_2 <= 100));
  __CPROVER_assume((pub_r001716_15_1 >= (-100)) && (pub_r001716_15_1 <= 100));
  __CPROVER_assume((pub_r001716_15_2 >= (-100)) && (pub_r001716_15_2 <= 100));
  __CPROVER_assume((pub_r001716_16_1 >= (-100)) && (pub_r001716_16_1 <= 100));
  __CPROVER_assume((pub_r001716_16_2 >= (-100)) && (pub_r001716_16_2 <= 100));
  __CPROVER_assume((pub_r001716_17_1 >= (-100)) && (pub_r001716_17_1 <= 100));
  __CPROVER_assume((pub_r001716_17_2 >= (-100)) && (pub_r001716_17_2 <= 100));
  __CPROVER_assume((pub_r001716_18_1 >= (-100)) && (pub_r001716_18_1 <= 100));
  __CPROVER_assume((pub_r001716_18_2 >= (-100)) && (pub_r001716_18_2 <= 100));
  __CPROVER_assume((pub_r001716_19_1 >= (-100)) && (pub_r001716_19_1 <= 100));
  __CPROVER_assume((pub_r001716_19_2 >= (-100)) && (pub_r001716_19_2 <= 100));
  __CPROVER_assume((pub_r001716_20_1 >= (-100)) && (pub_r001716_20_1 <= 100));
  __CPROVER_assume((pub_r001716_20_2 >= (-100)) && (pub_r001716_20_2 <= 100));
  __CPROVER_assume((pub_r001716_21_1 >= (-100)) && (pub_r001716_21_1 <= 100));
  __CPROVER_assume((pub_r001716_21_2 >= (-100)) && (pub_r001716_21_2 <= 100));
  __CPROVER_assume((sec_r001716_0_1 >= 0) && (sec_r001716_0_1 <= 255));
  __CPROVER_assume((sec_r001716_0_2 >= 0) && (sec_r001716_0_2 <= 255));
  __CPROVER_assume((sec_r001716_1_1 >= 0) && (sec_r001716_1_1 <= 255));
  __CPROVER_assume((sec_r001716_1_2 >= 0) && (sec_r001716_1_2 <= 255));
  __CPROVER_assume((sec_r001716_2_1 >= 0) && (sec_r001716_2_1 <= 255));
  __CPROVER_assume((sec_r001716_2_2 >= 0) && (sec_r001716_2_2 <= 255));
  __CPROVER_assume((sec_r001716_3_1 >= 0) && (sec_r001716_3_1 <= 255));
  __CPROVER_assume((sec_r001716_3_2 >= 0) && (sec_r001716_3_2 <= 255));
  __CPROVER_assume((sec_r001716_4_1 >= 0) && (sec_r001716_4_1 <= 255));
  __CPROVER_assume((sec_r001716_4_2 >= 0) && (sec_r001716_4_2 <= 255));
  __CPROVER_assume((sec_r001716_5_1 >= 0) && (sec_r001716_5_1 <= 255));
  __CPROVER_assume((sec_r001716_5_2 >= 0) && (sec_r001716_5_2 <= 255));
  __CPROVER_assume((sec_r001716_6_1 >= 0) && (sec_r001716_6_1 <= 255));
  __CPROVER_assume((sec_r001716_6_2 >= 0) && (sec_r001716_6_2 <= 255));
  __CPROVER_assume((sec_r001716_7_1 >= 0) && (sec_r001716_7_1 <= 255));
  __CPROVER_assume((sec_r001716_7_2 >= 0) && (sec_r001716_7_2 <= 255));
  __CPROVER_assume((sec_r001716_8_1 >= 0) && (sec_r001716_8_1 <= 255));
  __CPROVER_assume((sec_r001716_8_2 >= 0) && (sec_r001716_8_2 <= 255));
  __CPROVER_assume((sec_r001716_9_1 >= 0) && (sec_r001716_9_1 <= 255));
  __CPROVER_assume((sec_r001716_9_2 >= 0) && (sec_r001716_9_2 <= 255));
  __CPROVER_assume((sec_r001716_10_1 >= 0) && (sec_r001716_10_1 <= 255));
  __CPROVER_assume((sec_r001716_10_2 >= 0) && (sec_r001716_10_2 <= 255));
  __CPROVER_assume((sec_r001716_11_1 >= 0) && (sec_r001716_11_1 <= 255));
  __CPROVER_assume((sec_r001716_11_2 >= 0) && (sec_r001716_11_2 <= 255));
  __CPROVER_assume((sec_r001716_12_1 >= 0) && (sec_r001716_12_1 <= 255));
  __CPROVER_assume((sec_r001716_12_2 >= 0) && (sec_r001716_12_2 <= 255));
  __CPROVER_assume((sec_r001716_13_1 >= 0) && (sec_r001716_13_1 <= 255));
  __CPROVER_assume((sec_r001716_13_2 >= 0) && (sec_r001716_13_2 <= 255));
  __CPROVER_assume((sec_r001716_14_1 >= 0) && (sec_r001716_14_1 <= 255));
  __CPROVER_assume((sec_r001716_14_2 >= 0) && (sec_r001716_14_2 <= 255));
  __CPROVER_assume((sec_r001716_15_1 >= 0) && (sec_r001716_15_1 <= 255));
  __CPROVER_assume((sec_r001716_15_2 >= 0) && (sec_r001716_15_2 <= 255));
  __CPROVER_assume((sec_r001716_16_1 >= 0) && (sec_r001716_16_1 <= 255));
  __CPROVER_assume((sec_r001716_16_2 >= 0) && (sec_r001716_16_2 <= 255));
  __CPROVER_assume((sec_r001716_17_1 >= 0) && (sec_r001716_17_1 <= 255));
  __CPROVER_assume((sec_r001716_17_2 >= 0) && (sec_r001716_17_2 <= 255));
  struct StreamBuffer_R001716_1613_0 st_var_0_1 = {0};
  struct StreamBuffer_R001716_1613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001716_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001716_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001716_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001716_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001716_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001716_0_2 + 7) & 15;
  struct Vector3D_R001716_1613_1 st_var_1_1 = {0};
  struct Vector3D_R001716_1613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001716_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001716_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001716_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001716_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001716_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001716_0_2 + 9) & 15;
  union TelemetryField_R001716_1613_0 u_var_1;
  union TelemetryField_R001716_1613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001716_1613_0(sec_r001716_0_1, pub_r001716_1_1);
  int helper_flow_0_2 = fn_R001716_1613_0(sec_r001716_0_2, pub_r001716_1_2);
  fn_R001716_1613_0_2(sec_r001716_0_1, pub_r001716_1_1, sec_r001716_0_2, pub_r001716_1_2);
  int helper_flow_1_1 = fn_R001716_1613_1(sec_r001716_1_1, pub_r001716_2_1, pub_r001716_3_1, pub_r001716_4_1, pub_r001716_5_1);
  int helper_flow_1_2 = fn_R001716_1613_1(sec_r001716_1_2, pub_r001716_2_2, pub_r001716_3_2, pub_r001716_4_2, pub_r001716_5_2);
  fn_R001716_1613_1_2(sec_r001716_1_1, pub_r001716_2_1, pub_r001716_3_1, pub_r001716_4_1, pub_r001716_5_1, sec_r001716_1_2, pub_r001716_2_2, pub_r001716_3_2, pub_r001716_4_2, pub_r001716_5_2);
  int helper_flow_2_1 = fn_R001716_1613_2(sec_r001716_2_1, sec_r001716_3_1, pub_r001716_4_1, pub_r001716_5_1);
  int helper_flow_2_2 = fn_R001716_1613_2(sec_r001716_2_2, sec_r001716_3_2, pub_r001716_4_2, pub_r001716_5_2);
  fn_R001716_1613_2_2(sec_r001716_2_1, sec_r001716_3_1, pub_r001716_4_1, pub_r001716_5_1, sec_r001716_2_2, sec_r001716_3_2, pub_r001716_4_2, pub_r001716_5_2);
  int helper_flow_3_1 = fn_R001716_1613_3(sec_r001716_3_1, sec_r001716_4_1, pub_r001716_5_1);
  int helper_flow_3_2 = fn_R001716_1613_3(sec_r001716_3_2, sec_r001716_4_2, pub_r001716_5_2);
  fn_R001716_1613_3_2(sec_r001716_3_1, sec_r001716_4_1, pub_r001716_5_1, sec_r001716_3_2, sec_r001716_4_2, pub_r001716_5_2);
  int helper_flow_4_1 = fn_R001716_1613_4(sec_r001716_4_1, pub_r001716_5_1);
  int helper_flow_4_2 = fn_R001716_1613_4(sec_r001716_4_2, pub_r001716_5_2);
  fn_R001716_1613_4_2(sec_r001716_4_1, pub_r001716_5_1, sec_r001716_4_2, pub_r001716_5_2);
  int helper_flow_5_1 = fn_R001716_1613_5(sec_r001716_5_1, sec_r001716_6_1);
  int helper_flow_5_2 = fn_R001716_1613_5(sec_r001716_5_2, sec_r001716_6_2);
  fn_R001716_1613_5_2(sec_r001716_5_1, sec_r001716_6_1, sec_r001716_5_2, sec_r001716_6_2);
  int helper_flow_6_1 = fn_R001716_1613_6(sec_r001716_6_1, pub_r001716_7_1, pub_r001716_8_1, pub_r001716_9_1, pub_r001716_10_1);
  int helper_flow_6_2 = fn_R001716_1613_6(sec_r001716_6_2, pub_r001716_7_2, pub_r001716_8_2, pub_r001716_9_2, pub_r001716_10_2);
  fn_R001716_1613_6_2(sec_r001716_6_1, pub_r001716_7_1, pub_r001716_8_1, pub_r001716_9_1, pub_r001716_10_1, sec_r001716_6_2, pub_r001716_7_2, pub_r001716_8_2, pub_r001716_9_2, pub_r001716_10_2);
  int helper_flow_7_1 = fn_R001716_1613_7(sec_r001716_7_1, sec_r001716_8_1, pub_r001716_9_1);
  int helper_flow_7_2 = fn_R001716_1613_7(sec_r001716_7_2, sec_r001716_8_2, pub_r001716_9_2);
  fn_R001716_1613_7_2(sec_r001716_7_1, sec_r001716_8_1, pub_r001716_9_1, sec_r001716_7_2, sec_r001716_8_2, pub_r001716_9_2);
  int stage_v_0_1 = ((sec_r001716_2_1 + (pub_r001716_13_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001716_2_2 + (pub_r001716_13_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001716_8_1 * 2) + 12) & 63;
  int stage_v_1_2 = ((pub_r001716_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001716_5_1 + (pub_r001716_17_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001716_5_2 + (pub_r001716_17_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001716_8_1 + (pub_r001716_17_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001716_8_2 + (pub_r001716_17_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((stage_v_2_1 + (pub_r001716_5_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((stage_v_2_2 + (pub_r001716_5_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001716_6_1 + (pub_r001716_18_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001716_6_2 + (pub_r001716_18_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001716_6_1 * 2) + 33) & 63;
  int stage_v_6_2 = ((pub_r001716_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001716_3_1 + (pub_r001716_17_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001716_3_2 + (pub_r001716_17_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001716_0_1 + (pub_r001716_14_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001716_0_2 + (pub_r001716_14_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001716_12_1 * 2) + 44) & 63;
  int stage_v_9_2 = ((pub_r001716_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001716_0_1 * 2) + 10) & 63;
  int stage_v_10_2 = ((pub_r001716_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001716_6_1 + (pub_r001716_7_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001716_6_2 + (pub_r001716_7_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((stage_v_3_1 + (pub_r001716_19_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((stage_v_3_2 + (pub_r001716_19_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001716_2_1 * 2) + 38) & 63;
  int stage_v_13_2 = ((pub_r001716_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((stage_v_3_1 + (pub_r001716_3_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_3_2 + (pub_r001716_3_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001716_8_1 * 2) + 28) & 63;
  int stage_v_15_2 = ((pub_r001716_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001716_17_1 + (pub_r001716_1_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001716_17_2 + (pub_r001716_1_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001716_10_1 + (pub_r001716_21_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001716_10_2 + (pub_r001716_21_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001716_15_1 + (pub_r001716_19_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001716_15_2 + (pub_r001716_19_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((helper_flow_3_1 + (pub_r001716_18_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_3_2 + (pub_r001716_18_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((helper_flow_0_1 + (pub_r001716_9_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_0_2 + (pub_r001716_9_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_14_1 + (pub_r001716_4_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_14_2 + (pub_r001716_4_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001716_13_1 + (pub_r001716_9_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001716_13_2 + (pub_r001716_9_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001716_16_1 * 2) + 31) & 63;
  int stage_v_23_2 = ((pub_r001716_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001716_16_1 * 2) + 26) & 63;
  int stage_v_24_2 = ((pub_r001716_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((stage_v_4_1 + (pub_r001716_11_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_4_2 + (pub_r001716_11_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((stage_v_3_1 + (pub_r001716_16_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_3_2 + (pub_r001716_16_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_26_1 + (pub_r001716_19_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_26_2 + (pub_r001716_19_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((helper_flow_2_1 + (pub_r001716_15_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((helper_flow_2_2 + (pub_r001716_15_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_16_1 + (pub_r001716_2_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_16_2 + (pub_r001716_2_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001716_16_1 + (pub_r001716_12_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001716_16_2 + (pub_r001716_12_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((stage_v_29_1 + (pub_r001716_19_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_29_2 + (pub_r001716_19_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_7_1 + (pub_r001716_7_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_7_2 + (pub_r001716_7_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_26_1 + (pub_r001716_2_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_26_2 + (pub_r001716_2_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001716_18_1 * 2) + 47) & 63;
  int stage_v_34_2 = ((pub_r001716_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001716_4_1 * 2) + 45) & 63;
  int stage_v_35_2 = ((pub_r001716_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_18_1 + (pub_r001716_11_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_18_2 + (pub_r001716_11_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001716_5_1 * 2) + 6) & 63;
  int stage_v_37_2 = ((pub_r001716_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001716_8_1 * 2) + 13) & 63;
  int stage_v_38_2 = ((pub_r001716_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001716_2_1 + (pub_r001716_10_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001716_2_2 + (pub_r001716_10_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001716_3_1 * 2) + 17) & 63;
  int stage_v_40_2 = ((pub_r001716_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_3_1 + (pub_r001716_7_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_3_2 + (pub_r001716_7_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((sec_r001716_10_1 + (pub_r001716_18_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001716_10_2 + (pub_r001716_18_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001716_3_1 + (pub_r001716_16_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001716_3_2 + (pub_r001716_16_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_36_1 + (pub_r001716_5_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_36_2 + (pub_r001716_5_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_39_1 + (pub_r001716_20_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_39_2 + (pub_r001716_20_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001716_1_1 * 2) + 25) & 63;
  int stage_v_46_2 = ((pub_r001716_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((sec_r001716_4_1 + (pub_r001716_0_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001716_4_2 + (pub_r001716_0_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001716_10_1 * 2) + 18) & 63;
  int stage_v_48_2 = ((pub_r001716_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001716_15_1 * 2) + 37) & 63;
  int stage_v_49_2 = ((pub_r001716_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001716_8_1 * 2) + 40) & 63;
  int stage_v_50_2 = ((pub_r001716_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001716_19_1 * 2) + 35) & 63;
  int stage_v_51_2 = ((pub_r001716_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_17_1 + (pub_r001716_11_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_17_2 + (pub_r001716_11_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001716_3_1 * 2) + 6) & 63;
  int stage_v_53_2 = ((pub_r001716_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001716_16_1 * 2) + 45) & 63;
  int stage_v_54_2 = ((pub_r001716_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((sec_r001716_8_1 + (pub_r001716_21_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001716_8_2 + (pub_r001716_21_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001716_4_1 * 2) + 27) & 63;
  int stage_v_56_2 = ((pub_r001716_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_31_1 + (pub_r001716_15_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_31_2 + (pub_r001716_15_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_47_1 + (pub_r001716_21_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_47_2 + (pub_r001716_21_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((sec_r001716_13_1 + (pub_r001716_17_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001716_13_2 + (pub_r001716_17_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_31_1 + (pub_r001716_18_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_31_2 + (pub_r001716_18_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_45_1 + (pub_r001716_14_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_45_2 + (pub_r001716_14_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001716_20_1 * 2) + 49) & 63;
  int stage_v_62_2 = ((pub_r001716_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_55_1 + (pub_r001716_19_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_55_2 + (pub_r001716_19_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001716_2_1 * 2) + 32) & 63;
  int stage_v_64_2 = ((pub_r001716_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_60_1 + (pub_r001716_21_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_60_2 + (pub_r001716_21_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001716_6_1 * 2) + 40) & 63;
  int stage_v_66_2 = ((pub_r001716_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_31_1 + (pub_r001716_15_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_31_2 + (pub_r001716_15_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((helper_flow_6_1 + (pub_r001716_16_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((helper_flow_6_2 + (pub_r001716_16_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_4_1 + (pub_r001716_10_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_4_2 + (pub_r001716_10_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001716_6_1 * 2) + 11) & 63;
  int stage_v_70_2 = ((pub_r001716_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_20_1 + (pub_r001716_0_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_20_2 + (pub_r001716_0_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_21_1 + (pub_r001716_4_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_21_2 + (pub_r001716_4_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_72_1 + (pub_r001716_12_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_72_2 + (pub_r001716_12_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001716_16_1 * 2) + 45) & 63;
  int stage_v_74_2 = ((pub_r001716_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001716_4_1 * 2) + 48) & 63;
  int stage_v_75_2 = ((pub_r001716_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001716_13_1 * 2) + 27) & 63;
  int stage_v_76_2 = ((pub_r001716_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_68_1 + (pub_r001716_8_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_68_2 + (pub_r001716_8_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001716_9_1 * 2) + 16) & 63;
  int stage_v_78_2 = ((pub_r001716_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001716_21_1 * 2) + 43) & 63;
  int stage_v_79_2 = ((pub_r001716_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_39_1 + (pub_r001716_7_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_39_2 + (pub_r001716_7_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_67_1 + (pub_r001716_12_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_67_2 + (pub_r001716_12_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001716_16_1 * 2) + 28) & 63;
  int stage_v_82_2 = ((pub_r001716_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001716_4_1 * 2) + 39) & 63;
  int stage_v_83_2 = ((pub_r001716_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_4_1 + (pub_r001716_2_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_4_2 + (pub_r001716_2_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((helper_flow_1_1 + (pub_r001716_3_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((helper_flow_1_2 + (pub_r001716_3_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001716_7_1 * 2) + 31) & 63;
  int stage_v_86_2 = ((pub_r001716_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001716_19_1 * 2) + 38) & 63;
  int stage_v_87_2 = ((pub_r001716_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_55_1 + (pub_r001716_4_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_55_2 + (pub_r001716_4_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_19_1 + (pub_r001716_10_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_19_2 + (pub_r001716_10_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_32_1 + (pub_r001716_19_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_32_2 + (pub_r001716_19_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_36_1 + (pub_r001716_2_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_36_2 + (pub_r001716_2_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((helper_flow_7_1 + (pub_r001716_11_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((helper_flow_7_2 + (pub_r001716_11_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001716_21_1 * 2) + 11) & 63;
  int stage_v_93_2 = ((pub_r001716_21_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((sec_r001716_9_1 + (pub_r001716_17_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001716_9_2 + (pub_r001716_17_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_6_1 + (pub_r001716_10_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_6_2 + (pub_r001716_10_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001716_13_1 + (pub_r001716_18_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001716_13_2 + (pub_r001716_18_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001716_21_1 * 2) + 10) & 63;
  int stage_v_97_2 = ((pub_r001716_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_47_1 + (pub_r001716_0_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_47_2 + (pub_r001716_0_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_0_1 + (pub_r001716_12_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_0_2 + (pub_r001716_12_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_16_1 + (pub_r001716_20_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_16_2 + (pub_r001716_20_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_96_1 + (pub_r001716_9_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_96_2 + (pub_r001716_9_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001716_14_1 * 2) + 46) & 63;
  int stage_v_102_2 = ((pub_r001716_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_94_1 + (pub_r001716_8_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_94_2 + (pub_r001716_8_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_59_1 + (pub_r001716_12_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_59_2 + (pub_r001716_12_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_68_1 + (pub_r001716_14_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_68_2 + (pub_r001716_14_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001716_7_1 * 2) + 32) & 63;
  int stage_v_106_2 = ((pub_r001716_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_17_1 + (pub_r001716_7_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_17_2 + (pub_r001716_7_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_92_1 + (pub_r001716_21_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_92_2 + (pub_r001716_21_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((sec_r001716_8_1 + (pub_r001716_9_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((sec_r001716_8_2 + (pub_r001716_9_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_99_1 + (pub_r001716_19_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_99_2 + (pub_r001716_19_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((pub_r001716_8_1 * 2) + 7) & 63;
  int stage_v_111_2 = ((pub_r001716_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001716_9_1 * 2) + 8) & 63;
  int stage_v_112_2 = ((pub_r001716_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_94_1 + (pub_r001716_6_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_94_2 + (pub_r001716_6_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001716_10_1 * 2) + 26) & 63;
  int stage_v_114_2 = ((pub_r001716_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001716_6_1 * 2) + 32) & 63;
  int stage_v_115_2 = ((pub_r001716_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_27_1 + (pub_r001716_20_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_27_2 + (pub_r001716_20_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_60_1 + (pub_r001716_1_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_60_2 + (pub_r001716_1_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_107_1 + (pub_r001716_9_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_107_2 + (pub_r001716_9_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_91_1 + (pub_r001716_20_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_91_2 + (pub_r001716_20_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001716_11_1 * 2) + 31) & 63;
  int stage_v_120_2 = ((pub_r001716_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_94_1 + (pub_r001716_4_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_94_2 + (pub_r001716_4_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((sec_r001716_6_1 + (pub_r001716_0_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001716_6_2 + (pub_r001716_0_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_41_1 + (pub_r001716_19_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_41_2 + (pub_r001716_19_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001716_1_1 * 2) + 29) & 63;
  int stage_v_124_2 = ((pub_r001716_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_71_1 + (pub_r001716_18_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_71_2 + (pub_r001716_18_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001716_7_1 * 2) + 23) & 63;
  int stage_v_126_2 = ((pub_r001716_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_7_1 + (pub_r001716_6_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_7_2 + (pub_r001716_6_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_29_1 + (pub_r001716_15_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_29_2 + (pub_r001716_15_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001716_19_1 * 2) + 18) & 63;
  int stage_v_129_2 = ((pub_r001716_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_128_1 + (pub_r001716_8_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_128_2 + (pub_r001716_8_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_3_1 + (pub_r001716_4_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_3_2 + (pub_r001716_4_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001716_1_1 + (pub_r001716_7_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001716_1_2 + (pub_r001716_7_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_123_1 + (pub_r001716_1_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_123_2 + (pub_r001716_1_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001716_9_1 * 2) + 7) & 63;
  int stage_v_134_2 = ((pub_r001716_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_22_1 + (pub_r001716_3_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_22_2 + (pub_r001716_3_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_131_1 + (pub_r001716_21_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_131_2 + (pub_r001716_21_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001716_19_1 * 2) + 5) & 63;
  int stage_v_137_2 = ((pub_r001716_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001716_4_1 * 2) + 8) & 63;
  int stage_v_138_2 = ((pub_r001716_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001716_0_1 * 2) + 17) & 63;
  int stage_v_139_2 = ((pub_r001716_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001716_3_1 * 2) + 22) & 63;
  int stage_v_140_2 = ((pub_r001716_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((helper_flow_7_1 + (pub_r001716_12_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((helper_flow_7_2 + (pub_r001716_12_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_65_1 + (pub_r001716_21_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_65_2 + (pub_r001716_21_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_33_1 + (pub_r001716_16_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_33_2 + (pub_r001716_16_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001716_19_1 * 2) + 47) & 63;
  int stage_v_144_2 = ((pub_r001716_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001716_9_1 * 2) + 42) & 63;
  int stage_v_145_2 = ((pub_r001716_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001716_7_1 * 2) + 23) & 63;
  int stage_v_146_2 = ((pub_r001716_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_81_1 + (pub_r001716_18_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_81_2 + (pub_r001716_18_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_136_1 + (pub_r001716_12_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_136_2 + (pub_r001716_12_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001716_10_1 * 2) + 23) & 63;
  int stage_v_149_2 = ((pub_r001716_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_43_1 + (pub_r001716_13_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_43_2 + (pub_r001716_13_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001716_1_1 * 2) + 37) & 63;
  int stage_v_151_2 = ((pub_r001716_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((sec_r001716_11_1 + (pub_r001716_4_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((sec_r001716_11_2 + (pub_r001716_4_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_41_1 + (pub_r001716_9_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_41_2 + (pub_r001716_9_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_63_1 + (pub_r001716_0_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_63_2 + (pub_r001716_0_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_96_1 + (pub_r001716_14_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_96_2 + (pub_r001716_14_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((helper_flow_2_1 + (pub_r001716_2_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((helper_flow_2_2 + (pub_r001716_2_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001716_19_1 * 2) + 26) & 63;
  int stage_v_157_2 = ((pub_r001716_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001716_14_1 * 2) + 6) & 63;
  int stage_v_158_2 = ((pub_r001716_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_100_1 + (pub_r001716_0_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_100_2 + (pub_r001716_0_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((sec_r001716_9_1 + (pub_r001716_11_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((sec_r001716_9_2 + (pub_r001716_11_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_109_1 + (pub_r001716_17_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_109_2 + (pub_r001716_17_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001716_14_1 + (pub_r001716_3_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001716_14_2 + (pub_r001716_3_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_61_1 + (pub_r001716_4_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_61_2 + (pub_r001716_4_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001716_0_1 * 2) + 19) & 63;
  int stage_v_164_2 = ((pub_r001716_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_136_1 + (pub_r001716_13_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_136_2 + (pub_r001716_13_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_131_1 + (pub_r001716_11_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_131_2 + (pub_r001716_11_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_33_1 + (pub_r001716_17_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_33_2 + (pub_r001716_17_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_107_1 + (pub_r001716_10_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_107_2 + (pub_r001716_10_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001716_12_1 * 2) + 24) & 63;
  int stage_v_169_2 = ((pub_r001716_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_71_1 + (pub_r001716_12_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_71_2 + (pub_r001716_12_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001716_12_1 * 2) + 19) & 63;
  int stage_v_171_2 = ((pub_r001716_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001716_2_1 * 2) + 50) & 63;
  int stage_v_172_2 = ((pub_r001716_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_152_1 + (pub_r001716_5_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_152_2 + (pub_r001716_5_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_81_1 + (pub_r001716_3_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_81_2 + (pub_r001716_3_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_103_1 + (pub_r001716_17_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_103_2 + (pub_r001716_17_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_71_1 + (pub_r001716_0_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_71_2 + (pub_r001716_0_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_130_1 + (pub_r001716_4_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_130_2 + (pub_r001716_4_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001716_20_1 * 2) + 21) & 63;
  int stage_v_178_2 = ((pub_r001716_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001716_2_1 * 2) + 6) & 63;
  int stage_v_179_2 = ((pub_r001716_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_84_1 + (pub_r001716_10_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_84_2 + (pub_r001716_10_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_116_1 + (pub_r001716_13_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_116_2 + (pub_r001716_13_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_85_1 + (pub_r001716_3_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_85_2 + (pub_r001716_3_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001716_1_1 * 2) + 50) & 63;
  int stage_v_183_2 = ((pub_r001716_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_181_1 + (pub_r001716_17_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_181_2 + (pub_r001716_17_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_21_1 + (pub_r001716_16_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_21_2 + (pub_r001716_16_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_184_1 + (pub_r001716_8_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_184_2 + (pub_r001716_8_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_132_1 + (pub_r001716_17_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_132_2 + (pub_r001716_17_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001716_9_1 * 2) + 45) & 63;
  int stage_v_188_2 = ((pub_r001716_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_69_1 + (pub_r001716_12_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_69_2 + (pub_r001716_12_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_19_1 + (pub_r001716_17_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_19_2 + (pub_r001716_17_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_63_1 + (pub_r001716_14_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_63_2 + (pub_r001716_14_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001716_5_1 * 2) + 18) & 63;
  int stage_v_192_2 = ((pub_r001716_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_0_1 + (pub_r001716_2_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_0_2 + (pub_r001716_2_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_127_1 + (pub_r001716_7_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_127_2 + (pub_r001716_7_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((helper_flow_1_1 + (pub_r001716_2_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((helper_flow_1_2 + (pub_r001716_2_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001716_10_1 * 2) + 32) & 63;
  int stage_v_196_2 = ((pub_r001716_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((sec_r001716_0_1 + (pub_r001716_11_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((sec_r001716_0_2 + (pub_r001716_11_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001716_10_1 * 2) + 29) & 63;
  int stage_v_198_2 = ((pub_r001716_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001716_19_1 * 2) + 30) & 63;
  int stage_v_199_2 = ((pub_r001716_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_77_1 + (pub_r001716_17_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_77_2 + (pub_r001716_17_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001716_15_1 * 2) + 11) & 63;
  int stage_v_201_2 = ((pub_r001716_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_26_1 + (pub_r001716_2_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_26_2 + (pub_r001716_2_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001716_19_1 * 2) + 9) & 63;
  int stage_v_203_2 = ((pub_r001716_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_47_1 + (pub_r001716_12_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_47_2 + (pub_r001716_12_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001716_3_1 * 2) + 37) & 63;
  int stage_v_205_2 = ((pub_r001716_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001716_19_1 * 2) + 16) & 63;
  int stage_v_206_2 = ((pub_r001716_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001716_3_1 + (pub_r001716_16_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001716_3_2 + (pub_r001716_16_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_177_1 + (pub_r001716_10_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_177_2 + (pub_r001716_10_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001716_15_1 * 2) + 37) & 63;
  int stage_v_209_2 = ((pub_r001716_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_186_1 + (pub_r001716_21_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_186_2 + (pub_r001716_21_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((helper_flow_3_1 + (pub_r001716_0_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_3_2 + (pub_r001716_0_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001716_16_1 * 2) + 28) & 63;
  int stage_v_212_2 = ((pub_r001716_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001716_12_1 * 2) + 6) & 63;
  int stage_v_213_2 = ((pub_r001716_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_133_1 + (pub_r001716_3_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_133_2 + (pub_r001716_3_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001716_12_1 * 2) + 42) & 63;
  int stage_v_215_2 = ((pub_r001716_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001716_3_1 == pub_r001716_3_2);
  __CPROVER_assume(sec_r001716_8_1 != sec_r001716_8_2);
  __CPROVER_assume(sec_r001716_1_1 != sec_r001716_1_2);
  __CPROVER_assume(pub_r001716_7_1 == pub_r001716_7_2);
  __CPROVER_assume(pub_r001716_21_1 == pub_r001716_21_2);
  __CPROVER_assume(pub_r001716_5_1 == pub_r001716_5_2);
  __CPROVER_assume(sec_r001716_2_1 != sec_r001716_2_2);
  __CPROVER_assume(pub_r001716_19_1 == pub_r001716_19_2);
  __CPROVER_assume(sec_r001716_14_1 != sec_r001716_14_2);
  __CPROVER_assume(pub_r001716_12_1 == pub_r001716_12_2);
  __CPROVER_assume(pub_r001716_8_1 == pub_r001716_8_2);
  __CPROVER_assume(pub_r001716_0_1 == pub_r001716_0_2);
  __CPROVER_assume(pub_r001716_4_1 == pub_r001716_4_2);
  __CPROVER_assume(sec_r001716_0_1 != sec_r001716_0_2);
  __CPROVER_assume(sec_r001716_3_1 != sec_r001716_3_2);
  __CPROVER_assume(pub_r001716_10_1 == pub_r001716_10_2);
  __CPROVER_assume(sec_r001716_4_1 != sec_r001716_4_2);
  __CPROVER_assume(sec_r001716_13_1 != sec_r001716_13_2);
  __CPROVER_assume(sec_r001716_16_1 != sec_r001716_16_2);
  __CPROVER_assume(pub_r001716_18_1 == pub_r001716_18_2);
  __CPROVER_assume(pub_r001716_17_1 == pub_r001716_17_2);
  __CPROVER_assume(pub_r001716_9_1 == pub_r001716_9_2);
  __CPROVER_assume(pub_r001716_16_1 == pub_r001716_16_2);
  __CPROVER_assume(sec_r001716_17_1 != sec_r001716_17_2);
  __CPROVER_assume(sec_r001716_15_1 != sec_r001716_15_2);
  __CPROVER_assume(sec_r001716_6_1 != sec_r001716_6_2);
  __CPROVER_assume(sec_r001716_9_1 != sec_r001716_9_2);
  __CPROVER_assume(sec_r001716_10_1 != sec_r001716_10_2);
  __CPROVER_assume(pub_r001716_1_1 == pub_r001716_1_2);
  __CPROVER_assume(sec_r001716_11_1 != sec_r001716_11_2);
  __CPROVER_assume(sec_r001716_7_1 != sec_r001716_7_2);
  __CPROVER_assume(sec_r001716_5_1 != sec_r001716_5_2);
  __CPROVER_assume(pub_r001716_20_1 == pub_r001716_20_2);
  __CPROVER_assume(pub_r001716_14_1 == pub_r001716_14_2);
  __CPROVER_assume(pub_r001716_13_1 == pub_r001716_13_2);
  __CPROVER_assume(pub_r001716_15_1 == pub_r001716_15_2);
  __CPROVER_assume(pub_r001716_6_1 == pub_r001716_6_2);
  __CPROVER_assume(pub_r001716_11_1 == pub_r001716_11_2);
  __CPROVER_assume(sec_r001716_12_1 != sec_r001716_12_2);
  __CPROVER_assume(pub_r001716_2_1 == pub_r001716_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
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
}


