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
struct EventLog_R001530_3013_0
{
  unsigned char timestamp;
  int code;
  unsigned char signature;
  int buffer[3];
};
struct AudioFrame_R001530_3013_1
{
  short envelope;
  int peak;
  int rms;
  int buffer[3];
};
struct Vector3D_R001530_3013_2
{
  short coord_z;
  unsigned char pitch;
  int heading;
  int coord_x;
  int coord_y;
  int norm_sq;
  int buffer[3];
};
struct SensorNode_R001530_3013_3
{
  short threshold;
  int gain;
  unsigned char offset;
  int buffer[3];
};
union PacketPayload_R001530_3013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001530_3013_1
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
void fn_R001530_3013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001530_3013_0 st_1 = {0};
  struct EventLog_R001530_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_62_1 = 0;
  int quantum_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_62_1 = ((quantum_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_62_2 = ((quantum_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_62_1) & 127;
    acc_2 = (acc_2 + quantum_62_2) & 127;
  }

  int weight_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_21_1) & 63;
  aux_2 = (aux_2 + weight_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_78_1)
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

  switch (phase_78_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_62_1 == quantum_62_2);
  assert(weight_21_1 == weight_21_2);
  assert(phase_78_1 == phase_78_2);
}

int fn_R001530_3013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001530_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_62 = ((quantum_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_62) & 127;
  }

  int weight_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_21) & 63;
  acc ^= aux;
  int phase_78 = (aux + st.buffer[1]) & 3;
  switch (phase_78)
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

