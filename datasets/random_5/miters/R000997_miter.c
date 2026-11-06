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
struct Vector3D_R000997_1724_0
{
  unsigned char coord_y;
  short heading;
  short coord_z;
  int norm_sq;
  int pitch;
  int buffer[3];
};
struct CipherContext_R000997_1724_1
{
  unsigned char counter;
  int tag;
  int round_key;
  int iv;
  short nonce;
  int flags;
  int buffer[3];
};
struct AudioFrame_R000997_1724_2
{
  short rms;
  int peak;
  short sample_rate;
  int envelope;
  int gain;
  int buffer[3];
};
union PacketPayload_R000997_1724_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000997_1724_1
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
void fn_R000997_1724_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_77_1 = local_arr_1[aux_1 % 3];
  int accumulator_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_77_2 * 2)) & 127;
  int tally_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_64_1) & 63;
  aux_2 = (aux_2 + tally_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_40_1)
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

  switch (mask_40_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
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

  assert(accumulator_77_1 == accumulator_77_2);
  assert(tally_64_1 == tally_64_2);
  assert(mask_40_1 == mask_40_2);
}

int fn_R000997_1724_0(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int accumulator_77 = local_arr[aux % 3];
  acc = (acc + (accumulator_77 * 2)) & 127;
  int tally_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_64) & 63;
  acc ^= aux;
  int mask_40 = (aux + st.buffer[1]) & 3;
  switch (mask_40)
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
  return (acc + aux) & 255;
}

void fn_R000997_1724_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_15_1)
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

  switch (coefficient_15_2)
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
  int segment_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_14_1 > 37)
  {
    acc_1 = ((acc_1 + (segment_14_1 * 2)) + 5) & 127;
    aux_1 ^= segment_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_14_2 > 37)
  {
    acc_2 = ((acc_2 + (segment_14_2 * 2)) + 5) & 127;
    aux_2 ^= segment_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  assert(segment_14_1 == segment_14_2);
}

int fn_R000997_1724_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_15 = (aux + st.buffer[1]) & 3;
  switch (coefficient_15)
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
  int segment_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_14 > 37)
  {
    acc = ((acc + (segment_14 * 2)) + 5) & 127;
    aux ^= segment_14 & 15;
  }
  else
  {
    acc = ((acc - segment_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_16_1 = local_arr_1[aux_1 % 3];
  int delta_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_16_2 * 2)) & 127;
  int vector_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_64_1 > 12)
  {
    acc_1 = ((acc_1 + (vector_64_1 * 2)) + 5) & 127;
    aux_1 ^= vector_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_64_2 > 12)
  {
    acc_2 = ((acc_2 + (vector_64_2 * 2)) + 5) & 127;
    aux_2 ^= vector_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_16_1 == delta_16_2);
  assert(vector_64_1 == vector_64_2);
}

int fn_R000997_1724_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_16 = local_arr[aux % 3];
  acc = (acc + (delta_16 * 2)) & 127;
  int vector_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_64 > 12)
  {
    acc = ((acc + (vector_64 * 2)) + 5) & 127;
    aux ^= vector_64 & 15;
  }
  else
  {
    acc = ((acc - vector_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_99_1 = local_arr_1[aux_1 % 3];
  int pivot_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_99_2 * 2)) & 127;
  int tally_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_68_1 > 23)
  {
    acc_1 = ((acc_1 + (tally_68_1 * 2)) + 5) & 127;
    aux_1 ^= tally_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_68_2 > 23)
  {
    acc_2 = ((acc_2 + (tally_68_2 * 2)) + 5) & 127;
    aux_2 ^= tally_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_46_1) & 63;
  aux_2 = (aux_2 + checksum_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_99_1 == pivot_99_2);
  assert(tally_68_1 == tally_68_2);
  assert(checksum_46_1 == checksum_46_2);
}

