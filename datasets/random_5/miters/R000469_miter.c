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
struct Vector3D_R000469_6913_0
{
  int pitch;
  unsigned char coord_y;
  short heading;
  int norm_sq;
  unsigned char coord_x;
  int buffer[3];
};
struct Transaction_R000469_6913_1
{
  unsigned char auth_code;
  int status;
  int balance;
  int buffer[3];
};
struct DeviceConfig_R000469_6913_2
{
  short id;
  short parity;
  short baud_rate;
  int stop_bits;
  short timeout;
  int buffer[3];
};
struct AudioFrame_R000469_6913_3
{
  int channels;
  unsigned char envelope;
  int gain;
  unsigned char peak;
  short sample_rate;
  int buffer[3];
};
union TelemetryField_R000469_6913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000469_6913_1
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
void fn_R000469_6913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st_1 = {0};
  struct Transaction_R000469_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_97_1 > 23)
  {
    acc_1 = ((acc_1 + (cursor_97_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_97_2 > 23)
  {
    acc_2 = ((acc_2 + (cursor_97_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_91_1) & 63;
  aux_2 = (aux_2 + checksum_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_44_1)
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

  switch (quantum_44_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_97_1 == cursor_97_2);
  assert(checksum_91_1 == checksum_91_2);
  assert(quantum_44_1 == quantum_44_2);
}

int fn_R000469_6913_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_97 > 23)
  {
    acc = ((acc + (cursor_97 * 2)) + 5) & 127;
    aux ^= cursor_97 & 15;
  }
  else
  {
    acc = ((acc - cursor_97) + 11) & 127;
    aux += 3;
  }
  int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_44 = (aux + st.buffer[1]) & 3;
  switch (quantum_44)
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

void fn_R000469_6913_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000469_6913_2 st_1 = {0};
  struct DeviceConfig_R000469_6913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int mask_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_76_1 > 18)
  {
    acc_1 = ((acc_1 + (mask_76_1 * 2)) + 5) & 127;
    aux_1 ^= mask_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_76_2 > 18)
  {
    acc_2 = ((acc_2 + (mask_76_2 * 2)) + 5) & 127;
    aux_2 ^= mask_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_44_1 = local_arr_1[aux_1 % 3];
  int parity_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_76_1 == mask_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_44_1 == parity_44_2);
}

int fn_R000469_6913_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000469_6913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int mask_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_76 > 18)
  {
    acc = ((acc + (mask_76 * 2)) + 5) & 127;
    aux ^= mask_76 & 15;
  }
  else
  {
    acc = ((acc - mask_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_44 = local_arr[aux % 3];
  acc = (acc + (parity_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st_1 = {0};
  struct Vector3D_R000469_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int sample_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_93_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_93_1 * 2)) + 5) & 127;
    aux_1 ^= sample_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_93_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_93_2 * 2)) + 5) & 127;
    aux_2 ^= sample_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_84_1 = local_arr_1[aux_1 % 3];
  int index_reg_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_93_1 == sample_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
}

