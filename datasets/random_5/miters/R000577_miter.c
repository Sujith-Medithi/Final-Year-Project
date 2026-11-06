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
struct FilterState_R000577_7713_0
{
  int prev_out;
  short damping;
  unsigned char mode;
  int cutoff;
  short gain_db;
  int buffer[3];
};
struct StreamBuffer_R000577_7713_1
{
  unsigned char checksum;
  int watermark;
  unsigned char head;
  int state;
  int tail;
  int capacity;
  int buffer[3];
};
struct EventLog_R000577_7713_2
{
  short severity;
  unsigned char facility;
  unsigned char timestamp;
  int buffer[3];
};
union PacketPayload_R000577_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000577_7713_1
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
void fn_R000577_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_20_1 > 43)
  {
    acc_1 = ((acc_1 + (offset_20_1 * 2)) + 5) & 127;
    aux_1 ^= offset_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_20_2 > 43)
  {
    acc_2 = ((acc_2 + (offset_20_2 * 2)) + 5) & 127;
    aux_2 ^= offset_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_32_1 = local_arr_1[aux_1 % 3];
  int margin_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_32_2 * 2)) & 127;
  int cursor_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_43_1) & 63;
  aux_2 = (aux_2 + cursor_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_37_1)
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

  switch (index_reg_37_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_20_1 == offset_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_32_1 == margin_32_2);
  assert(cursor_43_1 == cursor_43_2);
  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R000577_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_20 > 43)
  {
    acc = ((acc + (offset_20 * 2)) + 5) & 127;
    aux ^= offset_20 & 15;
  }
  else
  {
    acc = ((acc - offset_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_32 = local_arr[aux % 3];
  acc = (acc + (margin_32 * 2)) & 127;
  int cursor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_43) & 63;
  acc ^= aux;
  int index_reg_37 = (aux + st.buffer[1]) & 3;
  switch (index_reg_37)
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

void fn_R000577_7713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_40_1) & 63;
  aux_2 = (aux_2 + cursor_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_95_1)
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

  switch (bound_95_2)
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
  int segment_76_1 = local_arr_1[aux_1 % 3];
  int segment_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_40_1 == cursor_40_2);
  assert(bound_95_1 == bound_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_76_1 == segment_76_2);
}

int fn_R000577_7713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_40) & 63;
  acc ^= aux;
  int bound_95 = (aux + st.buffer[1]) & 3;
  switch (bound_95)
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
  int segment_76 = local_arr[aux % 3];
  acc = (acc + (segment_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int phase_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_64_1 > 32)
  {
    acc_1 = ((acc_1 + (phase_64_1 * 2)) + 5) & 127;
    aux_1 ^= phase_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_64_2 > 32)
  {
    acc_2 = ((acc_2 + (phase_64_2 * 2)) + 5) & 127;
    aux_2 ^= phase_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_69_1 = local_arr_1[aux_1 % 3];
  int quotient_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_64_1 == phase_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_69_1 == quotient_69_2);
}

int fn_R000577_7713_2(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int phase_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_64 > 32)
  {
    acc = ((acc + (phase_64 * 2)) + 5) & 127;
    aux ^= phase_64 & 15;
  }
  else
  {
    acc = ((acc - phase_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_69 = local_arr[aux % 3];
  acc = (acc + (quotient_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_65_1)
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

  switch (factor_65_2)
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

  int pivot_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_96_1) & 63;
  aux_2 = (aux_2 + pivot_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_95_1 = local_arr_1[aux_1 % 3];
  int vector_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_65_1 == factor_65_2);
  assert(pivot_96_1 == pivot_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_95_1 == vector_95_2);
}

int fn_R000577_7713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_65 = (aux + st.buffer[1]) & 3;
  switch (factor_65)
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

  int pivot_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_95 = local_arr[aux % 3];
  acc = (acc + (vector_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int residue_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_24_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_24_1 * 2)) + 5) & 127;
    aux_1 ^= residue_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_24_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_24_2 * 2)) + 5) & 127;
    aux_2 ^= residue_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_39_1) & 63;
  aux_2 = (aux_2 + quantum_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_24_1 == residue_24_2);
  assert(quantum_39_1 == quantum_39_2);
}

int fn_R000577_7713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int residue_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_24 > 34)
  {
    acc = ((acc + (residue_24 * 2)) + 5) & 127;
    aux ^= residue_24 & 15;
  }
  else
  {
    acc = ((acc - residue_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000577_7713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int window_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_81_1)
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

  switch (window_81_2)
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
  int index_reg_46_1 = local_arr_1[aux_1 % 3];
  int index_reg_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_81_1 == window_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_46_1 == index_reg_46_2);
}