void fn_R001530_3013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_64_1)
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

  switch (parity_64_2)
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

  int weight_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_46_1) & 63;
  aux_2 = (aux_2 + weight_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_93_1 = 0;
  int quotient_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_93_1 = ((quotient_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_93_2 = ((quotient_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_93_1) & 127;
    acc_2 = (acc_2 + quotient_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_64_1 == parity_64_2);
  assert(weight_46_1 == weight_46_2);
  assert(quotient_93_1 == quotient_93_2);
}

int fn_R001530_3013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_64 = (aux + st.buffer[1]) & 3;
  switch (parity_64)
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

  int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_93 = ((quotient_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001530_3013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st_1 = {0};
  struct Vector3D_R001530_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_16_1 > 49)
  {
    acc_1 = ((acc_1 + (parity_16_1 * 2)) + 5) & 127;
    aux_1 ^= parity_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_16_2 > 49)
  {
    acc_2 = ((acc_2 + (parity_16_2 * 2)) + 5) & 127;
    aux_2 ^= parity_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_98_1 = 0;
  int delta_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_98_1 = ((delta_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_98_2 = ((delta_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_98_1) & 127;
    acc_2 = (acc_2 + delta_98_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_82_1 = local_arr_1[aux_1 % 3];
  int pivot_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_16_1 == parity_16_2);
  assert(delta_98_1 == delta_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_82_1 == pivot_82_2);
}

int fn_R001530_3013_2(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_16 > 49)
  {
    acc = ((acc + (parity_16 * 2)) + 5) & 127;
    aux ^= parity_16 & 15;
  }
  else
  {
    acc = ((acc - parity_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_98 = ((delta_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_98) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_82 = local_arr[aux % 3];
  acc = (acc + (pivot_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001530_3013_0 st_1 = {0};
  struct EventLog_R001530_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_58_1 = local_arr_1[aux_1 % 3];
  int margin_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_58_1 == margin_58_2);
}

int fn_R001530_3013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001530_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int margin_58 = local_arr[aux % 3];
  acc = (acc + (margin_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_72_1 = 0;
  int vector_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_72_1 = ((vector_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_72_2 = ((vector_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_72_1) & 127;
    acc_2 = (acc_2 + vector_72_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_43_1 = local_arr_1[aux_1 % 3];
  int mask_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_43_2 * 2)) & 127;
  int residue_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_12_1)
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

  switch (residue_12_2)
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

  int tracker_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_36_1) & 63;
  aux_2 = (aux_2 + tracker_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_72_1 == vector_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_43_1 == mask_43_2);
  assert(residue_12_1 == residue_12_2);
  assert(tracker_36_1 == tracker_36_2);
}

int fn_R001530_3013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_72 = ((vector_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_72) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_43 = local_arr[aux % 3];
  acc = (acc + (mask_43 * 2)) & 127;
  int residue_12 = (aux + st.buffer[1]) & 3;
  switch (residue_12)
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

  int tracker_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_36) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001530_3013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_12_1 = local_arr_1[aux_1 % 3];
  int scale_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_12_2 * 2)) & 127;
  int segment_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_87_1)
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

  switch (segment_87_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_12_1 == scale_12_2);
  assert(segment_87_1 == segment_87_2);
}

int fn_R001530_3013_5(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int scale_12 = local_arr[aux % 3];
  acc = (acc + (scale_12 * 2)) & 127;
  int segment_87 = (aux + st.buffer[1]) & 3;
  switch (segment_87)
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

void fn_R001530_3013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_36_1) & 63;
  aux_2 = (aux_2 + pivot_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_86_1 = local_arr_1[aux_1 % 3];
  int metric_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_36_1 == pivot_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_86_1 == metric_86_2);
}

int fn_R001530_3013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_86 = local_arr[aux % 3];
  acc = (acc + (metric_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st_1 = {0};
  struct SensorNode_R001530_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  int mask_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_22_1)
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

  switch (mask_22_2)
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

  int anchor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_54_1 > 24)
  {
    acc_1 = ((acc_1 + (anchor_54_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_54_2 > 24)
  {
    acc_2 = ((acc_2 + (anchor_54_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
  assert(mask_22_1 == mask_22_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R001530_3013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  int mask_22 = (aux + st.buffer[1]) & 3;
  switch (mask_22)
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

  int anchor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_54 > 24)
  {
    acc = ((acc + (anchor_54 * 2)) + 5) & 127;
    aux ^= anchor_54 & 15;
  }
  else
  {
    acc = ((acc - anchor_54) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st_1 = {0};
  struct SensorNode_R001530_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int parity_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_74_1) & 63;
  aux_2 = (aux_2 + parity_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_55_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_55_1 * 2)) + 5) & 127;
    aux_1 ^= sample_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_55_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_55_2 * 2)) + 5) & 127;
    aux_2 ^= sample_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_80_1)
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

  switch (metric_80_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_74_1 == parity_74_2);
  assert(sample_55_1 == sample_55_2);
  assert(metric_80_1 == metric_80_2);
}

int fn_R001530_3013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_74) & 63;
  acc ^= aux;
  int sample_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_55 > 42)
  {
    acc = ((acc + (sample_55 * 2)) + 5) & 127;
    aux ^= sample_55 & 15;
  }
  else
  {
    acc = ((acc - sample_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_80 = (aux + st.buffer[1]) & 3;
  switch (metric_80)
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

void fn_R001530_3013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st_1 = {0};
  struct Vector3D_R001530_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_67_1 = 0;
  int damping_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_67_1 = ((damping_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_67_2 = ((damping_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_67_1) & 127;
    acc_2 = (acc_2 + damping_67_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_73_1 = local_arr_1[aux_1 % 3];
  int parity_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_73_2 * 2)) & 127;
  int tracker_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_21_1)
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

  switch (tracker_21_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_67_1 == damping_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_73_1 == parity_73_2);
  assert(tracker_21_1 == tracker_21_2);
}

int fn_R001530_3013_9(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_67 = ((damping_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_67) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_73 = local_arr[aux % 3];
  acc = (acc + (parity_73 * 2)) & 127;
  int tracker_21 = (aux + st.buffer[1]) & 3;
  switch (tracker_21)
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

void fn_R001530_3013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int vector_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_58_1 > 43)
  {
    acc_1 = ((acc_1 + (vector_58_1 * 2)) + 5) & 127;
    aux_1 ^= vector_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_58_2 > 43)
  {
    acc_2 = ((acc_2 + (vector_58_2 * 2)) + 5) & 127;
    aux_2 ^= vector_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_58_1 == vector_58_2);
}

int fn_R001530_3013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int vector_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_58 > 43)
  {
    acc = ((acc + (vector_58 * 2)) + 5) & 127;
    aux ^= vector_58 & 15;
  }
  else
  {
    acc = ((acc - vector_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st_1 = {0};
  struct Vector3D_R001530_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_31_1) & 63;
  aux_2 = (aux_2 + damping_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_37_1 = local_arr_1[aux_1 % 3];
  int parity_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_31_1 == damping_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_37_1 == parity_37_2);
}

int fn_R001530_3013_11(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_37 = local_arr[aux % 3];
  acc = (acc + (parity_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tracker_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_96_1) & 63;
  aux_2 = (aux_2 + tracker_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_26_1 = 0;
  int offset_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_26_1 = ((offset_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_26_2 = ((offset_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_26_1) & 127;
    acc_2 = (acc_2 + offset_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_96_1 == tracker_96_2);
  assert(offset_26_1 == offset_26_2);
}

int fn_R001530_3013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tracker_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_96) & 63;
  acc ^= aux;
  int offset_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_26 = ((offset_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001530_3013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st_1 = {0};
  struct Vector3D_R001530_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_42_1 = local_arr_1[aux_1 % 3];
  int vector_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_42_2 * 2)) & 127;
  int residue_88_1 = 0;
  int residue_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_88_1 = ((residue_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_88_2 = ((residue_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_88_1) & 127;
    acc_2 = (acc_2 + residue_88_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_42_1 == vector_42_2);
  assert(residue_88_1 == residue_88_2);
}

int fn_R001530_3013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001530_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int vector_42 = local_arr[aux % 3];
  acc = (acc + (vector_42 * 2)) & 127;
  int residue_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_88 = ((residue_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_88) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_76_1 = local_arr_1[aux_1 % 3];
  int checksum_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_76_2 * 2)) & 127;
  int margin_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_10_1) & 63;
  aux_2 = (aux_2 + margin_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_52_1 = 0;
  int metric_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_52_1 = ((metric_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_52_2 = ((metric_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_52_1) & 127;
    acc_2 = (acc_2 + metric_52_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_76_1 == checksum_76_2);
  assert(margin_10_1 == margin_10_2);
  assert(metric_52_1 == metric_52_2);
}

int fn_R001530_3013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int checksum_76 = local_arr[aux % 3];
  acc = (acc + (checksum_76 * 2)) & 127;
  int margin_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_10) & 63;
  acc ^= aux;
  int metric_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_52 = ((metric_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_52) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001530_3013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st_1 = {0};
  struct SensorNode_R001530_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_90_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_90_1 * 2)) + 5) & 127;
    aux_1 ^= factor_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_90_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_90_2 * 2)) + 5) & 127;
    aux_2 ^= factor_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_90_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_90_1 == factor_90_2);
}

int fn_R001530_3013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_90 > 19)
  {
    acc = ((acc + (factor_90 * 2)) + 5) & 127;
    aux ^= factor_90 & 15;
  }
  else
  {
    acc = ((acc - factor_90) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001530_3013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st_1 = {0};
  struct AudioFrame_R001530_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_64_1)
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

  switch (damping_64_2)
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

  int vector_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_73_1 > 15)
  {
    acc_1 = ((acc_1 + (vector_73_1 * 2)) + 5) & 127;
    aux_1 ^= vector_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_73_2 > 15)
  {
    acc_2 = ((acc_2 + (vector_73_2 * 2)) + 5) & 127;
    aux_2 ^= vector_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_64_1 == damping_64_2);
  assert(vector_73_1 == vector_73_2);
}

int fn_R001530_3013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001530_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_64 = (aux + st.buffer[1]) & 3;
  switch (damping_64)
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

  int vector_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_73 > 15)
  {
    acc = ((acc + (vector_73 * 2)) + 5) & 127;
    aux ^= vector_73 & 15;
  }
  else
  {
    acc = ((acc - vector_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001530_3013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st_1 = {0};
  struct SensorNode_R001530_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_80_1 > 50)
  {
    acc_1 = ((acc_1 + (residue_80_1 * 2)) + 5) & 127;
    aux_1 ^= residue_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_80_2 > 50)
  {
    acc_2 = ((acc_2 + (residue_80_2 * 2)) + 5) & 127;
    aux_2 ^= residue_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_39_1 = local_arr_1[aux_1 % 3];
  int margin_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_80_1 == residue_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_39_1 == margin_39_2);
}

int fn_R001530_3013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001530_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_80 > 50)
  {
    acc = ((acc + (residue_80 * 2)) + 5) & 127;
    aux ^= residue_80 & 15;
  }
  else
  {
    acc = ((acc - residue_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_39 = local_arr[aux % 3];
  acc = (acc + (margin_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001530_0_1;
  int sec_r001530_0_2;
  int sec_r001530_1_1;
  int sec_r001530_1_2;
  int sec_r001530_2_1;
  int sec_r001530_2_2;
  int sec_r001530_3_1;
  int sec_r001530_3_2;
  int sec_r001530_4_1;
  int sec_r001530_4_2;
  int sec_r001530_5_1;
  int sec_r001530_5_2;
  int sec_r001530_6_1;
  int sec_r001530_6_2;
  int sec_r001530_7_1;
  int sec_r001530_7_2;
  int sec_r001530_8_1;
  int sec_r001530_8_2;
  int sec_r001530_9_1;
  int sec_r001530_9_2;
  int sec_r001530_10_1;
  int sec_r001530_10_2;
  int sec_r001530_11_1;
  int sec_r001530_11_2;
  int sec_r001530_12_1;
  int sec_r001530_12_2;
  int sec_r001530_13_1;
  int sec_r001530_13_2;
  int sec_r001530_14_1;
  int sec_r001530_14_2;
  int sec_r001530_15_1;
  int sec_r001530_15_2;
  int sec_r001530_16_1;
  int sec_r001530_16_2;
  int sec_r001530_17_1;
  int sec_r001530_17_2;
  int sec_r001530_18_1;
  int sec_r001530_18_2;
  int sec_r001530_19_1;
  int sec_r001530_19_2;
  int sec_r001530_20_1;
  int sec_r001530_20_2;
  int sec_r001530_21_1;
  int sec_r001530_21_2;
  int sec_r001530_22_1;
  int sec_r001530_22_2;
  int sec_r001530_23_1;
  int sec_r001530_23_2;
  int pub_r001530_0_1;
  int pub_r001530_0_2;
  int pub_r001530_1_1;
  int pub_r001530_1_2;
  int pub_r001530_2_1;
  int pub_r001530_2_2;
  int pub_r001530_3_1;
  int pub_r001530_3_2;
  int pub_r001530_4_1;
  int pub_r001530_4_2;
  int pub_r001530_5_1;
  int pub_r001530_5_2;
  int pub_r001530_6_1;
  int pub_r001530_6_2;
  int pub_r001530_7_1;
  int pub_r001530_7_2;
  int pub_r001530_8_1;
  int pub_r001530_8_2;
  int pub_r001530_9_1;
  int pub_r001530_9_2;
  int pub_r001530_10_1;
  int pub_r001530_10_2;
  int pub_r001530_11_1;
  int pub_r001530_11_2;
  int pub_r001530_12_1;
  int pub_r001530_12_2;
  int pub_r001530_13_1;
  int pub_r001530_13_2;
  int pub_r001530_14_1;
  int pub_r001530_14_2;
  int pub_r001530_15_1;
  int pub_r001530_15_2;
  int pub_r001530_16_1;
  int pub_r001530_16_2;
  int pub_r001530_17_1;
  int pub_r001530_17_2;
  int pub_r001530_18_1;
  int pub_r001530_18_2;
  int pub_r001530_19_1;
  int pub_r001530_19_2;
  int pub_r001530_20_1;
  int pub_r001530_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001530_0_1 >= (-100)) && (pub_r001530_0_1 <= 100));
  __CPROVER_assume((pub_r001530_0_2 >= (-100)) && (pub_r001530_0_2 <= 100));
  __CPROVER_assume((pub_r001530_1_1 >= (-100)) && (pub_r001530_1_1 <= 100));
  __CPROVER_assume((pub_r001530_1_2 >= (-100)) && (pub_r001530_1_2 <= 100));
  __CPROVER_assume((pub_r001530_2_1 >= (-100)) && (pub_r001530_2_1 <= 100));
  __CPROVER_assume((pub_r001530_2_2 >= (-100)) && (pub_r001530_2_2 <= 100));
  __CPROVER_assume((pub_r001530_3_1 >= (-100)) && (pub_r001530_3_1 <= 100));
  __CPROVER_assume((pub_r001530_3_2 >= (-100)) && (pub_r001530_3_2 <= 100));
  __CPROVER_assume((pub_r001530_4_1 >= (-100)) && (pub_r001530_4_1 <= 100));
  __CPROVER_assume((pub_r001530_4_2 >= (-100)) && (pub_r001530_4_2 <= 100));
  __CPROVER_assume((pub_r001530_5_1 >= (-100)) && (pub_r001530_5_1 <= 100));
  __CPROVER_assume((pub_r001530_5_2 >= (-100)) && (pub_r001530_5_2 <= 100));
  __CPROVER_assume((pub_r001530_6_1 >= (-100)) && (pub_r001530_6_1 <= 100));
  __CPROVER_assume((pub_r001530_6_2 >= (-100)) && (pub_r001530_6_2 <= 100));
  __CPROVER_assume((pub_r001530_7_1 >= (-100)) && (pub_r001530_7_1 <= 100));
  __CPROVER_assume((pub_r001530_7_2 >= (-100)) && (pub_r001530_7_2 <= 100));
  __CPROVER_assume((pub_r001530_8_1 >= (-100)) && (pub_r001530_8_1 <= 100));
  __CPROVER_assume((pub_r001530_8_2 >= (-100)) && (pub_r001530_8_2 <= 100));
  __CPROVER_assume((pub_r001530_9_1 >= (-100)) && (pub_r001530_9_1 <= 100));
  __CPROVER_assume((pub_r001530_9_2 >= (-100)) && (pub_r001530_9_2 <= 100));
  __CPROVER_assume((pub_r001530_10_1 >= (-100)) && (pub_r001530_10_1 <= 100));
  __CPROVER_assume((pub_r001530_10_2 >= (-100)) && (pub_r001530_10_2 <= 100));
  __CPROVER_assume((pub_r001530_11_1 >= (-100)) && (pub_r001530_11_1 <= 100));
  __CPROVER_assume((pub_r001530_11_2 >= (-100)) && (pub_r001530_11_2 <= 100));
  __CPROVER_assume((pub_r001530_12_1 >= (-100)) && (pub_r001530_12_1 <= 100));
  __CPROVER_assume((pub_r001530_12_2 >= (-100)) && (pub_r001530_12_2 <= 100));
  __CPROVER_assume((pub_r001530_13_1 >= (-100)) && (pub_r001530_13_1 <= 100));
  __CPROVER_assume((pub_r001530_13_2 >= (-100)) && (pub_r001530_13_2 <= 100));
  __CPROVER_assume((pub_r001530_14_1 >= (-100)) && (pub_r001530_14_1 <= 100));
  __CPROVER_assume((pub_r001530_14_2 >= (-100)) && (pub_r001530_14_2 <= 100));
  __CPROVER_assume((pub_r001530_15_1 >= (-100)) && (pub_r001530_15_1 <= 100));
  __CPROVER_assume((pub_r001530_15_2 >= (-100)) && (pub_r001530_15_2 <= 100));
  __CPROVER_assume((pub_r001530_16_1 >= (-100)) && (pub_r001530_16_1 <= 100));
  __CPROVER_assume((pub_r001530_16_2 >= (-100)) && (pub_r001530_16_2 <= 100));
  __CPROVER_assume((pub_r001530_17_1 >= (-100)) && (pub_r001530_17_1 <= 100));
  __CPROVER_assume((pub_r001530_17_2 >= (-100)) && (pub_r001530_17_2 <= 100));
  __CPROVER_assume((pub_r001530_18_1 >= (-100)) && (pub_r001530_18_1 <= 100));
  __CPROVER_assume((pub_r001530_18_2 >= (-100)) && (pub_r001530_18_2 <= 100));
  __CPROVER_assume((pub_r001530_19_1 >= (-100)) && (pub_r001530_19_1 <= 100));
  __CPROVER_assume((pub_r001530_19_2 >= (-100)) && (pub_r001530_19_2 <= 100));
  __CPROVER_assume((pub_r001530_20_1 >= (-100)) && (pub_r001530_20_1 <= 100));
  __CPROVER_assume((pub_r001530_20_2 >= (-100)) && (pub_r001530_20_2 <= 100));
  __CPROVER_assume((sec_r001530_0_1 >= 0) && (sec_r001530_0_1 <= 255));
  __CPROVER_assume((sec_r001530_0_2 >= 0) && (sec_r001530_0_2 <= 255));
  __CPROVER_assume((sec_r001530_1_1 >= 0) && (sec_r001530_1_1 <= 255));
  __CPROVER_assume((sec_r001530_1_2 >= 0) && (sec_r001530_1_2 <= 255));
  __CPROVER_assume((sec_r001530_2_1 >= 0) && (sec_r001530_2_1 <= 255));
  __CPROVER_assume((sec_r001530_2_2 >= 0) && (sec_r001530_2_2 <= 255));
  __CPROVER_assume((sec_r001530_3_1 >= 0) && (sec_r001530_3_1 <= 255));
  __CPROVER_assume((sec_r001530_3_2 >= 0) && (sec_r001530_3_2 <= 255));
  __CPROVER_assume((sec_r001530_4_1 >= 0) && (sec_r001530_4_1 <= 255));
  __CPROVER_assume((sec_r001530_4_2 >= 0) && (sec_r001530_4_2 <= 255));
  __CPROVER_assume((sec_r001530_5_1 >= 0) && (sec_r001530_5_1 <= 255));
  __CPROVER_assume((sec_r001530_5_2 >= 0) && (sec_r001530_5_2 <= 255));
  __CPROVER_assume((sec_r001530_6_1 >= 0) && (sec_r001530_6_1 <= 255));
  __CPROVER_assume((sec_r001530_6_2 >= 0) && (sec_r001530_6_2 <= 255));
  __CPROVER_assume((sec_r001530_7_1 >= 0) && (sec_r001530_7_1 <= 255));
  __CPROVER_assume((sec_r001530_7_2 >= 0) && (sec_r001530_7_2 <= 255));
  __CPROVER_assume((sec_r001530_8_1 >= 0) && (sec_r001530_8_1 <= 255));
  __CPROVER_assume((sec_r001530_8_2 >= 0) && (sec_r001530_8_2 <= 255));
  __CPROVER_assume((sec_r001530_9_1 >= 0) && (sec_r001530_9_1 <= 255));
  __CPROVER_assume((sec_r001530_9_2 >= 0) && (sec_r001530_9_2 <= 255));
  __CPROVER_assume((sec_r001530_10_1 >= 0) && (sec_r001530_10_1 <= 255));
  __CPROVER_assume((sec_r001530_10_2 >= 0) && (sec_r001530_10_2 <= 255));
  __CPROVER_assume((sec_r001530_11_1 >= 0) && (sec_r001530_11_1 <= 255));
  __CPROVER_assume((sec_r001530_11_2 >= 0) && (sec_r001530_11_2 <= 255));
  __CPROVER_assume((sec_r001530_12_1 >= 0) && (sec_r001530_12_1 <= 255));
  __CPROVER_assume((sec_r001530_12_2 >= 0) && (sec_r001530_12_2 <= 255));
  __CPROVER_assume((sec_r001530_13_1 >= 0) && (sec_r001530_13_1 <= 255));
  __CPROVER_assume((sec_r001530_13_2 >= 0) && (sec_r001530_13_2 <= 255));
  __CPROVER_assume((sec_r001530_14_1 >= 0) && (sec_r001530_14_1 <= 255));
  __CPROVER_assume((sec_r001530_14_2 >= 0) && (sec_r001530_14_2 <= 255));
  __CPROVER_assume((sec_r001530_15_1 >= 0) && (sec_r001530_15_1 <= 255));
  __CPROVER_assume((sec_r001530_15_2 >= 0) && (sec_r001530_15_2 <= 255));
  __CPROVER_assume((sec_r001530_16_1 >= 0) && (sec_r001530_16_1 <= 255));
  __CPROVER_assume((sec_r001530_16_2 >= 0) && (sec_r001530_16_2 <= 255));
  __CPROVER_assume((sec_r001530_17_1 >= 0) && (sec_r001530_17_1 <= 255));
  __CPROVER_assume((sec_r001530_17_2 >= 0) && (sec_r001530_17_2 <= 255));
  __CPROVER_assume((sec_r001530_18_1 >= 0) && (sec_r001530_18_1 <= 255));
  __CPROVER_assume((sec_r001530_18_2 >= 0) && (sec_r001530_18_2 <= 255));
  __CPROVER_assume((sec_r001530_19_1 >= 0) && (sec_r001530_19_1 <= 255));
  __CPROVER_assume((sec_r001530_19_2 >= 0) && (sec_r001530_19_2 <= 255));
  __CPROVER_assume((sec_r001530_20_1 >= 0) && (sec_r001530_20_1 <= 255));
  __CPROVER_assume((sec_r001530_20_2 >= 0) && (sec_r001530_20_2 <= 255));
  __CPROVER_assume((sec_r001530_21_1 >= 0) && (sec_r001530_21_1 <= 255));
  __CPROVER_assume((sec_r001530_21_2 >= 0) && (sec_r001530_21_2 <= 255));
  __CPROVER_assume((sec_r001530_22_1 >= 0) && (sec_r001530_22_1 <= 255));
  __CPROVER_assume((sec_r001530_22_2 >= 0) && (sec_r001530_22_2 <= 255));
  __CPROVER_assume((sec_r001530_23_1 >= 0) && (sec_r001530_23_1 <= 255));
  __CPROVER_assume((sec_r001530_23_2 >= 0) && (sec_r001530_23_2 <= 255));
  struct EventLog_R001530_3013_0 st_var_0_1 = {0};
  struct EventLog_R001530_3013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001530_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001530_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001530_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001530_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001530_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001530_0_2 + 7) & 15;
  struct AudioFrame_R001530_3013_1 st_var_1_1 = {0};
  struct AudioFrame_R001530_3013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001530_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001530_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001530_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001530_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001530_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001530_0_2 + 9) & 15;
  struct Vector3D_R001530_3013_2 st_var_2_1 = {0};
  struct Vector3D_R001530_3013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001530_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001530_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001530_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001530_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001530_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001530_0_2 + 11) & 15;
  struct SensorNode_R001530_3013_3 st_var_3_1 = {0};
  struct SensorNode_R001530_3013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001530_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001530_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001530_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001530_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001530_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001530_0_2 + 13) & 15;
  union PacketPayload_R001530_3013_0 u_var_1;
  union PacketPayload_R001530_3013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001530_3013_0(sec_r001530_0_1, pub_r001530_1_1, pub_r001530_2_1, pub_r001530_3_1, pub_r001530_4_1);
  int helper_flow_0_2 = fn_R001530_3013_0(sec_r001530_0_2, pub_r001530_1_2, pub_r001530_2_2, pub_r001530_3_2, pub_r001530_4_2);
  fn_R001530_3013_0_2(sec_r001530_0_1, pub_r001530_1_1, pub_r001530_2_1, pub_r001530_3_1, pub_r001530_4_1, sec_r001530_0_2, pub_r001530_1_2, pub_r001530_2_2, pub_r001530_3_2, pub_r001530_4_2);
  int helper_flow_1_1 = fn_R001530_3013_1(sec_r001530_1_1, pub_r001530_2_1, pub_r001530_3_1);
  int helper_flow_1_2 = fn_R001530_3013_1(sec_r001530_1_2, pub_r001530_2_2, pub_r001530_3_2);
  fn_R001530_3013_1_2(sec_r001530_1_1, pub_r001530_2_1, pub_r001530_3_1, sec_r001530_1_2, pub_r001530_2_2, pub_r001530_3_2);
  int helper_flow_2_1 = fn_R001530_3013_2(sec_r001530_2_1, sec_r001530_3_1);
  int helper_flow_2_2 = fn_R001530_3013_2(sec_r001530_2_2, sec_r001530_3_2);
  fn_R001530_3013_2_2(sec_r001530_2_1, sec_r001530_3_1, sec_r001530_2_2, sec_r001530_3_2);
  int helper_flow_3_1 = fn_R001530_3013_3(sec_r001530_3_1, pub_r001530_4_1, pub_r001530_5_1, pub_r001530_6_1, pub_r001530_7_1);
  int helper_flow_3_2 = fn_R001530_3013_3(sec_r001530_3_2, pub_r001530_4_2, pub_r001530_5_2, pub_r001530_6_2, pub_r001530_7_2);
  fn_R001530_3013_3_2(sec_r001530_3_1, pub_r001530_4_1, pub_r001530_5_1, pub_r001530_6_1, pub_r001530_7_1, sec_r001530_3_2, pub_r001530_4_2, pub_r001530_5_2, pub_r001530_6_2, pub_r001530_7_2);
  int helper_flow_4_1 = fn_R001530_3013_4(sec_r001530_4_1, sec_r001530_5_1, pub_r001530_6_1, pub_r001530_7_1);
  int helper_flow_4_2 = fn_R001530_3013_4(sec_r001530_4_2, sec_r001530_5_2, pub_r001530_6_2, pub_r001530_7_2);
  fn_R001530_3013_4_2(sec_r001530_4_1, sec_r001530_5_1, pub_r001530_6_1, pub_r001530_7_1, sec_r001530_4_2, sec_r001530_5_2, pub_r001530_6_2, pub_r001530_7_2);
  int helper_flow_5_1 = fn_R001530_3013_5(sec_r001530_5_1, pub_r001530_6_1);
  int helper_flow_5_2 = fn_R001530_3013_5(sec_r001530_5_2, pub_r001530_6_2);
  fn_R001530_3013_5_2(sec_r001530_5_1, pub_r001530_6_1, sec_r001530_5_2, pub_r001530_6_2);
  int helper_flow_6_1 = fn_R001530_3013_6(sec_r001530_6_1, sec_r001530_7_1, pub_r001530_8_1);
  int helper_flow_6_2 = fn_R001530_3013_6(sec_r001530_6_2, sec_r001530_7_2, pub_r001530_8_2);
  fn_R001530_3013_6_2(sec_r001530_6_1, sec_r001530_7_1, pub_r001530_8_1, sec_r001530_6_2, sec_r001530_7_2, pub_r001530_8_2);
  int helper_flow_7_1 = fn_R001530_3013_7(sec_r001530_7_1, sec_r001530_8_1, pub_r001530_9_1, pub_r001530_10_1, pub_r001530_11_1);
  int helper_flow_7_2 = fn_R001530_3013_7(sec_r001530_7_2, sec_r001530_8_2, pub_r001530_9_2, pub_r001530_10_2, pub_r001530_11_2);
  fn_R001530_3013_7_2(sec_r001530_7_1, sec_r001530_8_1, pub_r001530_9_1, pub_r001530_10_1, pub_r001530_11_1, sec_r001530_7_2, sec_r001530_8_2, pub_r001530_9_2, pub_r001530_10_2, pub_r001530_11_2);
  int helper_flow_8_1 = fn_R001530_3013_8(sec_r001530_8_1, pub_r001530_9_1, pub_r001530_10_1, pub_r001530_11_1);
  int helper_flow_8_2 = fn_R001530_3013_8(sec_r001530_8_2, pub_r001530_9_2, pub_r001530_10_2, pub_r001530_11_2);
  fn_R001530_3013_8_2(sec_r001530_8_1, pub_r001530_9_1, pub_r001530_10_1, pub_r001530_11_1, sec_r001530_8_2, pub_r001530_9_2, pub_r001530_10_2, pub_r001530_11_2);
  int stage_v_0_1 = (((sec_r001530_9_1 ^ 0x2A) * 2) + pub_r001530_17_1) & 127;
  int stage_v_0_2 = (((sec_r001530_9_2 ^ 0x2A) * 2) + pub_r001530_17_2) & 127;
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
  int stage_v_1_1 = ((pub_r001530_14_1 * 2) + 6) & 63;
  int stage_v_1_2 = ((pub_r001530_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_2_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_2_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001530_22_1 ^ 0x2A) * 2) + pub_r001530_5_1) & 127;
  int stage_v_3_2 = (((sec_r001530_22_2 ^ 0x2A) * 2) + pub_r001530_5_2) & 127;
  if (stage_v_3_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((pub_r001530_12_1 * 2) + 18) & 63;
  int stage_v_4_2 = ((pub_r001530_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001530_9_1 * 2) + 40) & 63;
  int stage_v_5_2 = ((pub_r001530_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_6_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_6_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001530_3_1 * 2) + 5) & 63;
  int stage_v_7_2 = ((pub_r001530_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001530_2_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_8_2 = (((sec_r001530_2_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001530_11_1 * 2) + 48) & 63;
  int stage_v_9_2 = ((pub_r001530_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001530_4_1 * 2) + 12) & 63;
  int stage_v_10_2 = ((pub_r001530_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001530_23_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_11_2 = (((sec_r001530_23_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_11_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001530_10_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_12_2 = (((sec_r001530_10_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_12_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_13_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_13_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001530_6_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_14_2 = (((sec_r001530_6_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_14_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_15_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_15_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001530_14_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_16_2 = (((sec_r001530_14_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_16_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_17_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
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
  int stage_v_18_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001530_17_1) & 127;
  int stage_v_18_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001530_17_2) & 127;
  if (stage_v_18_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001530_9_1) & 127;
  int stage_v_19_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001530_9_2) & 127;
  if (stage_v_19_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001530_10_1) & 127;
  int stage_v_20_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001530_10_2) & 127;
  if (stage_v_20_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001530_3_1 * 2) + 8) & 63;
  int stage_v_21_2 = ((pub_r001530_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001530_1_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_22_2 = (((sec_r001530_1_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_22_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((pub_r001530_3_1 * 2) + 23) & 63;
  int stage_v_23_2 = ((pub_r001530_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001530_8_1 * 2) + 11) & 63;
  int stage_v_24_2 = ((pub_r001530_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_25_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_25_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((pub_r001530_15_1 * 2) + 42) & 63;
  int stage_v_26_2 = ((pub_r001530_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001530_10_1 * 2) + 43) & 63;
  int stage_v_27_2 = ((pub_r001530_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_28_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_28_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001530_9_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_29_2 = (((sec_r001530_9_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_29_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_30_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
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
  int stage_v_31_1 = ((pub_r001530_2_1 * 2) + 30) & 63;
  int stage_v_31_2 = ((pub_r001530_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001530_18_1) & 127;
  int stage_v_32_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001530_18_2) & 127;
  if (stage_v_32_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_33_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_33_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001530_18_1 ^ 0x2A) * 2) + pub_r001530_9_1) & 127;
  int stage_v_34_2 = (((sec_r001530_18_2 ^ 0x2A) * 2) + pub_r001530_9_2) & 127;
  if (stage_v_34_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_35_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_35_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((pub_r001530_11_1 * 2) + 46) & 63;
  int stage_v_36_2 = ((pub_r001530_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001530_14_1 * 2) + 40) & 63;
  int stage_v_37_2 = ((pub_r001530_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_38_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_38_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001530_12_1 * 2) + 28) & 63;
  int stage_v_39_2 = ((pub_r001530_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001530_0_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_40_2 = (((sec_r001530_0_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_40_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001530_20_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_41_2 = (((sec_r001530_20_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_41_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_42_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_42_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_43_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_43_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((sec_r001530_22_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_44_2 = (((sec_r001530_22_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_44_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_45_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_45_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_46_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_46_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_47_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_47_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001530_11_1 * 2) + 28) & 63;
  int stage_v_48_2 = ((pub_r001530_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_49_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_49_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_50_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_50_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001530_2_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_51_2 = (((sec_r001530_2_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_51_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001530_14_1 * 2) + 19) & 63;
  int stage_v_52_2 = ((pub_r001530_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_53_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_53_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001530_9_1 * 2) + 21) & 63;
  int stage_v_54_2 = ((pub_r001530_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_55_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_55_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001530_8_1) & 127;
  int stage_v_56_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001530_8_2) & 127;
  if (stage_v_56_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001530_5_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_57_2 = (((sec_r001530_5_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_57_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_58_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_58_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001530_10_1) & 127;
  int stage_v_59_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001530_10_2) & 127;
  if (stage_v_59_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001530_12_1 * 2) + 42) & 63;
  int stage_v_60_2 = ((pub_r001530_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001530_13_1 ^ 0x2A) * 2) + pub_r001530_8_1) & 127;
  int stage_v_61_2 = (((sec_r001530_13_2 ^ 0x2A) * 2) + pub_r001530_8_2) & 127;
  if (stage_v_61_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001530_2_1 * 2) + 20) & 63;
  int stage_v_62_2 = ((pub_r001530_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_63_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_63_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_64_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_64_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001530_9_1 * 2) + 13) & 63;
  int stage_v_65_2 = ((pub_r001530_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_66_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_66_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_67_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_67_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_68_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_68_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_69_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_69_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((pub_r001530_1_1 * 2) + 40) & 63;
  int stage_v_70_2 = ((pub_r001530_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_71_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_71_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001530_2_1 * 2) + 42) & 63;
  int stage_v_72_2 = ((pub_r001530_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_73_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_73_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_74_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_74_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_75_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_75_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_76_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_76_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001530_1_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_77_2 = (((sec_r001530_1_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_77_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001530_19_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_78_2 = (((sec_r001530_19_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_78_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((pub_r001530_14_1 * 2) + 9) & 63;
  int stage_v_79_2 = ((pub_r001530_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_80_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_80_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001530_6_1 * 2) + 40) & 63;
  int stage_v_81_2 = ((pub_r001530_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001530_7_1 * 2) + 44) & 63;
  int stage_v_82_2 = ((pub_r001530_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001530_9_1 * 2) + 26) & 63;
  int stage_v_83_2 = ((pub_r001530_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001530_4_1 * 2) + 45) & 63;
  int stage_v_84_2 = ((pub_r001530_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001530_13_1 * 2) + 8) & 63;
  int stage_v_85_2 = ((pub_r001530_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_86_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_86_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_87_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_87_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_88_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_88_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001530_10_1) & 127;
  int stage_v_89_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001530_10_2) & 127;
  if (stage_v_89_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_90_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_90_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_91_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_91_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((sec_r001530_20_1 ^ 0x2A) * 2) + pub_r001530_8_1) & 127;
  int stage_v_92_2 = (((sec_r001530_20_2 ^ 0x2A) * 2) + pub_r001530_8_2) & 127;
  if (stage_v_92_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_93_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_93_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_94_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_94_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_95_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_95_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_96_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_96_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001530_18_1) & 127;
  int stage_v_97_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001530_18_2) & 127;
  if (stage_v_97_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001530_17_1) & 127;
  int stage_v_98_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001530_17_2) & 127;
  if (stage_v_98_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001530_13_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_99_2 = (((sec_r001530_13_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_99_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_100_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_100_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((sec_r001530_11_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_101_2 = (((sec_r001530_11_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_101_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001530_1_1 * 2) + 37) & 63;
  int stage_v_102_2 = ((pub_r001530_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_103_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_103_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_104_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_104_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001530_20_1 * 2) + 13) & 63;
  int stage_v_105_2 = ((pub_r001530_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_106_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_106_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001530_17_1 * 2) + 36) & 63;
  int stage_v_107_2 = ((pub_r001530_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_108_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_108_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001530_9_1 * 2) + 34) & 63;
  int stage_v_109_2 = ((pub_r001530_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001530_9_1) & 127;
  int stage_v_110_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001530_9_2) & 127;
  if (stage_v_110_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_111_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_111_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_112_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_112_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_113_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_113_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001530_5_1) & 127;
  int stage_v_114_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001530_5_2) & 127;
  if (stage_v_114_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_115_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_115_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((pub_r001530_12_1 * 2) + 18) & 63;
  int stage_v_116_2 = ((pub_r001530_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_117_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_117_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((pub_r001530_18_1 * 2) + 5) & 63;
  int stage_v_118_2 = ((pub_r001530_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_119_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
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
  int stage_v_120_1 = (((sec_r001530_11_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_120_2 = (((sec_r001530_11_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_120_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((sec_r001530_21_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_121_2 = (((sec_r001530_21_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_121_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001530_8_1) & 127;
  int stage_v_122_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001530_8_2) & 127;
  if (stage_v_122_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((sec_r001530_5_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_123_2 = (((sec_r001530_5_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_123_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001530_12_1 * 2) + 48) & 63;
  int stage_v_124_2 = ((pub_r001530_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_125_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_125_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_126_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_126_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((pub_r001530_5_1 * 2) + 6) & 63;
  int stage_v_127_2 = ((pub_r001530_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_128_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_128_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_129_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_129_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001530_5_1) & 127;
  int stage_v_130_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001530_5_2) & 127;
  if (stage_v_130_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001530_2_1 * 2) + 48) & 63;
  int stage_v_131_2 = ((pub_r001530_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001530_7_1 ^ 0x2A) * 2) + pub_r001530_17_1) & 127;
  int stage_v_132_2 = (((sec_r001530_7_2 ^ 0x2A) * 2) + pub_r001530_17_2) & 127;
  if (stage_v_132_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001530_15_1 * 2) + 28) & 63;
  int stage_v_133_2 = ((pub_r001530_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_134_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_134_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((sec_r001530_20_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_135_2 = (((sec_r001530_20_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_135_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((pub_r001530_7_1 * 2) + 18) & 63;
  int stage_v_136_2 = ((pub_r001530_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001530_19_1 * 2) + 17) & 63;
  int stage_v_137_2 = ((pub_r001530_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((sec_r001530_17_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_138_2 = (((sec_r001530_17_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_138_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((sec_r001530_4_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_139_2 = (((sec_r001530_4_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_139_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001530_22_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_140_2 = (((sec_r001530_22_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_140_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((sec_r001530_9_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_141_2 = (((sec_r001530_9_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_141_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_142_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_142_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_143_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_143_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_144_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_144_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001530_12_1 * 2) + 13) & 63;
  int stage_v_145_2 = ((pub_r001530_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_146_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_146_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001530_10_1 * 2) + 41) & 63;
  int stage_v_147_2 = ((pub_r001530_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_148_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_148_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001530_16_1 * 2) + 8) & 63;
  int stage_v_149_2 = ((pub_r001530_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001530_15_1 * 2) + 31) & 63;
  int stage_v_150_2 = ((pub_r001530_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_151_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_151_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_152_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_152_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_153_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_153_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_154_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_154_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_155_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_155_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((sec_r001530_7_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_156_2 = (((sec_r001530_7_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_156_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_157_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_157_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_158_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_158_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001530_5_1) & 127;
  int stage_v_159_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001530_5_2) & 127;
  if (stage_v_159_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001530_8_1 * 2) + 29) & 63;
  int stage_v_160_2 = ((pub_r001530_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_161_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_161_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_162_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_162_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_163_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_163_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_164_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_164_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((pub_r001530_16_1 * 2) + 19) & 63;
  int stage_v_165_2 = ((pub_r001530_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((sec_r001530_11_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_166_2 = (((sec_r001530_11_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_166_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((sec_r001530_5_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_167_2 = (((sec_r001530_5_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_167_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001530_8_1) & 127;
  int stage_v_168_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001530_8_2) & 127;
  if (stage_v_168_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_169_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_169_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((pub_r001530_9_1 * 2) + 35) & 63;
  int stage_v_170_2 = ((pub_r001530_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_171_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_171_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_172_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_172_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001530_18_1) & 127;
  int stage_v_173_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001530_18_2) & 127;
  if (stage_v_173_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001530_20_1 * 2) + 36) & 63;
  int stage_v_174_2 = ((pub_r001530_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001530_10_1) & 127;
  int stage_v_175_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001530_10_2) & 127;
  if (stage_v_175_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_176_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_176_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_177_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_177_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_178_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_178_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_179_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_179_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((sec_r001530_12_1 ^ 0x2A) * 2) + pub_r001530_9_1) & 127;
  int stage_v_180_2 = (((sec_r001530_12_2 ^ 0x2A) * 2) + pub_r001530_9_2) & 127;
  if (stage_v_180_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_181_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_181_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_182_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_182_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_183_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_183_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_184_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_184_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001530_8_1 * 2) + 49) & 63;
  int stage_v_185_2 = ((pub_r001530_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001530_11_1 * 2) + 32) & 63;
  int stage_v_186_2 = ((pub_r001530_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_187_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_187_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((sec_r001530_7_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_188_2 = (((sec_r001530_7_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_188_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_189_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_189_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_190_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_190_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001530_7_1 * 2) + 24) & 63;
  int stage_v_191_2 = ((pub_r001530_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001530_0_1) & 127;
  int stage_v_192_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001530_0_2) & 127;
  if (stage_v_192_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_183_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_193_2 = (((stage_v_183_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_193_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_194_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_194_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_195_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_195_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_196_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_196_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_197_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_197_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_198_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_198_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_199_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_199_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001530_16_1) & 127;
  int stage_v_200_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001530_16_2) & 127;
  if (stage_v_200_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001530_14_1) & 127;
  int stage_v_201_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001530_14_2) & 127;
  if (stage_v_201_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_202_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_202_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001530_17_1) & 127;
  int stage_v_203_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001530_17_2) & 127;
  if (stage_v_203_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_204_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_204_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_205_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_205_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001530_5_1) & 127;
  int stage_v_206_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001530_5_2) & 127;
  if (stage_v_206_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_207_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_207_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_208_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_208_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_209_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
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
  int stage_v_210_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_210_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_210_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001530_15_1) & 127;
  int stage_v_211_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001530_15_2) & 127;
  if (stage_v_211_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001530_9_1 * 2) + 43) & 63;
  int stage_v_212_2 = ((pub_r001530_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_213_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
  if (stage_v_213_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001530_13_1) & 127;
  int stage_v_214_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001530_13_2) & 127;
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
  int stage_v_215_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001530_1_1) & 127;
  int stage_v_215_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001530_1_2) & 127;
  if (stage_v_215_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_216_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_216_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((pub_r001530_8_1 * 2) + 49) & 63;
  int stage_v_217_2 = ((pub_r001530_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001530_9_1) & 127;
  int stage_v_218_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001530_9_2) & 127;
  if (stage_v_218_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001530_18_1) & 127;
  int stage_v_219_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001530_18_2) & 127;
  if (stage_v_219_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_220_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_220_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((pub_r001530_18_1 * 2) + 30) & 63;
  int stage_v_221_2 = ((pub_r001530_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_222_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_222_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001530_8_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_223_2 = (((sec_r001530_8_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_223_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((pub_r001530_12_1 * 2) + 9) & 63;
  int stage_v_224_2 = ((pub_r001530_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001530_20_1) & 127;
  int stage_v_225_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001530_20_2) & 127;
  if (stage_v_225_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001530_6_1) & 127;
  int stage_v_226_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001530_6_2) & 127;
  if (stage_v_226_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((pub_r001530_18_1 * 2) + 37) & 63;
  int stage_v_227_2 = ((pub_r001530_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((sec_r001530_1_1 ^ 0x2A) * 2) + pub_r001530_2_1) & 127;
  int stage_v_228_2 = (((sec_r001530_1_2 ^ 0x2A) * 2) + pub_r001530_2_2) & 127;
  if (stage_v_228_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((pub_r001530_13_1 * 2) + 20) & 63;
  int stage_v_229_2 = ((pub_r001530_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((sec_r001530_21_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_230_2 = (((sec_r001530_21_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_230_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((sec_r001530_14_1 ^ 0x2A) * 2) + pub_r001530_11_1) & 127;
  int stage_v_231_2 = (((sec_r001530_14_2 ^ 0x2A) * 2) + pub_r001530_11_2) & 127;
  if (stage_v_231_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001530_3_1) & 127;
  int stage_v_232_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001530_3_2) & 127;
  if (stage_v_232_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001530_19_1) & 127;
  int stage_v_233_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001530_19_2) & 127;
  if (stage_v_233_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((pub_r001530_13_1 * 2) + 20) & 63;
  int stage_v_234_2 = ((pub_r001530_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001530_10_1) & 127;
  int stage_v_235_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001530_10_2) & 127;
  if (stage_v_235_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((pub_r001530_14_1 * 2) + 31) & 63;
  int stage_v_236_2 = ((pub_r001530_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_216_1 ^ 0x2A) * 2) + pub_r001530_12_1) & 127;
  int stage_v_237_2 = (((stage_v_216_2 ^ 0x2A) * 2) + pub_r001530_12_2) & 127;
  if (stage_v_237_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_188_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_238_2 = (((stage_v_188_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_238_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001530_7_1) & 127;
  int stage_v_239_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001530_7_2) & 127;
  if (stage_v_239_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001530_4_1) & 127;
  int stage_v_240_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001530_4_2) & 127;
  if (stage_v_240_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001530_6_1 != sec_r001530_6_2);
  __CPROVER_assume(pub_r001530_5_1 == pub_r001530_5_2);
  __CPROVER_assume(pub_r001530_9_1 == pub_r001530_9_2);
  __CPROVER_assume(pub_r001530_11_1 == pub_r001530_11_2);
  __CPROVER_assume(sec_r001530_15_1 != sec_r001530_15_2);
  __CPROVER_assume(pub_r001530_1_1 == pub_r001530_1_2);
  __CPROVER_assume(pub_r001530_3_1 == pub_r001530_3_2);
  __CPROVER_assume(pub_r001530_6_1 == pub_r001530_6_2);
  __CPROVER_assume(pub_r001530_18_1 == pub_r001530_18_2);
  __CPROVER_assume(pub_r001530_20_1 == pub_r001530_20_2);
  __CPROVER_assume(sec_r001530_14_1 != sec_r001530_14_2);
  __CPROVER_assume(sec_r001530_22_1 != sec_r001530_22_2);
  __CPROVER_assume(pub_r001530_8_1 == pub_r001530_8_2);
  __CPROVER_assume(pub_r001530_14_1 == pub_r001530_14_2);
  __CPROVER_assume(sec_r001530_20_1 != sec_r001530_20_2);
  __CPROVER_assume(pub_r001530_12_1 == pub_r001530_12_2);
  __CPROVER_assume(sec_r001530_10_1 != sec_r001530_10_2);
  __CPROVER_assume(pub_r001530_16_1 == pub_r001530_16_2);
  __CPROVER_assume(pub_r001530_10_1 == pub_r001530_10_2);
  __CPROVER_assume(sec_r001530_16_1 != sec_r001530_16_2);
  __CPROVER_assume(sec_r001530_17_1 != sec_r001530_17_2);
  __CPROVER_assume(pub_r001530_2_1 == pub_r001530_2_2);
  __CPROVER_assume(sec_r001530_11_1 != sec_r001530_11_2);
  __CPROVER_assume(sec_r001530_21_1 != sec_r001530_21_2);
  __CPROVER_assume(sec_r001530_4_1 != sec_r001530_4_2);
  __CPROVER_assume(sec_r001530_2_1 != sec_r001530_2_2);
  __CPROVER_assume(pub_r001530_7_1 == pub_r001530_7_2);
  __CPROVER_assume(sec_r001530_23_1 != sec_r001530_23_2);
  __CPROVER_assume(sec_r001530_5_1 != sec_r001530_5_2);
  __CPROVER_assume(sec_r001530_19_1 != sec_r001530_19_2);
  __CPROVER_assume(sec_r001530_0_1 != sec_r001530_0_2);
  __CPROVER_assume(pub_r001530_0_1 == pub_r001530_0_2);
  __CPROVER_assume(sec_r001530_12_1 != sec_r001530_12_2);
  __CPROVER_assume(pub_r001530_19_1 == pub_r001530_19_2);
  __CPROVER_assume(sec_r001530_8_1 != sec_r001530_8_2);
  __CPROVER_assume(sec_r001530_13_1 != sec_r001530_13_2);
  __CPROVER_assume(pub_r001530_13_1 == pub_r001530_13_2);
  __CPROVER_assume(pub_r001530_17_1 == pub_r001530_17_2);
  __CPROVER_assume(sec_r001530_9_1 != sec_r001530_9_2);
  __CPROVER_assume(sec_r001530_7_1 != sec_r001530_7_2);
  __CPROVER_assume(sec_r001530_3_1 != sec_r001530_3_2);
  __CPROVER_assume(pub_r001530_15_1 == pub_r001530_15_2);
  __CPROVER_assume(pub_r001530_4_1 == pub_r001530_4_2);
  __CPROVER_assume(sec_r001530_1_1 != sec_r001530_1_2);
  __CPROVER_assume(sec_r001530_18_1 != sec_r001530_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.offset == st_var_3_2.offset);
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
}


