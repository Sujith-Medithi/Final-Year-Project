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
struct EventLog_R000497_9713_0
{
  int severity;
  int facility;
  int signature;
  int timestamp;
  unsigned char code;
  int seq;
  int buffer[3];
};
struct Vector3D_R000497_9713_1
{
  unsigned char pitch;
  short coord_y;
  short coord_z;
  int heading;
  int norm_sq;
  int buffer[3];
};
union PacketPayload_R000497_9713_0
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
void fn_R000497_9713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int bound_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_72_1) & 63;
  aux_2 = (aux_2 + bound_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_29_1)
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

  switch (parity_29_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_27_1 > 36)
  {
    acc_1 = ((acc_1 + (quantum_27_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_27_2 > 36)
  {
    acc_2 = ((acc_2 + (quantum_27_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_72_1 == bound_72_2);
  assert(parity_29_1 == parity_29_2);
  assert(quantum_27_1 == quantum_27_2);
}

int fn_R000497_9713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_72) & 63;
  acc ^= aux;
  int parity_29 = (aux + st.buffer[1]) & 3;
  switch (parity_29)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_27 > 36)
  {
    acc = ((acc + (quantum_27 * 2)) + 5) & 127;
    aux ^= quantum_27 & 15;
  }
  else
  {
    acc = ((acc - quantum_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000497_9713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int delta_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_83_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_83_1 * 2)) + 5) & 127;
    aux_1 ^= delta_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_83_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_83_2 * 2)) + 5) & 127;
    aux_2 ^= delta_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_83_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_45_1 = local_arr_1[aux_1 % 3];
  int delta_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_83_1 == delta_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_45_1 == delta_45_2);
}

int fn_R000497_9713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int delta_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_83 > 26)
  {
    acc = ((acc + (delta_83 * 2)) + 5) & 127;
    aux ^= delta_83 & 15;
  }
  else
  {
    acc = ((acc - delta_83) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_45 = local_arr[aux % 3];
  acc = (acc + (delta_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int pivot_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_56_1)
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

  switch (pivot_56_2)
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

  int delta_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_76_1) & 63;
  aux_2 = (aux_2 + delta_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_67_1 = local_arr_1[aux_1 % 3];
  int anchor_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_56_1 == pivot_56_2);
  assert(delta_76_1 == delta_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_67_1 == anchor_67_2);
}

int fn_R000497_9713_2(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int pivot_56 = (aux + st.buffer[1]) & 3;
  switch (pivot_56)
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

  int delta_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_76) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_67 = local_arr[aux % 3];
  acc = (acc + (anchor_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_88_1)
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

  switch (anchor_88_2)
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

  int quotient_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_18_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_18_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_18_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_18_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_54_1 = local_arr_1[aux_1 % 3];
  int parity_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_88_1 == anchor_88_2);
  assert(quotient_18_1 == quotient_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_54_1 == parity_54_2);
}

int fn_R000497_9713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_88 = (aux + st.buffer[1]) & 3;
  switch (anchor_88)
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

  int quotient_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_18 > 45)
  {
    acc = ((acc + (quotient_18 * 2)) + 5) & 127;
    aux ^= quotient_18 & 15;
  }
  else
  {
    acc = ((acc - quotient_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_54 = local_arr[aux % 3];
  acc = (acc + (parity_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_58_1) & 63;
  aux_2 = (aux_2 + tracker_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_38_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_38_1 * 2)) + 5) & 127;
    aux_1 ^= sample_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_38_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_38_2 * 2)) + 5) & 127;
    aux_2 ^= sample_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_58_1 == tracker_58_2);
  assert(sample_38_1 == sample_38_2);
}

