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
struct FilterState_R001535_3513_0
{
  short mode;
  unsigned char gain_db;
  int prev_in;
  unsigned char damping;
  short prev_out;
  int buffer[3];
};
struct MatrixBlock_R001535_3513_1
{
  unsigned char dim;
  int determinant;
  unsigned char stride;
  int scale;
  short density;
  int buffer[3];
};
struct Vector3D_R001535_3513_2
{
  short pitch;
  int coord_z;
  int coord_y;
  int heading;
  int norm_sq;
  short coord_x;
  int buffer[3];
};
union TelemetryField_R001535_3513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001535_3513_1
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
void fn_R001535_3513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_81_1 = local_arr_1[aux_1 % 3];
  int damping_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_81_2 * 2)) & 127;
  int anchor_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_19_1) & 63;
  aux_2 = (aux_2 + anchor_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_56_1)
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

  switch (sample_56_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_81_1 == damping_81_2);
  assert(anchor_19_1 == anchor_19_2);
  assert(sample_56_1 == sample_56_2);
}

int fn_R001535_3513_0(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int damping_81 = local_arr[aux % 3];
  acc = (acc + (damping_81 * 2)) & 127;
  int anchor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_19) & 63;
  acc ^= aux;
  int sample_56 = (aux + st.buffer[1]) & 3;
  switch (sample_56)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tally_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_23_1 > 31)
  {
    acc_1 = ((acc_1 + (tally_23_1 * 2)) + 5) & 127;
    aux_1 ^= tally_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_23_2 > 31)
  {
    acc_2 = ((acc_2 + (tally_23_2 * 2)) + 5) & 127;
    aux_2 ^= tally_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_23_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_23_1 == tally_23_2);
}

int fn_R001535_3513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tally_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_23 > 31)
  {
    acc = ((acc + (tally_23 * 2)) + 5) & 127;
    aux ^= tally_23 & 15;
  }
  else
  {
    acc = ((acc - tally_23) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_49_1 = 0;
  int phase_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_49_1 = ((phase_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_49_2 = ((phase_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_49_1) & 127;
    acc_2 = (acc_2 + phase_49_2) & 127;
  }

  int parity_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_80_1)
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

  switch (parity_80_2)
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

  int stride_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_20_1 > 37)
  {
    acc_1 = ((acc_1 + (stride_20_1 * 2)) + 5) & 127;
    aux_1 ^= stride_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_20_2 > 37)
  {
    acc_2 = ((acc_2 + (stride_20_2 * 2)) + 5) & 127;
    aux_2 ^= stride_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_49_1 == phase_49_2);
  assert(parity_80_1 == parity_80_2);
  assert(stride_20_1 == stride_20_2);
}

int fn_R001535_3513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_49 = ((phase_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_49) & 127;
  }

  int parity_80 = (aux + st.buffer[1]) & 3;
  switch (parity_80)
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

  int stride_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_20 > 37)
  {
    acc = ((acc + (stride_20 * 2)) + 5) & 127;
    aux ^= stride_20 & 15;
  }
  else
  {
    acc = ((acc - stride_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001535_3513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int offset_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_35_1) & 63;
  aux_2 = (aux_2 + offset_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_67_1 = 0;
  int quantum_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_67_1 = ((quantum_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_67_2 = ((quantum_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_67_1) & 127;
    acc_2 = (acc_2 + quantum_67_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_25_1 = local_arr_1[aux_1 % 3];
  int checksum_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_35_1 == offset_35_2);
  assert(quantum_67_1 == quantum_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_25_1 == checksum_25_2);
}

int fn_R001535_3513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int offset_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_35) & 63;
  acc ^= aux;
  int quantum_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_67 = ((quantum_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_67) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_25 = local_arr[aux % 3];
  acc = (acc + (checksum_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
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
  int quantum_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_24_1)
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

  switch (quantum_24_2)
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

  int tracker_34_1 = 0;
  int tracker_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_34_1 = ((tracker_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_34_2 = ((tracker_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_34_1) & 127;
    acc_2 = (acc_2 + tracker_34_2) & 127;
  }

  int phase_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_68_1) & 63;
  aux_2 = (aux_2 + phase_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_24_1 == quantum_24_2);
  assert(tracker_34_1 == tracker_34_2);
  assert(phase_68_1 == phase_68_2);
}

int fn_R001535_3513_4(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_24 = (aux + st.buffer[1]) & 3;
  switch (quantum_24)
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

  int tracker_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_34 = ((tracker_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_34) & 127;
  }

  int phase_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001535_3513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int mask_13_1 = 0;
  int mask_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_13_1 = ((mask_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_13_2 = ((mask_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_13_1) & 127;
    acc_2 = (acc_2 + mask_13_2) & 127;
  }

  int offset_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_33_1)
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

  switch (offset_33_2)
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
  int threshold_96_1 = local_arr_1[aux_1 % 3];
  int threshold_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_13_1 == mask_13_2);
  assert(offset_33_1 == offset_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_96_1 == threshold_96_2);
}

int fn_R001535_3513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int mask_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_13 = ((mask_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_13) & 127;
  }

  int offset_33 = (aux + st.buffer[1]) & 3;
  switch (offset_33)
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
  int threshold_96 = local_arr[aux % 3];
  acc = (acc + (threshold_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_97_1 = 0;
  int margin_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_97_1 = ((margin_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_97_2 = ((margin_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_97_1) & 127;
    acc_2 = (acc_2 + margin_97_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_21_1 = local_arr_1[aux_1 % 3];
  int damping_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_51_1)
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

  switch (residue_51_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_97_1 == margin_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_21_1 == damping_21_2);
  assert(residue_51_1 == residue_51_2);
}

int fn_R001535_3513_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_97 = ((margin_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_97) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_21 = local_arr[aux % 3];
  acc = (acc + (damping_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_51 = (aux + st.buffer[1]) & 3;
  switch (residue_51)
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

  return (acc + aux) & 255;
}

void fn_R001535_3513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int residue_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_29_1) & 63;
  aux_2 = (aux_2 + residue_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_95_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_95_1 * 2)) + 5) & 127;
    aux_1 ^= margin_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_95_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_95_2 * 2)) + 5) & 127;
    aux_2 ^= margin_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_29_1)
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

  switch (quantum_29_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_29_1 == residue_29_2);
  assert(margin_95_1 == margin_95_2);
  assert(quantum_29_1 == quantum_29_2);
}

int fn_R001535_3513_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int residue_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_95 > 24)
  {
    acc = ((acc + (margin_95 * 2)) + 5) & 127;
    aux ^= margin_95 & 15;
  }
  else
  {
    acc = ((acc - margin_95) + 11) & 127;
    aux += 3;
  }
  int quantum_29 = (aux + st.buffer[1]) & 3;
  switch (quantum_29)
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

void fn_R001535_3513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_46_1) & 63;
  aux_2 = (aux_2 + margin_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_84_1 = local_arr_1[aux_1 % 3];
  int quantum_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_46_1 == margin_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_84_1 == quantum_84_2);
}

int fn_R001535_3513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_84 = local_arr[aux % 3];
  acc = (acc + (quantum_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_95_1 = 0;
  int bound_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_95_1 = ((bound_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_95_2 = ((bound_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_95_1) & 127;
    acc_2 = (acc_2 + bound_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_95_1 == bound_95_2);
}

int fn_R001535_3513_9(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_95 = ((bound_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001535_3513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_70_1)
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

  switch (tally_70_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_89_1 = local_arr_1[aux_1 % 3];
  int tally_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_70_1 == tally_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_89_1 == tally_89_2);
}

int fn_R001535_3513_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_70 = (aux + st.buffer[1]) & 3;
  switch (tally_70)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_89 = local_arr[aux % 3];
  acc = (acc + (tally_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_97_1) & 63;
  aux_2 = (aux_2 + bound_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_97_1 == bound_97_2);
}

int fn_R001535_3513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001535_3513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_76_1)
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

  switch (offset_76_2)
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

  int weight_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_67_1 > 44)
  {
    acc_1 = ((acc_1 + (weight_67_1 * 2)) + 5) & 127;
    aux_1 ^= weight_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_67_2 > 44)
  {
    acc_2 = ((acc_2 + (weight_67_2 * 2)) + 5) & 127;
    aux_2 ^= weight_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_12_1) & 63;
  aux_2 = (aux_2 + margin_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_76_1 == offset_76_2);
  assert(weight_67_1 == weight_67_2);
  assert(margin_12_1 == margin_12_2);
}

int fn_R001535_3513_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_76 = (aux + st.buffer[1]) & 3;
  switch (offset_76)
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

  int weight_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_67 > 44)
  {
    acc = ((acc + (weight_67 * 2)) + 5) & 127;
    aux ^= weight_67 & 15;
  }
  else
  {
    acc = ((acc - weight_67) + 11) & 127;
    aux += 3;
  }
  int margin_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_52_1) & 63;
  aux_2 = (aux_2 + anchor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_82_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_82_1 * 2)) + 5) & 127;
    aux_1 ^= offset_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_82_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_82_2 * 2)) + 5) & 127;
    aux_2 ^= offset_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_52_1 == anchor_52_2);
  assert(offset_82_1 == offset_82_2);
  assert(accumulator_57_1 == accumulator_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
}

