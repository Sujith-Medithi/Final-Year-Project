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
struct AudioFrame_R000237_3713_0
{
  int channels;
  short gain;
  short peak;
  int rms;
  short envelope;
  int sample_rate;
  int buffer[3];
};
struct FilterState_R000237_3713_1
{
  int prev_in;
  int damping;
  unsigned char prev_out;
  short cutoff;
  int gain_db;
  int buffer[3];
};
struct CipherContext_R000237_3713_2
{
  int round_key;
  int flags;
  int tag;
  int buffer[3];
};
union PacketPayload_R000237_3713_0
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
void fn_R000237_3713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_11_1)
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

  switch (vector_11_2)
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

  int damping_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_89_1 > 40)
  {
    acc_1 = ((acc_1 + (damping_89_1 * 2)) + 5) & 127;
    aux_1 ^= damping_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_89_2 > 40)
  {
    acc_2 = ((acc_2 + (damping_89_2 * 2)) + 5) & 127;
    aux_2 ^= damping_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_11_1 == vector_11_2);
  assert(damping_89_1 == damping_89_2);
}

int fn_R000237_3713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_11 = (aux + st.buffer[1]) & 3;
  switch (vector_11)
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

  int damping_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_89 > 40)
  {
    acc = ((acc + (damping_89 * 2)) + 5) & 127;
    aux ^= damping_89 & 15;
  }
  else
  {
    acc = ((acc - damping_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_30_1 = local_arr_1[aux_1 % 3];
  int tracker_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_30_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_92_1 > 50)
  {
    acc_1 = ((acc_1 + (cursor_92_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_92_2 > 50)
  {
    acc_2 = ((acc_2 + (cursor_92_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_50_1) & 63;
  aux_2 = (aux_2 + coefficient_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_30_1 == tracker_30_2);
  assert(cursor_92_1 == cursor_92_2);
  assert(coefficient_50_1 == coefficient_50_2);
}

int fn_R000237_3713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int tracker_30 = local_arr[aux % 3];
  acc = (acc + (tracker_30 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_92 > 50)
  {
    acc = ((acc + (cursor_92 * 2)) + 5) & 127;
    aux ^= cursor_92 & 15;
  }
  else
  {
    acc = ((acc - cursor_92) + 11) & 127;
    aux += 3;
  }
  int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000237_3713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_86_1 > 42)
  {
    acc_1 = ((acc_1 + (margin_86_1 * 2)) + 5) & 127;
    aux_1 ^= margin_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_86_2 > 42)
  {
    acc_2 = ((acc_2 + (margin_86_2 * 2)) + 5) & 127;
    aux_2 ^= margin_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_64_1) & 63;
  aux_2 = (aux_2 + residue_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_86_1 == margin_86_2);
  assert(residue_64_1 == residue_64_2);
}

int fn_R000237_3713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_86 > 42)
  {
    acc = ((acc + (margin_86 * 2)) + 5) & 127;
    aux ^= margin_86 & 15;
  }
  else
  {
    acc = ((acc - margin_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000237_3713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st_1 = {0};
  struct FilterState_R000237_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_39_1)
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

  switch (offset_39_2)
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

  int delta_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_36_1) & 63;
  aux_2 = (aux_2 + delta_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_39_1 == offset_39_2);
  assert(delta_36_1 == delta_36_2);
}

int fn_R000237_3713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_39 = (aux + st.buffer[1]) & 3;
  switch (offset_39)
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

  int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000237_3713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
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
  int threshold_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_35_1)
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

  switch (threshold_35_2)
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

  int sample_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_90_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_90_1 * 2)) + 5) & 127;
    aux_1 ^= sample_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_90_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_90_2 * 2)) + 5) & 127;
    aux_2 ^= sample_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_45_1) & 63;
  aux_2 = (aux_2 + vector_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_35_1 == threshold_35_2);
  assert(sample_90_1 == sample_90_2);
  assert(vector_45_1 == vector_45_2);
}

int fn_R000237_3713_4(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_35 = (aux + st.buffer[1]) & 3;
  switch (threshold_35)
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

  int sample_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_90 > 25)
  {
    acc = ((acc + (sample_90 * 2)) + 5) & 127;
    aux ^= sample_90 & 15;
  }
  else
  {
    acc = ((acc - sample_90) + 11) & 127;
    aux += 3;
  }
  int vector_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000237_3713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st_1 = {0};
  struct FilterState_R000237_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_92_1 = local_arr_1[aux_1 % 3];
  int damping_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_92_2 * 2)) & 127;
  int tracker_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_97_1)
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

  switch (tracker_97_2)
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

  int accumulator_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_70_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_70_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_70_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_70_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_44_1) & 63;
  aux_2 = (aux_2 + weight_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_92_1 == damping_92_2);
  assert(tracker_97_1 == tracker_97_2);
  assert(accumulator_70_1 == accumulator_70_2);
  assert(weight_44_1 == weight_44_2);
}

