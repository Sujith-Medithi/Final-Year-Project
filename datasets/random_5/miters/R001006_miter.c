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
struct DeviceConfig_R001006_613_0
{
  unsigned char timeout;
  int parity;
  int port;
  int baud_rate;
  int buffer[3];
};
struct StreamBuffer_R001006_613_1
{
  int head;
  int state;
  short capacity;
  short tail;
  short checksum;
  unsigned char watermark;
  int buffer[3];
};
struct Vector3D_R001006_613_2
{
  short norm_sq;
  int coord_x;
  unsigned char heading;
  int coord_z;
  unsigned char pitch;
  unsigned char coord_y;
  int buffer[3];
};
union TelemetryField_R001006_613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001006_613_1
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
void fn_R001006_613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_11_1) & 63;
  aux_2 = (aux_2 + phase_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_50_1 = local_arr_1[aux_1 % 3];
  int bound_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_50_2 * 2)) & 127;
  int offset_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_80_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_80_1 * 2)) + 5) & 127;
    aux_1 ^= offset_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_80_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_80_2 * 2)) + 5) & 127;
    aux_2 ^= offset_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_11_1 == phase_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_50_1 == bound_50_2);
  assert(offset_80_1 == offset_80_2);
}

int fn_R001006_613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_50 = local_arr[aux % 3];
  acc = (acc + (bound_50 * 2)) & 127;
  int offset_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_80 > 32)
  {
    acc = ((acc + (offset_80 * 2)) + 5) & 127;
    aux ^= offset_80 & 15;
  }
  else
  {
    acc = ((acc - offset_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001006_613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_25_1) & 63;
  aux_2 = (aux_2 + bound_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_95_1 > 47)
  {
    acc_1 = ((acc_1 + (offset_95_1 * 2)) + 5) & 127;
    aux_1 ^= offset_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_95_2 > 47)
  {
    acc_2 = ((acc_2 + (offset_95_2 * 2)) + 5) & 127;
    aux_2 ^= offset_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_95_1 = local_arr_1[aux_1 % 3];
  int offset_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_25_1 == bound_25_2);
  assert(offset_95_1 == offset_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

}

int fn_R001006_613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_25) & 63;
  acc ^= aux;
  int offset_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_95 > 47)
  {
    acc = ((acc + (offset_95 * 2)) + 5) & 127;
    aux ^= offset_95 & 15;
  }
  else
  {
    acc = ((acc - offset_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_95 = local_arr[aux % 3];
  acc = (acc + (offset_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_18_1)
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

  switch (margin_18_2)
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

  int quantum_98_1 = 0;
  int quantum_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_98_1 = ((quantum_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_98_2 = ((quantum_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_98_1) & 127;
    acc_2 = (acc_2 + quantum_98_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_78_1 = local_arr_1[aux_1 % 3];
  int parity_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_18_1 == margin_18_2);
  assert(quantum_98_1 == quantum_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_78_1 == parity_78_2);
}

int fn_R001006_613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_18 = (aux + st.buffer[1]) & 3;
  switch (margin_18)
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

  int quantum_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_98 = ((quantum_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_98) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_78 = local_arr[aux % 3];
  acc = (acc + (parity_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_92_1) & 63;
  aux_2 = (aux_2 + offset_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_75_1 = 0;
  int delta_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_75_1 = ((delta_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_75_2 = ((delta_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_75_1) & 127;
    acc_2 = (acc_2 + delta_75_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_70_1 = local_arr_1[aux_1 % 3];
  int vector_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_70_2 * 2)) & 127;
  int offset_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_33_1 > 49)
  {
    acc_1 = ((acc_1 + (offset_33_1 * 2)) + 5) & 127;
    aux_1 ^= offset_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_33_2 > 49)
  {
    acc_2 = ((acc_2 + (offset_33_2 * 2)) + 5) & 127;
    aux_2 ^= offset_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_92_1 == offset_92_2);
  assert(delta_75_1 == delta_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_70_1 == vector_70_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001006_613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_92) & 63;
  acc ^= aux;
  int delta_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_75 = ((delta_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_75) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_70 = local_arr[aux % 3];
  acc = (acc + (vector_70 * 2)) & 127;
  int offset_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_33 > 49)
  {
    acc = ((acc + (offset_33 * 2)) + 5) & 127;
    aux ^= offset_33 & 15;
  }
  else
  {
    acc = ((acc - offset_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001006_613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int coefficient_24_1 = 0;
  int coefficient_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_24_1 = ((coefficient_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_24_2 = ((coefficient_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_24_1) & 127;
    acc_2 = (acc_2 + coefficient_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_24_1 == coefficient_24_2);
}

int fn_R001006_613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int coefficient_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_24 = ((coefficient_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_61_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_61_1 * 2)) + 5) & 127;
    aux_1 ^= offset_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_61_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_61_2 * 2)) + 5) & 127;
    aux_2 ^= offset_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_25_1) & 63;
  aux_2 = (aux_2 + tracker_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_83_1 = local_arr_1[aux_1 % 3];
  int quantum_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_61_1 == offset_61_2);
  assert(tracker_25_1 == tracker_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_83_1 == quantum_83_2);
}

int fn_R001006_613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_61 > 26)
  {
    acc = ((acc + (offset_61 * 2)) + 5) & 127;
    aux ^= offset_61 & 15;
  }
  else
  {
    acc = ((acc - offset_61) + 11) & 127;
    aux += 3;
  }
  int tracker_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_83 = local_arr[aux % 3];
  acc = (acc + (quantum_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_26_1 = 0;
  int residue_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_26_1 = ((residue_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_26_2 = ((residue_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_26_1) & 127;
    acc_2 = (acc_2 + residue_26_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_32_1 > 46)
  {
    acc_1 = ((acc_1 + (weight_32_1 * 2)) + 5) & 127;
    aux_1 ^= weight_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_32_2 > 46)
  {
    acc_2 = ((acc_2 + (weight_32_2 * 2)) + 5) & 127;
    aux_2 ^= weight_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_69_1) & 63;
  aux_2 = (aux_2 + sample_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_26_1 == residue_26_2);
  assert(weight_32_1 == weight_32_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R001006_613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_26 = ((residue_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_26) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_32 > 46)
  {
    acc = ((acc + (weight_32 * 2)) + 5) & 127;
    aux ^= weight_32 & 15;
  }
  else
  {
    acc = ((acc - weight_32) + 11) & 127;
    aux += 3;
  }
  int sample_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001006_613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_10_1)
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

  switch (weight_10_2)
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
  int mask_80_1 = local_arr_1[aux_1 % 3];
  int mask_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_10_1 == weight_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_80_1 == mask_80_2);
}

int fn_R001006_613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_10 = (aux + st.buffer[1]) & 3;
  switch (weight_10)
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
  int mask_80 = local_arr[aux % 3];
  acc = (acc + (mask_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_46_1)
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

  switch (accumulator_46_2)
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

  int mask_50_1 = 0;
  int mask_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_50_1 = ((mask_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_50_2 = ((mask_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_50_1) & 127;
    acc_2 = (acc_2 + mask_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_46_1 == accumulator_46_2);
  assert(mask_50_1 == mask_50_2);
}

int fn_R001006_613_8(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_46 = (aux + st.buffer[1]) & 3;
  switch (accumulator_46)
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

  int mask_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_50 = ((mask_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001006_613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int bound_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_75_1)
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

  switch (bound_75_2)
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

  int parity_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_91_1 > 47)
  {
    acc_1 = ((acc_1 + (parity_91_1 * 2)) + 5) & 127;
    aux_1 ^= parity_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_91_2 > 47)
  {
    acc_2 = ((acc_2 + (parity_91_2 * 2)) + 5) & 127;
    aux_2 ^= parity_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_89_1 = local_arr_1[aux_1 % 3];
  int checksum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_89_2 * 2)) & 127;
  int tally_16_1 = 0;
  int tally_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_16_1 = ((tally_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_16_2 = ((tally_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_16_1) & 127;
    acc_2 = (acc_2 + tally_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_75_1 == bound_75_2);
  assert(parity_91_1 == parity_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_89_1 == checksum_89_2);
  assert(tally_16_1 == tally_16_2);
}

int fn_R001006_613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int bound_75 = (aux + st.buffer[1]) & 3;
  switch (bound_75)
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

  int parity_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_91 > 47)
  {
    acc = ((acc + (parity_91 * 2)) + 5) & 127;
    aux ^= parity_91 & 15;
  }
  else
  {
    acc = ((acc - parity_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_89 = local_arr[aux % 3];
  acc = (acc + (checksum_89 * 2)) & 127;
  int tally_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_16 = ((tally_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001006_613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st_1 = {0};
  struct Vector3D_R001006_613_2 st_2 = {0};
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
  int anchor_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_95_1)
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

  switch (anchor_95_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_95_1 == anchor_95_2);
}

int fn_R001006_613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_95 = (aux + st.buffer[1]) & 3;
  switch (anchor_95)
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

void fn_R001006_613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_27_1)
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

  switch (index_reg_27_2)
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

  int anchor_61_1 = 0;
  int anchor_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_61_1 = ((anchor_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_61_2 = ((anchor_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_61_1) & 127;
    acc_2 = (acc_2 + anchor_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_27_1 == index_reg_27_2);
  assert(anchor_61_1 == anchor_61_2);
}

int fn_R001006_613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_27 = (aux + st.buffer[1]) & 3;
  switch (index_reg_27)
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

  int anchor_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_61 = ((anchor_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001006_613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_38_1 > 33)
  {
    acc_1 = ((acc_1 + (checksum_38_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_38_2 > 33)
  {
    acc_2 = ((acc_2 + (checksum_38_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_29_1 = local_arr_1[aux_1 % 3];
  int residue_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_29_2 * 2)) & 127;
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_38_1 == checksum_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_29_1 == residue_29_2);
  assert(mask_92_1 == mask_92_2);
}

int fn_R001006_613_12(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_38 > 33)
  {
    acc = ((acc + (checksum_38 * 2)) + 5) & 127;
    aux ^= checksum_38 & 15;
  }
  else
  {
    acc = ((acc - checksum_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_29 = local_arr[aux % 3];
  acc = (acc + (residue_29 * 2)) & 127;
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

void fn_R001006_613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_77_1 = local_arr_1[aux_1 % 3];
  int damping_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_77_2 * 2)) & 127;
  int weight_17_1 = 0;
  int weight_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_17_1 = ((weight_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_17_2 = ((weight_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_17_1) & 127;
    acc_2 = (acc_2 + weight_17_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_60_1 > 22)
  {
    acc_1 = ((acc_1 + (index_reg_60_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_60_2 > 22)
  {
    acc_2 = ((acc_2 + (index_reg_60_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_77_1 == damping_77_2);
  assert(weight_17_1 == weight_17_2);
  assert(index_reg_60_1 == index_reg_60_2);
}

int fn_R001006_613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int damping_77 = local_arr[aux % 3];
  acc = (acc + (damping_77 * 2)) & 127;
  int weight_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_17 = ((weight_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_17) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_60 > 22)
  {
    acc = ((acc + (index_reg_60 * 2)) + 5) & 127;
    aux ^= index_reg_60 & 15;
  }
  else
  {
    acc = ((acc - index_reg_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001006_613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st_1 = {0};
  struct Vector3D_R001006_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_19_1 = local_arr_1[aux_1 % 3];
  int residue_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_19_2 * 2)) & 127;
  int cursor_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_88_1)
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

  switch (cursor_88_2)
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
  int window_82_1 = 0;
  int window_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_82_1 = ((window_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_82_2 = ((window_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_82_1) & 127;
    acc_2 = (acc_2 + window_82_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_19_1 == residue_19_2);
  assert(cursor_88_1 == cursor_88_2);
  assert(window_82_1 == window_82_2);
}

int fn_R001006_613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int residue_19 = local_arr[aux % 3];
  acc = (acc + (residue_19 * 2)) & 127;
  int cursor_88 = (aux + st.buffer[1]) & 3;
  switch (cursor_88)
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
  int window_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_82 = ((window_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_82) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001006_613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_97_1 = 0;
  int segment_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_97_1 = ((segment_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_97_2 = ((segment_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_97_1) & 127;
    acc_2 = (acc_2 + segment_97_2) & 127;
  }

  int scale_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_78_1 > 21)
  {
    acc_1 = ((acc_1 + (scale_78_1 * 2)) + 5) & 127;
    aux_1 ^= scale_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_78_2 > 21)
  {
    acc_2 = ((acc_2 + (scale_78_2 * 2)) + 5) & 127;
    aux_2 ^= scale_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_51_1)
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

  switch (threshold_51_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_97_1 == segment_97_2);
  assert(scale_78_1 == scale_78_2);
  assert(threshold_51_1 == threshold_51_2);
}

int fn_R001006_613_15(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_97 = ((segment_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_97) & 127;
  }

  int scale_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_78 > 21)
  {
    acc = ((acc + (scale_78 * 2)) + 5) & 127;
    aux ^= scale_78 & 15;
  }
  else
  {
    acc = ((acc - scale_78) + 11) & 127;
    aux += 3;
  }
  int threshold_51 = (aux + st.buffer[1]) & 3;
  switch (threshold_51)
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

void fn_R001006_613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st_1 = {0};
  struct DeviceConfig_R001006_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int weight_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_91_1)
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

  switch (weight_91_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_64_1 = local_arr_1[aux_1 % 3];
  int bound_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_64_2 * 2)) & 127;
  int sample_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_63_1 > 46)
  {
    acc_1 = ((acc_1 + (sample_63_1 * 2)) + 5) & 127;
    aux_1 ^= sample_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_63_2 > 46)
  {
    acc_2 = ((acc_2 + (sample_63_2 * 2)) + 5) & 127;
    aux_2 ^= sample_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_63_1 = 0;
  int residue_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_63_1 = ((residue_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_63_2 = ((residue_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_63_1) & 127;
    acc_2 = (acc_2 + residue_63_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_91_1 == weight_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_64_1 == bound_64_2);
  assert(sample_63_1 == sample_63_2);
  assert(residue_63_1 == residue_63_2);
}

int fn_R001006_613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001006_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int weight_91 = (aux + st.buffer[1]) & 3;
  switch (weight_91)
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

  int local_arr[3] = {4, 9, 15};
  int bound_64 = local_arr[aux % 3];
  acc = (acc + (bound_64 * 2)) & 127;
  int sample_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_63 > 46)
  {
    acc = ((acc + (sample_63 * 2)) + 5) & 127;
    aux ^= sample_63 & 15;
  }
  else
  {
    acc = ((acc - sample_63) + 11) & 127;
    aux += 3;
  }
  int residue_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_63 = ((residue_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_63) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001006_613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st_1 = {0};
  struct StreamBuffer_R001006_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_36_1 > 17)
  {
    acc_1 = ((acc_1 + (accumulator_36_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_36_2 > 17)
  {
    acc_2 = ((acc_2 + (accumulator_36_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_84_1 = local_arr_1[aux_1 % 3];
  int accumulator_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_36_1 == accumulator_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_84_1 == accumulator_84_2);
}

int fn_R001006_613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001006_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_36 > 17)
  {
    acc = ((acc + (accumulator_36 * 2)) + 5) & 127;
    aux ^= accumulator_36 & 15;
  }
  else
  {
    acc = ((acc - accumulator_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_84 = local_arr[aux % 3];
  acc = (acc + (accumulator_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001006_613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st_1 = {0};
  struct Vector3D_R001006_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quantum_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_41_1)
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

  switch (quantum_41_2)
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
  int index_reg_98_1 = local_arr_1[aux_1 % 3];
  int index_reg_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_98_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_42_1 = 0;
  int metric_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_42_1 = ((metric_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_42_2 = ((metric_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_42_1) & 127;
    acc_2 = (acc_2 + metric_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_41_1 == quantum_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_98_1 == index_reg_98_2);
  assert(metric_42_1 == metric_42_2);
}

int fn_R001006_613_18(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001006_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quantum_41 = (aux + st.buffer[1]) & 3;
  switch (quantum_41)
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
  int index_reg_98 = local_arr[aux % 3];
  acc = (acc + (index_reg_98 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_42 = ((metric_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_42) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001006_0_1;
  int sec_r001006_0_2;
  int sec_r001006_1_1;
  int sec_r001006_1_2;
  int sec_r001006_2_1;
  int sec_r001006_2_2;
  int sec_r001006_3_1;
  int sec_r001006_3_2;
  int sec_r001006_4_1;
  int sec_r001006_4_2;
  int sec_r001006_5_1;
  int sec_r001006_5_2;
  int sec_r001006_6_1;
  int sec_r001006_6_2;
  int sec_r001006_7_1;
  int sec_r001006_7_2;
  int sec_r001006_8_1;
  int sec_r001006_8_2;
  int sec_r001006_9_1;
  int sec_r001006_9_2;
  int sec_r001006_10_1;
  int sec_r001006_10_2;
  int sec_r001006_11_1;
  int sec_r001006_11_2;
  int sec_r001006_12_1;
  int sec_r001006_12_2;
  int sec_r001006_13_1;
  int sec_r001006_13_2;
  int sec_r001006_14_1;
  int sec_r001006_14_2;
  int sec_r001006_15_1;
  int sec_r001006_15_2;
  int sec_r001006_16_1;
  int sec_r001006_16_2;
  int sec_r001006_17_1;
  int sec_r001006_17_2;
  int sec_r001006_18_1;
  int sec_r001006_18_2;
  int sec_r001006_19_1;
  int sec_r001006_19_2;
  int sec_r001006_20_1;
  int sec_r001006_20_2;
  int sec_r001006_21_1;
  int sec_r001006_21_2;
  int sec_r001006_22_1;
  int sec_r001006_22_2;
  int sec_r001006_23_1;
  int sec_r001006_23_2;
  int pub_r001006_0_1;
  int pub_r001006_0_2;
  int pub_r001006_1_1;
  int pub_r001006_1_2;
  int pub_r001006_2_1;
  int pub_r001006_2_2;
  int pub_r001006_3_1;
  int pub_r001006_3_2;
  int pub_r001006_4_1;
  int pub_r001006_4_2;
  int pub_r001006_5_1;
  int pub_r001006_5_2;
  int pub_r001006_6_1;
  int pub_r001006_6_2;
  int pub_r001006_7_1;
  int pub_r001006_7_2;
  int pub_r001006_8_1;
  int pub_r001006_8_2;
  int pub_r001006_9_1;
  int pub_r001006_9_2;
  int pub_r001006_10_1;
  int pub_r001006_10_2;
  int pub_r001006_11_1;
  int pub_r001006_11_2;
  int pub_r001006_12_1;
  int pub_r001006_12_2;
  int pub_r001006_13_1;
  int pub_r001006_13_2;
  int pub_r001006_14_1;
  int pub_r001006_14_2;
  int pub_r001006_15_1;
  int pub_r001006_15_2;
  int pub_r001006_16_1;
  int pub_r001006_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001006_0_1 >= (-100)) && (pub_r001006_0_1 <= 100));
  __CPROVER_assume((pub_r001006_0_2 >= (-100)) && (pub_r001006_0_2 <= 100));
  __CPROVER_assume((pub_r001006_1_1 >= (-100)) && (pub_r001006_1_1 <= 100));
  __CPROVER_assume((pub_r001006_1_2 >= (-100)) && (pub_r001006_1_2 <= 100));
  __CPROVER_assume((pub_r001006_2_1 >= (-100)) && (pub_r001006_2_1 <= 100));
  __CPROVER_assume((pub_r001006_2_2 >= (-100)) && (pub_r001006_2_2 <= 100));
  __CPROVER_assume((pub_r001006_3_1 >= (-100)) && (pub_r001006_3_1 <= 100));
  __CPROVER_assume((pub_r001006_3_2 >= (-100)) && (pub_r001006_3_2 <= 100));
  __CPROVER_assume((pub_r001006_4_1 >= (-100)) && (pub_r001006_4_1 <= 100));
  __CPROVER_assume((pub_r001006_4_2 >= (-100)) && (pub_r001006_4_2 <= 100));
  __CPROVER_assume((pub_r001006_5_1 >= (-100)) && (pub_r001006_5_1 <= 100));
  __CPROVER_assume((pub_r001006_5_2 >= (-100)) && (pub_r001006_5_2 <= 100));
  __CPROVER_assume((pub_r001006_6_1 >= (-100)) && (pub_r001006_6_1 <= 100));
  __CPROVER_assume((pub_r001006_6_2 >= (-100)) && (pub_r001006_6_2 <= 100));
  __CPROVER_assume((pub_r001006_7_1 >= (-100)) && (pub_r001006_7_1 <= 100));
  __CPROVER_assume((pub_r001006_7_2 >= (-100)) && (pub_r001006_7_2 <= 100));
  __CPROVER_assume((pub_r001006_8_1 >= (-100)) && (pub_r001006_8_1 <= 100));
  __CPROVER_assume((pub_r001006_8_2 >= (-100)) && (pub_r001006_8_2 <= 100));
  __CPROVER_assume((pub_r001006_9_1 >= (-100)) && (pub_r001006_9_1 <= 100));
  __CPROVER_assume((pub_r001006_9_2 >= (-100)) && (pub_r001006_9_2 <= 100));
  __CPROVER_assume((pub_r001006_10_1 >= (-100)) && (pub_r001006_10_1 <= 100));
  __CPROVER_assume((pub_r001006_10_2 >= (-100)) && (pub_r001006_10_2 <= 100));
  __CPROVER_assume((pub_r001006_11_1 >= (-100)) && (pub_r001006_11_1 <= 100));
  __CPROVER_assume((pub_r001006_11_2 >= (-100)) && (pub_r001006_11_2 <= 100));
  __CPROVER_assume((pub_r001006_12_1 >= (-100)) && (pub_r001006_12_1 <= 100));
  __CPROVER_assume((pub_r001006_12_2 >= (-100)) && (pub_r001006_12_2 <= 100));
  __CPROVER_assume((pub_r001006_13_1 >= (-100)) && (pub_r001006_13_1 <= 100));
  __CPROVER_assume((pub_r001006_13_2 >= (-100)) && (pub_r001006_13_2 <= 100));
  __CPROVER_assume((pub_r001006_14_1 >= (-100)) && (pub_r001006_14_1 <= 100));
  __CPROVER_assume((pub_r001006_14_2 >= (-100)) && (pub_r001006_14_2 <= 100));
  __CPROVER_assume((pub_r001006_15_1 >= (-100)) && (pub_r001006_15_1 <= 100));
  __CPROVER_assume((pub_r001006_15_2 >= (-100)) && (pub_r001006_15_2 <= 100));
  __CPROVER_assume((pub_r001006_16_1 >= (-100)) && (pub_r001006_16_1 <= 100));
  __CPROVER_assume((pub_r001006_16_2 >= (-100)) && (pub_r001006_16_2 <= 100));
  __CPROVER_assume((sec_r001006_0_1 >= 0) && (sec_r001006_0_1 <= 255));
  __CPROVER_assume((sec_r001006_0_2 >= 0) && (sec_r001006_0_2 <= 255));
  __CPROVER_assume((sec_r001006_1_1 >= 0) && (sec_r001006_1_1 <= 255));
  __CPROVER_assume((sec_r001006_1_2 >= 0) && (sec_r001006_1_2 <= 255));
  __CPROVER_assume((sec_r001006_2_1 >= 0) && (sec_r001006_2_1 <= 255));
  __CPROVER_assume((sec_r001006_2_2 >= 0) && (sec_r001006_2_2 <= 255));
  __CPROVER_assume((sec_r001006_3_1 >= 0) && (sec_r001006_3_1 <= 255));
  __CPROVER_assume((sec_r001006_3_2 >= 0) && (sec_r001006_3_2 <= 255));
  __CPROVER_assume((sec_r001006_4_1 >= 0) && (sec_r001006_4_1 <= 255));
  __CPROVER_assume((sec_r001006_4_2 >= 0) && (sec_r001006_4_2 <= 255));
  __CPROVER_assume((sec_r001006_5_1 >= 0) && (sec_r001006_5_1 <= 255));
  __CPROVER_assume((sec_r001006_5_2 >= 0) && (sec_r001006_5_2 <= 255));
  __CPROVER_assume((sec_r001006_6_1 >= 0) && (sec_r001006_6_1 <= 255));
  __CPROVER_assume((sec_r001006_6_2 >= 0) && (sec_r001006_6_2 <= 255));
  __CPROVER_assume((sec_r001006_7_1 >= 0) && (sec_r001006_7_1 <= 255));
  __CPROVER_assume((sec_r001006_7_2 >= 0) && (sec_r001006_7_2 <= 255));
  __CPROVER_assume((sec_r001006_8_1 >= 0) && (sec_r001006_8_1 <= 255));
  __CPROVER_assume((sec_r001006_8_2 >= 0) && (sec_r001006_8_2 <= 255));
  __CPROVER_assume((sec_r001006_9_1 >= 0) && (sec_r001006_9_1 <= 255));
  __CPROVER_assume((sec_r001006_9_2 >= 0) && (sec_r001006_9_2 <= 255));
  __CPROVER_assume((sec_r001006_10_1 >= 0) && (sec_r001006_10_1 <= 255));
  __CPROVER_assume((sec_r001006_10_2 >= 0) && (sec_r001006_10_2 <= 255));
  __CPROVER_assume((sec_r001006_11_1 >= 0) && (sec_r001006_11_1 <= 255));
  __CPROVER_assume((sec_r001006_11_2 >= 0) && (sec_r001006_11_2 <= 255));
  __CPROVER_assume((sec_r001006_12_1 >= 0) && (sec_r001006_12_1 <= 255));
  __CPROVER_assume((sec_r001006_12_2 >= 0) && (sec_r001006_12_2 <= 255));
  __CPROVER_assume((sec_r001006_13_1 >= 0) && (sec_r001006_13_1 <= 255));
  __CPROVER_assume((sec_r001006_13_2 >= 0) && (sec_r001006_13_2 <= 255));
  __CPROVER_assume((sec_r001006_14_1 >= 0) && (sec_r001006_14_1 <= 255));
  __CPROVER_assume((sec_r001006_14_2 >= 0) && (sec_r001006_14_2 <= 255));
  __CPROVER_assume((sec_r001006_15_1 >= 0) && (sec_r001006_15_1 <= 255));
  __CPROVER_assume((sec_r001006_15_2 >= 0) && (sec_r001006_15_2 <= 255));
  __CPROVER_assume((sec_r001006_16_1 >= 0) && (sec_r001006_16_1 <= 255));
  __CPROVER_assume((sec_r001006_16_2 >= 0) && (sec_r001006_16_2 <= 255));
  __CPROVER_assume((sec_r001006_17_1 >= 0) && (sec_r001006_17_1 <= 255));
  __CPROVER_assume((sec_r001006_17_2 >= 0) && (sec_r001006_17_2 <= 255));
  __CPROVER_assume((sec_r001006_18_1 >= 0) && (sec_r001006_18_1 <= 255));
  __CPROVER_assume((sec_r001006_18_2 >= 0) && (sec_r001006_18_2 <= 255));
  __CPROVER_assume((sec_r001006_19_1 >= 0) && (sec_r001006_19_1 <= 255));
  __CPROVER_assume((sec_r001006_19_2 >= 0) && (sec_r001006_19_2 <= 255));
  __CPROVER_assume((sec_r001006_20_1 >= 0) && (sec_r001006_20_1 <= 255));
  __CPROVER_assume((sec_r001006_20_2 >= 0) && (sec_r001006_20_2 <= 255));
  __CPROVER_assume((sec_r001006_21_1 >= 0) && (sec_r001006_21_1 <= 255));
  __CPROVER_assume((sec_r001006_21_2 >= 0) && (sec_r001006_21_2 <= 255));
  __CPROVER_assume((sec_r001006_22_1 >= 0) && (sec_r001006_22_1 <= 255));
  __CPROVER_assume((sec_r001006_22_2 >= 0) && (sec_r001006_22_2 <= 255));
  __CPROVER_assume((sec_r001006_23_1 >= 0) && (sec_r001006_23_1 <= 255));
  __CPROVER_assume((sec_r001006_23_2 >= 0) && (sec_r001006_23_2 <= 255));
  struct DeviceConfig_R001006_613_0 st_var_0_1 = {0};
  struct DeviceConfig_R001006_613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001006_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001006_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001006_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001006_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001006_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001006_0_2 + 7) & 15;
  struct StreamBuffer_R001006_613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001006_613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001006_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001006_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001006_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001006_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001006_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001006_0_2 + 9) & 15;
  struct Vector3D_R001006_613_2 st_var_2_1 = {0};
  struct Vector3D_R001006_613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001006_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001006_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001006_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001006_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001006_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001006_0_2 + 11) & 15;
  union TelemetryField_R001006_613_0 u_var_1;
  union TelemetryField_R001006_613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001006_613_0(sec_r001006_0_1, pub_r001006_1_1, pub_r001006_2_1, pub_r001006_3_1, pub_r001006_4_1);
  int helper_flow_0_2 = fn_R001006_613_0(sec_r001006_0_2, pub_r001006_1_2, pub_r001006_2_2, pub_r001006_3_2, pub_r001006_4_2);
  fn_R001006_613_0_2(sec_r001006_0_1, pub_r001006_1_1, pub_r001006_2_1, pub_r001006_3_1, pub_r001006_4_1, sec_r001006_0_2, pub_r001006_1_2, pub_r001006_2_2, pub_r001006_3_2, pub_r001006_4_2);
  int helper_flow_1_1 = fn_R001006_613_1(sec_r001006_1_1, sec_r001006_2_1, pub_r001006_3_1);
  int helper_flow_1_2 = fn_R001006_613_1(sec_r001006_1_2, sec_r001006_2_2, pub_r001006_3_2);
  fn_R001006_613_1_2(sec_r001006_1_1, sec_r001006_2_1, pub_r001006_3_1, sec_r001006_1_2, sec_r001006_2_2, pub_r001006_3_2);
  int helper_flow_2_1 = fn_R001006_613_2(sec_r001006_2_1, pub_r001006_3_1, pub_r001006_4_1, pub_r001006_5_1, pub_r001006_6_1);
  int helper_flow_2_2 = fn_R001006_613_2(sec_r001006_2_2, pub_r001006_3_2, pub_r001006_4_2, pub_r001006_5_2, pub_r001006_6_2);
  fn_R001006_613_2_2(sec_r001006_2_1, pub_r001006_3_1, pub_r001006_4_1, pub_r001006_5_1, pub_r001006_6_1, sec_r001006_2_2, pub_r001006_3_2, pub_r001006_4_2, pub_r001006_5_2, pub_r001006_6_2);
  int helper_flow_3_1 = fn_R001006_613_3(sec_r001006_3_1, pub_r001006_4_1, pub_r001006_5_1);
  int helper_flow_3_2 = fn_R001006_613_3(sec_r001006_3_2, pub_r001006_4_2, pub_r001006_5_2);
  fn_R001006_613_3_2(sec_r001006_3_1, pub_r001006_4_1, pub_r001006_5_1, sec_r001006_3_2, pub_r001006_4_2, pub_r001006_5_2);
  int helper_flow_4_1 = fn_R001006_613_4(sec_r001006_4_1, sec_r001006_5_1, pub_r001006_6_1, pub_r001006_7_1, pub_r001006_8_1);
  int helper_flow_4_2 = fn_R001006_613_4(sec_r001006_4_2, sec_r001006_5_2, pub_r001006_6_2, pub_r001006_7_2, pub_r001006_8_2);
  fn_R001006_613_4_2(sec_r001006_4_1, sec_r001006_5_1, pub_r001006_6_1, pub_r001006_7_1, pub_r001006_8_1, sec_r001006_4_2, sec_r001006_5_2, pub_r001006_6_2, pub_r001006_7_2, pub_r001006_8_2);
  int helper_flow_5_1 = fn_R001006_613_5(sec_r001006_5_1, sec_r001006_6_1, pub_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1);
  int helper_flow_5_2 = fn_R001006_613_5(sec_r001006_5_2, sec_r001006_6_2, pub_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2);
  fn_R001006_613_5_2(sec_r001006_5_1, sec_r001006_6_1, pub_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1, sec_r001006_5_2, sec_r001006_6_2, pub_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2);
  int helper_flow_6_1 = fn_R001006_613_6(sec_r001006_6_1, sec_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1, pub_r001006_10_1);
  int helper_flow_6_2 = fn_R001006_613_6(sec_r001006_6_2, sec_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2, pub_r001006_10_2);
  fn_R001006_613_6_2(sec_r001006_6_1, sec_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1, pub_r001006_10_1, sec_r001006_6_2, sec_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2, pub_r001006_10_2);
  int helper_flow_7_1 = fn_R001006_613_7(sec_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1);
  int helper_flow_7_2 = fn_R001006_613_7(sec_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2);
  fn_R001006_613_7_2(sec_r001006_7_1, pub_r001006_8_1, pub_r001006_9_1, sec_r001006_7_2, pub_r001006_8_2, pub_r001006_9_2);
  int helper_flow_8_1 = fn_R001006_613_8(sec_r001006_8_1, sec_r001006_9_1);
  int helper_flow_8_2 = fn_R001006_613_8(sec_r001006_8_2, sec_r001006_9_2);
  fn_R001006_613_8_2(sec_r001006_8_1, sec_r001006_9_1, sec_r001006_8_2, sec_r001006_9_2);
  int stage_v_0_1 = ((helper_flow_0_1 + (pub_r001006_16_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_0_2 + (pub_r001006_16_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001006_2_1 * 2) + 37) & 63;
  int stage_v_1_2 = ((pub_r001006_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001006_14_1 + (pub_r001006_13_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001006_14_2 + (pub_r001006_13_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001006_13_1 + (pub_r001006_13_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001006_13_2 + (pub_r001006_13_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001006_4_1 * 2) + 13) & 63;
  int stage_v_4_2 = ((pub_r001006_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001006_15_1 * 2) + 40) & 63;
  int stage_v_5_2 = ((pub_r001006_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001006_13_1 * 2) + 24) & 63;
  int stage_v_6_2 = ((pub_r001006_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001006_7_1 + (pub_r001006_8_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001006_7_2 + (pub_r001006_8_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((stage_v_2_1 + (pub_r001006_11_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((stage_v_2_2 + (pub_r001006_11_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001006_2_1 + (pub_r001006_5_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001006_2_2 + (pub_r001006_5_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((helper_flow_7_1 + (pub_r001006_6_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_7_2 + (pub_r001006_6_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001006_13_1 * 2) + 34) & 63;
  int stage_v_11_2 = ((pub_r001006_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001006_4_1 * 2) + 23) & 63;
  int stage_v_12_2 = ((pub_r001006_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((helper_flow_2_1 + (pub_r001006_14_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_2_2 + (pub_r001006_14_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001006_2_1 * 2) + 47) & 63;
  int stage_v_14_2 = ((pub_r001006_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001006_2_1 * 2) + 12) & 63;
  int stage_v_15_2 = ((pub_r001006_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001006_12_1 * 2) + 5) & 63;
  int stage_v_16_2 = ((pub_r001006_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001006_23_1 + (pub_r001006_12_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001006_23_2 + (pub_r001006_12_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001006_1_1 + (pub_r001006_9_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001006_1_2 + (pub_r001006_9_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001006_7_1 * 2) + 38) & 63;
  int stage_v_19_2 = ((pub_r001006_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001006_16_1 * 2) + 10) & 63;
  int stage_v_20_2 = ((pub_r001006_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001006_3_1 * 2) + 37) & 63;
  int stage_v_21_2 = ((pub_r001006_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_4_1 + (pub_r001006_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((helper_flow_4_2 + (pub_r001006_14_2 * 2)) + 71) & 127;
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
  int stage_v_23_1 = ((stage_v_22_1 + (pub_r001006_16_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_22_2 + (pub_r001006_16_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((sec_r001006_5_1 + (pub_r001006_13_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001006_5_2 + (pub_r001006_13_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_22_1 + (pub_r001006_12_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_22_2 + (pub_r001006_12_2 * 2)) + 80) & 127;
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
  int stage_v_26_1 = ((pub_r001006_2_1 * 2) + 27) & 63;
  int stage_v_26_2 = ((pub_r001006_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001006_13_1 * 2) + 31) & 63;
  int stage_v_27_2 = ((pub_r001006_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001006_11_1 * 2) + 44) & 63;
  int stage_v_28_2 = ((pub_r001006_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001006_3_1 + (pub_r001006_3_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001006_3_2 + (pub_r001006_3_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001006_1_1 + (pub_r001006_9_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001006_1_2 + (pub_r001006_9_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001006_4_1 * 2) + 30) & 63;
  int stage_v_31_2 = ((pub_r001006_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001006_0_1 * 2) + 17) & 63;
  int stage_v_32_2 = ((pub_r001006_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001006_13_1 + (pub_r001006_1_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001006_13_2 + (pub_r001006_1_2 * 2)) + 104) & 127;
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
  int stage_v_34_1 = ((pub_r001006_10_1 * 2) + 33) & 63;
  int stage_v_34_2 = ((pub_r001006_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((stage_v_7_1 + (pub_r001006_4_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_7_2 + (pub_r001006_4_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001006_3_1 * 2) + 44) & 63;
  int stage_v_36_2 = ((pub_r001006_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001006_1_1 * 2) + 26) & 63;
  int stage_v_37_2 = ((pub_r001006_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001006_9_1 + (pub_r001006_3_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001006_9_2 + (pub_r001006_3_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001006_2_1 * 2) + 45) & 63;
  int stage_v_39_2 = ((pub_r001006_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001006_11_1 * 2) + 48) & 63;
  int stage_v_40_2 = ((pub_r001006_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((helper_flow_1_1 + (pub_r001006_5_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((helper_flow_1_2 + (pub_r001006_5_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001006_1_1 * 2) + 42) & 63;
  int stage_v_42_2 = ((pub_r001006_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001006_7_1 * 2) + 44) & 63;
  int stage_v_43_2 = ((pub_r001006_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((stage_v_18_1 + (pub_r001006_16_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_18_2 + (pub_r001006_16_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001006_0_1 * 2) + 11) & 63;
  int stage_v_45_2 = ((pub_r001006_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_33_1 + (pub_r001006_10_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_33_2 + (pub_r001006_10_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001006_11_1 + (pub_r001006_0_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001006_11_2 + (pub_r001006_0_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001006_7_1 * 2) + 20) & 63;
  int stage_v_48_2 = ((pub_r001006_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001006_15_1 * 2) + 22) & 63;
  int stage_v_49_2 = ((pub_r001006_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001006_6_1 * 2) + 50) & 63;
  int stage_v_50_2 = ((pub_r001006_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((stage_v_44_1 + (pub_r001006_14_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_44_2 + (pub_r001006_14_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001006_5_1 * 2) + 16) & 63;
  int stage_v_52_2 = ((pub_r001006_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((sec_r001006_2_1 + (pub_r001006_11_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001006_2_2 + (pub_r001006_11_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_22_1 + (pub_r001006_4_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_22_2 + (pub_r001006_4_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001006_20_1 + (pub_r001006_9_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001006_20_2 + (pub_r001006_9_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001006_15_1 * 2) + 28) & 63;
  int stage_v_56_2 = ((pub_r001006_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001006_6_1 * 2) + 32) & 63;
  int stage_v_57_2 = ((pub_r001006_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_25_1 + (pub_r001006_0_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_25_2 + (pub_r001006_0_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001006_12_1 * 2) + 50) & 63;
  int stage_v_59_2 = ((pub_r001006_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001006_6_1 * 2) + 23) & 63;
  int stage_v_60_2 = ((pub_r001006_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((stage_v_38_1 + (pub_r001006_16_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_38_2 + (pub_r001006_16_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((sec_r001006_17_1 + (pub_r001006_5_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((sec_r001006_17_2 + (pub_r001006_5_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_38_1 + (pub_r001006_16_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_38_2 + (pub_r001006_16_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001006_3_1 * 2) + 11) & 63;
  int stage_v_64_2 = ((pub_r001006_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001006_14_1 * 2) + 11) & 63;
  int stage_v_65_2 = ((pub_r001006_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((helper_flow_0_1 + (pub_r001006_7_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((helper_flow_0_2 + (pub_r001006_7_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((sec_r001006_1_1 + (pub_r001006_0_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((sec_r001006_1_2 + (pub_r001006_0_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001006_8_1 * 2) + 47) & 63;
  int stage_v_68_2 = ((pub_r001006_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001006_4_1 * 2) + 25) & 63;
  int stage_v_69_2 = ((pub_r001006_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((sec_r001006_5_1 + (pub_r001006_3_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001006_5_2 + (pub_r001006_3_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_54_1 + (pub_r001006_5_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_54_2 + (pub_r001006_5_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001006_16_1 * 2) + 23) & 63;
  int stage_v_72_2 = ((pub_r001006_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((sec_r001006_16_1 + (pub_r001006_4_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((sec_r001006_16_2 + (pub_r001006_4_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((sec_r001006_23_1 + (pub_r001006_9_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((sec_r001006_23_2 + (pub_r001006_9_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((sec_r001006_5_1 + (pub_r001006_4_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001006_5_2 + (pub_r001006_4_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001006_3_1 * 2) + 5) & 63;
  int stage_v_76_2 = ((pub_r001006_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((helper_flow_3_1 + (pub_r001006_13_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_3_2 + (pub_r001006_13_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001006_9_1 * 2) + 40) & 63;
  int stage_v_78_2 = ((pub_r001006_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_24_1 + (pub_r001006_16_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_24_2 + (pub_r001006_16_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001006_13_1 + (pub_r001006_8_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001006_13_2 + (pub_r001006_8_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((sec_r001006_17_1 + (pub_r001006_15_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((sec_r001006_17_2 + (pub_r001006_15_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001006_8_1 * 2) + 48) & 63;
  int stage_v_82_2 = ((pub_r001006_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_35_1 + (pub_r001006_5_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_35_2 + (pub_r001006_5_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001006_8_1 * 2) + 9) & 63;
  int stage_v_84_2 = ((pub_r001006_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((sec_r001006_5_1 + (pub_r001006_15_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001006_5_2 + (pub_r001006_15_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001006_12_1 * 2) + 30) & 63;
  int stage_v_86_2 = ((pub_r001006_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001006_14_1 * 2) + 24) & 63;
  int stage_v_87_2 = ((pub_r001006_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((sec_r001006_17_1 + (pub_r001006_12_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((sec_r001006_17_2 + (pub_r001006_12_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001006_15_1 * 2) + 40) & 63;
  int stage_v_89_2 = ((pub_r001006_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001006_19_1 + (pub_r001006_3_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001006_19_2 + (pub_r001006_3_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_3_1 + (pub_r001006_14_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_3_2 + (pub_r001006_14_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_17_1 + (pub_r001006_5_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_17_2 + (pub_r001006_5_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001006_13_1 * 2) + 37) & 63;
  int stage_v_93_2 = ((pub_r001006_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_23_1 + (pub_r001006_11_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_23_2 + (pub_r001006_11_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((sec_r001006_18_1 + (pub_r001006_2_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((sec_r001006_18_2 + (pub_r001006_2_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001006_7_1 + (pub_r001006_7_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001006_7_2 + (pub_r001006_7_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001006_15_1 * 2) + 42) & 63;
  int stage_v_97_2 = ((pub_r001006_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001006_8_1 * 2) + 22) & 63;
  int stage_v_98_2 = ((pub_r001006_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_13_1 + (pub_r001006_3_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_13_2 + (pub_r001006_3_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001006_4_1 * 2) + 49) & 63;
  int stage_v_100_2 = ((pub_r001006_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((helper_flow_0_1 + (pub_r001006_12_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((helper_flow_0_2 + (pub_r001006_12_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((sec_r001006_18_1 + (pub_r001006_11_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((sec_r001006_18_2 + (pub_r001006_11_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_96_1 + (pub_r001006_9_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_96_2 + (pub_r001006_9_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001006_12_1 * 2) + 44) & 63;
  int stage_v_104_2 = ((pub_r001006_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_17_1 + (pub_r001006_15_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_17_2 + (pub_r001006_15_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001006_2_1 * 2) + 20) & 63;
  int stage_v_106_2 = ((pub_r001006_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_2_1 + (pub_r001006_7_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_2_2 + (pub_r001006_7_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001006_11_1 * 2) + 49) & 63;
  int stage_v_108_2 = ((pub_r001006_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_92_1 + (pub_r001006_1_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_92_2 + (pub_r001006_1_2 * 2)) + 332) & 127;
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
  int stage_v_110_1 = ((stage_v_22_1 + (pub_r001006_2_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_22_2 + (pub_r001006_2_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_77_1 + (pub_r001006_8_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_77_2 + (pub_r001006_8_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001006_7_1 + (pub_r001006_3_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001006_7_2 + (pub_r001006_3_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001006_12_1 * 2) + 48) & 63;
  int stage_v_113_2 = ((pub_r001006_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_55_1 + (pub_r001006_0_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_55_2 + (pub_r001006_0_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_95_1 + (pub_r001006_14_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_95_2 + (pub_r001006_14_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_63_1 + (pub_r001006_3_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_63_2 + (pub_r001006_3_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_73_1 + (pub_r001006_12_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_73_2 + (pub_r001006_12_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((pub_r001006_14_1 * 2) + 22) & 63;
  int stage_v_118_2 = ((pub_r001006_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_44_1 + (pub_r001006_14_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_44_2 + (pub_r001006_14_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_110_1 + (pub_r001006_2_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_110_2 + (pub_r001006_2_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_46_1 + (pub_r001006_14_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_46_2 + (pub_r001006_14_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_71_1 + (pub_r001006_3_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_71_2 + (pub_r001006_3_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((sec_r001006_13_1 + (pub_r001006_4_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((sec_r001006_13_2 + (pub_r001006_4_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_80_1 + (pub_r001006_5_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_80_2 + (pub_r001006_5_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001006_8_1 * 2) + 49) & 63;
  int stage_v_125_2 = ((pub_r001006_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_77_1 + (pub_r001006_16_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_77_2 + (pub_r001006_16_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001006_6_1 * 2) + 39) & 63;
  int stage_v_127_2 = ((pub_r001006_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((sec_r001006_2_1 + (pub_r001006_1_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((sec_r001006_2_2 + (pub_r001006_1_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((sec_r001006_1_1 + (pub_r001006_9_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001006_1_2 + (pub_r001006_9_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001006_5_1 * 2) + 25) & 63;
  int stage_v_130_2 = ((pub_r001006_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_62_1 + (pub_r001006_12_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_62_2 + (pub_r001006_12_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001006_20_1 + (pub_r001006_14_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001006_20_2 + (pub_r001006_14_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_120_1 + (pub_r001006_13_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_120_2 + (pub_r001006_13_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_0_1 + (pub_r001006_1_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_0_2 + (pub_r001006_1_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001006_1_1 * 2) + 32) & 63;
  int stage_v_135_2 = ((pub_r001006_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_74_1 + (pub_r001006_10_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_74_2 + (pub_r001006_10_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_122_1 + (pub_r001006_16_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_122_2 + (pub_r001006_16_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((sec_r001006_18_1 + (pub_r001006_3_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((sec_r001006_18_2 + (pub_r001006_3_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001006_2_1 * 2) + 8) & 63;
  int stage_v_139_2 = ((pub_r001006_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001006_13_1 * 2) + 13) & 63;
  int stage_v_140_2 = ((pub_r001006_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_81_1 + (pub_r001006_14_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_81_2 + (pub_r001006_14_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_33_1 + (pub_r001006_10_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_33_2 + (pub_r001006_10_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_81_1 + (pub_r001006_14_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_81_2 + (pub_r001006_14_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001006_5_1 * 2) + 11) & 63;
  int stage_v_144_2 = ((pub_r001006_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001006_9_1 * 2) + 28) & 63;
  int stage_v_145_2 = ((pub_r001006_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_116_1 + (pub_r001006_2_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_116_2 + (pub_r001006_2_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_90_1 + (pub_r001006_3_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_90_2 + (pub_r001006_3_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_71_1 + (pub_r001006_7_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_71_2 + (pub_r001006_7_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001006_16_1 * 2) + 37) & 63;
  int stage_v_149_2 = ((pub_r001006_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_147_1 + (pub_r001006_16_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_147_2 + (pub_r001006_16_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_73_1 + (pub_r001006_3_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_73_2 + (pub_r001006_3_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_103_1 + (pub_r001006_0_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_103_2 + (pub_r001006_0_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((helper_flow_1_1 + (pub_r001006_8_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((helper_flow_1_2 + (pub_r001006_8_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_103_1 + (pub_r001006_3_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_103_2 + (pub_r001006_3_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001006_6_1 * 2) + 6) & 63;
  int stage_v_155_2 = ((pub_r001006_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_150_1 + (pub_r001006_0_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_150_2 + (pub_r001006_0_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_117_1 + (pub_r001006_11_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_117_2 + (pub_r001006_11_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_46_1 + (pub_r001006_7_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_46_2 + (pub_r001006_7_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((sec_r001006_0_1 + (pub_r001006_13_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((sec_r001006_0_2 + (pub_r001006_13_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_38_1 + (pub_r001006_7_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_38_2 + (pub_r001006_7_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_9_1 + (pub_r001006_4_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_9_2 + (pub_r001006_4_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001006_9_1 * 2) + 40) & 63;
  int stage_v_162_2 = ((pub_r001006_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_47_1 + (pub_r001006_13_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_47_2 + (pub_r001006_13_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((sec_r001006_4_1 + (pub_r001006_10_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((sec_r001006_4_2 + (pub_r001006_10_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((sec_r001006_20_1 + (pub_r001006_2_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((sec_r001006_20_2 + (pub_r001006_2_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001006_12_1 * 2) + 10) & 63;
  int stage_v_166_2 = ((pub_r001006_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_67_1 + (pub_r001006_2_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_67_2 + (pub_r001006_2_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((pub_r001006_15_1 * 2) + 32) & 63;
  int stage_v_168_2 = ((pub_r001006_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001006_7_1 * 2) + 30) & 63;
  int stage_v_169_2 = ((pub_r001006_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_143_1 + (pub_r001006_9_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_143_2 + (pub_r001006_9_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((helper_flow_1_1 + (pub_r001006_3_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((helper_flow_1_2 + (pub_r001006_3_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_62_1 + (pub_r001006_4_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_62_2 + (pub_r001006_4_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001006_10_1 * 2) + 29) & 63;
  int stage_v_173_2 = ((pub_r001006_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_71_1 + (pub_r001006_9_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_71_2 + (pub_r001006_9_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_123_1 + (pub_r001006_13_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_123_2 + (pub_r001006_13_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001006_14_1 * 2) + 6) & 63;
  int stage_v_176_2 = ((pub_r001006_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001006_10_1 * 2) + 24) & 63;
  int stage_v_177_2 = ((pub_r001006_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_167_1 + (pub_r001006_15_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_167_2 + (pub_r001006_15_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_22_1 + (pub_r001006_8_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_22_2 + (pub_r001006_8_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001006_5_1 * 2) + 30) & 63;
  int stage_v_180_2 = ((pub_r001006_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((sec_r001006_11_1 + (pub_r001006_8_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((sec_r001006_11_2 + (pub_r001006_8_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_25_1 + (pub_r001006_7_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_25_2 + (pub_r001006_7_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((sec_r001006_1_1 + (pub_r001006_0_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((sec_r001006_1_2 + (pub_r001006_0_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_85_1 + (pub_r001006_4_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_85_2 + (pub_r001006_4_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_53_1 + (pub_r001006_9_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_53_2 + (pub_r001006_9_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_35_1 + (pub_r001006_5_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_35_2 + (pub_r001006_5_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_150_1 + (pub_r001006_9_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_150_2 + (pub_r001006_9_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((sec_r001006_13_1 + (pub_r001006_1_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((sec_r001006_13_2 + (pub_r001006_1_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001006_2_1 * 2) + 23) & 63;
  int stage_v_189_2 = ((pub_r001006_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001006_16_1 * 2) + 39) & 63;
  int stage_v_190_2 = ((pub_r001006_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_137_1 + (pub_r001006_12_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_137_2 + (pub_r001006_12_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((sec_r001006_10_1 + (pub_r001006_2_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((sec_r001006_10_2 + (pub_r001006_2_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001006_11_1 * 2) + 39) & 63;
  int stage_v_193_2 = ((pub_r001006_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001006_9_1 * 2) + 14) & 63;
  int stage_v_194_2 = ((pub_r001006_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((sec_r001006_11_1 + (pub_r001006_13_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((sec_r001006_11_2 + (pub_r001006_13_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001006_2_1 * 2) + 33) & 63;
  int stage_v_196_2 = ((pub_r001006_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_18_1 + (pub_r001006_6_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_18_2 + (pub_r001006_6_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((sec_r001006_7_1 + (pub_r001006_7_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001006_7_2 + (pub_r001006_7_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((pub_r001006_16_1 * 2) + 32) & 63;
  int stage_v_199_2 = ((pub_r001006_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_105_1 + (pub_r001006_15_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_105_2 + (pub_r001006_15_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001006_2_1 * 2) + 12) & 63;
  int stage_v_201_2 = ((pub_r001006_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001006_8_1 * 2) + 9) & 63;
  int stage_v_202_2 = ((pub_r001006_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((helper_flow_8_1 + (pub_r001006_1_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((helper_flow_8_2 + (pub_r001006_1_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_195_1 + (pub_r001006_4_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_195_2 + (pub_r001006_4_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_198_1 + (pub_r001006_2_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_198_2 + (pub_r001006_2_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_54_1 + (pub_r001006_9_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_54_2 + (pub_r001006_9_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001006_16_1 * 2) + 31) & 63;
  int stage_v_207_2 = ((pub_r001006_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_158_1 + (pub_r001006_9_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_158_2 + (pub_r001006_9_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001006_17_1 != sec_r001006_17_2);
  __CPROVER_assume(pub_r001006_6_1 == pub_r001006_6_2);
  __CPROVER_assume(sec_r001006_10_1 != sec_r001006_10_2);
  __CPROVER_assume(pub_r001006_14_1 == pub_r001006_14_2);
  __CPROVER_assume(sec_r001006_1_1 != sec_r001006_1_2);
  __CPROVER_assume(sec_r001006_18_1 != sec_r001006_18_2);
  __CPROVER_assume(sec_r001006_23_1 != sec_r001006_23_2);
  __CPROVER_assume(pub_r001006_10_1 == pub_r001006_10_2);
  __CPROVER_assume(sec_r001006_7_1 != sec_r001006_7_2);
  __CPROVER_assume(sec_r001006_21_1 != sec_r001006_21_2);
  __CPROVER_assume(sec_r001006_16_1 != sec_r001006_16_2);
  __CPROVER_assume(sec_r001006_5_1 != sec_r001006_5_2);
  __CPROVER_assume(pub_r001006_4_1 == pub_r001006_4_2);
  __CPROVER_assume(pub_r001006_7_1 == pub_r001006_7_2);
  __CPROVER_assume(sec_r001006_11_1 != sec_r001006_11_2);
  __CPROVER_assume(sec_r001006_8_1 != sec_r001006_8_2);
  __CPROVER_assume(pub_r001006_3_1 == pub_r001006_3_2);
  __CPROVER_assume(sec_r001006_22_1 != sec_r001006_22_2);
  __CPROVER_assume(sec_r001006_15_1 != sec_r001006_15_2);
  __CPROVER_assume(pub_r001006_0_1 == pub_r001006_0_2);
  __CPROVER_assume(pub_r001006_11_1 == pub_r001006_11_2);
  __CPROVER_assume(pub_r001006_9_1 == pub_r001006_9_2);
  __CPROVER_assume(sec_r001006_13_1 != sec_r001006_13_2);
  __CPROVER_assume(pub_r001006_13_1 == pub_r001006_13_2);
  __CPROVER_assume(pub_r001006_2_1 == pub_r001006_2_2);
  __CPROVER_assume(sec_r001006_14_1 != sec_r001006_14_2);
  __CPROVER_assume(sec_r001006_20_1 != sec_r001006_20_2);
  __CPROVER_assume(pub_r001006_15_1 == pub_r001006_15_2);
  __CPROVER_assume(pub_r001006_16_1 == pub_r001006_16_2);
  __CPROVER_assume(pub_r001006_5_1 == pub_r001006_5_2);
  __CPROVER_assume(sec_r001006_4_1 != sec_r001006_4_2);
  __CPROVER_assume(pub_r001006_8_1 == pub_r001006_8_2);
  __CPROVER_assume(sec_r001006_6_1 != sec_r001006_6_2);
  __CPROVER_assume(sec_r001006_12_1 != sec_r001006_12_2);
  __CPROVER_assume(pub_r001006_12_1 == pub_r001006_12_2);
  __CPROVER_assume(pub_r001006_1_1 == pub_r001006_1_2);
  __CPROVER_assume(sec_r001006_9_1 != sec_r001006_9_2);
  __CPROVER_assume(sec_r001006_19_1 != sec_r001006_19_2);
  __CPROVER_assume(sec_r001006_2_1 != sec_r001006_2_2);
  __CPROVER_assume(sec_r001006_3_1 != sec_r001006_3_2);
  __CPROVER_assume(sec_r001006_0_1 != sec_r001006_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
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
}


