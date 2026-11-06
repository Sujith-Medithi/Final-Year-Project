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
struct Vector3D_R000566_6613_0
{
  int coord_y;
  unsigned char coord_x;
  int norm_sq;
  int coord_z;
  int buffer[3];
};
struct DeviceConfig_R000566_6613_1
{
  short stop_bits;
  short parity;
  short baud_rate;
  short timeout;
  unsigned char port;
  int id;
  int buffer[3];
};
struct FilterState_R000566_6613_2
{
  int prev_in;
  unsigned char damping;
  short cutoff;
  unsigned char mode;
  unsigned char prev_out;
  short gain_db;
  int buffer[3];
};
union PacketPayload_R000566_6613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000566_6613_1
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
void fn_R000566_6613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_45_1) & 63;
  aux_2 = (aux_2 + sample_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_45_1 == sample_45_2);
}

int fn_R000566_6613_0(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_64_1 = local_arr_1[aux_1 % 3];
  int residue_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_64_2 * 2)) & 127;
  int segment_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_92_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_92_1 * 2)) + 5) & 127;
    aux_1 ^= segment_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_92_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_92_2 * 2)) + 5) & 127;
    aux_2 ^= segment_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_64_1 == residue_64_2);
  assert(segment_92_1 == segment_92_2);
}

int fn_R000566_6613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int residue_64 = local_arr[aux % 3];
  acc = (acc + (residue_64 * 2)) & 127;
  int segment_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_92 > 24)
  {
    acc = ((acc + (segment_92 * 2)) + 5) & 127;
    aux ^= segment_92 & 15;
  }
  else
  {
    acc = ((acc - segment_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000566_6613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_95_1)
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

  switch (sample_95_2)
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

  int window_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_79_1 > 48)
  {
    acc_1 = ((acc_1 + (window_79_1 * 2)) + 5) & 127;
    aux_1 ^= window_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_79_2 > 48)
  {
    acc_2 = ((acc_2 + (window_79_2 * 2)) + 5) & 127;
    aux_2 ^= window_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_79_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_95_1) & 63;
  aux_2 = (aux_2 + metric_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_95_1 == sample_95_2);
  assert(window_79_1 == window_79_2);
  assert(metric_95_1 == metric_95_2);
}

int fn_R000566_6613_2(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_95 = (aux + st.buffer[1]) & 3;
  switch (sample_95)
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

  int window_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_79 > 48)
  {
    acc = ((acc + (window_79 * 2)) + 5) & 127;
    aux ^= window_79 & 15;
  }
  else
  {
    acc = ((acc - window_79) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int coefficient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_63_1 > 39)
  {
    acc_1 = ((acc_1 + (coefficient_63_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_63_2 > 39)
  {
    acc_2 = ((acc_2 + (coefficient_63_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_65_1)
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

  switch (quantum_65_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_63_1 == coefficient_63_2);
  assert(quantum_65_1 == quantum_65_2);
}

int fn_R000566_6613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int coefficient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_63 > 39)
  {
    acc = ((acc + (coefficient_63 * 2)) + 5) & 127;
    aux ^= coefficient_63 & 15;
  }
  else
  {
    acc = ((acc - coefficient_63) + 11) & 127;
    aux += 3;
  }
  int quantum_65 = (aux + st.buffer[1]) & 3;
  switch (quantum_65)
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

void fn_R000566_6613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_99_1)
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

  switch (tally_99_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_89_1 > 37)
  {
    acc_1 = ((acc_1 + (window_89_1 * 2)) + 5) & 127;
    aux_1 ^= window_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_89_2 > 37)
  {
    acc_2 = ((acc_2 + (window_89_2 * 2)) + 5) & 127;
    aux_2 ^= window_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_84_1) & 63;
  aux_2 = (aux_2 + tally_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_99_1 == tally_99_2);
  assert(window_89_1 == window_89_2);
  assert(tally_84_1 == tally_84_2);
}

int fn_R000566_6613_4(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_99 = (aux + st.buffer[1]) & 3;
  switch (tally_99)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_89 > 37)
  {
    acc = ((acc + (window_89 * 2)) + 5) & 127;
    aux ^= window_89 & 15;
  }
  else
  {
    acc = ((acc - window_89) + 11) & 127;
    aux += 3;
  }
  int tally_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_14_1 = local_arr_1[aux_1 % 3];
  int margin_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_14_2 * 2)) & 127;
  int index_reg_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_71_1) & 63;
  aux_2 = (aux_2 + index_reg_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_10_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_10_1 * 2)) + 5) & 127;
    aux_1 ^= offset_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_10_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_10_2 * 2)) + 5) & 127;
    aux_2 ^= offset_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_25_1)
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

  switch (anchor_25_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_14_1 == margin_14_2);
  assert(index_reg_71_1 == index_reg_71_2);
  assert(offset_10_1 == offset_10_2);
  assert(anchor_25_1 == anchor_25_2);
}

int fn_R000566_6613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int margin_14 = local_arr[aux % 3];
  acc = (acc + (margin_14 * 2)) & 127;
  int index_reg_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_71) & 63;
  acc ^= aux;
  int offset_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_10 > 24)
  {
    acc = ((acc + (offset_10 * 2)) + 5) & 127;
    aux ^= offset_10 & 15;
  }
  else
  {
    acc = ((acc - offset_10) + 11) & 127;
    aux += 3;
  }
  int anchor_25 = (aux + st.buffer[1]) & 3;
  switch (anchor_25)
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

void fn_R000566_6613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_30_1)
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

  switch (quotient_30_2)
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

  int factor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_94_1) & 63;
  aux_2 = (aux_2 + factor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_31_1 > 43)
  {
    acc_1 = ((acc_1 + (cursor_31_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_31_2 > 43)
  {
    acc_2 = ((acc_2 + (cursor_31_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_84_1 = local_arr_1[aux_1 % 3];
  int metric_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_30_1 == quotient_30_2);
  assert(factor_94_1 == factor_94_2);
  assert(cursor_31_1 == cursor_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_84_1 == metric_84_2);
}

int fn_R000566_6613_6(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_30 = (aux + st.buffer[1]) & 3;
  switch (quotient_30)
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

  int factor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_94) & 63;
  acc ^= aux;
  int cursor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_31 > 43)
  {
    acc = ((acc + (cursor_31 * 2)) + 5) & 127;
    aux ^= cursor_31 & 15;
  }
  else
  {
    acc = ((acc - cursor_31) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_84 = local_arr[aux % 3];
  acc = (acc + (metric_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000566_6613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st_1 = {0};
  struct FilterState_R000566_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_88_1)
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

  switch (stride_88_2)
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
  int margin_13_1 = local_arr_1[aux_1 % 3];
  int margin_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_13_2 * 2)) & 127;
  int window_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_88_1) & 63;
  aux_2 = (aux_2 + window_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_88_1 == stride_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_13_1 == margin_13_2);
  assert(window_88_1 == window_88_2);
}

int fn_R000566_6613_7(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_88 = (aux + st.buffer[1]) & 3;
  switch (stride_88)
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
  int margin_13 = local_arr[aux % 3];
  acc = (acc + (margin_13 * 2)) & 127;
  int window_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_23_1 = local_arr_1[aux_1 % 3];
  int damping_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_23_2 * 2)) & 127;
  int segment_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_66_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_66_1 * 2)) + 5) & 127;
    aux_1 ^= segment_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_66_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_66_2 * 2)) + 5) & 127;
    aux_2 ^= segment_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_68_1)
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

  switch (residue_68_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_23_1 == damping_23_2);
  assert(segment_66_1 == segment_66_2);
  assert(residue_68_1 == residue_68_2);
}