int fn_R000577_7713_5(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int window_81 = (aux + st.buffer[1]) & 3;
  switch (window_81)
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
  int index_reg_46 = local_arr[aux % 3];
  acc = (acc + (index_reg_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_26_1)
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

  switch (window_26_2)
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
  int accumulator_18_1 = local_arr_1[aux_1 % 3];
  int accumulator_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_18_2 * 2)) & 127;
  int damping_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_91_1) & 63;
  aux_2 = (aux_2 + damping_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_26_1 == window_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  assert(damping_91_1 == damping_91_2);
}

int fn_R000577_7713_6(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_26 = (aux + st.buffer[1]) & 3;
  switch (window_26)
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
  int accumulator_18 = local_arr[aux % 3];
  acc = (acc + (accumulator_18 * 2)) & 127;
  int damping_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000577_7713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_93_1) & 63;
  aux_2 = (aux_2 + anchor_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_92_1)
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

  switch (factor_92_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_93_1 == anchor_93_2);
  assert(factor_92_1 == factor_92_2);
}

int fn_R000577_7713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_93) & 63;
  acc ^= aux;
  int factor_92 = (aux + st.buffer[1]) & 3;
  switch (factor_92)
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
  return (acc + aux) & 255;
}

void fn_R000577_7713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_47_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_47_1 * 2)) + 5) & 127;
    aux_1 ^= delta_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_47_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_47_2 * 2)) + 5) & 127;
    aux_2 ^= delta_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_47_1 == delta_47_2);
}

int fn_R000577_7713_8(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_47 > 46)
  {
    acc = ((acc + (delta_47 * 2)) + 5) & 127;
    aux ^= delta_47 & 15;
  }
  else
  {
    acc = ((acc - delta_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000577_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int residue_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_93_1) & 63;
  aux_2 = (aux_2 + residue_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_39_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_39_1 * 2)) + 5) & 127;
    aux_1 ^= damping_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_39_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_39_2 * 2)) + 5) & 127;
    aux_2 ^= damping_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_93_1 == residue_93_2);
  assert(damping_39_1 == damping_39_2);
}

int fn_R000577_7713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int residue_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_93) & 63;
  acc ^= aux;
  int damping_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_39 > 31)
  {
    acc = ((acc + (damping_39 * 2)) + 5) & 127;
    aux ^= damping_39 & 15;
  }
  else
  {
    acc = ((acc - damping_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000577_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st_1 = {0};
  struct FilterState_R000577_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int bound_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_32_1)
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

  switch (bound_32_2)
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
  int phase_93_1 = local_arr_1[aux_1 % 3];
  int phase_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_93_2 * 2)) & 127;
  int delta_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_54_1 > 39)
  {
    acc_1 = ((acc_1 + (delta_54_1 * 2)) + 5) & 127;
    aux_1 ^= delta_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_54_2 > 39)
  {
    acc_2 = ((acc_2 + (delta_54_2 * 2)) + 5) & 127;
    aux_2 ^= delta_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_54_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_32_1 == bound_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_93_1 == phase_93_2);
  assert(delta_54_1 == delta_54_2);
}

int fn_R000577_7713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int bound_32 = (aux + st.buffer[1]) & 3;
  switch (bound_32)
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
  int phase_93 = local_arr[aux % 3];
  acc = (acc + (phase_93 * 2)) & 127;
  int delta_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_54 > 39)
  {
    acc = ((acc + (delta_54 * 2)) + 5) & 127;
    aux ^= delta_54 & 15;
  }
  else
  {
    acc = ((acc - delta_54) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_57_1 = local_arr_1[aux_1 % 3];
  int threshold_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_57_2 * 2)) & 127;
  int tracker_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_91_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_91_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_91_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_91_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_57_1 == threshold_57_2);
  assert(tracker_91_1 == tracker_91_2);
}

int fn_R000577_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_57 = local_arr[aux % 3];
  acc = (acc + (threshold_57 * 2)) & 127;
  int tracker_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_91 > 47)
  {
    acc = ((acc + (tracker_91 * 2)) + 5) & 127;
    aux ^= tracker_91 & 15;
  }
  else
  {
    acc = ((acc - tracker_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000577_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int window_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_90_1)
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

  switch (window_90_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_90_1 == window_90_2);
}

int fn_R000577_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int window_90 = (aux + st.buffer[1]) & 3;
  switch (window_90)
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

void fn_R000577_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_81_1 = local_arr_1[aux_1 % 3];
  int index_reg_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_81_2 * 2)) & 127;
  int residue_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_50_1)
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

  switch (residue_50_2)
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

  int window_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_74_1) & 63;
  aux_2 = (aux_2 + window_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_81_1 == index_reg_81_2);
  assert(residue_50_1 == residue_50_2);
  assert(window_74_1 == window_74_2);
}