int fn_R000497_9713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_58) & 63;
  acc ^= aux;
  int sample_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_38 > 33)
  {
    acc = ((acc + (sample_38 * 2)) + 5) & 127;
    aux ^= sample_38 & 15;
  }
  else
  {
    acc = ((acc - sample_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000497_9713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
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
  int phase_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_38_1) & 63;
  aux_2 = (aux_2 + phase_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_92_1 = local_arr_1[aux_1 % 3];
  int factor_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_38_1 == phase_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_92_1 == factor_92_2);
}

int fn_R000497_9713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_92 = local_arr[aux % 3];
  acc = (acc + (factor_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_52_1) & 63;
  aux_2 = (aux_2 + bound_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_77_1 > 46)
  {
    acc_1 = ((acc_1 + (checksum_77_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_77_2 > 46)
  {
    acc_2 = ((acc_2 + (checksum_77_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_52_1 == bound_52_2);
  assert(checksum_77_1 == checksum_77_2);
}

int fn_R000497_9713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_52) & 63;
  acc ^= aux;
  int checksum_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_77 > 46)
  {
    acc = ((acc + (checksum_77 * 2)) + 5) & 127;
    aux ^= checksum_77 & 15;
  }
  else
  {
    acc = ((acc - checksum_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000497_9713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_73_1)
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

  switch (phase_73_2)
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

  int phase_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_87_1 > 24)
  {
    acc_1 = ((acc_1 + (phase_87_1 * 2)) + 5) & 127;
    aux_1 ^= phase_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_87_2 > 24)
  {
    acc_2 = ((acc_2 + (phase_87_2 * 2)) + 5) & 127;
    aux_2 ^= phase_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_31_1) & 63;
  aux_2 = (aux_2 + metric_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_73_1 == phase_73_2);
  assert(phase_87_1 == phase_87_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R000497_9713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_73 = (aux + st.buffer[1]) & 3;
  switch (phase_73)
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

  int phase_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_87 > 24)
  {
    acc = ((acc + (phase_87 * 2)) + 5) & 127;
    aux ^= phase_87 & 15;
  }
  else
  {
    acc = ((acc - phase_87) + 11) & 127;
    aux += 3;
  }
  int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000497_9713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_27_1 = local_arr_1[aux_1 % 3];
  int sample_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_25_1 == index_reg_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_27_1 == sample_27_2);
}

int fn_R000497_9713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
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
  int local_arr[3] = {4, 9, 15};
  int sample_27 = local_arr[aux % 3];
  acc = (acc + (sample_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_38_1) & 63;
  aux_2 = (aux_2 + vector_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_71_1 = local_arr_1[aux_1 % 3];
  int scale_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_71_2 * 2)) & 127;
  int index_reg_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_45_1)
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

  switch (index_reg_45_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_38_1 == vector_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_71_1 == scale_71_2);
  assert(index_reg_45_1 == index_reg_45_2);
}

int fn_R000497_9713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_71 = local_arr[aux % 3];
  acc = (acc + (scale_71 * 2)) & 127;
  int index_reg_45 = (aux + st.buffer[1]) & 3;
  switch (index_reg_45)
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

void fn_R000497_9713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int window_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_44_1) & 63;
  aux_2 = (aux_2 + window_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_98_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_98_1 * 2)) + 5) & 127;
    aux_1 ^= residue_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_98_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_98_2 * 2)) + 5) & 127;
    aux_2 ^= residue_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_89_1)
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

  switch (index_reg_89_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_44_1 == window_44_2);
  assert(residue_98_1 == residue_98_2);
  assert(index_reg_89_1 == index_reg_89_2);
}