int fn_R000566_6613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int damping_23 = local_arr[aux % 3];
  acc = (acc + (damping_23 * 2)) & 127;
  int segment_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_66 > 24)
  {
    acc = ((acc + (segment_66 * 2)) + 5) & 127;
    aux ^= segment_66 & 15;
  }
  else
  {
    acc = ((acc - segment_66) + 11) & 127;
    aux += 3;
  }
  int residue_68 = (aux + st.buffer[1]) & 3;
  switch (residue_68)
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

void fn_R000566_6613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_81_1)
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

  switch (tracker_81_2)
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
  int cursor_21_1 = local_arr_1[aux_1 % 3];
  int cursor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_21_2 * 2)) & 127;
  int mask_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_41_1) & 63;
  aux_2 = (aux_2 + mask_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_81_1 == tracker_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(mask_41_1 == mask_41_2);
}

int fn_R000566_6613_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_81 = (aux + st.buffer[1]) & 3;
  switch (tracker_81)
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
  int cursor_21 = local_arr[aux % 3];
  acc = (acc + (cursor_21 * 2)) & 127;
  int mask_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_86_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_86_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_86_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_86_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_84_1) & 63;
  aux_2 = (aux_2 + quotient_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_81_1 = local_arr_1[aux_1 % 3];
  int segment_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_81_2 * 2)) & 127;
  int stride_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_73_1)
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

  switch (stride_73_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_86_1 == quotient_86_2);
  assert(quotient_84_1 == quotient_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_81_1 == segment_81_2);
  assert(stride_73_1 == stride_73_2);
}

int fn_R000566_6613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_86 > 13)
  {
    acc = ((acc + (quotient_86 * 2)) + 5) & 127;
    aux ^= quotient_86 & 15;
  }
  else
  {
    acc = ((acc - quotient_86) + 11) & 127;
    aux += 3;
  }
  int quotient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_81 = local_arr[aux % 3];
  acc = (acc + (segment_81 * 2)) & 127;
  int stride_73 = (aux + st.buffer[1]) & 3;
  switch (stride_73)
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

void fn_R000566_6613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_76_1 = local_arr_1[aux_1 % 3];
  int offset_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_76_1 == offset_76_2);
}

int fn_R000566_6613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_76 = local_arr[aux % 3];
  acc = (acc + (offset_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000566_6613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_74_1 = local_arr_1[aux_1 % 3];
  int checksum_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_74_2 * 2)) & 127;
  int coefficient_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_99_1 > 19)
  {
    acc_1 = ((acc_1 + (coefficient_99_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_99_2 > 19)
  {
    acc_2 = ((acc_2 + (coefficient_99_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_21_1) & 63;
  aux_2 = (aux_2 + vector_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_74_1 == checksum_74_2);
  assert(coefficient_99_1 == coefficient_99_2);
  assert(vector_21_1 == vector_21_2);
}

int fn_R000566_6613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000566_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_74 = local_arr[aux % 3];
  acc = (acc + (checksum_74 * 2)) & 127;
  int coefficient_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_99 > 19)
  {
    acc = ((acc + (coefficient_99 * 2)) + 5) & 127;
    aux ^= coefficient_99 & 15;
  }
  else
  {
    acc = ((acc - coefficient_99) + 11) & 127;
    aux += 3;
  }
  int vector_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_50_1)
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

  switch (segment_50_2)
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

  int phase_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_17_1 > 38)
  {
    acc_1 = ((acc_1 + (phase_17_1 * 2)) + 5) & 127;
    aux_1 ^= phase_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_17_2 > 38)
  {
    acc_2 = ((acc_2 + (phase_17_2 * 2)) + 5) & 127;
    aux_2 ^= phase_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_47_1) & 63;
  aux_2 = (aux_2 + damping_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_50_1 == segment_50_2);
  assert(phase_17_1 == phase_17_2);
  assert(damping_47_1 == damping_47_2);
}

int fn_R000566_6613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_50 = (aux + st.buffer[1]) & 3;
  switch (segment_50)
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

  int phase_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_17 > 38)
  {
    acc = ((acc + (phase_17 * 2)) + 5) & 127;
    aux ^= phase_17 & 15;
  }
  else
  {
    acc = ((acc - phase_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st_1 = {0};
  struct FilterState_R000566_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int margin_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_28_1 > 37)
  {
    acc_1 = ((acc_1 + (margin_28_1 * 2)) + 5) & 127;
    aux_1 ^= margin_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_28_2 > 37)
  {
    acc_2 = ((acc_2 + (margin_28_2 * 2)) + 5) & 127;
    aux_2 ^= margin_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_28_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_31_1)
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

  switch (residue_31_2)
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
  int coefficient_39_1 = local_arr_1[aux_1 % 3];
  int coefficient_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_28_1 == margin_28_2);
  assert(residue_31_1 == residue_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R000566_6613_14(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int margin_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_28 > 37)
  {
    acc = ((acc + (margin_28 * 2)) + 5) & 127;
    aux ^= margin_28 & 15;
  }
  else
  {
    acc = ((acc - margin_28) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_31 = (aux + st.buffer[1]) & 3;
  switch (residue_31)
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
  int coefficient_39 = local_arr[aux % 3];
  acc = (acc + (coefficient_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000566_6613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st_1 = {0};
  struct FilterState_R000566_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_58_1)
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

  switch (anchor_58_2)
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

  int offset_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_17_1 > 19)
  {
    acc_1 = ((acc_1 + (offset_17_1 * 2)) + 5) & 127;
    aux_1 ^= offset_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_17_2 > 19)
  {
    acc_2 = ((acc_2 + (offset_17_2 * 2)) + 5) & 127;
    aux_2 ^= offset_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_92_1) & 63;
  aux_2 = (aux_2 + sample_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_58_1 == anchor_58_2);
  assert(offset_17_1 == offset_17_2);
  assert(sample_92_1 == sample_92_2);
}

int fn_R000566_6613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_58 = (aux + st.buffer[1]) & 3;
  switch (anchor_58)
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

  int offset_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_17 > 19)
  {
    acc = ((acc + (offset_17 * 2)) + 5) & 127;
    aux ^= offset_17 & 15;
  }
  else
  {
    acc = ((acc - offset_17) + 11) & 127;
    aux += 3;
  }
  int sample_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st_1 = {0};
  struct FilterState_R000566_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int phase_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_11_1)
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

  switch (phase_11_2)
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

  int scale_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_97_1) & 63;
  aux_2 = (aux_2 + scale_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_11_1 == phase_11_2);
  assert(scale_97_1 == scale_97_2);
}

int fn_R000566_6613_16(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000566_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int phase_11 = (aux + st.buffer[1]) & 3;
  switch (phase_11)
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

  int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000566_6613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st_1 = {0};
  struct Vector3D_R000566_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_56_1 > 20)
  {
    acc_1 = ((acc_1 + (margin_56_1 * 2)) + 5) & 127;
    aux_1 ^= margin_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_56_2 > 20)
  {
    acc_2 = ((acc_2 + (margin_56_2 * 2)) + 5) & 127;
    aux_2 ^= margin_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_75_1) & 63;
  aux_2 = (aux_2 + damping_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_79_1 = local_arr_1[aux_1 % 3];
  int metric_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  assert(damping_75_1 == damping_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_79_1 == metric_79_2);
}

