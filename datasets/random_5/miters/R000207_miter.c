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
struct FilterState_R000207_713_0
{
  short damping;
  int prev_in;
  int mode;
  int buffer[3];
};
struct AudioFrame_R000207_713_1
{
  int peak;
  int envelope;
  short channels;
  unsigned char gain;
  int buffer[3];
};
struct StreamBuffer_R000207_713_2
{
  unsigned char watermark;
  int state;
  unsigned char head;
  int checksum;
  int capacity;
  int tail;
  int buffer[3];
};
union RegisterBank_R000207_713_0
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
void fn_R000207_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_88_1)
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

  switch (bound_88_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_89_1 = local_arr_1[aux_1 % 3];
  int tracker_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_88_1 == bound_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_89_1 == tracker_89_2);
}

int fn_R000207_713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_88 = (aux + st.buffer[1]) & 3;
  switch (bound_88)
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
  int local_arr[3] = {4, 9, 15};
  int tracker_89 = local_arr[aux % 3];
  acc = (acc + (tracker_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_41_1) & 63;
  aux_2 = (aux_2 + segment_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_20_1)
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

  switch (mask_20_2)
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
  int margin_65_1 = local_arr_1[aux_1 % 3];
  int margin_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_41_1 == segment_41_2);
  assert(mask_20_1 == mask_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_65_1 == margin_65_2);
}

int fn_R000207_713_1(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_41) & 63;
  acc ^= aux;
  int mask_20 = (aux + st.buffer[1]) & 3;
  switch (mask_20)
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
  int margin_65 = local_arr[aux % 3];
  acc = (acc + (margin_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_69_1)
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

  switch (cursor_69_2)
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

  int mask_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_35_1) & 63;
  aux_2 = (aux_2 + mask_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_69_1 == cursor_69_2);
  assert(mask_35_1 == mask_35_2);
}

int fn_R000207_713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_69 = (aux + st.buffer[1]) & 3;
  switch (cursor_69)
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

  int mask_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_98_1) & 63;
  aux_2 = (aux_2 + segment_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_97_1 = local_arr_1[aux_1 % 3];
  int residue_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_98_1 == segment_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_97_1 == residue_97_2);
}

int fn_R000207_713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_97 = local_arr[aux % 3];
  acc = (acc + (residue_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_43_1)
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

  switch (checksum_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_43_1 == checksum_43_2);
}

int fn_R000207_713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_43 = (aux + st.buffer[1]) & 3;
  switch (checksum_43)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tally_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_64_1)
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

  switch (tally_64_2)
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

  int cursor_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_75_1 > 21)
  {
    acc_1 = ((acc_1 + (cursor_75_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_75_2 > 21)
  {
    acc_2 = ((acc_2 + (cursor_75_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_26_1 = local_arr_1[aux_1 % 3];
  int damping_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_64_1 == tally_64_2);
  assert(cursor_75_1 == cursor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_26_1 == damping_26_2);
}

int fn_R000207_713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tally_64 = (aux + st.buffer[1]) & 3;
  switch (tally_64)
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

  int cursor_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_75 > 21)
  {
    acc = ((acc + (cursor_75 * 2)) + 5) & 127;
    aux ^= cursor_75 & 15;
  }
  else
  {
    acc = ((acc - cursor_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_26 = local_arr[aux % 3];
  acc = (acc + (damping_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st_1 = {0};
  struct FilterState_R000207_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_80_1) & 63;
  aux_2 = (aux_2 + offset_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_72_1 = local_arr_1[aux_1 % 3];
  int sample_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_72_2 * 2)) & 127;
  int window_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_52_1 > 18)
  {
    acc_1 = ((acc_1 + (window_52_1 * 2)) + 5) & 127;
    aux_1 ^= window_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_52_2 > 18)
  {
    acc_2 = ((acc_2 + (window_52_2 * 2)) + 5) & 127;
    aux_2 ^= window_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_52_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_80_1 == offset_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_72_1 == sample_72_2);
  assert(window_52_1 == window_52_2);
}

int fn_R000207_713_6(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_72 = local_arr[aux % 3];
  acc = (acc + (sample_72 * 2)) & 127;
  int window_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_52 > 18)
  {
    acc = ((acc + (window_52 * 2)) + 5) & 127;
    aux ^= window_52 & 15;
  }
  else
  {
    acc = ((acc - window_52) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_44_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_44_1 * 2)) + 5) & 127;
    aux_1 ^= segment_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_44_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_44_2 * 2)) + 5) & 127;
    aux_2 ^= segment_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_57_1) & 63;
  aux_2 = (aux_2 + phase_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_49_1)
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

  switch (residue_49_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(phase_57_1 == phase_57_2);
  assert(residue_49_1 == residue_49_2);
}

int fn_R000207_713_7(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_44 > 16)
  {
    acc = ((acc + (segment_44 * 2)) + 5) & 127;
    aux ^= segment_44 & 15;
  }
  else
  {
    acc = ((acc - segment_44) + 11) & 127;
    aux += 3;
  }
  int phase_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_57) & 63;
  acc ^= aux;
  int residue_49 = (aux + st.buffer[1]) & 3;
  switch (residue_49)
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
  return (acc + aux) & 255;
}

