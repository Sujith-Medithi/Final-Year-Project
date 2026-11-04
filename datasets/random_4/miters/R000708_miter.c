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
struct Vector3D_R000708_813_0
{
  int coord_x;
  int pitch;
  int coord_y;
  int buffer[3];
};
struct CipherContext_R000708_813_1
{
  int tag;
  int counter;
  unsigned char nonce;
  int buffer[3];
};
struct AudioFrame_R000708_813_2
{
  int peak;
  short channels;
  short envelope;
  unsigned char gain;
  unsigned char rms;
  unsigned char sample_rate;
  int buffer[3];
};
union PacketPayload_R000708_813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000708_813_1
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
void fn_R000708_813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_62_1) & 63;
  aux_2 = (aux_2 + checksum_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_31_1)
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

  switch (coefficient_31_2)
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
  int window_85_1 = local_arr_1[aux_1 % 3];
  int window_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_62_1 == checksum_62_2);
  assert(coefficient_31_1 == coefficient_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_85_1 == window_85_2);
}

int fn_R000708_813_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_62) & 63;
  acc ^= aux;
  int coefficient_31 = (aux + st.buffer[1]) & 3;
  switch (coefficient_31)
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
  int window_85 = local_arr[aux % 3];
  acc = (acc + (window_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_39_1) & 63;
  aux_2 = (aux_2 + accumulator_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_64_1)
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

  switch (delta_64_2)
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

  int cursor_47_1 = 0;
  int cursor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_47_1 = ((cursor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_47_2 = ((cursor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_47_1) & 127;
    acc_2 = (acc_2 + cursor_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_39_1 == accumulator_39_2);
  assert(delta_64_1 == delta_64_2);
  assert(cursor_47_1 == cursor_47_2);
}

int fn_R000708_813_1(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_39) & 63;
  acc ^= aux;
  int delta_64 = (aux + st.buffer[1]) & 3;
  switch (delta_64)
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

  int cursor_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_47 = ((cursor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int residue_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_46_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_46_1 * 2)) + 5) & 127;
    aux_1 ^= residue_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_46_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_46_2 * 2)) + 5) & 127;
    aux_2 ^= residue_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_93_1) & 63;
  aux_2 = (aux_2 + delta_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_46_1 == residue_46_2);
  assert(delta_93_1 == delta_93_2);
}

int fn_R000708_813_2(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int residue_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_46 > 44)
  {
    acc = ((acc + (residue_46 * 2)) + 5) & 127;
    aux ^= residue_46 & 15;
  }
  else
  {
    acc = ((acc - residue_46) + 11) & 127;
    aux += 3;
  }
  int delta_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000708_813_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_48_1 > 37)
  {
    acc_1 = ((acc_1 + (metric_48_1 * 2)) + 5) & 127;
    aux_1 ^= metric_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_48_2 > 37)
  {
    acc_2 = ((acc_2 + (metric_48_2 * 2)) + 5) & 127;
    aux_2 ^= metric_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_59_1) & 63;
  aux_2 = (aux_2 + window_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_48_1 == metric_48_2);
  assert(window_59_1 == window_59_2);
}

int fn_R000708_813_3(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_48 > 37)
  {
    acc = ((acc + (metric_48 * 2)) + 5) & 127;
    aux ^= metric_48 & 15;
  }
  else
  {
    acc = ((acc - metric_48) + 11) & 127;
    aux += 3;
  }
  int window_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st_1 = {0};
  struct Vector3D_R000708_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int vector_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_75_1)
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

  switch (vector_75_2)
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

  int damping_11_1 = 0;
  int damping_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_11_1 = ((damping_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_11_2 = ((damping_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_11_1) & 127;
    acc_2 = (acc_2 + damping_11_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_49_1 = local_arr_1[aux_1 % 3];
  int tally_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_49_2 * 2)) & 127;
  int parity_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_67_1 > 30)
  {
    acc_1 = ((acc_1 + (parity_67_1 * 2)) + 5) & 127;
    aux_1 ^= parity_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_67_2 > 30)
  {
    acc_2 = ((acc_2 + (parity_67_2 * 2)) + 5) & 127;
    aux_2 ^= parity_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_75_1 == vector_75_2);
  assert(damping_11_1 == damping_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_49_1 == tally_49_2);
  assert(parity_67_1 == parity_67_2);
}

int fn_R000708_813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int vector_75 = (aux + st.buffer[1]) & 3;
  switch (vector_75)
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

  int damping_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_11 = ((damping_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_11) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_49 = local_arr[aux % 3];
  acc = (acc + (tally_49 * 2)) & 127;
  int parity_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_67 > 30)
  {
    acc = ((acc + (parity_67 * 2)) + 5) & 127;
    aux ^= parity_67 & 15;
  }
  else
  {
    acc = ((acc - parity_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000708_813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int window_48_1 = 0;
  int window_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_48_1 = ((window_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_48_2 = ((window_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_48_1) & 127;
    acc_2 = (acc_2 + window_48_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_92_1 = local_arr_1[aux_1 % 3];
  int mask_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_92_2 * 2)) & 127;
  int mask_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_87_1)
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

  switch (mask_87_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_48_1 == window_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_92_1 == mask_92_2);
  assert(mask_87_1 == mask_87_2);
}

int fn_R000708_813_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int window_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_48 = ((window_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_48) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_92 = local_arr[aux % 3];
  acc = (acc + (mask_92 * 2)) & 127;
  int mask_87 = (aux + st.buffer[1]) & 3;
  switch (mask_87)
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

void fn_R000708_813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_62_1 = local_arr_1[aux_1 % 3];
  int tracker_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_62_2 * 2)) & 127;
  int offset_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_79_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_79_1 * 2)) + 5) & 127;
    aux_1 ^= offset_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_79_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_79_2 * 2)) + 5) & 127;
    aux_2 ^= offset_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_62_1 == tracker_62_2);
  assert(offset_79_1 == offset_79_2);
}