int fn_R000566_6613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000566_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_56 > 20)
  {
    acc = ((acc + (margin_56 * 2)) + 5) & 127;
    aux ^= margin_56 & 15;
  }
  else
  {
    acc = ((acc - margin_56) + 11) & 127;
    aux += 3;
  }
  int damping_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_79 = local_arr[aux % 3];
  acc = (acc + (metric_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000566_0_1;
  int sec_r000566_0_2;
  int sec_r000566_1_1;
  int sec_r000566_1_2;
  int sec_r000566_2_1;
  int sec_r000566_2_2;
  int sec_r000566_3_1;
  int sec_r000566_3_2;
  int sec_r000566_4_1;
  int sec_r000566_4_2;
  int sec_r000566_5_1;
  int sec_r000566_5_2;
  int sec_r000566_6_1;
  int sec_r000566_6_2;
  int sec_r000566_7_1;
  int sec_r000566_7_2;
  int sec_r000566_8_1;
  int sec_r000566_8_2;
  int sec_r000566_9_1;
  int sec_r000566_9_2;
  int sec_r000566_10_1;
  int sec_r000566_10_2;
  int sec_r000566_11_1;
  int sec_r000566_11_2;
  int sec_r000566_12_1;
  int sec_r000566_12_2;
  int sec_r000566_13_1;
  int sec_r000566_13_2;
  int sec_r000566_14_1;
  int sec_r000566_14_2;
  int sec_r000566_15_1;
  int sec_r000566_15_2;
  int pub_r000566_0_1;
  int pub_r000566_0_2;
  int pub_r000566_1_1;
  int pub_r000566_1_2;
  int pub_r000566_2_1;
  int pub_r000566_2_2;
  int pub_r000566_3_1;
  int pub_r000566_3_2;
  int pub_r000566_4_1;
  int pub_r000566_4_2;
  int pub_r000566_5_1;
  int pub_r000566_5_2;
  int pub_r000566_6_1;
  int pub_r000566_6_2;
  int pub_r000566_7_1;
  int pub_r000566_7_2;
  int pub_r000566_8_1;
  int pub_r000566_8_2;
  int pub_r000566_9_1;
  int pub_r000566_9_2;
  int pub_r000566_10_1;
  int pub_r000566_10_2;
  int pub_r000566_11_1;
  int pub_r000566_11_2;
  int pub_r000566_12_1;
  int pub_r000566_12_2;
  int pub_r000566_13_1;
  int pub_r000566_13_2;
  int pub_r000566_14_1;
  int pub_r000566_14_2;
  int pub_r000566_15_1;
  int pub_r000566_15_2;
  int pub_r000566_16_1;
  int pub_r000566_16_2;
  int pub_r000566_17_1;
  int pub_r000566_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000566_0_1 >= (-100)) && (pub_r000566_0_1 <= 100));
  __CPROVER_assume((pub_r000566_0_2 >= (-100)) && (pub_r000566_0_2 <= 100));
  __CPROVER_assume((pub_r000566_1_1 >= (-100)) && (pub_r000566_1_1 <= 100));
  __CPROVER_assume((pub_r000566_1_2 >= (-100)) && (pub_r000566_1_2 <= 100));
  __CPROVER_assume((pub_r000566_2_1 >= (-100)) && (pub_r000566_2_1 <= 100));
  __CPROVER_assume((pub_r000566_2_2 >= (-100)) && (pub_r000566_2_2 <= 100));
  __CPROVER_assume((pub_r000566_3_1 >= (-100)) && (pub_r000566_3_1 <= 100));
  __CPROVER_assume((pub_r000566_3_2 >= (-100)) && (pub_r000566_3_2 <= 100));
  __CPROVER_assume((pub_r000566_4_1 >= (-100)) && (pub_r000566_4_1 <= 100));
  __CPROVER_assume((pub_r000566_4_2 >= (-100)) && (pub_r000566_4_2 <= 100));
  __CPROVER_assume((pub_r000566_5_1 >= (-100)) && (pub_r000566_5_1 <= 100));
  __CPROVER_assume((pub_r000566_5_2 >= (-100)) && (pub_r000566_5_2 <= 100));
  __CPROVER_assume((pub_r000566_6_1 >= (-100)) && (pub_r000566_6_1 <= 100));
  __CPROVER_assume((pub_r000566_6_2 >= (-100)) && (pub_r000566_6_2 <= 100));
  __CPROVER_assume((pub_r000566_7_1 >= (-100)) && (pub_r000566_7_1 <= 100));
  __CPROVER_assume((pub_r000566_7_2 >= (-100)) && (pub_r000566_7_2 <= 100));
  __CPROVER_assume((pub_r000566_8_1 >= (-100)) && (pub_r000566_8_1 <= 100));
  __CPROVER_assume((pub_r000566_8_2 >= (-100)) && (pub_r000566_8_2 <= 100));
  __CPROVER_assume((pub_r000566_9_1 >= (-100)) && (pub_r000566_9_1 <= 100));
  __CPROVER_assume((pub_r000566_9_2 >= (-100)) && (pub_r000566_9_2 <= 100));
  __CPROVER_assume((pub_r000566_10_1 >= (-100)) && (pub_r000566_10_1 <= 100));
  __CPROVER_assume((pub_r000566_10_2 >= (-100)) && (pub_r000566_10_2 <= 100));
  __CPROVER_assume((pub_r000566_11_1 >= (-100)) && (pub_r000566_11_1 <= 100));
  __CPROVER_assume((pub_r000566_11_2 >= (-100)) && (pub_r000566_11_2 <= 100));
  __CPROVER_assume((pub_r000566_12_1 >= (-100)) && (pub_r000566_12_1 <= 100));
  __CPROVER_assume((pub_r000566_12_2 >= (-100)) && (pub_r000566_12_2 <= 100));
  __CPROVER_assume((pub_r000566_13_1 >= (-100)) && (pub_r000566_13_1 <= 100));
  __CPROVER_assume((pub_r000566_13_2 >= (-100)) && (pub_r000566_13_2 <= 100));
  __CPROVER_assume((pub_r000566_14_1 >= (-100)) && (pub_r000566_14_1 <= 100));
  __CPROVER_assume((pub_r000566_14_2 >= (-100)) && (pub_r000566_14_2 <= 100));
  __CPROVER_assume((pub_r000566_15_1 >= (-100)) && (pub_r000566_15_1 <= 100));
  __CPROVER_assume((pub_r000566_15_2 >= (-100)) && (pub_r000566_15_2 <= 100));
  __CPROVER_assume((pub_r000566_16_1 >= (-100)) && (pub_r000566_16_1 <= 100));
  __CPROVER_assume((pub_r000566_16_2 >= (-100)) && (pub_r000566_16_2 <= 100));
  __CPROVER_assume((pub_r000566_17_1 >= (-100)) && (pub_r000566_17_1 <= 100));
  __CPROVER_assume((pub_r000566_17_2 >= (-100)) && (pub_r000566_17_2 <= 100));
  __CPROVER_assume((sec_r000566_0_1 >= 0) && (sec_r000566_0_1 <= 255));
  __CPROVER_assume((sec_r000566_0_2 >= 0) && (sec_r000566_0_2 <= 255));
  __CPROVER_assume((sec_r000566_1_1 >= 0) && (sec_r000566_1_1 <= 255));
  __CPROVER_assume((sec_r000566_1_2 >= 0) && (sec_r000566_1_2 <= 255));
  __CPROVER_assume((sec_r000566_2_1 >= 0) && (sec_r000566_2_1 <= 255));
  __CPROVER_assume((sec_r000566_2_2 >= 0) && (sec_r000566_2_2 <= 255));
  __CPROVER_assume((sec_r000566_3_1 >= 0) && (sec_r000566_3_1 <= 255));
  __CPROVER_assume((sec_r000566_3_2 >= 0) && (sec_r000566_3_2 <= 255));
  __CPROVER_assume((sec_r000566_4_1 >= 0) && (sec_r000566_4_1 <= 255));
  __CPROVER_assume((sec_r000566_4_2 >= 0) && (sec_r000566_4_2 <= 255));
  __CPROVER_assume((sec_r000566_5_1 >= 0) && (sec_r000566_5_1 <= 255));
  __CPROVER_assume((sec_r000566_5_2 >= 0) && (sec_r000566_5_2 <= 255));
  __CPROVER_assume((sec_r000566_6_1 >= 0) && (sec_r000566_6_1 <= 255));
  __CPROVER_assume((sec_r000566_6_2 >= 0) && (sec_r000566_6_2 <= 255));
  __CPROVER_assume((sec_r000566_7_1 >= 0) && (sec_r000566_7_1 <= 255));
  __CPROVER_assume((sec_r000566_7_2 >= 0) && (sec_r000566_7_2 <= 255));
  __CPROVER_assume((sec_r000566_8_1 >= 0) && (sec_r000566_8_1 <= 255));
  __CPROVER_assume((sec_r000566_8_2 >= 0) && (sec_r000566_8_2 <= 255));
  __CPROVER_assume((sec_r000566_9_1 >= 0) && (sec_r000566_9_1 <= 255));
  __CPROVER_assume((sec_r000566_9_2 >= 0) && (sec_r000566_9_2 <= 255));
  __CPROVER_assume((sec_r000566_10_1 >= 0) && (sec_r000566_10_1 <= 255));
  __CPROVER_assume((sec_r000566_10_2 >= 0) && (sec_r000566_10_2 <= 255));
  __CPROVER_assume((sec_r000566_11_1 >= 0) && (sec_r000566_11_1 <= 255));
  __CPROVER_assume((sec_r000566_11_2 >= 0) && (sec_r000566_11_2 <= 255));
  __CPROVER_assume((sec_r000566_12_1 >= 0) && (sec_r000566_12_1 <= 255));
  __CPROVER_assume((sec_r000566_12_2 >= 0) && (sec_r000566_12_2 <= 255));
  __CPROVER_assume((sec_r000566_13_1 >= 0) && (sec_r000566_13_1 <= 255));
  __CPROVER_assume((sec_r000566_13_2 >= 0) && (sec_r000566_13_2 <= 255));
  __CPROVER_assume((sec_r000566_14_1 >= 0) && (sec_r000566_14_1 <= 255));
  __CPROVER_assume((sec_r000566_14_2 >= 0) && (sec_r000566_14_2 <= 255));
  __CPROVER_assume((sec_r000566_15_1 >= 0) && (sec_r000566_15_1 <= 255));
  __CPROVER_assume((sec_r000566_15_2 >= 0) && (sec_r000566_15_2 <= 255));
  struct Vector3D_R000566_6613_0 st_var_0_1 = {0};
  struct Vector3D_R000566_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000566_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000566_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000566_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000566_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000566_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000566_0_2 + 7) & 15;
  struct DeviceConfig_R000566_6613_1 st_var_1_1 = {0};
  struct DeviceConfig_R000566_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000566_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000566_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000566_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000566_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000566_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000566_0_2 + 9) & 15;
  struct FilterState_R000566_6613_2 st_var_2_1 = {0};
  struct FilterState_R000566_6613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000566_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000566_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000566_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000566_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000566_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000566_0_2 + 11) & 15;
  union PacketPayload_R000566_6613_0 u_var_1;
  union PacketPayload_R000566_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 26)
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
  if (stage_v_0_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 26)
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 29)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 29)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  if ((sec_r000566_15_1 & 63) > 20)
  {
    stage_v_4_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  }
  else
  {
    stage_v_4_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
  }
  if ((sec_r000566_15_2 & 63) > 20)
  {
    stage_v_4_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  }
  else
  {
    stage_v_4_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  if ((stage_v_4_1 & 63) > 28)
  {
    stage_v_5_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  }
  else
  {
    stage_v_5_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
  }
  if ((stage_v_4_2 & 63) > 28)
  {
    stage_v_5_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  }
  else
  {
    stage_v_5_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  if ((sec_r000566_0_1 & 63) > 58)
  {
    stage_v_6_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  }
  else
  {
    stage_v_6_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
  }
  if ((sec_r000566_0_2 & 63) > 58)
  {
    stage_v_6_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  }
  else
  {
    stage_v_6_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  if ((stage_v_6_1 & 63) > 24)
  {
    stage_v_7_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  }
  else
  {
    stage_v_7_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
  }
  if ((stage_v_6_2 & 63) > 24)
  {
    stage_v_7_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  }
  else
  {
    stage_v_7_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  if ((sec_r000566_12_1 & 63) > 44)
  {
    stage_v_8_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  }
  else
  {
    stage_v_8_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
  }
  if ((sec_r000566_12_2 & 63) > 44)
  {
    stage_v_8_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  }
  else
  {
    stage_v_8_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  if ((sec_r000566_9_1 & 63) > 31)
  {
    stage_v_9_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  }
  else
  {
    stage_v_9_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 31)
  {
    stage_v_9_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  }
  else
  {
    stage_v_9_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  if ((stage_v_6_1 & 63) > 29)
  {
    stage_v_10_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  }
  else
  {
    stage_v_10_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
  }
  if ((stage_v_6_2 & 63) > 29)
  {
    stage_v_10_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  }
  else
  {
    stage_v_10_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  if ((stage_v_8_1 & 63) > 40)
  {
    stage_v_11_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  }
  else
  {
    stage_v_11_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
  }
  if ((stage_v_8_2 & 63) > 40)
  {
    stage_v_11_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  }
  else
  {
    stage_v_11_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  if ((stage_v_8_1 & 63) > 31)
  {
    stage_v_12_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  }
  else
  {
    stage_v_12_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
  }
  if ((stage_v_8_2 & 63) > 31)
  {
    stage_v_12_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  }
  else
  {
    stage_v_12_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  if ((stage_v_10_1 & 63) > 39)
  {
    stage_v_13_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  }
  else
  {
    stage_v_13_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
  }
  if ((stage_v_10_2 & 63) > 39)
  {
    stage_v_13_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  }
  else
  {
    stage_v_13_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  if ((stage_v_10_1 & 63) > 37)
  {
    stage_v_14_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  }
  else
  {
    stage_v_14_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
  }
  if ((stage_v_10_2 & 63) > 37)
  {
    stage_v_14_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  }
  else
  {
    stage_v_14_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((stage_v_9_1 & 63) > 16)
  {
    stage_v_15_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  }
  else
  {
    stage_v_15_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
  }
  if ((stage_v_9_2 & 63) > 16)
  {
    stage_v_15_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  }
  else
  {
    stage_v_15_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_15_1 & 63) > 17)
  {
    stage_v_16_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  }
  else
  {
    stage_v_16_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
  }
  if ((stage_v_15_2 & 63) > 17)
  {
    stage_v_16_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  }
  else
  {
    stage_v_16_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_6_1 & 63) > 36)
  {
    stage_v_17_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  }
  else
  {
    stage_v_17_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
  }
  if ((stage_v_6_2 & 63) > 36)
  {
    stage_v_17_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  }
  else
  {
    stage_v_17_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_14_1 & 63) > 36)
  {
    stage_v_18_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  }
  else
  {
    stage_v_18_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
  }
  if ((stage_v_14_2 & 63) > 36)
  {
    stage_v_18_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  }
  else
  {
    stage_v_18_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((sec_r000566_2_1 & 63) > 21)
  {
    stage_v_19_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  }
  else
  {
    stage_v_19_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
  }
  if ((sec_r000566_2_2 & 63) > 21)
  {
    stage_v_19_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  }
  else
  {
    stage_v_19_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_8_1 & 63) > 57)
  {
    stage_v_20_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  }
  else
  {
    stage_v_20_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
  }
  if ((stage_v_8_2 & 63) > 57)
  {
    stage_v_20_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  }
  else
  {
    stage_v_20_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_12_1 & 63) > 38)
  {
    stage_v_21_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  }
  else
  {
    stage_v_21_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
  }
  if ((stage_v_12_2 & 63) > 38)
  {
    stage_v_21_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  }
  else
  {
    stage_v_21_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_4_1 & 63) > 58)
  {
    stage_v_22_1 = ((pub_r000566_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  }
  else
  {
    stage_v_22_1 = ((pub_r000566_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
  }
  if ((stage_v_4_2 & 63) > 58)
  {
    stage_v_22_2 = ((pub_r000566_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  }
  else
  {
    stage_v_22_2 = ((pub_r000566_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_11_1 & 63) > 39)
  {
    stage_v_23_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  }
  else
  {
    stage_v_23_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
  }
  if ((stage_v_11_2 & 63) > 39)
  {
    stage_v_23_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  }
  else
  {
    stage_v_23_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_22_1 & 63) > 47)
  {
    stage_v_24_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  }
  else
  {
    stage_v_24_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 47)
  {
    stage_v_24_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  }
  else
  {
    stage_v_24_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((sec_r000566_14_1 & 63) > 43)
  {
    stage_v_25_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  }
  else
  {
    stage_v_25_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
  }
  if ((sec_r000566_14_2 & 63) > 43)
  {
    stage_v_25_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  }
  else
  {
    stage_v_25_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_18_1 & 63) > 25)
  {
    stage_v_26_1 = ((pub_r000566_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  }
  else
  {
    stage_v_26_1 = ((pub_r000566_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
  }
  if ((stage_v_18_2 & 63) > 25)
  {
    stage_v_26_2 = ((pub_r000566_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  }
  else
  {
    stage_v_26_2 = ((pub_r000566_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((sec_r000566_11_1 & 63) > 34)
  {
    stage_v_27_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  }
  else
  {
    stage_v_27_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 34)
  {
    stage_v_27_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  }
  else
  {
    stage_v_27_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_14_1 & 63) > 41)
  {
    stage_v_28_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  }
  else
  {
    stage_v_28_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
  }
  if ((stage_v_14_2 & 63) > 41)
  {
    stage_v_28_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  }
  else
  {
    stage_v_28_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_17_1 & 63) > 35)
  {
    stage_v_29_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  }
  else
  {
    stage_v_29_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 35)
  {
    stage_v_29_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  }
  else
  {
    stage_v_29_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000566_0_1 & 63) > 24)
  {
    stage_v_30_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  }
  else
  {
    stage_v_30_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
  }
  if ((sec_r000566_0_2 & 63) > 24)
  {
    stage_v_30_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  }
  else
  {
    stage_v_30_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_9_1 & 63) > 52)
  {
    stage_v_31_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  }
  else
  {
    stage_v_31_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
  }
  if ((stage_v_9_2 & 63) > 52)
  {
    stage_v_31_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  }
  else
  {
    stage_v_31_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_8_1 & 63) > 23)
  {
    stage_v_32_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  }
  else
  {
    stage_v_32_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
  }
  if ((stage_v_8_2 & 63) > 23)
  {
    stage_v_32_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  }
  else
  {
    stage_v_32_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000566_11_1 & 63) > 50)
  {
    stage_v_33_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  }
  else
  {
    stage_v_33_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 50)
  {
    stage_v_33_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  }
  else
  {
    stage_v_33_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000566_2_1 & 63) > 49)
  {
    stage_v_34_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  }
  else
  {
    stage_v_34_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
  }
  if ((sec_r000566_2_2 & 63) > 49)
  {
    stage_v_34_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  }
  else
  {
    stage_v_34_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_14_1 & 63) > 21)
  {
    stage_v_35_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  }
  else
  {
    stage_v_35_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
  }
  if ((stage_v_14_2 & 63) > 21)
  {
    stage_v_35_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  }
  else
  {
    stage_v_35_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_23_1 & 63) > 51)
  {
    stage_v_36_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  }
  else
  {
    stage_v_36_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
  }
  if ((stage_v_23_2 & 63) > 51)
  {
    stage_v_36_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  }
  else
  {
    stage_v_36_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 63) > 39)
  {
    stage_v_37_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  }
  else
  {
    stage_v_37_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
  }
  if ((stage_v_36_2 & 63) > 39)
  {
    stage_v_37_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  }
  else
  {
    stage_v_37_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000566_7_1 & 63) > 21)
  {
    stage_v_38_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  }
  else
  {
    stage_v_38_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
  }
  if ((sec_r000566_7_2 & 63) > 21)
  {
    stage_v_38_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  }
  else
  {
    stage_v_38_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_11_1 & 63) > 34)
  {
    stage_v_39_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  }
  else
  {
    stage_v_39_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
  }
  if ((stage_v_11_2 & 63) > 34)
  {
    stage_v_39_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  }
  else
  {
    stage_v_39_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_28_1 & 63) > 29)
  {
    stage_v_40_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  }
  else
  {
    stage_v_40_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
  }
  if ((stage_v_28_2 & 63) > 29)
  {
    stage_v_40_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  }
  else
  {
    stage_v_40_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000566_10_1 & 63) > 53)
  {
    stage_v_41_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  }
  else
  {
    stage_v_41_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
  }
  if ((sec_r000566_10_2 & 63) > 53)
  {
    stage_v_41_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  }
  else
  {
    stage_v_41_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_16_1 & 63) > 60)
  {
    stage_v_42_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  }
  else
  {
    stage_v_42_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
  }
  if ((stage_v_16_2 & 63) > 60)
  {
    stage_v_42_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  }
  else
  {
    stage_v_42_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000566_7_1 & 63) > 59)
  {
    stage_v_43_1 = ((pub_r000566_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  }
  else
  {
    stage_v_43_1 = ((pub_r000566_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
  }
  if ((sec_r000566_7_2 & 63) > 59)
  {
    stage_v_43_2 = ((pub_r000566_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  }
  else
  {
    stage_v_43_2 = ((pub_r000566_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000566_11_1 & 63) > 34)
  {
    stage_v_44_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  }
  else
  {
    stage_v_44_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 34)
  {
    stage_v_44_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  }
  else
  {
    stage_v_44_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_5_1 & 63) > 19)
  {
    stage_v_45_1 = ((pub_r000566_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  }
  else
  {
    stage_v_45_1 = ((pub_r000566_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
  }
  if ((stage_v_5_2 & 63) > 19)
  {
    stage_v_45_2 = ((pub_r000566_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  }
  else
  {
    stage_v_45_2 = ((pub_r000566_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_18_1 & 63) > 15)
  {
    stage_v_46_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  }
  else
  {
    stage_v_46_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
  }
  if ((stage_v_18_2 & 63) > 15)
  {
    stage_v_46_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  }
  else
  {
    stage_v_46_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_20_1 & 63) > 45)
  {
    stage_v_47_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  }
  else
  {
    stage_v_47_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
  }
  if ((stage_v_20_2 & 63) > 45)
  {
    stage_v_47_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  }
  else
  {
    stage_v_47_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000566_13_1 & 63) > 31)
  {
    stage_v_48_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  }
  else
  {
    stage_v_48_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
  }
  if ((sec_r000566_13_2 & 63) > 31)
  {
    stage_v_48_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  }
  else
  {
    stage_v_48_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_17_1 & 63) > 53)
  {
    stage_v_49_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  }
  else
  {
    stage_v_49_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 53)
  {
    stage_v_49_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  }
  else
  {
    stage_v_49_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_35_1 & 63) > 32)
  {
    stage_v_50_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  }
  else
  {
    stage_v_50_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
  }
  if ((stage_v_35_2 & 63) > 32)
  {
    stage_v_50_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  }
  else
  {
    stage_v_50_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000566_9_1 & 63) > 23)
  {
    stage_v_51_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  }
  else
  {
    stage_v_51_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 23)
  {
    stage_v_51_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  }
  else
  {
    stage_v_51_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000566_15_1 & 63) > 25)
  {
    stage_v_52_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  }
  else
  {
    stage_v_52_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
  }
  if ((sec_r000566_15_2 & 63) > 25)
  {
    stage_v_52_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  }
  else
  {
    stage_v_52_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_50_1 & 63) > 26)
  {
    stage_v_53_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  }
  else
  {
    stage_v_53_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 26)
  {
    stage_v_53_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  }
  else
  {
    stage_v_53_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_52_1 & 63) > 56)
  {
    stage_v_54_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  }
  else
  {
    stage_v_54_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 56)
  {
    stage_v_54_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  }
  else
  {
    stage_v_54_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_26_1 & 63) > 33)
  {
    stage_v_55_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  }
  else
  {
    stage_v_55_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
  }
  if ((stage_v_26_2 & 63) > 33)
  {
    stage_v_55_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  }
  else
  {
    stage_v_55_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000566_6_1 & 63) > 39)
  {
    stage_v_56_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  }
  else
  {
    stage_v_56_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
  }
  if ((sec_r000566_6_2 & 63) > 39)
  {
    stage_v_56_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  }
  else
  {
    stage_v_56_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000566_6_1 & 63) > 18)
  {
    stage_v_57_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  }
  else
  {
    stage_v_57_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
  }
  if ((sec_r000566_6_2 & 63) > 18)
  {
    stage_v_57_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  }
  else
  {
    stage_v_57_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_22_1 & 63) > 29)
  {
    stage_v_58_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  }
  else
  {
    stage_v_58_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
  }
  if ((stage_v_22_2 & 63) > 29)
  {
    stage_v_58_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  }
  else
  {
    stage_v_58_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_8_1 & 63) > 54)
  {
    stage_v_59_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  }
  else
  {
    stage_v_59_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
  }
  if ((stage_v_8_2 & 63) > 54)
  {
    stage_v_59_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  }
  else
  {
    stage_v_59_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000566_9_1 & 63) > 36)
  {
    stage_v_60_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  }
  else
  {
    stage_v_60_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 36)
  {
    stage_v_60_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  }
  else
  {
    stage_v_60_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_56_1 & 63) > 39)
  {
    stage_v_61_1 = ((pub_r000566_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  }
  else
  {
    stage_v_61_1 = ((pub_r000566_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 39)
  {
    stage_v_61_2 = ((pub_r000566_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  }
  else
  {
    stage_v_61_2 = ((pub_r000566_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_7_1 & 63) > 30)
  {
    stage_v_62_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  }
  else
  {
    stage_v_62_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
  }
  if ((stage_v_7_2 & 63) > 30)
  {
    stage_v_62_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  }
  else
  {
    stage_v_62_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_16_1 & 63) > 16)
  {
    stage_v_63_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  }
  else
  {
    stage_v_63_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
  }
  if ((stage_v_16_2 & 63) > 16)
  {
    stage_v_63_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  }
  else
  {
    stage_v_63_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_43_1 & 63) > 38)
  {
    stage_v_64_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  }
  else
  {
    stage_v_64_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 38)
  {
    stage_v_64_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  }
  else
  {
    stage_v_64_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000566_14_1 & 63) > 47)
  {
    stage_v_65_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  }
  else
  {
    stage_v_65_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
  }
  if ((sec_r000566_14_2 & 63) > 47)
  {
    stage_v_65_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  }
  else
  {
    stage_v_65_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000566_1_1 & 63) > 37)
  {
    stage_v_66_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  }
  else
  {
    stage_v_66_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
  }
  if ((sec_r000566_1_2 & 63) > 37)
  {
    stage_v_66_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  }
  else
  {
    stage_v_66_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_34_1 & 63) > 27)
  {
    stage_v_67_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  }
  else
  {
    stage_v_67_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 27)
  {
    stage_v_67_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  }
  else
  {
    stage_v_67_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_59_1 & 63) > 53)
  {
    stage_v_68_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  }
  else
  {
    stage_v_68_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 53)
  {
    stage_v_68_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  }
  else
  {
    stage_v_68_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_43_1 & 63) > 52)
  {
    stage_v_69_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  }
  else
  {
    stage_v_69_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 52)
  {
    stage_v_69_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  }
  else
  {
    stage_v_69_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_21_1 & 63) > 43)
  {
    stage_v_70_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  }
  else
  {
    stage_v_70_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
  }
  if ((stage_v_21_2 & 63) > 43)
  {
    stage_v_70_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  }
  else
  {
    stage_v_70_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000566_12_1 & 63) > 47)
  {
    stage_v_71_1 = ((pub_r000566_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  }
  else
  {
    stage_v_71_1 = ((pub_r000566_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
  }
  if ((sec_r000566_12_2 & 63) > 47)
  {
    stage_v_71_2 = ((pub_r000566_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  }
  else
  {
    stage_v_71_2 = ((pub_r000566_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_50_1 & 63) > 58)
  {
    stage_v_72_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  }
  else
  {
    stage_v_72_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 58)
  {
    stage_v_72_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  }
  else
  {
    stage_v_72_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_59_1 & 63) > 58)
  {
    stage_v_73_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  }
  else
  {
    stage_v_73_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 58)
  {
    stage_v_73_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  }
  else
  {
    stage_v_73_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_58_1 & 63) > 42)
  {
    stage_v_74_1 = ((pub_r000566_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  }
  else
  {
    stage_v_74_1 = ((pub_r000566_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 42)
  {
    stage_v_74_2 = ((pub_r000566_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  }
  else
  {
    stage_v_74_2 = ((pub_r000566_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000566_11_1 & 63) > 55)
  {
    stage_v_75_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  }
  else
  {
    stage_v_75_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 55)
  {
    stage_v_75_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  }
  else
  {
    stage_v_75_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000566_8_1 & 63) > 33)
  {
    stage_v_76_1 = ((pub_r000566_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  }
  else
  {
    stage_v_76_1 = ((pub_r000566_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
  }
  if ((sec_r000566_8_2 & 63) > 33)
  {
    stage_v_76_2 = ((pub_r000566_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  }
  else
  {
    stage_v_76_2 = ((pub_r000566_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_69_1 & 63) > 15)
  {
    stage_v_77_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  }
  else
  {
    stage_v_77_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
  }
  if ((stage_v_69_2 & 63) > 15)
  {
    stage_v_77_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  }
  else
  {
    stage_v_77_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_33_1 & 63) > 33)
  {
    stage_v_78_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  }
  else
  {
    stage_v_78_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 33)
  {
    stage_v_78_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  }
  else
  {
    stage_v_78_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000566_8_1 & 63) > 37)
  {
    stage_v_79_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  }
  else
  {
    stage_v_79_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
  }
  if ((sec_r000566_8_2 & 63) > 37)
  {
    stage_v_79_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  }
  else
  {
    stage_v_79_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_43_1 & 63) > 58)
  {
    stage_v_80_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  }
  else
  {
    stage_v_80_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 58)
  {
    stage_v_80_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  }
  else
  {
    stage_v_80_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000566_11_1 & 63) > 16)
  {
    stage_v_81_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  }
  else
  {
    stage_v_81_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 16)
  {
    stage_v_81_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  }
  else
  {
    stage_v_81_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000566_11_1 & 63) > 23)
  {
    stage_v_82_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  }
  else
  {
    stage_v_82_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
  }
  if ((sec_r000566_11_2 & 63) > 23)
  {
    stage_v_82_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  }
  else
  {
    stage_v_82_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_17_1 & 63) > 15)
  {
    stage_v_83_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  }
  else
  {
    stage_v_83_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
  }
  if ((stage_v_17_2 & 63) > 15)
  {
    stage_v_83_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  }
  else
  {
    stage_v_83_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_61_1 & 63) > 31)
  {
    stage_v_84_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  }
  else
  {
    stage_v_84_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
  }
  if ((stage_v_61_2 & 63) > 31)
  {
    stage_v_84_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  }
  else
  {
    stage_v_84_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_12_1 & 63) > 27)
  {
    stage_v_85_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  }
  else
  {
    stage_v_85_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
  }
  if ((stage_v_12_2 & 63) > 27)
  {
    stage_v_85_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  }
  else
  {
    stage_v_85_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000566_9_1 & 63) > 43)
  {
    stage_v_86_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  }
  else
  {
    stage_v_86_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 43)
  {
    stage_v_86_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  }
  else
  {
    stage_v_86_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_13_1 & 63) > 46)
  {
    stage_v_87_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  }
  else
  {
    stage_v_87_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 46)
  {
    stage_v_87_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  }
  else
  {
    stage_v_87_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_27_1 & 63) > 56)
  {
    stage_v_88_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  }
  else
  {
    stage_v_88_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 56)
  {
    stage_v_88_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  }
  else
  {
    stage_v_88_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_57_1 & 63) > 15)
  {
    stage_v_89_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  }
  else
  {
    stage_v_89_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
  }
  if ((stage_v_57_2 & 63) > 15)
  {
    stage_v_89_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  }
  else
  {
    stage_v_89_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_32_1 & 63) > 18)
  {
    stage_v_90_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  }
  else
  {
    stage_v_90_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 18)
  {
    stage_v_90_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  }
  else
  {
    stage_v_90_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_13_1 & 63) > 34)
  {
    stage_v_91_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  }
  else
  {
    stage_v_91_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 34)
  {
    stage_v_91_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  }
  else
  {
    stage_v_91_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000566_12_1 & 63) > 47)
  {
    stage_v_92_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((sec_r000566_12_2 & 63) > 47)
  {
    stage_v_92_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_61_1 & 63) > 41)
  {
    stage_v_93_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((stage_v_61_2 & 63) > 41)
  {
    stage_v_93_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000566_3_1 & 63) > 57)
  {
    stage_v_94_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((sec_r000566_3_2 & 63) > 57)
  {
    stage_v_94_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000566_10_1 & 63) > 25)
  {
    stage_v_95_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((sec_r000566_10_2 & 63) > 25)
  {
    stage_v_95_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000566_12_1 & 63) > 42)
  {
    stage_v_96_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((sec_r000566_12_2 & 63) > 42)
  {
    stage_v_96_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_52_1 & 63) > 45)
  {
    stage_v_97_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 45)
  {
    stage_v_97_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_31_1 & 63) > 27)
  {
    stage_v_98_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 27)
  {
    stage_v_98_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_83_1 & 63) > 33)
  {
    stage_v_99_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((stage_v_83_2 & 63) > 33)
  {
    stage_v_99_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_58_1 & 63) > 37)
  {
    stage_v_100_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 37)
  {
    stage_v_100_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_77_1 & 63) > 22)
  {
    stage_v_101_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 22)
  {
    stage_v_101_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000566_15_1 & 63) > 51)
  {
    stage_v_102_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((sec_r000566_15_2 & 63) > 51)
  {
    stage_v_102_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000566_1_1 & 63) > 36)
  {
    stage_v_103_1 = ((pub_r000566_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000566_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((sec_r000566_1_2 & 63) > 36)
  {
    stage_v_103_2 = ((pub_r000566_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000566_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000566_9_1 & 63) > 53)
  {
    stage_v_104_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 53)
  {
    stage_v_104_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_73_1 & 63) > 55)
  {
    stage_v_105_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((stage_v_73_2 & 63) > 55)
  {
    stage_v_105_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_4_1 & 63) > 45)
  {
    stage_v_106_1 = ((pub_r000566_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000566_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((stage_v_4_2 & 63) > 45)
  {
    stage_v_106_2 = ((pub_r000566_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000566_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000566_0_1 & 63) > 40)
  {
    stage_v_107_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((sec_r000566_0_2 & 63) > 40)
  {
    stage_v_107_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_107_1 & 63) > 38)
  {
    stage_v_108_1 = ((pub_r000566_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000566_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_107_2 & 63) > 38)
  {
    stage_v_108_2 = ((pub_r000566_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000566_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_77_1 & 63) > 56)
  {
    stage_v_109_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 56)
  {
    stage_v_109_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_53_1 & 63) > 49)
  {
    stage_v_110_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((stage_v_53_2 & 63) > 49)
  {
    stage_v_110_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_77_1 & 63) > 32)
  {
    stage_v_111_1 = ((pub_r000566_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000566_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 32)
  {
    stage_v_111_2 = ((pub_r000566_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000566_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_73_1 & 63) > 34)
  {
    stage_v_112_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((stage_v_73_2 & 63) > 34)
  {
    stage_v_112_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_76_1 & 63) > 46)
  {
    stage_v_113_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((stage_v_76_2 & 63) > 46)
  {
    stage_v_113_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_53_1 & 63) > 54)
  {
    stage_v_114_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_53_2 & 63) > 54)
  {
    stage_v_114_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000566_3_1 & 63) > 18)
  {
    stage_v_115_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((sec_r000566_3_2 & 63) > 18)
  {
    stage_v_115_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_4_1 & 63) > 44)
  {
    stage_v_116_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((stage_v_4_2 & 63) > 44)
  {
    stage_v_116_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_19_1 & 63) > 25)
  {
    stage_v_117_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((stage_v_19_2 & 63) > 25)
  {
    stage_v_117_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000566_8_1 & 63) > 34)
  {
    stage_v_118_1 = ((pub_r000566_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000566_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((sec_r000566_8_2 & 63) > 34)
  {
    stage_v_118_2 = ((pub_r000566_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000566_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_42_1 & 63) > 23)
  {
    stage_v_119_1 = ((pub_r000566_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000566_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 23)
  {
    stage_v_119_2 = ((pub_r000566_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000566_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_63_1 & 63) > 59)
  {
    stage_v_120_1 = ((pub_r000566_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000566_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 59)
  {
    stage_v_120_2 = ((pub_r000566_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000566_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000566_2_1 & 63) > 18)
  {
    stage_v_121_1 = ((pub_r000566_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000566_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((sec_r000566_2_2 & 63) > 18)
  {
    stage_v_121_2 = ((pub_r000566_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000566_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_63_1 & 63) > 46)
  {
    stage_v_122_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 46)
  {
    stage_v_122_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_110_1 & 63) > 18)
  {
    stage_v_123_1 = ((pub_r000566_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000566_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((stage_v_110_2 & 63) > 18)
  {
    stage_v_123_2 = ((pub_r000566_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000566_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_115_1 & 63) > 30)
  {
    stage_v_124_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((stage_v_115_2 & 63) > 30)
  {
    stage_v_124_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_112_1 & 63) > 59)
  {
    stage_v_125_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((stage_v_112_2 & 63) > 59)
  {
    stage_v_125_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_108_1 & 63) > 19)
  {
    stage_v_126_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((stage_v_108_2 & 63) > 19)
  {
    stage_v_126_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_111_1 & 63) > 17)
  {
    stage_v_127_1 = ((pub_r000566_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000566_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((stage_v_111_2 & 63) > 17)
  {
    stage_v_127_2 = ((pub_r000566_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000566_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000566_9_1 & 63) > 53)
  {
    stage_v_128_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 53)
  {
    stage_v_128_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000566_5_1 & 63) > 33)
  {
    stage_v_129_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((sec_r000566_5_2 & 63) > 33)
  {
    stage_v_129_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_38_1 & 63) > 35)
  {
    stage_v_130_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_38_2 & 63) > 35)
  {
    stage_v_130_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_114_1 & 63) > 44)
  {
    stage_v_131_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((stage_v_114_2 & 63) > 44)
  {
    stage_v_131_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000566_3_1 & 63) > 59)
  {
    stage_v_132_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((sec_r000566_3_2 & 63) > 59)
  {
    stage_v_132_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_93_1 & 63) > 16)
  {
    stage_v_133_1 = ((pub_r000566_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000566_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((stage_v_93_2 & 63) > 16)
  {
    stage_v_133_2 = ((pub_r000566_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000566_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_133_1 & 63) > 26)
  {
    stage_v_134_1 = ((pub_r000566_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000566_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((stage_v_133_2 & 63) > 26)
  {
    stage_v_134_2 = ((pub_r000566_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000566_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000566_2_1 & 63) > 29)
  {
    stage_v_135_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((sec_r000566_2_2 & 63) > 29)
  {
    stage_v_135_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_61_1 & 63) > 32)
  {
    stage_v_136_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((stage_v_61_2 & 63) > 32)
  {
    stage_v_136_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000566_3_1 & 63) > 52)
  {
    stage_v_137_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((sec_r000566_3_2 & 63) > 52)
  {
    stage_v_137_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_112_1 & 63) > 50)
  {
    stage_v_138_1 = ((pub_r000566_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000566_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((stage_v_112_2 & 63) > 50)
  {
    stage_v_138_2 = ((pub_r000566_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000566_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_111_1 & 63) > 17)
  {
    stage_v_139_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((stage_v_111_2 & 63) > 17)
  {
    stage_v_139_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_18_1 & 63) > 33)
  {
    stage_v_140_1 = ((pub_r000566_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000566_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((stage_v_18_2 & 63) > 33)
  {
    stage_v_140_2 = ((pub_r000566_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000566_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000566_13_1 & 63) > 47)
  {
    stage_v_141_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((sec_r000566_13_2 & 63) > 47)
  {
    stage_v_141_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_13_1 & 63) > 29)
  {
    stage_v_142_1 = ((pub_r000566_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000566_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((stage_v_13_2 & 63) > 29)
  {
    stage_v_142_2 = ((pub_r000566_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000566_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000566_2_1 & 63) > 18)
  {
    stage_v_143_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((sec_r000566_2_2 & 63) > 18)
  {
    stage_v_143_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_126_1 & 63) > 32)
  {
    stage_v_144_1 = ((pub_r000566_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000566_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((stage_v_126_2 & 63) > 32)
  {
    stage_v_144_2 = ((pub_r000566_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000566_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_48_1 & 63) > 39)
  {
    stage_v_145_1 = ((pub_r000566_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000566_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((stage_v_48_2 & 63) > 39)
  {
    stage_v_145_2 = ((pub_r000566_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000566_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_78_1 & 63) > 32)
  {
    stage_v_146_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((stage_v_78_2 & 63) > 32)
  {
    stage_v_146_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_44_1 & 63) > 18)
  {
    stage_v_147_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((stage_v_44_2 & 63) > 18)
  {
    stage_v_147_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000566_9_1 & 63) > 51)
  {
    stage_v_148_1 = ((pub_r000566_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000566_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((sec_r000566_9_2 & 63) > 51)
  {
    stage_v_148_2 = ((pub_r000566_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000566_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_142_1 & 63) > 48)
  {
    stage_v_149_1 = ((pub_r000566_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000566_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((stage_v_142_2 & 63) > 48)
  {
    stage_v_149_2 = ((pub_r000566_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000566_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_50_1 & 63) > 33)
  {
    stage_v_150_1 = ((pub_r000566_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000566_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 33)
  {
    stage_v_150_2 = ((pub_r000566_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000566_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_96_1 & 63) > 42)
  {
    stage_v_151_1 = ((pub_r000566_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000566_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((stage_v_96_2 & 63) > 42)
  {
    stage_v_151_2 = ((pub_r000566_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000566_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_106_1 & 63) > 30)
  {
    stage_v_152_1 = ((pub_r000566_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000566_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 30)
  {
    stage_v_152_2 = ((pub_r000566_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000566_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000566_1_1 != sec_r000566_1_2);
  __CPROVER_assume(pub_r000566_11_1 == pub_r000566_11_2);
  __CPROVER_assume(pub_r000566_17_1 == pub_r000566_17_2);
  __CPROVER_assume(sec_r000566_4_1 != sec_r000566_4_2);
  __CPROVER_assume(pub_r000566_16_1 == pub_r000566_16_2);
  __CPROVER_assume(pub_r000566_2_1 == pub_r000566_2_2);
  __CPROVER_assume(pub_r000566_12_1 == pub_r000566_12_2);
  __CPROVER_assume(sec_r000566_2_1 != sec_r000566_2_2);
  __CPROVER_assume(sec_r000566_14_1 != sec_r000566_14_2);
  __CPROVER_assume(pub_r000566_0_1 == pub_r000566_0_2);
  __CPROVER_assume(pub_r000566_4_1 == pub_r000566_4_2);
  __CPROVER_assume(sec_r000566_8_1 != sec_r000566_8_2);
  __CPROVER_assume(sec_r000566_9_1 != sec_r000566_9_2);
  __CPROVER_assume(sec_r000566_15_1 != sec_r000566_15_2);
  __CPROVER_assume(sec_r000566_13_1 != sec_r000566_13_2);
  __CPROVER_assume(pub_r000566_1_1 == pub_r000566_1_2);
  __CPROVER_assume(pub_r000566_9_1 == pub_r000566_9_2);
  __CPROVER_assume(sec_r000566_11_1 != sec_r000566_11_2);
  __CPROVER_assume(pub_r000566_5_1 == pub_r000566_5_2);
  __CPROVER_assume(sec_r000566_5_1 != sec_r000566_5_2);
  __CPROVER_assume(pub_r000566_6_1 == pub_r000566_6_2);
  __CPROVER_assume(pub_r000566_14_1 == pub_r000566_14_2);
  __CPROVER_assume(pub_r000566_13_1 == pub_r000566_13_2);
  __CPROVER_assume(pub_r000566_15_1 == pub_r000566_15_2);
  __CPROVER_assume(pub_r000566_8_1 == pub_r000566_8_2);
  __CPROVER_assume(sec_r000566_12_1 != sec_r000566_12_2);
  __CPROVER_assume(sec_r000566_10_1 != sec_r000566_10_2);
  __CPROVER_assume(sec_r000566_3_1 != sec_r000566_3_2);
  __CPROVER_assume(sec_r000566_7_1 != sec_r000566_7_2);
  __CPROVER_assume(sec_r000566_0_1 != sec_r000566_0_2);
  __CPROVER_assume(sec_r000566_6_1 != sec_r000566_6_2);
  __CPROVER_assume(pub_r000566_3_1 == pub_r000566_3_2);
  __CPROVER_assume(pub_r000566_10_1 == pub_r000566_10_2);
  __CPROVER_assume(pub_r000566_7_1 == pub_r000566_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.id == st_var_1_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
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
}