int fn_R000577_7713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int index_reg_81 = local_arr[aux % 3];
  acc = (acc + (index_reg_81 * 2)) & 127;
  int residue_50 = (aux + st.buffer[1]) & 3;
  switch (residue_50)
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

  int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_84_1)
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

  switch (margin_84_2)
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

  int margin_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_88_1 > 18)
  {
    acc_1 = ((acc_1 + (margin_88_1 * 2)) + 5) & 127;
    aux_1 ^= margin_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_88_2 > 18)
  {
    acc_2 = ((acc_2 + (margin_88_2 * 2)) + 5) & 127;
    aux_2 ^= margin_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_88_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_84_1 == margin_84_2);
  assert(margin_88_1 == margin_88_2);
}

int fn_R000577_7713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_84 = (aux + st.buffer[1]) & 3;
  switch (margin_84)
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

  int margin_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_88 > 18)
  {
    acc = ((acc + (margin_88 * 2)) + 5) & 127;
    aux ^= margin_88 & 15;
  }
  else
  {
    acc = ((acc - margin_88) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000577_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_45_1 = local_arr_1[aux_1 % 3];
  int accumulator_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_45_2 * 2)) & 127;
  int quantum_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_56_1 > 41)
  {
    acc_1 = ((acc_1 + (quantum_56_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_56_2 > 41)
  {
    acc_2 = ((acc_2 + (quantum_56_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_89_1) & 63;
  aux_2 = (aux_2 + anchor_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_45_1 == accumulator_45_2);
  assert(quantum_56_1 == quantum_56_2);
  assert(anchor_89_1 == anchor_89_2);
}

int fn_R000577_7713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int accumulator_45 = local_arr[aux % 3];
  acc = (acc + (accumulator_45 * 2)) & 127;
  int quantum_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_56 > 41)
  {
    acc = ((acc + (quantum_56 * 2)) + 5) & 127;
    aux ^= quantum_56 & 15;
  }
  else
  {
    acc = ((acc - quantum_56) + 11) & 127;
    aux += 3;
  }
  int anchor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000577_7713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_44_1 = local_arr_1[aux_1 % 3];
  int margin_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_44_2 * 2)) & 127;
  int quantum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_75_1)
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

  switch (quantum_75_2)
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

  int phase_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_49_1 > 30)
  {
    acc_1 = ((acc_1 + (phase_49_1 * 2)) + 5) & 127;
    aux_1 ^= phase_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_49_2 > 30)
  {
    acc_2 = ((acc_2 + (phase_49_2 * 2)) + 5) & 127;
    aux_2 ^= phase_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(quantum_75_1 == quantum_75_2);
  assert(phase_49_1 == phase_49_2);
}

int fn_R000577_7713_16(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_44 = local_arr[aux % 3];
  acc = (acc + (margin_44 * 2)) & 127;
  int quantum_75 = (aux + st.buffer[1]) & 3;
  switch (quantum_75)
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

  int phase_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_49 > 30)
  {
    acc = ((acc + (phase_49 * 2)) + 5) & 127;
    aux ^= phase_49 & 15;
  }
  else
  {
    acc = ((acc - phase_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000577_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st_1 = {0};
  struct FilterState_R000577_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_26_1 = local_arr_1[aux_1 % 3];
  int factor_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_26_2 * 2)) & 127;
  int weight_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_56_1)
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

  switch (weight_56_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
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

  assert(factor_26_1 == factor_26_2);
  assert(weight_56_1 == weight_56_2);
}

int fn_R000577_7713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int factor_26 = local_arr[aux % 3];
  acc = (acc + (factor_26 * 2)) & 127;
  int weight_56 = (aux + st.buffer[1]) & 3;
  switch (weight_56)
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

void fn_R000577_7713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tracker_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_82_1)
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

  switch (tracker_82_2)
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

  int offset_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_71_1) & 63;
  aux_2 = (aux_2 + offset_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_40_1 > 15)
  {
    acc_1 = ((acc_1 + (segment_40_1 * 2)) + 5) & 127;
    aux_1 ^= segment_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_40_2 > 15)
  {
    acc_2 = ((acc_2 + (segment_40_2 * 2)) + 5) & 127;
    aux_2 ^= segment_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_82_1 == tracker_82_2);
  assert(offset_71_1 == offset_71_2);
  assert(segment_40_1 == segment_40_2);
}

