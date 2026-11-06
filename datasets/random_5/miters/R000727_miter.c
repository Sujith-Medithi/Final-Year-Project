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
struct Transaction_R000727_2713_0
{
  unsigned char fee;
  unsigned char auth_code;
  unsigned char balance;
  int buffer[3];
};
struct DeviceConfig_R000727_2713_1
{
  int timeout;
  unsigned char parity;
  short id;
  int baud_rate;
  short stop_bits;
  short port;
  int buffer[3];
};
union PacketPayload_R000727_2713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000727_2713_1
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
void fn_R000727_2713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int delta_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_55_1)
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

  switch (delta_55_2)
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

  int accumulator_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_87_1) & 63;
  aux_2 = (aux_2 + accumulator_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(accumulator_87_1 == accumulator_87_2);
}

int fn_R000727_2713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int delta_55 = (aux + st.buffer[1]) & 3;
  switch (delta_55)
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

  int accumulator_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000727_2713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 47)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 47)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_92_1 = local_arr_1[aux_1 % 3];
  int parity_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_38_1)
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

  switch (mask_38_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_18_1 == segment_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(mask_38_1 == mask_38_2);
}

int fn_R000727_2713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 47)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_92 = local_arr[aux % 3];
  acc = (acc + (parity_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_38 = (aux + st.buffer[1]) & 3;
  switch (mask_38)
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

void fn_R000727_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_44_1 = local_arr_1[aux_1 % 3];
  int stride_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_44_2 * 2)) & 127;
  int damping_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_16_1 > 15)
  {
    acc_1 = ((acc_1 + (damping_16_1 * 2)) + 5) & 127;
    aux_1 ^= damping_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_16_2 > 15)
  {
    acc_2 = ((acc_2 + (damping_16_2 * 2)) + 5) & 127;
    aux_2 ^= damping_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_73_1)
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

  switch (tally_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(damping_16_1 == damping_16_2);
  assert(tally_73_1 == tally_73_2);
}

int fn_R000727_2713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int stride_44 = local_arr[aux % 3];
  acc = (acc + (stride_44 * 2)) & 127;
  int damping_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_16 > 15)
  {
    acc = ((acc + (damping_16 * 2)) + 5) & 127;
    aux ^= damping_16 & 15;
  }
  else
  {
    acc = ((acc - damping_16) + 11) & 127;
    aux += 3;
  }
  int tally_73 = (aux + st.buffer[1]) & 3;
  switch (tally_73)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_34_1)
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

  switch (threshold_34_2)
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
  int residue_49_1 = local_arr_1[aux_1 % 3];
  int residue_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_34_1 == threshold_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_49_1 == residue_49_2);
}

int fn_R000727_2713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_34 = (aux + st.buffer[1]) & 3;
  switch (threshold_34)
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
  int residue_49 = local_arr[aux % 3];
  acc = (acc + (residue_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_94_1)
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

  switch (metric_94_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_34_1 > 34)
  {
    acc_1 = ((acc_1 + (sample_34_1 * 2)) + 5) & 127;
    aux_1 ^= sample_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_34_2 > 34)
  {
    acc_2 = ((acc_2 + (sample_34_2 * 2)) + 5) & 127;
    aux_2 ^= sample_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_94_1 == metric_94_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R000727_2713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_94 = (aux + st.buffer[1]) & 3;
  switch (metric_94)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_34 > 34)
  {
    acc = ((acc + (sample_34 * 2)) + 5) & 127;
    aux ^= sample_34 & 15;
  }
  else
  {
    acc = ((acc - sample_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000727_2713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_79_1) & 63;
  aux_2 = (aux_2 + pivot_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_12_1 = local_arr_1[aux_1 % 3];
  int window_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_79_1 == pivot_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_12_1 == window_12_2);
}

int fn_R000727_2713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_12 = local_arr[aux % 3];
  acc = (acc + (window_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_27_1) & 63;
  aux_2 = (aux_2 + stride_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_82_1)
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

  switch (coefficient_82_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_27_1 == stride_27_2);
  assert(coefficient_82_1 == coefficient_82_2);
}

int fn_R000727_2713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_27) & 63;
  acc ^= aux;
  int coefficient_82 = (aux + st.buffer[1]) & 3;
  switch (coefficient_82)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int threshold_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_45_1) & 63;
  aux_2 = (aux_2 + threshold_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_18_1 = local_arr_1[aux_1 % 3];
  int segment_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_18_1 == segment_18_2);
}

int fn_R000727_2713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_45) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_18 = local_arr[aux % 3];
  acc = (acc + (segment_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
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

  int segment_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_13_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_13_1 * 2)) + 5) & 127;
    aux_1 ^= segment_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_13_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_13_2 * 2)) + 5) & 127;
    aux_2 ^= segment_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_88_1) & 63;
  aux_2 = (aux_2 + stride_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_56_1 == factor_56_2);
  assert(segment_13_1 == segment_13_2);
  assert(stride_88_1 == stride_88_2);
}

