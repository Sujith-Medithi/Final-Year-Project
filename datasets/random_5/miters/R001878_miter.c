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
struct StreamBuffer_R001878_7813_0
{
  short watermark;
  short capacity;
  int checksum;
  short state;
  short head;
  short tail;
  int buffer[3];
};
struct Vector3D_R001878_7813_1
{
  short norm_sq;
  unsigned char pitch;
  short coord_z;
  int buffer[3];
};
struct DeviceConfig_R001878_7813_2
{
  unsigned char parity;
  short baud_rate;
  int id;
  int buffer[3];
};
union TelemetryField_R001878_7813_0
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
void fn_R001878_7813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_55_1)
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

  switch (residue_55_2)
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

  int segment_99_1 = 0;
  int segment_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_99_1 = ((segment_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_99_2 = ((segment_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_99_1) & 127;
    acc_2 = (acc_2 + segment_99_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_10_1 = local_arr_1[aux_1 % 3];
  int window_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_55_1 == residue_55_2);
  assert(segment_99_1 == segment_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_10_1 == window_10_2);
}

int fn_R001878_7813_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_55 = (aux + st.buffer[1]) & 3;
  switch (residue_55)
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

  int segment_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_99 = ((segment_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_99) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_10 = local_arr[aux % 3];
  acc = (acc + (window_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_59_1 = 0;
  int tracker_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_59_1 = ((tracker_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_59_2 = ((tracker_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_59_1) & 127;
    acc_2 = (acc_2 + tracker_59_2) & 127;
  }

  int metric_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_17_1)
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

  switch (metric_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_59_1 == tracker_59_2);
  assert(metric_17_1 == metric_17_2);
}

int fn_R001878_7813_1(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_59 = ((tracker_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_59) & 127;
  }

  int metric_17 = (aux + st.buffer[1]) & 3;
  switch (metric_17)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st_1 = {0};
  struct StreamBuffer_R001878_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_99_1 > 46)
  {
    acc_1 = ((acc_1 + (scale_99_1 * 2)) + 5) & 127;
    aux_1 ^= scale_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_99_2 > 46)
  {
    acc_2 = ((acc_2 + (scale_99_2 * 2)) + 5) & 127;
    aux_2 ^= scale_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_29_1)
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

  switch (cursor_29_2)
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
  int anchor_75_1 = local_arr_1[aux_1 % 3];
  int anchor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_99_1 == scale_99_2);
  assert(cursor_29_1 == cursor_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_75_1 == anchor_75_2);
}

int fn_R001878_7813_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_99 > 46)
  {
    acc = ((acc + (scale_99 * 2)) + 5) & 127;
    aux ^= scale_99 & 15;
  }
  else
  {
    acc = ((acc - scale_99) + 11) & 127;
    aux += 3;
  }
  int cursor_29 = (aux + st.buffer[1]) & 3;
  switch (cursor_29)
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
  int anchor_75 = local_arr[aux % 3];
  acc = (acc + (anchor_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_39_1 = local_arr_1[aux_1 % 3];
  int phase_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_39_2 * 2)) & 127;
  int scale_73_1 = 0;
  int scale_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_73_1 = ((scale_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_73_2 = ((scale_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_73_1) & 127;
    acc_2 = (acc_2 + scale_73_2) & 127;
  }

  int delta_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_19_1) & 63;
  aux_2 = (aux_2 + delta_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_82_1 > 22)
  {
    acc_1 = ((acc_1 + (checksum_82_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_82_2 > 22)
  {
    acc_2 = ((acc_2 + (checksum_82_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_39_1 == phase_39_2);
  assert(scale_73_1 == scale_73_2);
  assert(delta_19_1 == delta_19_2);
  assert(checksum_82_1 == checksum_82_2);
}

int fn_R001878_7813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int phase_39 = local_arr[aux % 3];
  acc = (acc + (phase_39 * 2)) & 127;
  int scale_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_73 = ((scale_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_73) & 127;
  }

  int delta_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_19) & 63;
  acc ^= aux;
  int checksum_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_82 > 22)
  {
    acc = ((acc + (checksum_82 * 2)) + 5) & 127;
    aux ^= checksum_82 & 15;
  }
  else
  {
    acc = ((acc - checksum_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001878_7813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_76_1)
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

  switch (phase_76_2)
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

  int weight_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_68_1 > 34)
  {
    acc_1 = ((acc_1 + (weight_68_1 * 2)) + 5) & 127;
    aux_1 ^= weight_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_68_2 > 34)
  {
    acc_2 = ((acc_2 + (weight_68_2 * 2)) + 5) & 127;
    aux_2 ^= weight_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_76_1 == phase_76_2);
  assert(weight_68_1 == weight_68_2);
}

int fn_R001878_7813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_76 = (aux + st.buffer[1]) & 3;
  switch (phase_76)
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

  int weight_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_68 > 34)
  {
    acc = ((acc + (weight_68 * 2)) + 5) & 127;
    aux ^= weight_68 & 15;
  }
  else
  {
    acc = ((acc - weight_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001878_7813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_55_1 = 0;
  int quotient_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_55_1 = ((quotient_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_55_2 = ((quotient_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_55_1) & 127;
    acc_2 = (acc_2 + quotient_55_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_39_1) & 63;
  aux_2 = (aux_2 + anchor_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_80_1)
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

  switch (mask_80_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_55_1 == quotient_55_2);
  assert(anchor_39_1 == anchor_39_2);
  assert(mask_80_1 == mask_80_2);
}

int fn_R001878_7813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_55 = ((quotient_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_55) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_39) & 63;
  acc ^= aux;
  int mask_80 = (aux + st.buffer[1]) & 3;
  switch (mask_80)
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

void fn_R001878_7813_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_14_1 > 33)
  {
    acc_1 = ((acc_1 + (scale_14_1 * 2)) + 5) & 127;
    aux_1 ^= scale_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_14_2 > 33)
  {
    acc_2 = ((acc_2 + (scale_14_2 * 2)) + 5) & 127;
    aux_2 ^= scale_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_61_1 = local_arr_1[aux_1 % 3];
  int margin_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_14_1 == scale_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_61_1 == margin_61_2);
}

int fn_R001878_7813_6(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_14 > 33)
  {
    acc = ((acc + (scale_14 * 2)) + 5) & 127;
    aux ^= scale_14 & 15;
  }
  else
  {
    acc = ((acc - scale_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_61 = local_arr[aux % 3];
  acc = (acc + (margin_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_73_1 = 0;
  int scale_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_73_1 = ((scale_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_73_2 = ((scale_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_73_1) & 127;
    acc_2 = (acc_2 + scale_73_2) & 127;
  }

  int weight_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_25_1)
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

  switch (weight_25_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_73_1 == scale_73_2);
  assert(weight_25_1 == weight_25_2);
}

int fn_R001878_7813_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_73 = ((scale_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_73) & 127;
  }

  int weight_25 = (aux + st.buffer[1]) & 3;
  switch (weight_25)
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

void fn_R001878_7813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_48_1 > 36)
  {
    acc_1 = ((acc_1 + (margin_48_1 * 2)) + 5) & 127;
    aux_1 ^= margin_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_48_2 > 36)
  {
    acc_2 = ((acc_2 + (margin_48_2 * 2)) + 5) & 127;
    aux_2 ^= margin_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_37_1 = 0;
  int checksum_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_37_1 = ((checksum_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_37_2 = ((checksum_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_37_1) & 127;
    acc_2 = (acc_2 + checksum_37_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_48_1 == margin_48_2);
  assert(checksum_37_1 == checksum_37_2);
}

int fn_R001878_7813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_48 > 36)
  {
    acc = ((acc + (margin_48 * 2)) + 5) & 127;
    aux ^= margin_48 & 15;
  }
  else
  {
    acc = ((acc - margin_48) + 11) & 127;
    aux += 3;
  }
  int checksum_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_37 = ((checksum_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_37) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001878_7813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_26_1 = local_arr_1[aux_1 % 3];
  int bound_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_26_2 * 2)) & 127;
  int parity_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_94_1)
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

  switch (parity_94_2)
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

  int quantum_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_19_1) & 63;
  aux_2 = (aux_2 + quantum_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(bound_26_1 == bound_26_2);
  assert(parity_94_1 == parity_94_2);
  assert(quantum_19_1 == quantum_19_2);
}

int fn_R001878_7813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int bound_26 = local_arr[aux % 3];
  acc = (acc + (bound_26 * 2)) & 127;
  int parity_94 = (aux + st.buffer[1]) & 3;
  switch (parity_94)
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

  int quantum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_76_1 = 0;
  int segment_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_76_1 = ((segment_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_76_2 = ((segment_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_76_1) & 127;
    acc_2 = (acc_2 + segment_76_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_65_1 = local_arr_1[aux_1 % 3];
  int damping_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_65_2 * 2)) & 127;
  int metric_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_46_1)
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

  switch (metric_46_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_76_1 == segment_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_65_1 == damping_65_2);
  assert(metric_46_1 == metric_46_2);
}

int fn_R001878_7813_10(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_76 = ((segment_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_76) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_65 = local_arr[aux % 3];
  acc = (acc + (damping_65 * 2)) & 127;
  int metric_46 = (aux + st.buffer[1]) & 3;
  switch (metric_46)
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

void fn_R001878_7813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st_1 = {0};
  struct StreamBuffer_R001878_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_21_1 = local_arr_1[aux_1 % 3];
  int factor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_21_2 * 2)) & 127;
  int margin_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_27_1 > 29)
  {
    acc_1 = ((acc_1 + (margin_27_1 * 2)) + 5) & 127;
    aux_1 ^= margin_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_27_2 > 29)
  {
    acc_2 = ((acc_2 + (margin_27_2 * 2)) + 5) & 127;
    aux_2 ^= margin_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_27_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_40_1 = 0;
  int mask_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_40_1 = ((mask_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_40_2 = ((mask_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_40_1) & 127;
    acc_2 = (acc_2 + mask_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(margin_27_1 == margin_27_2);
  assert(mask_40_1 == mask_40_2);
}

int fn_R001878_7813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int factor_21 = local_arr[aux % 3];
  acc = (acc + (factor_21 * 2)) & 127;
  int margin_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_27 > 29)
  {
    acc = ((acc + (margin_27 * 2)) + 5) & 127;
    aux ^= margin_27 & 15;
  }
  else
  {
    acc = ((acc - margin_27) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_40 = ((mask_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001878_7813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st_1 = {0};
  struct StreamBuffer_R001878_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_46_1)
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

  switch (quotient_46_2)
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
  int bound_95_1 = local_arr_1[aux_1 % 3];
  int bound_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_95_2 * 2)) & 127;
  int parity_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_62_1) & 63;
  aux_2 = (aux_2 + parity_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_46_1 == quotient_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_95_1 == bound_95_2);
  assert(parity_62_1 == parity_62_2);
}

int fn_R001878_7813_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_46 = (aux + st.buffer[1]) & 3;
  switch (quotient_46)
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
  int bound_95 = local_arr[aux % 3];
  acc = (acc + (bound_95 * 2)) & 127;
  int parity_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001878_7813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_87_1 = 0;
  int index_reg_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_87_1 = ((index_reg_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_87_2 = ((index_reg_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_87_1) & 127;
    acc_2 = (acc_2 + index_reg_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_87_1 == index_reg_87_2);
}

int fn_R001878_7813_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_87 = ((index_reg_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001878_7813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_32_1)
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

  switch (window_32_2)
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

  int factor_51_1 = 0;
  int factor_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_51_1 = ((factor_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_51_2 = ((factor_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_51_1) & 127;
    acc_2 = (acc_2 + factor_51_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_89_1) & 63;
  aux_2 = (aux_2 + delta_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_32_1 == window_32_2);
  assert(factor_51_1 == factor_51_2);
  assert(delta_89_1 == delta_89_2);
}

int fn_R001878_7813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_32 = (aux + st.buffer[1]) & 3;
  switch (window_32)
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

  int factor_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_51 = ((factor_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_51) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001878_7813_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st_1 = {0};
  struct Vector3D_R001878_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_14_1)
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

  switch (metric_14_2)
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

  int damping_80_1 = 0;
  int damping_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_80_1 = ((damping_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_80_2 = ((damping_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_80_1) & 127;
    acc_2 = (acc_2 + damping_80_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_39_1) & 63;
  aux_2 = (aux_2 + delta_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  assert(damping_80_1 == damping_80_2);
  assert(delta_39_1 == delta_39_2);
}

int fn_R001878_7813_15(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001878_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_14 = (aux + st.buffer[1]) & 3;
  switch (metric_14)
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

  int damping_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_80 = ((damping_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_80) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001878_7813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_24_1 = local_arr_1[aux_1 % 3];
  int phase_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_24_2 * 2)) & 127;
  int sample_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_80_1) & 63;
  aux_2 = (aux_2 + sample_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(phase_24_1 == phase_24_2);
  assert(sample_80_1 == sample_80_2);
}

int fn_R001878_7813_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int phase_24 = local_arr[aux % 3];
  acc = (acc + (phase_24 * 2)) & 127;
  int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st_1 = {0};
  struct StreamBuffer_R001878_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int cursor_50_1 = 0;
  int cursor_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_50_1 = ((cursor_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_50_2 = ((cursor_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_50_1) & 127;
    acc_2 = (acc_2 + cursor_50_2) & 127;
  }

  int phase_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_62_1)
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

  switch (phase_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_78_1 > 37)
  {
    acc_1 = ((acc_1 + (weight_78_1 * 2)) + 5) & 127;
    aux_1 ^= weight_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_78_2 > 37)
  {
    acc_2 = ((acc_2 + (weight_78_2 * 2)) + 5) & 127;
    aux_2 ^= weight_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(phase_62_1 == phase_62_2);
  assert(weight_78_1 == weight_78_2);
}

int fn_R001878_7813_17(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001878_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int cursor_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_50 = ((cursor_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_50) & 127;
  }

  int phase_62 = (aux + st.buffer[1]) & 3;
  switch (phase_62)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_78 > 37)
  {
    acc = ((acc + (weight_78 * 2)) + 5) & 127;
    aux ^= weight_78 & 15;
  }
  else
  {
    acc = ((acc - weight_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001878_7813_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_25_1)
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

  switch (parity_25_2)
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

  int phase_68_1 = 0;
  int phase_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_68_1 = ((phase_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_68_2 = ((phase_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_68_1) & 127;
    acc_2 = (acc_2 + phase_68_2) & 127;
  }

  int parity_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_15_1 > 48)
  {
    acc_1 = ((acc_1 + (parity_15_1 * 2)) + 5) & 127;
    aux_1 ^= parity_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_15_2 > 48)
  {
    acc_2 = ((acc_2 + (parity_15_2 * 2)) + 5) & 127;
    aux_2 ^= parity_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_15_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_25_1 == parity_25_2);
  assert(phase_68_1 == phase_68_2);
  assert(parity_15_1 == parity_15_2);
}

int fn_R001878_7813_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_25 = (aux + st.buffer[1]) & 3;
  switch (parity_25)
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

  int phase_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_68 = ((phase_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_68) & 127;
  }

  int parity_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_15 > 48)
  {
    acc = ((acc + (parity_15 * 2)) + 5) & 127;
    aux ^= parity_15 & 15;
  }
  else
  {
    acc = ((acc - parity_15) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001878_7813_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
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
  int coefficient_17_1 = 0;
  int coefficient_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_17_1 = ((coefficient_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_17_2 = ((coefficient_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_17_1) & 127;
    acc_2 = (acc_2 + coefficient_17_2) & 127;
  }

  int scale_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_88_1)
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

  switch (scale_88_2)
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

  int phase_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_68_1 > 50)
  {
    acc_1 = ((acc_1 + (phase_68_1 * 2)) + 5) & 127;
    aux_1 ^= phase_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_68_2 > 50)
  {
    acc_2 = ((acc_2 + (phase_68_2 * 2)) + 5) & 127;
    aux_2 ^= phase_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  assert(scale_88_1 == scale_88_2);
  assert(phase_68_1 == phase_68_2);
}

int fn_R001878_7813_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_17 = ((coefficient_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_17) & 127;
  }

  int scale_88 = (aux + st.buffer[1]) & 3;
  switch (scale_88)
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

  int phase_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_68 > 50)
  {
    acc = ((acc + (phase_68 * 2)) + 5) & 127;
    aux ^= phase_68 & 15;
  }
  else
  {
    acc = ((acc - phase_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001878_7813_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_73_1)
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

  switch (residue_73_2)
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
  int checksum_63_1 = local_arr_1[aux_1 % 3];
  int checksum_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_63_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_42_1) & 63;
  aux_2 = (aux_2 + cursor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_73_1 == residue_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(cursor_42_1 == cursor_42_2);
}

int fn_R001878_7813_20(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001878_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_73 = (aux + st.buffer[1]) & 3;
  switch (residue_73)
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
  int checksum_63 = local_arr[aux % 3];
  acc = (acc + (checksum_63 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001878_0_1;
  int sec_r001878_0_2;
  int sec_r001878_1_1;
  int sec_r001878_1_2;
  int sec_r001878_2_1;
  int sec_r001878_2_2;
  int sec_r001878_3_1;
  int sec_r001878_3_2;
  int sec_r001878_4_1;
  int sec_r001878_4_2;
  int sec_r001878_5_1;
  int sec_r001878_5_2;
  int sec_r001878_6_1;
  int sec_r001878_6_2;
  int sec_r001878_7_1;
  int sec_r001878_7_2;
  int sec_r001878_8_1;
  int sec_r001878_8_2;
  int sec_r001878_9_1;
  int sec_r001878_9_2;
  int sec_r001878_10_1;
  int sec_r001878_10_2;
  int sec_r001878_11_1;
  int sec_r001878_11_2;
  int sec_r001878_12_1;
  int sec_r001878_12_2;
  int sec_r001878_13_1;
  int sec_r001878_13_2;
  int sec_r001878_14_1;
  int sec_r001878_14_2;
  int sec_r001878_15_1;
  int sec_r001878_15_2;
  int sec_r001878_16_1;
  int sec_r001878_16_2;
  int sec_r001878_17_1;
  int sec_r001878_17_2;
  int sec_r001878_18_1;
  int sec_r001878_18_2;
  int sec_r001878_19_1;
  int sec_r001878_19_2;
  int sec_r001878_20_1;
  int sec_r001878_20_2;
  int sec_r001878_21_1;
  int sec_r001878_21_2;
  int sec_r001878_22_1;
  int sec_r001878_22_2;
  int pub_r001878_0_1;
  int pub_r001878_0_2;
  int pub_r001878_1_1;
  int pub_r001878_1_2;
  int pub_r001878_2_1;
  int pub_r001878_2_2;
  int pub_r001878_3_1;
  int pub_r001878_3_2;
  int pub_r001878_4_1;
  int pub_r001878_4_2;
  int pub_r001878_5_1;
  int pub_r001878_5_2;
  int pub_r001878_6_1;
  int pub_r001878_6_2;
  int pub_r001878_7_1;
  int pub_r001878_7_2;
  int pub_r001878_8_1;
  int pub_r001878_8_2;
  int pub_r001878_9_1;
  int pub_r001878_9_2;
  int pub_r001878_10_1;
  int pub_r001878_10_2;
  int pub_r001878_11_1;
  int pub_r001878_11_2;
  int pub_r001878_12_1;
  int pub_r001878_12_2;
  int pub_r001878_13_1;
  int pub_r001878_13_2;
  int pub_r001878_14_1;
  int pub_r001878_14_2;
  int pub_r001878_15_1;
  int pub_r001878_15_2;
  int pub_r001878_16_1;
  int pub_r001878_16_2;
  int pub_r001878_17_1;
  int pub_r001878_17_2;
  int pub_r001878_18_1;
  int pub_r001878_18_2;
  int pub_r001878_19_1;
  int pub_r001878_19_2;
  int pub_r001878_20_1;
  int pub_r001878_20_2;
  int pub_r001878_21_1;
  int pub_r001878_21_2;
  int pub_r001878_22_1;
  int pub_r001878_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001878_0_1 >= (-100)) && (pub_r001878_0_1 <= 100));
  __CPROVER_assume((pub_r001878_0_2 >= (-100)) && (pub_r001878_0_2 <= 100));
  __CPROVER_assume((pub_r001878_1_1 >= (-100)) && (pub_r001878_1_1 <= 100));
  __CPROVER_assume((pub_r001878_1_2 >= (-100)) && (pub_r001878_1_2 <= 100));
  __CPROVER_assume((pub_r001878_2_1 >= (-100)) && (pub_r001878_2_1 <= 100));
  __CPROVER_assume((pub_r001878_2_2 >= (-100)) && (pub_r001878_2_2 <= 100));
  __CPROVER_assume((pub_r001878_3_1 >= (-100)) && (pub_r001878_3_1 <= 100));
  __CPROVER_assume((pub_r001878_3_2 >= (-100)) && (pub_r001878_3_2 <= 100));
  __CPROVER_assume((pub_r001878_4_1 >= (-100)) && (pub_r001878_4_1 <= 100));
  __CPROVER_assume((pub_r001878_4_2 >= (-100)) && (pub_r001878_4_2 <= 100));
  __CPROVER_assume((pub_r001878_5_1 >= (-100)) && (pub_r001878_5_1 <= 100));
  __CPROVER_assume((pub_r001878_5_2 >= (-100)) && (pub_r001878_5_2 <= 100));
  __CPROVER_assume((pub_r001878_6_1 >= (-100)) && (pub_r001878_6_1 <= 100));
  __CPROVER_assume((pub_r001878_6_2 >= (-100)) && (pub_r001878_6_2 <= 100));
  __CPROVER_assume((pub_r001878_7_1 >= (-100)) && (pub_r001878_7_1 <= 100));
  __CPROVER_assume((pub_r001878_7_2 >= (-100)) && (pub_r001878_7_2 <= 100));
  __CPROVER_assume((pub_r001878_8_1 >= (-100)) && (pub_r001878_8_1 <= 100));
  __CPROVER_assume((pub_r001878_8_2 >= (-100)) && (pub_r001878_8_2 <= 100));
  __CPROVER_assume((pub_r001878_9_1 >= (-100)) && (pub_r001878_9_1 <= 100));
  __CPROVER_assume((pub_r001878_9_2 >= (-100)) && (pub_r001878_9_2 <= 100));
  __CPROVER_assume((pub_r001878_10_1 >= (-100)) && (pub_r001878_10_1 <= 100));
  __CPROVER_assume((pub_r001878_10_2 >= (-100)) && (pub_r001878_10_2 <= 100));
  __CPROVER_assume((pub_r001878_11_1 >= (-100)) && (pub_r001878_11_1 <= 100));
  __CPROVER_assume((pub_r001878_11_2 >= (-100)) && (pub_r001878_11_2 <= 100));
  __CPROVER_assume((pub_r001878_12_1 >= (-100)) && (pub_r001878_12_1 <= 100));
  __CPROVER_assume((pub_r001878_12_2 >= (-100)) && (pub_r001878_12_2 <= 100));
  __CPROVER_assume((pub_r001878_13_1 >= (-100)) && (pub_r001878_13_1 <= 100));
  __CPROVER_assume((pub_r001878_13_2 >= (-100)) && (pub_r001878_13_2 <= 100));
  __CPROVER_assume((pub_r001878_14_1 >= (-100)) && (pub_r001878_14_1 <= 100));
  __CPROVER_assume((pub_r001878_14_2 >= (-100)) && (pub_r001878_14_2 <= 100));
  __CPROVER_assume((pub_r001878_15_1 >= (-100)) && (pub_r001878_15_1 <= 100));
  __CPROVER_assume((pub_r001878_15_2 >= (-100)) && (pub_r001878_15_2 <= 100));
  __CPROVER_assume((pub_r001878_16_1 >= (-100)) && (pub_r001878_16_1 <= 100));
  __CPROVER_assume((pub_r001878_16_2 >= (-100)) && (pub_r001878_16_2 <= 100));
  __CPROVER_assume((pub_r001878_17_1 >= (-100)) && (pub_r001878_17_1 <= 100));
  __CPROVER_assume((pub_r001878_17_2 >= (-100)) && (pub_r001878_17_2 <= 100));
  __CPROVER_assume((pub_r001878_18_1 >= (-100)) && (pub_r001878_18_1 <= 100));
  __CPROVER_assume((pub_r001878_18_2 >= (-100)) && (pub_r001878_18_2 <= 100));
  __CPROVER_assume((pub_r001878_19_1 >= (-100)) && (pub_r001878_19_1 <= 100));
  __CPROVER_assume((pub_r001878_19_2 >= (-100)) && (pub_r001878_19_2 <= 100));
  __CPROVER_assume((pub_r001878_20_1 >= (-100)) && (pub_r001878_20_1 <= 100));
  __CPROVER_assume((pub_r001878_20_2 >= (-100)) && (pub_r001878_20_2 <= 100));
  __CPROVER_assume((pub_r001878_21_1 >= (-100)) && (pub_r001878_21_1 <= 100));
  __CPROVER_assume((pub_r001878_21_2 >= (-100)) && (pub_r001878_21_2 <= 100));
  __CPROVER_assume((pub_r001878_22_1 >= (-100)) && (pub_r001878_22_1 <= 100));
  __CPROVER_assume((pub_r001878_22_2 >= (-100)) && (pub_r001878_22_2 <= 100));
  __CPROVER_assume((sec_r001878_0_1 >= 0) && (sec_r001878_0_1 <= 255));
  __CPROVER_assume((sec_r001878_0_2 >= 0) && (sec_r001878_0_2 <= 255));
  __CPROVER_assume((sec_r001878_1_1 >= 0) && (sec_r001878_1_1 <= 255));
  __CPROVER_assume((sec_r001878_1_2 >= 0) && (sec_r001878_1_2 <= 255));
  __CPROVER_assume((sec_r001878_2_1 >= 0) && (sec_r001878_2_1 <= 255));
  __CPROVER_assume((sec_r001878_2_2 >= 0) && (sec_r001878_2_2 <= 255));
  __CPROVER_assume((sec_r001878_3_1 >= 0) && (sec_r001878_3_1 <= 255));
  __CPROVER_assume((sec_r001878_3_2 >= 0) && (sec_r001878_3_2 <= 255));
  __CPROVER_assume((sec_r001878_4_1 >= 0) && (sec_r001878_4_1 <= 255));
  __CPROVER_assume((sec_r001878_4_2 >= 0) && (sec_r001878_4_2 <= 255));
  __CPROVER_assume((sec_r001878_5_1 >= 0) && (sec_r001878_5_1 <= 255));
  __CPROVER_assume((sec_r001878_5_2 >= 0) && (sec_r001878_5_2 <= 255));
  __CPROVER_assume((sec_r001878_6_1 >= 0) && (sec_r001878_6_1 <= 255));
  __CPROVER_assume((sec_r001878_6_2 >= 0) && (sec_r001878_6_2 <= 255));
  __CPROVER_assume((sec_r001878_7_1 >= 0) && (sec_r001878_7_1 <= 255));
  __CPROVER_assume((sec_r001878_7_2 >= 0) && (sec_r001878_7_2 <= 255));
  __CPROVER_assume((sec_r001878_8_1 >= 0) && (sec_r001878_8_1 <= 255));
  __CPROVER_assume((sec_r001878_8_2 >= 0) && (sec_r001878_8_2 <= 255));
  __CPROVER_assume((sec_r001878_9_1 >= 0) && (sec_r001878_9_1 <= 255));
  __CPROVER_assume((sec_r001878_9_2 >= 0) && (sec_r001878_9_2 <= 255));
  __CPROVER_assume((sec_r001878_10_1 >= 0) && (sec_r001878_10_1 <= 255));
  __CPROVER_assume((sec_r001878_10_2 >= 0) && (sec_r001878_10_2 <= 255));
  __CPROVER_assume((sec_r001878_11_1 >= 0) && (sec_r001878_11_1 <= 255));
  __CPROVER_assume((sec_r001878_11_2 >= 0) && (sec_r001878_11_2 <= 255));
  __CPROVER_assume((sec_r001878_12_1 >= 0) && (sec_r001878_12_1 <= 255));
  __CPROVER_assume((sec_r001878_12_2 >= 0) && (sec_r001878_12_2 <= 255));
  __CPROVER_assume((sec_r001878_13_1 >= 0) && (sec_r001878_13_1 <= 255));
  __CPROVER_assume((sec_r001878_13_2 >= 0) && (sec_r001878_13_2 <= 255));
  __CPROVER_assume((sec_r001878_14_1 >= 0) && (sec_r001878_14_1 <= 255));
  __CPROVER_assume((sec_r001878_14_2 >= 0) && (sec_r001878_14_2 <= 255));
  __CPROVER_assume((sec_r001878_15_1 >= 0) && (sec_r001878_15_1 <= 255));
  __CPROVER_assume((sec_r001878_15_2 >= 0) && (sec_r001878_15_2 <= 255));
  __CPROVER_assume((sec_r001878_16_1 >= 0) && (sec_r001878_16_1 <= 255));
  __CPROVER_assume((sec_r001878_16_2 >= 0) && (sec_r001878_16_2 <= 255));
  __CPROVER_assume((sec_r001878_17_1 >= 0) && (sec_r001878_17_1 <= 255));
  __CPROVER_assume((sec_r001878_17_2 >= 0) && (sec_r001878_17_2 <= 255));
  __CPROVER_assume((sec_r001878_18_1 >= 0) && (sec_r001878_18_1 <= 255));
  __CPROVER_assume((sec_r001878_18_2 >= 0) && (sec_r001878_18_2 <= 255));
  __CPROVER_assume((sec_r001878_19_1 >= 0) && (sec_r001878_19_1 <= 255));
  __CPROVER_assume((sec_r001878_19_2 >= 0) && (sec_r001878_19_2 <= 255));
  __CPROVER_assume((sec_r001878_20_1 >= 0) && (sec_r001878_20_1 <= 255));
  __CPROVER_assume((sec_r001878_20_2 >= 0) && (sec_r001878_20_2 <= 255));
  __CPROVER_assume((sec_r001878_21_1 >= 0) && (sec_r001878_21_1 <= 255));
  __CPROVER_assume((sec_r001878_21_2 >= 0) && (sec_r001878_21_2 <= 255));
  __CPROVER_assume((sec_r001878_22_1 >= 0) && (sec_r001878_22_1 <= 255));
  __CPROVER_assume((sec_r001878_22_2 >= 0) && (sec_r001878_22_2 <= 255));
  struct StreamBuffer_R001878_7813_0 st_var_0_1 = {0};
  struct StreamBuffer_R001878_7813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001878_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001878_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001878_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001878_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001878_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001878_0_2 + 7) & 15;
  struct Vector3D_R001878_7813_1 st_var_1_1 = {0};
  struct Vector3D_R001878_7813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001878_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001878_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001878_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001878_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001878_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001878_0_2 + 9) & 15;
  struct DeviceConfig_R001878_7813_2 st_var_2_1 = {0};
  struct DeviceConfig_R001878_7813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001878_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001878_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001878_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001878_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001878_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001878_0_2 + 11) & 15;
  union TelemetryField_R001878_7813_0 u_var_1;
  union TelemetryField_R001878_7813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001878_7813_0(sec_r001878_0_1, sec_r001878_1_1, pub_r001878_2_1, pub_r001878_3_1, pub_r001878_4_1);
  int helper_flow_0_2 = fn_R001878_7813_0(sec_r001878_0_2, sec_r001878_1_2, pub_r001878_2_2, pub_r001878_3_2, pub_r001878_4_2);
  fn_R001878_7813_0_2(sec_r001878_0_1, sec_r001878_1_1, pub_r001878_2_1, pub_r001878_3_1, pub_r001878_4_1, sec_r001878_0_2, sec_r001878_1_2, pub_r001878_2_2, pub_r001878_3_2, pub_r001878_4_2);
  int helper_flow_1_1 = fn_R001878_7813_1(sec_r001878_1_1, pub_r001878_2_1);
  int helper_flow_1_2 = fn_R001878_7813_1(sec_r001878_1_2, pub_r001878_2_2);
  fn_R001878_7813_1_2(sec_r001878_1_1, pub_r001878_2_1, sec_r001878_1_2, pub_r001878_2_2);
  int helper_flow_2_1 = fn_R001878_7813_2(sec_r001878_2_1, sec_r001878_3_1, pub_r001878_4_1, pub_r001878_5_1);
  int helper_flow_2_2 = fn_R001878_7813_2(sec_r001878_2_2, sec_r001878_3_2, pub_r001878_4_2, pub_r001878_5_2);
  fn_R001878_7813_2_2(sec_r001878_2_1, sec_r001878_3_1, pub_r001878_4_1, pub_r001878_5_1, sec_r001878_2_2, sec_r001878_3_2, pub_r001878_4_2, pub_r001878_5_2);
  int helper_flow_3_1 = fn_R001878_7813_3(sec_r001878_3_1, pub_r001878_4_1, pub_r001878_5_1, pub_r001878_6_1);
  int helper_flow_3_2 = fn_R001878_7813_3(sec_r001878_3_2, pub_r001878_4_2, pub_r001878_5_2, pub_r001878_6_2);
  fn_R001878_7813_3_2(sec_r001878_3_1, pub_r001878_4_1, pub_r001878_5_1, pub_r001878_6_1, sec_r001878_3_2, pub_r001878_4_2, pub_r001878_5_2, pub_r001878_6_2);
  int helper_flow_4_1 = fn_R001878_7813_4(sec_r001878_4_1, sec_r001878_5_1, pub_r001878_6_1, pub_r001878_7_1);
  int helper_flow_4_2 = fn_R001878_7813_4(sec_r001878_4_2, sec_r001878_5_2, pub_r001878_6_2, pub_r001878_7_2);
  fn_R001878_7813_4_2(sec_r001878_4_1, sec_r001878_5_1, pub_r001878_6_1, pub_r001878_7_1, sec_r001878_4_2, sec_r001878_5_2, pub_r001878_6_2, pub_r001878_7_2);
  int helper_flow_5_1 = fn_R001878_7813_5(sec_r001878_5_1, pub_r001878_6_1, pub_r001878_7_1);
  int helper_flow_5_2 = fn_R001878_7813_5(sec_r001878_5_2, pub_r001878_6_2, pub_r001878_7_2);
  fn_R001878_7813_5_2(sec_r001878_5_1, pub_r001878_6_1, pub_r001878_7_1, sec_r001878_5_2, pub_r001878_6_2, pub_r001878_7_2);
  int helper_flow_6_1 = fn_R001878_7813_6(sec_r001878_6_1, sec_r001878_7_1);
  int helper_flow_6_2 = fn_R001878_7813_6(sec_r001878_6_2, sec_r001878_7_2);
  fn_R001878_7813_6_2(sec_r001878_6_1, sec_r001878_7_1, sec_r001878_6_2, sec_r001878_7_2);
  int helper_flow_7_1 = fn_R001878_7813_7(sec_r001878_7_1, pub_r001878_8_1, pub_r001878_9_1, pub_r001878_10_1);
  int helper_flow_7_2 = fn_R001878_7813_7(sec_r001878_7_2, pub_r001878_8_2, pub_r001878_9_2, pub_r001878_10_2);
  fn_R001878_7813_7_2(sec_r001878_7_1, pub_r001878_8_1, pub_r001878_9_1, pub_r001878_10_1, sec_r001878_7_2, pub_r001878_8_2, pub_r001878_9_2, pub_r001878_10_2);
  int helper_flow_8_1 = fn_R001878_7813_8(sec_r001878_8_1, pub_r001878_9_1, pub_r001878_10_1, pub_r001878_11_1);
  int helper_flow_8_2 = fn_R001878_7813_8(sec_r001878_8_2, pub_r001878_9_2, pub_r001878_10_2, pub_r001878_11_2);
  fn_R001878_7813_8_2(sec_r001878_8_1, pub_r001878_9_1, pub_r001878_10_1, pub_r001878_11_1, sec_r001878_8_2, pub_r001878_9_2, pub_r001878_10_2, pub_r001878_11_2);
  int helper_flow_9_1 = fn_R001878_7813_9(sec_r001878_9_1, pub_r001878_10_1, pub_r001878_11_1, pub_r001878_12_1);
  int helper_flow_9_2 = fn_R001878_7813_9(sec_r001878_9_2, pub_r001878_10_2, pub_r001878_11_2, pub_r001878_12_2);
  fn_R001878_7813_9_2(sec_r001878_9_1, pub_r001878_10_1, pub_r001878_11_1, pub_r001878_12_1, sec_r001878_9_2, pub_r001878_10_2, pub_r001878_11_2, pub_r001878_12_2);
  int helper_flow_10_1 = fn_R001878_7813_10(sec_r001878_10_1, pub_r001878_11_1, pub_r001878_12_1);
  int helper_flow_10_2 = fn_R001878_7813_10(sec_r001878_10_2, pub_r001878_11_2, pub_r001878_12_2);
  fn_R001878_7813_10_2(sec_r001878_10_1, pub_r001878_11_1, pub_r001878_12_1, sec_r001878_10_2, pub_r001878_11_2, pub_r001878_12_2);
  int stage_v_0_1 = ((pub_r001878_10_1 * 2) + 35) & 63;
  int stage_v_0_2 = ((pub_r001878_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001878_15_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001878_15_2 & 15)) & 63;
    if ((sec_r001878_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001878_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = ((pub_r001878_21_1 * 2) + 33) & 63;
  int stage_v_2_2 = ((pub_r001878_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001878_22_1 * 2) + 30) & 63;
  int stage_v_3_2 = ((pub_r001878_22_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001878_4_1 * 2) + 47) & 63;
  int stage_v_4_2 = ((pub_r001878_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (it_1 * 3)) + (sec_r001878_18_1 & 15)) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (it_2 * 3)) + (sec_r001878_18_2 & 15)) & 63;
    if ((sec_r001878_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_5_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_5_1) + 7) & 255;
    }
    if ((sec_r001878_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_5_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_5_2) + 7) & 255;
    }
  }

  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001878_7_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001878_7_2 & 15)) & 63;
    if ((sec_r001878_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001878_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (it_1 * 3)) + (sec_r001878_20_1 & 15)) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (it_2 * 3)) + (sec_r001878_20_2 & 15)) & 63;
    if ((sec_r001878_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_7_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_7_1) + 7) & 255;
    }
    if ((sec_r001878_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_7_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_7_2) + 7) & 255;
    }
  }

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (it_1 * 3)) + (sec_r001878_7_1 & 15)) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (it_2 * 3)) + (sec_r001878_7_2 & 15)) & 63;
    if ((sec_r001878_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_8_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_8_1) + 7) & 255;
    }
    if ((sec_r001878_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_8_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_8_2) + 7) & 255;
    }
  }

  int stage_v_9_1 = ((pub_r001878_12_1 * 2) + 36) & 63;
  int stage_v_9_2 = ((pub_r001878_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (sec_r001878_11_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (sec_r001878_11_2 & 15)) & 63;
    if ((sec_r001878_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((sec_r001878_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_13_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_13_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_13_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_13_2) + 7) & 255;
    }
  }

  int stage_v_14_1 = ((pub_r001878_6_1 * 2) + 23) & 63;
  int stage_v_14_2 = ((pub_r001878_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (sec_r001878_16_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (sec_r001878_16_2 & 15)) & 63;
    if ((sec_r001878_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((sec_r001878_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (it_1 * 3)) + (sec_r001878_16_1 & 15)) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (it_2 * 3)) + (sec_r001878_16_2 & 15)) & 63;
    if ((sec_r001878_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_17_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_17_1) + 7) & 255;
    }
    if ((sec_r001878_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_17_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_17_2) + 7) & 255;
    }
  }

  int stage_v_18_1 = ((pub_r001878_6_1 * 2) + 31) & 63;
  int stage_v_18_2 = ((pub_r001878_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (sec_r001878_9_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (sec_r001878_9_2 & 15)) & 63;
    if ((sec_r001878_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((sec_r001878_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_20_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_20_2) + 7) & 255;
    }
  }

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001878_15_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001878_15_2 & 15)) & 63;
    if ((sec_r001878_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001878_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_22_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_22_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_22_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_22_2) + 7) & 255;
    }
  }

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001878_19_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001878_19_2 & 15)) & 63;
    if ((sec_r001878_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001878_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = ((pub_r001878_7_1 * 2) + 25) & 63;
  int stage_v_25_2 = ((pub_r001878_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_26_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_26_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_26_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_26_2) + 7) & 255;
    }
  }

  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_27_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_27_2) + 7) & 255;
    }
  }

  int stage_v_28_1 = ((pub_r001878_2_1 * 2) + 9) & 63;
  int stage_v_28_2 = ((pub_r001878_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001878_8_1 * 2) + 40) & 63;
  int stage_v_29_2 = ((pub_r001878_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = ((pub_r001878_13_1 * 2) + 26) & 63;
  int stage_v_31_2 = ((pub_r001878_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (sec_r001878_14_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (sec_r001878_14_2 & 15)) & 63;
    if ((sec_r001878_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((sec_r001878_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (it_1 * 3)) + (sec_r001878_17_1 & 15)) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (it_2 * 3)) + (sec_r001878_17_2 & 15)) & 63;
    if ((sec_r001878_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_33_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_33_1) + 7) & 255;
    }
    if ((sec_r001878_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_33_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_33_2) + 7) & 255;
    }
  }

  int stage_v_34_1 = ((pub_r001878_8_1 * 2) + 47) & 63;
  int stage_v_34_2 = ((pub_r001878_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001878_3_1 * 2) + 19) & 63;
  int stage_v_35_2 = ((pub_r001878_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001878_21_1 * 2) + 10) & 63;
  int stage_v_36_2 = ((pub_r001878_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001878_13_1 * 2) + 7) & 63;
  int stage_v_37_2 = ((pub_r001878_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_6_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_6_2 & 15)) & 63;
    if ((stage_v_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_39_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_39_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_39_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_39_2) + 7) & 255;
    }
  }

  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_40_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_40_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_40_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_40_2) + 7) & 255;
    }
  }

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (it_1 * 3)) + (sec_r001878_12_1 & 15)) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (it_2 * 3)) + (sec_r001878_12_2 & 15)) & 63;
    if ((sec_r001878_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_41_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_41_1) + 7) & 255;
    }
    if ((sec_r001878_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_41_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_41_2) + 7) & 255;
    }
  }

  int stage_v_42_1 = ((pub_r001878_6_1 * 2) + 43) & 63;
  int stage_v_42_2 = ((pub_r001878_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (sec_r001878_1_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (sec_r001878_1_2 & 15)) & 63;
    if ((sec_r001878_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((sec_r001878_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (sec_r001878_4_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (sec_r001878_4_2 & 15)) & 63;
    if ((sec_r001878_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((sec_r001878_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (sec_r001878_12_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (sec_r001878_12_2 & 15)) & 63;
    if ((sec_r001878_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((sec_r001878_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (it_1 * 3)) + (sec_r001878_2_1 & 15)) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (it_2 * 3)) + (sec_r001878_2_2 & 15)) & 63;
    if ((sec_r001878_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_46_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_46_1) + 7) & 255;
    }
    if ((sec_r001878_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_46_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_46_2) + 7) & 255;
    }
  }

  int stage_v_47_1 = ((pub_r001878_6_1 * 2) + 17) & 63;
  int stage_v_47_2 = ((pub_r001878_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001878_0_1 * 2) + 42) & 63;
  int stage_v_48_2 = ((pub_r001878_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_49_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_49_2) + 7) & 255;
    }
  }

  int stage_v_50_1 = ((pub_r001878_1_1 * 2) + 38) & 63;
  int stage_v_50_2 = ((pub_r001878_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = ((pub_r001878_9_1 * 2) + 30) & 63;
  int stage_v_52_2 = ((pub_r001878_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001878_11_1 * 2) + 13) & 63;
  int stage_v_53_2 = ((pub_r001878_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_54_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_54_2) + 7) & 255;
    }
  }

  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (sec_r001878_21_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (sec_r001878_21_2 & 15)) & 63;
    if ((sec_r001878_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((sec_r001878_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_56_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_56_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_56_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_56_2) + 7) & 255;
    }
  }

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = ((pub_r001878_11_1 * 2) + 25) & 63;
  int stage_v_58_2 = ((pub_r001878_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001878_8_1 * 2) + 40) & 63;
  int stage_v_59_2 = ((pub_r001878_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001878_8_1 * 2) + 10) & 63;
  int stage_v_60_2 = ((pub_r001878_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001878_12_1 * 2) + 34) & 63;
  int stage_v_61_2 = ((pub_r001878_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001878_15_1 * 2) + 27) & 63;
  int stage_v_62_2 = ((pub_r001878_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001878_21_1 * 2) + 15) & 63;
  int stage_v_63_2 = ((pub_r001878_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001878_11_1 * 2) + 20) & 63;
  int stage_v_64_2 = ((pub_r001878_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001878_2_1 * 2) + 36) & 63;
  int stage_v_65_2 = ((pub_r001878_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001878_22_1 * 2) + 47) & 63;
  int stage_v_66_2 = ((pub_r001878_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001878_3_1 * 2) + 47) & 63;
  int stage_v_67_2 = ((pub_r001878_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = ((pub_r001878_2_1 * 2) + 43) & 63;
  int stage_v_69_2 = ((pub_r001878_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001878_3_1 * 2) + 20) & 63;
  int stage_v_70_2 = ((pub_r001878_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001878_2_1 * 2) + 28) & 63;
  int stage_v_71_2 = ((pub_r001878_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_72_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_72_2) + 7) & 255;
    }
  }

  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_73_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_73_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_73_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_73_2) + 7) & 255;
    }
  }

  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (sec_r001878_11_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (sec_r001878_11_2 & 15)) & 63;
    if ((sec_r001878_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((sec_r001878_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = ((pub_r001878_20_1 * 2) + 27) & 63;
  int stage_v_76_2 = ((pub_r001878_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001878_8_1 * 2) + 20) & 63;
  int stage_v_77_2 = ((pub_r001878_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_78_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_78_2) + 7) & 255;
    }
  }

  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (it_1 * 3)) + (stage_v_19_1 & 15)) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (it_2 * 3)) + (stage_v_19_2 & 15)) & 63;
    if ((stage_v_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_79_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_79_1) + 7) & 255;
    }
    if ((stage_v_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_79_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_79_2) + 7) & 255;
    }
  }

  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (sec_r001878_10_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (sec_r001878_10_2 & 15)) & 63;
    if ((sec_r001878_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((sec_r001878_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_81_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_81_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_81_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_81_2) + 7) & 255;
    }
  }

  int stage_v_82_1 = ((pub_r001878_7_1 * 2) + 33) & 63;
  int stage_v_82_2 = ((pub_r001878_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (sec_r001878_16_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (sec_r001878_16_2 & 15)) & 63;
    if ((sec_r001878_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((sec_r001878_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (it_1 * 3)) + (stage_v_72_1 & 15)) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (it_2 * 3)) + (stage_v_72_2 & 15)) & 63;
    if ((stage_v_72_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_84_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_84_1) + 7) & 255;
    }
    if ((stage_v_72_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_84_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_84_2) + 7) & 255;
    }
  }

  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_85_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_85_2) + 7) & 255;
    }
  }

  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (sec_r001878_22_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (sec_r001878_22_2 & 15)) & 63;
    if ((sec_r001878_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((sec_r001878_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_86_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_86_2) + 7) & 255;
    }
  }

  int stage_v_87_1 = ((pub_r001878_8_1 * 2) + 32) & 63;
  int stage_v_87_2 = ((pub_r001878_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (sec_r001878_15_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (sec_r001878_15_2 & 15)) & 63;
    if ((sec_r001878_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((sec_r001878_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = ((pub_r001878_19_1 * 2) + 11) & 63;
  int stage_v_90_2 = ((pub_r001878_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (sec_r001878_18_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (sec_r001878_18_2 & 15)) & 63;
    if ((sec_r001878_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((sec_r001878_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = ((pub_r001878_20_1 * 2) + 23) & 63;
  int stage_v_92_2 = ((pub_r001878_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001878_3_1 * 2) + 14) & 63;
  int stage_v_93_2 = ((pub_r001878_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_94_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_94_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_94_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_94_2) + 7) & 255;
    }
  }

  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = ((pub_r001878_14_1 * 2) + 10) & 63;
  int stage_v_96_2 = ((pub_r001878_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (sec_r001878_7_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (sec_r001878_7_2 & 15)) & 63;
    if ((sec_r001878_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((sec_r001878_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = ((pub_r001878_7_1 * 2) + 46) & 63;
  int stage_v_98_2 = ((pub_r001878_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (stage_v_94_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (stage_v_94_2 & 15)) & 63;
    if ((stage_v_94_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((stage_v_94_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_100_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_100_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_100_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_100_2) + 7) & 255;
    }
  }

  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (sec_r001878_8_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (sec_r001878_8_2 & 15)) & 63;
    if ((sec_r001878_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((sec_r001878_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = ((pub_r001878_16_1 * 2) + 41) & 63;
  int stage_v_102_2 = ((pub_r001878_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_86_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_86_2 & 15)) & 63;
    if ((stage_v_86_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_86_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_103_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_103_2) + 7) & 255;
    }
  }

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (stage_v_101_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (stage_v_101_2 & 15)) & 63;
    if ((stage_v_101_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((stage_v_101_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_104_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_104_2) + 7) & 255;
    }
  }

  int stage_v_105_1 = ((pub_r001878_2_1 * 2) + 19) & 63;
  int stage_v_105_2 = ((pub_r001878_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001878_9_1 * 2) + 16) & 63;
  int stage_v_106_2 = ((pub_r001878_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001878_11_1 * 2) + 22) & 63;
  int stage_v_107_2 = ((pub_r001878_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (sec_r001878_20_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (sec_r001878_20_2 & 15)) & 63;
    if ((sec_r001878_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((sec_r001878_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = ((pub_r001878_13_1 * 2) + 50) & 63;
  int stage_v_109_2 = ((pub_r001878_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001878_12_1 * 2) + 25) & 63;
  int stage_v_110_2 = ((pub_r001878_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_112_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_112_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_112_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_112_2) + 7) & 255;
    }
  }

  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (it_1 * 3)) + (sec_r001878_22_1 & 15)) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (it_2 * 3)) + (sec_r001878_22_2 & 15)) & 63;
    if ((sec_r001878_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_113_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_113_1) + 7) & 255;
    }
    if ((sec_r001878_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_113_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_113_2) + 7) & 255;
    }
  }

  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_85_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_85_2 & 15)) & 63;
    if ((stage_v_85_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_85_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_114_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_114_2) + 7) & 255;
    }
  }

  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (it_1 * 3)) + (stage_v_103_1 & 15)) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (it_2 * 3)) + (stage_v_103_2 & 15)) & 63;
    if ((stage_v_103_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_115_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_115_1) + 7) & 255;
    }
    if ((stage_v_103_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_115_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_115_2) + 7) & 255;
    }
  }

  int stage_v_116_1 = ((pub_r001878_4_1 * 2) + 5) & 63;
  int stage_v_116_2 = ((pub_r001878_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001878_10_1 * 2) + 14) & 63;
  int stage_v_117_2 = ((pub_r001878_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_118_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_118_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_118_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_118_2) + 7) & 255;
    }
  }

  int stage_v_119_1 = ((pub_r001878_8_1 * 2) + 50) & 63;
  int stage_v_119_2 = ((pub_r001878_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001878_15_1 * 2) + 30) & 63;
  int stage_v_120_2 = ((pub_r001878_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (it_1 * 3)) + (sec_r001878_13_1 & 15)) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (it_2 * 3)) + (sec_r001878_13_2 & 15)) & 63;
    if ((sec_r001878_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_121_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_121_1) + 7) & 255;
    }
    if ((sec_r001878_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_121_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_121_2) + 7) & 255;
    }
  }

  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_122_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_122_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_122_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_122_2) + 7) & 255;
    }
  }

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (it_1 * 3)) + (sec_r001878_10_1 & 15)) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (it_2 * 3)) + (sec_r001878_10_2 & 15)) & 63;
    if ((sec_r001878_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_124_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_124_1) + 7) & 255;
    }
    if ((sec_r001878_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_124_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_124_2) + 7) & 255;
    }
  }

  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = ((pub_r001878_21_1 * 2) + 48) & 63;
  int stage_v_126_2 = ((pub_r001878_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (sec_r001878_21_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (sec_r001878_21_2 & 15)) & 63;
    if ((sec_r001878_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((sec_r001878_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (it_1 * 3)) + (sec_r001878_22_1 & 15)) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (it_2 * 3)) + (sec_r001878_22_2 & 15)) & 63;
    if ((sec_r001878_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_128_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_128_1) + 7) & 255;
    }
    if ((sec_r001878_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_128_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_128_2) + 7) & 255;
    }
  }

  int stage_v_129_1 = ((pub_r001878_12_1 * 2) + 5) & 63;
  int stage_v_129_2 = ((pub_r001878_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_130_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_130_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_130_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_130_2) + 7) & 255;
    }
  }

  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (it_1 * 3)) + (stage_v_40_1 & 15)) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (it_2 * 3)) + (stage_v_40_2 & 15)) & 63;
    if ((stage_v_40_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_132_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_132_1) + 7) & 255;
    }
    if ((stage_v_40_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_132_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_132_2) + 7) & 255;
    }
  }

  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (sec_r001878_14_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (sec_r001878_14_2 & 15)) & 63;
    if ((sec_r001878_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((sec_r001878_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_134_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_134_2) + 7) & 255;
    }
  }

  int stage_v_135_1 = ((pub_r001878_6_1 * 2) + 6) & 63;
  int stage_v_135_2 = ((pub_r001878_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (sec_r001878_10_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (sec_r001878_10_2 & 15)) & 63;
    if ((sec_r001878_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((sec_r001878_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_136_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_136_2) + 7) & 255;
    }
  }

  int stage_v_137_1 = ((pub_r001878_18_1 * 2) + 48) & 63;
  int stage_v_137_2 = ((pub_r001878_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_124_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_124_2 & 15)) & 63;
    if ((stage_v_124_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_124_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = ((pub_r001878_8_1 * 2) + 29) & 63;
  int stage_v_139_2 = ((pub_r001878_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001878_9_1 * 2) + 13) & 63;
  int stage_v_140_2 = ((pub_r001878_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (it_1 * 3)) + (stage_v_94_1 & 15)) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (it_2 * 3)) + (stage_v_94_2 & 15)) & 63;
    if ((stage_v_94_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_142_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_142_1) + 7) & 255;
    }
    if ((stage_v_94_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_142_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_142_2) + 7) & 255;
    }
  }

  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_143_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_143_2) + 7) & 255;
    }
  }

  int stage_v_144_1 = ((pub_r001878_16_1 * 2) + 37) & 63;
  int stage_v_144_2 = ((pub_r001878_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (sec_r001878_10_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (sec_r001878_10_2 & 15)) & 63;
    if ((sec_r001878_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((sec_r001878_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (it_1 * 3)) + (stage_v_97_1 & 15)) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (it_2 * 3)) + (stage_v_97_2 & 15)) & 63;
    if ((stage_v_97_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_146_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_146_1) + 7) & 255;
    }
    if ((stage_v_97_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_146_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_146_2) + 7) & 255;
    }
  }

  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (sec_r001878_4_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (sec_r001878_4_2 & 15)) & 63;
    if ((sec_r001878_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((sec_r001878_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_148_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_148_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_148_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_148_2) + 7) & 255;
    }
  }

  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (stage_v_138_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (stage_v_138_2 & 15)) & 63;
    if ((stage_v_138_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((stage_v_138_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_149_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_149_2) + 7) & 255;
    }
  }

  int stage_v_150_1 = ((pub_r001878_13_1 * 2) + 16) & 63;
  int stage_v_150_2 = ((pub_r001878_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_151_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_151_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_151_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_151_2) + 7) & 255;
    }
  }

  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (it_1 * 3)) + (sec_r001878_2_1 & 15)) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (it_2 * 3)) + (sec_r001878_2_2 & 15)) & 63;
    if ((sec_r001878_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_152_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_152_1) + 7) & 255;
    }
    if ((sec_r001878_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_152_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_152_2) + 7) & 255;
    }
  }

  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (sec_r001878_11_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (sec_r001878_11_2 & 15)) & 63;
    if ((sec_r001878_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((sec_r001878_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_153_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_153_2) + 7) & 255;
    }
  }

  int stage_v_154_1 = ((pub_r001878_11_1 * 2) + 45) & 63;
  int stage_v_154_2 = ((pub_r001878_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001878_15_1 * 2) + 47) & 63;
  int stage_v_155_2 = ((pub_r001878_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001878_7_1 * 2) + 20) & 63;
  int stage_v_156_2 = ((pub_r001878_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001878_8_1 * 2) + 21) & 63;
  int stage_v_157_2 = ((pub_r001878_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001878_4_1 * 2) + 9) & 63;
  int stage_v_158_2 = ((pub_r001878_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (stage_v_56_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (stage_v_56_2 & 15)) & 63;
    if ((stage_v_56_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((stage_v_56_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_159_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_159_2) + 7) & 255;
    }
  }

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = ((pub_r001878_14_1 * 2) + 16) & 63;
  int stage_v_161_2 = ((pub_r001878_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_162_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_162_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_162_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_162_2) + 7) & 255;
    }
  }

  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_74_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_74_2 & 15)) & 63;
    if ((stage_v_74_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_74_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = ((pub_r001878_15_1 * 2) + 17) & 63;
  int stage_v_164_2 = ((pub_r001878_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001878_13_1 * 2) + 39) & 63;
  int stage_v_165_2 = ((pub_r001878_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (it_1 * 3)) + (stage_v_54_1 & 15)) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (it_2 * 3)) + (stage_v_54_2 & 15)) & 63;
    if ((stage_v_54_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_167_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_167_1) + 7) & 255;
    }
    if ((stage_v_54_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_167_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_167_2) + 7) & 255;
    }
  }

  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (stage_v_146_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (stage_v_146_2 & 15)) & 63;
    if ((stage_v_146_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((stage_v_146_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = ((pub_r001878_14_1 * 2) + 16) & 63;
  int stage_v_169_2 = ((pub_r001878_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (it_1 * 3)) + (stage_v_118_1 & 15)) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (it_2 * 3)) + (stage_v_118_2 & 15)) & 63;
    if ((stage_v_118_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_170_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_170_1) + 7) & 255;
    }
    if ((stage_v_118_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_170_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_170_2) + 7) & 255;
    }
  }

  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (it_1 * 3)) + (sec_r001878_3_1 & 15)) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (it_2 * 3)) + (sec_r001878_3_2 & 15)) & 63;
    if ((sec_r001878_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_171_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_171_1) + 7) & 255;
    }
    if ((sec_r001878_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_171_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_171_2) + 7) & 255;
    }
  }

  int stage_v_172_1 = ((pub_r001878_11_1 * 2) + 42) & 63;
  int stage_v_172_2 = ((pub_r001878_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_173_1 = ((stage_v_173_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_173_2 = ((stage_v_173_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_173_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_173_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_173_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_173_2) + 7) & 255;
    }
  }

  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_174_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_174_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_174_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_174_2) + 7) & 255;
    }
  }

  int stage_v_175_1 = ((pub_r001878_13_1 * 2) + 9) & 63;
  int stage_v_175_2 = ((pub_r001878_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (stage_v_85_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (stage_v_85_2 & 15)) & 63;
    if ((stage_v_85_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((stage_v_85_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_55_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_55_2 & 15)) & 63;
    if ((stage_v_55_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_55_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_178_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_178_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_178_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_178_2) + 7) & 255;
    }
  }

  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (stage_v_40_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (stage_v_40_2 & 15)) & 63;
    if ((stage_v_40_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((stage_v_40_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_179_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_179_2) + 7) & 255;
    }
  }

  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_180_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_180_2) + 7) & 255;
    }
  }

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_148_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_148_2 & 15)) & 63;
    if ((stage_v_148_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_148_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = ((pub_r001878_11_1 * 2) + 43) & 63;
  int stage_v_182_2 = ((pub_r001878_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = ((pub_r001878_0_1 * 2) + 42) & 63;
  int stage_v_184_2 = ((pub_r001878_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001878_19_1 * 2) + 13) & 63;
  int stage_v_185_2 = ((pub_r001878_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001878_21_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001878_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = ((pub_r001878_22_1 * 2) + 47) & 63;
  int stage_v_188_2 = ((pub_r001878_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001878_8_1 * 2) + 13) & 63;
  int stage_v_189_2 = ((pub_r001878_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = ((pub_r001878_1_1 * 2) + 45) & 63;
  int stage_v_191_2 = ((pub_r001878_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (stage_v_177_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (stage_v_177_2 & 15)) & 63;
    if ((stage_v_177_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((stage_v_177_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  int stage_v_194_1 = 0;
  int stage_v_194_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_194_1 = ((stage_v_194_1 + (it_1 * 3)) + (stage_v_131_1 & 15)) & 63;
    stage_v_194_2 = ((stage_v_194_2 + (it_2 * 3)) + (stage_v_131_2 & 15)) & 63;
    if ((stage_v_131_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_194_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_194_1) + 7) & 255;
    }
    if ((stage_v_131_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_194_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_194_2) + 7) & 255;
    }
  }

  int stage_v_195_1 = ((pub_r001878_3_1 * 2) + 18) & 63;
  int stage_v_195_2 = ((pub_r001878_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = 0;
  int stage_v_196_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_196_1 = ((stage_v_196_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_196_2 = ((stage_v_196_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_196_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_196_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_196_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_196_2) + 7) & 255;
    }
  }

  int stage_v_197_1 = 0;
  int stage_v_197_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_197_1 = ((stage_v_197_1 + (it_1 * 3)) + (stage_v_84_1 & 15)) & 63;
    stage_v_197_2 = ((stage_v_197_2 + (it_2 * 3)) + (stage_v_84_2 & 15)) & 63;
    if ((stage_v_84_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_197_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_197_1) + 7) & 255;
    }
    if ((stage_v_84_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_197_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_197_2) + 7) & 255;
    }
  }

  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (it_1 * 3)) + (stage_v_163_1 & 15)) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (it_2 * 3)) + (stage_v_163_2 & 15)) & 63;
    if ((stage_v_163_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_198_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_198_1) + 7) & 255;
    }
    if ((stage_v_163_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_198_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_198_2) + 7) & 255;
    }
  }

  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (it_1 * 3)) + (stage_v_72_1 & 15)) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (it_2 * 3)) + (stage_v_72_2 & 15)) & 63;
    if ((stage_v_72_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_199_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_199_1) + 7) & 255;
    }
    if ((stage_v_72_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_199_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_199_2) + 7) & 255;
    }
  }

  int stage_v_200_1 = 0;
  int stage_v_200_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_200_1 = ((stage_v_200_1 + (it_1 * 3)) + (stage_v_173_1 & 15)) & 63;
    stage_v_200_2 = ((stage_v_200_2 + (it_2 * 3)) + (stage_v_173_2 & 15)) & 63;
    if ((stage_v_173_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_200_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_200_1) + 7) & 255;
    }
    if ((stage_v_173_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_200_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_200_2) + 7) & 255;
    }
  }

  int stage_v_201_1 = ((pub_r001878_3_1 * 2) + 24) & 63;
  int stage_v_201_2 = ((pub_r001878_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001878_5_1 * 2) + 18) & 63;
  int stage_v_202_2 = ((pub_r001878_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001878_4_1 * 2) + 33) & 63;
  int stage_v_203_2 = ((pub_r001878_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_204_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_204_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_204_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_204_2) + 7) & 255;
    }
  }

  int stage_v_205_1 = 0;
  int stage_v_205_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_205_1 = ((stage_v_205_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_205_2 = ((stage_v_205_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_205_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_205_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_205_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_205_2) + 7) & 255;
    }
  }

  int stage_v_206_1 = 0;
  int stage_v_206_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_206_1 = ((stage_v_206_1 + (it_1 * 3)) + (stage_v_176_1 & 15)) & 63;
    stage_v_206_2 = ((stage_v_206_2 + (it_2 * 3)) + (stage_v_176_2 & 15)) & 63;
    if ((stage_v_176_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_206_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_206_1) + 7) & 255;
    }
    if ((stage_v_176_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_206_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_206_2) + 7) & 255;
    }
  }

  int stage_v_207_1 = ((pub_r001878_8_1 * 2) + 19) & 63;
  int stage_v_207_2 = ((pub_r001878_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001878_21_1 * 2) + 48) & 63;
  int stage_v_208_2 = ((pub_r001878_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001878_13_1 * 2) + 40) & 63;
  int stage_v_209_2 = ((pub_r001878_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = 0;
  int stage_v_210_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_210_1 = ((stage_v_210_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_210_2 = ((stage_v_210_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_210_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_210_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_210_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_210_2) + 7) & 255;
    }
  }

  int stage_v_211_1 = 0;
  int stage_v_211_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_211_1 = ((stage_v_211_1 + (it_1 * 3)) + (stage_v_200_1 & 15)) & 63;
    stage_v_211_2 = ((stage_v_211_2 + (it_2 * 3)) + (stage_v_200_2 & 15)) & 63;
    if ((stage_v_200_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_211_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_211_1) + 7) & 255;
    }
    if ((stage_v_200_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_211_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_211_2) + 7) & 255;
    }
  }

  int stage_v_212_1 = ((pub_r001878_10_1 * 2) + 20) & 63;
  int stage_v_212_2 = ((pub_r001878_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001878_11_1 * 2) + 34) & 63;
  int stage_v_213_2 = ((pub_r001878_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001878_21_1 * 2) + 15) & 63;
  int stage_v_214_2 = ((pub_r001878_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = 0;
  int stage_v_215_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_215_1 = ((stage_v_215_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_215_2 = ((stage_v_215_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_215_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_215_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_215_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_215_2) + 7) & 255;
    }
  }

  int stage_v_216_1 = 0;
  int stage_v_216_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_216_1 = ((stage_v_216_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_216_2 = ((stage_v_216_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_216_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_216_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_216_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_216_2) + 7) & 255;
    }
  }

  int stage_v_217_1 = 0;
  int stage_v_217_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_217_1 = ((stage_v_217_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_217_2 = ((stage_v_217_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_217_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_217_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_217_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_217_2) + 7) & 255;
    }
  }

  int stage_v_218_1 = ((pub_r001878_17_1 * 2) + 50) & 63;
  int stage_v_218_2 = ((pub_r001878_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001878_10_1 * 2) + 13) & 63;
  int stage_v_219_2 = ((pub_r001878_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = 0;
  int stage_v_220_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_220_1 = ((stage_v_220_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_220_2 = ((stage_v_220_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_220_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_220_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_220_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_220_2) + 7) & 255;
    }
  }

  int stage_v_221_1 = ((pub_r001878_0_1 * 2) + 12) & 63;
  int stage_v_221_2 = ((pub_r001878_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = 0;
  int stage_v_222_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_222_1 = ((stage_v_222_1 + (it_1 * 3)) + (sec_r001878_1_1 & 15)) & 63;
    stage_v_222_2 = ((stage_v_222_2 + (it_2 * 3)) + (sec_r001878_1_2 & 15)) & 63;
    if ((sec_r001878_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_222_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_222_1) + 7) & 255;
    }
    if ((sec_r001878_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_222_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_222_2) + 7) & 255;
    }
  }

  int stage_v_223_1 = 0;
  int stage_v_223_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_223_1 = ((stage_v_223_1 + (it_1 * 3)) + (sec_r001878_8_1 & 15)) & 63;
    stage_v_223_2 = ((stage_v_223_2 + (it_2 * 3)) + (sec_r001878_8_2 & 15)) & 63;
    if ((sec_r001878_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_223_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_223_1) + 7) & 255;
    }
    if ((sec_r001878_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_223_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_223_2) + 7) & 255;
    }
  }

  int stage_v_224_1 = ((pub_r001878_21_1 * 2) + 20) & 63;
  int stage_v_224_2 = ((pub_r001878_21_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001878_19_1 * 2) + 43) & 63;
  int stage_v_225_2 = ((pub_r001878_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001878_12_1 * 2) + 45) & 63;
  int stage_v_226_2 = ((pub_r001878_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = 0;
  int stage_v_227_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_227_1 = ((stage_v_227_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_227_2 = ((stage_v_227_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_227_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_227_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_227_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_227_2) + 7) & 255;
    }
  }

  int stage_v_228_1 = 0;
  int stage_v_228_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_228_1 = ((stage_v_228_1 + (it_1 * 3)) + (stage_v_145_1 & 15)) & 63;
    stage_v_228_2 = ((stage_v_228_2 + (it_2 * 3)) + (stage_v_145_2 & 15)) & 63;
    if ((stage_v_145_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_228_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_228_1) + 7) & 255;
    }
    if ((stage_v_145_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_228_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_228_2) + 7) & 255;
    }
  }

  int stage_v_229_1 = ((pub_r001878_4_1 * 2) + 14) & 63;
  int stage_v_229_2 = ((pub_r001878_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = 0;
  int stage_v_230_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_230_1 = ((stage_v_230_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_230_2 = ((stage_v_230_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_230_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_230_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_230_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_230_2) + 7) & 255;
    }
  }

  int stage_v_231_1 = ((pub_r001878_14_1 * 2) + 7) & 63;
  int stage_v_231_2 = ((pub_r001878_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = 0;
  int stage_v_232_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_232_1 = ((stage_v_232_1 + (it_1 * 3)) + (stage_v_128_1 & 15)) & 63;
    stage_v_232_2 = ((stage_v_232_2 + (it_2 * 3)) + (stage_v_128_2 & 15)) & 63;
    if ((stage_v_128_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_232_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_232_1) + 7) & 255;
    }
    if ((stage_v_128_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_232_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_232_2) + 7) & 255;
    }
  }

  int stage_v_233_1 = ((pub_r001878_13_1 * 2) + 21) & 63;
  int stage_v_233_2 = ((pub_r001878_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001878_4_1 * 2) + 46) & 63;
  int stage_v_234_2 = ((pub_r001878_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001878_15_1 * 2) + 21) & 63;
  int stage_v_235_2 = ((pub_r001878_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = 0;
  int stage_v_236_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_236_1 = ((stage_v_236_1 + (it_1 * 3)) + (stage_v_33_1 & 15)) & 63;
    stage_v_236_2 = ((stage_v_236_2 + (it_2 * 3)) + (stage_v_33_2 & 15)) & 63;
    if ((stage_v_33_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_236_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_236_1) + 7) & 255;
    }
    if ((stage_v_33_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_236_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_236_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001878_6_1 != sec_r001878_6_2);
  __CPROVER_assume(sec_r001878_17_1 != sec_r001878_17_2);
  __CPROVER_assume(pub_r001878_13_1 == pub_r001878_13_2);
  __CPROVER_assume(sec_r001878_21_1 != sec_r001878_21_2);
  __CPROVER_assume(pub_r001878_0_1 == pub_r001878_0_2);
  __CPROVER_assume(pub_r001878_9_1 == pub_r001878_9_2);
  __CPROVER_assume(sec_r001878_9_1 != sec_r001878_9_2);
  __CPROVER_assume(sec_r001878_10_1 != sec_r001878_10_2);
  __CPROVER_assume(pub_r001878_18_1 == pub_r001878_18_2);
  __CPROVER_assume(sec_r001878_4_1 != sec_r001878_4_2);
  __CPROVER_assume(pub_r001878_21_1 == pub_r001878_21_2);
  __CPROVER_assume(pub_r001878_5_1 == pub_r001878_5_2);
  __CPROVER_assume(sec_r001878_14_1 != sec_r001878_14_2);
  __CPROVER_assume(pub_r001878_4_1 == pub_r001878_4_2);
  __CPROVER_assume(sec_r001878_16_1 != sec_r001878_16_2);
  __CPROVER_assume(pub_r001878_1_1 == pub_r001878_1_2);
  __CPROVER_assume(sec_r001878_12_1 != sec_r001878_12_2);
  __CPROVER_assume(sec_r001878_13_1 != sec_r001878_13_2);
  __CPROVER_assume(sec_r001878_2_1 != sec_r001878_2_2);
  __CPROVER_assume(sec_r001878_7_1 != sec_r001878_7_2);
  __CPROVER_assume(pub_r001878_20_1 == pub_r001878_20_2);
  __CPROVER_assume(pub_r001878_19_1 == pub_r001878_19_2);
  __CPROVER_assume(pub_r001878_2_1 == pub_r001878_2_2);
  __CPROVER_assume(sec_r001878_5_1 != sec_r001878_5_2);
  __CPROVER_assume(sec_r001878_11_1 != sec_r001878_11_2);
  __CPROVER_assume(pub_r001878_11_1 == pub_r001878_11_2);
  __CPROVER_assume(pub_r001878_16_1 == pub_r001878_16_2);
  __CPROVER_assume(pub_r001878_6_1 == pub_r001878_6_2);
  __CPROVER_assume(sec_r001878_22_1 != sec_r001878_22_2);
  __CPROVER_assume(pub_r001878_7_1 == pub_r001878_7_2);
  __CPROVER_assume(pub_r001878_10_1 == pub_r001878_10_2);
  __CPROVER_assume(pub_r001878_17_1 == pub_r001878_17_2);
  __CPROVER_assume(sec_r001878_3_1 != sec_r001878_3_2);
  __CPROVER_assume(sec_r001878_18_1 != sec_r001878_18_2);
  __CPROVER_assume(sec_r001878_19_1 != sec_r001878_19_2);
  __CPROVER_assume(pub_r001878_3_1 == pub_r001878_3_2);
  __CPROVER_assume(sec_r001878_8_1 != sec_r001878_8_2);
  __CPROVER_assume(sec_r001878_15_1 != sec_r001878_15_2);
  __CPROVER_assume(pub_r001878_14_1 == pub_r001878_14_2);
  __CPROVER_assume(sec_r001878_1_1 != sec_r001878_1_2);
  __CPROVER_assume(pub_r001878_15_1 == pub_r001878_15_2);
  __CPROVER_assume(sec_r001878_20_1 != sec_r001878_20_2);
  __CPROVER_assume(pub_r001878_8_1 == pub_r001878_8_2);
  __CPROVER_assume(pub_r001878_12_1 == pub_r001878_12_2);
  __CPROVER_assume(pub_r001878_22_1 == pub_r001878_22_2);
  __CPROVER_assume(sec_r001878_0_1 != sec_r001878_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
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
}


