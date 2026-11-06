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
struct FilterState_R000597_9713_0
{
  int prev_in;
  int gain_db;
  unsigned char prev_out;
  short mode;
  int buffer[3];
};
struct StreamBuffer_R000597_9713_1
{
  int watermark;
  short state;
  short head;
  unsigned char checksum;
  unsigned char tail;
  int capacity;
  int buffer[3];
};
struct SensorNode_R000597_9713_2
{
  int gain;
  int status;
  unsigned char threshold;
  int buffer[3];
};
union ColorPixel_R000597_9713_0
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
void fn_R000597_9713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st_1 = {0};
  struct StreamBuffer_R000597_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_47_1 = local_arr_1[aux_1 % 3];
  int delta_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_85_1 > 39)
  {
    acc_1 = ((acc_1 + (cursor_85_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_85_2 > 39)
  {
    acc_2 = ((acc_2 + (cursor_85_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_29_1)
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

  switch (vector_29_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
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

  assert(delta_47_1 == delta_47_2);
  assert(cursor_85_1 == cursor_85_2);
  assert(vector_29_1 == vector_29_2);
}

int fn_R000597_9713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int delta_47 = local_arr[aux % 3];
  acc = (acc + (delta_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_85 > 39)
  {
    acc = ((acc + (cursor_85 * 2)) + 5) & 127;
    aux ^= cursor_85 & 15;
  }
  else
  {
    acc = ((acc - cursor_85) + 11) & 127;
    aux += 3;
  }
  int vector_29 = (aux + st.buffer[1]) & 3;
  switch (vector_29)
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

void fn_R000597_9713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st_1 = {0};
  struct FilterState_R000597_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_93_1 = local_arr_1[aux_1 % 3];
  int factor_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_93_2 * 2)) & 127;
  int accumulator_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_81_1)
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

  switch (accumulator_81_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_93_1 == factor_93_2);
  assert(accumulator_81_1 == accumulator_81_2);
}

int fn_R000597_9713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int factor_93 = local_arr[aux % 3];
  acc = (acc + (factor_93 * 2)) & 127;
  int accumulator_81 = (aux + st.buffer[1]) & 3;
  switch (accumulator_81)
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

void fn_R000597_9713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_24_1 = local_arr_1[aux_1 % 3];
  int window_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_24_2 * 2)) & 127;
  int tally_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_17_1) & 63;
  aux_2 = (aux_2 + tally_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_18_1)
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

  switch (damping_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_24_1 == window_24_2);
  assert(tally_17_1 == tally_17_2);
  assert(damping_18_1 == damping_18_2);
}

int fn_R000597_9713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int window_24 = local_arr[aux % 3];
  acc = (acc + (window_24 * 2)) & 127;
  int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_17) & 63;
  acc ^= aux;
  int damping_18 = (aux + st.buffer[1]) & 3;
  switch (damping_18)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st_1 = {0};
  struct FilterState_R000597_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int accumulator_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_37_1) & 63;
  aux_2 = (aux_2 + accumulator_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_51_1 > 45)
  {
    acc_1 = ((acc_1 + (tally_51_1 * 2)) + 5) & 127;
    aux_1 ^= tally_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_51_2 > 45)
  {
    acc_2 = ((acc_2 + (tally_51_2 * 2)) + 5) & 127;
    aux_2 ^= tally_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_79_1 = local_arr_1[aux_1 % 3];
  int accumulator_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_37_1 == accumulator_37_2);
  assert(tally_51_1 == tally_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_79_1 == accumulator_79_2);
}

int fn_R000597_9713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int accumulator_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_37) & 63;
  acc ^= aux;
  int tally_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_51 > 45)
  {
    acc = ((acc + (tally_51 * 2)) + 5) & 127;
    aux ^= tally_51 & 15;
  }
  else
  {
    acc = ((acc - tally_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_79 = local_arr[aux % 3];
  acc = (acc + (accumulator_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st_1 = {0};
  struct FilterState_R000597_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int parity_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_72_1)
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

  switch (parity_72_2)
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
  int pivot_72_1 = local_arr_1[aux_1 % 3];
  int pivot_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_72_2 * 2)) & 127;
  int mask_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_94_1) & 63;
  aux_2 = (aux_2 + mask_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_72_1 == parity_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_72_1 == pivot_72_2);
  assert(mask_94_1 == mask_94_2);
}

int fn_R000597_9713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int parity_72 = (aux + st.buffer[1]) & 3;
  switch (parity_72)
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
  int pivot_72 = local_arr[aux % 3];
  acc = (acc + (pivot_72 * 2)) & 127;
  int mask_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000597_9713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int bound_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_69_1 > 41)
  {
    acc_1 = ((acc_1 + (bound_69_1 * 2)) + 5) & 127;
    aux_1 ^= bound_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_69_2 > 41)
  {
    acc_2 = ((acc_2 + (bound_69_2 * 2)) + 5) & 127;
    aux_2 ^= bound_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_57_1)
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

  switch (index_reg_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_80_1) & 63;
  aux_2 = (aux_2 + tally_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_69_1 == bound_69_2);
  assert(index_reg_57_1 == index_reg_57_2);
  assert(tally_80_1 == tally_80_2);
}

