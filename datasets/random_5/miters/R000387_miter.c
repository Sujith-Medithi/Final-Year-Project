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
struct DeviceConfig_R000387_8713_0
{
  unsigned char timeout;
  unsigned char parity;
  int baud_rate;
  int id;
  int buffer[3];
};
struct CipherContext_R000387_8713_1
{
  int counter;
  unsigned char flags;
  int iv;
  int round_key;
  unsigned char tag;
  int buffer[3];
};
struct AudioFrame_R000387_8713_2
{
  int envelope;
  short sample_rate;
  unsigned char rms;
  int gain;
  int buffer[3];
};
struct StreamBuffer_R000387_8713_3
{
  unsigned char capacity;
  unsigned char watermark;
  int state;
  int tail;
  unsigned char head;
  int buffer[3];
};
union PacketPayload_R000387_8713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000387_8713_1
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
void fn_R000387_8713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st_1 = {0};
  struct CipherContext_R000387_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_52_1) & 63;
  aux_2 = (aux_2 + quotient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
}

int fn_R000387_8713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st_1 = {0};
  struct CipherContext_R000387_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_30_1 = local_arr_1[aux_1 % 3];
  int pivot_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_30_2 * 2)) & 127;
  int pivot_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_79_1)
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

  switch (pivot_79_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_30_1 == pivot_30_2);
  assert(pivot_79_1 == pivot_79_2);
}

int fn_R000387_8713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int pivot_30 = local_arr[aux % 3];
  acc = (acc + (pivot_30 * 2)) & 127;
  int pivot_79 = (aux + st.buffer[1]) & 3;
  switch (pivot_79)
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

void fn_R000387_8713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int sample_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_12_1 > 44)
  {
    acc_1 = ((acc_1 + (sample_12_1 * 2)) + 5) & 127;
    aux_1 ^= sample_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_12_2 > 44)
  {
    acc_2 = ((acc_2 + (sample_12_2 * 2)) + 5) & 127;
    aux_2 ^= sample_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_12_1 == sample_12_2);
}

int fn_R000387_8713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int sample_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_12 > 44)
  {
    acc = ((acc + (sample_12 * 2)) + 5) & 127;
    aux ^= sample_12 & 15;
  }
  else
  {
    acc = ((acc - sample_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_20_1)
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

  switch (parity_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_76_1) & 63;
  aux_2 = (aux_2 + residue_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_19_1 > 22)
  {
    acc_1 = ((acc_1 + (tally_19_1 * 2)) + 5) & 127;
    aux_1 ^= tally_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_19_2 > 22)
  {
    acc_2 = ((acc_2 + (tally_19_2 * 2)) + 5) & 127;
    aux_2 ^= tally_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_20_1 == parity_20_2);
  assert(residue_76_1 == residue_76_2);
  assert(tally_19_1 == tally_19_2);
}

int fn_R000387_8713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_20 = (aux + st.buffer[1]) & 3;
  switch (parity_20)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_76) & 63;
  acc ^= aux;
  int tally_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_19 > 22)
  {
    acc = ((acc + (tally_19 * 2)) + 5) & 127;
    aux ^= tally_19 & 15;
  }
  else
  {
    acc = ((acc - tally_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st_1 = {0};
  struct CipherContext_R000387_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tracker_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_99_1)
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

  switch (tracker_99_2)
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

  int damping_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_46_1 > 40)
  {
    acc_1 = ((acc_1 + (damping_46_1 * 2)) + 5) & 127;
    aux_1 ^= damping_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_46_2 > 40)
  {
    acc_2 = ((acc_2 + (damping_46_2 * 2)) + 5) & 127;
    aux_2 ^= damping_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_73_1 = local_arr_1[aux_1 % 3];
  int delta_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_99_1 == tracker_99_2);
  assert(damping_46_1 == damping_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_73_1 == delta_73_2);
}

int fn_R000387_8713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tracker_99 = (aux + st.buffer[1]) & 3;
  switch (tracker_99)
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

  int damping_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_46 > 40)
  {
    acc = ((acc + (damping_46 * 2)) + 5) & 127;
    aux ^= damping_46 & 15;
  }
  else
  {
    acc = ((acc - damping_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_73 = local_arr[aux % 3];
  acc = (acc + (delta_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_63_1 > 14)
  {
    acc_1 = ((acc_1 + (residue_63_1 * 2)) + 5) & 127;
    aux_1 ^= residue_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_63_2 > 14)
  {
    acc_2 = ((acc_2 + (residue_63_2 * 2)) + 5) & 127;
    aux_2 ^= residue_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_38_1) & 63;
  aux_2 = (aux_2 + weight_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_63_1 == residue_63_2);
  assert(weight_38_1 == weight_38_2);
}

int fn_R000387_8713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_63 > 14)
  {
    acc = ((acc + (residue_63 * 2)) + 5) & 127;
    aux ^= residue_63 & 15;
  }
  else
  {
    acc = ((acc - residue_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000387_8713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int phase_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_75_1) & 63;
  aux_2 = (aux_2 + phase_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_75_1 == phase_75_2);
}

int fn_R000387_8713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int phase_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
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
  int weight_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_18_1 > 20)
  {
    acc_1 = ((acc_1 + (weight_18_1 * 2)) + 5) & 127;
    aux_1 ^= weight_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_18_2 > 20)
  {
    acc_2 = ((acc_2 + (weight_18_2 * 2)) + 5) & 127;
    aux_2 ^= weight_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_18_1 == weight_18_2);
}

int fn_R000387_8713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_18 > 20)
  {
    acc = ((acc + (weight_18 * 2)) + 5) & 127;
    aux ^= weight_18 & 15;
  }
  else
  {
    acc = ((acc - weight_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_94_1) & 63;
  aux_2 = (aux_2 + residue_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_47_1 > 40)
  {
    acc_1 = ((acc_1 + (delta_47_1 * 2)) + 5) & 127;
    aux_1 ^= delta_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_47_2 > 40)
  {
    acc_2 = ((acc_2 + (delta_47_2 * 2)) + 5) & 127;
    aux_2 ^= delta_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_18_1)
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

  switch (vector_18_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_94_1 == residue_94_2);
  assert(delta_47_1 == delta_47_2);
  assert(vector_18_1 == vector_18_2);
}

int fn_R000387_8713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_94) & 63;
  acc ^= aux;
  int delta_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_47 > 40)
  {
    acc = ((acc + (delta_47 * 2)) + 5) & 127;
    aux ^= delta_47 & 15;
  }
  else
  {
    acc = ((acc - delta_47) + 11) & 127;
    aux += 3;
  }
  int vector_18 = (aux + st.buffer[1]) & 3;
  switch (vector_18)
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