int fn_R000237_3713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_92 = local_arr[aux % 3];
  acc = (acc + (damping_92 * 2)) & 127;
  int tracker_97 = (aux + st.buffer[1]) & 3;
  switch (tracker_97)
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

  int accumulator_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_70 > 50)
  {
    acc = ((acc + (accumulator_70 * 2)) + 5) & 127;
    aux ^= accumulator_70 & 15;
  }
  else
  {
    acc = ((acc - accumulator_70) + 11) & 127;
    aux += 3;
  }
  int weight_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000237_3713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st_1 = {0};
  struct FilterState_R000237_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_15_1 = local_arr_1[aux_1 % 3];
  int parity_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_78_1 > 34)
  {
    acc_1 = ((acc_1 + (checksum_78_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_78_2 > 34)
  {
    acc_2 = ((acc_2 + (checksum_78_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_15_1 == parity_15_2);
  assert(checksum_78_1 == checksum_78_2);
}

int fn_R000237_3713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int parity_15 = local_arr[aux % 3];
  acc = (acc + (parity_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_78 > 34)
  {
    acc = ((acc + (checksum_78 * 2)) + 5) & 127;
    aux ^= checksum_78 & 15;
  }
  else
  {
    acc = ((acc - checksum_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st_1 = {0};
  struct FilterState_R000237_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_82_1 = local_arr_1[aux_1 % 3];
  int margin_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_12_1 > 46)
  {
    acc_1 = ((acc_1 + (damping_12_1 * 2)) + 5) & 127;
    aux_1 ^= damping_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_12_2 > 46)
  {
    acc_2 = ((acc_2 + (damping_12_2 * 2)) + 5) & 127;
    aux_2 ^= damping_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_82_1 == margin_82_2);
  assert(damping_12_1 == damping_12_2);
}

int fn_R000237_3713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int margin_82 = local_arr[aux % 3];
  acc = (acc + (margin_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_12 > 46)
  {
    acc = ((acc + (damping_12 * 2)) + 5) & 127;
    aux ^= damping_12 & 15;
  }
  else
  {
    acc = ((acc - damping_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_76_1) & 63;
  aux_2 = (aux_2 + segment_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_98_1 = local_arr_1[aux_1 % 3];
  int index_reg_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_98_2 * 2)) & 127;
  int cursor_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_74_1)
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

  switch (cursor_74_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_76_1 == segment_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_98_1 == index_reg_98_2);
  assert(cursor_74_1 == cursor_74_2);
}

int fn_R000237_3713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_76) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_98 = local_arr[aux % 3];
  acc = (acc + (index_reg_98 * 2)) & 127;
  int cursor_74 = (aux + st.buffer[1]) & 3;
  switch (cursor_74)
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

void fn_R000237_3713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_50_1 = local_arr_1[aux_1 % 3];
  int delta_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_47_1) & 63;
  aux_2 = (aux_2 + checksum_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_96_1 > 41)
  {
    acc_1 = ((acc_1 + (segment_96_1 * 2)) + 5) & 127;
    aux_1 ^= segment_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_96_2 > 41)
  {
    acc_2 = ((acc_2 + (segment_96_2 * 2)) + 5) & 127;
    aux_2 ^= segment_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_50_1 == delta_50_2);
  assert(checksum_47_1 == checksum_47_2);
  assert(segment_96_1 == segment_96_2);
}

int fn_R000237_3713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int delta_50 = local_arr[aux % 3];
  acc = (acc + (delta_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_47) & 63;
  acc ^= aux;
  int segment_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_96 > 41)
  {
    acc = ((acc + (segment_96 * 2)) + 5) & 127;
    aux ^= segment_96 & 15;
  }
  else
  {
    acc = ((acc - segment_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int pivot_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_46_1) & 63;
  aux_2 = (aux_2 + pivot_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_97_1 > 13)
  {
    acc_1 = ((acc_1 + (vector_97_1 * 2)) + 5) & 127;
    aux_1 ^= vector_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_97_2 > 13)
  {
    acc_2 = ((acc_2 + (vector_97_2 * 2)) + 5) & 127;
    aux_2 ^= vector_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_88_1 = local_arr_1[aux_1 % 3];
  int vector_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(vector_97_1 == vector_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_88_1 == vector_88_2);
}

int fn_R000237_3713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int pivot_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_46) & 63;
  acc ^= aux;
  int vector_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_97 > 13)
  {
    acc = ((acc + (vector_97 * 2)) + 5) & 127;
    aux ^= vector_97 & 15;
  }
  else
  {
    acc = ((acc - vector_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_88 = local_arr[aux % 3];
  acc = (acc + (vector_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000237_3713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_62_1) & 63;
  aux_2 = (aux_2 + mask_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_79_1 > 21)
  {
    acc_1 = ((acc_1 + (quantum_79_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_79_2 > 21)
  {
    acc_2 = ((acc_2 + (quantum_79_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_62_1 == mask_62_2);
  assert(quantum_79_1 == quantum_79_2);
}

int fn_R000237_3713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_62) & 63;
  acc ^= aux;
  int quantum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_79 > 21)
  {
    acc = ((acc + (quantum_79 * 2)) + 5) & 127;
    aux ^= quantum_79 & 15;
  }
  else
  {
    acc = ((acc - quantum_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_78_1) & 63;
  aux_2 = (aux_2 + phase_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_23_1)
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

  switch (offset_23_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_78_1 == phase_78_2);
  assert(offset_23_1 == offset_23_2);
}

int fn_R000237_3713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_23 = (aux + st.buffer[1]) & 3;
  switch (offset_23)
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

void fn_R000237_3713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_90_1)
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

  switch (window_90_2)
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
  int index_reg_50_1 = local_arr_1[aux_1 % 3];
  int index_reg_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_90_1 == window_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_50_1 == index_reg_50_2);
}

int fn_R000237_3713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_90 = (aux + st.buffer[1]) & 3;
  switch (window_90)
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
  int index_reg_50 = local_arr[aux % 3];
  acc = (acc + (index_reg_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000237_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st_1 = {0};
  struct FilterState_R000237_3713_1 st_2 = {0};
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
  int weight_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_99_1 > 45)
  {
    acc_1 = ((acc_1 + (weight_99_1 * 2)) + 5) & 127;
    aux_1 ^= weight_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_99_2 > 45)
  {
    acc_2 = ((acc_2 + (weight_99_2 * 2)) + 5) & 127;
    aux_2 ^= weight_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_52_1) & 63;
  aux_2 = (aux_2 + bound_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_96_1)
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

  switch (delta_96_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_99_1 == weight_99_2);
  assert(bound_52_1 == bound_52_2);
  assert(delta_96_1 == delta_96_2);
}

int fn_R000237_3713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000237_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_99 > 45)
  {
    acc = ((acc + (weight_99 * 2)) + 5) & 127;
    aux ^= weight_99 & 15;
  }
  else
  {
    acc = ((acc - weight_99) + 11) & 127;
    aux += 3;
  }
  int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_52) & 63;
  acc ^= aux;
  int delta_96 = (aux + st.buffer[1]) & 3;
  switch (delta_96)
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

void fn_R000237_3713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_79_1) & 63;
  aux_2 = (aux_2 + pivot_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_50_1 > 49)
  {
    acc_1 = ((acc_1 + (factor_50_1 * 2)) + 5) & 127;
    aux_1 ^= factor_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_50_2 > 49)
  {
    acc_2 = ((acc_2 + (factor_50_2 * 2)) + 5) & 127;
    aux_2 ^= factor_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_87_1)
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

  switch (quotient_87_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_79_1 == pivot_79_2);
  assert(factor_50_1 == factor_50_2);
  assert(quotient_87_1 == quotient_87_2);
}

int fn_R000237_3713_15(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_79) & 63;
  acc ^= aux;
  int factor_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_50 > 49)
  {
    acc = ((acc + (factor_50 * 2)) + 5) & 127;
    aux ^= factor_50 & 15;
  }
  else
  {
    acc = ((acc - factor_50) + 11) & 127;
    aux += 3;
  }
  int quotient_87 = (aux + st.buffer[1]) & 3;
  switch (quotient_87)
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

void fn_R000237_3713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_25_1)
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

  switch (segment_25_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_25_1 == segment_25_2);
}

int fn_R000237_3713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_25 = (aux + st.buffer[1]) & 3;
  switch (segment_25)
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

void fn_R000237_3713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st_1 = {0};
  struct CipherContext_R000237_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_27_1)
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

  switch (quantum_27_2)
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

  int segment_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_88_1) & 63;
  aux_2 = (aux_2 + segment_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_88_1 > 14)
  {
    acc_1 = ((acc_1 + (checksum_88_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_88_2 > 14)
  {
    acc_2 = ((acc_2 + (checksum_88_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_27_1 == quantum_27_2);
  assert(segment_88_1 == segment_88_2);
  assert(checksum_88_1 == checksum_88_2);
}

int fn_R000237_3713_17(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000237_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_27 = (aux + st.buffer[1]) & 3;
  switch (quantum_27)
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

  int segment_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_88) & 63;
  acc ^= aux;
  int checksum_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_88 > 14)
  {
    acc = ((acc + (checksum_88 * 2)) + 5) & 127;
    aux ^= checksum_88 & 15;
  }
  else
  {
    acc = ((acc - checksum_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000237_3713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_84_1) & 63;
  aux_2 = (aux_2 + index_reg_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_94_1)
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

  switch (checksum_94_2)
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
  int index_reg_82_1 = local_arr_1[aux_1 % 3];
  int index_reg_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
  assert(checksum_94_1 == checksum_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_82_1 == index_reg_82_2);
}

int fn_R000237_3713_18(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_84) & 63;
  acc ^= aux;
  int checksum_94 = (aux + st.buffer[1]) & 3;
  switch (checksum_94)
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
  int index_reg_82 = local_arr[aux % 3];
  acc = (acc + (index_reg_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000237_3713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st_1 = {0};
  struct AudioFrame_R000237_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_21_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_21_1 * 2)) + 5) & 127;
    aux_1 ^= metric_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_21_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_21_2 * 2)) + 5) & 127;
    aux_2 ^= metric_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_62_1)
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

  switch (sample_62_2)
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
  int coefficient_65_1 = local_arr_1[aux_1 % 3];
  int coefficient_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_65_2 * 2)) & 127;
  int cursor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_12_1) & 63;
  aux_2 = (aux_2 + cursor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_21_1 == metric_21_2);
  assert(sample_62_1 == sample_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(cursor_12_1 == cursor_12_2);
}

