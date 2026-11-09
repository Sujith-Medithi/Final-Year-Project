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
struct Transaction_R001232_3213_0
{
  int auth_code;
  short rate;
  int balance;
  int status;
  int buffer[3];
};
struct AudioFrame_R001232_3213_1
{
  short peak;
  int envelope;
  unsigned char gain;
  int buffer[3];
};
struct DeviceConfig_R001232_3213_2
{
  int stop_bits;
  int parity;
  unsigned char id;
  short baud_rate;
  int port;
  int buffer[3];
};
union RegisterBank_R001232_3213_0
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
void fn_R001232_3213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int mask_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_57_1 > 40)
  {
    acc_1 = ((acc_1 + (mask_57_1 * 2)) + 5) & 127;
    aux_1 ^= mask_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_57_2 > 40)
  {
    acc_2 = ((acc_2 + (mask_57_2 * 2)) + 5) & 127;
    aux_2 ^= mask_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_41_1 = 0;
  int phase_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_41_1 = ((phase_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_41_2 = ((phase_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_41_1) & 127;
    acc_2 = (acc_2 + phase_41_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_56_1) & 63;
  aux_2 = (aux_2 + segment_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(phase_41_1 == phase_41_2);
  assert(segment_56_1 == segment_56_2);
}

int fn_R001232_3213_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int mask_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_57 > 40)
  {
    acc = ((acc + (mask_57 * 2)) + 5) & 127;
    aux ^= mask_57 & 15;
  }
  else
  {
    acc = ((acc - mask_57) + 11) & 127;
    aux += 3;
  }
  int phase_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_41 = ((phase_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_41) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001232_3213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int phase_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_67_1)
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

  switch (phase_67_2)
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

  int damping_75_1 = 0;
  int damping_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_75_1 = ((damping_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_75_2 = ((damping_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_75_1) & 127;
    acc_2 = (acc_2 + damping_75_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_65_1 = local_arr_1[aux_1 % 3];
  int coefficient_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_65_2 * 2)) & 127;
  int window_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_39_1 > 43)
  {
    acc_1 = ((acc_1 + (window_39_1 * 2)) + 5) & 127;
    aux_1 ^= window_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_39_2 > 43)
  {
    acc_2 = ((acc_2 + (window_39_2 * 2)) + 5) & 127;
    aux_2 ^= window_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_67_1 == phase_67_2);
  assert(damping_75_1 == damping_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(window_39_1 == window_39_2);
}

int fn_R001232_3213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int phase_67 = (aux + st.buffer[1]) & 3;
  switch (phase_67)
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

  int damping_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_75 = ((damping_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_75) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_65 = local_arr[aux % 3];
  acc = (acc + (coefficient_65 * 2)) & 127;
  int window_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_39 > 43)
  {
    acc = ((acc + (window_39 * 2)) + 5) & 127;
    aux ^= window_39 & 15;
  }
  else
  {
    acc = ((acc - window_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001232_3213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001232_3213_1 st_1 = {0};
  struct AudioFrame_R001232_3213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_41_1 = local_arr_1[aux_1 % 3];
  int segment_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_41_2 * 2)) & 127;
  int factor_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_83_1)
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

  switch (factor_83_2)
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

  int index_reg_57_1 = 0;
  int index_reg_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_57_1 = ((index_reg_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_57_2 = ((index_reg_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_57_1) & 127;
    acc_2 = (acc_2 + index_reg_57_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_41_1 == segment_41_2);
  assert(factor_83_1 == factor_83_2);
  assert(index_reg_57_1 == index_reg_57_2);
}

int fn_R001232_3213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001232_3213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int segment_41 = local_arr[aux % 3];
  acc = (acc + (segment_41 * 2)) & 127;
  int factor_83 = (aux + st.buffer[1]) & 3;
  switch (factor_83)
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

  int index_reg_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_57 = ((index_reg_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_57) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001232_3213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
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
  int mask_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_24_1 > 33)
  {
    acc_1 = ((acc_1 + (mask_24_1 * 2)) + 5) & 127;
    aux_1 ^= mask_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_24_2 > 33)
  {
    acc_2 = ((acc_2 + (mask_24_2 * 2)) + 5) & 127;
    aux_2 ^= mask_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_14_1) & 63;
  aux_2 = (aux_2 + window_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_47_1 = 0;
  int anchor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_47_1 = ((anchor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_47_2 = ((anchor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_47_1) & 127;
    acc_2 = (acc_2 + anchor_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_24_1 == mask_24_2);
  assert(window_14_1 == window_14_2);
  assert(anchor_47_1 == anchor_47_2);
}

int fn_R001232_3213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_24 > 33)
  {
    acc = ((acc + (mask_24 * 2)) + 5) & 127;
    aux ^= mask_24 & 15;
  }
  else
  {
    acc = ((acc - mask_24) + 11) & 127;
    aux += 3;
  }
  int window_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_14) & 63;
  acc ^= aux;
  int anchor_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_47 = ((anchor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001232_3213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_81_1) & 63;
  aux_2 = (aux_2 + pivot_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_85_1 = 0;
  int bound_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_85_1 = ((bound_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_85_2 = ((bound_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_85_1) & 127;
    acc_2 = (acc_2 + bound_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_81_1 == pivot_81_2);
  assert(bound_85_1 == bound_85_2);
}

int fn_R001232_3213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_81) & 63;
  acc ^= aux;
  int bound_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_85 = ((bound_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001232_3213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int pivot_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_17_1) & 63;
  aux_2 = (aux_2 + pivot_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_76_1)
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

  switch (parity_76_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_17_1 == pivot_17_2);
  assert(parity_76_1 == parity_76_2);
}

int fn_R001232_3213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int pivot_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_17) & 63;
  acc ^= aux;
  int parity_76 = (aux + st.buffer[1]) & 3;
  switch (parity_76)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001232_3213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int mask_30_1 = 0;
  int mask_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_30_1 = ((mask_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_30_2 = ((mask_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_30_1) & 127;
    acc_2 = (acc_2 + mask_30_2) & 127;
  }

  int phase_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_34_1) & 63;
  aux_2 = (aux_2 + phase_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_92_1)
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

  switch (parity_92_2)
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
  int threshold_87_1 = local_arr_1[aux_1 % 3];
  int threshold_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_30_1 == mask_30_2);
  assert(phase_34_1 == phase_34_2);
  assert(parity_92_1 == parity_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_87_1 == threshold_87_2);
}

int fn_R001232_3213_6(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int mask_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_30 = ((mask_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_30) & 127;
  }

  int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_34) & 63;
  acc ^= aux;
  int parity_92 = (aux + st.buffer[1]) & 3;
  switch (parity_92)
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
  int threshold_87 = local_arr[aux % 3];
  acc = (acc + (threshold_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001232_3213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_12_1)
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

  switch (anchor_12_2)
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

  int cursor_82_1 = 0;
  int cursor_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_82_1 = ((cursor_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_82_2 = ((cursor_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_82_1) & 127;
    acc_2 = (acc_2 + cursor_82_2) & 127;
  }

  int anchor_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_13_1) & 63;
  aux_2 = (aux_2 + anchor_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_37_1 > 29)
  {
    acc_1 = ((acc_1 + (mask_37_1 * 2)) + 5) & 127;
    aux_1 ^= mask_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_37_2 > 29)
  {
    acc_2 = ((acc_2 + (mask_37_2 * 2)) + 5) & 127;
    aux_2 ^= mask_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_12_1 == anchor_12_2);
  assert(cursor_82_1 == cursor_82_2);
  assert(anchor_13_1 == anchor_13_2);
  assert(mask_37_1 == mask_37_2);
}

int fn_R001232_3213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_12 = (aux + st.buffer[1]) & 3;
  switch (anchor_12)
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

  int cursor_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_82 = ((cursor_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_82) & 127;
  }

  int anchor_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_13) & 63;
  acc ^= aux;
  int mask_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_37 > 29)
  {
    acc = ((acc + (mask_37 * 2)) + 5) & 127;
    aux ^= mask_37 & 15;
  }
  else
  {
    acc = ((acc - mask_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001232_3213_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_56_1 > 48)
  {
    acc_1 = ((acc_1 + (metric_56_1 * 2)) + 5) & 127;
    aux_1 ^= metric_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_56_2 > 48)
  {
    acc_2 = ((acc_2 + (metric_56_2 * 2)) + 5) & 127;
    aux_2 ^= metric_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_74_1)
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

  switch (phase_74_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_56_1 == metric_56_2);
  assert(phase_74_1 == phase_74_2);
}

int fn_R001232_3213_8(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_56 > 48)
  {
    acc = ((acc + (metric_56 * 2)) + 5) & 127;
    aux ^= metric_56 & 15;
  }
  else
  {
    acc = ((acc - metric_56) + 11) & 127;
    aux += 3;
  }
  int phase_74 = (aux + st.buffer[1]) & 3;
  switch (phase_74)
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

  return (acc + aux) & 255;
}

void fn_R001232_3213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_10_1 = local_arr_1[aux_1 % 3];
  int checksum_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_10_2 * 2)) & 127;
  int quotient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_62_1)
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

  switch (quotient_62_2)
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

  int checksum_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_44_1) & 63;
  aux_2 = (aux_2 + checksum_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_10_1 == checksum_10_2);
  assert(quotient_62_1 == quotient_62_2);
  assert(checksum_44_1 == checksum_44_2);
}

int fn_R001232_3213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int checksum_10 = local_arr[aux % 3];
  acc = (acc + (checksum_10 * 2)) & 127;
  int quotient_62 = (aux + st.buffer[1]) & 3;
  switch (quotient_62)
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

  int checksum_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001232_3213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int factor_61_1 = 0;
  int factor_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_61_1 = ((factor_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_61_2 = ((factor_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_61_1) & 127;
    acc_2 = (acc_2 + factor_61_2) & 127;
  }

  int metric_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_84_1) & 63;
  aux_2 = (aux_2 + metric_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_46_1 = local_arr_1[aux_1 % 3];
  int margin_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_46_2 * 2)) & 127;
  int factor_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_56_1)
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

  switch (factor_56_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_61_1 == factor_61_2);
  assert(metric_84_1 == metric_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_46_1 == margin_46_2);
  assert(factor_56_1 == factor_56_2);
}

int fn_R001232_3213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int factor_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_61 = ((factor_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_61) & 127;
  }

  int metric_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_46 = local_arr[aux % 3];
  acc = (acc + (margin_46 * 2)) & 127;
  int factor_56 = (aux + st.buffer[1]) & 3;
  switch (factor_56)
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

void fn_R001232_3213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001232_3213_1 st_1 = {0};
  struct AudioFrame_R001232_3213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_22_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_22_1 * 2)) + 5) & 127;
    aux_1 ^= offset_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_22_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_22_2 * 2)) + 5) & 127;
    aux_2 ^= offset_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_55_1) & 63;
  aux_2 = (aux_2 + tracker_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_22_1 == offset_22_2);
  assert(tracker_55_1 == tracker_55_2);
}

int fn_R001232_3213_11(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001232_3213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_22 > 25)
  {
    acc = ((acc + (offset_22 * 2)) + 5) & 127;
    aux ^= offset_22 & 15;
  }
  else
  {
    acc = ((acc - offset_22) + 11) & 127;
    aux += 3;
  }
  int tracker_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001232_3213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_97_1 = 0;
  int segment_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_97_1 = ((segment_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_97_2 = ((segment_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_97_1) & 127;
    acc_2 = (acc_2 + segment_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_97_1 == segment_97_2);
}

int fn_R001232_3213_12(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_97 = ((segment_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001232_3213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_50_1)
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

  switch (parity_50_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_93_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_93_1 * 2)) + 5) & 127;
    aux_1 ^= metric_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_93_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_93_2 * 2)) + 5) & 127;
    aux_2 ^= metric_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_50_1 == parity_50_2);
  assert(metric_93_1 == metric_93_2);
}

