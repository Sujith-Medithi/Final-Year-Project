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
struct MatrixBlock_R001856_5613_0
{
  short stride;
  unsigned char determinant;
  int dim;
  unsigned char scale;
  int buffer[3];
};
struct EventLog_R001856_5613_1
{
  short timestamp;
  int seq;
  short signature;
  int code;
  int facility;
  int buffer[3];
};
struct Vector3D_R001856_5613_2
{
  short norm_sq;
  unsigned char coord_y;
  int coord_x;
  short heading;
  int coord_z;
  int buffer[3];
};
struct DeviceConfig_R001856_5613_3
{
  short port;
  unsigned char id;
  short stop_bits;
  short baud_rate;
  int buffer[3];
};
union PacketPayload_R001856_5613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001856_5613_1
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
void fn_R001856_5613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int coefficient_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_83_1 > 36)
  {
    acc_1 = ((acc_1 + (coefficient_83_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_83_2 > 36)
  {
    acc_2 = ((acc_2 + (coefficient_83_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_65_1 = local_arr_1[aux_1 % 3];
  int coefficient_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_65_2 * 2)) & 127;
  int offset_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_10_1) & 63;
  aux_2 = (aux_2 + offset_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_83_1 == coefficient_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R001856_5613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int coefficient_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_83 > 36)
  {
    acc = ((acc + (coefficient_83 * 2)) + 5) & 127;
    aux ^= coefficient_83 & 15;
  }
  else
  {
    acc = ((acc - coefficient_83) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_65 = local_arr[aux % 3];
  acc = (acc + (coefficient_65 * 2)) & 127;
  int offset_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001856_5613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_98_1 > 49)
  {
    acc_1 = ((acc_1 + (offset_98_1 * 2)) + 5) & 127;
    aux_1 ^= offset_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_98_2 > 49)
  {
    acc_2 = ((acc_2 + (offset_98_2 * 2)) + 5) & 127;
    aux_2 ^= offset_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_63_1) & 63;
  aux_2 = (aux_2 + mask_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_63_1 = local_arr_1[aux_1 % 3];
  int threshold_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_98_1 == offset_98_2);
  assert(mask_63_1 == mask_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_63_1 == threshold_63_2);
}

int fn_R001856_5613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_98 > 49)
  {
    acc = ((acc + (offset_98 * 2)) + 5) & 127;
    aux ^= offset_98 & 15;
  }
  else
  {
    acc = ((acc - offset_98) + 11) & 127;
    aux += 3;
  }
  int mask_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_63) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_63 = local_arr[aux % 3];
  acc = (acc + (threshold_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tracker_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_22_1)
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

  switch (tracker_22_2)
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
  int accumulator_54_1 = local_arr_1[aux_1 % 3];
  int accumulator_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_22_1 == tracker_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_54_1 == accumulator_54_2);
}

int fn_R001856_5613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tracker_22 = (aux + st.buffer[1]) & 3;
  switch (tracker_22)
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
  int accumulator_54 = local_arr[aux % 3];
  acc = (acc + (accumulator_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_37_1) & 63;
  aux_2 = (aux_2 + delta_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_31_1 = local_arr_1[aux_1 % 3];
  int segment_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_31_2 * 2)) & 127;
  int tally_41_1 = 0;
  int tally_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_41_1 = ((tally_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_41_2 = ((tally_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_41_1) & 127;
    acc_2 = (acc_2 + tally_41_2) & 127;
  }

  int tally_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_81_1 > 15)
  {
    acc_1 = ((acc_1 + (tally_81_1 * 2)) + 5) & 127;
    aux_1 ^= tally_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_81_2 > 15)
  {
    acc_2 = ((acc_2 + (tally_81_2 * 2)) + 5) & 127;
    aux_2 ^= tally_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_37_1 == delta_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_31_1 == segment_31_2);
  assert(tally_41_1 == tally_41_2);
  assert(tally_81_1 == tally_81_2);
}

int fn_R001856_5613_3(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_31 = local_arr[aux % 3];
  acc = (acc + (segment_31 * 2)) & 127;
  int tally_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_41 = ((tally_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_41) & 127;
  }

  int tally_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_81 > 15)
  {
    acc = ((acc + (tally_81 * 2)) + 5) & 127;
    aux ^= tally_81 & 15;
  }
  else
  {
    acc = ((acc - tally_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001856_5613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_35_1)
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

  switch (tracker_35_2)
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

  int segment_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_59_1) & 63;
  aux_2 = (aux_2 + segment_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_35_1 == tracker_35_2);
  assert(segment_59_1 == segment_59_2);
}

int fn_R001856_5613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_35 = (aux + st.buffer[1]) & 3;
  switch (tracker_35)
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

  int segment_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001856_5613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int cursor_59_1 = 0;
  int cursor_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_59_1 = ((cursor_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_59_2 = ((cursor_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_59_1) & 127;
    acc_2 = (acc_2 + cursor_59_2) & 127;
  }

  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_45_1)
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

  switch (sample_45_2)
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

  int accumulator_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_11_1 > 40)
  {
    acc_1 = ((acc_1 + (accumulator_11_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_11_2 > 40)
  {
    acc_2 = ((acc_2 + (accumulator_11_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_59_1 == cursor_59_2);
  assert(accumulator_28_1 == accumulator_28_2);
  assert(sample_45_1 == sample_45_2);
  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R001856_5613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int cursor_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_59 = ((cursor_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_59) & 127;
  }

  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  int sample_45 = (aux + st.buffer[1]) & 3;
  switch (sample_45)
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

  int accumulator_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_11 > 40)
  {
    acc = ((acc + (accumulator_11 * 2)) + 5) & 127;
    aux ^= accumulator_11 & 15;
  }
  else
  {
    acc = ((acc - accumulator_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001856_5613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st_1 = {0};
  struct MatrixBlock_R001856_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int pivot_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_74_1)
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

  switch (pivot_74_2)
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
  int checksum_81_1 = local_arr_1[aux_1 % 3];
  int checksum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_74_1 == pivot_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_81_1 == checksum_81_2);
}

int fn_R001856_5613_6(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int pivot_74 = (aux + st.buffer[1]) & 3;
  switch (pivot_74)
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
  int checksum_81 = local_arr[aux % 3];
  acc = (acc + (checksum_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_38_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_38_1 * 2)) + 5) & 127;
    aux_1 ^= stride_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_38_2 > 36)
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
  int vector_69_1 = local_arr_1[aux_1 % 3];
  int vector_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_69_2 * 2)) & 127;
  int mask_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_15_1) & 63;
  aux_2 = (aux_2 + mask_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_46_1)
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

  switch (tally_46_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_38_1 == stride_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_69_1 == vector_69_2);
  assert(mask_15_1 == mask_15_2);
  assert(tally_46_1 == tally_46_2);
}

int fn_R001856_5613_7(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_38 > 36)
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
  int vector_69 = local_arr[aux % 3];
  acc = (acc + (vector_69 * 2)) & 127;
  int mask_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_15) & 63;
  acc ^= aux;
  int tally_46 = (aux + st.buffer[1]) & 3;
  switch (tally_46)
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

void fn_R001856_5613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_90_1) & 63;
  aux_2 = (aux_2 + phase_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_33_1)
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

  switch (index_reg_33_2)
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

  int factor_86_1 = 0;
  int factor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_86_1 = ((factor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_86_2 = ((factor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_86_1) & 127;
    acc_2 = (acc_2 + factor_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_90_1 == phase_90_2);
  assert(index_reg_33_1 == index_reg_33_2);
  assert(factor_86_1 == factor_86_2);
}

int fn_R001856_5613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_90) & 63;
  acc ^= aux;
  int index_reg_33 = (aux + st.buffer[1]) & 3;
  switch (index_reg_33)
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

  int factor_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_86 = ((factor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001856_5613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_93_1) & 63;
  aux_2 = (aux_2 + margin_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_68_1 = local_arr_1[aux_1 % 3];
  int phase_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_68_2 * 2)) & 127;
  int scale_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_77_1)
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

  switch (scale_77_2)
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

  int offset_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_59_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_59_1 * 2)) + 5) & 127;
    aux_1 ^= offset_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_59_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_59_2 * 2)) + 5) & 127;
    aux_2 ^= offset_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_93_1 == margin_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_68_1 == phase_68_2);
  assert(scale_77_1 == scale_77_2);
  assert(offset_59_1 == offset_59_2);
}