void fn_R000387_8713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st_1 = {0};
  struct StreamBuffer_R000387_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_53_1)
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

  switch (vector_53_2)
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

  int parity_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_78_1) & 63;
  aux_2 = (aux_2 + parity_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_53_1 == vector_53_2);
  assert(parity_78_1 == parity_78_2);
}

int fn_R000387_8713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_53 = (aux + st.buffer[1]) & 3;
  switch (vector_53)
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

  int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000387_8713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int checksum_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_20_1) & 63;
  aux_2 = (aux_2 + checksum_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_15_1)
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

  switch (factor_15_2)
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

  int anchor_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_52_1 > 24)
  {
    acc_1 = ((acc_1 + (anchor_52_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_52_2 > 24)
  {
    acc_2 = ((acc_2 + (anchor_52_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  assert(factor_15_1 == factor_15_2);
  assert(anchor_52_1 == anchor_52_2);
}

int fn_R000387_8713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int checksum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_20) & 63;
  acc ^= aux;
  int factor_15 = (aux + st.buffer[1]) & 3;
  switch (factor_15)
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

  int anchor_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_52 > 24)
  {
    acc = ((acc + (anchor_52 * 2)) + 5) & 127;
    aux ^= anchor_52 & 15;
  }
  else
  {
    acc = ((acc - anchor_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_83_1 > 42)
  {
    acc_1 = ((acc_1 + (offset_83_1 * 2)) + 5) & 127;
    aux_1 ^= offset_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_83_2 > 42)
  {
    acc_2 = ((acc_2 + (offset_83_2 * 2)) + 5) & 127;
    aux_2 ^= offset_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_93_1 = local_arr_1[aux_1 % 3];
  int accumulator_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_93_2 * 2)) & 127;
  int tally_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_57_1)
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

  switch (tally_57_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_83_1 == offset_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_93_1 == accumulator_93_2);
  assert(tally_57_1 == tally_57_2);
}

int fn_R000387_8713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_83 > 42)
  {
    acc = ((acc + (offset_83 * 2)) + 5) & 127;
    aux ^= offset_83 & 15;
  }
  else
  {
    acc = ((acc - offset_83) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_93 = local_arr[aux % 3];
  acc = (acc + (accumulator_93 * 2)) & 127;
  int tally_57 = (aux + st.buffer[1]) & 3;
  switch (tally_57)
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

void fn_R000387_8713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_77_1) & 63;
  aux_2 = (aux_2 + factor_77_2) & 63;
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_77_1 == factor_77_2);
}

int fn_R000387_8713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st_1 = {0};
  struct CipherContext_R000387_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_46_1)
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

  switch (segment_46_2)
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

  int pivot_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_36_1) & 63;
  aux_2 = (aux_2 + pivot_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_46_1 == segment_46_2);
  assert(pivot_36_1 == pivot_36_2);
}

int fn_R000387_8713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_46 = (aux + st.buffer[1]) & 3;
  switch (segment_46)
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

  int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_71_1 = local_arr_1[aux_1 % 3];
  int tally_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_71_2 * 2)) & 127;
  int mask_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_25_1) & 63;
  aux_2 = (aux_2 + mask_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_71_1 > 43)
  {
    acc_1 = ((acc_1 + (weight_71_1 * 2)) + 5) & 127;
    aux_1 ^= weight_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_71_2 > 43)
  {
    acc_2 = ((acc_2 + (weight_71_2 * 2)) + 5) & 127;
    aux_2 ^= weight_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_71_1 == tally_71_2);
  assert(mask_25_1 == mask_25_2);
  assert(weight_71_1 == weight_71_2);
}