void fn_R000207_713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quantum_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_60_1 > 49)
  {
    acc_1 = ((acc_1 + (quantum_60_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_60_2 > 49)
  {
    acc_2 = ((acc_2 + (quantum_60_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_37_1)
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

  switch (index_reg_37_2)
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

  int margin_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_87_1) & 63;
  aux_2 = (aux_2 + margin_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_48_1 = local_arr_1[aux_1 % 3];
  int parity_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_60_1 == quantum_60_2);
  assert(index_reg_37_1 == index_reg_37_2);
  assert(margin_87_1 == margin_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_48_1 == parity_48_2);
}

int fn_R000207_713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quantum_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_60 > 49)
  {
    acc = ((acc + (quantum_60 * 2)) + 5) & 127;
    aux ^= quantum_60 & 15;
  }
  else
  {
    acc = ((acc - quantum_60) + 11) & 127;
    aux += 3;
  }
  int index_reg_37 = (aux + st.buffer[1]) & 3;
  switch (index_reg_37)
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

  int margin_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_48 = local_arr[aux % 3];
  acc = (acc + (parity_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int threshold_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_23_1) & 63;
  aux_2 = (aux_2 + threshold_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_42_1)
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

  switch (coefficient_42_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_23_1 == threshold_23_2);
  assert(segment_18_1 == segment_18_2);
  assert(coefficient_42_1 == coefficient_42_2);
}

int fn_R000207_713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int threshold_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_23) & 63;
  acc ^= aux;
  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 16)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  int coefficient_42 = (aux + st.buffer[1]) & 3;
  switch (coefficient_42)
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

void fn_R000207_713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_16_1 > 21)
  {
    acc_1 = ((acc_1 + (phase_16_1 * 2)) + 5) & 127;
    aux_1 ^= phase_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_16_2 > 21)
  {
    acc_2 = ((acc_2 + (phase_16_2 * 2)) + 5) & 127;
    aux_2 ^= phase_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_16_1 == phase_16_2);
}

int fn_R000207_713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_16 > 21)
  {
    acc = ((acc + (phase_16 * 2)) + 5) & 127;
    aux ^= phase_16 & 15;
  }
  else
  {
    acc = ((acc - phase_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tally_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_24_1) & 63;
  aux_2 = (aux_2 + tally_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_82_1 = local_arr_1[aux_1 % 3];
  int factor_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_24_1 == tally_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_82_1 == factor_82_2);
}

int fn_R000207_713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tally_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_82 = local_arr[aux % 3];
  acc = (acc + (factor_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_78_1) & 63;
  aux_2 = (aux_2 + damping_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_16_1)
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

  switch (pivot_16_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_78_1 == damping_78_2);
  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000207_713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_78) & 63;
  acc ^= aux;
  int pivot_16 = (aux + st.buffer[1]) & 3;
  switch (pivot_16)
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

void fn_R000207_713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st_1 = {0};
  struct FilterState_R000207_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_40_1 = local_arr_1[aux_1 % 3];
  int index_reg_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_15_1) & 63;
  aux_2 = (aux_2 + threshold_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_40_1 == index_reg_40_2);
  assert(threshold_15_1 == threshold_15_2);
}

int fn_R000207_713_13(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int index_reg_40 = local_arr[aux % 3];
  acc = (acc + (index_reg_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000207_713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_73_1 > 50)
  {
    acc_1 = ((acc_1 + (bound_73_1 * 2)) + 5) & 127;
    aux_1 ^= bound_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_73_2 > 50)
  {
    acc_2 = ((acc_2 + (bound_73_2 * 2)) + 5) & 127;
    aux_2 ^= bound_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_43_1 = local_arr_1[aux_1 % 3];
  int window_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_43_2 * 2)) & 127;
  int factor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_63_1)
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

  switch (factor_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_73_1 == bound_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_43_1 == window_43_2);
  assert(factor_63_1 == factor_63_2);
}

int fn_R000207_713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_73 > 50)
  {
    acc = ((acc + (bound_73 * 2)) + 5) & 127;
    aux ^= bound_73 & 15;
  }
  else
  {
    acc = ((acc - bound_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_43 = local_arr[aux % 3];
  acc = (acc + (window_43 * 2)) & 127;
  int factor_63 = (aux + st.buffer[1]) & 3;
  switch (factor_63)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_54_1 = local_arr_1[aux_1 % 3];
  int weight_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_11_1 > 14)
  {
    acc_1 = ((acc_1 + (damping_11_1 * 2)) + 5) & 127;
    aux_1 ^= damping_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_11_2 > 14)
  {
    acc_2 = ((acc_2 + (damping_11_2 * 2)) + 5) & 127;
    aux_2 ^= damping_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_95_1)
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

  switch (residue_95_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_54_1 == weight_54_2);
  assert(damping_11_1 == damping_11_2);
  assert(residue_95_1 == residue_95_2);
}

int fn_R000207_713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int weight_54 = local_arr[aux % 3];
  acc = (acc + (weight_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_11 > 14)
  {
    acc = ((acc + (damping_11 * 2)) + 5) & 127;
    aux ^= damping_11 & 15;
  }
  else
  {
    acc = ((acc - damping_11) + 11) & 127;
    aux += 3;
  }
  int residue_95 = (aux + st.buffer[1]) & 3;
  switch (residue_95)
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

void fn_R000207_713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_83_1)
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

  switch (tracker_83_2)
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

  int threshold_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_60_1) & 63;
  aux_2 = (aux_2 + threshold_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_55_1 = local_arr_1[aux_1 % 3];
  int anchor_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_83_1 == tracker_83_2);
  assert(threshold_60_1 == threshold_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_55_1 == anchor_55_2);
}

