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
struct FilterState_R000296_9613_0
{
  unsigned char prev_out;
  int damping;
  int mode;
  unsigned char prev_in;
  int cutoff;
  int buffer[3];
};
struct EventLog_R000296_9613_1
{
  unsigned char timestamp;
  int signature;
  int facility;
  short seq;
  int code;
  int buffer[3];
};
struct DeviceConfig_R000296_9613_2
{
  int stop_bits;
  short port;
  short baud_rate;
  int buffer[3];
};
union ColorPixel_R000296_9613_0
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
void fn_R000296_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_29_1 = local_arr_1[aux_1 % 3];
  int mask_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_29_2 * 2)) & 127;
  int sample_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_69_1) & 63;
  aux_2 = (aux_2 + sample_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_29_1 == mask_29_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R000296_9613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int mask_29 = local_arr[aux % 3];
  acc = (acc + (mask_29 * 2)) & 127;
  int sample_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000296_9613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int index_reg_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_77_1 > 20)
  {
    acc_1 = ((acc_1 + (index_reg_77_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_77_2 > 20)
  {
    acc_2 = ((acc_2 + (index_reg_77_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_96_1)
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

  switch (tracker_96_2)
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
  int delta_12_1 = local_arr_1[aux_1 % 3];
  int delta_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_77_1 == index_reg_77_2);
  assert(tracker_96_1 == tracker_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_12_1 == delta_12_2);
}

int fn_R000296_9613_1(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int index_reg_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_77 > 20)
  {
    acc = ((acc + (index_reg_77 * 2)) + 5) & 127;
    aux ^= index_reg_77 & 15;
  }
  else
  {
    acc = ((acc - index_reg_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_96 = (aux + st.buffer[1]) & 3;
  switch (tracker_96)
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
  int delta_12 = local_arr[aux % 3];
  acc = (acc + (delta_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_57_1 = local_arr_1[aux_1 % 3];
  int residue_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_57_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_57_1 == residue_57_2);
}

int fn_R000296_9613_2(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int residue_57 = local_arr[aux % 3];
  acc = (acc + (residue_57 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_10_1) & 63;
  aux_2 = (aux_2 + stride_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_38_1)
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

  switch (residue_38_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_10_1 == stride_10_2);
  assert(residue_38_1 == residue_38_2);
}

int fn_R000296_9613_3(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_38 = (aux + st.buffer[1]) & 3;
  switch (residue_38)
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

void fn_R000296_9613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int cursor_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_87_1) & 63;
  aux_2 = (aux_2 + cursor_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_15_1)
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

  switch (damping_15_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_87_1 == cursor_87_2);
  assert(damping_15_1 == damping_15_2);
}

int fn_R000296_9613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int cursor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_87) & 63;
  acc ^= aux;
  int damping_15 = (aux + st.buffer[1]) & 3;
  switch (damping_15)
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

void fn_R000296_9613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int pivot_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_80_1 > 11)
  {
    acc_1 = ((acc_1 + (pivot_80_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_80_2 > 11)
  {
    acc_2 = ((acc_2 + (pivot_80_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_84_1) & 63;
  aux_2 = (aux_2 + cursor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_65_1)
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

  switch (parity_65_2)
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
  int factor_32_1 = local_arr_1[aux_1 % 3];
  int factor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_80_1 == pivot_80_2);
  assert(cursor_84_1 == cursor_84_2);
  assert(parity_65_1 == parity_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_32_1 == factor_32_2);
}

int fn_R000296_9613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int pivot_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_80 > 11)
  {
    acc = ((acc + (pivot_80 * 2)) + 5) & 127;
    aux ^= pivot_80 & 15;
  }
  else
  {
    acc = ((acc - pivot_80) + 11) & 127;
    aux += 3;
  }
  int cursor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_84) & 63;
  acc ^= aux;
  int parity_65 = (aux + st.buffer[1]) & 3;
  switch (parity_65)
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
  int factor_32 = local_arr[aux % 3];
  acc = (acc + (factor_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_16_1 = local_arr_1[aux_1 % 3];
  int delta_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_16_2 * 2)) & 127;
  int bound_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_47_1 > 27)
  {
    acc_1 = ((acc_1 + (bound_47_1 * 2)) + 5) & 127;
    aux_1 ^= bound_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_47_2 > 27)
  {
    acc_2 = ((acc_2 + (bound_47_2 * 2)) + 5) & 127;
    aux_2 ^= bound_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_83_1)
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

  switch (mask_83_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_16_1 == delta_16_2);
  assert(bound_47_1 == bound_47_2);
  assert(mask_83_1 == mask_83_2);
}

int fn_R000296_9613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int delta_16 = local_arr[aux % 3];
  acc = (acc + (delta_16 * 2)) & 127;
  int bound_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_47 > 27)
  {
    acc = ((acc + (bound_47 * 2)) + 5) & 127;
    aux ^= bound_47 & 15;
  }
  else
  {
    acc = ((acc - bound_47) + 11) & 127;
    aux += 3;
  }
  int mask_83 = (aux + st.buffer[1]) & 3;
  switch (mask_83)
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

void fn_R000296_9613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int segment_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_75_1)
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

  switch (segment_75_2)
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

  int weight_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_56_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_56_1 * 2)) + 5) & 127;
    aux_1 ^= weight_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_56_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_56_2 * 2)) + 5) & 127;
    aux_2 ^= weight_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_75_1 == segment_75_2);
  assert(weight_56_1 == weight_56_2);
}

int fn_R000296_9613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int segment_75 = (aux + st.buffer[1]) & 3;
  switch (segment_75)
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

  int weight_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_56 > 49)
  {
    acc = ((acc + (weight_56 * 2)) + 5) & 127;
    aux ^= weight_56 & 15;
  }
  else
  {
    acc = ((acc - weight_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000296_9613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_91_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_91_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_91_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_91_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_89_1 = local_arr_1[aux_1 % 3];
  int parity_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_89_2 * 2)) & 127;
  int weight_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_39_1)
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

  switch (weight_39_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_91_1 == threshold_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_89_1 == parity_89_2);
  assert(weight_39_1 == weight_39_2);
}

int fn_R000296_9613_8(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_91 > 24)
  {
    acc = ((acc + (threshold_91 * 2)) + 5) & 127;
    aux ^= threshold_91 & 15;
  }
  else
  {
    acc = ((acc - threshold_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_89 = local_arr[aux % 3];
  acc = (acc + (parity_89 * 2)) & 127;
  int weight_39 = (aux + st.buffer[1]) & 3;
  switch (weight_39)
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

void fn_R000296_9613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quotient_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_42_1)
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

  switch (quotient_42_2)
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

  int quotient_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_64_1) & 63;
  aux_2 = (aux_2 + quotient_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_34_1 = local_arr_1[aux_1 % 3];
  int scale_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_42_1 == quotient_42_2);
  assert(quotient_64_1 == quotient_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_34_1 == scale_34_2);
}

int fn_R000296_9613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quotient_42 = (aux + st.buffer[1]) & 3;
  switch (quotient_42)
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

  int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_34 = local_arr[aux % 3];
  acc = (acc + (scale_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_13_1) & 63;
  aux_2 = (aux_2 + quantum_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_23_1)
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

  switch (accumulator_23_2)
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
  int delta_58_1 = local_arr_1[aux_1 % 3];
  int delta_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_58_2 * 2)) & 127;
  int vector_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_88_1 > 22)
  {
    acc_1 = ((acc_1 + (vector_88_1 * 2)) + 5) & 127;
    aux_1 ^= vector_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_88_2 > 22)
  {
    acc_2 = ((acc_2 + (vector_88_2 * 2)) + 5) & 127;
    aux_2 ^= vector_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_13_1 == quantum_13_2);
  assert(accumulator_23_1 == accumulator_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_58_1 == delta_58_2);
  assert(vector_88_1 == vector_88_2);
}

