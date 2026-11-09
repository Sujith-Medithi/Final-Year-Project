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
struct Vector3D_R001205_513_0
{
  int norm_sq;
  int coord_z;
  int heading;
  short coord_y;
  int coord_x;
  short pitch;
  int buffer[3];
};
struct EventLog_R001205_513_1
{
  int timestamp;
  int signature;
  int severity;
  int seq;
  short facility;
  unsigned char code;
  int buffer[3];
};
struct MatrixBlock_R001205_513_2
{
  short scale;
  short stride;
  int trace;
  unsigned char determinant;
  int density;
  int buffer[3];
};
struct FilterState_R001205_513_3
{
  int prev_out;
  short cutoff;
  int prev_in;
  int gain_db;
  int mode;
  short damping;
  int buffer[3];
};
union PacketPayload_R001205_513_0
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
void fn_R001205_513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_99_1 > 18)
  {
    acc_1 = ((acc_1 + (quantum_99_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_99_2 > 18)
  {
    acc_2 = ((acc_2 + (quantum_99_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_99_1 == quantum_99_2);
}

int fn_R001205_513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_99 > 18)
  {
    acc = ((acc + (quantum_99 * 2)) + 5) & 127;
    aux ^= quantum_99 & 15;
  }
  else
  {
    acc = ((acc - quantum_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001205_513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st_1 = {0};
  struct Vector3D_R001205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_86_1 = local_arr_1[aux_1 % 3];
  int index_reg_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_86_2 * 2)) & 127;
  int cursor_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_60_1)
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

  switch (cursor_60_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
  assert(cursor_60_1 == cursor_60_2);
}

int fn_R001205_513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int index_reg_86 = local_arr[aux % 3];
  acc = (acc + (index_reg_86 * 2)) & 127;
  int cursor_60 = (aux + st.buffer[1]) & 3;
  switch (cursor_60)
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

void fn_R001205_513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st_1 = {0};
  struct EventLog_R001205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int parity_71_1 = 0;
  int parity_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_71_1 = ((parity_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_71_2 = ((parity_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_71_1) & 127;
    acc_2 = (acc_2 + parity_71_2) & 127;
  }

  int weight_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_68_1) & 63;
  aux_2 = (aux_2 + weight_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_14_1 = local_arr_1[aux_1 % 3];
  int delta_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_71_1 == parity_71_2);
  assert(weight_68_1 == weight_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_14_1 == delta_14_2);
}

int fn_R001205_513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int parity_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_71 = ((parity_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_71) & 127;
  }

  int weight_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_14 = local_arr[aux % 3];
  acc = (acc + (delta_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001205_513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st_1 = {0};
  struct EventLog_R001205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quantum_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_40_1 > 39)
  {
    acc_1 = ((acc_1 + (quantum_40_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_40_2 > 39)
  {
    acc_2 = ((acc_2 + (quantum_40_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_74_1 = 0;
  int coefficient_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_74_1 = ((coefficient_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_74_2 = ((coefficient_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_74_1) & 127;
    acc_2 = (acc_2 + coefficient_74_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_64_1 = local_arr_1[aux_1 % 3];
  int threshold_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_40_1 == quantum_40_2);
  assert(coefficient_74_1 == coefficient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_64_1 == threshold_64_2);
}

int fn_R001205_513_3(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quantum_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_40 > 39)
  {
    acc = ((acc + (quantum_40 * 2)) + 5) & 127;
    aux ^= quantum_40 & 15;
  }
  else
  {
    acc = ((acc - quantum_40) + 11) & 127;
    aux += 3;
  }
  int coefficient_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_74 = ((coefficient_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_74) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_64 = local_arr[aux % 3];
  acc = (acc + (threshold_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001205_513_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st_1 = {0};
  struct EventLog_R001205_513_1 st_2 = {0};
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
  int damping_93_1 = 0;
  int damping_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_93_1 = ((damping_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_93_2 = ((damping_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_93_1) & 127;
    acc_2 = (acc_2 + damping_93_2) & 127;
  }

  int checksum_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_65_1) & 63;
  aux_2 = (aux_2 + checksum_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_31_1 = local_arr_1[aux_1 % 3];
  int sample_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_93_1 == damping_93_2);
  assert(checksum_65_1 == checksum_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_31_1 == sample_31_2);
}

int fn_R001205_513_4(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_93 = ((damping_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_93) & 127;
  }

  int checksum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_31 = local_arr[aux % 3];
  acc = (acc + (sample_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001205_513_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_52_1 = 0;
  int offset_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_52_1 = ((offset_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_52_2 = ((offset_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_52_1) & 127;
    acc_2 = (acc_2 + offset_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_48_1) & 63;
  aux_2 = (aux_2 + pivot_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_25_1)
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

  switch (bound_25_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_52_1 == offset_52_2);
  assert(pivot_48_1 == pivot_48_2);
  assert(bound_25_1 == bound_25_2);
}

int fn_R001205_513_5(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_52 = ((offset_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_48) & 63;
  acc ^= aux;
  int bound_25 = (aux + st.buffer[1]) & 3;
  switch (bound_25)
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

void fn_R001205_513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st_1 = {0};
  struct Vector3D_R001205_513_0 st_2 = {0};
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
  int accumulator_76_1 = 0;
  int accumulator_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_76_1 = ((accumulator_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_76_2 = ((accumulator_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_76_1) & 127;
    acc_2 = (acc_2 + accumulator_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_76_1 == accumulator_76_2);
}

int fn_R001205_513_6(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_76 = ((accumulator_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_76) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001205_513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st_1 = {0};
  struct EventLog_R001205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_11_1) & 63;
  aux_2 = (aux_2 + damping_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_35_1 = 0;
  int accumulator_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_35_1 = ((accumulator_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_35_2 = ((accumulator_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_35_1) & 127;
    acc_2 = (acc_2 + accumulator_35_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_14_1 > 32)
  {
    acc_1 = ((acc_1 + (bound_14_1 * 2)) + 5) & 127;
    aux_1 ^= bound_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_14_2 > 32)
  {
    acc_2 = ((acc_2 + (bound_14_2 * 2)) + 5) & 127;
    aux_2 ^= bound_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_11_1 == damping_11_2);
  assert(accumulator_35_1 == accumulator_35_2);
  assert(bound_14_1 == bound_14_2);
}

int fn_R001205_513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_11) & 63;
  acc ^= aux;
  int accumulator_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_35 = ((accumulator_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_35) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_14 > 32)
  {
    acc = ((acc + (bound_14 * 2)) + 5) & 127;
    aux ^= bound_14 & 15;
  }
  else
  {
    acc = ((acc - bound_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001205_513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st_1 = {0};
  struct Vector3D_R001205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_21_1 = 0;
  int metric_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_21_1 = ((metric_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_21_2 = ((metric_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_21_1) & 127;
    acc_2 = (acc_2 + metric_21_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_44_1 = local_arr_1[aux_1 % 3];
  int sample_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_44_2 * 2)) & 127;
  int accumulator_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_30_1 > 28)
  {
    acc_1 = ((acc_1 + (accumulator_30_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_30_2 > 28)
  {
    acc_2 = ((acc_2 + (accumulator_30_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_66_1) & 63;
  aux_2 = (aux_2 + pivot_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_21_1 == metric_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_44_1 == sample_44_2);
  assert(accumulator_30_1 == accumulator_30_2);
  assert(pivot_66_1 == pivot_66_2);
}

int fn_R001205_513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_21 = ((metric_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_21) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_44 = local_arr[aux % 3];
  acc = (acc + (sample_44 * 2)) & 127;
  int accumulator_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_30 > 28)
  {
    acc = ((acc + (accumulator_30 * 2)) + 5) & 127;
    aux ^= accumulator_30 & 15;
  }
  else
  {
    acc = ((acc - accumulator_30) + 11) & 127;
    aux += 3;
  }
  int pivot_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001205_513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001205_513_2 st_1 = {0};
  struct MatrixBlock_R001205_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_22_1)
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

  switch (threshold_22_2)
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
  int weight_88_1 = local_arr_1[aux_1 % 3];
  int weight_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_88_2 * 2)) & 127;
  int stride_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_99_1) & 63;
  aux_2 = (aux_2 + stride_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_22_1 == threshold_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_88_1 == weight_88_2);
  assert(stride_99_1 == stride_99_2);
}

int fn_R001205_513_9(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001205_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_22 = (aux + st.buffer[1]) & 3;
  switch (threshold_22)
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
  int weight_88 = local_arr[aux % 3];
  acc = (acc + (weight_88 * 2)) & 127;
  int stride_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001205_513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st_1 = {0};
  struct EventLog_R001205_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int index_reg_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_46_1) & 63;
  aux_2 = (aux_2 + index_reg_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_53_1)
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

  switch (accumulator_53_2)
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
  int phase_62_1 = local_arr_1[aux_1 % 3];
  int phase_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_62_2 * 2)) & 127;
  int margin_26_1 = 0;
  int margin_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_26_1 = ((margin_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_26_2 = ((margin_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_26_1) & 127;
    acc_2 = (acc_2 + margin_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_46_1 == index_reg_46_2);
  assert(accumulator_53_1 == accumulator_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_62_1 == phase_62_2);
  assert(margin_26_1 == margin_26_2);
}

int fn_R001205_513_10(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001205_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int index_reg_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_46) & 63;
  acc ^= aux;
  int accumulator_53 = (aux + st.buffer[1]) & 3;
  switch (accumulator_53)
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
  int phase_62 = local_arr[aux % 3];
  acc = (acc + (phase_62 * 2)) & 127;
  int margin_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_26 = ((margin_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001205_513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st_1 = {0};
  struct Vector3D_R001205_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_70_1)
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

  switch (checksum_70_2)
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

  int scale_94_1 = 0;
  int scale_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_94_1 = ((scale_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_94_2 = ((scale_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_94_1) & 127;
    acc_2 = (acc_2 + scale_94_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_70_1 == checksum_70_2);
  assert(scale_94_1 == scale_94_2);
}

int fn_R001205_513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001205_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_70 = (aux + st.buffer[1]) & 3;
  switch (checksum_70)
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

  int scale_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_94 = ((scale_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_94) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001205_513_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_74_1 = 0;
  int tally_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_74_1 = ((tally_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_74_2 = ((tally_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_74_1) & 127;
    acc_2 = (acc_2 + tally_74_2) & 127;
  }

  int quantum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_98_1)
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

  switch (quantum_98_2)
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

  int sample_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_20_1) & 63;
  aux_2 = (aux_2 + sample_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_74_1 == tally_74_2);
  assert(quantum_98_1 == quantum_98_2);
  assert(sample_20_1 == sample_20_2);
}

int fn_R001205_513_12(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_74 = ((tally_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_74) & 127;
  }

  int quantum_98 = (aux + st.buffer[1]) & 3;
  switch (quantum_98)
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

  int sample_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001205_513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_71_1 > 20)
  {
    acc_1 = ((acc_1 + (vector_71_1 * 2)) + 5) & 127;
    aux_1 ^= vector_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_71_2 > 20)
  {
    acc_2 = ((acc_2 + (vector_71_2 * 2)) + 5) & 127;
    aux_2 ^= vector_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_99_1 = 0;
  int coefficient_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_99_1 = ((coefficient_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_99_2 = ((coefficient_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_99_1) & 127;
    acc_2 = (acc_2 + coefficient_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_71_1 == vector_71_2);
  assert(coefficient_99_1 == coefficient_99_2);
}

int fn_R001205_513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_71 > 20)
  {
    acc = ((acc + (vector_71 * 2)) + 5) & 127;
    aux ^= vector_71 & 15;
  }
  else
  {
    acc = ((acc - vector_71) + 11) & 127;
    aux += 3;
  }
  int coefficient_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_99 = ((coefficient_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001205_513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int stride_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_72_1) & 63;
  aux_2 = (aux_2 + stride_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_77_1)
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

  switch (phase_77_2)
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

  int pivot_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_46_1 > 45)
  {
    acc_1 = ((acc_1 + (pivot_46_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_46_2 > 45)
  {
    acc_2 = ((acc_2 + (pivot_46_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_72_1 == stride_72_2);
  assert(phase_77_1 == phase_77_2);
  assert(pivot_46_1 == pivot_46_2);
}

int fn_R001205_513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int stride_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_72) & 63;
  acc ^= aux;
  int phase_77 = (aux + st.buffer[1]) & 3;
  switch (phase_77)
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

  int pivot_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_46 > 45)
  {
    acc = ((acc + (pivot_46 * 2)) + 5) & 127;
    aux ^= pivot_46 & 15;
  }
  else
  {
    acc = ((acc - pivot_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001205_513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st_1 = {0};
  struct FilterState_R001205_513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tracker_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_23_1)
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

  switch (tracker_23_2)
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

  int metric_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_81_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_81_1 * 2)) + 5) & 127;
    aux_1 ^= metric_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_81_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_81_2 * 2)) + 5) & 127;
    aux_2 ^= metric_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_23_1 == tracker_23_2);
  assert(metric_81_1 == metric_81_2);
}

int fn_R001205_513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001205_513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tracker_23 = (aux + st.buffer[1]) & 3;
  switch (tracker_23)
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

  int metric_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_81 > 31)
  {
    acc = ((acc + (metric_81 * 2)) + 5) & 127;
    aux ^= metric_81 & 15;
  }
  else
  {
    acc = ((acc - metric_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001205_0_1;
  int sec_r001205_0_2;
  int sec_r001205_1_1;
  int sec_r001205_1_2;
  int sec_r001205_2_1;
  int sec_r001205_2_2;
  int sec_r001205_3_1;
  int sec_r001205_3_2;
  int sec_r001205_4_1;
  int sec_r001205_4_2;
  int sec_r001205_5_1;
  int sec_r001205_5_2;
  int sec_r001205_6_1;
  int sec_r001205_6_2;
  int sec_r001205_7_1;
  int sec_r001205_7_2;
  int sec_r001205_8_1;
  int sec_r001205_8_2;
  int sec_r001205_9_1;
  int sec_r001205_9_2;
  int sec_r001205_10_1;
  int sec_r001205_10_2;
  int sec_r001205_11_1;
  int sec_r001205_11_2;
  int sec_r001205_12_1;
  int sec_r001205_12_2;
  int sec_r001205_13_1;
  int sec_r001205_13_2;
  int sec_r001205_14_1;
  int sec_r001205_14_2;
  int sec_r001205_15_1;
  int sec_r001205_15_2;
  int sec_r001205_16_1;
  int sec_r001205_16_2;
  int sec_r001205_17_1;
  int sec_r001205_17_2;
  int sec_r001205_18_1;
  int sec_r001205_18_2;
  int sec_r001205_19_1;
  int sec_r001205_19_2;
  int pub_r001205_0_1;
  int pub_r001205_0_2;
  int pub_r001205_1_1;
  int pub_r001205_1_2;
  int pub_r001205_2_1;
  int pub_r001205_2_2;
  int pub_r001205_3_1;
  int pub_r001205_3_2;
  int pub_r001205_4_1;
  int pub_r001205_4_2;
  int pub_r001205_5_1;
  int pub_r001205_5_2;
  int pub_r001205_6_1;
  int pub_r001205_6_2;
  int pub_r001205_7_1;
  int pub_r001205_7_2;
  int pub_r001205_8_1;
  int pub_r001205_8_2;
  int pub_r001205_9_1;
  int pub_r001205_9_2;
  int pub_r001205_10_1;
  int pub_r001205_10_2;
  int pub_r001205_11_1;
  int pub_r001205_11_2;
  int pub_r001205_12_1;
  int pub_r001205_12_2;
  int pub_r001205_13_1;
  int pub_r001205_13_2;
  int pub_r001205_14_1;
  int pub_r001205_14_2;
  int pub_r001205_15_1;
  int pub_r001205_15_2;
  int pub_r001205_16_1;
  int pub_r001205_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001205_0_1 >= (-100)) && (pub_r001205_0_1 <= 100));
  __CPROVER_assume((pub_r001205_0_2 >= (-100)) && (pub_r001205_0_2 <= 100));
  __CPROVER_assume((pub_r001205_1_1 >= (-100)) && (pub_r001205_1_1 <= 100));
  __CPROVER_assume((pub_r001205_1_2 >= (-100)) && (pub_r001205_1_2 <= 100));
  __CPROVER_assume((pub_r001205_2_1 >= (-100)) && (pub_r001205_2_1 <= 100));
  __CPROVER_assume((pub_r001205_2_2 >= (-100)) && (pub_r001205_2_2 <= 100));
  __CPROVER_assume((pub_r001205_3_1 >= (-100)) && (pub_r001205_3_1 <= 100));
  __CPROVER_assume((pub_r001205_3_2 >= (-100)) && (pub_r001205_3_2 <= 100));
  __CPROVER_assume((pub_r001205_4_1 >= (-100)) && (pub_r001205_4_1 <= 100));
  __CPROVER_assume((pub_r001205_4_2 >= (-100)) && (pub_r001205_4_2 <= 100));
  __CPROVER_assume((pub_r001205_5_1 >= (-100)) && (pub_r001205_5_1 <= 100));
  __CPROVER_assume((pub_r001205_5_2 >= (-100)) && (pub_r001205_5_2 <= 100));
  __CPROVER_assume((pub_r001205_6_1 >= (-100)) && (pub_r001205_6_1 <= 100));
  __CPROVER_assume((pub_r001205_6_2 >= (-100)) && (pub_r001205_6_2 <= 100));
  __CPROVER_assume((pub_r001205_7_1 >= (-100)) && (pub_r001205_7_1 <= 100));
  __CPROVER_assume((pub_r001205_7_2 >= (-100)) && (pub_r001205_7_2 <= 100));
  __CPROVER_assume((pub_r001205_8_1 >= (-100)) && (pub_r001205_8_1 <= 100));
  __CPROVER_assume((pub_r001205_8_2 >= (-100)) && (pub_r001205_8_2 <= 100));
  __CPROVER_assume((pub_r001205_9_1 >= (-100)) && (pub_r001205_9_1 <= 100));
  __CPROVER_assume((pub_r001205_9_2 >= (-100)) && (pub_r001205_9_2 <= 100));
  __CPROVER_assume((pub_r001205_10_1 >= (-100)) && (pub_r001205_10_1 <= 100));
  __CPROVER_assume((pub_r001205_10_2 >= (-100)) && (pub_r001205_10_2 <= 100));
  __CPROVER_assume((pub_r001205_11_1 >= (-100)) && (pub_r001205_11_1 <= 100));
  __CPROVER_assume((pub_r001205_11_2 >= (-100)) && (pub_r001205_11_2 <= 100));
  __CPROVER_assume((pub_r001205_12_1 >= (-100)) && (pub_r001205_12_1 <= 100));
  __CPROVER_assume((pub_r001205_12_2 >= (-100)) && (pub_r001205_12_2 <= 100));
  __CPROVER_assume((pub_r001205_13_1 >= (-100)) && (pub_r001205_13_1 <= 100));
  __CPROVER_assume((pub_r001205_13_2 >= (-100)) && (pub_r001205_13_2 <= 100));
  __CPROVER_assume((pub_r001205_14_1 >= (-100)) && (pub_r001205_14_1 <= 100));
  __CPROVER_assume((pub_r001205_14_2 >= (-100)) && (pub_r001205_14_2 <= 100));
  __CPROVER_assume((pub_r001205_15_1 >= (-100)) && (pub_r001205_15_1 <= 100));
  __CPROVER_assume((pub_r001205_15_2 >= (-100)) && (pub_r001205_15_2 <= 100));
  __CPROVER_assume((pub_r001205_16_1 >= (-100)) && (pub_r001205_16_1 <= 100));
  __CPROVER_assume((pub_r001205_16_2 >= (-100)) && (pub_r001205_16_2 <= 100));
  __CPROVER_assume((sec_r001205_0_1 >= 0) && (sec_r001205_0_1 <= 255));
  __CPROVER_assume((sec_r001205_0_2 >= 0) && (sec_r001205_0_2 <= 255));
  __CPROVER_assume((sec_r001205_1_1 >= 0) && (sec_r001205_1_1 <= 255));
  __CPROVER_assume((sec_r001205_1_2 >= 0) && (sec_r001205_1_2 <= 255));
  __CPROVER_assume((sec_r001205_2_1 >= 0) && (sec_r001205_2_1 <= 255));
  __CPROVER_assume((sec_r001205_2_2 >= 0) && (sec_r001205_2_2 <= 255));
  __CPROVER_assume((sec_r001205_3_1 >= 0) && (sec_r001205_3_1 <= 255));
  __CPROVER_assume((sec_r001205_3_2 >= 0) && (sec_r001205_3_2 <= 255));
  __CPROVER_assume((sec_r001205_4_1 >= 0) && (sec_r001205_4_1 <= 255));
  __CPROVER_assume((sec_r001205_4_2 >= 0) && (sec_r001205_4_2 <= 255));
  __CPROVER_assume((sec_r001205_5_1 >= 0) && (sec_r001205_5_1 <= 255));
  __CPROVER_assume((sec_r001205_5_2 >= 0) && (sec_r001205_5_2 <= 255));
  __CPROVER_assume((sec_r001205_6_1 >= 0) && (sec_r001205_6_1 <= 255));
  __CPROVER_assume((sec_r001205_6_2 >= 0) && (sec_r001205_6_2 <= 255));
  __CPROVER_assume((sec_r001205_7_1 >= 0) && (sec_r001205_7_1 <= 255));
  __CPROVER_assume((sec_r001205_7_2 >= 0) && (sec_r001205_7_2 <= 255));
  __CPROVER_assume((sec_r001205_8_1 >= 0) && (sec_r001205_8_1 <= 255));
  __CPROVER_assume((sec_r001205_8_2 >= 0) && (sec_r001205_8_2 <= 255));
  __CPROVER_assume((sec_r001205_9_1 >= 0) && (sec_r001205_9_1 <= 255));
  __CPROVER_assume((sec_r001205_9_2 >= 0) && (sec_r001205_9_2 <= 255));
  __CPROVER_assume((sec_r001205_10_1 >= 0) && (sec_r001205_10_1 <= 255));
  __CPROVER_assume((sec_r001205_10_2 >= 0) && (sec_r001205_10_2 <= 255));
  __CPROVER_assume((sec_r001205_11_1 >= 0) && (sec_r001205_11_1 <= 255));
  __CPROVER_assume((sec_r001205_11_2 >= 0) && (sec_r001205_11_2 <= 255));
  __CPROVER_assume((sec_r001205_12_1 >= 0) && (sec_r001205_12_1 <= 255));
  __CPROVER_assume((sec_r001205_12_2 >= 0) && (sec_r001205_12_2 <= 255));
  __CPROVER_assume((sec_r001205_13_1 >= 0) && (sec_r001205_13_1 <= 255));
  __CPROVER_assume((sec_r001205_13_2 >= 0) && (sec_r001205_13_2 <= 255));
  __CPROVER_assume((sec_r001205_14_1 >= 0) && (sec_r001205_14_1 <= 255));
  __CPROVER_assume((sec_r001205_14_2 >= 0) && (sec_r001205_14_2 <= 255));
  __CPROVER_assume((sec_r001205_15_1 >= 0) && (sec_r001205_15_1 <= 255));
  __CPROVER_assume((sec_r001205_15_2 >= 0) && (sec_r001205_15_2 <= 255));
  __CPROVER_assume((sec_r001205_16_1 >= 0) && (sec_r001205_16_1 <= 255));
  __CPROVER_assume((sec_r001205_16_2 >= 0) && (sec_r001205_16_2 <= 255));
  __CPROVER_assume((sec_r001205_17_1 >= 0) && (sec_r001205_17_1 <= 255));
  __CPROVER_assume((sec_r001205_17_2 >= 0) && (sec_r001205_17_2 <= 255));
  __CPROVER_assume((sec_r001205_18_1 >= 0) && (sec_r001205_18_1 <= 255));
  __CPROVER_assume((sec_r001205_18_2 >= 0) && (sec_r001205_18_2 <= 255));
  __CPROVER_assume((sec_r001205_19_1 >= 0) && (sec_r001205_19_1 <= 255));
  __CPROVER_assume((sec_r001205_19_2 >= 0) && (sec_r001205_19_2 <= 255));
  struct Vector3D_R001205_513_0 st_var_0_1 = {0};
  struct Vector3D_R001205_513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001205_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001205_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001205_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001205_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001205_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001205_0_2 + 7) & 15;
  struct EventLog_R001205_513_1 st_var_1_1 = {0};
  struct EventLog_R001205_513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001205_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001205_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001205_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001205_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001205_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001205_0_2 + 9) & 15;
  struct MatrixBlock_R001205_513_2 st_var_2_1 = {0};
  struct MatrixBlock_R001205_513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001205_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001205_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001205_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001205_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001205_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001205_0_2 + 11) & 15;
  struct FilterState_R001205_513_3 st_var_3_1 = {0};
  struct FilterState_R001205_513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001205_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001205_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001205_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001205_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001205_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001205_0_2 + 13) & 15;
  union PacketPayload_R001205_513_0 u_var_1;
  union PacketPayload_R001205_513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001205_513_0(sec_r001205_0_1, sec_r001205_1_1, pub_r001205_2_1);
  int helper_flow_0_2 = fn_R001205_513_0(sec_r001205_0_2, sec_r001205_1_2, pub_r001205_2_2);
  fn_R001205_513_0_2(sec_r001205_0_1, sec_r001205_1_1, pub_r001205_2_1, sec_r001205_0_2, sec_r001205_1_2, pub_r001205_2_2);
  int helper_flow_1_1 = fn_R001205_513_1(sec_r001205_1_1, sec_r001205_2_1, pub_r001205_3_1, pub_r001205_4_1);
  int helper_flow_1_2 = fn_R001205_513_1(sec_r001205_1_2, sec_r001205_2_2, pub_r001205_3_2, pub_r001205_4_2);
  fn_R001205_513_1_2(sec_r001205_1_1, sec_r001205_2_1, pub_r001205_3_1, pub_r001205_4_1, sec_r001205_1_2, sec_r001205_2_2, pub_r001205_3_2, pub_r001205_4_2);
  int helper_flow_2_1 = fn_R001205_513_2(sec_r001205_2_1, pub_r001205_3_1, pub_r001205_4_1, pub_r001205_5_1, pub_r001205_6_1);
  int helper_flow_2_2 = fn_R001205_513_2(sec_r001205_2_2, pub_r001205_3_2, pub_r001205_4_2, pub_r001205_5_2, pub_r001205_6_2);
  fn_R001205_513_2_2(sec_r001205_2_1, pub_r001205_3_1, pub_r001205_4_1, pub_r001205_5_1, pub_r001205_6_1, sec_r001205_2_2, pub_r001205_3_2, pub_r001205_4_2, pub_r001205_5_2, pub_r001205_6_2);
  int helper_flow_3_1 = fn_R001205_513_3(sec_r001205_3_1, pub_r001205_4_1);
  int helper_flow_3_2 = fn_R001205_513_3(sec_r001205_3_2, pub_r001205_4_2);
  fn_R001205_513_3_2(sec_r001205_3_1, pub_r001205_4_1, sec_r001205_3_2, pub_r001205_4_2);
  int helper_flow_4_1 = fn_R001205_513_4(sec_r001205_4_1, pub_r001205_5_1);
  int helper_flow_4_2 = fn_R001205_513_4(sec_r001205_4_2, pub_r001205_5_2);
  fn_R001205_513_4_2(sec_r001205_4_1, pub_r001205_5_1, sec_r001205_4_2, pub_r001205_5_2);
  int helper_flow_5_1 = fn_R001205_513_5(sec_r001205_5_1, sec_r001205_6_1);
  int helper_flow_5_2 = fn_R001205_513_5(sec_r001205_5_2, sec_r001205_6_2);
  fn_R001205_513_5_2(sec_r001205_5_1, sec_r001205_6_1, sec_r001205_5_2, sec_r001205_6_2);
  int helper_flow_6_1 = fn_R001205_513_6(sec_r001205_6_1, sec_r001205_7_1);
  int helper_flow_6_2 = fn_R001205_513_6(sec_r001205_6_2, sec_r001205_7_2);
  fn_R001205_513_6_2(sec_r001205_6_1, sec_r001205_7_1, sec_r001205_6_2, sec_r001205_7_2);
  int helper_flow_7_1 = fn_R001205_513_7(sec_r001205_7_1, sec_r001205_8_1, pub_r001205_9_1, pub_r001205_10_1);
  int helper_flow_7_2 = fn_R001205_513_7(sec_r001205_7_2, sec_r001205_8_2, pub_r001205_9_2, pub_r001205_10_2);
  fn_R001205_513_7_2(sec_r001205_7_1, sec_r001205_8_1, pub_r001205_9_1, pub_r001205_10_1, sec_r001205_7_2, sec_r001205_8_2, pub_r001205_9_2, pub_r001205_10_2);
  int helper_flow_8_1 = fn_R001205_513_8(sec_r001205_8_1, pub_r001205_9_1, pub_r001205_10_1, pub_r001205_11_1);
  int helper_flow_8_2 = fn_R001205_513_8(sec_r001205_8_2, pub_r001205_9_2, pub_r001205_10_2, pub_r001205_11_2);
  fn_R001205_513_8_2(sec_r001205_8_1, pub_r001205_9_1, pub_r001205_10_1, pub_r001205_11_1, sec_r001205_8_2, pub_r001205_9_2, pub_r001205_10_2, pub_r001205_11_2);
  int stage_v_0_1 = ((pub_r001205_13_1 * 2) + 44) & 63;
  int stage_v_0_2 = ((pub_r001205_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001205_5_1 * 2) + 19) & 63;
  int stage_v_1_2 = ((pub_r001205_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001205_6_1 * 2) + 36) & 63;
  int stage_v_2_2 = ((pub_r001205_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001205_10_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001205_10_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((sec_r001205_14_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001205_14_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((sec_r001205_1_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_5_2 = ((sec_r001205_1_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((sec_r001205_13_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001205_13_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001205_13_1 * 2) + 26) & 63;
  int stage_v_7_2 = ((pub_r001205_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_8_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001205_0_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001205_0_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((sec_r001205_16_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001205_16_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((pub_r001205_14_1 * 2) + 27) & 63;
  int stage_v_11_2 = ((pub_r001205_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001205_3_1 * 2) + 28) & 63;
  int stage_v_12_2 = ((pub_r001205_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001205_0_1 * 2) + 12) & 63;
  int stage_v_13_2 = ((pub_r001205_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001205_0_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001205_0_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((pub_r001205_8_1 * 2) + 15) & 63;
  int stage_v_15_2 = ((pub_r001205_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001205_9_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_16_2 = ((sec_r001205_9_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_17_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((pub_r001205_10_1 * 2) + 42) & 63;
  int stage_v_18_2 = ((pub_r001205_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001205_14_1 * 2) + 43) & 63;
  int stage_v_19_2 = ((pub_r001205_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_5_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_5_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((stage_v_20_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_21_2 = ((stage_v_20_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_22_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((sec_r001205_11_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_23_2 = ((sec_r001205_11_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((sec_r001205_17_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001205_17_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((sec_r001205_1_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001205_1_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((sec_r001205_5_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_26_2 = ((sec_r001205_5_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((pub_r001205_15_1 * 2) + 40) & 63;
  int stage_v_27_2 = ((pub_r001205_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001205_8_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001205_8_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((sec_r001205_17_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_29_2 = ((sec_r001205_17_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((sec_r001205_6_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_30_2 = ((sec_r001205_6_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((pub_r001205_6_1 * 2) + 10) & 63;
  int stage_v_31_2 = ((pub_r001205_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001205_9_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001205_9_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((pub_r001205_7_1 * 2) + 26) & 63;
  int stage_v_33_2 = ((pub_r001205_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001205_14_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001205_14_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001205_3_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001205_3_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((stage_v_26_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_26_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001205_0_1 * 2) + 13) & 63;
  int stage_v_37_2 = ((pub_r001205_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_3_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_38_2 = ((stage_v_3_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_14_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_14_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((sec_r001205_3_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_40_2 = ((sec_r001205_3_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((pub_r001205_14_1 * 2) + 19) & 63;
  int stage_v_41_2 = ((pub_r001205_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_39_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_39_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_25_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_25_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_29_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_29_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001205_13_1 * 2) + 37) & 63;
  int stage_v_45_2 = ((pub_r001205_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001205_12_1 * 2) + 7) & 63;
  int stage_v_46_2 = ((pub_r001205_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001205_15_1 * 2) + 18) & 63;
  int stage_v_47_2 = ((pub_r001205_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_48_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((sec_r001205_12_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001205_12_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001205_4_1 * 2) + 40) & 63;
  int stage_v_50_2 = ((pub_r001205_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((stage_v_5_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_51_2 = ((stage_v_5_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((pub_r001205_12_1 * 2) + 12) & 63;
  int stage_v_52_2 = ((pub_r001205_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001205_3_1 * 2) + 40) & 63;
  int stage_v_53_2 = ((pub_r001205_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001205_5_1 * 2) + 42) & 63;
  int stage_v_54_2 = ((pub_r001205_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_3_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_55_2 = ((helper_flow_3_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((stage_v_23_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_23_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((stage_v_10_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_10_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((pub_r001205_5_1 * 2) + 43) & 63;
  int stage_v_58_2 = ((pub_r001205_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_48_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_59_2 = ((stage_v_48_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((stage_v_14_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_60_2 = ((stage_v_14_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_61_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((pub_r001205_12_1 * 2) + 8) & 63;
  int stage_v_63_2 = ((pub_r001205_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001205_18_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_64_2 = ((sec_r001205_18_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((stage_v_5_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_5_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((stage_v_34_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_34_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((helper_flow_3_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_67_2 = ((helper_flow_3_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001205_12_1 * 2) + 40) & 63;
  int stage_v_68_2 = ((pub_r001205_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_62_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_62_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((stage_v_3_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_71_2 = ((stage_v_3_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((stage_v_59_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_59_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001205_0_1 * 2) + 36) & 63;
  int stage_v_73_2 = ((pub_r001205_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_57_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_74_2 = ((stage_v_57_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((pub_r001205_3_1 * 2) + 14) & 63;
  int stage_v_75_2 = ((pub_r001205_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((helper_flow_7_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_76_2 = ((helper_flow_7_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((pub_r001205_3_1 * 2) + 49) & 63;
  int stage_v_77_2 = ((pub_r001205_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001205_13_1 * 2) + 13) & 63;
  int stage_v_78_2 = ((pub_r001205_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001205_7_1 * 2) + 11) & 63;
  int stage_v_79_2 = ((pub_r001205_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((pub_r001205_2_1 * 2) + 49) & 63;
  int stage_v_81_2 = ((pub_r001205_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001205_5_1 * 2) + 20) & 63;
  int stage_v_82_2 = ((pub_r001205_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001205_11_1 * 2) + 39) & 63;
  int stage_v_83_2 = ((pub_r001205_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_20_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_20_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((stage_v_3_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_3_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((sec_r001205_14_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_86_2 = ((sec_r001205_14_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((sec_r001205_15_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_87_2 = ((sec_r001205_15_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((pub_r001205_7_1 * 2) + 34) & 63;
  int stage_v_88_2 = ((pub_r001205_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001205_8_1 * 2) + 10) & 63;
  int stage_v_89_2 = ((pub_r001205_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001205_4_1 * 2) + 28) & 63;
  int stage_v_90_2 = ((pub_r001205_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_66_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_91_2 = ((stage_v_66_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((stage_v_21_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_21_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((sec_r001205_17_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_93_2 = ((sec_r001205_17_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((pub_r001205_13_1 * 2) + 36) & 63;
  int stage_v_94_2 = ((pub_r001205_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001205_10_1 * 2) + 34) & 63;
  int stage_v_95_2 = ((pub_r001205_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001205_4_1 * 2) + 12) & 63;
  int stage_v_96_2 = ((pub_r001205_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_43_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_43_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((stage_v_55_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_55_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001205_13_1 * 2) + 14) & 63;
  int stage_v_99_2 = ((pub_r001205_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_84_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_84_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_101_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((sec_r001205_2_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_102_2 = ((sec_r001205_2_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((stage_v_26_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_26_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((pub_r001205_16_1 * 2) + 30) & 63;
  int stage_v_104_2 = ((pub_r001205_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_44_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_105_2 = ((stage_v_44_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((stage_v_51_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_106_2 = ((stage_v_51_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((pub_r001205_4_1 * 2) + 41) & 63;
  int stage_v_107_2 = ((pub_r001205_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001205_16_1 * 2) + 6) & 63;
  int stage_v_108_2 = ((pub_r001205_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001205_14_1 * 2) + 8) & 63;
  int stage_v_109_2 = ((pub_r001205_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((helper_flow_4_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_110_2 = ((helper_flow_4_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((pub_r001205_1_1 * 2) + 27) & 63;
  int stage_v_111_2 = ((pub_r001205_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((stage_v_5_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_112_2 = ((stage_v_5_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_32_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_32_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((pub_r001205_16_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001205_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((helper_flow_5_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_115_2 = ((helper_flow_5_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001205_1_1 * 2) + 43) & 63;
  int stage_v_116_2 = ((pub_r001205_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001205_2_1 * 2) + 38) & 63;
  int stage_v_117_2 = ((pub_r001205_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001205_8_1 * 2) + 20) & 63;
  int stage_v_118_2 = ((pub_r001205_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((helper_flow_7_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_119_2 = ((helper_flow_7_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001205_2_1 * 2) + 18) & 63;
  int stage_v_120_2 = ((pub_r001205_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_36_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_36_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((sec_r001205_19_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_122_2 = ((sec_r001205_19_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_98_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_98_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001205_6_1 * 2) + 7) & 63;
  int stage_v_124_2 = ((pub_r001205_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_69_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_69_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_91_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_91_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_127_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_115_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_115_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001205_9_1 * 2) + 10) & 63;
  int stage_v_129_2 = ((pub_r001205_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001205_0_1 * 2) + 21) & 63;
  int stage_v_130_2 = ((pub_r001205_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001205_1_1 * 2) + 7) & 63;
  int stage_v_131_2 = ((pub_r001205_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_72_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_72_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((pub_r001205_10_1 * 2) + 15) & 63;
  int stage_v_133_2 = ((pub_r001205_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_67_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_134_2 = ((stage_v_67_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((stage_v_72_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_135_2 = ((stage_v_72_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_23_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_23_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001205_9_1 * 2) + 19) & 63;
  int stage_v_137_2 = ((pub_r001205_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_43_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_43_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001205_12_1 * 2) + 50) & 63;
  int stage_v_139_2 = ((pub_r001205_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001205_10_1 * 2) + 23) & 63;
  int stage_v_140_2 = ((pub_r001205_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((helper_flow_2_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_141_2 = ((helper_flow_2_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((sec_r001205_10_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_142_2 = ((sec_r001205_10_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001205_6_1 * 2) + 48) & 63;
  int stage_v_143_2 = ((pub_r001205_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((sec_r001205_16_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_144_2 = ((sec_r001205_16_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_70_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_70_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((sec_r001205_15_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_146_2 = ((sec_r001205_15_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((helper_flow_0_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_147_2 = ((helper_flow_0_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001205_4_1 * 2) + 35) & 63;
  int stage_v_148_2 = ((pub_r001205_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001205_16_1 * 2) + 36) & 63;
  int stage_v_149_2 = ((pub_r001205_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001205_9_1 * 2) + 30) & 63;
  int stage_v_150_2 = ((pub_r001205_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001205_3_1 * 2) + 14) & 63;
  int stage_v_151_2 = ((pub_r001205_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001205_1_1 * 2) + 5) & 63;
  int stage_v_152_2 = ((pub_r001205_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001205_10_1 * 2) + 5) & 63;
  int stage_v_153_2 = ((pub_r001205_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001205_12_1 * 2) + 5) & 63;
  int stage_v_154_2 = ((pub_r001205_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001205_7_1 * 2) + 15) & 63;
  int stage_v_155_2 = ((pub_r001205_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001205_12_1 * 2) + 10) & 63;
  int stage_v_156_2 = ((pub_r001205_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001205_15_1 * 2) + 19) & 63;
  int stage_v_157_2 = ((pub_r001205_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_6_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_6_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_26_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_26_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_80_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_80_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((stage_v_126_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_126_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((pub_r001205_3_1 * 2) + 44) & 63;
  int stage_v_162_2 = ((pub_r001205_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_136_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_136_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((stage_v_98_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_98_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001205_7_1 * 2) + 40) & 63;
  int stage_v_165_2 = ((pub_r001205_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001205_1_1 * 2) + 43) & 63;
  int stage_v_166_2 = ((pub_r001205_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((sec_r001205_0_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_167_2 = ((sec_r001205_0_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((stage_v_43_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_43_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((pub_r001205_0_1 * 2) + 9) & 63;
  int stage_v_169_2 = ((pub_r001205_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001205_8_1 * 2) + 15) & 63;
  int stage_v_170_2 = ((pub_r001205_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001205_16_1 * 2) + 20) & 63;
  int stage_v_171_2 = ((pub_r001205_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001205_3_1 * 2) + 12) & 63;
  int stage_v_172_2 = ((pub_r001205_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_160_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_160_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((sec_r001205_8_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_174_2 = ((sec_r001205_8_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_24_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_24_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((stage_v_67_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_67_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001205_5_1 * 2) + 22) & 63;
  int stage_v_177_2 = ((pub_r001205_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_20_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_20_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((pub_r001205_16_1 * 2) + 34) & 63;
  int stage_v_179_2 = ((pub_r001205_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001205_10_1 * 2) + 43) & 63;
  int stage_v_180_2 = ((pub_r001205_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((helper_flow_3_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_181_2 = ((helper_flow_3_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((pub_r001205_5_1 * 2) + 36) & 63;
  int stage_v_182_2 = ((pub_r001205_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_71_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_71_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001205_15_1 * 2) + 8) & 63;
  int stage_v_184_2 = ((pub_r001205_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001205_0_1 * 2) + 14) & 63;
  int stage_v_185_2 = ((pub_r001205_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001205_14_1 * 2) + 7) & 63;
  int stage_v_186_2 = ((pub_r001205_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001205_12_1 * 2) + 40) & 63;
  int stage_v_187_2 = ((pub_r001205_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001205_16_1 * 2) + 49) & 63;
  int stage_v_188_2 = ((pub_r001205_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_24_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_189_2 = ((stage_v_24_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((sec_r001205_14_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_190_2 = ((sec_r001205_14_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_122_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_122_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((pub_r001205_6_1 * 2) + 50) & 63;
  int stage_v_192_2 = ((pub_r001205_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_20_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_20_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001205_6_1 * 2) + 21) & 63;
  int stage_v_194_2 = ((pub_r001205_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_122_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_122_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_66_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_66_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((pub_r001205_4_1 * 2) + 12) & 63;
  int stage_v_197_2 = ((pub_r001205_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((sec_r001205_18_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_198_2 = ((sec_r001205_18_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_98_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_98_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((pub_r001205_15_1 * 2) + 17) & 63;
  int stage_v_200_2 = ((pub_r001205_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((sec_r001205_8_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_201_2 = ((sec_r001205_8_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((pub_r001205_1_1 * 2) + 46) & 63;
  int stage_v_202_2 = ((pub_r001205_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_174_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_174_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((stage_v_35_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_35_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((pub_r001205_9_1 * 2) + 43) & 63;
  int stage_v_205_2 = ((pub_r001205_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001205_7_1 * 2) + 40) & 63;
  int stage_v_206_2 = ((pub_r001205_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001205_0_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_207_2 = ((sec_r001205_0_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((pub_r001205_14_1 * 2) + 18) & 63;
  int stage_v_208_2 = ((pub_r001205_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_203_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_203_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((sec_r001205_4_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_210_2 = ((sec_r001205_4_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((pub_r001205_11_1 * 2) + 48) & 63;
  int stage_v_211_2 = ((pub_r001205_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_198_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_198_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((sec_r001205_17_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_213_2 = ((sec_r001205_17_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_178_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_178_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((stage_v_121_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_215_2 = ((stage_v_121_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((sec_r001205_6_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_216_2 = ((sec_r001205_6_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001205_6_1 * 2) + 48) & 63;
  int stage_v_217_2 = ((pub_r001205_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001205_5_1 * 2) + 23) & 63;
  int stage_v_218_2 = ((pub_r001205_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001205_5_1 * 2) + 22) & 63;
  int stage_v_219_2 = ((pub_r001205_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_132_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_132_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((sec_r001205_3_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_221_2 = ((sec_r001205_3_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_61_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_61_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001205_6_1 * 2) + 16) & 63;
  int stage_v_223_2 = ((pub_r001205_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001205_8_1 * 2) + 28) & 63;
  int stage_v_224_2 = ((pub_r001205_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_42_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_42_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001205_2_1 * 2) + 50) & 63;
  int stage_v_226_2 = ((pub_r001205_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((sec_r001205_7_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_227_2 = ((sec_r001205_7_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_35_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_35_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((pub_r001205_11_1 * 2) + 39) & 63;
  int stage_v_229_2 = ((pub_r001205_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_92_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_92_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((pub_r001205_10_1 * 2) + 14) & 63;
  int stage_v_231_2 = ((pub_r001205_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001205_2_1 * 2) + 21) & 63;
  int stage_v_232_2 = ((pub_r001205_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_193_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_193_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((pub_r001205_4_1 * 2) + 7) & 63;
  int stage_v_234_2 = ((pub_r001205_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_84_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_84_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((pub_r001205_15_1 * 2) + 18) & 63;
  int stage_v_236_2 = ((pub_r001205_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001205_1_1 * 2) + 13) & 63;
  int stage_v_237_2 = ((pub_r001205_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001205_8_1 * 2) + 25) & 63;
  int stage_v_238_2 = ((pub_r001205_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_57_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_57_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_216_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_216_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((stage_v_106_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_106_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_242_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((pub_r001205_9_1 * 2) + 33) & 63;
  int stage_v_243_2 = ((pub_r001205_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001205_1_1 * 2) + 37) & 63;
  int stage_v_244_2 = ((pub_r001205_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((stage_v_74_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_245_2 = ((stage_v_74_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001205_7_1 * 2) + 50) & 63;
  int stage_v_246_2 = ((pub_r001205_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_195_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_195_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((stage_v_48_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_48_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_20_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_20_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001205_1_1 * 2) + 45) & 63;
  int stage_v_250_2 = ((pub_r001205_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001205_13_1 * 2) + 23) & 63;
  int stage_v_251_2 = ((pub_r001205_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001205_7_1 * 2) + 29) & 63;
  int stage_v_252_2 = ((pub_r001205_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_103_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_103_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((stage_v_72_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_72_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((stage_v_245_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_245_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_85_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_85_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_4_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_4_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((pub_r001205_4_1 * 2) + 33) & 63;
  int stage_v_258_2 = ((pub_r001205_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001205_15_1 * 2) + 30) & 63;
  int stage_v_259_2 = ((pub_r001205_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001205_15_1 * 2) + 50) & 63;
  int stage_v_260_2 = ((pub_r001205_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001205_14_1 * 2) + 41) & 63;
  int stage_v_261_2 = ((pub_r001205_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((stage_v_36_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_36_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((sec_r001205_11_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_263_2 = ((sec_r001205_11_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001205_2_1 * 2) + 21) & 63;
  int stage_v_264_2 = ((pub_r001205_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((stage_v_69_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_69_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_127_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_127_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((pub_r001205_15_1 * 2) + 21) & 63;
  int stage_v_267_2 = ((pub_r001205_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001205_10_1 * 2) + 49) & 63;
  int stage_v_268_2 = ((pub_r001205_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_181_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_181_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_145_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_145_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001205_7_1 * 2) + 27) & 63;
  int stage_v_271_2 = ((pub_r001205_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001205_2_1 * 2) + 45) & 63;
  int stage_v_272_2 = ((pub_r001205_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001205_11_1 * 2) + 25) & 63;
  int stage_v_273_2 = ((pub_r001205_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001205_7_1 * 2) + 25) & 63;
  int stage_v_274_2 = ((pub_r001205_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((stage_v_32_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_32_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_191_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_191_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((pub_r001205_2_1 * 2) + 28) & 63;
  int stage_v_277_2 = ((pub_r001205_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001205_5_1 * 2) + 39) & 63;
  int stage_v_278_2 = ((pub_r001205_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((stage_v_215_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_215_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((pub_r001205_1_1 * 2) + 48) & 63;
  int stage_v_280_2 = ((pub_r001205_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((stage_v_40_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_40_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((pub_r001205_12_1 * 2) + 11) & 63;
  int stage_v_282_2 = ((pub_r001205_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((stage_v_263_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_263_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((pub_r001205_6_1 * 2) + 31) & 63;
  int stage_v_284_2 = ((pub_r001205_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((stage_v_195_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_195_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((pub_r001205_11_1 * 2) + 19) & 63;
  int stage_v_286_2 = ((pub_r001205_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_59_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_59_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001205_16_1 * 2) + 6) & 63;
  int stage_v_288_2 = ((pub_r001205_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001205_10_1 * 2) + 10) & 63;
  int stage_v_289_2 = ((pub_r001205_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((helper_flow_5_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_290_2 = ((helper_flow_5_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001205_8_1 * 2) + 12) & 63;
  int stage_v_291_2 = ((pub_r001205_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((stage_v_115_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_115_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((stage_v_21_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_21_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((pub_r001205_4_1 * 2) + 13) & 63;
  int stage_v_294_2 = ((pub_r001205_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001205_5_1 * 2) + 8) & 63;
  int stage_v_295_2 = ((pub_r001205_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001205_14_1 * 2) + 11) & 63;
  int stage_v_296_2 = ((pub_r001205_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001205_0_1 * 2) + 8) & 63;
  int stage_v_297_2 = ((pub_r001205_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001205_5_1 * 2) + 15) & 63;
  int stage_v_298_2 = ((pub_r001205_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001205_0_1 * 2) + 27) & 63;
  int stage_v_299_2 = ((pub_r001205_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((stage_v_87_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_87_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001205_6_1 * 2) + 42) & 63;
  int stage_v_301_2 = ((pub_r001205_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001205_9_1 * 2) + 46) & 63;
  int stage_v_302_2 = ((pub_r001205_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001205_2_1 * 2) + 15) & 63;
  int stage_v_303_2 = ((pub_r001205_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001205_3_1 * 2) + 41) & 63;
  int stage_v_304_2 = ((pub_r001205_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((stage_v_290_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_290_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((stage_v_80_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_80_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((sec_r001205_2_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_307_2 = ((sec_r001205_2_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((pub_r001205_2_1 * 2) + 32) & 63;
  int stage_v_308_2 = ((pub_r001205_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((stage_v_175_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_175_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_230_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_230_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((helper_flow_7_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_311_2 = ((helper_flow_7_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_142_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_142_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((pub_r001205_9_1 * 2) + 22) & 63;
  int stage_v_313_2 = ((pub_r001205_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001205_16_1 * 2) + 40) & 63;
  int stage_v_314_2 = ((pub_r001205_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((stage_v_36_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_36_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((pub_r001205_6_1 * 2) + 24) & 63;
  int stage_v_316_2 = ((pub_r001205_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001205_13_1 * 2) + 35) & 63;
  int stage_v_317_2 = ((pub_r001205_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001205_13_1 * 2) + 9) & 63;
  int stage_v_318_2 = ((pub_r001205_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((helper_flow_4_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_319_2 = ((helper_flow_4_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((pub_r001205_11_1 * 2) + 21) & 63;
  int stage_v_320_2 = ((pub_r001205_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((stage_v_101_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_101_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((pub_r001205_9_1 * 2) + 32) & 63;
  int stage_v_322_2 = ((pub_r001205_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((stage_v_36_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_36_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((stage_v_312_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_312_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_163_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_163_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001205_12_1 * 2) + 8) & 63;
  int stage_v_326_2 = ((pub_r001205_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001205_9_1 * 2) + 31) & 63;
  int stage_v_327_2 = ((pub_r001205_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001205_1_1 * 2) + 16) & 63;
  int stage_v_328_2 = ((pub_r001205_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001205_0_1 * 2) + 27) & 63;
  int stage_v_329_2 = ((pub_r001205_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001205_10_1 * 2) + 18) & 63;
  int stage_v_330_2 = ((pub_r001205_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((stage_v_254_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_254_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_195_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_195_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((stage_v_199_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_199_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((pub_r001205_14_1 * 2) + 41) & 63;
  int stage_v_334_2 = ((pub_r001205_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((sec_r001205_9_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_335_2 = ((sec_r001205_9_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((sec_r001205_9_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_336_2 = ((sec_r001205_9_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001205_15_1 * 2) + 23) & 63;
  int stage_v_337_2 = ((pub_r001205_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_134_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_134_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001205_13_1 * 2) + 10) & 63;
  int stage_v_339_2 = ((pub_r001205_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001205_3_1 * 2) + 32) & 63;
  int stage_v_340_2 = ((pub_r001205_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001205_16_1 * 2) + 5) & 63;
  int stage_v_341_2 = ((pub_r001205_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001205_4_1 * 2) + 19) & 63;
  int stage_v_342_2 = ((pub_r001205_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001205_13_1 * 2) + 50) & 63;
  int stage_v_343_2 = ((pub_r001205_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((stage_v_241_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_241_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_72_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_72_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((pub_r001205_12_1 * 2) + 32) & 63;
  int stage_v_346_2 = ((pub_r001205_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((stage_v_93_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_93_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((stage_v_91_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_91_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((stage_v_103_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_103_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((sec_r001205_6_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_350_2 = ((sec_r001205_6_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001205_4_1 * 2) + 30) & 63;
  int stage_v_351_2 = ((pub_r001205_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((stage_v_332_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_332_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_305_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_305_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((sec_r001205_4_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_354_2 = ((sec_r001205_4_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((pub_r001205_0_1 * 2) + 46) & 63;
  int stage_v_355_2 = ((pub_r001205_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001205_1_1 * 2) + 15) & 63;
  int stage_v_356_2 = ((pub_r001205_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001205_1_1 * 2) + 26) & 63;
  int stage_v_357_2 = ((pub_r001205_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((stage_v_333_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_333_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((stage_v_249_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_249_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((pub_r001205_12_1 * 2) + 17) & 63;
  int stage_v_360_2 = ((pub_r001205_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001205_7_1 * 2) + 21) & 63;
  int stage_v_361_2 = ((pub_r001205_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001205_11_1 * 2) + 22) & 63;
  int stage_v_362_2 = ((pub_r001205_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((stage_v_254_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_254_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_97_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_97_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_312_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_312_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_147_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_147_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((stage_v_10_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_10_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((stage_v_239_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_239_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001205_11_1 * 2) + 23) & 63;
  int stage_v_369_2 = ((pub_r001205_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_67_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_67_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_365_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_365_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((stage_v_16_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_16_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001205_10_1 * 2) + 16) & 63;
  int stage_v_373_2 = ((pub_r001205_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001205_1_1 * 2) + 13) & 63;
  int stage_v_374_2 = ((pub_r001205_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((sec_r001205_15_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_375_2 = ((sec_r001205_15_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((stage_v_195_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_195_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((pub_r001205_12_1 * 2) + 46) & 63;
  int stage_v_377_2 = ((pub_r001205_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_21_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_21_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((pub_r001205_10_1 * 2) + 27) & 63;
  int stage_v_379_2 = ((pub_r001205_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((stage_v_161_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_161_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_196_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_196_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_305_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_305_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((pub_r001205_8_1 * 2) + 18) & 63;
  int stage_v_383_2 = ((pub_r001205_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((stage_v_55_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_55_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((stage_v_263_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_263_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_253_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_253_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((stage_v_285_1 << 1) ^ (pub_r001205_4_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_285_2 << 1) ^ (pub_r001205_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001205_8_1 * 2) + 46) & 63;
  int stage_v_388_2 = ((pub_r001205_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001205_14_1 * 2) + 14) & 63;
  int stage_v_389_2 = ((pub_r001205_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((stage_v_312_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_390_2 = ((stage_v_312_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_390_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_390_2 + 1) & 15;
  out_sink_1 ^= stage_v_390_1 & 63;
  out_sink_2 ^= stage_v_390_2 & 63;
  int stage_v_391_1 = ((stage_v_26_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_26_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_213_1 << 1) ^ (pub_r001205_11_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_213_2 << 1) ^ (pub_r001205_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((sec_r001205_11_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_393_2 = ((sec_r001205_11_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((pub_r001205_8_1 * 2) + 30) & 63;
  int stage_v_394_2 = ((pub_r001205_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((stage_v_225_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_395_2 = ((stage_v_225_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_395_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_395_2 + 1) & 15;
  out_sink_1 ^= stage_v_395_1 & 63;
  out_sink_2 ^= stage_v_395_2 & 63;
  int stage_v_396_1 = ((stage_v_101_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_101_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001205_3_1 * 2) + 12) & 63;
  int stage_v_397_2 = ((pub_r001205_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((stage_v_385_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_385_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((stage_v_381_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_381_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((stage_v_306_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_306_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((stage_v_39_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_39_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_210_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_210_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((pub_r001205_0_1 * 2) + 30) & 63;
  int stage_v_403_2 = ((pub_r001205_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001205_14_1 * 2) + 25) & 63;
  int stage_v_404_2 = ((pub_r001205_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((stage_v_30_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_405_2 = ((stage_v_30_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_405_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_405_2 + 1) & 15;
  out_sink_1 ^= stage_v_405_1 & 63;
  out_sink_2 ^= stage_v_405_2 & 63;
  int stage_v_406_1 = ((pub_r001205_9_1 * 2) + 17) & 63;
  int stage_v_406_2 = ((pub_r001205_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((stage_v_228_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_228_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((pub_r001205_2_1 * 2) + 21) & 63;
  int stage_v_408_2 = ((pub_r001205_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((stage_v_376_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_376_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((stage_v_380_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_380_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((pub_r001205_7_1 * 2) + 14) & 63;
  int stage_v_411_2 = ((pub_r001205_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_395_1 << 1) ^ (pub_r001205_15_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_395_2 << 1) ^ (pub_r001205_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((pub_r001205_2_1 * 2) + 43) & 63;
  int stage_v_413_2 = ((pub_r001205_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001205_3_1 * 2) + 45) & 63;
  int stage_v_414_2 = ((pub_r001205_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((stage_v_275_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_275_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_416_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001205_14_1 * 2) + 12) & 63;
  int stage_v_417_2 = ((pub_r001205_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((stage_v_262_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_262_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((pub_r001205_6_1 * 2) + 37) & 63;
  int stage_v_419_2 = ((pub_r001205_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001205_3_1 * 2) + 5) & 63;
  int stage_v_420_2 = ((pub_r001205_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((stage_v_135_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_135_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((stage_v_292_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_292_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((pub_r001205_3_1 * 2) + 29) & 63;
  int stage_v_423_2 = ((pub_r001205_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001205_9_1 * 2) + 13) & 63;
  int stage_v_424_2 = ((pub_r001205_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001205_15_1 * 2) + 28) & 63;
  int stage_v_425_2 = ((pub_r001205_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((stage_v_216_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_216_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((pub_r001205_8_1 * 2) + 31) & 63;
  int stage_v_427_2 = ((pub_r001205_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001205_16_1 * 2) + 6) & 63;
  int stage_v_428_2 = ((pub_r001205_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((stage_v_70_1 << 1) ^ (pub_r001205_16_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_70_2 << 1) ^ (pub_r001205_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_92_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_92_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((pub_r001205_15_1 * 2) + 35) & 63;
  int stage_v_431_2 = ((pub_r001205_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001205_13_1 * 2) + 11) & 63;
  int stage_v_432_2 = ((pub_r001205_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((sec_r001205_6_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_433_2 = ((sec_r001205_6_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_433_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_433_2 + 1) & 15;
  out_sink_1 ^= stage_v_433_1 & 63;
  out_sink_2 ^= stage_v_433_2 & 63;
  int stage_v_434_1 = ((pub_r001205_14_1 * 2) + 18) & 63;
  int stage_v_434_2 = ((pub_r001205_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001205_15_1 * 2) + 35) & 63;
  int stage_v_435_2 = ((pub_r001205_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001205_1_1 * 2) + 5) & 63;
  int stage_v_436_2 = ((pub_r001205_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((stage_v_144_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_144_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((stage_v_276_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_438_2 = ((stage_v_276_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_438_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_438_2 + 1) & 15;
  out_sink_1 ^= stage_v_438_1 & 63;
  out_sink_2 ^= stage_v_438_2 & 63;
  int stage_v_439_1 = ((helper_flow_6_1 << 1) ^ (pub_r001205_1_1 >> 1)) & 127;
  int stage_v_439_2 = ((helper_flow_6_2 << 1) ^ (pub_r001205_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((stage_v_300_1 << 1) ^ (pub_r001205_10_1 >> 1)) & 127;
  int stage_v_440_2 = ((stage_v_300_2 << 1) ^ (pub_r001205_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_440_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_440_2 + 1) & 15;
  out_sink_1 ^= stage_v_440_1 & 63;
  out_sink_2 ^= stage_v_440_2 & 63;
  int stage_v_441_1 = ((pub_r001205_16_1 * 2) + 24) & 63;
  int stage_v_441_2 = ((pub_r001205_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001205_9_1 * 2) + 29) & 63;
  int stage_v_442_2 = ((pub_r001205_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((stage_v_391_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_443_2 = ((stage_v_391_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_443_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_443_2 + 1) & 15;
  out_sink_1 ^= stage_v_443_1 & 63;
  out_sink_2 ^= stage_v_443_2 & 63;
  int stage_v_444_1 = ((pub_r001205_4_1 * 2) + 8) & 63;
  int stage_v_444_2 = ((pub_r001205_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001205_14_1 * 2) + 8) & 63;
  int stage_v_445_2 = ((pub_r001205_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((stage_v_174_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_446_2 = ((stage_v_174_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_446_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_446_2 + 1) & 15;
  out_sink_1 ^= stage_v_446_1 & 63;
  out_sink_2 ^= stage_v_446_2 & 63;
  int stage_v_447_1 = ((stage_v_285_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_447_2 = ((stage_v_285_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_447_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_447_2 + 1) & 15;
  out_sink_1 ^= stage_v_447_1 & 63;
  out_sink_2 ^= stage_v_447_2 & 63;
  int stage_v_448_1 = ((pub_r001205_8_1 * 2) + 36) & 63;
  int stage_v_448_2 = ((pub_r001205_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001205_15_1 * 2) + 26) & 63;
  int stage_v_449_2 = ((pub_r001205_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001205_11_1 * 2) + 11) & 63;
  int stage_v_450_2 = ((pub_r001205_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((stage_v_353_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_451_2 = ((stage_v_353_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_451_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_451_2 + 1) & 15;
  out_sink_1 ^= stage_v_451_1 & 63;
  out_sink_2 ^= stage_v_451_2 & 63;
  int stage_v_452_1 = ((pub_r001205_13_1 * 2) + 29) & 63;
  int stage_v_452_2 = ((pub_r001205_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001205_5_1 * 2) + 30) & 63;
  int stage_v_453_2 = ((pub_r001205_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((stage_v_189_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_454_2 = ((stage_v_189_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_454_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_454_2 + 1) & 15;
  out_sink_1 ^= stage_v_454_1 & 63;
  out_sink_2 ^= stage_v_454_2 & 63;
  int stage_v_455_1 = ((stage_v_421_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_455_2 = ((stage_v_421_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_455_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_455_2 + 1) & 15;
  out_sink_1 ^= stage_v_455_1 & 63;
  out_sink_2 ^= stage_v_455_2 & 63;
  int stage_v_456_1 = ((stage_v_365_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_456_2 = ((stage_v_365_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_456_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_456_2 + 1) & 15;
  out_sink_1 ^= stage_v_456_1 & 63;
  out_sink_2 ^= stage_v_456_2 & 63;
  int stage_v_457_1 = ((stage_v_65_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_457_2 = ((stage_v_65_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_457_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_457_2 + 1) & 15;
  out_sink_1 ^= stage_v_457_1 & 63;
  out_sink_2 ^= stage_v_457_2 & 63;
  int stage_v_458_1 = ((stage_v_307_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_458_2 = ((stage_v_307_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_458_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_458_2 + 1) & 15;
  out_sink_1 ^= stage_v_458_1 & 63;
  out_sink_2 ^= stage_v_458_2 & 63;
  int stage_v_459_1 = ((helper_flow_1_1 << 1) ^ (pub_r001205_6_1 >> 1)) & 127;
  int stage_v_459_2 = ((helper_flow_1_2 << 1) ^ (pub_r001205_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_459_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_459_2 + 1) & 15;
  out_sink_1 ^= stage_v_459_1 & 63;
  out_sink_2 ^= stage_v_459_2 & 63;
  int stage_v_460_1 = ((stage_v_255_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_460_2 = ((stage_v_255_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_460_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_460_2 + 1) & 15;
  out_sink_1 ^= stage_v_460_1 & 63;
  out_sink_2 ^= stage_v_460_2 & 63;
  int stage_v_461_1 = ((pub_r001205_11_1 * 2) + 50) & 63;
  int stage_v_461_2 = ((pub_r001205_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((stage_v_40_1 << 1) ^ (pub_r001205_8_1 >> 1)) & 127;
  int stage_v_462_2 = ((stage_v_40_2 << 1) ^ (pub_r001205_8_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_462_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_462_2 + 1) & 15;
  out_sink_1 ^= stage_v_462_1 & 63;
  out_sink_2 ^= stage_v_462_2 & 63;
  int stage_v_463_1 = ((stage_v_352_1 << 1) ^ (pub_r001205_5_1 >> 1)) & 127;
  int stage_v_463_2 = ((stage_v_352_2 << 1) ^ (pub_r001205_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_463_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_463_2 + 1) & 15;
  out_sink_1 ^= stage_v_463_1 & 63;
  out_sink_2 ^= stage_v_463_2 & 63;
  int stage_v_464_1 = ((sec_r001205_18_1 << 1) ^ (pub_r001205_12_1 >> 1)) & 127;
  int stage_v_464_2 = ((sec_r001205_18_2 << 1) ^ (pub_r001205_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_464_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_464_2 + 1) & 15;
  out_sink_1 ^= stage_v_464_1 & 63;
  out_sink_2 ^= stage_v_464_2 & 63;
  int stage_v_465_1 = ((pub_r001205_12_1 * 2) + 42) & 63;
  int stage_v_465_2 = ((pub_r001205_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001205_9_1 * 2) + 38) & 63;
  int stage_v_466_2 = ((pub_r001205_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((stage_v_333_1 << 1) ^ (pub_r001205_3_1 >> 1)) & 127;
  int stage_v_467_2 = ((stage_v_333_2 << 1) ^ (pub_r001205_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_467_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_467_2 + 1) & 15;
  out_sink_1 ^= stage_v_467_1 & 63;
  out_sink_2 ^= stage_v_467_2 & 63;
  int stage_v_468_1 = ((stage_v_40_1 << 1) ^ (pub_r001205_13_1 >> 1)) & 127;
  int stage_v_468_2 = ((stage_v_40_2 << 1) ^ (pub_r001205_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_468_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_468_2 + 1) & 15;
  out_sink_1 ^= stage_v_468_1 & 63;
  out_sink_2 ^= stage_v_468_2 & 63;
  int stage_v_469_1 = ((stage_v_49_1 << 1) ^ (pub_r001205_2_1 >> 1)) & 127;
  int stage_v_469_2 = ((stage_v_49_2 << 1) ^ (pub_r001205_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_469_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_469_2 + 1) & 15;
  out_sink_1 ^= stage_v_469_1 & 63;
  out_sink_2 ^= stage_v_469_2 & 63;
  int stage_v_470_1 = ((stage_v_287_1 << 1) ^ (pub_r001205_0_1 >> 1)) & 127;
  int stage_v_470_2 = ((stage_v_287_2 << 1) ^ (pub_r001205_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_470_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_470_2 + 1) & 15;
  out_sink_1 ^= stage_v_470_1 & 63;
  out_sink_2 ^= stage_v_470_2 & 63;
  int stage_v_471_1 = ((sec_r001205_16_1 << 1) ^ (pub_r001205_9_1 >> 1)) & 127;
  int stage_v_471_2 = ((sec_r001205_16_2 << 1) ^ (pub_r001205_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_471_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_471_2 + 1) & 15;
  out_sink_1 ^= stage_v_471_1 & 63;
  out_sink_2 ^= stage_v_471_2 & 63;
  int stage_v_472_1 = ((stage_v_196_1 << 1) ^ (pub_r001205_14_1 >> 1)) & 127;
  int stage_v_472_2 = ((stage_v_196_2 << 1) ^ (pub_r001205_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_472_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_472_2 + 1) & 15;
  out_sink_1 ^= stage_v_472_1 & 63;
  out_sink_2 ^= stage_v_472_2 & 63;
  int stage_v_473_1 = ((helper_flow_8_1 << 1) ^ (pub_r001205_7_1 >> 1)) & 127;
  int stage_v_473_2 = ((helper_flow_8_2 << 1) ^ (pub_r001205_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_473_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_473_2 + 1) & 15;
  out_sink_1 ^= stage_v_473_1 & 63;
  out_sink_2 ^= stage_v_473_2 & 63;
  int stage_v_474_1 = ((pub_r001205_15_1 * 2) + 27) & 63;
  int stage_v_474_2 = ((pub_r001205_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001205_0_1 != sec_r001205_0_2);
  __CPROVER_assume(pub_r001205_3_1 == pub_r001205_3_2);
  __CPROVER_assume(pub_r001205_9_1 == pub_r001205_9_2);
  __CPROVER_assume(sec_r001205_19_1 != sec_r001205_19_2);
  __CPROVER_assume(pub_r001205_13_1 == pub_r001205_13_2);
  __CPROVER_assume(sec_r001205_4_1 != sec_r001205_4_2);
  __CPROVER_assume(pub_r001205_15_1 == pub_r001205_15_2);
  __CPROVER_assume(sec_r001205_7_1 != sec_r001205_7_2);
  __CPROVER_assume(pub_r001205_14_1 == pub_r001205_14_2);
  __CPROVER_assume(sec_r001205_2_1 != sec_r001205_2_2);
  __CPROVER_assume(sec_r001205_13_1 != sec_r001205_13_2);
  __CPROVER_assume(sec_r001205_18_1 != sec_r001205_18_2);
  __CPROVER_assume(pub_r001205_16_1 == pub_r001205_16_2);
  __CPROVER_assume(pub_r001205_0_1 == pub_r001205_0_2);
  __CPROVER_assume(pub_r001205_1_1 == pub_r001205_1_2);
  __CPROVER_assume(sec_r001205_10_1 != sec_r001205_10_2);
  __CPROVER_assume(sec_r001205_17_1 != sec_r001205_17_2);
  __CPROVER_assume(pub_r001205_2_1 == pub_r001205_2_2);
  __CPROVER_assume(pub_r001205_10_1 == pub_r001205_10_2);
  __CPROVER_assume(sec_r001205_16_1 != sec_r001205_16_2);
  __CPROVER_assume(pub_r001205_7_1 == pub_r001205_7_2);
  __CPROVER_assume(sec_r001205_15_1 != sec_r001205_15_2);
  __CPROVER_assume(sec_r001205_8_1 != sec_r001205_8_2);
  __CPROVER_assume(sec_r001205_3_1 != sec_r001205_3_2);
  __CPROVER_assume(pub_r001205_12_1 == pub_r001205_12_2);
  __CPROVER_assume(sec_r001205_6_1 != sec_r001205_6_2);
  __CPROVER_assume(sec_r001205_9_1 != sec_r001205_9_2);
  __CPROVER_assume(pub_r001205_5_1 == pub_r001205_5_2);
  __CPROVER_assume(pub_r001205_11_1 == pub_r001205_11_2);
  __CPROVER_assume(sec_r001205_5_1 != sec_r001205_5_2);
  __CPROVER_assume(pub_r001205_8_1 == pub_r001205_8_2);
  __CPROVER_assume(sec_r001205_14_1 != sec_r001205_14_2);
  __CPROVER_assume(pub_r001205_6_1 == pub_r001205_6_2);
  __CPROVER_assume(sec_r001205_12_1 != sec_r001205_12_2);
  __CPROVER_assume(pub_r001205_4_1 == pub_r001205_4_2);
  __CPROVER_assume(sec_r001205_11_1 != sec_r001205_11_2);
  __CPROVER_assume(sec_r001205_1_1 != sec_r001205_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.density == st_var_2_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.damping == st_var_3_2.damping);
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
}