int fn_R000497_9713_10(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int window_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_44) & 63;
  acc ^= aux;
  int residue_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_98 > 40)
  {
    acc = ((acc + (residue_98 * 2)) + 5) & 127;
    aux ^= residue_98 & 15;
  }
  else
  {
    acc = ((acc - residue_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_89 = (aux + st.buffer[1]) & 3;
  switch (index_reg_89)
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

void fn_R000497_9713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_93_1 = local_arr_1[aux_1 % 3];
  int tally_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_93_2 * 2)) & 127;
  int accumulator_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_70_1 > 33)
  {
    acc_1 = ((acc_1 + (accumulator_70_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_70_2 > 33)
  {
    acc_2 = ((acc_2 + (accumulator_70_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_70_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_93_1 == tally_93_2);
  assert(accumulator_70_1 == accumulator_70_2);
}

int fn_R000497_9713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int tally_93 = local_arr[aux % 3];
  acc = (acc + (tally_93 * 2)) & 127;
  int accumulator_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_70 > 33)
  {
    acc = ((acc + (accumulator_70 * 2)) + 5) & 127;
    aux ^= accumulator_70 & 15;
  }
  else
  {
    acc = ((acc - accumulator_70) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_77_1) & 63;
  aux_2 = (aux_2 + metric_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_72_1 = local_arr_1[aux_1 % 3];
  int quotient_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_72_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_37_1 > 28)
  {
    acc_1 = ((acc_1 + (phase_37_1 * 2)) + 5) & 127;
    aux_1 ^= phase_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_37_2 > 28)
  {
    acc_2 = ((acc_2 + (phase_37_2 * 2)) + 5) & 127;
    aux_2 ^= phase_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_77_1 == metric_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_72_1 == quotient_72_2);
  assert(phase_37_1 == phase_37_2);
}

int fn_R000497_9713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_77) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_72 = local_arr[aux % 3];
  acc = (acc + (quotient_72 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_37 > 28)
  {
    acc = ((acc + (phase_37 * 2)) + 5) & 127;
    aux ^= phase_37 & 15;
  }
  else
  {
    acc = ((acc - phase_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000497_9713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st_1 = {0};
  struct Vector3D_R000497_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int phase_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_62_1 > 50)
  {
    acc_1 = ((acc_1 + (phase_62_1 * 2)) + 5) & 127;
    aux_1 ^= phase_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_62_2 > 50)
  {
    acc_2 = ((acc_2 + (phase_62_2 * 2)) + 5) & 127;
    aux_2 ^= phase_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_62_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_62_1 == phase_62_2);
}

int fn_R000497_9713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000497_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int phase_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_62 > 50)
  {
    acc = ((acc + (phase_62 * 2)) + 5) & 127;
    aux ^= phase_62 & 15;
  }
  else
  {
    acc = ((acc - phase_62) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quantum_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_13_1)
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

  switch (quantum_13_2)
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
  int offset_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_35_1 > 10)
  {
    acc_1 = ((acc_1 + (offset_35_1 * 2)) + 5) & 127;
    aux_1 ^= offset_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_35_2 > 10)
  {
    acc_2 = ((acc_2 + (offset_35_2 * 2)) + 5) & 127;
    aux_2 ^= offset_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_13_1 == quantum_13_2);
  assert(offset_35_1 == offset_35_2);
}

int fn_R000497_9713_14(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quantum_13 = (aux + st.buffer[1]) & 3;
  switch (quantum_13)
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
  int offset_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_35 > 10)
  {
    acc = ((acc + (offset_35 * 2)) + 5) & 127;
    aux ^= offset_35 & 15;
  }
  else
  {
    acc = ((acc - offset_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000497_9713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_30_1 = local_arr_1[aux_1 % 3];
  int cursor_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_30_2 * 2)) & 127;
  int index_reg_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_60_1 > 19)
  {
    acc_1 = ((acc_1 + (index_reg_60_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_60_2 > 19)
  {
    acc_2 = ((acc_2 + (index_reg_60_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_30_1 == cursor_30_2);
  assert(index_reg_60_1 == index_reg_60_2);
}

int fn_R000497_9713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int cursor_30 = local_arr[aux % 3];
  acc = (acc + (cursor_30 * 2)) & 127;
  int index_reg_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_60 > 19)
  {
    acc = ((acc + (index_reg_60 * 2)) + 5) & 127;
    aux ^= index_reg_60 & 15;
  }
  else
  {
    acc = ((acc - index_reg_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int margin_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_73_1 > 16)
  {
    acc_1 = ((acc_1 + (margin_73_1 * 2)) + 5) & 127;
    aux_1 ^= margin_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_73_2 > 16)
  {
    acc_2 = ((acc_2 + (margin_73_2 * 2)) + 5) & 127;
    aux_2 ^= margin_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_94_1)
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

  switch (segment_94_2)
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
  int metric_52_1 = local_arr_1[aux_1 % 3];
  int metric_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_52_2 * 2)) & 127;
  int threshold_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_70_1) & 63;
  aux_2 = (aux_2 + threshold_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_73_1 == margin_73_2);
  assert(segment_94_1 == segment_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_52_1 == metric_52_2);
  assert(threshold_70_1 == threshold_70_2);
}

int fn_R000497_9713_16(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int margin_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_73 > 16)
  {
    acc = ((acc + (margin_73 * 2)) + 5) & 127;
    aux ^= margin_73 & 15;
  }
  else
  {
    acc = ((acc - margin_73) + 11) & 127;
    aux += 3;
  }
  int segment_94 = (aux + st.buffer[1]) & 3;
  switch (segment_94)
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
  int metric_52 = local_arr[aux % 3];
  acc = (acc + (metric_52 * 2)) & 127;
  int threshold_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000497_9713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_92_1 = local_arr_1[aux_1 % 3];
  int coefficient_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
}

int fn_R000497_9713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_92 = local_arr[aux % 3];
  acc = (acc + (coefficient_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000497_9713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st_1 = {0};
  struct EventLog_R000497_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int damping_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_95_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_95_1 * 2)) + 5) & 127;
    aux_1 ^= damping_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_95_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_95_2 * 2)) + 5) & 127;
    aux_2 ^= damping_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_44_1)
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

  switch (checksum_44_2)
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

  int parity_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_91_1) & 63;
  aux_2 = (aux_2 + parity_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_95_1 == damping_95_2);
  assert(checksum_44_1 == checksum_44_2);
  assert(parity_91_1 == parity_91_2);
}