int fn_R000469_6913_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int sample_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_93 > 50)
  {
    acc = ((acc + (sample_93 * 2)) + 5) & 127;
    aux ^= sample_93 & 15;
  }
  else
  {
    acc = ((acc - sample_93) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_84 = local_arr[aux % 3];
  acc = (acc + (index_reg_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st_1 = {0};
  struct Transaction_R000469_6913_1 st_2 = {0};
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
  int accumulator_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_73_1)
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

  switch (accumulator_73_2)
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

  int anchor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_38_1) & 63;
  aux_2 = (aux_2 + anchor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_59_1 > 17)
  {
    acc_1 = ((acc_1 + (cursor_59_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_59_2 > 17)
  {
    acc_2 = ((acc_2 + (cursor_59_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  assert(anchor_38_1 == anchor_38_2);
  assert(cursor_59_1 == cursor_59_2);
}

int fn_R000469_6913_3(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_73 = (aux + st.buffer[1]) & 3;
  switch (accumulator_73)
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

  int anchor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_38) & 63;
  acc ^= aux;
  int cursor_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_59 > 17)
  {
    acc = ((acc + (cursor_59 * 2)) + 5) & 127;
    aux ^= cursor_59 & 15;
  }
  else
  {
    acc = ((acc - cursor_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000469_6913_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st_1 = {0};
  struct Transaction_R000469_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int bound_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_57_1)
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

  switch (bound_57_2)
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
  int residue_26_1 = local_arr_1[aux_1 % 3];
  int residue_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_57_1 == bound_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_26_1 == residue_26_2);
}

int fn_R000469_6913_4(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int bound_57 = (aux + st.buffer[1]) & 3;
  switch (bound_57)
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
  int residue_26 = local_arr[aux % 3];
  acc = (acc + (residue_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_63_1 > 49)
  {
    acc_1 = ((acc_1 + (quotient_63_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_63_2 > 49)
  {
    acc_2 = ((acc_2 + (quotient_63_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_63_1 == quotient_63_2);
}

int fn_R000469_6913_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_63 > 49)
  {
    acc = ((acc + (quotient_63 * 2)) + 5) & 127;
    aux ^= quotient_63 & 15;
  }
  else
  {
    acc = ((acc - quotient_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_60_1)
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

  switch (offset_60_2)
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
  int bound_96_1 = local_arr_1[aux_1 % 3];
  int bound_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_96_2 * 2)) & 127;
  int residue_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_58_1 > 13)
  {
    acc_1 = ((acc_1 + (residue_58_1 * 2)) + 5) & 127;
    aux_1 ^= residue_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_58_2 > 13)
  {
    acc_2 = ((acc_2 + (residue_58_2 * 2)) + 5) & 127;
    aux_2 ^= residue_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_96_1 == bound_96_2);
  assert(residue_58_1 == residue_58_2);
}

int fn_R000469_6913_6(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_60 = (aux + st.buffer[1]) & 3;
  switch (offset_60)
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
  int bound_96 = local_arr[aux % 3];
  acc = (acc + (bound_96 * 2)) & 127;
  int residue_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_58 > 13)
  {
    acc = ((acc + (residue_58 * 2)) + 5) & 127;
    aux ^= residue_58 & 15;
  }
  else
  {
    acc = ((acc - residue_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000469_6913_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st_1 = {0};
  struct Transaction_R000469_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_22_1 > 11)
  {
    acc_1 = ((acc_1 + (bound_22_1 * 2)) + 5) & 127;
    aux_1 ^= bound_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_22_2 > 11)
  {
    acc_2 = ((acc_2 + (bound_22_2 * 2)) + 5) & 127;
    aux_2 ^= bound_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_22_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_22_1 == bound_22_2);
}

int fn_R000469_6913_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_22 > 11)
  {
    acc = ((acc + (bound_22 * 2)) + 5) & 127;
    aux ^= bound_22 & 15;
  }
  else
  {
    acc = ((acc - bound_22) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st_1 = {0};
  struct Vector3D_R000469_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_82_1 = local_arr_1[aux_1 % 3];
  int metric_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
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

  assert(metric_82_1 == metric_82_2);
}

int fn_R000469_6913_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_82 = local_arr[aux % 3];
  acc = (acc + (metric_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st_1 = {0};
  struct Transaction_R000469_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_12_1)
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

  switch (damping_12_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_69_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_69_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_69_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_69_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_56_1) & 63;
  aux_2 = (aux_2 + quotient_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_12_1 == damping_12_2);
  assert(quotient_69_1 == quotient_69_2);
  assert(quotient_56_1 == quotient_56_2);
}

int fn_R000469_6913_9(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000469_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_12 = (aux + st.buffer[1]) & 3;
  switch (damping_12)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_69 > 45)
  {
    acc = ((acc + (quotient_69 * 2)) + 5) & 127;
    aux ^= quotient_69 & 15;
  }
  else
  {
    acc = ((acc - quotient_69) + 11) & 127;
    aux += 3;
  }
  int quotient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000469_6913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quantum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_75_1)
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

  switch (quantum_75_2)
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

  int sample_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_33_1) & 63;
  aux_2 = (aux_2 + sample_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_77_1 = local_arr_1[aux_1 % 3];
  int bound_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_75_1 == quantum_75_2);
  assert(sample_33_1 == sample_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_77_1 == bound_77_2);
}

int fn_R000469_6913_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quantum_75 = (aux + st.buffer[1]) & 3;
  switch (quantum_75)
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

  int sample_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_77 = local_arr[aux % 3];
  acc = (acc + (bound_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_99_1 > 40)
  {
    acc_1 = ((acc_1 + (margin_99_1 * 2)) + 5) & 127;
    aux_1 ^= margin_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_99_2 > 40)
  {
    acc_2 = ((acc_2 + (margin_99_2 * 2)) + 5) & 127;
    aux_2 ^= margin_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_99_1 == margin_99_2);
}

int fn_R000469_6913_11(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_99 > 40)
  {
    acc = ((acc + (margin_99 * 2)) + 5) & 127;
    aux ^= margin_99 & 15;
  }
  else
  {
    acc = ((acc - margin_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000469_6913_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_92_1)
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

  switch (residue_92_2)
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
  int threshold_68_1 = local_arr_1[aux_1 % 3];
  int threshold_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_68_2 * 2)) & 127;
  int damping_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_67_1 > 32)
  {
    acc_1 = ((acc_1 + (damping_67_1 * 2)) + 5) & 127;
    aux_1 ^= damping_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_67_2 > 32)
  {
    acc_2 = ((acc_2 + (damping_67_2 * 2)) + 5) & 127;
    aux_2 ^= damping_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_92_1 == residue_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_68_1 == threshold_68_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R000469_6913_12(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_92 = (aux + st.buffer[1]) & 3;
  switch (residue_92)
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
  int threshold_68 = local_arr[aux % 3];
  acc = (acc + (threshold_68 * 2)) & 127;
  int damping_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_67 > 32)
  {
    acc = ((acc + (damping_67 * 2)) + 5) & 127;
    aux ^= damping_67 & 15;
  }
  else
  {
    acc = ((acc - damping_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000469_6913_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st_1 = {0};
  struct AudioFrame_R000469_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_88_1 = local_arr_1[aux_1 % 3];
  int weight_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_88_1 == weight_88_2);
}

int fn_R000469_6913_13(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000469_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int weight_88 = local_arr[aux % 3];
  acc = (acc + (weight_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000469_6913_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st_1 = {0};
  struct Vector3D_R000469_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_97_1) & 63;
  aux_2 = (aux_2 + factor_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_82_1)
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

  switch (margin_82_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_97_1 == factor_97_2);
  assert(margin_82_1 == margin_82_2);
}

int fn_R000469_6913_14(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000469_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_97) & 63;
  acc ^= aux;
  int margin_82 = (aux + st.buffer[1]) & 3;
  switch (margin_82)
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

void main()
{
  int sec_r000469_0_1;
  int sec_r000469_0_2;
  int sec_r000469_1_1;
  int sec_r000469_1_2;
  int sec_r000469_2_1;
  int sec_r000469_2_2;
  int sec_r000469_3_1;
  int sec_r000469_3_2;
  int sec_r000469_4_1;
  int sec_r000469_4_2;
  int sec_r000469_5_1;
  int sec_r000469_5_2;
  int sec_r000469_6_1;
  int sec_r000469_6_2;
  int sec_r000469_7_1;
  int sec_r000469_7_2;
  int sec_r000469_8_1;
  int sec_r000469_8_2;
  int sec_r000469_9_1;
  int sec_r000469_9_2;
  int sec_r000469_10_1;
  int sec_r000469_10_2;
  int sec_r000469_11_1;
  int sec_r000469_11_2;
  int sec_r000469_12_1;
  int sec_r000469_12_2;
  int sec_r000469_13_1;
  int sec_r000469_13_2;
  int sec_r000469_14_1;
  int sec_r000469_14_2;
  int sec_r000469_15_1;
  int sec_r000469_15_2;
  int sec_r000469_16_1;
  int sec_r000469_16_2;
  int sec_r000469_17_1;
  int sec_r000469_17_2;
  int sec_r000469_18_1;
  int sec_r000469_18_2;
  int sec_r000469_19_1;
  int sec_r000469_19_2;
  int sec_r000469_20_1;
  int sec_r000469_20_2;
  int sec_r000469_21_1;
  int sec_r000469_21_2;
  int sec_r000469_22_1;
  int sec_r000469_22_2;
  int pub_r000469_0_1;
  int pub_r000469_0_2;
  int pub_r000469_1_1;
  int pub_r000469_1_2;
  int pub_r000469_2_1;
  int pub_r000469_2_2;
  int pub_r000469_3_1;
  int pub_r000469_3_2;
  int pub_r000469_4_1;
  int pub_r000469_4_2;
  int pub_r000469_5_1;
  int pub_r000469_5_2;
  int pub_r000469_6_1;
  int pub_r000469_6_2;
  int pub_r000469_7_1;
  int pub_r000469_7_2;
  int pub_r000469_8_1;
  int pub_r000469_8_2;
  int pub_r000469_9_1;
  int pub_r000469_9_2;
  int pub_r000469_10_1;
  int pub_r000469_10_2;
  int pub_r000469_11_1;
  int pub_r000469_11_2;
  int pub_r000469_12_1;
  int pub_r000469_12_2;
  int pub_r000469_13_1;
  int pub_r000469_13_2;
  int pub_r000469_14_1;
  int pub_r000469_14_2;
  int pub_r000469_15_1;
  int pub_r000469_15_2;
  int pub_r000469_16_1;
  int pub_r000469_16_2;
  int pub_r000469_17_1;
  int pub_r000469_17_2;
  int pub_r000469_18_1;
  int pub_r000469_18_2;
  int pub_r000469_19_1;
  int pub_r000469_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000469_0_1 >= (-100)) && (pub_r000469_0_1 <= 100));
  __CPROVER_assume((pub_r000469_0_2 >= (-100)) && (pub_r000469_0_2 <= 100));
  __CPROVER_assume((pub_r000469_1_1 >= (-100)) && (pub_r000469_1_1 <= 100));
  __CPROVER_assume((pub_r000469_1_2 >= (-100)) && (pub_r000469_1_2 <= 100));
  __CPROVER_assume((pub_r000469_2_1 >= (-100)) && (pub_r000469_2_1 <= 100));
  __CPROVER_assume((pub_r000469_2_2 >= (-100)) && (pub_r000469_2_2 <= 100));
  __CPROVER_assume((pub_r000469_3_1 >= (-100)) && (pub_r000469_3_1 <= 100));
  __CPROVER_assume((pub_r000469_3_2 >= (-100)) && (pub_r000469_3_2 <= 100));
  __CPROVER_assume((pub_r000469_4_1 >= (-100)) && (pub_r000469_4_1 <= 100));
  __CPROVER_assume((pub_r000469_4_2 >= (-100)) && (pub_r000469_4_2 <= 100));
  __CPROVER_assume((pub_r000469_5_1 >= (-100)) && (pub_r000469_5_1 <= 100));
  __CPROVER_assume((pub_r000469_5_2 >= (-100)) && (pub_r000469_5_2 <= 100));
  __CPROVER_assume((pub_r000469_6_1 >= (-100)) && (pub_r000469_6_1 <= 100));
  __CPROVER_assume((pub_r000469_6_2 >= (-100)) && (pub_r000469_6_2 <= 100));
  __CPROVER_assume((pub_r000469_7_1 >= (-100)) && (pub_r000469_7_1 <= 100));
  __CPROVER_assume((pub_r000469_7_2 >= (-100)) && (pub_r000469_7_2 <= 100));
  __CPROVER_assume((pub_r000469_8_1 >= (-100)) && (pub_r000469_8_1 <= 100));
  __CPROVER_assume((pub_r000469_8_2 >= (-100)) && (pub_r000469_8_2 <= 100));
  __CPROVER_assume((pub_r000469_9_1 >= (-100)) && (pub_r000469_9_1 <= 100));
  __CPROVER_assume((pub_r000469_9_2 >= (-100)) && (pub_r000469_9_2 <= 100));
  __CPROVER_assume((pub_r000469_10_1 >= (-100)) && (pub_r000469_10_1 <= 100));
  __CPROVER_assume((pub_r000469_10_2 >= (-100)) && (pub_r000469_10_2 <= 100));
  __CPROVER_assume((pub_r000469_11_1 >= (-100)) && (pub_r000469_11_1 <= 100));
  __CPROVER_assume((pub_r000469_11_2 >= (-100)) && (pub_r000469_11_2 <= 100));
  __CPROVER_assume((pub_r000469_12_1 >= (-100)) && (pub_r000469_12_1 <= 100));
  __CPROVER_assume((pub_r000469_12_2 >= (-100)) && (pub_r000469_12_2 <= 100));
  __CPROVER_assume((pub_r000469_13_1 >= (-100)) && (pub_r000469_13_1 <= 100));
  __CPROVER_assume((pub_r000469_13_2 >= (-100)) && (pub_r000469_13_2 <= 100));
  __CPROVER_assume((pub_r000469_14_1 >= (-100)) && (pub_r000469_14_1 <= 100));
  __CPROVER_assume((pub_r000469_14_2 >= (-100)) && (pub_r000469_14_2 <= 100));
  __CPROVER_assume((pub_r000469_15_1 >= (-100)) && (pub_r000469_15_1 <= 100));
  __CPROVER_assume((pub_r000469_15_2 >= (-100)) && (pub_r000469_15_2 <= 100));
  __CPROVER_assume((pub_r000469_16_1 >= (-100)) && (pub_r000469_16_1 <= 100));
  __CPROVER_assume((pub_r000469_16_2 >= (-100)) && (pub_r000469_16_2 <= 100));
  __CPROVER_assume((pub_r000469_17_1 >= (-100)) && (pub_r000469_17_1 <= 100));
  __CPROVER_assume((pub_r000469_17_2 >= (-100)) && (pub_r000469_17_2 <= 100));
  __CPROVER_assume((pub_r000469_18_1 >= (-100)) && (pub_r000469_18_1 <= 100));
  __CPROVER_assume((pub_r000469_18_2 >= (-100)) && (pub_r000469_18_2 <= 100));
  __CPROVER_assume((pub_r000469_19_1 >= (-100)) && (pub_r000469_19_1 <= 100));
  __CPROVER_assume((pub_r000469_19_2 >= (-100)) && (pub_r000469_19_2 <= 100));
  __CPROVER_assume((sec_r000469_0_1 >= 0) && (sec_r000469_0_1 <= 255));
  __CPROVER_assume((sec_r000469_0_2 >= 0) && (sec_r000469_0_2 <= 255));
  __CPROVER_assume((sec_r000469_1_1 >= 0) && (sec_r000469_1_1 <= 255));
  __CPROVER_assume((sec_r000469_1_2 >= 0) && (sec_r000469_1_2 <= 255));
  __CPROVER_assume((sec_r000469_2_1 >= 0) && (sec_r000469_2_1 <= 255));
  __CPROVER_assume((sec_r000469_2_2 >= 0) && (sec_r000469_2_2 <= 255));
  __CPROVER_assume((sec_r000469_3_1 >= 0) && (sec_r000469_3_1 <= 255));
  __CPROVER_assume((sec_r000469_3_2 >= 0) && (sec_r000469_3_2 <= 255));
  __CPROVER_assume((sec_r000469_4_1 >= 0) && (sec_r000469_4_1 <= 255));
  __CPROVER_assume((sec_r000469_4_2 >= 0) && (sec_r000469_4_2 <= 255));
  __CPROVER_assume((sec_r000469_5_1 >= 0) && (sec_r000469_5_1 <= 255));
  __CPROVER_assume((sec_r000469_5_2 >= 0) && (sec_r000469_5_2 <= 255));
  __CPROVER_assume((sec_r000469_6_1 >= 0) && (sec_r000469_6_1 <= 255));
  __CPROVER_assume((sec_r000469_6_2 >= 0) && (sec_r000469_6_2 <= 255));
  __CPROVER_assume((sec_r000469_7_1 >= 0) && (sec_r000469_7_1 <= 255));
  __CPROVER_assume((sec_r000469_7_2 >= 0) && (sec_r000469_7_2 <= 255));
  __CPROVER_assume((sec_r000469_8_1 >= 0) && (sec_r000469_8_1 <= 255));
  __CPROVER_assume((sec_r000469_8_2 >= 0) && (sec_r000469_8_2 <= 255));
  __CPROVER_assume((sec_r000469_9_1 >= 0) && (sec_r000469_9_1 <= 255));
  __CPROVER_assume((sec_r000469_9_2 >= 0) && (sec_r000469_9_2 <= 255));
  __CPROVER_assume((sec_r000469_10_1 >= 0) && (sec_r000469_10_1 <= 255));
  __CPROVER_assume((sec_r000469_10_2 >= 0) && (sec_r000469_10_2 <= 255));
  __CPROVER_assume((sec_r000469_11_1 >= 0) && (sec_r000469_11_1 <= 255));
  __CPROVER_assume((sec_r000469_11_2 >= 0) && (sec_r000469_11_2 <= 255));
  __CPROVER_assume((sec_r000469_12_1 >= 0) && (sec_r000469_12_1 <= 255));
  __CPROVER_assume((sec_r000469_12_2 >= 0) && (sec_r000469_12_2 <= 255));
  __CPROVER_assume((sec_r000469_13_1 >= 0) && (sec_r000469_13_1 <= 255));
  __CPROVER_assume((sec_r000469_13_2 >= 0) && (sec_r000469_13_2 <= 255));
  __CPROVER_assume((sec_r000469_14_1 >= 0) && (sec_r000469_14_1 <= 255));
  __CPROVER_assume((sec_r000469_14_2 >= 0) && (sec_r000469_14_2 <= 255));
  __CPROVER_assume((sec_r000469_15_1 >= 0) && (sec_r000469_15_1 <= 255));
  __CPROVER_assume((sec_r000469_15_2 >= 0) && (sec_r000469_15_2 <= 255));
  __CPROVER_assume((sec_r000469_16_1 >= 0) && (sec_r000469_16_1 <= 255));
  __CPROVER_assume((sec_r000469_16_2 >= 0) && (sec_r000469_16_2 <= 255));
  __CPROVER_assume((sec_r000469_17_1 >= 0) && (sec_r000469_17_1 <= 255));
  __CPROVER_assume((sec_r000469_17_2 >= 0) && (sec_r000469_17_2 <= 255));
  __CPROVER_assume((sec_r000469_18_1 >= 0) && (sec_r000469_18_1 <= 255));
  __CPROVER_assume((sec_r000469_18_2 >= 0) && (sec_r000469_18_2 <= 255));
  __CPROVER_assume((sec_r000469_19_1 >= 0) && (sec_r000469_19_1 <= 255));
  __CPROVER_assume((sec_r000469_19_2 >= 0) && (sec_r000469_19_2 <= 255));
  __CPROVER_assume((sec_r000469_20_1 >= 0) && (sec_r000469_20_1 <= 255));
  __CPROVER_assume((sec_r000469_20_2 >= 0) && (sec_r000469_20_2 <= 255));
  __CPROVER_assume((sec_r000469_21_1 >= 0) && (sec_r000469_21_1 <= 255));
  __CPROVER_assume((sec_r000469_21_2 >= 0) && (sec_r000469_21_2 <= 255));
  __CPROVER_assume((sec_r000469_22_1 >= 0) && (sec_r000469_22_1 <= 255));
  __CPROVER_assume((sec_r000469_22_2 >= 0) && (sec_r000469_22_2 <= 255));
  struct Vector3D_R000469_6913_0 st_var_0_1 = {0};
  struct Vector3D_R000469_6913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000469_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000469_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000469_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000469_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000469_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000469_0_2 + 7) & 15;
  struct Transaction_R000469_6913_1 st_var_1_1 = {0};
  struct Transaction_R000469_6913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000469_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000469_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000469_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000469_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000469_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000469_0_2 + 9) & 15;
  struct DeviceConfig_R000469_6913_2 st_var_2_1 = {0};
  struct DeviceConfig_R000469_6913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000469_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000469_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000469_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000469_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000469_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000469_0_2 + 11) & 15;
  struct AudioFrame_R000469_6913_3 st_var_3_1 = {0};
  struct AudioFrame_R000469_6913_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000469_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000469_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000469_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000469_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000469_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000469_0_2 + 13) & 15;
  union TelemetryField_R000469_6913_0 u_var_1;
  union TelemetryField_R000469_6913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 31)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 31)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int s_idx_28_1 = sec_r000469_11_1 & 3;
  int s_idx_28_2 = sec_r000469_11_2 & 3;
  int stage_v_28_1 = (table_1[s_idx_28_1] + pub_r000469_18_1) & 127;
  int stage_v_28_2 = (table_2[s_idx_28_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_28_1] = (stage_v_28_1 + 7) & 63;
  table_2[s_idx_28_2] = (stage_v_28_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int s_idx_29_1 = stage_v_28_1 & 3;
  int s_idx_29_2 = stage_v_28_2 & 3;
  int stage_v_29_1 = (table_1[s_idx_29_1] + pub_r000469_17_1) & 127;
  int stage_v_29_2 = (table_2[s_idx_29_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_29_1] = (stage_v_29_1 + 7) & 63;
  table_2[s_idx_29_2] = (stage_v_29_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int s_idx_30_1 = stage_v_28_1 & 3;
  int s_idx_30_2 = stage_v_28_2 & 3;
  int stage_v_30_1 = (table_1[s_idx_30_1] + pub_r000469_2_1) & 127;
  int stage_v_30_2 = (table_2[s_idx_30_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_30_1] = (stage_v_30_1 + 7) & 63;
  table_2[s_idx_30_2] = (stage_v_30_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int s_idx_31_1 = sec_r000469_19_1 & 3;
  int s_idx_31_2 = sec_r000469_19_2 & 3;
  int stage_v_31_1 = (table_1[s_idx_31_1] + pub_r000469_9_1) & 127;
  int stage_v_31_2 = (table_2[s_idx_31_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_31_1] = (stage_v_31_1 + 7) & 63;
  table_2[s_idx_31_2] = (stage_v_31_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int s_idx_32_1 = stage_v_31_1 & 3;
  int s_idx_32_2 = stage_v_31_2 & 3;
  int stage_v_32_1 = (table_1[s_idx_32_1] + pub_r000469_2_1) & 127;
  int stage_v_32_2 = (table_2[s_idx_32_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_32_1] = (stage_v_32_1 + 7) & 63;
  table_2[s_idx_32_2] = (stage_v_32_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int s_idx_33_1 = sec_r000469_4_1 & 3;
  int s_idx_33_2 = sec_r000469_4_2 & 3;
  int stage_v_33_1 = (table_1[s_idx_33_1] + pub_r000469_9_1) & 127;
  int stage_v_33_2 = (table_2[s_idx_33_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_33_1] = (stage_v_33_1 + 7) & 63;
  table_2[s_idx_33_2] = (stage_v_33_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int s_idx_34_1 = sec_r000469_14_1 & 3;
  int s_idx_34_2 = sec_r000469_14_2 & 3;
  int stage_v_34_1 = (table_1[s_idx_34_1] + pub_r000469_3_1) & 127;
  int stage_v_34_2 = (table_2[s_idx_34_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_34_1] = (stage_v_34_1 + 7) & 63;
  table_2[s_idx_34_2] = (stage_v_34_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int s_idx_35_1 = stage_v_32_1 & 3;
  int s_idx_35_2 = stage_v_32_2 & 3;
  int stage_v_35_1 = (table_1[s_idx_35_1] + pub_r000469_16_1) & 127;
  int stage_v_35_2 = (table_2[s_idx_35_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_35_1] = (stage_v_35_1 + 7) & 63;
  table_2[s_idx_35_2] = (stage_v_35_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int s_idx_36_1 = stage_v_30_1 & 3;
  int s_idx_36_2 = stage_v_30_2 & 3;
  int stage_v_36_1 = (table_1[s_idx_36_1] + pub_r000469_4_1) & 127;
  int stage_v_36_2 = (table_2[s_idx_36_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_36_1] = (stage_v_36_1 + 7) & 63;
  table_2[s_idx_36_2] = (stage_v_36_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int s_idx_37_1 = sec_r000469_0_1 & 3;
  int s_idx_37_2 = sec_r000469_0_2 & 3;
  int stage_v_37_1 = (table_1[s_idx_37_1] + pub_r000469_2_1) & 127;
  int stage_v_37_2 = (table_2[s_idx_37_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_37_1] = (stage_v_37_1 + 7) & 63;
  table_2[s_idx_37_2] = (stage_v_37_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int s_idx_38_1 = stage_v_34_1 & 3;
  int s_idx_38_2 = stage_v_34_2 & 3;
  int stage_v_38_1 = (table_1[s_idx_38_1] + pub_r000469_8_1) & 127;
  int stage_v_38_2 = (table_2[s_idx_38_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_38_1] = (stage_v_38_1 + 7) & 63;
  table_2[s_idx_38_2] = (stage_v_38_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int s_idx_39_1 = stage_v_35_1 & 3;
  int s_idx_39_2 = stage_v_35_2 & 3;
  int stage_v_39_1 = (table_1[s_idx_39_1] + pub_r000469_10_1) & 127;
  int stage_v_39_2 = (table_2[s_idx_39_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_39_1] = (stage_v_39_1 + 7) & 63;
  table_2[s_idx_39_2] = (stage_v_39_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int s_idx_40_1 = sec_r000469_2_1 & 3;
  int s_idx_40_2 = sec_r000469_2_2 & 3;
  int stage_v_40_1 = (table_1[s_idx_40_1] + pub_r000469_1_1) & 127;
  int stage_v_40_2 = (table_2[s_idx_40_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_40_1] = (stage_v_40_1 + 7) & 63;
  table_2[s_idx_40_2] = (stage_v_40_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int s_idx_41_1 = stage_v_34_1 & 3;
  int s_idx_41_2 = stage_v_34_2 & 3;
  int stage_v_41_1 = (table_1[s_idx_41_1] + pub_r000469_4_1) & 127;
  int stage_v_41_2 = (table_2[s_idx_41_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_41_1] = (stage_v_41_1 + 7) & 63;
  table_2[s_idx_41_2] = (stage_v_41_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int s_idx_42_1 = stage_v_41_1 & 3;
  int s_idx_42_2 = stage_v_41_2 & 3;
  int stage_v_42_1 = (table_1[s_idx_42_1] + pub_r000469_6_1) & 127;
  int stage_v_42_2 = (table_2[s_idx_42_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_42_1] = (stage_v_42_1 + 7) & 63;
  table_2[s_idx_42_2] = (stage_v_42_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int s_idx_43_1 = stage_v_32_1 & 3;
  int s_idx_43_2 = stage_v_32_2 & 3;
  int stage_v_43_1 = (table_1[s_idx_43_1] + pub_r000469_8_1) & 127;
  int stage_v_43_2 = (table_2[s_idx_43_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_43_1] = (stage_v_43_1 + 7) & 63;
  table_2[s_idx_43_2] = (stage_v_43_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int s_idx_44_1 = sec_r000469_0_1 & 3;
  int s_idx_44_2 = sec_r000469_0_2 & 3;
  int stage_v_44_1 = (table_1[s_idx_44_1] + pub_r000469_17_1) & 127;
  int stage_v_44_2 = (table_2[s_idx_44_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_44_1] = (stage_v_44_1 + 7) & 63;
  table_2[s_idx_44_2] = (stage_v_44_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int s_idx_45_1 = sec_r000469_20_1 & 3;
  int s_idx_45_2 = sec_r000469_20_2 & 3;
  int stage_v_45_1 = (table_1[s_idx_45_1] + pub_r000469_11_1) & 127;
  int stage_v_45_2 = (table_2[s_idx_45_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_45_1] = (stage_v_45_1 + 7) & 63;
  table_2[s_idx_45_2] = (stage_v_45_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int s_idx_46_1 = stage_v_41_1 & 3;
  int s_idx_46_2 = stage_v_41_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000469_14_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = stage_v_35_1 & 3;
  int s_idx_47_2 = stage_v_35_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000469_1_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = stage_v_46_1 & 3;
  int s_idx_48_2 = stage_v_46_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000469_14_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = stage_v_31_1 & 3;
  int s_idx_49_2 = stage_v_31_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000469_10_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = stage_v_30_1 & 3;
  int s_idx_50_2 = stage_v_30_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000469_7_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000469_7_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = stage_v_48_1 & 3;
  int s_idx_51_2 = stage_v_48_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000469_18_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = sec_r000469_5_1 & 3;
  int s_idx_52_2 = sec_r000469_5_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000469_8_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = sec_r000469_14_1 & 3;
  int s_idx_53_2 = sec_r000469_14_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000469_11_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = stage_v_42_1 & 3;
  int s_idx_54_2 = stage_v_42_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000469_3_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_53_1 & 3;
  int s_idx_55_2 = stage_v_53_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000469_10_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = stage_v_34_1 & 3;
  int s_idx_56_2 = stage_v_34_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000469_14_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = sec_r000469_17_1 & 3;
  int s_idx_57_2 = sec_r000469_17_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000469_11_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = stage_v_55_1 & 3;
  int s_idx_58_2 = stage_v_55_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000469_19_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = stage_v_36_1 & 3;
  int s_idx_59_2 = stage_v_36_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000469_1_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = stage_v_53_1 & 3;
  int s_idx_60_2 = stage_v_53_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000469_18_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = sec_r000469_3_1 & 3;
  int s_idx_61_2 = sec_r000469_3_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000469_0_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = stage_v_53_1 & 3;
  int s_idx_62_2 = stage_v_53_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000469_2_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = stage_v_52_1 & 3;
  int s_idx_63_2 = stage_v_52_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000469_10_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = stage_v_40_1 & 3;
  int s_idx_64_2 = stage_v_40_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000469_0_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = stage_v_59_1 & 3;
  int s_idx_65_2 = stage_v_59_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000469_1_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = stage_v_33_1 & 3;
  int s_idx_66_2 = stage_v_33_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000469_18_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_56_1 & 3;
  int s_idx_67_2 = stage_v_56_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000469_18_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = stage_v_48_1 & 3;
  int s_idx_68_2 = stage_v_48_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000469_9_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = stage_v_63_1 & 3;
  int s_idx_69_2 = stage_v_63_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000469_2_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = stage_v_66_1 & 3;
  int s_idx_70_2 = stage_v_66_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000469_10_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = sec_r000469_6_1 & 3;
  int s_idx_71_2 = sec_r000469_6_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000469_14_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_69_1 & 3;
  int s_idx_72_2 = stage_v_69_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000469_14_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = stage_v_47_1 & 3;
  int s_idx_73_2 = stage_v_47_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000469_7_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000469_7_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = stage_v_45_1 & 3;
  int s_idx_74_2 = stage_v_45_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000469_14_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = stage_v_56_1 & 3;
  int s_idx_75_2 = stage_v_56_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000469_18_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = sec_r000469_5_1 & 3;
  int s_idx_76_2 = sec_r000469_5_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000469_5_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = stage_v_30_1 & 3;
  int s_idx_77_2 = stage_v_30_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000469_11_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = stage_v_50_1 & 3;
  int s_idx_78_2 = stage_v_50_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000469_15_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = sec_r000469_12_1 & 3;
  int s_idx_79_2 = sec_r000469_12_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000469_17_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = stage_v_59_1 & 3;
  int s_idx_80_2 = stage_v_59_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000469_0_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_28_1 & 3;
  int s_idx_81_2 = stage_v_28_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000469_9_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = stage_v_74_1 & 3;
  int s_idx_82_2 = stage_v_74_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000469_13_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = stage_v_81_1 & 3;
  int s_idx_83_2 = stage_v_81_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000469_14_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = stage_v_80_1 & 3;
  int s_idx_84_2 = stage_v_80_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000469_8_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = stage_v_34_1 & 3;
  int s_idx_85_2 = stage_v_34_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000469_12_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = sec_r000469_21_1 & 3;
  int s_idx_86_2 = sec_r000469_21_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000469_0_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = stage_v_79_1 & 3;
  int s_idx_87_2 = stage_v_79_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000469_8_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = stage_v_77_1 & 3;
  int s_idx_88_2 = stage_v_77_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000469_6_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = stage_v_42_1 & 3;
  int s_idx_89_2 = stage_v_42_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000469_7_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000469_7_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = sec_r000469_15_1 & 3;
  int s_idx_90_2 = sec_r000469_15_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000469_9_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = sec_r000469_5_1 & 3;
  int s_idx_91_2 = sec_r000469_5_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000469_5_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = sec_r000469_11_1 & 3;
  int s_idx_92_2 = sec_r000469_11_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000469_14_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_48_1 & 3;
  int s_idx_93_2 = stage_v_48_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000469_15_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = sec_r000469_4_1 & 3;
  int s_idx_94_2 = sec_r000469_4_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000469_10_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = sec_r000469_9_1 & 3;
  int s_idx_95_2 = sec_r000469_9_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000469_8_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = sec_r000469_10_1 & 3;
  int s_idx_96_2 = sec_r000469_10_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000469_10_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = sec_r000469_8_1 & 3;
  int s_idx_97_2 = sec_r000469_8_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000469_5_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = sec_r000469_7_1 & 3;
  int s_idx_98_2 = sec_r000469_7_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000469_14_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = stage_v_45_1 & 3;
  int s_idx_99_2 = stage_v_45_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000469_8_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = sec_r000469_8_1 & 3;
  int s_idx_100_2 = sec_r000469_8_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000469_3_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = sec_r000469_1_1 & 3;
  int s_idx_101_2 = sec_r000469_1_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000469_1_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = stage_v_79_1 & 3;
  int s_idx_102_2 = stage_v_79_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000469_10_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_61_1 & 3;
  int s_idx_103_2 = stage_v_61_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000469_11_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_69_1 & 3;
  int s_idx_104_2 = stage_v_69_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000469_2_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = sec_r000469_8_1 & 3;
  int s_idx_105_2 = sec_r000469_8_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000469_17_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_67_1 & 3;
  int s_idx_106_2 = stage_v_67_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000469_9_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = stage_v_104_1 & 3;
  int s_idx_107_2 = stage_v_104_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000469_1_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = sec_r000469_22_1 & 3;
  int s_idx_108_2 = sec_r000469_22_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000469_6_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = sec_r000469_22_1 & 3;
  int s_idx_109_2 = sec_r000469_22_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000469_1_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = stage_v_77_1 & 3;
  int s_idx_110_2 = stage_v_77_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000469_8_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_32_1 & 3;
  int s_idx_111_2 = stage_v_32_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000469_9_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = stage_v_87_1 & 3;
  int s_idx_112_2 = stage_v_87_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000469_19_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = stage_v_85_1 & 3;
  int s_idx_113_2 = stage_v_85_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000469_5_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = stage_v_112_1 & 3;
  int s_idx_114_2 = stage_v_112_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000469_10_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = stage_v_93_1 & 3;
  int s_idx_115_2 = stage_v_93_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000469_11_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_85_1 & 3;
  int s_idx_116_2 = stage_v_85_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000469_5_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = stage_v_37_1 & 3;
  int s_idx_117_2 = stage_v_37_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000469_18_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = stage_v_93_1 & 3;
  int s_idx_118_2 = stage_v_93_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000469_10_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = sec_r000469_19_1 & 3;
  int s_idx_119_2 = sec_r000469_19_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000469_18_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = sec_r000469_17_1 & 3;
  int s_idx_120_2 = sec_r000469_17_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000469_18_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = stage_v_82_1 & 3;
  int s_idx_121_2 = stage_v_82_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000469_17_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = sec_r000469_0_1 & 3;
  int s_idx_122_2 = sec_r000469_0_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000469_18_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = sec_r000469_4_1 & 3;
  int s_idx_123_2 = sec_r000469_4_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000469_6_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = sec_r000469_8_1 & 3;
  int s_idx_124_2 = sec_r000469_8_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000469_1_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_94_1 & 3;
  int s_idx_125_2 = stage_v_94_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000469_11_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = stage_v_84_1 & 3;
  int s_idx_126_2 = stage_v_84_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000469_12_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = sec_r000469_4_1 & 3;
  int s_idx_127_2 = sec_r000469_4_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000469_2_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = stage_v_44_1 & 3;
  int s_idx_128_2 = stage_v_44_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000469_13_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = stage_v_93_1 & 3;
  int s_idx_129_2 = stage_v_93_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000469_1_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000469_15_1 & 3;
  int s_idx_130_2 = sec_r000469_15_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000469_6_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = stage_v_30_1 & 3;
  int s_idx_131_2 = stage_v_30_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000469_1_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = sec_r000469_16_1 & 3;
  int s_idx_132_2 = sec_r000469_16_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000469_0_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = stage_v_126_1 & 3;
  int s_idx_133_2 = stage_v_126_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000469_6_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = stage_v_121_1 & 3;
  int s_idx_134_2 = stage_v_121_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000469_5_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_48_1 & 3;
  int s_idx_135_2 = stage_v_48_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000469_14_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = stage_v_118_1 & 3;
  int s_idx_136_2 = stage_v_118_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000469_3_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_36_1 & 3;
  int s_idx_137_2 = stage_v_36_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000469_18_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = stage_v_36_1 & 3;
  int s_idx_138_2 = stage_v_36_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000469_4_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = stage_v_133_1 & 3;
  int s_idx_139_2 = stage_v_133_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000469_10_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = stage_v_77_1 & 3;
  int s_idx_140_2 = stage_v_77_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000469_5_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = stage_v_117_1 & 3;
  int s_idx_141_2 = stage_v_117_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000469_18_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = stage_v_80_1 & 3;
  int s_idx_142_2 = stage_v_80_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000469_6_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_56_1 & 3;
  int s_idx_143_2 = stage_v_56_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000469_8_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_64_1 & 3;
  int s_idx_144_2 = stage_v_64_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000469_16_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = sec_r000469_6_1 & 3;
  int s_idx_145_2 = sec_r000469_6_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000469_13_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = sec_r000469_4_1 & 3;
  int s_idx_146_2 = sec_r000469_4_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000469_5_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = sec_r000469_2_1 & 3;
  int s_idx_147_2 = sec_r000469_2_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000469_5_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_122_1 & 3;
  int s_idx_148_2 = stage_v_122_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000469_19_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = sec_r000469_14_1 & 3;
  int s_idx_149_2 = sec_r000469_14_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000469_3_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = sec_r000469_14_1 & 3;
  int s_idx_150_2 = sec_r000469_14_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000469_13_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = stage_v_37_1 & 3;
  int s_idx_151_2 = stage_v_37_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000469_8_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = sec_r000469_19_1 & 3;
  int s_idx_152_2 = sec_r000469_19_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000469_9_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_100_1 & 3;
  int s_idx_153_2 = stage_v_100_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000469_11_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = stage_v_112_1 & 3;
  int s_idx_154_2 = stage_v_112_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000469_1_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = stage_v_143_1 & 3;
  int s_idx_155_2 = stage_v_143_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000469_15_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = stage_v_68_1 & 3;
  int s_idx_156_2 = stage_v_68_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000469_18_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = stage_v_70_1 & 3;
  int s_idx_157_2 = stage_v_70_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000469_9_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = stage_v_127_1 & 3;
  int s_idx_158_2 = stage_v_127_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000469_19_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = stage_v_143_1 & 3;
  int s_idx_159_2 = stage_v_143_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000469_9_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = sec_r000469_1_1 & 3;
  int s_idx_160_2 = sec_r000469_1_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000469_10_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = sec_r000469_10_1 & 3;
  int s_idx_161_2 = sec_r000469_10_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000469_1_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_159_1 & 3;
  int s_idx_162_2 = stage_v_159_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000469_12_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_118_1 & 3;
  int s_idx_163_2 = stage_v_118_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000469_11_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_43_1 & 3;
  int s_idx_164_2 = stage_v_43_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000469_14_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = stage_v_100_1 & 3;
  int s_idx_165_2 = stage_v_100_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000469_5_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = stage_v_116_1 & 3;
  int s_idx_166_2 = stage_v_116_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000469_1_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = stage_v_135_1 & 3;
  int s_idx_167_2 = stage_v_135_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000469_0_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = sec_r000469_2_1 & 3;
  int s_idx_168_2 = sec_r000469_2_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000469_2_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = stage_v_138_1 & 3;
  int s_idx_169_2 = stage_v_138_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000469_15_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = stage_v_80_1 & 3;
  int s_idx_170_2 = stage_v_80_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000469_11_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = stage_v_93_1 & 3;
  int s_idx_171_2 = stage_v_93_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000469_18_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = stage_v_105_1 & 3;
  int s_idx_172_2 = stage_v_105_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000469_17_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = stage_v_159_1 & 3;
  int s_idx_173_2 = stage_v_159_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000469_19_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = sec_r000469_17_1 & 3;
  int s_idx_174_2 = sec_r000469_17_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000469_15_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = sec_r000469_16_1 & 3;
  int s_idx_175_2 = sec_r000469_16_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000469_15_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = stage_v_132_1 & 3;
  int s_idx_176_2 = stage_v_132_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000469_9_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = stage_v_96_1 & 3;
  int s_idx_177_2 = stage_v_96_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000469_4_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_60_1 & 3;
  int s_idx_178_2 = stage_v_60_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000469_18_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = sec_r000469_10_1 & 3;
  int s_idx_179_2 = sec_r000469_10_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000469_19_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = stage_v_35_1 & 3;
  int s_idx_180_2 = stage_v_35_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000469_6_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = stage_v_133_1 & 3;
  int s_idx_181_2 = stage_v_133_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000469_12_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = stage_v_130_1 & 3;
  int s_idx_182_2 = stage_v_130_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000469_2_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_93_1 & 3;
  int s_idx_183_2 = stage_v_93_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000469_5_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = sec_r000469_3_1 & 3;
  int s_idx_184_2 = sec_r000469_3_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000469_13_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = sec_r000469_3_1 & 3;
  int s_idx_185_2 = sec_r000469_3_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000469_10_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_67_1 & 3;
  int s_idx_186_2 = stage_v_67_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000469_8_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_71_1 & 3;
  int s_idx_187_2 = stage_v_71_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000469_3_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = stage_v_168_1 & 3;
  int s_idx_188_2 = stage_v_168_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000469_10_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = sec_r000469_13_1 & 3;
  int s_idx_189_2 = sec_r000469_13_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000469_6_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = stage_v_147_1 & 3;
  int s_idx_190_2 = stage_v_147_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000469_6_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = stage_v_72_1 & 3;
  int s_idx_191_2 = stage_v_72_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000469_15_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = sec_r000469_2_1 & 3;
  int s_idx_192_2 = sec_r000469_2_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000469_5_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = stage_v_187_1 & 3;
  int s_idx_193_2 = stage_v_187_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000469_3_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_66_1 & 3;
  int s_idx_194_2 = stage_v_66_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000469_11_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = sec_r000469_5_1 & 3;
  int s_idx_195_2 = sec_r000469_5_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000469_5_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = sec_r000469_11_1 & 3;
  int s_idx_196_2 = sec_r000469_11_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000469_2_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_196_1 & 3;
  int s_idx_197_2 = stage_v_196_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000469_17_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = sec_r000469_15_1 & 3;
  int s_idx_198_2 = sec_r000469_15_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000469_1_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = stage_v_154_1 & 3;
  int s_idx_199_2 = stage_v_154_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000469_3_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_71_1 & 3;
  int s_idx_200_2 = stage_v_71_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000469_18_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = stage_v_114_1 & 3;
  int s_idx_201_2 = stage_v_114_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000469_2_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_173_1 & 3;
  int s_idx_202_2 = stage_v_173_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000469_16_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = sec_r000469_22_1 & 3;
  int s_idx_203_2 = sec_r000469_22_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000469_12_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = stage_v_137_1 & 3;
  int s_idx_204_2 = stage_v_137_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000469_17_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = stage_v_57_1 & 3;
  int s_idx_205_2 = stage_v_57_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000469_7_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000469_7_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = sec_r000469_2_1 & 3;
  int s_idx_206_2 = sec_r000469_2_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000469_18_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = stage_v_100_1 & 3;
  int s_idx_207_2 = stage_v_100_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000469_4_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_61_1 & 3;
  int s_idx_208_2 = stage_v_61_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000469_15_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000469_15_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = stage_v_197_1 & 3;
  int s_idx_209_2 = stage_v_197_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000469_0_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_76_1 & 3;
  int s_idx_210_2 = stage_v_76_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000469_1_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = stage_v_107_1 & 3;
  int s_idx_211_2 = stage_v_107_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000469_11_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = stage_v_28_1 & 3;
  int s_idx_212_2 = stage_v_28_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000469_12_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = stage_v_106_1 & 3;
  int s_idx_213_2 = stage_v_106_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000469_18_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = sec_r000469_16_1 & 3;
  int s_idx_214_2 = sec_r000469_16_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000469_5_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = stage_v_173_1 & 3;
  int s_idx_215_2 = stage_v_173_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000469_8_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = stage_v_104_1 & 3;
  int s_idx_216_2 = stage_v_104_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000469_13_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = stage_v_215_1 & 3;
  int s_idx_217_2 = stage_v_215_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000469_9_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = stage_v_89_1 & 3;
  int s_idx_218_2 = stage_v_89_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000469_4_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = sec_r000469_5_1 & 3;
  int s_idx_219_2 = sec_r000469_5_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000469_16_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = stage_v_181_1 & 3;
  int s_idx_220_2 = stage_v_181_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000469_17_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_144_1 & 3;
  int s_idx_221_2 = stage_v_144_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000469_7_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000469_7_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = stage_v_82_1 & 3;
  int s_idx_222_2 = stage_v_82_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000469_4_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = stage_v_175_1 & 3;
  int s_idx_223_2 = stage_v_175_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000469_0_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = sec_r000469_0_1 & 3;
  int s_idx_224_2 = sec_r000469_0_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000469_12_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = sec_r000469_22_1 & 3;
  int s_idx_225_2 = sec_r000469_22_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000469_18_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = stage_v_185_1 & 3;
  int s_idx_226_2 = stage_v_185_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000469_2_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = stage_v_108_1 & 3;
  int s_idx_227_2 = stage_v_108_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000469_19_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000469_19_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int s_idx_228_1 = stage_v_220_1 & 3;
  int s_idx_228_2 = stage_v_220_2 & 3;
  int stage_v_228_1 = (table_1[s_idx_228_1] + pub_r000469_13_1) & 127;
  int stage_v_228_2 = (table_2[s_idx_228_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_228_1] = (stage_v_228_1 + 7) & 63;
  table_2[s_idx_228_2] = (stage_v_228_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int s_idx_229_1 = stage_v_88_1 & 3;
  int s_idx_229_2 = stage_v_88_2 & 3;
  int stage_v_229_1 = (table_1[s_idx_229_1] + pub_r000469_16_1) & 127;
  int stage_v_229_2 = (table_2[s_idx_229_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_229_1] = (stage_v_229_1 + 7) & 63;
  table_2[s_idx_229_2] = (stage_v_229_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int s_idx_230_1 = sec_r000469_8_1 & 3;
  int s_idx_230_2 = sec_r000469_8_2 & 3;
  int stage_v_230_1 = (table_1[s_idx_230_1] + pub_r000469_14_1) & 127;
  int stage_v_230_2 = (table_2[s_idx_230_2] + pub_r000469_14_2) & 127;
  table_1[s_idx_230_1] = (stage_v_230_1 + 7) & 63;
  table_2[s_idx_230_2] = (stage_v_230_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int s_idx_231_1 = stage_v_158_1 & 3;
  int s_idx_231_2 = stage_v_158_2 & 3;
  int stage_v_231_1 = (table_1[s_idx_231_1] + pub_r000469_11_1) & 127;
  int stage_v_231_2 = (table_2[s_idx_231_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_231_1] = (stage_v_231_1 + 7) & 63;
  table_2[s_idx_231_2] = (stage_v_231_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int s_idx_232_1 = stage_v_107_1 & 3;
  int s_idx_232_2 = stage_v_107_2 & 3;
  int stage_v_232_1 = (table_1[s_idx_232_1] + pub_r000469_5_1) & 127;
  int stage_v_232_2 = (table_2[s_idx_232_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_232_1] = (stage_v_232_1 + 7) & 63;
  table_2[s_idx_232_2] = (stage_v_232_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int s_idx_233_1 = stage_v_202_1 & 3;
  int s_idx_233_2 = stage_v_202_2 & 3;
  int stage_v_233_1 = (table_1[s_idx_233_1] + pub_r000469_2_1) & 127;
  int stage_v_233_2 = (table_2[s_idx_233_2] + pub_r000469_2_2) & 127;
  table_1[s_idx_233_1] = (stage_v_233_1 + 7) & 63;
  table_2[s_idx_233_2] = (stage_v_233_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int s_idx_234_1 = stage_v_158_1 & 3;
  int s_idx_234_2 = stage_v_158_2 & 3;
  int stage_v_234_1 = (table_1[s_idx_234_1] + pub_r000469_10_1) & 127;
  int stage_v_234_2 = (table_2[s_idx_234_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_234_1] = (stage_v_234_1 + 7) & 63;
  table_2[s_idx_234_2] = (stage_v_234_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int s_idx_235_1 = stage_v_110_1 & 3;
  int s_idx_235_2 = stage_v_110_2 & 3;
  int stage_v_235_1 = (table_1[s_idx_235_1] + pub_r000469_10_1) & 127;
  int stage_v_235_2 = (table_2[s_idx_235_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_235_1] = (stage_v_235_1 + 7) & 63;
  table_2[s_idx_235_2] = (stage_v_235_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int s_idx_236_1 = stage_v_148_1 & 3;
  int s_idx_236_2 = stage_v_148_2 & 3;
  int stage_v_236_1 = (table_1[s_idx_236_1] + pub_r000469_10_1) & 127;
  int stage_v_236_2 = (table_2[s_idx_236_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_236_1] = (stage_v_236_1 + 7) & 63;
  table_2[s_idx_236_2] = (stage_v_236_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int s_idx_237_1 = stage_v_105_1 & 3;
  int s_idx_237_2 = stage_v_105_2 & 3;
  int stage_v_237_1 = (table_1[s_idx_237_1] + pub_r000469_5_1) & 127;
  int stage_v_237_2 = (table_2[s_idx_237_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_237_1] = (stage_v_237_1 + 7) & 63;
  table_2[s_idx_237_2] = (stage_v_237_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int s_idx_238_1 = stage_v_158_1 & 3;
  int s_idx_238_2 = stage_v_158_2 & 3;
  int stage_v_238_1 = (table_1[s_idx_238_1] + pub_r000469_8_1) & 127;
  int stage_v_238_2 = (table_2[s_idx_238_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_238_1] = (stage_v_238_1 + 7) & 63;
  table_2[s_idx_238_2] = (stage_v_238_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int s_idx_239_1 = stage_v_97_1 & 3;
  int s_idx_239_2 = stage_v_97_2 & 3;
  int stage_v_239_1 = (table_1[s_idx_239_1] + pub_r000469_9_1) & 127;
  int stage_v_239_2 = (table_2[s_idx_239_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_239_1] = (stage_v_239_1 + 7) & 63;
  table_2[s_idx_239_2] = (stage_v_239_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int s_idx_240_1 = stage_v_129_1 & 3;
  int s_idx_240_2 = stage_v_129_2 & 3;
  int stage_v_240_1 = (table_1[s_idx_240_1] + pub_r000469_9_1) & 127;
  int stage_v_240_2 = (table_2[s_idx_240_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_240_1] = (stage_v_240_1 + 7) & 63;
  table_2[s_idx_240_2] = (stage_v_240_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int s_idx_241_1 = stage_v_164_1 & 3;
  int s_idx_241_2 = stage_v_164_2 & 3;
  int stage_v_241_1 = (table_1[s_idx_241_1] + pub_r000469_6_1) & 127;
  int stage_v_241_2 = (table_2[s_idx_241_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_241_1] = (stage_v_241_1 + 7) & 63;
  table_2[s_idx_241_2] = (stage_v_241_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int s_idx_242_1 = sec_r000469_5_1 & 3;
  int s_idx_242_2 = sec_r000469_5_2 & 3;
  int stage_v_242_1 = (table_1[s_idx_242_1] + pub_r000469_10_1) & 127;
  int stage_v_242_2 = (table_2[s_idx_242_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_242_1] = (stage_v_242_1 + 7) & 63;
  table_2[s_idx_242_2] = (stage_v_242_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int s_idx_243_1 = stage_v_91_1 & 3;
  int s_idx_243_2 = stage_v_91_2 & 3;
  int stage_v_243_1 = (table_1[s_idx_243_1] + pub_r000469_13_1) & 127;
  int stage_v_243_2 = (table_2[s_idx_243_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_243_1] = (stage_v_243_1 + 7) & 63;
  table_2[s_idx_243_2] = (stage_v_243_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int s_idx_244_1 = sec_r000469_12_1 & 3;
  int s_idx_244_2 = sec_r000469_12_2 & 3;
  int stage_v_244_1 = (table_1[s_idx_244_1] + pub_r000469_6_1) & 127;
  int stage_v_244_2 = (table_2[s_idx_244_2] + pub_r000469_6_2) & 127;
  table_1[s_idx_244_1] = (stage_v_244_1 + 7) & 63;
  table_2[s_idx_244_2] = (stage_v_244_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int s_idx_245_1 = sec_r000469_1_1 & 3;
  int s_idx_245_2 = sec_r000469_1_2 & 3;
  int stage_v_245_1 = (table_1[s_idx_245_1] + pub_r000469_4_1) & 127;
  int stage_v_245_2 = (table_2[s_idx_245_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_245_1] = (stage_v_245_1 + 7) & 63;
  table_2[s_idx_245_2] = (stage_v_245_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int s_idx_246_1 = stage_v_215_1 & 3;
  int s_idx_246_2 = stage_v_215_2 & 3;
  int stage_v_246_1 = (table_1[s_idx_246_1] + pub_r000469_3_1) & 127;
  int stage_v_246_2 = (table_2[s_idx_246_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_246_1] = (stage_v_246_1 + 7) & 63;
  table_2[s_idx_246_2] = (stage_v_246_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int s_idx_247_1 = stage_v_111_1 & 3;
  int s_idx_247_2 = stage_v_111_2 & 3;
  int stage_v_247_1 = (table_1[s_idx_247_1] + pub_r000469_11_1) & 127;
  int stage_v_247_2 = (table_2[s_idx_247_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_247_1] = (stage_v_247_1 + 7) & 63;
  table_2[s_idx_247_2] = (stage_v_247_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int s_idx_248_1 = sec_r000469_2_1 & 3;
  int s_idx_248_2 = sec_r000469_2_2 & 3;
  int stage_v_248_1 = (table_1[s_idx_248_1] + pub_r000469_8_1) & 127;
  int stage_v_248_2 = (table_2[s_idx_248_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_248_1] = (stage_v_248_1 + 7) & 63;
  table_2[s_idx_248_2] = (stage_v_248_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int s_idx_249_1 = sec_r000469_21_1 & 3;
  int s_idx_249_2 = sec_r000469_21_2 & 3;
  int stage_v_249_1 = (table_1[s_idx_249_1] + pub_r000469_16_1) & 127;
  int stage_v_249_2 = (table_2[s_idx_249_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_249_1] = (stage_v_249_1 + 7) & 63;
  table_2[s_idx_249_2] = (stage_v_249_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int s_idx_250_1 = stage_v_72_1 & 3;
  int s_idx_250_2 = stage_v_72_2 & 3;
  int stage_v_250_1 = (table_1[s_idx_250_1] + pub_r000469_13_1) & 127;
  int stage_v_250_2 = (table_2[s_idx_250_2] + pub_r000469_13_2) & 127;
  table_1[s_idx_250_1] = (stage_v_250_1 + 7) & 63;
  table_2[s_idx_250_2] = (stage_v_250_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int s_idx_251_1 = stage_v_245_1 & 3;
  int s_idx_251_2 = stage_v_245_2 & 3;
  int stage_v_251_1 = (table_1[s_idx_251_1] + pub_r000469_17_1) & 127;
  int stage_v_251_2 = (table_2[s_idx_251_2] + pub_r000469_17_2) & 127;
  table_1[s_idx_251_1] = (stage_v_251_1 + 7) & 63;
  table_2[s_idx_251_2] = (stage_v_251_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int s_idx_252_1 = stage_v_141_1 & 3;
  int s_idx_252_2 = stage_v_141_2 & 3;
  int stage_v_252_1 = (table_1[s_idx_252_1] + pub_r000469_9_1) & 127;
  int stage_v_252_2 = (table_2[s_idx_252_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_252_1] = (stage_v_252_1 + 7) & 63;
  table_2[s_idx_252_2] = (stage_v_252_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int s_idx_253_1 = stage_v_68_1 & 3;
  int s_idx_253_2 = stage_v_68_2 & 3;
  int stage_v_253_1 = (table_1[s_idx_253_1] + pub_r000469_9_1) & 127;
  int stage_v_253_2 = (table_2[s_idx_253_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_253_1] = (stage_v_253_1 + 7) & 63;
  table_2[s_idx_253_2] = (stage_v_253_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int s_idx_254_1 = stage_v_198_1 & 3;
  int s_idx_254_2 = stage_v_198_2 & 3;
  int stage_v_254_1 = (table_1[s_idx_254_1] + pub_r000469_11_1) & 127;
  int stage_v_254_2 = (table_2[s_idx_254_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_254_1] = (stage_v_254_1 + 7) & 63;
  table_2[s_idx_254_2] = (stage_v_254_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int s_idx_255_1 = sec_r000469_19_1 & 3;
  int s_idx_255_2 = sec_r000469_19_2 & 3;
  int stage_v_255_1 = (table_1[s_idx_255_1] + pub_r000469_11_1) & 127;
  int stage_v_255_2 = (table_2[s_idx_255_2] + pub_r000469_11_2) & 127;
  table_1[s_idx_255_1] = (stage_v_255_1 + 7) & 63;
  table_2[s_idx_255_2] = (stage_v_255_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int s_idx_256_1 = stage_v_161_1 & 3;
  int s_idx_256_2 = stage_v_161_2 & 3;
  int stage_v_256_1 = (table_1[s_idx_256_1] + pub_r000469_5_1) & 127;
  int stage_v_256_2 = (table_2[s_idx_256_2] + pub_r000469_5_2) & 127;
  table_1[s_idx_256_1] = (stage_v_256_1 + 7) & 63;
  table_2[s_idx_256_2] = (stage_v_256_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  int s_idx_257_1 = sec_r000469_0_1 & 3;
  int s_idx_257_2 = sec_r000469_0_2 & 3;
  int stage_v_257_1 = (table_1[s_idx_257_1] + pub_r000469_8_1) & 127;
  int stage_v_257_2 = (table_2[s_idx_257_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_257_1] = (stage_v_257_1 + 7) & 63;
  table_2[s_idx_257_2] = (stage_v_257_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  int s_idx_258_1 = stage_v_53_1 & 3;
  int s_idx_258_2 = stage_v_53_2 & 3;
  int stage_v_258_1 = (table_1[s_idx_258_1] + pub_r000469_16_1) & 127;
  int stage_v_258_2 = (table_2[s_idx_258_2] + pub_r000469_16_2) & 127;
  table_1[s_idx_258_1] = (stage_v_258_1 + 7) & 63;
  table_2[s_idx_258_2] = (stage_v_258_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int s_idx_259_1 = sec_r000469_4_1 & 3;
  int s_idx_259_2 = sec_r000469_4_2 & 3;
  int stage_v_259_1 = (table_1[s_idx_259_1] + pub_r000469_12_1) & 127;
  int stage_v_259_2 = (table_2[s_idx_259_2] + pub_r000469_12_2) & 127;
  table_1[s_idx_259_1] = (stage_v_259_1 + 7) & 63;
  table_2[s_idx_259_2] = (stage_v_259_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int s_idx_260_1 = stage_v_82_1 & 3;
  int s_idx_260_2 = stage_v_82_2 & 3;
  int stage_v_260_1 = (table_1[s_idx_260_1] + pub_r000469_4_1) & 127;
  int stage_v_260_2 = (table_2[s_idx_260_2] + pub_r000469_4_2) & 127;
  table_1[s_idx_260_1] = (stage_v_260_1 + 7) & 63;
  table_2[s_idx_260_2] = (stage_v_260_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  int s_idx_261_1 = sec_r000469_7_1 & 3;
  int s_idx_261_2 = sec_r000469_7_2 & 3;
  int stage_v_261_1 = (table_1[s_idx_261_1] + pub_r000469_18_1) & 127;
  int stage_v_261_2 = (table_2[s_idx_261_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_261_1] = (stage_v_261_1 + 7) & 63;
  table_2[s_idx_261_2] = (stage_v_261_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  int s_idx_262_1 = stage_v_39_1 & 3;
  int s_idx_262_2 = stage_v_39_2 & 3;
  int stage_v_262_1 = (table_1[s_idx_262_1] + pub_r000469_8_1) & 127;
  int stage_v_262_2 = (table_2[s_idx_262_2] + pub_r000469_8_2) & 127;
  table_1[s_idx_262_1] = (stage_v_262_1 + 7) & 63;
  table_2[s_idx_262_2] = (stage_v_262_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int s_idx_263_1 = stage_v_217_1 & 3;
  int s_idx_263_2 = stage_v_217_2 & 3;
  int stage_v_263_1 = (table_1[s_idx_263_1] + pub_r000469_10_1) & 127;
  int stage_v_263_2 = (table_2[s_idx_263_2] + pub_r000469_10_2) & 127;
  table_1[s_idx_263_1] = (stage_v_263_1 + 7) & 63;
  table_2[s_idx_263_2] = (stage_v_263_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int s_idx_264_1 = sec_r000469_8_1 & 3;
  int s_idx_264_2 = sec_r000469_8_2 & 3;
  int stage_v_264_1 = (table_1[s_idx_264_1] + pub_r000469_1_1) & 127;
  int stage_v_264_2 = (table_2[s_idx_264_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_264_1] = (stage_v_264_1 + 7) & 63;
  table_2[s_idx_264_2] = (stage_v_264_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  int s_idx_265_1 = stage_v_251_1 & 3;
  int s_idx_265_2 = stage_v_251_2 & 3;
  int stage_v_265_1 = (table_1[s_idx_265_1] + pub_r000469_0_1) & 127;
  int stage_v_265_2 = (table_2[s_idx_265_2] + pub_r000469_0_2) & 127;
  table_1[s_idx_265_1] = (stage_v_265_1 + 7) & 63;
  table_2[s_idx_265_2] = (stage_v_265_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  int s_idx_266_1 = sec_r000469_8_1 & 3;
  int s_idx_266_2 = sec_r000469_8_2 & 3;
  int stage_v_266_1 = (table_1[s_idx_266_1] + pub_r000469_1_1) & 127;
  int stage_v_266_2 = (table_2[s_idx_266_2] + pub_r000469_1_2) & 127;
  table_1[s_idx_266_1] = (stage_v_266_1 + 7) & 63;
  table_2[s_idx_266_2] = (stage_v_266_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  int s_idx_267_1 = stage_v_264_1 & 3;
  int s_idx_267_2 = stage_v_264_2 & 3;
  int stage_v_267_1 = (table_1[s_idx_267_1] + pub_r000469_18_1) & 127;
  int stage_v_267_2 = (table_2[s_idx_267_2] + pub_r000469_18_2) & 127;
  table_1[s_idx_267_1] = (stage_v_267_1 + 7) & 63;
  table_2[s_idx_267_2] = (stage_v_267_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  int s_idx_268_1 = stage_v_209_1 & 3;
  int s_idx_268_2 = stage_v_209_2 & 3;
  int stage_v_268_1 = (table_1[s_idx_268_1] + pub_r000469_3_1) & 127;
  int stage_v_268_2 = (table_2[s_idx_268_2] + pub_r000469_3_2) & 127;
  table_1[s_idx_268_1] = (stage_v_268_1 + 7) & 63;
  table_2[s_idx_268_2] = (stage_v_268_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  int s_idx_269_1 = stage_v_82_1 & 3;
  int s_idx_269_2 = stage_v_82_2 & 3;
  int stage_v_269_1 = (table_1[s_idx_269_1] + pub_r000469_9_1) & 127;
  int stage_v_269_2 = (table_2[s_idx_269_2] + pub_r000469_9_2) & 127;
  table_1[s_idx_269_1] = (stage_v_269_1 + 7) & 63;
  table_2[s_idx_269_2] = (stage_v_269_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000469_13_1 != sec_r000469_13_2);
  __CPROVER_assume(pub_r000469_7_1 == pub_r000469_7_2);
  __CPROVER_assume(pub_r000469_11_1 == pub_r000469_11_2);
  __CPROVER_assume(pub_r000469_18_1 == pub_r000469_18_2);
  __CPROVER_assume(pub_r000469_1_1 == pub_r000469_1_2);
  __CPROVER_assume(sec_r000469_7_1 != sec_r000469_7_2);
  __CPROVER_assume(sec_r000469_15_1 != sec_r000469_15_2);
  __CPROVER_assume(sec_r000469_1_1 != sec_r000469_1_2);
  __CPROVER_assume(sec_r000469_17_1 != sec_r000469_17_2);
  __CPROVER_assume(sec_r000469_10_1 != sec_r000469_10_2);
  __CPROVER_assume(sec_r000469_12_1 != sec_r000469_12_2);
  __CPROVER_assume(sec_r000469_18_1 != sec_r000469_18_2);
  __CPROVER_assume(pub_r000469_10_1 == pub_r000469_10_2);
  __CPROVER_assume(sec_r000469_19_1 != sec_r000469_19_2);
  __CPROVER_assume(sec_r000469_8_1 != sec_r000469_8_2);
  __CPROVER_assume(sec_r000469_22_1 != sec_r000469_22_2);
  __CPROVER_assume(pub_r000469_3_1 == pub_r000469_3_2);
  __CPROVER_assume(pub_r000469_9_1 == pub_r000469_9_2);
  __CPROVER_assume(sec_r000469_5_1 != sec_r000469_5_2);
  __CPROVER_assume(pub_r000469_2_1 == pub_r000469_2_2);
  __CPROVER_assume(sec_r000469_21_1 != sec_r000469_21_2);
  __CPROVER_assume(sec_r000469_9_1 != sec_r000469_9_2);
  __CPROVER_assume(sec_r000469_11_1 != sec_r000469_11_2);
  __CPROVER_assume(sec_r000469_20_1 != sec_r000469_20_2);
  __CPROVER_assume(pub_r000469_12_1 == pub_r000469_12_2);
  __CPROVER_assume(pub_r000469_14_1 == pub_r000469_14_2);
  __CPROVER_assume(sec_r000469_4_1 != sec_r000469_4_2);
  __CPROVER_assume(pub_r000469_4_1 == pub_r000469_4_2);
  __CPROVER_assume(sec_r000469_3_1 != sec_r000469_3_2);
  __CPROVER_assume(pub_r000469_8_1 == pub_r000469_8_2);
  __CPROVER_assume(pub_r000469_13_1 == pub_r000469_13_2);
  __CPROVER_assume(pub_r000469_17_1 == pub_r000469_17_2);
  __CPROVER_assume(pub_r000469_0_1 == pub_r000469_0_2);
  __CPROVER_assume(pub_r000469_16_1 == pub_r000469_16_2);
  __CPROVER_assume(sec_r000469_16_1 != sec_r000469_16_2);
  __CPROVER_assume(pub_r000469_5_1 == pub_r000469_5_2);
  __CPROVER_assume(sec_r000469_14_1 != sec_r000469_14_2);
  __CPROVER_assume(pub_r000469_19_1 == pub_r000469_19_2);
  __CPROVER_assume(sec_r000469_2_1 != sec_r000469_2_2);
  __CPROVER_assume(pub_r000469_15_1 == pub_r000469_15_2);
  __CPROVER_assume(pub_r000469_6_1 == pub_r000469_6_2);
  __CPROVER_assume(sec_r000469_0_1 != sec_r000469_0_2);
  __CPROVER_assume(sec_r000469_6_1 != sec_r000469_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
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
  assert(s_idx_28_1 == s_idx_28_2);
  assert(stage_v_28_1 == stage_v_28_2);
  assert(s_idx_29_1 == s_idx_29_2);
  assert(stage_v_29_1 == stage_v_29_2);
  assert(s_idx_30_1 == s_idx_30_2);
  assert(stage_v_30_1 == stage_v_30_2);
  assert(s_idx_31_1 == s_idx_31_2);
  assert(stage_v_31_1 == stage_v_31_2);
  assert(s_idx_32_1 == s_idx_32_2);
  assert(stage_v_32_1 == stage_v_32_2);
  assert(s_idx_33_1 == s_idx_33_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(s_idx_34_1 == s_idx_34_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(s_idx_35_1 == s_idx_35_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(s_idx_36_1 == s_idx_36_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(s_idx_37_1 == s_idx_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(s_idx_38_1 == s_idx_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(s_idx_39_1 == s_idx_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(s_idx_40_1 == s_idx_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(s_idx_41_1 == s_idx_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(s_idx_42_1 == s_idx_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(s_idx_43_1 == s_idx_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(s_idx_44_1 == s_idx_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(s_idx_45_1 == s_idx_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(s_idx_215_1 == s_idx_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(s_idx_216_1 == s_idx_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(s_idx_217_1 == s_idx_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(s_idx_218_1 == s_idx_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(s_idx_219_1 == s_idx_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(s_idx_220_1 == s_idx_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(s_idx_221_1 == s_idx_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(s_idx_222_1 == s_idx_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(s_idx_223_1 == s_idx_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(s_idx_224_1 == s_idx_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(s_idx_225_1 == s_idx_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(s_idx_226_1 == s_idx_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(s_idx_227_1 == s_idx_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(s_idx_228_1 == s_idx_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(s_idx_229_1 == s_idx_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(s_idx_230_1 == s_idx_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(s_idx_231_1 == s_idx_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(s_idx_232_1 == s_idx_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(s_idx_233_1 == s_idx_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(s_idx_234_1 == s_idx_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(s_idx_235_1 == s_idx_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(s_idx_236_1 == s_idx_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(s_idx_237_1 == s_idx_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(s_idx_238_1 == s_idx_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(s_idx_239_1 == s_idx_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(s_idx_240_1 == s_idx_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(s_idx_241_1 == s_idx_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(s_idx_242_1 == s_idx_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(s_idx_243_1 == s_idx_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(s_idx_244_1 == s_idx_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(s_idx_245_1 == s_idx_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(s_idx_246_1 == s_idx_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(s_idx_247_1 == s_idx_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(s_idx_248_1 == s_idx_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(s_idx_249_1 == s_idx_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(s_idx_250_1 == s_idx_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(s_idx_251_1 == s_idx_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(s_idx_252_1 == s_idx_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(s_idx_253_1 == s_idx_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(s_idx_254_1 == s_idx_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(s_idx_255_1 == s_idx_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(s_idx_256_1 == s_idx_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(s_idx_257_1 == s_idx_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(s_idx_258_1 == s_idx_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(s_idx_259_1 == s_idx_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(s_idx_260_1 == s_idx_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(s_idx_261_1 == s_idx_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(s_idx_262_1 == s_idx_262_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(s_idx_263_1 == s_idx_263_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(s_idx_264_1 == s_idx_264_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(s_idx_265_1 == s_idx_265_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(s_idx_266_1 == s_idx_266_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(s_idx_267_1 == s_idx_267_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(s_idx_268_1 == s_idx_268_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(s_idx_269_1 == s_idx_269_2);
  assert(stage_v_269_1 == stage_v_269_2);
}