int fn_R000727_2713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
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

  int segment_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_13 > 27)
  {
    acc = ((acc + (segment_13 * 2)) + 5) & 127;
    aux ^= segment_13 & 15;
  }
  else
  {
    acc = ((acc - segment_13) + 11) & 127;
    aux += 3;
  }
  int stride_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000727_2713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_91_1) & 63;
  aux_2 = (aux_2 + tracker_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_51_1 = local_arr_1[aux_1 % 3];
  int factor_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_51_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_19_1)
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

  switch (quotient_19_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_91_1 == tracker_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_51_1 == factor_51_2);
  assert(quotient_19_1 == quotient_19_2);
}

int fn_R000727_2713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_51 = local_arr[aux % 3];
  acc = (acc + (factor_51 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_19 = (aux + st.buffer[1]) & 3;
  switch (quotient_19)
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

void fn_R000727_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_22_1)
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

  switch (quantum_22_2)
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
  int index_reg_44_1 = local_arr_1[aux_1 % 3];
  int index_reg_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_44_1 == index_reg_44_2);
}

int fn_R000727_2713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_22 = (aux + st.buffer[1]) & 3;
  switch (quantum_22)
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
  int index_reg_44 = local_arr[aux % 3];
  acc = (acc + (index_reg_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_70_1)
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

  switch (metric_70_2)
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

  int segment_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_34_1) & 63;
  aux_2 = (aux_2 + segment_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_70_1 == metric_70_2);
  assert(segment_34_1 == segment_34_2);
}

int fn_R000727_2713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_70 = (aux + st.buffer[1]) & 3;
  switch (metric_70)
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

  int segment_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000727_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
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
  int quotient_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_71_1 > 19)
  {
    acc_1 = ((acc_1 + (quotient_71_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_71_2 > 19)
  {
    acc_2 = ((acc_2 + (quotient_71_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_87_1) & 63;
  aux_2 = (aux_2 + factor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_71_1 == quotient_71_2);
  assert(factor_87_1 == factor_87_2);
}

int fn_R000727_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_71 > 19)
  {
    acc = ((acc + (quotient_71 * 2)) + 5) & 127;
    aux ^= quotient_71 & 15;
  }
  else
  {
    acc = ((acc - quotient_71) + 11) & 127;
    aux += 3;
  }
  int factor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000727_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_57_1 = local_arr_1[aux_1 % 3];
  int scale_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_57_2 * 2)) & 127;
  int index_reg_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_32_1 > 43)
  {
    acc_1 = ((acc_1 + (index_reg_32_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_32_2 > 43)
  {
    acc_2 = ((acc_2 + (index_reg_32_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_57_1 == scale_57_2);
  assert(index_reg_32_1 == index_reg_32_2);
}

int fn_R000727_2713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int scale_57 = local_arr[aux % 3];
  acc = (acc + (scale_57 * 2)) & 127;
  int index_reg_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_32 > 43)
  {
    acc = ((acc + (index_reg_32 * 2)) + 5) & 127;
    aux ^= index_reg_32 & 15;
  }
  else
  {
    acc = ((acc - index_reg_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000727_2713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int segment_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_12_1) & 63;
  aux_2 = (aux_2 + segment_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_12_1 == segment_12_2);
}

int fn_R000727_2713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int segment_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
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
  int quantum_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_57_1)
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

  switch (quantum_57_2)
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
  int coefficient_68_1 = local_arr_1[aux_1 % 3];
  int coefficient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_68_2 * 2)) & 127;
  int tally_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_31_1) & 63;
  aux_2 = (aux_2 + tally_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_57_1 == quantum_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_68_1 == coefficient_68_2);
  assert(tally_31_1 == tally_31_2);
}

int fn_R000727_2713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_57 = (aux + st.buffer[1]) & 3;
  switch (quantum_57)
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
  int coefficient_68 = local_arr[aux % 3];
  acc = (acc + (coefficient_68 * 2)) & 127;
  int tally_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000727_2713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int metric_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_99_1)
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

  switch (metric_99_2)
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
  int quotient_80_1 = local_arr_1[aux_1 % 3];
  int quotient_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_99_1 == metric_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_80_1 == quotient_80_2);
}

int fn_R000727_2713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int metric_99 = (aux + st.buffer[1]) & 3;
  switch (metric_99)
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
  int quotient_80 = local_arr[aux % 3];
  acc = (acc + (quotient_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st_1 = {0};
  struct Transaction_R000727_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_24_1)
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

  switch (pivot_24_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_41_1 = local_arr_1[aux_1 % 3];
  int anchor_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_41_2 * 2)) & 127;
  int weight_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_48_1 > 21)
  {
    acc_1 = ((acc_1 + (weight_48_1 * 2)) + 5) & 127;
    aux_1 ^= weight_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_48_2 > 21)
  {
    acc_2 = ((acc_2 + (weight_48_2 * 2)) + 5) & 127;
    aux_2 ^= weight_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_24_1 == pivot_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_41_1 == anchor_41_2);
  assert(weight_48_1 == weight_48_2);
}