int fn_R001535_3513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_52) & 63;
  acc ^= aux;
  int offset_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_82 > 36)
  {
    acc = ((acc + (offset_82 * 2)) + 5) & 127;
    aux ^= offset_82 & 15;
  }
  else
  {
    acc = ((acc - offset_82) + 11) & 127;
    aux += 3;
  }
  int accumulator_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_54_1 = 0;
  int phase_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_54_1 = ((phase_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_54_2 = ((phase_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_54_1) & 127;
    acc_2 = (acc_2 + phase_54_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_76_1 = local_arr_1[aux_1 % 3];
  int checksum_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_76_2 * 2)) & 127;
  int quotient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_38_1) & 63;
  aux_2 = (aux_2 + quotient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_44_1 > 15)
  {
    acc_1 = ((acc_1 + (stride_44_1 * 2)) + 5) & 127;
    aux_1 ^= stride_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_44_2 > 15)
  {
    acc_2 = ((acc_2 + (stride_44_2 * 2)) + 5) & 127;
    aux_2 ^= stride_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_54_1 == phase_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_76_1 == checksum_76_2);
  assert(quotient_38_1 == quotient_38_2);
  assert(stride_44_1 == stride_44_2);
}

int fn_R001535_3513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_54 = ((phase_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_54) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_76 = local_arr[aux % 3];
  acc = (acc + (checksum_76 * 2)) & 127;
  int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_38) & 63;
  acc ^= aux;
  int stride_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_44 > 15)
  {
    acc = ((acc + (stride_44 * 2)) + 5) & 127;
    aux ^= stride_44 & 15;
  }
  else
  {
    acc = ((acc - stride_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001535_3513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 27)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 27)
  {
    acc_2 = ((acc_2 + (factor_20_2 * 2)) + 5) & 127;
    aux_2 ^= factor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_42_1)
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

  switch (metric_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_79_1 = local_arr_1[aux_1 % 3];
  int threshold_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_20_1 == factor_20_2);
  assert(metric_42_1 == metric_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_79_1 == threshold_79_2);
}

