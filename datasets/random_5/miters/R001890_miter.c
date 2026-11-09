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
struct EventLog_R001890_9013_0
{
  int seq;
  short signature;
  short code;
  int severity;
  int buffer[3];
};
struct FilterState_R001890_9013_1
{
  unsigned char cutoff;
  short gain_db;
  unsigned char prev_out;
  short mode;
  unsigned char damping;
  int prev_in;
  int buffer[3];
};
struct Vector3D_R001890_9013_2
{
  unsigned char norm_sq;
  short coord_z;
  int coord_x;
  int heading;
  int coord_y;
  int buffer[3];
};
union PacketPayload_R001890_9013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001890_9013_1
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
void fn_R001890_9013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_60_1) & 63;
  aux_2 = (aux_2 + checksum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_60_1 == checksum_60_2);
}

int fn_R001890_9013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st_1 = {0};
  struct FilterState_R001890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_74_1 = local_arr_1[aux_1 % 3];
  int scale_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_74_2 * 2)) & 127;
  int damping_20_1 = 0;
  int damping_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_20_1 = ((damping_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_20_2 = ((damping_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_20_1) & 127;
    acc_2 = (acc_2 + damping_20_2) & 127;
  }

  int margin_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_76_1 > 50)
  {
    acc_1 = ((acc_1 + (margin_76_1 * 2)) + 5) & 127;
    aux_1 ^= margin_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_76_2 > 50)
  {
    acc_2 = ((acc_2 + (margin_76_2 * 2)) + 5) & 127;
    aux_2 ^= margin_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_27_1) & 63;
  aux_2 = (aux_2 + scale_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_74_1 == scale_74_2);
  assert(damping_20_1 == damping_20_2);
  assert(margin_76_1 == margin_76_2);
  assert(scale_27_1 == scale_27_2);
}

