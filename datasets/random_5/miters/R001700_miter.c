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
struct DeviceConfig_R001700_13_0
{
  int stop_bits;
  int id;
  int baud_rate;
  int buffer[3];
};
struct Transaction_R001700_13_1
{
  unsigned char status;
  int auth_code;
  int rate;
  unsigned char balance;
  int buffer[3];
};
struct StreamBuffer_R001700_13_2
{
  int tail;
  short state;
  short capacity;
  short checksum;
  int buffer[3];
};
struct Vector3D_R001700_13_3
{
  int pitch;
  int heading;
  unsigned char coord_x;
  unsigned char norm_sq;
  unsigned char coord_y;
  int buffer[3];
};
union RegisterBank_R001700_13_0
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
void fn_R001700_13_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_82_1 > 13)
  {
    acc_1 = ((acc_1 + (anchor_82_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_82_2 > 13)
  {
    acc_2 = ((acc_2 + (anchor_82_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_77_1 = local_arr_1[aux_1 % 3];
  int threshold_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_82_1 == anchor_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_77_1 == threshold_77_2);
}

int fn_R001700_13_0(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_82 > 13)
  {
    acc = ((acc + (anchor_82 * 2)) + 5) & 127;
    aux ^= anchor_82 & 15;
  }
  else
  {
    acc = ((acc - anchor_82) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_77 = local_arr[aux % 3];
  acc = (acc + (threshold_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001700_13_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st_1 = {0};
  struct DeviceConfig_R001700_13_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_96_1 = local_arr_1[aux_1 % 3];
  int index_reg_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_96_2 * 2)) & 127;
  int tracker_76_1 = 0;
  int tracker_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_76_1 = ((tracker_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_76_2 = ((tracker_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_76_1) & 127;
    acc_2 = (acc_2 + tracker_76_2) & 127;
  }

  int index_reg_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_43_1 > 41)
  {
    acc_1 = ((acc_1 + (index_reg_43_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_43_2 > 41)
  {
    acc_2 = ((acc_2 + (index_reg_43_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_96_1 == index_reg_96_2);
  assert(tracker_76_1 == tracker_76_2);
  assert(index_reg_43_1 == index_reg_43_2);
}

int fn_R001700_13_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int index_reg_96 = local_arr[aux % 3];
  acc = (acc + (index_reg_96 * 2)) & 127;
  int tracker_76 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_76 = ((tracker_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_76) & 127;
  }

  int index_reg_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_43 > 41)
  {
    acc = ((acc + (index_reg_43 * 2)) + 5) & 127;
    aux ^= index_reg_43 & 15;
  }
  else
  {
    acc = ((acc - index_reg_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_83_1 = local_arr_1[aux_1 % 3];
  int window_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_83_2 * 2)) & 127;
  int parity_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_80_1) & 63;
  aux_2 = (aux_2 + parity_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_92_1 > 41)
  {
    acc_1 = ((acc_1 + (stride_92_1 * 2)) + 5) & 127;
    aux_1 ^= stride_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_92_2 > 41)
  {
    acc_2 = ((acc_2 + (stride_92_2 * 2)) + 5) & 127;
    aux_2 ^= stride_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_83_1 == window_83_2);
  assert(parity_80_1 == parity_80_2);
  assert(stride_92_1 == stride_92_2);
}

int fn_R001700_13_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int window_83 = local_arr[aux % 3];
  acc = (acc + (window_83 * 2)) & 127;
  int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_80) & 63;
  acc ^= aux;
  int stride_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_92 > 41)
  {
    acc = ((acc + (stride_92 * 2)) + 5) & 127;
    aux ^= stride_92 & 15;
  }
  else
  {
    acc = ((acc - stride_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st_1 = {0};
  struct DeviceConfig_R001700_13_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int index_reg_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_55_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_55_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_55_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_55_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_36_1 = 0;
  int segment_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_36_1 = ((segment_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_36_2 = ((segment_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_36_1) & 127;
    acc_2 = (acc_2 + segment_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_55_1 == index_reg_55_2);
  assert(segment_36_1 == segment_36_2);
}

int fn_R001700_13_3(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int index_reg_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_55 > 38)
  {
    acc = ((acc + (index_reg_55 * 2)) + 5) & 127;
    aux ^= index_reg_55 & 15;
  }
  else
  {
    acc = ((acc - index_reg_55) + 11) & 127;
    aux += 3;
  }
  int segment_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_36 = ((segment_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001700_13_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int index_reg_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_29_1) & 63;
  aux_2 = (aux_2 + index_reg_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_26_1 > 36)
  {
    acc_1 = ((acc_1 + (residue_26_1 * 2)) + 5) & 127;
    aux_1 ^= residue_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_26_2 > 36)
  {
    acc_2 = ((acc_2 + (residue_26_2 * 2)) + 5) & 127;
    aux_2 ^= residue_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_29_1)
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

  switch (phase_29_2)
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

  int window_61_1 = 0;
  int window_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_61_1 = ((window_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_61_2 = ((window_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_61_1) & 127;
    acc_2 = (acc_2 + window_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_29_1 == index_reg_29_2);
  assert(residue_26_1 == residue_26_2);
  assert(phase_29_1 == phase_29_2);
  assert(window_61_1 == window_61_2);
}

int fn_R001700_13_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int index_reg_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_29) & 63;
  acc ^= aux;
  int residue_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_26 > 36)
  {
    acc = ((acc + (residue_26 * 2)) + 5) & 127;
    aux ^= residue_26 & 15;
  }
  else
  {
    acc = ((acc - residue_26) + 11) & 127;
    aux += 3;
  }
  int phase_29 = (aux + st.buffer[1]) & 3;
  switch (phase_29)
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

  int window_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_61 = ((window_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001700_13_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st_1 = {0};
  struct Vector3D_R001700_13_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_21_1 = local_arr_1[aux_1 % 3];
  int delta_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_21_2 * 2)) & 127;
  int vector_72_1 = 0;
  int vector_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_72_1 = ((vector_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_72_2 = ((vector_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_72_1) & 127;
    acc_2 = (acc_2 + vector_72_2) & 127;
  }

  int tracker_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_40_1 > 43)
  {
    acc_1 = ((acc_1 + (tracker_40_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_40_2 > 43)
  {
    acc_2 = ((acc_2 + (tracker_40_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_54_1)
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

  switch (bound_54_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_21_1 == delta_21_2);
  assert(vector_72_1 == vector_72_2);
  assert(tracker_40_1 == tracker_40_2);
  assert(bound_54_1 == bound_54_2);
}

int fn_R001700_13_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int delta_21 = local_arr[aux % 3];
  acc = (acc + (delta_21 * 2)) & 127;
  int vector_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_72 = ((vector_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_72) & 127;
  }

  int tracker_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_40 > 43)
  {
    acc = ((acc + (tracker_40 * 2)) + 5) & 127;
    aux ^= tracker_40 & 15;
  }
  else
  {
    acc = ((acc - tracker_40) + 11) & 127;
    aux += 3;
  }
  int bound_54 = (aux + st.buffer[1]) & 3;
  switch (bound_54)
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

void fn_R001700_13_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_56_1 = local_arr_1[aux_1 % 3];
  int tally_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_56_1 == tally_56_2);
}

int fn_R001700_13_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int tally_56 = local_arr[aux % 3];
  acc = (acc + (tally_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001700_13_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_99_1)
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

  switch (metric_99_2)
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

  int scale_99_1 = 0;
  int scale_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_99_1 = ((scale_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_99_2 = ((scale_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_99_1) & 127;
    acc_2 = (acc_2 + scale_99_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_54_1 > 28)
  {
    acc_1 = ((acc_1 + (cursor_54_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_54_2 > 28)
  {
    acc_2 = ((acc_2 + (cursor_54_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_99_1 == metric_99_2);
  assert(scale_99_1 == scale_99_2);
  assert(cursor_54_1 == cursor_54_2);
}

int fn_R001700_13_7(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_99 = (aux + st.buffer[1]) & 3;
  switch (metric_99)
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

  int scale_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_99 = ((scale_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_99) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_54 > 28)
  {
    acc = ((acc + (cursor_54 * 2)) + 5) & 127;
    aux ^= cursor_54 & 15;
  }
  else
  {
    acc = ((acc - cursor_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st_1 = {0};
  struct Transaction_R001700_13_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_16_1 = local_arr_1[aux_1 % 3];
  int accumulator_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_16_2 * 2)) & 127;
  int pivot_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_80_1)
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

  switch (pivot_80_2)
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

  int parity_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_34_1) & 63;
  aux_2 = (aux_2 + parity_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_16_1 == accumulator_16_2);
  assert(pivot_80_1 == pivot_80_2);
  assert(parity_34_1 == parity_34_2);
}

int fn_R001700_13_8(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int accumulator_16 = local_arr[aux % 3];
  acc = (acc + (accumulator_16 * 2)) & 127;
  int pivot_80 = (aux + st.buffer[1]) & 3;
  switch (pivot_80)
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

  int parity_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001700_13_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st_1 = {0};
  struct Transaction_R001700_13_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_21_1 > 18)
  {
    acc_1 = ((acc_1 + (cursor_21_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_21_2 > 18)
  {
    acc_2 = ((acc_2 + (cursor_21_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_14_1 = 0;
  int window_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_14_1 = ((window_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_14_2 = ((window_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_14_1) & 127;
    acc_2 = (acc_2 + window_14_2) & 127;
  }

  int metric_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_27_1) & 63;
  aux_2 = (aux_2 + metric_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_39_1)
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

  switch (offset_39_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(window_14_1 == window_14_2);
  assert(metric_27_1 == metric_27_2);
  assert(offset_39_1 == offset_39_2);
}

int fn_R001700_13_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_21 > 18)
  {
    acc = ((acc + (cursor_21 * 2)) + 5) & 127;
    aux ^= cursor_21 & 15;
  }
  else
  {
    acc = ((acc - cursor_21) + 11) & 127;
    aux += 3;
  }
  int window_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_14 = ((window_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_14) & 127;
  }

  int metric_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_27) & 63;
  acc ^= aux;
  int offset_39 = (aux + st.buffer[1]) & 3;
  switch (offset_39)
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

void fn_R001700_13_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st_1 = {0};
  struct Vector3D_R001700_13_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_39_1)
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

  switch (damping_39_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_39_1 == damping_39_2);
}

int fn_R001700_13_10(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_39 = (aux + st.buffer[1]) & 3;
  switch (damping_39)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001700_13_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st_1 = {0};
  struct Transaction_R001700_13_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int threshold_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_57_1) & 63;
  aux_2 = (aux_2 + threshold_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_41_1 > 45)
  {
    acc_1 = ((acc_1 + (vector_41_1 * 2)) + 5) & 127;
    aux_1 ^= vector_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_41_2 > 45)
  {
    acc_2 = ((acc_2 + (vector_41_2 * 2)) + 5) & 127;
    aux_2 ^= vector_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
  assert(vector_41_1 == vector_41_2);
}

int fn_R001700_13_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001700_13_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_57) & 63;
  acc ^= aux;
  int vector_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_41 > 45)
  {
    acc = ((acc + (vector_41 * 2)) + 5) & 127;
    aux ^= vector_41 & 15;
  }
  else
  {
    acc = ((acc - vector_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st_1 = {0};
  struct DeviceConfig_R001700_13_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_24_1 = local_arr_1[aux_1 % 3];
  int residue_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_24_2 * 2)) & 127;
  int damping_75_1 = 0;
  int damping_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_75_1 = ((damping_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_75_2 = ((damping_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_75_1) & 127;
    acc_2 = (acc_2 + damping_75_2) & 127;
  }

  int factor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_26_1)
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

  switch (factor_26_2)
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

  int stride_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_56_1 > 35)
  {
    acc_1 = ((acc_1 + (stride_56_1 * 2)) + 5) & 127;
    aux_1 ^= stride_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_56_2 > 35)
  {
    acc_2 = ((acc_2 + (stride_56_2 * 2)) + 5) & 127;
    aux_2 ^= stride_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_24_1 == residue_24_2);
  assert(damping_75_1 == damping_75_2);
  assert(factor_26_1 == factor_26_2);
  assert(stride_56_1 == stride_56_2);
}

int fn_R001700_13_12(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int residue_24 = local_arr[aux % 3];
  acc = (acc + (residue_24 * 2)) & 127;
  int damping_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_75 = ((damping_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_75) & 127;
  }

  int factor_26 = (aux + st.buffer[1]) & 3;
  switch (factor_26)
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

  int stride_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_56 > 35)
  {
    acc = ((acc + (stride_56 * 2)) + 5) & 127;
    aux ^= stride_56 & 15;
  }
  else
  {
    acc = ((acc - stride_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st_1 = {0};
  struct Vector3D_R001700_13_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_11_1 = 0;
  int segment_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_11_1 = ((segment_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_11_2 = ((segment_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_11_1) & 127;
    acc_2 = (acc_2 + segment_11_2) & 127;
  }

  int damping_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_78_1)
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

  switch (damping_78_2)
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
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  int phase_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_83_1) & 63;
  aux_2 = (aux_2 + phase_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_11_1 == segment_11_2);
  assert(damping_78_1 == damping_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(phase_83_1 == phase_83_2);
}

int fn_R001700_13_13(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001700_13_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_11 = ((segment_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_11) & 127;
  }

  int damping_78 = (aux + st.buffer[1]) & 3;
  switch (damping_78)
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
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001700_13_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st_1 = {0};
  struct DeviceConfig_R001700_13_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_66_1 = local_arr_1[aux_1 % 3];
  int factor_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_66_2 * 2)) & 127;
  int quantum_40_1 = 0;
  int quantum_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_40_1 = ((quantum_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_40_2 = ((quantum_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_40_1) & 127;
    acc_2 = (acc_2 + quantum_40_2) & 127;
  }

  int cursor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_42_1 > 30)
  {
    acc_1 = ((acc_1 + (cursor_42_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_42_2 > 30)
  {
    acc_2 = ((acc_2 + (cursor_42_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_66_1 == factor_66_2);
  assert(quantum_40_1 == quantum_40_2);
  assert(cursor_42_1 == cursor_42_2);
}

int fn_R001700_13_14(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int factor_66 = local_arr[aux % 3];
  acc = (acc + (factor_66 * 2)) & 127;
  int quantum_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_40 = ((quantum_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_40) & 127;
  }

  int cursor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_42 > 30)
  {
    acc = ((acc + (cursor_42 * 2)) + 5) & 127;
    aux ^= cursor_42 & 15;
  }
  else
  {
    acc = ((acc - cursor_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001700_13_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_23_1 = 0;
  int threshold_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_23_1 = ((threshold_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_23_2 = ((threshold_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_23_1) & 127;
    acc_2 = (acc_2 + threshold_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_23_1 == threshold_23_2);
}

int fn_R001700_13_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_23 = ((threshold_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001700_13_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st_1 = {0};
  struct StreamBuffer_R001700_13_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int delta_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_48_1) & 63;
  aux_2 = (aux_2 + delta_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_39_1 = 0;
  int index_reg_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_39_1 = ((index_reg_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_39_2 = ((index_reg_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_39_1) & 127;
    acc_2 = (acc_2 + index_reg_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_48_1 == delta_48_2);
  assert(index_reg_39_1 == index_reg_39_2);
}

int fn_R001700_13_16(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001700_13_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_48) & 63;
  acc ^= aux;
  int index_reg_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_39 = ((index_reg_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001700_13_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st_1 = {0};
  struct DeviceConfig_R001700_13_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_58_1 = 0;
  int tally_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_58_1 = ((tally_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_58_2 = ((tally_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_58_1) & 127;
    acc_2 = (acc_2 + tally_58_2) & 127;
  }

  int index_reg_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_79_1)
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

  switch (index_reg_79_2)
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
  int mask_33_1 = local_arr_1[aux_1 % 3];
  int mask_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_58_1 == tally_58_2);
  assert(index_reg_79_1 == index_reg_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_33_1 == mask_33_2);
}

int fn_R001700_13_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001700_13_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_58 = ((tally_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_58) & 127;
  }

  int index_reg_79 = (aux + st.buffer[1]) & 3;
  switch (index_reg_79)
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
  int mask_33 = local_arr[aux % 3];
  acc = (acc + (mask_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001700_0_1;
  int sec_r001700_0_2;
  int sec_r001700_1_1;
  int sec_r001700_1_2;
  int sec_r001700_2_1;
  int sec_r001700_2_2;
  int sec_r001700_3_1;
  int sec_r001700_3_2;
  int sec_r001700_4_1;
  int sec_r001700_4_2;
  int sec_r001700_5_1;
  int sec_r001700_5_2;
  int sec_r001700_6_1;
  int sec_r001700_6_2;
  int sec_r001700_7_1;
  int sec_r001700_7_2;
  int sec_r001700_8_1;
  int sec_r001700_8_2;
  int sec_r001700_9_1;
  int sec_r001700_9_2;
  int sec_r001700_10_1;
  int sec_r001700_10_2;
  int sec_r001700_11_1;
  int sec_r001700_11_2;
  int sec_r001700_12_1;
  int sec_r001700_12_2;
  int sec_r001700_13_1;
  int sec_r001700_13_2;
  int sec_r001700_14_1;
  int sec_r001700_14_2;
  int sec_r001700_15_1;
  int sec_r001700_15_2;
  int sec_r001700_16_1;
  int sec_r001700_16_2;
  int sec_r001700_17_1;
  int sec_r001700_17_2;
  int pub_r001700_0_1;
  int pub_r001700_0_2;
  int pub_r001700_1_1;
  int pub_r001700_1_2;
  int pub_r001700_2_1;
  int pub_r001700_2_2;
  int pub_r001700_3_1;
  int pub_r001700_3_2;
  int pub_r001700_4_1;
  int pub_r001700_4_2;
  int pub_r001700_5_1;
  int pub_r001700_5_2;
  int pub_r001700_6_1;
  int pub_r001700_6_2;
  int pub_r001700_7_1;
  int pub_r001700_7_2;
  int pub_r001700_8_1;
  int pub_r001700_8_2;
  int pub_r001700_9_1;
  int pub_r001700_9_2;
  int pub_r001700_10_1;
  int pub_r001700_10_2;
  int pub_r001700_11_1;
  int pub_r001700_11_2;
  int pub_r001700_12_1;
  int pub_r001700_12_2;
  int pub_r001700_13_1;
  int pub_r001700_13_2;
  int pub_r001700_14_1;
  int pub_r001700_14_2;
  int pub_r001700_15_1;
  int pub_r001700_15_2;
  int pub_r001700_16_1;
  int pub_r001700_16_2;
  int pub_r001700_17_1;
  int pub_r001700_17_2;
  int pub_r001700_18_1;
  int pub_r001700_18_2;
  int pub_r001700_19_1;
  int pub_r001700_19_2;
  int pub_r001700_20_1;
  int pub_r001700_20_2;
  int pub_r001700_21_1;
  int pub_r001700_21_2;
  int pub_r001700_22_1;
  int pub_r001700_22_2;
  int pub_r001700_23_1;
  int pub_r001700_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001700_0_1 >= (-100)) && (pub_r001700_0_1 <= 100));
  __CPROVER_assume((pub_r001700_0_2 >= (-100)) && (pub_r001700_0_2 <= 100));
  __CPROVER_assume((pub_r001700_1_1 >= (-100)) && (pub_r001700_1_1 <= 100));
  __CPROVER_assume((pub_r001700_1_2 >= (-100)) && (pub_r001700_1_2 <= 100));
  __CPROVER_assume((pub_r001700_2_1 >= (-100)) && (pub_r001700_2_1 <= 100));
  __CPROVER_assume((pub_r001700_2_2 >= (-100)) && (pub_r001700_2_2 <= 100));
  __CPROVER_assume((pub_r001700_3_1 >= (-100)) && (pub_r001700_3_1 <= 100));
  __CPROVER_assume((pub_r001700_3_2 >= (-100)) && (pub_r001700_3_2 <= 100));
  __CPROVER_assume((pub_r001700_4_1 >= (-100)) && (pub_r001700_4_1 <= 100));
  __CPROVER_assume((pub_r001700_4_2 >= (-100)) && (pub_r001700_4_2 <= 100));
  __CPROVER_assume((pub_r001700_5_1 >= (-100)) && (pub_r001700_5_1 <= 100));
  __CPROVER_assume((pub_r001700_5_2 >= (-100)) && (pub_r001700_5_2 <= 100));
  __CPROVER_assume((pub_r001700_6_1 >= (-100)) && (pub_r001700_6_1 <= 100));
  __CPROVER_assume((pub_r001700_6_2 >= (-100)) && (pub_r001700_6_2 <= 100));
  __CPROVER_assume((pub_r001700_7_1 >= (-100)) && (pub_r001700_7_1 <= 100));
  __CPROVER_assume((pub_r001700_7_2 >= (-100)) && (pub_r001700_7_2 <= 100));
  __CPROVER_assume((pub_r001700_8_1 >= (-100)) && (pub_r001700_8_1 <= 100));
  __CPROVER_assume((pub_r001700_8_2 >= (-100)) && (pub_r001700_8_2 <= 100));
  __CPROVER_assume((pub_r001700_9_1 >= (-100)) && (pub_r001700_9_1 <= 100));
  __CPROVER_assume((pub_r001700_9_2 >= (-100)) && (pub_r001700_9_2 <= 100));
  __CPROVER_assume((pub_r001700_10_1 >= (-100)) && (pub_r001700_10_1 <= 100));
  __CPROVER_assume((pub_r001700_10_2 >= (-100)) && (pub_r001700_10_2 <= 100));
  __CPROVER_assume((pub_r001700_11_1 >= (-100)) && (pub_r001700_11_1 <= 100));
  __CPROVER_assume((pub_r001700_11_2 >= (-100)) && (pub_r001700_11_2 <= 100));
  __CPROVER_assume((pub_r001700_12_1 >= (-100)) && (pub_r001700_12_1 <= 100));
  __CPROVER_assume((pub_r001700_12_2 >= (-100)) && (pub_r001700_12_2 <= 100));
  __CPROVER_assume((pub_r001700_13_1 >= (-100)) && (pub_r001700_13_1 <= 100));
  __CPROVER_assume((pub_r001700_13_2 >= (-100)) && (pub_r001700_13_2 <= 100));
  __CPROVER_assume((pub_r001700_14_1 >= (-100)) && (pub_r001700_14_1 <= 100));
  __CPROVER_assume((pub_r001700_14_2 >= (-100)) && (pub_r001700_14_2 <= 100));
  __CPROVER_assume((pub_r001700_15_1 >= (-100)) && (pub_r001700_15_1 <= 100));
  __CPROVER_assume((pub_r001700_15_2 >= (-100)) && (pub_r001700_15_2 <= 100));
  __CPROVER_assume((pub_r001700_16_1 >= (-100)) && (pub_r001700_16_1 <= 100));
  __CPROVER_assume((pub_r001700_16_2 >= (-100)) && (pub_r001700_16_2 <= 100));
  __CPROVER_assume((pub_r001700_17_1 >= (-100)) && (pub_r001700_17_1 <= 100));
  __CPROVER_assume((pub_r001700_17_2 >= (-100)) && (pub_r001700_17_2 <= 100));
  __CPROVER_assume((pub_r001700_18_1 >= (-100)) && (pub_r001700_18_1 <= 100));
  __CPROVER_assume((pub_r001700_18_2 >= (-100)) && (pub_r001700_18_2 <= 100));
  __CPROVER_assume((pub_r001700_19_1 >= (-100)) && (pub_r001700_19_1 <= 100));
  __CPROVER_assume((pub_r001700_19_2 >= (-100)) && (pub_r001700_19_2 <= 100));
  __CPROVER_assume((pub_r001700_20_1 >= (-100)) && (pub_r001700_20_1 <= 100));
  __CPROVER_assume((pub_r001700_20_2 >= (-100)) && (pub_r001700_20_2 <= 100));
  __CPROVER_assume((pub_r001700_21_1 >= (-100)) && (pub_r001700_21_1 <= 100));
  __CPROVER_assume((pub_r001700_21_2 >= (-100)) && (pub_r001700_21_2 <= 100));
  __CPROVER_assume((pub_r001700_22_1 >= (-100)) && (pub_r001700_22_1 <= 100));
  __CPROVER_assume((pub_r001700_22_2 >= (-100)) && (pub_r001700_22_2 <= 100));
  __CPROVER_assume((pub_r001700_23_1 >= (-100)) && (pub_r001700_23_1 <= 100));
  __CPROVER_assume((pub_r001700_23_2 >= (-100)) && (pub_r001700_23_2 <= 100));
  __CPROVER_assume((sec_r001700_0_1 >= 0) && (sec_r001700_0_1 <= 255));
  __CPROVER_assume((sec_r001700_0_2 >= 0) && (sec_r001700_0_2 <= 255));
  __CPROVER_assume((sec_r001700_1_1 >= 0) && (sec_r001700_1_1 <= 255));
  __CPROVER_assume((sec_r001700_1_2 >= 0) && (sec_r001700_1_2 <= 255));
  __CPROVER_assume((sec_r001700_2_1 >= 0) && (sec_r001700_2_1 <= 255));
  __CPROVER_assume((sec_r001700_2_2 >= 0) && (sec_r001700_2_2 <= 255));
  __CPROVER_assume((sec_r001700_3_1 >= 0) && (sec_r001700_3_1 <= 255));
  __CPROVER_assume((sec_r001700_3_2 >= 0) && (sec_r001700_3_2 <= 255));
  __CPROVER_assume((sec_r001700_4_1 >= 0) && (sec_r001700_4_1 <= 255));
  __CPROVER_assume((sec_r001700_4_2 >= 0) && (sec_r001700_4_2 <= 255));
  __CPROVER_assume((sec_r001700_5_1 >= 0) && (sec_r001700_5_1 <= 255));
  __CPROVER_assume((sec_r001700_5_2 >= 0) && (sec_r001700_5_2 <= 255));
  __CPROVER_assume((sec_r001700_6_1 >= 0) && (sec_r001700_6_1 <= 255));
  __CPROVER_assume((sec_r001700_6_2 >= 0) && (sec_r001700_6_2 <= 255));
  __CPROVER_assume((sec_r001700_7_1 >= 0) && (sec_r001700_7_1 <= 255));
  __CPROVER_assume((sec_r001700_7_2 >= 0) && (sec_r001700_7_2 <= 255));
  __CPROVER_assume((sec_r001700_8_1 >= 0) && (sec_r001700_8_1 <= 255));
  __CPROVER_assume((sec_r001700_8_2 >= 0) && (sec_r001700_8_2 <= 255));
  __CPROVER_assume((sec_r001700_9_1 >= 0) && (sec_r001700_9_1 <= 255));
  __CPROVER_assume((sec_r001700_9_2 >= 0) && (sec_r001700_9_2 <= 255));
  __CPROVER_assume((sec_r001700_10_1 >= 0) && (sec_r001700_10_1 <= 255));
  __CPROVER_assume((sec_r001700_10_2 >= 0) && (sec_r001700_10_2 <= 255));
  __CPROVER_assume((sec_r001700_11_1 >= 0) && (sec_r001700_11_1 <= 255));
  __CPROVER_assume((sec_r001700_11_2 >= 0) && (sec_r001700_11_2 <= 255));
  __CPROVER_assume((sec_r001700_12_1 >= 0) && (sec_r001700_12_1 <= 255));
  __CPROVER_assume((sec_r001700_12_2 >= 0) && (sec_r001700_12_2 <= 255));
  __CPROVER_assume((sec_r001700_13_1 >= 0) && (sec_r001700_13_1 <= 255));
  __CPROVER_assume((sec_r001700_13_2 >= 0) && (sec_r001700_13_2 <= 255));
  __CPROVER_assume((sec_r001700_14_1 >= 0) && (sec_r001700_14_1 <= 255));
  __CPROVER_assume((sec_r001700_14_2 >= 0) && (sec_r001700_14_2 <= 255));
  __CPROVER_assume((sec_r001700_15_1 >= 0) && (sec_r001700_15_1 <= 255));
  __CPROVER_assume((sec_r001700_15_2 >= 0) && (sec_r001700_15_2 <= 255));
  __CPROVER_assume((sec_r001700_16_1 >= 0) && (sec_r001700_16_1 <= 255));
  __CPROVER_assume((sec_r001700_16_2 >= 0) && (sec_r001700_16_2 <= 255));
  __CPROVER_assume((sec_r001700_17_1 >= 0) && (sec_r001700_17_1 <= 255));
  __CPROVER_assume((sec_r001700_17_2 >= 0) && (sec_r001700_17_2 <= 255));
  struct DeviceConfig_R001700_13_0 st_var_0_1 = {0};
  struct DeviceConfig_R001700_13_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001700_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001700_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001700_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001700_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001700_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001700_0_2 + 7) & 15;
  struct Transaction_R001700_13_1 st_var_1_1 = {0};
  struct Transaction_R001700_13_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001700_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001700_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001700_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001700_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001700_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001700_0_2 + 9) & 15;
  struct StreamBuffer_R001700_13_2 st_var_2_1 = {0};
  struct StreamBuffer_R001700_13_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001700_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001700_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001700_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001700_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001700_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001700_0_2 + 11) & 15;
  struct Vector3D_R001700_13_3 st_var_3_1 = {0};
  struct Vector3D_R001700_13_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001700_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001700_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001700_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001700_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001700_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001700_0_2 + 13) & 15;
  union RegisterBank_R001700_13_0 u_var_1;
  union RegisterBank_R001700_13_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001700_13_0(sec_r001700_0_1, pub_r001700_1_1);
  int helper_flow_0_2 = fn_R001700_13_0(sec_r001700_0_2, pub_r001700_1_2);
  fn_R001700_13_0_2(sec_r001700_0_1, pub_r001700_1_1, sec_r001700_0_2, pub_r001700_1_2);
  int helper_flow_1_1 = fn_R001700_13_1(sec_r001700_1_1, pub_r001700_2_1, pub_r001700_3_1, pub_r001700_4_1);
  int helper_flow_1_2 = fn_R001700_13_1(sec_r001700_1_2, pub_r001700_2_2, pub_r001700_3_2, pub_r001700_4_2);
  fn_R001700_13_1_2(sec_r001700_1_1, pub_r001700_2_1, pub_r001700_3_1, pub_r001700_4_1, sec_r001700_1_2, pub_r001700_2_2, pub_r001700_3_2, pub_r001700_4_2);
  int helper_flow_2_1 = fn_R001700_13_2(sec_r001700_2_1, pub_r001700_3_1, pub_r001700_4_1, pub_r001700_5_1, pub_r001700_6_1);
  int helper_flow_2_2 = fn_R001700_13_2(sec_r001700_2_2, pub_r001700_3_2, pub_r001700_4_2, pub_r001700_5_2, pub_r001700_6_2);
  fn_R001700_13_2_2(sec_r001700_2_1, pub_r001700_3_1, pub_r001700_4_1, pub_r001700_5_1, pub_r001700_6_1, sec_r001700_2_2, pub_r001700_3_2, pub_r001700_4_2, pub_r001700_5_2, pub_r001700_6_2);
  int helper_flow_3_1 = fn_R001700_13_3(sec_r001700_3_1, sec_r001700_4_1);
  int helper_flow_3_2 = fn_R001700_13_3(sec_r001700_3_2, sec_r001700_4_2);
  fn_R001700_13_3_2(sec_r001700_3_1, sec_r001700_4_1, sec_r001700_3_2, sec_r001700_4_2);
  int helper_flow_4_1 = fn_R001700_13_4(sec_r001700_4_1, sec_r001700_5_1, pub_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1);
  int helper_flow_4_2 = fn_R001700_13_4(sec_r001700_4_2, sec_r001700_5_2, pub_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2);
  fn_R001700_13_4_2(sec_r001700_4_1, sec_r001700_5_1, pub_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1, sec_r001700_4_2, sec_r001700_5_2, pub_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2);
  int helper_flow_5_1 = fn_R001700_13_5(sec_r001700_5_1, sec_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1);
  int helper_flow_5_2 = fn_R001700_13_5(sec_r001700_5_2, sec_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2);
  fn_R001700_13_5_2(sec_r001700_5_1, sec_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1, sec_r001700_5_2, sec_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2);
  int helper_flow_6_1 = fn_R001700_13_6(sec_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1, pub_r001700_9_1, pub_r001700_10_1);
  int helper_flow_6_2 = fn_R001700_13_6(sec_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2, pub_r001700_9_2, pub_r001700_10_2);
  fn_R001700_13_6_2(sec_r001700_6_1, pub_r001700_7_1, pub_r001700_8_1, pub_r001700_9_1, pub_r001700_10_1, sec_r001700_6_2, pub_r001700_7_2, pub_r001700_8_2, pub_r001700_9_2, pub_r001700_10_2);
  int helper_flow_7_1 = fn_R001700_13_7(sec_r001700_7_1, sec_r001700_8_1);
  int helper_flow_7_2 = fn_R001700_13_7(sec_r001700_7_2, sec_r001700_8_2);
  fn_R001700_13_7_2(sec_r001700_7_1, sec_r001700_8_1, sec_r001700_7_2, sec_r001700_8_2);
  int helper_flow_8_1 = fn_R001700_13_8(sec_r001700_8_1, sec_r001700_9_1, pub_r001700_10_1);
  int helper_flow_8_2 = fn_R001700_13_8(sec_r001700_8_2, sec_r001700_9_2, pub_r001700_10_2);
  fn_R001700_13_8_2(sec_r001700_8_1, sec_r001700_9_1, pub_r001700_10_1, sec_r001700_8_2, sec_r001700_9_2, pub_r001700_10_2);
  int helper_flow_9_1 = fn_R001700_13_9(sec_r001700_9_1, pub_r001700_10_1, pub_r001700_11_1, pub_r001700_12_1);
  int helper_flow_9_2 = fn_R001700_13_9(sec_r001700_9_2, pub_r001700_10_2, pub_r001700_11_2, pub_r001700_12_2);
  fn_R001700_13_9_2(sec_r001700_9_1, pub_r001700_10_1, pub_r001700_11_1, pub_r001700_12_1, sec_r001700_9_2, pub_r001700_10_2, pub_r001700_11_2, pub_r001700_12_2);
  int helper_flow_10_1 = fn_R001700_13_10(sec_r001700_10_1, sec_r001700_11_1);
  int helper_flow_10_2 = fn_R001700_13_10(sec_r001700_10_2, sec_r001700_11_2);
  fn_R001700_13_10_2(sec_r001700_10_1, sec_r001700_11_1, sec_r001700_10_2, sec_r001700_11_2);
  int stage_v_0_1 = (((sec_r001700_10_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_0_2 = (((sec_r001700_10_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_0_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001700_14_1 * 2) + 37) & 63;
  int stage_v_1_2 = ((pub_r001700_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_2_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_2_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_3_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_3_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001700_10_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_4_2 = (((sec_r001700_10_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_4_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001700_12_1) & 127;
  int stage_v_5_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001700_12_2) & 127;
  if (stage_v_5_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_6_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_6_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001700_15_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_7_2 = (((sec_r001700_15_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_7_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001700_11_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_8_2 = (((sec_r001700_11_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_8_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001700_13_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_9_2 = (((sec_r001700_13_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_9_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_10_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_10_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((pub_r001700_23_1 * 2) + 9) & 63;
  int stage_v_11_2 = ((pub_r001700_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001700_15_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_12_2 = (((sec_r001700_15_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_12_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((sec_r001700_4_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_13_2 = (((sec_r001700_4_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_13_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001700_3_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_14_2 = (((sec_r001700_3_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_14_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_15_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_15_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_16_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_16_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001700_8_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_17_2 = (((sec_r001700_8_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_17_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_18_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_18_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_19_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_19_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001700_12_1 ^ 0x2A) * 2) + pub_r001700_17_1) & 127;
  int stage_v_20_2 = (((sec_r001700_12_2 ^ 0x2A) * 2) + pub_r001700_17_2) & 127;
  if (stage_v_20_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_21_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_21_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001700_21_1 * 2) + 47) & 63;
  int stage_v_22_2 = ((pub_r001700_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001700_2_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_23_2 = (((sec_r001700_2_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_23_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_24_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_24_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001700_20_1 * 2) + 21) & 63;
  int stage_v_25_2 = ((pub_r001700_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001700_15_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_26_2 = (((sec_r001700_15_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_26_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_27_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_27_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((sec_r001700_1_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_28_2 = (((sec_r001700_1_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_28_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001700_0_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_29_2 = (((sec_r001700_0_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_29_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_30_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_30_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_31_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_31_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001700_0_1 ^ 0x2A) * 2) + pub_r001700_23_1) & 127;
  int stage_v_32_2 = (((sec_r001700_0_2 ^ 0x2A) * 2) + pub_r001700_23_2) & 127;
  if (stage_v_32_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_33_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_33_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_34_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_34_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_35_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_35_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((sec_r001700_7_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_36_2 = (((sec_r001700_7_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_36_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((sec_r001700_3_1 ^ 0x2A) * 2) + pub_r001700_12_1) & 127;
  int stage_v_37_2 = (((sec_r001700_3_2 ^ 0x2A) * 2) + pub_r001700_12_2) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001700_15_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_38_2 = (((sec_r001700_15_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_38_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_39_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_39_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_40_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_40_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_41_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_41_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_42_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_42_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_43_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_43_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001700_23_1 * 2) + 10) & 63;
  int stage_v_44_2 = ((pub_r001700_23_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_45_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_45_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_46_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_46_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001700_17_1 * 2) + 28) & 63;
  int stage_v_47_2 = ((pub_r001700_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001700_1_1 * 2) + 10) & 63;
  int stage_v_48_2 = ((pub_r001700_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001700_12_1 * 2) + 5) & 63;
  int stage_v_49_2 = ((pub_r001700_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_50_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_50_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001700_16_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_51_2 = (((sec_r001700_16_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_51_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_52_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_52_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_53_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_53_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001700_11_1 * 2) + 13) & 63;
  int stage_v_54_2 = ((pub_r001700_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001700_11_1 * 2) + 25) & 63;
  int stage_v_55_2 = ((pub_r001700_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_56_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_56_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((pub_r001700_22_1 * 2) + 9) & 63;
  int stage_v_57_2 = ((pub_r001700_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_58_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_58_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((sec_r001700_5_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_59_2 = (((sec_r001700_5_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_59_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001700_5_1 * 2) + 7) & 63;
  int stage_v_60_2 = ((pub_r001700_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001700_12_1) & 127;
  int stage_v_61_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001700_12_2) & 127;
  if (stage_v_61_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001700_22_1 * 2) + 34) & 63;
  int stage_v_62_2 = ((pub_r001700_22_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_63_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_63_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_64_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_64_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_65_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_65_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_66_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_66_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_67_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_67_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_68_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_68_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_69_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_69_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001700_5_1) & 127;
  int stage_v_70_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001700_5_2) & 127;
  if (stage_v_70_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_71_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_71_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_72_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_72_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_73_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_73_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_74_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_74_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((pub_r001700_5_1 * 2) + 48) & 63;
  int stage_v_75_2 = ((pub_r001700_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_76_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_76_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001700_4_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_77_2 = (((sec_r001700_4_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_77_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_78_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_78_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001700_5_1) & 127;
  int stage_v_79_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001700_5_2) & 127;
  if (stage_v_79_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_80_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_80_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_81_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_81_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_82_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_82_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_83_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_83_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_84_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_84_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((sec_r001700_17_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_85_2 = (((sec_r001700_17_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_85_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_86_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_87_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_87_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001700_10_1 * 2) + 26) & 63;
  int stage_v_88_2 = ((pub_r001700_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_89_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_89_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((pub_r001700_22_1 * 2) + 26) & 63;
  int stage_v_90_2 = ((pub_r001700_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001700_11_1 * 2) + 41) & 63;
  int stage_v_91_2 = ((pub_r001700_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_92_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_92_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_93_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_93_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001700_2_1 ^ 0x2A) * 2) + pub_r001700_17_1) & 127;
  int stage_v_94_2 = (((sec_r001700_2_2 ^ 0x2A) * 2) + pub_r001700_17_2) & 127;
  if (stage_v_94_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001700_13_1 * 2) + 14) & 63;
  int stage_v_95_2 = ((pub_r001700_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001700_12_1 * 2) + 32) & 63;
  int stage_v_96_2 = ((pub_r001700_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001700_18_1 * 2) + 39) & 63;
  int stage_v_97_2 = ((pub_r001700_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_98_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_98_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_99_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_99_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_100_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_100_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_101_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_101_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001700_23_1 * 2) + 36) & 63;
  int stage_v_102_2 = ((pub_r001700_23_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((sec_r001700_9_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_103_2 = (((sec_r001700_9_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_103_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_104_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_104_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_105_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_105_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((sec_r001700_10_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_106_2 = (((sec_r001700_10_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_106_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001700_0_1 * 2) + 19) & 63;
  int stage_v_107_2 = ((pub_r001700_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001700_10_1 * 2) + 41) & 63;
  int stage_v_108_2 = ((pub_r001700_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_109_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_109_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_110_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_110_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_111_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_111_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001700_19_1 * 2) + 33) & 63;
  int stage_v_112_2 = ((pub_r001700_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_113_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_113_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_114_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_114_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_115_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_115_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((sec_r001700_5_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_116_2 = (((sec_r001700_5_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_116_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001700_1_1 * 2) + 6) & 63;
  int stage_v_117_2 = ((pub_r001700_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_118_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_118_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((sec_r001700_10_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_119_2 = (((sec_r001700_10_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_119_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((sec_r001700_9_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_120_2 = (((sec_r001700_9_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_120_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_121_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_121_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001700_20_1 * 2) + 36) & 63;
  int stage_v_122_2 = ((pub_r001700_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001700_19_1 * 2) + 43) & 63;
  int stage_v_123_2 = ((pub_r001700_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_124_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_124_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001700_0_1 * 2) + 28) & 63;
  int stage_v_125_2 = ((pub_r001700_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_126_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_126_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_127_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_127_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_128_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_128_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001700_19_1 * 2) + 25) & 63;
  int stage_v_129_2 = ((pub_r001700_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_130_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_130_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_131_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_131_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001700_19_1 * 2) + 48) & 63;
  int stage_v_132_2 = ((pub_r001700_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001700_19_1 * 2) + 24) & 63;
  int stage_v_133_2 = ((pub_r001700_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001700_21_1 * 2) + 14) & 63;
  int stage_v_134_2 = ((pub_r001700_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_135_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_135_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_136_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_136_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_137_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_137_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((sec_r001700_12_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_138_2 = (((sec_r001700_12_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_138_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_139_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_139_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_140_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_140_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((sec_r001700_1_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_141_2 = (((sec_r001700_1_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_141_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_142_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_142_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_143_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_143_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_137_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_144_2 = (((stage_v_137_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_144_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001700_13_1 * 2) + 28) & 63;
  int stage_v_145_2 = ((pub_r001700_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001700_10_1 * 2) + 25) & 63;
  int stage_v_146_2 = ((pub_r001700_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001700_4_1 * 2) + 10) & 63;
  int stage_v_147_2 = ((pub_r001700_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001700_11_1 * 2) + 36) & 63;
  int stage_v_148_2 = ((pub_r001700_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001700_6_1 * 2) + 21) & 63;
  int stage_v_149_2 = ((pub_r001700_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((sec_r001700_7_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_150_2 = (((sec_r001700_7_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_150_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_151_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_151_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001700_5_1) & 127;
  int stage_v_152_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001700_5_2) & 127;
  if (stage_v_152_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_153_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_153_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_154_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_154_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((pub_r001700_20_1 * 2) + 43) & 63;
  int stage_v_155_2 = ((pub_r001700_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_156_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_156_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((pub_r001700_18_1 * 2) + 14) & 63;
  int stage_v_157_2 = ((pub_r001700_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_158_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_158_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_159_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_159_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001700_23_1) & 127;
  int stage_v_160_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001700_23_2) & 127;
  if (stage_v_160_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001700_4_1) & 127;
  int stage_v_161_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001700_4_2) & 127;
  if (stage_v_161_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001700_23_1) & 127;
  int stage_v_162_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001700_23_2) & 127;
  if (stage_v_162_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001700_7_1 * 2) + 14) & 63;
  int stage_v_163_2 = ((pub_r001700_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001700_21_1 * 2) + 15) & 63;
  int stage_v_164_2 = ((pub_r001700_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_165_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_165_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((pub_r001700_19_1 * 2) + 35) & 63;
  int stage_v_166_2 = ((pub_r001700_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001700_9_1 * 2) + 8) & 63;
  int stage_v_167_2 = ((pub_r001700_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001700_2_1 * 2) + 36) & 63;
  int stage_v_168_2 = ((pub_r001700_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001700_23_1) & 127;
  int stage_v_169_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001700_23_2) & 127;
  if (stage_v_169_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_170_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_170_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_171_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_171_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_172_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_172_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001700_23_1) & 127;
  int stage_v_173_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001700_23_2) & 127;
  if (stage_v_173_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_174_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_174_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001700_19_1 * 2) + 8) & 63;
  int stage_v_175_2 = ((pub_r001700_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_176_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_176_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((sec_r001700_2_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_177_2 = (((sec_r001700_2_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_177_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_178_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_178_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001700_16_1 * 2) + 49) & 63;
  int stage_v_179_2 = ((pub_r001700_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001700_12_1) & 127;
  int stage_v_180_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001700_12_2) & 127;
  if (stage_v_180_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((pub_r001700_16_1 * 2) + 29) & 63;
  int stage_v_181_2 = ((pub_r001700_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_182_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_182_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_183_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_183_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001700_16_1 * 2) + 48) & 63;
  int stage_v_184_2 = ((pub_r001700_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_185_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_185_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((pub_r001700_8_1 * 2) + 42) & 63;
  int stage_v_186_2 = ((pub_r001700_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_187_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_187_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001700_22_1 * 2) + 22) & 63;
  int stage_v_188_2 = ((pub_r001700_22_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((sec_r001700_16_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_189_2 = (((sec_r001700_16_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_189_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_190_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_190_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001700_12_1) & 127;
  int stage_v_191_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001700_12_2) & 127;
  if (stage_v_191_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001700_16_1) & 127;
  int stage_v_192_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001700_16_2) & 127;
  if (stage_v_192_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_193_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_193_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001700_18_1) & 127;
  int stage_v_194_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001700_18_2) & 127;
  if (stage_v_194_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001700_14_1 * 2) + 16) & 63;
  int stage_v_195_2 = ((pub_r001700_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001700_15_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_196_2 = (((sec_r001700_15_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_196_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001700_17_1) & 127;
  int stage_v_197_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001700_17_2) & 127;
  if (stage_v_197_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001700_4_1 * 2) + 23) & 63;
  int stage_v_198_2 = ((pub_r001700_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_199_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_199_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_200_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_200_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_201_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_201_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_202_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_202_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_203_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_203_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((pub_r001700_22_1 * 2) + 13) & 63;
  int stage_v_204_2 = ((pub_r001700_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_205_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_205_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((pub_r001700_15_1 * 2) + 21) & 63;
  int stage_v_206_2 = ((pub_r001700_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_207_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_207_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001700_17_1) & 127;
  int stage_v_208_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001700_17_2) & 127;
  if (stage_v_208_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001700_6_1) & 127;
  int stage_v_209_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001700_6_2) & 127;
  if (stage_v_209_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001700_21_1 * 2) + 38) & 63;
  int stage_v_210_2 = ((pub_r001700_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001700_17_1) & 127;
  int stage_v_211_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001700_17_2) & 127;
  if (stage_v_211_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001700_5_1) & 127;
  int stage_v_212_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001700_5_2) & 127;
  if (stage_v_212_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((sec_r001700_1_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_213_2 = (((sec_r001700_1_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_213_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_214_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_214_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001700_10_1 * 2) + 15) & 63;
  int stage_v_215_2 = ((pub_r001700_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001700_13_1) & 127;
  int stage_v_216_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001700_13_2) & 127;
  if (stage_v_216_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_217_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_217_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((pub_r001700_16_1 * 2) + 50) & 63;
  int stage_v_218_2 = ((pub_r001700_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001700_0_1) & 127;
  int stage_v_219_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001700_0_2) & 127;
  if (stage_v_219_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001700_7_1 * 2) + 44) & 63;
  int stage_v_220_2 = ((pub_r001700_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001700_14_1 * 2) + 27) & 63;
  int stage_v_221_2 = ((pub_r001700_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_222_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_222_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((pub_r001700_9_1 * 2) + 11) & 63;
  int stage_v_223_2 = ((pub_r001700_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001700_19_1 * 2) + 25) & 63;
  int stage_v_224_2 = ((pub_r001700_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001700_20_1) & 127;
  int stage_v_225_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001700_20_2) & 127;
  if (stage_v_225_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001700_14_1) & 127;
  int stage_v_226_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001700_14_2) & 127;
  if (stage_v_226_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_227_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_227_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_228_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_228_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_229_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_229_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001700_7_1) & 127;
  int stage_v_230_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001700_7_2) & 127;
  if (stage_v_230_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((sec_r001700_11_1 ^ 0x2A) * 2) + pub_r001700_21_1) & 127;
  int stage_v_231_2 = (((sec_r001700_11_2 ^ 0x2A) * 2) + pub_r001700_21_2) & 127;
  if (stage_v_231_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_222_1 ^ 0x2A) * 2) + pub_r001700_3_1) & 127;
  int stage_v_232_2 = (((stage_v_222_2 ^ 0x2A) * 2) + pub_r001700_3_2) & 127;
  if (stage_v_232_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001700_22_1) & 127;
  int stage_v_233_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001700_22_2) & 127;
  if (stage_v_233_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001700_10_1) & 127;
  int stage_v_234_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001700_10_2) & 127;
  if (stage_v_234_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001700_1_1) & 127;
  int stage_v_235_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001700_1_2) & 127;
  if (stage_v_235_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001700_2_1) & 127;
  int stage_v_236_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001700_2_2) & 127;
  if (stage_v_236_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_216_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_237_2 = (((stage_v_216_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_237_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((pub_r001700_16_1 * 2) + 36) & 63;
  int stage_v_238_2 = ((pub_r001700_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((sec_r001700_2_1 ^ 0x2A) * 2) + pub_r001700_8_1) & 127;
  int stage_v_239_2 = (((sec_r001700_2_2 ^ 0x2A) * 2) + pub_r001700_8_2) & 127;
  if (stage_v_239_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((pub_r001700_7_1 * 2) + 14) & 63;
  int stage_v_240_2 = ((pub_r001700_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001700_19_1) & 127;
  int stage_v_241_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001700_19_2) & 127;
  if (stage_v_241_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((pub_r001700_5_1 * 2) + 9) & 63;
  int stage_v_242_2 = ((pub_r001700_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001700_7_1 * 2) + 23) & 63;
  int stage_v_243_2 = ((pub_r001700_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((sec_r001700_4_1 ^ 0x2A) * 2) + pub_r001700_11_1) & 127;
  int stage_v_244_2 = (((sec_r001700_4_2 ^ 0x2A) * 2) + pub_r001700_11_2) & 127;
  if (stage_v_244_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001700_15_1) & 127;
  int stage_v_245_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001700_15_2) & 127;
  if (stage_v_245_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
  }
  if (stage_v_245_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001700_9_1) & 127;
  int stage_v_246_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001700_9_2) & 127;
  if (stage_v_246_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001700_14_1 == pub_r001700_14_2);
  __CPROVER_assume(pub_r001700_18_1 == pub_r001700_18_2);
  __CPROVER_assume(pub_r001700_5_1 == pub_r001700_5_2);
  __CPROVER_assume(pub_r001700_1_1 == pub_r001700_1_2);
  __CPROVER_assume(pub_r001700_16_1 == pub_r001700_16_2);
  __CPROVER_assume(sec_r001700_11_1 != sec_r001700_11_2);
  __CPROVER_assume(pub_r001700_20_1 == pub_r001700_20_2);
  __CPROVER_assume(pub_r001700_11_1 == pub_r001700_11_2);
  __CPROVER_assume(pub_r001700_22_1 == pub_r001700_22_2);
  __CPROVER_assume(sec_r001700_17_1 != sec_r001700_17_2);
  __CPROVER_assume(sec_r001700_8_1 != sec_r001700_8_2);
  __CPROVER_assume(sec_r001700_13_1 != sec_r001700_13_2);
  __CPROVER_assume(pub_r001700_10_1 == pub_r001700_10_2);
  __CPROVER_assume(sec_r001700_1_1 != sec_r001700_1_2);
  __CPROVER_assume(sec_r001700_15_1 != sec_r001700_15_2);
  __CPROVER_assume(sec_r001700_16_1 != sec_r001700_16_2);
  __CPROVER_assume(pub_r001700_8_1 == pub_r001700_8_2);
  __CPROVER_assume(sec_r001700_7_1 != sec_r001700_7_2);
  __CPROVER_assume(pub_r001700_12_1 == pub_r001700_12_2);
  __CPROVER_assume(pub_r001700_6_1 == pub_r001700_6_2);
  __CPROVER_assume(sec_r001700_0_1 != sec_r001700_0_2);
  __CPROVER_assume(pub_r001700_15_1 == pub_r001700_15_2);
  __CPROVER_assume(sec_r001700_10_1 != sec_r001700_10_2);
  __CPROVER_assume(sec_r001700_9_1 != sec_r001700_9_2);
  __CPROVER_assume(pub_r001700_0_1 == pub_r001700_0_2);
  __CPROVER_assume(pub_r001700_13_1 == pub_r001700_13_2);
  __CPROVER_assume(pub_r001700_7_1 == pub_r001700_7_2);
  __CPROVER_assume(sec_r001700_5_1 != sec_r001700_5_2);
  __CPROVER_assume(pub_r001700_21_1 == pub_r001700_21_2);
  __CPROVER_assume(pub_r001700_17_1 == pub_r001700_17_2);
  __CPROVER_assume(pub_r001700_3_1 == pub_r001700_3_2);
  __CPROVER_assume(sec_r001700_12_1 != sec_r001700_12_2);
  __CPROVER_assume(sec_r001700_14_1 != sec_r001700_14_2);
  __CPROVER_assume(sec_r001700_2_1 != sec_r001700_2_2);
  __CPROVER_assume(pub_r001700_9_1 == pub_r001700_9_2);
  __CPROVER_assume(sec_r001700_3_1 != sec_r001700_3_2);
  __CPROVER_assume(pub_r001700_4_1 == pub_r001700_4_2);
  __CPROVER_assume(pub_r001700_19_1 == pub_r001700_19_2);
  __CPROVER_assume(sec_r001700_4_1 != sec_r001700_4_2);
  __CPROVER_assume(pub_r001700_2_1 == pub_r001700_2_2);
  __CPROVER_assume(sec_r001700_6_1 != sec_r001700_6_2);
  __CPROVER_assume(pub_r001700_23_1 == pub_r001700_23_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.pitch == st_var_3_2.pitch);
  assert(st_var_3_1.heading == st_var_3_2.heading);
  assert(st_var_3_1.coord_x == st_var_3_2.coord_x);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
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
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