int fn_R000296_9613_10(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_13) & 63;
  acc ^= aux;
  int accumulator_23 = (aux + st.buffer[1]) & 3;
  switch (accumulator_23)
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
  int delta_58 = local_arr[aux % 3];
  acc = (acc + (delta_58 * 2)) & 127;
  int vector_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_88 > 22)
  {
    acc = ((acc + (vector_88 * 2)) + 5) & 127;
    aux ^= vector_88 & 15;
  }
  else
  {
    acc = ((acc - vector_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000296_9613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_47_1)
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

  switch (stride_47_2)
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
  int sample_20_1 = local_arr_1[aux_1 % 3];
  int sample_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_20_2 * 2)) & 127;
  int pivot_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_16_1) & 63;
  aux_2 = (aux_2 + pivot_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_47_1 == stride_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_20_1 == sample_20_2);
  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000296_9613_11(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_47 = (aux + st.buffer[1]) & 3;
  switch (stride_47)
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
  int sample_20 = local_arr[aux % 3];
  acc = (acc + (sample_20 * 2)) & 127;
  int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000296_9613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_84_1) & 63;
  aux_2 = (aux_2 + pivot_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_92_1)
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

  switch (stride_92_2)
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

  int vector_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_97_1 > 18)
  {
    acc_1 = ((acc_1 + (vector_97_1 * 2)) + 5) & 127;
    aux_1 ^= vector_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_97_2 > 18)
  {
    acc_2 = ((acc_2 + (vector_97_2 * 2)) + 5) & 127;
    aux_2 ^= vector_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_84_1 == pivot_84_2);
  assert(stride_92_1 == stride_92_2);
  assert(vector_97_1 == vector_97_2);
}

int fn_R000296_9613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_84) & 63;
  acc ^= aux;
  int stride_92 = (aux + st.buffer[1]) & 3;
  switch (stride_92)
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

  int vector_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_97 > 18)
  {
    acc = ((acc + (vector_97 * 2)) + 5) & 127;
    aux ^= vector_97 & 15;
  }
  else
  {
    acc = ((acc - vector_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000296_9613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_14_1) & 63;
  aux_2 = (aux_2 + delta_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_26_1 = local_arr_1[aux_1 % 3];
  int index_reg_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_26_2 * 2)) & 127;
  int quantum_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_35_1)
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

  switch (quantum_35_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_14_1 == delta_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_26_1 == index_reg_26_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R000296_9613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_26 = local_arr[aux % 3];
  acc = (acc + (index_reg_26 * 2)) & 127;
  int quantum_35 = (aux + st.buffer[1]) & 3;
  switch (quantum_35)
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

void fn_R000296_9613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st_1 = {0};
  struct EventLog_R000296_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_79_1 > 48)
  {
    acc_1 = ((acc_1 + (sample_79_1 * 2)) + 5) & 127;
    aux_1 ^= sample_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_79_2 > 48)
  {
    acc_2 = ((acc_2 + (sample_79_2 * 2)) + 5) & 127;
    aux_2 ^= sample_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_91_1) & 63;
  aux_2 = (aux_2 + window_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_79_1 == sample_79_2);
  assert(window_91_1 == window_91_2);
}

int fn_R000296_9613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_79 > 48)
  {
    acc = ((acc + (sample_79 * 2)) + 5) & 127;
    aux ^= sample_79 & 15;
  }
  else
  {
    acc = ((acc - sample_79) + 11) & 127;
    aux += 3;
  }
  int window_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000296_9613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st_1 = {0};
  struct EventLog_R000296_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_47_1) & 63;
  aux_2 = (aux_2 + tally_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_20_1 = local_arr_1[aux_1 % 3];
  int checksum_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_47_1 == tally_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_20_1 == checksum_20_2);
}

int fn_R000296_9613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_20 = local_arr[aux % 3];
  acc = (acc + (checksum_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st_1 = {0};
  struct EventLog_R000296_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_14_1)
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

  switch (checksum_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_21_1 = local_arr_1[aux_1 % 3];
  int residue_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_21_2 * 2)) & 127;
  int delta_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_70_1) & 63;
  aux_2 = (aux_2 + delta_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_14_1 == checksum_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_21_1 == residue_21_2);
  assert(delta_70_1 == delta_70_2);
}

int fn_R000296_9613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_14 = (aux + st.buffer[1]) & 3;
  switch (checksum_14)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_21 = local_arr[aux % 3];
  acc = (acc + (residue_21 * 2)) & 127;
  int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000296_9613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st_1 = {0};
  struct EventLog_R000296_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_35_1 = local_arr_1[aux_1 % 3];
  int weight_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_35_1 == weight_35_2);
}

int fn_R000296_9613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int weight_35 = local_arr[aux % 3];
  acc = (acc + (weight_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st_1 = {0};
  struct EventLog_R000296_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_58_1 > 13)
  {
    acc_1 = ((acc_1 + (anchor_58_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_58_2 > 13)
  {
    acc_2 = ((acc_2 + (anchor_58_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_39_1) & 63;
  aux_2 = (aux_2 + accumulator_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_68_1)
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

  switch (segment_68_2)
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
  int delta_44_1 = local_arr_1[aux_1 % 3];
  int delta_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_58_1 == anchor_58_2);
  assert(accumulator_39_1 == accumulator_39_2);
  assert(segment_68_1 == segment_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_44_1 == delta_44_2);
}

int fn_R000296_9613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000296_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_58 > 13)
  {
    acc = ((acc + (anchor_58 * 2)) + 5) & 127;
    aux ^= anchor_58 & 15;
  }
  else
  {
    acc = ((acc - anchor_58) + 11) & 127;
    aux += 3;
  }
  int accumulator_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_39) & 63;
  acc ^= aux;
  int segment_68 = (aux + st.buffer[1]) & 3;
  switch (segment_68)
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
  int delta_44 = local_arr[aux % 3];
  acc = (acc + (delta_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_65_1 = local_arr_1[aux_1 % 3];
  int index_reg_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_65_2 * 2)) & 127;
  int accumulator_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_40_1)
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

  switch (accumulator_40_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_65_1 == index_reg_65_2);
  assert(accumulator_40_1 == accumulator_40_2);
}

int fn_R000296_9613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int index_reg_65 = local_arr[aux % 3];
  acc = (acc + (index_reg_65 * 2)) & 127;
  int accumulator_40 = (aux + st.buffer[1]) & 3;
  switch (accumulator_40)
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

void fn_R000296_9613_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int offset_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_20_1 > 11)
  {
    acc_1 = ((acc_1 + (offset_20_1 * 2)) + 5) & 127;
    aux_1 ^= offset_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_20_2 > 11)
  {
    acc_2 = ((acc_2 + (offset_20_2 * 2)) + 5) & 127;
    aux_2 ^= offset_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_57_1) & 63;
  aux_2 = (aux_2 + quotient_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_20_1 == offset_20_2);
  assert(quotient_57_1 == quotient_57_2);
}