int fn_R001535_3513_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 27)
  {
    acc = ((acc + (factor_20 * 2)) + 5) & 127;
    aux ^= factor_20 & 15;
  }
  else
  {
    acc = ((acc - factor_20) + 11) & 127;
    aux += 3;
  }
  int metric_42 = (aux + st.buffer[1]) & 3;
  switch (metric_42)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_79 = local_arr[aux % 3];
  acc = (acc + (threshold_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_43_1 = 0;
  int residue_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_43_1 = ((residue_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_43_2 = ((residue_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_43_1) & 127;
    acc_2 = (acc_2 + residue_43_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_40_1 = local_arr_1[aux_1 % 3];
  int scale_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_43_1 == residue_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_40_1 == scale_40_2);
}

int fn_R001535_3513_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_43 = ((residue_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_43) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_40 = local_arr[aux % 3];
  acc = (acc + (scale_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_57_1)
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

  switch (sample_57_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_41_1 = local_arr_1[aux_1 % 3];
  int residue_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_57_1 == sample_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_41_1 == residue_41_2);
}

int fn_R001535_3513_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_57 = (aux + st.buffer[1]) & 3;
  switch (sample_57)
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
  int local_arr[3] = {4, 9, 15};
  int residue_41 = local_arr[aux % 3];
  acc = (acc + (residue_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_84_1 = local_arr_1[aux_1 % 3];
  int offset_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_84_2 * 2)) & 127;
  int tracker_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_91_1 > 25)
  {
    acc_1 = ((acc_1 + (tracker_91_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_91_2 > 25)
  {
    acc_2 = ((acc_2 + (tracker_91_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_14_1 = 0;
  int anchor_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_14_1 = ((anchor_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_14_2 = ((anchor_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_14_1) & 127;
    acc_2 = (acc_2 + anchor_14_2) & 127;
  }

  int coefficient_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_69_1)
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

  switch (coefficient_69_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_84_1 == offset_84_2);
  assert(tracker_91_1 == tracker_91_2);
  assert(anchor_14_1 == anchor_14_2);
  assert(coefficient_69_1 == coefficient_69_2);
}

int fn_R001535_3513_18(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_84 = local_arr[aux % 3];
  acc = (acc + (offset_84 * 2)) & 127;
  int tracker_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_91 > 25)
  {
    acc = ((acc + (tracker_91 * 2)) + 5) & 127;
    aux ^= tracker_91 & 15;
  }
  else
  {
    acc = ((acc - tracker_91) + 11) & 127;
    aux += 3;
  }
  int anchor_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_14 = ((anchor_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_14) & 127;
  }

  int coefficient_69 = (aux + st.buffer[1]) & 3;
  switch (coefficient_69)
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

void fn_R001535_3513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_92_1)
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

  switch (residue_92_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_92_1 == residue_92_2);
}

int fn_R001535_3513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_92 = (aux + st.buffer[1]) & 3;
  switch (residue_92)
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

void fn_R001535_3513_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_99_1 > 39)
  {
    acc_1 = ((acc_1 + (quotient_99_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_99_2 > 39)
  {
    acc_2 = ((acc_2 + (quotient_99_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_99_1 == quotient_99_2);
}

int fn_R001535_3513_20(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_99 > 39)
  {
    acc = ((acc + (quotient_99 * 2)) + 5) & 127;
    aux ^= quotient_99 & 15;
  }
  else
  {
    acc = ((acc - quotient_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001535_3513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int bound_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_98_1)
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

  switch (bound_98_2)
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

  int metric_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_10_1 > 13)
  {
    acc_1 = ((acc_1 + (metric_10_1 * 2)) + 5) & 127;
    aux_1 ^= metric_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_10_2 > 13)
  {
    acc_2 = ((acc_2 + (metric_10_2 * 2)) + 5) & 127;
    aux_2 ^= metric_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_90_1 = 0;
  int cursor_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_90_1 = ((cursor_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_90_2 = ((cursor_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_90_1) & 127;
    acc_2 = (acc_2 + cursor_90_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_98_1 == bound_98_2);
  assert(metric_10_1 == metric_10_2);
  assert(cursor_90_1 == cursor_90_2);
}

int fn_R001535_3513_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001535_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int bound_98 = (aux + st.buffer[1]) & 3;
  switch (bound_98)
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

  int metric_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_10 > 13)
  {
    acc = ((acc + (metric_10 * 2)) + 5) & 127;
    aux ^= metric_10 & 15;
  }
  else
  {
    acc = ((acc - metric_10) + 11) & 127;
    aux += 3;
  }
  int cursor_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_90 = ((cursor_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_90) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001535_3513_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st_1 = {0};
  struct Vector3D_R001535_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_79_1)
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

  switch (damping_79_2)
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
  int quantum_97_1 = local_arr_1[aux_1 % 3];
  int quantum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_97_2 * 2)) & 127;
  int window_94_1 = 0;
  int window_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_94_1 = ((window_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_94_2 = ((window_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_94_1) & 127;
    acc_2 = (acc_2 + window_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_79_1 == damping_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_97_1 == quantum_97_2);
  assert(window_94_1 == window_94_2);
}

int fn_R001535_3513_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001535_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_79 = (aux + st.buffer[1]) & 3;
  switch (damping_79)
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
  int quantum_97 = local_arr[aux % 3];
  acc = (acc + (quantum_97 * 2)) & 127;
  int window_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_94 = ((window_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001535_3513_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st_1 = {0};
  struct FilterState_R001535_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_50_1 = 0;
  int sample_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_50_1 = ((sample_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_50_2 = ((sample_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_50_1) & 127;
    acc_2 = (acc_2 + sample_50_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_59_1 = local_arr_1[aux_1 % 3];
  int anchor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_59_2 * 2)) & 127;
  int factor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_57_1)
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

  switch (factor_57_2)
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

  int accumulator_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_59_1 > 17)
  {
    acc_1 = ((acc_1 + (accumulator_59_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_59_2 > 17)
  {
    acc_2 = ((acc_2 + (accumulator_59_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_50_1 == sample_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_59_1 == anchor_59_2);
  assert(factor_57_1 == factor_57_2);
  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R001535_3513_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001535_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_50 = ((sample_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_50) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_59 = local_arr[aux % 3];
  acc = (acc + (anchor_59 * 2)) & 127;
  int factor_57 = (aux + st.buffer[1]) & 3;
  switch (factor_57)
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

  int accumulator_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_59 > 17)
  {
    acc = ((acc + (accumulator_59 * 2)) + 5) & 127;
    aux ^= accumulator_59 & 15;
  }
  else
  {
    acc = ((acc - accumulator_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001535_0_1;
  int sec_r001535_0_2;
  int sec_r001535_1_1;
  int sec_r001535_1_2;
  int sec_r001535_2_1;
  int sec_r001535_2_2;
  int sec_r001535_3_1;
  int sec_r001535_3_2;
  int sec_r001535_4_1;
  int sec_r001535_4_2;
  int sec_r001535_5_1;
  int sec_r001535_5_2;
  int sec_r001535_6_1;
  int sec_r001535_6_2;
  int sec_r001535_7_1;
  int sec_r001535_7_2;
  int sec_r001535_8_1;
  int sec_r001535_8_2;
  int sec_r001535_9_1;
  int sec_r001535_9_2;
  int sec_r001535_10_1;
  int sec_r001535_10_2;
  int sec_r001535_11_1;
  int sec_r001535_11_2;
  int sec_r001535_12_1;
  int sec_r001535_12_2;
  int sec_r001535_13_1;
  int sec_r001535_13_2;
  int sec_r001535_14_1;
  int sec_r001535_14_2;
  int sec_r001535_15_1;
  int sec_r001535_15_2;
  int sec_r001535_16_1;
  int sec_r001535_16_2;
  int sec_r001535_17_1;
  int sec_r001535_17_2;
  int sec_r001535_18_1;
  int sec_r001535_18_2;
  int sec_r001535_19_1;
  int sec_r001535_19_2;
  int sec_r001535_20_1;
  int sec_r001535_20_2;
  int pub_r001535_0_1;
  int pub_r001535_0_2;
  int pub_r001535_1_1;
  int pub_r001535_1_2;
  int pub_r001535_2_1;
  int pub_r001535_2_2;
  int pub_r001535_3_1;
  int pub_r001535_3_2;
  int pub_r001535_4_1;
  int pub_r001535_4_2;
  int pub_r001535_5_1;
  int pub_r001535_5_2;
  int pub_r001535_6_1;
  int pub_r001535_6_2;
  int pub_r001535_7_1;
  int pub_r001535_7_2;
  int pub_r001535_8_1;
  int pub_r001535_8_2;
  int pub_r001535_9_1;
  int pub_r001535_9_2;
  int pub_r001535_10_1;
  int pub_r001535_10_2;
  int pub_r001535_11_1;
  int pub_r001535_11_2;
  int pub_r001535_12_1;
  int pub_r001535_12_2;
  int pub_r001535_13_1;
  int pub_r001535_13_2;
  int pub_r001535_14_1;
  int pub_r001535_14_2;
  int pub_r001535_15_1;
  int pub_r001535_15_2;
  int pub_r001535_16_1;
  int pub_r001535_16_2;
  int pub_r001535_17_1;
  int pub_r001535_17_2;
  int pub_r001535_18_1;
  int pub_r001535_18_2;
  int pub_r001535_19_1;
  int pub_r001535_19_2;
  int pub_r001535_20_1;
  int pub_r001535_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001535_0_1 >= (-100)) && (pub_r001535_0_1 <= 100));
  __CPROVER_assume((pub_r001535_0_2 >= (-100)) && (pub_r001535_0_2 <= 100));
  __CPROVER_assume((pub_r001535_1_1 >= (-100)) && (pub_r001535_1_1 <= 100));
  __CPROVER_assume((pub_r001535_1_2 >= (-100)) && (pub_r001535_1_2 <= 100));
  __CPROVER_assume((pub_r001535_2_1 >= (-100)) && (pub_r001535_2_1 <= 100));
  __CPROVER_assume((pub_r001535_2_2 >= (-100)) && (pub_r001535_2_2 <= 100));
  __CPROVER_assume((pub_r001535_3_1 >= (-100)) && (pub_r001535_3_1 <= 100));
  __CPROVER_assume((pub_r001535_3_2 >= (-100)) && (pub_r001535_3_2 <= 100));
  __CPROVER_assume((pub_r001535_4_1 >= (-100)) && (pub_r001535_4_1 <= 100));
  __CPROVER_assume((pub_r001535_4_2 >= (-100)) && (pub_r001535_4_2 <= 100));
  __CPROVER_assume((pub_r001535_5_1 >= (-100)) && (pub_r001535_5_1 <= 100));
  __CPROVER_assume((pub_r001535_5_2 >= (-100)) && (pub_r001535_5_2 <= 100));
  __CPROVER_assume((pub_r001535_6_1 >= (-100)) && (pub_r001535_6_1 <= 100));
  __CPROVER_assume((pub_r001535_6_2 >= (-100)) && (pub_r001535_6_2 <= 100));
  __CPROVER_assume((pub_r001535_7_1 >= (-100)) && (pub_r001535_7_1 <= 100));
  __CPROVER_assume((pub_r001535_7_2 >= (-100)) && (pub_r001535_7_2 <= 100));
  __CPROVER_assume((pub_r001535_8_1 >= (-100)) && (pub_r001535_8_1 <= 100));
  __CPROVER_assume((pub_r001535_8_2 >= (-100)) && (pub_r001535_8_2 <= 100));
  __CPROVER_assume((pub_r001535_9_1 >= (-100)) && (pub_r001535_9_1 <= 100));
  __CPROVER_assume((pub_r001535_9_2 >= (-100)) && (pub_r001535_9_2 <= 100));
  __CPROVER_assume((pub_r001535_10_1 >= (-100)) && (pub_r001535_10_1 <= 100));
  __CPROVER_assume((pub_r001535_10_2 >= (-100)) && (pub_r001535_10_2 <= 100));
  __CPROVER_assume((pub_r001535_11_1 >= (-100)) && (pub_r001535_11_1 <= 100));
  __CPROVER_assume((pub_r001535_11_2 >= (-100)) && (pub_r001535_11_2 <= 100));
  __CPROVER_assume((pub_r001535_12_1 >= (-100)) && (pub_r001535_12_1 <= 100));
  __CPROVER_assume((pub_r001535_12_2 >= (-100)) && (pub_r001535_12_2 <= 100));
  __CPROVER_assume((pub_r001535_13_1 >= (-100)) && (pub_r001535_13_1 <= 100));
  __CPROVER_assume((pub_r001535_13_2 >= (-100)) && (pub_r001535_13_2 <= 100));
  __CPROVER_assume((pub_r001535_14_1 >= (-100)) && (pub_r001535_14_1 <= 100));
  __CPROVER_assume((pub_r001535_14_2 >= (-100)) && (pub_r001535_14_2 <= 100));
  __CPROVER_assume((pub_r001535_15_1 >= (-100)) && (pub_r001535_15_1 <= 100));
  __CPROVER_assume((pub_r001535_15_2 >= (-100)) && (pub_r001535_15_2 <= 100));
  __CPROVER_assume((pub_r001535_16_1 >= (-100)) && (pub_r001535_16_1 <= 100));
  __CPROVER_assume((pub_r001535_16_2 >= (-100)) && (pub_r001535_16_2 <= 100));
  __CPROVER_assume((pub_r001535_17_1 >= (-100)) && (pub_r001535_17_1 <= 100));
  __CPROVER_assume((pub_r001535_17_2 >= (-100)) && (pub_r001535_17_2 <= 100));
  __CPROVER_assume((pub_r001535_18_1 >= (-100)) && (pub_r001535_18_1 <= 100));
  __CPROVER_assume((pub_r001535_18_2 >= (-100)) && (pub_r001535_18_2 <= 100));
  __CPROVER_assume((pub_r001535_19_1 >= (-100)) && (pub_r001535_19_1 <= 100));
  __CPROVER_assume((pub_r001535_19_2 >= (-100)) && (pub_r001535_19_2 <= 100));
  __CPROVER_assume((pub_r001535_20_1 >= (-100)) && (pub_r001535_20_1 <= 100));
  __CPROVER_assume((pub_r001535_20_2 >= (-100)) && (pub_r001535_20_2 <= 100));
  __CPROVER_assume((sec_r001535_0_1 >= 0) && (sec_r001535_0_1 <= 255));
  __CPROVER_assume((sec_r001535_0_2 >= 0) && (sec_r001535_0_2 <= 255));
  __CPROVER_assume((sec_r001535_1_1 >= 0) && (sec_r001535_1_1 <= 255));
  __CPROVER_assume((sec_r001535_1_2 >= 0) && (sec_r001535_1_2 <= 255));
  __CPROVER_assume((sec_r001535_2_1 >= 0) && (sec_r001535_2_1 <= 255));
  __CPROVER_assume((sec_r001535_2_2 >= 0) && (sec_r001535_2_2 <= 255));
  __CPROVER_assume((sec_r001535_3_1 >= 0) && (sec_r001535_3_1 <= 255));
  __CPROVER_assume((sec_r001535_3_2 >= 0) && (sec_r001535_3_2 <= 255));
  __CPROVER_assume((sec_r001535_4_1 >= 0) && (sec_r001535_4_1 <= 255));
  __CPROVER_assume((sec_r001535_4_2 >= 0) && (sec_r001535_4_2 <= 255));
  __CPROVER_assume((sec_r001535_5_1 >= 0) && (sec_r001535_5_1 <= 255));
  __CPROVER_assume((sec_r001535_5_2 >= 0) && (sec_r001535_5_2 <= 255));
  __CPROVER_assume((sec_r001535_6_1 >= 0) && (sec_r001535_6_1 <= 255));
  __CPROVER_assume((sec_r001535_6_2 >= 0) && (sec_r001535_6_2 <= 255));
  __CPROVER_assume((sec_r001535_7_1 >= 0) && (sec_r001535_7_1 <= 255));
  __CPROVER_assume((sec_r001535_7_2 >= 0) && (sec_r001535_7_2 <= 255));
  __CPROVER_assume((sec_r001535_8_1 >= 0) && (sec_r001535_8_1 <= 255));
  __CPROVER_assume((sec_r001535_8_2 >= 0) && (sec_r001535_8_2 <= 255));
  __CPROVER_assume((sec_r001535_9_1 >= 0) && (sec_r001535_9_1 <= 255));
  __CPROVER_assume((sec_r001535_9_2 >= 0) && (sec_r001535_9_2 <= 255));
  __CPROVER_assume((sec_r001535_10_1 >= 0) && (sec_r001535_10_1 <= 255));
  __CPROVER_assume((sec_r001535_10_2 >= 0) && (sec_r001535_10_2 <= 255));
  __CPROVER_assume((sec_r001535_11_1 >= 0) && (sec_r001535_11_1 <= 255));
  __CPROVER_assume((sec_r001535_11_2 >= 0) && (sec_r001535_11_2 <= 255));
  __CPROVER_assume((sec_r001535_12_1 >= 0) && (sec_r001535_12_1 <= 255));
  __CPROVER_assume((sec_r001535_12_2 >= 0) && (sec_r001535_12_2 <= 255));
  __CPROVER_assume((sec_r001535_13_1 >= 0) && (sec_r001535_13_1 <= 255));
  __CPROVER_assume((sec_r001535_13_2 >= 0) && (sec_r001535_13_2 <= 255));
  __CPROVER_assume((sec_r001535_14_1 >= 0) && (sec_r001535_14_1 <= 255));
  __CPROVER_assume((sec_r001535_14_2 >= 0) && (sec_r001535_14_2 <= 255));
  __CPROVER_assume((sec_r001535_15_1 >= 0) && (sec_r001535_15_1 <= 255));
  __CPROVER_assume((sec_r001535_15_2 >= 0) && (sec_r001535_15_2 <= 255));
  __CPROVER_assume((sec_r001535_16_1 >= 0) && (sec_r001535_16_1 <= 255));
  __CPROVER_assume((sec_r001535_16_2 >= 0) && (sec_r001535_16_2 <= 255));
  __CPROVER_assume((sec_r001535_17_1 >= 0) && (sec_r001535_17_1 <= 255));
  __CPROVER_assume((sec_r001535_17_2 >= 0) && (sec_r001535_17_2 <= 255));
  __CPROVER_assume((sec_r001535_18_1 >= 0) && (sec_r001535_18_1 <= 255));
  __CPROVER_assume((sec_r001535_18_2 >= 0) && (sec_r001535_18_2 <= 255));
  __CPROVER_assume((sec_r001535_19_1 >= 0) && (sec_r001535_19_1 <= 255));
  __CPROVER_assume((sec_r001535_19_2 >= 0) && (sec_r001535_19_2 <= 255));
  __CPROVER_assume((sec_r001535_20_1 >= 0) && (sec_r001535_20_1 <= 255));
  __CPROVER_assume((sec_r001535_20_2 >= 0) && (sec_r001535_20_2 <= 255));
  struct FilterState_R001535_3513_0 st_var_0_1 = {0};
  struct FilterState_R001535_3513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001535_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001535_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001535_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001535_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001535_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001535_0_2 + 7) & 15;
  struct MatrixBlock_R001535_3513_1 st_var_1_1 = {0};
  struct MatrixBlock_R001535_3513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001535_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001535_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001535_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001535_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001535_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001535_0_2 + 9) & 15;
  struct Vector3D_R001535_3513_2 st_var_2_1 = {0};
  struct Vector3D_R001535_3513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001535_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001535_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001535_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001535_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001535_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001535_0_2 + 11) & 15;
  union TelemetryField_R001535_3513_0 u_var_1;
  union TelemetryField_R001535_3513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001535_3513_0(sec_r001535_0_1, pub_r001535_1_1);
  int helper_flow_0_2 = fn_R001535_3513_0(sec_r001535_0_2, pub_r001535_1_2);
  fn_R001535_3513_0_2(sec_r001535_0_1, pub_r001535_1_1, sec_r001535_0_2, pub_r001535_1_2);
  int helper_flow_1_1 = fn_R001535_3513_1(sec_r001535_1_1, pub_r001535_2_1, pub_r001535_3_1, pub_r001535_4_1, pub_r001535_5_1);
  int helper_flow_1_2 = fn_R001535_3513_1(sec_r001535_1_2, pub_r001535_2_2, pub_r001535_3_2, pub_r001535_4_2, pub_r001535_5_2);
  fn_R001535_3513_1_2(sec_r001535_1_1, pub_r001535_2_1, pub_r001535_3_1, pub_r001535_4_1, pub_r001535_5_1, sec_r001535_1_2, pub_r001535_2_2, pub_r001535_3_2, pub_r001535_4_2, pub_r001535_5_2);
  int helper_flow_2_1 = fn_R001535_3513_2(sec_r001535_2_1, sec_r001535_3_1, pub_r001535_4_1);
  int helper_flow_2_2 = fn_R001535_3513_2(sec_r001535_2_2, sec_r001535_3_2, pub_r001535_4_2);
  fn_R001535_3513_2_2(sec_r001535_2_1, sec_r001535_3_1, pub_r001535_4_1, sec_r001535_2_2, sec_r001535_3_2, pub_r001535_4_2);
  int helper_flow_3_1 = fn_R001535_3513_3(sec_r001535_3_1, sec_r001535_4_1, pub_r001535_5_1);
  int helper_flow_3_2 = fn_R001535_3513_3(sec_r001535_3_2, sec_r001535_4_2, pub_r001535_5_2);
  fn_R001535_3513_3_2(sec_r001535_3_1, sec_r001535_4_1, pub_r001535_5_1, sec_r001535_3_2, sec_r001535_4_2, pub_r001535_5_2);
  int helper_flow_4_1 = fn_R001535_3513_4(sec_r001535_4_1, sec_r001535_5_1);
  int helper_flow_4_2 = fn_R001535_3513_4(sec_r001535_4_2, sec_r001535_5_2);
  fn_R001535_3513_4_2(sec_r001535_4_1, sec_r001535_5_1, sec_r001535_4_2, sec_r001535_5_2);
  int stage_v_0_1 = ((sec_r001535_9_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001535_9_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((pub_r001535_4_1 * 2) + 32) & 63;
  int stage_v_1_2 = ((pub_r001535_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001535_14_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001535_14_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((sec_r001535_5_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001535_5_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((pub_r001535_1_1 * 2) + 23) & 63;
  int stage_v_4_2 = ((pub_r001535_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001535_13_1 * 2) + 18) & 63;
  int stage_v_5_2 = ((pub_r001535_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001535_9_1 * 2) + 27) & 63;
  int stage_v_6_2 = ((pub_r001535_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001535_5_1 * 2) + 8) & 63;
  int stage_v_7_2 = ((pub_r001535_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001535_12_1 * 2) + 50) & 63;
  int stage_v_8_2 = ((pub_r001535_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001535_14_1 * 2) + 14) & 63;
  int stage_v_9_2 = ((pub_r001535_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001535_8_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001535_8_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((pub_r001535_2_1 * 2) + 18) & 63;
  int stage_v_11_2 = ((pub_r001535_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((stage_v_3_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_12_2 = ((stage_v_3_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((stage_v_3_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_13_2 = ((stage_v_3_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((stage_v_12_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_14_2 = ((stage_v_12_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_2_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_2_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((stage_v_0_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_16_2 = ((stage_v_0_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((pub_r001535_9_1 * 2) + 37) & 63;
  int stage_v_17_2 = ((pub_r001535_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001535_11_1 * 2) + 48) & 63;
  int stage_v_18_2 = ((pub_r001535_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((sec_r001535_13_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_19_2 = ((sec_r001535_13_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((stage_v_13_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_13_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001535_11_1 * 2) + 14) & 63;
  int stage_v_21_2 = ((pub_r001535_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_3_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_22_2 = ((helper_flow_3_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_23_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((pub_r001535_5_1 * 2) + 7) & 63;
  int stage_v_24_2 = ((pub_r001535_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001535_7_1 * 2) + 50) & 63;
  int stage_v_25_2 = ((pub_r001535_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001535_16_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_26_2 = ((sec_r001535_16_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((pub_r001535_11_1 * 2) + 29) & 63;
  int stage_v_27_2 = ((pub_r001535_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001535_2_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001535_2_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001535_15_1 * 2) + 32) & 63;
  int stage_v_29_2 = ((pub_r001535_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001535_4_1 * 2) + 44) & 63;
  int stage_v_30_2 = ((pub_r001535_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001535_13_1 * 2) + 12) & 63;
  int stage_v_31_2 = ((pub_r001535_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((pub_r001535_12_1 * 2) + 10) & 63;
  int stage_v_33_2 = ((pub_r001535_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001535_0_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001535_0_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001535_18_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001535_18_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((pub_r001535_13_1 * 2) + 43) & 63;
  int stage_v_36_2 = ((pub_r001535_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_3_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_37_2 = ((stage_v_3_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((pub_r001535_6_1 * 2) + 15) & 63;
  int stage_v_38_2 = ((pub_r001535_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001535_14_1 * 2) + 36) & 63;
  int stage_v_39_2 = ((pub_r001535_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001535_6_1 * 2) + 48) & 63;
  int stage_v_40_2 = ((pub_r001535_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((sec_r001535_13_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_41_2 = ((sec_r001535_13_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_42_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((helper_flow_4_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_43_2 = ((helper_flow_4_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((pub_r001535_12_1 * 2) + 6) & 63;
  int stage_v_44_2 = ((pub_r001535_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_34_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_45_2 = ((stage_v_34_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((stage_v_42_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_42_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001535_14_1 * 2) + 15) & 63;
  int stage_v_47_2 = ((pub_r001535_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001535_6_1 * 2) + 10) & 63;
  int stage_v_48_2 = ((pub_r001535_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001535_14_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001535_14_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001535_18_1 * 2) + 39) & 63;
  int stage_v_50_2 = ((pub_r001535_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001535_5_1 * 2) + 29) & 63;
  int stage_v_51_2 = ((pub_r001535_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((sec_r001535_12_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001535_12_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((stage_v_35_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_35_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((sec_r001535_6_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_55_2 = ((sec_r001535_6_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((pub_r001535_2_1 * 2) + 5) & 63;
  int stage_v_56_2 = ((pub_r001535_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001535_16_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_57_2 = ((sec_r001535_16_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((stage_v_10_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_10_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((sec_r001535_18_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_59_2 = ((sec_r001535_18_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((pub_r001535_13_1 * 2) + 25) & 63;
  int stage_v_60_2 = ((pub_r001535_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((stage_v_10_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_10_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_16_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_16_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((sec_r001535_19_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_63_2 = ((sec_r001535_19_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((stage_v_2_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_64_2 = ((stage_v_2_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((pub_r001535_10_1 * 2) + 35) & 63;
  int stage_v_65_2 = ((pub_r001535_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001535_15_1 * 2) + 37) & 63;
  int stage_v_66_2 = ((pub_r001535_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_67_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001535_6_1 * 2) + 26) & 63;
  int stage_v_68_2 = ((pub_r001535_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001535_11_1 * 2) + 9) & 63;
  int stage_v_69_2 = ((pub_r001535_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001535_6_1 * 2) + 32) & 63;
  int stage_v_70_2 = ((pub_r001535_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001535_12_1 * 2) + 29) & 63;
  int stage_v_71_2 = ((pub_r001535_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_61_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_61_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((stage_v_72_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_73_2 = ((stage_v_72_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((stage_v_34_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_74_2 = ((stage_v_34_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((pub_r001535_16_1 * 2) + 45) & 63;
  int stage_v_75_2 = ((pub_r001535_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001535_0_1 * 2) + 8) & 63;
  int stage_v_76_2 = ((pub_r001535_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001535_0_1 * 2) + 42) & 63;
  int stage_v_77_2 = ((pub_r001535_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((sec_r001535_12_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_78_2 = ((sec_r001535_12_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((stage_v_37_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_79_2 = ((stage_v_37_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((pub_r001535_13_1 * 2) + 25) & 63;
  int stage_v_80_2 = ((pub_r001535_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((helper_flow_4_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_81_2 = ((helper_flow_4_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((stage_v_46_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_46_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((pub_r001535_13_1 * 2) + 25) & 63;
  int stage_v_83_2 = ((pub_r001535_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((sec_r001535_4_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_84_2 = ((sec_r001535_4_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((pub_r001535_16_1 * 2) + 18) & 63;
  int stage_v_85_2 = ((pub_r001535_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001535_13_1 * 2) + 43) & 63;
  int stage_v_86_2 = ((pub_r001535_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001535_11_1 * 2) + 41) & 63;
  int stage_v_87_2 = ((pub_r001535_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_88_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((stage_v_14_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_14_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((sec_r001535_0_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_90_2 = ((sec_r001535_0_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((pub_r001535_2_1 * 2) + 42) & 63;
  int stage_v_91_2 = ((pub_r001535_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001535_2_1 * 2) + 37) & 63;
  int stage_v_92_2 = ((pub_r001535_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_32_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_32_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((pub_r001535_8_1 * 2) + 39) & 63;
  int stage_v_94_2 = ((pub_r001535_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001535_20_1 * 2) + 10) & 63;
  int stage_v_95_2 = ((pub_r001535_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_49_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_49_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((sec_r001535_10_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_97_2 = ((sec_r001535_10_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((stage_v_55_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_55_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001535_9_1 * 2) + 39) & 63;
  int stage_v_99_2 = ((pub_r001535_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001535_13_1 * 2) + 26) & 63;
  int stage_v_100_2 = ((pub_r001535_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_10_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_10_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((pub_r001535_10_1 * 2) + 5) & 63;
  int stage_v_102_2 = ((pub_r001535_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_79_1 << 1) ^ (pub_r001535_2_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_79_2 << 1) ^ (pub_r001535_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((stage_v_64_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_64_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001535_13_1 * 2) + 50) & 63;
  int stage_v_105_2 = ((pub_r001535_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001535_19_1 * 2) + 21) & 63;
  int stage_v_106_2 = ((pub_r001535_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((sec_r001535_7_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_107_2 = ((sec_r001535_7_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001535_8_1 * 2) + 44) & 63;
  int stage_v_108_2 = ((pub_r001535_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_74_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_74_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001535_11_1 * 2) + 36) & 63;
  int stage_v_110_2 = ((pub_r001535_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_32_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_32_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((helper_flow_2_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_112_2 = ((helper_flow_2_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_0_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_0_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((stage_v_32_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_114_2 = ((stage_v_32_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_22_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_22_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001535_18_1 * 2) + 36) & 63;
  int stage_v_116_2 = ((pub_r001535_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((stage_v_104_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_117_2 = ((stage_v_104_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((pub_r001535_20_1 * 2) + 38) & 63;
  int stage_v_118_2 = ((pub_r001535_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001535_13_1 * 2) + 22) & 63;
  int stage_v_119_2 = ((pub_r001535_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001535_18_1 * 2) + 36) & 63;
  int stage_v_120_2 = ((pub_r001535_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((sec_r001535_2_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_121_2 = ((sec_r001535_2_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((stage_v_90_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_90_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_88_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_88_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001535_5_1 * 2) + 27) & 63;
  int stage_v_124_2 = ((pub_r001535_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001535_4_1 * 2) + 40) & 63;
  int stage_v_125_2 = ((pub_r001535_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001535_5_1 * 2) + 49) & 63;
  int stage_v_126_2 = ((pub_r001535_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_74_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_74_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_123_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_123_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_90_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_90_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((sec_r001535_13_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_130_2 = ((sec_r001535_13_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((pub_r001535_6_1 * 2) + 42) & 63;
  int stage_v_131_2 = ((pub_r001535_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_112_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_112_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((stage_v_58_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_58_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001535_13_1 * 2) + 14) & 63;
  int stage_v_134_2 = ((pub_r001535_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001535_8_1 * 2) + 20) & 63;
  int stage_v_135_2 = ((pub_r001535_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((helper_flow_1_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_136_2 = ((helper_flow_1_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((stage_v_117_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_117_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((stage_v_54_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_54_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001535_18_1 * 2) + 20) & 63;
  int stage_v_139_2 = ((pub_r001535_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_115_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_115_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_141_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_62_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_62_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001535_16_1 * 2) + 27) & 63;
  int stage_v_143_2 = ((pub_r001535_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001535_20_1 * 2) + 19) & 63;
  int stage_v_144_2 = ((pub_r001535_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001535_2_1 * 2) + 31) & 63;
  int stage_v_145_2 = ((pub_r001535_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001535_5_1 * 2) + 10) & 63;
  int stage_v_146_2 = ((pub_r001535_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((sec_r001535_8_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_147_2 = ((sec_r001535_8_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((sec_r001535_17_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_148_2 = ((sec_r001535_17_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((sec_r001535_12_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_149_2 = ((sec_r001535_12_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((sec_r001535_9_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_150_2 = ((sec_r001535_9_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((stage_v_79_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_79_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((pub_r001535_2_1 * 2) + 39) & 63;
  int stage_v_152_2 = ((pub_r001535_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_28_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_28_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((pub_r001535_20_1 * 2) + 18) & 63;
  int stage_v_154_2 = ((pub_r001535_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_151_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_151_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((sec_r001535_19_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_156_2 = ((sec_r001535_19_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((pub_r001535_16_1 * 2) + 35) & 63;
  int stage_v_157_2 = ((pub_r001535_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001535_6_1 * 2) + 36) & 63;
  int stage_v_158_2 = ((pub_r001535_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_84_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_84_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_128_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_128_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((pub_r001535_4_1 * 2) + 36) & 63;
  int stage_v_161_2 = ((pub_r001535_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001535_3_1 * 2) + 19) & 63;
  int stage_v_162_2 = ((pub_r001535_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001535_15_1 * 2) + 13) & 63;
  int stage_v_163_2 = ((pub_r001535_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001535_11_1 * 2) + 25) & 63;
  int stage_v_164_2 = ((pub_r001535_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001535_8_1 * 2) + 19) & 63;
  int stage_v_165_2 = ((pub_r001535_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_122_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_122_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((pub_r001535_12_1 * 2) + 45) & 63;
  int stage_v_167_2 = ((pub_r001535_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001535_0_1 * 2) + 23) & 63;
  int stage_v_168_2 = ((pub_r001535_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_141_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_141_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_128_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_128_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((stage_v_132_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_132_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((sec_r001535_11_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_172_2 = ((sec_r001535_11_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((sec_r001535_6_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_173_2 = ((sec_r001535_6_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((pub_r001535_15_1 * 2) + 48) & 63;
  int stage_v_174_2 = ((pub_r001535_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((sec_r001535_19_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_175_2 = ((sec_r001535_19_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((stage_v_16_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_16_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001535_20_1 * 2) + 9) & 63;
  int stage_v_177_2 = ((pub_r001535_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001535_13_1 * 2) + 48) & 63;
  int stage_v_178_2 = ((pub_r001535_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001535_6_1 * 2) + 38) & 63;
  int stage_v_179_2 = ((pub_r001535_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_169_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_180_2 = ((stage_v_169_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((stage_v_169_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_181_2 = ((stage_v_169_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((pub_r001535_3_1 * 2) + 12) & 63;
  int stage_v_182_2 = ((pub_r001535_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_72_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_72_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((stage_v_115_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_115_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((pub_r001535_7_1 * 2) + 11) & 63;
  int stage_v_185_2 = ((pub_r001535_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_173_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_186_2 = ((stage_v_173_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_186_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_186_2 + 1) & 15;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = ((stage_v_23_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_23_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((pub_r001535_13_1 * 2) + 12) & 63;
  int stage_v_188_2 = ((pub_r001535_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((sec_r001535_9_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_189_2 = ((sec_r001535_9_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((stage_v_10_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_190_2 = ((stage_v_10_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_54_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_54_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_122_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_122_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((pub_r001535_2_1 * 2) + 18) & 63;
  int stage_v_193_2 = ((pub_r001535_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001535_5_1 * 2) + 18) & 63;
  int stage_v_194_2 = ((pub_r001535_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((sec_r001535_0_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_195_2 = ((sec_r001535_0_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((sec_r001535_14_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_196_2 = ((sec_r001535_14_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((pub_r001535_11_1 * 2) + 31) & 63;
  int stage_v_197_2 = ((pub_r001535_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001535_1_1 * 2) + 37) & 63;
  int stage_v_198_2 = ((pub_r001535_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001535_8_1 * 2) + 38) & 63;
  int stage_v_199_2 = ((pub_r001535_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_114_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_114_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001535_8_1 * 2) + 19) & 63;
  int stage_v_201_2 = ((pub_r001535_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_200_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_200_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001535_7_1 * 2) + 28) & 63;
  int stage_v_203_2 = ((pub_r001535_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_171_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_171_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((stage_v_19_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_19_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_206_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((stage_v_153_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_207_2 = ((stage_v_153_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((pub_r001535_6_1 * 2) + 27) & 63;
  int stage_v_208_2 = ((pub_r001535_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_67_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_67_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((stage_v_98_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_98_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_115_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_115_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001535_5_1 * 2) + 36) & 63;
  int stage_v_212_2 = ((pub_r001535_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_20_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_20_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_147_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_147_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((stage_v_127_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_215_2 = ((stage_v_127_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((stage_v_49_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_49_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001535_13_1 * 2) + 45) & 63;
  int stage_v_217_2 = ((pub_r001535_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001535_16_1 * 2) + 32) & 63;
  int stage_v_218_2 = ((pub_r001535_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((sec_r001535_9_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_219_2 = ((sec_r001535_9_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001535_4_1 * 2) + 31) & 63;
  int stage_v_220_2 = ((pub_r001535_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_211_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_211_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_156_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_156_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001535_10_1 * 2) + 28) & 63;
  int stage_v_223_2 = ((pub_r001535_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_224_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((stage_v_10_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_10_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001535_2_1 * 2) + 26) & 63;
  int stage_v_226_2 = ((pub_r001535_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001535_10_1 * 2) + 15) & 63;
  int stage_v_227_2 = ((pub_r001535_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001535_19_1 * 2) + 48) & 63;
  int stage_v_228_2 = ((pub_r001535_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((stage_v_142_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_142_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((stage_v_15_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_15_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((pub_r001535_8_1 * 2) + 30) & 63;
  int stage_v_231_2 = ((pub_r001535_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_148_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_148_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((stage_v_23_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_23_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((pub_r001535_2_1 * 2) + 14) & 63;
  int stage_v_234_2 = ((pub_r001535_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_235_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_16_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_16_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001535_5_1 * 2) + 15) & 63;
  int stage_v_237_2 = ((pub_r001535_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((sec_r001535_16_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_238_2 = ((sec_r001535_16_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((pub_r001535_5_1 * 2) + 9) & 63;
  int stage_v_239_2 = ((pub_r001535_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_142_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_142_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001535_0_1 * 2) + 32) & 63;
  int stage_v_241_2 = ((pub_r001535_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001535_17_1 * 2) + 37) & 63;
  int stage_v_242_2 = ((pub_r001535_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_26_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_26_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001535_3_1 * 2) + 24) & 63;
  int stage_v_244_2 = ((pub_r001535_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001535_5_1 * 2) + 22) & 63;
  int stage_v_245_2 = ((pub_r001535_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_104_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_104_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((pub_r001535_9_1 * 2) + 26) & 63;
  int stage_v_247_2 = ((pub_r001535_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((pub_r001535_3_1 * 2) + 35) & 63;
  int stage_v_249_2 = ((pub_r001535_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001535_9_1 * 2) + 22) & 63;
  int stage_v_250_2 = ((pub_r001535_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001535_8_1 * 2) + 30) & 63;
  int stage_v_251_2 = ((pub_r001535_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001535_3_1 * 2) + 33) & 63;
  int stage_v_252_2 = ((pub_r001535_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((sec_r001535_9_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_253_2 = ((sec_r001535_9_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001535_17_1 * 2) + 22) & 63;
  int stage_v_254_2 = ((pub_r001535_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001535_13_1 * 2) + 42) & 63;
  int stage_v_255_2 = ((pub_r001535_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001535_17_1 * 2) + 29) & 63;
  int stage_v_256_2 = ((pub_r001535_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((stage_v_160_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_160_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((pub_r001535_3_1 * 2) + 7) & 63;
  int stage_v_258_2 = ((pub_r001535_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001535_11_1 * 2) + 32) & 63;
  int stage_v_259_2 = ((pub_r001535_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((stage_v_132_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_132_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((helper_flow_4_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_261_2 = ((helper_flow_4_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((stage_v_138_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_138_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((pub_r001535_17_1 * 2) + 27) & 63;
  int stage_v_263_2 = ((pub_r001535_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001535_19_1 * 2) + 5) & 63;
  int stage_v_264_2 = ((pub_r001535_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001535_20_1 * 2) + 50) & 63;
  int stage_v_265_2 = ((pub_r001535_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001535_17_1 * 2) + 17) & 63;
  int stage_v_266_2 = ((pub_r001535_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_62_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_62_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_268_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_268_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_268_2 + 1) & 15;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = ((stage_v_204_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_204_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((pub_r001535_6_1 * 2) + 8) & 63;
  int stage_v_270_2 = ((pub_r001535_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((stage_v_153_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_153_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((stage_v_123_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_123_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_153_1 << 1) ^ (pub_r001535_11_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_153_2 << 1) ^ (pub_r001535_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_90_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_90_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_230_1 << 1) ^ (pub_r001535_19_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_230_2 << 1) ^ (pub_r001535_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_176_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_176_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_186_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_186_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001535_9_1 * 2) + 41) & 63;
  int stage_v_278_2 = ((pub_r001535_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001535_3_1 * 2) + 46) & 63;
  int stage_v_279_2 = ((pub_r001535_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001535_15_1 * 2) + 45) & 63;
  int stage_v_280_2 = ((pub_r001535_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001535_1_1 * 2) + 8) & 63;
  int stage_v_281_2 = ((pub_r001535_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001535_17_1 * 2) + 16) & 63;
  int stage_v_282_2 = ((pub_r001535_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001535_5_1 * 2) + 9) & 63;
  int stage_v_283_2 = ((pub_r001535_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001535_13_1 * 2) + 21) & 63;
  int stage_v_284_2 = ((pub_r001535_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001535_16_1 * 2) + 40) & 63;
  int stage_v_285_2 = ((pub_r001535_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001535_2_1 * 2) + 16) & 63;
  int stage_v_286_2 = ((pub_r001535_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_121_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_121_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001535_13_1 * 2) + 9) & 63;
  int stage_v_288_2 = ((pub_r001535_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_97_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_97_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((pub_r001535_2_1 * 2) + 49) & 63;
  int stage_v_290_2 = ((pub_r001535_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((stage_v_271_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_271_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((pub_r001535_14_1 * 2) + 35) & 63;
  int stage_v_292_2 = ((pub_r001535_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001535_12_1 * 2) + 9) & 63;
  int stage_v_293_2 = ((pub_r001535_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001535_17_1 * 2) + 41) & 63;
  int stage_v_294_2 = ((pub_r001535_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((sec_r001535_15_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_295_2 = ((sec_r001535_15_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001535_17_1 * 2) + 34) & 63;
  int stage_v_296_2 = ((pub_r001535_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001535_17_1 * 2) + 48) & 63;
  int stage_v_297_2 = ((pub_r001535_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((stage_v_109_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_109_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_74_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_74_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((pub_r001535_8_1 * 2) + 7) & 63;
  int stage_v_300_2 = ((pub_r001535_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_236_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_236_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((pub_r001535_1_1 * 2) + 17) & 63;
  int stage_v_302_2 = ((pub_r001535_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((helper_flow_4_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_303_2 = ((helper_flow_4_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001535_17_1 * 2) + 5) & 63;
  int stage_v_304_2 = ((pub_r001535_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((stage_v_64_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_64_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((stage_v_78_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_78_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((sec_r001535_3_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_307_2 = ((sec_r001535_3_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((stage_v_54_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_54_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_248_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_248_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((pub_r001535_11_1 * 2) + 17) & 63;
  int stage_v_310_2 = ((pub_r001535_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((stage_v_253_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_253_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_23_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_23_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_260_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_260_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001535_1_1 * 2) + 16) & 63;
  int stage_v_314_2 = ((pub_r001535_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((sec_r001535_15_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_315_2 = ((sec_r001535_15_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((pub_r001535_2_1 * 2) + 16) & 63;
  int stage_v_316_2 = ((pub_r001535_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001535_3_1 * 2) + 44) & 63;
  int stage_v_317_2 = ((pub_r001535_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((stage_v_272_1 << 1) ^ (pub_r001535_9_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_272_2 << 1) ^ (pub_r001535_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_160_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_160_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001535_14_1 * 2) + 47) & 63;
  int stage_v_321_2 = ((pub_r001535_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001535_2_1 * 2) + 21) & 63;
  int stage_v_322_2 = ((pub_r001535_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((sec_r001535_16_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_323_2 = ((sec_r001535_16_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((stage_v_224_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_224_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001535_16_1 * 2) + 28) & 63;
  int stage_v_326_2 = ((pub_r001535_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((sec_r001535_18_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_327_2 = ((sec_r001535_18_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((stage_v_180_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_180_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((pub_r001535_11_1 * 2) + 15) & 63;
  int stage_v_329_2 = ((pub_r001535_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((sec_r001535_7_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_330_2 = ((sec_r001535_7_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_195_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_195_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((pub_r001535_19_1 * 2) + 43) & 63;
  int stage_v_332_2 = ((pub_r001535_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001535_8_1 * 2) + 26) & 63;
  int stage_v_333_2 = ((pub_r001535_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001535_8_1 * 2) + 31) & 63;
  int stage_v_334_2 = ((pub_r001535_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_312_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_312_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((stage_v_12_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_12_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001535_11_1 * 2) + 27) & 63;
  int stage_v_337_2 = ((pub_r001535_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_211_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_211_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((stage_v_96_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_96_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((stage_v_35_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_35_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_98_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_98_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((pub_r001535_5_1 * 2) + 44) & 63;
  int stage_v_342_2 = ((pub_r001535_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((sec_r001535_20_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_343_2 = ((sec_r001535_20_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001535_9_1 * 2) + 5) & 63;
  int stage_v_344_2 = ((pub_r001535_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001535_0_1 * 2) + 49) & 63;
  int stage_v_345_2 = ((pub_r001535_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001535_15_1 * 2) + 14) & 63;
  int stage_v_346_2 = ((pub_r001535_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001535_15_1 * 2) + 14) & 63;
  int stage_v_347_2 = ((pub_r001535_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((sec_r001535_17_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_348_2 = ((sec_r001535_17_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((sec_r001535_6_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_349_2 = ((sec_r001535_6_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_306_1 << 1) ^ (pub_r001535_14_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_306_2 << 1) ^ (pub_r001535_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_289_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_289_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((pub_r001535_5_1 * 2) + 48) & 63;
  int stage_v_352_2 = ((pub_r001535_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001535_16_1 * 2) + 36) & 63;
  int stage_v_353_2 = ((pub_r001535_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((stage_v_97_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_97_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((pub_r001535_19_1 * 2) + 10) & 63;
  int stage_v_355_2 = ((pub_r001535_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((stage_v_236_1 << 1) ^ (pub_r001535_2_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_236_2 << 1) ^ (pub_r001535_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((pub_r001535_9_1 * 2) + 11) & 63;
  int stage_v_357_2 = ((pub_r001535_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((stage_v_318_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_318_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((pub_r001535_19_1 * 2) + 18) & 63;
  int stage_v_359_2 = ((pub_r001535_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((stage_v_354_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_354_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((helper_flow_1_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_361_2 = ((helper_flow_1_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_361_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_361_2 + 1) & 15;
  out_sink_1 ^= stage_v_361_1 & 63;
  out_sink_2 ^= stage_v_361_2 & 63;
  int stage_v_362_1 = ((stage_v_209_1 << 1) ^ (pub_r001535_15_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_209_2 << 1) ^ (pub_r001535_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_28_1 << 1) ^ (pub_r001535_16_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_28_2 << 1) ^ (pub_r001535_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_79_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_79_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((pub_r001535_4_1 * 2) + 6) & 63;
  int stage_v_365_2 = ((pub_r001535_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001535_17_1 * 2) + 43) & 63;
  int stage_v_367_2 = ((pub_r001535_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001535_19_1 * 2) + 33) & 63;
  int stage_v_368_2 = ((pub_r001535_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001535_2_1 * 2) + 40) & 63;
  int stage_v_369_2 = ((pub_r001535_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_221_1 << 1) ^ (pub_r001535_2_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_221_2 << 1) ^ (pub_r001535_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001535_6_1 * 2) + 50) & 63;
  int stage_v_371_2 = ((pub_r001535_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((stage_v_184_1 << 1) ^ (pub_r001535_8_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_184_2 << 1) ^ (pub_r001535_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001535_4_1 * 2) + 27) & 63;
  int stage_v_373_2 = ((pub_r001535_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((stage_v_19_1 << 1) ^ (pub_r001535_10_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_19_2 << 1) ^ (pub_r001535_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001535_10_1 * 2) + 50) & 63;
  int stage_v_375_2 = ((pub_r001535_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001535_5_1 * 2) + 24) & 63;
  int stage_v_376_2 = ((pub_r001535_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_46_1 << 1) ^ (pub_r001535_4_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_46_2 << 1) ^ (pub_r001535_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_45_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_45_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_351_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_351_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_62_1 << 1) ^ (pub_r001535_12_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_62_2 << 1) ^ (pub_r001535_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_273_1 << 1) ^ (pub_r001535_18_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_273_2 << 1) ^ (pub_r001535_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_224_1 << 1) ^ (pub_r001535_0_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_224_2 << 1) ^ (pub_r001535_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_298_1 << 1) ^ (pub_r001535_20_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_298_2 << 1) ^ (pub_r001535_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((stage_v_22_1 << 1) ^ (pub_r001535_7_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_22_2 << 1) ^ (pub_r001535_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((sec_r001535_4_1 << 1) ^ (pub_r001535_17_1 >> 1)) & 127;
  int stage_v_385_2 = ((sec_r001535_4_2 << 1) ^ (pub_r001535_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_115_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_115_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((pub_r001535_14_1 * 2) + 13) & 63;
  int stage_v_387_2 = ((pub_r001535_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((stage_v_128_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_388_2 = ((stage_v_128_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_388_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_388_2 + 1) & 15;
  out_sink_1 ^= stage_v_388_1 & 63;
  out_sink_2 ^= stage_v_388_2 & 63;
  int stage_v_389_1 = ((stage_v_88_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_88_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001535_7_1 * 2) + 21) & 63;
  int stage_v_390_2 = ((pub_r001535_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_324_1 << 1) ^ (pub_r001535_13_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_324_2 << 1) ^ (pub_r001535_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((pub_r001535_1_1 * 2) + 37) & 63;
  int stage_v_392_2 = ((pub_r001535_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((stage_v_107_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_107_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((stage_v_2_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_2_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001535_11_1 * 2) + 21) & 63;
  int stage_v_395_2 = ((pub_r001535_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001535_18_1 * 2) + 30) & 63;
  int stage_v_396_2 = ((pub_r001535_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((stage_v_216_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_216_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((pub_r001535_19_1 * 2) + 49) & 63;
  int stage_v_398_2 = ((pub_r001535_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001535_11_1 * 2) + 22) & 63;
  int stage_v_399_2 = ((pub_r001535_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((stage_v_356_1 << 1) ^ (pub_r001535_3_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_356_2 << 1) ^ (pub_r001535_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((pub_r001535_4_1 * 2) + 5) & 63;
  int stage_v_401_2 = ((pub_r001535_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001535_13_1 * 2) + 38) & 63;
  int stage_v_402_2 = ((pub_r001535_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001535_5_1 * 2) + 26) & 63;
  int stage_v_403_2 = ((pub_r001535_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((stage_v_305_1 << 1) ^ (pub_r001535_5_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_305_2 << 1) ^ (pub_r001535_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001535_14_1 * 2) + 39) & 63;
  int stage_v_405_2 = ((pub_r001535_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_358_1 << 1) ^ (pub_r001535_6_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_358_2 << 1) ^ (pub_r001535_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((stage_v_184_1 << 1) ^ (pub_r001535_1_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_184_2 << 1) ^ (pub_r001535_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001535_5_1 != sec_r001535_5_2);
  __CPROVER_assume(pub_r001535_1_1 == pub_r001535_1_2);
  __CPROVER_assume(sec_r001535_20_1 != sec_r001535_20_2);
  __CPROVER_assume(sec_r001535_13_1 != sec_r001535_13_2);
  __CPROVER_assume(sec_r001535_0_1 != sec_r001535_0_2);
  __CPROVER_assume(pub_r001535_4_1 == pub_r001535_4_2);
  __CPROVER_assume(pub_r001535_5_1 == pub_r001535_5_2);
  __CPROVER_assume(sec_r001535_18_1 != sec_r001535_18_2);
  __CPROVER_assume(sec_r001535_14_1 != sec_r001535_14_2);
  __CPROVER_assume(pub_r001535_10_1 == pub_r001535_10_2);
  __CPROVER_assume(sec_r001535_15_1 != sec_r001535_15_2);
  __CPROVER_assume(pub_r001535_7_1 == pub_r001535_7_2);
  __CPROVER_assume(pub_r001535_20_1 == pub_r001535_20_2);
  __CPROVER_assume(pub_r001535_15_1 == pub_r001535_15_2);
  __CPROVER_assume(pub_r001535_8_1 == pub_r001535_8_2);
  __CPROVER_assume(pub_r001535_14_1 == pub_r001535_14_2);
  __CPROVER_assume(pub_r001535_17_1 == pub_r001535_17_2);
  __CPROVER_assume(pub_r001535_16_1 == pub_r001535_16_2);
  __CPROVER_assume(pub_r001535_11_1 == pub_r001535_11_2);
  __CPROVER_assume(sec_r001535_7_1 != sec_r001535_7_2);
  __CPROVER_assume(sec_r001535_2_1 != sec_r001535_2_2);
  __CPROVER_assume(sec_r001535_11_1 != sec_r001535_11_2);
  __CPROVER_assume(sec_r001535_3_1 != sec_r001535_3_2);
  __CPROVER_assume(sec_r001535_6_1 != sec_r001535_6_2);
  __CPROVER_assume(sec_r001535_17_1 != sec_r001535_17_2);
  __CPROVER_assume(pub_r001535_2_1 == pub_r001535_2_2);
  __CPROVER_assume(pub_r001535_18_1 == pub_r001535_18_2);
  __CPROVER_assume(sec_r001535_10_1 != sec_r001535_10_2);
  __CPROVER_assume(pub_r001535_19_1 == pub_r001535_19_2);
  __CPROVER_assume(pub_r001535_6_1 == pub_r001535_6_2);
  __CPROVER_assume(pub_r001535_3_1 == pub_r001535_3_2);
  __CPROVER_assume(pub_r001535_9_1 == pub_r001535_9_2);
  __CPROVER_assume(pub_r001535_13_1 == pub_r001535_13_2);
  __CPROVER_assume(sec_r001535_9_1 != sec_r001535_9_2);
  __CPROVER_assume(sec_r001535_19_1 != sec_r001535_19_2);
  __CPROVER_assume(sec_r001535_16_1 != sec_r001535_16_2);
  __CPROVER_assume(pub_r001535_12_1 == pub_r001535_12_2);
  __CPROVER_assume(pub_r001535_0_1 == pub_r001535_0_2);
  __CPROVER_assume(sec_r001535_4_1 != sec_r001535_4_2);
  __CPROVER_assume(sec_r001535_12_1 != sec_r001535_12_2);
  __CPROVER_assume(sec_r001535_8_1 != sec_r001535_8_2);
  __CPROVER_assume(sec_r001535_1_1 != sec_r001535_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.density == st_var_1_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
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
}