int fn_R000207_713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_83 = (aux + st.buffer[1]) & 3;
  switch (tracker_83)
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

  int threshold_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_60) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_55 = local_arr[aux % 3];
  acc = (acc + (anchor_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st_1 = {0};
  struct FilterState_R000207_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_90_1)
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

  switch (mask_90_2)
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

  int factor_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_67_1 > 12)
  {
    acc_1 = ((acc_1 + (factor_67_1 * 2)) + 5) & 127;
    aux_1 ^= factor_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_67_2 > 12)
  {
    acc_2 = ((acc_2 + (factor_67_2 * 2)) + 5) & 127;
    aux_2 ^= factor_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_67_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_90_1 == mask_90_2);
  assert(factor_67_1 == factor_67_2);
}

int fn_R000207_713_17(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_90 = (aux + st.buffer[1]) & 3;
  switch (mask_90)
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

  int factor_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_67 > 12)
  {
    acc = ((acc + (factor_67 * 2)) + 5) & 127;
    aux ^= factor_67 & 15;
  }
  else
  {
    acc = ((acc - factor_67) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_84_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_84_1 * 2)) + 5) & 127;
    aux_1 ^= metric_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_84_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_84_2 * 2)) + 5) & 127;
    aux_2 ^= metric_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_79_1)
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

  switch (mask_79_2)
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
  int checksum_67_1 = local_arr_1[aux_1 % 3];
  int checksum_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  assert(mask_79_1 == mask_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_67_1 == checksum_67_2);
}

int fn_R000207_713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_84 > 33)
  {
    acc = ((acc + (metric_84 * 2)) + 5) & 127;
    aux ^= metric_84 & 15;
  }
  else
  {
    acc = ((acc - metric_84) + 11) & 127;
    aux += 3;
  }
  int mask_79 = (aux + st.buffer[1]) & 3;
  switch (mask_79)
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
  int checksum_67 = local_arr[aux % 3];
  acc = (acc + (checksum_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_22_1 = local_arr_1[aux_1 % 3];
  int metric_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_22_2 * 2)) & 127;
  int quotient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_62_1)
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

  switch (quotient_62_2)
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

  int bound_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_66_1 > 42)
  {
    acc_1 = ((acc_1 + (bound_66_1 * 2)) + 5) & 127;
    aux_1 ^= bound_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_66_2 > 42)
  {
    acc_2 = ((acc_2 + (bound_66_2 * 2)) + 5) & 127;
    aux_2 ^= bound_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_22_1 == metric_22_2);
  assert(quotient_62_1 == quotient_62_2);
  assert(bound_66_1 == bound_66_2);
}

int fn_R000207_713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int metric_22 = local_arr[aux % 3];
  acc = (acc + (metric_22 * 2)) & 127;
  int quotient_62 = (aux + st.buffer[1]) & 3;
  switch (quotient_62)
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

  int bound_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_66 > 42)
  {
    acc = ((acc + (bound_66 * 2)) + 5) & 127;
    aux ^= bound_66 & 15;
  }
  else
  {
    acc = ((acc - bound_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000207_713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st_1 = {0};
  struct FilterState_R000207_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_56_1)
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

  switch (scale_56_2)
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
  int window_77_1 = local_arr_1[aux_1 % 3];
  int window_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_77_2 * 2)) & 127;
  int delta_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_87_1 > 34)
  {
    acc_1 = ((acc_1 + (delta_87_1 * 2)) + 5) & 127;
    aux_1 ^= delta_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_87_2 > 34)
  {
    acc_2 = ((acc_2 + (delta_87_2 * 2)) + 5) & 127;
    aux_2 ^= delta_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_17_1) & 63;
  aux_2 = (aux_2 + bound_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_56_1 == scale_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_77_1 == window_77_2);
  assert(delta_87_1 == delta_87_2);
  assert(bound_17_1 == bound_17_2);
}

int fn_R000207_713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_56 = (aux + st.buffer[1]) & 3;
  switch (scale_56)
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
  int window_77 = local_arr[aux % 3];
  acc = (acc + (window_77 * 2)) & 127;
  int delta_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_87 > 34)
  {
    acc = ((acc + (delta_87 * 2)) + 5) & 127;
    aux ^= delta_87 & 15;
  }
  else
  {
    acc = ((acc - delta_87) + 11) & 127;
    aux += 3;
  }
  int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000207_713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st_1 = {0};
  struct AudioFrame_R000207_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int margin_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_80_1) & 63;
  aux_2 = (aux_2 + margin_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_80_1 == margin_80_2);
}

int fn_R000207_713_21(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000207_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int margin_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st_1 = {0};
  struct StreamBuffer_R000207_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_72_1)
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

  switch (stride_72_2)
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
  int threshold_11_1 = local_arr_1[aux_1 % 3];
  int threshold_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_72_1 == stride_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_11_1 == threshold_11_2);
}

