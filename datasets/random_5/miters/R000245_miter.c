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
struct FilterState_R000245_4513_0
{
  int gain_db;
  unsigned char cutoff;
  int damping;
  int mode;
  short prev_out;
  int prev_in;
  int buffer[3];
};
struct EventLog_R000245_4513_1
{
  unsigned char signature;
  unsigned char code;
  unsigned char timestamp;
  int buffer[3];
};
struct Vector3D_R000245_4513_2
{
  int norm_sq;
  int coord_z;
  int coord_x;
  int coord_y;
  short heading;
  int buffer[3];
};
struct SensorNode_R000245_4513_3
{
  unsigned char calib;
  int gain;
  unsigned char offset;
  int threshold;
  int buffer[3];
};
union TelemetryField_R000245_4513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000245_4513_1
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
void fn_R000245_4513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st_1 = {0};
  struct FilterState_R000245_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_81_1) & 63;
  aux_2 = (aux_2 + cursor_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_62_1)
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

  switch (scale_62_2)
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
  int vector_80_1 = local_arr_1[aux_1 % 3];
  int vector_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_81_1 == cursor_81_2);
  assert(scale_62_1 == scale_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_80_1 == vector_80_2);
}

int fn_R000245_4513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_81) & 63;
  acc ^= aux;
  int scale_62 = (aux + st.buffer[1]) & 3;
  switch (scale_62)
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
  int vector_80 = local_arr[aux % 3];
  acc = (acc + (vector_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_20_1)
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

  switch (coefficient_20_2)
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
  int weight_95_1 = local_arr_1[aux_1 % 3];
  int weight_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_20_1 == coefficient_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_95_1 == weight_95_2);
}

int fn_R000245_4513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_20 = (aux + st.buffer[1]) & 3;
  switch (coefficient_20)
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
  int weight_95 = local_arr[aux % 3];
  acc = (acc + (weight_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_38_1) & 63;
  aux_2 = (aux_2 + offset_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_85_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_85_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_85_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_85_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_66_1)
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

  switch (quantum_66_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_38_1 == offset_38_2);
  assert(anchor_85_1 == anchor_85_2);
  assert(quantum_66_1 == quantum_66_2);
}

int fn_R000245_4513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_38) & 63;
  acc ^= aux;
  int anchor_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_85 > 36)
  {
    acc = ((acc + (anchor_85 * 2)) + 5) & 127;
    aux ^= anchor_85 & 15;
  }
  else
  {
    acc = ((acc - anchor_85) + 11) & 127;
    aux += 3;
  }
  int quantum_66 = (aux + st.buffer[1]) & 3;
  switch (quantum_66)
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

void fn_R000245_4513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_16_1)
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

  switch (pivot_16_2)
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

  int quotient_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_41_1) & 63;
  aux_2 = (aux_2 + quotient_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_16_1 == pivot_16_2);
  assert(quotient_41_1 == quotient_41_2);
}

int fn_R000245_4513_3(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_16 = (aux + st.buffer[1]) & 3;
  switch (pivot_16)
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

  int quotient_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000245_4513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st_1 = {0};
  struct FilterState_R000245_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_15_1 = local_arr_1[aux_1 % 3];
  int tracker_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_15_2 * 2)) & 127;
  int quantum_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_63_1) & 63;
  aux_2 = (aux_2 + quantum_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_95_1)
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

  switch (coefficient_95_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_15_1 == tracker_15_2);
  assert(quantum_63_1 == quantum_63_2);
  assert(coefficient_95_1 == coefficient_95_2);
}

int fn_R000245_4513_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int tracker_15 = local_arr[aux % 3];
  acc = (acc + (tracker_15 * 2)) & 127;
  int quantum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_63) & 63;
  acc ^= aux;
  int coefficient_95 = (aux + st.buffer[1]) & 3;
  switch (coefficient_95)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000245_4513_1 st_1 = {0};
  struct EventLog_R000245_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_43_1 = local_arr_1[aux_1 % 3];
  int threshold_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_43_2 * 2)) & 127;
  int scale_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_90_1)
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

  switch (scale_90_2)
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

  int margin_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_30_1) & 63;
  aux_2 = (aux_2 + margin_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_43_1 == threshold_43_2);
  assert(scale_90_1 == scale_90_2);
  assert(margin_30_1 == margin_30_2);
}

int fn_R000245_4513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000245_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_43 = local_arr[aux % 3];
  acc = (acc + (threshold_43 * 2)) & 127;
  int scale_90 = (aux + st.buffer[1]) & 3;
  switch (scale_90)
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

  int margin_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000245_4513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_99_1) & 63;
  aux_2 = (aux_2 + accumulator_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_56_1 > 23)
  {
    acc_1 = ((acc_1 + (bound_56_1 * 2)) + 5) & 127;
    aux_1 ^= bound_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_56_2 > 23)
  {
    acc_2 = ((acc_2 + (bound_56_2 * 2)) + 5) & 127;
    aux_2 ^= bound_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
  assert(bound_56_1 == bound_56_2);
}

int fn_R000245_4513_6(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_56 > 23)
  {
    acc = ((acc + (bound_56 * 2)) + 5) & 127;
    aux ^= bound_56 & 15;
  }
  else
  {
    acc = ((acc - bound_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000245_4513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st_1 = {0};
  struct SensorNode_R000245_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_25_1) & 63;
  aux_2 = (aux_2 + accumulator_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_72_1 = local_arr_1[aux_1 % 3];
  int window_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_72_2 * 2)) & 127;
  int phase_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_62_1)
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

  switch (phase_62_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_25_1 == accumulator_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_72_1 == window_72_2);
  assert(phase_62_1 == phase_62_2);
}

int fn_R000245_4513_7(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_72 = local_arr[aux % 3];
  acc = (acc + (window_72 * 2)) & 127;
  int phase_62 = (aux + st.buffer[1]) & 3;
  switch (phase_62)
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

void fn_R000245_4513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st_1 = {0};
  struct FilterState_R000245_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_70_1) & 63;
  aux_2 = (aux_2 + index_reg_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_14_1 > 32)
  {
    acc_1 = ((acc_1 + (tally_14_1 * 2)) + 5) & 127;
    aux_1 ^= tally_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_14_2 > 32)
  {
    acc_2 = ((acc_2 + (tally_14_2 * 2)) + 5) & 127;
    aux_2 ^= tally_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_22_1 = local_arr_1[aux_1 % 3];
  int accumulator_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_22_2 * 2)) & 127;
  int stride_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_92_1)
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

  switch (stride_92_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_70_1 == index_reg_70_2);
  assert(tally_14_1 == tally_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(stride_92_1 == stride_92_2);
}