int fn_R001232_3213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_50 = (aux + st.buffer[1]) & 3;
  switch (parity_50)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_93 > 31)
  {
    acc = ((acc + (metric_93 * 2)) + 5) & 127;
    aux ^= metric_93 & 15;
  }
  else
  {
    acc = ((acc - metric_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001232_3213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st_1 = {0};
  struct Transaction_R001232_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_10_1 = 0;
  int bound_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_10_1 = ((bound_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_10_2 = ((bound_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_10_1) & 127;
    acc_2 = (acc_2 + bound_10_2) & 127;
  }

  int coefficient_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_45_1) & 63;
  aux_2 = (aux_2 + coefficient_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_78_1 = local_arr_1[aux_1 % 3];
  int cursor_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_10_1 == bound_10_2);
  assert(coefficient_45_1 == coefficient_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_78_1 == cursor_78_2);
}

int fn_R001232_3213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001232_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_10 = ((bound_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_10) & 127;
  }

  int coefficient_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_45) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_78 = local_arr[aux % 3];
  acc = (acc + (cursor_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001232_3213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_99_1)
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

  switch (window_99_2)
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
  int scale_20_1 = local_arr_1[aux_1 % 3];
  int scale_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_20_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_99_1 == window_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_20_1 == scale_20_2);
}

int fn_R001232_3213_15(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001232_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_99 = (aux + st.buffer[1]) & 3;
  switch (window_99)
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
  int scale_20 = local_arr[aux % 3];
  acc = (acc + (scale_20 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001232_0_1;
  int sec_r001232_0_2;
  int sec_r001232_1_1;
  int sec_r001232_1_2;
  int sec_r001232_2_1;
  int sec_r001232_2_2;
  int sec_r001232_3_1;
  int sec_r001232_3_2;
  int sec_r001232_4_1;
  int sec_r001232_4_2;
  int sec_r001232_5_1;
  int sec_r001232_5_2;
  int sec_r001232_6_1;
  int sec_r001232_6_2;
  int sec_r001232_7_1;
  int sec_r001232_7_2;
  int sec_r001232_8_1;
  int sec_r001232_8_2;
  int sec_r001232_9_1;
  int sec_r001232_9_2;
  int sec_r001232_10_1;
  int sec_r001232_10_2;
  int sec_r001232_11_1;
  int sec_r001232_11_2;
  int sec_r001232_12_1;
  int sec_r001232_12_2;
  int sec_r001232_13_1;
  int sec_r001232_13_2;
  int sec_r001232_14_1;
  int sec_r001232_14_2;
  int sec_r001232_15_1;
  int sec_r001232_15_2;
  int sec_r001232_16_1;
  int sec_r001232_16_2;
  int sec_r001232_17_1;
  int sec_r001232_17_2;
  int sec_r001232_18_1;
  int sec_r001232_18_2;
  int sec_r001232_19_1;
  int sec_r001232_19_2;
  int pub_r001232_0_1;
  int pub_r001232_0_2;
  int pub_r001232_1_1;
  int pub_r001232_1_2;
  int pub_r001232_2_1;
  int pub_r001232_2_2;
  int pub_r001232_3_1;
  int pub_r001232_3_2;
  int pub_r001232_4_1;
  int pub_r001232_4_2;
  int pub_r001232_5_1;
  int pub_r001232_5_2;
  int pub_r001232_6_1;
  int pub_r001232_6_2;
  int pub_r001232_7_1;
  int pub_r001232_7_2;
  int pub_r001232_8_1;
  int pub_r001232_8_2;
  int pub_r001232_9_1;
  int pub_r001232_9_2;
  int pub_r001232_10_1;
  int pub_r001232_10_2;
  int pub_r001232_11_1;
  int pub_r001232_11_2;
  int pub_r001232_12_1;
  int pub_r001232_12_2;
  int pub_r001232_13_1;
  int pub_r001232_13_2;
  int pub_r001232_14_1;
  int pub_r001232_14_2;
  int pub_r001232_15_1;
  int pub_r001232_15_2;
  int pub_r001232_16_1;
  int pub_r001232_16_2;
  int pub_r001232_17_1;
  int pub_r001232_17_2;
  int pub_r001232_18_1;
  int pub_r001232_18_2;
  int pub_r001232_19_1;
  int pub_r001232_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001232_0_1 >= (-100)) && (pub_r001232_0_1 <= 100));
  __CPROVER_assume((pub_r001232_0_2 >= (-100)) && (pub_r001232_0_2 <= 100));
  __CPROVER_assume((pub_r001232_1_1 >= (-100)) && (pub_r001232_1_1 <= 100));
  __CPROVER_assume((pub_r001232_1_2 >= (-100)) && (pub_r001232_1_2 <= 100));
  __CPROVER_assume((pub_r001232_2_1 >= (-100)) && (pub_r001232_2_1 <= 100));
  __CPROVER_assume((pub_r001232_2_2 >= (-100)) && (pub_r001232_2_2 <= 100));
  __CPROVER_assume((pub_r001232_3_1 >= (-100)) && (pub_r001232_3_1 <= 100));
  __CPROVER_assume((pub_r001232_3_2 >= (-100)) && (pub_r001232_3_2 <= 100));
  __CPROVER_assume((pub_r001232_4_1 >= (-100)) && (pub_r001232_4_1 <= 100));
  __CPROVER_assume((pub_r001232_4_2 >= (-100)) && (pub_r001232_4_2 <= 100));
  __CPROVER_assume((pub_r001232_5_1 >= (-100)) && (pub_r001232_5_1 <= 100));
  __CPROVER_assume((pub_r001232_5_2 >= (-100)) && (pub_r001232_5_2 <= 100));
  __CPROVER_assume((pub_r001232_6_1 >= (-100)) && (pub_r001232_6_1 <= 100));
  __CPROVER_assume((pub_r001232_6_2 >= (-100)) && (pub_r001232_6_2 <= 100));
  __CPROVER_assume((pub_r001232_7_1 >= (-100)) && (pub_r001232_7_1 <= 100));
  __CPROVER_assume((pub_r001232_7_2 >= (-100)) && (pub_r001232_7_2 <= 100));
  __CPROVER_assume((pub_r001232_8_1 >= (-100)) && (pub_r001232_8_1 <= 100));
  __CPROVER_assume((pub_r001232_8_2 >= (-100)) && (pub_r001232_8_2 <= 100));
  __CPROVER_assume((pub_r001232_9_1 >= (-100)) && (pub_r001232_9_1 <= 100));
  __CPROVER_assume((pub_r001232_9_2 >= (-100)) && (pub_r001232_9_2 <= 100));
  __CPROVER_assume((pub_r001232_10_1 >= (-100)) && (pub_r001232_10_1 <= 100));
  __CPROVER_assume((pub_r001232_10_2 >= (-100)) && (pub_r001232_10_2 <= 100));
  __CPROVER_assume((pub_r001232_11_1 >= (-100)) && (pub_r001232_11_1 <= 100));
  __CPROVER_assume((pub_r001232_11_2 >= (-100)) && (pub_r001232_11_2 <= 100));
  __CPROVER_assume((pub_r001232_12_1 >= (-100)) && (pub_r001232_12_1 <= 100));
  __CPROVER_assume((pub_r001232_12_2 >= (-100)) && (pub_r001232_12_2 <= 100));
  __CPROVER_assume((pub_r001232_13_1 >= (-100)) && (pub_r001232_13_1 <= 100));
  __CPROVER_assume((pub_r001232_13_2 >= (-100)) && (pub_r001232_13_2 <= 100));
  __CPROVER_assume((pub_r001232_14_1 >= (-100)) && (pub_r001232_14_1 <= 100));
  __CPROVER_assume((pub_r001232_14_2 >= (-100)) && (pub_r001232_14_2 <= 100));
  __CPROVER_assume((pub_r001232_15_1 >= (-100)) && (pub_r001232_15_1 <= 100));
  __CPROVER_assume((pub_r001232_15_2 >= (-100)) && (pub_r001232_15_2 <= 100));
  __CPROVER_assume((pub_r001232_16_1 >= (-100)) && (pub_r001232_16_1 <= 100));
  __CPROVER_assume((pub_r001232_16_2 >= (-100)) && (pub_r001232_16_2 <= 100));
  __CPROVER_assume((pub_r001232_17_1 >= (-100)) && (pub_r001232_17_1 <= 100));
  __CPROVER_assume((pub_r001232_17_2 >= (-100)) && (pub_r001232_17_2 <= 100));
  __CPROVER_assume((pub_r001232_18_1 >= (-100)) && (pub_r001232_18_1 <= 100));
  __CPROVER_assume((pub_r001232_18_2 >= (-100)) && (pub_r001232_18_2 <= 100));
  __CPROVER_assume((pub_r001232_19_1 >= (-100)) && (pub_r001232_19_1 <= 100));
  __CPROVER_assume((pub_r001232_19_2 >= (-100)) && (pub_r001232_19_2 <= 100));
  __CPROVER_assume((sec_r001232_0_1 >= 0) && (sec_r001232_0_1 <= 255));
  __CPROVER_assume((sec_r001232_0_2 >= 0) && (sec_r001232_0_2 <= 255));
  __CPROVER_assume((sec_r001232_1_1 >= 0) && (sec_r001232_1_1 <= 255));
  __CPROVER_assume((sec_r001232_1_2 >= 0) && (sec_r001232_1_2 <= 255));
  __CPROVER_assume((sec_r001232_2_1 >= 0) && (sec_r001232_2_1 <= 255));
  __CPROVER_assume((sec_r001232_2_2 >= 0) && (sec_r001232_2_2 <= 255));
  __CPROVER_assume((sec_r001232_3_1 >= 0) && (sec_r001232_3_1 <= 255));
  __CPROVER_assume((sec_r001232_3_2 >= 0) && (sec_r001232_3_2 <= 255));
  __CPROVER_assume((sec_r001232_4_1 >= 0) && (sec_r001232_4_1 <= 255));
  __CPROVER_assume((sec_r001232_4_2 >= 0) && (sec_r001232_4_2 <= 255));
  __CPROVER_assume((sec_r001232_5_1 >= 0) && (sec_r001232_5_1 <= 255));
  __CPROVER_assume((sec_r001232_5_2 >= 0) && (sec_r001232_5_2 <= 255));
  __CPROVER_assume((sec_r001232_6_1 >= 0) && (sec_r001232_6_1 <= 255));
  __CPROVER_assume((sec_r001232_6_2 >= 0) && (sec_r001232_6_2 <= 255));
  __CPROVER_assume((sec_r001232_7_1 >= 0) && (sec_r001232_7_1 <= 255));
  __CPROVER_assume((sec_r001232_7_2 >= 0) && (sec_r001232_7_2 <= 255));
  __CPROVER_assume((sec_r001232_8_1 >= 0) && (sec_r001232_8_1 <= 255));
  __CPROVER_assume((sec_r001232_8_2 >= 0) && (sec_r001232_8_2 <= 255));
  __CPROVER_assume((sec_r001232_9_1 >= 0) && (sec_r001232_9_1 <= 255));
  __CPROVER_assume((sec_r001232_9_2 >= 0) && (sec_r001232_9_2 <= 255));
  __CPROVER_assume((sec_r001232_10_1 >= 0) && (sec_r001232_10_1 <= 255));
  __CPROVER_assume((sec_r001232_10_2 >= 0) && (sec_r001232_10_2 <= 255));
  __CPROVER_assume((sec_r001232_11_1 >= 0) && (sec_r001232_11_1 <= 255));
  __CPROVER_assume((sec_r001232_11_2 >= 0) && (sec_r001232_11_2 <= 255));
  __CPROVER_assume((sec_r001232_12_1 >= 0) && (sec_r001232_12_1 <= 255));
  __CPROVER_assume((sec_r001232_12_2 >= 0) && (sec_r001232_12_2 <= 255));
  __CPROVER_assume((sec_r001232_13_1 >= 0) && (sec_r001232_13_1 <= 255));
  __CPROVER_assume((sec_r001232_13_2 >= 0) && (sec_r001232_13_2 <= 255));
  __CPROVER_assume((sec_r001232_14_1 >= 0) && (sec_r001232_14_1 <= 255));
  __CPROVER_assume((sec_r001232_14_2 >= 0) && (sec_r001232_14_2 <= 255));
  __CPROVER_assume((sec_r001232_15_1 >= 0) && (sec_r001232_15_1 <= 255));
  __CPROVER_assume((sec_r001232_15_2 >= 0) && (sec_r001232_15_2 <= 255));
  __CPROVER_assume((sec_r001232_16_1 >= 0) && (sec_r001232_16_1 <= 255));
  __CPROVER_assume((sec_r001232_16_2 >= 0) && (sec_r001232_16_2 <= 255));
  __CPROVER_assume((sec_r001232_17_1 >= 0) && (sec_r001232_17_1 <= 255));
  __CPROVER_assume((sec_r001232_17_2 >= 0) && (sec_r001232_17_2 <= 255));
  __CPROVER_assume((sec_r001232_18_1 >= 0) && (sec_r001232_18_1 <= 255));
  __CPROVER_assume((sec_r001232_18_2 >= 0) && (sec_r001232_18_2 <= 255));
  __CPROVER_assume((sec_r001232_19_1 >= 0) && (sec_r001232_19_1 <= 255));
  __CPROVER_assume((sec_r001232_19_2 >= 0) && (sec_r001232_19_2 <= 255));
  struct Transaction_R001232_3213_0 st_var_0_1 = {0};
  struct Transaction_R001232_3213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001232_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001232_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001232_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001232_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001232_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001232_0_2 + 7) & 15;
  struct AudioFrame_R001232_3213_1 st_var_1_1 = {0};
  struct AudioFrame_R001232_3213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001232_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001232_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001232_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001232_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001232_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001232_0_2 + 9) & 15;
  struct DeviceConfig_R001232_3213_2 st_var_2_1 = {0};
  struct DeviceConfig_R001232_3213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001232_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001232_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001232_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001232_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001232_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001232_0_2 + 11) & 15;
  union RegisterBank_R001232_3213_0 u_var_1;
  union RegisterBank_R001232_3213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001232_3213_0(sec_r001232_0_1, pub_r001232_1_1, pub_r001232_2_1, pub_r001232_3_1);
  int helper_flow_0_2 = fn_R001232_3213_0(sec_r001232_0_2, pub_r001232_1_2, pub_r001232_2_2, pub_r001232_3_2);
  fn_R001232_3213_0_2(sec_r001232_0_1, pub_r001232_1_1, pub_r001232_2_1, pub_r001232_3_1, sec_r001232_0_2, pub_r001232_1_2, pub_r001232_2_2, pub_r001232_3_2);
  int helper_flow_1_1 = fn_R001232_3213_1(sec_r001232_1_1, pub_r001232_2_1, pub_r001232_3_1);
  int helper_flow_1_2 = fn_R001232_3213_1(sec_r001232_1_2, pub_r001232_2_2, pub_r001232_3_2);
  fn_R001232_3213_1_2(sec_r001232_1_1, pub_r001232_2_1, pub_r001232_3_1, sec_r001232_1_2, pub_r001232_2_2, pub_r001232_3_2);
  int helper_flow_2_1 = fn_R001232_3213_2(sec_r001232_2_1, sec_r001232_3_1, pub_r001232_4_1);
  int helper_flow_2_2 = fn_R001232_3213_2(sec_r001232_2_2, sec_r001232_3_2, pub_r001232_4_2);
  fn_R001232_3213_2_2(sec_r001232_2_1, sec_r001232_3_1, pub_r001232_4_1, sec_r001232_2_2, sec_r001232_3_2, pub_r001232_4_2);
  int helper_flow_3_1 = fn_R001232_3213_3(sec_r001232_3_1, sec_r001232_4_1, pub_r001232_5_1, pub_r001232_6_1);
  int helper_flow_3_2 = fn_R001232_3213_3(sec_r001232_3_2, sec_r001232_4_2, pub_r001232_5_2, pub_r001232_6_2);
  fn_R001232_3213_3_2(sec_r001232_3_1, sec_r001232_4_1, pub_r001232_5_1, pub_r001232_6_1, sec_r001232_3_2, sec_r001232_4_2, pub_r001232_5_2, pub_r001232_6_2);
  int helper_flow_4_1 = fn_R001232_3213_4(sec_r001232_4_1, pub_r001232_5_1, pub_r001232_6_1, pub_r001232_7_1, pub_r001232_8_1);
  int helper_flow_4_2 = fn_R001232_3213_4(sec_r001232_4_2, pub_r001232_5_2, pub_r001232_6_2, pub_r001232_7_2, pub_r001232_8_2);
  fn_R001232_3213_4_2(sec_r001232_4_1, pub_r001232_5_1, pub_r001232_6_1, pub_r001232_7_1, pub_r001232_8_1, sec_r001232_4_2, pub_r001232_5_2, pub_r001232_6_2, pub_r001232_7_2, pub_r001232_8_2);
  int helper_flow_5_1 = fn_R001232_3213_5(sec_r001232_5_1, pub_r001232_6_1, pub_r001232_7_1);
  int helper_flow_5_2 = fn_R001232_3213_5(sec_r001232_5_2, pub_r001232_6_2, pub_r001232_7_2);
  fn_R001232_3213_5_2(sec_r001232_5_1, pub_r001232_6_1, pub_r001232_7_1, sec_r001232_5_2, pub_r001232_6_2, pub_r001232_7_2);
  int stage_v_0_1 = ((pub_r001232_10_1 * 2) + 17) & 63;
  int stage_v_0_2 = ((pub_r001232_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001232_13_1 * 2) + 29) & 63;
  int stage_v_1_2 = ((pub_r001232_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001232_1_1 * 2) + 22) & 63;
  int stage_v_2_2 = ((pub_r001232_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001232_8_1 * 3) + pub_r001232_10_1) + 22) & 127;
  int stage_v_3_2 = (((sec_r001232_8_2 * 3) + pub_r001232_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001232_8_1 * 3) + pub_r001232_6_1) + 29) & 127;
  int stage_v_4_2 = (((sec_r001232_8_2 * 3) + pub_r001232_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((helper_flow_1_1 * 3) + pub_r001232_13_1) + 19) & 127;
  int stage_v_5_2 = (((helper_flow_1_2 * 3) + pub_r001232_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((stage_v_5_1 * 3) + pub_r001232_16_1) + 39) & 127;
  int stage_v_6_2 = (((stage_v_5_2 * 3) + pub_r001232_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001232_8_1 * 2) + 24) & 63;
  int stage_v_7_2 = ((pub_r001232_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001232_7_1 * 2) + 36) & 63;
  int stage_v_8_2 = ((pub_r001232_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001232_10_1 * 2) + 41) & 63;
  int stage_v_9_2 = ((pub_r001232_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001232_2_1 * 2) + 11) & 63;
  int stage_v_10_2 = ((pub_r001232_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001232_9_1 * 3) + pub_r001232_1_1) + 12) & 127;
  int stage_v_11_2 = (((sec_r001232_9_2 * 3) + pub_r001232_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001232_1_1 * 3) + pub_r001232_3_1) + 4) & 127;
  int stage_v_12_2 = (((sec_r001232_1_2 * 3) + pub_r001232_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001232_16_1 * 2) + 37) & 63;
  int stage_v_13_2 = ((pub_r001232_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001232_14_1 * 2) + 28) & 63;
  int stage_v_14_2 = ((pub_r001232_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001232_0_1 * 2) + 5) & 63;
  int stage_v_15_2 = ((pub_r001232_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001232_3_1 * 2) + 49) & 63;
  int stage_v_16_2 = ((pub_r001232_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001232_16_1 * 2) + 27) & 63;
  int stage_v_17_2 = ((pub_r001232_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001232_6_1 * 2) + 7) & 63;
  int stage_v_18_2 = ((pub_r001232_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001232_2_1 * 3) + pub_r001232_8_1) + 33) & 127;
  int stage_v_19_2 = (((sec_r001232_2_2 * 3) + pub_r001232_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001232_15_1 * 3) + pub_r001232_18_1) + 3) & 127;
  int stage_v_20_2 = (((sec_r001232_15_2 * 3) + pub_r001232_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001232_4_1 * 2) + 29) & 63;
  int stage_v_21_2 = ((pub_r001232_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001232_5_1 * 2) + 11) & 63;
  int stage_v_22_2 = ((pub_r001232_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001232_6_1 * 2) + 20) & 63;
  int stage_v_23_2 = ((pub_r001232_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001232_18_1 * 3) + pub_r001232_9_1) + 22) & 127;
  int stage_v_24_2 = (((sec_r001232_18_2 * 3) + pub_r001232_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((stage_v_12_1 * 3) + pub_r001232_2_1) + 9) & 127;
  int stage_v_25_2 = (((stage_v_12_2 * 3) + pub_r001232_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001232_12_1 * 3) + pub_r001232_7_1) + 32) & 127;
  int stage_v_26_2 = (((sec_r001232_12_2 * 3) + pub_r001232_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((sec_r001232_19_1 * 3) + pub_r001232_7_1) + 44) & 127;
  int stage_v_27_2 = (((sec_r001232_19_2 * 3) + pub_r001232_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((sec_r001232_15_1 * 3) + pub_r001232_11_1) + 21) & 127;
  int stage_v_28_2 = (((sec_r001232_15_2 * 3) + pub_r001232_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((stage_v_27_1 * 3) + pub_r001232_18_1) + 22) & 127;
  int stage_v_29_2 = (((stage_v_27_2 * 3) + pub_r001232_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((helper_flow_3_1 * 3) + pub_r001232_0_1) + 11) & 127;
  int stage_v_30_2 = (((helper_flow_3_2 * 3) + pub_r001232_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001232_0_1 * 3) + pub_r001232_4_1) + 14) & 127;
  int stage_v_31_2 = (((sec_r001232_0_2 * 3) + pub_r001232_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((helper_flow_3_1 * 3) + pub_r001232_10_1) + 30) & 127;
  int stage_v_32_2 = (((helper_flow_3_2 * 3) + pub_r001232_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001232_18_1 * 2) + 22) & 63;
  int stage_v_33_2 = ((pub_r001232_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001232_16_1 * 2) + 27) & 63;
  int stage_v_34_2 = ((pub_r001232_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001232_2_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001232_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001232_19_1 * 2) + 47) & 63;
  int stage_v_36_2 = ((pub_r001232_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001232_19_1 * 2) + 31) & 63;
  int stage_v_37_2 = ((pub_r001232_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001232_15_1 * 2) + 29) & 63;
  int stage_v_38_2 = ((pub_r001232_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001232_12_1 * 2) + 30) & 63;
  int stage_v_39_2 = ((pub_r001232_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_6_1 * 3) + pub_r001232_15_1) + 25) & 127;
  int stage_v_40_2 = (((stage_v_6_2 * 3) + pub_r001232_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001232_7_1 * 2) + 13) & 63;
  int stage_v_41_2 = ((pub_r001232_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001232_18_1 * 2) + 27) & 63;
  int stage_v_42_2 = ((pub_r001232_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001232_17_1 * 2) + 8) & 63;
  int stage_v_43_2 = ((pub_r001232_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001232_0_1 * 2) + 46) & 63;
  int stage_v_44_2 = ((pub_r001232_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001232_12_1 * 2) + 37) & 63;
  int stage_v_45_2 = ((pub_r001232_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001232_15_1 * 2) + 12) & 63;
  int stage_v_46_2 = ((pub_r001232_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001232_12_1 * 3) + pub_r001232_7_1) + 45) & 127;
  int stage_v_47_2 = (((sec_r001232_12_2 * 3) + pub_r001232_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001232_10_1 * 2) + 45) & 63;
  int stage_v_48_2 = ((pub_r001232_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_25_1 * 3) + pub_r001232_11_1) + 29) & 127;
  int stage_v_49_2 = (((stage_v_25_2 * 3) + pub_r001232_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_29_1 * 3) + pub_r001232_2_1) + 14) & 127;
  int stage_v_50_2 = (((stage_v_29_2 * 3) + pub_r001232_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001232_16_1 * 2) + 10) & 63;
  int stage_v_51_2 = ((pub_r001232_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001232_15_1 * 2) + 33) & 63;
  int stage_v_52_2 = ((pub_r001232_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001232_3_1 * 2) + 22) & 63;
  int stage_v_53_2 = ((pub_r001232_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((helper_flow_0_1 * 3) + pub_r001232_0_1) + 14) & 127;
  int stage_v_54_2 = (((helper_flow_0_2 * 3) + pub_r001232_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001232_12_1 * 2) + 44) & 63;
  int stage_v_55_2 = ((pub_r001232_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_47_1 * 3) + pub_r001232_1_1) + 10) & 127;
  int stage_v_56_2 = (((stage_v_47_2 * 3) + pub_r001232_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001232_10_1 * 2) + 26) & 63;
  int stage_v_57_2 = ((pub_r001232_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001232_11_1 * 2) + 11) & 63;
  int stage_v_58_2 = ((pub_r001232_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_56_1 * 3) + pub_r001232_10_1) + 33) & 127;
  int stage_v_59_2 = (((stage_v_56_2 * 3) + pub_r001232_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001232_15_1 * 2) + 13) & 63;
  int stage_v_60_2 = ((pub_r001232_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001232_1_1 * 3) + pub_r001232_3_1) + 23) & 127;
  int stage_v_61_2 = (((sec_r001232_1_2 * 3) + pub_r001232_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001232_19_1 * 2) + 12) & 63;
  int stage_v_62_2 = ((pub_r001232_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((helper_flow_0_1 * 3) + pub_r001232_17_1) + 20) & 127;
  int stage_v_63_2 = (((helper_flow_0_2 * 3) + pub_r001232_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001232_4_1 * 3) + pub_r001232_15_1) + 33) & 127;
  int stage_v_64_2 = (((sec_r001232_4_2 * 3) + pub_r001232_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((helper_flow_5_1 * 3) + pub_r001232_9_1) + 42) & 127;
  int stage_v_65_2 = (((helper_flow_5_2 * 3) + pub_r001232_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001232_10_1 * 2) + 32) & 63;
  int stage_v_66_2 = ((pub_r001232_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001232_5_1 * 2) + 31) & 63;
  int stage_v_67_2 = ((pub_r001232_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001232_4_1 * 2) + 30) & 63;
  int stage_v_68_2 = ((pub_r001232_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001232_15_1 * 2) + 22) & 63;
  int stage_v_69_2 = ((pub_r001232_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001232_2_1 * 2) + 23) & 63;
  int stage_v_70_2 = ((pub_r001232_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001232_11_1 * 2) + 33) & 63;
  int stage_v_71_2 = ((pub_r001232_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001232_4_1 * 2) + 16) & 63;
  int stage_v_72_2 = ((pub_r001232_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_20_1 * 3) + pub_r001232_3_1) + 8) & 127;
  int stage_v_73_2 = (((stage_v_20_2 * 3) + pub_r001232_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001232_7_1 * 2) + 22) & 63;
  int stage_v_74_2 = ((pub_r001232_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001232_17_1 * 2) + 45) & 63;
  int stage_v_75_2 = ((pub_r001232_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001232_11_1 * 2) + 15) & 63;
  int stage_v_76_2 = ((pub_r001232_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001232_8_1 * 2) + 26) & 63;
  int stage_v_77_2 = ((pub_r001232_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001232_17_1 * 2) + 46) & 63;
  int stage_v_78_2 = ((pub_r001232_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001232_17_1 * 2) + 19) & 63;
  int stage_v_79_2 = ((pub_r001232_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001232_4_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001232_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001232_8_1 * 2) + 20) & 63;
  int stage_v_81_2 = ((pub_r001232_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001232_18_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001232_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001232_10_1 * 2) + 39) & 63;
  int stage_v_83_2 = ((pub_r001232_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_26_1 * 3) + pub_r001232_11_1) + 12) & 127;
  int stage_v_84_2 = (((stage_v_26_2 * 3) + pub_r001232_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001232_18_1 * 2) + 17) & 63;
  int stage_v_85_2 = ((pub_r001232_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((sec_r001232_2_1 * 3) + pub_r001232_16_1) + 30) & 127;
  int stage_v_86_2 = (((sec_r001232_2_2 * 3) + pub_r001232_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001232_11_1 * 2) + 42) & 63;
  int stage_v_87_2 = ((pub_r001232_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001232_16_1 * 2) + 8) & 63;
  int stage_v_88_2 = ((pub_r001232_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001232_6_1 * 2) + 45) & 63;
  int stage_v_89_2 = ((pub_r001232_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001232_14_1 * 2) + 11) & 63;
  int stage_v_90_2 = ((pub_r001232_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_3_1 * 3) + pub_r001232_3_1) + 41) & 127;
  int stage_v_91_2 = (((stage_v_3_2 * 3) + pub_r001232_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_49_1 * 3) + pub_r001232_1_1) + 18) & 127;
  int stage_v_92_2 = (((stage_v_49_2 * 3) + pub_r001232_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((sec_r001232_11_1 * 3) + pub_r001232_1_1) + 40) & 127;
  int stage_v_93_2 = (((sec_r001232_11_2 * 3) + pub_r001232_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001232_6_1 * 2) + 11) & 63;
  int stage_v_94_2 = ((pub_r001232_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001232_0_1 * 2) + 34) & 63;
  int stage_v_95_2 = ((pub_r001232_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001232_17_1 * 2) + 11) & 63;
  int stage_v_96_2 = ((pub_r001232_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001232_13_1 * 2) + 36) & 63;
  int stage_v_97_2 = ((pub_r001232_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001232_5_1 * 2) + 30) & 63;
  int stage_v_98_2 = ((pub_r001232_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001232_6_1 * 2) + 50) & 63;
  int stage_v_99_2 = ((pub_r001232_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001232_15_1 * 2) + 47) & 63;
  int stage_v_100_2 = ((pub_r001232_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001232_12_1 * 2) + 7) & 63;
  int stage_v_101_2 = ((pub_r001232_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_3_1 * 3) + pub_r001232_4_1) + 16) & 127;
  int stage_v_102_2 = (((stage_v_3_2 * 3) + pub_r001232_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001232_1_1 * 2) + 29) & 63;
  int stage_v_103_2 = ((pub_r001232_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001232_9_1 * 2) + 42) & 63;
  int stage_v_104_2 = ((pub_r001232_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001232_0_1 * 2) + 41) & 63;
  int stage_v_105_2 = ((pub_r001232_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001232_6_1 * 2) + 18) & 63;
  int stage_v_106_2 = ((pub_r001232_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_65_1 * 3) + pub_r001232_3_1) + 13) & 127;
  int stage_v_107_2 = (((stage_v_65_2 * 3) + pub_r001232_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001232_14_1 * 2) + 11) & 63;
  int stage_v_108_2 = ((pub_r001232_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_3_1 * 3) + pub_r001232_18_1) + 26) & 127;
  int stage_v_109_2 = (((stage_v_3_2 * 3) + pub_r001232_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001232_3_1 * 2) + 32) & 63;
  int stage_v_110_2 = ((pub_r001232_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001232_18_1 * 2) + 14) & 63;
  int stage_v_111_2 = ((pub_r001232_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001232_0_1 * 2) + 38) & 63;
  int stage_v_112_2 = ((pub_r001232_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001232_5_1 * 2) + 42) & 63;
  int stage_v_113_2 = ((pub_r001232_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001232_18_1 * 2) + 14) & 63;
  int stage_v_114_2 = ((pub_r001232_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001232_3_1 * 2) + 7) & 63;
  int stage_v_115_2 = ((pub_r001232_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001232_12_1 * 2) + 17) & 63;
  int stage_v_116_2 = ((pub_r001232_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001232_13_1 * 2) + 8) & 63;
  int stage_v_117_2 = ((pub_r001232_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001232_19_1 * 2) + 35) & 63;
  int stage_v_118_2 = ((pub_r001232_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_93_1 * 3) + pub_r001232_18_1) + 5) & 127;
  int stage_v_119_2 = (((stage_v_93_2 * 3) + pub_r001232_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001232_8_1 * 3) + pub_r001232_7_1) + 45) & 127;
  int stage_v_120_2 = (((sec_r001232_8_2 * 3) + pub_r001232_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_19_1 * 3) + pub_r001232_19_1) + 45) & 127;
  int stage_v_121_2 = (((stage_v_19_2 * 3) + pub_r001232_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_61_1 * 3) + pub_r001232_4_1) + 3) & 127;
  int stage_v_122_2 = (((stage_v_61_2 * 3) + pub_r001232_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001232_10_1 * 2) + 41) & 63;
  int stage_v_123_2 = ((pub_r001232_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_19_1 * 3) + pub_r001232_16_1) + 25) & 127;
  int stage_v_124_2 = (((stage_v_19_2 * 3) + pub_r001232_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001232_19_1 * 2) + 36) & 63;
  int stage_v_125_2 = ((pub_r001232_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001232_13_1 * 3) + pub_r001232_14_1) + 9) & 127;
  int stage_v_126_2 = (((sec_r001232_13_2 * 3) + pub_r001232_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_5_1 * 3) + pub_r001232_5_1) + 34) & 127;
  int stage_v_127_2 = (((stage_v_5_2 * 3) + pub_r001232_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001232_1_1 * 2) + 36) & 63;
  int stage_v_128_2 = ((pub_r001232_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001232_11_1 * 2) + 10) & 63;
  int stage_v_129_2 = ((pub_r001232_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001232_3_1 * 2) + 14) & 63;
  int stage_v_130_2 = ((pub_r001232_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001232_16_1 * 2) + 19) & 63;
  int stage_v_131_2 = ((pub_r001232_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001232_5_1 * 3) + pub_r001232_3_1) + 24) & 127;
  int stage_v_132_2 = (((sec_r001232_5_2 * 3) + pub_r001232_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((sec_r001232_17_1 * 3) + pub_r001232_19_1) + 34) & 127;
  int stage_v_133_2 = (((sec_r001232_17_2 * 3) + pub_r001232_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_119_1 * 3) + pub_r001232_16_1) + 29) & 127;
  int stage_v_134_2 = (((stage_v_119_2 * 3) + pub_r001232_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_121_1 * 3) + pub_r001232_18_1) + 41) & 127;
  int stage_v_135_2 = (((stage_v_121_2 * 3) + pub_r001232_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((sec_r001232_18_1 * 3) + pub_r001232_13_1) + 30) & 127;
  int stage_v_136_2 = (((sec_r001232_18_2 * 3) + pub_r001232_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001232_5_1 * 2) + 30) & 63;
  int stage_v_137_2 = ((pub_r001232_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001232_3_1 * 2) + 45) & 63;
  int stage_v_138_2 = ((pub_r001232_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001232_10_1 * 2) + 26) & 63;
  int stage_v_139_2 = ((pub_r001232_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001232_18_1 * 2) + 13) & 63;
  int stage_v_140_2 = ((pub_r001232_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((helper_flow_1_1 * 3) + pub_r001232_2_1) + 16) & 127;
  int stage_v_141_2 = (((helper_flow_1_2 * 3) + pub_r001232_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001232_15_1 * 2) + 32) & 63;
  int stage_v_142_2 = ((pub_r001232_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001232_2_1 * 2) + 36) & 63;
  int stage_v_143_2 = ((pub_r001232_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001232_2_1 * 2) + 28) & 63;
  int stage_v_144_2 = ((pub_r001232_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001232_0_1 * 2) + 33) & 63;
  int stage_v_145_2 = ((pub_r001232_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001232_3_1 * 2) + 6) & 63;
  int stage_v_146_2 = ((pub_r001232_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001232_0_1 * 2) + 31) & 63;
  int stage_v_147_2 = ((pub_r001232_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001232_2_1 * 2) + 34) & 63;
  int stage_v_148_2 = ((pub_r001232_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001232_7_1 * 2) + 24) & 63;
  int stage_v_149_2 = ((pub_r001232_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_91_1 * 3) + pub_r001232_15_1) + 18) & 127;
  int stage_v_150_2 = (((stage_v_91_2 * 3) + pub_r001232_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001232_9_1 * 2) + 38) & 63;
  int stage_v_151_2 = ((pub_r001232_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_121_1 * 3) + pub_r001232_11_1) + 11) & 127;
  int stage_v_152_2 = (((stage_v_121_2 * 3) + pub_r001232_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((sec_r001232_3_1 * 3) + pub_r001232_4_1) + 15) & 127;
  int stage_v_153_2 = (((sec_r001232_3_2 * 3) + pub_r001232_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_122_1 * 3) + pub_r001232_19_1) + 15) & 127;
  int stage_v_154_2 = (((stage_v_122_2 * 3) + pub_r001232_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001232_3_1 * 2) + 9) & 63;
  int stage_v_155_2 = ((pub_r001232_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001232_14_1 * 2) + 22) & 63;
  int stage_v_156_2 = ((pub_r001232_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001232_0_1 * 2) + 8) & 63;
  int stage_v_157_2 = ((pub_r001232_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001232_9_1 * 2) + 31) & 63;
  int stage_v_158_2 = ((pub_r001232_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001232_8_1 * 2) + 28) & 63;
  int stage_v_159_2 = ((pub_r001232_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001232_3_1 * 2) + 48) & 63;
  int stage_v_160_2 = ((pub_r001232_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001232_2_1 * 2) + 39) & 63;
  int stage_v_161_2 = ((pub_r001232_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_135_1 * 3) + pub_r001232_16_1) + 12) & 127;
  int stage_v_162_2 = (((stage_v_135_2 * 3) + pub_r001232_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_152_1 * 3) + pub_r001232_3_1) + 17) & 127;
  int stage_v_163_2 = (((stage_v_152_2 * 3) + pub_r001232_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_11_1 * 3) + pub_r001232_17_1) + 24) & 127;
  int stage_v_164_2 = (((stage_v_11_2 * 3) + pub_r001232_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_11_1 * 3) + pub_r001232_4_1) + 25) & 127;
  int stage_v_165_2 = (((stage_v_11_2 * 3) + pub_r001232_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((helper_flow_2_1 * 3) + pub_r001232_13_1) + 33) & 127;
  int stage_v_166_2 = (((helper_flow_2_2 * 3) + pub_r001232_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001232_11_1 * 2) + 36) & 63;
  int stage_v_167_2 = ((pub_r001232_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_61_1 * 3) + pub_r001232_7_1) + 35) & 127;
  int stage_v_168_2 = (((stage_v_61_2 * 3) + pub_r001232_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((sec_r001232_4_1 * 3) + pub_r001232_8_1) + 27) & 127;
  int stage_v_169_2 = (((sec_r001232_4_2 * 3) + pub_r001232_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_29_1 * 3) + pub_r001232_16_1) + 18) & 127;
  int stage_v_170_2 = (((stage_v_29_2 * 3) + pub_r001232_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((sec_r001232_16_1 * 3) + pub_r001232_12_1) + 31) & 127;
  int stage_v_171_2 = (((sec_r001232_16_2 * 3) + pub_r001232_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001232_19_1 * 2) + 15) & 63;
  int stage_v_172_2 = ((pub_r001232_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((sec_r001232_16_1 * 3) + pub_r001232_1_1) + 35) & 127;
  int stage_v_173_2 = (((sec_r001232_16_2 * 3) + pub_r001232_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001232_2_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001232_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001232_3_1 * 2) + 35) & 63;
  int stage_v_175_2 = ((pub_r001232_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001232_10_1 * 2) + 45) & 63;
  int stage_v_176_2 = ((pub_r001232_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001232_3_1 * 2) + 30) & 63;
  int stage_v_177_2 = ((pub_r001232_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_107_1 * 3) + pub_r001232_3_1) + 7) & 127;
  int stage_v_178_2 = (((stage_v_107_2 * 3) + pub_r001232_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001232_19_1 * 2) + 42) & 63;
  int stage_v_179_2 = ((pub_r001232_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001232_18_1 * 2) + 26) & 63;
  int stage_v_180_2 = ((pub_r001232_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_61_1 * 3) + pub_r001232_15_1) + 28) & 127;
  int stage_v_181_2 = (((stage_v_61_2 * 3) + pub_r001232_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001232_17_1 * 2) + 48) & 63;
  int stage_v_182_2 = ((pub_r001232_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001232_0_1 * 2) + 22) & 63;
  int stage_v_183_2 = ((pub_r001232_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001232_17_1 * 2) + 29) & 63;
  int stage_v_184_2 = ((pub_r001232_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_120_1 * 3) + pub_r001232_16_1) + 40) & 127;
  int stage_v_185_2 = (((stage_v_120_2 * 3) + pub_r001232_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001232_8_1 * 2) + 25) & 63;
  int stage_v_186_2 = ((pub_r001232_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((helper_flow_3_1 * 3) + pub_r001232_14_1) + 39) & 127;
  int stage_v_187_2 = (((helper_flow_3_2 * 3) + pub_r001232_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001232_4_1 * 2) + 14) & 63;
  int stage_v_188_2 = ((pub_r001232_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_171_1 * 3) + pub_r001232_18_1) + 35) & 127;
  int stage_v_189_2 = (((stage_v_171_2 * 3) + pub_r001232_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001232_6_1 * 2) + 42) & 63;
  int stage_v_190_2 = ((pub_r001232_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_54_1 * 3) + pub_r001232_2_1) + 9) & 127;
  int stage_v_191_2 = (((stage_v_54_2 * 3) + pub_r001232_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001232_13_1 * 2) + 31) & 63;
  int stage_v_192_2 = ((pub_r001232_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_132_1 * 3) + pub_r001232_19_1) + 17) & 127;
  int stage_v_193_2 = (((stage_v_132_2 * 3) + pub_r001232_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_93_1 * 3) + pub_r001232_0_1) + 37) & 127;
  int stage_v_194_2 = (((stage_v_93_2 * 3) + pub_r001232_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001232_14_1 * 2) + 27) & 63;
  int stage_v_195_2 = ((pub_r001232_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((helper_flow_5_1 * 3) + pub_r001232_2_1) + 34) & 127;
  int stage_v_196_2 = (((helper_flow_5_2 * 3) + pub_r001232_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001232_17_1 * 2) + 23) & 63;
  int stage_v_197_2 = ((pub_r001232_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001232_13_1 * 2) + 42) & 63;
  int stage_v_198_2 = ((pub_r001232_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_6_1 * 3) + pub_r001232_6_1) + 16) & 127;
  int stage_v_199_2 = (((stage_v_6_2 * 3) + pub_r001232_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001232_2_1 * 2) + 20) & 63;
  int stage_v_200_2 = ((pub_r001232_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_24_1 * 3) + pub_r001232_7_1) + 7) & 127;
  int stage_v_201_2 = (((stage_v_24_2 * 3) + pub_r001232_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001232_8_1 * 2) + 41) & 63;
  int stage_v_202_2 = ((pub_r001232_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001232_18_1 * 2) + 12) & 63;
  int stage_v_203_2 = ((pub_r001232_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001232_11_1 * 2) + 13) & 63;
  int stage_v_204_2 = ((pub_r001232_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_163_1 * 3) + pub_r001232_10_1) + 3) & 127;
  int stage_v_205_2 = (((stage_v_163_2 * 3) + pub_r001232_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_127_1 * 3) + pub_r001232_13_1) + 42) & 127;
  int stage_v_206_2 = (((stage_v_127_2 * 3) + pub_r001232_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001232_12_1 * 2) + 11) & 63;
  int stage_v_207_2 = ((pub_r001232_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001232_16_1 * 2) + 11) & 63;
  int stage_v_208_2 = ((pub_r001232_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001232_5_1 * 2) + 31) & 63;
  int stage_v_209_2 = ((pub_r001232_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_64_1 * 3) + pub_r001232_3_1) + 45) & 127;
  int stage_v_210_2 = (((stage_v_64_2 * 3) + pub_r001232_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_6_1 * 3) + pub_r001232_1_1) + 6) & 127;
  int stage_v_211_2 = (((stage_v_6_2 * 3) + pub_r001232_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_166_1 * 3) + pub_r001232_5_1) + 39) & 127;
  int stage_v_212_2 = (((stage_v_166_2 * 3) + pub_r001232_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001232_5_1 * 2) + 40) & 63;
  int stage_v_213_2 = ((pub_r001232_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001232_2_1 * 2) + 8) & 63;
  int stage_v_214_2 = ((pub_r001232_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_124_1 * 3) + pub_r001232_12_1) + 16) & 127;
  int stage_v_215_2 = (((stage_v_124_2 * 3) + pub_r001232_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((sec_r001232_13_1 * 3) + pub_r001232_19_1) + 39) & 127;
  int stage_v_216_2 = (((sec_r001232_13_2 * 3) + pub_r001232_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001232_15_1 * 2) + 38) & 63;
  int stage_v_217_2 = ((pub_r001232_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001232_19_1 * 2) + 11) & 63;
  int stage_v_218_2 = ((pub_r001232_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001232_3_1 * 2) + 22) & 63;
  int stage_v_219_2 = ((pub_r001232_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_211_1 * 3) + pub_r001232_19_1) + 4) & 127;
  int stage_v_220_2 = (((stage_v_211_2 * 3) + pub_r001232_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_181_1 * 3) + pub_r001232_3_1) + 30) & 127;
  int stage_v_221_2 = (((stage_v_181_2 * 3) + pub_r001232_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((sec_r001232_5_1 * 3) + pub_r001232_10_1) + 43) & 127;
  int stage_v_222_2 = (((sec_r001232_5_2 * 3) + pub_r001232_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001232_12_1 * 2) + 26) & 63;
  int stage_v_223_2 = ((pub_r001232_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_141_1 * 3) + pub_r001232_2_1) + 16) & 127;
  int stage_v_224_2 = (((stage_v_141_2 * 3) + pub_r001232_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001232_9_1 * 2) + 24) & 63;
  int stage_v_225_2 = ((pub_r001232_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001232_15_1 * 2) + 19) & 63;
  int stage_v_226_2 = ((pub_r001232_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001232_14_1 * 2) + 17) & 63;
  int stage_v_227_2 = ((pub_r001232_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001232_5_1 * 2) + 30) & 63;
  int stage_v_228_2 = ((pub_r001232_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_86_1 * 3) + pub_r001232_13_1) + 19) & 127;
  int stage_v_229_2 = (((stage_v_86_2 * 3) + pub_r001232_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_50_1 * 3) + pub_r001232_17_1) + 43) & 127;
  int stage_v_230_2 = (((stage_v_50_2 * 3) + pub_r001232_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001232_8_1 * 2) + 9) & 63;
  int stage_v_231_2 = ((pub_r001232_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001232_2_1 * 2) + 48) & 63;
  int stage_v_232_2 = ((pub_r001232_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001232_8_1 * 2) + 7) & 63;
  int stage_v_233_2 = ((pub_r001232_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001232_1_1 * 2) + 40) & 63;
  int stage_v_234_2 = ((pub_r001232_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_3_1 * 3) + pub_r001232_8_1) + 15) & 127;
  int stage_v_235_2 = (((stage_v_3_2 * 3) + pub_r001232_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001232_13_1 * 2) + 24) & 63;
  int stage_v_236_2 = ((pub_r001232_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_24_1 * 3) + pub_r001232_10_1) + 35) & 127;
  int stage_v_237_2 = (((stage_v_24_2 * 3) + pub_r001232_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001232_15_1 * 2) + 24) & 63;
  int stage_v_238_2 = ((pub_r001232_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001232_8_1 * 2) + 37) & 63;
  int stage_v_239_2 = ((pub_r001232_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001232_5_1 * 2) + 27) & 63;
  int stage_v_240_2 = ((pub_r001232_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001232_12_1 * 2) + 30) & 63;
  int stage_v_241_2 = ((pub_r001232_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_193_1 * 3) + pub_r001232_13_1) + 21) & 127;
  int stage_v_242_2 = (((stage_v_193_2 * 3) + pub_r001232_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001232_2_1 * 2) + 41) & 63;
  int stage_v_243_2 = ((pub_r001232_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_120_1 * 3) + pub_r001232_11_1) + 39) & 127;
  int stage_v_244_2 = (((stage_v_120_2 * 3) + pub_r001232_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001232_16_1 * 2) + 28) & 63;
  int stage_v_245_2 = ((pub_r001232_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_73_1 * 3) + pub_r001232_6_1) + 19) & 127;
  int stage_v_246_2 = (((stage_v_73_2 * 3) + pub_r001232_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001232_8_1 * 2) + 30) & 63;
  int stage_v_247_2 = ((pub_r001232_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001232_14_1 * 2) + 34) & 63;
  int stage_v_248_2 = ((pub_r001232_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001232_19_1 * 2) + 29) & 63;
  int stage_v_249_2 = ((pub_r001232_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = (((stage_v_242_1 * 3) + pub_r001232_16_1) + 40) & 127;
  int stage_v_250_2 = (((stage_v_242_2 * 3) + pub_r001232_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((sec_r001232_10_1 * 3) + pub_r001232_1_1) + 28) & 127;
  int stage_v_251_2 = (((sec_r001232_10_2 * 3) + pub_r001232_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_193_1 * 3) + pub_r001232_5_1) + 37) & 127;
  int stage_v_252_2 = (((stage_v_193_2 * 3) + pub_r001232_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001232_16_1 * 2) + 10) & 63;
  int stage_v_253_2 = ((pub_r001232_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_120_1 * 3) + pub_r001232_14_1) + 19) & 127;
  int stage_v_254_2 = (((stage_v_120_2 * 3) + pub_r001232_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001232_10_1 * 2) + 29) & 63;
  int stage_v_255_2 = ((pub_r001232_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((sec_r001232_13_1 * 3) + pub_r001232_2_1) + 29) & 127;
  int stage_v_256_2 = (((sec_r001232_13_2 * 3) + pub_r001232_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001232_15_1 * 2) + 17) & 63;
  int stage_v_257_2 = ((pub_r001232_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_32_1 * 3) + pub_r001232_2_1) + 33) & 127;
  int stage_v_258_2 = (((stage_v_32_2 * 3) + pub_r001232_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001232_13_1 * 2) + 28) & 63;
  int stage_v_259_2 = ((pub_r001232_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001232_17_1 * 2) + 12) & 63;
  int stage_v_260_2 = ((pub_r001232_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001232_10_1 * 2) + 46) & 63;
  int stage_v_261_2 = ((pub_r001232_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_134_1 * 3) + pub_r001232_16_1) + 22) & 127;
  int stage_v_262_2 = (((stage_v_134_2 * 3) + pub_r001232_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001232_3_1 * 2) + 50) & 63;
  int stage_v_263_2 = ((pub_r001232_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((sec_r001232_7_1 * 3) + pub_r001232_5_1) + 40) & 127;
  int stage_v_264_2 = (((sec_r001232_7_2 * 3) + pub_r001232_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001232_7_1 * 2) + 36) & 63;
  int stage_v_265_2 = ((pub_r001232_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001232_4_1 * 2) + 35) & 63;
  int stage_v_266_2 = ((pub_r001232_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_107_1 * 3) + pub_r001232_2_1) + 19) & 127;
  int stage_v_267_2 = (((stage_v_107_2 * 3) + pub_r001232_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_119_1 * 3) + pub_r001232_6_1) + 14) & 127;
  int stage_v_268_2 = (((stage_v_119_2 * 3) + pub_r001232_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001232_11_1 * 2) + 47) & 63;
  int stage_v_269_2 = ((pub_r001232_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001232_16_1 * 2) + 28) & 63;
  int stage_v_270_2 = ((pub_r001232_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001232_8_1 * 2) + 15) & 63;
  int stage_v_271_2 = ((pub_r001232_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001232_18_1 * 2) + 26) & 63;
  int stage_v_272_2 = ((pub_r001232_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_267_1 * 3) + pub_r001232_8_1) + 30) & 127;
  int stage_v_273_2 = (((stage_v_267_2 * 3) + pub_r001232_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001232_8_1 * 2) + 27) & 63;
  int stage_v_274_2 = ((pub_r001232_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001232_0_1 * 2) + 7) & 63;
  int stage_v_275_2 = ((pub_r001232_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001232_3_1 * 2) + 7) & 63;
  int stage_v_276_2 = ((pub_r001232_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_30_1 * 3) + pub_r001232_14_1) + 13) & 127;
  int stage_v_277_2 = (((stage_v_30_2 * 3) + pub_r001232_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_6_1 * 3) + pub_r001232_5_1) + 29) & 127;
  int stage_v_278_2 = (((stage_v_6_2 * 3) + pub_r001232_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001232_2_1 * 2) + 7) & 63;
  int stage_v_279_2 = ((pub_r001232_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001232_9_1 * 2) + 43) & 63;
  int stage_v_280_2 = ((pub_r001232_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001232_1_1 * 2) + 27) & 63;
  int stage_v_281_2 = ((pub_r001232_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001232_14_1 * 2) + 18) & 63;
  int stage_v_282_2 = ((pub_r001232_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001232_3_1 * 2) + 33) & 63;
  int stage_v_283_2 = ((pub_r001232_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001232_2_1 * 2) + 31) & 63;
  int stage_v_284_2 = ((pub_r001232_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_3_1 * 3) + pub_r001232_18_1) + 18) & 127;
  int stage_v_285_2 = (((stage_v_3_2 * 3) + pub_r001232_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_122_1 * 3) + pub_r001232_18_1) + 9) & 127;
  int stage_v_286_2 = (((stage_v_122_2 * 3) + pub_r001232_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_181_1 * 3) + pub_r001232_6_1) + 42) & 127;
  int stage_v_287_2 = (((stage_v_181_2 * 3) + pub_r001232_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001232_4_1 * 2) + 21) & 63;
  int stage_v_288_2 = ((pub_r001232_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_163_1 * 3) + pub_r001232_1_1) + 8) & 127;
  int stage_v_289_2 = (((stage_v_163_2 * 3) + pub_r001232_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001232_9_1 * 2) + 7) & 63;
  int stage_v_290_2 = ((pub_r001232_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001232_17_1 * 2) + 27) & 63;
  int stage_v_291_2 = ((pub_r001232_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_242_1 * 3) + pub_r001232_6_1) + 34) & 127;
  int stage_v_292_2 = (((stage_v_242_2 * 3) + pub_r001232_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001232_3_1 * 2) + 36) & 63;
  int stage_v_293_2 = ((pub_r001232_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_24_1 * 3) + pub_r001232_18_1) + 11) & 127;
  int stage_v_294_2 = (((stage_v_24_2 * 3) + pub_r001232_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((sec_r001232_11_1 * 3) + pub_r001232_15_1) + 6) & 127;
  int stage_v_295_2 = (((sec_r001232_11_2 * 3) + pub_r001232_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_171_1 * 3) + pub_r001232_7_1) + 22) & 127;
  int stage_v_296_2 = (((stage_v_171_2 * 3) + pub_r001232_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001232_16_1 * 2) + 43) & 63;
  int stage_v_297_2 = ((pub_r001232_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001232_1_1 * 2) + 26) & 63;
  int stage_v_298_2 = ((pub_r001232_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_296_1 * 3) + pub_r001232_19_1) + 13) & 127;
  int stage_v_299_2 = (((stage_v_296_2 * 3) + pub_r001232_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_277_1 * 3) + pub_r001232_11_1) + 12) & 127;
  int stage_v_300_2 = (((stage_v_277_2 * 3) + pub_r001232_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_121_1 * 3) + pub_r001232_12_1) + 45) & 127;
  int stage_v_301_2 = (((stage_v_121_2 * 3) + pub_r001232_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((sec_r001232_15_1 * 3) + pub_r001232_15_1) + 7) & 127;
  int stage_v_302_2 = (((sec_r001232_15_2 * 3) + pub_r001232_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001232_12_1 * 2) + 42) & 63;
  int stage_v_303_2 = ((pub_r001232_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001232_1_1 * 2) + 31) & 63;
  int stage_v_304_2 = ((pub_r001232_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001232_17_1 * 2) + 26) & 63;
  int stage_v_305_2 = ((pub_r001232_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_27_1 * 3) + pub_r001232_13_1) + 16) & 127;
  int stage_v_306_2 = (((stage_v_27_2 * 3) + pub_r001232_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001232_7_1 * 2) + 33) & 63;
  int stage_v_307_2 = ((pub_r001232_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001232_1_1 * 2) + 21) & 63;
  int stage_v_308_2 = ((pub_r001232_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_251_1 * 3) + pub_r001232_19_1) + 9) & 127;
  int stage_v_309_2 = (((stage_v_251_2 * 3) + pub_r001232_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001232_9_1 * 2) + 9) & 63;
  int stage_v_310_2 = ((pub_r001232_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_120_1 * 3) + pub_r001232_0_1) + 19) & 127;
  int stage_v_311_2 = (((stage_v_120_2 * 3) + pub_r001232_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((helper_flow_0_1 * 3) + pub_r001232_18_1) + 17) & 127;
  int stage_v_312_2 = (((helper_flow_0_2 * 3) + pub_r001232_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((helper_flow_2_1 * 3) + pub_r001232_6_1) + 33) & 127;
  int stage_v_313_2 = (((helper_flow_2_2 * 3) + pub_r001232_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001232_16_1 * 2) + 49) & 63;
  int stage_v_314_2 = ((pub_r001232_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_132_1 * 3) + pub_r001232_4_1) + 34) & 127;
  int stage_v_315_2 = (((stage_v_132_2 * 3) + pub_r001232_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001232_14_1 * 2) + 30) & 63;
  int stage_v_316_2 = ((pub_r001232_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001232_0_1 * 2) + 15) & 63;
  int stage_v_317_2 = ((pub_r001232_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001232_5_1 * 2) + 17) & 63;
  int stage_v_318_2 = ((pub_r001232_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001232_14_1 * 2) + 6) & 63;
  int stage_v_319_2 = ((pub_r001232_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_122_1 * 3) + pub_r001232_4_1) + 35) & 127;
  int stage_v_320_2 = (((stage_v_122_2 * 3) + pub_r001232_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001232_19_1 * 2) + 43) & 63;
  int stage_v_321_2 = ((pub_r001232_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001232_15_1 * 2) + 32) & 63;
  int stage_v_322_2 = ((pub_r001232_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001232_7_1 * 2) + 14) & 63;
  int stage_v_323_2 = ((pub_r001232_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_165_1 * 3) + pub_r001232_6_1) + 24) & 127;
  int stage_v_324_2 = (((stage_v_165_2 * 3) + pub_r001232_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001232_1_1 * 2) + 9) & 63;
  int stage_v_325_2 = ((pub_r001232_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001232_5_1 * 2) + 21) & 63;
  int stage_v_326_2 = ((pub_r001232_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001232_7_1 * 2) + 30) & 63;
  int stage_v_327_2 = ((pub_r001232_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_170_1 * 3) + pub_r001232_10_1) + 37) & 127;
  int stage_v_328_2 = (((stage_v_170_2 * 3) + pub_r001232_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001232_10_1 * 2) + 41) & 63;
  int stage_v_329_2 = ((pub_r001232_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001232_12_1 * 2) + 14) & 63;
  int stage_v_330_2 = ((pub_r001232_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001232_10_1 * 2) + 18) & 63;
  int stage_v_331_2 = ((pub_r001232_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001232_7_1 * 2) + 40) & 63;
  int stage_v_332_2 = ((pub_r001232_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001232_14_1 * 2) + 47) & 63;
  int stage_v_333_2 = ((pub_r001232_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001232_10_1 * 2) + 44) & 63;
  int stage_v_334_2 = ((pub_r001232_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001232_13_1 * 2) + 27) & 63;
  int stage_v_335_2 = ((pub_r001232_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001232_1_1 * 2) + 8) & 63;
  int stage_v_336_2 = ((pub_r001232_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001232_6_1 * 2) + 6) & 63;
  int stage_v_337_2 = ((pub_r001232_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((helper_flow_3_1 * 3) + pub_r001232_6_1) + 5) & 127;
  int stage_v_338_2 = (((helper_flow_3_2 * 3) + pub_r001232_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001232_9_1 * 2) + 15) & 63;
  int stage_v_339_2 = ((pub_r001232_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001232_3_1 * 2) + 29) & 63;
  int stage_v_340_2 = ((pub_r001232_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001232_6_1 * 2) + 36) & 63;
  int stage_v_341_2 = ((pub_r001232_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001232_19_1 * 2) + 19) & 63;
  int stage_v_342_2 = ((pub_r001232_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001232_1_1 * 2) + 31) & 63;
  int stage_v_343_2 = ((pub_r001232_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001232_18_1 * 2) + 29) & 63;
  int stage_v_344_2 = ((pub_r001232_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001232_19_1 * 2) + 18) & 63;
  int stage_v_345_2 = ((pub_r001232_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001232_15_1 * 2) + 42) & 63;
  int stage_v_346_2 = ((pub_r001232_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((helper_flow_3_1 * 3) + pub_r001232_4_1) + 7) & 127;
  int stage_v_347_2 = (((helper_flow_3_2 * 3) + pub_r001232_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_199_1 * 3) + pub_r001232_1_1) + 35) & 127;
  int stage_v_348_2 = (((stage_v_199_2 * 3) + pub_r001232_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_258_1 * 3) + pub_r001232_16_1) + 39) & 127;
  int stage_v_349_2 = (((stage_v_258_2 * 3) + pub_r001232_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_54_1 * 3) + pub_r001232_4_1) + 33) & 127;
  int stage_v_350_2 = (((stage_v_54_2 * 3) + pub_r001232_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001232_3_1 * 2) + 26) & 63;
  int stage_v_351_2 = ((pub_r001232_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001232_3_1 * 2) + 21) & 63;
  int stage_v_352_2 = ((pub_r001232_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001232_16_1 * 2) + 10) & 63;
  int stage_v_353_2 = ((pub_r001232_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_212_1 * 3) + pub_r001232_10_1) + 8) & 127;
  int stage_v_354_2 = (((stage_v_212_2 * 3) + pub_r001232_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001232_1_1 * 2) + 7) & 63;
  int stage_v_355_2 = ((pub_r001232_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_27_1 * 3) + pub_r001232_8_1) + 25) & 127;
  int stage_v_356_2 = (((stage_v_27_2 * 3) + pub_r001232_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((sec_r001232_14_1 * 3) + pub_r001232_19_1) + 43) & 127;
  int stage_v_357_2 = (((sec_r001232_14_2 * 3) + pub_r001232_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_168_1 * 3) + pub_r001232_10_1) + 27) & 127;
  int stage_v_358_2 = (((stage_v_168_2 * 3) + pub_r001232_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_221_1 * 3) + pub_r001232_19_1) + 36) & 127;
  int stage_v_359_2 = (((stage_v_221_2 * 3) + pub_r001232_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001232_8_1 * 2) + 38) & 63;
  int stage_v_360_2 = ((pub_r001232_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001232_15_1 * 2) + 18) & 63;
  int stage_v_361_2 = ((pub_r001232_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_152_1 * 3) + pub_r001232_13_1) + 32) & 127;
  int stage_v_362_2 = (((stage_v_152_2 * 3) + pub_r001232_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_292_1 * 3) + pub_r001232_6_1) + 10) & 127;
  int stage_v_363_2 = (((stage_v_292_2 * 3) + pub_r001232_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001232_7_1 * 2) + 21) & 63;
  int stage_v_364_2 = ((pub_r001232_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001232_9_1 * 2) + 30) & 63;
  int stage_v_365_2 = ((pub_r001232_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001232_9_1 * 2) + 7) & 63;
  int stage_v_366_2 = ((pub_r001232_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_150_1 * 3) + pub_r001232_5_1) + 39) & 127;
  int stage_v_367_2 = (((stage_v_150_2 * 3) + pub_r001232_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_47_1 * 3) + pub_r001232_18_1) + 31) & 127;
  int stage_v_368_2 = (((stage_v_47_2 * 3) + pub_r001232_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_224_1 * 3) + pub_r001232_17_1) + 17) & 127;
  int stage_v_369_2 = (((stage_v_224_2 * 3) + pub_r001232_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001232_18_1 * 2) + 19) & 63;
  int stage_v_370_2 = ((pub_r001232_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_134_1 * 3) + pub_r001232_11_1) + 4) & 127;
  int stage_v_371_2 = (((stage_v_134_2 * 3) + pub_r001232_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001232_10_1 * 2) + 19) & 63;
  int stage_v_372_2 = ((pub_r001232_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001232_3_1 * 2) + 21) & 63;
  int stage_v_373_2 = ((pub_r001232_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001232_19_1 * 2) + 27) & 63;
  int stage_v_374_2 = ((pub_r001232_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001232_14_1 * 2) + 12) & 63;
  int stage_v_375_2 = ((pub_r001232_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = (((stage_v_168_1 * 3) + pub_r001232_16_1) + 38) & 127;
  int stage_v_376_2 = (((stage_v_168_2 * 3) + pub_r001232_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001232_0_1 * 2) + 48) & 63;
  int stage_v_377_2 = ((pub_r001232_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001232_18_1 * 2) + 42) & 63;
  int stage_v_378_2 = ((pub_r001232_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_356_1 * 3) + pub_r001232_0_1) + 42) & 127;
  int stage_v_379_2 = (((stage_v_356_2 * 3) + pub_r001232_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_229_1 * 3) + pub_r001232_9_1) + 21) & 127;
  int stage_v_380_2 = (((stage_v_229_2 * 3) + pub_r001232_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((sec_r001232_9_1 * 3) + pub_r001232_17_1) + 26) & 127;
  int stage_v_381_2 = (((sec_r001232_9_2 * 3) + pub_r001232_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_312_1 * 3) + pub_r001232_3_1) + 23) & 127;
  int stage_v_382_2 = (((stage_v_312_2 * 3) + pub_r001232_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001232_8_1 * 2) + 26) & 63;
  int stage_v_383_2 = ((pub_r001232_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001232_15_1 * 2) + 14) & 63;
  int stage_v_384_2 = ((pub_r001232_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_191_1 * 3) + pub_r001232_16_1) + 8) & 127;
  int stage_v_385_2 = (((stage_v_191_2 * 3) + pub_r001232_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_12_1 * 3) + pub_r001232_1_1) + 35) & 127;
  int stage_v_386_2 = (((stage_v_12_2 * 3) + pub_r001232_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = ((pub_r001232_5_1 * 2) + 38) & 63;
  int stage_v_387_2 = ((pub_r001232_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001232_6_1 * 2) + 46) & 63;
  int stage_v_388_2 = ((pub_r001232_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_235_1 * 3) + pub_r001232_3_1) + 35) & 127;
  int stage_v_389_2 = (((stage_v_235_2 * 3) + pub_r001232_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001232_4_1 * 2) + 47) & 63;
  int stage_v_390_2 = ((pub_r001232_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_178_1 * 3) + pub_r001232_15_1) + 5) & 127;
  int stage_v_391_2 = (((stage_v_178_2 * 3) + pub_r001232_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_350_1 * 3) + pub_r001232_9_1) + 3) & 127;
  int stage_v_392_2 = (((stage_v_350_2 * 3) + pub_r001232_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001232_11_1 * 2) + 7) & 63;
  int stage_v_393_2 = ((pub_r001232_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_296_1 * 3) + pub_r001232_19_1) + 8) & 127;
  int stage_v_394_2 = (((stage_v_296_2 * 3) + pub_r001232_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001232_12_1 * 2) + 19) & 63;
  int stage_v_395_2 = ((pub_r001232_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001232_19_1 * 2) + 45) & 63;
  int stage_v_396_2 = ((pub_r001232_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001232_11_1 * 2) + 32) & 63;
  int stage_v_397_2 = ((pub_r001232_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001232_11_1 * 2) + 18) & 63;
  int stage_v_398_2 = ((pub_r001232_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((sec_r001232_19_1 * 3) + pub_r001232_8_1) + 11) & 127;
  int stage_v_399_2 = (((sec_r001232_19_2 * 3) + pub_r001232_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001232_6_1 * 2) + 47) & 63;
  int stage_v_400_2 = ((pub_r001232_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001232_14_1 * 2) + 42) & 63;
  int stage_v_401_2 = ((pub_r001232_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001232_6_1 * 2) + 43) & 63;
  int stage_v_402_2 = ((pub_r001232_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_385_1 * 3) + pub_r001232_12_1) + 20) & 127;
  int stage_v_403_2 = (((stage_v_385_2 * 3) + pub_r001232_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001232_9_1 * 2) + 43) & 63;
  int stage_v_404_2 = ((pub_r001232_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001232_9_1 * 2) + 25) & 63;
  int stage_v_405_2 = ((pub_r001232_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((sec_r001232_10_1 * 3) + pub_r001232_15_1) + 41) & 127;
  int stage_v_406_2 = (((sec_r001232_10_2 * 3) + pub_r001232_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001232_17_1 * 2) + 46) & 63;
  int stage_v_407_2 = ((pub_r001232_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001232_0_1 * 2) + 41) & 63;
  int stage_v_408_2 = ((pub_r001232_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001232_6_1 * 2) + 35) & 63;
  int stage_v_409_2 = ((pub_r001232_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001232_6_1 * 2) + 20) & 63;
  int stage_v_410_2 = ((pub_r001232_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001232_17_1 * 2) + 24) & 63;
  int stage_v_411_2 = ((pub_r001232_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001232_17_1 * 2) + 12) & 63;
  int stage_v_412_2 = ((pub_r001232_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001232_8_1 * 2) + 24) & 63;
  int stage_v_413_2 = ((pub_r001232_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001232_1_1 * 2) + 44) & 63;
  int stage_v_414_2 = ((pub_r001232_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001232_18_1 * 2) + 6) & 63;
  int stage_v_415_2 = ((pub_r001232_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001232_13_1 * 2) + 19) & 63;
  int stage_v_416_2 = ((pub_r001232_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001232_19_1 * 2) + 31) & 63;
  int stage_v_417_2 = ((pub_r001232_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001232_8_1 * 2) + 46) & 63;
  int stage_v_418_2 = ((pub_r001232_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001232_11_1 * 2) + 37) & 63;
  int stage_v_419_2 = ((pub_r001232_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001232_3_1 * 2) + 37) & 63;
  int stage_v_420_2 = ((pub_r001232_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_162_1 * 3) + pub_r001232_2_1) + 36) & 127;
  int stage_v_421_2 = (((stage_v_162_2 * 3) + pub_r001232_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001232_4_1 * 2) + 17) & 63;
  int stage_v_422_2 = ((pub_r001232_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001232_13_1 * 2) + 22) & 63;
  int stage_v_423_2 = ((pub_r001232_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001232_3_1 * 2) + 26) & 63;
  int stage_v_424_2 = ((pub_r001232_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001232_2_1 * 2) + 21) & 63;
  int stage_v_425_2 = ((pub_r001232_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_185_1 * 3) + pub_r001232_19_1) + 33) & 127;
  int stage_v_426_2 = (((stage_v_185_2 * 3) + pub_r001232_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_20_1 * 3) + pub_r001232_7_1) + 31) & 127;
  int stage_v_427_2 = (((stage_v_20_2 * 3) + pub_r001232_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001232_13_1 * 2) + 32) & 63;
  int stage_v_428_2 = ((pub_r001232_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001232_15_1 * 2) + 26) & 63;
  int stage_v_429_2 = ((pub_r001232_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_426_1 * 3) + pub_r001232_10_1) + 26) & 127;
  int stage_v_430_2 = (((stage_v_426_2 * 3) + pub_r001232_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001232_15_1 * 2) + 7) & 63;
  int stage_v_431_2 = ((pub_r001232_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001232_17_1 * 2) + 12) & 63;
  int stage_v_432_2 = ((pub_r001232_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001232_1_1 * 2) + 5) & 63;
  int stage_v_433_2 = ((pub_r001232_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001232_15_1 * 2) + 38) & 63;
  int stage_v_434_2 = ((pub_r001232_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001232_11_1 * 2) + 48) & 63;
  int stage_v_435_2 = ((pub_r001232_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001232_18_1 * 2) + 11) & 63;
  int stage_v_436_2 = ((pub_r001232_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001232_5_1 * 2) + 11) & 63;
  int stage_v_437_2 = ((pub_r001232_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001232_6_1 * 2) + 12) & 63;
  int stage_v_438_2 = ((pub_r001232_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_25_1 * 3) + pub_r001232_2_1) + 27) & 127;
  int stage_v_439_2 = (((stage_v_25_2 * 3) + pub_r001232_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_135_1 * 3) + pub_r001232_3_1) + 45) & 127;
  int stage_v_440_2 = (((stage_v_135_2 * 3) + pub_r001232_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = ((pub_r001232_15_1 * 2) + 10) & 63;
  int stage_v_441_2 = ((pub_r001232_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001232_18_1 * 2) + 14) & 63;
  int stage_v_442_2 = ((pub_r001232_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001232_7_1 * 2) + 32) & 63;
  int stage_v_443_2 = ((pub_r001232_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = (((stage_v_294_1 * 3) + pub_r001232_3_1) + 9) & 127;
  int stage_v_444_2 = (((stage_v_294_2 * 3) + pub_r001232_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = ((pub_r001232_4_1 * 2) + 40) & 63;
  int stage_v_445_2 = ((pub_r001232_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001232_17_1 * 2) + 45) & 63;
  int stage_v_446_2 = ((pub_r001232_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001232_14_1 * 2) + 15) & 63;
  int stage_v_447_2 = ((pub_r001232_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001232_7_1 * 2) + 18) & 63;
  int stage_v_448_2 = ((pub_r001232_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_391_1 * 3) + pub_r001232_1_1) + 45) & 127;
  int stage_v_449_2 = (((stage_v_391_2 * 3) + pub_r001232_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001232_19_1 * 2) + 37) & 63;
  int stage_v_450_2 = ((pub_r001232_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_315_1 * 3) + pub_r001232_12_1) + 31) & 127;
  int stage_v_451_2 = (((stage_v_315_2 * 3) + pub_r001232_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001232_5_1 * 2) + 10) & 63;
  int stage_v_452_2 = ((pub_r001232_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001232_11_1 * 2) + 20) & 63;
  int stage_v_453_2 = ((pub_r001232_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001232_4_1 * 2) + 50) & 63;
  int stage_v_454_2 = ((pub_r001232_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001232_10_1 * 2) + 43) & 63;
  int stage_v_455_2 = ((pub_r001232_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_278_1 * 3) + pub_r001232_12_1) + 9) & 127;
  int stage_v_456_2 = (((stage_v_278_2 * 3) + pub_r001232_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001232_3_1 * 2) + 44) & 63;
  int stage_v_457_2 = ((pub_r001232_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = (((stage_v_382_1 * 3) + pub_r001232_1_1) + 16) & 127;
  int stage_v_458_2 = (((stage_v_382_2 * 3) + pub_r001232_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_237_1 * 3) + pub_r001232_12_1) + 7) & 127;
  int stage_v_459_2 = (((stage_v_237_2 * 3) + pub_r001232_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001232_0_1 * 2) + 34) & 63;
  int stage_v_460_2 = ((pub_r001232_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001232_4_1 * 2) + 11) & 63;
  int stage_v_461_2 = ((pub_r001232_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((stage_v_134_1 * 3) + pub_r001232_14_1) + 21) & 127;
  int stage_v_462_2 = (((stage_v_134_2 * 3) + pub_r001232_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = ((pub_r001232_8_1 * 2) + 39) & 63;
  int stage_v_463_2 = ((pub_r001232_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001232_11_1 * 2) + 46) & 63;
  int stage_v_464_2 = ((pub_r001232_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001232_4_1 * 2) + 7) & 63;
  int stage_v_465_2 = ((pub_r001232_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001232_8_1 * 2) + 29) & 63;
  int stage_v_466_2 = ((pub_r001232_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((pub_r001232_4_1 * 2) + 39) & 63;
  int stage_v_467_2 = ((pub_r001232_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = ((pub_r001232_16_1 * 2) + 12) & 63;
  int stage_v_468_2 = ((pub_r001232_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001232_7_1 * 2) + 7) & 63;
  int stage_v_469_2 = ((pub_r001232_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_250_1 * 3) + pub_r001232_8_1) + 3) & 127;
  int stage_v_470_2 = (((stage_v_250_2 * 3) + pub_r001232_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001232_18_1 * 2) + 11) & 63;
  int stage_v_471_2 = ((pub_r001232_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001232_3_1 * 2) + 26) & 63;
  int stage_v_472_2 = ((pub_r001232_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001232_10_1 * 2) + 40) & 63;
  int stage_v_473_2 = ((pub_r001232_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001232_7_1 * 2) + 24) & 63;
  int stage_v_474_2 = ((pub_r001232_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001232_16_1 * 2) + 15) & 63;
  int stage_v_475_2 = ((pub_r001232_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001232_19_1 * 2) + 6) & 63;
  int stage_v_476_2 = ((pub_r001232_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = (((stage_v_92_1 * 3) + pub_r001232_0_1) + 21) & 127;
  int stage_v_477_2 = (((stage_v_92_2 * 3) + pub_r001232_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001232_3_1 == pub_r001232_3_2);
  __CPROVER_assume(sec_r001232_7_1 != sec_r001232_7_2);
  __CPROVER_assume(pub_r001232_17_1 == pub_r001232_17_2);
  __CPROVER_assume(pub_r001232_4_1 == pub_r001232_4_2);
  __CPROVER_assume(pub_r001232_14_1 == pub_r001232_14_2);
  __CPROVER_assume(sec_r001232_15_1 != sec_r001232_15_2);
  __CPROVER_assume(pub_r001232_13_1 == pub_r001232_13_2);
  __CPROVER_assume(sec_r001232_8_1 != sec_r001232_8_2);
  __CPROVER_assume(pub_r001232_1_1 == pub_r001232_1_2);
  __CPROVER_assume(sec_r001232_16_1 != sec_r001232_16_2);
  __CPROVER_assume(sec_r001232_3_1 != sec_r001232_3_2);
  __CPROVER_assume(pub_r001232_6_1 == pub_r001232_6_2);
  __CPROVER_assume(sec_r001232_17_1 != sec_r001232_17_2);
  __CPROVER_assume(pub_r001232_7_1 == pub_r001232_7_2);
  __CPROVER_assume(sec_r001232_13_1 != sec_r001232_13_2);
  __CPROVER_assume(sec_r001232_19_1 != sec_r001232_19_2);
  __CPROVER_assume(pub_r001232_16_1 == pub_r001232_16_2);
  __CPROVER_assume(pub_r001232_19_1 == pub_r001232_19_2);
  __CPROVER_assume(sec_r001232_9_1 != sec_r001232_9_2);
  __CPROVER_assume(pub_r001232_0_1 == pub_r001232_0_2);
  __CPROVER_assume(pub_r001232_5_1 == pub_r001232_5_2);
  __CPROVER_assume(sec_r001232_1_1 != sec_r001232_1_2);
  __CPROVER_assume(sec_r001232_18_1 != sec_r001232_18_2);
  __CPROVER_assume(pub_r001232_10_1 == pub_r001232_10_2);
  __CPROVER_assume(pub_r001232_9_1 == pub_r001232_9_2);
  __CPROVER_assume(pub_r001232_18_1 == pub_r001232_18_2);
  __CPROVER_assume(pub_r001232_11_1 == pub_r001232_11_2);
  __CPROVER_assume(sec_r001232_2_1 != sec_r001232_2_2);
  __CPROVER_assume(sec_r001232_5_1 != sec_r001232_5_2);
  __CPROVER_assume(sec_r001232_10_1 != sec_r001232_10_2);
  __CPROVER_assume(pub_r001232_12_1 == pub_r001232_12_2);
  __CPROVER_assume(sec_r001232_6_1 != sec_r001232_6_2);
  __CPROVER_assume(sec_r001232_0_1 != sec_r001232_0_2);
  __CPROVER_assume(sec_r001232_4_1 != sec_r001232_4_2);
  __CPROVER_assume(sec_r001232_11_1 != sec_r001232_11_2);
  __CPROVER_assume(pub_r001232_8_1 == pub_r001232_8_2);
  __CPROVER_assume(pub_r001232_15_1 == pub_r001232_15_2);
  __CPROVER_assume(sec_r001232_14_1 != sec_r001232_14_2);
  __CPROVER_assume(sec_r001232_12_1 != sec_r001232_12_2);
  __CPROVER_assume(pub_r001232_2_1 == pub_r001232_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.port == st_var_2_2.port);
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
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
}


