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
struct FilterState_R000072_7213_0
{
  short prev_out;
  unsigned char mode;
  short cutoff;
  int gain_db;
  unsigned char prev_in;
  unsigned char damping;
  int buffer[3];
};
struct EventLog_R000072_7213_1
{
  unsigned char severity;
  int facility;
  unsigned char seq;
  int code;
  int signature;
  int buffer[3];
};
struct StreamBuffer_R000072_7213_2
{
  int tail;
  int watermark;
  unsigned char state;
  int head;
  int buffer[3];
};
union ColorPixel_R000072_7213_0
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
void fn_R000072_7213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int delta_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_28_1)
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

  switch (delta_28_2)
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

  int cursor_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_73_1 > 43)
  {
    acc_1 = ((acc_1 + (cursor_73_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_73_2 > 43)
  {
    acc_2 = ((acc_2 + (cursor_73_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_60_1) & 63;
  aux_2 = (aux_2 + margin_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_28_1 == delta_28_2);
  assert(cursor_73_1 == cursor_73_2);
  assert(margin_60_1 == margin_60_2);
}

int fn_R000072_7213_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int delta_28 = (aux + st.buffer[1]) & 3;
  switch (delta_28)
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

  int cursor_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_73 > 43)
  {
    acc = ((acc + (cursor_73 * 2)) + 5) & 127;
    aux ^= cursor_73 & 15;
  }
  else
  {
    acc = ((acc - cursor_73) + 11) & 127;
    aux += 3;
  }
  int margin_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000072_7213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st_1 = {0};
  struct EventLog_R000072_7213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_46_1 = local_arr_1[aux_1 % 3];
  int vector_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_46_2 * 2)) & 127;
  int offset_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_24_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_24_1 * 2)) + 5) & 127;
    aux_1 ^= offset_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_24_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_24_2 * 2)) + 5) & 127;
    aux_2 ^= offset_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_76_1)
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

  switch (mask_76_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_46_1 == vector_46_2);
  assert(offset_24_1 == offset_24_2);
  assert(mask_76_1 == mask_76_2);
}

int fn_R000072_7213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_46 = local_arr[aux % 3];
  acc = (acc + (vector_46 * 2)) & 127;
  int offset_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_24 > 32)
  {
    acc = ((acc + (offset_24 * 2)) + 5) & 127;
    aux ^= offset_24 & 15;
  }
  else
  {
    acc = ((acc - offset_24) + 11) & 127;
    aux += 3;
  }
  int mask_76 = (aux + st.buffer[1]) & 3;
  switch (mask_76)
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

void fn_R000072_7213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int margin_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_56_1)
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

  switch (margin_56_2)
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

  int metric_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_11_1) & 63;
  aux_2 = (aux_2 + metric_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_29_1 > 25)
  {
    acc_1 = ((acc_1 + (delta_29_1 * 2)) + 5) & 127;
    aux_1 ^= delta_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_29_2 > 25)
  {
    acc_2 = ((acc_2 + (delta_29_2 * 2)) + 5) & 127;
    aux_2 ^= delta_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  assert(metric_11_1 == metric_11_2);
  assert(delta_29_1 == delta_29_2);
}

int fn_R000072_7213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int margin_56 = (aux + st.buffer[1]) & 3;
  switch (margin_56)
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

  int metric_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_29 > 25)
  {
    acc = ((acc + (delta_29 * 2)) + 5) & 127;
    aux ^= delta_29 & 15;
  }
  else
  {
    acc = ((acc - delta_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000072_7213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st_1 = {0};
  struct FilterState_R000072_7213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_81_1)
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

  switch (bound_81_2)
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

  int damping_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_52_1) & 63;
  aux_2 = (aux_2 + damping_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_44_1 = local_arr_1[aux_1 % 3];
  int bound_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_81_1 == bound_81_2);
  assert(damping_52_1 == damping_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_44_1 == bound_44_2);
}

int fn_R000072_7213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_81 = (aux + st.buffer[1]) & 3;
  switch (bound_81)
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

  int damping_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_52) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_44 = local_arr[aux % 3];
  acc = (acc + (bound_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000072_7213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_97_1 = local_arr_1[aux_1 % 3];
  int offset_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_97_2 * 2)) & 127;
  int accumulator_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_75_1) & 63;
  aux_2 = (aux_2 + accumulator_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_52_1)
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

  switch (sample_52_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_97_1 == offset_97_2);
  assert(accumulator_75_1 == accumulator_75_2);
  assert(sample_52_1 == sample_52_2);
}

int fn_R000072_7213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int offset_97 = local_arr[aux % 3];
  acc = (acc + (offset_97 * 2)) & 127;
  int accumulator_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_75) & 63;
  acc ^= aux;
  int sample_52 = (aux + st.buffer[1]) & 3;
  switch (sample_52)
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

void fn_R000072_7213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_15_1 = local_arr_1[aux_1 % 3];
  int margin_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_15_2 * 2)) & 127;
  int bound_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_56_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_56_1 * 2)) + 5) & 127;
    aux_1 ^= bound_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_56_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_56_2 * 2)) + 5) & 127;
    aux_2 ^= bound_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_15_1 == margin_15_2);
  assert(bound_56_1 == bound_56_2);
}

int fn_R000072_7213_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int margin_15 = local_arr[aux % 3];
  acc = (acc + (margin_15 * 2)) & 127;
  int bound_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_56 > 45)
  {
    acc = ((acc + (bound_56 * 2)) + 5) & 127;
    aux ^= bound_56 & 15;
  }
  else
  {
    acc = ((acc - bound_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000072_7213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st_1 = {0};
  struct EventLog_R000072_7213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_61_1 = local_arr_1[aux_1 % 3];
  int stride_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_61_2 * 2)) & 127;
  int bound_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_18_1) & 63;
  aux_2 = (aux_2 + bound_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_30_1)
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

  switch (bound_30_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_61_1 == stride_61_2);
  assert(bound_18_1 == bound_18_2);
  assert(bound_30_1 == bound_30_2);
}

int fn_R000072_7213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_61 = local_arr[aux % 3];
  acc = (acc + (stride_61 * 2)) & 127;
  int bound_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_18) & 63;
  acc ^= aux;
  int bound_30 = (aux + st.buffer[1]) & 3;
  switch (bound_30)
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

void fn_R000072_7213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st_1 = {0};
  struct FilterState_R000072_7213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_41_1)
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

  switch (pivot_41_2)
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

  int sample_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_68_1) & 63;
  aux_2 = (aux_2 + sample_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_41_1 == pivot_41_2);
  assert(sample_68_1 == sample_68_2);
}

int fn_R000072_7213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_41 = (aux + st.buffer[1]) & 3;
  switch (pivot_41)
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

  int sample_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000072_7213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_27_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_27_1 * 2)) + 5) & 127;
    aux_1 ^= damping_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_27_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_27_2 * 2)) + 5) & 127;
    aux_2 ^= damping_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_95_1)
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

  switch (window_95_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_27_1 == damping_27_2);
  assert(window_95_1 == window_95_2);
}

int fn_R000072_7213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_27 > 31)
  {
    acc = ((acc + (damping_27 * 2)) + 5) & 127;
    aux ^= damping_27 & 15;
  }
  else
  {
    acc = ((acc - damping_27) + 11) & 127;
    aux += 3;
  }
  int window_95 = (aux + st.buffer[1]) & 3;
  switch (window_95)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000072_7213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st_1 = {0};
  struct FilterState_R000072_7213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_56_1) & 63;
  aux_2 = (aux_2 + metric_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_76_1 = local_arr_1[aux_1 % 3];
  int pivot_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_56_1 == metric_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_76_1 == pivot_76_2);
}

int fn_R000072_7213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_76 = local_arr[aux % 3];
  acc = (acc + (pivot_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000072_7213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st_1 = {0};
  struct EventLog_R000072_7213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_84_1 > 46)
  {
    acc_1 = ((acc_1 + (pivot_84_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_84_2 > 46)
  {
    acc_2 = ((acc_2 + (pivot_84_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_29_1 = local_arr_1[aux_1 % 3];
  int segment_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_84_1 == pivot_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_29_1 == segment_29_2);
}

int fn_R000072_7213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_84 > 46)
  {
    acc = ((acc + (pivot_84 * 2)) + 5) & 127;
    aux ^= pivot_84 & 15;
  }
  else
  {
    acc = ((acc - pivot_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_29 = local_arr[aux % 3];
  acc = (acc + (segment_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000072_7213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st_1 = {0};
  struct FilterState_R000072_7213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int phase_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_10_1 > 44)
  {
    acc_1 = ((acc_1 + (phase_10_1 * 2)) + 5) & 127;
    aux_1 ^= phase_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_10_2 > 44)
  {
    acc_2 = ((acc_2 + (phase_10_2 * 2)) + 5) & 127;
    aux_2 ^= phase_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_37_1)
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

  switch (tally_37_2)
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

  int segment_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_77_1) & 63;
  aux_2 = (aux_2 + segment_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_10_1 == phase_10_2);
  assert(tally_37_1 == tally_37_2);
  assert(segment_77_1 == segment_77_2);
}

int fn_R000072_7213_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000072_7213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int phase_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_10 > 44)
  {
    acc = ((acc + (phase_10 * 2)) + 5) & 127;
    aux ^= phase_10 & 15;
  }
  else
  {
    acc = ((acc - phase_10) + 11) & 127;
    aux += 3;
  }
  int tally_37 = (aux + st.buffer[1]) & 3;
  switch (tally_37)
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

  int segment_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000072_7213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_74_1)
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

  switch (coefficient_74_2)
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
  int threshold_98_1 = local_arr_1[aux_1 % 3];
  int threshold_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_98_2 * 2)) & 127;
  int tracker_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_98_1) & 63;
  aux_2 = (aux_2 + tracker_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_74_1 == coefficient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_98_1 == threshold_98_2);
  assert(tracker_98_1 == tracker_98_2);
}

int fn_R000072_7213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_74 = (aux + st.buffer[1]) & 3;
  switch (coefficient_74)
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
  int threshold_98 = local_arr[aux % 3];
  acc = (acc + (threshold_98 * 2)) & 127;
  int tracker_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_98) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000072_7213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st_1 = {0};
  struct EventLog_R000072_7213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_47_1)
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

  switch (quotient_47_2)
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
  int delta_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_20_1 > 11)
  {
    acc_1 = ((acc_1 + (delta_20_1 * 2)) + 5) & 127;
    aux_1 ^= delta_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_20_2 > 11)
  {
    acc_2 = ((acc_2 + (delta_20_2 * 2)) + 5) & 127;
    aux_2 ^= delta_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_72_1) & 63;
  aux_2 = (aux_2 + metric_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_47_1 == quotient_47_2);
  assert(delta_20_1 == delta_20_2);
  assert(metric_72_1 == metric_72_2);
}