int fn_R000245_4513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_70) & 63;
  acc ^= aux;
  int tally_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_14 > 32)
  {
    acc = ((acc + (tally_14 * 2)) + 5) & 127;
    aux ^= tally_14 & 15;
  }
  else
  {
    acc = ((acc - tally_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_22 = local_arr[aux % 3];
  acc = (acc + (accumulator_22 * 2)) & 127;
  int stride_92 = (aux + st.buffer[1]) & 3;
  switch (stride_92)
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

void fn_R000245_4513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st_1 = {0};
  struct FilterState_R000245_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_18_1 = local_arr_1[aux_1 % 3];
  int margin_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_18_2 * 2)) & 127;
  int threshold_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_33_1)
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

  switch (threshold_33_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_91_1 > 38)
  {
    acc_1 = ((acc_1 + (scale_91_1 * 2)) + 5) & 127;
    aux_1 ^= scale_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_91_2 > 38)
  {
    acc_2 = ((acc_2 + (scale_91_2 * 2)) + 5) & 127;
    aux_2 ^= scale_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_18_1 == margin_18_2);
  assert(threshold_33_1 == threshold_33_2);
  assert(scale_91_1 == scale_91_2);
}

int fn_R000245_4513_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int margin_18 = local_arr[aux % 3];
  acc = (acc + (margin_18 * 2)) & 127;
  int threshold_33 = (aux + st.buffer[1]) & 3;
  switch (threshold_33)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_91 > 38)
  {
    acc = ((acc + (scale_91 * 2)) + 5) & 127;
    aux ^= scale_91 & 15;
  }
  else
  {
    acc = ((acc - scale_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000245_4513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st_1 = {0};
  struct FilterState_R000245_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_25_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_25_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_25_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_25_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_23_1) & 63;
  aux_2 = (aux_2 + index_reg_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_74_1)
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

  switch (accumulator_74_2)
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
  int delta_30_1 = local_arr_1[aux_1 % 3];
  int delta_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_25_1 == index_reg_25_2);
  assert(index_reg_23_1 == index_reg_23_2);
  assert(accumulator_74_1 == accumulator_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_30_1 == delta_30_2);
}

int fn_R000245_4513_10(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000245_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_25 > 25)
  {
    acc = ((acc + (index_reg_25 * 2)) + 5) & 127;
    aux ^= index_reg_25 & 15;
  }
  else
  {
    acc = ((acc - index_reg_25) + 11) & 127;
    aux += 3;
  }
  int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_23) & 63;
  acc ^= aux;
  int accumulator_74 = (aux + st.buffer[1]) & 3;
  switch (accumulator_74)
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
  int delta_30 = local_arr[aux % 3];
  acc = (acc + (delta_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st_1 = {0};
  struct SensorNode_R000245_4513_3 st_2 = {0};
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
  int pivot_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_29_1 > 32)
  {
    acc_1 = ((acc_1 + (pivot_29_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_29_2 > 32)
  {
    acc_2 = ((acc_2 + (pivot_29_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_36_1) & 63;
  aux_2 = (aux_2 + mask_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_29_1 == pivot_29_2);
  assert(mask_36_1 == mask_36_2);
}

int fn_R000245_4513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_29 > 32)
  {
    acc = ((acc + (pivot_29 * 2)) + 5) & 127;
    aux ^= pivot_29 & 15;
  }
  else
  {
    acc = ((acc - pivot_29) + 11) & 127;
    aux += 3;
  }
  int mask_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_36) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000245_4513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st_1 = {0};
  struct SensorNode_R000245_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_36_1 > 23)
  {
    acc_1 = ((acc_1 + (factor_36_1 * 2)) + 5) & 127;
    aux_1 ^= factor_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_36_2 > 23)
  {
    acc_2 = ((acc_2 + (factor_36_2 * 2)) + 5) & 127;
    aux_2 ^= factor_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_36_1 == factor_36_2);
}

int fn_R000245_4513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_36 > 23)
  {
    acc = ((acc + (factor_36 * 2)) + 5) & 127;
    aux ^= factor_36 & 15;
  }
  else
  {
    acc = ((acc - factor_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000245_4513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_73_1 = local_arr_1[aux_1 % 3];
  int accumulator_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_73_2 * 2)) & 127;
  int vector_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_10_1) & 63;
  aux_2 = (aux_2 + vector_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  assert(vector_10_1 == vector_10_2);
}

int fn_R000245_4513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int accumulator_73 = local_arr[aux % 3];
  acc = (acc + (accumulator_73 * 2)) & 127;
  int vector_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000245_4513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000245_4513_1 st_1 = {0};
  struct EventLog_R000245_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_73_1 > 20)
  {
    acc_1 = ((acc_1 + (residue_73_1 * 2)) + 5) & 127;
    aux_1 ^= residue_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_73_2 > 20)
  {
    acc_2 = ((acc_2 + (residue_73_2 * 2)) + 5) & 127;
    aux_2 ^= residue_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_46_1)
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

  switch (accumulator_46_2)
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
  int mask_95_1 = local_arr_1[aux_1 % 3];
  int mask_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_73_1 == residue_73_2);
  assert(accumulator_46_1 == accumulator_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_95_1 == mask_95_2);
}

int fn_R000245_4513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000245_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_73 > 20)
  {
    acc = ((acc + (residue_73 * 2)) + 5) & 127;
    aux ^= residue_73 & 15;
  }
  else
  {
    acc = ((acc - residue_73) + 11) & 127;
    aux += 3;
  }
  int accumulator_46 = (aux + st.buffer[1]) & 3;
  switch (accumulator_46)
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
  int mask_95 = local_arr[aux % 3];
  acc = (acc + (mask_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st_1 = {0};
  struct SensorNode_R000245_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int delta_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_26_1 > 25)
  {
    acc_1 = ((acc_1 + (delta_26_1 * 2)) + 5) & 127;
    aux_1 ^= delta_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_26_2 > 25)
  {
    acc_2 = ((acc_2 + (delta_26_2 * 2)) + 5) & 127;
    aux_2 ^= delta_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_98_1) & 63;
  aux_2 = (aux_2 + sample_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_26_1 == delta_26_2);
  assert(sample_98_1 == sample_98_2);
}

