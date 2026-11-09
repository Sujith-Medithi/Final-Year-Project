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
struct DeviceConfig_R001735_3513_0
{
  unsigned char parity;
  unsigned char port;
  unsigned char timeout;
  int stop_bits;
  int id;
  int baud_rate;
  int buffer[3];
};
struct MatrixBlock_R001735_3513_1
{
  int determinant;
  short scale;
  int trace;
  int stride;
  int density;
  short dim;
  int buffer[3];
};
struct AudioFrame_R001735_3513_2
{
  short peak;
  int rms;
  unsigned char sample_rate;
  int buffer[3];
};
struct CipherContext_R001735_3513_3
{
  int tag;
  int iv;
  int nonce;
  unsigned char counter;
  int buffer[3];
};
union RegisterBank_R001735_3513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001735_3513_1
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
void fn_R001735_3513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st_1 = {0};
  struct CipherContext_R001735_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_81_1 > 47)
  {
    acc_1 = ((acc_1 + (anchor_81_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_81_2 > 47)
  {
    acc_2 = ((acc_2 + (anchor_81_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_89_1 = 0;
  int cursor_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_89_1 = ((cursor_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_89_2 = ((cursor_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_89_1) & 127;
    acc_2 = (acc_2 + cursor_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_81_1 == anchor_81_2);
  assert(cursor_89_1 == cursor_89_2);
}

int fn_R001735_3513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_81 > 47)
  {
    acc = ((acc + (anchor_81 * 2)) + 5) & 127;
    aux ^= anchor_81 & 15;
  }
  else
  {
    acc = ((acc - anchor_81) + 11) & 127;
    aux += 3;
  }
  int cursor_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_89 = ((cursor_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001735_3513_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st_1 = {0};
  struct DeviceConfig_R001735_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_49_1 = 0;
  int tracker_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_49_1 = ((tracker_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_49_2 = ((tracker_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_49_1) & 127;
    acc_2 = (acc_2 + tracker_49_2) & 127;
  }

  int sample_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_12_1 > 41)
  {
    acc_1 = ((acc_1 + (sample_12_1 * 2)) + 5) & 127;
    aux_1 ^= sample_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_12_2 > 41)
  {
    acc_2 = ((acc_2 + (sample_12_2 * 2)) + 5) & 127;
    aux_2 ^= sample_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_49_1 == tracker_49_2);
  assert(sample_12_1 == sample_12_2);
}

int fn_R001735_3513_1(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_49 = ((tracker_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_49) & 127;
  }

  int sample_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_12 > 41)
  {
    acc = ((acc + (sample_12 * 2)) + 5) & 127;
    aux ^= sample_12 & 15;
  }
  else
  {
    acc = ((acc - sample_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001735_3513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st_1 = {0};
  struct AudioFrame_R001735_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tracker_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_77_1) & 63;
  aux_2 = (aux_2 + tracker_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_12_1 = 0;
  int anchor_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_12_1 = ((anchor_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_12_2 = ((anchor_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_12_1) & 127;
    acc_2 = (acc_2 + anchor_12_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_77_1 == tracker_77_2);
  assert(anchor_12_1 == anchor_12_2);
}

int fn_R001735_3513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tracker_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_77) & 63;
  acc ^= aux;
  int anchor_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_12 = ((anchor_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_12) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001735_3513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st_1 = {0};
  struct CipherContext_R001735_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_73_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_73_1 * 2)) + 5) & 127;
    aux_1 ^= segment_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_73_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_73_2 * 2)) + 5) & 127;
    aux_2 ^= segment_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_75_1)
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

  switch (metric_75_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_73_1 == segment_73_2);
  assert(metric_75_1 == metric_75_2);
}

int fn_R001735_3513_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_73 > 24)
  {
    acc = ((acc + (segment_73 * 2)) + 5) & 127;
    aux ^= segment_73 & 15;
  }
  else
  {
    acc = ((acc - segment_73) + 11) & 127;
    aux += 3;
  }
  int metric_75 = (aux + st.buffer[1]) & 3;
  switch (metric_75)
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

void fn_R001735_3513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st_1 = {0};
  struct CipherContext_R001735_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_39_1 = 0;
  int tally_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_39_1 = ((tally_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_39_2 = ((tally_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_39_1) & 127;
    acc_2 = (acc_2 + tally_39_2) & 127;
  }

  int offset_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_44_1) & 63;
  aux_2 = (aux_2 + offset_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_71_1 = local_arr_1[aux_1 % 3];
  int tally_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_71_2 * 2)) & 127;
  int sample_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_59_1)
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

  switch (sample_59_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_39_1 == tally_39_2);
  assert(offset_44_1 == offset_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_71_1 == tally_71_2);
  assert(sample_59_1 == sample_59_2);
}

int fn_R001735_3513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_39 = ((tally_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_39) & 127;
  }

  int offset_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_71 = local_arr[aux % 3];
  acc = (acc + (tally_71 * 2)) & 127;
  int sample_59 = (aux + st.buffer[1]) & 3;
  switch (sample_59)
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

void fn_R001735_3513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st_1 = {0};
  struct AudioFrame_R001735_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_45_1)
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

  switch (factor_45_2)
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

  int offset_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_24_1) & 63;
  aux_2 = (aux_2 + offset_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_45_1 == factor_45_2);
  assert(offset_24_1 == offset_24_2);
}

int fn_R001735_3513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_45 = (aux + st.buffer[1]) & 3;
  switch (factor_45)
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

  int offset_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001735_3513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st_1 = {0};
  struct CipherContext_R001735_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_26_1 = 0;
  int coefficient_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_26_1 = ((coefficient_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_26_2 = ((coefficient_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_26_1) & 127;
    acc_2 = (acc_2 + coefficient_26_2) & 127;
  }

  int weight_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_62_1) & 63;
  aux_2 = (aux_2 + weight_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_26_1 == coefficient_26_2);
  assert(weight_62_1 == weight_62_2);
}

int fn_R001735_3513_6(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_26 = ((coefficient_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_26) & 127;
  }

  int weight_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001735_3513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st_1 = {0};
  struct AudioFrame_R001735_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int cursor_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_25_1 > 22)
  {
    acc_1 = ((acc_1 + (cursor_25_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_25_2 > 22)
  {
    acc_2 = ((acc_2 + (cursor_25_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_12_1 = local_arr_1[aux_1 % 3];
  int vector_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_12_2 * 2)) & 127;
  int metric_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_27_1)
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

  switch (metric_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_25_1 == cursor_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_12_1 == vector_12_2);
  assert(metric_27_1 == metric_27_2);
}

int fn_R001735_3513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int cursor_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_25 > 22)
  {
    acc = ((acc + (cursor_25 * 2)) + 5) & 127;
    aux ^= cursor_25 & 15;
  }
  else
  {
    acc = ((acc - cursor_25) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_12 = local_arr[aux % 3];
  acc = (acc + (vector_12 * 2)) & 127;
  int metric_27 = (aux + st.buffer[1]) & 3;
  switch (metric_27)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001735_3513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001735_3513_1 st_1 = {0};
  struct MatrixBlock_R001735_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_43_1 = local_arr_1[aux_1 % 3];
  int residue_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_43_2 * 2)) & 127;
  int coefficient_61_1 = 0;
  int coefficient_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_61_1 = ((coefficient_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_61_2 = ((coefficient_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_61_1) & 127;
    acc_2 = (acc_2 + coefficient_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_43_1 == residue_43_2);
  assert(coefficient_61_1 == coefficient_61_2);
}

int fn_R001735_3513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001735_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int residue_43 = local_arr[aux % 3];
  acc = (acc + (residue_43 * 2)) & 127;
  int coefficient_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_61 = ((coefficient_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001735_3513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st_1 = {0};
  struct AudioFrame_R001735_3513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int pivot_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_35_1) & 63;
  aux_2 = (aux_2 + pivot_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_12_1 > 50)
  {
    acc_1 = ((acc_1 + (checksum_12_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_12_2 > 50)
  {
    acc_2 = ((acc_2 + (checksum_12_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_67_1)
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

  switch (residue_67_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_35_1 == pivot_35_2);
  assert(checksum_12_1 == checksum_12_2);
  assert(residue_67_1 == residue_67_2);
}

int fn_R001735_3513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001735_3513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int pivot_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_35) & 63;
  acc ^= aux;
  int checksum_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_12 > 50)
  {
    acc = ((acc + (checksum_12 * 2)) + 5) & 127;
    aux ^= checksum_12 & 15;
  }
  else
  {
    acc = ((acc - checksum_12) + 11) & 127;
    aux += 3;
  }
  int residue_67 = (aux + st.buffer[1]) & 3;
  switch (residue_67)
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

void fn_R001735_3513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st_1 = {0};
  struct DeviceConfig_R001735_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int segment_48_1 = 0;
  int segment_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_48_1 = ((segment_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_48_2 = ((segment_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_48_1) & 127;
    acc_2 = (acc_2 + segment_48_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_56_1 = local_arr_1[aux_1 % 3];
  int vector_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_56_2 * 2)) & 127;
  int stride_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_58_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_58_1 * 2)) + 5) & 127;
    aux_1 ^= stride_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_58_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_58_2 * 2)) + 5) & 127;
    aux_2 ^= stride_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_56_1 == vector_56_2);
  assert(stride_58_1 == stride_58_2);
}

int fn_R001735_3513_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int segment_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_48 = ((segment_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_48) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_56 = local_arr[aux % 3];
  acc = (acc + (vector_56 * 2)) & 127;
  int stride_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_58 > 12)
  {
    acc = ((acc + (stride_58 * 2)) + 5) & 127;
    aux ^= stride_58 & 15;
  }
  else
  {
    acc = ((acc - stride_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001735_3513_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st_1 = {0};
  struct CipherContext_R001735_3513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int offset_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_51_1) & 63;
  aux_2 = (aux_2 + offset_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_60_1 = 0;
  int damping_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_60_1 = ((damping_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_60_2 = ((damping_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_60_1) & 127;
    acc_2 = (acc_2 + damping_60_2) & 127;
  }

  int stride_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_99_1)
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

  switch (stride_99_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_51_1 == offset_51_2);
  assert(damping_60_1 == damping_60_2);
  assert(stride_99_1 == stride_99_2);
}

int fn_R001735_3513_11(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001735_3513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int offset_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_51) & 63;
  acc ^= aux;
  int damping_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_60 = ((damping_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_60) & 127;
  }

  int stride_99 = (aux + st.buffer[1]) & 3;
  switch (stride_99)
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

void fn_R001735_3513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st_1 = {0};
  struct DeviceConfig_R001735_3513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_39_1) & 63;
  aux_2 = (aux_2 + vector_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_64_1 = 0;
  int bound_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_64_1 = ((bound_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_64_2 = ((bound_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_64_1) & 127;
    acc_2 = (acc_2 + bound_64_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_90_1 = local_arr_1[aux_1 % 3];
  int quotient_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_39_1 == vector_39_2);
  assert(bound_64_1 == bound_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_90_1 == quotient_90_2);
}

int fn_R001735_3513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001735_3513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_39) & 63;
  acc ^= aux;
  int bound_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_64 = ((bound_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_64) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_90 = local_arr[aux % 3];
  acc = (acc + (quotient_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001735_3513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001735_3513_1 st_1 = {0};
  struct MatrixBlock_R001735_3513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_97_1 > 15)
  {
    acc_1 = ((acc_1 + (vector_97_1 * 2)) + 5) & 127;
    aux_1 ^= vector_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_97_2 > 15)
  {
    acc_2 = ((acc_2 + (vector_97_2 * 2)) + 5) & 127;
    aux_2 ^= vector_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_19_1)
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

  switch (mask_19_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_97_1 == vector_97_2);
  assert(mask_19_1 == mask_19_2);
}

int fn_R001735_3513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001735_3513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_97 > 15)
  {
    acc = ((acc + (vector_97 * 2)) + 5) & 127;
    aux ^= vector_97 & 15;
  }
  else
  {
    acc = ((acc - vector_97) + 11) & 127;
    aux += 3;
  }
  int mask_19 = (aux + st.buffer[1]) & 3;
  switch (mask_19)
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

void main()
{
  int sec_r001735_0_1;
  int sec_r001735_0_2;
  int sec_r001735_1_1;
  int sec_r001735_1_2;
  int sec_r001735_2_1;
  int sec_r001735_2_2;
  int sec_r001735_3_1;
  int sec_r001735_3_2;
  int sec_r001735_4_1;
  int sec_r001735_4_2;
  int sec_r001735_5_1;
  int sec_r001735_5_2;
  int sec_r001735_6_1;
  int sec_r001735_6_2;
  int sec_r001735_7_1;
  int sec_r001735_7_2;
  int sec_r001735_8_1;
  int sec_r001735_8_2;
  int sec_r001735_9_1;
  int sec_r001735_9_2;
  int sec_r001735_10_1;
  int sec_r001735_10_2;
  int sec_r001735_11_1;
  int sec_r001735_11_2;
  int sec_r001735_12_1;
  int sec_r001735_12_2;
  int sec_r001735_13_1;
  int sec_r001735_13_2;
  int sec_r001735_14_1;
  int sec_r001735_14_2;
  int sec_r001735_15_1;
  int sec_r001735_15_2;
  int sec_r001735_16_1;
  int sec_r001735_16_2;
  int sec_r001735_17_1;
  int sec_r001735_17_2;
  int pub_r001735_0_1;
  int pub_r001735_0_2;
  int pub_r001735_1_1;
  int pub_r001735_1_2;
  int pub_r001735_2_1;
  int pub_r001735_2_2;
  int pub_r001735_3_1;
  int pub_r001735_3_2;
  int pub_r001735_4_1;
  int pub_r001735_4_2;
  int pub_r001735_5_1;
  int pub_r001735_5_2;
  int pub_r001735_6_1;
  int pub_r001735_6_2;
  int pub_r001735_7_1;
  int pub_r001735_7_2;
  int pub_r001735_8_1;
  int pub_r001735_8_2;
  int pub_r001735_9_1;
  int pub_r001735_9_2;
  int pub_r001735_10_1;
  int pub_r001735_10_2;
  int pub_r001735_11_1;
  int pub_r001735_11_2;
  int pub_r001735_12_1;
  int pub_r001735_12_2;
  int pub_r001735_13_1;
  int pub_r001735_13_2;
  int pub_r001735_14_1;
  int pub_r001735_14_2;
  int pub_r001735_15_1;
  int pub_r001735_15_2;
  int pub_r001735_16_1;
  int pub_r001735_16_2;
  int pub_r001735_17_1;
  int pub_r001735_17_2;
  int pub_r001735_18_1;
  int pub_r001735_18_2;
  int pub_r001735_19_1;
  int pub_r001735_19_2;
  int pub_r001735_20_1;
  int pub_r001735_20_2;
  int pub_r001735_21_1;
  int pub_r001735_21_2;
  int pub_r001735_22_1;
  int pub_r001735_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001735_0_1 >= (-100)) && (pub_r001735_0_1 <= 100));
  __CPROVER_assume((pub_r001735_0_2 >= (-100)) && (pub_r001735_0_2 <= 100));
  __CPROVER_assume((pub_r001735_1_1 >= (-100)) && (pub_r001735_1_1 <= 100));
  __CPROVER_assume((pub_r001735_1_2 >= (-100)) && (pub_r001735_1_2 <= 100));
  __CPROVER_assume((pub_r001735_2_1 >= (-100)) && (pub_r001735_2_1 <= 100));
  __CPROVER_assume((pub_r001735_2_2 >= (-100)) && (pub_r001735_2_2 <= 100));
  __CPROVER_assume((pub_r001735_3_1 >= (-100)) && (pub_r001735_3_1 <= 100));
  __CPROVER_assume((pub_r001735_3_2 >= (-100)) && (pub_r001735_3_2 <= 100));
  __CPROVER_assume((pub_r001735_4_1 >= (-100)) && (pub_r001735_4_1 <= 100));
  __CPROVER_assume((pub_r001735_4_2 >= (-100)) && (pub_r001735_4_2 <= 100));
  __CPROVER_assume((pub_r001735_5_1 >= (-100)) && (pub_r001735_5_1 <= 100));
  __CPROVER_assume((pub_r001735_5_2 >= (-100)) && (pub_r001735_5_2 <= 100));
  __CPROVER_assume((pub_r001735_6_1 >= (-100)) && (pub_r001735_6_1 <= 100));
  __CPROVER_assume((pub_r001735_6_2 >= (-100)) && (pub_r001735_6_2 <= 100));
  __CPROVER_assume((pub_r001735_7_1 >= (-100)) && (pub_r001735_7_1 <= 100));
  __CPROVER_assume((pub_r001735_7_2 >= (-100)) && (pub_r001735_7_2 <= 100));
  __CPROVER_assume((pub_r001735_8_1 >= (-100)) && (pub_r001735_8_1 <= 100));
  __CPROVER_assume((pub_r001735_8_2 >= (-100)) && (pub_r001735_8_2 <= 100));
  __CPROVER_assume((pub_r001735_9_1 >= (-100)) && (pub_r001735_9_1 <= 100));
  __CPROVER_assume((pub_r001735_9_2 >= (-100)) && (pub_r001735_9_2 <= 100));
  __CPROVER_assume((pub_r001735_10_1 >= (-100)) && (pub_r001735_10_1 <= 100));
  __CPROVER_assume((pub_r001735_10_2 >= (-100)) && (pub_r001735_10_2 <= 100));
  __CPROVER_assume((pub_r001735_11_1 >= (-100)) && (pub_r001735_11_1 <= 100));
  __CPROVER_assume((pub_r001735_11_2 >= (-100)) && (pub_r001735_11_2 <= 100));
  __CPROVER_assume((pub_r001735_12_1 >= (-100)) && (pub_r001735_12_1 <= 100));
  __CPROVER_assume((pub_r001735_12_2 >= (-100)) && (pub_r001735_12_2 <= 100));
  __CPROVER_assume((pub_r001735_13_1 >= (-100)) && (pub_r001735_13_1 <= 100));
  __CPROVER_assume((pub_r001735_13_2 >= (-100)) && (pub_r001735_13_2 <= 100));
  __CPROVER_assume((pub_r001735_14_1 >= (-100)) && (pub_r001735_14_1 <= 100));
  __CPROVER_assume((pub_r001735_14_2 >= (-100)) && (pub_r001735_14_2 <= 100));
  __CPROVER_assume((pub_r001735_15_1 >= (-100)) && (pub_r001735_15_1 <= 100));
  __CPROVER_assume((pub_r001735_15_2 >= (-100)) && (pub_r001735_15_2 <= 100));
  __CPROVER_assume((pub_r001735_16_1 >= (-100)) && (pub_r001735_16_1 <= 100));
  __CPROVER_assume((pub_r001735_16_2 >= (-100)) && (pub_r001735_16_2 <= 100));
  __CPROVER_assume((pub_r001735_17_1 >= (-100)) && (pub_r001735_17_1 <= 100));
  __CPROVER_assume((pub_r001735_17_2 >= (-100)) && (pub_r001735_17_2 <= 100));
  __CPROVER_assume((pub_r001735_18_1 >= (-100)) && (pub_r001735_18_1 <= 100));
  __CPROVER_assume((pub_r001735_18_2 >= (-100)) && (pub_r001735_18_2 <= 100));
  __CPROVER_assume((pub_r001735_19_1 >= (-100)) && (pub_r001735_19_1 <= 100));
  __CPROVER_assume((pub_r001735_19_2 >= (-100)) && (pub_r001735_19_2 <= 100));
  __CPROVER_assume((pub_r001735_20_1 >= (-100)) && (pub_r001735_20_1 <= 100));
  __CPROVER_assume((pub_r001735_20_2 >= (-100)) && (pub_r001735_20_2 <= 100));
  __CPROVER_assume((pub_r001735_21_1 >= (-100)) && (pub_r001735_21_1 <= 100));
  __CPROVER_assume((pub_r001735_21_2 >= (-100)) && (pub_r001735_21_2 <= 100));
  __CPROVER_assume((pub_r001735_22_1 >= (-100)) && (pub_r001735_22_1 <= 100));
  __CPROVER_assume((pub_r001735_22_2 >= (-100)) && (pub_r001735_22_2 <= 100));
  __CPROVER_assume((sec_r001735_0_1 >= 0) && (sec_r001735_0_1 <= 255));
  __CPROVER_assume((sec_r001735_0_2 >= 0) && (sec_r001735_0_2 <= 255));
  __CPROVER_assume((sec_r001735_1_1 >= 0) && (sec_r001735_1_1 <= 255));
  __CPROVER_assume((sec_r001735_1_2 >= 0) && (sec_r001735_1_2 <= 255));
  __CPROVER_assume((sec_r001735_2_1 >= 0) && (sec_r001735_2_1 <= 255));
  __CPROVER_assume((sec_r001735_2_2 >= 0) && (sec_r001735_2_2 <= 255));
  __CPROVER_assume((sec_r001735_3_1 >= 0) && (sec_r001735_3_1 <= 255));
  __CPROVER_assume((sec_r001735_3_2 >= 0) && (sec_r001735_3_2 <= 255));
  __CPROVER_assume((sec_r001735_4_1 >= 0) && (sec_r001735_4_1 <= 255));
  __CPROVER_assume((sec_r001735_4_2 >= 0) && (sec_r001735_4_2 <= 255));
  __CPROVER_assume((sec_r001735_5_1 >= 0) && (sec_r001735_5_1 <= 255));
  __CPROVER_assume((sec_r001735_5_2 >= 0) && (sec_r001735_5_2 <= 255));
  __CPROVER_assume((sec_r001735_6_1 >= 0) && (sec_r001735_6_1 <= 255));
  __CPROVER_assume((sec_r001735_6_2 >= 0) && (sec_r001735_6_2 <= 255));
  __CPROVER_assume((sec_r001735_7_1 >= 0) && (sec_r001735_7_1 <= 255));
  __CPROVER_assume((sec_r001735_7_2 >= 0) && (sec_r001735_7_2 <= 255));
  __CPROVER_assume((sec_r001735_8_1 >= 0) && (sec_r001735_8_1 <= 255));
  __CPROVER_assume((sec_r001735_8_2 >= 0) && (sec_r001735_8_2 <= 255));
  __CPROVER_assume((sec_r001735_9_1 >= 0) && (sec_r001735_9_1 <= 255));
  __CPROVER_assume((sec_r001735_9_2 >= 0) && (sec_r001735_9_2 <= 255));
  __CPROVER_assume((sec_r001735_10_1 >= 0) && (sec_r001735_10_1 <= 255));
  __CPROVER_assume((sec_r001735_10_2 >= 0) && (sec_r001735_10_2 <= 255));
  __CPROVER_assume((sec_r001735_11_1 >= 0) && (sec_r001735_11_1 <= 255));
  __CPROVER_assume((sec_r001735_11_2 >= 0) && (sec_r001735_11_2 <= 255));
  __CPROVER_assume((sec_r001735_12_1 >= 0) && (sec_r001735_12_1 <= 255));
  __CPROVER_assume((sec_r001735_12_2 >= 0) && (sec_r001735_12_2 <= 255));
  __CPROVER_assume((sec_r001735_13_1 >= 0) && (sec_r001735_13_1 <= 255));
  __CPROVER_assume((sec_r001735_13_2 >= 0) && (sec_r001735_13_2 <= 255));
  __CPROVER_assume((sec_r001735_14_1 >= 0) && (sec_r001735_14_1 <= 255));
  __CPROVER_assume((sec_r001735_14_2 >= 0) && (sec_r001735_14_2 <= 255));
  __CPROVER_assume((sec_r001735_15_1 >= 0) && (sec_r001735_15_1 <= 255));
  __CPROVER_assume((sec_r001735_15_2 >= 0) && (sec_r001735_15_2 <= 255));
  __CPROVER_assume((sec_r001735_16_1 >= 0) && (sec_r001735_16_1 <= 255));
  __CPROVER_assume((sec_r001735_16_2 >= 0) && (sec_r001735_16_2 <= 255));
  __CPROVER_assume((sec_r001735_17_1 >= 0) && (sec_r001735_17_1 <= 255));
  __CPROVER_assume((sec_r001735_17_2 >= 0) && (sec_r001735_17_2 <= 255));
  struct DeviceConfig_R001735_3513_0 st_var_0_1 = {0};
  struct DeviceConfig_R001735_3513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001735_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001735_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001735_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001735_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001735_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001735_0_2 + 7) & 15;
  struct MatrixBlock_R001735_3513_1 st_var_1_1 = {0};
  struct MatrixBlock_R001735_3513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001735_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001735_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001735_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001735_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001735_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001735_0_2 + 9) & 15;
  struct AudioFrame_R001735_3513_2 st_var_2_1 = {0};
  struct AudioFrame_R001735_3513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001735_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001735_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001735_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001735_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001735_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001735_0_2 + 11) & 15;
  struct CipherContext_R001735_3513_3 st_var_3_1 = {0};
  struct CipherContext_R001735_3513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001735_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001735_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001735_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001735_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001735_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001735_0_2 + 13) & 15;
  union RegisterBank_R001735_3513_0 u_var_1;
  union RegisterBank_R001735_3513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001735_3513_0(sec_r001735_0_1, pub_r001735_1_1, pub_r001735_2_1, pub_r001735_3_1);
  int helper_flow_0_2 = fn_R001735_3513_0(sec_r001735_0_2, pub_r001735_1_2, pub_r001735_2_2, pub_r001735_3_2);
  fn_R001735_3513_0_2(sec_r001735_0_1, pub_r001735_1_1, pub_r001735_2_1, pub_r001735_3_1, sec_r001735_0_2, pub_r001735_1_2, pub_r001735_2_2, pub_r001735_3_2);
  int helper_flow_1_1 = fn_R001735_3513_1(sec_r001735_1_1, pub_r001735_2_1);
  int helper_flow_1_2 = fn_R001735_3513_1(sec_r001735_1_2, pub_r001735_2_2);
  fn_R001735_3513_1_2(sec_r001735_1_1, pub_r001735_2_1, sec_r001735_1_2, pub_r001735_2_2);
  int helper_flow_2_1 = fn_R001735_3513_2(sec_r001735_2_1, sec_r001735_3_1, pub_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1);
  int helper_flow_2_2 = fn_R001735_3513_2(sec_r001735_2_2, sec_r001735_3_2, pub_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2);
  fn_R001735_3513_2_2(sec_r001735_2_1, sec_r001735_3_1, pub_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1, sec_r001735_2_2, sec_r001735_3_2, pub_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2);
  int helper_flow_3_1 = fn_R001735_3513_3(sec_r001735_3_1, pub_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1, pub_r001735_7_1);
  int helper_flow_3_2 = fn_R001735_3513_3(sec_r001735_3_2, pub_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2, pub_r001735_7_2);
  fn_R001735_3513_3_2(sec_r001735_3_1, pub_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1, pub_r001735_7_1, sec_r001735_3_2, pub_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2, pub_r001735_7_2);
  int helper_flow_4_1 = fn_R001735_3513_4(sec_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1);
  int helper_flow_4_2 = fn_R001735_3513_4(sec_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2);
  fn_R001735_3513_4_2(sec_r001735_4_1, pub_r001735_5_1, pub_r001735_6_1, sec_r001735_4_2, pub_r001735_5_2, pub_r001735_6_2);
  int stage_v_0_1 = ((sec_r001735_7_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001735_7_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((pub_r001735_15_1 * 2) + 25) & 63;
  int stage_v_1_2 = ((pub_r001735_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001735_2_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001735_2_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((stage_v_0_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_3_2 = ((stage_v_0_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((sec_r001735_8_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001735_8_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001735_0_1 * 2) + 24) & 63;
  int stage_v_5_2 = ((pub_r001735_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001735_17_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001735_17_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001735_7_1 * 2) + 39) & 63;
  int stage_v_7_2 = ((pub_r001735_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001735_15_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001735_15_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001735_6_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001735_6_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((sec_r001735_11_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001735_11_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((pub_r001735_3_1 * 2) + 41) & 63;
  int stage_v_11_2 = ((pub_r001735_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001735_17_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001735_17_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((pub_r001735_2_1 * 2) + 6) & 63;
  int stage_v_13_2 = ((pub_r001735_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001735_7_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001735_7_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_2_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_2_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001735_7_1 * 2) + 20) & 63;
  int stage_v_16_2 = ((pub_r001735_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001735_1_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_17_2 = ((sec_r001735_1_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((sec_r001735_17_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_18_2 = ((sec_r001735_17_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((stage_v_18_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_18_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((stage_v_18_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_18_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001735_8_1 * 2) + 50) & 63;
  int stage_v_21_2 = ((pub_r001735_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((sec_r001735_14_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_22_2 = ((sec_r001735_14_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((stage_v_17_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_17_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((stage_v_0_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_24_2 = ((stage_v_0_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((helper_flow_1_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_25_2 = ((helper_flow_1_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((stage_v_24_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_26_2 = ((stage_v_24_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((stage_v_4_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_27_2 = ((stage_v_4_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001735_22_1 * 2) + 36) & 63;
  int stage_v_28_2 = ((pub_r001735_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001735_19_1 * 2) + 16) & 63;
  int stage_v_29_2 = ((pub_r001735_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((stage_v_25_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_30_2 = ((stage_v_25_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((sec_r001735_0_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_31_2 = ((sec_r001735_0_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((sec_r001735_15_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001735_15_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_33_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((stage_v_20_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_34_2 = ((stage_v_20_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001735_17_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001735_17_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((pub_r001735_9_1 * 2) + 11) & 63;
  int stage_v_36_2 = ((pub_r001735_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_30_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_37_2 = ((stage_v_30_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((sec_r001735_7_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_38_2 = ((sec_r001735_7_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_2_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_2_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001735_13_1 * 2) + 14) & 63;
  int stage_v_40_2 = ((pub_r001735_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001735_17_1 * 2) + 12) & 63;
  int stage_v_41_2 = ((pub_r001735_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((sec_r001735_12_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_42_2 = ((sec_r001735_12_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_24_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_24_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_30_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_30_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001735_15_1 * 2) + 22) & 63;
  int stage_v_45_2 = ((pub_r001735_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001735_10_1 * 2) + 16) & 63;
  int stage_v_46_2 = ((pub_r001735_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001735_15_1 * 2) + 12) & 63;
  int stage_v_47_2 = ((pub_r001735_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_14_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_48_2 = ((stage_v_14_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((stage_v_34_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_34_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((stage_v_17_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_50_2 = ((stage_v_17_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((pub_r001735_2_1 * 2) + 30) & 63;
  int stage_v_51_2 = ((pub_r001735_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_35_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_52_2 = ((stage_v_35_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001735_3_1 * 2) + 35) & 63;
  int stage_v_53_2 = ((pub_r001735_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((helper_flow_3_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_54_2 = ((helper_flow_3_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001735_1_1 * 2) + 39) & 63;
  int stage_v_55_2 = ((pub_r001735_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((pub_r001735_5_1 * 2) + 16) & 63;
  int stage_v_57_2 = ((pub_r001735_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001735_21_1 * 2) + 9) & 63;
  int stage_v_58_2 = ((pub_r001735_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001735_22_1 * 2) + 45) & 63;
  int stage_v_59_2 = ((pub_r001735_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((sec_r001735_4_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_60_2 = ((sec_r001735_4_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_49_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_49_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_52_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_52_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((stage_v_9_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_9_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((pub_r001735_2_1 * 2) + 33) & 63;
  int stage_v_64_2 = ((pub_r001735_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_4_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_4_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001735_2_1 * 2) + 7) & 63;
  int stage_v_66_2 = ((pub_r001735_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001735_9_1 * 2) + 29) & 63;
  int stage_v_67_2 = ((pub_r001735_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((helper_flow_2_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_68_2 = ((helper_flow_2_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((pub_r001735_11_1 * 2) + 37) & 63;
  int stage_v_69_2 = ((pub_r001735_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_34_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_34_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((stage_v_20_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_71_2 = ((stage_v_20_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((stage_v_22_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_22_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001735_18_1 * 2) + 40) & 63;
  int stage_v_73_2 = ((pub_r001735_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001735_12_1 * 2) + 39) & 63;
  int stage_v_74_2 = ((pub_r001735_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001735_12_1 * 2) + 33) & 63;
  int stage_v_75_2 = ((pub_r001735_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001735_17_1 * 2) + 8) & 63;
  int stage_v_76_2 = ((pub_r001735_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001735_14_1 * 2) + 18) & 63;
  int stage_v_77_2 = ((pub_r001735_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001735_4_1 * 2) + 6) & 63;
  int stage_v_78_2 = ((pub_r001735_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001735_1_1 * 2) + 36) & 63;
  int stage_v_79_2 = ((pub_r001735_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_63_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_63_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((pub_r001735_22_1 * 2) + 24) & 63;
  int stage_v_81_2 = ((pub_r001735_22_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_44_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_44_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((sec_r001735_16_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_83_2 = ((sec_r001735_16_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((pub_r001735_3_1 * 2) + 23) & 63;
  int stage_v_84_2 = ((pub_r001735_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001735_8_1 * 2) + 50) & 63;
  int stage_v_85_2 = ((pub_r001735_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_65_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_65_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001735_14_1 * 2) + 15) & 63;
  int stage_v_87_2 = ((pub_r001735_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001735_5_1 * 2) + 7) & 63;
  int stage_v_88_2 = ((pub_r001735_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001735_20_1 * 2) + 44) & 63;
  int stage_v_89_2 = ((pub_r001735_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_27_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_27_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((stage_v_19_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_91_2 = ((stage_v_19_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((pub_r001735_19_1 * 2) + 41) & 63;
  int stage_v_92_2 = ((pub_r001735_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001735_2_1 * 2) + 7) & 63;
  int stage_v_93_2 = ((pub_r001735_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001735_16_1 * 2) + 46) & 63;
  int stage_v_94_2 = ((pub_r001735_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001735_4_1 * 2) + 8) & 63;
  int stage_v_95_2 = ((pub_r001735_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_50_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_50_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((stage_v_38_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_38_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((sec_r001735_13_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_99_2 = ((sec_r001735_13_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((pub_r001735_11_1 * 2) + 25) & 63;
  int stage_v_100_2 = ((pub_r001735_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_6_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_6_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((stage_v_42_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_42_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001735_19_1 * 2) + 31) & 63;
  int stage_v_103_2 = ((pub_r001735_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_80_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_80_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((stage_v_82_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_105_2 = ((stage_v_82_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((stage_v_22_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_106_2 = ((stage_v_22_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((pub_r001735_11_1 * 2) + 37) & 63;
  int stage_v_107_2 = ((pub_r001735_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_72_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_108_2 = ((stage_v_72_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((pub_r001735_7_1 * 2) + 14) & 63;
  int stage_v_109_2 = ((pub_r001735_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((stage_v_0_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_0_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((stage_v_30_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_30_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((sec_r001735_8_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_112_2 = ((sec_r001735_8_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((sec_r001735_12_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_113_2 = ((sec_r001735_12_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((stage_v_19_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_114_2 = ((stage_v_19_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((pub_r001735_15_1 * 2) + 7) & 63;
  int stage_v_115_2 = ((pub_r001735_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_102_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_102_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((sec_r001735_11_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001735_11_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((pub_r001735_9_1 * 2) + 33) & 63;
  int stage_v_118_2 = ((pub_r001735_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_33_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_119_2 = ((stage_v_33_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((stage_v_44_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_44_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((pub_r001735_19_1 * 2) + 45) & 63;
  int stage_v_121_2 = ((pub_r001735_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((sec_r001735_8_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_122_2 = ((sec_r001735_8_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((pub_r001735_13_1 * 2) + 23) & 63;
  int stage_v_123_2 = ((pub_r001735_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001735_14_1 * 2) + 26) & 63;
  int stage_v_124_2 = ((pub_r001735_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_6_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_6_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((pub_r001735_13_1 * 2) + 14) & 63;
  int stage_v_126_2 = ((pub_r001735_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001735_14_1 * 2) + 7) & 63;
  int stage_v_127_2 = ((pub_r001735_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001735_21_1 * 2) + 35) & 63;
  int stage_v_128_2 = ((pub_r001735_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_22_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_22_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((stage_v_24_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_24_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((pub_r001735_8_1 * 2) + 34) & 63;
  int stage_v_131_2 = ((pub_r001735_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001735_17_1 * 2) + 44) & 63;
  int stage_v_132_2 = ((pub_r001735_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_48_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_48_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001735_16_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001735_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001735_10_1 * 2) + 15) & 63;
  int stage_v_135_2 = ((pub_r001735_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_8_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_8_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001735_11_1 * 2) + 30) & 63;
  int stage_v_137_2 = ((pub_r001735_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_122_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_122_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((stage_v_68_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_68_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((sec_r001735_15_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_140_2 = ((sec_r001735_15_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((helper_flow_4_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_141_2 = ((helper_flow_4_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((sec_r001735_9_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_142_2 = ((sec_r001735_9_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((stage_v_129_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_143_2 = ((stage_v_129_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((pub_r001735_22_1 * 2) + 16) & 63;
  int stage_v_144_2 = ((pub_r001735_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001735_9_1 * 2) + 31) & 63;
  int stage_v_145_2 = ((pub_r001735_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_42_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_42_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((sec_r001735_1_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_147_2 = ((sec_r001735_1_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001735_18_1 * 2) + 26) & 63;
  int stage_v_148_2 = ((pub_r001735_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((stage_v_71_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_149_2 = ((stage_v_71_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((stage_v_101_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_101_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((helper_flow_2_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_151_2 = ((helper_flow_2_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((pub_r001735_18_1 * 2) + 27) & 63;
  int stage_v_152_2 = ((pub_r001735_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001735_4_1 * 2) + 50) & 63;
  int stage_v_153_2 = ((pub_r001735_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_35_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_35_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_30_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_30_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001735_12_1 * 2) + 43) & 63;
  int stage_v_156_2 = ((pub_r001735_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001735_5_1 * 2) + 38) & 63;
  int stage_v_157_2 = ((pub_r001735_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_99_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_99_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_117_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_117_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001735_1_1 * 2) + 20) & 63;
  int stage_v_160_2 = ((pub_r001735_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001735_20_1 * 2) + 37) & 63;
  int stage_v_161_2 = ((pub_r001735_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_80_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_80_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001735_3_1 * 2) + 29) & 63;
  int stage_v_163_2 = ((pub_r001735_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001735_17_1 * 2) + 34) & 63;
  int stage_v_164_2 = ((pub_r001735_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_49_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_49_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_116_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_116_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_140_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_140_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((pub_r001735_7_1 * 2) + 30) & 63;
  int stage_v_168_2 = ((pub_r001735_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001735_8_1 * 2) + 15) & 63;
  int stage_v_169_2 = ((pub_r001735_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((stage_v_14_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_14_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((sec_r001735_8_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_172_2 = ((sec_r001735_8_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((stage_v_31_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_31_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((sec_r001735_3_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_174_2 = ((sec_r001735_3_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((pub_r001735_4_1 * 2) + 22) & 63;
  int stage_v_175_2 = ((pub_r001735_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001735_17_1 * 2) + 6) & 63;
  int stage_v_176_2 = ((pub_r001735_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_33_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_177_2 = ((stage_v_33_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((pub_r001735_9_1 * 2) + 20) & 63;
  int stage_v_178_2 = ((pub_r001735_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001735_20_1 * 2) + 50) & 63;
  int stage_v_179_2 = ((pub_r001735_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001735_12_1 * 2) + 8) & 63;
  int stage_v_180_2 = ((pub_r001735_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001735_21_1 * 2) + 22) & 63;
  int stage_v_181_2 = ((pub_r001735_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_114_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_114_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((stage_v_91_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_91_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((stage_v_113_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_113_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((sec_r001735_9_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_185_2 = ((sec_r001735_9_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001735_15_1 * 2) + 47) & 63;
  int stage_v_186_2 = ((pub_r001735_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_50_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_50_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_174_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_174_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001735_10_1 * 2) + 34) & 63;
  int stage_v_189_2 = ((pub_r001735_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((stage_v_60_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_190_2 = ((stage_v_60_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((pub_r001735_3_1 * 2) + 32) & 63;
  int stage_v_191_2 = ((pub_r001735_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_6_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_6_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((stage_v_71_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_71_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((sec_r001735_15_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_194_2 = ((sec_r001735_15_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001735_0_1 * 2) + 11) & 63;
  int stage_v_195_2 = ((pub_r001735_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_90_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_90_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_63_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_63_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((stage_v_133_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_133_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_44_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_44_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((sec_r001735_16_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_200_2 = ((sec_r001735_16_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((sec_r001735_2_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_201_2 = ((sec_r001735_2_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_139_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_139_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((stage_v_201_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_201_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((pub_r001735_22_1 * 2) + 12) & 63;
  int stage_v_204_2 = ((pub_r001735_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((helper_flow_0_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_205_2 = ((helper_flow_0_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((sec_r001735_7_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_206_2 = ((sec_r001735_7_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((stage_v_177_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_207_2 = ((stage_v_177_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((pub_r001735_16_1 * 2) + 28) & 63;
  int stage_v_208_2 = ((pub_r001735_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001735_17_1 * 2) + 20) & 63;
  int stage_v_209_2 = ((pub_r001735_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_83_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_83_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_116_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_116_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((stage_v_97_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_97_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((helper_flow_1_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_213_2 = ((helper_flow_1_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_120_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_120_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001735_22_1 * 2) + 47) & 63;
  int stage_v_215_2 = ((pub_r001735_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001735_15_1 * 2) + 22) & 63;
  int stage_v_216_2 = ((pub_r001735_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001735_1_1 * 2) + 25) & 63;
  int stage_v_217_2 = ((pub_r001735_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_106_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_106_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((sec_r001735_6_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_219_2 = ((sec_r001735_6_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001735_11_1 * 2) + 31) & 63;
  int stage_v_220_2 = ((pub_r001735_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_199_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_199_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((pub_r001735_2_1 * 2) + 31) & 63;
  int stage_v_222_2 = ((pub_r001735_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001735_12_1 * 2) + 46) & 63;
  int stage_v_223_2 = ((pub_r001735_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_98_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_98_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((sec_r001735_8_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_225_2 = ((sec_r001735_8_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001735_8_1 * 2) + 16) & 63;
  int stage_v_226_2 = ((pub_r001735_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_86_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_86_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_61_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_61_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((pub_r001735_10_1 * 2) + 39) & 63;
  int stage_v_229_2 = ((pub_r001735_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_117_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_117_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((stage_v_9_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_9_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((stage_v_228_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_228_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((pub_r001735_2_1 * 2) + 44) & 63;
  int stage_v_233_2 = ((pub_r001735_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_48_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_48_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_99_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_99_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001735_21_1 * 2) + 25) & 63;
  int stage_v_237_2 = ((pub_r001735_21_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001735_12_1 * 2) + 23) & 63;
  int stage_v_238_2 = ((pub_r001735_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_83_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_83_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((pub_r001735_8_1 * 2) + 16) & 63;
  int stage_v_240_2 = ((pub_r001735_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001735_1_1 * 2) + 50) & 63;
  int stage_v_241_2 = ((pub_r001735_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_154_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_154_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_26_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_26_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_165_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_165_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001735_2_1 * 2) + 41) & 63;
  int stage_v_245_2 = ((pub_r001735_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001735_5_1 * 2) + 9) & 63;
  int stage_v_246_2 = ((pub_r001735_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_244_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_244_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((stage_v_98_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_98_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((pub_r001735_10_1 * 2) + 22) & 63;
  int stage_v_249_2 = ((pub_r001735_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001735_11_1 * 2) + 48) & 63;
  int stage_v_250_2 = ((pub_r001735_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001735_4_1 * 2) + 10) & 63;
  int stage_v_251_2 = ((pub_r001735_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((stage_v_201_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_201_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((pub_r001735_13_1 * 2) + 14) & 63;
  int stage_v_253_2 = ((pub_r001735_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((helper_flow_4_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_254_2 = ((helper_flow_4_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((pub_r001735_5_1 * 2) + 19) & 63;
  int stage_v_255_2 = ((pub_r001735_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((helper_flow_4_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_256_2 = ((helper_flow_4_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_105_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_105_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_231_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_231_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((stage_v_247_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_247_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001735_6_1 * 2) + 16) & 63;
  int stage_v_260_2 = ((pub_r001735_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((stage_v_147_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_147_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((stage_v_207_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_207_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((pub_r001735_17_1 * 2) + 35) & 63;
  int stage_v_263_2 = ((pub_r001735_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_83_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_83_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_119_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_119_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_230_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_230_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((stage_v_130_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_130_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((stage_v_235_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_268_2 = ((stage_v_235_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_268_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_268_2 + 1) & 15;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = ((stage_v_187_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_187_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((pub_r001735_19_1 * 2) + 40) & 63;
  int stage_v_270_2 = ((pub_r001735_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001735_20_1 * 2) + 36) & 63;
  int stage_v_271_2 = ((pub_r001735_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001735_6_1 * 2) + 24) & 63;
  int stage_v_272_2 = ((pub_r001735_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001735_11_1 * 2) + 28) & 63;
  int stage_v_273_2 = ((pub_r001735_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((stage_v_22_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_22_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((pub_r001735_15_1 * 2) + 30) & 63;
  int stage_v_275_2 = ((pub_r001735_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001735_21_1 * 2) + 43) & 63;
  int stage_v_276_2 = ((pub_r001735_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((stage_v_42_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_42_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((stage_v_201_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_201_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((stage_v_50_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_50_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((stage_v_277_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_277_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((stage_v_42_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_42_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((pub_r001735_0_1 * 2) + 23) & 63;
  int stage_v_282_2 = ((pub_r001735_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((stage_v_3_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_3_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_141_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_141_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001735_18_1 * 2) + 23) & 63;
  int stage_v_285_2 = ((pub_r001735_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_14_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_14_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((pub_r001735_16_1 * 2) + 42) & 63;
  int stage_v_287_2 = ((pub_r001735_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((stage_v_198_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_288_2 = ((stage_v_198_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_288_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_288_2 + 1) & 15;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = ((pub_r001735_15_1 * 2) + 45) & 63;
  int stage_v_289_2 = ((pub_r001735_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001735_3_1 * 2) + 37) & 63;
  int stage_v_290_2 = ((pub_r001735_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((stage_v_43_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_43_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((pub_r001735_14_1 * 2) + 8) & 63;
  int stage_v_292_2 = ((pub_r001735_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001735_5_1 * 2) + 44) & 63;
  int stage_v_293_2 = ((pub_r001735_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001735_6_1 * 2) + 28) & 63;
  int stage_v_294_2 = ((pub_r001735_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001735_10_1 * 2) + 46) & 63;
  int stage_v_295_2 = ((pub_r001735_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001735_6_1 * 2) + 48) & 63;
  int stage_v_296_2 = ((pub_r001735_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((stage_v_201_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_297_2 = ((stage_v_201_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_54_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_54_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_143_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_143_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((pub_r001735_17_1 * 2) + 20) & 63;
  int stage_v_300_2 = ((pub_r001735_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_213_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_213_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((sec_r001735_9_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_302_2 = ((sec_r001735_9_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((pub_r001735_10_1 * 2) + 6) & 63;
  int stage_v_303_2 = ((pub_r001735_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((stage_v_72_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_72_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((pub_r001735_20_1 * 2) + 31) & 63;
  int stage_v_305_2 = ((pub_r001735_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_183_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_183_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001735_16_1 * 2) + 48) & 63;
  int stage_v_307_2 = ((pub_r001735_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_0_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_0_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001735_20_1 * 2) + 26) & 63;
  int stage_v_309_2 = ((pub_r001735_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001735_9_1 * 2) + 33) & 63;
  int stage_v_310_2 = ((pub_r001735_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((stage_v_33_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_33_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_90_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_90_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((pub_r001735_14_1 * 2) + 34) & 63;
  int stage_v_313_2 = ((pub_r001735_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001735_0_1 * 2) + 45) & 63;
  int stage_v_314_2 = ((pub_r001735_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001735_5_1 * 2) + 22) & 63;
  int stage_v_315_2 = ((pub_r001735_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001735_21_1 * 2) + 9) & 63;
  int stage_v_316_2 = ((pub_r001735_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((stage_v_284_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_284_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_221_1 << 1) ^ (pub_r001735_19_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_221_2 << 1) ^ (pub_r001735_19_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((sec_r001735_16_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_319_2 = ((sec_r001735_16_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((pub_r001735_20_1 * 2) + 43) & 63;
  int stage_v_320_2 = ((pub_r001735_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((stage_v_230_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_230_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((stage_v_194_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_194_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_278_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_278_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001735_9_1 * 2) + 17) & 63;
  int stage_v_324_2 = ((pub_r001735_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((stage_v_44_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_44_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001735_3_1 * 2) + 13) & 63;
  int stage_v_326_2 = ((pub_r001735_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((stage_v_261_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_261_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((pub_r001735_2_1 * 2) + 14) & 63;
  int stage_v_328_2 = ((pub_r001735_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001735_16_1 * 2) + 9) & 63;
  int stage_v_329_2 = ((pub_r001735_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_24_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_24_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001735_0_1 * 2) + 5) & 63;
  int stage_v_331_2 = ((pub_r001735_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001735_19_1 * 2) + 18) & 63;
  int stage_v_332_2 = ((pub_r001735_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((stage_v_14_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_14_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((pub_r001735_19_1 * 2) + 16) & 63;
  int stage_v_334_2 = ((pub_r001735_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_283_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_283_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((stage_v_319_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_319_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001735_21_1 * 2) + 37) & 63;
  int stage_v_337_2 = ((pub_r001735_21_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001735_16_1 * 2) + 25) & 63;
  int stage_v_338_2 = ((pub_r001735_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001735_19_1 * 2) + 5) & 63;
  int stage_v_339_2 = ((pub_r001735_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((stage_v_167_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_167_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((pub_r001735_11_1 * 2) + 21) & 63;
  int stage_v_341_2 = ((pub_r001735_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_184_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_184_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((pub_r001735_13_1 * 2) + 5) & 63;
  int stage_v_343_2 = ((pub_r001735_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((stage_v_44_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_44_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_182_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_182_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((stage_v_319_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_319_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((stage_v_172_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_172_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((pub_r001735_15_1 * 2) + 15) & 63;
  int stage_v_348_2 = ((pub_r001735_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001735_3_1 * 2) + 7) & 63;
  int stage_v_349_2 = ((pub_r001735_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_342_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_342_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001735_21_1 * 2) + 35) & 63;
  int stage_v_351_2 = ((pub_r001735_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001735_19_1 * 2) + 35) & 63;
  int stage_v_352_2 = ((pub_r001735_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((stage_v_15_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_15_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((stage_v_279_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_279_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((stage_v_147_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_147_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((stage_v_302_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_302_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((sec_r001735_15_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_357_2 = ((sec_r001735_15_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001735_11_1 * 2) + 32) & 63;
  int stage_v_358_2 = ((pub_r001735_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((stage_v_140_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_140_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((stage_v_346_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_346_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001735_4_1 * 2) + 42) & 63;
  int stage_v_361_2 = ((pub_r001735_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001735_4_1 * 2) + 22) & 63;
  int stage_v_362_2 = ((pub_r001735_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((stage_v_182_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_182_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_258_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_258_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_48_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_48_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_22_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_22_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001735_16_1 * 2) + 22) & 63;
  int stage_v_367_2 = ((pub_r001735_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001735_3_1 * 2) + 10) & 63;
  int stage_v_368_2 = ((pub_r001735_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001735_19_1 * 2) + 14) & 63;
  int stage_v_369_2 = ((pub_r001735_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001735_17_1 * 2) + 29) & 63;
  int stage_v_370_2 = ((pub_r001735_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((stage_v_25_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_25_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((stage_v_182_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_182_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001735_3_1 * 2) + 37) & 63;
  int stage_v_373_2 = ((pub_r001735_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001735_9_1 * 2) + 28) & 63;
  int stage_v_374_2 = ((pub_r001735_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001735_14_1 * 2) + 42) & 63;
  int stage_v_375_2 = ((pub_r001735_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001735_6_1 * 2) + 19) & 63;
  int stage_v_376_2 = ((pub_r001735_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_225_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_225_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_224_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_224_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_14_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_14_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_379_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_379_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((pub_r001735_11_1 * 2) + 50) & 63;
  int stage_v_381_2 = ((pub_r001735_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((stage_v_333_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_333_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_143_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_143_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((stage_v_363_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_363_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((stage_v_130_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_130_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_198_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_198_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((stage_v_347_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_347_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001735_6_1 * 2) + 43) & 63;
  int stage_v_388_2 = ((pub_r001735_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_213_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_213_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001735_12_1 * 2) + 11) & 63;
  int stage_v_390_2 = ((pub_r001735_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_345_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_345_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_321_1 << 1) ^ (pub_r001735_1_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_321_2 << 1) ^ (pub_r001735_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((stage_v_150_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_150_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((stage_v_52_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_52_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001735_3_1 * 2) + 34) & 63;
  int stage_v_395_2 = ((pub_r001735_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_122_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_122_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001735_3_1 * 2) + 21) & 63;
  int stage_v_397_2 = ((pub_r001735_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001735_2_1 * 2) + 15) & 63;
  int stage_v_398_2 = ((pub_r001735_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001735_11_1 * 2) + 43) & 63;
  int stage_v_399_2 = ((pub_r001735_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001735_9_1 * 2) + 48) & 63;
  int stage_v_400_2 = ((pub_r001735_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_63_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_63_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_239_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_239_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((stage_v_182_1 << 1) ^ (pub_r001735_17_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_182_2 << 1) ^ (pub_r001735_17_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((pub_r001735_20_1 * 2) + 45) & 63;
  int stage_v_404_2 = ((pub_r001735_20_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001735_11_1 * 2) + 50) & 63;
  int stage_v_405_2 = ((pub_r001735_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001735_9_1 * 2) + 25) & 63;
  int stage_v_406_2 = ((pub_r001735_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((stage_v_265_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_265_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_56_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_56_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((stage_v_214_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_214_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((pub_r001735_13_1 * 2) + 13) & 63;
  int stage_v_410_2 = ((pub_r001735_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((stage_v_261_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_411_2 = ((stage_v_261_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_411_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_411_2 + 1) & 15;
  out_sink_1 ^= stage_v_411_1 & 63;
  out_sink_2 ^= stage_v_411_2 & 63;
  int stage_v_412_1 = ((pub_r001735_19_1 * 2) + 18) & 63;
  int stage_v_412_2 = ((pub_r001735_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((sec_r001735_12_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_413_2 = ((sec_r001735_12_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((pub_r001735_2_1 * 2) + 40) & 63;
  int stage_v_414_2 = ((pub_r001735_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((sec_r001735_12_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_415_2 = ((sec_r001735_12_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((stage_v_242_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_242_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001735_18_1 * 2) + 49) & 63;
  int stage_v_417_2 = ((pub_r001735_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((stage_v_291_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_291_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((pub_r001735_5_1 * 2) + 8) & 63;
  int stage_v_419_2 = ((pub_r001735_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001735_10_1 * 2) + 29) & 63;
  int stage_v_420_2 = ((pub_r001735_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((stage_v_407_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_407_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((pub_r001735_12_1 * 2) + 14) & 63;
  int stage_v_422_2 = ((pub_r001735_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001735_16_1 * 2) + 41) & 63;
  int stage_v_423_2 = ((pub_r001735_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((stage_v_201_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_424_2 = ((stage_v_201_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_424_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_424_2 + 1) & 15;
  out_sink_1 ^= stage_v_424_1 & 63;
  out_sink_2 ^= stage_v_424_2 & 63;
  int stage_v_425_1 = ((pub_r001735_11_1 * 2) + 27) & 63;
  int stage_v_425_2 = ((pub_r001735_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001735_6_1 * 2) + 43) & 63;
  int stage_v_426_2 = ((pub_r001735_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((sec_r001735_16_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_427_2 = ((sec_r001735_16_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((stage_v_151_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_428_2 = ((stage_v_151_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_428_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_428_2 + 1) & 15;
  out_sink_1 ^= stage_v_428_1 & 63;
  out_sink_2 ^= stage_v_428_2 & 63;
  int stage_v_429_1 = ((stage_v_342_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_342_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_355_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_355_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((pub_r001735_20_1 * 2) + 24) & 63;
  int stage_v_431_2 = ((pub_r001735_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((stage_v_268_1 << 1) ^ (pub_r001735_3_1 >> 1)) & 127;
  int stage_v_432_2 = ((stage_v_268_2 << 1) ^ (pub_r001735_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_432_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_432_2 + 1) & 15;
  out_sink_1 ^= stage_v_432_1 & 63;
  out_sink_2 ^= stage_v_432_2 & 63;
  int stage_v_433_1 = ((pub_r001735_1_1 * 2) + 21) & 63;
  int stage_v_433_2 = ((pub_r001735_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001735_14_1 * 2) + 43) & 63;
  int stage_v_434_2 = ((pub_r001735_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((stage_v_231_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_435_2 = ((stage_v_231_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_435_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_435_2 + 1) & 15;
  out_sink_1 ^= stage_v_435_1 & 63;
  out_sink_2 ^= stage_v_435_2 & 63;
  int stage_v_436_1 = ((stage_v_418_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_436_2 = ((stage_v_418_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_436_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_436_2 + 1) & 15;
  out_sink_1 ^= stage_v_436_1 & 63;
  out_sink_2 ^= stage_v_436_2 & 63;
  int stage_v_437_1 = ((pub_r001735_22_1 * 2) + 30) & 63;
  int stage_v_437_2 = ((pub_r001735_22_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001735_7_1 * 2) + 37) & 63;
  int stage_v_438_2 = ((pub_r001735_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((stage_v_242_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_439_2 = ((stage_v_242_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((pub_r001735_20_1 * 2) + 14) & 63;
  int stage_v_440_2 = ((pub_r001735_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((stage_v_173_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_441_2 = ((stage_v_173_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_441_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_441_2 + 1) & 15;
  out_sink_1 ^= stage_v_441_1 & 63;
  out_sink_2 ^= stage_v_441_2 & 63;
  int stage_v_442_1 = ((pub_r001735_9_1 * 2) + 6) & 63;
  int stage_v_442_2 = ((pub_r001735_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001735_13_1 * 2) + 47) & 63;
  int stage_v_443_2 = ((pub_r001735_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((sec_r001735_13_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_444_2 = ((sec_r001735_13_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((stage_v_242_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_445_2 = ((stage_v_242_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_445_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_445_2 + 1) & 15;
  out_sink_1 ^= stage_v_445_1 & 63;
  out_sink_2 ^= stage_v_445_2 & 63;
  int stage_v_446_1 = ((pub_r001735_21_1 * 2) + 48) & 63;
  int stage_v_446_2 = ((pub_r001735_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001735_16_1 * 2) + 25) & 63;
  int stage_v_447_2 = ((pub_r001735_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((stage_v_416_1 << 1) ^ (pub_r001735_11_1 >> 1)) & 127;
  int stage_v_448_2 = ((stage_v_416_2 << 1) ^ (pub_r001735_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_448_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_448_2 + 1) & 15;
  out_sink_1 ^= stage_v_448_1 & 63;
  out_sink_2 ^= stage_v_448_2 & 63;
  int stage_v_449_1 = ((pub_r001735_1_1 * 2) + 42) & 63;
  int stage_v_449_2 = ((pub_r001735_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((stage_v_407_1 << 1) ^ (pub_r001735_12_1 >> 1)) & 127;
  int stage_v_450_2 = ((stage_v_407_2 << 1) ^ (pub_r001735_12_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_450_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_450_2 + 1) & 15;
  out_sink_1 ^= stage_v_450_1 & 63;
  out_sink_2 ^= stage_v_450_2 & 63;
  int stage_v_451_1 = ((pub_r001735_20_1 * 2) + 23) & 63;
  int stage_v_451_2 = ((pub_r001735_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001735_1_1 * 2) + 14) & 63;
  int stage_v_452_2 = ((pub_r001735_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((stage_v_380_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_453_2 = ((stage_v_380_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_453_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_453_2 + 1) & 15;
  out_sink_1 ^= stage_v_453_1 & 63;
  out_sink_2 ^= stage_v_453_2 & 63;
  int stage_v_454_1 = ((stage_v_177_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_454_2 = ((stage_v_177_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_454_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_454_2 + 1) & 15;
  out_sink_1 ^= stage_v_454_1 & 63;
  out_sink_2 ^= stage_v_454_2 & 63;
  int stage_v_455_1 = ((pub_r001735_14_1 * 2) + 34) & 63;
  int stage_v_455_2 = ((pub_r001735_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001735_10_1 * 2) + 28) & 63;
  int stage_v_456_2 = ((pub_r001735_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001735_7_1 * 2) + 18) & 63;
  int stage_v_457_2 = ((pub_r001735_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001735_14_1 * 2) + 25) & 63;
  int stage_v_458_2 = ((pub_r001735_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((stage_v_203_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_459_2 = ((stage_v_203_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_459_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_459_2 + 1) & 15;
  out_sink_1 ^= stage_v_459_1 & 63;
  out_sink_2 ^= stage_v_459_2 & 63;
  int stage_v_460_1 = ((pub_r001735_17_1 * 2) + 31) & 63;
  int stage_v_460_2 = ((pub_r001735_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001735_15_1 * 2) + 49) & 63;
  int stage_v_461_2 = ((pub_r001735_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((stage_v_299_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_462_2 = ((stage_v_299_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_462_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_462_2 + 1) & 15;
  out_sink_1 ^= stage_v_462_1 & 63;
  out_sink_2 ^= stage_v_462_2 & 63;
  int stage_v_463_1 = ((pub_r001735_1_1 * 2) + 40) & 63;
  int stage_v_463_2 = ((pub_r001735_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((stage_v_394_1 << 1) ^ (pub_r001735_10_1 >> 1)) & 127;
  int stage_v_464_2 = ((stage_v_394_2 << 1) ^ (pub_r001735_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_464_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_464_2 + 1) & 15;
  out_sink_1 ^= stage_v_464_1 & 63;
  out_sink_2 ^= stage_v_464_2 & 63;
  int stage_v_465_1 = ((stage_v_80_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_465_2 = ((stage_v_80_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_465_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_465_2 + 1) & 15;
  out_sink_1 ^= stage_v_465_1 & 63;
  out_sink_2 ^= stage_v_465_2 & 63;
  int stage_v_466_1 = ((pub_r001735_11_1 * 2) + 29) & 63;
  int stage_v_466_2 = ((pub_r001735_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((stage_v_306_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_467_2 = ((stage_v_306_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_467_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_467_2 + 1) & 15;
  out_sink_1 ^= stage_v_467_1 & 63;
  out_sink_2 ^= stage_v_467_2 & 63;
  int stage_v_468_1 = ((sec_r001735_4_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_468_2 = ((sec_r001735_4_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_468_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_468_2 + 1) & 15;
  out_sink_1 ^= stage_v_468_1 & 63;
  out_sink_2 ^= stage_v_468_2 & 63;
  int stage_v_469_1 = ((stage_v_257_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_469_2 = ((stage_v_257_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_469_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_469_2 + 1) & 15;
  out_sink_1 ^= stage_v_469_1 & 63;
  out_sink_2 ^= stage_v_469_2 & 63;
  int stage_v_470_1 = ((pub_r001735_14_1 * 2) + 19) & 63;
  int stage_v_470_2 = ((pub_r001735_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001735_9_1 * 2) + 37) & 63;
  int stage_v_471_2 = ((pub_r001735_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001735_6_1 * 2) + 26) & 63;
  int stage_v_472_2 = ((pub_r001735_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((stage_v_210_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_473_2 = ((stage_v_210_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_473_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_473_2 + 1) & 15;
  out_sink_1 ^= stage_v_473_1 & 63;
  out_sink_2 ^= stage_v_473_2 & 63;
  int stage_v_474_1 = ((pub_r001735_13_1 * 2) + 26) & 63;
  int stage_v_474_2 = ((pub_r001735_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((sec_r001735_10_1 << 1) ^ (pub_r001735_22_1 >> 1)) & 127;
  int stage_v_475_2 = ((sec_r001735_10_2 << 1) ^ (pub_r001735_22_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_475_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_475_2 + 1) & 15;
  out_sink_1 ^= stage_v_475_1 & 63;
  out_sink_2 ^= stage_v_475_2 & 63;
  int stage_v_476_1 = ((pub_r001735_3_1 * 2) + 13) & 63;
  int stage_v_476_2 = ((pub_r001735_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001735_6_1 * 2) + 30) & 63;
  int stage_v_477_2 = ((pub_r001735_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((pub_r001735_19_1 * 2) + 31) & 63;
  int stage_v_478_2 = ((pub_r001735_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001735_2_1 * 2) + 32) & 63;
  int stage_v_479_2 = ((pub_r001735_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001735_10_1 * 2) + 8) & 63;
  int stage_v_480_2 = ((pub_r001735_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001735_20_1 * 2) + 28) & 63;
  int stage_v_481_2 = ((pub_r001735_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((stage_v_269_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_482_2 = ((stage_v_269_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_482_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_482_2 + 1) & 15;
  out_sink_1 ^= stage_v_482_1 & 63;
  out_sink_2 ^= stage_v_482_2 & 63;
  int stage_v_483_1 = ((stage_v_396_1 << 1) ^ (pub_r001735_18_1 >> 1)) & 127;
  int stage_v_483_2 = ((stage_v_396_2 << 1) ^ (pub_r001735_18_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_483_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_483_2 + 1) & 15;
  out_sink_1 ^= stage_v_483_1 & 63;
  out_sink_2 ^= stage_v_483_2 & 63;
  int stage_v_484_1 = ((stage_v_391_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_484_2 = ((stage_v_391_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_484_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_484_2 + 1) & 15;
  out_sink_1 ^= stage_v_484_1 & 63;
  out_sink_2 ^= stage_v_484_2 & 63;
  int stage_v_485_1 = ((stage_v_125_1 << 1) ^ (pub_r001735_14_1 >> 1)) & 127;
  int stage_v_485_2 = ((stage_v_125_2 << 1) ^ (pub_r001735_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_485_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_485_2 + 1) & 15;
  out_sink_1 ^= stage_v_485_1 & 63;
  out_sink_2 ^= stage_v_485_2 & 63;
  int stage_v_486_1 = ((pub_r001735_21_1 * 2) + 46) & 63;
  int stage_v_486_2 = ((pub_r001735_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((pub_r001735_11_1 * 2) + 42) & 63;
  int stage_v_487_2 = ((pub_r001735_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((stage_v_325_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_488_2 = ((stage_v_325_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_488_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_488_2 + 1) & 15;
  out_sink_1 ^= stage_v_488_1 & 63;
  out_sink_2 ^= stage_v_488_2 & 63;
  int stage_v_489_1 = ((pub_r001735_4_1 * 2) + 14) & 63;
  int stage_v_489_2 = ((pub_r001735_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((stage_v_214_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_490_2 = ((stage_v_214_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_490_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_490_2 + 1) & 15;
  out_sink_1 ^= stage_v_490_1 & 63;
  out_sink_2 ^= stage_v_490_2 & 63;
  int stage_v_491_1 = ((pub_r001735_19_1 * 2) + 19) & 63;
  int stage_v_491_2 = ((pub_r001735_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((stage_v_409_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_492_2 = ((stage_v_409_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_492_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_492_2 + 1) & 15;
  out_sink_1 ^= stage_v_492_1 & 63;
  out_sink_2 ^= stage_v_492_2 & 63;
  int stage_v_493_1 = ((pub_r001735_1_1 * 2) + 20) & 63;
  int stage_v_493_2 = ((pub_r001735_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = ((pub_r001735_14_1 * 2) + 22) & 63;
  int stage_v_494_2 = ((pub_r001735_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_494_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_494_2) & 127;
  int stage_v_495_1 = ((stage_v_330_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_495_2 = ((stage_v_330_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_495_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_495_2 + 1) & 15;
  out_sink_1 ^= stage_v_495_1 & 63;
  out_sink_2 ^= stage_v_495_2 & 63;
  int stage_v_496_1 = ((pub_r001735_2_1 * 2) + 46) & 63;
  int stage_v_496_2 = ((pub_r001735_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_496_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_496_2) & 127;
  int stage_v_497_1 = ((pub_r001735_13_1 * 2) + 35) & 63;
  int stage_v_497_2 = ((pub_r001735_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((stage_v_247_1 << 1) ^ (pub_r001735_2_1 >> 1)) & 127;
  int stage_v_498_2 = ((stage_v_247_2 << 1) ^ (pub_r001735_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_498_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_498_2 + 1) & 15;
  out_sink_1 ^= stage_v_498_1 & 63;
  out_sink_2 ^= stage_v_498_2 & 63;
  int stage_v_499_1 = ((pub_r001735_5_1 * 2) + 36) & 63;
  int stage_v_499_2 = ((pub_r001735_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = ((stage_v_120_1 << 1) ^ (pub_r001735_20_1 >> 1)) & 127;
  int stage_v_500_2 = ((stage_v_120_2 << 1) ^ (pub_r001735_20_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_500_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_500_2 + 1) & 15;
  out_sink_1 ^= stage_v_500_1 & 63;
  out_sink_2 ^= stage_v_500_2 & 63;
  int stage_v_501_1 = ((stage_v_155_1 << 1) ^ (pub_r001735_5_1 >> 1)) & 127;
  int stage_v_501_2 = ((stage_v_155_2 << 1) ^ (pub_r001735_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_501_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_501_2 + 1) & 15;
  out_sink_1 ^= stage_v_501_1 & 63;
  out_sink_2 ^= stage_v_501_2 & 63;
  int stage_v_502_1 = ((pub_r001735_13_1 * 2) + 29) & 63;
  int stage_v_502_2 = ((pub_r001735_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((stage_v_32_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_503_2 = ((stage_v_32_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_503_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_503_2 + 1) & 15;
  out_sink_1 ^= stage_v_503_1 & 63;
  out_sink_2 ^= stage_v_503_2 & 63;
  int stage_v_504_1 = ((stage_v_503_1 << 1) ^ (pub_r001735_21_1 >> 1)) & 127;
  int stage_v_504_2 = ((stage_v_503_2 << 1) ^ (pub_r001735_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_504_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_504_2 + 1) & 15;
  out_sink_1 ^= stage_v_504_1 & 63;
  out_sink_2 ^= stage_v_504_2 & 63;
  int stage_v_505_1 = ((sec_r001735_17_1 << 1) ^ (pub_r001735_7_1 >> 1)) & 127;
  int stage_v_505_2 = ((sec_r001735_17_2 << 1) ^ (pub_r001735_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_505_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_505_2 + 1) & 15;
  out_sink_1 ^= stage_v_505_1 & 63;
  out_sink_2 ^= stage_v_505_2 & 63;
  int stage_v_506_1 = ((stage_v_268_1 << 1) ^ (pub_r001735_4_1 >> 1)) & 127;
  int stage_v_506_2 = ((stage_v_268_2 << 1) ^ (pub_r001735_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_506_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_506_2 + 1) & 15;
  out_sink_1 ^= stage_v_506_1 & 63;
  out_sink_2 ^= stage_v_506_2 & 63;
  int stage_v_507_1 = ((pub_r001735_15_1 * 2) + 16) & 63;
  int stage_v_507_2 = ((pub_r001735_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_507_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_507_2) & 127;
  int stage_v_508_1 = ((pub_r001735_13_1 * 2) + 46) & 63;
  int stage_v_508_2 = ((pub_r001735_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_508_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_508_2) & 127;
  int stage_v_509_1 = ((pub_r001735_15_1 * 2) + 29) & 63;
  int stage_v_509_2 = ((pub_r001735_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_509_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_509_2) & 127;
  int stage_v_510_1 = ((pub_r001735_13_1 * 2) + 19) & 63;
  int stage_v_510_2 = ((pub_r001735_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_510_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_510_2) & 127;
  int stage_v_511_1 = ((pub_r001735_6_1 * 2) + 39) & 63;
  int stage_v_511_2 = ((pub_r001735_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((stage_v_143_1 << 1) ^ (pub_r001735_15_1 >> 1)) & 127;
  int stage_v_512_2 = ((stage_v_143_2 << 1) ^ (pub_r001735_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_512_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_512_2 + 1) & 15;
  out_sink_1 ^= stage_v_512_1 & 63;
  out_sink_2 ^= stage_v_512_2 & 63;
  int stage_v_513_1 = ((pub_r001735_7_1 * 2) + 47) & 63;
  int stage_v_513_2 = ((pub_r001735_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_513_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_513_2) & 127;
  int stage_v_514_1 = ((stage_v_473_1 << 1) ^ (pub_r001735_13_1 >> 1)) & 127;
  int stage_v_514_2 = ((stage_v_473_2 << 1) ^ (pub_r001735_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_514_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_514_2 + 1) & 15;
  out_sink_1 ^= stage_v_514_1 & 63;
  out_sink_2 ^= stage_v_514_2 & 63;
  int stage_v_515_1 = ((stage_v_371_1 << 1) ^ (pub_r001735_16_1 >> 1)) & 127;
  int stage_v_515_2 = ((stage_v_371_2 << 1) ^ (pub_r001735_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_515_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_515_2 + 1) & 15;
  out_sink_1 ^= stage_v_515_1 & 63;
  out_sink_2 ^= stage_v_515_2 & 63;
  int stage_v_516_1 = ((stage_v_283_1 << 1) ^ (pub_r001735_6_1 >> 1)) & 127;
  int stage_v_516_2 = ((stage_v_283_2 << 1) ^ (pub_r001735_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_516_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_516_2 + 1) & 15;
  out_sink_1 ^= stage_v_516_1 & 63;
  out_sink_2 ^= stage_v_516_2 & 63;
  int stage_v_517_1 = ((pub_r001735_22_1 * 2) + 42) & 63;
  int stage_v_517_2 = ((pub_r001735_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_517_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_517_2) & 127;
  int stage_v_518_1 = ((stage_v_483_1 << 1) ^ (pub_r001735_0_1 >> 1)) & 127;
  int stage_v_518_2 = ((stage_v_483_2 << 1) ^ (pub_r001735_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_518_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_518_2 + 1) & 15;
  out_sink_1 ^= stage_v_518_1 & 63;
  out_sink_2 ^= stage_v_518_2 & 63;
  int stage_v_519_1 = ((pub_r001735_10_1 * 2) + 14) & 63;
  int stage_v_519_2 = ((pub_r001735_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_519_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_519_2) & 127;
  int stage_v_520_1 = ((stage_v_142_1 << 1) ^ (pub_r001735_9_1 >> 1)) & 127;
  int stage_v_520_2 = ((stage_v_142_2 << 1) ^ (pub_r001735_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_520_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_520_2 + 1) & 15;
  out_sink_1 ^= stage_v_520_1 & 63;
  out_sink_2 ^= stage_v_520_2 & 63;
  int stage_v_521_1 = ((pub_r001735_8_1 * 2) + 21) & 63;
  int stage_v_521_2 = ((pub_r001735_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_521_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_521_2) & 127;
  int stage_v_522_1 = ((pub_r001735_15_1 * 2) + 37) & 63;
  int stage_v_522_2 = ((pub_r001735_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_522_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_522_2) & 127;
  int stage_v_523_1 = ((stage_v_288_1 << 1) ^ (pub_r001735_8_1 >> 1)) & 127;
  int stage_v_523_2 = ((stage_v_288_2 << 1) ^ (pub_r001735_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_523_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_523_2 + 1) & 15;
  out_sink_1 ^= stage_v_523_1 & 63;
  out_sink_2 ^= stage_v_523_2 & 63;
  int stage_v_524_1 = ((pub_r001735_4_1 * 2) + 20) & 63;
  int stage_v_524_2 = ((pub_r001735_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_524_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_524_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001735_17_1 != sec_r001735_17_2);
  __CPROVER_assume(pub_r001735_21_1 == pub_r001735_21_2);
  __CPROVER_assume(pub_r001735_12_1 == pub_r001735_12_2);
  __CPROVER_assume(pub_r001735_17_1 == pub_r001735_17_2);
  __CPROVER_assume(pub_r001735_14_1 == pub_r001735_14_2);
  __CPROVER_assume(pub_r001735_4_1 == pub_r001735_4_2);
  __CPROVER_assume(pub_r001735_6_1 == pub_r001735_6_2);
  __CPROVER_assume(sec_r001735_7_1 != sec_r001735_7_2);
  __CPROVER_assume(sec_r001735_2_1 != sec_r001735_2_2);
  __CPROVER_assume(pub_r001735_0_1 == pub_r001735_0_2);
  __CPROVER_assume(sec_r001735_9_1 != sec_r001735_9_2);
  __CPROVER_assume(sec_r001735_1_1 != sec_r001735_1_2);
  __CPROVER_assume(sec_r001735_5_1 != sec_r001735_5_2);
  __CPROVER_assume(sec_r001735_11_1 != sec_r001735_11_2);
  __CPROVER_assume(pub_r001735_7_1 == pub_r001735_7_2);
  __CPROVER_assume(sec_r001735_13_1 != sec_r001735_13_2);
  __CPROVER_assume(sec_r001735_3_1 != sec_r001735_3_2);
  __CPROVER_assume(pub_r001735_20_1 == pub_r001735_20_2);
  __CPROVER_assume(sec_r001735_6_1 != sec_r001735_6_2);
  __CPROVER_assume(sec_r001735_0_1 != sec_r001735_0_2);
  __CPROVER_assume(pub_r001735_3_1 == pub_r001735_3_2);
  __CPROVER_assume(pub_r001735_10_1 == pub_r001735_10_2);
  __CPROVER_assume(pub_r001735_11_1 == pub_r001735_11_2);
  __CPROVER_assume(sec_r001735_15_1 != sec_r001735_15_2);
  __CPROVER_assume(pub_r001735_19_1 == pub_r001735_19_2);
  __CPROVER_assume(sec_r001735_12_1 != sec_r001735_12_2);
  __CPROVER_assume(pub_r001735_2_1 == pub_r001735_2_2);
  __CPROVER_assume(sec_r001735_14_1 != sec_r001735_14_2);
  __CPROVER_assume(pub_r001735_8_1 == pub_r001735_8_2);
  __CPROVER_assume(sec_r001735_16_1 != sec_r001735_16_2);
  __CPROVER_assume(pub_r001735_9_1 == pub_r001735_9_2);
  __CPROVER_assume(pub_r001735_13_1 == pub_r001735_13_2);
  __CPROVER_assume(pub_r001735_1_1 == pub_r001735_1_2);
  __CPROVER_assume(pub_r001735_5_1 == pub_r001735_5_2);
  __CPROVER_assume(sec_r001735_8_1 != sec_r001735_8_2);
  __CPROVER_assume(pub_r001735_15_1 == pub_r001735_15_2);
  __CPROVER_assume(pub_r001735_16_1 == pub_r001735_16_2);
  __CPROVER_assume(sec_r001735_10_1 != sec_r001735_10_2);
  __CPROVER_assume(pub_r001735_22_1 == pub_r001735_22_2);
  __CPROVER_assume(sec_r001735_4_1 != sec_r001735_4_2);
  __CPROVER_assume(pub_r001735_18_1 == pub_r001735_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.counter == st_var_3_2.counter);
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
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
  assert(stage_v_510_1 == stage_v_510_2);
  assert(stage_v_511_1 == stage_v_511_2);
  assert(stage_v_512_1 == stage_v_512_2);
  assert(stage_v_513_1 == stage_v_513_2);
  assert(stage_v_514_1 == stage_v_514_2);
  assert(stage_v_515_1 == stage_v_515_2);
  assert(stage_v_516_1 == stage_v_516_2);
  assert(stage_v_517_1 == stage_v_517_2);
  assert(stage_v_518_1 == stage_v_518_2);
  assert(stage_v_519_1 == stage_v_519_2);
  assert(stage_v_520_1 == stage_v_520_2);
  assert(stage_v_521_1 == stage_v_521_2);
  assert(stage_v_522_1 == stage_v_522_2);
  assert(stage_v_523_1 == stage_v_523_2);
  assert(stage_v_524_1 == stage_v_524_2);
}