int fn_R000072_7213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000072_7213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_47 = (aux + st.buffer[1]) & 3;
  switch (quotient_47)
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
  int delta_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_20 > 11)
  {
    acc = ((acc + (delta_20 * 2)) + 5) & 127;
    aux ^= delta_20 & 15;
  }
  else
  {
    acc = ((acc - delta_20) + 11) & 127;
    aux += 3;
  }
  int metric_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000072_7213_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int anchor_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_13_1 > 22)
  {
    acc_1 = ((acc_1 + (anchor_13_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_13_2 > 22)
  {
    acc_2 = ((acc_2 + (anchor_13_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_39_1) & 63;
  aux_2 = (aux_2 + mask_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_13_1 == anchor_13_2);
  assert(mask_39_1 == mask_39_2);
}

int fn_R000072_7213_14(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int anchor_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_13 > 22)
  {
    acc = ((acc + (anchor_13 * 2)) + 5) & 127;
    aux ^= anchor_13 & 15;
  }
  else
  {
    acc = ((acc - anchor_13) + 11) & 127;
    aux += 3;
  }
  int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000072_7213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_68_1 = local_arr_1[aux_1 % 3];
  int margin_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_68_2 * 2)) & 127;
  int stride_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_54_1 > 23)
  {
    acc_1 = ((acc_1 + (stride_54_1 * 2)) + 5) & 127;
    aux_1 ^= stride_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_54_2 > 23)
  {
    acc_2 = ((acc_2 + (stride_54_2 * 2)) + 5) & 127;
    aux_2 ^= stride_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_68_1 == margin_68_2);
  assert(stride_54_1 == stride_54_2);
}

int fn_R000072_7213_15(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int margin_68 = local_arr[aux % 3];
  acc = (acc + (margin_68 * 2)) & 127;
  int stride_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_54 > 23)
  {
    acc = ((acc + (stride_54 * 2)) + 5) & 127;
    aux ^= stride_54 & 15;
  }
  else
  {
    acc = ((acc - stride_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000072_7213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_76_1) & 63;
  aux_2 = (aux_2 + vector_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_13_1 > 36)
  {
    acc_1 = ((acc_1 + (quotient_13_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_13_2 > 36)
  {
    acc_2 = ((acc_2 + (quotient_13_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_90_1 = local_arr_1[aux_1 % 3];
  int anchor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_90_2 * 2)) & 127;
  int weight_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_33_1)
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

  switch (weight_33_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_76_1 == vector_76_2);
  assert(quotient_13_1 == quotient_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_90_1 == anchor_90_2);
  assert(weight_33_1 == weight_33_2);
}

int fn_R000072_7213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000072_7213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_76) & 63;
  acc ^= aux;
  int quotient_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_13 > 36)
  {
    acc = ((acc + (quotient_13 * 2)) + 5) & 127;
    aux ^= quotient_13 & 15;
  }
  else
  {
    acc = ((acc - quotient_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_90 = local_arr[aux % 3];
  acc = (acc + (anchor_90 * 2)) & 127;
  int weight_33 = (aux + st.buffer[1]) & 3;
  switch (weight_33)
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

void main()
{
  int sec_r000072_0_1;
  int sec_r000072_0_2;
  int sec_r000072_1_1;
  int sec_r000072_1_2;
  int sec_r000072_2_1;
  int sec_r000072_2_2;
  int sec_r000072_3_1;
  int sec_r000072_3_2;
  int sec_r000072_4_1;
  int sec_r000072_4_2;
  int sec_r000072_5_1;
  int sec_r000072_5_2;
  int sec_r000072_6_1;
  int sec_r000072_6_2;
  int sec_r000072_7_1;
  int sec_r000072_7_2;
  int sec_r000072_8_1;
  int sec_r000072_8_2;
  int sec_r000072_9_1;
  int sec_r000072_9_2;
  int sec_r000072_10_1;
  int sec_r000072_10_2;
  int sec_r000072_11_1;
  int sec_r000072_11_2;
  int sec_r000072_12_1;
  int sec_r000072_12_2;
  int sec_r000072_13_1;
  int sec_r000072_13_2;
  int sec_r000072_14_1;
  int sec_r000072_14_2;
  int sec_r000072_15_1;
  int sec_r000072_15_2;
  int sec_r000072_16_1;
  int sec_r000072_16_2;
  int sec_r000072_17_1;
  int sec_r000072_17_2;
  int pub_r000072_0_1;
  int pub_r000072_0_2;
  int pub_r000072_1_1;
  int pub_r000072_1_2;
  int pub_r000072_2_1;
  int pub_r000072_2_2;
  int pub_r000072_3_1;
  int pub_r000072_3_2;
  int pub_r000072_4_1;
  int pub_r000072_4_2;
  int pub_r000072_5_1;
  int pub_r000072_5_2;
  int pub_r000072_6_1;
  int pub_r000072_6_2;
  int pub_r000072_7_1;
  int pub_r000072_7_2;
  int pub_r000072_8_1;
  int pub_r000072_8_2;
  int pub_r000072_9_1;
  int pub_r000072_9_2;
  int pub_r000072_10_1;
  int pub_r000072_10_2;
  int pub_r000072_11_1;
  int pub_r000072_11_2;
  int pub_r000072_12_1;
  int pub_r000072_12_2;
  int pub_r000072_13_1;
  int pub_r000072_13_2;
  int pub_r000072_14_1;
  int pub_r000072_14_2;
  int pub_r000072_15_1;
  int pub_r000072_15_2;
  int pub_r000072_16_1;
  int pub_r000072_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000072_0_1 >= (-100)) && (pub_r000072_0_1 <= 100));
  __CPROVER_assume((pub_r000072_0_2 >= (-100)) && (pub_r000072_0_2 <= 100));
  __CPROVER_assume((pub_r000072_1_1 >= (-100)) && (pub_r000072_1_1 <= 100));
  __CPROVER_assume((pub_r000072_1_2 >= (-100)) && (pub_r000072_1_2 <= 100));
  __CPROVER_assume((pub_r000072_2_1 >= (-100)) && (pub_r000072_2_1 <= 100));
  __CPROVER_assume((pub_r000072_2_2 >= (-100)) && (pub_r000072_2_2 <= 100));
  __CPROVER_assume((pub_r000072_3_1 >= (-100)) && (pub_r000072_3_1 <= 100));
  __CPROVER_assume((pub_r000072_3_2 >= (-100)) && (pub_r000072_3_2 <= 100));
  __CPROVER_assume((pub_r000072_4_1 >= (-100)) && (pub_r000072_4_1 <= 100));
  __CPROVER_assume((pub_r000072_4_2 >= (-100)) && (pub_r000072_4_2 <= 100));
  __CPROVER_assume((pub_r000072_5_1 >= (-100)) && (pub_r000072_5_1 <= 100));
  __CPROVER_assume((pub_r000072_5_2 >= (-100)) && (pub_r000072_5_2 <= 100));
  __CPROVER_assume((pub_r000072_6_1 >= (-100)) && (pub_r000072_6_1 <= 100));
  __CPROVER_assume((pub_r000072_6_2 >= (-100)) && (pub_r000072_6_2 <= 100));
  __CPROVER_assume((pub_r000072_7_1 >= (-100)) && (pub_r000072_7_1 <= 100));
  __CPROVER_assume((pub_r000072_7_2 >= (-100)) && (pub_r000072_7_2 <= 100));
  __CPROVER_assume((pub_r000072_8_1 >= (-100)) && (pub_r000072_8_1 <= 100));
  __CPROVER_assume((pub_r000072_8_2 >= (-100)) && (pub_r000072_8_2 <= 100));
  __CPROVER_assume((pub_r000072_9_1 >= (-100)) && (pub_r000072_9_1 <= 100));
  __CPROVER_assume((pub_r000072_9_2 >= (-100)) && (pub_r000072_9_2 <= 100));
  __CPROVER_assume((pub_r000072_10_1 >= (-100)) && (pub_r000072_10_1 <= 100));
  __CPROVER_assume((pub_r000072_10_2 >= (-100)) && (pub_r000072_10_2 <= 100));
  __CPROVER_assume((pub_r000072_11_1 >= (-100)) && (pub_r000072_11_1 <= 100));
  __CPROVER_assume((pub_r000072_11_2 >= (-100)) && (pub_r000072_11_2 <= 100));
  __CPROVER_assume((pub_r000072_12_1 >= (-100)) && (pub_r000072_12_1 <= 100));
  __CPROVER_assume((pub_r000072_12_2 >= (-100)) && (pub_r000072_12_2 <= 100));
  __CPROVER_assume((pub_r000072_13_1 >= (-100)) && (pub_r000072_13_1 <= 100));
  __CPROVER_assume((pub_r000072_13_2 >= (-100)) && (pub_r000072_13_2 <= 100));
  __CPROVER_assume((pub_r000072_14_1 >= (-100)) && (pub_r000072_14_1 <= 100));
  __CPROVER_assume((pub_r000072_14_2 >= (-100)) && (pub_r000072_14_2 <= 100));
  __CPROVER_assume((pub_r000072_15_1 >= (-100)) && (pub_r000072_15_1 <= 100));
  __CPROVER_assume((pub_r000072_15_2 >= (-100)) && (pub_r000072_15_2 <= 100));
  __CPROVER_assume((pub_r000072_16_1 >= (-100)) && (pub_r000072_16_1 <= 100));
  __CPROVER_assume((pub_r000072_16_2 >= (-100)) && (pub_r000072_16_2 <= 100));
  __CPROVER_assume((sec_r000072_0_1 >= 0) && (sec_r000072_0_1 <= 255));
  __CPROVER_assume((sec_r000072_0_2 >= 0) && (sec_r000072_0_2 <= 255));
  __CPROVER_assume((sec_r000072_1_1 >= 0) && (sec_r000072_1_1 <= 255));
  __CPROVER_assume((sec_r000072_1_2 >= 0) && (sec_r000072_1_2 <= 255));
  __CPROVER_assume((sec_r000072_2_1 >= 0) && (sec_r000072_2_1 <= 255));
  __CPROVER_assume((sec_r000072_2_2 >= 0) && (sec_r000072_2_2 <= 255));
  __CPROVER_assume((sec_r000072_3_1 >= 0) && (sec_r000072_3_1 <= 255));
  __CPROVER_assume((sec_r000072_3_2 >= 0) && (sec_r000072_3_2 <= 255));
  __CPROVER_assume((sec_r000072_4_1 >= 0) && (sec_r000072_4_1 <= 255));
  __CPROVER_assume((sec_r000072_4_2 >= 0) && (sec_r000072_4_2 <= 255));
  __CPROVER_assume((sec_r000072_5_1 >= 0) && (sec_r000072_5_1 <= 255));
  __CPROVER_assume((sec_r000072_5_2 >= 0) && (sec_r000072_5_2 <= 255));
  __CPROVER_assume((sec_r000072_6_1 >= 0) && (sec_r000072_6_1 <= 255));
  __CPROVER_assume((sec_r000072_6_2 >= 0) && (sec_r000072_6_2 <= 255));
  __CPROVER_assume((sec_r000072_7_1 >= 0) && (sec_r000072_7_1 <= 255));
  __CPROVER_assume((sec_r000072_7_2 >= 0) && (sec_r000072_7_2 <= 255));
  __CPROVER_assume((sec_r000072_8_1 >= 0) && (sec_r000072_8_1 <= 255));
  __CPROVER_assume((sec_r000072_8_2 >= 0) && (sec_r000072_8_2 <= 255));
  __CPROVER_assume((sec_r000072_9_1 >= 0) && (sec_r000072_9_1 <= 255));
  __CPROVER_assume((sec_r000072_9_2 >= 0) && (sec_r000072_9_2 <= 255));
  __CPROVER_assume((sec_r000072_10_1 >= 0) && (sec_r000072_10_1 <= 255));
  __CPROVER_assume((sec_r000072_10_2 >= 0) && (sec_r000072_10_2 <= 255));
  __CPROVER_assume((sec_r000072_11_1 >= 0) && (sec_r000072_11_1 <= 255));
  __CPROVER_assume((sec_r000072_11_2 >= 0) && (sec_r000072_11_2 <= 255));
  __CPROVER_assume((sec_r000072_12_1 >= 0) && (sec_r000072_12_1 <= 255));
  __CPROVER_assume((sec_r000072_12_2 >= 0) && (sec_r000072_12_2 <= 255));
  __CPROVER_assume((sec_r000072_13_1 >= 0) && (sec_r000072_13_1 <= 255));
  __CPROVER_assume((sec_r000072_13_2 >= 0) && (sec_r000072_13_2 <= 255));
  __CPROVER_assume((sec_r000072_14_1 >= 0) && (sec_r000072_14_1 <= 255));
  __CPROVER_assume((sec_r000072_14_2 >= 0) && (sec_r000072_14_2 <= 255));
  __CPROVER_assume((sec_r000072_15_1 >= 0) && (sec_r000072_15_1 <= 255));
  __CPROVER_assume((sec_r000072_15_2 >= 0) && (sec_r000072_15_2 <= 255));
  __CPROVER_assume((sec_r000072_16_1 >= 0) && (sec_r000072_16_1 <= 255));
  __CPROVER_assume((sec_r000072_16_2 >= 0) && (sec_r000072_16_2 <= 255));
  __CPROVER_assume((sec_r000072_17_1 >= 0) && (sec_r000072_17_1 <= 255));
  __CPROVER_assume((sec_r000072_17_2 >= 0) && (sec_r000072_17_2 <= 255));
  struct FilterState_R000072_7213_0 st_var_0_1 = {0};
  struct FilterState_R000072_7213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000072_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000072_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000072_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000072_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000072_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000072_0_2 + 7) & 15;
  struct EventLog_R000072_7213_1 st_var_1_1 = {0};
  struct EventLog_R000072_7213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000072_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000072_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000072_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000072_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000072_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000072_0_2 + 9) & 15;
  struct StreamBuffer_R000072_7213_2 st_var_2_1 = {0};
  struct StreamBuffer_R000072_7213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000072_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000072_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000072_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000072_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000072_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000072_0_2 + 11) & 15;
  union ColorPixel_R000072_7213_0 u_var_1;
  union ColorPixel_R000072_7213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 35)
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
  if (stage_v_1_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 35)
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
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 55)
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
  if (stage_v_3_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 55)
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
  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 55)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 55)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
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

  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_0_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_0_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 52)
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
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 52)
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
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 47)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 47)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((sec_r000072_8_1 + pub_r000072_9_1) + 21) & 127;
  int stage_v_42_2 = ((sec_r000072_8_2 + pub_r000072_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((sec_r000072_0_1 + pub_r000072_9_1) + 11) & 127;
  int stage_v_43_2 = ((sec_r000072_0_2 + pub_r000072_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((stage_v_42_1 + pub_r000072_14_1) + 37) & 127;
  int stage_v_44_2 = ((stage_v_42_2 + pub_r000072_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((sec_r000072_0_1 + pub_r000072_10_1) + 48) & 127;
  int stage_v_45_2 = ((sec_r000072_0_2 + pub_r000072_10_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_42_1 + pub_r000072_7_1) + 33) & 127;
  int stage_v_46_2 = ((stage_v_42_2 + pub_r000072_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((stage_v_45_1 + pub_r000072_5_1) + 33) & 127;
  int stage_v_47_2 = ((stage_v_45_2 + pub_r000072_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((sec_r000072_11_1 + pub_r000072_16_1) + 41) & 127;
  int stage_v_48_2 = ((sec_r000072_11_2 + pub_r000072_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((sec_r000072_6_1 + pub_r000072_9_1) + 25) & 127;
  int stage_v_49_2 = ((sec_r000072_6_2 + pub_r000072_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((stage_v_46_1 + pub_r000072_3_1) + 23) & 127;
  int stage_v_50_2 = ((stage_v_46_2 + pub_r000072_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((sec_r000072_11_1 + pub_r000072_3_1) + 25) & 127;
  int stage_v_51_2 = ((sec_r000072_11_2 + pub_r000072_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((stage_v_42_1 + pub_r000072_9_1) + 21) & 127;
  int stage_v_52_2 = ((stage_v_42_2 + pub_r000072_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((sec_r000072_8_1 + pub_r000072_12_1) + 24) & 127;
  int stage_v_53_2 = ((sec_r000072_8_2 + pub_r000072_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_48_1 + pub_r000072_7_1) + 16) & 127;
  int stage_v_54_2 = ((stage_v_48_2 + pub_r000072_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((sec_r000072_4_1 + pub_r000072_3_1) + 23) & 127;
  int stage_v_55_2 = ((sec_r000072_4_2 + pub_r000072_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((stage_v_53_1 + pub_r000072_5_1) + 29) & 127;
  int stage_v_56_2 = ((stage_v_53_2 + pub_r000072_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_42_1 + pub_r000072_16_1) + 35) & 127;
  int stage_v_57_2 = ((stage_v_42_2 + pub_r000072_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_43_1 + pub_r000072_12_1) + 14) & 127;
  int stage_v_58_2 = ((stage_v_43_2 + pub_r000072_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_46_1 + pub_r000072_13_1) + 45) & 127;
  int stage_v_59_2 = ((stage_v_46_2 + pub_r000072_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((sec_r000072_6_1 + pub_r000072_15_1) + 36) & 127;
  int stage_v_60_2 = ((sec_r000072_6_2 + pub_r000072_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_58_1 + pub_r000072_9_1) + 34) & 127;
  int stage_v_61_2 = ((stage_v_58_2 + pub_r000072_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_57_1 + pub_r000072_4_1) + 18) & 127;
  int stage_v_62_2 = ((stage_v_57_2 + pub_r000072_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_54_1 + pub_r000072_2_1) + 45) & 127;
  int stage_v_63_2 = ((stage_v_54_2 + pub_r000072_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((sec_r000072_4_1 + pub_r000072_14_1) + 27) & 127;
  int stage_v_64_2 = ((sec_r000072_4_2 + pub_r000072_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_42_1 + pub_r000072_5_1) + 43) & 127;
  int stage_v_65_2 = ((stage_v_42_2 + pub_r000072_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((sec_r000072_5_1 + pub_r000072_7_1) + 49) & 127;
  int stage_v_66_2 = ((sec_r000072_5_2 + pub_r000072_7_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_44_1 + pub_r000072_7_1) + 20) & 127;
  int stage_v_67_2 = ((stage_v_44_2 + pub_r000072_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000072_7_1 + pub_r000072_14_1) + 48) & 127;
  int stage_v_68_2 = ((sec_r000072_7_2 + pub_r000072_14_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_42_1 + pub_r000072_8_1) + 10) & 127;
  int stage_v_69_2 = ((stage_v_42_2 + pub_r000072_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_60_1 + pub_r000072_11_1) + 7) & 127;
  int stage_v_70_2 = ((stage_v_60_2 + pub_r000072_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_56_1 + pub_r000072_12_1) + 6) & 127;
  int stage_v_71_2 = ((stage_v_56_2 + pub_r000072_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((sec_r000072_15_1 + pub_r000072_7_1) + 15) & 127;
  int stage_v_72_2 = ((sec_r000072_15_2 + pub_r000072_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((sec_r000072_13_1 + pub_r000072_15_1) + 35) & 127;
  int stage_v_73_2 = ((sec_r000072_13_2 + pub_r000072_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_68_1 + pub_r000072_14_1) + 48) & 127;
  int stage_v_74_2 = ((stage_v_68_2 + pub_r000072_14_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000072_7_1 + pub_r000072_11_1) + 10) & 127;
  int stage_v_75_2 = ((sec_r000072_7_2 + pub_r000072_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_42_1 + pub_r000072_3_1) + 25) & 127;
  int stage_v_76_2 = ((stage_v_42_2 + pub_r000072_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((sec_r000072_13_1 + pub_r000072_10_1) + 48) & 127;
  int stage_v_77_2 = ((sec_r000072_13_2 + pub_r000072_10_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_56_1 + pub_r000072_14_1) + 37) & 127;
  int stage_v_78_2 = ((stage_v_56_2 + pub_r000072_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_57_1 + pub_r000072_0_1) + 46) & 127;
  int stage_v_79_2 = ((stage_v_57_2 + pub_r000072_0_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_64_1 + pub_r000072_3_1) + 35) & 127;
  int stage_v_80_2 = ((stage_v_64_2 + pub_r000072_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_79_1 + pub_r000072_16_1) + 28) & 127;
  int stage_v_81_2 = ((stage_v_79_2 + pub_r000072_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_69_1 + pub_r000072_3_1) + 41) & 127;
  int stage_v_82_2 = ((stage_v_69_2 + pub_r000072_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((sec_r000072_7_1 + pub_r000072_14_1) + 35) & 127;
  int stage_v_83_2 = ((sec_r000072_7_2 + pub_r000072_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((sec_r000072_3_1 + pub_r000072_5_1) + 35) & 127;
  int stage_v_84_2 = ((sec_r000072_3_2 + pub_r000072_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_61_1 + pub_r000072_13_1) + 16) & 127;
  int stage_v_85_2 = ((stage_v_61_2 + pub_r000072_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_83_1 + pub_r000072_11_1) + 33) & 127;
  int stage_v_86_2 = ((stage_v_83_2 + pub_r000072_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_69_1 + pub_r000072_4_1) + 15) & 127;
  int stage_v_87_2 = ((stage_v_69_2 + pub_r000072_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_85_1 + pub_r000072_15_1) + 30) & 127;
  int stage_v_88_2 = ((stage_v_85_2 + pub_r000072_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((sec_r000072_11_1 + pub_r000072_4_1) + 18) & 127;
  int stage_v_89_2 = ((sec_r000072_11_2 + pub_r000072_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_50_1 + pub_r000072_8_1) + 47) & 127;
  int stage_v_90_2 = ((stage_v_50_2 + pub_r000072_8_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_49_1 + pub_r000072_2_1) + 13) & 127;
  int stage_v_91_2 = ((stage_v_49_2 + pub_r000072_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_56_1 + pub_r000072_0_1) + 23) & 127;
  int stage_v_92_2 = ((stage_v_56_2 + pub_r000072_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_75_1 + pub_r000072_8_1) + 31) & 127;
  int stage_v_93_2 = ((stage_v_75_2 + pub_r000072_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((stage_v_45_1 + pub_r000072_0_1) + 34) & 127;
  int stage_v_94_2 = ((stage_v_45_2 + pub_r000072_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_85_1 + pub_r000072_2_1) + 49) & 127;
  int stage_v_95_2 = ((stage_v_85_2 + pub_r000072_2_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000072_7_1 + pub_r000072_4_1) + 12) & 127;
  int stage_v_96_2 = ((sec_r000072_7_2 + pub_r000072_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_51_1 + pub_r000072_14_1) + 12) & 127;
  int stage_v_97_2 = ((stage_v_51_2 + pub_r000072_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_72_1 + pub_r000072_8_1) + 33) & 127;
  int stage_v_98_2 = ((stage_v_72_2 + pub_r000072_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_87_1 + pub_r000072_1_1) + 35) & 127;
  int stage_v_99_2 = ((stage_v_87_2 + pub_r000072_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_67_1 + pub_r000072_1_1) + 8) & 127;
  int stage_v_100_2 = ((stage_v_67_2 + pub_r000072_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_79_1 + pub_r000072_6_1) + 25) & 127;
  int stage_v_101_2 = ((stage_v_79_2 + pub_r000072_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000072_4_1 + pub_r000072_3_1) + 41) & 127;
  int stage_v_102_2 = ((sec_r000072_4_2 + pub_r000072_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((sec_r000072_17_1 + pub_r000072_7_1) + 16) & 127;
  int stage_v_103_2 = ((sec_r000072_17_2 + pub_r000072_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_62_1 + pub_r000072_12_1) + 31) & 127;
  int stage_v_104_2 = ((stage_v_62_2 + pub_r000072_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_82_1 + pub_r000072_14_1) + 30) & 127;
  int stage_v_105_2 = ((stage_v_82_2 + pub_r000072_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_101_1 + pub_r000072_14_1) + 36) & 127;
  int stage_v_106_2 = ((stage_v_101_2 + pub_r000072_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_91_1 + pub_r000072_9_1) + 8) & 127;
  int stage_v_107_2 = ((stage_v_91_2 + pub_r000072_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_60_1 + pub_r000072_5_1) + 42) & 127;
  int stage_v_108_2 = ((stage_v_60_2 + pub_r000072_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((stage_v_99_1 + pub_r000072_14_1) + 3) & 127;
  int stage_v_109_2 = ((stage_v_99_2 + pub_r000072_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_103_1 + pub_r000072_7_1) + 12) & 127;
  int stage_v_110_2 = ((stage_v_103_2 + pub_r000072_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_77_1 + pub_r000072_3_1) + 18) & 127;
  int stage_v_111_2 = ((stage_v_77_2 + pub_r000072_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000072_4_1 + pub_r000072_15_1) + 29) & 127;
  int stage_v_112_2 = ((sec_r000072_4_2 + pub_r000072_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((sec_r000072_8_1 + pub_r000072_9_1) + 28) & 127;
  int stage_v_113_2 = ((sec_r000072_8_2 + pub_r000072_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_64_1 + pub_r000072_15_1) + 43) & 127;
  int stage_v_114_2 = ((stage_v_64_2 + pub_r000072_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_114_1 + pub_r000072_4_1) + 39) & 127;
  int stage_v_115_2 = ((stage_v_114_2 + pub_r000072_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_66_1 + pub_r000072_7_1) + 23) & 127;
  int stage_v_116_2 = ((stage_v_66_2 + pub_r000072_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((sec_r000072_15_1 + pub_r000072_14_1) + 19) & 127;
  int stage_v_117_2 = ((sec_r000072_15_2 + pub_r000072_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000072_7_1 + pub_r000072_13_1) + 45) & 127;
  int stage_v_118_2 = ((sec_r000072_7_2 + pub_r000072_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_47_1 + pub_r000072_0_1) + 4) & 127;
  int stage_v_119_2 = ((stage_v_47_2 + pub_r000072_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_114_1 + pub_r000072_6_1) + 9) & 127;
  int stage_v_120_2 = ((stage_v_114_2 + pub_r000072_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_42_1 + pub_r000072_11_1) + 26) & 127;
  int stage_v_121_2 = ((stage_v_42_2 + pub_r000072_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_85_1 + pub_r000072_5_1) + 14) & 127;
  int stage_v_122_2 = ((stage_v_85_2 + pub_r000072_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((sec_r000072_15_1 + pub_r000072_8_1) + 37) & 127;
  int stage_v_123_2 = ((sec_r000072_15_2 + pub_r000072_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_71_1 + pub_r000072_10_1) + 20) & 127;
  int stage_v_124_2 = ((stage_v_71_2 + pub_r000072_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((sec_r000072_5_1 + pub_r000072_6_1) + 3) & 127;
  int stage_v_125_2 = ((sec_r000072_5_2 + pub_r000072_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_84_1 + pub_r000072_7_1) + 7) & 127;
  int stage_v_126_2 = ((stage_v_84_2 + pub_r000072_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_84_1 + pub_r000072_16_1) + 33) & 127;
  int stage_v_127_2 = ((stage_v_84_2 + pub_r000072_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_125_1 + pub_r000072_9_1) + 47) & 127;
  int stage_v_128_2 = ((stage_v_125_2 + pub_r000072_9_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_102_1 + pub_r000072_5_1) + 6) & 127;
  int stage_v_129_2 = ((stage_v_102_2 + pub_r000072_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_117_1 + pub_r000072_1_1) + 15) & 127;
  int stage_v_130_2 = ((stage_v_117_2 + pub_r000072_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_81_1 + pub_r000072_10_1) + 24) & 127;
  int stage_v_131_2 = ((stage_v_81_2 + pub_r000072_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_123_1 + pub_r000072_5_1) + 21) & 127;
  int stage_v_132_2 = ((stage_v_123_2 + pub_r000072_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((sec_r000072_14_1 + pub_r000072_3_1) + 17) & 127;
  int stage_v_133_2 = ((sec_r000072_14_2 + pub_r000072_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000072_10_1 + pub_r000072_2_1) + 24) & 127;
  int stage_v_134_2 = ((sec_r000072_10_2 + pub_r000072_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_90_1 + pub_r000072_13_1) + 15) & 127;
  int stage_v_135_2 = ((stage_v_90_2 + pub_r000072_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_101_1 + pub_r000072_5_1) + 28) & 127;
  int stage_v_136_2 = ((stage_v_101_2 + pub_r000072_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_122_1 + pub_r000072_6_1) + 6) & 127;
  int stage_v_137_2 = ((stage_v_122_2 + pub_r000072_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_131_1 + pub_r000072_0_1) + 16) & 127;
  int stage_v_138_2 = ((stage_v_131_2 + pub_r000072_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_127_1 + pub_r000072_16_1) + 42) & 127;
  int stage_v_139_2 = ((stage_v_127_2 + pub_r000072_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_111_1 + pub_r000072_2_1) + 49) & 127;
  int stage_v_140_2 = ((stage_v_111_2 + pub_r000072_2_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_66_1 + pub_r000072_7_1) + 10) & 127;
  int stage_v_141_2 = ((stage_v_66_2 + pub_r000072_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_54_1 + pub_r000072_0_1) + 18) & 127;
  int stage_v_142_2 = ((stage_v_54_2 + pub_r000072_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_80_1 + pub_r000072_13_1) + 15) & 127;
  int stage_v_143_2 = ((stage_v_80_2 + pub_r000072_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_139_1 + pub_r000072_3_1) + 8) & 127;
  int stage_v_144_2 = ((stage_v_139_2 + pub_r000072_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((sec_r000072_17_1 + pub_r000072_11_1) + 43) & 127;
  int stage_v_145_2 = ((sec_r000072_17_2 + pub_r000072_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_51_1 + pub_r000072_4_1) + 33) & 127;
  int stage_v_146_2 = ((stage_v_51_2 + pub_r000072_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000072_6_1 + pub_r000072_4_1) + 40) & 127;
  int stage_v_147_2 = ((sec_r000072_6_2 + pub_r000072_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_94_1 + pub_r000072_12_1) + 48) & 127;
  int stage_v_148_2 = ((stage_v_94_2 + pub_r000072_12_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((sec_r000072_15_1 + pub_r000072_10_1) + 27) & 127;
  int stage_v_149_2 = ((sec_r000072_15_2 + pub_r000072_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((sec_r000072_6_1 + pub_r000072_6_1) + 20) & 127;
  int stage_v_150_2 = ((sec_r000072_6_2 + pub_r000072_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_50_1 + pub_r000072_6_1) + 9) & 127;
  int stage_v_151_2 = ((stage_v_50_2 + pub_r000072_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((sec_r000072_5_1 + pub_r000072_15_1) + 18) & 127;
  int stage_v_152_2 = ((sec_r000072_5_2 + pub_r000072_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_142_1 + pub_r000072_16_1) + 39) & 127;
  int stage_v_153_2 = ((stage_v_142_2 + pub_r000072_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_61_1 + pub_r000072_6_1) + 16) & 127;
  int stage_v_154_2 = ((stage_v_61_2 + pub_r000072_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((sec_r000072_2_1 + pub_r000072_0_1) + 22) & 127;
  int stage_v_155_2 = ((sec_r000072_2_2 + pub_r000072_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((sec_r000072_16_1 + pub_r000072_0_1) + 31) & 127;
  int stage_v_156_2 = ((sec_r000072_16_2 + pub_r000072_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000072_2_1 + pub_r000072_15_1) + 29) & 127;
  int stage_v_157_2 = ((sec_r000072_2_2 + pub_r000072_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_125_1 + pub_r000072_15_1) + 36) & 127;
  int stage_v_158_2 = ((stage_v_125_2 + pub_r000072_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000072_16_1 + pub_r000072_10_1) + 15) & 127;
  int stage_v_159_2 = ((sec_r000072_16_2 + pub_r000072_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_124_1 + pub_r000072_8_1) + 33) & 127;
  int stage_v_160_2 = ((stage_v_124_2 + pub_r000072_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_131_1 + pub_r000072_2_1) + 6) & 127;
  int stage_v_161_2 = ((stage_v_131_2 + pub_r000072_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_85_1 + pub_r000072_7_1) + 24) & 127;
  int stage_v_162_2 = ((stage_v_85_2 + pub_r000072_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000072_0_1 + pub_r000072_10_1) + 32) & 127;
  int stage_v_163_2 = ((sec_r000072_0_2 + pub_r000072_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((sec_r000072_1_1 + pub_r000072_1_1) + 27) & 127;
  int stage_v_164_2 = ((sec_r000072_1_2 + pub_r000072_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000072_7_1 + pub_r000072_13_1) + 34) & 127;
  int stage_v_165_2 = ((sec_r000072_7_2 + pub_r000072_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000072_2_1 + pub_r000072_13_1) + 18) & 127;
  int stage_v_166_2 = ((sec_r000072_2_2 + pub_r000072_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_77_1 + pub_r000072_2_1) + 10) & 127;
  int stage_v_167_2 = ((stage_v_77_2 + pub_r000072_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_166_1 + pub_r000072_10_1) + 11) & 127;
  int stage_v_168_2 = ((stage_v_166_2 + pub_r000072_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_104_1 + pub_r000072_6_1) + 16) & 127;
  int stage_v_169_2 = ((stage_v_104_2 + pub_r000072_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((sec_r000072_7_1 + pub_r000072_4_1) + 7) & 127;
  int stage_v_170_2 = ((sec_r000072_7_2 + pub_r000072_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_69_1 + pub_r000072_7_1) + 35) & 127;
  int stage_v_171_2 = ((stage_v_69_2 + pub_r000072_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_70_1 + pub_r000072_10_1) + 46) & 127;
  int stage_v_172_2 = ((stage_v_70_2 + pub_r000072_10_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_50_1 + pub_r000072_5_1) + 29) & 127;
  int stage_v_173_2 = ((stage_v_50_2 + pub_r000072_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((sec_r000072_17_1 + pub_r000072_14_1) + 43) & 127;
  int stage_v_174_2 = ((sec_r000072_17_2 + pub_r000072_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((sec_r000072_13_1 + pub_r000072_10_1) + 48) & 127;
  int stage_v_175_2 = ((sec_r000072_13_2 + pub_r000072_10_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000072_1_1 + pub_r000072_8_1) + 27) & 127;
  int stage_v_176_2 = ((sec_r000072_1_2 + pub_r000072_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_65_1 + pub_r000072_13_1) + 3) & 127;
  int stage_v_177_2 = ((stage_v_65_2 + pub_r000072_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_164_1 + pub_r000072_12_1) + 16) & 127;
  int stage_v_178_2 = ((stage_v_164_2 + pub_r000072_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_76_1 + pub_r000072_5_1) + 43) & 127;
  int stage_v_179_2 = ((stage_v_76_2 + pub_r000072_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((sec_r000072_7_1 + pub_r000072_2_1) + 8) & 127;
  int stage_v_180_2 = ((sec_r000072_7_2 + pub_r000072_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_88_1 + pub_r000072_9_1) + 46) & 127;
  int stage_v_181_2 = ((stage_v_88_2 + pub_r000072_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((sec_r000072_11_1 + pub_r000072_16_1) + 14) & 127;
  int stage_v_182_2 = ((sec_r000072_11_2 + pub_r000072_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_170_1 + pub_r000072_8_1) + 7) & 127;
  int stage_v_183_2 = ((stage_v_170_2 + pub_r000072_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_102_1 + pub_r000072_12_1) + 10) & 127;
  int stage_v_184_2 = ((stage_v_102_2 + pub_r000072_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((sec_r000072_7_1 + pub_r000072_15_1) + 49) & 127;
  int stage_v_185_2 = ((sec_r000072_7_2 + pub_r000072_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((sec_r000072_10_1 + pub_r000072_7_1) + 48) & 127;
  int stage_v_186_2 = ((sec_r000072_10_2 + pub_r000072_7_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((sec_r000072_14_1 + pub_r000072_16_1) + 19) & 127;
  int stage_v_187_2 = ((sec_r000072_14_2 + pub_r000072_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_148_1 + pub_r000072_4_1) + 27) & 127;
  int stage_v_188_2 = ((stage_v_148_2 + pub_r000072_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_133_1 + pub_r000072_6_1) + 23) & 127;
  int stage_v_189_2 = ((stage_v_133_2 + pub_r000072_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((sec_r000072_3_1 + pub_r000072_7_1) + 23) & 127;
  int stage_v_190_2 = ((sec_r000072_3_2 + pub_r000072_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((sec_r000072_12_1 + pub_r000072_7_1) + 32) & 127;
  int stage_v_191_2 = ((sec_r000072_12_2 + pub_r000072_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000072_2_1 + pub_r000072_4_1) + 32) & 127;
  int stage_v_192_2 = ((sec_r000072_2_2 + pub_r000072_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((sec_r000072_12_1 + pub_r000072_14_1) + 35) & 127;
  int stage_v_193_2 = ((sec_r000072_12_2 + pub_r000072_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_137_1 + pub_r000072_11_1) + 44) & 127;
  int stage_v_194_2 = ((stage_v_137_2 + pub_r000072_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_143_1 + pub_r000072_10_1) + 30) & 127;
  int stage_v_195_2 = ((stage_v_143_2 + pub_r000072_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_91_1 + pub_r000072_2_1) + 6) & 127;
  int stage_v_196_2 = ((stage_v_91_2 + pub_r000072_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((stage_v_71_1 + pub_r000072_2_1) + 30) & 127;
  int stage_v_197_2 = ((stage_v_71_2 + pub_r000072_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_127_1 + pub_r000072_2_1) + 21) & 127;
  int stage_v_198_2 = ((stage_v_127_2 + pub_r000072_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_181_1 + pub_r000072_8_1) + 26) & 127;
  int stage_v_199_2 = ((stage_v_181_2 + pub_r000072_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_92_1 + pub_r000072_6_1) + 44) & 127;
  int stage_v_200_2 = ((stage_v_92_2 + pub_r000072_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_106_1 + pub_r000072_16_1) + 32) & 127;
  int stage_v_201_2 = ((stage_v_106_2 + pub_r000072_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((sec_r000072_6_1 + pub_r000072_4_1) + 27) & 127;
  int stage_v_202_2 = ((sec_r000072_6_2 + pub_r000072_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_116_1 + pub_r000072_13_1) + 30) & 127;
  int stage_v_203_2 = ((stage_v_116_2 + pub_r000072_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((sec_r000072_3_1 + pub_r000072_0_1) + 25) & 127;
  int stage_v_204_2 = ((sec_r000072_3_2 + pub_r000072_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((stage_v_117_1 + pub_r000072_15_1) + 46) & 127;
  int stage_v_205_2 = ((stage_v_117_2 + pub_r000072_15_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_73_1 + pub_r000072_11_1) + 10) & 127;
  int stage_v_206_2 = ((stage_v_73_2 + pub_r000072_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_175_1 + pub_r000072_7_1) + 25) & 127;
  int stage_v_207_2 = ((stage_v_175_2 + pub_r000072_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000072_10_1 + pub_r000072_9_1) + 7) & 127;
  int stage_v_208_2 = ((sec_r000072_10_2 + pub_r000072_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((sec_r000072_13_1 + pub_r000072_16_1) + 40) & 127;
  int stage_v_209_2 = ((sec_r000072_13_2 + pub_r000072_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_121_1 + pub_r000072_11_1) + 29) & 127;
  int stage_v_210_2 = ((stage_v_121_2 + pub_r000072_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((sec_r000072_7_1 + pub_r000072_13_1) + 38) & 127;
  int stage_v_211_2 = ((sec_r000072_7_2 + pub_r000072_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_143_1 + pub_r000072_16_1) + 23) & 127;
  int stage_v_212_2 = ((stage_v_143_2 + pub_r000072_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000072_7_1 + pub_r000072_1_1) + 21) & 127;
  int stage_v_213_2 = ((sec_r000072_7_2 + pub_r000072_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_61_1 + pub_r000072_6_1) + 41) & 127;
  int stage_v_214_2 = ((stage_v_61_2 + pub_r000072_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_176_1 + pub_r000072_1_1) + 48) & 127;
  int stage_v_215_2 = ((stage_v_176_2 + pub_r000072_1_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_62_1 + pub_r000072_13_1) + 13) & 127;
  int stage_v_216_2 = ((stage_v_62_2 + pub_r000072_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_125_1 + pub_r000072_15_1) + 20) & 127;
  int stage_v_217_2 = ((stage_v_125_2 + pub_r000072_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000072_10_1 + pub_r000072_15_1) + 6) & 127;
  int stage_v_218_2 = ((sec_r000072_10_2 + pub_r000072_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_71_1 + pub_r000072_12_1) + 34) & 127;
  int stage_v_219_2 = ((stage_v_71_2 + pub_r000072_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_218_1 + pub_r000072_4_1) + 42) & 127;
  int stage_v_220_2 = ((stage_v_218_2 + pub_r000072_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_168_1 + pub_r000072_0_1) + 37) & 127;
  int stage_v_221_2 = ((stage_v_168_2 + pub_r000072_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000072_8_1 + pub_r000072_4_1) + 37) & 127;
  int stage_v_222_2 = ((sec_r000072_8_2 + pub_r000072_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_195_1 + pub_r000072_16_1) + 41) & 127;
  int stage_v_223_2 = ((stage_v_195_2 + pub_r000072_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_128_1 + pub_r000072_10_1) + 34) & 127;
  int stage_v_224_2 = ((stage_v_128_2 + pub_r000072_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_161_1 + pub_r000072_3_1) + 13) & 127;
  int stage_v_225_2 = ((stage_v_161_2 + pub_r000072_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_81_1 + pub_r000072_3_1) + 7) & 127;
  int stage_v_226_2 = ((stage_v_81_2 + pub_r000072_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((sec_r000072_6_1 + pub_r000072_16_1) + 22) & 127;
  int stage_v_227_2 = ((sec_r000072_6_2 + pub_r000072_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_121_1 + pub_r000072_15_1) + 31) & 127;
  int stage_v_228_2 = ((stage_v_121_2 + pub_r000072_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((stage_v_98_1 + pub_r000072_6_1) + 43) & 127;
  int stage_v_229_2 = ((stage_v_98_2 + pub_r000072_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_100_1 + pub_r000072_12_1) + 47) & 127;
  int stage_v_230_2 = ((stage_v_100_2 + pub_r000072_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((stage_v_158_1 + pub_r000072_2_1) + 26) & 127;
  int stage_v_231_2 = ((stage_v_158_2 + pub_r000072_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((sec_r000072_4_1 + pub_r000072_13_1) + 45) & 127;
  int stage_v_232_2 = ((sec_r000072_4_2 + pub_r000072_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((stage_v_132_1 + pub_r000072_12_1) + 18) & 127;
  int stage_v_233_2 = ((stage_v_132_2 + pub_r000072_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_210_1 + pub_r000072_8_1) + 33) & 127;
  int stage_v_234_2 = ((stage_v_210_2 + pub_r000072_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((sec_r000072_9_1 + pub_r000072_12_1) + 36) & 127;
  int stage_v_235_2 = ((sec_r000072_9_2 + pub_r000072_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((stage_v_45_1 + pub_r000072_3_1) + 32) & 127;
  int stage_v_236_2 = ((stage_v_45_2 + pub_r000072_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_106_1 + pub_r000072_6_1) + 38) & 127;
  int stage_v_237_2 = ((stage_v_106_2 + pub_r000072_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((sec_r000072_2_1 + pub_r000072_0_1) + 42) & 127;
  int stage_v_238_2 = ((sec_r000072_2_2 + pub_r000072_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_192_1 + pub_r000072_5_1) + 30) & 127;
  int stage_v_239_2 = ((stage_v_192_2 + pub_r000072_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((stage_v_110_1 + pub_r000072_3_1) + 13) & 127;
  int stage_v_240_2 = ((stage_v_110_2 + pub_r000072_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((stage_v_87_1 + pub_r000072_9_1) + 22) & 127;
  int stage_v_241_2 = ((stage_v_87_2 + pub_r000072_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((sec_r000072_10_1 + pub_r000072_13_1) + 7) & 127;
  int stage_v_242_2 = ((sec_r000072_10_2 + pub_r000072_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((stage_v_76_1 + pub_r000072_6_1) + 10) & 127;
  int stage_v_243_2 = ((stage_v_76_2 + pub_r000072_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((stage_v_74_1 + pub_r000072_12_1) + 25) & 127;
  int stage_v_244_2 = ((stage_v_74_2 + pub_r000072_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((stage_v_160_1 + pub_r000072_13_1) + 48) & 127;
  int stage_v_245_2 = ((stage_v_160_2 + pub_r000072_13_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((stage_v_174_1 + pub_r000072_14_1) + 28) & 127;
  int stage_v_246_2 = ((stage_v_174_2 + pub_r000072_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((stage_v_245_1 + pub_r000072_11_1) + 33) & 127;
  int stage_v_247_2 = ((stage_v_245_2 + pub_r000072_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((stage_v_247_1 + pub_r000072_4_1) + 16) & 127;
  int stage_v_248_2 = ((stage_v_247_2 + pub_r000072_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_105_1 + pub_r000072_5_1) + 16) & 127;
  int stage_v_249_2 = ((stage_v_105_2 + pub_r000072_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_196_1 + pub_r000072_10_1) + 23) & 127;
  int stage_v_250_2 = ((stage_v_196_2 + pub_r000072_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((sec_r000072_3_1 + pub_r000072_4_1) + 19) & 127;
  int stage_v_251_2 = ((sec_r000072_3_2 + pub_r000072_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_211_1 + pub_r000072_0_1) + 40) & 127;
  int stage_v_252_2 = ((stage_v_211_2 + pub_r000072_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((sec_r000072_6_1 + pub_r000072_14_1) + 46) & 127;
  int stage_v_253_2 = ((sec_r000072_6_2 + pub_r000072_14_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_174_1 + pub_r000072_15_1) + 6) & 127;
  int stage_v_254_2 = ((stage_v_174_2 + pub_r000072_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((stage_v_168_1 + pub_r000072_1_1) + 6) & 127;
  int stage_v_255_2 = ((stage_v_168_2 + pub_r000072_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((sec_r000072_11_1 + pub_r000072_8_1) + 33) & 127;
  int stage_v_256_2 = ((sec_r000072_11_2 + pub_r000072_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((sec_r000072_3_1 + pub_r000072_9_1) + 27) & 127;
  int stage_v_257_2 = ((sec_r000072_3_2 + pub_r000072_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((stage_v_197_1 + pub_r000072_7_1) + 6) & 127;
  int stage_v_258_2 = ((stage_v_197_2 + pub_r000072_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((sec_r000072_5_1 + pub_r000072_11_1) + 10) & 127;
  int stage_v_259_2 = ((sec_r000072_5_2 + pub_r000072_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((stage_v_109_1 + pub_r000072_6_1) + 6) & 127;
  int stage_v_260_2 = ((stage_v_109_2 + pub_r000072_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((stage_v_158_1 + pub_r000072_12_1) + 38) & 127;
  int stage_v_261_2 = ((stage_v_158_2 + pub_r000072_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_170_1 + pub_r000072_13_1) + 5) & 127;
  int stage_v_262_2 = ((stage_v_170_2 + pub_r000072_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000072_15_1 + pub_r000072_9_1) + 37) & 127;
  int stage_v_263_2 = ((sec_r000072_15_2 + pub_r000072_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((stage_v_82_1 + pub_r000072_11_1) + 39) & 127;
  int stage_v_264_2 = ((stage_v_82_2 + pub_r000072_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((stage_v_254_1 + pub_r000072_8_1) + 27) & 127;
  int stage_v_265_2 = ((stage_v_254_2 + pub_r000072_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((stage_v_189_1 + pub_r000072_9_1) + 39) & 127;
  int stage_v_266_2 = ((stage_v_189_2 + pub_r000072_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000072_13_1 + pub_r000072_1_1) + 34) & 127;
  int stage_v_267_2 = ((sec_r000072_13_2 + pub_r000072_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((stage_v_190_1 + pub_r000072_8_1) + 42) & 127;
  int stage_v_268_2 = ((stage_v_190_2 + pub_r000072_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_48_1 + pub_r000072_10_1) + 40) & 127;
  int stage_v_269_2 = ((stage_v_48_2 + pub_r000072_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_50_1 + pub_r000072_6_1) + 38) & 127;
  int stage_v_270_2 = ((stage_v_50_2 + pub_r000072_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((stage_v_75_1 + pub_r000072_14_1) + 14) & 127;
  int stage_v_271_2 = ((stage_v_75_2 + pub_r000072_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((stage_v_139_1 + pub_r000072_10_1) + 38) & 127;
  int stage_v_272_2 = ((stage_v_139_2 + pub_r000072_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((stage_v_64_1 + pub_r000072_10_1) + 21) & 127;
  int stage_v_273_2 = ((stage_v_64_2 + pub_r000072_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((sec_r000072_14_1 + pub_r000072_9_1) + 48) & 127;
  int stage_v_274_2 = ((sec_r000072_14_2 + pub_r000072_9_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((stage_v_178_1 + pub_r000072_3_1) + 19) & 127;
  int stage_v_275_2 = ((stage_v_178_2 + pub_r000072_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((sec_r000072_1_1 + pub_r000072_16_1) + 10) & 127;
  int stage_v_276_2 = ((sec_r000072_1_2 + pub_r000072_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((sec_r000072_1_1 + pub_r000072_10_1) + 44) & 127;
  int stage_v_277_2 = ((sec_r000072_1_2 + pub_r000072_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((sec_r000072_6_1 + pub_r000072_15_1) + 38) & 127;
  int stage_v_278_2 = ((sec_r000072_6_2 + pub_r000072_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((sec_r000072_13_1 + pub_r000072_4_1) + 19) & 127;
  int stage_v_279_2 = ((sec_r000072_13_2 + pub_r000072_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((stage_v_200_1 + pub_r000072_8_1) + 41) & 127;
  int stage_v_280_2 = ((stage_v_200_2 + pub_r000072_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((sec_r000072_14_1 + pub_r000072_2_1) + 17) & 127;
  int stage_v_281_2 = ((sec_r000072_14_2 + pub_r000072_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((sec_r000072_2_1 + pub_r000072_6_1) + 34) & 127;
  int stage_v_282_2 = ((sec_r000072_2_2 + pub_r000072_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_251_1 + pub_r000072_6_1) + 20) & 127;
  int stage_v_283_2 = ((stage_v_251_2 + pub_r000072_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((stage_v_282_1 + pub_r000072_1_1) + 49) & 127;
  int stage_v_284_2 = ((stage_v_282_2 + pub_r000072_1_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((sec_r000072_8_1 + pub_r000072_9_1) + 48) & 127;
  int stage_v_285_2 = ((sec_r000072_8_2 + pub_r000072_9_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((stage_v_195_1 + pub_r000072_0_1) + 8) & 127;
  int stage_v_286_2 = ((stage_v_195_2 + pub_r000072_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_76_1 + pub_r000072_15_1) + 11) & 127;
  int stage_v_287_2 = ((stage_v_76_2 + pub_r000072_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((stage_v_90_1 + pub_r000072_14_1) + 19) & 127;
  int stage_v_288_2 = ((stage_v_90_2 + pub_r000072_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((sec_r000072_3_1 + pub_r000072_16_1) + 6) & 127;
  int stage_v_289_2 = ((sec_r000072_3_2 + pub_r000072_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((stage_v_162_1 + pub_r000072_1_1) + 43) & 127;
  int stage_v_290_2 = ((stage_v_162_2 + pub_r000072_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((stage_v_223_1 + pub_r000072_7_1) + 21) & 127;
  int stage_v_291_2 = ((stage_v_223_2 + pub_r000072_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((sec_r000072_9_1 + pub_r000072_11_1) + 35) & 127;
  int stage_v_292_2 = ((sec_r000072_9_2 + pub_r000072_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((sec_r000072_16_1 + pub_r000072_8_1) + 28) & 127;
  int stage_v_293_2 = ((sec_r000072_16_2 + pub_r000072_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((sec_r000072_3_1 + pub_r000072_0_1) + 35) & 127;
  int stage_v_294_2 = ((sec_r000072_3_2 + pub_r000072_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((sec_r000072_2_1 + pub_r000072_9_1) + 48) & 127;
  int stage_v_295_2 = ((sec_r000072_2_2 + pub_r000072_9_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_231_1 + pub_r000072_16_1) + 45) & 127;
  int stage_v_296_2 = ((stage_v_231_2 + pub_r000072_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_163_1 + pub_r000072_15_1) + 15) & 127;
  int stage_v_297_2 = ((stage_v_163_2 + pub_r000072_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((stage_v_98_1 + pub_r000072_9_1) + 25) & 127;
  int stage_v_298_2 = ((stage_v_98_2 + pub_r000072_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_229_1 + pub_r000072_10_1) + 27) & 127;
  int stage_v_299_2 = ((stage_v_229_2 + pub_r000072_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((stage_v_69_1 + pub_r000072_4_1) + 14) & 127;
  int stage_v_300_2 = ((stage_v_69_2 + pub_r000072_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((sec_r000072_3_1 + pub_r000072_13_1) + 27) & 127;
  int stage_v_301_2 = ((sec_r000072_3_2 + pub_r000072_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_209_1 + pub_r000072_10_1) + 16) & 127;
  int stage_v_302_2 = ((stage_v_209_2 + pub_r000072_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((stage_v_295_1 + pub_r000072_1_1) + 26) & 127;
  int stage_v_303_2 = ((stage_v_295_2 + pub_r000072_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((stage_v_194_1 + pub_r000072_16_1) + 44) & 127;
  int stage_v_304_2 = ((stage_v_194_2 + pub_r000072_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_58_1 + pub_r000072_13_1) + 4) & 127;
  int stage_v_305_2 = ((stage_v_58_2 + pub_r000072_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((stage_v_125_1 + pub_r000072_15_1) + 8) & 127;
  int stage_v_306_2 = ((stage_v_125_2 + pub_r000072_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((stage_v_57_1 + pub_r000072_9_1) + 46) & 127;
  int stage_v_307_2 = ((stage_v_57_2 + pub_r000072_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((sec_r000072_13_1 + pub_r000072_13_1) + 37) & 127;
  int stage_v_308_2 = ((sec_r000072_13_2 + pub_r000072_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((sec_r000072_14_1 + pub_r000072_12_1) + 5) & 127;
  int stage_v_309_2 = ((sec_r000072_14_2 + pub_r000072_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((sec_r000072_11_1 + pub_r000072_15_1) + 13) & 127;
  int stage_v_310_2 = ((sec_r000072_11_2 + pub_r000072_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((stage_v_261_1 + pub_r000072_5_1) + 24) & 127;
  int stage_v_311_2 = ((stage_v_261_2 + pub_r000072_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((stage_v_294_1 + pub_r000072_3_1) + 17) & 127;
  int stage_v_312_2 = ((stage_v_294_2 + pub_r000072_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((stage_v_238_1 + pub_r000072_3_1) + 33) & 127;
  int stage_v_313_2 = ((stage_v_238_2 + pub_r000072_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((sec_r000072_1_1 + pub_r000072_7_1) + 46) & 127;
  int stage_v_314_2 = ((sec_r000072_1_2 + pub_r000072_7_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((sec_r000072_10_1 + pub_r000072_13_1) + 18) & 127;
  int stage_v_315_2 = ((sec_r000072_10_2 + pub_r000072_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((sec_r000072_1_1 + pub_r000072_10_1) + 31) & 127;
  int stage_v_316_2 = ((sec_r000072_1_2 + pub_r000072_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((sec_r000072_15_1 + pub_r000072_6_1) + 16) & 127;
  int stage_v_317_2 = ((sec_r000072_15_2 + pub_r000072_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((stage_v_298_1 + pub_r000072_5_1) + 12) & 127;
  int stage_v_318_2 = ((stage_v_298_2 + pub_r000072_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((stage_v_216_1 + pub_r000072_13_1) + 27) & 127;
  int stage_v_319_2 = ((stage_v_216_2 + pub_r000072_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((sec_r000072_15_1 + pub_r000072_13_1) + 40) & 127;
  int stage_v_320_2 = ((sec_r000072_15_2 + pub_r000072_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((sec_r000072_3_1 + pub_r000072_5_1) + 39) & 127;
  int stage_v_321_2 = ((sec_r000072_3_2 + pub_r000072_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((stage_v_282_1 + pub_r000072_8_1) + 38) & 127;
  int stage_v_322_2 = ((stage_v_282_2 + pub_r000072_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((sec_r000072_3_1 + pub_r000072_0_1) + 12) & 127;
  int stage_v_323_2 = ((sec_r000072_3_2 + pub_r000072_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((stage_v_300_1 + pub_r000072_4_1) + 49) & 127;
  int stage_v_324_2 = ((stage_v_300_2 + pub_r000072_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((sec_r000072_14_1 + pub_r000072_12_1) + 49) & 127;
  int stage_v_325_2 = ((sec_r000072_14_2 + pub_r000072_12_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((stage_v_119_1 + pub_r000072_14_1) + 6) & 127;
  int stage_v_326_2 = ((stage_v_119_2 + pub_r000072_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((stage_v_269_1 + pub_r000072_7_1) + 21) & 127;
  int stage_v_327_2 = ((stage_v_269_2 + pub_r000072_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((sec_r000072_0_1 + pub_r000072_10_1) + 43) & 127;
  int stage_v_328_2 = ((sec_r000072_0_2 + pub_r000072_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((stage_v_253_1 + pub_r000072_10_1) + 9) & 127;
  int stage_v_329_2 = ((stage_v_253_2 + pub_r000072_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((stage_v_299_1 + pub_r000072_2_1) + 47) & 127;
  int stage_v_330_2 = ((stage_v_299_2 + pub_r000072_2_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((stage_v_92_1 + pub_r000072_11_1) + 30) & 127;
  int stage_v_331_2 = ((stage_v_92_2 + pub_r000072_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((stage_v_165_1 + pub_r000072_3_1) + 20) & 127;
  int stage_v_332_2 = ((stage_v_165_2 + pub_r000072_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((stage_v_65_1 + pub_r000072_0_1) + 38) & 127;
  int stage_v_333_2 = ((stage_v_65_2 + pub_r000072_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((stage_v_107_1 + pub_r000072_8_1) + 34) & 127;
  int stage_v_334_2 = ((stage_v_107_2 + pub_r000072_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((sec_r000072_2_1 + pub_r000072_12_1) + 20) & 127;
  int stage_v_335_2 = ((sec_r000072_2_2 + pub_r000072_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((sec_r000072_15_1 + pub_r000072_3_1) + 46) & 127;
  int stage_v_336_2 = ((sec_r000072_15_2 + pub_r000072_3_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((sec_r000072_12_1 + pub_r000072_9_1) + 44) & 127;
  int stage_v_337_2 = ((sec_r000072_12_2 + pub_r000072_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((stage_v_92_1 + pub_r000072_9_1) + 35) & 127;
  int stage_v_338_2 = ((stage_v_92_2 + pub_r000072_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((sec_r000072_14_1 + pub_r000072_5_1) + 29) & 127;
  int stage_v_339_2 = ((sec_r000072_14_2 + pub_r000072_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((stage_v_172_1 + pub_r000072_5_1) + 6) & 127;
  int stage_v_340_2 = ((stage_v_172_2 + pub_r000072_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((stage_v_197_1 + pub_r000072_14_1) + 26) & 127;
  int stage_v_341_2 = ((stage_v_197_2 + pub_r000072_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((stage_v_83_1 + pub_r000072_10_1) + 35) & 127;
  int stage_v_342_2 = ((stage_v_83_2 + pub_r000072_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((stage_v_184_1 + pub_r000072_16_1) + 23) & 127;
  int stage_v_343_2 = ((stage_v_184_2 + pub_r000072_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((stage_v_333_1 + pub_r000072_7_1) + 26) & 127;
  int stage_v_344_2 = ((stage_v_333_2 + pub_r000072_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((sec_r000072_2_1 + pub_r000072_3_1) + 3) & 127;
  int stage_v_345_2 = ((sec_r000072_2_2 + pub_r000072_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((stage_v_122_1 + pub_r000072_14_1) + 12) & 127;
  int stage_v_346_2 = ((stage_v_122_2 + pub_r000072_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((stage_v_129_1 + pub_r000072_2_1) + 4) & 127;
  int stage_v_347_2 = ((stage_v_129_2 + pub_r000072_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((stage_v_198_1 + pub_r000072_6_1) + 49) & 127;
  int stage_v_348_2 = ((stage_v_198_2 + pub_r000072_6_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((sec_r000072_16_1 + pub_r000072_9_1) + 44) & 127;
  int stage_v_349_2 = ((sec_r000072_16_2 + pub_r000072_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((stage_v_323_1 + pub_r000072_14_1) + 40) & 127;
  int stage_v_350_2 = ((stage_v_323_2 + pub_r000072_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((sec_r000072_3_1 + pub_r000072_12_1) + 15) & 127;
  int stage_v_351_2 = ((sec_r000072_3_2 + pub_r000072_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((stage_v_275_1 + pub_r000072_0_1) + 48) & 127;
  int stage_v_352_2 = ((stage_v_275_2 + pub_r000072_0_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((stage_v_88_1 + pub_r000072_1_1) + 41) & 127;
  int stage_v_353_2 = ((stage_v_88_2 + pub_r000072_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((sec_r000072_16_1 + pub_r000072_1_1) + 11) & 127;
  int stage_v_354_2 = ((sec_r000072_16_2 + pub_r000072_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((stage_v_297_1 + pub_r000072_14_1) + 37) & 127;
  int stage_v_355_2 = ((stage_v_297_2 + pub_r000072_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((stage_v_194_1 + pub_r000072_1_1) + 42) & 127;
  int stage_v_356_2 = ((stage_v_194_2 + pub_r000072_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((stage_v_185_1 + pub_r000072_13_1) + 23) & 127;
  int stage_v_357_2 = ((stage_v_185_2 + pub_r000072_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((stage_v_354_1 + pub_r000072_0_1) + 9) & 127;
  int stage_v_358_2 = ((stage_v_354_2 + pub_r000072_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((sec_r000072_15_1 + pub_r000072_14_1) + 41) & 127;
  int stage_v_359_2 = ((sec_r000072_15_2 + pub_r000072_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((stage_v_70_1 + pub_r000072_9_1) + 46) & 127;
  int stage_v_360_2 = ((stage_v_70_2 + pub_r000072_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((sec_r000072_8_1 + pub_r000072_8_1) + 20) & 127;
  int stage_v_361_2 = ((sec_r000072_8_2 + pub_r000072_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((sec_r000072_12_1 + pub_r000072_13_1) + 30) & 127;
  int stage_v_362_2 = ((sec_r000072_12_2 + pub_r000072_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((stage_v_261_1 + pub_r000072_4_1) + 16) & 127;
  int stage_v_363_2 = ((stage_v_261_2 + pub_r000072_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((stage_v_66_1 + pub_r000072_7_1) + 28) & 127;
  int stage_v_364_2 = ((stage_v_66_2 + pub_r000072_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((stage_v_234_1 + pub_r000072_4_1) + 3) & 127;
  int stage_v_365_2 = ((stage_v_234_2 + pub_r000072_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((stage_v_201_1 + pub_r000072_14_1) + 46) & 127;
  int stage_v_366_2 = ((stage_v_201_2 + pub_r000072_14_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((stage_v_213_1 + pub_r000072_0_1) + 25) & 127;
  int stage_v_367_2 = ((stage_v_213_2 + pub_r000072_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((stage_v_178_1 + pub_r000072_12_1) + 26) & 127;
  int stage_v_368_2 = ((stage_v_178_2 + pub_r000072_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((stage_v_250_1 + pub_r000072_10_1) + 3) & 127;
  int stage_v_369_2 = ((stage_v_250_2 + pub_r000072_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((sec_r000072_10_1 + pub_r000072_10_1) + 26) & 127;
  int stage_v_370_2 = ((sec_r000072_10_2 + pub_r000072_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((sec_r000072_9_1 + pub_r000072_6_1) + 18) & 127;
  int stage_v_371_2 = ((sec_r000072_9_2 + pub_r000072_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((sec_r000072_4_1 + pub_r000072_13_1) + 15) & 127;
  int stage_v_372_2 = ((sec_r000072_4_2 + pub_r000072_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((stage_v_361_1 + pub_r000072_7_1) + 8) & 127;
  int stage_v_373_2 = ((stage_v_361_2 + pub_r000072_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((stage_v_230_1 + pub_r000072_16_1) + 9) & 127;
  int stage_v_374_2 = ((stage_v_230_2 + pub_r000072_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((stage_v_73_1 + pub_r000072_16_1) + 13) & 127;
  int stage_v_375_2 = ((stage_v_73_2 + pub_r000072_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((sec_r000072_8_1 + pub_r000072_2_1) + 18) & 127;
  int stage_v_376_2 = ((sec_r000072_8_2 + pub_r000072_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((stage_v_270_1 + pub_r000072_7_1) + 15) & 127;
  int stage_v_377_2 = ((stage_v_270_2 + pub_r000072_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((sec_r000072_17_1 + pub_r000072_2_1) + 3) & 127;
  int stage_v_378_2 = ((sec_r000072_17_2 + pub_r000072_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((stage_v_128_1 + pub_r000072_16_1) + 21) & 127;
  int stage_v_379_2 = ((stage_v_128_2 + pub_r000072_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((stage_v_342_1 + pub_r000072_3_1) + 17) & 127;
  int stage_v_380_2 = ((stage_v_342_2 + pub_r000072_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((stage_v_256_1 + pub_r000072_10_1) + 41) & 127;
  int stage_v_381_2 = ((stage_v_256_2 + pub_r000072_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((stage_v_355_1 + pub_r000072_13_1) + 27) & 127;
  int stage_v_382_2 = ((stage_v_355_2 + pub_r000072_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((stage_v_47_1 + pub_r000072_0_1) + 42) & 127;
  int stage_v_383_2 = ((stage_v_47_2 + pub_r000072_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((sec_r000072_13_1 + pub_r000072_8_1) + 17) & 127;
  int stage_v_384_2 = ((sec_r000072_13_2 + pub_r000072_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((sec_r000072_8_1 + pub_r000072_5_1) + 25) & 127;
  int stage_v_385_2 = ((sec_r000072_8_2 + pub_r000072_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((stage_v_241_1 + pub_r000072_12_1) + 47) & 127;
  int stage_v_386_2 = ((stage_v_241_2 + pub_r000072_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((stage_v_124_1 + pub_r000072_4_1) + 49) & 127;
  int stage_v_387_2 = ((stage_v_124_2 + pub_r000072_4_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((stage_v_227_1 + pub_r000072_9_1) + 23) & 127;
  int stage_v_388_2 = ((stage_v_227_2 + pub_r000072_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((stage_v_377_1 + pub_r000072_9_1) + 41) & 127;
  int stage_v_389_2 = ((stage_v_377_2 + pub_r000072_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((sec_r000072_13_1 + pub_r000072_1_1) + 18) & 127;
  int stage_v_390_2 = ((sec_r000072_13_2 + pub_r000072_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((sec_r000072_17_1 + pub_r000072_8_1) + 37) & 127;
  int stage_v_391_2 = ((sec_r000072_17_2 + pub_r000072_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((sec_r000072_6_1 + pub_r000072_10_1) + 17) & 127;
  int stage_v_392_2 = ((sec_r000072_6_2 + pub_r000072_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((stage_v_375_1 + pub_r000072_12_1) + 49) & 127;
  int stage_v_393_2 = ((stage_v_375_2 + pub_r000072_12_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((stage_v_267_1 + pub_r000072_8_1) + 25) & 127;
  int stage_v_394_2 = ((stage_v_267_2 + pub_r000072_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000072_1_1 != sec_r000072_1_2);
  __CPROVER_assume(sec_r000072_6_1 != sec_r000072_6_2);
  __CPROVER_assume(pub_r000072_15_1 == pub_r000072_15_2);
  __CPROVER_assume(sec_r000072_16_1 != sec_r000072_16_2);
  __CPROVER_assume(sec_r000072_9_1 != sec_r000072_9_2);
  __CPROVER_assume(pub_r000072_13_1 == pub_r000072_13_2);
  __CPROVER_assume(sec_r000072_0_1 != sec_r000072_0_2);
  __CPROVER_assume(pub_r000072_7_1 == pub_r000072_7_2);
  __CPROVER_assume(sec_r000072_11_1 != sec_r000072_11_2);
  __CPROVER_assume(pub_r000072_16_1 == pub_r000072_16_2);
  __CPROVER_assume(pub_r000072_5_1 == pub_r000072_5_2);
  __CPROVER_assume(sec_r000072_14_1 != sec_r000072_14_2);
  __CPROVER_assume(sec_r000072_4_1 != sec_r000072_4_2);
  __CPROVER_assume(pub_r000072_9_1 == pub_r000072_9_2);
  __CPROVER_assume(sec_r000072_5_1 != sec_r000072_5_2);
  __CPROVER_assume(pub_r000072_3_1 == pub_r000072_3_2);
  __CPROVER_assume(pub_r000072_2_1 == pub_r000072_2_2);
  __CPROVER_assume(sec_r000072_8_1 != sec_r000072_8_2);
  __CPROVER_assume(sec_r000072_15_1 != sec_r000072_15_2);
  __CPROVER_assume(sec_r000072_10_1 != sec_r000072_10_2);
  __CPROVER_assume(pub_r000072_6_1 == pub_r000072_6_2);
  __CPROVER_assume(pub_r000072_1_1 == pub_r000072_1_2);
  __CPROVER_assume(pub_r000072_12_1 == pub_r000072_12_2);
  __CPROVER_assume(sec_r000072_12_1 != sec_r000072_12_2);
  __CPROVER_assume(pub_r000072_4_1 == pub_r000072_4_2);
  __CPROVER_assume(sec_r000072_2_1 != sec_r000072_2_2);
  __CPROVER_assume(sec_r000072_13_1 != sec_r000072_13_2);
  __CPROVER_assume(pub_r000072_11_1 == pub_r000072_11_2);
  __CPROVER_assume(sec_r000072_3_1 != sec_r000072_3_2);
  __CPROVER_assume(pub_r000072_0_1 == pub_r000072_0_2);
  __CPROVER_assume(pub_r000072_14_1 == pub_r000072_14_2);
  __CPROVER_assume(pub_r000072_10_1 == pub_r000072_10_2);
  __CPROVER_assume(pub_r000072_8_1 == pub_r000072_8_2);
  __CPROVER_assume(sec_r000072_17_1 != sec_r000072_17_2);
  __CPROVER_assume(sec_r000072_7_1 != sec_r000072_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
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
}