int fn_R000597_9713_5(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int bound_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_69 > 41)
  {
    acc = ((acc + (bound_69 * 2)) + 5) & 127;
    aux ^= bound_69 & 15;
  }
  else
  {
    acc = ((acc - bound_69) + 11) & 127;
    aux += 3;
  }
  int index_reg_57 = (aux + st.buffer[1]) & 3;
  switch (index_reg_57)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000597_9713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_24_1 > 32)
  {
    acc_1 = ((acc_1 + (quantum_24_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_24_2 > 32)
  {
    acc_2 = ((acc_2 + (quantum_24_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_48_1) & 63;
  aux_2 = (aux_2 + margin_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_17_1)
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

  switch (parity_17_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_24_1 == quantum_24_2);
  assert(margin_48_1 == margin_48_2);
  assert(parity_17_1 == parity_17_2);
}

int fn_R000597_9713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_24 > 32)
  {
    acc = ((acc + (quantum_24 * 2)) + 5) & 127;
    aux ^= quantum_24 & 15;
  }
  else
  {
    acc = ((acc - quantum_24) + 11) & 127;
    aux += 3;
  }
  int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_48) & 63;
  acc ^= aux;
  int parity_17 = (aux + st.buffer[1]) & 3;
  switch (parity_17)
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

void fn_R000597_9713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_57_1 = local_arr_1[aux_1 % 3];
  int damping_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_57_1 == damping_57_2);
}

int fn_R000597_9713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_57 = local_arr[aux % 3];
  acc = (acc + (damping_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_11_1) & 63;
  aux_2 = (aux_2 + threshold_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_75_1 = local_arr_1[aux_1 % 3];
  int bound_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_75_2 * 2)) & 127;
  int segment_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_38_1)
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

  switch (segment_38_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_11_1 == threshold_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_75_1 == bound_75_2);
  assert(segment_38_1 == segment_38_2);
}

int fn_R000597_9713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_75 = local_arr[aux % 3];
  acc = (acc + (bound_75 * 2)) & 127;
  int segment_38 = (aux + st.buffer[1]) & 3;
  switch (segment_38)
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

