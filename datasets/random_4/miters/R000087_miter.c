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
struct MatrixBlock_R000087_8713_0
{
  short stride;
  int density;
  int dim;
  short determinant;
  short scale;
  int buffer[3];
};
struct Vector3D_R000087_8713_1
{
  int coord_x;
  int heading;
  short norm_sq;
  unsigned char coord_z;
  int buffer[3];
};
struct StreamBuffer_R000087_8713_2
{
  int capacity;
  unsigned char tail;
  int checksum;
  int head;
  int buffer[3];
};
struct SensorNode_R000087_8713_3
{
  int calib;
  int gain;
  short offset;
  short reading;
  short status;
  int buffer[3];
};
union PacketPayload_R000087_8713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000087_8713_1
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
void fn_R000087_8713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st_1 = {0};
  struct SensorNode_R000087_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int pivot_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_94_1) & 63;
  aux_2 = (aux_2 + pivot_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_52_1 = local_arr_1[aux_1 % 3];
  int window_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_94_1 == pivot_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_52_1 == window_52_2);
}

int fn_R000087_8713_0(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int pivot_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_94) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_52 = local_arr[aux % 3];
  acc = (acc + (window_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000087_8713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st_1 = {0};
  struct SensorNode_R000087_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_27_1 = 0;
  int mask_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_27_1 = ((mask_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_27_2 = ((mask_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_27_1) & 127;
    acc_2 = (acc_2 + mask_27_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_32_1 = local_arr_1[aux_1 % 3];
  int cursor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_27_1 == mask_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_32_1 == cursor_32_2);
}

int fn_R000087_8713_1(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_27 = ((mask_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_27) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_32 = local_arr[aux % 3];
  acc = (acc + (cursor_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000087_8713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st_1 = {0};
  struct SensorNode_R000087_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_84_1)
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

  switch (mask_84_2)
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

  int accumulator_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_99_1 > 35)
  {
    acc_1 = ((acc_1 + (accumulator_99_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_99_2 > 35)
  {
    acc_2 = ((acc_2 + (accumulator_99_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_84_1 == mask_84_2);
  assert(accumulator_99_1 == accumulator_99_2);
}

int fn_R000087_8713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_84 = (aux + st.buffer[1]) & 3;
  switch (mask_84)
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

  int accumulator_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_99 > 35)
  {
    acc = ((acc + (accumulator_99 * 2)) + 5) & 127;
    aux ^= accumulator_99 & 15;
  }
  else
  {
    acc = ((acc - accumulator_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000087_8713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st_1 = {0};
  struct StreamBuffer_R000087_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int anchor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_72_1) & 63;
  aux_2 = (aux_2 + anchor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_25_1)
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

  switch (index_reg_25_2)
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

  int cursor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_31_1 > 25)
  {
    acc_1 = ((acc_1 + (cursor_31_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_31_2 > 25)
  {
    acc_2 = ((acc_2 + (cursor_31_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_72_1 == anchor_72_2);
  assert(index_reg_25_1 == index_reg_25_2);
  assert(cursor_31_1 == cursor_31_2);
}

int fn_R000087_8713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_72) & 63;
  acc ^= aux;
  int index_reg_25 = (aux + st.buffer[1]) & 3;
  switch (index_reg_25)
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

  int cursor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_31 > 25)
  {
    acc = ((acc + (cursor_31 * 2)) + 5) & 127;
    aux ^= cursor_31 & 15;
  }
  else
  {
    acc = ((acc - cursor_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000087_8713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st_1 = {0};
  struct SensorNode_R000087_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_80_1 = local_arr_1[aux_1 % 3];
  int parity_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_80_2 * 2)) & 127;
  int quantum_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_43_1 > 28)
  {
    acc_1 = ((acc_1 + (quantum_43_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_43_2 > 28)
  {
    acc_2 = ((acc_2 + (quantum_43_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_39_1) & 63;
  aux_2 = (aux_2 + margin_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_98_1 = 0;
  int index_reg_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_98_1 = ((index_reg_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_98_2 = ((index_reg_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_98_1) & 127;
    acc_2 = (acc_2 + index_reg_98_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_80_1 == parity_80_2);
  assert(quantum_43_1 == quantum_43_2);
  assert(margin_39_1 == margin_39_2);
  assert(index_reg_98_1 == index_reg_98_2);
}

int fn_R000087_8713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int parity_80 = local_arr[aux % 3];
  acc = (acc + (parity_80 * 2)) & 127;
  int quantum_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_43 > 28)
  {
    acc = ((acc + (quantum_43 * 2)) + 5) & 127;
    aux ^= quantum_43 & 15;
  }
  else
  {
    acc = ((acc - quantum_43) + 11) & 127;
    aux += 3;
  }
  int margin_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_39) & 63;
  acc ^= aux;
  int index_reg_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_98 = ((index_reg_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_98) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000087_8713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st_1 = {0};
  struct MatrixBlock_R000087_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_82_1 = 0;
  int phase_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_82_1 = ((phase_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_82_2 = ((phase_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_82_1) & 127;
    acc_2 = (acc_2 + phase_82_2) & 127;
  }

  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_83_1 = local_arr_1[aux_1 % 3];
  int checksum_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_82_1 == phase_82_2);
  assert(phase_21_1 == phase_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_83_1 == checksum_83_2);
}

int fn_R000087_8713_5(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_82 = ((phase_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_82) & 127;
  }

  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_83 = local_arr[aux % 3];
  acc = (acc + (checksum_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000087_8713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st_1 = {0};
  struct StreamBuffer_R000087_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_34_1)
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

  switch (quotient_34_2)
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

  int coefficient_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_95_1) & 63;
  aux_2 = (aux_2 + coefficient_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_55_1 = local_arr_1[aux_1 % 3];
  int segment_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_55_2 * 2)) & 127;
  int vector_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_52_1 > 33)
  {
    acc_1 = ((acc_1 + (vector_52_1 * 2)) + 5) & 127;
    aux_1 ^= vector_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_52_2 > 33)
  {
    acc_2 = ((acc_2 + (vector_52_2 * 2)) + 5) & 127;
    aux_2 ^= vector_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_34_1 == quotient_34_2);
  assert(coefficient_95_1 == coefficient_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_55_1 == segment_55_2);
  assert(vector_52_1 == vector_52_2);
}

int fn_R000087_8713_6(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_34 = (aux + st.buffer[1]) & 3;
  switch (quotient_34)
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

  int coefficient_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_55 = local_arr[aux % 3];
  acc = (acc + (segment_55 * 2)) & 127;
  int vector_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_52 > 33)
  {
    acc = ((acc + (vector_52 * 2)) + 5) & 127;
    aux ^= vector_52 & 15;
  }
  else
  {
    acc = ((acc - vector_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000087_8713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000087_8713_1 st_1 = {0};
  struct Vector3D_R000087_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tracker_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_15_1 > 22)
  {
    acc_1 = ((acc_1 + (tracker_15_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_15_2 > 22)
  {
    acc_2 = ((acc_2 + (tracker_15_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_43_1 = 0;
  int segment_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_43_1 = ((segment_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_43_2 = ((segment_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_43_1) & 127;
    acc_2 = (acc_2 + segment_43_2) & 127;
  }

  int tally_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_71_1) & 63;
  aux_2 = (aux_2 + tally_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_99_1)
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

  switch (scale_99_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_15_1 == tracker_15_2);
  assert(segment_43_1 == segment_43_2);
  assert(tally_71_1 == tally_71_2);
  assert(scale_99_1 == scale_99_2);
}

int fn_R000087_8713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000087_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tracker_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_15 > 22)
  {
    acc = ((acc + (tracker_15 * 2)) + 5) & 127;
    aux ^= tracker_15 & 15;
  }
  else
  {
    acc = ((acc - tracker_15) + 11) & 127;
    aux += 3;
  }
  int segment_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_43 = ((segment_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_43) & 127;
  }

  int tally_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_71) & 63;
  acc ^= aux;
  int scale_99 = (aux + st.buffer[1]) & 3;
  switch (scale_99)
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

void fn_R000087_8713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st_1 = {0};
  struct SensorNode_R000087_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int mask_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_18_1) & 63;
  aux_2 = (aux_2 + mask_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_64_1 = local_arr_1[aux_1 % 3];
  int offset_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_18_1 == mask_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_64_1 == offset_64_2);
}

int fn_R000087_8713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000087_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int mask_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_64 = local_arr[aux % 3];
  acc = (acc + (offset_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000087_8713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st_1 = {0};
  struct MatrixBlock_R000087_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_51_1 = local_arr_1[aux_1 % 3];
  int scale_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_51_2 * 2)) & 127;
  int stride_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_61_1) & 63;
  aux_2 = (aux_2 + stride_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_78_1 = 0;
  int cursor_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_78_1 = ((cursor_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_78_2 = ((cursor_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_78_1) & 127;
    acc_2 = (acc_2 + cursor_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_51_1 == scale_51_2);
  assert(stride_61_1 == stride_61_2);
  assert(cursor_78_1 == cursor_78_2);
}

int fn_R000087_8713_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int scale_51 = local_arr[aux % 3];
  acc = (acc + (scale_51 * 2)) & 127;
  int stride_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_61) & 63;
  acc ^= aux;
  int cursor_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_78 = ((cursor_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000087_8713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000087_8713_1 st_1 = {0};
  struct Vector3D_R000087_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_99_1) & 63;
  aux_2 = (aux_2 + quotient_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_76_1 = 0;
  int sample_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_76_1 = ((sample_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_76_2 = ((sample_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_76_1) & 127;
    acc_2 = (acc_2 + sample_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_99_1 == quotient_99_2);
  assert(sample_76_1 == sample_76_2);
}

int fn_R000087_8713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000087_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_99) & 63;
  acc ^= aux;
  int sample_76 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_76 = ((sample_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_76) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000087_8713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st_1 = {0};
  struct StreamBuffer_R000087_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_49_1 = local_arr_1[aux_1 % 3];
  int tracker_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_49_2 * 2)) & 127;
  int scale_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_46_1)
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

  switch (scale_46_2)
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
  int quotient_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_84_1) & 63;
  aux_2 = (aux_2 + quotient_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_49_1 == tracker_49_2);
  assert(scale_46_1 == scale_46_2);
  assert(quotient_84_1 == quotient_84_2);
}

int fn_R000087_8713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int tracker_49 = local_arr[aux % 3];
  acc = (acc + (tracker_49 * 2)) & 127;
  int scale_46 = (aux + st.buffer[1]) & 3;
  switch (scale_46)
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
  int quotient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000087_8713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st_1 = {0};
  struct StreamBuffer_R000087_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_57_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_57_1 * 2)) + 5) & 127;
    aux_1 ^= offset_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_57_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_57_2 * 2)) + 5) & 127;
    aux_2 ^= offset_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_79_1) & 63;
  aux_2 = (aux_2 + scale_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_57_1 == offset_57_2);
  assert(scale_79_1 == scale_79_2);
}

int fn_R000087_8713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000087_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_57 > 25)
  {
    acc = ((acc + (offset_57 * 2)) + 5) & 127;
    aux ^= offset_57 & 15;
  }
  else
  {
    acc = ((acc - offset_57) + 11) & 127;
    aux += 3;
  }
  int scale_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000087_8713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st_1 = {0};
  struct MatrixBlock_R000087_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_21_1 = local_arr_1[aux_1 % 3];
  int cursor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_16_1 == weight_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_21_1 == cursor_21_2);
}

int fn_R000087_8713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000087_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
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

  int local_arr[3] = {4, 9, 15};
  int cursor_21 = local_arr[aux % 3];
  acc = (acc + (cursor_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000087_0_1;
  int sec_r000087_0_2;
  int sec_r000087_1_1;
  int sec_r000087_1_2;
  int sec_r000087_2_1;
  int sec_r000087_2_2;
  int sec_r000087_3_1;
  int sec_r000087_3_2;
  int sec_r000087_4_1;
  int sec_r000087_4_2;
  int sec_r000087_5_1;
  int sec_r000087_5_2;
  int sec_r000087_6_1;
  int sec_r000087_6_2;
  int sec_r000087_7_1;
  int sec_r000087_7_2;
  int sec_r000087_8_1;
  int sec_r000087_8_2;
  int sec_r000087_9_1;
  int sec_r000087_9_2;
  int sec_r000087_10_1;
  int sec_r000087_10_2;
  int sec_r000087_11_1;
  int sec_r000087_11_2;
  int sec_r000087_12_1;
  int sec_r000087_12_2;
  int sec_r000087_13_1;
  int sec_r000087_13_2;
  int sec_r000087_14_1;
  int sec_r000087_14_2;
  int sec_r000087_15_1;
  int sec_r000087_15_2;
  int sec_r000087_16_1;
  int sec_r000087_16_2;
  int sec_r000087_17_1;
  int sec_r000087_17_2;
  int sec_r000087_18_1;
  int sec_r000087_18_2;
  int pub_r000087_0_1;
  int pub_r000087_0_2;
  int pub_r000087_1_1;
  int pub_r000087_1_2;
  int pub_r000087_2_1;
  int pub_r000087_2_2;
  int pub_r000087_3_1;
  int pub_r000087_3_2;
  int pub_r000087_4_1;
  int pub_r000087_4_2;
  int pub_r000087_5_1;
  int pub_r000087_5_2;
  int pub_r000087_6_1;
  int pub_r000087_6_2;
  int pub_r000087_7_1;
  int pub_r000087_7_2;
  int pub_r000087_8_1;
  int pub_r000087_8_2;
  int pub_r000087_9_1;
  int pub_r000087_9_2;
  int pub_r000087_10_1;
  int pub_r000087_10_2;
  int pub_r000087_11_1;
  int pub_r000087_11_2;
  int pub_r000087_12_1;
  int pub_r000087_12_2;
  int pub_r000087_13_1;
  int pub_r000087_13_2;
  int pub_r000087_14_1;
  int pub_r000087_14_2;
  int pub_r000087_15_1;
  int pub_r000087_15_2;
  int pub_r000087_16_1;
  int pub_r000087_16_2;
  int pub_r000087_17_1;
  int pub_r000087_17_2;
  int pub_r000087_18_1;
  int pub_r000087_18_2;
  int pub_r000087_19_1;
  int pub_r000087_19_2;
  int pub_r000087_20_1;
  int pub_r000087_20_2;
  int pub_r000087_21_1;
  int pub_r000087_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000087_0_1 >= (-100)) && (pub_r000087_0_1 <= 100));
  __CPROVER_assume((pub_r000087_0_2 >= (-100)) && (pub_r000087_0_2 <= 100));
  __CPROVER_assume((pub_r000087_1_1 >= (-100)) && (pub_r000087_1_1 <= 100));
  __CPROVER_assume((pub_r000087_1_2 >= (-100)) && (pub_r000087_1_2 <= 100));
  __CPROVER_assume((pub_r000087_2_1 >= (-100)) && (pub_r000087_2_1 <= 100));
  __CPROVER_assume((pub_r000087_2_2 >= (-100)) && (pub_r000087_2_2 <= 100));
  __CPROVER_assume((pub_r000087_3_1 >= (-100)) && (pub_r000087_3_1 <= 100));
  __CPROVER_assume((pub_r000087_3_2 >= (-100)) && (pub_r000087_3_2 <= 100));
  __CPROVER_assume((pub_r000087_4_1 >= (-100)) && (pub_r000087_4_1 <= 100));
  __CPROVER_assume((pub_r000087_4_2 >= (-100)) && (pub_r000087_4_2 <= 100));
  __CPROVER_assume((pub_r000087_5_1 >= (-100)) && (pub_r000087_5_1 <= 100));
  __CPROVER_assume((pub_r000087_5_2 >= (-100)) && (pub_r000087_5_2 <= 100));
  __CPROVER_assume((pub_r000087_6_1 >= (-100)) && (pub_r000087_6_1 <= 100));
  __CPROVER_assume((pub_r000087_6_2 >= (-100)) && (pub_r000087_6_2 <= 100));
  __CPROVER_assume((pub_r000087_7_1 >= (-100)) && (pub_r000087_7_1 <= 100));
  __CPROVER_assume((pub_r000087_7_2 >= (-100)) && (pub_r000087_7_2 <= 100));
  __CPROVER_assume((pub_r000087_8_1 >= (-100)) && (pub_r000087_8_1 <= 100));
  __CPROVER_assume((pub_r000087_8_2 >= (-100)) && (pub_r000087_8_2 <= 100));
  __CPROVER_assume((pub_r000087_9_1 >= (-100)) && (pub_r000087_9_1 <= 100));
  __CPROVER_assume((pub_r000087_9_2 >= (-100)) && (pub_r000087_9_2 <= 100));
  __CPROVER_assume((pub_r000087_10_1 >= (-100)) && (pub_r000087_10_1 <= 100));
  __CPROVER_assume((pub_r000087_10_2 >= (-100)) && (pub_r000087_10_2 <= 100));
  __CPROVER_assume((pub_r000087_11_1 >= (-100)) && (pub_r000087_11_1 <= 100));
  __CPROVER_assume((pub_r000087_11_2 >= (-100)) && (pub_r000087_11_2 <= 100));
  __CPROVER_assume((pub_r000087_12_1 >= (-100)) && (pub_r000087_12_1 <= 100));
  __CPROVER_assume((pub_r000087_12_2 >= (-100)) && (pub_r000087_12_2 <= 100));
  __CPROVER_assume((pub_r000087_13_1 >= (-100)) && (pub_r000087_13_1 <= 100));
  __CPROVER_assume((pub_r000087_13_2 >= (-100)) && (pub_r000087_13_2 <= 100));
  __CPROVER_assume((pub_r000087_14_1 >= (-100)) && (pub_r000087_14_1 <= 100));
  __CPROVER_assume((pub_r000087_14_2 >= (-100)) && (pub_r000087_14_2 <= 100));
  __CPROVER_assume((pub_r000087_15_1 >= (-100)) && (pub_r000087_15_1 <= 100));
  __CPROVER_assume((pub_r000087_15_2 >= (-100)) && (pub_r000087_15_2 <= 100));
  __CPROVER_assume((pub_r000087_16_1 >= (-100)) && (pub_r000087_16_1 <= 100));
  __CPROVER_assume((pub_r000087_16_2 >= (-100)) && (pub_r000087_16_2 <= 100));
  __CPROVER_assume((pub_r000087_17_1 >= (-100)) && (pub_r000087_17_1 <= 100));
  __CPROVER_assume((pub_r000087_17_2 >= (-100)) && (pub_r000087_17_2 <= 100));
  __CPROVER_assume((pub_r000087_18_1 >= (-100)) && (pub_r000087_18_1 <= 100));
  __CPROVER_assume((pub_r000087_18_2 >= (-100)) && (pub_r000087_18_2 <= 100));
  __CPROVER_assume((pub_r000087_19_1 >= (-100)) && (pub_r000087_19_1 <= 100));
  __CPROVER_assume((pub_r000087_19_2 >= (-100)) && (pub_r000087_19_2 <= 100));
  __CPROVER_assume((pub_r000087_20_1 >= (-100)) && (pub_r000087_20_1 <= 100));
  __CPROVER_assume((pub_r000087_20_2 >= (-100)) && (pub_r000087_20_2 <= 100));
  __CPROVER_assume((pub_r000087_21_1 >= (-100)) && (pub_r000087_21_1 <= 100));
  __CPROVER_assume((pub_r000087_21_2 >= (-100)) && (pub_r000087_21_2 <= 100));
  __CPROVER_assume((sec_r000087_0_1 >= 0) && (sec_r000087_0_1 <= 255));
  __CPROVER_assume((sec_r000087_0_2 >= 0) && (sec_r000087_0_2 <= 255));
  __CPROVER_assume((sec_r000087_1_1 >= 0) && (sec_r000087_1_1 <= 255));
  __CPROVER_assume((sec_r000087_1_2 >= 0) && (sec_r000087_1_2 <= 255));
  __CPROVER_assume((sec_r000087_2_1 >= 0) && (sec_r000087_2_1 <= 255));
  __CPROVER_assume((sec_r000087_2_2 >= 0) && (sec_r000087_2_2 <= 255));
  __CPROVER_assume((sec_r000087_3_1 >= 0) && (sec_r000087_3_1 <= 255));
  __CPROVER_assume((sec_r000087_3_2 >= 0) && (sec_r000087_3_2 <= 255));
  __CPROVER_assume((sec_r000087_4_1 >= 0) && (sec_r000087_4_1 <= 255));
  __CPROVER_assume((sec_r000087_4_2 >= 0) && (sec_r000087_4_2 <= 255));
  __CPROVER_assume((sec_r000087_5_1 >= 0) && (sec_r000087_5_1 <= 255));
  __CPROVER_assume((sec_r000087_5_2 >= 0) && (sec_r000087_5_2 <= 255));
  __CPROVER_assume((sec_r000087_6_1 >= 0) && (sec_r000087_6_1 <= 255));
  __CPROVER_assume((sec_r000087_6_2 >= 0) && (sec_r000087_6_2 <= 255));
  __CPROVER_assume((sec_r000087_7_1 >= 0) && (sec_r000087_7_1 <= 255));
  __CPROVER_assume((sec_r000087_7_2 >= 0) && (sec_r000087_7_2 <= 255));
  __CPROVER_assume((sec_r000087_8_1 >= 0) && (sec_r000087_8_1 <= 255));
  __CPROVER_assume((sec_r000087_8_2 >= 0) && (sec_r000087_8_2 <= 255));
  __CPROVER_assume((sec_r000087_9_1 >= 0) && (sec_r000087_9_1 <= 255));
  __CPROVER_assume((sec_r000087_9_2 >= 0) && (sec_r000087_9_2 <= 255));
  __CPROVER_assume((sec_r000087_10_1 >= 0) && (sec_r000087_10_1 <= 255));
  __CPROVER_assume((sec_r000087_10_2 >= 0) && (sec_r000087_10_2 <= 255));
  __CPROVER_assume((sec_r000087_11_1 >= 0) && (sec_r000087_11_1 <= 255));
  __CPROVER_assume((sec_r000087_11_2 >= 0) && (sec_r000087_11_2 <= 255));
  __CPROVER_assume((sec_r000087_12_1 >= 0) && (sec_r000087_12_1 <= 255));
  __CPROVER_assume((sec_r000087_12_2 >= 0) && (sec_r000087_12_2 <= 255));
  __CPROVER_assume((sec_r000087_13_1 >= 0) && (sec_r000087_13_1 <= 255));
  __CPROVER_assume((sec_r000087_13_2 >= 0) && (sec_r000087_13_2 <= 255));
  __CPROVER_assume((sec_r000087_14_1 >= 0) && (sec_r000087_14_1 <= 255));
  __CPROVER_assume((sec_r000087_14_2 >= 0) && (sec_r000087_14_2 <= 255));
  __CPROVER_assume((sec_r000087_15_1 >= 0) && (sec_r000087_15_1 <= 255));
  __CPROVER_assume((sec_r000087_15_2 >= 0) && (sec_r000087_15_2 <= 255));
  __CPROVER_assume((sec_r000087_16_1 >= 0) && (sec_r000087_16_1 <= 255));
  __CPROVER_assume((sec_r000087_16_2 >= 0) && (sec_r000087_16_2 <= 255));
  __CPROVER_assume((sec_r000087_17_1 >= 0) && (sec_r000087_17_1 <= 255));
  __CPROVER_assume((sec_r000087_17_2 >= 0) && (sec_r000087_17_2 <= 255));
  __CPROVER_assume((sec_r000087_18_1 >= 0) && (sec_r000087_18_1 <= 255));
  __CPROVER_assume((sec_r000087_18_2 >= 0) && (sec_r000087_18_2 <= 255));
  struct MatrixBlock_R000087_8713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000087_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000087_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000087_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000087_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000087_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000087_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000087_0_2 + 7) & 15;
  struct Vector3D_R000087_8713_1 st_var_1_1 = {0};
  struct Vector3D_R000087_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000087_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000087_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000087_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000087_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000087_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000087_0_2 + 9) & 15;
  struct StreamBuffer_R000087_8713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000087_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000087_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000087_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000087_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000087_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000087_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000087_0_2 + 11) & 15;
  struct SensorNode_R000087_8713_3 st_var_3_1 = {0};
  struct SensorNode_R000087_8713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000087_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000087_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000087_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000087_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000087_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000087_0_2 + 13) & 15;
  union PacketPayload_R000087_8713_0 u_var_1;
  union PacketPayload_R000087_8713_0 u_var_2;
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 50)
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
  if (stage_v_3_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 50)
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
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

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
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 36)
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
  if (stage_v_31_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 36)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 28)
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
  if (stage_v_34_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 28)
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
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 52)
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
  if (stage_v_39_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 52)
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
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 43) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 44)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 44)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 41)
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
  if (stage_v_50_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 41)
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
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 55) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 48)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 48)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (st_var_3_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_3_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 25)
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
  if (stage_v_60_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 25)
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
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
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
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((st_var_2_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_2_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 38)
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
  if (stage_v_66_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 38)
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
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 71) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_77_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 82) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((st_var_3_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_3_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 51)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 51)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_86_1 = (st_var_2_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_2_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

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
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = (st_var_2_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_2_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_92_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 95) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 95) & 15;
  int stage_v_94_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_94_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= stage_v_94_1;
  chk_sum_2 ^= stage_v_94_2;
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
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  int stage_v_97_1 = ((st_var_1_1.buffer[1] * 2) + 298) & 63;
  int stage_v_97_2 = ((st_var_1_2.buffer[1] * 2) + 298) & 63;
  if (stage_v_97_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_97_1) - 5) & 255;
    if (stage_v_97_1 > 53)
    {
      chk_sum_1 ^= stage_v_97_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_97_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_97_2) - 5) & 255;
    if (stage_v_97_2 > 53)
    {
      chk_sum_2 ^= stage_v_97_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  if (stage_v_103_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 47)
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
  if (stage_v_103_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 47)
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
  int stage_v_104_1 = ((st_var_0_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_0_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 29)
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
  if (stage_v_104_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 29)
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
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_107_1 = (st_var_3_1.buffer[0] ^ 110) & 3;
  int stage_v_107_2 = (st_var_3_2.buffer[0] ^ 110) & 3;
  switch (stage_v_107_1)
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

  switch (stage_v_107_2)
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

  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = ((st_var_3_1.buffer[0] * 2) + 340) & 63;
  int stage_v_111_2 = ((st_var_3_2.buffer[0] * 2) + 340) & 63;
  if (stage_v_111_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_111_1) - 5) & 255;
    if (stage_v_111_1 > 55)
    {
      chk_sum_1 ^= stage_v_111_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_111_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_111_2) - 5) & 255;
    if (stage_v_111_2 > 55)
    {
      chk_sum_2 ^= stage_v_111_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_112_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_112_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_113_1 = (st_var_1_1.buffer[0] ^ 116) & 3;
  int stage_v_113_2 = (st_var_1_2.buffer[0] ^ 116) & 3;
  switch (stage_v_113_1)
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

  switch (stage_v_113_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 115) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = (st_var_3_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_3_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_117_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_118_1 = ((st_var_2_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_2_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 42)
    {
      chk_sum_1 ^= stage_v_118_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 42)
    {
      chk_sum_2 ^= stage_v_118_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_119_1 = ((st_var_3_1.buffer[2] * 2) + 364) & 63;
  int stage_v_119_2 = ((st_var_3_2.buffer[2] * 2) + 364) & 63;
  if (stage_v_119_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_119_1) - 5) & 255;
    if (stage_v_119_1 > 34)
    {
      chk_sum_1 ^= stage_v_119_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_119_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_119_2) - 5) & 255;
    if (stage_v_119_2 > 34)
    {
      chk_sum_2 ^= stage_v_119_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
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
  int stage_v_122_1 = table_1[2];
  int stage_v_122_2 = table_2[2];
  table_1[2] = (table_1[3] + 245) & 63;
  table_2[2] = (table_2[3] + 245) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 124) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 125) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  int stage_v_125_1 = ((st_var_1_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_1_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 51)
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
  if (stage_v_125_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 51)
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
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (st_var_1_1.buffer[0] ^ 132) & 3;
  int stage_v_129_2 = (st_var_1_2.buffer[0] ^ 132) & 3;
  switch (stage_v_129_1)
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

  switch (stage_v_129_2)
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

  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_131_1 = ((st_var_3_1.buffer[2] * 2) + 400) & 63;
  int stage_v_131_2 = ((st_var_3_2.buffer[2] * 2) + 400) & 63;
  if (stage_v_131_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_131_1) - 5) & 255;
    if (stage_v_131_1 > 38)
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
  if (stage_v_131_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_131_2) - 5) & 255;
    if (stage_v_131_2 > 38)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 134) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 134) & 15;
  int stage_v_133_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_133_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= stage_v_133_1;
  chk_sum_2 ^= stage_v_133_2;
  int stage_v_134_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_134_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = table_1[3];
  int stage_v_139_2 = table_2[3];
  table_1[3] = (table_1[0] + 279) & 63;
  table_2[3] = (table_2[0] + 279) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (st_var_0_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_0_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = table_1[1];
  int stage_v_141_2 = table_2[1];
  table_1[1] = (table_1[2] + 283) & 63;
  table_2[1] = (table_2[2] + 283) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (st_var_2_1.buffer[0] ^ 145) & 3;
  int stage_v_142_2 = (st_var_2_2.buffer[0] ^ 145) & 3;
  switch (stage_v_142_1)
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

  switch (stage_v_142_2)
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

  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_144_1 = (st_var_0_1.buffer[0] ^ 147) & 3;
  int stage_v_144_2 = (st_var_0_2.buffer[0] ^ 147) & 3;
  switch (stage_v_144_1)
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

  switch (stage_v_144_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 146) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 146) & 15;
  int stage_v_145_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_145_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= stage_v_145_1;
  chk_sum_2 ^= stage_v_145_2;
  int stage_v_146_1 = (st_var_2_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_2_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
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

  switch (stage_v_150_2)
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

  int stage_v_151_1 = (st_var_3_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_3_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
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
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 156) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = table_1[0];
  int stage_v_156_2 = table_2[0];
  table_1[0] = (table_1[1] + 313) & 63;
  table_2[0] = (table_2[1] + 313) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_157_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_158_1 = table_1[2];
  int stage_v_158_2 = table_2[2];
  table_1[2] = (table_1[3] + 317) & 63;
  table_2[2] = (table_2[3] + 317) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((st_var_3_1.buffer[0] * 2) + 484) & 63;
  int stage_v_159_2 = ((st_var_3_2.buffer[0] * 2) + 484) & 63;
  if (stage_v_159_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_159_1) - 5) & 255;
    if (stage_v_159_1 > 52)
    {
      chk_sum_1 ^= stage_v_159_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_159_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_159_2) - 5) & 255;
    if (stage_v_159_2 > 52)
    {
      chk_sum_2 ^= stage_v_159_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_160_1 = table_1[0];
  int stage_v_160_2 = table_2[0];
  table_1[0] = (table_1[1] + 321) & 63;
  table_2[0] = (table_2[1] + 321) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_162_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (167 & 31);
  int stage_v_162_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (167 & 31);
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= (stage_v_162_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_162_2 << 1) & 127;
  int stage_v_163_1 = (st_var_3_1.buffer[0] ^ 166) & 3;
  int stage_v_163_2 = (st_var_3_2.buffer[0] ^ 166) & 3;
  switch (stage_v_163_1)
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

  switch (stage_v_163_2)
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

  int stage_v_164_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (169 & 31);
  int stage_v_164_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (169 & 31);
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= (stage_v_164_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_164_2 << 1) & 127;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = table_1[2];
  int stage_v_166_2 = table_2[2];
  table_1[2] = (table_1[3] + 333) & 63;
  table_2[2] = (table_2[3] + 333) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (172 & 31);
  int stage_v_167_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (172 & 31);
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= (stage_v_167_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_167_2 << 1) & 127;
  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 42)
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
  if (stage_v_168_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 42)
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
  int stage_v_169_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (174 & 31);
  int stage_v_169_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (174 & 31);
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= (stage_v_169_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_169_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 171) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 171) & 15;
  int stage_v_170_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_170_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= stage_v_170_1;
  chk_sum_2 ^= stage_v_170_2;
  int stage_v_171_1 = table_1[3];
  int stage_v_171_2 = table_2[3];
  table_1[3] = (table_1[0] + 343) & 63;
  table_2[3] = (table_2[0] + 343) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 29)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 29)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = ((st_var_1_1.buffer[2] * 2) + 526) & 63;
  int stage_v_173_2 = ((st_var_1_2.buffer[2] * 2) + 526) & 63;
  if (stage_v_173_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_173_1) - 5) & 255;
    if (stage_v_173_1 > 41)
    {
      chk_sum_1 ^= stage_v_173_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_173_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_173_2) - 5) & 255;
    if (stage_v_173_2 > 41)
    {
      chk_sum_2 ^= stage_v_173_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (st_var_1_1.buffer[0] ^ 180) & 3;
  int stage_v_177_2 = (st_var_1_2.buffer[0] ^ 180) & 3;
  switch (stage_v_177_1)
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

  switch (stage_v_177_2)
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

  int stage_v_178_1 = (st_var_2_1.buffer[0] ^ 181) & 3;
  int stage_v_178_2 = (st_var_2_2.buffer[0] ^ 181) & 3;
  switch (stage_v_178_1)
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

  switch (stage_v_178_2)
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

  int dead_sec_0_1 = (sec_r000087_2_1 ^ sec_r000087_2_1) * 0;
  int dead_sec_0_2 = (sec_r000087_2_2 ^ sec_r000087_2_2) * 0;
  int dead_sec_1_1 = ((sec_r000087_13_1 + 18) - (sec_r000087_13_1 + 18)) * 0;
  int dead_sec_1_2 = ((sec_r000087_13_2 + 18) - (sec_r000087_13_2 + 18)) * 0;
  int dead_sec_2_1 = (sec_r000087_1_1 ^ sec_r000087_1_1) * 0;
  int dead_sec_2_2 = (sec_r000087_1_2 ^ sec_r000087_1_2) * 0;
  int dead_sec_3_1 = ((sec_r000087_12_1 << 2) ^ (sec_r000087_12_1 << 2)) * 0;
  int dead_sec_3_2 = ((sec_r000087_12_2 << 2) ^ (sec_r000087_12_2 << 2)) * 0;
  out_sink_1 = ((((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) + dead_sec_2_1) + dead_sec_3_1) & 255;
  out_sink_2 = ((((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) + dead_sec_2_2) + dead_sec_3_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000087_11_1 == pub_r000087_11_2);
  __CPROVER_assume(sec_r000087_13_1 != sec_r000087_13_2);
  __CPROVER_assume(pub_r000087_2_1 == pub_r000087_2_2);
  __CPROVER_assume(sec_r000087_11_1 != sec_r000087_11_2);
  __CPROVER_assume(pub_r000087_20_1 == pub_r000087_20_2);
  __CPROVER_assume(pub_r000087_18_1 == pub_r000087_18_2);
  __CPROVER_assume(pub_r000087_9_1 == pub_r000087_9_2);
  __CPROVER_assume(pub_r000087_17_1 == pub_r000087_17_2);
  __CPROVER_assume(pub_r000087_8_1 == pub_r000087_8_2);
  __CPROVER_assume(pub_r000087_16_1 == pub_r000087_16_2);
  __CPROVER_assume(pub_r000087_3_1 == pub_r000087_3_2);
  __CPROVER_assume(pub_r000087_1_1 == pub_r000087_1_2);
  __CPROVER_assume(pub_r000087_14_1 == pub_r000087_14_2);
  __CPROVER_assume(sec_r000087_8_1 != sec_r000087_8_2);
  __CPROVER_assume(pub_r000087_15_1 == pub_r000087_15_2);
  __CPROVER_assume(pub_r000087_4_1 == pub_r000087_4_2);
  __CPROVER_assume(sec_r000087_15_1 != sec_r000087_15_2);
  __CPROVER_assume(sec_r000087_3_1 != sec_r000087_3_2);
  __CPROVER_assume(sec_r000087_4_1 != sec_r000087_4_2);
  __CPROVER_assume(sec_r000087_16_1 != sec_r000087_16_2);
  __CPROVER_assume(sec_r000087_12_1 != sec_r000087_12_2);
  __CPROVER_assume(pub_r000087_5_1 == pub_r000087_5_2);
  __CPROVER_assume(sec_r000087_9_1 != sec_r000087_9_2);
  __CPROVER_assume(sec_r000087_5_1 != sec_r000087_5_2);
  __CPROVER_assume(pub_r000087_12_1 == pub_r000087_12_2);
  __CPROVER_assume(sec_r000087_17_1 != sec_r000087_17_2);
  __CPROVER_assume(pub_r000087_6_1 == pub_r000087_6_2);
  __CPROVER_assume(sec_r000087_2_1 != sec_r000087_2_2);
  __CPROVER_assume(pub_r000087_13_1 == pub_r000087_13_2);
  __CPROVER_assume(sec_r000087_0_1 != sec_r000087_0_2);
  __CPROVER_assume(sec_r000087_10_1 != sec_r000087_10_2);
  __CPROVER_assume(sec_r000087_7_1 != sec_r000087_7_2);
  __CPROVER_assume(sec_r000087_6_1 != sec_r000087_6_2);
  __CPROVER_assume(sec_r000087_18_1 != sec_r000087_18_2);
  __CPROVER_assume(sec_r000087_14_1 != sec_r000087_14_2);
  __CPROVER_assume(pub_r000087_21_1 == pub_r000087_21_2);
  __CPROVER_assume(pub_r000087_10_1 == pub_r000087_10_2);
  __CPROVER_assume(pub_r000087_19_1 == pub_r000087_19_2);
  __CPROVER_assume(pub_r000087_7_1 == pub_r000087_7_2);
  __CPROVER_assume(pub_r000087_0_1 == pub_r000087_0_2);
  __CPROVER_assume(sec_r000087_1_1 != sec_r000087_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.status == st_var_3_2.status);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
  assert(dead_sec_2_1 == dead_sec_2_2);
  assert(dead_sec_3_1 == dead_sec_3_2);
}