int fn_R000708_813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tracker_62 = local_arr[aux % 3];
  acc = (acc + (tracker_62 * 2)) & 127;
  int offset_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_79 > 36)
  {
    acc = ((acc + (offset_79 * 2)) + 5) & 127;
    aux ^= offset_79 & 15;
  }
  else
  {
    acc = ((acc - offset_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000708_813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st_1 = {0};
  struct Vector3D_R000708_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int margin_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_13_1)
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

  switch (margin_13_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_66_1 = 0;
  int tracker_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_66_1 = ((tracker_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_66_2 = ((tracker_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_66_1) & 127;
    acc_2 = (acc_2 + tracker_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_13_1 == margin_13_2);
  assert(tracker_66_1 == tracker_66_2);
}

int fn_R000708_813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int margin_13 = (aux + st.buffer[1]) & 3;
  switch (margin_13)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_66 = ((tracker_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_34_1 = local_arr_1[aux_1 % 3];
  int quotient_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_34_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_34_1 == quotient_34_2);
}

int fn_R000708_813_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int quotient_34 = local_arr[aux % 3];
  acc = (acc + (quotient_34 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_45_1 > 40)
  {
    acc_1 = ((acc_1 + (threshold_45_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_45_2 > 40)
  {
    acc_2 = ((acc_2 + (threshold_45_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_41_1) & 63;
  aux_2 = (aux_2 + margin_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_62_1 = local_arr_1[aux_1 % 3];
  int pivot_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_62_2 * 2)) & 127;
  int sample_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_30_1)
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

  switch (sample_30_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  assert(margin_41_1 == margin_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(sample_30_1 == sample_30_2);
}

int fn_R000708_813_9(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_45 > 40)
  {
    acc = ((acc + (threshold_45 * 2)) + 5) & 127;
    aux ^= threshold_45 & 15;
  }
  else
  {
    acc = ((acc - threshold_45) + 11) & 127;
    aux += 3;
  }
  int margin_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_62 = local_arr[aux % 3];
  acc = (acc + (pivot_62 * 2)) & 127;
  int sample_30 = (aux + st.buffer[1]) & 3;
  switch (sample_30)
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

void fn_R000708_813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_94_1 = local_arr_1[aux_1 % 3];
  int margin_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_94_2 * 2)) & 127;
  int pivot_90_1 = 0;
  int pivot_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_90_1 = ((pivot_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_90_2 = ((pivot_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_90_1) & 127;
    acc_2 = (acc_2 + pivot_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_94_1 == margin_94_2);
  assert(pivot_90_1 == pivot_90_2);
}

int fn_R000708_813_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int margin_94 = local_arr[aux % 3];
  acc = (acc + (margin_94 * 2)) & 127;
  int pivot_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_90 = ((pivot_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_58_1 = local_arr_1[aux_1 % 3];
  int phase_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_58_2 * 2)) & 127;
  int vector_65_1 = 0;
  int vector_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_65_1 = ((vector_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_65_2 = ((vector_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_65_1) & 127;
    acc_2 = (acc_2 + vector_65_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_58_1 == phase_58_2);
  assert(vector_65_1 == vector_65_2);
}

int fn_R000708_813_11(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int phase_58 = local_arr[aux % 3];
  acc = (acc + (phase_58 * 2)) & 127;
  int vector_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_65 = ((vector_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_65) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_46_1 = 0;
  int tracker_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_46_1 = ((tracker_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_46_2 = ((tracker_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_46_1) & 127;
    acc_2 = (acc_2 + tracker_46_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_80_1 = local_arr_1[aux_1 % 3];
  int window_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_46_1 == tracker_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_80_1 == window_80_2);
}

int fn_R000708_813_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_46 = ((tracker_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_46) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_80 = local_arr[aux % 3];
  acc = (acc + (window_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_65_1 > 14)
  {
    acc_1 = ((acc_1 + (factor_65_1 * 2)) + 5) & 127;
    aux_1 ^= factor_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_65_2 > 14)
  {
    acc_2 = ((acc_2 + (factor_65_2 * 2)) + 5) & 127;
    aux_2 ^= factor_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_34_1)
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

  switch (cursor_34_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_65_1 == factor_65_2);
  assert(cursor_34_1 == cursor_34_2);
}

int fn_R000708_813_13(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_65 > 14)
  {
    acc = ((acc + (factor_65 * 2)) + 5) & 127;
    aux ^= factor_65 & 15;
  }
  else
  {
    acc = ((acc - factor_65) + 11) & 127;
    aux += 3;
  }
  int cursor_34 = (aux + st.buffer[1]) & 3;
  switch (cursor_34)
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

void fn_R000708_813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_41_1) & 63;
  aux_2 = (aux_2 + quotient_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_30_1 > 28)
  {
    acc_1 = ((acc_1 + (index_reg_30_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_30_2 > 28)
  {
    acc_2 = ((acc_2 + (index_reg_30_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_41_1 == quotient_41_2);
  assert(index_reg_30_1 == index_reg_30_2);
}

int fn_R000708_813_14(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_30 > 28)
  {
    acc = ((acc + (index_reg_30 * 2)) + 5) & 127;
    aux ^= index_reg_30 & 15;
  }
  else
  {
    acc = ((acc - index_reg_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000708_813_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int scale_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_49_1) & 63;
  aux_2 = (aux_2 + scale_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_68_1 = 0;
  int delta_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_68_1 = ((delta_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_68_2 = ((delta_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_68_1) & 127;
    acc_2 = (acc_2 + delta_68_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_49_1 == scale_49_2);
  assert(delta_68_1 == delta_68_2);
}

int fn_R000708_813_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int scale_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_49) & 63;
  acc ^= aux;
  int delta_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_68 = ((delta_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_68) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int vector_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_78_1 > 10)
  {
    acc_1 = ((acc_1 + (vector_78_1 * 2)) + 5) & 127;
    aux_1 ^= vector_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_78_2 > 10)
  {
    acc_2 = ((acc_2 + (vector_78_2 * 2)) + 5) & 127;
    aux_2 ^= vector_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_48_1 = 0;
  int window_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_48_1 = ((window_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_48_2 = ((window_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_48_1) & 127;
    acc_2 = (acc_2 + window_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_78_1 == vector_78_2);
  assert(window_48_1 == window_48_2);
}

int fn_R000708_813_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int vector_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_78 > 10)
  {
    acc = ((acc + (vector_78 * 2)) + 5) & 127;
    aux ^= vector_78 & 15;
  }
  else
  {
    acc = ((acc - vector_78) + 11) & 127;
    aux += 3;
  }
  int window_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_48 = ((window_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_86_1 > 44)
  {
    acc_1 = ((acc_1 + (segment_86_1 * 2)) + 5) & 127;
    aux_1 ^= segment_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_86_2 > 44)
  {
    acc_2 = ((acc_2 + (segment_86_2 * 2)) + 5) & 127;
    aux_2 ^= segment_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_86_1 == segment_86_2);
}

int fn_R000708_813_17(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_86 > 44)
  {
    acc = ((acc + (segment_86 * 2)) + 5) & 127;
    aux ^= segment_86 & 15;
  }
  else
  {
    acc = ((acc - segment_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_48_1 = 0;
  int segment_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_48_1 = ((segment_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_48_2 = ((segment_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_48_1) & 127;
    acc_2 = (acc_2 + segment_48_2) & 127;
  }

  int vector_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_30_1) & 63;
  aux_2 = (aux_2 + vector_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_76_1 > 44)
  {
    acc_1 = ((acc_1 + (bound_76_1 * 2)) + 5) & 127;
    aux_1 ^= bound_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_76_2 > 44)
  {
    acc_2 = ((acc_2 + (bound_76_2 * 2)) + 5) & 127;
    aux_2 ^= bound_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  assert(vector_30_1 == vector_30_2);
  assert(bound_76_1 == bound_76_2);
}

int fn_R000708_813_18(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_48 = ((segment_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_48) & 127;
  }

  int vector_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_30) & 63;
  acc ^= aux;
  int bound_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_76 > 44)
  {
    acc = ((acc + (bound_76 * 2)) + 5) & 127;
    aux ^= bound_76 & 15;
  }
  else
  {
    acc = ((acc - bound_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000708_813_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st_1 = {0};
  struct Vector3D_R000708_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_58_1 > 39)
  {
    acc_1 = ((acc_1 + (factor_58_1 * 2)) + 5) & 127;
    aux_1 ^= factor_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_58_2 > 39)
  {
    acc_2 = ((acc_2 + (factor_58_2 * 2)) + 5) & 127;
    aux_2 ^= factor_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_23_1) & 63;
  aux_2 = (aux_2 + sample_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_58_1 == factor_58_2);
  assert(sample_23_1 == sample_23_2);
}

int fn_R000708_813_19(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000708_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_58 > 39)
  {
    acc = ((acc + (factor_58 * 2)) + 5) & 127;
    aux ^= factor_58 & 15;
  }
  else
  {
    acc = ((acc - factor_58) + 11) & 127;
    aux += 3;
  }
  int sample_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000708_813_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int segment_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_23_1)
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

  switch (segment_23_2)
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
  int damping_16_1 = local_arr_1[aux_1 % 3];
  int damping_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_23_1 == segment_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_16_1 == damping_16_2);
}

int fn_R000708_813_20(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int segment_23 = (aux + st.buffer[1]) & 3;
  switch (segment_23)
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
  int damping_16 = local_arr[aux % 3];
  acc = (acc + (damping_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000708_813_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_48_1 = local_arr_1[aux_1 % 3];
  int phase_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_48_2 * 2)) & 127;
  int factor_29_1 = 0;
  int factor_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_29_1 = ((factor_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_29_2 = ((factor_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_29_1) & 127;
    acc_2 = (acc_2 + factor_29_2) & 127;
  }

  int pivot_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_13_1 > 44)
  {
    acc_1 = ((acc_1 + (pivot_13_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_13_2 > 44)
  {
    acc_2 = ((acc_2 + (pivot_13_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_48_1 == phase_48_2);
  assert(factor_29_1 == factor_29_2);
  assert(pivot_13_1 == pivot_13_2);
}

int fn_R000708_813_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_48 = local_arr[aux % 3];
  acc = (acc + (phase_48 * 2)) & 127;
  int factor_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_29 = ((factor_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_29) & 127;
  }

  int pivot_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_13 > 44)
  {
    acc = ((acc + (pivot_13 * 2)) + 5) & 127;
    aux ^= pivot_13 & 15;
  }
  else
  {
    acc = ((acc - pivot_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000708_813_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_81_1 > 29)
  {
    acc_1 = ((acc_1 + (factor_81_1 * 2)) + 5) & 127;
    aux_1 ^= factor_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_81_2 > 29)
  {
    acc_2 = ((acc_2 + (factor_81_2 * 2)) + 5) & 127;
    aux_2 ^= factor_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_18_1) & 63;
  aux_2 = (aux_2 + sample_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_81_1 == factor_81_2);
  assert(sample_18_1 == sample_18_2);
}

int fn_R000708_813_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_81 > 29)
  {
    acc = ((acc + (factor_81 * 2)) + 5) & 127;
    aux ^= factor_81 & 15;
  }
  else
  {
    acc = ((acc - factor_81) + 11) & 127;
    aux += 3;
  }
  int sample_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000708_813_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st_1 = {0};
  struct AudioFrame_R000708_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_17_1 > 37)
  {
    acc_1 = ((acc_1 + (offset_17_1 * 2)) + 5) & 127;
    aux_1 ^= offset_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_17_2 > 37)
  {
    acc_2 = ((acc_2 + (offset_17_2 * 2)) + 5) & 127;
    aux_2 ^= offset_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_78_1 = 0;
  int mask_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_78_1 = ((mask_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_78_2 = ((mask_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_78_1) & 127;
    acc_2 = (acc_2 + mask_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_17_1 == offset_17_2);
  assert(mask_78_1 == mask_78_2);
}

int fn_R000708_813_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000708_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_17 > 37)
  {
    acc = ((acc + (offset_17 * 2)) + 5) & 127;
    aux ^= offset_17 & 15;
  }
  else
  {
    acc = ((acc - offset_17) + 11) & 127;
    aux += 3;
  }
  int mask_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_78 = ((mask_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000708_813_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st_1 = {0};
  struct CipherContext_R000708_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_83_1) & 63;
  aux_2 = (aux_2 + scale_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_10_1 > 44)
  {
    acc_1 = ((acc_1 + (damping_10_1 * 2)) + 5) & 127;
    aux_1 ^= damping_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_10_2 > 44)
  {
    acc_2 = ((acc_2 + (damping_10_2 * 2)) + 5) & 127;
    aux_2 ^= damping_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_61_1)
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

  switch (vector_61_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_83_1 == scale_83_2);
  assert(damping_10_1 == damping_10_2);
  assert(vector_61_1 == vector_61_2);
}

int fn_R000708_813_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000708_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_83) & 63;
  acc ^= aux;
  int damping_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_10 > 44)
  {
    acc = ((acc + (damping_10 * 2)) + 5) & 127;
    aux ^= damping_10 & 15;
  }
  else
  {
    acc = ((acc - damping_10) + 11) & 127;
    aux += 3;
  }
  int vector_61 = (aux + st.buffer[1]) & 3;
  switch (vector_61)
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
  int sec_r000708_0_1;
  int sec_r000708_0_2;
  int sec_r000708_1_1;
  int sec_r000708_1_2;
  int sec_r000708_2_1;
  int sec_r000708_2_2;
  int sec_r000708_3_1;
  int sec_r000708_3_2;
  int sec_r000708_4_1;
  int sec_r000708_4_2;
  int sec_r000708_5_1;
  int sec_r000708_5_2;
  int sec_r000708_6_1;
  int sec_r000708_6_2;
  int sec_r000708_7_1;
  int sec_r000708_7_2;
  int sec_r000708_8_1;
  int sec_r000708_8_2;
  int sec_r000708_9_1;
  int sec_r000708_9_2;
  int sec_r000708_10_1;
  int sec_r000708_10_2;
  int sec_r000708_11_1;
  int sec_r000708_11_2;
  int sec_r000708_12_1;
  int sec_r000708_12_2;
  int sec_r000708_13_1;
  int sec_r000708_13_2;
  int sec_r000708_14_1;
  int sec_r000708_14_2;
  int sec_r000708_15_1;
  int sec_r000708_15_2;
  int sec_r000708_16_1;
  int sec_r000708_16_2;
  int sec_r000708_17_1;
  int sec_r000708_17_2;
  int pub_r000708_0_1;
  int pub_r000708_0_2;
  int pub_r000708_1_1;
  int pub_r000708_1_2;
  int pub_r000708_2_1;
  int pub_r000708_2_2;
  int pub_r000708_3_1;
  int pub_r000708_3_2;
  int pub_r000708_4_1;
  int pub_r000708_4_2;
  int pub_r000708_5_1;
  int pub_r000708_5_2;
  int pub_r000708_6_1;
  int pub_r000708_6_2;
  int pub_r000708_7_1;
  int pub_r000708_7_2;
  int pub_r000708_8_1;
  int pub_r000708_8_2;
  int pub_r000708_9_1;
  int pub_r000708_9_2;
  int pub_r000708_10_1;
  int pub_r000708_10_2;
  int pub_r000708_11_1;
  int pub_r000708_11_2;
  int pub_r000708_12_1;
  int pub_r000708_12_2;
  int pub_r000708_13_1;
  int pub_r000708_13_2;
  int pub_r000708_14_1;
  int pub_r000708_14_2;
  int pub_r000708_15_1;
  int pub_r000708_15_2;
  int pub_r000708_16_1;
  int pub_r000708_16_2;
  int pub_r000708_17_1;
  int pub_r000708_17_2;
  int pub_r000708_18_1;
  int pub_r000708_18_2;
  int pub_r000708_19_1;
  int pub_r000708_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000708_0_1 >= (-100)) && (pub_r000708_0_1 <= 100));
  __CPROVER_assume((pub_r000708_0_2 >= (-100)) && (pub_r000708_0_2 <= 100));
  __CPROVER_assume((pub_r000708_1_1 >= (-100)) && (pub_r000708_1_1 <= 100));
  __CPROVER_assume((pub_r000708_1_2 >= (-100)) && (pub_r000708_1_2 <= 100));
  __CPROVER_assume((pub_r000708_2_1 >= (-100)) && (pub_r000708_2_1 <= 100));
  __CPROVER_assume((pub_r000708_2_2 >= (-100)) && (pub_r000708_2_2 <= 100));
  __CPROVER_assume((pub_r000708_3_1 >= (-100)) && (pub_r000708_3_1 <= 100));
  __CPROVER_assume((pub_r000708_3_2 >= (-100)) && (pub_r000708_3_2 <= 100));
  __CPROVER_assume((pub_r000708_4_1 >= (-100)) && (pub_r000708_4_1 <= 100));
  __CPROVER_assume((pub_r000708_4_2 >= (-100)) && (pub_r000708_4_2 <= 100));
  __CPROVER_assume((pub_r000708_5_1 >= (-100)) && (pub_r000708_5_1 <= 100));
  __CPROVER_assume((pub_r000708_5_2 >= (-100)) && (pub_r000708_5_2 <= 100));
  __CPROVER_assume((pub_r000708_6_1 >= (-100)) && (pub_r000708_6_1 <= 100));
  __CPROVER_assume((pub_r000708_6_2 >= (-100)) && (pub_r000708_6_2 <= 100));
  __CPROVER_assume((pub_r000708_7_1 >= (-100)) && (pub_r000708_7_1 <= 100));
  __CPROVER_assume((pub_r000708_7_2 >= (-100)) && (pub_r000708_7_2 <= 100));
  __CPROVER_assume((pub_r000708_8_1 >= (-100)) && (pub_r000708_8_1 <= 100));
  __CPROVER_assume((pub_r000708_8_2 >= (-100)) && (pub_r000708_8_2 <= 100));
  __CPROVER_assume((pub_r000708_9_1 >= (-100)) && (pub_r000708_9_1 <= 100));
  __CPROVER_assume((pub_r000708_9_2 >= (-100)) && (pub_r000708_9_2 <= 100));
  __CPROVER_assume((pub_r000708_10_1 >= (-100)) && (pub_r000708_10_1 <= 100));
  __CPROVER_assume((pub_r000708_10_2 >= (-100)) && (pub_r000708_10_2 <= 100));
  __CPROVER_assume((pub_r000708_11_1 >= (-100)) && (pub_r000708_11_1 <= 100));
  __CPROVER_assume((pub_r000708_11_2 >= (-100)) && (pub_r000708_11_2 <= 100));
  __CPROVER_assume((pub_r000708_12_1 >= (-100)) && (pub_r000708_12_1 <= 100));
  __CPROVER_assume((pub_r000708_12_2 >= (-100)) && (pub_r000708_12_2 <= 100));
  __CPROVER_assume((pub_r000708_13_1 >= (-100)) && (pub_r000708_13_1 <= 100));
  __CPROVER_assume((pub_r000708_13_2 >= (-100)) && (pub_r000708_13_2 <= 100));
  __CPROVER_assume((pub_r000708_14_1 >= (-100)) && (pub_r000708_14_1 <= 100));
  __CPROVER_assume((pub_r000708_14_2 >= (-100)) && (pub_r000708_14_2 <= 100));
  __CPROVER_assume((pub_r000708_15_1 >= (-100)) && (pub_r000708_15_1 <= 100));
  __CPROVER_assume((pub_r000708_15_2 >= (-100)) && (pub_r000708_15_2 <= 100));
  __CPROVER_assume((pub_r000708_16_1 >= (-100)) && (pub_r000708_16_1 <= 100));
  __CPROVER_assume((pub_r000708_16_2 >= (-100)) && (pub_r000708_16_2 <= 100));
  __CPROVER_assume((pub_r000708_17_1 >= (-100)) && (pub_r000708_17_1 <= 100));
  __CPROVER_assume((pub_r000708_17_2 >= (-100)) && (pub_r000708_17_2 <= 100));
  __CPROVER_assume((pub_r000708_18_1 >= (-100)) && (pub_r000708_18_1 <= 100));
  __CPROVER_assume((pub_r000708_18_2 >= (-100)) && (pub_r000708_18_2 <= 100));
  __CPROVER_assume((pub_r000708_19_1 >= (-100)) && (pub_r000708_19_1 <= 100));
  __CPROVER_assume((pub_r000708_19_2 >= (-100)) && (pub_r000708_19_2 <= 100));
  __CPROVER_assume((sec_r000708_0_1 >= 0) && (sec_r000708_0_1 <= 255));
  __CPROVER_assume((sec_r000708_0_2 >= 0) && (sec_r000708_0_2 <= 255));
  __CPROVER_assume((sec_r000708_1_1 >= 0) && (sec_r000708_1_1 <= 255));
  __CPROVER_assume((sec_r000708_1_2 >= 0) && (sec_r000708_1_2 <= 255));
  __CPROVER_assume((sec_r000708_2_1 >= 0) && (sec_r000708_2_1 <= 255));
  __CPROVER_assume((sec_r000708_2_2 >= 0) && (sec_r000708_2_2 <= 255));
  __CPROVER_assume((sec_r000708_3_1 >= 0) && (sec_r000708_3_1 <= 255));
  __CPROVER_assume((sec_r000708_3_2 >= 0) && (sec_r000708_3_2 <= 255));
  __CPROVER_assume((sec_r000708_4_1 >= 0) && (sec_r000708_4_1 <= 255));
  __CPROVER_assume((sec_r000708_4_2 >= 0) && (sec_r000708_4_2 <= 255));
  __CPROVER_assume((sec_r000708_5_1 >= 0) && (sec_r000708_5_1 <= 255));
  __CPROVER_assume((sec_r000708_5_2 >= 0) && (sec_r000708_5_2 <= 255));
  __CPROVER_assume((sec_r000708_6_1 >= 0) && (sec_r000708_6_1 <= 255));
  __CPROVER_assume((sec_r000708_6_2 >= 0) && (sec_r000708_6_2 <= 255));
  __CPROVER_assume((sec_r000708_7_1 >= 0) && (sec_r000708_7_1 <= 255));
  __CPROVER_assume((sec_r000708_7_2 >= 0) && (sec_r000708_7_2 <= 255));
  __CPROVER_assume((sec_r000708_8_1 >= 0) && (sec_r000708_8_1 <= 255));
  __CPROVER_assume((sec_r000708_8_2 >= 0) && (sec_r000708_8_2 <= 255));
  __CPROVER_assume((sec_r000708_9_1 >= 0) && (sec_r000708_9_1 <= 255));
  __CPROVER_assume((sec_r000708_9_2 >= 0) && (sec_r000708_9_2 <= 255));
  __CPROVER_assume((sec_r000708_10_1 >= 0) && (sec_r000708_10_1 <= 255));
  __CPROVER_assume((sec_r000708_10_2 >= 0) && (sec_r000708_10_2 <= 255));
  __CPROVER_assume((sec_r000708_11_1 >= 0) && (sec_r000708_11_1 <= 255));
  __CPROVER_assume((sec_r000708_11_2 >= 0) && (sec_r000708_11_2 <= 255));
  __CPROVER_assume((sec_r000708_12_1 >= 0) && (sec_r000708_12_1 <= 255));
  __CPROVER_assume((sec_r000708_12_2 >= 0) && (sec_r000708_12_2 <= 255));
  __CPROVER_assume((sec_r000708_13_1 >= 0) && (sec_r000708_13_1 <= 255));
  __CPROVER_assume((sec_r000708_13_2 >= 0) && (sec_r000708_13_2 <= 255));
  __CPROVER_assume((sec_r000708_14_1 >= 0) && (sec_r000708_14_1 <= 255));
  __CPROVER_assume((sec_r000708_14_2 >= 0) && (sec_r000708_14_2 <= 255));
  __CPROVER_assume((sec_r000708_15_1 >= 0) && (sec_r000708_15_1 <= 255));
  __CPROVER_assume((sec_r000708_15_2 >= 0) && (sec_r000708_15_2 <= 255));
  __CPROVER_assume((sec_r000708_16_1 >= 0) && (sec_r000708_16_1 <= 255));
  __CPROVER_assume((sec_r000708_16_2 >= 0) && (sec_r000708_16_2 <= 255));
  __CPROVER_assume((sec_r000708_17_1 >= 0) && (sec_r000708_17_1 <= 255));
  __CPROVER_assume((sec_r000708_17_2 >= 0) && (sec_r000708_17_2 <= 255));
  struct Vector3D_R000708_813_0 st_var_0_1 = {0};
  struct Vector3D_R000708_813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000708_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000708_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000708_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000708_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000708_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000708_0_2 + 7) & 15;
  struct CipherContext_R000708_813_1 st_var_1_1 = {0};
  struct CipherContext_R000708_813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000708_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000708_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000708_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000708_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000708_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000708_0_2 + 9) & 15;
  struct AudioFrame_R000708_813_2 st_var_2_1 = {0};
  struct AudioFrame_R000708_813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000708_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000708_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000708_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000708_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000708_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000708_0_2 + 11) & 15;
  union PacketPayload_R000708_813_0 u_var_1;
  union PacketPayload_R000708_813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
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
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 44)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 44)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 48)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 48)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 54)
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
  if (stage_v_28_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 54)
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
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 40)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 40)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
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
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 44)
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
  if (stage_v_55_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 44)
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
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 59) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 64) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_0_2.buffer[0] * 3) & 63;
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
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = (st_var_1_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_1_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 51)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 51)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 44)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 44)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (st_var_1_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_1_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 81) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = ((st_var_1_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_1_2.buffer[1] * 2) + 253) & 63;
  if (stage_v_82_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_82_1) - 5) & 255;
    if (stage_v_82_1 > 34)
    {
      chk_sum_1 ^= stage_v_82_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_82_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_82_2) - 5) & 255;
    if (stage_v_82_2 > 34)
    {
      chk_sum_2 ^= stage_v_82_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = (st_var_0_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_0_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 29)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 29)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 96) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 96) & 15;
  int stage_v_95_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_95_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= stage_v_95_1;
  chk_sum_2 ^= stage_v_95_2;
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 37)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 37)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 47)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 47)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 102) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((st_var_1_1.buffer[1] * 2) + 316) & 63;
  int stage_v_103_2 = ((st_var_1_2.buffer[1] * 2) + 316) & 63;
  if (stage_v_103_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 44)
    {
      chk_sum_1 ^= stage_v_103_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_103_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 44)
    {
      chk_sum_2 ^= stage_v_103_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_105_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_107_1 = (st_var_2_1.buffer[0] ^ 110) & 3;
  int stage_v_107_2 = (st_var_2_2.buffer[0] ^ 110) & 3;
  switch (stage_v_107_1)
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

  switch (stage_v_107_2)
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

  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = ((st_var_0_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_0_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 38)
    {
      chk_sum_1 ^= stage_v_117_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_117_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 38)
    {
      chk_sum_2 ^= stage_v_117_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_118_1 = ((st_var_1_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_1_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 28)
    {
      chk_sum_1 ^= stage_v_118_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_118_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 28)
    {
      chk_sum_2 ^= stage_v_118_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_119_1 = ((st_var_2_1.buffer[2] * 2) + 364) & 63;
  int stage_v_119_2 = ((st_var_2_2.buffer[2] * 2) + 364) & 63;
  if (stage_v_119_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_119_1) - 5) & 255;
    if (stage_v_119_1 > 35)
    {
      chk_sum_1 ^= stage_v_119_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_119_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_119_2) - 5) & 255;
    if (stage_v_119_2 > 35)
    {
      chk_sum_2 ^= stage_v_119_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 33)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 33)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 26)
    {
      chk_sum_1 ^= stage_v_121_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_121_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 26)
    {
      chk_sum_2 ^= stage_v_121_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_122_1 = ((st_var_2_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_2_2.buffer[2] * 2) + 373) & 63;
  if (stage_v_122_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_122_1) - 5) & 255;
    if (stage_v_122_1 > 54)
    {
      chk_sum_1 ^= stage_v_122_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_122_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_122_2) - 5) & 255;
    if (stage_v_122_2 > 54)
    {
      chk_sum_2 ^= stage_v_122_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_123_1 = ((st_var_0_1.buffer[0] * 2) + 376) & 63;
  int stage_v_123_2 = ((st_var_0_2.buffer[0] * 2) + 376) & 63;
  if (stage_v_123_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_123_1) - 5) & 255;
    if (stage_v_123_1 > 49)
    {
      chk_sum_1 ^= stage_v_123_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_123_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_123_2) - 5) & 255;
    if (stage_v_123_2 > 49)
    {
      chk_sum_2 ^= stage_v_123_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((st_var_2_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_2_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 46)
    {
      chk_sum_1 ^= stage_v_125_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_125_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 46)
    {
      chk_sum_2 ^= stage_v_125_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_128_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (133 & 31);
  int stage_v_128_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (133 & 31);
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= (stage_v_128_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_128_2 << 1) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = table_1[2];
  int stage_v_130_2 = table_2[2];
  table_1[2] = (table_1[3] + 261) & 63;
  table_2[2] = (table_2[3] + 261) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((st_var_2_1.buffer[2] * 2) + 400) & 63;
  int stage_v_131_2 = ((st_var_2_2.buffer[2] * 2) + 400) & 63;
  if (stage_v_131_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_131_1) - 5) & 255;
    if (stage_v_131_1 > 34)
    {
      chk_sum_1 ^= stage_v_131_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_131_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_131_2) - 5) & 255;
    if (stage_v_131_2 > 34)
    {
      chk_sum_2 ^= stage_v_131_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 134) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 134) & 15;
  int stage_v_133_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_133_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= stage_v_133_1;
  chk_sum_2 ^= stage_v_133_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = table_1[2];
  int stage_v_138_2 = table_2[2];
  table_1[2] = (table_1[3] + 277) & 63;
  table_2[2] = (table_2[3] + 277) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = (st_var_2_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_2_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = (st_var_0_1.buffer[0] ^ 144) & 3;
  int stage_v_141_2 = (st_var_0_2.buffer[0] ^ 144) & 3;
  switch (stage_v_141_1)
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

  switch (stage_v_141_2)
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

  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_144_1 = table_1[0];
  int stage_v_144_2 = table_2[0];
  table_1[0] = (table_1[1] + 289) & 63;
  table_2[0] = (table_2[1] + 289) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 45)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 45)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = (st_var_0_1.buffer[0] ^ 150) & 3;
  int stage_v_147_2 = (st_var_0_2.buffer[0] ^ 150) & 3;
  switch (stage_v_147_1)
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

  switch (stage_v_147_2)
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

  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (st_var_1_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_1_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (st_var_0_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_0_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = ((st_var_1_1.buffer[1] * 2) + 469) & 63;
  int stage_v_154_2 = ((st_var_1_2.buffer[1] * 2) + 469) & 63;
  if (stage_v_154_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_154_1) - 5) & 255;
    if (stage_v_154_1 > 29)
    {
      chk_sum_1 ^= stage_v_154_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_154_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_154_2) - 5) & 255;
    if (stage_v_154_2 > 29)
    {
      chk_sum_2 ^= stage_v_154_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  int stage_v_157_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (162 & 31);
  int stage_v_157_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (162 & 31);
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= (stage_v_157_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_157_2 << 1) & 127;
  int stage_v_158_1 = table_1[2];
  int stage_v_158_2 = table_2[2];
  table_1[2] = (table_1[3] + 317) & 63;
  table_2[2] = (table_2[3] + 317) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((st_var_1_1.buffer[1] * 2) + 487) & 63;
  int stage_v_160_2 = ((st_var_1_2.buffer[1] * 2) + 487) & 63;
  if (stage_v_160_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_160_1) - 5) & 255;
    if (stage_v_160_1 > 52)
    {
      chk_sum_1 ^= stage_v_160_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_160_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_160_2) - 5) & 255;
    if (stage_v_160_2 > 52)
    {
      chk_sum_2 ^= stage_v_160_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_161_1 = table_1[1];
  int stage_v_161_2 = table_2[1];
  table_1[1] = (table_1[2] + 323) & 63;
  table_2[1] = (table_2[2] + 323) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (168 & 31);
  int stage_v_163_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (168 & 31);
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  chk_sum_1 ^= (stage_v_163_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_163_2 << 1) & 127;
  int stage_v_164_1 = (st_var_2_1.buffer[0] ^ 167) & 3;
  int stage_v_164_2 = (st_var_2_2.buffer[0] ^ 167) & 3;
  switch (stage_v_164_1)
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

  switch (stage_v_164_2)
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

  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 167) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 167) & 15;
  int stage_v_166_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_166_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= stage_v_166_1;
  chk_sum_2 ^= stage_v_166_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 168) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  int l_bound_0_1 = (sec_r000708_10_1 & 1) + 1;
  int l_bound_0_2 = (sec_r000708_10_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_0_1) && (it_2 < l_bound_0_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 2;
    out_sink_2 += (it_2 * 3) + 2;
  }

  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000708_14_1 != sec_r000708_14_2);
  __CPROVER_assume(pub_r000708_5_1 == pub_r000708_5_2);
  __CPROVER_assume(sec_r000708_12_1 != sec_r000708_12_2);
  __CPROVER_assume(sec_r000708_17_1 != sec_r000708_17_2);
  __CPROVER_assume(pub_r000708_8_1 == pub_r000708_8_2);
  __CPROVER_assume(pub_r000708_12_1 == pub_r000708_12_2);
  __CPROVER_assume(sec_r000708_11_1 != sec_r000708_11_2);
  __CPROVER_assume(sec_r000708_9_1 != sec_r000708_9_2);
  __CPROVER_assume(pub_r000708_6_1 == pub_r000708_6_2);
  __CPROVER_assume(sec_r000708_16_1 != sec_r000708_16_2);
  __CPROVER_assume(pub_r000708_13_1 == pub_r000708_13_2);
  __CPROVER_assume(pub_r000708_14_1 == pub_r000708_14_2);
  __CPROVER_assume(pub_r000708_17_1 == pub_r000708_17_2);
  __CPROVER_assume(pub_r000708_11_1 == pub_r000708_11_2);
  __CPROVER_assume(sec_r000708_6_1 != sec_r000708_6_2);
  __CPROVER_assume(pub_r000708_7_1 == pub_r000708_7_2);
  __CPROVER_assume(sec_r000708_8_1 != sec_r000708_8_2);
  __CPROVER_assume(sec_r000708_3_1 != sec_r000708_3_2);
  __CPROVER_assume(pub_r000708_19_1 == pub_r000708_19_2);
  __CPROVER_assume(pub_r000708_2_1 == pub_r000708_2_2);
  __CPROVER_assume(pub_r000708_18_1 == pub_r000708_18_2);
  __CPROVER_assume(pub_r000708_0_1 == pub_r000708_0_2);
  __CPROVER_assume(pub_r000708_1_1 == pub_r000708_1_2);
  __CPROVER_assume(pub_r000708_4_1 == pub_r000708_4_2);
  __CPROVER_assume(sec_r000708_13_1 != sec_r000708_13_2);
  __CPROVER_assume(sec_r000708_4_1 != sec_r000708_4_2);
  __CPROVER_assume(pub_r000708_15_1 == pub_r000708_15_2);
  __CPROVER_assume(sec_r000708_0_1 != sec_r000708_0_2);
  __CPROVER_assume(pub_r000708_9_1 == pub_r000708_9_2);
  __CPROVER_assume(pub_r000708_3_1 == pub_r000708_3_2);
  __CPROVER_assume(sec_r000708_1_1 != sec_r000708_1_2);
  __CPROVER_assume(sec_r000708_5_1 != sec_r000708_5_2);
  __CPROVER_assume(sec_r000708_10_1 != sec_r000708_10_2);
  __CPROVER_assume(sec_r000708_7_1 != sec_r000708_7_2);
  __CPROVER_assume(pub_r000708_10_1 == pub_r000708_10_2);
  __CPROVER_assume(sec_r000708_15_1 != sec_r000708_15_2);
  __CPROVER_assume(sec_r000708_2_1 != sec_r000708_2_2);
  __CPROVER_assume(pub_r000708_16_1 == pub_r000708_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
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
  assert(l_bound_0_1 == l_bound_0_2);
}