int fn_R001890_9013_1(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int scale_74 = local_arr[aux % 3];
  acc = (acc + (scale_74 * 2)) & 127;
  int damping_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_20 = ((damping_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_20) & 127;
  }

  int margin_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_76 > 50)
  {
    acc = ((acc + (margin_76 * 2)) + 5) & 127;
    aux ^= margin_76 & 15;
  }
  else
  {
    acc = ((acc - margin_76) + 11) & 127;
    aux += 3;
  }
  int scale_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int pivot_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_31_1)
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

  switch (pivot_31_2)
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

  int anchor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_10_1 > 32)
  {
    acc_1 = ((acc_1 + (anchor_10_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_10_2 > 32)
  {
    acc_2 = ((acc_2 + (anchor_10_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_31_1 == pivot_31_2);
  assert(anchor_10_1 == anchor_10_2);
}

int fn_R001890_9013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int pivot_31 = (aux + st.buffer[1]) & 3;
  switch (pivot_31)
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

  int anchor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_10 > 32)
  {
    acc = ((acc + (anchor_10 * 2)) + 5) & 127;
    aux ^= anchor_10 & 15;
  }
  else
  {
    acc = ((acc - anchor_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001890_9013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
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
  int delta_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_69_1) & 63;
  aux_2 = (aux_2 + delta_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_40_1 = 0;
  int accumulator_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_40_1 = ((accumulator_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_40_2 = ((accumulator_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_40_1) & 127;
    acc_2 = (acc_2 + accumulator_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_69_1 == delta_69_2);
  assert(accumulator_40_1 == accumulator_40_2);
}

int fn_R001890_9013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_69) & 63;
  acc ^= aux;
  int accumulator_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_40 = ((accumulator_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001890_9013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int vector_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_90_1)
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

  switch (vector_90_2)
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

  int weight_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_66_1) & 63;
  aux_2 = (aux_2 + weight_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_75_1 = 0;
  int parity_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_75_1 = ((parity_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_75_2 = ((parity_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_75_1) & 127;
    acc_2 = (acc_2 + parity_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_90_1 == vector_90_2);
  assert(weight_66_1 == weight_66_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R001890_9013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int vector_90 = (aux + st.buffer[1]) & 3;
  switch (vector_90)
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

  int weight_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_66) & 63;
  acc ^= aux;
  int parity_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_75 = ((parity_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001890_9013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_15_1 = local_arr_1[aux_1 % 3];
  int anchor_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_15_2 * 2)) & 127;
  int bound_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_61_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_61_1 * 2)) + 5) & 127;
    aux_1 ^= bound_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_61_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_61_2 * 2)) + 5) & 127;
    aux_2 ^= bound_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_15_1 == anchor_15_2);
  assert(bound_61_1 == bound_61_2);
}

int fn_R001890_9013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int anchor_15 = local_arr[aux % 3];
  acc = (acc + (anchor_15 * 2)) & 127;
  int bound_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_61 > 10)
  {
    acc = ((acc + (bound_61 * 2)) + 5) & 127;
    aux ^= bound_61 & 15;
  }
  else
  {
    acc = ((acc - bound_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001890_9013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_41_1)
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

  switch (margin_41_2)
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

  int scale_27_1 = 0;
  int scale_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_27_1 = ((scale_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_27_2 = ((scale_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_27_1) & 127;
    acc_2 = (acc_2 + scale_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_41_1 == margin_41_2);
  assert(scale_27_1 == scale_27_2);
}

int fn_R001890_9013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_41 = (aux + st.buffer[1]) & 3;
  switch (margin_41)
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

  int scale_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_27 = ((scale_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001890_9013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_25_1 = local_arr_1[aux_1 % 3];
  int sample_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_25_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_38_1) & 63;
  aux_2 = (aux_2 + offset_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(offset_38_1 == offset_38_2);
}

int fn_R001890_9013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int sample_25 = local_arr[aux % 3];
  acc = (acc + (sample_25 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_93_1 = local_arr_1[aux_1 % 3];
  int quotient_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_93_2 * 2)) & 127;
  int index_reg_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_53_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_53_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_53_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_53_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_78_1) & 63;
  aux_2 = (aux_2 + quantum_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_93_1 == quotient_93_2);
  assert(index_reg_53_1 == index_reg_53_2);
  assert(quantum_78_1 == quantum_78_2);
}

int fn_R001890_9013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quotient_93 = local_arr[aux % 3];
  acc = (acc + (quotient_93 * 2)) & 127;
  int index_reg_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_53 > 35)
  {
    acc = ((acc + (index_reg_53 * 2)) + 5) & 127;
    aux ^= index_reg_53 & 15;
  }
  else
  {
    acc = ((acc - index_reg_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_50_1) & 63;
  aux_2 = (aux_2 + damping_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_91_1 = 0;
  int index_reg_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_91_1 = ((index_reg_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_91_2 = ((index_reg_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_91_1) & 127;
    acc_2 = (acc_2 + index_reg_91_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_50_1 == damping_50_2);
  assert(index_reg_91_1 == index_reg_91_2);
}

int fn_R001890_9013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_50) & 63;
  acc ^= aux;
  int index_reg_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_91 = ((index_reg_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_91) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001890_9013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_79_1)
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

  switch (sample_79_2)
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

  int quotient_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_40_1 > 46)
  {
    acc_1 = ((acc_1 + (quotient_40_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_40_2 > 46)
  {
    acc_2 = ((acc_2 + (quotient_40_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_79_1 == sample_79_2);
  assert(quotient_40_1 == quotient_40_2);
}

int fn_R001890_9013_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_79 = (aux + st.buffer[1]) & 3;
  switch (sample_79)
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

  int quotient_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_40 > 46)
  {
    acc = ((acc + (quotient_40 * 2)) + 5) & 127;
    aux ^= quotient_40 & 15;
  }
  else
  {
    acc = ((acc - quotient_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001890_9013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st_1 = {0};
  struct FilterState_R001890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_45_1) & 63;
  aux_2 = (aux_2 + bound_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_49_1 = local_arr_1[aux_1 % 3];
  int checksum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_49_2 * 2)) & 127;
  int bound_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_79_1 > 43)
  {
    acc_1 = ((acc_1 + (bound_79_1 * 2)) + 5) & 127;
    aux_1 ^= bound_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_79_2 > 43)
  {
    acc_2 = ((acc_2 + (bound_79_2 * 2)) + 5) & 127;
    aux_2 ^= bound_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_45_1 == bound_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_49_1 == checksum_49_2);
  assert(bound_79_1 == bound_79_2);
}

int fn_R001890_9013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_45) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_49 = local_arr[aux % 3];
  acc = (acc + (checksum_49 * 2)) & 127;
  int bound_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_79 > 43)
  {
    acc = ((acc + (bound_79 * 2)) + 5) & 127;
    aux ^= bound_79 & 15;
  }
  else
  {
    acc = ((acc - bound_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001890_9013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int weight_77_1 = 0;
  int weight_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_77_1 = ((weight_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_77_2 = ((weight_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_77_1) & 127;
    acc_2 = (acc_2 + weight_77_2) & 127;
  }

  int tracker_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_87_1)
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

  switch (tracker_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_77_1 == weight_77_2);
  assert(tracker_87_1 == tracker_87_2);
}

int fn_R001890_9013_12(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int weight_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_77 = ((weight_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_77) & 127;
  }

  int tracker_87 = (aux + st.buffer[1]) & 3;
  switch (tracker_87)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st_1 = {0};
  struct FilterState_R001890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int cursor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_33_1)
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

  switch (cursor_33_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_78_1) & 63;
  aux_2 = (aux_2 + factor_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_33_1 == cursor_33_2);
  assert(factor_78_1 == factor_78_2);
}

int fn_R001890_9013_13(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int cursor_33 = (aux + st.buffer[1]) & 3;
  switch (cursor_33)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_54_1) & 63;
  aux_2 = (aux_2 + segment_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_33_1 = 0;
  int pivot_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_33_1 = ((pivot_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_33_2 = ((pivot_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_33_1) & 127;
    acc_2 = (acc_2 + pivot_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_54_1 == segment_54_2);
  assert(pivot_33_1 == pivot_33_2);
}

int fn_R001890_9013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_54) & 63;
  acc ^= aux;
  int pivot_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_33 = ((pivot_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001890_9013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_52_1 = 0;
  int anchor_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_52_1 = ((anchor_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_52_2 = ((anchor_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_52_1) & 127;
    acc_2 = (acc_2 + anchor_52_2) & 127;
  }

  int anchor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_42_1)
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

  switch (anchor_42_2)
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
  int quotient_95_1 = local_arr_1[aux_1 % 3];
  int quotient_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_52_1 == anchor_52_2);
  assert(anchor_42_1 == anchor_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_95_1 == quotient_95_2);
}

int fn_R001890_9013_15(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_52 = ((anchor_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_52) & 127;
  }

  int anchor_42 = (aux + st.buffer[1]) & 3;
  switch (anchor_42)
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
  int quotient_95 = local_arr[aux % 3];
  acc = (acc + (quotient_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_25_1 = 0;
  int tracker_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_25_1 = ((tracker_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_25_2 = ((tracker_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_25_1) & 127;
    acc_2 = (acc_2 + tracker_25_2) & 127;
  }

  int sample_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_62_1)
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

  switch (sample_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_25_1 == tracker_25_2);
  assert(sample_62_1 == sample_62_2);
}

int fn_R001890_9013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_25 = ((tracker_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_25) & 127;
  }

  int sample_62 = (aux + st.buffer[1]) & 3;
  switch (sample_62)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_93_1 > 11)
  {
    acc_1 = ((acc_1 + (threshold_93_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_93_2 > 11)
  {
    acc_2 = ((acc_2 + (threshold_93_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_19_1 = 0;
  int margin_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_19_1 = ((margin_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_19_2 = ((margin_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_19_1) & 127;
    acc_2 = (acc_2 + margin_19_2) & 127;
  }

  int mask_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_58_1) & 63;
  aux_2 = (aux_2 + mask_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_93_1 == threshold_93_2);
  assert(margin_19_1 == margin_19_2);
  assert(mask_58_1 == mask_58_2);
}

int fn_R001890_9013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_93 > 11)
  {
    acc = ((acc + (threshold_93 * 2)) + 5) & 127;
    aux ^= threshold_93 & 15;
  }
  else
  {
    acc = ((acc - threshold_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_19 = ((margin_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_19) & 127;
  }

  int mask_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
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
  int factor_96_1 = 0;
  int factor_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_96_1 = ((factor_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_96_2 = ((factor_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_96_1) & 127;
    acc_2 = (acc_2 + factor_96_2) & 127;
  }

  int threshold_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_99_1) & 63;
  aux_2 = (aux_2 + threshold_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_96_1 == factor_96_2);
  assert(threshold_99_1 == threshold_99_2);
}

int fn_R001890_9013_18(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_96 = ((factor_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_96) & 127;
  }

  int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001890_9013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st_1 = {0};
  struct EventLog_R001890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int parity_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_79_1)
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

  switch (parity_79_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_21_1 = local_arr_1[aux_1 % 3];
  int factor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_79_1 == parity_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_21_1 == factor_21_2);
}

int fn_R001890_9013_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int parity_79 = (aux + st.buffer[1]) & 3;
  switch (parity_79)
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

  int local_arr[3] = {4, 9, 15};
  int factor_21 = local_arr[aux % 3];
  acc = (acc + (factor_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st_1 = {0};
  struct FilterState_R001890_9013_1 st_2 = {0};
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
  int damping_24_1 = 0;
  int damping_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_24_1 = ((damping_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_24_2 = ((damping_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_24_1) & 127;
    acc_2 = (acc_2 + damping_24_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_51_1 = local_arr_1[aux_1 % 3];
  int residue_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_24_1 == damping_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_51_1 == residue_51_2);
}

int fn_R001890_9013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_24 = ((damping_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_24) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_51 = local_arr[aux % 3];
  acc = (acc + (residue_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st_1 = {0};
  struct FilterState_R001890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_84_1 = local_arr_1[aux_1 % 3];
  int bound_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_84_2 * 2)) & 127;
  int metric_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_44_1)
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

  switch (metric_44_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_84_1 == bound_84_2);
  assert(metric_44_1 == metric_44_2);
}

int fn_R001890_9013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int bound_84 = local_arr[aux % 3];
  acc = (acc + (bound_84 * 2)) & 127;
  int metric_44 = (aux + st.buffer[1]) & 3;
  switch (metric_44)
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

void fn_R001890_9013_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_33_1 = 0;
  int anchor_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_33_1 = ((anchor_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_33_2 = ((anchor_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_33_1) & 127;
    acc_2 = (acc_2 + anchor_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_33_1 == anchor_33_2);
}

int fn_R001890_9013_22(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_33 = ((anchor_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001890_9013_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st_1 = {0};
  struct Vector3D_R001890_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_19_1 = local_arr_1[aux_1 % 3];
  int phase_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_19_1 == phase_19_2);
}

int fn_R001890_9013_23(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001890_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int phase_19 = local_arr[aux % 3];
  acc = (acc + (phase_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001890_0_1;
  int sec_r001890_0_2;
  int sec_r001890_1_1;
  int sec_r001890_1_2;
  int sec_r001890_2_1;
  int sec_r001890_2_2;
  int sec_r001890_3_1;
  int sec_r001890_3_2;
  int sec_r001890_4_1;
  int sec_r001890_4_2;
  int sec_r001890_5_1;
  int sec_r001890_5_2;
  int sec_r001890_6_1;
  int sec_r001890_6_2;
  int sec_r001890_7_1;
  int sec_r001890_7_2;
  int sec_r001890_8_1;
  int sec_r001890_8_2;
  int sec_r001890_9_1;
  int sec_r001890_9_2;
  int sec_r001890_10_1;
  int sec_r001890_10_2;
  int sec_r001890_11_1;
  int sec_r001890_11_2;
  int sec_r001890_12_1;
  int sec_r001890_12_2;
  int sec_r001890_13_1;
  int sec_r001890_13_2;
  int sec_r001890_14_1;
  int sec_r001890_14_2;
  int sec_r001890_15_1;
  int sec_r001890_15_2;
  int sec_r001890_16_1;
  int sec_r001890_16_2;
  int sec_r001890_17_1;
  int sec_r001890_17_2;
  int sec_r001890_18_1;
  int sec_r001890_18_2;
  int sec_r001890_19_1;
  int sec_r001890_19_2;
  int pub_r001890_0_1;
  int pub_r001890_0_2;
  int pub_r001890_1_1;
  int pub_r001890_1_2;
  int pub_r001890_2_1;
  int pub_r001890_2_2;
  int pub_r001890_3_1;
  int pub_r001890_3_2;
  int pub_r001890_4_1;
  int pub_r001890_4_2;
  int pub_r001890_5_1;
  int pub_r001890_5_2;
  int pub_r001890_6_1;
  int pub_r001890_6_2;
  int pub_r001890_7_1;
  int pub_r001890_7_2;
  int pub_r001890_8_1;
  int pub_r001890_8_2;
  int pub_r001890_9_1;
  int pub_r001890_9_2;
  int pub_r001890_10_1;
  int pub_r001890_10_2;
  int pub_r001890_11_1;
  int pub_r001890_11_2;
  int pub_r001890_12_1;
  int pub_r001890_12_2;
  int pub_r001890_13_1;
  int pub_r001890_13_2;
  int pub_r001890_14_1;
  int pub_r001890_14_2;
  int pub_r001890_15_1;
  int pub_r001890_15_2;
  int pub_r001890_16_1;
  int pub_r001890_16_2;
  int pub_r001890_17_1;
  int pub_r001890_17_2;
  int pub_r001890_18_1;
  int pub_r001890_18_2;
  int pub_r001890_19_1;
  int pub_r001890_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001890_0_1 >= (-100)) && (pub_r001890_0_1 <= 100));
  __CPROVER_assume((pub_r001890_0_2 >= (-100)) && (pub_r001890_0_2 <= 100));
  __CPROVER_assume((pub_r001890_1_1 >= (-100)) && (pub_r001890_1_1 <= 100));
  __CPROVER_assume((pub_r001890_1_2 >= (-100)) && (pub_r001890_1_2 <= 100));
  __CPROVER_assume((pub_r001890_2_1 >= (-100)) && (pub_r001890_2_1 <= 100));
  __CPROVER_assume((pub_r001890_2_2 >= (-100)) && (pub_r001890_2_2 <= 100));
  __CPROVER_assume((pub_r001890_3_1 >= (-100)) && (pub_r001890_3_1 <= 100));
  __CPROVER_assume((pub_r001890_3_2 >= (-100)) && (pub_r001890_3_2 <= 100));
  __CPROVER_assume((pub_r001890_4_1 >= (-100)) && (pub_r001890_4_1 <= 100));
  __CPROVER_assume((pub_r001890_4_2 >= (-100)) && (pub_r001890_4_2 <= 100));
  __CPROVER_assume((pub_r001890_5_1 >= (-100)) && (pub_r001890_5_1 <= 100));
  __CPROVER_assume((pub_r001890_5_2 >= (-100)) && (pub_r001890_5_2 <= 100));
  __CPROVER_assume((pub_r001890_6_1 >= (-100)) && (pub_r001890_6_1 <= 100));
  __CPROVER_assume((pub_r001890_6_2 >= (-100)) && (pub_r001890_6_2 <= 100));
  __CPROVER_assume((pub_r001890_7_1 >= (-100)) && (pub_r001890_7_1 <= 100));
  __CPROVER_assume((pub_r001890_7_2 >= (-100)) && (pub_r001890_7_2 <= 100));
  __CPROVER_assume((pub_r001890_8_1 >= (-100)) && (pub_r001890_8_1 <= 100));
  __CPROVER_assume((pub_r001890_8_2 >= (-100)) && (pub_r001890_8_2 <= 100));
  __CPROVER_assume((pub_r001890_9_1 >= (-100)) && (pub_r001890_9_1 <= 100));
  __CPROVER_assume((pub_r001890_9_2 >= (-100)) && (pub_r001890_9_2 <= 100));
  __CPROVER_assume((pub_r001890_10_1 >= (-100)) && (pub_r001890_10_1 <= 100));
  __CPROVER_assume((pub_r001890_10_2 >= (-100)) && (pub_r001890_10_2 <= 100));
  __CPROVER_assume((pub_r001890_11_1 >= (-100)) && (pub_r001890_11_1 <= 100));
  __CPROVER_assume((pub_r001890_11_2 >= (-100)) && (pub_r001890_11_2 <= 100));
  __CPROVER_assume((pub_r001890_12_1 >= (-100)) && (pub_r001890_12_1 <= 100));
  __CPROVER_assume((pub_r001890_12_2 >= (-100)) && (pub_r001890_12_2 <= 100));
  __CPROVER_assume((pub_r001890_13_1 >= (-100)) && (pub_r001890_13_1 <= 100));
  __CPROVER_assume((pub_r001890_13_2 >= (-100)) && (pub_r001890_13_2 <= 100));
  __CPROVER_assume((pub_r001890_14_1 >= (-100)) && (pub_r001890_14_1 <= 100));
  __CPROVER_assume((pub_r001890_14_2 >= (-100)) && (pub_r001890_14_2 <= 100));
  __CPROVER_assume((pub_r001890_15_1 >= (-100)) && (pub_r001890_15_1 <= 100));
  __CPROVER_assume((pub_r001890_15_2 >= (-100)) && (pub_r001890_15_2 <= 100));
  __CPROVER_assume((pub_r001890_16_1 >= (-100)) && (pub_r001890_16_1 <= 100));
  __CPROVER_assume((pub_r001890_16_2 >= (-100)) && (pub_r001890_16_2 <= 100));
  __CPROVER_assume((pub_r001890_17_1 >= (-100)) && (pub_r001890_17_1 <= 100));
  __CPROVER_assume((pub_r001890_17_2 >= (-100)) && (pub_r001890_17_2 <= 100));
  __CPROVER_assume((pub_r001890_18_1 >= (-100)) && (pub_r001890_18_1 <= 100));
  __CPROVER_assume((pub_r001890_18_2 >= (-100)) && (pub_r001890_18_2 <= 100));
  __CPROVER_assume((pub_r001890_19_1 >= (-100)) && (pub_r001890_19_1 <= 100));
  __CPROVER_assume((pub_r001890_19_2 >= (-100)) && (pub_r001890_19_2 <= 100));
  __CPROVER_assume((sec_r001890_0_1 >= 0) && (sec_r001890_0_1 <= 255));
  __CPROVER_assume((sec_r001890_0_2 >= 0) && (sec_r001890_0_2 <= 255));
  __CPROVER_assume((sec_r001890_1_1 >= 0) && (sec_r001890_1_1 <= 255));
  __CPROVER_assume((sec_r001890_1_2 >= 0) && (sec_r001890_1_2 <= 255));
  __CPROVER_assume((sec_r001890_2_1 >= 0) && (sec_r001890_2_1 <= 255));
  __CPROVER_assume((sec_r001890_2_2 >= 0) && (sec_r001890_2_2 <= 255));
  __CPROVER_assume((sec_r001890_3_1 >= 0) && (sec_r001890_3_1 <= 255));
  __CPROVER_assume((sec_r001890_3_2 >= 0) && (sec_r001890_3_2 <= 255));
  __CPROVER_assume((sec_r001890_4_1 >= 0) && (sec_r001890_4_1 <= 255));
  __CPROVER_assume((sec_r001890_4_2 >= 0) && (sec_r001890_4_2 <= 255));
  __CPROVER_assume((sec_r001890_5_1 >= 0) && (sec_r001890_5_1 <= 255));
  __CPROVER_assume((sec_r001890_5_2 >= 0) && (sec_r001890_5_2 <= 255));
  __CPROVER_assume((sec_r001890_6_1 >= 0) && (sec_r001890_6_1 <= 255));
  __CPROVER_assume((sec_r001890_6_2 >= 0) && (sec_r001890_6_2 <= 255));
  __CPROVER_assume((sec_r001890_7_1 >= 0) && (sec_r001890_7_1 <= 255));
  __CPROVER_assume((sec_r001890_7_2 >= 0) && (sec_r001890_7_2 <= 255));
  __CPROVER_assume((sec_r001890_8_1 >= 0) && (sec_r001890_8_1 <= 255));
  __CPROVER_assume((sec_r001890_8_2 >= 0) && (sec_r001890_8_2 <= 255));
  __CPROVER_assume((sec_r001890_9_1 >= 0) && (sec_r001890_9_1 <= 255));
  __CPROVER_assume((sec_r001890_9_2 >= 0) && (sec_r001890_9_2 <= 255));
  __CPROVER_assume((sec_r001890_10_1 >= 0) && (sec_r001890_10_1 <= 255));
  __CPROVER_assume((sec_r001890_10_2 >= 0) && (sec_r001890_10_2 <= 255));
  __CPROVER_assume((sec_r001890_11_1 >= 0) && (sec_r001890_11_1 <= 255));
  __CPROVER_assume((sec_r001890_11_2 >= 0) && (sec_r001890_11_2 <= 255));
  __CPROVER_assume((sec_r001890_12_1 >= 0) && (sec_r001890_12_1 <= 255));
  __CPROVER_assume((sec_r001890_12_2 >= 0) && (sec_r001890_12_2 <= 255));
  __CPROVER_assume((sec_r001890_13_1 >= 0) && (sec_r001890_13_1 <= 255));
  __CPROVER_assume((sec_r001890_13_2 >= 0) && (sec_r001890_13_2 <= 255));
  __CPROVER_assume((sec_r001890_14_1 >= 0) && (sec_r001890_14_1 <= 255));
  __CPROVER_assume((sec_r001890_14_2 >= 0) && (sec_r001890_14_2 <= 255));
  __CPROVER_assume((sec_r001890_15_1 >= 0) && (sec_r001890_15_1 <= 255));
  __CPROVER_assume((sec_r001890_15_2 >= 0) && (sec_r001890_15_2 <= 255));
  __CPROVER_assume((sec_r001890_16_1 >= 0) && (sec_r001890_16_1 <= 255));
  __CPROVER_assume((sec_r001890_16_2 >= 0) && (sec_r001890_16_2 <= 255));
  __CPROVER_assume((sec_r001890_17_1 >= 0) && (sec_r001890_17_1 <= 255));
  __CPROVER_assume((sec_r001890_17_2 >= 0) && (sec_r001890_17_2 <= 255));
  __CPROVER_assume((sec_r001890_18_1 >= 0) && (sec_r001890_18_1 <= 255));
  __CPROVER_assume((sec_r001890_18_2 >= 0) && (sec_r001890_18_2 <= 255));
  __CPROVER_assume((sec_r001890_19_1 >= 0) && (sec_r001890_19_1 <= 255));
  __CPROVER_assume((sec_r001890_19_2 >= 0) && (sec_r001890_19_2 <= 255));
  struct EventLog_R001890_9013_0 st_var_0_1 = {0};
  struct EventLog_R001890_9013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001890_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001890_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001890_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001890_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001890_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001890_0_2 + 7) & 15;
  struct FilterState_R001890_9013_1 st_var_1_1 = {0};
  struct FilterState_R001890_9013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001890_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001890_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001890_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001890_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001890_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001890_0_2 + 9) & 15;
  struct Vector3D_R001890_9013_2 st_var_2_1 = {0};
  struct Vector3D_R001890_9013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001890_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001890_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001890_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001890_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001890_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001890_0_2 + 11) & 15;
  union PacketPayload_R001890_9013_0 u_var_1;
  union PacketPayload_R001890_9013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001890_9013_0(sec_r001890_0_1, pub_r001890_1_1, pub_r001890_2_1, pub_r001890_3_1);
  int helper_flow_0_2 = fn_R001890_9013_0(sec_r001890_0_2, pub_r001890_1_2, pub_r001890_2_2, pub_r001890_3_2);
  fn_R001890_9013_0_2(sec_r001890_0_1, pub_r001890_1_1, pub_r001890_2_1, pub_r001890_3_1, sec_r001890_0_2, pub_r001890_1_2, pub_r001890_2_2, pub_r001890_3_2);
  int helper_flow_1_1 = fn_R001890_9013_1(sec_r001890_1_1, sec_r001890_2_1);
  int helper_flow_1_2 = fn_R001890_9013_1(sec_r001890_1_2, sec_r001890_2_2);
  fn_R001890_9013_1_2(sec_r001890_1_1, sec_r001890_2_1, sec_r001890_1_2, sec_r001890_2_2);
  int helper_flow_2_1 = fn_R001890_9013_2(sec_r001890_2_1, pub_r001890_3_1, pub_r001890_4_1);
  int helper_flow_2_2 = fn_R001890_9013_2(sec_r001890_2_2, pub_r001890_3_2, pub_r001890_4_2);
  fn_R001890_9013_2_2(sec_r001890_2_1, pub_r001890_3_1, pub_r001890_4_1, sec_r001890_2_2, pub_r001890_3_2, pub_r001890_4_2);
  int helper_flow_3_1 = fn_R001890_9013_3(sec_r001890_3_1, sec_r001890_4_1, pub_r001890_5_1);
  int helper_flow_3_2 = fn_R001890_9013_3(sec_r001890_3_2, sec_r001890_4_2, pub_r001890_5_2);
  fn_R001890_9013_3_2(sec_r001890_3_1, sec_r001890_4_1, pub_r001890_5_1, sec_r001890_3_2, sec_r001890_4_2, pub_r001890_5_2);
  int helper_flow_4_1 = fn_R001890_9013_4(sec_r001890_4_1, pub_r001890_5_1, pub_r001890_6_1, pub_r001890_7_1);
  int helper_flow_4_2 = fn_R001890_9013_4(sec_r001890_4_2, pub_r001890_5_2, pub_r001890_6_2, pub_r001890_7_2);
  fn_R001890_9013_4_2(sec_r001890_4_1, pub_r001890_5_1, pub_r001890_6_1, pub_r001890_7_1, sec_r001890_4_2, pub_r001890_5_2, pub_r001890_6_2, pub_r001890_7_2);
  int helper_flow_5_1 = fn_R001890_9013_5(sec_r001890_5_1, pub_r001890_6_1, pub_r001890_7_1);
  int helper_flow_5_2 = fn_R001890_9013_5(sec_r001890_5_2, pub_r001890_6_2, pub_r001890_7_2);
  fn_R001890_9013_5_2(sec_r001890_5_1, pub_r001890_6_1, pub_r001890_7_1, sec_r001890_5_2, pub_r001890_6_2, pub_r001890_7_2);
  int helper_flow_6_1 = fn_R001890_9013_6(sec_r001890_6_1, pub_r001890_7_1, pub_r001890_8_1);
  int helper_flow_6_2 = fn_R001890_9013_6(sec_r001890_6_2, pub_r001890_7_2, pub_r001890_8_2);
  fn_R001890_9013_6_2(sec_r001890_6_1, pub_r001890_7_1, pub_r001890_8_1, sec_r001890_6_2, pub_r001890_7_2, pub_r001890_8_2);
  int helper_flow_7_1 = fn_R001890_9013_7(sec_r001890_7_1, sec_r001890_8_1, pub_r001890_9_1);
  int helper_flow_7_2 = fn_R001890_9013_7(sec_r001890_7_2, sec_r001890_8_2, pub_r001890_9_2);
  fn_R001890_9013_7_2(sec_r001890_7_1, sec_r001890_8_1, pub_r001890_9_1, sec_r001890_7_2, sec_r001890_8_2, pub_r001890_9_2);
  int helper_flow_8_1 = fn_R001890_9013_8(sec_r001890_8_1, sec_r001890_9_1, pub_r001890_10_1, pub_r001890_11_1, pub_r001890_12_1);
  int helper_flow_8_2 = fn_R001890_9013_8(sec_r001890_8_2, sec_r001890_9_2, pub_r001890_10_2, pub_r001890_11_2, pub_r001890_12_2);
  fn_R001890_9013_8_2(sec_r001890_8_1, sec_r001890_9_1, pub_r001890_10_1, pub_r001890_11_1, pub_r001890_12_1, sec_r001890_8_2, sec_r001890_9_2, pub_r001890_10_2, pub_r001890_11_2, pub_r001890_12_2);
  int stage_v_0_1 = (((sec_r001890_3_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_0_2 = (((sec_r001890_3_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_0_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001890_0_1 * 2) + 42) & 63;
  int stage_v_1_2 = ((pub_r001890_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001890_2_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_2_2 = (((sec_r001890_2_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_2_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001890_6_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_3_2 = (((sec_r001890_6_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_3_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001890_8_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_4_2 = (((sec_r001890_8_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_4_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_5_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_5_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001890_4_1 * 2) + 11) & 63;
  int stage_v_6_2 = ((pub_r001890_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001890_0_1 * 2) + 7) & 63;
  int stage_v_7_2 = ((pub_r001890_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001890_16_1 * 2) + 10) & 63;
  int stage_v_8_2 = ((pub_r001890_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001890_15_1 * 2) + 36) & 63;
  int stage_v_9_2 = ((pub_r001890_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_10_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_10_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_11_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_11_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001890_7_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_12_2 = (((sec_r001890_7_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_12_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001890_9_1 * 2) + 49) & 63;
  int stage_v_13_2 = ((pub_r001890_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_14_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_14_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((sec_r001890_15_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_15_2 = (((sec_r001890_15_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_15_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_16_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_16_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_17_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_17_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001890_11_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_18_2 = (((sec_r001890_11_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_18_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_19_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_19_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((pub_r001890_3_1 * 2) + 14) & 63;
  int stage_v_20_2 = ((pub_r001890_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_21_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_21_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001890_6_1 * 2) + 17) & 63;
  int stage_v_22_2 = ((pub_r001890_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001890_19_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_23_2 = (((sec_r001890_19_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_23_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001890_14_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_24_2 = (((sec_r001890_14_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_24_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001890_6_1 * 2) + 42) & 63;
  int stage_v_25_2 = ((pub_r001890_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001890_2_1 * 2) + 11) & 63;
  int stage_v_26_2 = ((pub_r001890_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001890_10_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_27_2 = (((sec_r001890_10_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_27_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_28_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_28_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001890_1_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_29_2 = (((sec_r001890_1_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_29_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((sec_r001890_1_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_30_2 = (((sec_r001890_1_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_30_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001890_19_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_31_2 = (((sec_r001890_19_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_31_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((pub_r001890_18_1 * 2) + 32) & 63;
  int stage_v_32_2 = ((pub_r001890_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001890_12_1 * 2) + 18) & 63;
  int stage_v_33_2 = ((pub_r001890_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001890_10_1 * 2) + 43) & 63;
  int stage_v_34_2 = ((pub_r001890_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((sec_r001890_14_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_35_2 = (((sec_r001890_14_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_35_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_36_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_36_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_37_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_37_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001890_13_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_38_2 = (((sec_r001890_13_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_38_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_39_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_39_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_40_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_40_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001890_3_1) & 127;
  int stage_v_41_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001890_3_2) & 127;
  if (stage_v_41_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((sec_r001890_14_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_42_2 = (((sec_r001890_14_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_42_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_43_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_43_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001890_0_1 * 2) + 42) & 63;
  int stage_v_44_2 = ((pub_r001890_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001890_6_1 * 2) + 16) & 63;
  int stage_v_45_2 = ((pub_r001890_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_46_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_46_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001890_6_1 * 2) + 36) & 63;
  int stage_v_47_2 = ((pub_r001890_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((sec_r001890_6_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_48_2 = (((sec_r001890_6_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_48_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_49_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_49_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_50_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_50_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_51_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_51_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_52_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_52_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_53_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_53_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001890_8_1 * 2) + 14) & 63;
  int stage_v_54_2 = ((pub_r001890_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_55_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_55_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001890_19_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_56_2 = (((sec_r001890_19_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_56_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_57_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_57_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_58_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_58_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_59_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_59_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001890_12_1) & 127;
  int stage_v_60_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001890_12_2) & 127;
  if (stage_v_60_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_61_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_61_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001890_2_1 * 2) + 16) & 63;
  int stage_v_62_2 = ((pub_r001890_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_63_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_63_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((pub_r001890_19_1 * 2) + 29) & 63;
  int stage_v_64_2 = ((pub_r001890_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001890_6_1) & 127;
  int stage_v_65_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001890_6_2) & 127;
  if (stage_v_65_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_66_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_66_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_67_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_67_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((sec_r001890_4_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_68_2 = (((sec_r001890_4_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_68_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001890_3_1 * 2) + 37) & 63;
  int stage_v_69_2 = ((pub_r001890_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_70_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_70_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001890_16_1 * 2) + 46) & 63;
  int stage_v_71_2 = ((pub_r001890_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001890_3_1) & 127;
  int stage_v_72_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001890_3_2) & 127;
  if (stage_v_72_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_73_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_73_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_74_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_74_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_75_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_75_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((pub_r001890_15_1 * 2) + 31) & 63;
  int stage_v_76_2 = ((pub_r001890_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001890_7_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_77_2 = (((sec_r001890_7_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_77_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001890_13_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_78_2 = (((sec_r001890_13_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_78_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_79_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_79_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_80_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_80_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001890_19_1 * 2) + 45) & 63;
  int stage_v_81_2 = ((pub_r001890_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001890_0_1 * 2) + 35) & 63;
  int stage_v_82_2 = ((pub_r001890_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_83_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_83_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((sec_r001890_5_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_84_2 = (((sec_r001890_5_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_84_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_85_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_85_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001890_18_1 * 2) + 11) & 63;
  int stage_v_86_2 = ((pub_r001890_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_87_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_87_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001890_9_1 * 2) + 39) & 63;
  int stage_v_88_2 = ((pub_r001890_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001890_16_1 * 2) + 43) & 63;
  int stage_v_89_2 = ((pub_r001890_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_90_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_90_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_91_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_91_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_92_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_92_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_93_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_93_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_94_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_94_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_95_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_95_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((pub_r001890_0_1 * 2) + 29) & 63;
  int stage_v_96_2 = ((pub_r001890_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_97_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_97_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001890_12_1) & 127;
  int stage_v_98_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001890_12_2) & 127;
  if (stage_v_98_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_99_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_99_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((sec_r001890_16_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_100_2 = (((sec_r001890_16_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_100_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_101_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_101_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_102_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_102_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_103_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_103_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_104_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_104_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001890_6_1) & 127;
  int stage_v_105_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001890_6_2) & 127;
  if (stage_v_105_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_106_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_106_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001890_10_1 * 2) + 14) & 63;
  int stage_v_107_2 = ((pub_r001890_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((sec_r001890_5_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_108_2 = (((sec_r001890_5_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_108_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_109_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_109_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_110_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_110_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_111_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_111_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001890_4_1 * 2) + 49) & 63;
  int stage_v_112_2 = ((pub_r001890_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_113_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_113_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001890_4_1 * 2) + 22) & 63;
  int stage_v_114_2 = ((pub_r001890_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_115_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_115_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((sec_r001890_0_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_116_2 = (((sec_r001890_0_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_116_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001890_17_1 * 2) + 36) & 63;
  int stage_v_117_2 = ((pub_r001890_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001890_18_1 * 2) + 40) & 63;
  int stage_v_118_2 = ((pub_r001890_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_119_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_119_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_120_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_120_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_121_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_121_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_122_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_122_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001890_3_1) & 127;
  int stage_v_123_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001890_3_2) & 127;
  if (stage_v_123_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001890_9_1 * 2) + 44) & 63;
  int stage_v_124_2 = ((pub_r001890_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_125_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_125_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_126_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_126_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_127_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_127_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_128_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_128_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001890_15_1 * 2) + 40) & 63;
  int stage_v_129_2 = ((pub_r001890_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001890_5_1 * 2) + 41) & 63;
  int stage_v_130_2 = ((pub_r001890_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_131_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_131_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((sec_r001890_2_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_132_2 = (((sec_r001890_2_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_132_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_133_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_133_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001890_8_1) & 127;
  int stage_v_134_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001890_8_2) & 127;
  if (stage_v_134_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_135_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_135_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_136_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_136_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_137_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((pub_r001890_9_1 * 2) + 20) & 63;
  int stage_v_138_2 = ((pub_r001890_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_139_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_139_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((pub_r001890_15_1 * 2) + 24) & 63;
  int stage_v_140_2 = ((pub_r001890_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_141_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_141_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_142_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_142_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((pub_r001890_19_1 * 2) + 32) & 63;
  int stage_v_143_2 = ((pub_r001890_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001890_9_1 * 2) + 17) & 63;
  int stage_v_144_2 = ((pub_r001890_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_145_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_145_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_146_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_146_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001890_0_1) & 127;
  int stage_v_147_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001890_0_2) & 127;
  if (stage_v_147_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_148_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_148_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001890_19_1 * 2) + 49) & 63;
  int stage_v_149_2 = ((pub_r001890_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001890_2_1 * 2) + 22) & 63;
  int stage_v_150_2 = ((pub_r001890_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_151_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_151_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001890_10_1 * 2) + 43) & 63;
  int stage_v_152_2 = ((pub_r001890_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_153_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_153_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_154_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_154_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((pub_r001890_17_1 * 2) + 16) & 63;
  int stage_v_155_2 = ((pub_r001890_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_156_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_156_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((pub_r001890_3_1 * 2) + 40) & 63;
  int stage_v_157_2 = ((pub_r001890_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001890_9_1 * 2) + 31) & 63;
  int stage_v_158_2 = ((pub_r001890_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001890_6_1) & 127;
  int stage_v_159_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001890_6_2) & 127;
  if (stage_v_159_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001890_5_1 * 2) + 22) & 63;
  int stage_v_160_2 = ((pub_r001890_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001890_2_1 * 2) + 47) & 63;
  int stage_v_161_2 = ((pub_r001890_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001890_0_1 * 2) + 30) & 63;
  int stage_v_162_2 = ((pub_r001890_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((sec_r001890_5_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_163_2 = (((sec_r001890_5_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_163_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_164_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_164_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_165_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_165_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((pub_r001890_6_1 * 2) + 13) & 63;
  int stage_v_166_2 = ((pub_r001890_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_167_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_167_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((sec_r001890_4_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_168_2 = (((sec_r001890_4_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_168_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_169_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_169_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_170_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_170_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((sec_r001890_0_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_171_2 = (((sec_r001890_0_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_171_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_172_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_172_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_173_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_173_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_174_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_174_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001890_14_1 * 2) + 47) & 63;
  int stage_v_175_2 = ((pub_r001890_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001890_13_1) & 127;
  int stage_v_176_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001890_13_2) & 127;
  if (stage_v_176_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001890_5_1 * 2) + 18) & 63;
  int stage_v_177_2 = ((pub_r001890_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001890_0_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_178_2 = (((sec_r001890_0_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_178_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_179_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_179_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001890_10_1 * 2) + 40) & 63;
  int stage_v_180_2 = ((pub_r001890_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_181_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_181_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001890_10_1) & 127;
  int stage_v_182_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001890_10_2) & 127;
  if (stage_v_182_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001890_15_1 * 2) + 10) & 63;
  int stage_v_183_2 = ((pub_r001890_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_184_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_184_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001890_19_1 * 2) + 27) & 63;
  int stage_v_185_2 = ((pub_r001890_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001890_12_1) & 127;
  int stage_v_186_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001890_12_2) & 127;
  if (stage_v_186_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_187_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_187_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_188_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_188_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_189_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_189_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001890_1_1) & 127;
  int stage_v_190_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001890_1_2) & 127;
  if (stage_v_190_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_191_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_191_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_192_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_192_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001890_11_1) & 127;
  int stage_v_193_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001890_11_2) & 127;
  if (stage_v_193_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_194_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_194_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001890_19_1) & 127;
  int stage_v_195_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001890_19_2) & 127;
  if (stage_v_195_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((pub_r001890_9_1 * 2) + 9) & 63;
  int stage_v_196_2 = ((pub_r001890_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001890_2_1 * 2) + 27) & 63;
  int stage_v_197_2 = ((pub_r001890_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_198_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_198_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001890_9_1 * 2) + 45) & 63;
  int stage_v_199_2 = ((pub_r001890_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_189_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_200_2 = (((stage_v_189_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_200_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001890_12_1) & 127;
  int stage_v_201_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001890_12_2) & 127;
  if (stage_v_201_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001890_14_1) & 127;
  int stage_v_202_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001890_14_2) & 127;
  if (stage_v_202_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001890_2_1 * 2) + 40) & 63;
  int stage_v_203_2 = ((pub_r001890_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001890_6_1) & 127;
  int stage_v_204_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001890_6_2) & 127;
  if (stage_v_204_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001890_5_1 * 2) + 32) & 63;
  int stage_v_205_2 = ((pub_r001890_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001890_2_1) & 127;
  int stage_v_206_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001890_2_2) & 127;
  if (stage_v_206_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_207_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_207_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001890_13_1 * 2) + 28) & 63;
  int stage_v_208_2 = ((pub_r001890_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001890_7_1) & 127;
  int stage_v_209_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001890_7_2) & 127;
  if (stage_v_209_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_163_1 ^ 0x2A) * 2) + pub_r001890_15_1) & 127;
  int stage_v_210_2 = (((stage_v_163_2 ^ 0x2A) * 2) + pub_r001890_15_2) & 127;
  if (stage_v_210_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((sec_r001890_8_1 ^ 0x2A) * 2) + pub_r001890_9_1) & 127;
  int stage_v_211_2 = (((sec_r001890_8_2 ^ 0x2A) * 2) + pub_r001890_9_2) & 127;
  if (stage_v_211_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001890_14_1 * 2) + 48) & 63;
  int stage_v_212_2 = ((pub_r001890_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001890_18_1 * 2) + 34) & 63;
  int stage_v_213_2 = ((pub_r001890_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((sec_r001890_3_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_214_2 = (((sec_r001890_3_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_214_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001890_12_1 * 2) + 42) & 63;
  int stage_v_215_2 = ((pub_r001890_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001890_18_1) & 127;
  int stage_v_216_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001890_18_2) & 127;
  if (stage_v_216_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001890_17_1) & 127;
  int stage_v_217_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001890_17_2) & 127;
  if (stage_v_217_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((sec_r001890_12_1 ^ 0x2A) * 2) + pub_r001890_5_1) & 127;
  int stage_v_218_2 = (((sec_r001890_12_2 ^ 0x2A) * 2) + pub_r001890_5_2) & 127;
  if (stage_v_218_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((pub_r001890_17_1 * 2) + 13) & 63;
  int stage_v_219_2 = ((pub_r001890_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001890_3_1) & 127;
  int stage_v_220_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001890_3_2) & 127;
  if (stage_v_220_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001890_4_1) & 127;
  int stage_v_221_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001890_4_2) & 127;
  if (stage_v_221_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001890_16_1) & 127;
  int stage_v_222_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001890_16_2) & 127;
  if (stage_v_222_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001890_9_1 != sec_r001890_9_2);
  __CPROVER_assume(sec_r001890_12_1 != sec_r001890_12_2);
  __CPROVER_assume(sec_r001890_8_1 != sec_r001890_8_2);
  __CPROVER_assume(pub_r001890_13_1 == pub_r001890_13_2);
  __CPROVER_assume(pub_r001890_15_1 == pub_r001890_15_2);
  __CPROVER_assume(pub_r001890_17_1 == pub_r001890_17_2);
  __CPROVER_assume(sec_r001890_2_1 != sec_r001890_2_2);
  __CPROVER_assume(sec_r001890_0_1 != sec_r001890_0_2);
  __CPROVER_assume(sec_r001890_10_1 != sec_r001890_10_2);
  __CPROVER_assume(sec_r001890_17_1 != sec_r001890_17_2);
  __CPROVER_assume(pub_r001890_8_1 == pub_r001890_8_2);
  __CPROVER_assume(pub_r001890_12_1 == pub_r001890_12_2);
  __CPROVER_assume(pub_r001890_10_1 == pub_r001890_10_2);
  __CPROVER_assume(sec_r001890_1_1 != sec_r001890_1_2);
  __CPROVER_assume(sec_r001890_11_1 != sec_r001890_11_2);
  __CPROVER_assume(pub_r001890_3_1 == pub_r001890_3_2);
  __CPROVER_assume(pub_r001890_11_1 == pub_r001890_11_2);
  __CPROVER_assume(sec_r001890_7_1 != sec_r001890_7_2);
  __CPROVER_assume(sec_r001890_15_1 != sec_r001890_15_2);
  __CPROVER_assume(sec_r001890_16_1 != sec_r001890_16_2);
  __CPROVER_assume(pub_r001890_7_1 == pub_r001890_7_2);
  __CPROVER_assume(pub_r001890_14_1 == pub_r001890_14_2);
  __CPROVER_assume(sec_r001890_5_1 != sec_r001890_5_2);
  __CPROVER_assume(pub_r001890_18_1 == pub_r001890_18_2);
  __CPROVER_assume(pub_r001890_19_1 == pub_r001890_19_2);
  __CPROVER_assume(sec_r001890_13_1 != sec_r001890_13_2);
  __CPROVER_assume(sec_r001890_18_1 != sec_r001890_18_2);
  __CPROVER_assume(sec_r001890_3_1 != sec_r001890_3_2);
  __CPROVER_assume(pub_r001890_16_1 == pub_r001890_16_2);
  __CPROVER_assume(sec_r001890_14_1 != sec_r001890_14_2);
  __CPROVER_assume(pub_r001890_5_1 == pub_r001890_5_2);
  __CPROVER_assume(sec_r001890_19_1 != sec_r001890_19_2);
  __CPROVER_assume(pub_r001890_1_1 == pub_r001890_1_2);
  __CPROVER_assume(sec_r001890_4_1 != sec_r001890_4_2);
  __CPROVER_assume(sec_r001890_6_1 != sec_r001890_6_2);
  __CPROVER_assume(pub_r001890_2_1 == pub_r001890_2_2);
  __CPROVER_assume(pub_r001890_4_1 == pub_r001890_4_2);
  __CPROVER_assume(pub_r001890_0_1 == pub_r001890_0_2);
  __CPROVER_assume(pub_r001890_9_1 == pub_r001890_9_2);
  __CPROVER_assume(pub_r001890_6_1 == pub_r001890_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
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
}