int fn_R000245_4513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000245_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int delta_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_26 > 25)
  {
    acc = ((acc + (delta_26 * 2)) + 5) & 127;
    aux ^= delta_26 & 15;
  }
  else
  {
    acc = ((acc - delta_26) + 11) & 127;
    aux += 3;
  }
  int sample_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_98) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000245_4513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st_1 = {0};
  struct Vector3D_R000245_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_41_1) & 63;
  aux_2 = (aux_2 + scale_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_50_1 > 48)
  {
    acc_1 = ((acc_1 + (vector_50_1 * 2)) + 5) & 127;
    aux_1 ^= vector_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_50_2 > 48)
  {
    acc_2 = ((acc_2 + (vector_50_2 * 2)) + 5) & 127;
    aux_2 ^= vector_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_54_1)
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

  switch (delta_54_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_41_1 == scale_41_2);
  assert(vector_50_1 == vector_50_2);
  assert(delta_54_1 == delta_54_2);
}

int fn_R000245_4513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000245_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_50 > 48)
  {
    acc = ((acc + (vector_50 * 2)) + 5) & 127;
    aux ^= vector_50 & 15;
  }
  else
  {
    acc = ((acc - vector_50) + 11) & 127;
    aux += 3;
  }
  int delta_54 = (aux + st.buffer[1]) & 3;
  switch (delta_54)
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

