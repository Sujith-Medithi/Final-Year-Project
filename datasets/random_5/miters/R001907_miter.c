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
struct SensorNode_R001907_713_0
{
  unsigned char offset;
  int gain;
  int reading;
  short calib;
  int status;
  int buffer[3];
};
struct Vector3D_R001907_713_1
{
  int coord_x;
  int norm_sq;
  short heading;
  int buffer[3];
};
struct FilterState_R001907_713_2
{
  int damping;
  int mode;
  int prev_in;
  int buffer[3];
};
struct DeviceConfig_R001907_713_3
{
  short baud_rate;
  short id;
  int timeout;
  int stop_bits;
  int parity;
  int buffer[3];
};
union PacketPayload_R001907_713_0
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
void fn_R001907_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int weight_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_23_1)
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

  switch (weight_23_2)
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
  int quantum_17_1 = local_arr_1[aux_1 % 3];
  int quantum_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_17_2 * 2)) & 127;
  int residue_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_49_1) & 63;
  aux_2 = (aux_2 + residue_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_23_1 == weight_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_17_1 == quantum_17_2);
  assert(residue_49_1 == residue_49_2);
}

int fn_R001907_713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int weight_23 = (aux + st.buffer[1]) & 3;
  switch (weight_23)
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
  int quantum_17 = local_arr[aux % 3];
  acc = (acc + (quantum_17 * 2)) & 127;
  int residue_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001907_713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st_1 = {0};
  struct FilterState_R001907_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quantum_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_17_1)
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

  switch (quantum_17_2)
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
  int sample_28_1 = local_arr_1[aux_1 % 3];
  int sample_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_28_2 * 2)) & 127;
  int mask_57_1 = 0;
  int mask_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_57_1 = ((mask_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_57_2 = ((mask_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_57_1) & 127;
    acc_2 = (acc_2 + mask_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_17_1 == quantum_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_28_1 == sample_28_2);
  assert(mask_57_1 == mask_57_2);
}

int fn_R001907_713_1(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quantum_17 = (aux + st.buffer[1]) & 3;
  switch (quantum_17)
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
  int sample_28 = local_arr[aux % 3];
  acc = (acc + (sample_28 * 2)) & 127;
  int mask_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_57 = ((mask_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st_1 = {0};
  struct Vector3D_R001907_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int damping_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_58_1)
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

  switch (damping_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_96_1 = 0;
  int index_reg_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_96_1 = ((index_reg_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_96_2 = ((index_reg_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_96_1) & 127;
    acc_2 = (acc_2 + index_reg_96_2) & 127;
  }

  int phase_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_25_1 > 23)
  {
    acc_1 = ((acc_1 + (phase_25_1 * 2)) + 5) & 127;
    aux_1 ^= phase_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_25_2 > 23)
  {
    acc_2 = ((acc_2 + (phase_25_2 * 2)) + 5) & 127;
    aux_2 ^= phase_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_58_1 == damping_58_2);
  assert(index_reg_96_1 == index_reg_96_2);
  assert(phase_25_1 == phase_25_2);
}

int fn_R001907_713_2(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int damping_58 = (aux + st.buffer[1]) & 3;
  switch (damping_58)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_96 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_96 = ((index_reg_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_96) & 127;
  }

  int phase_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_25 > 23)
  {
    acc = ((acc + (phase_25 * 2)) + 5) & 127;
    aux ^= phase_25 & 15;
  }
  else
  {
    acc = ((acc - phase_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001907_713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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

  int quotient_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_70_1 > 44)
  {
    acc_1 = ((acc_1 + (quotient_70_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_70_2 > 44)
  {
    acc_2 = ((acc_2 + (quotient_70_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_70_1 = 0;
  int mask_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_70_1 = ((mask_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_70_2 = ((mask_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_70_1) & 127;
    acc_2 = (acc_2 + mask_70_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_73_1 == metric_73_2);
  assert(quotient_70_1 == quotient_70_2);
  assert(mask_70_1 == mask_70_2);
}

int fn_R001907_713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

  int quotient_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_70 > 44)
  {
    acc = ((acc + (quotient_70 * 2)) + 5) & 127;
    aux ^= quotient_70 & 15;
  }
  else
  {
    acc = ((acc - quotient_70) + 11) & 127;
    aux += 3;
  }
  int mask_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_70 = ((mask_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_70) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st_1 = {0};
  struct Vector3D_R001907_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_96_1 = local_arr_1[aux_1 % 3];
  int residue_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_96_1 == residue_96_2);
}

int fn_R001907_713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_96 = local_arr[aux % 3];
  acc = (acc + (residue_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001907_713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_52_1 > 23)
  {
    acc_1 = ((acc_1 + (residue_52_1 * 2)) + 5) & 127;
    aux_1 ^= residue_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_52_2 > 23)
  {
    acc_2 = ((acc_2 + (residue_52_2 * 2)) + 5) & 127;
    aux_2 ^= residue_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_58_1) & 63;
  aux_2 = (aux_2 + checksum_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_52_1 == residue_52_2);
  assert(checksum_58_1 == checksum_58_2);
}

int fn_R001907_713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_52 > 23)
  {
    acc = ((acc + (residue_52 * 2)) + 5) & 127;
    aux ^= residue_52 & 15;
  }
  else
  {
    acc = ((acc - residue_52) + 11) & 127;
    aux += 3;
  }
  int checksum_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001907_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st_1 = {0};
  struct FilterState_R001907_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_40_1 = local_arr_1[aux_1 % 3];
  int margin_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_40_2 * 2)) & 127;
  int quotient_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_73_1) & 63;
  aux_2 = (aux_2 + quotient_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_51_1)
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

  switch (tracker_51_2)
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

  int threshold_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_52_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_52_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_52_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_52_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_40_1 == margin_40_2);
  assert(quotient_73_1 == quotient_73_2);
  assert(tracker_51_1 == tracker_51_2);
  assert(threshold_52_1 == threshold_52_2);
}

int fn_R001907_713_6(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int margin_40 = local_arr[aux % 3];
  acc = (acc + (margin_40 * 2)) & 127;
  int quotient_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_73) & 63;
  acc ^= aux;
  int tracker_51 = (aux + st.buffer[1]) & 3;
  switch (tracker_51)
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

  int threshold_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_52 > 24)
  {
    acc = ((acc + (threshold_52 * 2)) + 5) & 127;
    aux ^= threshold_52 & 15;
  }
  else
  {
    acc = ((acc - threshold_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001907_713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_91_1 = local_arr_1[aux_1 % 3];
  int damping_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_91_2 * 2)) & 127;
  int delta_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_48_1 > 48)
  {
    acc_1 = ((acc_1 + (delta_48_1 * 2)) + 5) & 127;
    aux_1 ^= delta_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_48_2 > 48)
  {
    acc_2 = ((acc_2 + (delta_48_2 * 2)) + 5) & 127;
    aux_2 ^= delta_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_91_1 == damping_91_2);
  assert(delta_48_1 == delta_48_2);
}

int fn_R001907_713_7(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int damping_91 = local_arr[aux % 3];
  acc = (acc + (damping_91 * 2)) & 127;
  int delta_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_48 > 48)
  {
    acc = ((acc + (delta_48 * 2)) + 5) & 127;
    aux ^= delta_48 & 15;
  }
  else
  {
    acc = ((acc - delta_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001907_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st_1 = {0};
  struct FilterState_R001907_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_96_1 > 15)
  {
    acc_1 = ((acc_1 + (accumulator_96_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_96_2 > 15)
  {
    acc_2 = ((acc_2 + (accumulator_96_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_89_1 = local_arr_1[aux_1 % 3];
  int pivot_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_89_2 * 2)) & 127;
  int quotient_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_75_1) & 63;
  aux_2 = (aux_2 + quotient_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_78_1 = 0;
  int vector_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_78_1 = ((vector_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_78_2 = ((vector_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_78_1) & 127;
    acc_2 = (acc_2 + vector_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_96_1 == accumulator_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_89_1 == pivot_89_2);
  assert(quotient_75_1 == quotient_75_2);
  assert(vector_78_1 == vector_78_2);
}

int fn_R001907_713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001907_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_96 > 15)
  {
    acc = ((acc + (accumulator_96 * 2)) + 5) & 127;
    aux ^= accumulator_96 & 15;
  }
  else
  {
    acc = ((acc - accumulator_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_89 = local_arr[aux % 3];
  acc = (acc + (pivot_89 * 2)) & 127;
  int quotient_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_75) & 63;
  acc ^= aux;
  int vector_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_78 = ((vector_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int delta_58_1 = 0;
  int delta_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_58_1 = ((delta_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_58_2 = ((delta_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_58_1) & 127;
    acc_2 = (acc_2 + delta_58_2) & 127;
  }

  int tally_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_78_1 > 25)
  {
    acc_1 = ((acc_1 + (tally_78_1 * 2)) + 5) & 127;
    aux_1 ^= tally_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_78_2 > 25)
  {
    acc_2 = ((acc_2 + (tally_78_2 * 2)) + 5) & 127;
    aux_2 ^= tally_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_58_1 == delta_58_2);
  assert(tally_78_1 == tally_78_2);
}

int fn_R001907_713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int delta_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_58 = ((delta_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_58) & 127;
  }

  int tally_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_78 > 25)
  {
    acc = ((acc + (tally_78 * 2)) + 5) & 127;
    aux ^= tally_78 & 15;
  }
  else
  {
    acc = ((acc - tally_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001907_713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_89_1 = local_arr_1[aux_1 % 3];
  int checksum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_89_2 * 2)) & 127;
  int parity_83_1 = 0;
  int parity_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_83_1 = ((parity_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_83_2 = ((parity_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_83_1) & 127;
    acc_2 = (acc_2 + parity_83_2) & 127;
  }

  int weight_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_98_1) & 63;
  aux_2 = (aux_2 + weight_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_89_1 == checksum_89_2);
  assert(parity_83_1 == parity_83_2);
  assert(weight_98_1 == weight_98_2);
}

int fn_R001907_713_10(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int checksum_89 = local_arr[aux % 3];
  acc = (acc + (checksum_89 * 2)) & 127;
  int parity_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_83 = ((parity_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_83) & 127;
  }

  int weight_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001907_713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_18_1 = local_arr_1[aux_1 % 3];
  int sample_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_18_2 * 2)) & 127;
  int quantum_67_1 = 0;
  int quantum_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_67_1 = ((quantum_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_67_2 = ((quantum_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_67_1) & 127;
    acc_2 = (acc_2 + quantum_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_18_1 == sample_18_2);
  assert(quantum_67_1 == quantum_67_2);
}

int fn_R001907_713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int sample_18 = local_arr[aux % 3];
  acc = (acc + (sample_18 * 2)) & 127;
  int quantum_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_67 = ((quantum_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_17_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_17_1 * 2)) + 5) & 127;
    aux_1 ^= bound_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_17_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_17_2 * 2)) + 5) & 127;
    aux_2 ^= bound_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_97_1 = 0;
  int accumulator_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_97_1 = ((accumulator_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_97_2 = ((accumulator_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_97_1) & 127;
    acc_2 = (acc_2 + accumulator_97_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_72_1 = local_arr_1[aux_1 % 3];
  int factor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_72_2 * 2)) & 127;
  int quotient_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_18_1)
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

  switch (quotient_18_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_17_1 == bound_17_2);
  assert(accumulator_97_1 == accumulator_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_72_1 == factor_72_2);
  assert(quotient_18_1 == quotient_18_2);
}

int fn_R001907_713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_17 > 28)
  {
    acc = ((acc + (bound_17 * 2)) + 5) & 127;
    aux ^= bound_17 & 15;
  }
  else
  {
    acc = ((acc - bound_17) + 11) & 127;
    aux += 3;
  }
  int accumulator_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_97 = ((accumulator_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_97) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_72 = local_arr[aux % 3];
  acc = (acc + (factor_72 * 2)) & 127;
  int quotient_18 = (aux + st.buffer[1]) & 3;
  switch (quotient_18)
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

void fn_R001907_713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_68_1 > 19)
  {
    acc_1 = ((acc_1 + (stride_68_1 * 2)) + 5) & 127;
    aux_1 ^= stride_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_68_2 > 19)
  {
    acc_2 = ((acc_2 + (stride_68_2 * 2)) + 5) & 127;
    aux_2 ^= stride_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_37_1 = local_arr_1[aux_1 % 3];
  int weight_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_68_1 == stride_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_37_1 == weight_37_2);
}

int fn_R001907_713_13(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_68 > 19)
  {
    acc = ((acc + (stride_68 * 2)) + 5) & 127;
    aux ^= stride_68 & 15;
  }
  else
  {
    acc = ((acc - stride_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_37 = local_arr[aux % 3];
  acc = (acc + (weight_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001907_713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_57_1 = local_arr_1[aux_1 % 3];
  int parity_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_57_2 * 2)) & 127;
  int quantum_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_62_1)
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

  switch (quantum_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_63_1 == factor_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_57_1 == parity_57_2);
  assert(quantum_62_1 == quantum_62_2);
}

int fn_R001907_713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_57 = local_arr[aux % 3];
  acc = (acc + (parity_57 * 2)) & 127;
  int quantum_62 = (aux + st.buffer[1]) & 3;
  switch (quantum_62)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001907_713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_97_1 = 0;
  int phase_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_97_1 = ((phase_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_97_2 = ((phase_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_97_1) & 127;
    acc_2 = (acc_2 + phase_97_2) & 127;
  }

  int threshold_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_93_1) & 63;
  aux_2 = (aux_2 + threshold_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_97_1 == phase_97_2);
  assert(threshold_93_1 == threshold_93_2);
}

int fn_R001907_713_15(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_97 = ((phase_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_97) & 127;
  }

  int threshold_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001907_713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_77_1 = local_arr_1[aux_1 % 3];
  int threshold_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_70_1 = 0;
  int quotient_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_70_1 = ((quotient_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_70_2 = ((quotient_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_70_1) & 127;
    acc_2 = (acc_2 + quotient_70_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_77_1 == threshold_77_2);
  assert(quotient_70_1 == quotient_70_2);
}

int fn_R001907_713_16(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int threshold_77 = local_arr[aux % 3];
  acc = (acc + (threshold_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_70 = ((quotient_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_70) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_72_1 > 11)
  {
    acc_1 = ((acc_1 + (window_72_1 * 2)) + 5) & 127;
    aux_1 ^= window_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_72_2 > 11)
  {
    acc_2 = ((acc_2 + (window_72_2 * 2)) + 5) & 127;
    aux_2 ^= window_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_95_1 = 0;
  int segment_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_95_1 = ((segment_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_95_2 = ((segment_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_95_1) & 127;
    acc_2 = (acc_2 + segment_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_72_1 == window_72_2);
  assert(segment_95_1 == segment_95_2);
}

int fn_R001907_713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_72 > 11)
  {
    acc = ((acc + (window_72 * 2)) + 5) & 127;
    aux ^= window_72 & 15;
  }
  else
  {
    acc = ((acc - window_72) + 11) & 127;
    aux += 3;
  }
  int segment_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_95 = ((segment_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st_1 = {0};
  struct Vector3D_R001907_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_49_1)
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

  switch (tally_49_2)
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

  int accumulator_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_38_1) & 63;
  aux_2 = (aux_2 + accumulator_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_72_1 = local_arr_1[aux_1 % 3];
  int offset_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_72_2 * 2)) & 127;
  int checksum_99_1 = 0;
  int checksum_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_99_1 = ((checksum_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_99_2 = ((checksum_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_99_1) & 127;
    acc_2 = (acc_2 + checksum_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_49_1 == tally_49_2);
  assert(accumulator_38_1 == accumulator_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_72_1 == offset_72_2);
  assert(checksum_99_1 == checksum_99_2);
}

int fn_R001907_713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_49 = (aux + st.buffer[1]) & 3;
  switch (tally_49)
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

  int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_72 = local_arr[aux % 3];
  acc = (acc + (offset_72 * 2)) & 127;
  int checksum_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_99 = ((checksum_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st_1 = {0};
  struct SensorNode_R001907_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_55_1 > 35)
  {
    acc_1 = ((acc_1 + (quantum_55_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_55_2 > 35)
  {
    acc_2 = ((acc_2 + (quantum_55_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_68_1)
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

  switch (delta_68_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_55_1 == quantum_55_2);
  assert(delta_68_1 == delta_68_2);
}

int fn_R001907_713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001907_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_55 > 35)
  {
    acc = ((acc + (quantum_55 * 2)) + 5) & 127;
    aux ^= quantum_55 & 15;
  }
  else
  {
    acc = ((acc - quantum_55) + 11) & 127;
    aux += 3;
  }
  int delta_68 = (aux + st.buffer[1]) & 3;
  switch (delta_68)
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

void fn_R001907_713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st_1 = {0};
  struct Vector3D_R001907_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_72_1 = 0;
  int anchor_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_72_1 = ((anchor_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_72_2 = ((anchor_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_72_1) & 127;
    acc_2 = (acc_2 + anchor_72_2) & 127;
  }

  int tally_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_45_1)
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

  switch (tally_45_2)
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

  int accumulator_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_41_1 > 33)
  {
    acc_1 = ((acc_1 + (accumulator_41_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_41_2 > 33)
  {
    acc_2 = ((acc_2 + (accumulator_41_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_61_1 = local_arr_1[aux_1 % 3];
  int tracker_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_72_1 == anchor_72_2);
  assert(tally_45_1 == tally_45_2);
  assert(accumulator_41_1 == accumulator_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_61_1 == tracker_61_2);
}

int fn_R001907_713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001907_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_72 = ((anchor_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_72) & 127;
  }

  int tally_45 = (aux + st.buffer[1]) & 3;
  switch (tally_45)
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

  int accumulator_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_41 > 33)
  {
    acc = ((acc + (accumulator_41 * 2)) + 5) & 127;
    aux ^= accumulator_41 & 15;
  }
  else
  {
    acc = ((acc - accumulator_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tracker_61 = local_arr[aux % 3];
  acc = (acc + (tracker_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001907_713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tally_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_99_1) & 63;
  aux_2 = (aux_2 + tally_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_92_1 = local_arr_1[aux_1 % 3];
  int metric_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_99_1 = 0;
  int offset_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_99_1 = ((offset_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_99_2 = ((offset_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_99_1) & 127;
    acc_2 = (acc_2 + offset_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_99_1 == tally_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_92_1 == metric_92_2);
  assert(offset_99_1 == offset_99_2);
}

int fn_R001907_713_21(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tally_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_92 = local_arr[aux % 3];
  acc = (acc + (metric_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_99 = ((offset_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001907_713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st_1 = {0};
  struct DeviceConfig_R001907_713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_30_1) & 63;
  aux_2 = (aux_2 + coefficient_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_84_1 > 17)
  {
    acc_1 = ((acc_1 + (sample_84_1 * 2)) + 5) & 127;
    aux_1 ^= sample_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_84_2 > 17)
  {
    acc_2 = ((acc_2 + (sample_84_2 * 2)) + 5) & 127;
    aux_2 ^= sample_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_64_1 = local_arr_1[aux_1 % 3];
  int cursor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_30_1 == coefficient_30_2);
  assert(sample_84_1 == sample_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_64_1 == cursor_64_2);
}

int fn_R001907_713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001907_713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_30) & 63;
  acc ^= aux;
  int sample_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_84 > 17)
  {
    acc = ((acc + (sample_84 * 2)) + 5) & 127;
    aux ^= sample_84 & 15;
  }
  else
  {
    acc = ((acc - sample_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_64 = local_arr[aux % 3];
  acc = (acc + (cursor_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001907_0_1;
  int sec_r001907_0_2;
  int sec_r001907_1_1;
  int sec_r001907_1_2;
  int sec_r001907_2_1;
  int sec_r001907_2_2;
  int sec_r001907_3_1;
  int sec_r001907_3_2;
  int sec_r001907_4_1;
  int sec_r001907_4_2;
  int sec_r001907_5_1;
  int sec_r001907_5_2;
  int sec_r001907_6_1;
  int sec_r001907_6_2;
  int sec_r001907_7_1;
  int sec_r001907_7_2;
  int sec_r001907_8_1;
  int sec_r001907_8_2;
  int sec_r001907_9_1;
  int sec_r001907_9_2;
  int sec_r001907_10_1;
  int sec_r001907_10_2;
  int sec_r001907_11_1;
  int sec_r001907_11_2;
  int sec_r001907_12_1;
  int sec_r001907_12_2;
  int sec_r001907_13_1;
  int sec_r001907_13_2;
  int sec_r001907_14_1;
  int sec_r001907_14_2;
  int sec_r001907_15_1;
  int sec_r001907_15_2;
  int sec_r001907_16_1;
  int sec_r001907_16_2;
  int sec_r001907_17_1;
  int sec_r001907_17_2;
  int sec_r001907_18_1;
  int sec_r001907_18_2;
  int sec_r001907_19_1;
  int sec_r001907_19_2;
  int sec_r001907_20_1;
  int sec_r001907_20_2;
  int sec_r001907_21_1;
  int sec_r001907_21_2;
  int pub_r001907_0_1;
  int pub_r001907_0_2;
  int pub_r001907_1_1;
  int pub_r001907_1_2;
  int pub_r001907_2_1;
  int pub_r001907_2_2;
  int pub_r001907_3_1;
  int pub_r001907_3_2;
  int pub_r001907_4_1;
  int pub_r001907_4_2;
  int pub_r001907_5_1;
  int pub_r001907_5_2;
  int pub_r001907_6_1;
  int pub_r001907_6_2;
  int pub_r001907_7_1;
  int pub_r001907_7_2;
  int pub_r001907_8_1;
  int pub_r001907_8_2;
  int pub_r001907_9_1;
  int pub_r001907_9_2;
  int pub_r001907_10_1;
  int pub_r001907_10_2;
  int pub_r001907_11_1;
  int pub_r001907_11_2;
  int pub_r001907_12_1;
  int pub_r001907_12_2;
  int pub_r001907_13_1;
  int pub_r001907_13_2;
  int pub_r001907_14_1;
  int pub_r001907_14_2;
  int pub_r001907_15_1;
  int pub_r001907_15_2;
  int pub_r001907_16_1;
  int pub_r001907_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001907_0_1 >= (-100)) && (pub_r001907_0_1 <= 100));
  __CPROVER_assume((pub_r001907_0_2 >= (-100)) && (pub_r001907_0_2 <= 100));
  __CPROVER_assume((pub_r001907_1_1 >= (-100)) && (pub_r001907_1_1 <= 100));
  __CPROVER_assume((pub_r001907_1_2 >= (-100)) && (pub_r001907_1_2 <= 100));
  __CPROVER_assume((pub_r001907_2_1 >= (-100)) && (pub_r001907_2_1 <= 100));
  __CPROVER_assume((pub_r001907_2_2 >= (-100)) && (pub_r001907_2_2 <= 100));
  __CPROVER_assume((pub_r001907_3_1 >= (-100)) && (pub_r001907_3_1 <= 100));
  __CPROVER_assume((pub_r001907_3_2 >= (-100)) && (pub_r001907_3_2 <= 100));
  __CPROVER_assume((pub_r001907_4_1 >= (-100)) && (pub_r001907_4_1 <= 100));
  __CPROVER_assume((pub_r001907_4_2 >= (-100)) && (pub_r001907_4_2 <= 100));
  __CPROVER_assume((pub_r001907_5_1 >= (-100)) && (pub_r001907_5_1 <= 100));
  __CPROVER_assume((pub_r001907_5_2 >= (-100)) && (pub_r001907_5_2 <= 100));
  __CPROVER_assume((pub_r001907_6_1 >= (-100)) && (pub_r001907_6_1 <= 100));
  __CPROVER_assume((pub_r001907_6_2 >= (-100)) && (pub_r001907_6_2 <= 100));
  __CPROVER_assume((pub_r001907_7_1 >= (-100)) && (pub_r001907_7_1 <= 100));
  __CPROVER_assume((pub_r001907_7_2 >= (-100)) && (pub_r001907_7_2 <= 100));
  __CPROVER_assume((pub_r001907_8_1 >= (-100)) && (pub_r001907_8_1 <= 100));
  __CPROVER_assume((pub_r001907_8_2 >= (-100)) && (pub_r001907_8_2 <= 100));
  __CPROVER_assume((pub_r001907_9_1 >= (-100)) && (pub_r001907_9_1 <= 100));
  __CPROVER_assume((pub_r001907_9_2 >= (-100)) && (pub_r001907_9_2 <= 100));
  __CPROVER_assume((pub_r001907_10_1 >= (-100)) && (pub_r001907_10_1 <= 100));
  __CPROVER_assume((pub_r001907_10_2 >= (-100)) && (pub_r001907_10_2 <= 100));
  __CPROVER_assume((pub_r001907_11_1 >= (-100)) && (pub_r001907_11_1 <= 100));
  __CPROVER_assume((pub_r001907_11_2 >= (-100)) && (pub_r001907_11_2 <= 100));
  __CPROVER_assume((pub_r001907_12_1 >= (-100)) && (pub_r001907_12_1 <= 100));
  __CPROVER_assume((pub_r001907_12_2 >= (-100)) && (pub_r001907_12_2 <= 100));
  __CPROVER_assume((pub_r001907_13_1 >= (-100)) && (pub_r001907_13_1 <= 100));
  __CPROVER_assume((pub_r001907_13_2 >= (-100)) && (pub_r001907_13_2 <= 100));
  __CPROVER_assume((pub_r001907_14_1 >= (-100)) && (pub_r001907_14_1 <= 100));
  __CPROVER_assume((pub_r001907_14_2 >= (-100)) && (pub_r001907_14_2 <= 100));
  __CPROVER_assume((pub_r001907_15_1 >= (-100)) && (pub_r001907_15_1 <= 100));
  __CPROVER_assume((pub_r001907_15_2 >= (-100)) && (pub_r001907_15_2 <= 100));
  __CPROVER_assume((pub_r001907_16_1 >= (-100)) && (pub_r001907_16_1 <= 100));
  __CPROVER_assume((pub_r001907_16_2 >= (-100)) && (pub_r001907_16_2 <= 100));
  __CPROVER_assume((sec_r001907_0_1 >= 0) && (sec_r001907_0_1 <= 255));
  __CPROVER_assume((sec_r001907_0_2 >= 0) && (sec_r001907_0_2 <= 255));
  __CPROVER_assume((sec_r001907_1_1 >= 0) && (sec_r001907_1_1 <= 255));
  __CPROVER_assume((sec_r001907_1_2 >= 0) && (sec_r001907_1_2 <= 255));
  __CPROVER_assume((sec_r001907_2_1 >= 0) && (sec_r001907_2_1 <= 255));
  __CPROVER_assume((sec_r001907_2_2 >= 0) && (sec_r001907_2_2 <= 255));
  __CPROVER_assume((sec_r001907_3_1 >= 0) && (sec_r001907_3_1 <= 255));
  __CPROVER_assume((sec_r001907_3_2 >= 0) && (sec_r001907_3_2 <= 255));
  __CPROVER_assume((sec_r001907_4_1 >= 0) && (sec_r001907_4_1 <= 255));
  __CPROVER_assume((sec_r001907_4_2 >= 0) && (sec_r001907_4_2 <= 255));
  __CPROVER_assume((sec_r001907_5_1 >= 0) && (sec_r001907_5_1 <= 255));
  __CPROVER_assume((sec_r001907_5_2 >= 0) && (sec_r001907_5_2 <= 255));
  __CPROVER_assume((sec_r001907_6_1 >= 0) && (sec_r001907_6_1 <= 255));
  __CPROVER_assume((sec_r001907_6_2 >= 0) && (sec_r001907_6_2 <= 255));
  __CPROVER_assume((sec_r001907_7_1 >= 0) && (sec_r001907_7_1 <= 255));
  __CPROVER_assume((sec_r001907_7_2 >= 0) && (sec_r001907_7_2 <= 255));
  __CPROVER_assume((sec_r001907_8_1 >= 0) && (sec_r001907_8_1 <= 255));
  __CPROVER_assume((sec_r001907_8_2 >= 0) && (sec_r001907_8_2 <= 255));
  __CPROVER_assume((sec_r001907_9_1 >= 0) && (sec_r001907_9_1 <= 255));
  __CPROVER_assume((sec_r001907_9_2 >= 0) && (sec_r001907_9_2 <= 255));
  __CPROVER_assume((sec_r001907_10_1 >= 0) && (sec_r001907_10_1 <= 255));
  __CPROVER_assume((sec_r001907_10_2 >= 0) && (sec_r001907_10_2 <= 255));
  __CPROVER_assume((sec_r001907_11_1 >= 0) && (sec_r001907_11_1 <= 255));
  __CPROVER_assume((sec_r001907_11_2 >= 0) && (sec_r001907_11_2 <= 255));
  __CPROVER_assume((sec_r001907_12_1 >= 0) && (sec_r001907_12_1 <= 255));
  __CPROVER_assume((sec_r001907_12_2 >= 0) && (sec_r001907_12_2 <= 255));
  __CPROVER_assume((sec_r001907_13_1 >= 0) && (sec_r001907_13_1 <= 255));
  __CPROVER_assume((sec_r001907_13_2 >= 0) && (sec_r001907_13_2 <= 255));
  __CPROVER_assume((sec_r001907_14_1 >= 0) && (sec_r001907_14_1 <= 255));
  __CPROVER_assume((sec_r001907_14_2 >= 0) && (sec_r001907_14_2 <= 255));
  __CPROVER_assume((sec_r001907_15_1 >= 0) && (sec_r001907_15_1 <= 255));
  __CPROVER_assume((sec_r001907_15_2 >= 0) && (sec_r001907_15_2 <= 255));
  __CPROVER_assume((sec_r001907_16_1 >= 0) && (sec_r001907_16_1 <= 255));
  __CPROVER_assume((sec_r001907_16_2 >= 0) && (sec_r001907_16_2 <= 255));
  __CPROVER_assume((sec_r001907_17_1 >= 0) && (sec_r001907_17_1 <= 255));
  __CPROVER_assume((sec_r001907_17_2 >= 0) && (sec_r001907_17_2 <= 255));
  __CPROVER_assume((sec_r001907_18_1 >= 0) && (sec_r001907_18_1 <= 255));
  __CPROVER_assume((sec_r001907_18_2 >= 0) && (sec_r001907_18_2 <= 255));
  __CPROVER_assume((sec_r001907_19_1 >= 0) && (sec_r001907_19_1 <= 255));
  __CPROVER_assume((sec_r001907_19_2 >= 0) && (sec_r001907_19_2 <= 255));
  __CPROVER_assume((sec_r001907_20_1 >= 0) && (sec_r001907_20_1 <= 255));
  __CPROVER_assume((sec_r001907_20_2 >= 0) && (sec_r001907_20_2 <= 255));
  __CPROVER_assume((sec_r001907_21_1 >= 0) && (sec_r001907_21_1 <= 255));
  __CPROVER_assume((sec_r001907_21_2 >= 0) && (sec_r001907_21_2 <= 255));
  struct SensorNode_R001907_713_0 st_var_0_1 = {0};
  struct SensorNode_R001907_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001907_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001907_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001907_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001907_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001907_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001907_0_2 + 7) & 15;
  struct Vector3D_R001907_713_1 st_var_1_1 = {0};
  struct Vector3D_R001907_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001907_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001907_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001907_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001907_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001907_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001907_0_2 + 9) & 15;
  struct FilterState_R001907_713_2 st_var_2_1 = {0};
  struct FilterState_R001907_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001907_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001907_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001907_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001907_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001907_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001907_0_2 + 11) & 15;
  struct DeviceConfig_R001907_713_3 st_var_3_1 = {0};
  struct DeviceConfig_R001907_713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001907_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001907_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001907_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001907_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001907_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001907_0_2 + 13) & 15;
  union PacketPayload_R001907_713_0 u_var_1;
  union PacketPayload_R001907_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001907_713_0(sec_r001907_0_1, pub_r001907_1_1, pub_r001907_2_1, pub_r001907_3_1, pub_r001907_4_1);
  int helper_flow_0_2 = fn_R001907_713_0(sec_r001907_0_2, pub_r001907_1_2, pub_r001907_2_2, pub_r001907_3_2, pub_r001907_4_2);
  fn_R001907_713_0_2(sec_r001907_0_1, pub_r001907_1_1, pub_r001907_2_1, pub_r001907_3_1, pub_r001907_4_1, sec_r001907_0_2, pub_r001907_1_2, pub_r001907_2_2, pub_r001907_3_2, pub_r001907_4_2);
  int helper_flow_1_1 = fn_R001907_713_1(sec_r001907_1_1, pub_r001907_2_1);
  int helper_flow_1_2 = fn_R001907_713_1(sec_r001907_1_2, pub_r001907_2_2);
  fn_R001907_713_1_2(sec_r001907_1_1, pub_r001907_2_1, sec_r001907_1_2, pub_r001907_2_2);
  int helper_flow_2_1 = fn_R001907_713_2(sec_r001907_2_1, pub_r001907_3_1);
  int helper_flow_2_2 = fn_R001907_713_2(sec_r001907_2_2, pub_r001907_3_2);
  fn_R001907_713_2_2(sec_r001907_2_1, pub_r001907_3_1, sec_r001907_2_2, pub_r001907_3_2);
  int helper_flow_3_1 = fn_R001907_713_3(sec_r001907_3_1, pub_r001907_4_1, pub_r001907_5_1);
  int helper_flow_3_2 = fn_R001907_713_3(sec_r001907_3_2, pub_r001907_4_2, pub_r001907_5_2);
  fn_R001907_713_3_2(sec_r001907_3_1, pub_r001907_4_1, pub_r001907_5_1, sec_r001907_3_2, pub_r001907_4_2, pub_r001907_5_2);
  int helper_flow_4_1 = fn_R001907_713_4(sec_r001907_4_1, sec_r001907_5_1, pub_r001907_6_1, pub_r001907_7_1, pub_r001907_8_1);
  int helper_flow_4_2 = fn_R001907_713_4(sec_r001907_4_2, sec_r001907_5_2, pub_r001907_6_2, pub_r001907_7_2, pub_r001907_8_2);
  fn_R001907_713_4_2(sec_r001907_4_1, sec_r001907_5_1, pub_r001907_6_1, pub_r001907_7_1, pub_r001907_8_1, sec_r001907_4_2, sec_r001907_5_2, pub_r001907_6_2, pub_r001907_7_2, pub_r001907_8_2);
  int helper_flow_5_1 = fn_R001907_713_5(sec_r001907_5_1, pub_r001907_6_1, pub_r001907_7_1);
  int helper_flow_5_2 = fn_R001907_713_5(sec_r001907_5_2, pub_r001907_6_2, pub_r001907_7_2);
  fn_R001907_713_5_2(sec_r001907_5_1, pub_r001907_6_1, pub_r001907_7_1, sec_r001907_5_2, pub_r001907_6_2, pub_r001907_7_2);
  int helper_flow_6_1 = fn_R001907_713_6(sec_r001907_6_1, pub_r001907_7_1);
  int helper_flow_6_2 = fn_R001907_713_6(sec_r001907_6_2, pub_r001907_7_2);
  fn_R001907_713_6_2(sec_r001907_6_1, pub_r001907_7_1, sec_r001907_6_2, pub_r001907_7_2);
  int helper_flow_7_1 = fn_R001907_713_7(sec_r001907_7_1, pub_r001907_8_1);
  int helper_flow_7_2 = fn_R001907_713_7(sec_r001907_7_2, pub_r001907_8_2);
  fn_R001907_713_7_2(sec_r001907_7_1, pub_r001907_8_1, sec_r001907_7_2, pub_r001907_8_2);
  int helper_flow_8_1 = fn_R001907_713_8(sec_r001907_8_1, sec_r001907_9_1, pub_r001907_10_1, pub_r001907_11_1);
  int helper_flow_8_2 = fn_R001907_713_8(sec_r001907_8_2, sec_r001907_9_2, pub_r001907_10_2, pub_r001907_11_2);
  fn_R001907_713_8_2(sec_r001907_8_1, sec_r001907_9_1, pub_r001907_10_1, pub_r001907_11_1, sec_r001907_8_2, sec_r001907_9_2, pub_r001907_10_2, pub_r001907_11_2);
  int stage_v_0_1 = (sec_r001907_4_1 ^ pub_r001907_2_1) & 63;
  int stage_v_0_2 = (sec_r001907_4_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = ((pub_r001907_10_1 * 2) + 16) & 63;
  int stage_v_1_2 = ((pub_r001907_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (helper_flow_0_1 ^ pub_r001907_16_1) & 63;
  int stage_v_2_2 = (helper_flow_0_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001907_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((sec_r001907_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = ((pub_r001907_1_1 * 2) + 49) & 63;
  int stage_v_3_2 = ((pub_r001907_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (helper_flow_7_1 ^ pub_r001907_15_1) & 63;
  int stage_v_4_2 = (helper_flow_7_2 ^ pub_r001907_15_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = (sec_r001907_4_1 ^ pub_r001907_13_1) & 63;
  int stage_v_5_2 = (sec_r001907_4_2 ^ pub_r001907_13_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001907_19_1 ^ pub_r001907_16_1) & 63;
  int stage_v_6_2 = (sec_r001907_19_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (stage_v_2_1 ^ pub_r001907_15_1) & 63;
  int stage_v_7_2 = (stage_v_2_2 ^ pub_r001907_15_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001907_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001907_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = (sec_r001907_21_1 ^ pub_r001907_6_1) & 63;
  int stage_v_8_2 = (sec_r001907_21_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = ((pub_r001907_15_1 * 2) + 33) & 63;
  int stage_v_9_2 = ((pub_r001907_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (sec_r001907_12_1 ^ pub_r001907_7_1) & 63;
  int stage_v_10_2 = (sec_r001907_12_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = (sec_r001907_18_1 ^ pub_r001907_15_1) & 63;
  int stage_v_11_2 = (sec_r001907_18_2 ^ pub_r001907_15_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = ((pub_r001907_12_1 * 2) + 23) & 63;
  int stage_v_12_2 = ((pub_r001907_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (stage_v_10_1 ^ pub_r001907_9_1) & 63;
  int stage_v_13_2 = (stage_v_10_2 ^ pub_r001907_9_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001907_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001907_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = ((pub_r001907_3_1 * 2) + 14) & 63;
  int stage_v_14_2 = ((pub_r001907_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (helper_flow_5_1 ^ pub_r001907_6_1) & 63;
  int stage_v_15_2 = (helper_flow_5_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r001907_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r001907_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = (stage_v_10_1 ^ pub_r001907_12_1) & 63;
  int stage_v_16_2 = (stage_v_10_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r001907_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r001907_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = ((pub_r001907_8_1 * 2) + 18) & 63;
  int stage_v_17_2 = ((pub_r001907_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001907_1_1 * 2) + 27) & 63;
  int stage_v_18_2 = ((pub_r001907_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (stage_v_15_1 ^ pub_r001907_2_1) & 63;
  int stage_v_19_2 = (stage_v_15_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = ((pub_r001907_15_1 * 2) + 37) & 63;
  int stage_v_20_2 = ((pub_r001907_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (sec_r001907_3_1 ^ pub_r001907_6_1) & 63;
  int stage_v_21_2 = (sec_r001907_3_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001907_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r001907_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (sec_r001907_3_1 ^ pub_r001907_3_1) & 63;
  int stage_v_22_2 = (sec_r001907_3_2 ^ pub_r001907_3_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (stage_v_8_1 ^ pub_r001907_6_1) & 63;
  int stage_v_23_2 = (stage_v_8_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = (helper_flow_7_1 ^ pub_r001907_2_1) & 63;
  int stage_v_24_2 = (helper_flow_7_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (sec_r001907_11_1 ^ pub_r001907_16_1) & 63;
  int stage_v_25_2 = (sec_r001907_11_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r001907_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r001907_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (sec_r001907_13_1 ^ pub_r001907_14_1) & 63;
  int stage_v_26_2 = (sec_r001907_13_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001907_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001907_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (helper_flow_0_1 ^ pub_r001907_13_1) & 63;
  int stage_v_27_2 = (helper_flow_0_2 ^ pub_r001907_13_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r001907_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r001907_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = ((pub_r001907_11_1 * 2) + 5) & 63;
  int stage_v_28_2 = ((pub_r001907_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001907_2_1 * 2) + 15) & 63;
  int stage_v_29_2 = ((pub_r001907_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001907_3_1 * 2) + 9) & 63;
  int stage_v_30_2 = ((pub_r001907_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (helper_flow_6_1 ^ pub_r001907_14_1) & 63;
  int stage_v_31_2 = (helper_flow_6_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (sec_r001907_7_1 ^ pub_r001907_3_1) & 63;
  int stage_v_32_2 = (sec_r001907_7_2 ^ pub_r001907_3_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (stage_v_27_1 ^ pub_r001907_12_1) & 63;
  int stage_v_33_2 = (stage_v_27_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r001907_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r001907_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = ((pub_r001907_5_1 * 2) + 25) & 63;
  int stage_v_34_2 = ((pub_r001907_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (stage_v_21_1 ^ pub_r001907_4_1) & 63;
  int stage_v_35_2 = (stage_v_21_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = ((pub_r001907_6_1 * 2) + 33) & 63;
  int stage_v_36_2 = ((pub_r001907_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001907_4_1 * 2) + 45) & 63;
  int stage_v_37_2 = ((pub_r001907_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (helper_flow_6_1 ^ pub_r001907_14_1) & 63;
  int stage_v_38_2 = (helper_flow_6_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r001907_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r001907_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = (sec_r001907_9_1 ^ pub_r001907_1_1) & 63;
  int stage_v_39_2 = (sec_r001907_9_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (stage_v_35_1 ^ pub_r001907_16_1) & 63;
  int stage_v_40_2 = (stage_v_35_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001907_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r001907_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = ((pub_r001907_0_1 * 2) + 50) & 63;
  int stage_v_41_2 = ((pub_r001907_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (sec_r001907_20_1 ^ pub_r001907_7_1) & 63;
  int stage_v_42_2 = (sec_r001907_20_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = (stage_v_22_1 ^ pub_r001907_4_1) & 63;
  int stage_v_43_2 = (stage_v_22_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  }
  int stage_v_44_1 = (sec_r001907_21_1 ^ pub_r001907_8_1) & 63;
  int stage_v_44_2 = (sec_r001907_21_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r001907_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r001907_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = ((pub_r001907_6_1 * 2) + 18) & 63;
  int stage_v_45_2 = ((pub_r001907_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001907_6_1 * 2) + 39) & 63;
  int stage_v_46_2 = ((pub_r001907_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001907_4_1 * 2) + 26) & 63;
  int stage_v_47_2 = ((pub_r001907_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001907_13_1 * 2) + 37) & 63;
  int stage_v_48_2 = ((pub_r001907_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001907_1_1 * 2) + 11) & 63;
  int stage_v_49_2 = ((pub_r001907_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (stage_v_10_1 ^ pub_r001907_2_1) & 63;
  int stage_v_50_2 = (stage_v_10_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_24_1 ^ pub_r001907_13_1) & 63;
  int stage_v_51_2 = (stage_v_24_2 ^ pub_r001907_13_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r001907_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r001907_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (stage_v_26_1 ^ pub_r001907_11_1) & 63;
  int stage_v_52_2 = (stage_v_26_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = (helper_flow_8_1 ^ pub_r001907_6_1) & 63;
  int stage_v_53_2 = (helper_flow_8_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r001907_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r001907_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (sec_r001907_4_1 ^ pub_r001907_15_1) & 63;
  int stage_v_54_2 = (sec_r001907_4_2 ^ pub_r001907_15_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (stage_v_5_1 ^ pub_r001907_14_1) & 63;
  int stage_v_55_2 = (stage_v_5_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_53_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (helper_flow_3_1 ^ pub_r001907_11_1) & 63;
  int stage_v_56_2 = (helper_flow_3_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001907_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r001907_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (sec_r001907_10_1 ^ pub_r001907_1_1) & 63;
  int stage_v_57_2 = (sec_r001907_10_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (stage_v_5_1 ^ pub_r001907_10_1) & 63;
  int stage_v_58_2 = (stage_v_5_2 ^ pub_r001907_10_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r001907_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r001907_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = (sec_r001907_18_1 ^ pub_r001907_2_1) & 63;
  int stage_v_59_2 = (sec_r001907_18_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r001907_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r001907_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  }
  int stage_v_60_1 = (sec_r001907_12_1 ^ pub_r001907_0_1) & 63;
  int stage_v_60_2 = (sec_r001907_12_2 ^ pub_r001907_0_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((stage_v_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = ((pub_r001907_5_1 * 2) + 27) & 63;
  int stage_v_61_2 = ((pub_r001907_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001907_14_1 * 2) + 15) & 63;
  int stage_v_62_2 = ((pub_r001907_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001907_9_1 * 2) + 5) & 63;
  int stage_v_63_2 = ((pub_r001907_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_56_1 ^ pub_r001907_14_1) & 63;
  int stage_v_64_2 = (stage_v_56_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r001907_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r001907_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = (sec_r001907_14_1 ^ pub_r001907_0_1) & 63;
  int stage_v_65_2 = (sec_r001907_14_2 ^ pub_r001907_0_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r001907_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r001907_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = ((pub_r001907_8_1 * 2) + 13) & 63;
  int stage_v_66_2 = ((pub_r001907_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (stage_v_10_1 ^ pub_r001907_10_1) & 63;
  int stage_v_67_2 = (stage_v_10_2 ^ pub_r001907_10_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r001907_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r001907_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (helper_flow_2_1 ^ pub_r001907_12_1) & 63;
  int stage_v_68_2 = (helper_flow_2_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001907_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r001907_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (sec_r001907_21_1 ^ pub_r001907_7_1) & 63;
  int stage_v_69_2 = (sec_r001907_21_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_54_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = ((pub_r001907_7_1 * 2) + 8) & 63;
  int stage_v_70_2 = ((pub_r001907_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001907_5_1 * 2) + 8) & 63;
  int stage_v_71_2 = ((pub_r001907_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (stage_v_27_1 ^ pub_r001907_6_1) & 63;
  int stage_v_72_2 = (stage_v_27_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (stage_v_54_1 ^ pub_r001907_8_1) & 63;
  int stage_v_73_2 = (stage_v_54_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = (sec_r001907_7_1 ^ pub_r001907_7_1) & 63;
  int stage_v_74_2 = (sec_r001907_7_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = (sec_r001907_11_1 ^ pub_r001907_3_1) & 63;
  int stage_v_75_2 = (sec_r001907_11_2 ^ pub_r001907_3_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((stage_v_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = (sec_r001907_13_1 ^ pub_r001907_1_1) & 63;
  int stage_v_76_2 = (sec_r001907_13_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (stage_v_53_1 ^ pub_r001907_9_1) & 63;
  int stage_v_77_2 = (stage_v_53_2 ^ pub_r001907_9_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = ((pub_r001907_7_1 * 2) + 37) & 63;
  int stage_v_78_2 = ((pub_r001907_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001907_12_1 * 2) + 44) & 63;
  int stage_v_79_2 = ((pub_r001907_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001907_12_1 * 2) + 26) & 63;
  int stage_v_80_2 = ((pub_r001907_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (stage_v_59_1 ^ pub_r001907_1_1) & 63;
  int stage_v_81_2 = (stage_v_59_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (stage_v_24_1 ^ pub_r001907_2_1) & 63;
  int stage_v_82_2 = (stage_v_24_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (stage_v_53_1 ^ pub_r001907_14_1) & 63;
  int stage_v_83_2 = (stage_v_53_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_44_1 ^ pub_r001907_12_1) & 63;
  int stage_v_84_2 = (stage_v_44_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r001907_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r001907_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = (stage_v_73_1 ^ pub_r001907_2_1) & 63;
  int stage_v_85_2 = (stage_v_73_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (stage_v_40_1 ^ pub_r001907_13_1) & 63;
  int stage_v_86_2 = (stage_v_40_2 ^ pub_r001907_13_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = (stage_v_40_1 ^ pub_r001907_11_1) & 63;
  int stage_v_87_2 = (stage_v_40_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = (sec_r001907_16_1 ^ pub_r001907_12_1) & 63;
  int stage_v_88_2 = (sec_r001907_16_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = (stage_v_24_1 ^ pub_r001907_12_1) & 63;
  int stage_v_89_2 = (stage_v_24_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = ((pub_r001907_1_1 * 2) + 16) & 63;
  int stage_v_90_2 = ((pub_r001907_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (stage_v_54_1 ^ pub_r001907_12_1) & 63;
  int stage_v_91_2 = (stage_v_54_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = (stage_v_85_1 ^ pub_r001907_12_1) & 63;
  int stage_v_92_2 = (stage_v_85_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = (sec_r001907_18_1 ^ pub_r001907_4_1) & 63;
  int stage_v_93_2 = (sec_r001907_18_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r001907_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r001907_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = ((pub_r001907_11_1 * 2) + 15) & 63;
  int stage_v_94_2 = ((pub_r001907_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001907_6_1 * 2) + 7) & 63;
  int stage_v_95_2 = ((pub_r001907_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001907_5_1 * 2) + 13) & 63;
  int stage_v_96_2 = ((pub_r001907_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001907_0_1 * 2) + 48) & 63;
  int stage_v_97_2 = ((pub_r001907_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001907_10_1 * 2) + 26) & 63;
  int stage_v_98_2 = ((pub_r001907_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (helper_flow_4_1 ^ pub_r001907_12_1) & 63;
  int stage_v_99_2 = (helper_flow_4_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((stage_v_56_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = (stage_v_39_1 ^ pub_r001907_3_1) & 63;
  int stage_v_100_2 = (stage_v_39_2 ^ pub_r001907_3_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((stage_v_53_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = ((pub_r001907_3_1 * 2) + 12) & 63;
  int stage_v_101_2 = ((pub_r001907_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001907_12_1 * 2) + 23) & 63;
  int stage_v_102_2 = ((pub_r001907_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001907_4_1 * 2) + 32) & 63;
  int stage_v_103_2 = ((pub_r001907_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (sec_r001907_9_1 ^ pub_r001907_4_1) & 63;
  int stage_v_104_2 = (sec_r001907_9_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r001907_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r001907_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = (stage_v_38_1 ^ pub_r001907_8_1) & 63;
  int stage_v_105_2 = (stage_v_38_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((stage_v_75_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (stage_v_40_1 ^ pub_r001907_16_1) & 63;
  int stage_v_106_2 = (stage_v_40_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_89_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001907_10_1 * 2) + 21) & 63;
  int stage_v_107_2 = ((pub_r001907_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (stage_v_15_1 ^ pub_r001907_4_1) & 63;
  int stage_v_108_2 = (stage_v_15_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (sec_r001907_12_1 ^ pub_r001907_11_1) & 63;
  int stage_v_109_2 = (sec_r001907_12_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_73_1 ^ pub_r001907_2_1) & 63;
  int stage_v_110_2 = (stage_v_73_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = ((pub_r001907_0_1 * 2) + 31) & 63;
  int stage_v_111_2 = ((pub_r001907_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001907_12_1 * 2) + 37) & 63;
  int stage_v_112_2 = ((pub_r001907_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (stage_v_26_1 ^ pub_r001907_7_1) & 63;
  int stage_v_113_2 = (stage_v_26_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (stage_v_27_1 ^ pub_r001907_7_1) & 63;
  int stage_v_114_2 = (stage_v_27_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_86_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_86_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = (stage_v_26_1 ^ pub_r001907_8_1) & 63;
  int stage_v_115_2 = (stage_v_26_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_108_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_108_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = (stage_v_82_1 ^ pub_r001907_8_1) & 63;
  int stage_v_116_2 = (stage_v_82_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = ((pub_r001907_13_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001907_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (stage_v_15_1 ^ pub_r001907_1_1) & 63;
  int stage_v_118_2 = (stage_v_15_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_109_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = (stage_v_40_1 ^ pub_r001907_3_1) & 63;
  int stage_v_119_2 = (stage_v_40_2 ^ pub_r001907_3_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r001907_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r001907_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = ((pub_r001907_14_1 * 2) + 36) & 63;
  int stage_v_120_2 = ((pub_r001907_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (stage_v_59_1 ^ pub_r001907_1_1) & 63;
  int stage_v_121_2 = (stage_v_59_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((stage_v_93_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_6_1 ^ pub_r001907_4_1) & 63;
  int stage_v_122_2 = (stage_v_6_2 ^ pub_r001907_4_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (sec_r001907_15_1 ^ pub_r001907_9_1) & 63;
  int stage_v_123_2 = (sec_r001907_15_2 ^ pub_r001907_9_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_50_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (sec_r001907_9_1 ^ pub_r001907_1_1) & 63;
  int stage_v_124_2 = (sec_r001907_9_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = ((pub_r001907_3_1 * 2) + 27) & 63;
  int stage_v_125_2 = ((pub_r001907_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001907_9_1 * 2) + 19) & 63;
  int stage_v_126_2 = ((pub_r001907_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (stage_v_43_1 ^ pub_r001907_2_1) & 63;
  int stage_v_127_2 = (stage_v_43_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r001907_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r001907_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = (helper_flow_5_1 ^ pub_r001907_8_1) & 63;
  int stage_v_128_2 = (helper_flow_5_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = ((pub_r001907_14_1 * 2) + 5) & 63;
  int stage_v_129_2 = ((pub_r001907_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (stage_v_124_1 ^ pub_r001907_1_1) & 63;
  int stage_v_130_2 = (stage_v_124_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = (stage_v_121_1 ^ pub_r001907_9_1) & 63;
  int stage_v_131_2 = (stage_v_121_2 ^ pub_r001907_9_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (stage_v_11_1 ^ pub_r001907_2_1) & 63;
  int stage_v_132_2 = (stage_v_11_2 ^ pub_r001907_2_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_69_1 ^ pub_r001907_7_1) & 63;
  int stage_v_133_2 = (stage_v_69_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = (stage_v_32_1 ^ pub_r001907_16_1) & 63;
  int stage_v_134_2 = (stage_v_32_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r001907_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r001907_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = ((pub_r001907_15_1 * 2) + 39) & 63;
  int stage_v_135_2 = ((pub_r001907_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (stage_v_2_1 ^ pub_r001907_7_1) & 63;
  int stage_v_136_2 = (stage_v_2_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r001907_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r001907_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (stage_v_104_1 ^ pub_r001907_7_1) & 63;
  int stage_v_137_2 = (stage_v_104_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_99_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_99_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (stage_v_40_1 ^ pub_r001907_13_1) & 63;
  int stage_v_138_2 = (stage_v_40_2 ^ pub_r001907_13_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (stage_v_53_1 ^ pub_r001907_11_1) & 63;
  int stage_v_139_2 = (stage_v_53_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = ((pub_r001907_10_1 * 2) + 37) & 63;
  int stage_v_140_2 = ((pub_r001907_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (sec_r001907_7_1 ^ pub_r001907_6_1) & 63;
  int stage_v_141_2 = (sec_r001907_7_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_85_1 ^ pub_r001907_7_1) & 63;
  int stage_v_142_2 = (stage_v_85_2 ^ pub_r001907_7_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = (sec_r001907_2_1 ^ pub_r001907_15_1) & 63;
  int stage_v_143_2 = (sec_r001907_2_2 ^ pub_r001907_15_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_77_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (stage_v_11_1 ^ pub_r001907_5_1) & 63;
  int stage_v_144_2 = (stage_v_11_2 ^ pub_r001907_5_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r001907_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((sec_r001907_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = ((pub_r001907_16_1 * 2) + 45) & 63;
  int stage_v_145_2 = ((pub_r001907_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (helper_flow_2_1 ^ pub_r001907_8_1) & 63;
  int stage_v_146_2 = (helper_flow_2_2 ^ pub_r001907_8_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = ((pub_r001907_7_1 * 2) + 26) & 63;
  int stage_v_147_2 = ((pub_r001907_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (stage_v_26_1 ^ pub_r001907_6_1) & 63;
  int stage_v_148_2 = (stage_v_26_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_123_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((stage_v_123_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = (sec_r001907_9_1 ^ pub_r001907_1_1) & 63;
  int stage_v_149_2 = (sec_r001907_9_2 ^ pub_r001907_1_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r001907_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((sec_r001907_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (helper_flow_2_1 ^ pub_r001907_14_1) & 63;
  int stage_v_150_2 = (helper_flow_2_2 ^ pub_r001907_14_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_100_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (stage_v_31_1 ^ pub_r001907_12_1) & 63;
  int stage_v_151_2 = (stage_v_31_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((sec_r001907_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((sec_r001907_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (sec_r001907_10_1 ^ pub_r001907_9_1) & 63;
  int stage_v_152_2 = (sec_r001907_10_2 ^ pub_r001907_9_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (stage_v_25_1 ^ pub_r001907_0_1) & 63;
  int stage_v_153_2 = (stage_v_25_2 ^ pub_r001907_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_152_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_152_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = ((pub_r001907_2_1 * 2) + 18) & 63;
  int stage_v_154_2 = ((pub_r001907_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (stage_v_84_1 ^ pub_r001907_11_1) & 63;
  int stage_v_155_2 = (stage_v_84_2 ^ pub_r001907_11_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((sec_r001907_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((sec_r001907_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = (stage_v_155_1 ^ pub_r001907_0_1) & 63;
  int stage_v_156_2 = (stage_v_155_2 ^ pub_r001907_0_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_123_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_123_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = (stage_v_13_1 ^ pub_r001907_12_1) & 63;
  int stage_v_157_2 = (stage_v_13_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = (stage_v_50_1 ^ pub_r001907_6_1) & 63;
  int stage_v_158_2 = (stage_v_50_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_35_1 ^ pub_r001907_12_1) & 63;
  int stage_v_159_2 = (stage_v_35_2 ^ pub_r001907_12_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_127_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_127_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = (stage_v_89_1 ^ pub_r001907_6_1) & 63;
  int stage_v_160_2 = (stage_v_89_2 ^ pub_r001907_6_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = ((pub_r001907_2_1 * 2) + 31) & 63;
  int stage_v_161_2 = ((pub_r001907_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (stage_v_50_1 ^ pub_r001907_5_1) & 63;
  int stage_v_162_2 = (stage_v_50_2 ^ pub_r001907_5_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_156_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_156_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = (stage_v_143_1 ^ pub_r001907_10_1) & 63;
  int stage_v_163_2 = (stage_v_143_2 ^ pub_r001907_10_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_146_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_146_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (stage_v_152_1 ^ pub_r001907_10_1) & 63;
  int stage_v_164_2 = (stage_v_152_2 ^ pub_r001907_10_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((sec_r001907_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((sec_r001907_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_100_1 ^ pub_r001907_16_1) & 63;
  int stage_v_165_2 = (stage_v_100_2 ^ pub_r001907_16_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_65_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001907_3_1 != sec_r001907_3_2);
  __CPROVER_assume(sec_r001907_15_1 != sec_r001907_15_2);
  __CPROVER_assume(sec_r001907_8_1 != sec_r001907_8_2);
  __CPROVER_assume(pub_r001907_9_1 == pub_r001907_9_2);
  __CPROVER_assume(sec_r001907_14_1 != sec_r001907_14_2);
  __CPROVER_assume(sec_r001907_10_1 != sec_r001907_10_2);
  __CPROVER_assume(sec_r001907_21_1 != sec_r001907_21_2);
  __CPROVER_assume(pub_r001907_0_1 == pub_r001907_0_2);
  __CPROVER_assume(pub_r001907_7_1 == pub_r001907_7_2);
  __CPROVER_assume(sec_r001907_12_1 != sec_r001907_12_2);
  __CPROVER_assume(sec_r001907_13_1 != sec_r001907_13_2);
  __CPROVER_assume(sec_r001907_19_1 != sec_r001907_19_2);
  __CPROVER_assume(pub_r001907_4_1 == pub_r001907_4_2);
  __CPROVER_assume(pub_r001907_8_1 == pub_r001907_8_2);
  __CPROVER_assume(pub_r001907_16_1 == pub_r001907_16_2);
  __CPROVER_assume(sec_r001907_20_1 != sec_r001907_20_2);
  __CPROVER_assume(pub_r001907_10_1 == pub_r001907_10_2);
  __CPROVER_assume(sec_r001907_7_1 != sec_r001907_7_2);
  __CPROVER_assume(sec_r001907_1_1 != sec_r001907_1_2);
  __CPROVER_assume(sec_r001907_16_1 != sec_r001907_16_2);
  __CPROVER_assume(pub_r001907_1_1 == pub_r001907_1_2);
  __CPROVER_assume(sec_r001907_0_1 != sec_r001907_0_2);
  __CPROVER_assume(pub_r001907_12_1 == pub_r001907_12_2);
  __CPROVER_assume(sec_r001907_17_1 != sec_r001907_17_2);
  __CPROVER_assume(pub_r001907_3_1 == pub_r001907_3_2);
  __CPROVER_assume(sec_r001907_5_1 != sec_r001907_5_2);
  __CPROVER_assume(pub_r001907_14_1 == pub_r001907_14_2);
  __CPROVER_assume(pub_r001907_13_1 == pub_r001907_13_2);
  __CPROVER_assume(pub_r001907_15_1 == pub_r001907_15_2);
  __CPROVER_assume(pub_r001907_2_1 == pub_r001907_2_2);
  __CPROVER_assume(sec_r001907_11_1 != sec_r001907_11_2);
  __CPROVER_assume(pub_r001907_11_1 == pub_r001907_11_2);
  __CPROVER_assume(pub_r001907_5_1 == pub_r001907_5_2);
  __CPROVER_assume(sec_r001907_2_1 != sec_r001907_2_2);
  __CPROVER_assume(sec_r001907_4_1 != sec_r001907_4_2);
  __CPROVER_assume(sec_r001907_18_1 != sec_r001907_18_2);
  __CPROVER_assume(pub_r001907_6_1 == pub_r001907_6_2);
  __CPROVER_assume(sec_r001907_6_1 != sec_r001907_6_2);
  __CPROVER_assume(sec_r001907_9_1 != sec_r001907_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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
}