int fn_R001856_5613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_93) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_68 = local_arr[aux % 3];
  acc = (acc + (phase_68 * 2)) & 127;
  int scale_77 = (aux + st.buffer[1]) & 3;
  switch (scale_77)
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

  int offset_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_59 > 36)
  {
    acc = ((acc + (offset_59 * 2)) + 5) & 127;
    aux ^= offset_59 & 15;
  }
  else
  {
    acc = ((acc - offset_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001856_5613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_56_1 > 10)
  {
    acc_1 = ((acc_1 + (cursor_56_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_56_2 > 10)
  {
    acc_2 = ((acc_2 + (cursor_56_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_56_1 == cursor_56_2);
}

int fn_R001856_5613_10(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_56 > 10)
  {
    acc = ((acc + (cursor_56 * 2)) + 5) & 127;
    aux ^= cursor_56 & 15;
  }
  else
  {
    acc = ((acc - cursor_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001856_5613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_92_1 = 0;
  int offset_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_92_1 = ((offset_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_92_2 = ((offset_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_92_1) & 127;
    acc_2 = (acc_2 + offset_92_2) & 127;
  }

  int margin_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_72_1) & 63;
  aux_2 = (aux_2 + margin_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_92_1 == offset_92_2);
  assert(margin_72_1 == margin_72_2);
}

int fn_R001856_5613_11(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_92 = ((offset_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_92) & 127;
  }

  int margin_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001856_5613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st_1 = {0};
  struct MatrixBlock_R001856_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_31_1 > 13)
  {
    acc_1 = ((acc_1 + (scale_31_1 * 2)) + 5) & 127;
    aux_1 ^= scale_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_31_2 > 13)
  {
    acc_2 = ((acc_2 + (scale_31_2 * 2)) + 5) & 127;
    aux_2 ^= scale_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_79_1 = 0;
  int delta_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_79_1 = ((delta_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_79_2 = ((delta_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_79_1) & 127;
    acc_2 = (acc_2 + delta_79_2) & 127;
  }

  int anchor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_19_1)
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

  switch (anchor_19_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_31_1 == scale_31_2);
  assert(delta_79_1 == delta_79_2);
  assert(anchor_19_1 == anchor_19_2);
}

int fn_R001856_5613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_31 > 13)
  {
    acc = ((acc + (scale_31 * 2)) + 5) & 127;
    aux ^= scale_31 & 15;
  }
  else
  {
    acc = ((acc - scale_31) + 11) & 127;
    aux += 3;
  }
  int delta_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_79 = ((delta_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_79) & 127;
  }

  int anchor_19 = (aux + st.buffer[1]) & 3;
  switch (anchor_19)
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

void fn_R001856_5613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_97_1 > 46)
  {
    acc_1 = ((acc_1 + (factor_97_1 * 2)) + 5) & 127;
    aux_1 ^= factor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_97_2 > 46)
  {
    acc_2 = ((acc_2 + (factor_97_2 * 2)) + 5) & 127;
    aux_2 ^= factor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_97_1 == factor_97_2);
}

int fn_R001856_5613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_97 > 46)
  {
    acc = ((acc + (factor_97 * 2)) + 5) & 127;
    aux ^= factor_97 & 15;
  }
  else
  {
    acc = ((acc - factor_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st_1 = {0};
  struct MatrixBlock_R001856_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_92_1 = local_arr_1[aux_1 % 3];
  int parity_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_92_2 * 2)) & 127;
  int coefficient_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_35_1) & 63;
  aux_2 = (aux_2 + coefficient_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(coefficient_35_1 == coefficient_35_2);
}

int fn_R001856_5613_14(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001856_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_92 = local_arr[aux % 3];
  acc = (acc + (parity_92 * 2)) & 127;
  int coefficient_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001856_5613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int index_reg_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_50_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_50_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_50_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_50_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_38_1 = local_arr_1[aux_1 % 3];
  int delta_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_50_1 == index_reg_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_38_1 == delta_38_2);
}

int fn_R001856_5613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int index_reg_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_50 > 35)
  {
    acc = ((acc + (index_reg_50 * 2)) + 5) & 127;
    aux ^= index_reg_50 & 15;
  }
  else
  {
    acc = ((acc - index_reg_50) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_38 = local_arr[aux % 3];
  acc = (acc + (delta_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_91_1) & 63;
  aux_2 = (aux_2 + residue_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_79_1 = local_arr_1[aux_1 % 3];
  int tally_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_79_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_91_1 == residue_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_79_1 == tally_79_2);
}

int fn_R001856_5613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_79 = local_arr[aux % 3];
  acc = (acc + (tally_79 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_16_1) & 63;
  aux_2 = (aux_2 + damping_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_78_1)
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

  switch (accumulator_78_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_16_1 == damping_16_2);
  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R001856_5613_17(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_16) & 63;
  acc ^= aux;
  int accumulator_78 = (aux + st.buffer[1]) & 3;
  switch (accumulator_78)
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

void fn_R001856_5613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_46_1) & 63;
  aux_2 = (aux_2 + checksum_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_23_1 = 0;
  int anchor_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_23_1 = ((anchor_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_23_2 = ((anchor_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_23_1) & 127;
    acc_2 = (acc_2 + anchor_23_2) & 127;
  }

  int sample_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_18_1)
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

  switch (sample_18_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_46_1 == checksum_46_2);
  assert(anchor_23_1 == anchor_23_2);
  assert(sample_18_1 == sample_18_2);
}

int fn_R001856_5613_18(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_46) & 63;
  acc ^= aux;
  int anchor_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_23 = ((anchor_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_23) & 127;
  }

  int sample_18 = (aux + st.buffer[1]) & 3;
  switch (sample_18)
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

void fn_R001856_5613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int cursor_13_1 = 0;
  int cursor_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_13_1 = ((cursor_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_13_2 = ((cursor_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_13_1) & 127;
    acc_2 = (acc_2 + cursor_13_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_82_1 > 24)
  {
    acc_1 = ((acc_1 + (cursor_82_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_82_2 > 24)
  {
    acc_2 = ((acc_2 + (cursor_82_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_13_1 == cursor_13_2);
  assert(cursor_82_1 == cursor_82_2);
}

int fn_R001856_5613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int cursor_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_13 = ((cursor_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_13) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_82 > 24)
  {
    acc = ((acc + (cursor_82 * 2)) + 5) & 127;
    aux ^= cursor_82 & 15;
  }
  else
  {
    acc = ((acc - cursor_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001856_5613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_84_1) & 63;
  aux_2 = (aux_2 + offset_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_78_1 = 0;
  int tally_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_78_1 = ((tally_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_78_2 = ((tally_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_78_1) & 127;
    acc_2 = (acc_2 + tally_78_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_41_1 = local_arr_1[aux_1 % 3];
  int cursor_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_84_1 == offset_84_2);
  assert(tally_78_1 == tally_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_41_1 == cursor_41_2);
}

int fn_R001856_5613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001856_5613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_84) & 63;
  acc ^= aux;
  int tally_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_78 = ((tally_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_78) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_41 = local_arr[aux % 3];
  acc = (acc + (cursor_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st_1 = {0};
  struct EventLog_R001856_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_96_1 > 28)
  {
    acc_1 = ((acc_1 + (scale_96_1 * 2)) + 5) & 127;
    aux_1 ^= scale_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_96_2 > 28)
  {
    acc_2 = ((acc_2 + (scale_96_2 * 2)) + 5) & 127;
    aux_2 ^= scale_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_42_1) & 63;
  aux_2 = (aux_2 + index_reg_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_11_1 = 0;
  int delta_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_11_1 = ((delta_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_11_2 = ((delta_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_11_1) & 127;
    acc_2 = (acc_2 + delta_11_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_96_1 == scale_96_2);
  assert(index_reg_42_1 == index_reg_42_2);
  assert(delta_11_1 == delta_11_2);
}

int fn_R001856_5613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001856_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_96 > 28)
  {
    acc = ((acc + (scale_96 * 2)) + 5) & 127;
    aux ^= scale_96 & 15;
  }
  else
  {
    acc = ((acc - scale_96) + 11) & 127;
    aux += 3;
  }
  int index_reg_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_42) & 63;
  acc ^= aux;
  int delta_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_11 = ((delta_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_11) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001856_5613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st_1 = {0};
  struct Vector3D_R001856_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_44_1 > 16)
  {
    acc_1 = ((acc_1 + (window_44_1 * 2)) + 5) & 127;
    aux_1 ^= window_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_44_2 > 16)
  {
    acc_2 = ((acc_2 + (window_44_2 * 2)) + 5) & 127;
    aux_2 ^= window_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_68_1)
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

  switch (delta_68_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_44_1 == window_44_2);
  assert(delta_68_1 == delta_68_2);
}

int fn_R001856_5613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001856_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_44 > 16)
  {
    acc = ((acc + (window_44 * 2)) + 5) & 127;
    aux ^= window_44 & 15;
  }
  else
  {
    acc = ((acc - window_44) + 11) & 127;
    aux += 3;
  }
  int delta_68 = (aux + st.buffer[1]) & 3;
  switch (delta_68)
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

void main()
{
  int sec_r001856_0_1;
  int sec_r001856_0_2;
  int sec_r001856_1_1;
  int sec_r001856_1_2;
  int sec_r001856_2_1;
  int sec_r001856_2_2;
  int sec_r001856_3_1;
  int sec_r001856_3_2;
  int sec_r001856_4_1;
  int sec_r001856_4_2;
  int sec_r001856_5_1;
  int sec_r001856_5_2;
  int sec_r001856_6_1;
  int sec_r001856_6_2;
  int sec_r001856_7_1;
  int sec_r001856_7_2;
  int sec_r001856_8_1;
  int sec_r001856_8_2;
  int sec_r001856_9_1;
  int sec_r001856_9_2;
  int sec_r001856_10_1;
  int sec_r001856_10_2;
  int sec_r001856_11_1;
  int sec_r001856_11_2;
  int sec_r001856_12_1;
  int sec_r001856_12_2;
  int sec_r001856_13_1;
  int sec_r001856_13_2;
  int sec_r001856_14_1;
  int sec_r001856_14_2;
  int sec_r001856_15_1;
  int sec_r001856_15_2;
  int sec_r001856_16_1;
  int sec_r001856_16_2;
  int pub_r001856_0_1;
  int pub_r001856_0_2;
  int pub_r001856_1_1;
  int pub_r001856_1_2;
  int pub_r001856_2_1;
  int pub_r001856_2_2;
  int pub_r001856_3_1;
  int pub_r001856_3_2;
  int pub_r001856_4_1;
  int pub_r001856_4_2;
  int pub_r001856_5_1;
  int pub_r001856_5_2;
  int pub_r001856_6_1;
  int pub_r001856_6_2;
  int pub_r001856_7_1;
  int pub_r001856_7_2;
  int pub_r001856_8_1;
  int pub_r001856_8_2;
  int pub_r001856_9_1;
  int pub_r001856_9_2;
  int pub_r001856_10_1;
  int pub_r001856_10_2;
  int pub_r001856_11_1;
  int pub_r001856_11_2;
  int pub_r001856_12_1;
  int pub_r001856_12_2;
  int pub_r001856_13_1;
  int pub_r001856_13_2;
  int pub_r001856_14_1;
  int pub_r001856_14_2;
  int pub_r001856_15_1;
  int pub_r001856_15_2;
  int pub_r001856_16_1;
  int pub_r001856_16_2;
  int pub_r001856_17_1;
  int pub_r001856_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001856_0_1 >= (-100)) && (pub_r001856_0_1 <= 100));
  __CPROVER_assume((pub_r001856_0_2 >= (-100)) && (pub_r001856_0_2 <= 100));
  __CPROVER_assume((pub_r001856_1_1 >= (-100)) && (pub_r001856_1_1 <= 100));
  __CPROVER_assume((pub_r001856_1_2 >= (-100)) && (pub_r001856_1_2 <= 100));
  __CPROVER_assume((pub_r001856_2_1 >= (-100)) && (pub_r001856_2_1 <= 100));
  __CPROVER_assume((pub_r001856_2_2 >= (-100)) && (pub_r001856_2_2 <= 100));
  __CPROVER_assume((pub_r001856_3_1 >= (-100)) && (pub_r001856_3_1 <= 100));
  __CPROVER_assume((pub_r001856_3_2 >= (-100)) && (pub_r001856_3_2 <= 100));
  __CPROVER_assume((pub_r001856_4_1 >= (-100)) && (pub_r001856_4_1 <= 100));
  __CPROVER_assume((pub_r001856_4_2 >= (-100)) && (pub_r001856_4_2 <= 100));
  __CPROVER_assume((pub_r001856_5_1 >= (-100)) && (pub_r001856_5_1 <= 100));
  __CPROVER_assume((pub_r001856_5_2 >= (-100)) && (pub_r001856_5_2 <= 100));
  __CPROVER_assume((pub_r001856_6_1 >= (-100)) && (pub_r001856_6_1 <= 100));
  __CPROVER_assume((pub_r001856_6_2 >= (-100)) && (pub_r001856_6_2 <= 100));
  __CPROVER_assume((pub_r001856_7_1 >= (-100)) && (pub_r001856_7_1 <= 100));
  __CPROVER_assume((pub_r001856_7_2 >= (-100)) && (pub_r001856_7_2 <= 100));
  __CPROVER_assume((pub_r001856_8_1 >= (-100)) && (pub_r001856_8_1 <= 100));
  __CPROVER_assume((pub_r001856_8_2 >= (-100)) && (pub_r001856_8_2 <= 100));
  __CPROVER_assume((pub_r001856_9_1 >= (-100)) && (pub_r001856_9_1 <= 100));
  __CPROVER_assume((pub_r001856_9_2 >= (-100)) && (pub_r001856_9_2 <= 100));
  __CPROVER_assume((pub_r001856_10_1 >= (-100)) && (pub_r001856_10_1 <= 100));
  __CPROVER_assume((pub_r001856_10_2 >= (-100)) && (pub_r001856_10_2 <= 100));
  __CPROVER_assume((pub_r001856_11_1 >= (-100)) && (pub_r001856_11_1 <= 100));
  __CPROVER_assume((pub_r001856_11_2 >= (-100)) && (pub_r001856_11_2 <= 100));
  __CPROVER_assume((pub_r001856_12_1 >= (-100)) && (pub_r001856_12_1 <= 100));
  __CPROVER_assume((pub_r001856_12_2 >= (-100)) && (pub_r001856_12_2 <= 100));
  __CPROVER_assume((pub_r001856_13_1 >= (-100)) && (pub_r001856_13_1 <= 100));
  __CPROVER_assume((pub_r001856_13_2 >= (-100)) && (pub_r001856_13_2 <= 100));
  __CPROVER_assume((pub_r001856_14_1 >= (-100)) && (pub_r001856_14_1 <= 100));
  __CPROVER_assume((pub_r001856_14_2 >= (-100)) && (pub_r001856_14_2 <= 100));
  __CPROVER_assume((pub_r001856_15_1 >= (-100)) && (pub_r001856_15_1 <= 100));
  __CPROVER_assume((pub_r001856_15_2 >= (-100)) && (pub_r001856_15_2 <= 100));
  __CPROVER_assume((pub_r001856_16_1 >= (-100)) && (pub_r001856_16_1 <= 100));
  __CPROVER_assume((pub_r001856_16_2 >= (-100)) && (pub_r001856_16_2 <= 100));
  __CPROVER_assume((pub_r001856_17_1 >= (-100)) && (pub_r001856_17_1 <= 100));
  __CPROVER_assume((pub_r001856_17_2 >= (-100)) && (pub_r001856_17_2 <= 100));
  __CPROVER_assume((sec_r001856_0_1 >= 0) && (sec_r001856_0_1 <= 255));
  __CPROVER_assume((sec_r001856_0_2 >= 0) && (sec_r001856_0_2 <= 255));
  __CPROVER_assume((sec_r001856_1_1 >= 0) && (sec_r001856_1_1 <= 255));
  __CPROVER_assume((sec_r001856_1_2 >= 0) && (sec_r001856_1_2 <= 255));
  __CPROVER_assume((sec_r001856_2_1 >= 0) && (sec_r001856_2_1 <= 255));
  __CPROVER_assume((sec_r001856_2_2 >= 0) && (sec_r001856_2_2 <= 255));
  __CPROVER_assume((sec_r001856_3_1 >= 0) && (sec_r001856_3_1 <= 255));
  __CPROVER_assume((sec_r001856_3_2 >= 0) && (sec_r001856_3_2 <= 255));
  __CPROVER_assume((sec_r001856_4_1 >= 0) && (sec_r001856_4_1 <= 255));
  __CPROVER_assume((sec_r001856_4_2 >= 0) && (sec_r001856_4_2 <= 255));
  __CPROVER_assume((sec_r001856_5_1 >= 0) && (sec_r001856_5_1 <= 255));
  __CPROVER_assume((sec_r001856_5_2 >= 0) && (sec_r001856_5_2 <= 255));
  __CPROVER_assume((sec_r001856_6_1 >= 0) && (sec_r001856_6_1 <= 255));
  __CPROVER_assume((sec_r001856_6_2 >= 0) && (sec_r001856_6_2 <= 255));
  __CPROVER_assume((sec_r001856_7_1 >= 0) && (sec_r001856_7_1 <= 255));
  __CPROVER_assume((sec_r001856_7_2 >= 0) && (sec_r001856_7_2 <= 255));
  __CPROVER_assume((sec_r001856_8_1 >= 0) && (sec_r001856_8_1 <= 255));
  __CPROVER_assume((sec_r001856_8_2 >= 0) && (sec_r001856_8_2 <= 255));
  __CPROVER_assume((sec_r001856_9_1 >= 0) && (sec_r001856_9_1 <= 255));
  __CPROVER_assume((sec_r001856_9_2 >= 0) && (sec_r001856_9_2 <= 255));
  __CPROVER_assume((sec_r001856_10_1 >= 0) && (sec_r001856_10_1 <= 255));
  __CPROVER_assume((sec_r001856_10_2 >= 0) && (sec_r001856_10_2 <= 255));
  __CPROVER_assume((sec_r001856_11_1 >= 0) && (sec_r001856_11_1 <= 255));
  __CPROVER_assume((sec_r001856_11_2 >= 0) && (sec_r001856_11_2 <= 255));
  __CPROVER_assume((sec_r001856_12_1 >= 0) && (sec_r001856_12_1 <= 255));
  __CPROVER_assume((sec_r001856_12_2 >= 0) && (sec_r001856_12_2 <= 255));
  __CPROVER_assume((sec_r001856_13_1 >= 0) && (sec_r001856_13_1 <= 255));
  __CPROVER_assume((sec_r001856_13_2 >= 0) && (sec_r001856_13_2 <= 255));
  __CPROVER_assume((sec_r001856_14_1 >= 0) && (sec_r001856_14_1 <= 255));
  __CPROVER_assume((sec_r001856_14_2 >= 0) && (sec_r001856_14_2 <= 255));
  __CPROVER_assume((sec_r001856_15_1 >= 0) && (sec_r001856_15_1 <= 255));
  __CPROVER_assume((sec_r001856_15_2 >= 0) && (sec_r001856_15_2 <= 255));
  __CPROVER_assume((sec_r001856_16_1 >= 0) && (sec_r001856_16_1 <= 255));
  __CPROVER_assume((sec_r001856_16_2 >= 0) && (sec_r001856_16_2 <= 255));
  struct MatrixBlock_R001856_5613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001856_5613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001856_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001856_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001856_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001856_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001856_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001856_0_2 + 7) & 15;
  struct EventLog_R001856_5613_1 st_var_1_1 = {0};
  struct EventLog_R001856_5613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001856_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001856_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001856_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001856_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001856_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001856_0_2 + 9) & 15;
  struct Vector3D_R001856_5613_2 st_var_2_1 = {0};
  struct Vector3D_R001856_5613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001856_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001856_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001856_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001856_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001856_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001856_0_2 + 11) & 15;
  struct DeviceConfig_R001856_5613_3 st_var_3_1 = {0};
  struct DeviceConfig_R001856_5613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001856_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001856_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001856_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001856_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001856_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001856_0_2 + 13) & 15;
  union PacketPayload_R001856_5613_0 u_var_1;
  union PacketPayload_R001856_5613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001856_5613_0(sec_r001856_0_1, sec_r001856_1_1, pub_r001856_2_1, pub_r001856_3_1, pub_r001856_4_1);
  int helper_flow_0_2 = fn_R001856_5613_0(sec_r001856_0_2, sec_r001856_1_2, pub_r001856_2_2, pub_r001856_3_2, pub_r001856_4_2);
  fn_R001856_5613_0_2(sec_r001856_0_1, sec_r001856_1_1, pub_r001856_2_1, pub_r001856_3_1, pub_r001856_4_1, sec_r001856_0_2, sec_r001856_1_2, pub_r001856_2_2, pub_r001856_3_2, pub_r001856_4_2);
  int helper_flow_1_1 = fn_R001856_5613_1(sec_r001856_1_1, sec_r001856_2_1, pub_r001856_3_1, pub_r001856_4_1);
  int helper_flow_1_2 = fn_R001856_5613_1(sec_r001856_1_2, sec_r001856_2_2, pub_r001856_3_2, pub_r001856_4_2);
  fn_R001856_5613_1_2(sec_r001856_1_1, sec_r001856_2_1, pub_r001856_3_1, pub_r001856_4_1, sec_r001856_1_2, sec_r001856_2_2, pub_r001856_3_2, pub_r001856_4_2);
  int helper_flow_2_1 = fn_R001856_5613_2(sec_r001856_2_1, sec_r001856_3_1, pub_r001856_4_1, pub_r001856_5_1, pub_r001856_6_1);
  int helper_flow_2_2 = fn_R001856_5613_2(sec_r001856_2_2, sec_r001856_3_2, pub_r001856_4_2, pub_r001856_5_2, pub_r001856_6_2);
  fn_R001856_5613_2_2(sec_r001856_2_1, sec_r001856_3_1, pub_r001856_4_1, pub_r001856_5_1, pub_r001856_6_1, sec_r001856_2_2, sec_r001856_3_2, pub_r001856_4_2, pub_r001856_5_2, pub_r001856_6_2);
  int helper_flow_3_1 = fn_R001856_5613_3(sec_r001856_3_1, pub_r001856_4_1);
  int helper_flow_3_2 = fn_R001856_5613_3(sec_r001856_3_2, pub_r001856_4_2);
  fn_R001856_5613_3_2(sec_r001856_3_1, pub_r001856_4_1, sec_r001856_3_2, pub_r001856_4_2);
  int helper_flow_4_1 = fn_R001856_5613_4(sec_r001856_4_1, pub_r001856_5_1, pub_r001856_6_1, pub_r001856_7_1, pub_r001856_8_1);
  int helper_flow_4_2 = fn_R001856_5613_4(sec_r001856_4_2, pub_r001856_5_2, pub_r001856_6_2, pub_r001856_7_2, pub_r001856_8_2);
  fn_R001856_5613_4_2(sec_r001856_4_1, pub_r001856_5_1, pub_r001856_6_1, pub_r001856_7_1, pub_r001856_8_1, sec_r001856_4_2, pub_r001856_5_2, pub_r001856_6_2, pub_r001856_7_2, pub_r001856_8_2);
  int helper_flow_5_1 = fn_R001856_5613_5(sec_r001856_5_1, pub_r001856_6_1, pub_r001856_7_1, pub_r001856_8_1);
  int helper_flow_5_2 = fn_R001856_5613_5(sec_r001856_5_2, pub_r001856_6_2, pub_r001856_7_2, pub_r001856_8_2);
  fn_R001856_5613_5_2(sec_r001856_5_1, pub_r001856_6_1, pub_r001856_7_1, pub_r001856_8_1, sec_r001856_5_2, pub_r001856_6_2, pub_r001856_7_2, pub_r001856_8_2);
  int helper_flow_6_1 = fn_R001856_5613_6(sec_r001856_6_1, pub_r001856_7_1);
  int helper_flow_6_2 = fn_R001856_5613_6(sec_r001856_6_2, pub_r001856_7_2);
  fn_R001856_5613_6_2(sec_r001856_6_1, pub_r001856_7_1, sec_r001856_6_2, pub_r001856_7_2);
  int helper_flow_7_1 = fn_R001856_5613_7(sec_r001856_7_1, sec_r001856_8_1);
  int helper_flow_7_2 = fn_R001856_5613_7(sec_r001856_7_2, sec_r001856_8_2);
  fn_R001856_5613_7_2(sec_r001856_7_1, sec_r001856_8_1, sec_r001856_7_2, sec_r001856_8_2);
  int stage_v_0_1 = ((sec_r001856_7_1 + (pub_r001856_8_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001856_7_2 + (pub_r001856_8_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001856_8_1 + (pub_r001856_9_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001856_8_2 + (pub_r001856_9_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001856_6_1 * 2) + 31) & 63;
  int stage_v_2_2 = ((pub_r001856_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001856_11_1 + (pub_r001856_10_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001856_11_2 + (pub_r001856_10_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((sec_r001856_0_1 + (pub_r001856_5_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001856_0_2 + (pub_r001856_5_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001856_6_1 + (pub_r001856_3_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001856_6_2 + (pub_r001856_3_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001856_7_1 * 2) + 31) & 63;
  int stage_v_6_2 = ((pub_r001856_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001856_5_1 * 2) + 32) & 63;
  int stage_v_7_2 = ((pub_r001856_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001856_12_1 * 2) + 25) & 63;
  int stage_v_8_2 = ((pub_r001856_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((sec_r001856_12_1 + (pub_r001856_11_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001856_12_2 + (pub_r001856_11_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001856_16_1 * 2) + 47) & 63;
  int stage_v_10_2 = ((pub_r001856_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((helper_flow_2_1 + (pub_r001856_6_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_2_2 + (pub_r001856_6_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001856_15_1 * 2) + 46) & 63;
  int stage_v_12_2 = ((pub_r001856_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001856_11_1 + (pub_r001856_12_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001856_11_2 + (pub_r001856_12_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001856_5_1 + (pub_r001856_2_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001856_5_2 + (pub_r001856_2_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001856_0_1 * 2) + 40) & 63;
  int stage_v_15_2 = ((pub_r001856_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001856_15_1 + (pub_r001856_4_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001856_15_2 + (pub_r001856_4_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001856_3_1 + (pub_r001856_11_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001856_3_2 + (pub_r001856_11_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001856_17_1 * 2) + 10) & 63;
  int stage_v_18_2 = ((pub_r001856_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((sec_r001856_1_1 + (pub_r001856_12_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001856_1_2 + (pub_r001856_12_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((helper_flow_5_1 + (pub_r001856_2_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_5_2 + (pub_r001856_2_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001856_9_1 + (pub_r001856_2_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001856_9_2 + (pub_r001856_2_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_3_1 + (pub_r001856_12_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_3_2 + (pub_r001856_12_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001856_16_1 * 2) + 14) & 63;
  int stage_v_23_2 = ((pub_r001856_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001856_6_1 * 2) + 7) & 63;
  int stage_v_24_2 = ((pub_r001856_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001856_6_1 * 2) + 11) & 63;
  int stage_v_25_2 = ((pub_r001856_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((helper_flow_0_1 + (pub_r001856_8_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_0_2 + (pub_r001856_8_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001856_1_1 + (pub_r001856_0_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001856_1_2 + (pub_r001856_0_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_9_1 + (pub_r001856_8_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_9_2 + (pub_r001856_8_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001856_13_1 * 2) + 11) & 63;
  int stage_v_29_2 = ((pub_r001856_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001856_12_1 * 2) + 11) & 63;
  int stage_v_30_2 = ((pub_r001856_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001856_16_1 + (pub_r001856_9_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001856_16_2 + (pub_r001856_9_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_22_1 + (pub_r001856_13_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_22_2 + (pub_r001856_13_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001856_1_1 + (pub_r001856_2_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001856_1_2 + (pub_r001856_2_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001856_6_1 + (pub_r001856_9_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001856_6_2 + (pub_r001856_9_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001856_4_1 + (pub_r001856_16_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001856_4_2 + (pub_r001856_16_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001856_14_1 * 2) + 25) & 63;
  int stage_v_36_2 = ((pub_r001856_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001856_12_1 * 2) + 50) & 63;
  int stage_v_37_2 = ((pub_r001856_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001856_6_1 + (pub_r001856_5_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001856_6_2 + (pub_r001856_5_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((stage_v_28_1 + (pub_r001856_17_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((stage_v_28_2 + (pub_r001856_17_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001856_13_1 * 2) + 37) & 63;
  int stage_v_40_2 = ((pub_r001856_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001856_12_1 * 2) + 16) & 63;
  int stage_v_41_2 = ((pub_r001856_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001856_9_1 * 2) + 47) & 63;
  int stage_v_42_2 = ((pub_r001856_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((stage_v_33_1 + (pub_r001856_1_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_33_2 + (pub_r001856_1_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001856_10_1 * 2) + 44) & 63;
  int stage_v_44_2 = ((pub_r001856_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((helper_flow_4_1 + (pub_r001856_6_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((helper_flow_4_2 + (pub_r001856_6_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_17_1 + (pub_r001856_8_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_17_2 + (pub_r001856_8_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001856_8_1 + (pub_r001856_10_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001856_8_2 + (pub_r001856_10_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001856_16_1 + (pub_r001856_11_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001856_16_2 + (pub_r001856_11_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001856_7_1 * 2) + 6) & 63;
  int stage_v_49_2 = ((pub_r001856_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((sec_r001856_3_1 + (pub_r001856_7_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001856_3_2 + (pub_r001856_7_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001856_12_1 * 2) + 39) & 63;
  int stage_v_51_2 = ((pub_r001856_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_20_1 + (pub_r001856_0_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_20_2 + (pub_r001856_0_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((sec_r001856_5_1 + (pub_r001856_14_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001856_5_2 + (pub_r001856_14_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001856_10_1 * 2) + 48) & 63;
  int stage_v_54_2 = ((pub_r001856_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001856_4_1 * 2) + 37) & 63;
  int stage_v_55_2 = ((pub_r001856_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((stage_v_16_1 + (pub_r001856_3_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_16_2 + (pub_r001856_3_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_47_1 + (pub_r001856_6_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_47_2 + (pub_r001856_6_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_19_1 + (pub_r001856_16_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_19_2 + (pub_r001856_16_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_45_1 + (pub_r001856_14_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_45_2 + (pub_r001856_14_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001856_4_1 * 2) + 11) & 63;
  int stage_v_60_2 = ((pub_r001856_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001856_3_1 * 2) + 9) & 63;
  int stage_v_61_2 = ((pub_r001856_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_59_1 + (pub_r001856_12_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_59_2 + (pub_r001856_12_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001856_17_1 * 2) + 19) & 63;
  int stage_v_63_2 = ((pub_r001856_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001856_10_1 + (pub_r001856_15_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001856_10_2 + (pub_r001856_15_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001856_9_1 + (pub_r001856_7_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001856_9_2 + (pub_r001856_7_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((helper_flow_1_1 + (pub_r001856_15_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((helper_flow_1_2 + (pub_r001856_15_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_48_1 + (pub_r001856_17_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_48_2 + (pub_r001856_17_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001856_2_1 * 2) + 6) & 63;
  int stage_v_68_2 = ((pub_r001856_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_35_1 + (pub_r001856_10_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_35_2 + (pub_r001856_10_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((sec_r001856_1_1 + (pub_r001856_7_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001856_1_2 + (pub_r001856_7_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001856_10_1 + (pub_r001856_3_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001856_10_2 + (pub_r001856_3_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001856_8_1 * 2) + 5) & 63;
  int stage_v_72_2 = ((pub_r001856_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001856_14_1 * 2) + 18) & 63;
  int stage_v_73_2 = ((pub_r001856_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_17_1 + (pub_r001856_7_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_17_2 + (pub_r001856_7_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001856_2_1 * 2) + 25) & 63;
  int stage_v_75_2 = ((pub_r001856_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_33_1 + (pub_r001856_14_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_33_2 + (pub_r001856_14_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((pub_r001856_10_1 * 2) + 22) & 63;
  int stage_v_77_2 = ((pub_r001856_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001856_16_1 * 2) + 14) & 63;
  int stage_v_78_2 = ((pub_r001856_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_34_1 + (pub_r001856_1_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_34_2 + (pub_r001856_1_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_20_1 + (pub_r001856_14_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_20_2 + (pub_r001856_14_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((helper_flow_0_1 + (pub_r001856_15_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((helper_flow_0_2 + (pub_r001856_15_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((helper_flow_5_1 + (pub_r001856_10_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((helper_flow_5_2 + (pub_r001856_10_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((sec_r001856_4_1 + (pub_r001856_1_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001856_4_2 + (pub_r001856_1_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((helper_flow_5_1 + (pub_r001856_16_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((helper_flow_5_2 + (pub_r001856_16_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_32_1 + (pub_r001856_10_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_32_2 + (pub_r001856_10_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_32_1 + (pub_r001856_13_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_32_2 + (pub_r001856_13_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((pub_r001856_12_1 * 2) + 44) & 63;
  int stage_v_87_2 = ((pub_r001856_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_70_1 + (pub_r001856_12_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_70_2 + (pub_r001856_12_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_70_1 + (pub_r001856_11_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_70_2 + (pub_r001856_11_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001856_17_1 * 2) + 14) & 63;
  int stage_v_90_2 = ((pub_r001856_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_65_1 + (pub_r001856_2_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_65_2 + (pub_r001856_2_2 * 2)) + 278) & 127;
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
  int stage_v_92_1 = ((stage_v_56_1 + (pub_r001856_14_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_56_2 + (pub_r001856_14_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_84_1 + (pub_r001856_2_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_84_2 + (pub_r001856_2_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((pub_r001856_4_1 * 2) + 22) & 63;
  int stage_v_94_2 = ((pub_r001856_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((stage_v_45_1 + (pub_r001856_15_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_45_2 + (pub_r001856_15_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001856_10_1 * 2) + 20) & 63;
  int stage_v_96_2 = ((pub_r001856_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_66_1 + (pub_r001856_5_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_66_2 + (pub_r001856_5_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_80_1 + (pub_r001856_14_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_80_2 + (pub_r001856_14_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_84_1 + (pub_r001856_6_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_84_2 + (pub_r001856_6_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001856_11_1 * 2) + 41) & 63;
  int stage_v_100_2 = ((pub_r001856_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_81_1 + (pub_r001856_12_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_81_2 + (pub_r001856_12_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001856_9_1 * 2) + 45) & 63;
  int stage_v_102_2 = ((pub_r001856_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_97_1 + (pub_r001856_16_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_97_2 + (pub_r001856_16_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_57_1 + (pub_r001856_3_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_57_2 + (pub_r001856_3_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001856_7_1 * 2) + 50) & 63;
  int stage_v_105_2 = ((pub_r001856_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_4_1 + (pub_r001856_2_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_4_2 + (pub_r001856_2_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001856_13_1 * 2) + 14) & 63;
  int stage_v_107_2 = ((pub_r001856_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001856_1_1 * 2) + 9) & 63;
  int stage_v_108_2 = ((pub_r001856_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001856_14_1 * 2) + 15) & 63;
  int stage_v_109_2 = ((pub_r001856_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001856_17_1 * 2) + 36) & 63;
  int stage_v_110_2 = ((pub_r001856_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_17_1 + (pub_r001856_11_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_17_2 + (pub_r001856_11_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_31_1 + (pub_r001856_6_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_31_2 + (pub_r001856_6_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_98_1 + (pub_r001856_6_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_98_2 + (pub_r001856_6_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_81_1 + (pub_r001856_0_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_81_2 + (pub_r001856_0_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((sec_r001856_11_1 + (pub_r001856_13_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001856_11_2 + (pub_r001856_13_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_70_1 + (pub_r001856_4_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_70_2 + (pub_r001856_4_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((sec_r001856_10_1 + (pub_r001856_10_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((sec_r001856_10_2 + (pub_r001856_10_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_45_1 + (pub_r001856_16_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_45_2 + (pub_r001856_16_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((helper_flow_3_1 + (pub_r001856_6_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((helper_flow_3_2 + (pub_r001856_6_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001856_5_1 * 2) + 7) & 63;
  int stage_v_120_2 = ((pub_r001856_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((sec_r001856_3_1 + (pub_r001856_0_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((sec_r001856_3_2 + (pub_r001856_0_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_14_1 + (pub_r001856_16_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_14_2 + (pub_r001856_16_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001856_11_1 * 2) + 21) & 63;
  int stage_v_123_2 = ((pub_r001856_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_45_1 + (pub_r001856_13_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_45_2 + (pub_r001856_13_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001856_11_1 * 2) + 46) & 63;
  int stage_v_125_2 = ((pub_r001856_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((sec_r001856_7_1 + (pub_r001856_10_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((sec_r001856_7_2 + (pub_r001856_10_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001856_4_1 * 2) + 7) & 63;
  int stage_v_127_2 = ((pub_r001856_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001856_6_1 * 2) + 42) & 63;
  int stage_v_128_2 = ((pub_r001856_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001856_15_1 * 2) + 20) & 63;
  int stage_v_129_2 = ((pub_r001856_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_32_1 + (pub_r001856_3_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_32_2 + (pub_r001856_3_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((helper_flow_4_1 + (pub_r001856_10_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((helper_flow_4_2 + (pub_r001856_10_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001856_14_1 * 2) + 31) & 63;
  int stage_v_132_2 = ((pub_r001856_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((sec_r001856_1_1 + (pub_r001856_11_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001856_1_2 + (pub_r001856_11_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001856_7_1 * 2) + 6) & 63;
  int stage_v_134_2 = ((pub_r001856_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_113_1 + (pub_r001856_17_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_113_2 + (pub_r001856_17_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001856_2_1 * 2) + 37) & 63;
  int stage_v_136_2 = ((pub_r001856_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_130_1 + (pub_r001856_11_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_130_2 + (pub_r001856_11_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_52_1 + (pub_r001856_15_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_52_2 + (pub_r001856_15_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001856_8_1 * 2) + 5) & 63;
  int stage_v_139_2 = ((pub_r001856_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((sec_r001856_10_1 + (pub_r001856_7_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001856_10_2 + (pub_r001856_7_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_66_1 + (pub_r001856_9_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_66_2 + (pub_r001856_9_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((helper_flow_1_1 + (pub_r001856_6_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((helper_flow_1_2 + (pub_r001856_6_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001856_4_1 * 2) + 7) & 63;
  int stage_v_143_2 = ((pub_r001856_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_118_1 + (pub_r001856_15_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_118_2 + (pub_r001856_15_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_56_1 + (pub_r001856_14_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_56_2 + (pub_r001856_14_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001856_10_1 * 2) + 39) & 63;
  int stage_v_146_2 = ((pub_r001856_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_28_1 + (pub_r001856_16_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_28_2 + (pub_r001856_16_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001856_6_1 * 2) + 15) & 63;
  int stage_v_148_2 = ((pub_r001856_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001856_5_1 * 2) + 33) & 63;
  int stage_v_149_2 = ((pub_r001856_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001856_8_1 * 2) + 8) & 63;
  int stage_v_150_2 = ((pub_r001856_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001856_10_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001856_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001856_2_1 * 2) + 18) & 63;
  int stage_v_152_2 = ((pub_r001856_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_4_1 + (pub_r001856_12_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_4_2 + (pub_r001856_12_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_138_1 + (pub_r001856_13_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_138_2 + (pub_r001856_13_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001856_4_1 * 2) + 20) & 63;
  int stage_v_155_2 = ((pub_r001856_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001856_16_1 * 2) + 7) & 63;
  int stage_v_156_2 = ((pub_r001856_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_111_1 + (pub_r001856_12_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_111_2 + (pub_r001856_12_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001856_1_1 * 2) + 7) & 63;
  int stage_v_158_2 = ((pub_r001856_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((helper_flow_4_1 + (pub_r001856_16_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((helper_flow_4_2 + (pub_r001856_16_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001856_10_1 * 2) + 43) & 63;
  int stage_v_160_2 = ((pub_r001856_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_81_1 + (pub_r001856_16_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_81_2 + (pub_r001856_16_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001856_8_1 * 2) + 42) & 63;
  int stage_v_162_2 = ((pub_r001856_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_113_1 + (pub_r001856_0_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_113_2 + (pub_r001856_0_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001856_9_1 * 2) + 32) & 63;
  int stage_v_164_2 = ((pub_r001856_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001856_5_1 * 2) + 8) & 63;
  int stage_v_165_2 = ((pub_r001856_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_140_1 + (pub_r001856_9_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_140_2 + (pub_r001856_9_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_93_1 + (pub_r001856_8_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_93_2 + (pub_r001856_8_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_118_1 + (pub_r001856_8_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_118_2 + (pub_r001856_8_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_161_1 + (pub_r001856_2_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_161_2 + (pub_r001856_2_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001856_14_1 * 2) + 14) & 63;
  int stage_v_170_2 = ((pub_r001856_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_169_1 + (pub_r001856_6_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_169_2 + (pub_r001856_6_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_171_1 + (pub_r001856_14_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_171_2 + (pub_r001856_14_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_20_1 + (pub_r001856_12_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_20_2 + (pub_r001856_12_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_153_1 + (pub_r001856_4_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_153_2 + (pub_r001856_4_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001856_6_1 * 2) + 25) & 63;
  int stage_v_175_2 = ((pub_r001856_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001856_6_1 * 2) + 50) & 63;
  int stage_v_176_2 = ((pub_r001856_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_153_1 + (pub_r001856_5_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_153_2 + (pub_r001856_5_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_135_1 + (pub_r001856_1_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_135_2 + (pub_r001856_1_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_31_1 + (pub_r001856_15_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_31_2 + (pub_r001856_15_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001856_16_1 * 2) + 29) & 63;
  int stage_v_180_2 = ((pub_r001856_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_34_1 + (pub_r001856_9_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_34_2 + (pub_r001856_9_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_66_1 + (pub_r001856_11_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_66_2 + (pub_r001856_11_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_112_1 + (pub_r001856_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_112_2 + (pub_r001856_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_111_1 + (pub_r001856_7_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_111_2 + (pub_r001856_7_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001856_13_1 * 2) + 40) & 63;
  int stage_v_185_2 = ((pub_r001856_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((sec_r001856_9_1 + (pub_r001856_11_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((sec_r001856_9_2 + (pub_r001856_11_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_39_1 + (pub_r001856_4_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_39_2 + (pub_r001856_4_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001856_7_1 * 2) + 44) & 63;
  int stage_v_188_2 = ((pub_r001856_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001856_16_1 * 2) + 19) & 63;
  int stage_v_189_2 = ((pub_r001856_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001856_3_1 * 2) + 5) & 63;
  int stage_v_190_2 = ((pub_r001856_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001856_11_1 * 2) + 36) & 63;
  int stage_v_191_2 = ((pub_r001856_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001856_9_1 * 2) + 23) & 63;
  int stage_v_192_2 = ((pub_r001856_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_95_1 + (pub_r001856_17_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_95_2 + (pub_r001856_17_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_4_1 + (pub_r001856_0_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_4_2 + (pub_r001856_0_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_186_1 + (pub_r001856_6_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_186_2 + (pub_r001856_6_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_33_1 + (pub_r001856_15_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_33_2 + (pub_r001856_15_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_193_1 + (pub_r001856_0_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_193_2 + (pub_r001856_0_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001856_13_1 * 2) + 21) & 63;
  int stage_v_198_2 = ((pub_r001856_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001856_7_1 * 2) + 40) & 63;
  int stage_v_199_2 = ((pub_r001856_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_172_1 + (pub_r001856_7_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_172_2 + (pub_r001856_7_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_28_1 + (pub_r001856_15_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_28_2 + (pub_r001856_15_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001856_5_1 * 2) + 6) & 63;
  int stage_v_202_2 = ((pub_r001856_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001856_12_1 * 2) + 28) & 63;
  int stage_v_203_2 = ((pub_r001856_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001856_10_1 * 2) + 32) & 63;
  int stage_v_204_2 = ((pub_r001856_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_4_1 + (pub_r001856_8_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_4_2 + (pub_r001856_8_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_32_1 + (pub_r001856_5_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_32_2 + (pub_r001856_5_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001856_9_1 * 2) + 40) & 63;
  int stage_v_207_2 = ((pub_r001856_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_171_1 + (pub_r001856_12_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_171_2 + (pub_r001856_12_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001856_1_1 * 2) + 20) & 63;
  int stage_v_209_2 = ((pub_r001856_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_69_1 + (pub_r001856_7_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_69_2 + (pub_r001856_7_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001856_15_1 * 2) + 8) & 63;
  int stage_v_211_2 = ((pub_r001856_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_20_1 + (pub_r001856_1_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_20_2 + (pub_r001856_1_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_11_1 + (pub_r001856_7_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_11_2 + (pub_r001856_7_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((sec_r001856_3_1 + (pub_r001856_14_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((sec_r001856_3_2 + (pub_r001856_14_2 * 2)) + 647) & 127;
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
  int stage_v_215_1 = ((stage_v_177_1 + (pub_r001856_9_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_177_2 + (pub_r001856_9_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_205_1 + (pub_r001856_11_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_205_2 + (pub_r001856_11_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((pub_r001856_13_1 * 2) + 27) & 63;
  int stage_v_217_2 = ((pub_r001856_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_91_1 + (pub_r001856_17_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_91_2 + (pub_r001856_17_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_133_1 + (pub_r001856_13_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_133_2 + (pub_r001856_13_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_53_1 + (pub_r001856_17_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_53_2 + (pub_r001856_17_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((pub_r001856_9_1 * 2) + 30) & 63;
  int stage_v_221_2 = ((pub_r001856_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((sec_r001856_1_1 + (pub_r001856_7_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((sec_r001856_1_2 + (pub_r001856_7_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_124_1 + (pub_r001856_16_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_124_2 + (pub_r001856_16_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001856_10_1 * 2) + 20) & 63;
  int stage_v_224_2 = ((pub_r001856_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_131_1 + (pub_r001856_9_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_131_2 + (pub_r001856_9_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((sec_r001856_15_1 + (pub_r001856_3_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((sec_r001856_15_2 + (pub_r001856_3_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_166_1 + (pub_r001856_13_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_166_2 + (pub_r001856_13_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001856_1_1 * 2) + 27) & 63;
  int stage_v_228_2 = ((pub_r001856_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001856_16_1 * 2) + 29) & 63;
  int stage_v_229_2 = ((pub_r001856_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((helper_flow_4_1 + (pub_r001856_3_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((helper_flow_4_2 + (pub_r001856_3_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_161_1 + (pub_r001856_7_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_161_2 + (pub_r001856_7_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_131_1 + (pub_r001856_7_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_131_2 + (pub_r001856_7_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_187_1 + (pub_r001856_1_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_187_2 + (pub_r001856_1_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_117_1 + (pub_r001856_13_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_117_2 + (pub_r001856_13_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((pub_r001856_13_1 * 2) + 28) & 63;
  int stage_v_235_2 = ((pub_r001856_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((stage_v_117_1 + (pub_r001856_13_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_117_2 + (pub_r001856_13_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((stage_v_226_1 + (pub_r001856_11_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_226_2 + (pub_r001856_11_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((stage_v_22_1 + (pub_r001856_17_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_22_2 + (pub_r001856_17_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_230_1 + (pub_r001856_13_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_230_2 + (pub_r001856_13_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_193_1 + (pub_r001856_7_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_193_2 + (pub_r001856_7_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_130_1 + (pub_r001856_14_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_130_2 + (pub_r001856_14_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_43_1 + (pub_r001856_8_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_43_2 + (pub_r001856_8_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((sec_r001856_4_1 + (pub_r001856_5_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((sec_r001856_4_2 + (pub_r001856_5_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((pub_r001856_5_1 * 2) + 5) & 63;
  int stage_v_244_2 = ((pub_r001856_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001856_6_1 * 2) + 20) & 63;
  int stage_v_245_2 = ((pub_r001856_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_104_1 + (pub_r001856_11_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_104_2 + (pub_r001856_11_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((pub_r001856_14_1 * 2) + 8) & 63;
  int stage_v_247_2 = ((pub_r001856_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001856_2_1 * 2) + 35) & 63;
  int stage_v_248_2 = ((pub_r001856_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_184_1 + (pub_r001856_5_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_184_2 + (pub_r001856_5_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((stage_v_97_1 + (pub_r001856_14_1 * 2)) + 755) & 127;
  int stage_v_250_2 = ((stage_v_97_2 + (pub_r001856_14_2 * 2)) + 755) & 127;
  if (stage_v_250_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_250_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_250_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_250_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_251_1 = ((pub_r001856_10_1 * 2) + 38) & 63;
  int stage_v_251_2 = ((pub_r001856_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001856_17_1 * 2) + 49) & 63;
  int stage_v_252_2 = ((pub_r001856_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001856_6_1 * 2) + 46) & 63;
  int stage_v_253_2 = ((pub_r001856_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001856_8_1 * 2) + 26) & 63;
  int stage_v_254_2 = ((pub_r001856_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001856_7_1 * 2) + 43) & 63;
  int stage_v_255_2 = ((pub_r001856_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_216_1 + (pub_r001856_17_1 * 2)) + 773) & 127;
  int stage_v_256_2 = ((stage_v_216_2 + (pub_r001856_17_2 * 2)) + 773) & 127;
  if (stage_v_256_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_256_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_256_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_256_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_256_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_256_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_256_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_256_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_257_1 = ((pub_r001856_1_1 * 2) + 19) & 63;
  int stage_v_257_2 = ((pub_r001856_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((stage_v_28_1 + (pub_r001856_16_1 * 2)) + 779) & 127;
  int stage_v_258_2 = ((stage_v_28_2 + (pub_r001856_16_2 * 2)) + 779) & 127;
  if (stage_v_258_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_258_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_258_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_258_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001856_5_1 != sec_r001856_5_2);
  __CPROVER_assume(pub_r001856_8_1 == pub_r001856_8_2);
  __CPROVER_assume(sec_r001856_11_1 != sec_r001856_11_2);
  __CPROVER_assume(pub_r001856_5_1 == pub_r001856_5_2);
  __CPROVER_assume(sec_r001856_14_1 != sec_r001856_14_2);
  __CPROVER_assume(sec_r001856_15_1 != sec_r001856_15_2);
  __CPROVER_assume(pub_r001856_6_1 == pub_r001856_6_2);
  __CPROVER_assume(pub_r001856_14_1 == pub_r001856_14_2);
  __CPROVER_assume(pub_r001856_16_1 == pub_r001856_16_2);
  __CPROVER_assume(pub_r001856_7_1 == pub_r001856_7_2);
  __CPROVER_assume(sec_r001856_3_1 != sec_r001856_3_2);
  __CPROVER_assume(sec_r001856_4_1 != sec_r001856_4_2);
  __CPROVER_assume(sec_r001856_13_1 != sec_r001856_13_2);
  __CPROVER_assume(pub_r001856_11_1 == pub_r001856_11_2);
  __CPROVER_assume(sec_r001856_1_1 != sec_r001856_1_2);
  __CPROVER_assume(pub_r001856_1_1 == pub_r001856_1_2);
  __CPROVER_assume(pub_r001856_12_1 == pub_r001856_12_2);
  __CPROVER_assume(pub_r001856_17_1 == pub_r001856_17_2);
  __CPROVER_assume(pub_r001856_4_1 == pub_r001856_4_2);
  __CPROVER_assume(pub_r001856_9_1 == pub_r001856_9_2);
  __CPROVER_assume(sec_r001856_9_1 != sec_r001856_9_2);
  __CPROVER_assume(pub_r001856_15_1 == pub_r001856_15_2);
  __CPROVER_assume(sec_r001856_16_1 != sec_r001856_16_2);
  __CPROVER_assume(pub_r001856_3_1 == pub_r001856_3_2);
  __CPROVER_assume(pub_r001856_10_1 == pub_r001856_10_2);
  __CPROVER_assume(pub_r001856_13_1 == pub_r001856_13_2);
  __CPROVER_assume(pub_r001856_2_1 == pub_r001856_2_2);
  __CPROVER_assume(sec_r001856_12_1 != sec_r001856_12_2);
  __CPROVER_assume(pub_r001856_0_1 == pub_r001856_0_2);
  __CPROVER_assume(sec_r001856_7_1 != sec_r001856_7_2);
  __CPROVER_assume(sec_r001856_2_1 != sec_r001856_2_2);
  __CPROVER_assume(sec_r001856_10_1 != sec_r001856_10_2);
  __CPROVER_assume(sec_r001856_6_1 != sec_r001856_6_2);
  __CPROVER_assume(sec_r001856_8_1 != sec_r001856_8_2);
  __CPROVER_assume(sec_r001856_0_1 != sec_r001856_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
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
}