void fn_R000597_9713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st_1 = {0};
  struct StreamBuffer_R000597_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_56_1 = local_arr_1[aux_1 % 3];
  int delta_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_56_2 * 2)) & 127;
  int mask_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_49_1)
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

  switch (mask_49_2)
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

  int anchor_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_87_1 > 32)
  {
    acc_1 = ((acc_1 + (anchor_87_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_87_2 > 32)
  {
    acc_2 = ((acc_2 + (anchor_87_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
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

  assert(delta_56_1 == delta_56_2);
  assert(mask_49_1 == mask_49_2);
  assert(anchor_87_1 == anchor_87_2);
}

int fn_R000597_9713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int delta_56 = local_arr[aux % 3];
  acc = (acc + (delta_56 * 2)) & 127;
  int mask_49 = (aux + st.buffer[1]) & 3;
  switch (mask_49)
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

  int anchor_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_87 > 32)
  {
    acc = ((acc + (anchor_87 * 2)) + 5) & 127;
    aux ^= anchor_87 & 15;
  }
  else
  {
    acc = ((acc - anchor_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000597_9713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st_1 = {0};
  struct FilterState_R000597_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_79_1)
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

  switch (anchor_79_2)
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
  int accumulator_85_1 = local_arr_1[aux_1 % 3];
  int accumulator_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_85_2 * 2)) & 127;
  int coefficient_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_87_1 > 41)
  {
    acc_1 = ((acc_1 + (coefficient_87_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_87_2 > 41)
  {
    acc_2 = ((acc_2 + (coefficient_87_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_79_1 == anchor_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
  assert(coefficient_87_1 == coefficient_87_2);
}

int fn_R000597_9713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_79 = (aux + st.buffer[1]) & 3;
  switch (anchor_79)
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
  int accumulator_85 = local_arr[aux % 3];
  acc = (acc + (accumulator_85 * 2)) & 127;
  int coefficient_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_87 > 41)
  {
    acc = ((acc + (coefficient_87 * 2)) + 5) & 127;
    aux ^= coefficient_87 & 15;
  }
  else
  {
    acc = ((acc - coefficient_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000597_9713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int metric_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_86_1) & 63;
  aux_2 = (aux_2 + metric_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_55_1 > 22)
  {
    acc_1 = ((acc_1 + (bound_55_1 * 2)) + 5) & 127;
    aux_1 ^= bound_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_55_2 > 22)
  {
    acc_2 = ((acc_2 + (bound_55_2 * 2)) + 5) & 127;
    aux_2 ^= bound_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_71_1 = local_arr_1[aux_1 % 3];
  int index_reg_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_86_1 == metric_86_2);
  assert(bound_55_1 == bound_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R000597_9713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int metric_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_55 > 22)
  {
    acc = ((acc + (bound_55 * 2)) + 5) & 127;
    aux ^= bound_55 & 15;
  }
  else
  {
    acc = ((acc - bound_55) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_71 = local_arr[aux % 3];
  acc = (acc + (index_reg_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_63_1 = local_arr_1[aux_1 % 3];
  int checksum_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_63_2 * 2)) & 127;
  int index_reg_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_80_1) & 63;
  aux_2 = (aux_2 + index_reg_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(index_reg_80_1 == index_reg_80_2);
}

int fn_R000597_9713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int checksum_63 = local_arr[aux % 3];
  acc = (acc + (checksum_63 * 2)) & 127;
  int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000597_9713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_22_1 = local_arr_1[aux_1 % 3];
  int weight_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_22_1 == weight_22_2);
}

int fn_R000597_9713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int weight_22 = local_arr[aux % 3];
  acc = (acc + (weight_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st_1 = {0};
  struct StreamBuffer_R000597_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_12_1) & 63;
  aux_2 = (aux_2 + residue_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_56_1 > 44)
  {
    acc_1 = ((acc_1 + (cursor_56_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_56_2 > 44)
  {
    acc_2 = ((acc_2 + (cursor_56_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_12_1 == residue_12_2);
  assert(cursor_56_1 == cursor_56_2);
}

int fn_R000597_9713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_56 > 44)
  {
    acc = ((acc + (cursor_56 * 2)) + 5) & 127;
    aux ^= cursor_56 & 15;
  }
  else
  {
    acc = ((acc - cursor_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000597_9713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st_1 = {0};
  struct SensorNode_R000597_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_83_1 > 28)
  {
    acc_1 = ((acc_1 + (cursor_83_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_83_2 > 28)
  {
    acc_2 = ((acc_2 + (cursor_83_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_83_1 == cursor_83_2);
}

int fn_R000597_9713_15(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000597_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_83 > 28)
  {
    acc = ((acc + (cursor_83 * 2)) + 5) & 127;
    aux ^= cursor_83 & 15;
  }
  else
  {
    acc = ((acc - cursor_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000597_9713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st_1 = {0};
  struct FilterState_R000597_9713_0 st_2 = {0};
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
  int checksum_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_42_1) & 63;
  aux_2 = (aux_2 + checksum_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_11_1 > 15)
  {
    acc_1 = ((acc_1 + (accumulator_11_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_11_2 > 15)
  {
    acc_2 = ((acc_2 + (accumulator_11_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_11_1 = local_arr_1[aux_1 % 3];
  int tally_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_42_1 == checksum_42_2);
  assert(accumulator_11_1 == accumulator_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_11_1 == tally_11_2);
}

int fn_R000597_9713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000597_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_42) & 63;
  acc ^= aux;
  int accumulator_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_11 > 15)
  {
    acc = ((acc + (accumulator_11 * 2)) + 5) & 127;
    aux ^= accumulator_11 & 15;
  }
  else
  {
    acc = ((acc - accumulator_11) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_11 = local_arr[aux % 3];
  acc = (acc + (tally_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000597_9713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st_1 = {0};
  struct StreamBuffer_R000597_9713_1 st_2 = {0};
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
  int tally_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_15_1 > 38)
  {
    acc_1 = ((acc_1 + (tally_15_1 * 2)) + 5) & 127;
    aux_1 ^= tally_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_15_2 > 38)
  {
    acc_2 = ((acc_2 + (tally_15_2 * 2)) + 5) & 127;
    aux_2 ^= tally_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_15_1 == tally_15_2);
}

int fn_R000597_9713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000597_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_15 > 38)
  {
    acc = ((acc + (tally_15 * 2)) + 5) & 127;
    aux ^= tally_15 & 15;
  }
  else
  {
    acc = ((acc - tally_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000597_0_1;
  int sec_r000597_0_2;
  int sec_r000597_1_1;
  int sec_r000597_1_2;
  int sec_r000597_2_1;
  int sec_r000597_2_2;
  int sec_r000597_3_1;
  int sec_r000597_3_2;
  int sec_r000597_4_1;
  int sec_r000597_4_2;
  int sec_r000597_5_1;
  int sec_r000597_5_2;
  int sec_r000597_6_1;
  int sec_r000597_6_2;
  int sec_r000597_7_1;
  int sec_r000597_7_2;
  int sec_r000597_8_1;
  int sec_r000597_8_2;
  int sec_r000597_9_1;
  int sec_r000597_9_2;
  int sec_r000597_10_1;
  int sec_r000597_10_2;
  int sec_r000597_11_1;
  int sec_r000597_11_2;
  int sec_r000597_12_1;
  int sec_r000597_12_2;
  int sec_r000597_13_1;
  int sec_r000597_13_2;
  int sec_r000597_14_1;
  int sec_r000597_14_2;
  int sec_r000597_15_1;
  int sec_r000597_15_2;
  int sec_r000597_16_1;
  int sec_r000597_16_2;
  int sec_r000597_17_1;
  int sec_r000597_17_2;
  int pub_r000597_0_1;
  int pub_r000597_0_2;
  int pub_r000597_1_1;
  int pub_r000597_1_2;
  int pub_r000597_2_1;
  int pub_r000597_2_2;
  int pub_r000597_3_1;
  int pub_r000597_3_2;
  int pub_r000597_4_1;
  int pub_r000597_4_2;
  int pub_r000597_5_1;
  int pub_r000597_5_2;
  int pub_r000597_6_1;
  int pub_r000597_6_2;
  int pub_r000597_7_1;
  int pub_r000597_7_2;
  int pub_r000597_8_1;
  int pub_r000597_8_2;
  int pub_r000597_9_1;
  int pub_r000597_9_2;
  int pub_r000597_10_1;
  int pub_r000597_10_2;
  int pub_r000597_11_1;
  int pub_r000597_11_2;
  int pub_r000597_12_1;
  int pub_r000597_12_2;
  int pub_r000597_13_1;
  int pub_r000597_13_2;
  int pub_r000597_14_1;
  int pub_r000597_14_2;
  int pub_r000597_15_1;
  int pub_r000597_15_2;
  int pub_r000597_16_1;
  int pub_r000597_16_2;
  int pub_r000597_17_1;
  int pub_r000597_17_2;
  int pub_r000597_18_1;
  int pub_r000597_18_2;
  int pub_r000597_19_1;
  int pub_r000597_19_2;
  int pub_r000597_20_1;
  int pub_r000597_20_2;
  int pub_r000597_21_1;
  int pub_r000597_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000597_0_1 >= (-100)) && (pub_r000597_0_1 <= 100));
  __CPROVER_assume((pub_r000597_0_2 >= (-100)) && (pub_r000597_0_2 <= 100));
  __CPROVER_assume((pub_r000597_1_1 >= (-100)) && (pub_r000597_1_1 <= 100));
  __CPROVER_assume((pub_r000597_1_2 >= (-100)) && (pub_r000597_1_2 <= 100));
  __CPROVER_assume((pub_r000597_2_1 >= (-100)) && (pub_r000597_2_1 <= 100));
  __CPROVER_assume((pub_r000597_2_2 >= (-100)) && (pub_r000597_2_2 <= 100));
  __CPROVER_assume((pub_r000597_3_1 >= (-100)) && (pub_r000597_3_1 <= 100));
  __CPROVER_assume((pub_r000597_3_2 >= (-100)) && (pub_r000597_3_2 <= 100));
  __CPROVER_assume((pub_r000597_4_1 >= (-100)) && (pub_r000597_4_1 <= 100));
  __CPROVER_assume((pub_r000597_4_2 >= (-100)) && (pub_r000597_4_2 <= 100));
  __CPROVER_assume((pub_r000597_5_1 >= (-100)) && (pub_r000597_5_1 <= 100));
  __CPROVER_assume((pub_r000597_5_2 >= (-100)) && (pub_r000597_5_2 <= 100));
  __CPROVER_assume((pub_r000597_6_1 >= (-100)) && (pub_r000597_6_1 <= 100));
  __CPROVER_assume((pub_r000597_6_2 >= (-100)) && (pub_r000597_6_2 <= 100));
  __CPROVER_assume((pub_r000597_7_1 >= (-100)) && (pub_r000597_7_1 <= 100));
  __CPROVER_assume((pub_r000597_7_2 >= (-100)) && (pub_r000597_7_2 <= 100));
  __CPROVER_assume((pub_r000597_8_1 >= (-100)) && (pub_r000597_8_1 <= 100));
  __CPROVER_assume((pub_r000597_8_2 >= (-100)) && (pub_r000597_8_2 <= 100));
  __CPROVER_assume((pub_r000597_9_1 >= (-100)) && (pub_r000597_9_1 <= 100));
  __CPROVER_assume((pub_r000597_9_2 >= (-100)) && (pub_r000597_9_2 <= 100));
  __CPROVER_assume((pub_r000597_10_1 >= (-100)) && (pub_r000597_10_1 <= 100));
  __CPROVER_assume((pub_r000597_10_2 >= (-100)) && (pub_r000597_10_2 <= 100));
  __CPROVER_assume((pub_r000597_11_1 >= (-100)) && (pub_r000597_11_1 <= 100));
  __CPROVER_assume((pub_r000597_11_2 >= (-100)) && (pub_r000597_11_2 <= 100));
  __CPROVER_assume((pub_r000597_12_1 >= (-100)) && (pub_r000597_12_1 <= 100));
  __CPROVER_assume((pub_r000597_12_2 >= (-100)) && (pub_r000597_12_2 <= 100));
  __CPROVER_assume((pub_r000597_13_1 >= (-100)) && (pub_r000597_13_1 <= 100));
  __CPROVER_assume((pub_r000597_13_2 >= (-100)) && (pub_r000597_13_2 <= 100));
  __CPROVER_assume((pub_r000597_14_1 >= (-100)) && (pub_r000597_14_1 <= 100));
  __CPROVER_assume((pub_r000597_14_2 >= (-100)) && (pub_r000597_14_2 <= 100));
  __CPROVER_assume((pub_r000597_15_1 >= (-100)) && (pub_r000597_15_1 <= 100));
  __CPROVER_assume((pub_r000597_15_2 >= (-100)) && (pub_r000597_15_2 <= 100));
  __CPROVER_assume((pub_r000597_16_1 >= (-100)) && (pub_r000597_16_1 <= 100));
  __CPROVER_assume((pub_r000597_16_2 >= (-100)) && (pub_r000597_16_2 <= 100));
  __CPROVER_assume((pub_r000597_17_1 >= (-100)) && (pub_r000597_17_1 <= 100));
  __CPROVER_assume((pub_r000597_17_2 >= (-100)) && (pub_r000597_17_2 <= 100));
  __CPROVER_assume((pub_r000597_18_1 >= (-100)) && (pub_r000597_18_1 <= 100));
  __CPROVER_assume((pub_r000597_18_2 >= (-100)) && (pub_r000597_18_2 <= 100));
  __CPROVER_assume((pub_r000597_19_1 >= (-100)) && (pub_r000597_19_1 <= 100));
  __CPROVER_assume((pub_r000597_19_2 >= (-100)) && (pub_r000597_19_2 <= 100));
  __CPROVER_assume((pub_r000597_20_1 >= (-100)) && (pub_r000597_20_1 <= 100));
  __CPROVER_assume((pub_r000597_20_2 >= (-100)) && (pub_r000597_20_2 <= 100));
  __CPROVER_assume((pub_r000597_21_1 >= (-100)) && (pub_r000597_21_1 <= 100));
  __CPROVER_assume((pub_r000597_21_2 >= (-100)) && (pub_r000597_21_2 <= 100));
  __CPROVER_assume((sec_r000597_0_1 >= 0) && (sec_r000597_0_1 <= 255));
  __CPROVER_assume((sec_r000597_0_2 >= 0) && (sec_r000597_0_2 <= 255));
  __CPROVER_assume((sec_r000597_1_1 >= 0) && (sec_r000597_1_1 <= 255));
  __CPROVER_assume((sec_r000597_1_2 >= 0) && (sec_r000597_1_2 <= 255));
  __CPROVER_assume((sec_r000597_2_1 >= 0) && (sec_r000597_2_1 <= 255));
  __CPROVER_assume((sec_r000597_2_2 >= 0) && (sec_r000597_2_2 <= 255));
  __CPROVER_assume((sec_r000597_3_1 >= 0) && (sec_r000597_3_1 <= 255));
  __CPROVER_assume((sec_r000597_3_2 >= 0) && (sec_r000597_3_2 <= 255));
  __CPROVER_assume((sec_r000597_4_1 >= 0) && (sec_r000597_4_1 <= 255));
  __CPROVER_assume((sec_r000597_4_2 >= 0) && (sec_r000597_4_2 <= 255));
  __CPROVER_assume((sec_r000597_5_1 >= 0) && (sec_r000597_5_1 <= 255));
  __CPROVER_assume((sec_r000597_5_2 >= 0) && (sec_r000597_5_2 <= 255));
  __CPROVER_assume((sec_r000597_6_1 >= 0) && (sec_r000597_6_1 <= 255));
  __CPROVER_assume((sec_r000597_6_2 >= 0) && (sec_r000597_6_2 <= 255));
  __CPROVER_assume((sec_r000597_7_1 >= 0) && (sec_r000597_7_1 <= 255));
  __CPROVER_assume((sec_r000597_7_2 >= 0) && (sec_r000597_7_2 <= 255));
  __CPROVER_assume((sec_r000597_8_1 >= 0) && (sec_r000597_8_1 <= 255));
  __CPROVER_assume((sec_r000597_8_2 >= 0) && (sec_r000597_8_2 <= 255));
  __CPROVER_assume((sec_r000597_9_1 >= 0) && (sec_r000597_9_1 <= 255));
  __CPROVER_assume((sec_r000597_9_2 >= 0) && (sec_r000597_9_2 <= 255));
  __CPROVER_assume((sec_r000597_10_1 >= 0) && (sec_r000597_10_1 <= 255));
  __CPROVER_assume((sec_r000597_10_2 >= 0) && (sec_r000597_10_2 <= 255));
  __CPROVER_assume((sec_r000597_11_1 >= 0) && (sec_r000597_11_1 <= 255));
  __CPROVER_assume((sec_r000597_11_2 >= 0) && (sec_r000597_11_2 <= 255));
  __CPROVER_assume((sec_r000597_12_1 >= 0) && (sec_r000597_12_1 <= 255));
  __CPROVER_assume((sec_r000597_12_2 >= 0) && (sec_r000597_12_2 <= 255));
  __CPROVER_assume((sec_r000597_13_1 >= 0) && (sec_r000597_13_1 <= 255));
  __CPROVER_assume((sec_r000597_13_2 >= 0) && (sec_r000597_13_2 <= 255));
  __CPROVER_assume((sec_r000597_14_1 >= 0) && (sec_r000597_14_1 <= 255));
  __CPROVER_assume((sec_r000597_14_2 >= 0) && (sec_r000597_14_2 <= 255));
  __CPROVER_assume((sec_r000597_15_1 >= 0) && (sec_r000597_15_1 <= 255));
  __CPROVER_assume((sec_r000597_15_2 >= 0) && (sec_r000597_15_2 <= 255));
  __CPROVER_assume((sec_r000597_16_1 >= 0) && (sec_r000597_16_1 <= 255));
  __CPROVER_assume((sec_r000597_16_2 >= 0) && (sec_r000597_16_2 <= 255));
  __CPROVER_assume((sec_r000597_17_1 >= 0) && (sec_r000597_17_1 <= 255));
  __CPROVER_assume((sec_r000597_17_2 >= 0) && (sec_r000597_17_2 <= 255));
  struct FilterState_R000597_9713_0 st_var_0_1 = {0};
  struct FilterState_R000597_9713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000597_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000597_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000597_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000597_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000597_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000597_0_2 + 7) & 15;
  struct StreamBuffer_R000597_9713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000597_9713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000597_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000597_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000597_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000597_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000597_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000597_0_2 + 9) & 15;
  struct SensorNode_R000597_9713_2 st_var_2_1 = {0};
  struct SensorNode_R000597_9713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000597_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000597_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000597_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000597_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000597_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000597_0_2 + 11) & 15;
  union ColorPixel_R000597_9713_0 u_var_1;
  union ColorPixel_R000597_9713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 41)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 41)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 28)
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
  if (stage_v_1_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 28)
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

  switch (stage_v_2_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 36)
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
  if (stage_v_14_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 36)
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
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 55)
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
  if (stage_v_20_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 55)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 22) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((st_var_2_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_2_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 43)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 43)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 34)
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
  if (stage_v_24_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 34)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 29) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 54)
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
  if (stage_v_29_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 54)
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
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
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
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = (st_var_1_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_1_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 28)
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
  if (stage_v_36_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 28)
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
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 50)
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
  if (stage_v_49_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 50)
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
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 49)
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
  if (stage_v_50_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 49)
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
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 54)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 54)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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

  int stage_v_53_1 = (st_var_2_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_2_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 52)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 52)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = ((st_var_0_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_0_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 34)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 34)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = ((st_var_1_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_1_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 26)
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
  if (stage_v_58_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 26)
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
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 55)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 55)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
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
  int stage_v_63_1 = ((st_var_0_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_0_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 33)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 33)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = ((st_var_0_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_0_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 37)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 37)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 76) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = ((st_var_1_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_1_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 48)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 48)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000597_4_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((sec_r000597_4_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000597_16_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000597_16_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000597_14_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000597_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000597_14_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000597_14_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000597_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000597_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000597_0_1 & 1) != 0)
  {
    if ((sec_r000597_0_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((sec_r000597_0_2 & 1) != 0)
  {
    if ((sec_r000597_0_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_1_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000597_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000597_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000597_11_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_1_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000597_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000597_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000597_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000597_17_1 & 1) != 0)
  {
    if ((sec_r000597_9_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000597_10_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000597_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000597_10_1 + 7) & 127;
  }
  if ((sec_r000597_17_2 & 1) != 0)
  {
    if ((sec_r000597_9_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000597_10_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000597_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000597_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000597_1_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000597_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000597_1_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000597_1_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000597_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000597_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000597_7_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000597_7_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000597_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000597_7_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000597_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000597_7_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000597_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000597_7_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000597_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000597_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000597_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000597_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000597_16_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000597_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000597_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000597_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_12_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000597_6_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000597_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000597_6_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_12_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000597_6_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000597_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000597_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000597_8_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000597_11_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000597_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000597_11_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000597_8_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000597_11_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000597_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000597_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000597_9_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000597_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000597_9_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000597_9_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000597_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000597_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000597_9_1 & 1) != 0)
  {
    if ((sec_r000597_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000597_15_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000597_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000597_15_1 + 7) & 127;
  }
  if ((sec_r000597_9_2 & 1) != 0)
  {
    if ((sec_r000597_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000597_15_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000597_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000597_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000597_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000597_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000597_15_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000597_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000597_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000597_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000597_7_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000597_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000597_7_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000597_7_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000597_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000597_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000597_8_1 & 1) != 0)
  {
    if ((sec_r000597_11_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000597_21_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000597_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000597_21_1 + 7) & 127;
  }
  if ((sec_r000597_8_2 & 1) != 0)
  {
    if ((sec_r000597_11_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000597_21_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000597_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000597_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000597_7_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000597_7_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000597_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000597_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_14_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000597_10_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000597_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000597_10_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_14_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000597_10_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000597_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000597_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000597_12_1 & 1) != 0)
  {
    if ((sec_r000597_0_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000597_4_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000597_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000597_4_1 + 7) & 127;
  }
  if ((sec_r000597_12_2 & 1) != 0)
  {
    if ((sec_r000597_0_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000597_4_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000597_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000597_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000597_11_1 & 1) != 0)
  {
    if ((sec_r000597_10_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000597_12_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000597_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000597_12_1 + 7) & 127;
  }
  if ((sec_r000597_11_2 & 1) != 0)
  {
    if ((sec_r000597_10_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000597_12_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000597_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000597_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000597_20_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000597_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000597_20_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000597_20_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000597_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000597_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000597_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000597_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000597_11_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000597_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000597_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000597_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000597_3_1 & 1) != 0)
  {
    if ((sec_r000597_9_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000597_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000597_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000597_14_1 + 7) & 127;
  }
  if ((sec_r000597_3_2 & 1) != 0)
  {
    if ((sec_r000597_9_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000597_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000597_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000597_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000597_12_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000597_12_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000597_13_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000597_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000597_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000597_9_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000597_13_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000597_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000597_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000597_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000597_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000597_15_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000597_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000597_15_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000597_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000597_15_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000597_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000597_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000597_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000597_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000597_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000597_14_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000597_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000597_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000597_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000597_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000597_14_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000597_10_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000597_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000597_10_1 + 7) & 127;
  }
  if ((sec_r000597_14_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000597_10_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000597_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000597_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000597_8_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000597_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000597_8_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000597_8_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000597_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000597_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000597_5_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000597_0_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000597_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000597_0_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000597_5_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000597_0_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000597_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000597_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000597_17_1 & 1) != 0)
  {
    if ((sec_r000597_5_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((sec_r000597_17_2 & 1) != 0)
  {
    if ((sec_r000597_5_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000597_17_1 & 1) != 0)
  {
    if ((sec_r000597_0_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((sec_r000597_17_2 & 1) != 0)
  {
    if ((sec_r000597_0_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000597_4_1 & 1) != 0)
  {
    if ((sec_r000597_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000597_4_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000597_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000597_4_1 + 7) & 127;
  }
  if ((sec_r000597_4_2 & 1) != 0)
  {
    if ((sec_r000597_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000597_4_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000597_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000597_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000597_1_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000597_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000597_1_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000597_1_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000597_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000597_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000597_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000597_19_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000597_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000597_19_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000597_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000597_19_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000597_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000597_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000597_6_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000597_20_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000597_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000597_20_1 + 7) & 127;
  }
  if ((sec_r000597_6_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000597_20_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000597_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000597_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000597_14_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000597_0_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000597_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000597_0_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000597_14_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000597_0_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000597_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000597_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000597_3_1 & 1) != 0)
  {
    if ((sec_r000597_13_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000597_0_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000597_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000597_0_1 + 7) & 127;
  }
  if ((sec_r000597_3_2 & 1) != 0)
  {
    if ((sec_r000597_13_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000597_0_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000597_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000597_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000597_10_1 & 1) != 0)
  {
    if ((sec_r000597_15_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000597_17_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000597_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000597_17_1 + 7) & 127;
  }
  if ((sec_r000597_10_2 & 1) != 0)
  {
    if ((sec_r000597_15_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000597_17_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000597_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000597_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000597_4_1 & 1) != 0)
  {
    if ((sec_r000597_16_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000597_18_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000597_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000597_18_1 + 7) & 127;
  }
  if ((sec_r000597_4_2 & 1) != 0)
  {
    if ((sec_r000597_16_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000597_18_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000597_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000597_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000597_8_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000597_17_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000597_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000597_17_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000597_8_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000597_17_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000597_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000597_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000597_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000597_13_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000597_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000597_13_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000597_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000597_13_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000597_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000597_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000597_12_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000597_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000597_12_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000597_12_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000597_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000597_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000597_16_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000597_20_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000597_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000597_20_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000597_16_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000597_20_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000597_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000597_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000597_17_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000597_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000597_17_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000597_17_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000597_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000597_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000597_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000597_9_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000597_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000597_9_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000597_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000597_9_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000597_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000597_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000597_16_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000597_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000597_16_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000597_16_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000597_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000597_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000597_16_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000597_7_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000597_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000597_7_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000597_16_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000597_7_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000597_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000597_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000597_11_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000597_7_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000597_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000597_7_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000597_11_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000597_7_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000597_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000597_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000597_0_1 & 1) != 0)
  {
    if ((sec_r000597_13_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000597_13_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000597_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000597_13_1 + 7) & 127;
  }
  if ((sec_r000597_0_2 & 1) != 0)
  {
    if ((sec_r000597_13_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000597_13_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000597_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000597_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000597_7_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000597_1_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000597_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000597_1_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000597_7_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000597_1_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000597_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000597_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000597_7_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000597_7_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000597_15_1 & 1) != 0)
  {
    if ((sec_r000597_0_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((sec_r000597_15_2 & 1) != 0)
  {
    if ((sec_r000597_0_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000597_8_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000597_21_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000597_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000597_21_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000597_8_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000597_21_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000597_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000597_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000597_0_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000597_6_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000597_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000597_6_1 + 7) & 127;
  }
  if ((sec_r000597_0_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000597_6_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000597_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000597_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000597_8_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000597_13_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000597_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000597_13_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000597_8_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000597_13_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000597_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000597_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000597_7_1 & 1) != 0)
  {
    if ((sec_r000597_14_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000597_16_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000597_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000597_16_1 + 7) & 127;
  }
  if ((sec_r000597_7_2 & 1) != 0)
  {
    if ((sec_r000597_14_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000597_16_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000597_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000597_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000597_0_1 & 1) != 0)
  {
    if ((sec_r000597_13_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((sec_r000597_0_2 & 1) != 0)
  {
    if ((sec_r000597_13_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000597_9_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000597_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000597_9_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000597_9_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000597_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000597_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000597_9_1 & 1) != 0)
  {
    if ((sec_r000597_5_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000597_13_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000597_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000597_13_1 + 7) & 127;
  }
  if ((sec_r000597_9_2 & 1) != 0)
  {
    if ((sec_r000597_5_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000597_13_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000597_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000597_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000597_17_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((sec_r000597_17_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000597_8_1 & 1) != 0)
  {
    if ((sec_r000597_4_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((sec_r000597_8_2 & 1) != 0)
  {
    if ((sec_r000597_4_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000597_1_1 & 1) != 0)
  {
    if ((sec_r000597_17_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000597_2_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000597_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000597_2_1 + 7) & 127;
  }
  if ((sec_r000597_1_2 & 1) != 0)
  {
    if ((sec_r000597_17_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000597_2_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000597_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000597_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000597_11_1 & 1) != 0)
  {
    if ((sec_r000597_10_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((sec_r000597_11_2 & 1) != 0)
  {
    if ((sec_r000597_10_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000597_9_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000597_1_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000597_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000597_1_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000597_9_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000597_1_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000597_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000597_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000597_8_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000597_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000597_8_1 + 7) & 127;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000597_8_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000597_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000597_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000597_2_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000597_15_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000597_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000597_15_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000597_2_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000597_15_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000597_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000597_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r000597_14_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000597_3_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000597_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000597_3_1 + 7) & 127;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r000597_14_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000597_3_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000597_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000597_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000597_1_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000597_17_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000597_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000597_17_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000597_1_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000597_17_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000597_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000597_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((sec_r000597_6_1 & 1) != 0)
  {
    if ((sec_r000597_15_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000597_15_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000597_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000597_15_1 + 7) & 127;
  }
  if ((sec_r000597_6_2 & 1) != 0)
  {
    if ((sec_r000597_15_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000597_15_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000597_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000597_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000597_6_1 & 1) != 0)
  {
    if ((sec_r000597_6_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000597_7_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000597_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000597_7_1 + 7) & 127;
  }
  if ((sec_r000597_6_2 & 1) != 0)
  {
    if ((sec_r000597_6_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000597_7_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000597_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000597_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000597_3_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000597_5_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000597_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000597_5_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000597_3_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000597_5_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000597_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000597_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000597_9_1 != sec_r000597_9_2);
  __CPROVER_assume(pub_r000597_9_1 == pub_r000597_9_2);
  __CPROVER_assume(pub_r000597_2_1 == pub_r000597_2_2);
  __CPROVER_assume(pub_r000597_11_1 == pub_r000597_11_2);
  __CPROVER_assume(sec_r000597_2_1 != sec_r000597_2_2);
  __CPROVER_assume(pub_r000597_16_1 == pub_r000597_16_2);
  __CPROVER_assume(sec_r000597_0_1 != sec_r000597_0_2);
  __CPROVER_assume(pub_r000597_0_1 == pub_r000597_0_2);
  __CPROVER_assume(pub_r000597_19_1 == pub_r000597_19_2);
  __CPROVER_assume(sec_r000597_16_1 != sec_r000597_16_2);
  __CPROVER_assume(sec_r000597_7_1 != sec_r000597_7_2);
  __CPROVER_assume(pub_r000597_15_1 == pub_r000597_15_2);
  __CPROVER_assume(sec_r000597_4_1 != sec_r000597_4_2);
  __CPROVER_assume(sec_r000597_11_1 != sec_r000597_11_2);
  __CPROVER_assume(sec_r000597_15_1 != sec_r000597_15_2);
  __CPROVER_assume(pub_r000597_13_1 == pub_r000597_13_2);
  __CPROVER_assume(sec_r000597_8_1 != sec_r000597_8_2);
  __CPROVER_assume(pub_r000597_8_1 == pub_r000597_8_2);
  __CPROVER_assume(sec_r000597_12_1 != sec_r000597_12_2);
  __CPROVER_assume(sec_r000597_13_1 != sec_r000597_13_2);
  __CPROVER_assume(pub_r000597_5_1 == pub_r000597_5_2);
  __CPROVER_assume(sec_r000597_14_1 != sec_r000597_14_2);
  __CPROVER_assume(pub_r000597_14_1 == pub_r000597_14_2);
  __CPROVER_assume(pub_r000597_1_1 == pub_r000597_1_2);
  __CPROVER_assume(pub_r000597_18_1 == pub_r000597_18_2);
  __CPROVER_assume(pub_r000597_12_1 == pub_r000597_12_2);
  __CPROVER_assume(pub_r000597_10_1 == pub_r000597_10_2);
  __CPROVER_assume(pub_r000597_21_1 == pub_r000597_21_2);
  __CPROVER_assume(pub_r000597_7_1 == pub_r000597_7_2);
  __CPROVER_assume(sec_r000597_3_1 != sec_r000597_3_2);
  __CPROVER_assume(sec_r000597_5_1 != sec_r000597_5_2);
  __CPROVER_assume(pub_r000597_3_1 == pub_r000597_3_2);
  __CPROVER_assume(pub_r000597_6_1 == pub_r000597_6_2);
  __CPROVER_assume(sec_r000597_17_1 != sec_r000597_17_2);
  __CPROVER_assume(pub_r000597_4_1 == pub_r000597_4_2);
  __CPROVER_assume(pub_r000597_20_1 == pub_r000597_20_2);
  __CPROVER_assume(sec_r000597_1_1 != sec_r000597_1_2);
  __CPROVER_assume(sec_r000597_6_1 != sec_r000597_6_2);
  __CPROVER_assume(pub_r000597_17_1 == pub_r000597_17_2);
  __CPROVER_assume(sec_r000597_10_1 != sec_r000597_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
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
}