int fn_R000207_713_22(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000207_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_72 = (aux + st.buffer[1]) & 3;
  switch (stride_72)
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
  int threshold_11 = local_arr[aux % 3];
  acc = (acc + (threshold_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000207_713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st_1 = {0};
  struct FilterState_R000207_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_53_1 = local_arr_1[aux_1 % 3];
  int window_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_84_1 > 50)
  {
    acc_1 = ((acc_1 + (margin_84_1 * 2)) + 5) & 127;
    aux_1 ^= margin_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_84_2 > 50)
  {
    acc_2 = ((acc_2 + (margin_84_2 * 2)) + 5) & 127;
    aux_2 ^= margin_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_72_1) & 63;
  aux_2 = (aux_2 + bound_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_53_1 == window_53_2);
  assert(margin_84_1 == margin_84_2);
  assert(bound_72_1 == bound_72_2);
}

int fn_R000207_713_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000207_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int window_53 = local_arr[aux % 3];
  acc = (acc + (window_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_84 > 50)
  {
    acc = ((acc + (margin_84 * 2)) + 5) & 127;
    aux ^= margin_84 & 15;
  }
  else
  {
    acc = ((acc - margin_84) + 11) & 127;
    aux += 3;
  }
  int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000207_0_1;
  int sec_r000207_0_2;
  int sec_r000207_1_1;
  int sec_r000207_1_2;
  int sec_r000207_2_1;
  int sec_r000207_2_2;
  int sec_r000207_3_1;
  int sec_r000207_3_2;
  int sec_r000207_4_1;
  int sec_r000207_4_2;
  int sec_r000207_5_1;
  int sec_r000207_5_2;
  int sec_r000207_6_1;
  int sec_r000207_6_2;
  int sec_r000207_7_1;
  int sec_r000207_7_2;
  int sec_r000207_8_1;
  int sec_r000207_8_2;
  int sec_r000207_9_1;
  int sec_r000207_9_2;
  int sec_r000207_10_1;
  int sec_r000207_10_2;
  int sec_r000207_11_1;
  int sec_r000207_11_2;
  int sec_r000207_12_1;
  int sec_r000207_12_2;
  int sec_r000207_13_1;
  int sec_r000207_13_2;
  int sec_r000207_14_1;
  int sec_r000207_14_2;
  int sec_r000207_15_1;
  int sec_r000207_15_2;
  int sec_r000207_16_1;
  int sec_r000207_16_2;
  int sec_r000207_17_1;
  int sec_r000207_17_2;
  int sec_r000207_18_1;
  int sec_r000207_18_2;
  int sec_r000207_19_1;
  int sec_r000207_19_2;
  int pub_r000207_0_1;
  int pub_r000207_0_2;
  int pub_r000207_1_1;
  int pub_r000207_1_2;
  int pub_r000207_2_1;
  int pub_r000207_2_2;
  int pub_r000207_3_1;
  int pub_r000207_3_2;
  int pub_r000207_4_1;
  int pub_r000207_4_2;
  int pub_r000207_5_1;
  int pub_r000207_5_2;
  int pub_r000207_6_1;
  int pub_r000207_6_2;
  int pub_r000207_7_1;
  int pub_r000207_7_2;
  int pub_r000207_8_1;
  int pub_r000207_8_2;
  int pub_r000207_9_1;
  int pub_r000207_9_2;
  int pub_r000207_10_1;
  int pub_r000207_10_2;
  int pub_r000207_11_1;
  int pub_r000207_11_2;
  int pub_r000207_12_1;
  int pub_r000207_12_2;
  int pub_r000207_13_1;
  int pub_r000207_13_2;
  int pub_r000207_14_1;
  int pub_r000207_14_2;
  int pub_r000207_15_1;
  int pub_r000207_15_2;
  int pub_r000207_16_1;
  int pub_r000207_16_2;
  int pub_r000207_17_1;
  int pub_r000207_17_2;
  int pub_r000207_18_1;
  int pub_r000207_18_2;
  int pub_r000207_19_1;
  int pub_r000207_19_2;
  int pub_r000207_20_1;
  int pub_r000207_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000207_0_1 >= (-100)) && (pub_r000207_0_1 <= 100));
  __CPROVER_assume((pub_r000207_0_2 >= (-100)) && (pub_r000207_0_2 <= 100));
  __CPROVER_assume((pub_r000207_1_1 >= (-100)) && (pub_r000207_1_1 <= 100));
  __CPROVER_assume((pub_r000207_1_2 >= (-100)) && (pub_r000207_1_2 <= 100));
  __CPROVER_assume((pub_r000207_2_1 >= (-100)) && (pub_r000207_2_1 <= 100));
  __CPROVER_assume((pub_r000207_2_2 >= (-100)) && (pub_r000207_2_2 <= 100));
  __CPROVER_assume((pub_r000207_3_1 >= (-100)) && (pub_r000207_3_1 <= 100));
  __CPROVER_assume((pub_r000207_3_2 >= (-100)) && (pub_r000207_3_2 <= 100));
  __CPROVER_assume((pub_r000207_4_1 >= (-100)) && (pub_r000207_4_1 <= 100));
  __CPROVER_assume((pub_r000207_4_2 >= (-100)) && (pub_r000207_4_2 <= 100));
  __CPROVER_assume((pub_r000207_5_1 >= (-100)) && (pub_r000207_5_1 <= 100));
  __CPROVER_assume((pub_r000207_5_2 >= (-100)) && (pub_r000207_5_2 <= 100));
  __CPROVER_assume((pub_r000207_6_1 >= (-100)) && (pub_r000207_6_1 <= 100));
  __CPROVER_assume((pub_r000207_6_2 >= (-100)) && (pub_r000207_6_2 <= 100));
  __CPROVER_assume((pub_r000207_7_1 >= (-100)) && (pub_r000207_7_1 <= 100));
  __CPROVER_assume((pub_r000207_7_2 >= (-100)) && (pub_r000207_7_2 <= 100));
  __CPROVER_assume((pub_r000207_8_1 >= (-100)) && (pub_r000207_8_1 <= 100));
  __CPROVER_assume((pub_r000207_8_2 >= (-100)) && (pub_r000207_8_2 <= 100));
  __CPROVER_assume((pub_r000207_9_1 >= (-100)) && (pub_r000207_9_1 <= 100));
  __CPROVER_assume((pub_r000207_9_2 >= (-100)) && (pub_r000207_9_2 <= 100));
  __CPROVER_assume((pub_r000207_10_1 >= (-100)) && (pub_r000207_10_1 <= 100));
  __CPROVER_assume((pub_r000207_10_2 >= (-100)) && (pub_r000207_10_2 <= 100));
  __CPROVER_assume((pub_r000207_11_1 >= (-100)) && (pub_r000207_11_1 <= 100));
  __CPROVER_assume((pub_r000207_11_2 >= (-100)) && (pub_r000207_11_2 <= 100));
  __CPROVER_assume((pub_r000207_12_1 >= (-100)) && (pub_r000207_12_1 <= 100));
  __CPROVER_assume((pub_r000207_12_2 >= (-100)) && (pub_r000207_12_2 <= 100));
  __CPROVER_assume((pub_r000207_13_1 >= (-100)) && (pub_r000207_13_1 <= 100));
  __CPROVER_assume((pub_r000207_13_2 >= (-100)) && (pub_r000207_13_2 <= 100));
  __CPROVER_assume((pub_r000207_14_1 >= (-100)) && (pub_r000207_14_1 <= 100));
  __CPROVER_assume((pub_r000207_14_2 >= (-100)) && (pub_r000207_14_2 <= 100));
  __CPROVER_assume((pub_r000207_15_1 >= (-100)) && (pub_r000207_15_1 <= 100));
  __CPROVER_assume((pub_r000207_15_2 >= (-100)) && (pub_r000207_15_2 <= 100));
  __CPROVER_assume((pub_r000207_16_1 >= (-100)) && (pub_r000207_16_1 <= 100));
  __CPROVER_assume((pub_r000207_16_2 >= (-100)) && (pub_r000207_16_2 <= 100));
  __CPROVER_assume((pub_r000207_17_1 >= (-100)) && (pub_r000207_17_1 <= 100));
  __CPROVER_assume((pub_r000207_17_2 >= (-100)) && (pub_r000207_17_2 <= 100));
  __CPROVER_assume((pub_r000207_18_1 >= (-100)) && (pub_r000207_18_1 <= 100));
  __CPROVER_assume((pub_r000207_18_2 >= (-100)) && (pub_r000207_18_2 <= 100));
  __CPROVER_assume((pub_r000207_19_1 >= (-100)) && (pub_r000207_19_1 <= 100));
  __CPROVER_assume((pub_r000207_19_2 >= (-100)) && (pub_r000207_19_2 <= 100));
  __CPROVER_assume((pub_r000207_20_1 >= (-100)) && (pub_r000207_20_1 <= 100));
  __CPROVER_assume((pub_r000207_20_2 >= (-100)) && (pub_r000207_20_2 <= 100));
  __CPROVER_assume((sec_r000207_0_1 >= 0) && (sec_r000207_0_1 <= 255));
  __CPROVER_assume((sec_r000207_0_2 >= 0) && (sec_r000207_0_2 <= 255));
  __CPROVER_assume((sec_r000207_1_1 >= 0) && (sec_r000207_1_1 <= 255));
  __CPROVER_assume((sec_r000207_1_2 >= 0) && (sec_r000207_1_2 <= 255));
  __CPROVER_assume((sec_r000207_2_1 >= 0) && (sec_r000207_2_1 <= 255));
  __CPROVER_assume((sec_r000207_2_2 >= 0) && (sec_r000207_2_2 <= 255));
  __CPROVER_assume((sec_r000207_3_1 >= 0) && (sec_r000207_3_1 <= 255));
  __CPROVER_assume((sec_r000207_3_2 >= 0) && (sec_r000207_3_2 <= 255));
  __CPROVER_assume((sec_r000207_4_1 >= 0) && (sec_r000207_4_1 <= 255));
  __CPROVER_assume((sec_r000207_4_2 >= 0) && (sec_r000207_4_2 <= 255));
  __CPROVER_assume((sec_r000207_5_1 >= 0) && (sec_r000207_5_1 <= 255));
  __CPROVER_assume((sec_r000207_5_2 >= 0) && (sec_r000207_5_2 <= 255));
  __CPROVER_assume((sec_r000207_6_1 >= 0) && (sec_r000207_6_1 <= 255));
  __CPROVER_assume((sec_r000207_6_2 >= 0) && (sec_r000207_6_2 <= 255));
  __CPROVER_assume((sec_r000207_7_1 >= 0) && (sec_r000207_7_1 <= 255));
  __CPROVER_assume((sec_r000207_7_2 >= 0) && (sec_r000207_7_2 <= 255));
  __CPROVER_assume((sec_r000207_8_1 >= 0) && (sec_r000207_8_1 <= 255));
  __CPROVER_assume((sec_r000207_8_2 >= 0) && (sec_r000207_8_2 <= 255));
  __CPROVER_assume((sec_r000207_9_1 >= 0) && (sec_r000207_9_1 <= 255));
  __CPROVER_assume((sec_r000207_9_2 >= 0) && (sec_r000207_9_2 <= 255));
  __CPROVER_assume((sec_r000207_10_1 >= 0) && (sec_r000207_10_1 <= 255));
  __CPROVER_assume((sec_r000207_10_2 >= 0) && (sec_r000207_10_2 <= 255));
  __CPROVER_assume((sec_r000207_11_1 >= 0) && (sec_r000207_11_1 <= 255));
  __CPROVER_assume((sec_r000207_11_2 >= 0) && (sec_r000207_11_2 <= 255));
  __CPROVER_assume((sec_r000207_12_1 >= 0) && (sec_r000207_12_1 <= 255));
  __CPROVER_assume((sec_r000207_12_2 >= 0) && (sec_r000207_12_2 <= 255));
  __CPROVER_assume((sec_r000207_13_1 >= 0) && (sec_r000207_13_1 <= 255));
  __CPROVER_assume((sec_r000207_13_2 >= 0) && (sec_r000207_13_2 <= 255));
  __CPROVER_assume((sec_r000207_14_1 >= 0) && (sec_r000207_14_1 <= 255));
  __CPROVER_assume((sec_r000207_14_2 >= 0) && (sec_r000207_14_2 <= 255));
  __CPROVER_assume((sec_r000207_15_1 >= 0) && (sec_r000207_15_1 <= 255));
  __CPROVER_assume((sec_r000207_15_2 >= 0) && (sec_r000207_15_2 <= 255));
  __CPROVER_assume((sec_r000207_16_1 >= 0) && (sec_r000207_16_1 <= 255));
  __CPROVER_assume((sec_r000207_16_2 >= 0) && (sec_r000207_16_2 <= 255));
  __CPROVER_assume((sec_r000207_17_1 >= 0) && (sec_r000207_17_1 <= 255));
  __CPROVER_assume((sec_r000207_17_2 >= 0) && (sec_r000207_17_2 <= 255));
  __CPROVER_assume((sec_r000207_18_1 >= 0) && (sec_r000207_18_1 <= 255));
  __CPROVER_assume((sec_r000207_18_2 >= 0) && (sec_r000207_18_2 <= 255));
  __CPROVER_assume((sec_r000207_19_1 >= 0) && (sec_r000207_19_1 <= 255));
  __CPROVER_assume((sec_r000207_19_2 >= 0) && (sec_r000207_19_2 <= 255));
  struct FilterState_R000207_713_0 st_var_0_1 = {0};
  struct FilterState_R000207_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000207_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000207_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000207_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000207_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000207_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000207_0_2 + 7) & 15;
  struct AudioFrame_R000207_713_1 st_var_1_1 = {0};
  struct AudioFrame_R000207_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000207_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000207_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000207_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000207_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000207_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000207_0_2 + 9) & 15;
  struct StreamBuffer_R000207_713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000207_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000207_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000207_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000207_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000207_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000207_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000207_0_2 + 11) & 15;
  union RegisterBank_R000207_713_0 u_var_1;
  union RegisterBank_R000207_713_0 u_var_2;
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
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 46)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 46)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 26)
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
  if (stage_v_8_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 26)
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
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 17) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 47)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 47)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
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
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 52)
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
  if (stage_v_32_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 52)
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
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = ((st_var_2_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_2_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 38)
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
  if (stage_v_35_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 38)
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
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 42)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 42)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
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
  int stage_v_46_1 = ((st_var_1_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_1_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 33)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 33)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 38)
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
  if (stage_v_48_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 38)
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
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_1_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_1_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 34)
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
  if (stage_v_52_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 34)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000207_19_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((sec_r000207_19_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000207_9_1 & 1) != 0)
  {
    if ((sec_r000207_9_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((sec_r000207_9_2 & 1) != 0)
  {
    if ((sec_r000207_9_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000207_0_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000207_20_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000207_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000207_20_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000207_0_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000207_20_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000207_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000207_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000207_1_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000207_1_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000207_17_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000207_3_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000207_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000207_3_1 + 7) & 127;
  }
  if ((sec_r000207_17_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000207_3_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000207_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000207_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000207_4_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000207_2_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000207_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000207_2_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000207_4_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000207_2_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000207_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000207_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000207_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000207_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000207_12_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000207_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000207_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000207_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000207_3_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000207_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000207_3_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000207_3_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000207_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000207_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000207_6_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000207_6_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000207_13_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000207_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000207_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000207_13_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000207_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000207_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000207_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000207_17_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000207_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000207_17_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000207_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000207_17_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000207_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000207_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000207_1_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000207_1_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000207_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000207_1_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000207_1_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000207_1_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000207_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000207_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000207_19_1 & 1) != 0)
  {
    if ((sec_r000207_2_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((sec_r000207_19_2 & 1) != 0)
  {
    if ((sec_r000207_2_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000207_18_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000207_14_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000207_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000207_14_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000207_18_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000207_14_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000207_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000207_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000207_6_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000207_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000207_6_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000207_6_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000207_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000207_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000207_1_1 & 1) != 0)
  {
    if ((sec_r000207_19_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((sec_r000207_1_2 & 1) != 0)
  {
    if ((sec_r000207_19_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000207_14_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000207_8_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000207_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000207_8_1 + 7) & 127;
  }
  if ((sec_r000207_14_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000207_8_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000207_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000207_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000207_19_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000207_12_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000207_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000207_12_1 + 7) & 127;
  }
  if ((sec_r000207_19_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000207_12_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000207_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000207_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000207_14_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000207_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000207_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000207_14_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000207_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000207_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000207_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000207_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000207_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000207_7_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000207_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000207_7_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000207_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000207_7_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000207_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000207_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000207_19_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000207_3_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000207_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000207_3_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000207_19_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000207_3_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000207_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000207_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000207_7_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000207_10_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000207_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000207_10_1 + 7) & 127;
  }
  if ((sec_r000207_7_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000207_10_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000207_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000207_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000207_19_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000207_19_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000207_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000207_19_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000207_19_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000207_19_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000207_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000207_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000207_19_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000207_13_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000207_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000207_13_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000207_19_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000207_13_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000207_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000207_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000207_0_1 & 1) != 0)
  {
    if ((sec_r000207_13_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((sec_r000207_0_2 & 1) != 0)
  {
    if ((sec_r000207_13_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000207_15_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000207_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000207_15_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000207_15_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000207_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000207_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000207_18_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000207_18_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000207_12_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000207_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000207_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000207_10_1 + 7) & 127;
  }
  if ((sec_r000207_12_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000207_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000207_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000207_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000207_11_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((sec_r000207_11_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000207_17_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000207_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000207_17_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000207_17_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000207_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000207_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000207_6_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000207_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000207_6_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000207_6_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000207_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000207_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000207_8_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000207_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000207_8_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000207_8_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000207_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000207_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000207_4_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000207_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000207_4_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000207_4_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000207_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000207_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000207_0_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000207_18_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000207_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000207_18_1 + 7) & 127;
  }
  if ((sec_r000207_0_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000207_18_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000207_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000207_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000207_15_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000207_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000207_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000207_12_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000207_15_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000207_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000207_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000207_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000207_15_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((sec_r000207_15_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000207_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000207_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000207_0_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000207_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000207_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000207_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000207_11_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000207_6_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000207_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000207_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000207_11_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000207_6_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000207_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000207_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000207_14_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000207_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000207_14_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000207_14_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000207_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000207_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000207_8_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000207_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000207_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000207_4_1 + 7) & 127;
  }
  if ((sec_r000207_8_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000207_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000207_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000207_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000207_6_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000207_6_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000207_9_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000207_3_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000207_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000207_3_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000207_9_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000207_3_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000207_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000207_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000207_14_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000207_14_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000207_11_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((sec_r000207_11_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000207_8_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000207_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000207_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000207_8_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000207_8_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000207_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000207_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000207_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000207_2_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000207_2_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000207_12_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000207_12_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000207_19_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000207_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000207_19_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000207_19_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000207_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000207_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000207_14_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000207_14_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000207_9_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000207_9_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000207_1_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000207_11_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000207_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000207_11_1 + 7) & 127;
  }
  if ((sec_r000207_1_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000207_11_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000207_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000207_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000207_10_1 & 1) != 0)
  {
    if ((sec_r000207_15_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000207_2_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000207_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000207_2_1 + 7) & 127;
  }
  if ((sec_r000207_10_2 & 1) != 0)
  {
    if ((sec_r000207_15_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000207_2_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000207_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000207_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000207_8_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000207_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000207_8_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000207_8_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000207_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000207_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000207_14_1 & 1) != 0)
  {
    if ((sec_r000207_0_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000207_20_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000207_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000207_20_1 + 7) & 127;
  }
  if ((sec_r000207_14_2 & 1) != 0)
  {
    if ((sec_r000207_0_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000207_20_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000207_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000207_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000207_2_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000207_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000207_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000207_5_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000207_2_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000207_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000207_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000207_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000207_4_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000207_3_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000207_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000207_3_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000207_4_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000207_3_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000207_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000207_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000207_17_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000207_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000207_17_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000207_17_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000207_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000207_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000207_2_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000207_11_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000207_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000207_11_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000207_2_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000207_11_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000207_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000207_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000207_11_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000207_18_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000207_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000207_18_1 + 7) & 127;
  }
  if ((sec_r000207_11_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000207_18_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000207_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000207_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000207_7_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000207_13_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000207_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000207_13_1 + 7) & 127;
  }
  if ((sec_r000207_7_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000207_13_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000207_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000207_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000207_12_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000207_5_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000207_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000207_5_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000207_12_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000207_5_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000207_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000207_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000207_2_1 & 1) != 0)
  {
    if ((sec_r000207_10_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000207_15_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000207_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000207_15_1 + 7) & 127;
  }
  if ((sec_r000207_2_2 & 1) != 0)
  {
    if ((sec_r000207_10_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000207_15_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000207_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000207_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000207_9_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000207_15_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000207_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000207_15_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000207_9_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000207_15_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000207_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000207_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000207_15_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000207_7_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000207_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000207_7_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000207_15_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000207_7_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000207_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000207_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000207_1_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000207_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000207_1_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000207_1_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000207_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000207_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000207_6_1 & 1) != 0)
  {
    if ((sec_r000207_5_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000207_18_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000207_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000207_18_1 + 7) & 127;
  }
  if ((sec_r000207_6_2 & 1) != 0)
  {
    if ((sec_r000207_5_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000207_18_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000207_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000207_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000207_19_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000207_9_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000207_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000207_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000207_19_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000207_9_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000207_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000207_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000207_16_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000207_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000207_16_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000207_16_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000207_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000207_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000207_3_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000207_13_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000207_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000207_13_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000207_3_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000207_13_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000207_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000207_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000207_16_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000207_4_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000207_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000207_4_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000207_16_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000207_4_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000207_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000207_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000207_0_1 & 1) != 0)
  {
    if ((sec_r000207_1_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000207_4_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000207_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000207_4_1 + 7) & 127;
  }
  if ((sec_r000207_0_2 & 1) != 0)
  {
    if ((sec_r000207_1_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000207_4_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000207_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000207_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000207_18_1 == pub_r000207_18_2);
  __CPROVER_assume(sec_r000207_2_1 != sec_r000207_2_2);
  __CPROVER_assume(sec_r000207_9_1 != sec_r000207_9_2);
  __CPROVER_assume(pub_r000207_10_1 == pub_r000207_10_2);
  __CPROVER_assume(sec_r000207_7_1 != sec_r000207_7_2);
  __CPROVER_assume(pub_r000207_2_1 == pub_r000207_2_2);
  __CPROVER_assume(pub_r000207_7_1 == pub_r000207_7_2);
  __CPROVER_assume(sec_r000207_5_1 != sec_r000207_5_2);
  __CPROVER_assume(pub_r000207_11_1 == pub_r000207_11_2);
  __CPROVER_assume(pub_r000207_9_1 == pub_r000207_9_2);
  __CPROVER_assume(pub_r000207_20_1 == pub_r000207_20_2);
  __CPROVER_assume(sec_r000207_14_1 != sec_r000207_14_2);
  __CPROVER_assume(pub_r000207_0_1 == pub_r000207_0_2);
  __CPROVER_assume(pub_r000207_17_1 == pub_r000207_17_2);
  __CPROVER_assume(sec_r000207_11_1 != sec_r000207_11_2);
  __CPROVER_assume(sec_r000207_12_1 != sec_r000207_12_2);
  __CPROVER_assume(pub_r000207_19_1 == pub_r000207_19_2);
  __CPROVER_assume(sec_r000207_1_1 != sec_r000207_1_2);
  __CPROVER_assume(pub_r000207_4_1 == pub_r000207_4_2);
  __CPROVER_assume(sec_r000207_15_1 != sec_r000207_15_2);
  __CPROVER_assume(sec_r000207_3_1 != sec_r000207_3_2);
  __CPROVER_assume(sec_r000207_0_1 != sec_r000207_0_2);
  __CPROVER_assume(pub_r000207_3_1 == pub_r000207_3_2);
  __CPROVER_assume(pub_r000207_8_1 == pub_r000207_8_2);
  __CPROVER_assume(pub_r000207_16_1 == pub_r000207_16_2);
  __CPROVER_assume(pub_r000207_12_1 == pub_r000207_12_2);
  __CPROVER_assume(pub_r000207_15_1 == pub_r000207_15_2);
  __CPROVER_assume(pub_r000207_6_1 == pub_r000207_6_2);
  __CPROVER_assume(sec_r000207_10_1 != sec_r000207_10_2);
  __CPROVER_assume(pub_r000207_14_1 == pub_r000207_14_2);
  __CPROVER_assume(pub_r000207_5_1 == pub_r000207_5_2);
  __CPROVER_assume(sec_r000207_6_1 != sec_r000207_6_2);
  __CPROVER_assume(sec_r000207_4_1 != sec_r000207_4_2);
  __CPROVER_assume(sec_r000207_8_1 != sec_r000207_8_2);
  __CPROVER_assume(sec_r000207_16_1 != sec_r000207_16_2);
  __CPROVER_assume(sec_r000207_19_1 != sec_r000207_19_2);
  __CPROVER_assume(sec_r000207_13_1 != sec_r000207_13_2);
  __CPROVER_assume(sec_r000207_18_1 != sec_r000207_18_2);
  __CPROVER_assume(pub_r000207_13_1 == pub_r000207_13_2);
  __CPROVER_assume(pub_r000207_1_1 == pub_r000207_1_2);
  __CPROVER_assume(sec_r000207_17_1 != sec_r000207_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.tail == st_var_2_2.tail);
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
}