int fn_R000727_2713_17(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000727_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_24 = (aux + st.buffer[1]) & 3;
  switch (pivot_24)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_41 = local_arr[aux % 3];
  acc = (acc + (anchor_41 * 2)) & 127;
  int weight_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_48 > 21)
  {
    acc = ((acc + (weight_48 * 2)) + 5) & 127;
    aux ^= weight_48 & 15;
  }
  else
  {
    acc = ((acc - weight_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000727_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_96_1 > 31)
  {
    acc_1 = ((acc_1 + (delta_96_1 * 2)) + 5) & 127;
    aux_1 ^= delta_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_96_2 > 31)
  {
    acc_2 = ((acc_2 + (delta_96_2 * 2)) + 5) & 127;
    aux_2 ^= delta_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_67_1 = local_arr_1[aux_1 % 3];
  int mask_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_96_1 == delta_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_67_1 == mask_67_2);
}

int fn_R000727_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_96 > 31)
  {
    acc = ((acc + (delta_96 * 2)) + 5) & 127;
    aux ^= delta_96 & 15;
  }
  else
  {
    acc = ((acc - delta_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_67 = local_arr[aux % 3];
  acc = (acc + (mask_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000727_2713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_48_1) & 63;
  aux_2 = (aux_2 + metric_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_12_1)
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

  switch (stride_12_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_48_1 == metric_48_2);
  assert(stride_12_1 == stride_12_2);
}

int fn_R000727_2713_19(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000727_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_48) & 63;
  acc ^= aux;
  int stride_12 = (aux + st.buffer[1]) & 3;
  switch (stride_12)
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
  int sec_r000727_0_1;
  int sec_r000727_0_2;
  int sec_r000727_1_1;
  int sec_r000727_1_2;
  int sec_r000727_2_1;
  int sec_r000727_2_2;
  int sec_r000727_3_1;
  int sec_r000727_3_2;
  int sec_r000727_4_1;
  int sec_r000727_4_2;
  int sec_r000727_5_1;
  int sec_r000727_5_2;
  int sec_r000727_6_1;
  int sec_r000727_6_2;
  int sec_r000727_7_1;
  int sec_r000727_7_2;
  int sec_r000727_8_1;
  int sec_r000727_8_2;
  int sec_r000727_9_1;
  int sec_r000727_9_2;
  int sec_r000727_10_1;
  int sec_r000727_10_2;
  int sec_r000727_11_1;
  int sec_r000727_11_2;
  int sec_r000727_12_1;
  int sec_r000727_12_2;
  int sec_r000727_13_1;
  int sec_r000727_13_2;
  int sec_r000727_14_1;
  int sec_r000727_14_2;
  int sec_r000727_15_1;
  int sec_r000727_15_2;
  int sec_r000727_16_1;
  int sec_r000727_16_2;
  int sec_r000727_17_1;
  int sec_r000727_17_2;
  int sec_r000727_18_1;
  int sec_r000727_18_2;
  int sec_r000727_19_1;
  int sec_r000727_19_2;
  int sec_r000727_20_1;
  int sec_r000727_20_2;
  int sec_r000727_21_1;
  int sec_r000727_21_2;
  int pub_r000727_0_1;
  int pub_r000727_0_2;
  int pub_r000727_1_1;
  int pub_r000727_1_2;
  int pub_r000727_2_1;
  int pub_r000727_2_2;
  int pub_r000727_3_1;
  int pub_r000727_3_2;
  int pub_r000727_4_1;
  int pub_r000727_4_2;
  int pub_r000727_5_1;
  int pub_r000727_5_2;
  int pub_r000727_6_1;
  int pub_r000727_6_2;
  int pub_r000727_7_1;
  int pub_r000727_7_2;
  int pub_r000727_8_1;
  int pub_r000727_8_2;
  int pub_r000727_9_1;
  int pub_r000727_9_2;
  int pub_r000727_10_1;
  int pub_r000727_10_2;
  int pub_r000727_11_1;
  int pub_r000727_11_2;
  int pub_r000727_12_1;
  int pub_r000727_12_2;
  int pub_r000727_13_1;
  int pub_r000727_13_2;
  int pub_r000727_14_1;
  int pub_r000727_14_2;
  int pub_r000727_15_1;
  int pub_r000727_15_2;
  int pub_r000727_16_1;
  int pub_r000727_16_2;
  int pub_r000727_17_1;
  int pub_r000727_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000727_0_1 >= (-100)) && (pub_r000727_0_1 <= 100));
  __CPROVER_assume((pub_r000727_0_2 >= (-100)) && (pub_r000727_0_2 <= 100));
  __CPROVER_assume((pub_r000727_1_1 >= (-100)) && (pub_r000727_1_1 <= 100));
  __CPROVER_assume((pub_r000727_1_2 >= (-100)) && (pub_r000727_1_2 <= 100));
  __CPROVER_assume((pub_r000727_2_1 >= (-100)) && (pub_r000727_2_1 <= 100));
  __CPROVER_assume((pub_r000727_2_2 >= (-100)) && (pub_r000727_2_2 <= 100));
  __CPROVER_assume((pub_r000727_3_1 >= (-100)) && (pub_r000727_3_1 <= 100));
  __CPROVER_assume((pub_r000727_3_2 >= (-100)) && (pub_r000727_3_2 <= 100));
  __CPROVER_assume((pub_r000727_4_1 >= (-100)) && (pub_r000727_4_1 <= 100));
  __CPROVER_assume((pub_r000727_4_2 >= (-100)) && (pub_r000727_4_2 <= 100));
  __CPROVER_assume((pub_r000727_5_1 >= (-100)) && (pub_r000727_5_1 <= 100));
  __CPROVER_assume((pub_r000727_5_2 >= (-100)) && (pub_r000727_5_2 <= 100));
  __CPROVER_assume((pub_r000727_6_1 >= (-100)) && (pub_r000727_6_1 <= 100));
  __CPROVER_assume((pub_r000727_6_2 >= (-100)) && (pub_r000727_6_2 <= 100));
  __CPROVER_assume((pub_r000727_7_1 >= (-100)) && (pub_r000727_7_1 <= 100));
  __CPROVER_assume((pub_r000727_7_2 >= (-100)) && (pub_r000727_7_2 <= 100));
  __CPROVER_assume((pub_r000727_8_1 >= (-100)) && (pub_r000727_8_1 <= 100));
  __CPROVER_assume((pub_r000727_8_2 >= (-100)) && (pub_r000727_8_2 <= 100));
  __CPROVER_assume((pub_r000727_9_1 >= (-100)) && (pub_r000727_9_1 <= 100));
  __CPROVER_assume((pub_r000727_9_2 >= (-100)) && (pub_r000727_9_2 <= 100));
  __CPROVER_assume((pub_r000727_10_1 >= (-100)) && (pub_r000727_10_1 <= 100));
  __CPROVER_assume((pub_r000727_10_2 >= (-100)) && (pub_r000727_10_2 <= 100));
  __CPROVER_assume((pub_r000727_11_1 >= (-100)) && (pub_r000727_11_1 <= 100));
  __CPROVER_assume((pub_r000727_11_2 >= (-100)) && (pub_r000727_11_2 <= 100));
  __CPROVER_assume((pub_r000727_12_1 >= (-100)) && (pub_r000727_12_1 <= 100));
  __CPROVER_assume((pub_r000727_12_2 >= (-100)) && (pub_r000727_12_2 <= 100));
  __CPROVER_assume((pub_r000727_13_1 >= (-100)) && (pub_r000727_13_1 <= 100));
  __CPROVER_assume((pub_r000727_13_2 >= (-100)) && (pub_r000727_13_2 <= 100));
  __CPROVER_assume((pub_r000727_14_1 >= (-100)) && (pub_r000727_14_1 <= 100));
  __CPROVER_assume((pub_r000727_14_2 >= (-100)) && (pub_r000727_14_2 <= 100));
  __CPROVER_assume((pub_r000727_15_1 >= (-100)) && (pub_r000727_15_1 <= 100));
  __CPROVER_assume((pub_r000727_15_2 >= (-100)) && (pub_r000727_15_2 <= 100));
  __CPROVER_assume((pub_r000727_16_1 >= (-100)) && (pub_r000727_16_1 <= 100));
  __CPROVER_assume((pub_r000727_16_2 >= (-100)) && (pub_r000727_16_2 <= 100));
  __CPROVER_assume((pub_r000727_17_1 >= (-100)) && (pub_r000727_17_1 <= 100));
  __CPROVER_assume((pub_r000727_17_2 >= (-100)) && (pub_r000727_17_2 <= 100));
  __CPROVER_assume((sec_r000727_0_1 >= 0) && (sec_r000727_0_1 <= 255));
  __CPROVER_assume((sec_r000727_0_2 >= 0) && (sec_r000727_0_2 <= 255));
  __CPROVER_assume((sec_r000727_1_1 >= 0) && (sec_r000727_1_1 <= 255));
  __CPROVER_assume((sec_r000727_1_2 >= 0) && (sec_r000727_1_2 <= 255));
  __CPROVER_assume((sec_r000727_2_1 >= 0) && (sec_r000727_2_1 <= 255));
  __CPROVER_assume((sec_r000727_2_2 >= 0) && (sec_r000727_2_2 <= 255));
  __CPROVER_assume((sec_r000727_3_1 >= 0) && (sec_r000727_3_1 <= 255));
  __CPROVER_assume((sec_r000727_3_2 >= 0) && (sec_r000727_3_2 <= 255));
  __CPROVER_assume((sec_r000727_4_1 >= 0) && (sec_r000727_4_1 <= 255));
  __CPROVER_assume((sec_r000727_4_2 >= 0) && (sec_r000727_4_2 <= 255));
  __CPROVER_assume((sec_r000727_5_1 >= 0) && (sec_r000727_5_1 <= 255));
  __CPROVER_assume((sec_r000727_5_2 >= 0) && (sec_r000727_5_2 <= 255));
  __CPROVER_assume((sec_r000727_6_1 >= 0) && (sec_r000727_6_1 <= 255));
  __CPROVER_assume((sec_r000727_6_2 >= 0) && (sec_r000727_6_2 <= 255));
  __CPROVER_assume((sec_r000727_7_1 >= 0) && (sec_r000727_7_1 <= 255));
  __CPROVER_assume((sec_r000727_7_2 >= 0) && (sec_r000727_7_2 <= 255));
  __CPROVER_assume((sec_r000727_8_1 >= 0) && (sec_r000727_8_1 <= 255));
  __CPROVER_assume((sec_r000727_8_2 >= 0) && (sec_r000727_8_2 <= 255));
  __CPROVER_assume((sec_r000727_9_1 >= 0) && (sec_r000727_9_1 <= 255));
  __CPROVER_assume((sec_r000727_9_2 >= 0) && (sec_r000727_9_2 <= 255));
  __CPROVER_assume((sec_r000727_10_1 >= 0) && (sec_r000727_10_1 <= 255));
  __CPROVER_assume((sec_r000727_10_2 >= 0) && (sec_r000727_10_2 <= 255));
  __CPROVER_assume((sec_r000727_11_1 >= 0) && (sec_r000727_11_1 <= 255));
  __CPROVER_assume((sec_r000727_11_2 >= 0) && (sec_r000727_11_2 <= 255));
  __CPROVER_assume((sec_r000727_12_1 >= 0) && (sec_r000727_12_1 <= 255));
  __CPROVER_assume((sec_r000727_12_2 >= 0) && (sec_r000727_12_2 <= 255));
  __CPROVER_assume((sec_r000727_13_1 >= 0) && (sec_r000727_13_1 <= 255));
  __CPROVER_assume((sec_r000727_13_2 >= 0) && (sec_r000727_13_2 <= 255));
  __CPROVER_assume((sec_r000727_14_1 >= 0) && (sec_r000727_14_1 <= 255));
  __CPROVER_assume((sec_r000727_14_2 >= 0) && (sec_r000727_14_2 <= 255));
  __CPROVER_assume((sec_r000727_15_1 >= 0) && (sec_r000727_15_1 <= 255));
  __CPROVER_assume((sec_r000727_15_2 >= 0) && (sec_r000727_15_2 <= 255));
  __CPROVER_assume((sec_r000727_16_1 >= 0) && (sec_r000727_16_1 <= 255));
  __CPROVER_assume((sec_r000727_16_2 >= 0) && (sec_r000727_16_2 <= 255));
  __CPROVER_assume((sec_r000727_17_1 >= 0) && (sec_r000727_17_1 <= 255));
  __CPROVER_assume((sec_r000727_17_2 >= 0) && (sec_r000727_17_2 <= 255));
  __CPROVER_assume((sec_r000727_18_1 >= 0) && (sec_r000727_18_1 <= 255));
  __CPROVER_assume((sec_r000727_18_2 >= 0) && (sec_r000727_18_2 <= 255));
  __CPROVER_assume((sec_r000727_19_1 >= 0) && (sec_r000727_19_1 <= 255));
  __CPROVER_assume((sec_r000727_19_2 >= 0) && (sec_r000727_19_2 <= 255));
  __CPROVER_assume((sec_r000727_20_1 >= 0) && (sec_r000727_20_1 <= 255));
  __CPROVER_assume((sec_r000727_20_2 >= 0) && (sec_r000727_20_2 <= 255));
  __CPROVER_assume((sec_r000727_21_1 >= 0) && (sec_r000727_21_1 <= 255));
  __CPROVER_assume((sec_r000727_21_2 >= 0) && (sec_r000727_21_2 <= 255));
  struct Transaction_R000727_2713_0 st_var_0_1 = {0};
  struct Transaction_R000727_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000727_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000727_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000727_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000727_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000727_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000727_0_2 + 7) & 15;
  struct DeviceConfig_R000727_2713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000727_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000727_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000727_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000727_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000727_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000727_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000727_0_2 + 9) & 15;
  union PacketPayload_R000727_2713_0 u_var_1;
  union PacketPayload_R000727_2713_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 36)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 36)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 27) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 30)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 30)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 49)
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
  if (stage_v_31_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 49)
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
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 37)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 37)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 39) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 26)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 26)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 52) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 41)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 41)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 53)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 53)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 64) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((st_var_1_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_1_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 40)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 40)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (80 & 31);
  int stage_v_75_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (80 & 31);
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= (stage_v_75_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_75_2 << 1) & 127;
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = (st_var_1_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_1_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = ((st_var_0_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_0_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 32)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 32)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_79_1 = ((st_var_1_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_1_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 53)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 53)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_80_1 = ((st_var_0_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_0_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 46)
    {
      chk_sum_1 ^= stage_v_80_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_80_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 46)
    {
      chk_sum_2 ^= stage_v_80_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_81_1 = (st_var_1_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_1_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = ((st_var_1_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_1_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 47)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 47)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 49)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 49)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (92 & 31);
  int stage_v_87_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (92 & 31);
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= (stage_v_87_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_87_2 << 1) & 127;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = table_1[1];
  int stage_v_89_2 = table_2[1];
  table_1[1] = (table_1[2] + 179) & 63;
  table_2[1] = (table_2[2] + 179) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000727_20_1 & 1) != 0)
  {
    if ((sec_r000727_18_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((sec_r000727_20_2 & 1) != 0)
  {
    if ((sec_r000727_18_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000727_8_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000727_7_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000727_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000727_7_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000727_8_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000727_7_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000727_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000727_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000727_11_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000727_12_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000727_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000727_12_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000727_11_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000727_12_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000727_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000727_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000727_7_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000727_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000727_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000727_15_1 + 7) & 127;
  }
  if ((sec_r000727_7_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000727_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000727_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000727_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000727_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000727_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000727_8_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000727_16_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000727_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000727_16_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000727_8_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000727_16_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000727_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000727_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000727_21_1 & 1) != 0)
  {
    if ((sec_r000727_4_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000727_11_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000727_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000727_11_1 + 7) & 127;
  }
  if ((sec_r000727_21_2 & 1) != 0)
  {
    if ((sec_r000727_4_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000727_11_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000727_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000727_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_0_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000727_11_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000727_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000727_11_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_0_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000727_11_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000727_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000727_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000727_19_1 & 1) != 0)
  {
    if ((sec_r000727_21_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((sec_r000727_19_2 & 1) != 0)
  {
    if ((sec_r000727_21_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000727_7_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000727_7_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000727_0_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000727_7_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000727_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000727_7_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000727_0_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000727_7_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000727_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000727_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000727_19_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000727_19_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000727_10_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000727_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000727_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000727_11_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000727_10_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000727_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000727_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000727_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000727_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000727_16_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000727_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000727_16_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000727_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000727_16_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000727_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000727_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000727_13_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000727_13_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000727_18_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000727_7_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000727_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000727_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000727_18_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000727_7_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000727_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000727_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000727_19_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_19_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000727_13_1 & 1) != 0)
  {
    if ((sec_r000727_16_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_13_2 & 1) != 0)
  {
    if ((sec_r000727_16_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000727_12_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000727_10_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000727_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000727_10_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000727_12_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000727_10_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000727_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000727_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000727_6_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000727_3_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000727_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000727_3_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000727_6_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000727_3_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000727_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000727_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000727_9_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000727_10_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000727_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000727_10_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000727_9_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000727_10_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000727_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000727_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000727_5_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000727_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000727_5_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000727_5_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000727_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000727_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000727_9_1 & 1) != 0)
  {
    if ((sec_r000727_15_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000727_7_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000727_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000727_7_1 + 7) & 127;
  }
  if ((sec_r000727_9_2 & 1) != 0)
  {
    if ((sec_r000727_15_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000727_7_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000727_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000727_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000727_5_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000727_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000727_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000727_8_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000727_5_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000727_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000727_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000727_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000727_0_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000727_0_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000727_1_1 & 1) != 0)
  {
    if ((sec_r000727_5_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((sec_r000727_1_2 & 1) != 0)
  {
    if ((sec_r000727_5_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000727_15_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000727_6_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000727_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000727_6_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000727_15_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000727_6_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000727_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000727_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000727_9_1 & 1) != 0)
  {
    if ((sec_r000727_19_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000727_15_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000727_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000727_15_1 + 7) & 127;
  }
  if ((sec_r000727_9_2 & 1) != 0)
  {
    if ((sec_r000727_19_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000727_15_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000727_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000727_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000727_15_1 & 1) != 0)
  {
    if ((sec_r000727_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_15_2 & 1) != 0)
  {
    if ((sec_r000727_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000727_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000727_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000727_7_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000727_7_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000727_17_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000727_16_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000727_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000727_16_1 + 7) & 127;
  }
  if ((sec_r000727_17_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000727_16_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000727_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000727_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000727_2_1 & 1) != 0)
  {
    if ((sec_r000727_16_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000727_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000727_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000727_11_1 + 7) & 127;
  }
  if ((sec_r000727_2_2 & 1) != 0)
  {
    if ((sec_r000727_16_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000727_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000727_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000727_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000727_2_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000727_15_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000727_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000727_15_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000727_2_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000727_15_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000727_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000727_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000727_1_1 & 1) != 0)
  {
    if ((sec_r000727_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((sec_r000727_1_2 & 1) != 0)
  {
    if ((sec_r000727_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000727_0_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000727_0_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000727_17_1 & 1) != 0)
  {
    if ((sec_r000727_12_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((sec_r000727_17_2 & 1) != 0)
  {
    if ((sec_r000727_12_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000727_6_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000727_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000727_6_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000727_6_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000727_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000727_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000727_8_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000727_8_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000727_8_1 & 1) != 0)
  {
    if ((sec_r000727_19_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_8_2 & 1) != 0)
  {
    if ((sec_r000727_19_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_13_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000727_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000727_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000727_10_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_13_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000727_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000727_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000727_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000727_5_1 & 1) != 0)
  {
    if ((sec_r000727_7_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000727_4_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000727_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000727_4_1 + 7) & 127;
  }
  if ((sec_r000727_5_2 & 1) != 0)
  {
    if ((sec_r000727_7_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000727_4_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000727_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000727_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000727_2_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000727_12_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000727_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000727_12_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000727_2_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000727_12_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000727_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000727_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000727_15_1 & 1) != 0)
  {
    if ((sec_r000727_14_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_15_2 & 1) != 0)
  {
    if ((sec_r000727_14_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000727_13_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000727_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000727_13_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000727_13_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000727_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000727_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000727_9_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000727_15_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000727_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000727_15_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000727_9_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000727_15_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000727_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000727_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000727_16_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000727_12_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000727_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000727_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000727_16_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000727_12_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000727_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000727_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000727_17_1 & 1) != 0)
  {
    if ((sec_r000727_2_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000727_12_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000727_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000727_12_1 + 7) & 127;
  }
  if ((sec_r000727_17_2 & 1) != 0)
  {
    if ((sec_r000727_2_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000727_12_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000727_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000727_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000727_19_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000727_5_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000727_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000727_5_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000727_19_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000727_5_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000727_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000727_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000727_7_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000727_1_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000727_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000727_1_1 + 7) & 127;
  }
  if ((sec_r000727_7_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000727_1_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000727_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000727_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000727_5_1 & 1) != 0)
  {
    if ((sec_r000727_18_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000727_4_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000727_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000727_4_1 + 7) & 127;
  }
  if ((sec_r000727_5_2 & 1) != 0)
  {
    if ((sec_r000727_18_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000727_4_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000727_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000727_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000727_1_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000727_1_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000727_16_1 & 1) != 0)
  {
    if ((sec_r000727_18_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((sec_r000727_16_2 & 1) != 0)
  {
    if ((sec_r000727_18_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000727_19_1 & 1) != 0)
  {
    if ((sec_r000727_16_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((sec_r000727_19_2 & 1) != 0)
  {
    if ((sec_r000727_16_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000727_10_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000727_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000727_10_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000727_10_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000727_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000727_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000727_9_1 & 1) != 0)
  {
    if ((sec_r000727_4_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((sec_r000727_9_2 & 1) != 0)
  {
    if ((sec_r000727_4_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000727_21_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((sec_r000727_21_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000727_5_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000727_12_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000727_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000727_12_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000727_5_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000727_12_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000727_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000727_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000727_20_1 & 1) != 0)
  {
    if ((sec_r000727_3_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000727_17_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000727_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000727_17_1 + 7) & 127;
  }
  if ((sec_r000727_20_2 & 1) != 0)
  {
    if ((sec_r000727_3_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000727_17_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000727_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000727_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000727_21_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000727_21_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000727_0_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000727_11_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000727_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000727_11_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000727_0_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000727_11_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000727_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000727_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000727_16_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000727_10_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000727_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000727_10_1 + 7) & 127;
  }
  if ((sec_r000727_16_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000727_10_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000727_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000727_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_8_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000727_1_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000727_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000727_1_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_8_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000727_1_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000727_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000727_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000727_9_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000727_0_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000727_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000727_0_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000727_9_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000727_0_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000727_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000727_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000727_6_1 & 1) != 0)
  {
    if ((sec_r000727_11_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000727_4_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000727_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000727_4_1 + 7) & 127;
  }
  if ((sec_r000727_6_2 & 1) != 0)
  {
    if ((sec_r000727_11_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000727_4_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000727_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000727_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000727_15_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000727_9_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000727_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000727_9_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000727_15_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000727_9_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000727_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000727_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((sec_r000727_4_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000727_3_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000727_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000727_3_1 + 7) & 127;
  }
  if ((sec_r000727_4_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000727_3_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000727_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000727_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000727_9_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000727_4_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000727_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000727_4_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000727_9_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000727_4_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000727_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000727_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000727_1_1 & 1) != 0)
  {
    if ((sec_r000727_13_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000727_6_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000727_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000727_6_1 + 7) & 127;
  }
  if ((sec_r000727_1_2 & 1) != 0)
  {
    if ((sec_r000727_13_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000727_6_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000727_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000727_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((sec_r000727_9_1 & 1) != 0)
  {
    if ((sec_r000727_16_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000727_2_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000727_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000727_2_1 + 7) & 127;
  }
  if ((sec_r000727_9_2 & 1) != 0)
  {
    if ((sec_r000727_16_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000727_2_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000727_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000727_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((sec_r000727_17_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000727_1_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000727_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000727_1_1 + 7) & 127;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((sec_r000727_17_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000727_1_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000727_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000727_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000727_20_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000727_8_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000727_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000727_8_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000727_20_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000727_8_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000727_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000727_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000727_10_1 == pub_r000727_10_2);
  __CPROVER_assume(sec_r000727_14_1 != sec_r000727_14_2);
  __CPROVER_assume(sec_r000727_13_1 != sec_r000727_13_2);
  __CPROVER_assume(sec_r000727_20_1 != sec_r000727_20_2);
  __CPROVER_assume(sec_r000727_3_1 != sec_r000727_3_2);
  __CPROVER_assume(sec_r000727_6_1 != sec_r000727_6_2);
  __CPROVER_assume(sec_r000727_10_1 != sec_r000727_10_2);
  __CPROVER_assume(pub_r000727_7_1 == pub_r000727_7_2);
  __CPROVER_assume(sec_r000727_17_1 != sec_r000727_17_2);
  __CPROVER_assume(sec_r000727_2_1 != sec_r000727_2_2);
  __CPROVER_assume(sec_r000727_8_1 != sec_r000727_8_2);
  __CPROVER_assume(sec_r000727_19_1 != sec_r000727_19_2);
  __CPROVER_assume(pub_r000727_4_1 == pub_r000727_4_2);
  __CPROVER_assume(sec_r000727_11_1 != sec_r000727_11_2);
  __CPROVER_assume(sec_r000727_5_1 != sec_r000727_5_2);
  __CPROVER_assume(pub_r000727_11_1 == pub_r000727_11_2);
  __CPROVER_assume(sec_r000727_0_1 != sec_r000727_0_2);
  __CPROVER_assume(sec_r000727_16_1 != sec_r000727_16_2);
  __CPROVER_assume(pub_r000727_13_1 == pub_r000727_13_2);
  __CPROVER_assume(pub_r000727_15_1 == pub_r000727_15_2);
  __CPROVER_assume(pub_r000727_8_1 == pub_r000727_8_2);
  __CPROVER_assume(sec_r000727_7_1 != sec_r000727_7_2);
  __CPROVER_assume(pub_r000727_14_1 == pub_r000727_14_2);
  __CPROVER_assume(pub_r000727_17_1 == pub_r000727_17_2);
  __CPROVER_assume(pub_r000727_2_1 == pub_r000727_2_2);
  __CPROVER_assume(pub_r000727_6_1 == pub_r000727_6_2);
  __CPROVER_assume(sec_r000727_9_1 != sec_r000727_9_2);
  __CPROVER_assume(sec_r000727_18_1 != sec_r000727_18_2);
  __CPROVER_assume(sec_r000727_1_1 != sec_r000727_1_2);
  __CPROVER_assume(sec_r000727_21_1 != sec_r000727_21_2);
  __CPROVER_assume(pub_r000727_12_1 == pub_r000727_12_2);
  __CPROVER_assume(pub_r000727_3_1 == pub_r000727_3_2);
  __CPROVER_assume(sec_r000727_12_1 != sec_r000727_12_2);
  __CPROVER_assume(sec_r000727_4_1 != sec_r000727_4_2);
  __CPROVER_assume(pub_r000727_5_1 == pub_r000727_5_2);
  __CPROVER_assume(pub_r000727_9_1 == pub_r000727_9_2);
  __CPROVER_assume(pub_r000727_0_1 == pub_r000727_0_2);
  __CPROVER_assume(pub_r000727_16_1 == pub_r000727_16_2);
  __CPROVER_assume(pub_r000727_1_1 == pub_r000727_1_2);
  __CPROVER_assume(sec_r000727_15_1 != sec_r000727_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
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
}