int fn_R000997_1724_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int pivot_99 = local_arr[aux % 3];
  acc = (acc + (pivot_99 * 2)) & 127;
  int tally_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_68 > 23)
  {
    acc = ((acc + (tally_68 * 2)) + 5) & 127;
    aux ^= tally_68 & 15;
  }
  else
  {
    acc = ((acc - tally_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000997_1724_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_62_1 > 29)
  {
    acc_1 = ((acc_1 + (anchor_62_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_62_2 > 29)
  {
    acc_2 = ((acc_2 + (anchor_62_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_51_1 = local_arr_1[aux_1 % 3];
  int bound_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_62_1 == anchor_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_51_1 == bound_51_2);
}

int fn_R000997_1724_4(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_62 > 29)
  {
    acc = ((acc + (anchor_62 * 2)) + 5) & 127;
    aux ^= anchor_62 & 15;
  }
  else
  {
    acc = ((acc - anchor_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_51 = local_arr[aux % 3];
  acc = (acc + (bound_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_22_1 = local_arr_1[aux_1 % 3];
  int pivot_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_23_1 > 47)
  {
    acc_1 = ((acc_1 + (weight_23_1 * 2)) + 5) & 127;
    aux_1 ^= weight_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_23_2 > 47)
  {
    acc_2 = ((acc_2 + (weight_23_2 * 2)) + 5) & 127;
    aux_2 ^= weight_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_22_1 == pivot_22_2);
  assert(weight_23_1 == weight_23_2);
}

int fn_R000997_1724_5(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int pivot_22 = local_arr[aux % 3];
  acc = (acc + (pivot_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_23 > 47)
  {
    acc = ((acc + (weight_23 * 2)) + 5) & 127;
    aux ^= weight_23 & 15;
  }
  else
  {
    acc = ((acc - weight_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_87_1)
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

  switch (vector_87_2)
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

  int cursor_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_16_1 > 17)
  {
    acc_1 = ((acc_1 + (cursor_16_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_16_2 > 17)
  {
    acc_2 = ((acc_2 + (cursor_16_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_87_1 == vector_87_2);
  assert(cursor_16_1 == cursor_16_2);
}

int fn_R000997_1724_6(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_87 = (aux + st.buffer[1]) & 3;
  switch (vector_87)
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

  int cursor_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_16 > 17)
  {
    acc = ((acc + (cursor_16 * 2)) + 5) & 127;
    aux ^= cursor_16 & 15;
  }
  else
  {
    acc = ((acc - cursor_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_13_1 = local_arr_1[aux_1 % 3];
  int parity_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_13_2 * 2)) & 127;
  int phase_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_34_1) & 63;
  aux_2 = (aux_2 + phase_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
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

  assert(parity_13_1 == parity_13_2);
  assert(phase_34_1 == phase_34_2);
}

int fn_R000997_1724_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int parity_13 = local_arr[aux % 3];
  acc = (acc + (parity_13 * 2)) & 127;
  int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000997_1724_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_40_1 > 18)
  {
    acc_1 = ((acc_1 + (offset_40_1 * 2)) + 5) & 127;
    aux_1 ^= offset_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_40_2 > 18)
  {
    acc_2 = ((acc_2 + (offset_40_2 * 2)) + 5) & 127;
    aux_2 ^= offset_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_27_1)
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

  switch (bound_27_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_40_1 == offset_40_2);
  assert(bound_27_1 == bound_27_2);
}

int fn_R000997_1724_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_40 > 18)
  {
    acc = ((acc + (offset_40 * 2)) + 5) & 127;
    aux ^= offset_40 & 15;
  }
  else
  {
    acc = ((acc - offset_40) + 11) & 127;
    aux += 3;
  }
  int bound_27 = (aux + st.buffer[1]) & 3;
  switch (bound_27)
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

void fn_R000997_1724_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_76_1)
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

  switch (anchor_76_2)
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

  int bound_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_48_1) & 63;
  aux_2 = (aux_2 + bound_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_65_1 = local_arr_1[aux_1 % 3];
  int segment_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_65_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_76_1 == anchor_76_2);
  assert(bound_48_1 == bound_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_65_1 == segment_65_2);
}

int fn_R000997_1724_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_76 = (aux + st.buffer[1]) & 3;
  switch (anchor_76)
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

  int bound_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_65 = local_arr[aux % 3];
  acc = (acc + (segment_65 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_51_1 > 47)
  {
    acc_1 = ((acc_1 + (vector_51_1 * 2)) + 5) & 127;
    aux_1 ^= vector_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_51_2 > 47)
  {
    acc_2 = ((acc_2 + (vector_51_2 * 2)) + 5) & 127;
    aux_2 ^= vector_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_55_1)
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

  switch (pivot_55_2)
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
  int delta_44_1 = local_arr_1[aux_1 % 3];
  int delta_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_51_1 == vector_51_2);
  assert(pivot_55_1 == pivot_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_44_1 == delta_44_2);
}

int fn_R000997_1724_10(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_51 > 47)
  {
    acc = ((acc + (vector_51 * 2)) + 5) & 127;
    aux ^= vector_51 & 15;
  }
  else
  {
    acc = ((acc - vector_51) + 11) & 127;
    aux += 3;
  }
  int pivot_55 = (aux + st.buffer[1]) & 3;
  switch (pivot_55)
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
  int delta_44 = local_arr[aux % 3];
  acc = (acc + (delta_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_18_1 = local_arr_1[aux_1 % 3];
  int accumulator_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_71_1) & 63;
  aux_2 = (aux_2 + damping_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_51_1)
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

  switch (offset_51_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  assert(damping_71_1 == damping_71_2);
  assert(offset_51_1 == offset_51_2);
}

int fn_R000997_1724_11(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int accumulator_18 = local_arr[aux % 3];
  acc = (acc + (accumulator_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_71) & 63;
  acc ^= aux;
  int offset_51 = (aux + st.buffer[1]) & 3;
  switch (offset_51)
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

void fn_R000997_1724_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_29_1 = local_arr_1[aux_1 % 3];
  int mask_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_29_2 * 2)) & 127;
  int damping_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_81_1)
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

  switch (damping_81_2)
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

  int tracker_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_66_1 > 40)
  {
    acc_1 = ((acc_1 + (tracker_66_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_66_2 > 40)
  {
    acc_2 = ((acc_2 + (tracker_66_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_29_1 == mask_29_2);
  assert(damping_81_1 == damping_81_2);
  assert(tracker_66_1 == tracker_66_2);
}

int fn_R000997_1724_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int mask_29 = local_arr[aux % 3];
  acc = (acc + (mask_29 * 2)) & 127;
  int damping_81 = (aux + st.buffer[1]) & 3;
  switch (damping_81)
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

  int tracker_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_66 > 40)
  {
    acc = ((acc + (tracker_66 * 2)) + 5) & 127;
    aux ^= tracker_66 & 15;
  }
  else
  {
    acc = ((acc - tracker_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_66_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_66_1 * 2)) + 5) & 127;
    aux_1 ^= bound_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_66_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_66_2 * 2)) + 5) & 127;
    aux_2 ^= bound_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_73_1) & 63;
  aux_2 = (aux_2 + segment_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_17_1 = local_arr_1[aux_1 % 3];
  int quantum_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_66_1 == bound_66_2);
  assert(segment_73_1 == segment_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_17_1 == quantum_17_2);
}

int fn_R000997_1724_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_66 > 18)
  {
    acc = ((acc + (bound_66 * 2)) + 5) & 127;
    aux ^= bound_66 & 15;
  }
  else
  {
    acc = ((acc - bound_66) + 11) & 127;
    aux += 3;
  }
  int segment_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_17 = local_arr[aux % 3];
  acc = (acc + (quantum_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_63_1)
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

  switch (anchor_63_2)
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

  int cursor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_31_1 > 12)
  {
    acc_1 = ((acc_1 + (cursor_31_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_31_2 > 12)
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
  int accumulator_56_1 = local_arr_1[aux_1 % 3];
  int accumulator_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_63_1 == anchor_63_2);
  assert(cursor_31_1 == cursor_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_56_1 == accumulator_56_2);
}

int fn_R000997_1724_14(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_63 = (aux + st.buffer[1]) & 3;
  switch (anchor_63)
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

  int cursor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_31 > 12)
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
  int accumulator_56 = local_arr[aux % 3];
  acc = (acc + (accumulator_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
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
  int quantum_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_52_1)
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

  switch (quantum_52_2)
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

  int coefficient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_38_1) & 63;
  aux_2 = (aux_2 + coefficient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_52_1 == quantum_52_2);
  assert(coefficient_38_1 == coefficient_38_2);
}

int fn_R000997_1724_15(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_52 = (aux + st.buffer[1]) & 3;
  switch (quantum_52)
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

  int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000997_1724_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_65_1 > 16)
  {
    acc_1 = ((acc_1 + (bound_65_1 * 2)) + 5) & 127;
    aux_1 ^= bound_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_65_2 > 16)
  {
    acc_2 = ((acc_2 + (bound_65_2 * 2)) + 5) & 127;
    aux_2 ^= bound_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_11_1 = local_arr_1[aux_1 % 3];
  int sample_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_11_2 * 2)) & 127;
  int quantum_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_67_1)
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

  switch (quantum_67_2)
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

  int quotient_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_66_1) & 63;
  aux_2 = (aux_2 + quotient_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_65_1 == bound_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_11_1 == sample_11_2);
  assert(quantum_67_1 == quantum_67_2);
  assert(quotient_66_1 == quotient_66_2);
}

int fn_R000997_1724_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_65 > 16)
  {
    acc = ((acc + (bound_65 * 2)) + 5) & 127;
    aux ^= bound_65 & 15;
  }
  else
  {
    acc = ((acc - bound_65) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_11 = local_arr[aux % 3];
  acc = (acc + (sample_11 * 2)) & 127;
  int quantum_67 = (aux + st.buffer[1]) & 3;
  switch (quantum_67)
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

  int quotient_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000997_1724_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_78_1)
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

  switch (accumulator_78_2)
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

  int mask_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_25_1 > 20)
  {
    acc_1 = ((acc_1 + (mask_25_1 * 2)) + 5) & 127;
    aux_1 ^= mask_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_25_2 > 20)
  {
    acc_2 = ((acc_2 + (mask_25_2 * 2)) + 5) & 127;
    aux_2 ^= mask_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_78_1 == accumulator_78_2);
  assert(mask_25_1 == mask_25_2);
}

int fn_R000997_1724_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_78 = (aux + st.buffer[1]) & 3;
  switch (accumulator_78)
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

  int mask_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_25 > 20)
  {
    acc = ((acc + (mask_25 * 2)) + 5) & 127;
    aux ^= mask_25 & 15;
  }
  else
  {
    acc = ((acc - mask_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_69_1)
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

  switch (mask_69_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_69_1 == mask_69_2);
}

int fn_R000997_1724_18(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_69 = (aux + st.buffer[1]) & 3;
  switch (mask_69)
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

void fn_R000997_1724_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_85_1)
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

  switch (quantum_85_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_86_1 = local_arr_1[aux_1 % 3];
  int vector_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_86_2 * 2)) & 127;
  int pivot_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_22_1) & 63;
  aux_2 = (aux_2 + pivot_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_30_1 > 38)
  {
    acc_1 = ((acc_1 + (quotient_30_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_30_2 > 38)
  {
    acc_2 = ((acc_2 + (quotient_30_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_85_1 == quantum_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_86_1 == vector_86_2);
  assert(pivot_22_1 == pivot_22_2);
  assert(quotient_30_1 == quotient_30_2);
}

int fn_R000997_1724_19(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_85 = (aux + st.buffer[1]) & 3;
  switch (quantum_85)
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

  int local_arr[3] = {4, 9, 15};
  int vector_86 = local_arr[aux % 3];
  acc = (acc + (vector_86 * 2)) & 127;
  int pivot_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_22) & 63;
  acc ^= aux;
  int quotient_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_30 > 38)
  {
    acc = ((acc + (quotient_30 * 2)) + 5) & 127;
    aux ^= quotient_30 & 15;
  }
  else
  {
    acc = ((acc - quotient_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quotient_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_89_1) & 63;
  aux_2 = (aux_2 + quotient_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_38_1 = local_arr_1[aux_1 % 3];
  int threshold_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_59_1 > 25)
  {
    acc_1 = ((acc_1 + (checksum_59_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_59_2 > 25)
  {
    acc_2 = ((acc_2 + (checksum_59_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_89_1 == quotient_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_38_1 == threshold_38_2);
  assert(checksum_59_1 == checksum_59_2);
}

int fn_R000997_1724_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quotient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_38 = local_arr[aux % 3];
  acc = (acc + (threshold_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_59 > 25)
  {
    acc = ((acc + (checksum_59 * 2)) + 5) & 127;
    aux ^= checksum_59 & 15;
  }
  else
  {
    acc = ((acc - checksum_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st_1 = {0};
  struct AudioFrame_R000997_1724_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_72_1 > 25)
  {
    acc_1 = ((acc_1 + (damping_72_1 * 2)) + 5) & 127;
    aux_1 ^= damping_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_72_2 > 25)
  {
    acc_2 = ((acc_2 + (damping_72_2 * 2)) + 5) & 127;
    aux_2 ^= damping_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_51_1 = local_arr_1[aux_1 % 3];
  int mask_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_72_1 == damping_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_51_1 == mask_51_2);
}

int fn_R000997_1724_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000997_1724_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_72 > 25)
  {
    acc = ((acc + (damping_72 * 2)) + 5) & 127;
    aux ^= damping_72 & 15;
  }
  else
  {
    acc = ((acc - damping_72) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_51 = local_arr[aux % 3];
  acc = (acc + (mask_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000997_1724_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st_1 = {0};
  struct CipherContext_R000997_1724_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quotient_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_76_1)
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

  switch (quotient_76_2)
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

  int metric_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_90_1) & 63;
  aux_2 = (aux_2 + metric_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_65_1 = local_arr_1[aux_1 % 3];
  int checksum_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_65_2 * 2)) & 127;
  int sample_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_53_1 > 18)
  {
    acc_1 = ((acc_1 + (sample_53_1 * 2)) + 5) & 127;
    aux_1 ^= sample_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_53_2 > 18)
  {
    acc_2 = ((acc_2 + (sample_53_2 * 2)) + 5) & 127;
    aux_2 ^= sample_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_76_1 == quotient_76_2);
  assert(metric_90_1 == metric_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_65_1 == checksum_65_2);
  assert(sample_53_1 == sample_53_2);
}

int fn_R000997_1724_22(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000997_1724_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quotient_76 = (aux + st.buffer[1]) & 3;
  switch (quotient_76)
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

  int metric_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_65 = local_arr[aux % 3];
  acc = (acc + (checksum_65 * 2)) & 127;
  int sample_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_53 > 18)
  {
    acc = ((acc + (sample_53 * 2)) + 5) & 127;
    aux ^= sample_53 & 15;
  }
  else
  {
    acc = ((acc - sample_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000997_1724_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st_1 = {0};
  struct Vector3D_R000997_1724_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_72_1) & 63;
  aux_2 = (aux_2 + coefficient_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_13_1)
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

  switch (cursor_13_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_72_1 == coefficient_72_2);
  assert(cursor_13_1 == cursor_13_2);
}

int fn_R000997_1724_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000997_1724_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_72) & 63;
  acc ^= aux;
  int cursor_13 = (aux + st.buffer[1]) & 3;
  switch (cursor_13)
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
  int sec_r000997_0_1;
  int sec_r000997_0_2;
  int sec_r000997_1_1;
  int sec_r000997_1_2;
  int sec_r000997_2_1;
  int sec_r000997_2_2;
  int sec_r000997_3_1;
  int sec_r000997_3_2;
  int sec_r000997_4_1;
  int sec_r000997_4_2;
  int sec_r000997_5_1;
  int sec_r000997_5_2;
  int sec_r000997_6_1;
  int sec_r000997_6_2;
  int sec_r000997_7_1;
  int sec_r000997_7_2;
  int sec_r000997_8_1;
  int sec_r000997_8_2;
  int sec_r000997_9_1;
  int sec_r000997_9_2;
  int sec_r000997_10_1;
  int sec_r000997_10_2;
  int sec_r000997_11_1;
  int sec_r000997_11_2;
  int sec_r000997_12_1;
  int sec_r000997_12_2;
  int sec_r000997_13_1;
  int sec_r000997_13_2;
  int sec_r000997_14_1;
  int sec_r000997_14_2;
  int sec_r000997_15_1;
  int sec_r000997_15_2;
  int pub_r000997_0_1;
  int pub_r000997_0_2;
  int pub_r000997_1_1;
  int pub_r000997_1_2;
  int pub_r000997_2_1;
  int pub_r000997_2_2;
  int pub_r000997_3_1;
  int pub_r000997_3_2;
  int pub_r000997_4_1;
  int pub_r000997_4_2;
  int pub_r000997_5_1;
  int pub_r000997_5_2;
  int pub_r000997_6_1;
  int pub_r000997_6_2;
  int pub_r000997_7_1;
  int pub_r000997_7_2;
  int pub_r000997_8_1;
  int pub_r000997_8_2;
  int pub_r000997_9_1;
  int pub_r000997_9_2;
  int pub_r000997_10_1;
  int pub_r000997_10_2;
  int pub_r000997_11_1;
  int pub_r000997_11_2;
  int pub_r000997_12_1;
  int pub_r000997_12_2;
  int pub_r000997_13_1;
  int pub_r000997_13_2;
  int pub_r000997_14_1;
  int pub_r000997_14_2;
  int pub_r000997_15_1;
  int pub_r000997_15_2;
  int pub_r000997_16_1;
  int pub_r000997_16_2;
  int pub_r000997_17_1;
  int pub_r000997_17_2;
  int pub_r000997_18_1;
  int pub_r000997_18_2;
  int pub_r000997_19_1;
  int pub_r000997_19_2;
  int pub_r000997_20_1;
  int pub_r000997_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000997_0_1 >= (-100)) && (pub_r000997_0_1 <= 100));
  __CPROVER_assume((pub_r000997_0_2 >= (-100)) && (pub_r000997_0_2 <= 100));
  __CPROVER_assume((pub_r000997_1_1 >= (-100)) && (pub_r000997_1_1 <= 100));
  __CPROVER_assume((pub_r000997_1_2 >= (-100)) && (pub_r000997_1_2 <= 100));
  __CPROVER_assume((pub_r000997_2_1 >= (-100)) && (pub_r000997_2_1 <= 100));
  __CPROVER_assume((pub_r000997_2_2 >= (-100)) && (pub_r000997_2_2 <= 100));
  __CPROVER_assume((pub_r000997_3_1 >= (-100)) && (pub_r000997_3_1 <= 100));
  __CPROVER_assume((pub_r000997_3_2 >= (-100)) && (pub_r000997_3_2 <= 100));
  __CPROVER_assume((pub_r000997_4_1 >= (-100)) && (pub_r000997_4_1 <= 100));
  __CPROVER_assume((pub_r000997_4_2 >= (-100)) && (pub_r000997_4_2 <= 100));
  __CPROVER_assume((pub_r000997_5_1 >= (-100)) && (pub_r000997_5_1 <= 100));
  __CPROVER_assume((pub_r000997_5_2 >= (-100)) && (pub_r000997_5_2 <= 100));
  __CPROVER_assume((pub_r000997_6_1 >= (-100)) && (pub_r000997_6_1 <= 100));
  __CPROVER_assume((pub_r000997_6_2 >= (-100)) && (pub_r000997_6_2 <= 100));
  __CPROVER_assume((pub_r000997_7_1 >= (-100)) && (pub_r000997_7_1 <= 100));
  __CPROVER_assume((pub_r000997_7_2 >= (-100)) && (pub_r000997_7_2 <= 100));
  __CPROVER_assume((pub_r000997_8_1 >= (-100)) && (pub_r000997_8_1 <= 100));
  __CPROVER_assume((pub_r000997_8_2 >= (-100)) && (pub_r000997_8_2 <= 100));
  __CPROVER_assume((pub_r000997_9_1 >= (-100)) && (pub_r000997_9_1 <= 100));
  __CPROVER_assume((pub_r000997_9_2 >= (-100)) && (pub_r000997_9_2 <= 100));
  __CPROVER_assume((pub_r000997_10_1 >= (-100)) && (pub_r000997_10_1 <= 100));
  __CPROVER_assume((pub_r000997_10_2 >= (-100)) && (pub_r000997_10_2 <= 100));
  __CPROVER_assume((pub_r000997_11_1 >= (-100)) && (pub_r000997_11_1 <= 100));
  __CPROVER_assume((pub_r000997_11_2 >= (-100)) && (pub_r000997_11_2 <= 100));
  __CPROVER_assume((pub_r000997_12_1 >= (-100)) && (pub_r000997_12_1 <= 100));
  __CPROVER_assume((pub_r000997_12_2 >= (-100)) && (pub_r000997_12_2 <= 100));
  __CPROVER_assume((pub_r000997_13_1 >= (-100)) && (pub_r000997_13_1 <= 100));
  __CPROVER_assume((pub_r000997_13_2 >= (-100)) && (pub_r000997_13_2 <= 100));
  __CPROVER_assume((pub_r000997_14_1 >= (-100)) && (pub_r000997_14_1 <= 100));
  __CPROVER_assume((pub_r000997_14_2 >= (-100)) && (pub_r000997_14_2 <= 100));
  __CPROVER_assume((pub_r000997_15_1 >= (-100)) && (pub_r000997_15_1 <= 100));
  __CPROVER_assume((pub_r000997_15_2 >= (-100)) && (pub_r000997_15_2 <= 100));
  __CPROVER_assume((pub_r000997_16_1 >= (-100)) && (pub_r000997_16_1 <= 100));
  __CPROVER_assume((pub_r000997_16_2 >= (-100)) && (pub_r000997_16_2 <= 100));
  __CPROVER_assume((pub_r000997_17_1 >= (-100)) && (pub_r000997_17_1 <= 100));
  __CPROVER_assume((pub_r000997_17_2 >= (-100)) && (pub_r000997_17_2 <= 100));
  __CPROVER_assume((pub_r000997_18_1 >= (-100)) && (pub_r000997_18_1 <= 100));
  __CPROVER_assume((pub_r000997_18_2 >= (-100)) && (pub_r000997_18_2 <= 100));
  __CPROVER_assume((pub_r000997_19_1 >= (-100)) && (pub_r000997_19_1 <= 100));
  __CPROVER_assume((pub_r000997_19_2 >= (-100)) && (pub_r000997_19_2 <= 100));
  __CPROVER_assume((pub_r000997_20_1 >= (-100)) && (pub_r000997_20_1 <= 100));
  __CPROVER_assume((pub_r000997_20_2 >= (-100)) && (pub_r000997_20_2 <= 100));
  __CPROVER_assume((sec_r000997_0_1 >= 0) && (sec_r000997_0_1 <= 255));
  __CPROVER_assume((sec_r000997_0_2 >= 0) && (sec_r000997_0_2 <= 255));
  __CPROVER_assume((sec_r000997_1_1 >= 0) && (sec_r000997_1_1 <= 255));
  __CPROVER_assume((sec_r000997_1_2 >= 0) && (sec_r000997_1_2 <= 255));
  __CPROVER_assume((sec_r000997_2_1 >= 0) && (sec_r000997_2_1 <= 255));
  __CPROVER_assume((sec_r000997_2_2 >= 0) && (sec_r000997_2_2 <= 255));
  __CPROVER_assume((sec_r000997_3_1 >= 0) && (sec_r000997_3_1 <= 255));
  __CPROVER_assume((sec_r000997_3_2 >= 0) && (sec_r000997_3_2 <= 255));
  __CPROVER_assume((sec_r000997_4_1 >= 0) && (sec_r000997_4_1 <= 255));
  __CPROVER_assume((sec_r000997_4_2 >= 0) && (sec_r000997_4_2 <= 255));
  __CPROVER_assume((sec_r000997_5_1 >= 0) && (sec_r000997_5_1 <= 255));
  __CPROVER_assume((sec_r000997_5_2 >= 0) && (sec_r000997_5_2 <= 255));
  __CPROVER_assume((sec_r000997_6_1 >= 0) && (sec_r000997_6_1 <= 255));
  __CPROVER_assume((sec_r000997_6_2 >= 0) && (sec_r000997_6_2 <= 255));
  __CPROVER_assume((sec_r000997_7_1 >= 0) && (sec_r000997_7_1 <= 255));
  __CPROVER_assume((sec_r000997_7_2 >= 0) && (sec_r000997_7_2 <= 255));
  __CPROVER_assume((sec_r000997_8_1 >= 0) && (sec_r000997_8_1 <= 255));
  __CPROVER_assume((sec_r000997_8_2 >= 0) && (sec_r000997_8_2 <= 255));
  __CPROVER_assume((sec_r000997_9_1 >= 0) && (sec_r000997_9_1 <= 255));
  __CPROVER_assume((sec_r000997_9_2 >= 0) && (sec_r000997_9_2 <= 255));
  __CPROVER_assume((sec_r000997_10_1 >= 0) && (sec_r000997_10_1 <= 255));
  __CPROVER_assume((sec_r000997_10_2 >= 0) && (sec_r000997_10_2 <= 255));
  __CPROVER_assume((sec_r000997_11_1 >= 0) && (sec_r000997_11_1 <= 255));
  __CPROVER_assume((sec_r000997_11_2 >= 0) && (sec_r000997_11_2 <= 255));
  __CPROVER_assume((sec_r000997_12_1 >= 0) && (sec_r000997_12_1 <= 255));
  __CPROVER_assume((sec_r000997_12_2 >= 0) && (sec_r000997_12_2 <= 255));
  __CPROVER_assume((sec_r000997_13_1 >= 0) && (sec_r000997_13_1 <= 255));
  __CPROVER_assume((sec_r000997_13_2 >= 0) && (sec_r000997_13_2 <= 255));
  __CPROVER_assume((sec_r000997_14_1 >= 0) && (sec_r000997_14_1 <= 255));
  __CPROVER_assume((sec_r000997_14_2 >= 0) && (sec_r000997_14_2 <= 255));
  __CPROVER_assume((sec_r000997_15_1 >= 0) && (sec_r000997_15_1 <= 255));
  __CPROVER_assume((sec_r000997_15_2 >= 0) && (sec_r000997_15_2 <= 255));
  struct Vector3D_R000997_1724_0 st_var_0_1 = {0};
  struct Vector3D_R000997_1724_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000997_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000997_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000997_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000997_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000997_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000997_0_2 + 7) & 15;
  struct CipherContext_R000997_1724_1 st_var_1_1 = {0};
  struct CipherContext_R000997_1724_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000997_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000997_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000997_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000997_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000997_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000997_0_2 + 9) & 15;
  struct AudioFrame_R000997_1724_2 st_var_2_1 = {0};
  struct AudioFrame_R000997_1724_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000997_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000997_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000997_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000997_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000997_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000997_0_2 + 11) & 15;
  union PacketPayload_R000997_1724_0 u_var_1;
  union PacketPayload_R000997_1724_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 28)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 28)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 50)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 50)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 51)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 51)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = ((st_var_1_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_1_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 47)
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
  if (stage_v_31_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 47)
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
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 30)
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
  if (stage_v_32_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 30)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((st_var_2_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_2_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 31)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 31)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 49)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 49)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (st_var_2_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_2_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 47) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
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

  switch (stage_v_47_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
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

  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 50)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 50)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 52)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 52)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 52) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = ((st_var_2_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_2_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 38)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 38)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 57) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((st_var_1_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_1_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 32)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 32)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (st_var_0_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_0_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_63_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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
  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = ((st_var_1_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_1_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 34)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 34)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 53)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 53)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 77) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = (st_var_2_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_2_2.buffer[0] ^ 80) & 3;
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

  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = (st_var_2_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_2_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_84_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000997_3_1 & 1) != 0)
  {
    if ((sec_r000997_14_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000997_8_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000997_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000997_8_1 + 7) & 127;
  }
  if ((sec_r000997_3_2 & 1) != 0)
  {
    if ((sec_r000997_14_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000997_8_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000997_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000997_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000997_1_1 & 1) != 0)
  {
    if ((sec_r000997_10_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000997_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000997_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000997_11_1 + 7) & 127;
  }
  if ((sec_r000997_1_2 & 1) != 0)
  {
    if ((sec_r000997_10_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000997_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000997_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000997_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000997_2_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000997_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000997_2_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000997_2_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000997_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000997_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000997_10_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000997_9_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000997_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000997_9_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000997_10_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000997_9_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000997_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000997_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000997_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000997_3_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000997_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000997_3_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000997_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000997_3_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000997_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000997_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000997_11_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000997_15_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000997_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000997_15_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000997_11_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000997_15_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000997_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000997_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000997_13_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000997_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000997_13_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000997_13_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000997_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000997_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000997_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000997_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000997_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000997_5_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000997_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000997_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000997_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000997_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000997_8_1 & 1) != 0)
  {
    if ((sec_r000997_3_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000997_14_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000997_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000997_14_1 + 7) & 127;
  }
  if ((sec_r000997_8_2 & 1) != 0)
  {
    if ((sec_r000997_3_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000997_14_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000997_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000997_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000997_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000997_1_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000997_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000997_1_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000997_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000997_1_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000997_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000997_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000997_9_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000997_2_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000997_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000997_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000997_9_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000997_2_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000997_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000997_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000997_6_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000997_6_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000997_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000997_6_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000997_6_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000997_6_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000997_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000997_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000997_2_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((sec_r000997_2_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000997_7_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000997_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000997_7_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000997_7_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000997_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000997_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000997_0_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000997_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000997_0_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000997_0_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000997_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000997_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000997_9_1 & 1) != 0)
  {
    if ((sec_r000997_2_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000997_11_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000997_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000997_11_1 + 7) & 127;
  }
  if ((sec_r000997_9_2 & 1) != 0)
  {
    if ((sec_r000997_2_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000997_11_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000997_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000997_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000997_1_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000997_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000997_1_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000997_1_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000997_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000997_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000997_7_1 & 1) != 0)
  {
    if ((sec_r000997_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000997_17_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000997_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000997_17_1 + 7) & 127;
  }
  if ((sec_r000997_7_2 & 1) != 0)
  {
    if ((sec_r000997_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000997_17_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000997_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000997_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000997_12_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000997_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000997_12_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000997_12_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000997_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000997_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000997_0_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000997_15_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000997_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000997_15_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000997_0_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000997_15_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000997_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000997_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000997_10_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000997_1_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000997_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000997_1_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000997_10_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000997_1_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000997_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000997_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000997_4_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000997_18_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000997_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000997_18_1 + 7) & 127;
  }
  if ((sec_r000997_4_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000997_18_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000997_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000997_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000997_4_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000997_13_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000997_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000997_13_1 + 7) & 127;
  }
  if ((sec_r000997_4_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000997_13_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000997_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000997_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000997_8_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000997_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000997_8_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000997_8_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000997_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000997_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000997_17_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000997_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000997_17_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000997_17_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000997_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000997_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000997_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000997_11_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000997_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000997_11_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000997_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000997_11_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000997_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000997_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000997_0_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000997_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000997_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000997_8_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000997_0_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000997_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000997_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000997_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000997_17_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000997_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000997_17_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000997_17_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000997_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000997_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000997_15_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000997_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000997_15_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000997_15_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000997_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000997_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000997_12_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000997_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000997_12_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000997_12_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000997_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000997_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000997_13_1 & 1) != 0)
  {
    if ((sec_r000997_14_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000997_9_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000997_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000997_9_1 + 7) & 127;
  }
  if ((sec_r000997_13_2 & 1) != 0)
  {
    if ((sec_r000997_14_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000997_9_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000997_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000997_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000997_13_1 & 1) != 0)
  {
    if ((sec_r000997_0_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((sec_r000997_13_2 & 1) != 0)
  {
    if ((sec_r000997_0_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000997_2_1 & 1) != 0)
  {
    if ((sec_r000997_1_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000997_2_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000997_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000997_2_1 + 7) & 127;
  }
  if ((sec_r000997_2_2 & 1) != 0)
  {
    if ((sec_r000997_1_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000997_2_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000997_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000997_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000997_3_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000997_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000997_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000997_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000997_3_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000997_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000997_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000997_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000997_6_1 & 1) != 0)
  {
    if ((sec_r000997_12_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000997_14_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000997_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000997_14_1 + 7) & 127;
  }
  if ((sec_r000997_6_2 & 1) != 0)
  {
    if ((sec_r000997_12_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000997_14_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000997_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000997_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000997_13_1 & 1) != 0)
  {
    if ((sec_r000997_11_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000997_18_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000997_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000997_18_1 + 7) & 127;
  }
  if ((sec_r000997_13_2 & 1) != 0)
  {
    if ((sec_r000997_11_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000997_18_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000997_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000997_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000997_0_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000997_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000997_0_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000997_0_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000997_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000997_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000997_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000997_14_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000997_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000997_14_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000997_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000997_14_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000997_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000997_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000997_0_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000997_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000997_0_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000997_0_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000997_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000997_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000997_1_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000997_2_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000997_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000997_2_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000997_1_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000997_2_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000997_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000997_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000997_5_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000997_1_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000997_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000997_1_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000997_5_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000997_1_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000997_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000997_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000997_8_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000997_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000997_8_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000997_8_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000997_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000997_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000997_0_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000997_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000997_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000997_13_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000997_0_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000997_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000997_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000997_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000997_3_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000997_10_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000997_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000997_10_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000997_3_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000997_10_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000997_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000997_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000997_12_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000997_9_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000997_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000997_9_1 + 7) & 127;
  }
  if ((sec_r000997_12_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000997_9_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000997_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000997_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000997_7_1 & 1) != 0)
  {
    if ((sec_r000997_1_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000997_14_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000997_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000997_14_1 + 7) & 127;
  }
  if ((sec_r000997_7_2 & 1) != 0)
  {
    if ((sec_r000997_1_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000997_14_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000997_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000997_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000997_11_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000997_14_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000997_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000997_14_1 + 7) & 127;
  }
  if ((sec_r000997_11_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000997_14_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000997_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000997_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000997_8_1 & 1) != 0)
  {
    if ((sec_r000997_15_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000997_5_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000997_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000997_5_1 + 7) & 127;
  }
  if ((sec_r000997_8_2 & 1) != 0)
  {
    if ((sec_r000997_15_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000997_5_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000997_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000997_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000997_15_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000997_3_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000997_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000997_3_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000997_15_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000997_3_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000997_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000997_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000997_12_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000997_15_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000997_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000997_15_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000997_12_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000997_15_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000997_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000997_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000997_2_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000997_10_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000997_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000997_10_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000997_2_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000997_10_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000997_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000997_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000997_3_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000997_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000997_3_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000997_3_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000997_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000997_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000997_3_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000997_3_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000997_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000997_3_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000997_3_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000997_3_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000997_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000997_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000997_11_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000997_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000997_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000997_11_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000997_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000997_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000997_8_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000997_4_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000997_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000997_4_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000997_8_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000997_4_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000997_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000997_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000997_11_1 & 1) != 0)
  {
    if ((sec_r000997_7_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000997_8_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000997_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000997_8_1 + 7) & 127;
  }
  if ((sec_r000997_11_2 & 1) != 0)
  {
    if ((sec_r000997_7_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000997_8_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000997_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000997_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000997_13_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000997_18_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000997_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000997_18_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000997_13_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000997_18_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000997_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000997_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000997_14_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000997_7_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000997_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000997_7_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000997_14_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000997_7_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000997_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000997_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000997_5_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000997_10_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000997_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000997_10_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000997_5_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000997_10_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000997_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000997_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000997_14_1 & 1) != 0)
  {
    if ((sec_r000997_4_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000997_20_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000997_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000997_20_1 + 7) & 127;
  }
  if ((sec_r000997_14_2 & 1) != 0)
  {
    if ((sec_r000997_4_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000997_20_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000997_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000997_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000997_10_1 == pub_r000997_10_2);
  __CPROVER_assume(pub_r000997_15_1 == pub_r000997_15_2);
  __CPROVER_assume(pub_r000997_9_1 == pub_r000997_9_2);
  __CPROVER_assume(pub_r000997_0_1 == pub_r000997_0_2);
  __CPROVER_assume(pub_r000997_6_1 == pub_r000997_6_2);
  __CPROVER_assume(pub_r000997_16_1 == pub_r000997_16_2);
  __CPROVER_assume(pub_r000997_18_1 == pub_r000997_18_2);
  __CPROVER_assume(sec_r000997_6_1 != sec_r000997_6_2);
  __CPROVER_assume(pub_r000997_20_1 == pub_r000997_20_2);
  __CPROVER_assume(sec_r000997_3_1 != sec_r000997_3_2);
  __CPROVER_assume(pub_r000997_4_1 == pub_r000997_4_2);
  __CPROVER_assume(pub_r000997_12_1 == pub_r000997_12_2);
  __CPROVER_assume(pub_r000997_13_1 == pub_r000997_13_2);
  __CPROVER_assume(sec_r000997_10_1 != sec_r000997_10_2);
  __CPROVER_assume(pub_r000997_2_1 == pub_r000997_2_2);
  __CPROVER_assume(pub_r000997_5_1 == pub_r000997_5_2);
  __CPROVER_assume(sec_r000997_14_1 != sec_r000997_14_2);
  __CPROVER_assume(pub_r000997_1_1 == pub_r000997_1_2);
  __CPROVER_assume(pub_r000997_7_1 == pub_r000997_7_2);
  __CPROVER_assume(pub_r000997_8_1 == pub_r000997_8_2);
  __CPROVER_assume(sec_r000997_1_1 != sec_r000997_1_2);
  __CPROVER_assume(pub_r000997_19_1 == pub_r000997_19_2);
  __CPROVER_assume(sec_r000997_2_1 != sec_r000997_2_2);
  __CPROVER_assume(sec_r000997_13_1 != sec_r000997_13_2);
  __CPROVER_assume(pub_r000997_17_1 == pub_r000997_17_2);
  __CPROVER_assume(sec_r000997_4_1 != sec_r000997_4_2);
  __CPROVER_assume(sec_r000997_5_1 != sec_r000997_5_2);
  __CPROVER_assume(sec_r000997_15_1 != sec_r000997_15_2);
  __CPROVER_assume(pub_r000997_3_1 == pub_r000997_3_2);
  __CPROVER_assume(sec_r000997_11_1 != sec_r000997_11_2);
  __CPROVER_assume(sec_r000997_7_1 != sec_r000997_7_2);
  __CPROVER_assume(sec_r000997_9_1 != sec_r000997_9_2);
  __CPROVER_assume(pub_r000997_14_1 == pub_r000997_14_2);
  __CPROVER_assume(sec_r000997_8_1 != sec_r000997_8_2);
  __CPROVER_assume(sec_r000997_0_1 != sec_r000997_0_2);
  __CPROVER_assume(sec_r000997_12_1 != sec_r000997_12_2);
  __CPROVER_assume(pub_r000997_11_1 == pub_r000997_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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
}