void main()
{
  int sec_r000245_0_1;
  int sec_r000245_0_2;
  int sec_r000245_1_1;
  int sec_r000245_1_2;
  int sec_r000245_2_1;
  int sec_r000245_2_2;
  int sec_r000245_3_1;
  int sec_r000245_3_2;
  int sec_r000245_4_1;
  int sec_r000245_4_2;
  int sec_r000245_5_1;
  int sec_r000245_5_2;
  int sec_r000245_6_1;
  int sec_r000245_6_2;
  int sec_r000245_7_1;
  int sec_r000245_7_2;
  int sec_r000245_8_1;
  int sec_r000245_8_2;
  int sec_r000245_9_1;
  int sec_r000245_9_2;
  int sec_r000245_10_1;
  int sec_r000245_10_2;
  int sec_r000245_11_1;
  int sec_r000245_11_2;
  int sec_r000245_12_1;
  int sec_r000245_12_2;
  int sec_r000245_13_1;
  int sec_r000245_13_2;
  int sec_r000245_14_1;
  int sec_r000245_14_2;
  int sec_r000245_15_1;
  int sec_r000245_15_2;
  int pub_r000245_0_1;
  int pub_r000245_0_2;
  int pub_r000245_1_1;
  int pub_r000245_1_2;
  int pub_r000245_2_1;
  int pub_r000245_2_2;
  int pub_r000245_3_1;
  int pub_r000245_3_2;
  int pub_r000245_4_1;
  int pub_r000245_4_2;
  int pub_r000245_5_1;
  int pub_r000245_5_2;
  int pub_r000245_6_1;
  int pub_r000245_6_2;
  int pub_r000245_7_1;
  int pub_r000245_7_2;
  int pub_r000245_8_1;
  int pub_r000245_8_2;
  int pub_r000245_9_1;
  int pub_r000245_9_2;
  int pub_r000245_10_1;
  int pub_r000245_10_2;
  int pub_r000245_11_1;
  int pub_r000245_11_2;
  int pub_r000245_12_1;
  int pub_r000245_12_2;
  int pub_r000245_13_1;
  int pub_r000245_13_2;
  int pub_r000245_14_1;
  int pub_r000245_14_2;
  int pub_r000245_15_1;
  int pub_r000245_15_2;
  int pub_r000245_16_1;
  int pub_r000245_16_2;
  int pub_r000245_17_1;
  int pub_r000245_17_2;
  int pub_r000245_18_1;
  int pub_r000245_18_2;
  int pub_r000245_19_1;
  int pub_r000245_19_2;
  int pub_r000245_20_1;
  int pub_r000245_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000245_0_1 >= (-100)) && (pub_r000245_0_1 <= 100));
  __CPROVER_assume((pub_r000245_0_2 >= (-100)) && (pub_r000245_0_2 <= 100));
  __CPROVER_assume((pub_r000245_1_1 >= (-100)) && (pub_r000245_1_1 <= 100));
  __CPROVER_assume((pub_r000245_1_2 >= (-100)) && (pub_r000245_1_2 <= 100));
  __CPROVER_assume((pub_r000245_2_1 >= (-100)) && (pub_r000245_2_1 <= 100));
  __CPROVER_assume((pub_r000245_2_2 >= (-100)) && (pub_r000245_2_2 <= 100));
  __CPROVER_assume((pub_r000245_3_1 >= (-100)) && (pub_r000245_3_1 <= 100));
  __CPROVER_assume((pub_r000245_3_2 >= (-100)) && (pub_r000245_3_2 <= 100));
  __CPROVER_assume((pub_r000245_4_1 >= (-100)) && (pub_r000245_4_1 <= 100));
  __CPROVER_assume((pub_r000245_4_2 >= (-100)) && (pub_r000245_4_2 <= 100));
  __CPROVER_assume((pub_r000245_5_1 >= (-100)) && (pub_r000245_5_1 <= 100));
  __CPROVER_assume((pub_r000245_5_2 >= (-100)) && (pub_r000245_5_2 <= 100));
  __CPROVER_assume((pub_r000245_6_1 >= (-100)) && (pub_r000245_6_1 <= 100));
  __CPROVER_assume((pub_r000245_6_2 >= (-100)) && (pub_r000245_6_2 <= 100));
  __CPROVER_assume((pub_r000245_7_1 >= (-100)) && (pub_r000245_7_1 <= 100));
  __CPROVER_assume((pub_r000245_7_2 >= (-100)) && (pub_r000245_7_2 <= 100));
  __CPROVER_assume((pub_r000245_8_1 >= (-100)) && (pub_r000245_8_1 <= 100));
  __CPROVER_assume((pub_r000245_8_2 >= (-100)) && (pub_r000245_8_2 <= 100));
  __CPROVER_assume((pub_r000245_9_1 >= (-100)) && (pub_r000245_9_1 <= 100));
  __CPROVER_assume((pub_r000245_9_2 >= (-100)) && (pub_r000245_9_2 <= 100));
  __CPROVER_assume((pub_r000245_10_1 >= (-100)) && (pub_r000245_10_1 <= 100));
  __CPROVER_assume((pub_r000245_10_2 >= (-100)) && (pub_r000245_10_2 <= 100));
  __CPROVER_assume((pub_r000245_11_1 >= (-100)) && (pub_r000245_11_1 <= 100));
  __CPROVER_assume((pub_r000245_11_2 >= (-100)) && (pub_r000245_11_2 <= 100));
  __CPROVER_assume((pub_r000245_12_1 >= (-100)) && (pub_r000245_12_1 <= 100));
  __CPROVER_assume((pub_r000245_12_2 >= (-100)) && (pub_r000245_12_2 <= 100));
  __CPROVER_assume((pub_r000245_13_1 >= (-100)) && (pub_r000245_13_1 <= 100));
  __CPROVER_assume((pub_r000245_13_2 >= (-100)) && (pub_r000245_13_2 <= 100));
  __CPROVER_assume((pub_r000245_14_1 >= (-100)) && (pub_r000245_14_1 <= 100));
  __CPROVER_assume((pub_r000245_14_2 >= (-100)) && (pub_r000245_14_2 <= 100));
  __CPROVER_assume((pub_r000245_15_1 >= (-100)) && (pub_r000245_15_1 <= 100));
  __CPROVER_assume((pub_r000245_15_2 >= (-100)) && (pub_r000245_15_2 <= 100));
  __CPROVER_assume((pub_r000245_16_1 >= (-100)) && (pub_r000245_16_1 <= 100));
  __CPROVER_assume((pub_r000245_16_2 >= (-100)) && (pub_r000245_16_2 <= 100));
  __CPROVER_assume((pub_r000245_17_1 >= (-100)) && (pub_r000245_17_1 <= 100));
  __CPROVER_assume((pub_r000245_17_2 >= (-100)) && (pub_r000245_17_2 <= 100));
  __CPROVER_assume((pub_r000245_18_1 >= (-100)) && (pub_r000245_18_1 <= 100));
  __CPROVER_assume((pub_r000245_18_2 >= (-100)) && (pub_r000245_18_2 <= 100));
  __CPROVER_assume((pub_r000245_19_1 >= (-100)) && (pub_r000245_19_1 <= 100));
  __CPROVER_assume((pub_r000245_19_2 >= (-100)) && (pub_r000245_19_2 <= 100));
  __CPROVER_assume((pub_r000245_20_1 >= (-100)) && (pub_r000245_20_1 <= 100));
  __CPROVER_assume((pub_r000245_20_2 >= (-100)) && (pub_r000245_20_2 <= 100));
  __CPROVER_assume((sec_r000245_0_1 >= 0) && (sec_r000245_0_1 <= 255));
  __CPROVER_assume((sec_r000245_0_2 >= 0) && (sec_r000245_0_2 <= 255));
  __CPROVER_assume((sec_r000245_1_1 >= 0) && (sec_r000245_1_1 <= 255));
  __CPROVER_assume((sec_r000245_1_2 >= 0) && (sec_r000245_1_2 <= 255));
  __CPROVER_assume((sec_r000245_2_1 >= 0) && (sec_r000245_2_1 <= 255));
  __CPROVER_assume((sec_r000245_2_2 >= 0) && (sec_r000245_2_2 <= 255));
  __CPROVER_assume((sec_r000245_3_1 >= 0) && (sec_r000245_3_1 <= 255));
  __CPROVER_assume((sec_r000245_3_2 >= 0) && (sec_r000245_3_2 <= 255));
  __CPROVER_assume((sec_r000245_4_1 >= 0) && (sec_r000245_4_1 <= 255));
  __CPROVER_assume((sec_r000245_4_2 >= 0) && (sec_r000245_4_2 <= 255));
  __CPROVER_assume((sec_r000245_5_1 >= 0) && (sec_r000245_5_1 <= 255));
  __CPROVER_assume((sec_r000245_5_2 >= 0) && (sec_r000245_5_2 <= 255));
  __CPROVER_assume((sec_r000245_6_1 >= 0) && (sec_r000245_6_1 <= 255));
  __CPROVER_assume((sec_r000245_6_2 >= 0) && (sec_r000245_6_2 <= 255));
  __CPROVER_assume((sec_r000245_7_1 >= 0) && (sec_r000245_7_1 <= 255));
  __CPROVER_assume((sec_r000245_7_2 >= 0) && (sec_r000245_7_2 <= 255));
  __CPROVER_assume((sec_r000245_8_1 >= 0) && (sec_r000245_8_1 <= 255));
  __CPROVER_assume((sec_r000245_8_2 >= 0) && (sec_r000245_8_2 <= 255));
  __CPROVER_assume((sec_r000245_9_1 >= 0) && (sec_r000245_9_1 <= 255));
  __CPROVER_assume((sec_r000245_9_2 >= 0) && (sec_r000245_9_2 <= 255));
  __CPROVER_assume((sec_r000245_10_1 >= 0) && (sec_r000245_10_1 <= 255));
  __CPROVER_assume((sec_r000245_10_2 >= 0) && (sec_r000245_10_2 <= 255));
  __CPROVER_assume((sec_r000245_11_1 >= 0) && (sec_r000245_11_1 <= 255));
  __CPROVER_assume((sec_r000245_11_2 >= 0) && (sec_r000245_11_2 <= 255));
  __CPROVER_assume((sec_r000245_12_1 >= 0) && (sec_r000245_12_1 <= 255));
  __CPROVER_assume((sec_r000245_12_2 >= 0) && (sec_r000245_12_2 <= 255));
  __CPROVER_assume((sec_r000245_13_1 >= 0) && (sec_r000245_13_1 <= 255));
  __CPROVER_assume((sec_r000245_13_2 >= 0) && (sec_r000245_13_2 <= 255));
  __CPROVER_assume((sec_r000245_14_1 >= 0) && (sec_r000245_14_1 <= 255));
  __CPROVER_assume((sec_r000245_14_2 >= 0) && (sec_r000245_14_2 <= 255));
  __CPROVER_assume((sec_r000245_15_1 >= 0) && (sec_r000245_15_1 <= 255));
  __CPROVER_assume((sec_r000245_15_2 >= 0) && (sec_r000245_15_2 <= 255));
  struct FilterState_R000245_4513_0 st_var_0_1 = {0};
  struct FilterState_R000245_4513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000245_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000245_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000245_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000245_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000245_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000245_0_2 + 7) & 15;
  struct EventLog_R000245_4513_1 st_var_1_1 = {0};
  struct EventLog_R000245_4513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000245_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000245_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000245_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000245_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000245_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000245_0_2 + 9) & 15;
  struct Vector3D_R000245_4513_2 st_var_2_1 = {0};
  struct Vector3D_R000245_4513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000245_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000245_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000245_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000245_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000245_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000245_0_2 + 11) & 15;
  struct SensorNode_R000245_4513_3 st_var_3_1 = {0};
  struct SensorNode_R000245_4513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000245_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000245_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000245_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000245_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000245_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000245_0_2 + 13) & 15;
  union TelemetryField_R000245_4513_0 u_var_1;
  union TelemetryField_R000245_4513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 40)
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
  if (stage_v_3_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 40)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 33)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 33)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 46)
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
  if (stage_v_20_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 46)
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
  int stage_v_21_1 = (((sec_r000245_11_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_21_2 = (((sec_r000245_11_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = (((stage_v_21_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_22_2 = (((stage_v_21_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = (((stage_v_22_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_23_2 = (((stage_v_22_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = (((stage_v_22_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_24_2 = (((stage_v_22_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = (((stage_v_23_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_25_2 = (((stage_v_23_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = (((stage_v_25_1 << 2) ^ (sec_r000245_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_26_2 = (((stage_v_25_2 << 2) ^ (sec_r000245_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = (((stage_v_25_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_27_2 = (((stage_v_25_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = (((stage_v_26_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_28_2 = (((stage_v_26_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = (((stage_v_28_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_29_2 = (((stage_v_28_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_30_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = (((stage_v_29_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_31_2 = (((stage_v_29_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = (((sec_r000245_6_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_32_2 = (((sec_r000245_6_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = (((sec_r000245_12_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_33_2 = (((sec_r000245_12_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = (((stage_v_32_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_34_2 = (((stage_v_32_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = (((stage_v_25_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_35_2 = (((stage_v_25_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = (((sec_r000245_0_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_36_2 = (((sec_r000245_0_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = (((stage_v_28_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_37_2 = (((stage_v_28_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = (((stage_v_21_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_38_2 = (((stage_v_21_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = (((stage_v_32_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_39_2 = (((stage_v_32_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = (((sec_r000245_10_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_40_2 = (((sec_r000245_10_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = (((stage_v_36_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_41_2 = (((stage_v_36_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = (((sec_r000245_4_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_42_2 = (((sec_r000245_4_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = (((stage_v_35_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_43_2 = (((stage_v_35_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = (((stage_v_38_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_44_2 = (((stage_v_38_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = (((sec_r000245_9_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_45_2 = (((sec_r000245_9_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = (((stage_v_42_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_46_2 = (((stage_v_42_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = (((stage_v_41_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_47_2 = (((stage_v_41_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = (((sec_r000245_7_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_48_2 = (((sec_r000245_7_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = (((sec_r000245_1_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_49_2 = (((sec_r000245_1_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = (((stage_v_35_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_50_2 = (((stage_v_35_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = (((stage_v_27_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_51_2 = (((stage_v_27_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = (((stage_v_35_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_52_2 = (((stage_v_35_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = (((stage_v_48_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_53_2 = (((stage_v_48_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = (((sec_r000245_5_1 << 2) ^ (sec_r000245_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_54_2 = (((sec_r000245_5_2 << 2) ^ (sec_r000245_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = (((sec_r000245_11_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_55_2 = (((sec_r000245_11_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_56_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = (((stage_v_34_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_57_2 = (((stage_v_34_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = (((stage_v_57_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_58_2 = (((stage_v_57_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = (((sec_r000245_14_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_59_2 = (((sec_r000245_14_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = (((stage_v_47_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_60_2 = (((stage_v_47_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = (((stage_v_51_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((stage_v_51_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((stage_v_61_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((stage_v_61_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((sec_r000245_12_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((sec_r000245_12_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((sec_r000245_14_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((sec_r000245_14_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((stage_v_40_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((stage_v_40_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((stage_v_65_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((stage_v_65_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((stage_v_38_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((stage_v_38_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((sec_r000245_14_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((sec_r000245_14_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((stage_v_66_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((stage_v_66_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((stage_v_37_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((stage_v_37_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_71_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_71_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((stage_v_48_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((stage_v_48_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((stage_v_65_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((stage_v_65_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((sec_r000245_7_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((sec_r000245_7_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_55_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_55_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((stage_v_73_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((stage_v_73_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((stage_v_38_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((stage_v_38_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((stage_v_63_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((stage_v_63_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((stage_v_45_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((stage_v_45_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((sec_r000245_9_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((sec_r000245_9_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((stage_v_49_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((stage_v_49_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((sec_r000245_10_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((sec_r000245_10_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((stage_v_26_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((stage_v_26_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((stage_v_32_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((stage_v_32_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((sec_r000245_6_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((sec_r000245_6_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((stage_v_35_1 << 2) ^ (sec_r000245_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((stage_v_35_2 << 2) ^ (sec_r000245_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((stage_v_21_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((stage_v_21_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((sec_r000245_6_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((sec_r000245_6_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((stage_v_68_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((stage_v_68_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((stage_v_57_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((stage_v_57_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((stage_v_72_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((stage_v_72_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((sec_r000245_2_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((sec_r000245_2_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((stage_v_78_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((stage_v_78_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((stage_v_58_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((stage_v_58_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((stage_v_68_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((stage_v_68_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((stage_v_51_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((stage_v_51_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((stage_v_59_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((stage_v_59_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((stage_v_31_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((stage_v_31_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((sec_r000245_8_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((sec_r000245_8_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((sec_r000245_0_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((sec_r000245_0_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((stage_v_70_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((stage_v_70_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((stage_v_24_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((stage_v_24_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((stage_v_76_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((stage_v_76_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((stage_v_57_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((stage_v_57_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((stage_v_78_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((stage_v_78_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((stage_v_103_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((stage_v_103_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((stage_v_89_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((stage_v_89_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((sec_r000245_8_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((sec_r000245_8_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((stage_v_32_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((stage_v_32_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((stage_v_56_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((stage_v_56_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((stage_v_89_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((stage_v_89_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((stage_v_67_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((stage_v_67_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((sec_r000245_15_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((sec_r000245_15_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((stage_v_100_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((stage_v_100_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((stage_v_96_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((stage_v_96_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((stage_v_99_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((stage_v_99_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((sec_r000245_3_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((sec_r000245_3_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_58_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_58_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((stage_v_84_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((stage_v_84_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((stage_v_43_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((stage_v_43_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((stage_v_108_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((stage_v_108_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_75_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_75_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((stage_v_120_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((stage_v_120_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((stage_v_46_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((stage_v_46_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((stage_v_71_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((stage_v_71_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((sec_r000245_6_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((sec_r000245_6_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((sec_r000245_3_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((sec_r000245_3_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((stage_v_23_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((stage_v_23_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((sec_r000245_5_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((sec_r000245_5_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((stage_v_117_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((stage_v_117_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((stage_v_123_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((stage_v_123_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_127_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_127_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((sec_r000245_0_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((sec_r000245_0_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_66_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_66_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((stage_v_45_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((stage_v_45_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((stage_v_83_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((stage_v_83_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((sec_r000245_2_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((sec_r000245_2_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((stage_v_72_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((stage_v_72_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((sec_r000245_9_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((sec_r000245_9_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((stage_v_23_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((stage_v_23_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((stage_v_124_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((stage_v_124_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((stage_v_92_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((stage_v_92_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((sec_r000245_3_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((sec_r000245_3_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((stage_v_38_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((stage_v_38_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_145_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_145_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((sec_r000245_5_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((sec_r000245_5_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((stage_v_93_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((stage_v_93_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((stage_v_81_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((stage_v_81_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((stage_v_70_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((stage_v_70_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((sec_r000245_0_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((sec_r000245_0_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((stage_v_37_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((stage_v_37_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((sec_r000245_15_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((sec_r000245_15_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((stage_v_76_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((stage_v_76_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((stage_v_135_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((stage_v_135_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((stage_v_47_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((stage_v_47_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((sec_r000245_8_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((sec_r000245_8_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((sec_r000245_8_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((sec_r000245_8_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((stage_v_32_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((stage_v_32_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((stage_v_77_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((stage_v_77_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((stage_v_119_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((stage_v_119_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((sec_r000245_0_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((sec_r000245_0_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((sec_r000245_1_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((sec_r000245_1_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((sec_r000245_4_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((sec_r000245_4_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_133_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_133_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((stage_v_149_1 << 2) ^ (sec_r000245_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((stage_v_149_2 << 2) ^ (sec_r000245_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((stage_v_123_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((stage_v_123_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((sec_r000245_6_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((sec_r000245_6_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((stage_v_109_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((stage_v_109_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((stage_v_167_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((stage_v_167_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((stage_v_76_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((stage_v_76_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((stage_v_81_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((stage_v_81_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((stage_v_156_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((stage_v_156_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((sec_r000245_2_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((sec_r000245_2_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((stage_v_163_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((stage_v_163_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((stage_v_63_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((stage_v_63_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((sec_r000245_0_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((sec_r000245_0_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((stage_v_160_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((stage_v_160_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((stage_v_161_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((stage_v_161_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((sec_r000245_7_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((sec_r000245_7_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((stage_v_73_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((stage_v_73_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((stage_v_47_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((stage_v_47_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((sec_r000245_8_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((sec_r000245_8_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_43_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_43_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((stage_v_126_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((stage_v_126_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((stage_v_174_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((stage_v_174_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((sec_r000245_14_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((sec_r000245_14_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((sec_r000245_14_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((sec_r000245_14_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((sec_r000245_13_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((sec_r000245_13_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((stage_v_90_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((stage_v_90_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((stage_v_191_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((stage_v_191_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((sec_r000245_13_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((sec_r000245_13_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((stage_v_153_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((stage_v_153_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((sec_r000245_9_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((sec_r000245_9_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((sec_r000245_9_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((sec_r000245_9_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((sec_r000245_12_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((sec_r000245_12_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_144_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_144_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((stage_v_104_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((stage_v_104_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((stage_v_98_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((stage_v_98_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_162_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_162_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((sec_r000245_8_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((sec_r000245_8_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((stage_v_157_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((stage_v_157_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((stage_v_111_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((stage_v_111_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((stage_v_35_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((stage_v_35_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_102_1 << 2) ^ (sec_r000245_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_102_2 << 2) ^ (sec_r000245_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((stage_v_41_1 << 2) ^ (sec_r000245_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((stage_v_41_2 << 2) ^ (sec_r000245_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((stage_v_62_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((stage_v_62_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((stage_v_186_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((stage_v_186_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((stage_v_143_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((stage_v_143_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((stage_v_71_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((stage_v_71_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((stage_v_200_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((stage_v_200_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_31_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_31_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((stage_v_42_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((stage_v_42_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((stage_v_51_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((stage_v_51_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((stage_v_216_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((stage_v_216_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((stage_v_209_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((stage_v_209_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((stage_v_213_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((stage_v_213_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((stage_v_54_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((stage_v_54_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((sec_r000245_4_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((sec_r000245_4_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_201_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_201_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((sec_r000245_8_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((sec_r000245_8_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((stage_v_193_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((stage_v_193_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((stage_v_64_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((stage_v_64_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((stage_v_70_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((stage_v_70_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((stage_v_105_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((stage_v_105_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((stage_v_226_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((stage_v_226_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((sec_r000245_6_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((sec_r000245_6_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((stage_v_135_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((stage_v_135_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((stage_v_196_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((stage_v_196_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((stage_v_114_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((stage_v_114_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_68_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_68_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((stage_v_180_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((stage_v_180_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((sec_r000245_14_1 << 1) ^ (sec_r000245_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((sec_r000245_14_2 << 1) ^ (sec_r000245_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((stage_v_52_1 << 2) ^ (sec_r000245_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((stage_v_52_2 << 2) ^ (sec_r000245_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((sec_r000245_10_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((sec_r000245_10_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((stage_v_206_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((stage_v_206_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_223_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_223_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((stage_v_107_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((stage_v_107_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((stage_v_72_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((stage_v_72_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((stage_v_157_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((stage_v_157_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((stage_v_112_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((stage_v_112_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((stage_v_39_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((stage_v_39_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((stage_v_225_1 << 2) ^ (sec_r000245_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((stage_v_225_2 << 2) ^ (sec_r000245_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((sec_r000245_2_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((sec_r000245_2_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((stage_v_34_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((stage_v_34_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((sec_r000245_9_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((sec_r000245_9_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((sec_r000245_8_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((sec_r000245_8_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((stage_v_136_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((stage_v_136_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((stage_v_199_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((stage_v_199_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((stage_v_87_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((stage_v_87_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((stage_v_243_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((stage_v_243_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((sec_r000245_0_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((sec_r000245_0_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((stage_v_98_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((stage_v_98_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = (((stage_v_256_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_261_2 = (((stage_v_256_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_261_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_261_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = (((stage_v_226_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_262_2 = (((stage_v_226_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_262_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_262_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = (((stage_v_72_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_263_2 = (((stage_v_72_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_263_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_263_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = (((stage_v_26_1 << 2) ^ (sec_r000245_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_264_2 = (((stage_v_26_2 << 2) ^ (sec_r000245_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_264_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_264_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = (((sec_r000245_15_1 << 1) ^ (sec_r000245_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_265_2 = (((sec_r000245_15_2 << 1) ^ (sec_r000245_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_265_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_265_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = (((stage_v_112_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_266_2 = (((stage_v_112_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_266_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_266_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = (((stage_v_202_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_267_2 = (((stage_v_202_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_267_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_267_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = (((stage_v_122_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_268_2 = (((stage_v_122_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_268_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_268_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = (((stage_v_27_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_269_2 = (((stage_v_27_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_269_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_269_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = (((sec_r000245_4_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_270_2 = (((sec_r000245_4_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_270_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_270_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = (((stage_v_179_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_271_2 = (((stage_v_179_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_271_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_271_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_272_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_272_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_272_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = (((stage_v_136_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_273_2 = (((stage_v_136_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_273_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_273_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = (((stage_v_237_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_274_2 = (((stage_v_237_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_274_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_274_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = (((stage_v_215_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_275_2 = (((stage_v_215_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_275_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_275_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = (((stage_v_212_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_276_2 = (((stage_v_212_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_276_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_276_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = (((sec_r000245_12_1 << 2) ^ (sec_r000245_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_277_2 = (((sec_r000245_12_2 << 2) ^ (sec_r000245_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_277_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_277_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = (((stage_v_258_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_278_2 = (((stage_v_258_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_278_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_278_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = (((stage_v_222_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_279_2 = (((stage_v_222_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_279_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_279_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = (((stage_v_115_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_280_2 = (((stage_v_115_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_280_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_280_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = (((sec_r000245_14_1 << 2) ^ (sec_r000245_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_281_2 = (((sec_r000245_14_2 << 2) ^ (sec_r000245_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_281_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_281_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = (((sec_r000245_9_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_282_2 = (((sec_r000245_9_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_282_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_282_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = (((stage_v_57_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_283_2 = (((stage_v_57_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_283_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_283_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = (((stage_v_97_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_284_2 = (((stage_v_97_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_284_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_284_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = (((stage_v_74_1 << 2) ^ (sec_r000245_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_285_2 = (((stage_v_74_2 << 2) ^ (sec_r000245_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_285_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_285_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = (((sec_r000245_1_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_286_2 = (((sec_r000245_1_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_286_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_286_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = (((sec_r000245_9_1 << 2) ^ (sec_r000245_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_287_2 = (((sec_r000245_9_2 << 2) ^ (sec_r000245_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_287_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_287_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = (((stage_v_51_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_288_2 = (((stage_v_51_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_288_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_288_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = (((stage_v_214_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_289_2 = (((stage_v_214_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_289_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_289_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = (((stage_v_49_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_290_2 = (((stage_v_49_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_290_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_290_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = (((stage_v_91_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_291_2 = (((stage_v_91_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_291_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_291_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = (((stage_v_170_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_292_2 = (((stage_v_170_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_292_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_292_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = (((stage_v_32_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_293_2 = (((stage_v_32_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_293_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_293_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = (((sec_r000245_4_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_294_2 = (((sec_r000245_4_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_294_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_294_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = (((sec_r000245_11_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_295_2 = (((sec_r000245_11_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_295_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_295_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = (((stage_v_47_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_296_2 = (((stage_v_47_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_296_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_296_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = (((stage_v_54_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_297_2 = (((stage_v_54_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_297_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_297_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = (((stage_v_115_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_298_2 = (((stage_v_115_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_298_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_298_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = (((sec_r000245_9_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_299_2 = (((sec_r000245_9_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_299_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_299_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = (((stage_v_21_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_300_2 = (((stage_v_21_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_300_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_300_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = (((stage_v_84_1 << 1) ^ (sec_r000245_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_301_2 = (((stage_v_84_2 << 1) ^ (sec_r000245_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_301_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_301_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = (((stage_v_166_1 << 1) ^ (sec_r000245_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_302_2 = (((stage_v_166_2 << 1) ^ (sec_r000245_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_302_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_302_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = (((stage_v_274_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_303_2 = (((stage_v_274_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_303_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_303_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_304_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_304_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_304_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = (((stage_v_114_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_305_2 = (((stage_v_114_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_305_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_305_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = (((stage_v_269_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_306_2 = (((stage_v_269_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_306_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_306_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = (((stage_v_190_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_307_2 = (((stage_v_190_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_307_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_307_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = (((stage_v_78_1 << 1) ^ (sec_r000245_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_308_2 = (((stage_v_78_2 << 1) ^ (sec_r000245_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_308_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_308_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = (((stage_v_130_1 << 1) ^ (sec_r000245_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_309_2 = (((stage_v_130_2 << 1) ^ (sec_r000245_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_309_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_309_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = (((stage_v_182_1 << 2) ^ (sec_r000245_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_310_2 = (((stage_v_182_2 << 2) ^ (sec_r000245_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_310_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_310_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = (((stage_v_225_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_311_2 = (((stage_v_225_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_311_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_311_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = (((stage_v_61_1 << 1) ^ (sec_r000245_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_312_2 = (((stage_v_61_2 << 1) ^ (sec_r000245_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_312_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_312_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = (((stage_v_299_1 << 1) ^ (sec_r000245_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_313_2 = (((stage_v_299_2 << 1) ^ (sec_r000245_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_313_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_313_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = (((sec_r000245_3_1 << 1) ^ (sec_r000245_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_314_2 = (((sec_r000245_3_2 << 1) ^ (sec_r000245_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_314_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_314_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = (((stage_v_118_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_315_2 = (((stage_v_118_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_315_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_315_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = (((sec_r000245_8_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_316_2 = (((sec_r000245_8_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_316_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_316_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = (((sec_r000245_13_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_317_2 = (((sec_r000245_13_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_317_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_317_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = (((stage_v_309_1 << 2) ^ (sec_r000245_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_318_2 = (((stage_v_309_2 << 2) ^ (sec_r000245_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_318_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_318_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = (((stage_v_317_1 << 2) ^ (sec_r000245_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_319_2 = (((stage_v_317_2 << 2) ^ (sec_r000245_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_319_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_319_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = (((stage_v_122_1 << 2) ^ (sec_r000245_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_320_2 = (((stage_v_122_2 << 2) ^ (sec_r000245_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_320_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_320_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = (((stage_v_156_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_321_2 = (((stage_v_156_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_321_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_321_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = (((stage_v_288_1 << 1) ^ (sec_r000245_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_322_2 = (((stage_v_288_2 << 1) ^ (sec_r000245_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_322_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_322_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = (((stage_v_29_1 << 1) ^ (sec_r000245_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_323_2 = (((stage_v_29_2 << 1) ^ (sec_r000245_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_323_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_323_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = (((stage_v_105_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_324_2 = (((stage_v_105_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_324_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_324_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = (((stage_v_221_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_325_2 = (((stage_v_221_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_325_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_325_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = (((stage_v_286_1 << 1) ^ (sec_r000245_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_326_2 = (((stage_v_286_2 << 1) ^ (sec_r000245_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_326_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_326_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = (((sec_r000245_2_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_327_2 = (((sec_r000245_2_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_327_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_327_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = (((stage_v_242_1 << 2) ^ (sec_r000245_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_328_2 = (((stage_v_242_2 << 2) ^ (sec_r000245_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_328_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_328_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = (((sec_r000245_5_1 << 1) ^ (sec_r000245_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_329_2 = (((sec_r000245_5_2 << 1) ^ (sec_r000245_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_329_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_329_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = (((sec_r000245_2_1 << 2) ^ (sec_r000245_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_330_2 = (((sec_r000245_2_2 << 2) ^ (sec_r000245_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_330_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_330_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = (((stage_v_302_1 << 2) ^ (sec_r000245_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_331_2 = (((stage_v_302_2 << 2) ^ (sec_r000245_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_331_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_331_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = (((sec_r000245_13_1 << 2) ^ (sec_r000245_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_332_2 = (((sec_r000245_13_2 << 2) ^ (sec_r000245_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_332_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_332_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = (((stage_v_253_1 << 1) ^ (sec_r000245_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_333_2 = (((stage_v_253_2 << 1) ^ (sec_r000245_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_333_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_333_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = (((stage_v_124_1 << 2) ^ (sec_r000245_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_334_2 = (((stage_v_124_2 << 2) ^ (sec_r000245_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_334_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_334_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = (((stage_v_93_1 << 1) ^ (sec_r000245_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_335_2 = (((stage_v_93_2 << 1) ^ (sec_r000245_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_335_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_335_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = (((stage_v_84_1 << 2) ^ (sec_r000245_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_336_2 = (((stage_v_84_2 << 2) ^ (sec_r000245_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_336_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_336_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = (((stage_v_176_1 << 2) ^ (sec_r000245_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_337_2 = (((stage_v_176_2 << 2) ^ (sec_r000245_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_337_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_337_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = (((sec_r000245_0_1 << 1) ^ (sec_r000245_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_338_2 = (((sec_r000245_0_2 << 1) ^ (sec_r000245_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_338_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_338_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000245_13_1 != sec_r000245_13_2);
  __CPROVER_assume(pub_r000245_5_1 == pub_r000245_5_2);
  __CPROVER_assume(pub_r000245_4_1 == pub_r000245_4_2);
  __CPROVER_assume(pub_r000245_16_1 == pub_r000245_16_2);
  __CPROVER_assume(sec_r000245_15_1 != sec_r000245_15_2);
  __CPROVER_assume(pub_r000245_15_1 == pub_r000245_15_2);
  __CPROVER_assume(pub_r000245_6_1 == pub_r000245_6_2);
  __CPROVER_assume(sec_r000245_2_1 != sec_r000245_2_2);
  __CPROVER_assume(pub_r000245_12_1 == pub_r000245_12_2);
  __CPROVER_assume(sec_r000245_11_1 != sec_r000245_11_2);
  __CPROVER_assume(sec_r000245_5_1 != sec_r000245_5_2);
  __CPROVER_assume(sec_r000245_8_1 != sec_r000245_8_2);
  __CPROVER_assume(sec_r000245_10_1 != sec_r000245_10_2);
  __CPROVER_assume(pub_r000245_0_1 == pub_r000245_0_2);
  __CPROVER_assume(pub_r000245_17_1 == pub_r000245_17_2);
  __CPROVER_assume(pub_r000245_3_1 == pub_r000245_3_2);
  __CPROVER_assume(pub_r000245_14_1 == pub_r000245_14_2);
  __CPROVER_assume(sec_r000245_4_1 != sec_r000245_4_2);
  __CPROVER_assume(sec_r000245_14_1 != sec_r000245_14_2);
  __CPROVER_assume(pub_r000245_2_1 == pub_r000245_2_2);
  __CPROVER_assume(pub_r000245_8_1 == pub_r000245_8_2);
  __CPROVER_assume(pub_r000245_20_1 == pub_r000245_20_2);
  __CPROVER_assume(sec_r000245_12_1 != sec_r000245_12_2);
  __CPROVER_assume(pub_r000245_10_1 == pub_r000245_10_2);
  __CPROVER_assume(sec_r000245_9_1 != sec_r000245_9_2);
  __CPROVER_assume(sec_r000245_0_1 != sec_r000245_0_2);
  __CPROVER_assume(sec_r000245_1_1 != sec_r000245_1_2);
  __CPROVER_assume(sec_r000245_7_1 != sec_r000245_7_2);
  __CPROVER_assume(pub_r000245_13_1 == pub_r000245_13_2);
  __CPROVER_assume(pub_r000245_19_1 == pub_r000245_19_2);
  __CPROVER_assume(pub_r000245_11_1 == pub_r000245_11_2);
  __CPROVER_assume(pub_r000245_18_1 == pub_r000245_18_2);
  __CPROVER_assume(sec_r000245_6_1 != sec_r000245_6_2);
  __CPROVER_assume(pub_r000245_7_1 == pub_r000245_7_2);
  __CPROVER_assume(pub_r000245_9_1 == pub_r000245_9_2);
  __CPROVER_assume(sec_r000245_3_1 != sec_r000245_3_2);
  __CPROVER_assume(pub_r000245_1_1 == pub_r000245_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
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
}