int fn_R000296_9613_20(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int offset_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_20 > 11)
  {
    acc = ((acc + (offset_20 * 2)) + 5) & 127;
    aux ^= offset_20 & 15;
  }
  else
  {
    acc = ((acc - offset_20) + 11) & 127;
    aux += 3;
  }
  int quotient_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st_1 = {0};
  struct FilterState_R000296_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int weight_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_34_1 > 18)
  {
    acc_1 = ((acc_1 + (weight_34_1 * 2)) + 5) & 127;
    aux_1 ^= weight_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_34_2 > 18)
  {
    acc_2 = ((acc_2 + (weight_34_2 * 2)) + 5) & 127;
    aux_2 ^= weight_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_61_1)
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

  switch (segment_61_2)
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
  int anchor_11_1 = local_arr_1[aux_1 % 3];
  int anchor_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_34_1 == weight_34_2);
  assert(segment_61_1 == segment_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_11_1 == anchor_11_2);
}

int fn_R000296_9613_21(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000296_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int weight_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_34 > 18)
  {
    acc = ((acc + (weight_34 * 2)) + 5) & 127;
    aux ^= weight_34 & 15;
  }
  else
  {
    acc = ((acc - weight_34) + 11) & 127;
    aux += 3;
  }
  int segment_61 = (aux + st.buffer[1]) & 3;
  switch (segment_61)
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
  int anchor_11 = local_arr[aux % 3];
  acc = (acc + (anchor_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000296_9613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_67_1) & 63;
  aux_2 = (aux_2 + sample_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_69_1)
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

  switch (margin_69_2)
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

  int sample_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_69_1 > 29)
  {
    acc_1 = ((acc_1 + (sample_69_1 * 2)) + 5) & 127;
    aux_1 ^= sample_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_69_2 > 29)
  {
    acc_2 = ((acc_2 + (sample_69_2 * 2)) + 5) & 127;
    aux_2 ^= sample_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_67_1 == sample_67_2);
  assert(margin_69_1 == margin_69_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R000296_9613_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000296_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_67) & 63;
  acc ^= aux;
  int margin_69 = (aux + st.buffer[1]) & 3;
  switch (margin_69)
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

  int sample_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_69 > 29)
  {
    acc = ((acc + (sample_69 * 2)) + 5) & 127;
    aux ^= sample_69 & 15;
  }
  else
  {
    acc = ((acc - sample_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000296_0_1;
  int sec_r000296_0_2;
  int sec_r000296_1_1;
  int sec_r000296_1_2;
  int sec_r000296_2_1;
  int sec_r000296_2_2;
  int sec_r000296_3_1;
  int sec_r000296_3_2;
  int sec_r000296_4_1;
  int sec_r000296_4_2;
  int sec_r000296_5_1;
  int sec_r000296_5_2;
  int sec_r000296_6_1;
  int sec_r000296_6_2;
  int sec_r000296_7_1;
  int sec_r000296_7_2;
  int sec_r000296_8_1;
  int sec_r000296_8_2;
  int sec_r000296_9_1;
  int sec_r000296_9_2;
  int sec_r000296_10_1;
  int sec_r000296_10_2;
  int sec_r000296_11_1;
  int sec_r000296_11_2;
  int sec_r000296_12_1;
  int sec_r000296_12_2;
  int sec_r000296_13_1;
  int sec_r000296_13_2;
  int sec_r000296_14_1;
  int sec_r000296_14_2;
  int sec_r000296_15_1;
  int sec_r000296_15_2;
  int sec_r000296_16_1;
  int sec_r000296_16_2;
  int sec_r000296_17_1;
  int sec_r000296_17_2;
  int sec_r000296_18_1;
  int sec_r000296_18_2;
  int sec_r000296_19_1;
  int sec_r000296_19_2;
  int sec_r000296_20_1;
  int sec_r000296_20_2;
  int sec_r000296_21_1;
  int sec_r000296_21_2;
  int pub_r000296_0_1;
  int pub_r000296_0_2;
  int pub_r000296_1_1;
  int pub_r000296_1_2;
  int pub_r000296_2_1;
  int pub_r000296_2_2;
  int pub_r000296_3_1;
  int pub_r000296_3_2;
  int pub_r000296_4_1;
  int pub_r000296_4_2;
  int pub_r000296_5_1;
  int pub_r000296_5_2;
  int pub_r000296_6_1;
  int pub_r000296_6_2;
  int pub_r000296_7_1;
  int pub_r000296_7_2;
  int pub_r000296_8_1;
  int pub_r000296_8_2;
  int pub_r000296_9_1;
  int pub_r000296_9_2;
  int pub_r000296_10_1;
  int pub_r000296_10_2;
  int pub_r000296_11_1;
  int pub_r000296_11_2;
  int pub_r000296_12_1;
  int pub_r000296_12_2;
  int pub_r000296_13_1;
  int pub_r000296_13_2;
  int pub_r000296_14_1;
  int pub_r000296_14_2;
  int pub_r000296_15_1;
  int pub_r000296_15_2;
  int pub_r000296_16_1;
  int pub_r000296_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000296_0_1 >= (-100)) && (pub_r000296_0_1 <= 100));
  __CPROVER_assume((pub_r000296_0_2 >= (-100)) && (pub_r000296_0_2 <= 100));
  __CPROVER_assume((pub_r000296_1_1 >= (-100)) && (pub_r000296_1_1 <= 100));
  __CPROVER_assume((pub_r000296_1_2 >= (-100)) && (pub_r000296_1_2 <= 100));
  __CPROVER_assume((pub_r000296_2_1 >= (-100)) && (pub_r000296_2_1 <= 100));
  __CPROVER_assume((pub_r000296_2_2 >= (-100)) && (pub_r000296_2_2 <= 100));
  __CPROVER_assume((pub_r000296_3_1 >= (-100)) && (pub_r000296_3_1 <= 100));
  __CPROVER_assume((pub_r000296_3_2 >= (-100)) && (pub_r000296_3_2 <= 100));
  __CPROVER_assume((pub_r000296_4_1 >= (-100)) && (pub_r000296_4_1 <= 100));
  __CPROVER_assume((pub_r000296_4_2 >= (-100)) && (pub_r000296_4_2 <= 100));
  __CPROVER_assume((pub_r000296_5_1 >= (-100)) && (pub_r000296_5_1 <= 100));
  __CPROVER_assume((pub_r000296_5_2 >= (-100)) && (pub_r000296_5_2 <= 100));
  __CPROVER_assume((pub_r000296_6_1 >= (-100)) && (pub_r000296_6_1 <= 100));
  __CPROVER_assume((pub_r000296_6_2 >= (-100)) && (pub_r000296_6_2 <= 100));
  __CPROVER_assume((pub_r000296_7_1 >= (-100)) && (pub_r000296_7_1 <= 100));
  __CPROVER_assume((pub_r000296_7_2 >= (-100)) && (pub_r000296_7_2 <= 100));
  __CPROVER_assume((pub_r000296_8_1 >= (-100)) && (pub_r000296_8_1 <= 100));
  __CPROVER_assume((pub_r000296_8_2 >= (-100)) && (pub_r000296_8_2 <= 100));
  __CPROVER_assume((pub_r000296_9_1 >= (-100)) && (pub_r000296_9_1 <= 100));
  __CPROVER_assume((pub_r000296_9_2 >= (-100)) && (pub_r000296_9_2 <= 100));
  __CPROVER_assume((pub_r000296_10_1 >= (-100)) && (pub_r000296_10_1 <= 100));
  __CPROVER_assume((pub_r000296_10_2 >= (-100)) && (pub_r000296_10_2 <= 100));
  __CPROVER_assume((pub_r000296_11_1 >= (-100)) && (pub_r000296_11_1 <= 100));
  __CPROVER_assume((pub_r000296_11_2 >= (-100)) && (pub_r000296_11_2 <= 100));
  __CPROVER_assume((pub_r000296_12_1 >= (-100)) && (pub_r000296_12_1 <= 100));
  __CPROVER_assume((pub_r000296_12_2 >= (-100)) && (pub_r000296_12_2 <= 100));
  __CPROVER_assume((pub_r000296_13_1 >= (-100)) && (pub_r000296_13_1 <= 100));
  __CPROVER_assume((pub_r000296_13_2 >= (-100)) && (pub_r000296_13_2 <= 100));
  __CPROVER_assume((pub_r000296_14_1 >= (-100)) && (pub_r000296_14_1 <= 100));
  __CPROVER_assume((pub_r000296_14_2 >= (-100)) && (pub_r000296_14_2 <= 100));
  __CPROVER_assume((pub_r000296_15_1 >= (-100)) && (pub_r000296_15_1 <= 100));
  __CPROVER_assume((pub_r000296_15_2 >= (-100)) && (pub_r000296_15_2 <= 100));
  __CPROVER_assume((pub_r000296_16_1 >= (-100)) && (pub_r000296_16_1 <= 100));
  __CPROVER_assume((pub_r000296_16_2 >= (-100)) && (pub_r000296_16_2 <= 100));
  __CPROVER_assume((sec_r000296_0_1 >= 0) && (sec_r000296_0_1 <= 255));
  __CPROVER_assume((sec_r000296_0_2 >= 0) && (sec_r000296_0_2 <= 255));
  __CPROVER_assume((sec_r000296_1_1 >= 0) && (sec_r000296_1_1 <= 255));
  __CPROVER_assume((sec_r000296_1_2 >= 0) && (sec_r000296_1_2 <= 255));
  __CPROVER_assume((sec_r000296_2_1 >= 0) && (sec_r000296_2_1 <= 255));
  __CPROVER_assume((sec_r000296_2_2 >= 0) && (sec_r000296_2_2 <= 255));
  __CPROVER_assume((sec_r000296_3_1 >= 0) && (sec_r000296_3_1 <= 255));
  __CPROVER_assume((sec_r000296_3_2 >= 0) && (sec_r000296_3_2 <= 255));
  __CPROVER_assume((sec_r000296_4_1 >= 0) && (sec_r000296_4_1 <= 255));
  __CPROVER_assume((sec_r000296_4_2 >= 0) && (sec_r000296_4_2 <= 255));
  __CPROVER_assume((sec_r000296_5_1 >= 0) && (sec_r000296_5_1 <= 255));
  __CPROVER_assume((sec_r000296_5_2 >= 0) && (sec_r000296_5_2 <= 255));
  __CPROVER_assume((sec_r000296_6_1 >= 0) && (sec_r000296_6_1 <= 255));
  __CPROVER_assume((sec_r000296_6_2 >= 0) && (sec_r000296_6_2 <= 255));
  __CPROVER_assume((sec_r000296_7_1 >= 0) && (sec_r000296_7_1 <= 255));
  __CPROVER_assume((sec_r000296_7_2 >= 0) && (sec_r000296_7_2 <= 255));
  __CPROVER_assume((sec_r000296_8_1 >= 0) && (sec_r000296_8_1 <= 255));
  __CPROVER_assume((sec_r000296_8_2 >= 0) && (sec_r000296_8_2 <= 255));
  __CPROVER_assume((sec_r000296_9_1 >= 0) && (sec_r000296_9_1 <= 255));
  __CPROVER_assume((sec_r000296_9_2 >= 0) && (sec_r000296_9_2 <= 255));
  __CPROVER_assume((sec_r000296_10_1 >= 0) && (sec_r000296_10_1 <= 255));
  __CPROVER_assume((sec_r000296_10_2 >= 0) && (sec_r000296_10_2 <= 255));
  __CPROVER_assume((sec_r000296_11_1 >= 0) && (sec_r000296_11_1 <= 255));
  __CPROVER_assume((sec_r000296_11_2 >= 0) && (sec_r000296_11_2 <= 255));
  __CPROVER_assume((sec_r000296_12_1 >= 0) && (sec_r000296_12_1 <= 255));
  __CPROVER_assume((sec_r000296_12_2 >= 0) && (sec_r000296_12_2 <= 255));
  __CPROVER_assume((sec_r000296_13_1 >= 0) && (sec_r000296_13_1 <= 255));
  __CPROVER_assume((sec_r000296_13_2 >= 0) && (sec_r000296_13_2 <= 255));
  __CPROVER_assume((sec_r000296_14_1 >= 0) && (sec_r000296_14_1 <= 255));
  __CPROVER_assume((sec_r000296_14_2 >= 0) && (sec_r000296_14_2 <= 255));
  __CPROVER_assume((sec_r000296_15_1 >= 0) && (sec_r000296_15_1 <= 255));
  __CPROVER_assume((sec_r000296_15_2 >= 0) && (sec_r000296_15_2 <= 255));
  __CPROVER_assume((sec_r000296_16_1 >= 0) && (sec_r000296_16_1 <= 255));
  __CPROVER_assume((sec_r000296_16_2 >= 0) && (sec_r000296_16_2 <= 255));
  __CPROVER_assume((sec_r000296_17_1 >= 0) && (sec_r000296_17_1 <= 255));
  __CPROVER_assume((sec_r000296_17_2 >= 0) && (sec_r000296_17_2 <= 255));
  __CPROVER_assume((sec_r000296_18_1 >= 0) && (sec_r000296_18_1 <= 255));
  __CPROVER_assume((sec_r000296_18_2 >= 0) && (sec_r000296_18_2 <= 255));
  __CPROVER_assume((sec_r000296_19_1 >= 0) && (sec_r000296_19_1 <= 255));
  __CPROVER_assume((sec_r000296_19_2 >= 0) && (sec_r000296_19_2 <= 255));
  __CPROVER_assume((sec_r000296_20_1 >= 0) && (sec_r000296_20_1 <= 255));
  __CPROVER_assume((sec_r000296_20_2 >= 0) && (sec_r000296_20_2 <= 255));
  __CPROVER_assume((sec_r000296_21_1 >= 0) && (sec_r000296_21_1 <= 255));
  __CPROVER_assume((sec_r000296_21_2 >= 0) && (sec_r000296_21_2 <= 255));
  struct FilterState_R000296_9613_0 st_var_0_1 = {0};
  struct FilterState_R000296_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000296_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000296_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000296_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000296_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000296_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000296_0_2 + 7) & 15;
  struct EventLog_R000296_9613_1 st_var_1_1 = {0};
  struct EventLog_R000296_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000296_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000296_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000296_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000296_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000296_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000296_0_2 + 9) & 15;
  struct DeviceConfig_R000296_9613_2 st_var_2_1 = {0};
  struct DeviceConfig_R000296_9613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000296_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000296_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000296_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000296_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000296_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000296_0_2 + 11) & 15;
  union ColorPixel_R000296_9613_0 u_var_1;
  union ColorPixel_R000296_9613_0 u_var_2;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 32)
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
  if (stage_v_15_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 32)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 18) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
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
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 49)
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
  if (stage_v_29_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 49)
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
  if (stage_v_30_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 54)
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
  if (stage_v_30_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 54)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 35) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 42) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 31)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 31)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 25)
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
  if (stage_v_51_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 25)
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
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000296_7_1 & 63) > 58)
  {
    stage_v_52_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  }
  else
  {
    stage_v_52_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
  }
  if ((sec_r000296_7_2 & 63) > 58)
  {
    stage_v_52_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  }
  else
  {
    stage_v_52_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_52_1 & 63) > 43)
  {
    stage_v_53_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  }
  else
  {
    stage_v_53_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 43)
  {
    stage_v_53_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  }
  else
  {
    stage_v_53_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_53_1 & 63) > 16)
  {
    stage_v_54_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  }
  else
  {
    stage_v_54_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
  }
  if ((stage_v_53_2 & 63) > 16)
  {
    stage_v_54_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  }
  else
  {
    stage_v_54_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000296_20_1 & 63) > 45)
  {
    stage_v_55_1 = ((pub_r000296_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  }
  else
  {
    stage_v_55_1 = ((pub_r000296_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
  }
  if ((sec_r000296_20_2 & 63) > 45)
  {
    stage_v_55_2 = ((pub_r000296_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  }
  else
  {
    stage_v_55_2 = ((pub_r000296_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000296_17_1 & 63) > 49)
  {
    stage_v_56_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  }
  else
  {
    stage_v_56_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
  }
  if ((sec_r000296_17_2 & 63) > 49)
  {
    stage_v_56_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  }
  else
  {
    stage_v_56_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000296_1_1 & 63) > 28)
  {
    stage_v_57_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  }
  else
  {
    stage_v_57_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
  }
  if ((sec_r000296_1_2 & 63) > 28)
  {
    stage_v_57_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  }
  else
  {
    stage_v_57_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_56_1 & 63) > 32)
  {
    stage_v_58_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  }
  else
  {
    stage_v_58_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 32)
  {
    stage_v_58_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  }
  else
  {
    stage_v_58_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000296_13_1 & 63) > 42)
  {
    stage_v_59_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  }
  else
  {
    stage_v_59_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 42)
  {
    stage_v_59_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  }
  else
  {
    stage_v_59_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000296_5_1 & 63) > 60)
  {
    stage_v_60_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  }
  else
  {
    stage_v_60_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
  }
  if ((sec_r000296_5_2 & 63) > 60)
  {
    stage_v_60_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  }
  else
  {
    stage_v_60_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_58_1 & 63) > 34)
  {
    stage_v_61_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  }
  else
  {
    stage_v_61_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 34)
  {
    stage_v_61_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  }
  else
  {
    stage_v_61_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000296_16_1 & 63) > 20)
  {
    stage_v_62_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  }
  else
  {
    stage_v_62_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
  }
  if ((sec_r000296_16_2 & 63) > 20)
  {
    stage_v_62_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  }
  else
  {
    stage_v_62_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_60_1 & 63) > 19)
  {
    stage_v_63_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  }
  else
  {
    stage_v_63_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 19)
  {
    stage_v_63_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  }
  else
  {
    stage_v_63_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_56_1 & 63) > 24)
  {
    stage_v_64_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  }
  else
  {
    stage_v_64_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 24)
  {
    stage_v_64_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  }
  else
  {
    stage_v_64_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000296_14_1 & 63) > 58)
  {
    stage_v_65_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  }
  else
  {
    stage_v_65_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
  }
  if ((sec_r000296_14_2 & 63) > 58)
  {
    stage_v_65_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  }
  else
  {
    stage_v_65_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000296_18_1 & 63) > 43)
  {
    stage_v_66_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  }
  else
  {
    stage_v_66_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
  }
  if ((sec_r000296_18_2 & 63) > 43)
  {
    stage_v_66_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  }
  else
  {
    stage_v_66_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_58_1 & 63) > 29)
  {
    stage_v_67_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  }
  else
  {
    stage_v_67_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 29)
  {
    stage_v_67_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  }
  else
  {
    stage_v_67_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_63_1 & 63) > 18)
  {
    stage_v_68_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  }
  else
  {
    stage_v_68_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 18)
  {
    stage_v_68_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  }
  else
  {
    stage_v_68_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_59_1 & 63) > 19)
  {
    stage_v_69_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  }
  else
  {
    stage_v_69_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 19)
  {
    stage_v_69_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  }
  else
  {
    stage_v_69_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_68_1 & 63) > 16)
  {
    stage_v_70_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  }
  else
  {
    stage_v_70_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 16)
  {
    stage_v_70_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  }
  else
  {
    stage_v_70_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_66_1 & 63) > 23)
  {
    stage_v_71_1 = ((pub_r000296_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  }
  else
  {
    stage_v_71_1 = ((pub_r000296_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
  }
  if ((stage_v_66_2 & 63) > 23)
  {
    stage_v_71_2 = ((pub_r000296_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  }
  else
  {
    stage_v_71_2 = ((pub_r000296_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_58_1 & 63) > 15)
  {
    stage_v_72_1 = ((pub_r000296_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  }
  else
  {
    stage_v_72_1 = ((pub_r000296_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 15)
  {
    stage_v_72_2 = ((pub_r000296_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  }
  else
  {
    stage_v_72_2 = ((pub_r000296_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000296_20_1 & 63) > 29)
  {
    stage_v_73_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  }
  else
  {
    stage_v_73_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
  }
  if ((sec_r000296_20_2 & 63) > 29)
  {
    stage_v_73_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  }
  else
  {
    stage_v_73_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 63) > 52)
  {
    stage_v_74_1 = ((pub_r000296_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  }
  else
  {
    stage_v_74_1 = ((pub_r000296_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
  }
  if ((stage_v_70_2 & 63) > 52)
  {
    stage_v_74_2 = ((pub_r000296_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  }
  else
  {
    stage_v_74_2 = ((pub_r000296_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_59_1 & 63) > 43)
  {
    stage_v_75_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  }
  else
  {
    stage_v_75_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 43)
  {
    stage_v_75_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  }
  else
  {
    stage_v_75_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_71_1 & 63) > 56)
  {
    stage_v_76_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  }
  else
  {
    stage_v_76_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
  }
  if ((stage_v_71_2 & 63) > 56)
  {
    stage_v_76_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  }
  else
  {
    stage_v_76_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000296_13_1 & 63) > 47)
  {
    stage_v_77_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  }
  else
  {
    stage_v_77_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 47)
  {
    stage_v_77_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  }
  else
  {
    stage_v_77_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000296_1_1 & 63) > 30)
  {
    stage_v_78_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  }
  else
  {
    stage_v_78_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
  }
  if ((sec_r000296_1_2 & 63) > 30)
  {
    stage_v_78_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  }
  else
  {
    stage_v_78_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_65_1 & 63) > 19)
  {
    stage_v_79_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  }
  else
  {
    stage_v_79_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
  }
  if ((stage_v_65_2 & 63) > 19)
  {
    stage_v_79_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  }
  else
  {
    stage_v_79_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000296_3_1 & 63) > 29)
  {
    stage_v_80_1 = ((pub_r000296_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  }
  else
  {
    stage_v_80_1 = ((pub_r000296_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
  }
  if ((sec_r000296_3_2 & 63) > 29)
  {
    stage_v_80_2 = ((pub_r000296_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  }
  else
  {
    stage_v_80_2 = ((pub_r000296_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000296_6_1 & 63) > 22)
  {
    stage_v_81_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  }
  else
  {
    stage_v_81_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
  }
  if ((sec_r000296_6_2 & 63) > 22)
  {
    stage_v_81_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  }
  else
  {
    stage_v_81_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_66_1 & 63) > 22)
  {
    stage_v_82_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  }
  else
  {
    stage_v_82_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
  }
  if ((stage_v_66_2 & 63) > 22)
  {
    stage_v_82_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  }
  else
  {
    stage_v_82_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000296_0_1 & 63) > 52)
  {
    stage_v_83_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  }
  else
  {
    stage_v_83_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
  }
  if ((sec_r000296_0_2 & 63) > 52)
  {
    stage_v_83_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  }
  else
  {
    stage_v_83_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_52_1 & 63) > 42)
  {
    stage_v_84_1 = ((pub_r000296_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  }
  else
  {
    stage_v_84_1 = ((pub_r000296_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 42)
  {
    stage_v_84_2 = ((pub_r000296_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  }
  else
  {
    stage_v_84_2 = ((pub_r000296_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_67_1 & 63) > 20)
  {
    stage_v_85_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  }
  else
  {
    stage_v_85_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
  }
  if ((stage_v_67_2 & 63) > 20)
  {
    stage_v_85_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  }
  else
  {
    stage_v_85_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_85_1 & 63) > 58)
  {
    stage_v_86_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  }
  else
  {
    stage_v_86_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
  }
  if ((stage_v_85_2 & 63) > 58)
  {
    stage_v_86_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  }
  else
  {
    stage_v_86_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000296_19_1 & 63) > 59)
  {
    stage_v_87_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  }
  else
  {
    stage_v_87_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
  }
  if ((sec_r000296_19_2 & 63) > 59)
  {
    stage_v_87_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  }
  else
  {
    stage_v_87_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_58_1 & 63) > 22)
  {
    stage_v_88_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  }
  else
  {
    stage_v_88_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 22)
  {
    stage_v_88_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  }
  else
  {
    stage_v_88_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_60_1 & 63) > 53)
  {
    stage_v_89_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  }
  else
  {
    stage_v_89_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 53)
  {
    stage_v_89_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  }
  else
  {
    stage_v_89_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_63_1 & 63) > 27)
  {
    stage_v_90_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  }
  else
  {
    stage_v_90_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 27)
  {
    stage_v_90_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  }
  else
  {
    stage_v_90_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_74_1 & 63) > 49)
  {
    stage_v_91_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  }
  else
  {
    stage_v_91_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
  }
  if ((stage_v_74_2 & 63) > 49)
  {
    stage_v_91_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  }
  else
  {
    stage_v_91_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_76_1 & 63) > 20)
  {
    stage_v_92_1 = ((pub_r000296_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000296_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((stage_v_76_2 & 63) > 20)
  {
    stage_v_92_2 = ((pub_r000296_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000296_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000296_3_1 & 63) > 19)
  {
    stage_v_93_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((sec_r000296_3_2 & 63) > 19)
  {
    stage_v_93_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000296_12_1 & 63) > 30)
  {
    stage_v_94_1 = ((pub_r000296_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000296_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((sec_r000296_12_2 & 63) > 30)
  {
    stage_v_94_2 = ((pub_r000296_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000296_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000296_9_1 & 63) > 47)
  {
    stage_v_95_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((sec_r000296_9_2 & 63) > 47)
  {
    stage_v_95_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_52_1 & 63) > 57)
  {
    stage_v_96_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 57)
  {
    stage_v_96_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_68_1 & 63) > 47)
  {
    stage_v_97_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 47)
  {
    stage_v_97_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000296_13_1 & 63) > 35)
  {
    stage_v_98_1 = ((pub_r000296_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000296_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 35)
  {
    stage_v_98_2 = ((pub_r000296_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000296_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000296_4_1 & 63) > 49)
  {
    stage_v_99_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((sec_r000296_4_2 & 63) > 49)
  {
    stage_v_99_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 63) > 48)
  {
    stage_v_100_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 48)
  {
    stage_v_100_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000296_4_1 & 63) > 56)
  {
    stage_v_101_1 = ((pub_r000296_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000296_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((sec_r000296_4_2 & 63) > 56)
  {
    stage_v_101_2 = ((pub_r000296_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000296_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000296_21_1 & 63) > 42)
  {
    stage_v_102_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((sec_r000296_21_2 & 63) > 42)
  {
    stage_v_102_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000296_9_1 & 63) > 22)
  {
    stage_v_103_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((sec_r000296_9_2 & 63) > 22)
  {
    stage_v_103_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_56_1 & 63) > 19)
  {
    stage_v_104_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((stage_v_56_2 & 63) > 19)
  {
    stage_v_104_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_101_1 & 63) > 37)
  {
    stage_v_105_1 = ((pub_r000296_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000296_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((stage_v_101_2 & 63) > 37)
  {
    stage_v_105_2 = ((pub_r000296_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000296_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_103_1 & 63) > 36)
  {
    stage_v_106_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((stage_v_103_2 & 63) > 36)
  {
    stage_v_106_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000296_3_1 & 63) > 53)
  {
    stage_v_107_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((sec_r000296_3_2 & 63) > 53)
  {
    stage_v_107_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_52_1 & 63) > 54)
  {
    stage_v_108_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 54)
  {
    stage_v_108_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_105_1 & 63) > 38)
  {
    stage_v_109_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((stage_v_105_2 & 63) > 38)
  {
    stage_v_109_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000296_4_1 & 63) > 28)
  {
    stage_v_110_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((sec_r000296_4_2 & 63) > 28)
  {
    stage_v_110_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_104_1 & 63) > 17)
  {
    stage_v_111_1 = ((pub_r000296_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000296_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((stage_v_104_2 & 63) > 17)
  {
    stage_v_111_2 = ((pub_r000296_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000296_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_108_1 & 63) > 43)
  {
    stage_v_112_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((stage_v_108_2 & 63) > 43)
  {
    stage_v_112_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000296_13_1 & 63) > 57)
  {
    stage_v_113_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 57)
  {
    stage_v_113_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_72_1 & 63) > 24)
  {
    stage_v_114_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_72_2 & 63) > 24)
  {
    stage_v_114_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_83_1 & 63) > 25)
  {
    stage_v_115_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((stage_v_83_2 & 63) > 25)
  {
    stage_v_115_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_85_1 & 63) > 33)
  {
    stage_v_116_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((stage_v_85_2 & 63) > 33)
  {
    stage_v_116_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000296_21_1 & 63) > 59)
  {
    stage_v_117_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((sec_r000296_21_2 & 63) > 59)
  {
    stage_v_117_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_85_1 & 63) > 27)
  {
    stage_v_118_1 = ((pub_r000296_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000296_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((stage_v_85_2 & 63) > 27)
  {
    stage_v_118_2 = ((pub_r000296_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000296_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_108_1 & 63) > 45)
  {
    stage_v_119_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((stage_v_108_2 & 63) > 45)
  {
    stage_v_119_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000296_12_1 & 63) > 30)
  {
    stage_v_120_1 = ((pub_r000296_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000296_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((sec_r000296_12_2 & 63) > 30)
  {
    stage_v_120_2 = ((pub_r000296_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000296_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000296_0_1 & 63) > 31)
  {
    stage_v_121_1 = ((pub_r000296_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000296_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((sec_r000296_0_2 & 63) > 31)
  {
    stage_v_121_2 = ((pub_r000296_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000296_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_105_1 & 63) > 15)
  {
    stage_v_122_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_105_2 & 63) > 15)
  {
    stage_v_122_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000296_4_1 & 63) > 50)
  {
    stage_v_123_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((sec_r000296_4_2 & 63) > 50)
  {
    stage_v_123_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000296_2_1 & 63) > 32)
  {
    stage_v_124_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((sec_r000296_2_2 & 63) > 32)
  {
    stage_v_124_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000296_19_1 & 63) > 35)
  {
    stage_v_125_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((sec_r000296_19_2 & 63) > 35)
  {
    stage_v_125_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_124_1 & 63) > 27)
  {
    stage_v_126_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((stage_v_124_2 & 63) > 27)
  {
    stage_v_126_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000296_2_1 & 63) > 50)
  {
    stage_v_127_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((sec_r000296_2_2 & 63) > 50)
  {
    stage_v_127_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_119_1 & 63) > 33)
  {
    stage_v_128_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((stage_v_119_2 & 63) > 33)
  {
    stage_v_128_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_98_1 & 63) > 50)
  {
    stage_v_129_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((stage_v_98_2 & 63) > 50)
  {
    stage_v_129_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_95_1 & 63) > 27)
  {
    stage_v_130_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 27)
  {
    stage_v_130_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_127_1 & 63) > 16)
  {
    stage_v_131_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((stage_v_127_2 & 63) > 16)
  {
    stage_v_131_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000296_6_1 & 63) > 35)
  {
    stage_v_132_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((sec_r000296_6_2 & 63) > 35)
  {
    stage_v_132_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_80_1 & 63) > 25)
  {
    stage_v_133_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((stage_v_80_2 & 63) > 25)
  {
    stage_v_133_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000296_3_1 & 63) > 24)
  {
    stage_v_134_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((sec_r000296_3_2 & 63) > 24)
  {
    stage_v_134_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_61_1 & 63) > 46)
  {
    stage_v_135_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((stage_v_61_2 & 63) > 46)
  {
    stage_v_135_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000296_4_1 & 63) > 54)
  {
    stage_v_136_1 = ((pub_r000296_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000296_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((sec_r000296_4_2 & 63) > 54)
  {
    stage_v_136_2 = ((pub_r000296_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000296_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000296_21_1 & 63) > 38)
  {
    stage_v_137_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((sec_r000296_21_2 & 63) > 38)
  {
    stage_v_137_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_60_1 & 63) > 15)
  {
    stage_v_138_1 = ((pub_r000296_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000296_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 15)
  {
    stage_v_138_2 = ((pub_r000296_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000296_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_63_1 & 63) > 39)
  {
    stage_v_139_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 39)
  {
    stage_v_139_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_94_1 & 63) > 58)
  {
    stage_v_140_1 = ((pub_r000296_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000296_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((stage_v_94_2 & 63) > 58)
  {
    stage_v_140_2 = ((pub_r000296_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000296_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_88_1 & 63) > 59)
  {
    stage_v_141_1 = ((pub_r000296_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000296_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((stage_v_88_2 & 63) > 59)
  {
    stage_v_141_2 = ((pub_r000296_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000296_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000296_19_1 & 63) > 40)
  {
    stage_v_142_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((sec_r000296_19_2 & 63) > 40)
  {
    stage_v_142_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000296_13_1 & 63) > 42)
  {
    stage_v_143_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 42)
  {
    stage_v_143_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000296_12_1 & 63) > 60)
  {
    stage_v_144_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((sec_r000296_12_2 & 63) > 60)
  {
    stage_v_144_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_101_1 & 63) > 47)
  {
    stage_v_145_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((stage_v_101_2 & 63) > 47)
  {
    stage_v_145_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_135_1 & 63) > 21)
  {
    stage_v_146_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((stage_v_135_2 & 63) > 21)
  {
    stage_v_146_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000296_2_1 & 63) > 22)
  {
    stage_v_147_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((sec_r000296_2_2 & 63) > 22)
  {
    stage_v_147_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_98_1 & 63) > 54)
  {
    stage_v_148_1 = ((pub_r000296_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000296_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((stage_v_98_2 & 63) > 54)
  {
    stage_v_148_2 = ((pub_r000296_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000296_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_106_1 & 63) > 18)
  {
    stage_v_149_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 18)
  {
    stage_v_149_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_147_1 & 63) > 15)
  {
    stage_v_150_1 = ((pub_r000296_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000296_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((stage_v_147_2 & 63) > 15)
  {
    stage_v_150_2 = ((pub_r000296_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000296_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_82_1 & 63) > 47)
  {
    stage_v_151_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((stage_v_82_2 & 63) > 47)
  {
    stage_v_151_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_146_1 & 63) > 48)
  {
    stage_v_152_1 = ((pub_r000296_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000296_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_146_2 & 63) > 48)
  {
    stage_v_152_2 = ((pub_r000296_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000296_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_140_1 & 63) > 35)
  {
    stage_v_153_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  }
  else
  {
    stage_v_153_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
  }
  if ((stage_v_140_2 & 63) > 35)
  {
    stage_v_153_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  }
  else
  {
    stage_v_153_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_60_1 & 63) > 22)
  {
    stage_v_154_1 = ((pub_r000296_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  }
  else
  {
    stage_v_154_1 = ((pub_r000296_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 22)
  {
    stage_v_154_2 = ((pub_r000296_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  }
  else
  {
    stage_v_154_2 = ((pub_r000296_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000296_20_1 & 63) > 23)
  {
    stage_v_155_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  }
  else
  {
    stage_v_155_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
  }
  if ((sec_r000296_20_2 & 63) > 23)
  {
    stage_v_155_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  }
  else
  {
    stage_v_155_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_117_1 & 63) > 21)
  {
    stage_v_156_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  }
  else
  {
    stage_v_156_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
  }
  if ((stage_v_117_2 & 63) > 21)
  {
    stage_v_156_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  }
  else
  {
    stage_v_156_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_146_1 & 63) > 34)
  {
    stage_v_157_1 = ((pub_r000296_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  }
  else
  {
    stage_v_157_1 = ((pub_r000296_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
  }
  if ((stage_v_146_2 & 63) > 34)
  {
    stage_v_157_2 = ((pub_r000296_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  }
  else
  {
    stage_v_157_2 = ((pub_r000296_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_95_1 & 63) > 58)
  {
    stage_v_158_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  }
  else
  {
    stage_v_158_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 58)
  {
    stage_v_158_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  }
  else
  {
    stage_v_158_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_83_1 & 63) > 25)
  {
    stage_v_159_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  }
  else
  {
    stage_v_159_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
  }
  if ((stage_v_83_2 & 63) > 25)
  {
    stage_v_159_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  }
  else
  {
    stage_v_159_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000296_13_1 & 63) > 17)
  {
    stage_v_160_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  }
  else
  {
    stage_v_160_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
  }
  if ((sec_r000296_13_2 & 63) > 17)
  {
    stage_v_160_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  }
  else
  {
    stage_v_160_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((sec_r000296_21_1 & 63) > 34)
  {
    stage_v_161_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  }
  else
  {
    stage_v_161_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
  }
  if ((sec_r000296_21_2 & 63) > 34)
  {
    stage_v_161_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  }
  else
  {
    stage_v_161_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_157_1 & 63) > 17)
  {
    stage_v_162_1 = ((pub_r000296_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  }
  else
  {
    stage_v_162_1 = ((pub_r000296_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
  }
  if ((stage_v_157_2 & 63) > 17)
  {
    stage_v_162_2 = ((pub_r000296_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  }
  else
  {
    stage_v_162_2 = ((pub_r000296_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((sec_r000296_17_1 & 63) > 26)
  {
    stage_v_163_1 = ((pub_r000296_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  }
  else
  {
    stage_v_163_1 = ((pub_r000296_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
  }
  if ((sec_r000296_17_2 & 63) > 26)
  {
    stage_v_163_2 = ((pub_r000296_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  }
  else
  {
    stage_v_163_2 = ((pub_r000296_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_134_1 & 63) > 16)
  {
    stage_v_164_1 = ((pub_r000296_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  }
  else
  {
    stage_v_164_1 = ((pub_r000296_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
  }
  if ((stage_v_134_2 & 63) > 16)
  {
    stage_v_164_2 = ((pub_r000296_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  }
  else
  {
    stage_v_164_2 = ((pub_r000296_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_136_1 & 63) > 60)
  {
    stage_v_165_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  }
  else
  {
    stage_v_165_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
  }
  if ((stage_v_136_2 & 63) > 60)
  {
    stage_v_165_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  }
  else
  {
    stage_v_165_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((sec_r000296_6_1 & 63) > 59)
  {
    stage_v_166_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  }
  else
  {
    stage_v_166_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
  }
  if ((sec_r000296_6_2 & 63) > 59)
  {
    stage_v_166_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  }
  else
  {
    stage_v_166_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((sec_r000296_7_1 & 63) > 35)
  {
    stage_v_167_1 = ((pub_r000296_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  }
  else
  {
    stage_v_167_1 = ((pub_r000296_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
  }
  if ((sec_r000296_7_2 & 63) > 35)
  {
    stage_v_167_2 = ((pub_r000296_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  }
  else
  {
    stage_v_167_2 = ((pub_r000296_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  if ((stage_v_88_1 & 63) > 36)
  {
    stage_v_168_1 = ((pub_r000296_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  }
  else
  {
    stage_v_168_1 = ((pub_r000296_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
  }
  if ((stage_v_88_2 & 63) > 36)
  {
    stage_v_168_2 = ((pub_r000296_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  }
  else
  {
    stage_v_168_2 = ((pub_r000296_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  if ((stage_v_110_1 & 63) > 39)
  {
    stage_v_169_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  }
  else
  {
    stage_v_169_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
  }
  if ((stage_v_110_2 & 63) > 39)
  {
    stage_v_169_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  }
  else
  {
    stage_v_169_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  if ((stage_v_60_1 & 63) > 51)
  {
    stage_v_170_1 = ((pub_r000296_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  }
  else
  {
    stage_v_170_1 = ((pub_r000296_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 51)
  {
    stage_v_170_2 = ((pub_r000296_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  }
  else
  {
    stage_v_170_2 = ((pub_r000296_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  if ((stage_v_136_1 & 63) > 26)
  {
    stage_v_171_1 = ((pub_r000296_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  }
  else
  {
    stage_v_171_1 = ((pub_r000296_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
  }
  if ((stage_v_136_2 & 63) > 26)
  {
    stage_v_171_2 = ((pub_r000296_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  }
  else
  {
    stage_v_171_2 = ((pub_r000296_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  if ((stage_v_77_1 & 63) > 29)
  {
    stage_v_172_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  }
  else
  {
    stage_v_172_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
  }
  if ((stage_v_77_2 & 63) > 29)
  {
    stage_v_172_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  }
  else
  {
    stage_v_172_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  if ((stage_v_159_1 & 63) > 57)
  {
    stage_v_173_1 = ((pub_r000296_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  }
  else
  {
    stage_v_173_1 = ((pub_r000296_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
  }
  if ((stage_v_159_2 & 63) > 57)
  {
    stage_v_173_2 = ((pub_r000296_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  }
  else
  {
    stage_v_173_2 = ((pub_r000296_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  if ((stage_v_152_1 & 63) > 56)
  {
    stage_v_174_1 = ((pub_r000296_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  }
  else
  {
    stage_v_174_1 = ((pub_r000296_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
  }
  if ((stage_v_152_2 & 63) > 56)
  {
    stage_v_174_2 = ((pub_r000296_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  }
  else
  {
    stage_v_174_2 = ((pub_r000296_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  if ((stage_v_113_1 & 63) > 37)
  {
    stage_v_175_1 = ((pub_r000296_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  }
  else
  {
    stage_v_175_1 = ((pub_r000296_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
  }
  if ((stage_v_113_2 & 63) > 37)
  {
    stage_v_175_2 = ((pub_r000296_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  }
  else
  {
    stage_v_175_2 = ((pub_r000296_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  if ((stage_v_174_1 & 63) > 46)
  {
    stage_v_176_1 = ((pub_r000296_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  }
  else
  {
    stage_v_176_1 = ((pub_r000296_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
  }
  if ((stage_v_174_2 & 63) > 46)
  {
    stage_v_176_2 = ((pub_r000296_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  }
  else
  {
    stage_v_176_2 = ((pub_r000296_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000296_2_1 == pub_r000296_2_2);
  __CPROVER_assume(pub_r000296_4_1 == pub_r000296_4_2);
  __CPROVER_assume(sec_r000296_8_1 != sec_r000296_8_2);
  __CPROVER_assume(sec_r000296_3_1 != sec_r000296_3_2);
  __CPROVER_assume(pub_r000296_13_1 == pub_r000296_13_2);
  __CPROVER_assume(sec_r000296_15_1 != sec_r000296_15_2);
  __CPROVER_assume(pub_r000296_8_1 == pub_r000296_8_2);
  __CPROVER_assume(sec_r000296_20_1 != sec_r000296_20_2);
  __CPROVER_assume(pub_r000296_6_1 == pub_r000296_6_2);
  __CPROVER_assume(pub_r000296_1_1 == pub_r000296_1_2);
  __CPROVER_assume(pub_r000296_3_1 == pub_r000296_3_2);
  __CPROVER_assume(sec_r000296_10_1 != sec_r000296_10_2);
  __CPROVER_assume(sec_r000296_7_1 != sec_r000296_7_2);
  __CPROVER_assume(pub_r000296_10_1 == pub_r000296_10_2);
  __CPROVER_assume(sec_r000296_12_1 != sec_r000296_12_2);
  __CPROVER_assume(pub_r000296_12_1 == pub_r000296_12_2);
  __CPROVER_assume(sec_r000296_2_1 != sec_r000296_2_2);
  __CPROVER_assume(pub_r000296_9_1 == pub_r000296_9_2);
  __CPROVER_assume(sec_r000296_18_1 != sec_r000296_18_2);
  __CPROVER_assume(sec_r000296_1_1 != sec_r000296_1_2);
  __CPROVER_assume(sec_r000296_6_1 != sec_r000296_6_2);
  __CPROVER_assume(sec_r000296_13_1 != sec_r000296_13_2);
  __CPROVER_assume(sec_r000296_0_1 != sec_r000296_0_2);
  __CPROVER_assume(sec_r000296_9_1 != sec_r000296_9_2);
  __CPROVER_assume(sec_r000296_19_1 != sec_r000296_19_2);
  __CPROVER_assume(sec_r000296_21_1 != sec_r000296_21_2);
  __CPROVER_assume(sec_r000296_16_1 != sec_r000296_16_2);
  __CPROVER_assume(pub_r000296_0_1 == pub_r000296_0_2);
  __CPROVER_assume(pub_r000296_15_1 == pub_r000296_15_2);
  __CPROVER_assume(sec_r000296_5_1 != sec_r000296_5_2);
  __CPROVER_assume(pub_r000296_7_1 == pub_r000296_7_2);
  __CPROVER_assume(sec_r000296_11_1 != sec_r000296_11_2);
  __CPROVER_assume(pub_r000296_5_1 == pub_r000296_5_2);
  __CPROVER_assume(sec_r000296_17_1 != sec_r000296_17_2);
  __CPROVER_assume(sec_r000296_4_1 != sec_r000296_4_2);
  __CPROVER_assume(pub_r000296_14_1 == pub_r000296_14_2);
  __CPROVER_assume(pub_r000296_11_1 == pub_r000296_11_2);
  __CPROVER_assume(sec_r000296_14_1 != sec_r000296_14_2);
  __CPROVER_assume(pub_r000296_16_1 == pub_r000296_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
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
}