int fn_R000387_8713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int tally_71 = local_arr[aux % 3];
  acc = (acc + (tally_71 * 2)) & 127;
  int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_71 > 43)
  {
    acc = ((acc + (weight_71 * 2)) + 5) & 127;
    aux ^= weight_71 & 15;
  }
  else
  {
    acc = ((acc - weight_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st_1 = {0};
  struct CipherContext_R000387_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_68_1 = local_arr_1[aux_1 % 3];
  int sample_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_68_1 == sample_68_2);
}

int fn_R000387_8713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000387_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int sample_68 = local_arr[aux % 3];
  acc = (acc + (sample_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_45_1 > 22)
  {
    acc_1 = ((acc_1 + (cursor_45_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_45_2 > 22)
  {
    acc_2 = ((acc_2 + (cursor_45_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_45_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_28_1)
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

  switch (index_reg_28_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_45_1 == cursor_45_2);
  assert(index_reg_28_1 == index_reg_28_2);
}

int fn_R000387_8713_16(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_45 > 22)
  {
    acc = ((acc + (cursor_45 * 2)) + 5) & 127;
    aux ^= cursor_45 & 15;
  }
  else
  {
    acc = ((acc - cursor_45) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_28 = (aux + st.buffer[1]) & 3;
  switch (index_reg_28)
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

void fn_R000387_8713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int coefficient_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_32_1)
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

  switch (coefficient_32_2)
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

  int pivot_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_72_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_72_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_72_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_72_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
  assert(pivot_72_1 == pivot_72_2);
}

int fn_R000387_8713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int coefficient_32 = (aux + st.buffer[1]) & 3;
  switch (coefficient_32)
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

  int pivot_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_72 > 15)
  {
    acc = ((acc + (pivot_72 * 2)) + 5) & 127;
    aux ^= pivot_72 & 15;
  }
  else
  {
    acc = ((acc - pivot_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st_1 = {0};
  struct AudioFrame_R000387_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_50_1) & 63;
  aux_2 = (aux_2 + tally_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_50_1 == tally_50_2);
}

int fn_R000387_8713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000387_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_50) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000387_8713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
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
  int coefficient_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_13_1)
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

  switch (coefficient_13_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_13_1 == coefficient_13_2);
}

int fn_R000387_8713_19(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_13 = (aux + st.buffer[1]) & 3;
  switch (coefficient_13)
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

void fn_R000387_8713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st_1 = {0};
  struct StreamBuffer_R000387_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_34_1) & 63;
  aux_2 = (aux_2 + window_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_96_1 > 28)
  {
    acc_1 = ((acc_1 + (margin_96_1 * 2)) + 5) & 127;
    aux_1 ^= margin_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_96_2 > 28)
  {
    acc_2 = ((acc_2 + (margin_96_2 * 2)) + 5) & 127;
    aux_2 ^= margin_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_34_1 == window_34_2);
  assert(margin_96_1 == margin_96_2);
}

int fn_R000387_8713_20(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_34) & 63;
  acc ^= aux;
  int margin_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_96 > 28)
  {
    acc = ((acc + (margin_96 * 2)) + 5) & 127;
    aux ^= margin_96 & 15;
  }
  else
  {
    acc = ((acc - margin_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000387_8713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_50_1) & 63;
  aux_2 = (aux_2 + scale_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_94_1 > 27)
  {
    acc_1 = ((acc_1 + (index_reg_94_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_94_2 > 27)
  {
    acc_2 = ((acc_2 + (index_reg_94_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_33_1 = local_arr_1[aux_1 % 3];
  int checksum_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_33_2 * 2)) & 127;
  int vector_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_97_1)
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

  switch (vector_97_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_50_1 == scale_50_2);
  assert(index_reg_94_1 == index_reg_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_33_1 == checksum_33_2);
  assert(vector_97_1 == vector_97_2);
}

int fn_R000387_8713_21(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000387_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_50) & 63;
  acc ^= aux;
  int index_reg_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_94 > 27)
  {
    acc = ((acc + (index_reg_94 * 2)) + 5) & 127;
    aux ^= index_reg_94 & 15;
  }
  else
  {
    acc = ((acc - index_reg_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_33 = local_arr[aux % 3];
  acc = (acc + (checksum_33 * 2)) & 127;
  int vector_97 = (aux + st.buffer[1]) & 3;
  switch (vector_97)
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

void fn_R000387_8713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st_1 = {0};
  struct StreamBuffer_R000387_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_51_1)
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

  switch (segment_51_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_51_1 == segment_51_2);
}

int fn_R000387_8713_22(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000387_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_51 = (aux + st.buffer[1]) & 3;
  switch (segment_51)
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
  int sec_r000387_0_1;
  int sec_r000387_0_2;
  int sec_r000387_1_1;
  int sec_r000387_1_2;
  int sec_r000387_2_1;
  int sec_r000387_2_2;
  int sec_r000387_3_1;
  int sec_r000387_3_2;
  int sec_r000387_4_1;
  int sec_r000387_4_2;
  int sec_r000387_5_1;
  int sec_r000387_5_2;
  int sec_r000387_6_1;
  int sec_r000387_6_2;
  int sec_r000387_7_1;
  int sec_r000387_7_2;
  int sec_r000387_8_1;
  int sec_r000387_8_2;
  int sec_r000387_9_1;
  int sec_r000387_9_2;
  int sec_r000387_10_1;
  int sec_r000387_10_2;
  int sec_r000387_11_1;
  int sec_r000387_11_2;
  int sec_r000387_12_1;
  int sec_r000387_12_2;
  int sec_r000387_13_1;
  int sec_r000387_13_2;
  int sec_r000387_14_1;
  int sec_r000387_14_2;
  int sec_r000387_15_1;
  int sec_r000387_15_2;
  int sec_r000387_16_1;
  int sec_r000387_16_2;
  int sec_r000387_17_1;
  int sec_r000387_17_2;
  int sec_r000387_18_1;
  int sec_r000387_18_2;
  int sec_r000387_19_1;
  int sec_r000387_19_2;
  int sec_r000387_20_1;
  int sec_r000387_20_2;
  int sec_r000387_21_1;
  int sec_r000387_21_2;
  int pub_r000387_0_1;
  int pub_r000387_0_2;
  int pub_r000387_1_1;
  int pub_r000387_1_2;
  int pub_r000387_2_1;
  int pub_r000387_2_2;
  int pub_r000387_3_1;
  int pub_r000387_3_2;
  int pub_r000387_4_1;
  int pub_r000387_4_2;
  int pub_r000387_5_1;
  int pub_r000387_5_2;
  int pub_r000387_6_1;
  int pub_r000387_6_2;
  int pub_r000387_7_1;
  int pub_r000387_7_2;
  int pub_r000387_8_1;
  int pub_r000387_8_2;
  int pub_r000387_9_1;
  int pub_r000387_9_2;
  int pub_r000387_10_1;
  int pub_r000387_10_2;
  int pub_r000387_11_1;
  int pub_r000387_11_2;
  int pub_r000387_12_1;
  int pub_r000387_12_2;
  int pub_r000387_13_1;
  int pub_r000387_13_2;
  int pub_r000387_14_1;
  int pub_r000387_14_2;
  int pub_r000387_15_1;
  int pub_r000387_15_2;
  int pub_r000387_16_1;
  int pub_r000387_16_2;
  int pub_r000387_17_1;
  int pub_r000387_17_2;
  int pub_r000387_18_1;
  int pub_r000387_18_2;
  int pub_r000387_19_1;
  int pub_r000387_19_2;
  int pub_r000387_20_1;
  int pub_r000387_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000387_0_1 >= (-100)) && (pub_r000387_0_1 <= 100));
  __CPROVER_assume((pub_r000387_0_2 >= (-100)) && (pub_r000387_0_2 <= 100));
  __CPROVER_assume((pub_r000387_1_1 >= (-100)) && (pub_r000387_1_1 <= 100));
  __CPROVER_assume((pub_r000387_1_2 >= (-100)) && (pub_r000387_1_2 <= 100));
  __CPROVER_assume((pub_r000387_2_1 >= (-100)) && (pub_r000387_2_1 <= 100));
  __CPROVER_assume((pub_r000387_2_2 >= (-100)) && (pub_r000387_2_2 <= 100));
  __CPROVER_assume((pub_r000387_3_1 >= (-100)) && (pub_r000387_3_1 <= 100));
  __CPROVER_assume((pub_r000387_3_2 >= (-100)) && (pub_r000387_3_2 <= 100));
  __CPROVER_assume((pub_r000387_4_1 >= (-100)) && (pub_r000387_4_1 <= 100));
  __CPROVER_assume((pub_r000387_4_2 >= (-100)) && (pub_r000387_4_2 <= 100));
  __CPROVER_assume((pub_r000387_5_1 >= (-100)) && (pub_r000387_5_1 <= 100));
  __CPROVER_assume((pub_r000387_5_2 >= (-100)) && (pub_r000387_5_2 <= 100));
  __CPROVER_assume((pub_r000387_6_1 >= (-100)) && (pub_r000387_6_1 <= 100));
  __CPROVER_assume((pub_r000387_6_2 >= (-100)) && (pub_r000387_6_2 <= 100));
  __CPROVER_assume((pub_r000387_7_1 >= (-100)) && (pub_r000387_7_1 <= 100));
  __CPROVER_assume((pub_r000387_7_2 >= (-100)) && (pub_r000387_7_2 <= 100));
  __CPROVER_assume((pub_r000387_8_1 >= (-100)) && (pub_r000387_8_1 <= 100));
  __CPROVER_assume((pub_r000387_8_2 >= (-100)) && (pub_r000387_8_2 <= 100));
  __CPROVER_assume((pub_r000387_9_1 >= (-100)) && (pub_r000387_9_1 <= 100));
  __CPROVER_assume((pub_r000387_9_2 >= (-100)) && (pub_r000387_9_2 <= 100));
  __CPROVER_assume((pub_r000387_10_1 >= (-100)) && (pub_r000387_10_1 <= 100));
  __CPROVER_assume((pub_r000387_10_2 >= (-100)) && (pub_r000387_10_2 <= 100));
  __CPROVER_assume((pub_r000387_11_1 >= (-100)) && (pub_r000387_11_1 <= 100));
  __CPROVER_assume((pub_r000387_11_2 >= (-100)) && (pub_r000387_11_2 <= 100));
  __CPROVER_assume((pub_r000387_12_1 >= (-100)) && (pub_r000387_12_1 <= 100));
  __CPROVER_assume((pub_r000387_12_2 >= (-100)) && (pub_r000387_12_2 <= 100));
  __CPROVER_assume((pub_r000387_13_1 >= (-100)) && (pub_r000387_13_1 <= 100));
  __CPROVER_assume((pub_r000387_13_2 >= (-100)) && (pub_r000387_13_2 <= 100));
  __CPROVER_assume((pub_r000387_14_1 >= (-100)) && (pub_r000387_14_1 <= 100));
  __CPROVER_assume((pub_r000387_14_2 >= (-100)) && (pub_r000387_14_2 <= 100));
  __CPROVER_assume((pub_r000387_15_1 >= (-100)) && (pub_r000387_15_1 <= 100));
  __CPROVER_assume((pub_r000387_15_2 >= (-100)) && (pub_r000387_15_2 <= 100));
  __CPROVER_assume((pub_r000387_16_1 >= (-100)) && (pub_r000387_16_1 <= 100));
  __CPROVER_assume((pub_r000387_16_2 >= (-100)) && (pub_r000387_16_2 <= 100));
  __CPROVER_assume((pub_r000387_17_1 >= (-100)) && (pub_r000387_17_1 <= 100));
  __CPROVER_assume((pub_r000387_17_2 >= (-100)) && (pub_r000387_17_2 <= 100));
  __CPROVER_assume((pub_r000387_18_1 >= (-100)) && (pub_r000387_18_1 <= 100));
  __CPROVER_assume((pub_r000387_18_2 >= (-100)) && (pub_r000387_18_2 <= 100));
  __CPROVER_assume((pub_r000387_19_1 >= (-100)) && (pub_r000387_19_1 <= 100));
  __CPROVER_assume((pub_r000387_19_2 >= (-100)) && (pub_r000387_19_2 <= 100));
  __CPROVER_assume((pub_r000387_20_1 >= (-100)) && (pub_r000387_20_1 <= 100));
  __CPROVER_assume((pub_r000387_20_2 >= (-100)) && (pub_r000387_20_2 <= 100));
  __CPROVER_assume((sec_r000387_0_1 >= 0) && (sec_r000387_0_1 <= 255));
  __CPROVER_assume((sec_r000387_0_2 >= 0) && (sec_r000387_0_2 <= 255));
  __CPROVER_assume((sec_r000387_1_1 >= 0) && (sec_r000387_1_1 <= 255));
  __CPROVER_assume((sec_r000387_1_2 >= 0) && (sec_r000387_1_2 <= 255));
  __CPROVER_assume((sec_r000387_2_1 >= 0) && (sec_r000387_2_1 <= 255));
  __CPROVER_assume((sec_r000387_2_2 >= 0) && (sec_r000387_2_2 <= 255));
  __CPROVER_assume((sec_r000387_3_1 >= 0) && (sec_r000387_3_1 <= 255));
  __CPROVER_assume((sec_r000387_3_2 >= 0) && (sec_r000387_3_2 <= 255));
  __CPROVER_assume((sec_r000387_4_1 >= 0) && (sec_r000387_4_1 <= 255));
  __CPROVER_assume((sec_r000387_4_2 >= 0) && (sec_r000387_4_2 <= 255));
  __CPROVER_assume((sec_r000387_5_1 >= 0) && (sec_r000387_5_1 <= 255));
  __CPROVER_assume((sec_r000387_5_2 >= 0) && (sec_r000387_5_2 <= 255));
  __CPROVER_assume((sec_r000387_6_1 >= 0) && (sec_r000387_6_1 <= 255));
  __CPROVER_assume((sec_r000387_6_2 >= 0) && (sec_r000387_6_2 <= 255));
  __CPROVER_assume((sec_r000387_7_1 >= 0) && (sec_r000387_7_1 <= 255));
  __CPROVER_assume((sec_r000387_7_2 >= 0) && (sec_r000387_7_2 <= 255));
  __CPROVER_assume((sec_r000387_8_1 >= 0) && (sec_r000387_8_1 <= 255));
  __CPROVER_assume((sec_r000387_8_2 >= 0) && (sec_r000387_8_2 <= 255));
  __CPROVER_assume((sec_r000387_9_1 >= 0) && (sec_r000387_9_1 <= 255));
  __CPROVER_assume((sec_r000387_9_2 >= 0) && (sec_r000387_9_2 <= 255));
  __CPROVER_assume((sec_r000387_10_1 >= 0) && (sec_r000387_10_1 <= 255));
  __CPROVER_assume((sec_r000387_10_2 >= 0) && (sec_r000387_10_2 <= 255));
  __CPROVER_assume((sec_r000387_11_1 >= 0) && (sec_r000387_11_1 <= 255));
  __CPROVER_assume((sec_r000387_11_2 >= 0) && (sec_r000387_11_2 <= 255));
  __CPROVER_assume((sec_r000387_12_1 >= 0) && (sec_r000387_12_1 <= 255));
  __CPROVER_assume((sec_r000387_12_2 >= 0) && (sec_r000387_12_2 <= 255));
  __CPROVER_assume((sec_r000387_13_1 >= 0) && (sec_r000387_13_1 <= 255));
  __CPROVER_assume((sec_r000387_13_2 >= 0) && (sec_r000387_13_2 <= 255));
  __CPROVER_assume((sec_r000387_14_1 >= 0) && (sec_r000387_14_1 <= 255));
  __CPROVER_assume((sec_r000387_14_2 >= 0) && (sec_r000387_14_2 <= 255));
  __CPROVER_assume((sec_r000387_15_1 >= 0) && (sec_r000387_15_1 <= 255));
  __CPROVER_assume((sec_r000387_15_2 >= 0) && (sec_r000387_15_2 <= 255));
  __CPROVER_assume((sec_r000387_16_1 >= 0) && (sec_r000387_16_1 <= 255));
  __CPROVER_assume((sec_r000387_16_2 >= 0) && (sec_r000387_16_2 <= 255));
  __CPROVER_assume((sec_r000387_17_1 >= 0) && (sec_r000387_17_1 <= 255));
  __CPROVER_assume((sec_r000387_17_2 >= 0) && (sec_r000387_17_2 <= 255));
  __CPROVER_assume((sec_r000387_18_1 >= 0) && (sec_r000387_18_1 <= 255));
  __CPROVER_assume((sec_r000387_18_2 >= 0) && (sec_r000387_18_2 <= 255));
  __CPROVER_assume((sec_r000387_19_1 >= 0) && (sec_r000387_19_1 <= 255));
  __CPROVER_assume((sec_r000387_19_2 >= 0) && (sec_r000387_19_2 <= 255));
  __CPROVER_assume((sec_r000387_20_1 >= 0) && (sec_r000387_20_1 <= 255));
  __CPROVER_assume((sec_r000387_20_2 >= 0) && (sec_r000387_20_2 <= 255));
  __CPROVER_assume((sec_r000387_21_1 >= 0) && (sec_r000387_21_1 <= 255));
  __CPROVER_assume((sec_r000387_21_2 >= 0) && (sec_r000387_21_2 <= 255));
  struct DeviceConfig_R000387_8713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000387_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000387_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000387_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000387_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000387_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000387_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000387_0_2 + 7) & 15;
  struct CipherContext_R000387_8713_1 st_var_1_1 = {0};
  struct CipherContext_R000387_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000387_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000387_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000387_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000387_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000387_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000387_0_2 + 9) & 15;
  struct AudioFrame_R000387_8713_2 st_var_2_1 = {0};
  struct AudioFrame_R000387_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000387_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000387_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000387_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000387_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000387_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000387_0_2 + 11) & 15;
  struct StreamBuffer_R000387_8713_3 st_var_3_1 = {0};
  struct StreamBuffer_R000387_8713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000387_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000387_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000387_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000387_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000387_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000387_0_2 + 13) & 15;
  union PacketPayload_R000387_8713_0 u_var_1;
  union PacketPayload_R000387_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 39)
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
  if (stage_v_12_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 39)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 47)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 47)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 44)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 44)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 50)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 50)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 30)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 30)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 42)
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
  if (stage_v_29_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 42)
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
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 26)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 26)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
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
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 48) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 54)
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
  if (stage_v_50_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 54)
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 37)
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
  if (stage_v_53_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 37)
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
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (st_var_3_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_3_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000387_15_1 & 1) != 0)
  {
    if ((sec_r000387_3_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000387_7_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000387_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000387_7_1 + 7) & 127;
  }
  if ((sec_r000387_15_2 & 1) != 0)
  {
    if ((sec_r000387_3_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000387_7_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000387_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000387_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000387_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000387_17_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000387_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000387_17_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000387_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000387_17_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000387_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000387_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000387_7_1 & 1) != 0)
  {
    if ((sec_r000387_19_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000387_10_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000387_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000387_10_1 + 7) & 127;
  }
  if ((sec_r000387_7_2 & 1) != 0)
  {
    if ((sec_r000387_19_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000387_10_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000387_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000387_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000387_5_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000387_5_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000387_15_1 & 1) != 0)
  {
    if ((sec_r000387_8_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((sec_r000387_15_2 & 1) != 0)
  {
    if ((sec_r000387_8_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000387_7_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000387_7_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000387_21_1 & 1) != 0)
  {
    if ((sec_r000387_3_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000387_10_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000387_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000387_10_1 + 7) & 127;
  }
  if ((sec_r000387_21_2 & 1) != 0)
  {
    if ((sec_r000387_3_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000387_10_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000387_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000387_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000387_5_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000387_17_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000387_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000387_17_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000387_5_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000387_17_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000387_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000387_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000387_11_1 & 1) != 0)
  {
    if ((sec_r000387_0_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((sec_r000387_11_2 & 1) != 0)
  {
    if ((sec_r000387_0_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000387_0_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000387_0_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000387_7_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000387_17_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000387_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000387_17_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000387_7_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000387_17_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000387_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000387_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000387_3_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000387_20_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000387_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000387_20_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000387_3_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000387_20_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000387_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000387_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000387_1_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000387_1_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000387_17_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000387_15_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000387_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000387_15_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000387_17_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000387_15_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000387_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000387_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000387_6_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000387_8_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000387_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000387_8_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000387_6_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000387_8_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000387_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000387_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000387_0_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000387_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000387_0_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000387_0_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000387_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000387_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000387_21_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000387_19_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000387_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000387_19_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000387_21_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000387_19_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000387_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000387_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000387_19_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000387_9_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000387_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000387_9_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000387_19_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000387_9_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000387_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000387_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000387_9_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000387_2_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000387_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000387_2_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000387_9_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000387_2_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000387_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000387_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000387_8_1 & 1) != 0)
  {
    if ((sec_r000387_17_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((sec_r000387_8_2 & 1) != 0)
  {
    if ((sec_r000387_17_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000387_3_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((sec_r000387_3_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000387_4_1 & 1) != 0)
  {
    if ((sec_r000387_18_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000387_19_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000387_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000387_19_1 + 7) & 127;
  }
  if ((sec_r000387_4_2 & 1) != 0)
  {
    if ((sec_r000387_18_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000387_19_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000387_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000387_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000387_2_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000387_3_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000387_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000387_3_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000387_2_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000387_3_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000387_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000387_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000387_14_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000387_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000387_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000387_15_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000387_14_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000387_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000387_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000387_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000387_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000387_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000387_7_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000387_20_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000387_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000387_20_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000387_7_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000387_20_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000387_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000387_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000387_18_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000387_18_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000387_11_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000387_11_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000387_19_1 & 1) != 0)
  {
    if ((sec_r000387_21_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000387_1_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000387_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000387_1_1 + 7) & 127;
  }
  if ((sec_r000387_19_2 & 1) != 0)
  {
    if ((sec_r000387_21_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000387_1_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000387_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000387_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000387_18_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000387_0_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000387_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000387_0_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000387_18_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000387_0_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000387_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000387_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000387_18_1 & 1) != 0)
  {
    if ((sec_r000387_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000387_9_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000387_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000387_9_1 + 7) & 127;
  }
  if ((sec_r000387_18_2 & 1) != 0)
  {
    if ((sec_r000387_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000387_9_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000387_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000387_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000387_9_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000387_2_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000387_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000387_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000387_9_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000387_2_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000387_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000387_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000387_6_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000387_2_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000387_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000387_2_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000387_6_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000387_2_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000387_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000387_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000387_4_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000387_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000387_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000387_15_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000387_4_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000387_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000387_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000387_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000387_21_1 & 1) != 0)
  {
    if ((sec_r000387_0_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000387_16_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000387_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000387_16_1 + 7) & 127;
  }
  if ((sec_r000387_21_2 & 1) != 0)
  {
    if ((sec_r000387_0_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000387_16_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000387_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000387_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000387_18_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000387_5_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000387_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000387_5_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000387_18_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000387_5_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000387_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000387_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000387_9_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000387_9_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000387_20_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000387_20_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000387_12_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000387_9_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000387_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000387_9_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000387_12_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000387_9_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000387_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000387_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000387_14_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000387_14_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000387_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000387_14_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000387_14_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000387_14_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000387_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000387_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000387_9_1 & 1) != 0)
  {
    if ((sec_r000387_20_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((sec_r000387_9_2 & 1) != 0)
  {
    if ((sec_r000387_20_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000387_4_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000387_12_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000387_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000387_12_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000387_4_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000387_12_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000387_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000387_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000387_6_1 & 1) != 0)
  {
    if ((sec_r000387_9_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000387_1_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000387_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000387_1_1 + 7) & 127;
  }
  if ((sec_r000387_6_2 & 1) != 0)
  {
    if ((sec_r000387_9_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000387_1_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000387_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000387_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000387_5_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000387_5_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000387_2_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000387_2_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000387_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000387_2_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000387_2_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000387_2_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000387_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000387_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000387_14_1 & 1) != 0)
  {
    if ((sec_r000387_3_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000387_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000387_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000387_0_1 + 7) & 127;
  }
  if ((sec_r000387_14_2 & 1) != 0)
  {
    if ((sec_r000387_3_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000387_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000387_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000387_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000387_14_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000387_12_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000387_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000387_12_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000387_14_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000387_12_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000387_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000387_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000387_2_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000387_2_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000387_4_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000387_9_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000387_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000387_9_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000387_4_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000387_9_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000387_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000387_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000387_3_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000387_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000387_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000387_15_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000387_3_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000387_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000387_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000387_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000387_5_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000387_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000387_5_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000387_5_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000387_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000387_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000387_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000387_12_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000387_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000387_12_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000387_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000387_12_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000387_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000387_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000387_21_1 & 1) != 0)
  {
    if ((sec_r000387_6_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((sec_r000387_21_2 & 1) != 0)
  {
    if ((sec_r000387_6_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000387_11_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000387_19_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000387_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000387_19_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000387_11_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000387_19_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000387_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000387_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000387_6_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000387_20_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000387_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000387_20_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000387_6_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000387_20_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000387_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000387_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000387_18_1 & 1) != 0)
  {
    if ((sec_r000387_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000387_10_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000387_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000387_10_1 + 7) & 127;
  }
  if ((sec_r000387_18_2 & 1) != 0)
  {
    if ((sec_r000387_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000387_10_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000387_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000387_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000387_2_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000387_2_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000387_21_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000387_12_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000387_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000387_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000387_21_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000387_12_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000387_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000387_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000387_21_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000387_2_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000387_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000387_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000387_21_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000387_2_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000387_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000387_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000387_4_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000387_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000387_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000387_4_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000387_4_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000387_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000387_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000387_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000387_5_1 & 1) != 0)
  {
    if ((sec_r000387_12_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000387_1_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000387_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000387_1_1 + 7) & 127;
  }
  if ((sec_r000387_5_2 & 1) != 0)
  {
    if ((sec_r000387_12_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000387_1_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000387_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000387_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000387_14_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000387_0_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000387_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000387_0_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000387_14_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000387_0_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000387_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000387_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000387_2_1 & 1) != 0)
  {
    if ((sec_r000387_1_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((sec_r000387_2_2 & 1) != 0)
  {
    if ((sec_r000387_1_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000387_1_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000387_10_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000387_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000387_10_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000387_1_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000387_10_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000387_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000387_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000387_19_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000387_13_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000387_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000387_13_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000387_19_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000387_13_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000387_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000387_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000387_0_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000387_8_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000387_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000387_8_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000387_0_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000387_8_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000387_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000387_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000387_5_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000387_8_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000387_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000387_8_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000387_5_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000387_8_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000387_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000387_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000387_3_1 & 1) != 0)
  {
    if ((sec_r000387_11_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000387_11_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000387_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000387_11_1 + 7) & 127;
  }
  if ((sec_r000387_3_2 & 1) != 0)
  {
    if ((sec_r000387_11_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000387_11_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000387_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000387_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000387_6_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000387_14_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000387_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000387_14_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000387_6_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000387_14_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000387_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000387_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000387_17_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000387_8_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000387_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000387_8_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000387_17_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000387_8_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000387_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000387_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000387_8_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000387_18_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000387_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000387_18_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000387_8_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000387_18_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000387_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000387_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000387_19_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000387_6_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000387_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000387_6_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000387_19_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000387_6_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000387_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000387_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000387_21_1 != sec_r000387_21_2);
  __CPROVER_assume(pub_r000387_16_1 == pub_r000387_16_2);
  __CPROVER_assume(pub_r000387_17_1 == pub_r000387_17_2);
  __CPROVER_assume(pub_r000387_4_1 == pub_r000387_4_2);
  __CPROVER_assume(pub_r000387_7_1 == pub_r000387_7_2);
  __CPROVER_assume(sec_r000387_15_1 != sec_r000387_15_2);
  __CPROVER_assume(sec_r000387_18_1 != sec_r000387_18_2);
  __CPROVER_assume(sec_r000387_12_1 != sec_r000387_12_2);
  __CPROVER_assume(pub_r000387_1_1 == pub_r000387_1_2);
  __CPROVER_assume(pub_r000387_6_1 == pub_r000387_6_2);
  __CPROVER_assume(sec_r000387_17_1 != sec_r000387_17_2);
  __CPROVER_assume(pub_r000387_19_1 == pub_r000387_19_2);
  __CPROVER_assume(pub_r000387_10_1 == pub_r000387_10_2);
  __CPROVER_assume(sec_r000387_11_1 != sec_r000387_11_2);
  __CPROVER_assume(pub_r000387_5_1 == pub_r000387_5_2);
  __CPROVER_assume(pub_r000387_14_1 == pub_r000387_14_2);
  __CPROVER_assume(sec_r000387_20_1 != sec_r000387_20_2);
  __CPROVER_assume(sec_r000387_13_1 != sec_r000387_13_2);
  __CPROVER_assume(pub_r000387_13_1 == pub_r000387_13_2);
  __CPROVER_assume(sec_r000387_0_1 != sec_r000387_0_2);
  __CPROVER_assume(pub_r000387_3_1 == pub_r000387_3_2);
  __CPROVER_assume(pub_r000387_0_1 == pub_r000387_0_2);
  __CPROVER_assume(sec_r000387_10_1 != sec_r000387_10_2);
  __CPROVER_assume(sec_r000387_9_1 != sec_r000387_9_2);
  __CPROVER_assume(sec_r000387_3_1 != sec_r000387_3_2);
  __CPROVER_assume(sec_r000387_2_1 != sec_r000387_2_2);
  __CPROVER_assume(sec_r000387_6_1 != sec_r000387_6_2);
  __CPROVER_assume(sec_r000387_7_1 != sec_r000387_7_2);
  __CPROVER_assume(sec_r000387_14_1 != sec_r000387_14_2);
  __CPROVER_assume(pub_r000387_20_1 == pub_r000387_20_2);
  __CPROVER_assume(pub_r000387_9_1 == pub_r000387_9_2);
  __CPROVER_assume(pub_r000387_12_1 == pub_r000387_12_2);
  __CPROVER_assume(sec_r000387_5_1 != sec_r000387_5_2);
  __CPROVER_assume(pub_r000387_11_1 == pub_r000387_11_2);
  __CPROVER_assume(pub_r000387_15_1 == pub_r000387_15_2);
  __CPROVER_assume(sec_r000387_1_1 != sec_r000387_1_2);
  __CPROVER_assume(pub_r000387_2_1 == pub_r000387_2_2);
  __CPROVER_assume(sec_r000387_19_1 != sec_r000387_19_2);
  __CPROVER_assume(sec_r000387_4_1 != sec_r000387_4_2);
  __CPROVER_assume(sec_r000387_16_1 != sec_r000387_16_2);
  __CPROVER_assume(sec_r000387_8_1 != sec_r000387_8_2);
  __CPROVER_assume(pub_r000387_18_1 == pub_r000387_18_2);
  __CPROVER_assume(pub_r000387_8_1 == pub_r000387_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.id == st_var_0_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.capacity == st_var_3_2.capacity);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.head == st_var_3_2.head);
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
}