int fn_R000577_7713_18(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000577_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tracker_82 = (aux + st.buffer[1]) & 3;
  switch (tracker_82)
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

  int offset_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_71) & 63;
  acc ^= aux;
  int segment_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_40 > 15)
  {
    acc = ((acc + (segment_40 * 2)) + 5) & 127;
    aux ^= segment_40 & 15;
  }
  else
  {
    acc = ((acc - segment_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000577_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st_1 = {0};
  struct FilterState_R000577_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_86_1 > 30)
  {
    acc_1 = ((acc_1 + (coefficient_86_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_86_2 > 30)
  {
    acc_2 = ((acc_2 + (coefficient_86_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_12_1)
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

  switch (pivot_12_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_86_1 == coefficient_86_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R000577_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000577_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_86 > 30)
  {
    acc = ((acc + (coefficient_86 * 2)) + 5) & 127;
    aux ^= coefficient_86 & 15;
  }
  else
  {
    acc = ((acc - coefficient_86) + 11) & 127;
    aux += 3;
  }
  int pivot_12 = (aux + st.buffer[1]) & 3;
  switch (pivot_12)
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

void fn_R000577_7713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st_1 = {0};
  struct EventLog_R000577_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_10_1 > 38)
  {
    acc_1 = ((acc_1 + (vector_10_1 * 2)) + 5) & 127;
    aux_1 ^= vector_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_10_2 > 38)
  {
    acc_2 = ((acc_2 + (vector_10_2 * 2)) + 5) & 127;
    aux_2 ^= vector_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_84_1 = local_arr_1[aux_1 % 3];
  int factor_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_10_1 == vector_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_84_1 == factor_84_2);
}

int fn_R000577_7713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000577_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_10 > 38)
  {
    acc = ((acc + (vector_10 * 2)) + 5) & 127;
    aux ^= vector_10 & 15;
  }
  else
  {
    acc = ((acc - vector_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_84 = local_arr[aux % 3];
  acc = (acc + (factor_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000577_0_1;
  int sec_r000577_0_2;
  int sec_r000577_1_1;
  int sec_r000577_1_2;
  int sec_r000577_2_1;
  int sec_r000577_2_2;
  int sec_r000577_3_1;
  int sec_r000577_3_2;
  int sec_r000577_4_1;
  int sec_r000577_4_2;
  int sec_r000577_5_1;
  int sec_r000577_5_2;
  int sec_r000577_6_1;
  int sec_r000577_6_2;
  int sec_r000577_7_1;
  int sec_r000577_7_2;
  int sec_r000577_8_1;
  int sec_r000577_8_2;
  int sec_r000577_9_1;
  int sec_r000577_9_2;
  int sec_r000577_10_1;
  int sec_r000577_10_2;
  int sec_r000577_11_1;
  int sec_r000577_11_2;
  int sec_r000577_12_1;
  int sec_r000577_12_2;
  int sec_r000577_13_1;
  int sec_r000577_13_2;
  int sec_r000577_14_1;
  int sec_r000577_14_2;
  int sec_r000577_15_1;
  int sec_r000577_15_2;
  int sec_r000577_16_1;
  int sec_r000577_16_2;
  int sec_r000577_17_1;
  int sec_r000577_17_2;
  int pub_r000577_0_1;
  int pub_r000577_0_2;
  int pub_r000577_1_1;
  int pub_r000577_1_2;
  int pub_r000577_2_1;
  int pub_r000577_2_2;
  int pub_r000577_3_1;
  int pub_r000577_3_2;
  int pub_r000577_4_1;
  int pub_r000577_4_2;
  int pub_r000577_5_1;
  int pub_r000577_5_2;
  int pub_r000577_6_1;
  int pub_r000577_6_2;
  int pub_r000577_7_1;
  int pub_r000577_7_2;
  int pub_r000577_8_1;
  int pub_r000577_8_2;
  int pub_r000577_9_1;
  int pub_r000577_9_2;
  int pub_r000577_10_1;
  int pub_r000577_10_2;
  int pub_r000577_11_1;
  int pub_r000577_11_2;
  int pub_r000577_12_1;
  int pub_r000577_12_2;
  int pub_r000577_13_1;
  int pub_r000577_13_2;
  int pub_r000577_14_1;
  int pub_r000577_14_2;
  int pub_r000577_15_1;
  int pub_r000577_15_2;
  int pub_r000577_16_1;
  int pub_r000577_16_2;
  int pub_r000577_17_1;
  int pub_r000577_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000577_0_1 >= (-100)) && (pub_r000577_0_1 <= 100));
  __CPROVER_assume((pub_r000577_0_2 >= (-100)) && (pub_r000577_0_2 <= 100));
  __CPROVER_assume((pub_r000577_1_1 >= (-100)) && (pub_r000577_1_1 <= 100));
  __CPROVER_assume((pub_r000577_1_2 >= (-100)) && (pub_r000577_1_2 <= 100));
  __CPROVER_assume((pub_r000577_2_1 >= (-100)) && (pub_r000577_2_1 <= 100));
  __CPROVER_assume((pub_r000577_2_2 >= (-100)) && (pub_r000577_2_2 <= 100));
  __CPROVER_assume((pub_r000577_3_1 >= (-100)) && (pub_r000577_3_1 <= 100));
  __CPROVER_assume((pub_r000577_3_2 >= (-100)) && (pub_r000577_3_2 <= 100));
  __CPROVER_assume((pub_r000577_4_1 >= (-100)) && (pub_r000577_4_1 <= 100));
  __CPROVER_assume((pub_r000577_4_2 >= (-100)) && (pub_r000577_4_2 <= 100));
  __CPROVER_assume((pub_r000577_5_1 >= (-100)) && (pub_r000577_5_1 <= 100));
  __CPROVER_assume((pub_r000577_5_2 >= (-100)) && (pub_r000577_5_2 <= 100));
  __CPROVER_assume((pub_r000577_6_1 >= (-100)) && (pub_r000577_6_1 <= 100));
  __CPROVER_assume((pub_r000577_6_2 >= (-100)) && (pub_r000577_6_2 <= 100));
  __CPROVER_assume((pub_r000577_7_1 >= (-100)) && (pub_r000577_7_1 <= 100));
  __CPROVER_assume((pub_r000577_7_2 >= (-100)) && (pub_r000577_7_2 <= 100));
  __CPROVER_assume((pub_r000577_8_1 >= (-100)) && (pub_r000577_8_1 <= 100));
  __CPROVER_assume((pub_r000577_8_2 >= (-100)) && (pub_r000577_8_2 <= 100));
  __CPROVER_assume((pub_r000577_9_1 >= (-100)) && (pub_r000577_9_1 <= 100));
  __CPROVER_assume((pub_r000577_9_2 >= (-100)) && (pub_r000577_9_2 <= 100));
  __CPROVER_assume((pub_r000577_10_1 >= (-100)) && (pub_r000577_10_1 <= 100));
  __CPROVER_assume((pub_r000577_10_2 >= (-100)) && (pub_r000577_10_2 <= 100));
  __CPROVER_assume((pub_r000577_11_1 >= (-100)) && (pub_r000577_11_1 <= 100));
  __CPROVER_assume((pub_r000577_11_2 >= (-100)) && (pub_r000577_11_2 <= 100));
  __CPROVER_assume((pub_r000577_12_1 >= (-100)) && (pub_r000577_12_1 <= 100));
  __CPROVER_assume((pub_r000577_12_2 >= (-100)) && (pub_r000577_12_2 <= 100));
  __CPROVER_assume((pub_r000577_13_1 >= (-100)) && (pub_r000577_13_1 <= 100));
  __CPROVER_assume((pub_r000577_13_2 >= (-100)) && (pub_r000577_13_2 <= 100));
  __CPROVER_assume((pub_r000577_14_1 >= (-100)) && (pub_r000577_14_1 <= 100));
  __CPROVER_assume((pub_r000577_14_2 >= (-100)) && (pub_r000577_14_2 <= 100));
  __CPROVER_assume((pub_r000577_15_1 >= (-100)) && (pub_r000577_15_1 <= 100));
  __CPROVER_assume((pub_r000577_15_2 >= (-100)) && (pub_r000577_15_2 <= 100));
  __CPROVER_assume((pub_r000577_16_1 >= (-100)) && (pub_r000577_16_1 <= 100));
  __CPROVER_assume((pub_r000577_16_2 >= (-100)) && (pub_r000577_16_2 <= 100));
  __CPROVER_assume((pub_r000577_17_1 >= (-100)) && (pub_r000577_17_1 <= 100));
  __CPROVER_assume((pub_r000577_17_2 >= (-100)) && (pub_r000577_17_2 <= 100));
  __CPROVER_assume((sec_r000577_0_1 >= 0) && (sec_r000577_0_1 <= 255));
  __CPROVER_assume((sec_r000577_0_2 >= 0) && (sec_r000577_0_2 <= 255));
  __CPROVER_assume((sec_r000577_1_1 >= 0) && (sec_r000577_1_1 <= 255));
  __CPROVER_assume((sec_r000577_1_2 >= 0) && (sec_r000577_1_2 <= 255));
  __CPROVER_assume((sec_r000577_2_1 >= 0) && (sec_r000577_2_1 <= 255));
  __CPROVER_assume((sec_r000577_2_2 >= 0) && (sec_r000577_2_2 <= 255));
  __CPROVER_assume((sec_r000577_3_1 >= 0) && (sec_r000577_3_1 <= 255));
  __CPROVER_assume((sec_r000577_3_2 >= 0) && (sec_r000577_3_2 <= 255));
  __CPROVER_assume((sec_r000577_4_1 >= 0) && (sec_r000577_4_1 <= 255));
  __CPROVER_assume((sec_r000577_4_2 >= 0) && (sec_r000577_4_2 <= 255));
  __CPROVER_assume((sec_r000577_5_1 >= 0) && (sec_r000577_5_1 <= 255));
  __CPROVER_assume((sec_r000577_5_2 >= 0) && (sec_r000577_5_2 <= 255));
  __CPROVER_assume((sec_r000577_6_1 >= 0) && (sec_r000577_6_1 <= 255));
  __CPROVER_assume((sec_r000577_6_2 >= 0) && (sec_r000577_6_2 <= 255));
  __CPROVER_assume((sec_r000577_7_1 >= 0) && (sec_r000577_7_1 <= 255));
  __CPROVER_assume((sec_r000577_7_2 >= 0) && (sec_r000577_7_2 <= 255));
  __CPROVER_assume((sec_r000577_8_1 >= 0) && (sec_r000577_8_1 <= 255));
  __CPROVER_assume((sec_r000577_8_2 >= 0) && (sec_r000577_8_2 <= 255));
  __CPROVER_assume((sec_r000577_9_1 >= 0) && (sec_r000577_9_1 <= 255));
  __CPROVER_assume((sec_r000577_9_2 >= 0) && (sec_r000577_9_2 <= 255));
  __CPROVER_assume((sec_r000577_10_1 >= 0) && (sec_r000577_10_1 <= 255));
  __CPROVER_assume((sec_r000577_10_2 >= 0) && (sec_r000577_10_2 <= 255));
  __CPROVER_assume((sec_r000577_11_1 >= 0) && (sec_r000577_11_1 <= 255));
  __CPROVER_assume((sec_r000577_11_2 >= 0) && (sec_r000577_11_2 <= 255));
  __CPROVER_assume((sec_r000577_12_1 >= 0) && (sec_r000577_12_1 <= 255));
  __CPROVER_assume((sec_r000577_12_2 >= 0) && (sec_r000577_12_2 <= 255));
  __CPROVER_assume((sec_r000577_13_1 >= 0) && (sec_r000577_13_1 <= 255));
  __CPROVER_assume((sec_r000577_13_2 >= 0) && (sec_r000577_13_2 <= 255));
  __CPROVER_assume((sec_r000577_14_1 >= 0) && (sec_r000577_14_1 <= 255));
  __CPROVER_assume((sec_r000577_14_2 >= 0) && (sec_r000577_14_2 <= 255));
  __CPROVER_assume((sec_r000577_15_1 >= 0) && (sec_r000577_15_1 <= 255));
  __CPROVER_assume((sec_r000577_15_2 >= 0) && (sec_r000577_15_2 <= 255));
  __CPROVER_assume((sec_r000577_16_1 >= 0) && (sec_r000577_16_1 <= 255));
  __CPROVER_assume((sec_r000577_16_2 >= 0) && (sec_r000577_16_2 <= 255));
  __CPROVER_assume((sec_r000577_17_1 >= 0) && (sec_r000577_17_1 <= 255));
  __CPROVER_assume((sec_r000577_17_2 >= 0) && (sec_r000577_17_2 <= 255));
  struct FilterState_R000577_7713_0 st_var_0_1 = {0};
  struct FilterState_R000577_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000577_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000577_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000577_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000577_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000577_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000577_0_2 + 7) & 15;
  struct StreamBuffer_R000577_7713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000577_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000577_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000577_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000577_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000577_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000577_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000577_0_2 + 9) & 15;
  struct EventLog_R000577_7713_2 st_var_2_1 = {0};
  struct EventLog_R000577_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000577_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000577_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000577_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000577_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000577_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000577_0_2 + 11) & 15;
  union PacketPayload_R000577_7713_0 u_var_1;
  union PacketPayload_R000577_7713_0 u_var_2;
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
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 43)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 43)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 28)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 28)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 27)
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
  if (stage_v_18_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 27)
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
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 35)
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
  if (stage_v_28_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 35)
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
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 26)
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
  if (stage_v_38_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 26)
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
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 29)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 29)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000577_4_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((sec_r000577_4_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000577_17_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000577_2_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000577_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000577_2_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000577_17_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000577_2_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000577_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000577_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000577_3_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000577_2_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000577_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000577_2_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000577_3_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000577_2_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000577_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000577_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000577_9_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000577_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000577_9_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000577_9_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000577_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000577_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000577_4_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000577_9_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000577_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000577_9_1 + 7) & 127;
  }
  if ((sec_r000577_4_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000577_9_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000577_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000577_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000577_9_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000577_2_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000577_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000577_2_1 + 7) & 127;
  }
  if ((sec_r000577_9_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000577_2_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000577_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000577_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000577_6_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((sec_r000577_6_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000577_0_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000577_8_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000577_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000577_8_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000577_0_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000577_8_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000577_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000577_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000577_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000577_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000577_16_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000577_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000577_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000577_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000577_9_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((sec_r000577_9_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000577_4_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000577_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000577_4_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000577_4_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000577_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000577_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000577_11_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((sec_r000577_11_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000577_3_1 & 1) != 0)
  {
    if ((sec_r000577_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000577_3_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000577_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000577_3_1 + 7) & 127;
  }
  if ((sec_r000577_3_2 & 1) != 0)
  {
    if ((sec_r000577_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000577_3_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000577_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000577_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000577_15_1 & 1) != 0)
  {
    if ((sec_r000577_10_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000577_8_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000577_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000577_8_1 + 7) & 127;
  }
  if ((sec_r000577_15_2 & 1) != 0)
  {
    if ((sec_r000577_10_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000577_8_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000577_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000577_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000577_3_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000577_3_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000577_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000577_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000577_10_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000577_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000577_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000577_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000577_17_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000577_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000577_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000577_16_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000577_17_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000577_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000577_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000577_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000577_3_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000577_3_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_17_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000577_0_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000577_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000577_0_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_17_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000577_0_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000577_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000577_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000577_7_1 & 1) != 0)
  {
    if ((sec_r000577_4_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((sec_r000577_7_2 & 1) != 0)
  {
    if ((sec_r000577_4_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000577_14_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000577_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000577_14_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000577_14_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000577_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000577_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000577_13_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000577_8_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000577_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000577_8_1 + 7) & 127;
  }
  if ((sec_r000577_13_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000577_8_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000577_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000577_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000577_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000577_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000577_16_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000577_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000577_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000577_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000577_15_1 & 1) != 0)
  {
    if ((sec_r000577_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000577_5_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000577_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000577_5_1 + 7) & 127;
  }
  if ((sec_r000577_15_2 & 1) != 0)
  {
    if ((sec_r000577_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000577_5_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000577_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000577_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000577_9_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((sec_r000577_9_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000577_5_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000577_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000577_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000577_5_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000577_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000577_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000577_10_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000577_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000577_10_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000577_10_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000577_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000577_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000577_12_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000577_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000577_12_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000577_12_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000577_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000577_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000577_16_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000577_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000577_16_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000577_16_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000577_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000577_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000577_0_1 & 1) != 0)
  {
    if ((sec_r000577_11_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((sec_r000577_0_2 & 1) != 0)
  {
    if ((sec_r000577_11_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000577_7_1 & 1) != 0)
  {
    if ((sec_r000577_11_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((sec_r000577_7_2 & 1) != 0)
  {
    if ((sec_r000577_11_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000577_4_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000577_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000577_4_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000577_4_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000577_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000577_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000577_2_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((sec_r000577_2_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000577_0_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000577_4_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000577_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000577_4_1 + 7) & 127;
  }
  if ((sec_r000577_0_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000577_4_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000577_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000577_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000577_16_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000577_16_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000577_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000577_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000577_8_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000577_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000577_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000577_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000577_16_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000577_16_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_5_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000577_8_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000577_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000577_8_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_5_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000577_8_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000577_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000577_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000577_1_1 & 1) != 0)
  {
    if ((sec_r000577_13_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000577_2_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000577_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000577_2_1 + 7) & 127;
  }
  if ((sec_r000577_1_2 & 1) != 0)
  {
    if ((sec_r000577_13_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000577_2_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000577_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000577_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000577_9_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000577_15_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000577_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000577_15_1 + 7) & 127;
  }
  if ((sec_r000577_9_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000577_15_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000577_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000577_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000577_2_1 & 1) != 0)
  {
    if ((sec_r000577_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((sec_r000577_2_2 & 1) != 0)
  {
    if ((sec_r000577_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000577_10_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000577_9_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000577_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000577_9_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000577_10_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000577_9_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000577_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000577_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000577_17_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000577_17_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000577_12_1 & 1) != 0)
  {
    if ((sec_r000577_14_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000577_12_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000577_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000577_12_1 + 7) & 127;
  }
  if ((sec_r000577_12_2 & 1) != 0)
  {
    if ((sec_r000577_14_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000577_12_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000577_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000577_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000577_12_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000577_7_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000577_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000577_7_1 + 7) & 127;
  }
  if ((sec_r000577_12_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000577_7_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000577_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000577_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000577_4_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000577_9_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000577_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000577_9_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000577_4_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000577_9_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000577_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000577_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000577_0_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000577_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000577_0_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000577_0_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000577_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000577_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000577_12_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000577_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000577_12_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000577_12_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000577_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000577_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_8_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000577_5_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000577_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000577_5_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_8_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000577_5_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000577_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000577_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000577_8_1 & 1) != 0)
  {
    if ((sec_r000577_17_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000577_14_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000577_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000577_14_1 + 7) & 127;
  }
  if ((sec_r000577_8_2 & 1) != 0)
  {
    if ((sec_r000577_17_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000577_14_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000577_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000577_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000577_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000577_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000577_4_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000577_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000577_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000577_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000577_0_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000577_0_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000577_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000577_0_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000577_0_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000577_0_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000577_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000577_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_0_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_0_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000577_12_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000577_12_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000577_5_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000577_5_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000577_9_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000577_9_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000577_13_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000577_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000577_13_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000577_13_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000577_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000577_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000577_14_1 & 1) != 0)
  {
    if ((sec_r000577_6_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000577_17_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000577_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000577_17_1 + 7) & 127;
  }
  if ((sec_r000577_14_2 & 1) != 0)
  {
    if ((sec_r000577_6_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000577_17_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000577_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000577_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000577_5_1 & 1) != 0)
  {
    if ((sec_r000577_10_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000577_12_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000577_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000577_12_1 + 7) & 127;
  }
  if ((sec_r000577_5_2 & 1) != 0)
  {
    if ((sec_r000577_10_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000577_12_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000577_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000577_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000577_1_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000577_11_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000577_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000577_11_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000577_1_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000577_11_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000577_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000577_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000577_0_1 & 1) != 0)
  {
    if ((sec_r000577_4_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000577_1_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000577_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000577_1_1 + 7) & 127;
  }
  if ((sec_r000577_0_2 & 1) != 0)
  {
    if ((sec_r000577_4_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000577_1_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000577_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000577_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000577_3_1 & 1) != 0)
  {
    if ((sec_r000577_7_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((sec_r000577_3_2 & 1) != 0)
  {
    if ((sec_r000577_7_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000577_11_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000577_4_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000577_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000577_4_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000577_11_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000577_4_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000577_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000577_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000577_8_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000577_6_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000577_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000577_6_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000577_8_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000577_6_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000577_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000577_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000577_1_1 & 1) != 0)
  {
    if ((sec_r000577_15_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000577_12_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000577_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000577_12_1 + 7) & 127;
  }
  if ((sec_r000577_1_2 & 1) != 0)
  {
    if ((sec_r000577_15_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000577_12_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000577_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000577_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000577_7_1 != sec_r000577_7_2);
  __CPROVER_assume(sec_r000577_6_1 != sec_r000577_6_2);
  __CPROVER_assume(sec_r000577_15_1 != sec_r000577_15_2);
  __CPROVER_assume(pub_r000577_15_1 == pub_r000577_15_2);
  __CPROVER_assume(sec_r000577_10_1 != sec_r000577_10_2);
  __CPROVER_assume(sec_r000577_14_1 != sec_r000577_14_2);
  __CPROVER_assume(pub_r000577_11_1 == pub_r000577_11_2);
  __CPROVER_assume(pub_r000577_10_1 == pub_r000577_10_2);
  __CPROVER_assume(pub_r000577_8_1 == pub_r000577_8_2);
  __CPROVER_assume(pub_r000577_4_1 == pub_r000577_4_2);
  __CPROVER_assume(sec_r000577_17_1 != sec_r000577_17_2);
  __CPROVER_assume(sec_r000577_0_1 != sec_r000577_0_2);
  __CPROVER_assume(pub_r000577_1_1 == pub_r000577_1_2);
  __CPROVER_assume(pub_r000577_7_1 == pub_r000577_7_2);
  __CPROVER_assume(sec_r000577_4_1 != sec_r000577_4_2);
  __CPROVER_assume(pub_r000577_16_1 == pub_r000577_16_2);
  __CPROVER_assume(pub_r000577_17_1 == pub_r000577_17_2);
  __CPROVER_assume(pub_r000577_2_1 == pub_r000577_2_2);
  __CPROVER_assume(sec_r000577_11_1 != sec_r000577_11_2);
  __CPROVER_assume(sec_r000577_13_1 != sec_r000577_13_2);
  __CPROVER_assume(sec_r000577_9_1 != sec_r000577_9_2);
  __CPROVER_assume(sec_r000577_2_1 != sec_r000577_2_2);
  __CPROVER_assume(sec_r000577_8_1 != sec_r000577_8_2);
  __CPROVER_assume(pub_r000577_13_1 == pub_r000577_13_2);
  __CPROVER_assume(sec_r000577_3_1 != sec_r000577_3_2);
  __CPROVER_assume(sec_r000577_12_1 != sec_r000577_12_2);
  __CPROVER_assume(pub_r000577_9_1 == pub_r000577_9_2);
  __CPROVER_assume(sec_r000577_16_1 != sec_r000577_16_2);
  __CPROVER_assume(pub_r000577_5_1 == pub_r000577_5_2);
  __CPROVER_assume(sec_r000577_5_1 != sec_r000577_5_2);
  __CPROVER_assume(pub_r000577_6_1 == pub_r000577_6_2);
  __CPROVER_assume(pub_r000577_3_1 == pub_r000577_3_2);
  __CPROVER_assume(pub_r000577_0_1 == pub_r000577_0_2);
  __CPROVER_assume(pub_r000577_14_1 == pub_r000577_14_2);
  __CPROVER_assume(pub_r000577_12_1 == pub_r000577_12_2);
  __CPROVER_assume(sec_r000577_1_1 != sec_r000577_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
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
}