int fn_R000497_9713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000497_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int damping_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_95 > 31)
  {
    acc = ((acc + (damping_95 * 2)) + 5) & 127;
    aux ^= damping_95 & 15;
  }
  else
  {
    acc = ((acc - damping_95) + 11) & 127;
    aux += 3;
  }
  int checksum_44 = (aux + st.buffer[1]) & 3;
  switch (checksum_44)
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

  int parity_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000497_0_1;
  int sec_r000497_0_2;
  int sec_r000497_1_1;
  int sec_r000497_1_2;
  int sec_r000497_2_1;
  int sec_r000497_2_2;
  int sec_r000497_3_1;
  int sec_r000497_3_2;
  int sec_r000497_4_1;
  int sec_r000497_4_2;
  int sec_r000497_5_1;
  int sec_r000497_5_2;
  int sec_r000497_6_1;
  int sec_r000497_6_2;
  int sec_r000497_7_1;
  int sec_r000497_7_2;
  int sec_r000497_8_1;
  int sec_r000497_8_2;
  int sec_r000497_9_1;
  int sec_r000497_9_2;
  int sec_r000497_10_1;
  int sec_r000497_10_2;
  int sec_r000497_11_1;
  int sec_r000497_11_2;
  int sec_r000497_12_1;
  int sec_r000497_12_2;
  int sec_r000497_13_1;
  int sec_r000497_13_2;
  int sec_r000497_14_1;
  int sec_r000497_14_2;
  int sec_r000497_15_1;
  int sec_r000497_15_2;
  int sec_r000497_16_1;
  int sec_r000497_16_2;
  int sec_r000497_17_1;
  int sec_r000497_17_2;
  int pub_r000497_0_1;
  int pub_r000497_0_2;
  int pub_r000497_1_1;
  int pub_r000497_1_2;
  int pub_r000497_2_1;
  int pub_r000497_2_2;
  int pub_r000497_3_1;
  int pub_r000497_3_2;
  int pub_r000497_4_1;
  int pub_r000497_4_2;
  int pub_r000497_5_1;
  int pub_r000497_5_2;
  int pub_r000497_6_1;
  int pub_r000497_6_2;
  int pub_r000497_7_1;
  int pub_r000497_7_2;
  int pub_r000497_8_1;
  int pub_r000497_8_2;
  int pub_r000497_9_1;
  int pub_r000497_9_2;
  int pub_r000497_10_1;
  int pub_r000497_10_2;
  int pub_r000497_11_1;
  int pub_r000497_11_2;
  int pub_r000497_12_1;
  int pub_r000497_12_2;
  int pub_r000497_13_1;
  int pub_r000497_13_2;
  int pub_r000497_14_1;
  int pub_r000497_14_2;
  int pub_r000497_15_1;
  int pub_r000497_15_2;
  int pub_r000497_16_1;
  int pub_r000497_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000497_0_1 >= (-100)) && (pub_r000497_0_1 <= 100));
  __CPROVER_assume((pub_r000497_0_2 >= (-100)) && (pub_r000497_0_2 <= 100));
  __CPROVER_assume((pub_r000497_1_1 >= (-100)) && (pub_r000497_1_1 <= 100));
  __CPROVER_assume((pub_r000497_1_2 >= (-100)) && (pub_r000497_1_2 <= 100));
  __CPROVER_assume((pub_r000497_2_1 >= (-100)) && (pub_r000497_2_1 <= 100));
  __CPROVER_assume((pub_r000497_2_2 >= (-100)) && (pub_r000497_2_2 <= 100));
  __CPROVER_assume((pub_r000497_3_1 >= (-100)) && (pub_r000497_3_1 <= 100));
  __CPROVER_assume((pub_r000497_3_2 >= (-100)) && (pub_r000497_3_2 <= 100));
  __CPROVER_assume((pub_r000497_4_1 >= (-100)) && (pub_r000497_4_1 <= 100));
  __CPROVER_assume((pub_r000497_4_2 >= (-100)) && (pub_r000497_4_2 <= 100));
  __CPROVER_assume((pub_r000497_5_1 >= (-100)) && (pub_r000497_5_1 <= 100));
  __CPROVER_assume((pub_r000497_5_2 >= (-100)) && (pub_r000497_5_2 <= 100));
  __CPROVER_assume((pub_r000497_6_1 >= (-100)) && (pub_r000497_6_1 <= 100));
  __CPROVER_assume((pub_r000497_6_2 >= (-100)) && (pub_r000497_6_2 <= 100));
  __CPROVER_assume((pub_r000497_7_1 >= (-100)) && (pub_r000497_7_1 <= 100));
  __CPROVER_assume((pub_r000497_7_2 >= (-100)) && (pub_r000497_7_2 <= 100));
  __CPROVER_assume((pub_r000497_8_1 >= (-100)) && (pub_r000497_8_1 <= 100));
  __CPROVER_assume((pub_r000497_8_2 >= (-100)) && (pub_r000497_8_2 <= 100));
  __CPROVER_assume((pub_r000497_9_1 >= (-100)) && (pub_r000497_9_1 <= 100));
  __CPROVER_assume((pub_r000497_9_2 >= (-100)) && (pub_r000497_9_2 <= 100));
  __CPROVER_assume((pub_r000497_10_1 >= (-100)) && (pub_r000497_10_1 <= 100));
  __CPROVER_assume((pub_r000497_10_2 >= (-100)) && (pub_r000497_10_2 <= 100));
  __CPROVER_assume((pub_r000497_11_1 >= (-100)) && (pub_r000497_11_1 <= 100));
  __CPROVER_assume((pub_r000497_11_2 >= (-100)) && (pub_r000497_11_2 <= 100));
  __CPROVER_assume((pub_r000497_12_1 >= (-100)) && (pub_r000497_12_1 <= 100));
  __CPROVER_assume((pub_r000497_12_2 >= (-100)) && (pub_r000497_12_2 <= 100));
  __CPROVER_assume((pub_r000497_13_1 >= (-100)) && (pub_r000497_13_1 <= 100));
  __CPROVER_assume((pub_r000497_13_2 >= (-100)) && (pub_r000497_13_2 <= 100));
  __CPROVER_assume((pub_r000497_14_1 >= (-100)) && (pub_r000497_14_1 <= 100));
  __CPROVER_assume((pub_r000497_14_2 >= (-100)) && (pub_r000497_14_2 <= 100));
  __CPROVER_assume((pub_r000497_15_1 >= (-100)) && (pub_r000497_15_1 <= 100));
  __CPROVER_assume((pub_r000497_15_2 >= (-100)) && (pub_r000497_15_2 <= 100));
  __CPROVER_assume((pub_r000497_16_1 >= (-100)) && (pub_r000497_16_1 <= 100));
  __CPROVER_assume((pub_r000497_16_2 >= (-100)) && (pub_r000497_16_2 <= 100));
  __CPROVER_assume((sec_r000497_0_1 >= 0) && (sec_r000497_0_1 <= 255));
  __CPROVER_assume((sec_r000497_0_2 >= 0) && (sec_r000497_0_2 <= 255));
  __CPROVER_assume((sec_r000497_1_1 >= 0) && (sec_r000497_1_1 <= 255));
  __CPROVER_assume((sec_r000497_1_2 >= 0) && (sec_r000497_1_2 <= 255));
  __CPROVER_assume((sec_r000497_2_1 >= 0) && (sec_r000497_2_1 <= 255));
  __CPROVER_assume((sec_r000497_2_2 >= 0) && (sec_r000497_2_2 <= 255));
  __CPROVER_assume((sec_r000497_3_1 >= 0) && (sec_r000497_3_1 <= 255));
  __CPROVER_assume((sec_r000497_3_2 >= 0) && (sec_r000497_3_2 <= 255));
  __CPROVER_assume((sec_r000497_4_1 >= 0) && (sec_r000497_4_1 <= 255));
  __CPROVER_assume((sec_r000497_4_2 >= 0) && (sec_r000497_4_2 <= 255));
  __CPROVER_assume((sec_r000497_5_1 >= 0) && (sec_r000497_5_1 <= 255));
  __CPROVER_assume((sec_r000497_5_2 >= 0) && (sec_r000497_5_2 <= 255));
  __CPROVER_assume((sec_r000497_6_1 >= 0) && (sec_r000497_6_1 <= 255));
  __CPROVER_assume((sec_r000497_6_2 >= 0) && (sec_r000497_6_2 <= 255));
  __CPROVER_assume((sec_r000497_7_1 >= 0) && (sec_r000497_7_1 <= 255));
  __CPROVER_assume((sec_r000497_7_2 >= 0) && (sec_r000497_7_2 <= 255));
  __CPROVER_assume((sec_r000497_8_1 >= 0) && (sec_r000497_8_1 <= 255));
  __CPROVER_assume((sec_r000497_8_2 >= 0) && (sec_r000497_8_2 <= 255));
  __CPROVER_assume((sec_r000497_9_1 >= 0) && (sec_r000497_9_1 <= 255));
  __CPROVER_assume((sec_r000497_9_2 >= 0) && (sec_r000497_9_2 <= 255));
  __CPROVER_assume((sec_r000497_10_1 >= 0) && (sec_r000497_10_1 <= 255));
  __CPROVER_assume((sec_r000497_10_2 >= 0) && (sec_r000497_10_2 <= 255));
  __CPROVER_assume((sec_r000497_11_1 >= 0) && (sec_r000497_11_1 <= 255));
  __CPROVER_assume((sec_r000497_11_2 >= 0) && (sec_r000497_11_2 <= 255));
  __CPROVER_assume((sec_r000497_12_1 >= 0) && (sec_r000497_12_1 <= 255));
  __CPROVER_assume((sec_r000497_12_2 >= 0) && (sec_r000497_12_2 <= 255));
  __CPROVER_assume((sec_r000497_13_1 >= 0) && (sec_r000497_13_1 <= 255));
  __CPROVER_assume((sec_r000497_13_2 >= 0) && (sec_r000497_13_2 <= 255));
  __CPROVER_assume((sec_r000497_14_1 >= 0) && (sec_r000497_14_1 <= 255));
  __CPROVER_assume((sec_r000497_14_2 >= 0) && (sec_r000497_14_2 <= 255));
  __CPROVER_assume((sec_r000497_15_1 >= 0) && (sec_r000497_15_1 <= 255));
  __CPROVER_assume((sec_r000497_15_2 >= 0) && (sec_r000497_15_2 <= 255));
  __CPROVER_assume((sec_r000497_16_1 >= 0) && (sec_r000497_16_1 <= 255));
  __CPROVER_assume((sec_r000497_16_2 >= 0) && (sec_r000497_16_2 <= 255));
  __CPROVER_assume((sec_r000497_17_1 >= 0) && (sec_r000497_17_1 <= 255));
  __CPROVER_assume((sec_r000497_17_2 >= 0) && (sec_r000497_17_2 <= 255));
  struct EventLog_R000497_9713_0 st_var_0_1 = {0};
  struct EventLog_R000497_9713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000497_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000497_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000497_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000497_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000497_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000497_0_2 + 7) & 15;
  struct Vector3D_R000497_9713_1 st_var_1_1 = {0};
  struct Vector3D_R000497_9713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000497_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000497_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000497_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000497_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000497_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000497_0_2 + 9) & 15;
  union PacketPayload_R000497_9713_0 u_var_1;
  union PacketPayload_R000497_9713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
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
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 39)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 39)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 48)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 48)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 12) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 46)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 46)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 26)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 26)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (st_var_1_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_1_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 46)
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
  if (stage_v_31_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 46)
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
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 37)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 37)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_34_1 = (st_var_0_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_0_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000497_13_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000497_5_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000497_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000497_5_1 + 7) & 127;
  }
  if ((sec_r000497_13_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000497_5_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000497_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000497_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000497_3_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000497_3_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000497_16_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000497_16_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000497_3_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((sec_r000497_3_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000497_14_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000497_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000497_14_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000497_14_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000497_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000497_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000497_7_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000497_10_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000497_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000497_10_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000497_7_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000497_10_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000497_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000497_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000497_7_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((sec_r000497_7_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000497_13_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000497_11_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000497_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000497_11_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000497_13_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000497_11_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000497_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000497_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000497_16_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000497_10_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000497_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000497_10_1 + 7) & 127;
  }
  if ((sec_r000497_16_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000497_10_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000497_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000497_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000497_7_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000497_7_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000497_4_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000497_4_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000497_0_1 & 1) != 0)
  {
    if ((sec_r000497_11_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((sec_r000497_0_2 & 1) != 0)
  {
    if ((sec_r000497_11_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000497_9_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000497_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000497_9_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000497_9_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000497_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000497_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000497_11_1 & 1) != 0)
  {
    if ((sec_r000497_13_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((sec_r000497_11_2 & 1) != 0)
  {
    if ((sec_r000497_13_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000497_7_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000497_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000497_7_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000497_7_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000497_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000497_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000497_10_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000497_12_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000497_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000497_12_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000497_10_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000497_12_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000497_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000497_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000497_1_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000497_1_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000497_7_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000497_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000497_7_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000497_7_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000497_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000497_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000497_9_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000497_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000497_9_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000497_9_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000497_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000497_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000497_11_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000497_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000497_11_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000497_11_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000497_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000497_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000497_0_1 & 1) != 0)
  {
    if ((sec_r000497_3_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((sec_r000497_0_2 & 1) != 0)
  {
    if ((sec_r000497_3_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000497_2_1 & 1) != 0)
  {
    if ((sec_r000497_9_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000497_14_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000497_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000497_14_1 + 7) & 127;
  }
  if ((sec_r000497_2_2 & 1) != 0)
  {
    if ((sec_r000497_9_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000497_14_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000497_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000497_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000497_3_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000497_3_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000497_13_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000497_13_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000497_5_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000497_7_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000497_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000497_7_1 + 7) & 127;
  }
  if ((sec_r000497_5_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000497_7_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000497_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000497_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000497_12_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000497_16_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000497_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000497_16_1 + 7) & 127;
  }
  if ((sec_r000497_12_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000497_16_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000497_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000497_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000497_14_1 & 1) != 0)
  {
    if ((sec_r000497_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((sec_r000497_14_2 & 1) != 0)
  {
    if ((sec_r000497_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000497_10_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000497_10_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000497_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000497_10_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000497_10_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000497_10_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000497_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000497_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000497_2_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000497_4_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000497_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000497_4_1 + 7) & 127;
  }
  if ((sec_r000497_2_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000497_4_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000497_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000497_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000497_14_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000497_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000497_14_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000497_14_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000497_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000497_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000497_9_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000497_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000497_9_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000497_9_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000497_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000497_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000497_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000497_5_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000497_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000497_5_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000497_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000497_5_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000497_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000497_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000497_9_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000497_9_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000497_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000497_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000497_11_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000497_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000497_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000497_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000497_4_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000497_5_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000497_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000497_5_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000497_4_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000497_5_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000497_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000497_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000497_12_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000497_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000497_12_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000497_12_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000497_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000497_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000497_14_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((sec_r000497_14_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000497_1_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000497_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000497_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000497_1_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000497_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000497_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000497_2_1 & 1) != 0)
  {
    if ((sec_r000497_16_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((sec_r000497_2_2 & 1) != 0)
  {
    if ((sec_r000497_16_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000497_15_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000497_1_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000497_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000497_1_1 + 7) & 127;
  }
  if ((sec_r000497_15_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000497_1_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000497_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000497_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000497_12_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000497_4_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000497_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000497_4_1 + 7) & 127;
  }
  if ((sec_r000497_12_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000497_4_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000497_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000497_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000497_4_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000497_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000497_4_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000497_4_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000497_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000497_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000497_8_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000497_3_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000497_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000497_3_1 + 7) & 127;
  }
  if ((sec_r000497_8_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000497_3_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000497_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000497_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000497_13_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000497_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000497_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000497_9_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000497_13_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000497_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000497_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000497_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000497_3_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000497_3_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000497_12_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000497_12_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000497_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000497_12_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000497_12_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000497_12_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000497_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000497_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000497_12_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000497_3_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000497_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000497_3_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000497_12_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000497_3_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000497_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000497_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000497_7_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000497_1_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000497_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000497_1_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000497_7_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000497_1_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000497_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000497_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000497_10_1 & 1) != 0)
  {
    if ((sec_r000497_7_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000497_3_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000497_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000497_3_1 + 7) & 127;
  }
  if ((sec_r000497_10_2 & 1) != 0)
  {
    if ((sec_r000497_7_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000497_3_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000497_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000497_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000497_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000497_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000497_12_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000497_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000497_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000497_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000497_11_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((sec_r000497_11_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000497_12_1 & 1) != 0)
  {
    if ((sec_r000497_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((sec_r000497_12_2 & 1) != 0)
  {
    if ((sec_r000497_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000497_9_1 & 1) != 0)
  {
    if ((sec_r000497_12_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000497_11_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000497_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000497_11_1 + 7) & 127;
  }
  if ((sec_r000497_9_2 & 1) != 0)
  {
    if ((sec_r000497_12_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000497_11_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000497_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000497_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000497_4_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000497_5_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000497_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000497_5_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000497_4_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000497_5_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000497_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000497_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000497_9_1 & 1) != 0)
  {
    if ((sec_r000497_8_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000497_7_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000497_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000497_7_1 + 7) & 127;
  }
  if ((sec_r000497_9_2 & 1) != 0)
  {
    if ((sec_r000497_8_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000497_7_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000497_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000497_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000497_16_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000497_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000497_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000497_4_1 + 7) & 127;
  }
  if ((sec_r000497_16_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000497_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000497_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000497_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000497_0_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000497_15_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000497_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000497_15_1 + 7) & 127;
  }
  if ((sec_r000497_0_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000497_15_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000497_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000497_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000497_11_1 & 1) != 0)
  {
    if ((sec_r000497_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000497_2_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000497_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000497_2_1 + 7) & 127;
  }
  if ((sec_r000497_11_2 & 1) != 0)
  {
    if ((sec_r000497_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000497_2_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000497_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000497_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000497_11_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000497_11_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000497_16_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000497_11_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000497_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000497_11_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000497_16_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000497_11_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000497_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000497_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000497_7_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000497_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000497_7_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000497_7_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000497_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000497_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000497_17_1 & 1) != 0)
  {
    if ((sec_r000497_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000497_14_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000497_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000497_14_1 + 7) & 127;
  }
  if ((sec_r000497_17_2 & 1) != 0)
  {
    if ((sec_r000497_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000497_14_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000497_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000497_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000497_17_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000497_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000497_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000497_10_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000497_17_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000497_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000497_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000497_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000497_12_1 & 1) != 0)
  {
    if ((sec_r000497_15_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000497_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000497_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000497_8_1 + 7) & 127;
  }
  if ((sec_r000497_12_2 & 1) != 0)
  {
    if ((sec_r000497_15_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000497_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000497_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000497_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000497_9_1 & 1) != 0)
  {
    if ((sec_r000497_2_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000497_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000497_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000497_6_1 + 7) & 127;
  }
  if ((sec_r000497_9_2 & 1) != 0)
  {
    if ((sec_r000497_2_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000497_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000497_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000497_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000497_0_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000497_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000497_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000497_2_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000497_0_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000497_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000497_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000497_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000497_16_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000497_9_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000497_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000497_9_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000497_16_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000497_9_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000497_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000497_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000497_10_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000497_1_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000497_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000497_1_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000497_10_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000497_1_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000497_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000497_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000497_4_1 & 1) != 0)
  {
    if ((sec_r000497_6_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((sec_r000497_4_2 & 1) != 0)
  {
    if ((sec_r000497_6_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000497_14_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000497_14_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000497_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000497_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000497_16_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000497_13_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000497_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000497_13_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000497_16_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000497_13_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000497_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000497_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000497_4_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000497_0_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000497_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000497_0_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000497_4_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000497_0_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000497_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000497_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000497_7_1 != sec_r000497_7_2);
  __CPROVER_assume(pub_r000497_4_1 == pub_r000497_4_2);
  __CPROVER_assume(pub_r000497_5_1 == pub_r000497_5_2);
  __CPROVER_assume(pub_r000497_16_1 == pub_r000497_16_2);
  __CPROVER_assume(pub_r000497_2_1 == pub_r000497_2_2);
  __CPROVER_assume(sec_r000497_12_1 != sec_r000497_12_2);
  __CPROVER_assume(pub_r000497_3_1 == pub_r000497_3_2);
  __CPROVER_assume(pub_r000497_0_1 == pub_r000497_0_2);
  __CPROVER_assume(sec_r000497_16_1 != sec_r000497_16_2);
  __CPROVER_assume(sec_r000497_1_1 != sec_r000497_1_2);
  __CPROVER_assume(sec_r000497_4_1 != sec_r000497_4_2);
  __CPROVER_assume(sec_r000497_6_1 != sec_r000497_6_2);
  __CPROVER_assume(sec_r000497_9_1 != sec_r000497_9_2);
  __CPROVER_assume(sec_r000497_0_1 != sec_r000497_0_2);
  __CPROVER_assume(pub_r000497_6_1 == pub_r000497_6_2);
  __CPROVER_assume(sec_r000497_2_1 != sec_r000497_2_2);
  __CPROVER_assume(pub_r000497_7_1 == pub_r000497_7_2);
  __CPROVER_assume(sec_r000497_17_1 != sec_r000497_17_2);
  __CPROVER_assume(pub_r000497_14_1 == pub_r000497_14_2);
  __CPROVER_assume(pub_r000497_8_1 == pub_r000497_8_2);
  __CPROVER_assume(sec_r000497_3_1 != sec_r000497_3_2);
  __CPROVER_assume(sec_r000497_15_1 != sec_r000497_15_2);
  __CPROVER_assume(pub_r000497_10_1 == pub_r000497_10_2);
  __CPROVER_assume(pub_r000497_13_1 == pub_r000497_13_2);
  __CPROVER_assume(pub_r000497_9_1 == pub_r000497_9_2);
  __CPROVER_assume(pub_r000497_15_1 == pub_r000497_15_2);
  __CPROVER_assume(sec_r000497_14_1 != sec_r000497_14_2);
  __CPROVER_assume(sec_r000497_8_1 != sec_r000497_8_2);
  __CPROVER_assume(sec_r000497_11_1 != sec_r000497_11_2);
  __CPROVER_assume(pub_r000497_1_1 == pub_r000497_1_2);
  __CPROVER_assume(pub_r000497_12_1 == pub_r000497_12_2);
  __CPROVER_assume(sec_r000497_13_1 != sec_r000497_13_2);
  __CPROVER_assume(sec_r000497_10_1 != sec_r000497_10_2);
  __CPROVER_assume(sec_r000497_5_1 != sec_r000497_5_2);
  __CPROVER_assume(pub_r000497_11_1 == pub_r000497_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
}