int fn_R000237_3713_19(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000237_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_21 > 34)
  {
    acc = ((acc + (metric_21 * 2)) + 5) & 127;
    aux ^= metric_21 & 15;
  }
  else
  {
    acc = ((acc - metric_21) + 11) & 127;
    aux += 3;
  }
  int sample_62 = (aux + st.buffer[1]) & 3;
  switch (sample_62)
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
  int coefficient_65 = local_arr[aux % 3];
  acc = (acc + (coefficient_65 * 2)) & 127;
  int cursor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000237_0_1;
  int sec_r000237_0_2;
  int sec_r000237_1_1;
  int sec_r000237_1_2;
  int sec_r000237_2_1;
  int sec_r000237_2_2;
  int sec_r000237_3_1;
  int sec_r000237_3_2;
  int sec_r000237_4_1;
  int sec_r000237_4_2;
  int sec_r000237_5_1;
  int sec_r000237_5_2;
  int sec_r000237_6_1;
  int sec_r000237_6_2;
  int sec_r000237_7_1;
  int sec_r000237_7_2;
  int sec_r000237_8_1;
  int sec_r000237_8_2;
  int sec_r000237_9_1;
  int sec_r000237_9_2;
  int sec_r000237_10_1;
  int sec_r000237_10_2;
  int sec_r000237_11_1;
  int sec_r000237_11_2;
  int sec_r000237_12_1;
  int sec_r000237_12_2;
  int sec_r000237_13_1;
  int sec_r000237_13_2;
  int sec_r000237_14_1;
  int sec_r000237_14_2;
  int sec_r000237_15_1;
  int sec_r000237_15_2;
  int sec_r000237_16_1;
  int sec_r000237_16_2;
  int sec_r000237_17_1;
  int sec_r000237_17_2;
  int sec_r000237_18_1;
  int sec_r000237_18_2;
  int sec_r000237_19_1;
  int sec_r000237_19_2;
  int sec_r000237_20_1;
  int sec_r000237_20_2;
  int sec_r000237_21_1;
  int sec_r000237_21_2;
  int sec_r000237_22_1;
  int sec_r000237_22_2;
  int sec_r000237_23_1;
  int sec_r000237_23_2;
  int pub_r000237_0_1;
  int pub_r000237_0_2;
  int pub_r000237_1_1;
  int pub_r000237_1_2;
  int pub_r000237_2_1;
  int pub_r000237_2_2;
  int pub_r000237_3_1;
  int pub_r000237_3_2;
  int pub_r000237_4_1;
  int pub_r000237_4_2;
  int pub_r000237_5_1;
  int pub_r000237_5_2;
  int pub_r000237_6_1;
  int pub_r000237_6_2;
  int pub_r000237_7_1;
  int pub_r000237_7_2;
  int pub_r000237_8_1;
  int pub_r000237_8_2;
  int pub_r000237_9_1;
  int pub_r000237_9_2;
  int pub_r000237_10_1;
  int pub_r000237_10_2;
  int pub_r000237_11_1;
  int pub_r000237_11_2;
  int pub_r000237_12_1;
  int pub_r000237_12_2;
  int pub_r000237_13_1;
  int pub_r000237_13_2;
  int pub_r000237_14_1;
  int pub_r000237_14_2;
  int pub_r000237_15_1;
  int pub_r000237_15_2;
  int pub_r000237_16_1;
  int pub_r000237_16_2;
  int pub_r000237_17_1;
  int pub_r000237_17_2;
  int pub_r000237_18_1;
  int pub_r000237_18_2;
  int pub_r000237_19_1;
  int pub_r000237_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000237_0_1 >= (-100)) && (pub_r000237_0_1 <= 100));
  __CPROVER_assume((pub_r000237_0_2 >= (-100)) && (pub_r000237_0_2 <= 100));
  __CPROVER_assume((pub_r000237_1_1 >= (-100)) && (pub_r000237_1_1 <= 100));
  __CPROVER_assume((pub_r000237_1_2 >= (-100)) && (pub_r000237_1_2 <= 100));
  __CPROVER_assume((pub_r000237_2_1 >= (-100)) && (pub_r000237_2_1 <= 100));
  __CPROVER_assume((pub_r000237_2_2 >= (-100)) && (pub_r000237_2_2 <= 100));
  __CPROVER_assume((pub_r000237_3_1 >= (-100)) && (pub_r000237_3_1 <= 100));
  __CPROVER_assume((pub_r000237_3_2 >= (-100)) && (pub_r000237_3_2 <= 100));
  __CPROVER_assume((pub_r000237_4_1 >= (-100)) && (pub_r000237_4_1 <= 100));
  __CPROVER_assume((pub_r000237_4_2 >= (-100)) && (pub_r000237_4_2 <= 100));
  __CPROVER_assume((pub_r000237_5_1 >= (-100)) && (pub_r000237_5_1 <= 100));
  __CPROVER_assume((pub_r000237_5_2 >= (-100)) && (pub_r000237_5_2 <= 100));
  __CPROVER_assume((pub_r000237_6_1 >= (-100)) && (pub_r000237_6_1 <= 100));
  __CPROVER_assume((pub_r000237_6_2 >= (-100)) && (pub_r000237_6_2 <= 100));
  __CPROVER_assume((pub_r000237_7_1 >= (-100)) && (pub_r000237_7_1 <= 100));
  __CPROVER_assume((pub_r000237_7_2 >= (-100)) && (pub_r000237_7_2 <= 100));
  __CPROVER_assume((pub_r000237_8_1 >= (-100)) && (pub_r000237_8_1 <= 100));
  __CPROVER_assume((pub_r000237_8_2 >= (-100)) && (pub_r000237_8_2 <= 100));
  __CPROVER_assume((pub_r000237_9_1 >= (-100)) && (pub_r000237_9_1 <= 100));
  __CPROVER_assume((pub_r000237_9_2 >= (-100)) && (pub_r000237_9_2 <= 100));
  __CPROVER_assume((pub_r000237_10_1 >= (-100)) && (pub_r000237_10_1 <= 100));
  __CPROVER_assume((pub_r000237_10_2 >= (-100)) && (pub_r000237_10_2 <= 100));
  __CPROVER_assume((pub_r000237_11_1 >= (-100)) && (pub_r000237_11_1 <= 100));
  __CPROVER_assume((pub_r000237_11_2 >= (-100)) && (pub_r000237_11_2 <= 100));
  __CPROVER_assume((pub_r000237_12_1 >= (-100)) && (pub_r000237_12_1 <= 100));
  __CPROVER_assume((pub_r000237_12_2 >= (-100)) && (pub_r000237_12_2 <= 100));
  __CPROVER_assume((pub_r000237_13_1 >= (-100)) && (pub_r000237_13_1 <= 100));
  __CPROVER_assume((pub_r000237_13_2 >= (-100)) && (pub_r000237_13_2 <= 100));
  __CPROVER_assume((pub_r000237_14_1 >= (-100)) && (pub_r000237_14_1 <= 100));
  __CPROVER_assume((pub_r000237_14_2 >= (-100)) && (pub_r000237_14_2 <= 100));
  __CPROVER_assume((pub_r000237_15_1 >= (-100)) && (pub_r000237_15_1 <= 100));
  __CPROVER_assume((pub_r000237_15_2 >= (-100)) && (pub_r000237_15_2 <= 100));
  __CPROVER_assume((pub_r000237_16_1 >= (-100)) && (pub_r000237_16_1 <= 100));
  __CPROVER_assume((pub_r000237_16_2 >= (-100)) && (pub_r000237_16_2 <= 100));
  __CPROVER_assume((pub_r000237_17_1 >= (-100)) && (pub_r000237_17_1 <= 100));
  __CPROVER_assume((pub_r000237_17_2 >= (-100)) && (pub_r000237_17_2 <= 100));
  __CPROVER_assume((pub_r000237_18_1 >= (-100)) && (pub_r000237_18_1 <= 100));
  __CPROVER_assume((pub_r000237_18_2 >= (-100)) && (pub_r000237_18_2 <= 100));
  __CPROVER_assume((pub_r000237_19_1 >= (-100)) && (pub_r000237_19_1 <= 100));
  __CPROVER_assume((pub_r000237_19_2 >= (-100)) && (pub_r000237_19_2 <= 100));
  __CPROVER_assume((sec_r000237_0_1 >= 0) && (sec_r000237_0_1 <= 255));
  __CPROVER_assume((sec_r000237_0_2 >= 0) && (sec_r000237_0_2 <= 255));
  __CPROVER_assume((sec_r000237_1_1 >= 0) && (sec_r000237_1_1 <= 255));
  __CPROVER_assume((sec_r000237_1_2 >= 0) && (sec_r000237_1_2 <= 255));
  __CPROVER_assume((sec_r000237_2_1 >= 0) && (sec_r000237_2_1 <= 255));
  __CPROVER_assume((sec_r000237_2_2 >= 0) && (sec_r000237_2_2 <= 255));
  __CPROVER_assume((sec_r000237_3_1 >= 0) && (sec_r000237_3_1 <= 255));
  __CPROVER_assume((sec_r000237_3_2 >= 0) && (sec_r000237_3_2 <= 255));
  __CPROVER_assume((sec_r000237_4_1 >= 0) && (sec_r000237_4_1 <= 255));
  __CPROVER_assume((sec_r000237_4_2 >= 0) && (sec_r000237_4_2 <= 255));
  __CPROVER_assume((sec_r000237_5_1 >= 0) && (sec_r000237_5_1 <= 255));
  __CPROVER_assume((sec_r000237_5_2 >= 0) && (sec_r000237_5_2 <= 255));
  __CPROVER_assume((sec_r000237_6_1 >= 0) && (sec_r000237_6_1 <= 255));
  __CPROVER_assume((sec_r000237_6_2 >= 0) && (sec_r000237_6_2 <= 255));
  __CPROVER_assume((sec_r000237_7_1 >= 0) && (sec_r000237_7_1 <= 255));
  __CPROVER_assume((sec_r000237_7_2 >= 0) && (sec_r000237_7_2 <= 255));
  __CPROVER_assume((sec_r000237_8_1 >= 0) && (sec_r000237_8_1 <= 255));
  __CPROVER_assume((sec_r000237_8_2 >= 0) && (sec_r000237_8_2 <= 255));
  __CPROVER_assume((sec_r000237_9_1 >= 0) && (sec_r000237_9_1 <= 255));
  __CPROVER_assume((sec_r000237_9_2 >= 0) && (sec_r000237_9_2 <= 255));
  __CPROVER_assume((sec_r000237_10_1 >= 0) && (sec_r000237_10_1 <= 255));
  __CPROVER_assume((sec_r000237_10_2 >= 0) && (sec_r000237_10_2 <= 255));
  __CPROVER_assume((sec_r000237_11_1 >= 0) && (sec_r000237_11_1 <= 255));
  __CPROVER_assume((sec_r000237_11_2 >= 0) && (sec_r000237_11_2 <= 255));
  __CPROVER_assume((sec_r000237_12_1 >= 0) && (sec_r000237_12_1 <= 255));
  __CPROVER_assume((sec_r000237_12_2 >= 0) && (sec_r000237_12_2 <= 255));
  __CPROVER_assume((sec_r000237_13_1 >= 0) && (sec_r000237_13_1 <= 255));
  __CPROVER_assume((sec_r000237_13_2 >= 0) && (sec_r000237_13_2 <= 255));
  __CPROVER_assume((sec_r000237_14_1 >= 0) && (sec_r000237_14_1 <= 255));
  __CPROVER_assume((sec_r000237_14_2 >= 0) && (sec_r000237_14_2 <= 255));
  __CPROVER_assume((sec_r000237_15_1 >= 0) && (sec_r000237_15_1 <= 255));
  __CPROVER_assume((sec_r000237_15_2 >= 0) && (sec_r000237_15_2 <= 255));
  __CPROVER_assume((sec_r000237_16_1 >= 0) && (sec_r000237_16_1 <= 255));
  __CPROVER_assume((sec_r000237_16_2 >= 0) && (sec_r000237_16_2 <= 255));
  __CPROVER_assume((sec_r000237_17_1 >= 0) && (sec_r000237_17_1 <= 255));
  __CPROVER_assume((sec_r000237_17_2 >= 0) && (sec_r000237_17_2 <= 255));
  __CPROVER_assume((sec_r000237_18_1 >= 0) && (sec_r000237_18_1 <= 255));
  __CPROVER_assume((sec_r000237_18_2 >= 0) && (sec_r000237_18_2 <= 255));
  __CPROVER_assume((sec_r000237_19_1 >= 0) && (sec_r000237_19_1 <= 255));
  __CPROVER_assume((sec_r000237_19_2 >= 0) && (sec_r000237_19_2 <= 255));
  __CPROVER_assume((sec_r000237_20_1 >= 0) && (sec_r000237_20_1 <= 255));
  __CPROVER_assume((sec_r000237_20_2 >= 0) && (sec_r000237_20_2 <= 255));
  __CPROVER_assume((sec_r000237_21_1 >= 0) && (sec_r000237_21_1 <= 255));
  __CPROVER_assume((sec_r000237_21_2 >= 0) && (sec_r000237_21_2 <= 255));
  __CPROVER_assume((sec_r000237_22_1 >= 0) && (sec_r000237_22_1 <= 255));
  __CPROVER_assume((sec_r000237_22_2 >= 0) && (sec_r000237_22_2 <= 255));
  __CPROVER_assume((sec_r000237_23_1 >= 0) && (sec_r000237_23_1 <= 255));
  __CPROVER_assume((sec_r000237_23_2 >= 0) && (sec_r000237_23_2 <= 255));
  struct AudioFrame_R000237_3713_0 st_var_0_1 = {0};
  struct AudioFrame_R000237_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000237_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000237_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000237_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000237_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000237_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000237_0_2 + 7) & 15;
  struct FilterState_R000237_3713_1 st_var_1_1 = {0};
  struct FilterState_R000237_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000237_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000237_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000237_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000237_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000237_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000237_0_2 + 9) & 15;
  struct CipherContext_R000237_3713_2 st_var_2_1 = {0};
  struct CipherContext_R000237_3713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000237_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000237_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000237_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000237_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000237_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000237_0_2 + 11) & 15;
  union PacketPayload_R000237_3713_0 u_var_1;
  union PacketPayload_R000237_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 50)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 50)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
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
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 35)
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
  if (stage_v_17_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 35)
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
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
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
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
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

  switch (stage_v_24_2)
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
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 33)
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
  if (stage_v_29_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 33)
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
  int stage_v_30_1 = ((st_var_0_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_0_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 45)
    {
      chk_sum_1 ^= stage_v_30_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_30_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 45)
    {
      chk_sum_2 ^= stage_v_30_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((st_var_0_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_0_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 33)
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
  if (stage_v_33_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 33)
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
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (st_var_2_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_2_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 25)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 25)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 42) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 31)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 31)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 47) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 29)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 29)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = (st_var_1_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_1_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
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
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_65_1 = ((st_var_2_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_2_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 30)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 30)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 70) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 75) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 75) & 15;
  int stage_v_74_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_74_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= stage_v_74_1;
  chk_sum_2 ^= stage_v_74_2;
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
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((st_var_0_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_0_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 30)
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
  if (stage_v_78_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 30)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((st_var_0_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_0_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 29)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 29)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 83) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 47)
    {
      chk_sum_1 ^= stage_v_84_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_84_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 47)
    {
      chk_sum_2 ^= stage_v_84_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000237_6_1 & 1) != 0)
  {
    if ((sec_r000237_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000237_9_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000237_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000237_9_1 + 7) & 127;
  }
  if ((sec_r000237_6_2 & 1) != 0)
  {
    if ((sec_r000237_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000237_9_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000237_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000237_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000237_6_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000237_6_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000237_10_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000237_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000237_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000237_13_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000237_10_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000237_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000237_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000237_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000237_20_1 & 1) != 0)
  {
    if ((sec_r000237_6_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000237_16_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000237_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000237_16_1 + 7) & 127;
  }
  if ((sec_r000237_20_2 & 1) != 0)
  {
    if ((sec_r000237_6_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000237_16_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000237_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000237_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000237_18_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000237_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000237_18_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000237_18_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000237_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000237_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000237_1_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000237_1_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000237_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000237_1_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000237_1_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000237_1_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000237_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000237_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_22_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000237_17_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000237_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000237_17_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_22_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000237_17_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000237_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000237_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000237_13_1 & 1) != 0)
  {
    if ((sec_r000237_17_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000237_16_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000237_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000237_16_1 + 7) & 127;
  }
  if ((sec_r000237_13_2 & 1) != 0)
  {
    if ((sec_r000237_17_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000237_16_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000237_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000237_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000237_17_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000237_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000237_17_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000237_17_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000237_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000237_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000237_1_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000237_4_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000237_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000237_4_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000237_1_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000237_4_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000237_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000237_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000237_3_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000237_3_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000237_13_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000237_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000237_13_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000237_13_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000237_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000237_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000237_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000237_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000237_3_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000237_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000237_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000237_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000237_15_1 & 1) != 0)
  {
    if ((sec_r000237_17_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000237_4_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000237_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000237_4_1 + 7) & 127;
  }
  if ((sec_r000237_15_2 & 1) != 0)
  {
    if ((sec_r000237_17_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000237_4_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000237_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000237_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000237_9_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000237_9_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000237_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000237_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000237_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000237_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000237_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000237_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000237_17_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000237_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000237_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000237_4_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000237_17_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000237_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000237_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000237_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000237_15_1 & 1) != 0)
  {
    if ((sec_r000237_17_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((sec_r000237_15_2 & 1) != 0)
  {
    if ((sec_r000237_17_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000237_12_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000237_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000237_12_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000237_12_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000237_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000237_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000237_21_1 & 1) != 0)
  {
    if ((sec_r000237_4_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000237_8_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000237_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000237_8_1 + 7) & 127;
  }
  if ((sec_r000237_21_2 & 1) != 0)
  {
    if ((sec_r000237_4_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000237_8_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000237_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000237_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000237_18_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000237_18_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000237_22_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000237_7_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000237_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000237_7_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000237_22_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000237_7_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000237_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000237_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000237_11_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((sec_r000237_11_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000237_16_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000237_16_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000237_11_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000237_1_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000237_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000237_1_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000237_11_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000237_1_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000237_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000237_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000237_13_1 & 1) != 0)
  {
    if ((sec_r000237_9_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000237_19_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000237_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000237_19_1 + 7) & 127;
  }
  if ((sec_r000237_13_2 & 1) != 0)
  {
    if ((sec_r000237_9_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000237_19_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000237_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000237_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000237_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000237_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000237_16_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000237_9_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000237_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000237_9_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000237_16_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000237_9_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000237_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000237_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000237_0_1 & 1) != 0)
  {
    if ((sec_r000237_9_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000237_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000237_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000237_0_1 + 7) & 127;
  }
  if ((sec_r000237_0_2 & 1) != 0)
  {
    if ((sec_r000237_9_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000237_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000237_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000237_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000237_7_1 & 1) != 0)
  {
    if ((sec_r000237_4_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((sec_r000237_7_2 & 1) != 0)
  {
    if ((sec_r000237_4_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000237_5_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000237_8_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000237_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000237_8_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000237_5_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000237_8_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000237_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000237_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000237_19_1 & 1) != 0)
  {
    if ((sec_r000237_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000237_11_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000237_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000237_11_1 + 7) & 127;
  }
  if ((sec_r000237_19_2 & 1) != 0)
  {
    if ((sec_r000237_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000237_11_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000237_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000237_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000237_8_1 & 1) != 0)
  {
    if ((sec_r000237_0_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000237_9_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000237_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000237_9_1 + 7) & 127;
  }
  if ((sec_r000237_8_2 & 1) != 0)
  {
    if ((sec_r000237_0_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000237_9_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000237_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000237_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000237_2_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000237_13_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000237_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000237_13_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000237_2_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000237_13_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000237_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000237_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000237_0_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000237_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000237_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000237_4_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000237_0_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000237_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000237_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000237_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000237_16_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000237_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000237_16_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000237_16_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000237_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000237_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000237_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000237_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000237_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000237_7_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000237_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000237_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000237_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000237_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000237_8_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000237_12_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000237_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000237_12_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000237_8_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000237_12_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000237_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000237_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000237_12_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000237_8_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000237_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000237_8_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000237_12_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000237_8_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000237_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000237_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000237_12_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000237_12_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000237_14_1 & 1) != 0)
  {
    if ((sec_r000237_4_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000237_17_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000237_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000237_17_1 + 7) & 127;
  }
  if ((sec_r000237_14_2 & 1) != 0)
  {
    if ((sec_r000237_4_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000237_17_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000237_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000237_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000237_14_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000237_14_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000237_15_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000237_9_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000237_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000237_9_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000237_15_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000237_9_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000237_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000237_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000237_17_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000237_17_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000237_5_1 & 1) != 0)
  {
    if ((sec_r000237_14_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((sec_r000237_5_2 & 1) != 0)
  {
    if ((sec_r000237_14_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000237_22_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000237_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000237_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000237_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000237_22_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000237_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000237_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000237_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000237_6_1 & 1) != 0)
  {
    if ((sec_r000237_13_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((sec_r000237_6_2 & 1) != 0)
  {
    if ((sec_r000237_13_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000237_3_1 & 1) != 0)
  {
    if ((sec_r000237_11_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000237_18_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000237_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000237_18_1 + 7) & 127;
  }
  if ((sec_r000237_3_2 & 1) != 0)
  {
    if ((sec_r000237_11_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000237_18_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000237_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000237_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000237_2_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000237_2_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000237_20_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000237_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000237_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000237_5_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000237_20_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000237_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000237_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000237_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000237_9_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000237_9_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r000237_11_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000237_1_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000237_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000237_1_1 + 7) & 127;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r000237_11_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000237_1_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000237_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000237_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000237_7_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000237_7_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r000237_5_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000237_0_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000237_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000237_0_1 + 7) & 127;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r000237_5_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000237_0_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000237_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000237_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000237_9_1 & 1) != 0)
  {
    if ((sec_r000237_13_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((sec_r000237_9_2 & 1) != 0)
  {
    if ((sec_r000237_13_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000237_1_1 & 1) != 0)
  {
    if ((sec_r000237_15_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((sec_r000237_1_2 & 1) != 0)
  {
    if ((sec_r000237_15_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000237_10_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000237_13_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000237_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000237_13_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000237_10_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000237_13_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000237_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000237_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000237_18_1 & 1) != 0)
  {
    if ((sec_r000237_13_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000237_19_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000237_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000237_19_1 + 7) & 127;
  }
  if ((sec_r000237_18_2 & 1) != 0)
  {
    if ((sec_r000237_13_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000237_19_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000237_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000237_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000237_15_1 & 1) != 0)
  {
    if ((sec_r000237_12_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((sec_r000237_15_2 & 1) != 0)
  {
    if ((sec_r000237_12_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000237_16_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000237_2_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000237_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000237_2_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000237_16_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000237_2_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000237_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000237_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000237_22_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000237_11_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000237_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000237_11_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000237_22_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000237_11_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000237_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000237_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000237_10_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000237_2_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000237_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000237_2_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000237_10_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000237_2_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000237_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000237_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000237_5_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000237_3_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000237_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000237_3_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000237_5_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000237_3_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000237_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000237_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000237_6_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000237_16_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000237_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000237_16_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000237_6_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000237_16_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000237_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000237_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000237_17_1 & 1) != 0)
  {
    if ((sec_r000237_16_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((sec_r000237_17_2 & 1) != 0)
  {
    if ((sec_r000237_16_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000237_3_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000237_3_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r000237_1_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000237_19_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000237_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000237_19_1 + 7) & 127;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((sec_r000237_1_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000237_19_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000237_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000237_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000237_7_1 & 1) != 0)
  {
    if ((sec_r000237_18_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000237_14_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000237_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000237_14_1 + 7) & 127;
  }
  if ((sec_r000237_7_2 & 1) != 0)
  {
    if ((sec_r000237_18_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000237_14_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000237_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000237_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000237_4_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000237_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000237_4_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000237_4_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000237_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000237_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000237_15_1 & 1) != 0)
  {
    if ((sec_r000237_18_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((sec_r000237_15_2 & 1) != 0)
  {
    if ((sec_r000237_18_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000237_23_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000237_19_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000237_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000237_19_1 + 7) & 127;
  }
  if ((sec_r000237_23_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000237_19_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000237_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000237_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((sec_r000237_11_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000237_0_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000237_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000237_0_1 + 7) & 127;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((sec_r000237_11_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000237_0_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000237_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000237_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000237_8_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000237_11_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000237_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000237_11_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000237_8_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000237_11_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000237_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000237_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000237_10_1 & 1) != 0)
  {
    if ((sec_r000237_21_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((sec_r000237_10_2 & 1) != 0)
  {
    if ((sec_r000237_21_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r000237_12_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000237_19_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000237_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000237_19_1 + 7) & 127;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((sec_r000237_12_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000237_19_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000237_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000237_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((sec_r000237_16_1 & 1) != 0)
  {
    if ((sec_r000237_13_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000237_15_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000237_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000237_15_1 + 7) & 127;
  }
  if ((sec_r000237_16_2 & 1) != 0)
  {
    if ((sec_r000237_13_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000237_15_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000237_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000237_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000237_2_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000237_10_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000237_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000237_10_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000237_2_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000237_10_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000237_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000237_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((sec_r000237_19_1 & 1) != 0)
  {
    if ((sec_r000237_12_1 & 2) != 0)
    {
      stage_v_168_1 = (pub_r000237_9_1 + 31) & 127;
    }
    else
    {
      stage_v_168_1 = (pub_r000237_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_1 = (pub_r000237_9_1 + 7) & 127;
  }
  if ((sec_r000237_19_2 & 1) != 0)
  {
    if ((sec_r000237_12_2 & 2) != 0)
    {
      stage_v_168_2 = (pub_r000237_9_2 + 31) & 127;
    }
    else
    {
      stage_v_168_2 = (pub_r000237_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_168_2 = (pub_r000237_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((sec_r000237_14_1 & 1) != 0)
  {
    if ((sec_r000237_19_1 & 2) != 0)
    {
      stage_v_169_1 = (pub_r000237_18_1 + 31) & 127;
    }
    else
    {
      stage_v_169_1 = (pub_r000237_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_1 = (pub_r000237_18_1 + 7) & 127;
  }
  if ((sec_r000237_14_2 & 1) != 0)
  {
    if ((sec_r000237_19_2 & 2) != 0)
    {
      stage_v_169_2 = (pub_r000237_18_2 + 31) & 127;
    }
    else
    {
      stage_v_169_2 = (pub_r000237_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_169_2 = (pub_r000237_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((sec_r000237_2_1 & 2) != 0)
    {
      stage_v_170_1 = (pub_r000237_0_1 + 31) & 127;
    }
    else
    {
      stage_v_170_1 = (pub_r000237_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_1 = (pub_r000237_0_1 + 7) & 127;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((sec_r000237_2_2 & 2) != 0)
    {
      stage_v_170_2 = (pub_r000237_0_2 + 31) & 127;
    }
    else
    {
      stage_v_170_2 = (pub_r000237_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_170_2 = (pub_r000237_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000237_22_1 & 2) != 0)
    {
      stage_v_171_1 = (pub_r000237_11_1 + 31) & 127;
    }
    else
    {
      stage_v_171_1 = (pub_r000237_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_1 = (pub_r000237_11_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000237_22_2 & 2) != 0)
    {
      stage_v_171_2 = (pub_r000237_11_2 + 31) & 127;
    }
    else
    {
      stage_v_171_2 = (pub_r000237_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_171_2 = (pub_r000237_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000237_14_1 & 2) != 0)
    {
      stage_v_172_1 = (pub_r000237_6_1 + 31) & 127;
    }
    else
    {
      stage_v_172_1 = (pub_r000237_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_1 = (pub_r000237_6_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000237_14_2 & 2) != 0)
    {
      stage_v_172_2 = (pub_r000237_6_2 + 31) & 127;
    }
    else
    {
      stage_v_172_2 = (pub_r000237_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_172_2 = (pub_r000237_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000237_23_1 != sec_r000237_23_2);
  __CPROVER_assume(pub_r000237_0_1 == pub_r000237_0_2);
  __CPROVER_assume(sec_r000237_5_1 != sec_r000237_5_2);
  __CPROVER_assume(pub_r000237_2_1 == pub_r000237_2_2);
  __CPROVER_assume(pub_r000237_4_1 == pub_r000237_4_2);
  __CPROVER_assume(pub_r000237_16_1 == pub_r000237_16_2);
  __CPROVER_assume(sec_r000237_13_1 != sec_r000237_13_2);
  __CPROVER_assume(pub_r000237_18_1 == pub_r000237_18_2);
  __CPROVER_assume(pub_r000237_13_1 == pub_r000237_13_2);
  __CPROVER_assume(sec_r000237_15_1 != sec_r000237_15_2);
  __CPROVER_assume(pub_r000237_9_1 == pub_r000237_9_2);
  __CPROVER_assume(sec_r000237_20_1 != sec_r000237_20_2);
  __CPROVER_assume(sec_r000237_18_1 != sec_r000237_18_2);
  __CPROVER_assume(pub_r000237_19_1 == pub_r000237_19_2);
  __CPROVER_assume(pub_r000237_12_1 == pub_r000237_12_2);
  __CPROVER_assume(sec_r000237_19_1 != sec_r000237_19_2);
  __CPROVER_assume(sec_r000237_17_1 != sec_r000237_17_2);
  __CPROVER_assume(pub_r000237_15_1 == pub_r000237_15_2);
  __CPROVER_assume(pub_r000237_7_1 == pub_r000237_7_2);
  __CPROVER_assume(pub_r000237_11_1 == pub_r000237_11_2);
  __CPROVER_assume(pub_r000237_17_1 == pub_r000237_17_2);
  __CPROVER_assume(sec_r000237_9_1 != sec_r000237_9_2);
  __CPROVER_assume(pub_r000237_5_1 == pub_r000237_5_2);
  __CPROVER_assume(sec_r000237_3_1 != sec_r000237_3_2);
  __CPROVER_assume(sec_r000237_10_1 != sec_r000237_10_2);
  __CPROVER_assume(sec_r000237_0_1 != sec_r000237_0_2);
  __CPROVER_assume(pub_r000237_1_1 == pub_r000237_1_2);
  __CPROVER_assume(pub_r000237_10_1 == pub_r000237_10_2);
  __CPROVER_assume(sec_r000237_11_1 != sec_r000237_11_2);
  __CPROVER_assume(sec_r000237_21_1 != sec_r000237_21_2);
  __CPROVER_assume(pub_r000237_3_1 == pub_r000237_3_2);
  __CPROVER_assume(sec_r000237_4_1 != sec_r000237_4_2);
  __CPROVER_assume(sec_r000237_6_1 != sec_r000237_6_2);
  __CPROVER_assume(sec_r000237_22_1 != sec_r000237_22_2);
  __CPROVER_assume(sec_r000237_12_1 != sec_r000237_12_2);
  __CPROVER_assume(sec_r000237_8_1 != sec_r000237_8_2);
  __CPROVER_assume(pub_r000237_14_1 == pub_r000237_14_2);
  __CPROVER_assume(pub_r000237_8_1 == pub_r000237_8_2);
  __CPROVER_assume(sec_r000237_14_1 != sec_r000237_14_2);
  __CPROVER_assume(sec_r000237_7_1 != sec_r000237_7_2);
  __CPROVER_assume(sec_r000237_2_1 != sec_r000237_2_2);
  __CPROVER_assume(sec_r000237_16_1 != sec_r000237_16_2);
  __CPROVER_assume(sec_r000237_1_1 != sec_r000237_1_2);
  __CPROVER_assume(pub_r000237_6_1 == pub_r000237_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.tag == st_var_2_2.tag);
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
  assert(stage_v_168_1 == stage_v_168_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(stage_v_172_1 == stage_v_172_2);
}


