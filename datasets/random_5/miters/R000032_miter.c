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
struct CipherContext_R000032_3213_0
{
  short nonce;
  short round_key;
  int iv;
  int flags;
  short tag;
  int buffer[3];
};
struct DeviceConfig_R000032_3213_1
{
  int port;
  short id;
  int stop_bits;
  unsigned char parity;
  int buffer[3];
};
struct Vector3D_R000032_3213_2
{
  int coord_y;
  unsigned char coord_x;
  int pitch;
  int norm_sq;
  unsigned char coord_z;
  int buffer[3];
};
struct EventLog_R000032_3213_3
{
  unsigned char timestamp;
  int facility;
  unsigned char seq;
  unsigned char signature;
  unsigned char code;
  int buffer[3];
};
union PacketPayload_R000032_3213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000032_3213_1
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
void fn_R000032_3213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_20_1) & 63;
  aux_2 = (aux_2 + pivot_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_98_1)
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

  switch (margin_98_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_20_1 == pivot_20_2);
  assert(margin_98_1 == margin_98_2);
}

int fn_R000032_3213_0(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_20) & 63;
  acc ^= aux;
  int margin_98 = (aux + st.buffer[1]) & 3;
  switch (margin_98)
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

void fn_R000032_3213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st_1 = {0};
  struct EventLog_R000032_3213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_73_1)
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

  switch (cursor_73_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_73_1 == cursor_73_2);
}

int fn_R000032_3213_1(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_73 = (aux + st.buffer[1]) & 3;
  switch (cursor_73)
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

void fn_R000032_3213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st_1 = {0};
  struct EventLog_R000032_3213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_17_1) & 63;
  aux_2 = (aux_2 + quantum_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_46_1)
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

  switch (pivot_46_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_17_1 == quantum_17_2);
  assert(pivot_46_1 == pivot_46_2);
}

int fn_R000032_3213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_17) & 63;
  acc ^= aux;
  int pivot_46 = (aux + st.buffer[1]) & 3;
  switch (pivot_46)
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

void fn_R000032_3213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st_1 = {0};
  struct EventLog_R000032_3213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_53_1 = local_arr_1[aux_1 % 3];
  int segment_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_69_1) & 63;
  aux_2 = (aux_2 + stride_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_74_1 > 25)
  {
    acc_1 = ((acc_1 + (damping_74_1 * 2)) + 5) & 127;
    aux_1 ^= damping_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_74_2 > 25)
  {
    acc_2 = ((acc_2 + (damping_74_2 * 2)) + 5) & 127;
    aux_2 ^= damping_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_53_1 == segment_53_2);
  assert(stride_69_1 == stride_69_2);
  assert(damping_74_1 == damping_74_2);
}

int fn_R000032_3213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int segment_53 = local_arr[aux % 3];
  acc = (acc + (segment_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_69) & 63;
  acc ^= aux;
  int damping_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_74 > 25)
  {
    acc = ((acc + (damping_74 * 2)) + 5) & 127;
    aux ^= damping_74 & 15;
  }
  else
  {
    acc = ((acc - damping_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000032_3213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_95_1 > 25)
  {
    acc_1 = ((acc_1 + (phase_95_1 * 2)) + 5) & 127;
    aux_1 ^= phase_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_95_2 > 25)
  {
    acc_2 = ((acc_2 + (phase_95_2 * 2)) + 5) & 127;
    aux_2 ^= phase_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
}

int fn_R000032_3213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_95 > 25)
  {
    acc = ((acc + (phase_95 * 2)) + 5) & 127;
    aux ^= phase_95 & 15;
  }
  else
  {
    acc = ((acc - phase_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000032_3213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_18_1 > 18)
  {
    acc_1 = ((acc_1 + (factor_18_1 * 2)) + 5) & 127;
    aux_1 ^= factor_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_18_2 > 18)
  {
    acc_2 = ((acc_2 + (factor_18_2 * 2)) + 5) & 127;
    aux_2 ^= factor_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_18_1 == factor_18_2);
}

int fn_R000032_3213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_18 > 18)
  {
    acc = ((acc + (factor_18 * 2)) + 5) & 127;
    aux ^= factor_18 & 15;
  }
  else
  {
    acc = ((acc - factor_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000032_3213_1 st_1 = {0};
  struct DeviceConfig_R000032_3213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_23_1 = local_arr_1[aux_1 % 3];
  int threshold_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_23_2 * 2)) & 127;
  int delta_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_73_1 > 21)
  {
    acc_1 = ((acc_1 + (delta_73_1 * 2)) + 5) & 127;
    aux_1 ^= delta_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_73_2 > 21)
  {
    acc_2 = ((acc_2 + (delta_73_2 * 2)) + 5) & 127;
    aux_2 ^= delta_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_93_1) & 63;
  aux_2 = (aux_2 + mask_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_23_1 == threshold_23_2);
  assert(delta_73_1 == delta_73_2);
  assert(mask_93_1 == mask_93_2);
}

int fn_R000032_3213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000032_3213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int threshold_23 = local_arr[aux % 3];
  acc = (acc + (threshold_23 * 2)) & 127;
  int delta_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_73 > 21)
  {
    acc = ((acc + (delta_73 * 2)) + 5) & 127;
    aux ^= delta_73 & 15;
  }
  else
  {
    acc = ((acc - delta_73) + 11) & 127;
    aux += 3;
  }
  int mask_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_93) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st_1 = {0};
  struct CipherContext_R000032_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_93_1)
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

  switch (segment_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_93_1 == segment_93_2);
}

int fn_R000032_3213_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_93 = (aux + st.buffer[1]) & 3;
  switch (segment_93)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_33_1) & 63;
  aux_2 = (aux_2 + margin_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_24_1 > 30)
  {
    acc_1 = ((acc_1 + (metric_24_1 * 2)) + 5) & 127;
    aux_1 ^= metric_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_24_2 > 30)
  {
    acc_2 = ((acc_2 + (metric_24_2 * 2)) + 5) & 127;
    aux_2 ^= metric_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_33_1 == margin_33_2);
  assert(metric_24_1 == metric_24_2);
}

int fn_R000032_3213_8(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_33) & 63;
  acc ^= aux;
  int metric_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_24 > 30)
  {
    acc = ((acc + (metric_24 * 2)) + 5) & 127;
    aux ^= metric_24 & 15;
  }
  else
  {
    acc = ((acc - metric_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000032_3213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st_1 = {0};
  struct CipherContext_R000032_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_78_1) & 63;
  aux_2 = (aux_2 + parity_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_20_1 = local_arr_1[aux_1 % 3];
  int segment_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_20_1 == segment_20_2);
}

int fn_R000032_3213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_78) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_20 = local_arr[aux % 3];
  acc = (acc + (segment_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st_1 = {0};
  struct CipherContext_R000032_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_91_1) & 63;
  aux_2 = (aux_2 + quotient_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_58_1)
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

  switch (factor_58_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_91_1 == quotient_91_2);
  assert(factor_58_1 == factor_58_2);
}

int fn_R000032_3213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_91) & 63;
  acc ^= aux;
  int factor_58 = (aux + st.buffer[1]) & 3;
  switch (factor_58)
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

void fn_R000032_3213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000032_3213_1 st_1 = {0};
  struct DeviceConfig_R000032_3213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int segment_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_66_1 > 14)
  {
    acc_1 = ((acc_1 + (segment_66_1 * 2)) + 5) & 127;
    aux_1 ^= segment_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_66_2 > 14)
  {
    acc_2 = ((acc_2 + (segment_66_2 * 2)) + 5) & 127;
    aux_2 ^= segment_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_94_1) & 63;
  aux_2 = (aux_2 + factor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_66_1 == segment_66_2);
  assert(factor_94_1 == factor_94_2);
}

int fn_R000032_3213_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000032_3213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int segment_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_66 > 14)
  {
    acc = ((acc + (segment_66 * 2)) + 5) & 127;
    aux ^= segment_66 & 15;
  }
  else
  {
    acc = ((acc - segment_66) + 11) & 127;
    aux += 3;
  }
  int factor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st_1 = {0};
  struct CipherContext_R000032_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_57_1 = local_arr_1[aux_1 % 3];
  int window_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_57_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_20_1 > 20)
  {
    acc_1 = ((acc_1 + (cursor_20_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_20_2 > 20)
  {
    acc_2 = ((acc_2 + (cursor_20_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_96_1) & 63;
  aux_2 = (aux_2 + cursor_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
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

  assert(window_57_1 == window_57_2);
  assert(cursor_20_1 == cursor_20_2);
  assert(cursor_96_1 == cursor_96_2);
}

int fn_R000032_3213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int window_57 = local_arr[aux % 3];
  acc = (acc + (window_57 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_20 > 20)
  {
    acc = ((acc + (cursor_20 * 2)) + 5) & 127;
    aux ^= cursor_20 & 15;
  }
  else
  {
    acc = ((acc - cursor_20) + 11) & 127;
    aux += 3;
  }
  int cursor_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000032_3213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int mask_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_58_1)
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

  switch (mask_58_2)
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
  int phase_51_1 = local_arr_1[aux_1 % 3];
  int phase_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_51_2 * 2)) & 127;
  int segment_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_86_1) & 63;
  aux_2 = (aux_2 + segment_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_58_1 == mask_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_51_1 == phase_51_2);
  assert(segment_86_1 == segment_86_2);
}

int fn_R000032_3213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int mask_58 = (aux + st.buffer[1]) & 3;
  switch (mask_58)
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
  int phase_51 = local_arr[aux % 3];
  acc = (acc + (phase_51 * 2)) & 127;
  int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tracker_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_89_1)
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

  switch (tracker_89_2)
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
  int scale_94_1 = local_arr_1[aux_1 % 3];
  int scale_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_94_2 * 2)) & 127;
  int window_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_30_1 > 44)
  {
    acc_1 = ((acc_1 + (window_30_1 * 2)) + 5) & 127;
    aux_1 ^= window_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_30_2 > 44)
  {
    acc_2 = ((acc_2 + (window_30_2 * 2)) + 5) & 127;
    aux_2 ^= window_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_21_1) & 63;
  aux_2 = (aux_2 + mask_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_89_1 == tracker_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_94_1 == scale_94_2);
  assert(window_30_1 == window_30_2);
  assert(mask_21_1 == mask_21_2);
}

int fn_R000032_3213_14(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tracker_89 = (aux + st.buffer[1]) & 3;
  switch (tracker_89)
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
  int scale_94 = local_arr[aux % 3];
  acc = (acc + (scale_94 * 2)) & 127;
  int window_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_30 > 44)
  {
    acc = ((acc + (window_30 * 2)) + 5) & 127;
    aux ^= window_30 & 15;
  }
  else
  {
    acc = ((acc - window_30) + 11) & 127;
    aux += 3;
  }
  int mask_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000032_3213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_14_1)
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

  switch (mask_14_2)
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

  int bound_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_15_1) & 63;
  aux_2 = (aux_2 + bound_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_14_1 == mask_14_2);
  assert(bound_15_1 == bound_15_2);
}

int fn_R000032_3213_15(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_14 = (aux + st.buffer[1]) & 3;
  switch (mask_14)
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

  int bound_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000032_3213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st_1 = {0};
  struct CipherContext_R000032_3213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_85_1 > 13)
  {
    acc_1 = ((acc_1 + (sample_85_1 * 2)) + 5) & 127;
    aux_1 ^= sample_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_85_2 > 13)
  {
    acc_2 = ((acc_2 + (sample_85_2 * 2)) + 5) & 127;
    aux_2 ^= sample_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_85_1 == sample_85_2);
}

int fn_R000032_3213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000032_3213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_85 > 13)
  {
    acc = ((acc + (sample_85 * 2)) + 5) & 127;
    aux ^= sample_85 & 15;
  }
  else
  {
    acc = ((acc - sample_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st_1 = {0};
  struct Vector3D_R000032_3213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_69_1) & 63;
  aux_2 = (aux_2 + damping_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_59_1 = local_arr_1[aux_1 % 3];
  int weight_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_69_1 == damping_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_59_1 == weight_59_2);
}

int fn_R000032_3213_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000032_3213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_59 = local_arr[aux % 3];
  acc = (acc + (weight_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000032_3213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st_1 = {0};
  struct EventLog_R000032_3213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_74_1 > 13)
  {
    acc_1 = ((acc_1 + (threshold_74_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_74_2 > 13)
  {
    acc_2 = ((acc_2 + (threshold_74_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_13_1)
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

  switch (phase_13_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_74_1 == threshold_74_2);
  assert(phase_13_1 == phase_13_2);
}

int fn_R000032_3213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000032_3213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_74 > 13)
  {
    acc = ((acc + (threshold_74 * 2)) + 5) & 127;
    aux ^= threshold_74 & 15;
  }
  else
  {
    acc = ((acc - threshold_74) + 11) & 127;
    aux += 3;
  }
  int phase_13 = (aux + st.buffer[1]) & 3;
  switch (phase_13)
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

void main()
{
  int sec_r000032_0_1;
  int sec_r000032_0_2;
  int sec_r000032_1_1;
  int sec_r000032_1_2;
  int sec_r000032_2_1;
  int sec_r000032_2_2;
  int sec_r000032_3_1;
  int sec_r000032_3_2;
  int sec_r000032_4_1;
  int sec_r000032_4_2;
  int sec_r000032_5_1;
  int sec_r000032_5_2;
  int sec_r000032_6_1;
  int sec_r000032_6_2;
  int sec_r000032_7_1;
  int sec_r000032_7_2;
  int sec_r000032_8_1;
  int sec_r000032_8_2;
  int sec_r000032_9_1;
  int sec_r000032_9_2;
  int sec_r000032_10_1;
  int sec_r000032_10_2;
  int sec_r000032_11_1;
  int sec_r000032_11_2;
  int sec_r000032_12_1;
  int sec_r000032_12_2;
  int sec_r000032_13_1;
  int sec_r000032_13_2;
  int sec_r000032_14_1;
  int sec_r000032_14_2;
  int sec_r000032_15_1;
  int sec_r000032_15_2;
  int sec_r000032_16_1;
  int sec_r000032_16_2;
  int sec_r000032_17_1;
  int sec_r000032_17_2;
  int sec_r000032_18_1;
  int sec_r000032_18_2;
  int pub_r000032_0_1;
  int pub_r000032_0_2;
  int pub_r000032_1_1;
  int pub_r000032_1_2;
  int pub_r000032_2_1;
  int pub_r000032_2_2;
  int pub_r000032_3_1;
  int pub_r000032_3_2;
  int pub_r000032_4_1;
  int pub_r000032_4_2;
  int pub_r000032_5_1;
  int pub_r000032_5_2;
  int pub_r000032_6_1;
  int pub_r000032_6_2;
  int pub_r000032_7_1;
  int pub_r000032_7_2;
  int pub_r000032_8_1;
  int pub_r000032_8_2;
  int pub_r000032_9_1;
  int pub_r000032_9_2;
  int pub_r000032_10_1;
  int pub_r000032_10_2;
  int pub_r000032_11_1;
  int pub_r000032_11_2;
  int pub_r000032_12_1;
  int pub_r000032_12_2;
  int pub_r000032_13_1;
  int pub_r000032_13_2;
  int pub_r000032_14_1;
  int pub_r000032_14_2;
  int pub_r000032_15_1;
  int pub_r000032_15_2;
  int pub_r000032_16_1;
  int pub_r000032_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000032_0_1 >= (-100)) && (pub_r000032_0_1 <= 100));
  __CPROVER_assume((pub_r000032_0_2 >= (-100)) && (pub_r000032_0_2 <= 100));
  __CPROVER_assume((pub_r000032_1_1 >= (-100)) && (pub_r000032_1_1 <= 100));
  __CPROVER_assume((pub_r000032_1_2 >= (-100)) && (pub_r000032_1_2 <= 100));
  __CPROVER_assume((pub_r000032_2_1 >= (-100)) && (pub_r000032_2_1 <= 100));
  __CPROVER_assume((pub_r000032_2_2 >= (-100)) && (pub_r000032_2_2 <= 100));
  __CPROVER_assume((pub_r000032_3_1 >= (-100)) && (pub_r000032_3_1 <= 100));
  __CPROVER_assume((pub_r000032_3_2 >= (-100)) && (pub_r000032_3_2 <= 100));
  __CPROVER_assume((pub_r000032_4_1 >= (-100)) && (pub_r000032_4_1 <= 100));
  __CPROVER_assume((pub_r000032_4_2 >= (-100)) && (pub_r000032_4_2 <= 100));
  __CPROVER_assume((pub_r000032_5_1 >= (-100)) && (pub_r000032_5_1 <= 100));
  __CPROVER_assume((pub_r000032_5_2 >= (-100)) && (pub_r000032_5_2 <= 100));
  __CPROVER_assume((pub_r000032_6_1 >= (-100)) && (pub_r000032_6_1 <= 100));
  __CPROVER_assume((pub_r000032_6_2 >= (-100)) && (pub_r000032_6_2 <= 100));
  __CPROVER_assume((pub_r000032_7_1 >= (-100)) && (pub_r000032_7_1 <= 100));
  __CPROVER_assume((pub_r000032_7_2 >= (-100)) && (pub_r000032_7_2 <= 100));
  __CPROVER_assume((pub_r000032_8_1 >= (-100)) && (pub_r000032_8_1 <= 100));
  __CPROVER_assume((pub_r000032_8_2 >= (-100)) && (pub_r000032_8_2 <= 100));
  __CPROVER_assume((pub_r000032_9_1 >= (-100)) && (pub_r000032_9_1 <= 100));
  __CPROVER_assume((pub_r000032_9_2 >= (-100)) && (pub_r000032_9_2 <= 100));
  __CPROVER_assume((pub_r000032_10_1 >= (-100)) && (pub_r000032_10_1 <= 100));
  __CPROVER_assume((pub_r000032_10_2 >= (-100)) && (pub_r000032_10_2 <= 100));
  __CPROVER_assume((pub_r000032_11_1 >= (-100)) && (pub_r000032_11_1 <= 100));
  __CPROVER_assume((pub_r000032_11_2 >= (-100)) && (pub_r000032_11_2 <= 100));
  __CPROVER_assume((pub_r000032_12_1 >= (-100)) && (pub_r000032_12_1 <= 100));
  __CPROVER_assume((pub_r000032_12_2 >= (-100)) && (pub_r000032_12_2 <= 100));
  __CPROVER_assume((pub_r000032_13_1 >= (-100)) && (pub_r000032_13_1 <= 100));
  __CPROVER_assume((pub_r000032_13_2 >= (-100)) && (pub_r000032_13_2 <= 100));
  __CPROVER_assume((pub_r000032_14_1 >= (-100)) && (pub_r000032_14_1 <= 100));
  __CPROVER_assume((pub_r000032_14_2 >= (-100)) && (pub_r000032_14_2 <= 100));
  __CPROVER_assume((pub_r000032_15_1 >= (-100)) && (pub_r000032_15_1 <= 100));
  __CPROVER_assume((pub_r000032_15_2 >= (-100)) && (pub_r000032_15_2 <= 100));
  __CPROVER_assume((pub_r000032_16_1 >= (-100)) && (pub_r000032_16_1 <= 100));
  __CPROVER_assume((pub_r000032_16_2 >= (-100)) && (pub_r000032_16_2 <= 100));
  __CPROVER_assume((sec_r000032_0_1 >= 0) && (sec_r000032_0_1 <= 255));
  __CPROVER_assume((sec_r000032_0_2 >= 0) && (sec_r000032_0_2 <= 255));
  __CPROVER_assume((sec_r000032_1_1 >= 0) && (sec_r000032_1_1 <= 255));
  __CPROVER_assume((sec_r000032_1_2 >= 0) && (sec_r000032_1_2 <= 255));
  __CPROVER_assume((sec_r000032_2_1 >= 0) && (sec_r000032_2_1 <= 255));
  __CPROVER_assume((sec_r000032_2_2 >= 0) && (sec_r000032_2_2 <= 255));
  __CPROVER_assume((sec_r000032_3_1 >= 0) && (sec_r000032_3_1 <= 255));
  __CPROVER_assume((sec_r000032_3_2 >= 0) && (sec_r000032_3_2 <= 255));
  __CPROVER_assume((sec_r000032_4_1 >= 0) && (sec_r000032_4_1 <= 255));
  __CPROVER_assume((sec_r000032_4_2 >= 0) && (sec_r000032_4_2 <= 255));
  __CPROVER_assume((sec_r000032_5_1 >= 0) && (sec_r000032_5_1 <= 255));
  __CPROVER_assume((sec_r000032_5_2 >= 0) && (sec_r000032_5_2 <= 255));
  __CPROVER_assume((sec_r000032_6_1 >= 0) && (sec_r000032_6_1 <= 255));
  __CPROVER_assume((sec_r000032_6_2 >= 0) && (sec_r000032_6_2 <= 255));
  __CPROVER_assume((sec_r000032_7_1 >= 0) && (sec_r000032_7_1 <= 255));
  __CPROVER_assume((sec_r000032_7_2 >= 0) && (sec_r000032_7_2 <= 255));
  __CPROVER_assume((sec_r000032_8_1 >= 0) && (sec_r000032_8_1 <= 255));
  __CPROVER_assume((sec_r000032_8_2 >= 0) && (sec_r000032_8_2 <= 255));
  __CPROVER_assume((sec_r000032_9_1 >= 0) && (sec_r000032_9_1 <= 255));
  __CPROVER_assume((sec_r000032_9_2 >= 0) && (sec_r000032_9_2 <= 255));
  __CPROVER_assume((sec_r000032_10_1 >= 0) && (sec_r000032_10_1 <= 255));
  __CPROVER_assume((sec_r000032_10_2 >= 0) && (sec_r000032_10_2 <= 255));
  __CPROVER_assume((sec_r000032_11_1 >= 0) && (sec_r000032_11_1 <= 255));
  __CPROVER_assume((sec_r000032_11_2 >= 0) && (sec_r000032_11_2 <= 255));
  __CPROVER_assume((sec_r000032_12_1 >= 0) && (sec_r000032_12_1 <= 255));
  __CPROVER_assume((sec_r000032_12_2 >= 0) && (sec_r000032_12_2 <= 255));
  __CPROVER_assume((sec_r000032_13_1 >= 0) && (sec_r000032_13_1 <= 255));
  __CPROVER_assume((sec_r000032_13_2 >= 0) && (sec_r000032_13_2 <= 255));
  __CPROVER_assume((sec_r000032_14_1 >= 0) && (sec_r000032_14_1 <= 255));
  __CPROVER_assume((sec_r000032_14_2 >= 0) && (sec_r000032_14_2 <= 255));
  __CPROVER_assume((sec_r000032_15_1 >= 0) && (sec_r000032_15_1 <= 255));
  __CPROVER_assume((sec_r000032_15_2 >= 0) && (sec_r000032_15_2 <= 255));
  __CPROVER_assume((sec_r000032_16_1 >= 0) && (sec_r000032_16_1 <= 255));
  __CPROVER_assume((sec_r000032_16_2 >= 0) && (sec_r000032_16_2 <= 255));
  __CPROVER_assume((sec_r000032_17_1 >= 0) && (sec_r000032_17_1 <= 255));
  __CPROVER_assume((sec_r000032_17_2 >= 0) && (sec_r000032_17_2 <= 255));
  __CPROVER_assume((sec_r000032_18_1 >= 0) && (sec_r000032_18_1 <= 255));
  __CPROVER_assume((sec_r000032_18_2 >= 0) && (sec_r000032_18_2 <= 255));
  struct CipherContext_R000032_3213_0 st_var_0_1 = {0};
  struct CipherContext_R000032_3213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000032_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000032_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000032_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000032_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000032_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000032_0_2 + 7) & 15;
  struct DeviceConfig_R000032_3213_1 st_var_1_1 = {0};
  struct DeviceConfig_R000032_3213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000032_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000032_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000032_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000032_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000032_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000032_0_2 + 9) & 15;
  struct Vector3D_R000032_3213_2 st_var_2_1 = {0};
  struct Vector3D_R000032_3213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000032_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000032_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000032_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000032_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000032_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000032_0_2 + 11) & 15;
  struct EventLog_R000032_3213_3 st_var_3_1 = {0};
  struct EventLog_R000032_3213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000032_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000032_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000032_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000032_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000032_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000032_0_2 + 13) & 15;
  union PacketPayload_R000032_3213_0 u_var_1;
  union PacketPayload_R000032_3213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 52)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 52)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 44)
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
  if (stage_v_9_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 44)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 31)
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
  if (stage_v_12_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 31)
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
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
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
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 35)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 35)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
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
  int stage_v_25_1 = ((sec_r000032_3_1 + pub_r000032_4_1) + 41) & 127;
  int stage_v_25_2 = ((sec_r000032_3_2 + pub_r000032_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((stage_v_25_1 + pub_r000032_10_1) + 5) & 127;
  int stage_v_26_2 = ((stage_v_25_2 + pub_r000032_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((sec_r000032_4_1 + pub_r000032_4_1) + 23) & 127;
  int stage_v_27_2 = ((sec_r000032_4_2 + pub_r000032_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((stage_v_26_1 + pub_r000032_3_1) + 42) & 127;
  int stage_v_28_2 = ((stage_v_26_2 + pub_r000032_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((stage_v_27_1 + pub_r000032_6_1) + 19) & 127;
  int stage_v_29_2 = ((stage_v_27_2 + pub_r000032_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_26_1 + pub_r000032_5_1) + 11) & 127;
  int stage_v_30_2 = ((stage_v_26_2 + pub_r000032_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((stage_v_29_1 + pub_r000032_0_1) + 47) & 127;
  int stage_v_31_2 = ((stage_v_29_2 + pub_r000032_0_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((sec_r000032_18_1 + pub_r000032_11_1) + 19) & 127;
  int stage_v_32_2 = ((sec_r000032_18_2 + pub_r000032_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((sec_r000032_17_1 + pub_r000032_15_1) + 22) & 127;
  int stage_v_33_2 = ((sec_r000032_17_2 + pub_r000032_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((stage_v_29_1 + pub_r000032_11_1) + 25) & 127;
  int stage_v_34_2 = ((stage_v_29_2 + pub_r000032_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((stage_v_33_1 + pub_r000032_2_1) + 48) & 127;
  int stage_v_35_2 = ((stage_v_33_2 + pub_r000032_2_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((stage_v_32_1 + pub_r000032_2_1) + 28) & 127;
  int stage_v_36_2 = ((stage_v_32_2 + pub_r000032_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((stage_v_31_1 + pub_r000032_1_1) + 36) & 127;
  int stage_v_37_2 = ((stage_v_31_2 + pub_r000032_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((sec_r000032_16_1 + pub_r000032_16_1) + 23) & 127;
  int stage_v_38_2 = ((sec_r000032_16_2 + pub_r000032_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((stage_v_34_1 + pub_r000032_3_1) + 43) & 127;
  int stage_v_39_2 = ((stage_v_34_2 + pub_r000032_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((stage_v_35_1 + pub_r000032_5_1) + 20) & 127;
  int stage_v_40_2 = ((stage_v_35_2 + pub_r000032_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_31_1 + pub_r000032_13_1) + 3) & 127;
  int stage_v_41_2 = ((stage_v_31_2 + pub_r000032_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((sec_r000032_7_1 + pub_r000032_15_1) + 19) & 127;
  int stage_v_42_2 = ((sec_r000032_7_2 + pub_r000032_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((sec_r000032_17_1 + pub_r000032_12_1) + 41) & 127;
  int stage_v_43_2 = ((sec_r000032_17_2 + pub_r000032_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((stage_v_41_1 + pub_r000032_13_1) + 49) & 127;
  int stage_v_44_2 = ((stage_v_41_2 + pub_r000032_13_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((stage_v_37_1 + pub_r000032_13_1) + 44) & 127;
  int stage_v_45_2 = ((stage_v_37_2 + pub_r000032_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_26_1 + pub_r000032_1_1) + 17) & 127;
  int stage_v_46_2 = ((stage_v_26_2 + pub_r000032_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((stage_v_42_1 + pub_r000032_10_1) + 16) & 127;
  int stage_v_47_2 = ((stage_v_42_2 + pub_r000032_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((sec_r000032_0_1 + pub_r000032_16_1) + 36) & 127;
  int stage_v_48_2 = ((sec_r000032_0_2 + pub_r000032_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((sec_r000032_16_1 + pub_r000032_12_1) + 4) & 127;
  int stage_v_49_2 = ((sec_r000032_16_2 + pub_r000032_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((sec_r000032_5_1 + pub_r000032_1_1) + 23) & 127;
  int stage_v_50_2 = ((sec_r000032_5_2 + pub_r000032_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_30_1 + pub_r000032_13_1) + 13) & 127;
  int stage_v_51_2 = ((stage_v_30_2 + pub_r000032_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((sec_r000032_6_1 + pub_r000032_12_1) + 10) & 127;
  int stage_v_52_2 = ((sec_r000032_6_2 + pub_r000032_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_36_1 + pub_r000032_16_1) + 38) & 127;
  int stage_v_53_2 = ((stage_v_36_2 + pub_r000032_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_48_1 + pub_r000032_4_1) + 34) & 127;
  int stage_v_54_2 = ((stage_v_48_2 + pub_r000032_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_31_1 + pub_r000032_9_1) + 41) & 127;
  int stage_v_55_2 = ((stage_v_31_2 + pub_r000032_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((stage_v_31_1 + pub_r000032_16_1) + 35) & 127;
  int stage_v_56_2 = ((stage_v_31_2 + pub_r000032_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((sec_r000032_17_1 + pub_r000032_2_1) + 17) & 127;
  int stage_v_57_2 = ((sec_r000032_17_2 + pub_r000032_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_29_1 + pub_r000032_6_1) + 37) & 127;
  int stage_v_58_2 = ((stage_v_29_2 + pub_r000032_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((sec_r000032_14_1 + pub_r000032_4_1) + 23) & 127;
  int stage_v_59_2 = ((sec_r000032_14_2 + pub_r000032_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_31_1 + pub_r000032_16_1) + 33) & 127;
  int stage_v_60_2 = ((stage_v_31_2 + pub_r000032_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((sec_r000032_12_1 + pub_r000032_3_1) + 41) & 127;
  int stage_v_61_2 = ((sec_r000032_12_2 + pub_r000032_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((sec_r000032_15_1 + pub_r000032_15_1) + 7) & 127;
  int stage_v_62_2 = ((sec_r000032_15_2 + pub_r000032_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((stage_v_41_1 + pub_r000032_8_1) + 32) & 127;
  int stage_v_63_2 = ((stage_v_41_2 + pub_r000032_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((sec_r000032_9_1 + pub_r000032_4_1) + 5) & 127;
  int stage_v_64_2 = ((sec_r000032_9_2 + pub_r000032_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_50_1 + pub_r000032_9_1) + 11) & 127;
  int stage_v_65_2 = ((stage_v_50_2 + pub_r000032_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_61_1 + pub_r000032_12_1) + 35) & 127;
  int stage_v_66_2 = ((stage_v_61_2 + pub_r000032_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((sec_r000032_18_1 + pub_r000032_16_1) + 40) & 127;
  int stage_v_67_2 = ((sec_r000032_18_2 + pub_r000032_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000032_5_1 + pub_r000032_15_1) + 39) & 127;
  int stage_v_68_2 = ((sec_r000032_5_2 + pub_r000032_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((stage_v_47_1 + pub_r000032_5_1) + 37) & 127;
  int stage_v_69_2 = ((stage_v_47_2 + pub_r000032_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_65_1 + pub_r000032_6_1) + 23) & 127;
  int stage_v_70_2 = ((stage_v_65_2 + pub_r000032_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_47_1 + pub_r000032_0_1) + 49) & 127;
  int stage_v_71_2 = ((stage_v_47_2 + pub_r000032_0_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_47_1 + pub_r000032_10_1) + 25) & 127;
  int stage_v_72_2 = ((stage_v_47_2 + pub_r000032_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((stage_v_32_1 + pub_r000032_2_1) + 45) & 127;
  int stage_v_73_2 = ((stage_v_32_2 + pub_r000032_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_70_1 + pub_r000032_12_1) + 24) & 127;
  int stage_v_74_2 = ((stage_v_70_2 + pub_r000032_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000032_10_1 + pub_r000032_4_1) + 13) & 127;
  int stage_v_75_2 = ((sec_r000032_10_2 + pub_r000032_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((sec_r000032_5_1 + pub_r000032_16_1) + 39) & 127;
  int stage_v_76_2 = ((sec_r000032_5_2 + pub_r000032_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((sec_r000032_1_1 + pub_r000032_16_1) + 14) & 127;
  int stage_v_77_2 = ((sec_r000032_1_2 + pub_r000032_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((stage_v_48_1 + pub_r000032_7_1) + 3) & 127;
  int stage_v_78_2 = ((stage_v_48_2 + pub_r000032_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_42_1 + pub_r000032_13_1) + 30) & 127;
  int stage_v_79_2 = ((stage_v_42_2 + pub_r000032_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_53_1 + pub_r000032_12_1) + 37) & 127;
  int stage_v_80_2 = ((stage_v_53_2 + pub_r000032_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((sec_r000032_14_1 + pub_r000032_14_1) + 3) & 127;
  int stage_v_81_2 = ((sec_r000032_14_2 + pub_r000032_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((stage_v_74_1 + pub_r000032_13_1) + 39) & 127;
  int stage_v_82_2 = ((stage_v_74_2 + pub_r000032_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((sec_r000032_11_1 + pub_r000032_0_1) + 17) & 127;
  int stage_v_83_2 = ((sec_r000032_11_2 + pub_r000032_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_39_1 + pub_r000032_12_1) + 27) & 127;
  int stage_v_84_2 = ((stage_v_39_2 + pub_r000032_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_78_1 + pub_r000032_10_1) + 17) & 127;
  int stage_v_85_2 = ((stage_v_78_2 + pub_r000032_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_28_1 + pub_r000032_12_1) + 42) & 127;
  int stage_v_86_2 = ((stage_v_28_2 + pub_r000032_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((sec_r000032_18_1 + pub_r000032_13_1) + 24) & 127;
  int stage_v_87_2 = ((sec_r000032_18_2 + pub_r000032_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_37_1 + pub_r000032_14_1) + 45) & 127;
  int stage_v_88_2 = ((stage_v_37_2 + pub_r000032_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_57_1 + pub_r000032_3_1) + 12) & 127;
  int stage_v_89_2 = ((stage_v_57_2 + pub_r000032_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_77_1 + pub_r000032_13_1) + 8) & 127;
  int stage_v_90_2 = ((stage_v_77_2 + pub_r000032_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_89_1 + pub_r000032_0_1) + 20) & 127;
  int stage_v_91_2 = ((stage_v_89_2 + pub_r000032_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_69_1 + pub_r000032_10_1) + 34) & 127;
  int stage_v_92_2 = ((stage_v_69_2 + pub_r000032_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_40_1 + pub_r000032_1_1) + 14) & 127;
  int stage_v_93_2 = ((stage_v_40_2 + pub_r000032_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((stage_v_90_1 + pub_r000032_14_1) + 27) & 127;
  int stage_v_94_2 = ((stage_v_90_2 + pub_r000032_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_61_1 + pub_r000032_8_1) + 6) & 127;
  int stage_v_95_2 = ((stage_v_61_2 + pub_r000032_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000032_12_1 + pub_r000032_5_1) + 48) & 127;
  int stage_v_96_2 = ((sec_r000032_12_2 + pub_r000032_5_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_85_1 + pub_r000032_7_1) + 10) & 127;
  int stage_v_97_2 = ((stage_v_85_2 + pub_r000032_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000032_13_1 + pub_r000032_9_1) + 23) & 127;
  int stage_v_98_2 = ((sec_r000032_13_2 + pub_r000032_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((sec_r000032_14_1 + pub_r000032_16_1) + 11) & 127;
  int stage_v_99_2 = ((sec_r000032_14_2 + pub_r000032_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_71_1 + pub_r000032_1_1) + 16) & 127;
  int stage_v_100_2 = ((stage_v_71_2 + pub_r000032_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_46_1 + pub_r000032_4_1) + 26) & 127;
  int stage_v_101_2 = ((stage_v_46_2 + pub_r000032_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_72_1 + pub_r000032_13_1) + 35) & 127;
  int stage_v_102_2 = ((stage_v_72_2 + pub_r000032_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_47_1 + pub_r000032_5_1) + 30) & 127;
  int stage_v_103_2 = ((stage_v_47_2 + pub_r000032_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_79_1 + pub_r000032_16_1) + 10) & 127;
  int stage_v_104_2 = ((stage_v_79_2 + pub_r000032_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_77_1 + pub_r000032_16_1) + 13) & 127;
  int stage_v_105_2 = ((stage_v_77_2 + pub_r000032_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_83_1 + pub_r000032_4_1) + 6) & 127;
  int stage_v_106_2 = ((stage_v_83_2 + pub_r000032_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_50_1 + pub_r000032_10_1) + 22) & 127;
  int stage_v_107_2 = ((stage_v_50_2 + pub_r000032_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_36_1 + pub_r000032_12_1) + 31) & 127;
  int stage_v_108_2 = ((stage_v_36_2 + pub_r000032_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000032_0_1 + pub_r000032_11_1) + 19) & 127;
  int stage_v_109_2 = ((sec_r000032_0_2 + pub_r000032_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_79_1 + pub_r000032_14_1) + 7) & 127;
  int stage_v_110_2 = ((stage_v_79_2 + pub_r000032_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_28_1 + pub_r000032_14_1) + 33) & 127;
  int stage_v_111_2 = ((stage_v_28_2 + pub_r000032_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_93_1 + pub_r000032_8_1) + 24) & 127;
  int stage_v_112_2 = ((stage_v_93_2 + pub_r000032_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((sec_r000032_12_1 + pub_r000032_12_1) + 37) & 127;
  int stage_v_113_2 = ((sec_r000032_12_2 + pub_r000032_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((sec_r000032_3_1 + pub_r000032_7_1) + 31) & 127;
  int stage_v_114_2 = ((sec_r000032_3_2 + pub_r000032_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_80_1 + pub_r000032_7_1) + 35) & 127;
  int stage_v_115_2 = ((stage_v_80_2 + pub_r000032_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((sec_r000032_5_1 + pub_r000032_1_1) + 9) & 127;
  int stage_v_116_2 = ((sec_r000032_5_2 + pub_r000032_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_107_1 + pub_r000032_9_1) + 19) & 127;
  int stage_v_117_2 = ((stage_v_107_2 + pub_r000032_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_59_1 + pub_r000032_11_1) + 20) & 127;
  int stage_v_118_2 = ((stage_v_59_2 + pub_r000032_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_73_1 + pub_r000032_5_1) + 10) & 127;
  int stage_v_119_2 = ((stage_v_73_2 + pub_r000032_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_53_1 + pub_r000032_9_1) + 11) & 127;
  int stage_v_120_2 = ((stage_v_53_2 + pub_r000032_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_84_1 + pub_r000032_10_1) + 25) & 127;
  int stage_v_121_2 = ((stage_v_84_2 + pub_r000032_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_58_1 + pub_r000032_7_1) + 44) & 127;
  int stage_v_122_2 = ((stage_v_58_2 + pub_r000032_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_56_1 + pub_r000032_14_1) + 25) & 127;
  int stage_v_123_2 = ((stage_v_56_2 + pub_r000032_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_34_1 + pub_r000032_5_1) + 27) & 127;
  int stage_v_124_2 = ((stage_v_34_2 + pub_r000032_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_120_1 + pub_r000032_15_1) + 11) & 127;
  int stage_v_125_2 = ((stage_v_120_2 + pub_r000032_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((sec_r000032_1_1 + pub_r000032_11_1) + 16) & 127;
  int stage_v_126_2 = ((sec_r000032_1_2 + pub_r000032_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((sec_r000032_16_1 + pub_r000032_6_1) + 15) & 127;
  int stage_v_127_2 = ((sec_r000032_16_2 + pub_r000032_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_96_1 + pub_r000032_1_1) + 21) & 127;
  int stage_v_128_2 = ((stage_v_96_2 + pub_r000032_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000032_13_1 + pub_r000032_2_1) + 20) & 127;
  int stage_v_129_2 = ((sec_r000032_13_2 + pub_r000032_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((sec_r000032_4_1 + pub_r000032_7_1) + 21) & 127;
  int stage_v_130_2 = ((sec_r000032_4_2 + pub_r000032_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((sec_r000032_12_1 + pub_r000032_16_1) + 41) & 127;
  int stage_v_131_2 = ((sec_r000032_12_2 + pub_r000032_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000032_7_1 + pub_r000032_15_1) + 43) & 127;
  int stage_v_132_2 = ((sec_r000032_7_2 + pub_r000032_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_121_1 + pub_r000032_16_1) + 11) & 127;
  int stage_v_133_2 = ((stage_v_121_2 + pub_r000032_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000032_17_1 + pub_r000032_14_1) + 34) & 127;
  int stage_v_134_2 = ((sec_r000032_17_2 + pub_r000032_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((sec_r000032_13_1 + pub_r000032_11_1) + 29) & 127;
  int stage_v_135_2 = ((sec_r000032_13_2 + pub_r000032_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((sec_r000032_17_1 + pub_r000032_5_1) + 48) & 127;
  int stage_v_136_2 = ((sec_r000032_17_2 + pub_r000032_5_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_43_1 + pub_r000032_11_1) + 31) & 127;
  int stage_v_137_2 = ((stage_v_43_2 + pub_r000032_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_84_1 + pub_r000032_11_1) + 5) & 127;
  int stage_v_138_2 = ((stage_v_84_2 + pub_r000032_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_27_1 + pub_r000032_11_1) + 47) & 127;
  int stage_v_139_2 = ((stage_v_27_2 + pub_r000032_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_47_1 + pub_r000032_2_1) + 27) & 127;
  int stage_v_140_2 = ((stage_v_47_2 + pub_r000032_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_72_1 + pub_r000032_1_1) + 36) & 127;
  int stage_v_141_2 = ((stage_v_72_2 + pub_r000032_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_108_1 + pub_r000032_6_1) + 38) & 127;
  int stage_v_142_2 = ((stage_v_108_2 + pub_r000032_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((sec_r000032_0_1 + pub_r000032_6_1) + 16) & 127;
  int stage_v_143_2 = ((sec_r000032_0_2 + pub_r000032_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000032_2_1 + pub_r000032_0_1) + 45) & 127;
  int stage_v_144_2 = ((sec_r000032_2_2 + pub_r000032_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_102_1 + pub_r000032_9_1) + 9) & 127;
  int stage_v_145_2 = ((stage_v_102_2 + pub_r000032_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_44_1 + pub_r000032_7_1) + 17) & 127;
  int stage_v_146_2 = ((stage_v_44_2 + pub_r000032_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000032_0_1 + pub_r000032_6_1) + 36) & 127;
  int stage_v_147_2 = ((sec_r000032_0_2 + pub_r000032_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((sec_r000032_7_1 + pub_r000032_4_1) + 6) & 127;
  int stage_v_148_2 = ((sec_r000032_7_2 + pub_r000032_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_47_1 + pub_r000032_13_1) + 17) & 127;
  int stage_v_149_2 = ((stage_v_47_2 + pub_r000032_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_147_1 + pub_r000032_10_1) + 3) & 127;
  int stage_v_150_2 = ((stage_v_147_2 + pub_r000032_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000032_9_1 + pub_r000032_12_1) + 46) & 127;
  int stage_v_151_2 = ((sec_r000032_9_2 + pub_r000032_12_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_105_1 + pub_r000032_0_1) + 12) & 127;
  int stage_v_152_2 = ((stage_v_105_2 + pub_r000032_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000032_12_1 + pub_r000032_16_1) + 37) & 127;
  int stage_v_153_2 = ((sec_r000032_12_2 + pub_r000032_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_70_1 + pub_r000032_8_1) + 24) & 127;
  int stage_v_154_2 = ((stage_v_70_2 + pub_r000032_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_82_1 + pub_r000032_8_1) + 27) & 127;
  int stage_v_155_2 = ((stage_v_82_2 + pub_r000032_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_60_1 + pub_r000032_10_1) + 43) & 127;
  int stage_v_156_2 = ((stage_v_60_2 + pub_r000032_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000032_13_1 + pub_r000032_15_1) + 34) & 127;
  int stage_v_157_2 = ((sec_r000032_13_2 + pub_r000032_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_109_1 + pub_r000032_5_1) + 22) & 127;
  int stage_v_158_2 = ((stage_v_109_2 + pub_r000032_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_47_1 + pub_r000032_1_1) + 7) & 127;
  int stage_v_159_2 = ((stage_v_47_2 + pub_r000032_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((sec_r000032_18_1 + pub_r000032_9_1) + 7) & 127;
  int stage_v_160_2 = ((sec_r000032_18_2 + pub_r000032_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_39_1 + pub_r000032_15_1) + 41) & 127;
  int stage_v_161_2 = ((stage_v_39_2 + pub_r000032_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((sec_r000032_9_1 + pub_r000032_3_1) + 6) & 127;
  int stage_v_162_2 = ((sec_r000032_9_2 + pub_r000032_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000032_11_1 + pub_r000032_5_1) + 33) & 127;
  int stage_v_163_2 = ((sec_r000032_11_2 + pub_r000032_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_126_1 + pub_r000032_11_1) + 18) & 127;
  int stage_v_164_2 = ((stage_v_126_2 + pub_r000032_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000032_12_1 + pub_r000032_2_1) + 14) & 127;
  int stage_v_165_2 = ((sec_r000032_12_2 + pub_r000032_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000032_0_1 + pub_r000032_15_1) + 39) & 127;
  int stage_v_166_2 = ((sec_r000032_0_2 + pub_r000032_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_126_1 + pub_r000032_15_1) + 34) & 127;
  int stage_v_167_2 = ((stage_v_126_2 + pub_r000032_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000032_17_1 + pub_r000032_1_1) + 15) & 127;
  int stage_v_168_2 = ((sec_r000032_17_2 + pub_r000032_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_33_1 + pub_r000032_10_1) + 35) & 127;
  int stage_v_169_2 = ((stage_v_33_2 + pub_r000032_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_97_1 + pub_r000032_15_1) + 49) & 127;
  int stage_v_170_2 = ((stage_v_97_2 + pub_r000032_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((sec_r000032_17_1 + pub_r000032_4_1) + 41) & 127;
  int stage_v_171_2 = ((sec_r000032_17_2 + pub_r000032_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_83_1 + pub_r000032_8_1) + 12) & 127;
  int stage_v_172_2 = ((stage_v_83_2 + pub_r000032_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_89_1 + pub_r000032_11_1) + 39) & 127;
  int stage_v_173_2 = ((stage_v_89_2 + pub_r000032_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_106_1 + pub_r000032_2_1) + 3) & 127;
  int stage_v_174_2 = ((stage_v_106_2 + pub_r000032_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_154_1 + pub_r000032_15_1) + 39) & 127;
  int stage_v_175_2 = ((stage_v_154_2 + pub_r000032_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_140_1 + pub_r000032_16_1) + 3) & 127;
  int stage_v_176_2 = ((stage_v_140_2 + pub_r000032_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000032_11_1 + pub_r000032_9_1) + 23) & 127;
  int stage_v_177_2 = ((sec_r000032_11_2 + pub_r000032_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_54_1 + pub_r000032_4_1) + 44) & 127;
  int stage_v_178_2 = ((stage_v_54_2 + pub_r000032_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_43_1 + pub_r000032_11_1) + 11) & 127;
  int stage_v_179_2 = ((stage_v_43_2 + pub_r000032_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_124_1 + pub_r000032_4_1) + 29) & 127;
  int stage_v_180_2 = ((stage_v_124_2 + pub_r000032_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000032_13_1 + pub_r000032_16_1) + 48) & 127;
  int stage_v_181_2 = ((sec_r000032_13_2 + pub_r000032_16_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((sec_r000032_6_1 + pub_r000032_6_1) + 47) & 127;
  int stage_v_182_2 = ((sec_r000032_6_2 + pub_r000032_6_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_178_1 + pub_r000032_14_1) + 33) & 127;
  int stage_v_183_2 = ((stage_v_178_2 + pub_r000032_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((sec_r000032_5_1 + pub_r000032_9_1) + 37) & 127;
  int stage_v_184_2 = ((sec_r000032_5_2 + pub_r000032_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_113_1 + pub_r000032_4_1) + 8) & 127;
  int stage_v_185_2 = ((stage_v_113_2 + pub_r000032_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_158_1 + pub_r000032_5_1) + 23) & 127;
  int stage_v_186_2 = ((stage_v_158_2 + pub_r000032_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_106_1 + pub_r000032_10_1) + 35) & 127;
  int stage_v_187_2 = ((stage_v_106_2 + pub_r000032_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_62_1 + pub_r000032_11_1) + 30) & 127;
  int stage_v_188_2 = ((stage_v_62_2 + pub_r000032_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_56_1 + pub_r000032_8_1) + 29) & 127;
  int stage_v_189_2 = ((stage_v_56_2 + pub_r000032_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((sec_r000032_3_1 + pub_r000032_14_1) + 6) & 127;
  int stage_v_190_2 = ((sec_r000032_3_2 + pub_r000032_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((sec_r000032_17_1 + pub_r000032_7_1) + 24) & 127;
  int stage_v_191_2 = ((sec_r000032_17_2 + pub_r000032_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000032_5_1 + pub_r000032_8_1) + 34) & 127;
  int stage_v_192_2 = ((sec_r000032_5_2 + pub_r000032_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_46_1 + pub_r000032_5_1) + 16) & 127;
  int stage_v_193_2 = ((stage_v_46_2 + pub_r000032_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_48_1 + pub_r000032_16_1) + 44) & 127;
  int stage_v_194_2 = ((stage_v_48_2 + pub_r000032_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((sec_r000032_1_1 + pub_r000032_16_1) + 6) & 127;
  int stage_v_195_2 = ((sec_r000032_1_2 + pub_r000032_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_173_1 + pub_r000032_5_1) + 25) & 127;
  int stage_v_196_2 = ((stage_v_173_2 + pub_r000032_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((stage_v_146_1 + pub_r000032_16_1) + 24) & 127;
  int stage_v_197_2 = ((stage_v_146_2 + pub_r000032_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_114_1 + pub_r000032_7_1) + 43) & 127;
  int stage_v_198_2 = ((stage_v_114_2 + pub_r000032_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_151_1 + pub_r000032_11_1) + 26) & 127;
  int stage_v_199_2 = ((stage_v_151_2 + pub_r000032_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_100_1 + pub_r000032_8_1) + 14) & 127;
  int stage_v_200_2 = ((stage_v_100_2 + pub_r000032_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_27_1 + pub_r000032_14_1) + 35) & 127;
  int stage_v_201_2 = ((stage_v_27_2 + pub_r000032_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_91_1 + pub_r000032_1_1) + 24) & 127;
  int stage_v_202_2 = ((stage_v_91_2 + pub_r000032_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_184_1 + pub_r000032_6_1) + 27) & 127;
  int stage_v_203_2 = ((stage_v_184_2 + pub_r000032_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_199_1 + pub_r000032_2_1) + 27) & 127;
  int stage_v_204_2 = ((stage_v_199_2 + pub_r000032_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000032_17_1 + pub_r000032_10_1) + 3) & 127;
  int stage_v_205_2 = ((sec_r000032_17_2 + pub_r000032_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_116_1 + pub_r000032_11_1) + 16) & 127;
  int stage_v_206_2 = ((stage_v_116_2 + pub_r000032_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_42_1 + pub_r000032_11_1) + 45) & 127;
  int stage_v_207_2 = ((stage_v_42_2 + pub_r000032_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000032_13_1 + pub_r000032_2_1) + 19) & 127;
  int stage_v_208_2 = ((sec_r000032_13_2 + pub_r000032_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_188_1 + pub_r000032_14_1) + 23) & 127;
  int stage_v_209_2 = ((stage_v_188_2 + pub_r000032_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_41_1 + pub_r000032_11_1) + 28) & 127;
  int stage_v_210_2 = ((stage_v_41_2 + pub_r000032_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((sec_r000032_12_1 + pub_r000032_3_1) + 20) & 127;
  int stage_v_211_2 = ((sec_r000032_12_2 + pub_r000032_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_114_1 + pub_r000032_16_1) + 11) & 127;
  int stage_v_212_2 = ((stage_v_114_2 + pub_r000032_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((stage_v_175_1 + pub_r000032_3_1) + 20) & 127;
  int stage_v_213_2 = ((stage_v_175_2 + pub_r000032_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_197_1 + pub_r000032_8_1) + 16) & 127;
  int stage_v_214_2 = ((stage_v_197_2 + pub_r000032_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_82_1 + pub_r000032_7_1) + 33) & 127;
  int stage_v_215_2 = ((stage_v_82_2 + pub_r000032_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_115_1 + pub_r000032_4_1) + 9) & 127;
  int stage_v_216_2 = ((stage_v_115_2 + pub_r000032_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_38_1 + pub_r000032_15_1) + 22) & 127;
  int stage_v_217_2 = ((stage_v_38_2 + pub_r000032_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((stage_v_208_1 + pub_r000032_13_1) + 22) & 127;
  int stage_v_218_2 = ((stage_v_208_2 + pub_r000032_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_208_1 + pub_r000032_0_1) + 3) & 127;
  int stage_v_219_2 = ((stage_v_208_2 + pub_r000032_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_121_1 + pub_r000032_2_1) + 49) & 127;
  int stage_v_220_2 = ((stage_v_121_2 + pub_r000032_2_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((sec_r000032_3_1 + pub_r000032_7_1) + 40) & 127;
  int stage_v_221_2 = ((sec_r000032_3_2 + pub_r000032_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((stage_v_31_1 + pub_r000032_6_1) + 10) & 127;
  int stage_v_222_2 = ((stage_v_31_2 + pub_r000032_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_170_1 + pub_r000032_11_1) + 6) & 127;
  int stage_v_223_2 = ((stage_v_170_2 + pub_r000032_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((sec_r000032_3_1 + pub_r000032_8_1) + 11) & 127;
  int stage_v_224_2 = ((sec_r000032_3_2 + pub_r000032_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_129_1 + pub_r000032_15_1) + 18) & 127;
  int stage_v_225_2 = ((stage_v_129_2 + pub_r000032_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_102_1 + pub_r000032_4_1) + 33) & 127;
  int stage_v_226_2 = ((stage_v_102_2 + pub_r000032_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_56_1 + pub_r000032_14_1) + 35) & 127;
  int stage_v_227_2 = ((stage_v_56_2 + pub_r000032_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((sec_r000032_10_1 + pub_r000032_16_1) + 40) & 127;
  int stage_v_228_2 = ((sec_r000032_10_2 + pub_r000032_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((sec_r000032_10_1 + pub_r000032_1_1) + 32) & 127;
  int stage_v_229_2 = ((sec_r000032_10_2 + pub_r000032_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_96_1 + pub_r000032_14_1) + 24) & 127;
  int stage_v_230_2 = ((stage_v_96_2 + pub_r000032_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000032_4_1 + pub_r000032_14_1) + 37) & 127;
  int stage_v_231_2 = ((sec_r000032_4_2 + pub_r000032_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((stage_v_175_1 + pub_r000032_3_1) + 12) & 127;
  int stage_v_232_2 = ((stage_v_175_2 + pub_r000032_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((stage_v_211_1 + pub_r000032_7_1) + 14) & 127;
  int stage_v_233_2 = ((stage_v_211_2 + pub_r000032_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((sec_r000032_13_1 + pub_r000032_14_1) + 49) & 127;
  int stage_v_234_2 = ((sec_r000032_13_2 + pub_r000032_14_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((stage_v_108_1 + pub_r000032_3_1) + 28) & 127;
  int stage_v_235_2 = ((stage_v_108_2 + pub_r000032_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((sec_r000032_7_1 + pub_r000032_11_1) + 21) & 127;
  int stage_v_236_2 = ((sec_r000032_7_2 + pub_r000032_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_180_1 + pub_r000032_14_1) + 13) & 127;
  int stage_v_237_2 = ((stage_v_180_2 + pub_r000032_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((sec_r000032_17_1 + pub_r000032_11_1) + 3) & 127;
  int stage_v_238_2 = ((sec_r000032_17_2 + pub_r000032_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_225_1 + pub_r000032_9_1) + 35) & 127;
  int stage_v_239_2 = ((stage_v_225_2 + pub_r000032_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((sec_r000032_11_1 + pub_r000032_10_1) + 45) & 127;
  int stage_v_240_2 = ((sec_r000032_11_2 + pub_r000032_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((stage_v_110_1 + pub_r000032_4_1) + 15) & 127;
  int stage_v_241_2 = ((stage_v_110_2 + pub_r000032_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((sec_r000032_3_1 + pub_r000032_1_1) + 36) & 127;
  int stage_v_242_2 = ((sec_r000032_3_2 + pub_r000032_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((sec_r000032_4_1 + pub_r000032_4_1) + 39) & 127;
  int stage_v_243_2 = ((sec_r000032_4_2 + pub_r000032_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((sec_r000032_4_1 + pub_r000032_2_1) + 29) & 127;
  int stage_v_244_2 = ((sec_r000032_4_2 + pub_r000032_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((stage_v_221_1 + pub_r000032_4_1) + 18) & 127;
  int stage_v_245_2 = ((stage_v_221_2 + pub_r000032_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((sec_r000032_6_1 + pub_r000032_15_1) + 45) & 127;
  int stage_v_246_2 = ((sec_r000032_6_2 + pub_r000032_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((stage_v_76_1 + pub_r000032_1_1) + 24) & 127;
  int stage_v_247_2 = ((stage_v_76_2 + pub_r000032_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((stage_v_91_1 + pub_r000032_7_1) + 16) & 127;
  int stage_v_248_2 = ((stage_v_91_2 + pub_r000032_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_43_1 + pub_r000032_7_1) + 18) & 127;
  int stage_v_249_2 = ((stage_v_43_2 + pub_r000032_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_230_1 + pub_r000032_2_1) + 16) & 127;
  int stage_v_250_2 = ((stage_v_230_2 + pub_r000032_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_70_1 + pub_r000032_14_1) + 21) & 127;
  int stage_v_251_2 = ((stage_v_70_2 + pub_r000032_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_146_1 + pub_r000032_9_1) + 12) & 127;
  int stage_v_252_2 = ((stage_v_146_2 + pub_r000032_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((sec_r000032_10_1 + pub_r000032_3_1) + 31) & 127;
  int stage_v_253_2 = ((sec_r000032_10_2 + pub_r000032_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_173_1 + pub_r000032_5_1) + 27) & 127;
  int stage_v_254_2 = ((stage_v_173_2 + pub_r000032_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((sec_r000032_5_1 + pub_r000032_12_1) + 31) & 127;
  int stage_v_255_2 = ((sec_r000032_5_2 + pub_r000032_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((sec_r000032_16_1 + pub_r000032_5_1) + 48) & 127;
  int stage_v_256_2 = ((sec_r000032_16_2 + pub_r000032_5_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((stage_v_58_1 + pub_r000032_2_1) + 21) & 127;
  int stage_v_257_2 = ((stage_v_58_2 + pub_r000032_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((stage_v_205_1 + pub_r000032_7_1) + 17) & 127;
  int stage_v_258_2 = ((stage_v_205_2 + pub_r000032_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((sec_r000032_10_1 + pub_r000032_6_1) + 25) & 127;
  int stage_v_259_2 = ((sec_r000032_10_2 + pub_r000032_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((stage_v_71_1 + pub_r000032_2_1) + 21) & 127;
  int stage_v_260_2 = ((stage_v_71_2 + pub_r000032_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((stage_v_29_1 + pub_r000032_0_1) + 33) & 127;
  int stage_v_261_2 = ((stage_v_29_2 + pub_r000032_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((sec_r000032_5_1 + pub_r000032_13_1) + 30) & 127;
  int stage_v_262_2 = ((sec_r000032_5_2 + pub_r000032_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000032_9_1 + pub_r000032_3_1) + 44) & 127;
  int stage_v_263_2 = ((sec_r000032_9_2 + pub_r000032_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((stage_v_174_1 + pub_r000032_6_1) + 4) & 127;
  int stage_v_264_2 = ((stage_v_174_2 + pub_r000032_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((sec_r000032_16_1 + pub_r000032_13_1) + 39) & 127;
  int stage_v_265_2 = ((sec_r000032_16_2 + pub_r000032_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((stage_v_35_1 + pub_r000032_14_1) + 9) & 127;
  int stage_v_266_2 = ((stage_v_35_2 + pub_r000032_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000032_13_1 + pub_r000032_3_1) + 33) & 127;
  int stage_v_267_2 = ((sec_r000032_13_2 + pub_r000032_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((sec_r000032_3_1 + pub_r000032_5_1) + 31) & 127;
  int stage_v_268_2 = ((sec_r000032_3_2 + pub_r000032_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_58_1 + pub_r000032_10_1) + 17) & 127;
  int stage_v_269_2 = ((stage_v_58_2 + pub_r000032_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_166_1 + pub_r000032_5_1) + 23) & 127;
  int stage_v_270_2 = ((stage_v_166_2 + pub_r000032_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((stage_v_54_1 + pub_r000032_2_1) + 27) & 127;
  int stage_v_271_2 = ((stage_v_54_2 + pub_r000032_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((stage_v_251_1 + pub_r000032_14_1) + 49) & 127;
  int stage_v_272_2 = ((stage_v_251_2 + pub_r000032_14_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((sec_r000032_9_1 + pub_r000032_6_1) + 48) & 127;
  int stage_v_273_2 = ((sec_r000032_9_2 + pub_r000032_6_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((stage_v_71_1 + pub_r000032_2_1) + 15) & 127;
  int stage_v_274_2 = ((stage_v_71_2 + pub_r000032_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((sec_r000032_11_1 + pub_r000032_0_1) + 44) & 127;
  int stage_v_275_2 = ((sec_r000032_11_2 + pub_r000032_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((stage_v_222_1 + pub_r000032_9_1) + 43) & 127;
  int stage_v_276_2 = ((stage_v_222_2 + pub_r000032_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_174_1 + pub_r000032_1_1) + 34) & 127;
  int stage_v_277_2 = ((stage_v_174_2 + pub_r000032_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((stage_v_246_1 + pub_r000032_0_1) + 35) & 127;
  int stage_v_278_2 = ((stage_v_246_2 + pub_r000032_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((stage_v_59_1 + pub_r000032_7_1) + 12) & 127;
  int stage_v_279_2 = ((stage_v_59_2 + pub_r000032_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((stage_v_213_1 + pub_r000032_11_1) + 26) & 127;
  int stage_v_280_2 = ((stage_v_213_2 + pub_r000032_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((stage_v_182_1 + pub_r000032_9_1) + 33) & 127;
  int stage_v_281_2 = ((stage_v_182_2 + pub_r000032_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((sec_r000032_14_1 + pub_r000032_6_1) + 24) & 127;
  int stage_v_282_2 = ((sec_r000032_14_2 + pub_r000032_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((sec_r000032_1_1 + pub_r000032_12_1) + 27) & 127;
  int stage_v_283_2 = ((sec_r000032_1_2 + pub_r000032_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((sec_r000032_7_1 + pub_r000032_5_1) + 9) & 127;
  int stage_v_284_2 = ((sec_r000032_7_2 + pub_r000032_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((stage_v_192_1 + pub_r000032_7_1) + 49) & 127;
  int stage_v_285_2 = ((stage_v_192_2 + pub_r000032_7_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((stage_v_204_1 + pub_r000032_6_1) + 38) & 127;
  int stage_v_286_2 = ((stage_v_204_2 + pub_r000032_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_229_1 + pub_r000032_4_1) + 30) & 127;
  int stage_v_287_2 = ((stage_v_229_2 + pub_r000032_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((sec_r000032_3_1 + pub_r000032_1_1) + 45) & 127;
  int stage_v_288_2 = ((sec_r000032_3_2 + pub_r000032_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((sec_r000032_9_1 + pub_r000032_15_1) + 33) & 127;
  int stage_v_289_2 = ((sec_r000032_9_2 + pub_r000032_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((sec_r000032_13_1 + pub_r000032_14_1) + 29) & 127;
  int stage_v_290_2 = ((sec_r000032_13_2 + pub_r000032_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((sec_r000032_8_1 + pub_r000032_11_1) + 32) & 127;
  int stage_v_291_2 = ((sec_r000032_8_2 + pub_r000032_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((sec_r000032_12_1 + pub_r000032_8_1) + 27) & 127;
  int stage_v_292_2 = ((sec_r000032_12_2 + pub_r000032_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((sec_r000032_3_1 + pub_r000032_11_1) + 34) & 127;
  int stage_v_293_2 = ((sec_r000032_3_2 + pub_r000032_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((sec_r000032_4_1 + pub_r000032_16_1) + 14) & 127;
  int stage_v_294_2 = ((sec_r000032_4_2 + pub_r000032_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((sec_r000032_7_1 + pub_r000032_7_1) + 19) & 127;
  int stage_v_295_2 = ((sec_r000032_7_2 + pub_r000032_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_46_1 + pub_r000032_9_1) + 34) & 127;
  int stage_v_296_2 = ((stage_v_46_2 + pub_r000032_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_135_1 + pub_r000032_13_1) + 48) & 127;
  int stage_v_297_2 = ((stage_v_135_2 + pub_r000032_13_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((sec_r000032_15_1 + pub_r000032_7_1) + 31) & 127;
  int stage_v_298_2 = ((sec_r000032_15_2 + pub_r000032_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_295_1 + pub_r000032_1_1) + 17) & 127;
  int stage_v_299_2 = ((stage_v_295_2 + pub_r000032_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((stage_v_265_1 + pub_r000032_8_1) + 22) & 127;
  int stage_v_300_2 = ((stage_v_265_2 + pub_r000032_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((stage_v_252_1 + pub_r000032_1_1) + 47) & 127;
  int stage_v_301_2 = ((stage_v_252_2 + pub_r000032_1_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((sec_r000032_7_1 + pub_r000032_16_1) + 35) & 127;
  int stage_v_302_2 = ((sec_r000032_7_2 + pub_r000032_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((sec_r000032_7_1 + pub_r000032_11_1) + 29) & 127;
  int stage_v_303_2 = ((sec_r000032_7_2 + pub_r000032_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((sec_r000032_16_1 + pub_r000032_9_1) + 7) & 127;
  int stage_v_304_2 = ((sec_r000032_16_2 + pub_r000032_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_98_1 + pub_r000032_4_1) + 31) & 127;
  int stage_v_305_2 = ((stage_v_98_2 + pub_r000032_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((stage_v_26_1 + pub_r000032_14_1) + 36) & 127;
  int stage_v_306_2 = ((stage_v_26_2 + pub_r000032_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((sec_r000032_17_1 + pub_r000032_6_1) + 6) & 127;
  int stage_v_307_2 = ((sec_r000032_17_2 + pub_r000032_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((stage_v_254_1 + pub_r000032_1_1) + 28) & 127;
  int stage_v_308_2 = ((stage_v_254_2 + pub_r000032_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((stage_v_190_1 + pub_r000032_11_1) + 13) & 127;
  int stage_v_309_2 = ((stage_v_190_2 + pub_r000032_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((sec_r000032_2_1 + pub_r000032_6_1) + 15) & 127;
  int stage_v_310_2 = ((sec_r000032_2_2 + pub_r000032_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((stage_v_139_1 + pub_r000032_10_1) + 8) & 127;
  int stage_v_311_2 = ((stage_v_139_2 + pub_r000032_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((stage_v_154_1 + pub_r000032_5_1) + 39) & 127;
  int stage_v_312_2 = ((stage_v_154_2 + pub_r000032_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((sec_r000032_1_1 + pub_r000032_12_1) + 34) & 127;
  int stage_v_313_2 = ((sec_r000032_1_2 + pub_r000032_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((stage_v_300_1 + pub_r000032_6_1) + 10) & 127;
  int stage_v_314_2 = ((stage_v_300_2 + pub_r000032_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((stage_v_312_1 + pub_r000032_13_1) + 23) & 127;
  int stage_v_315_2 = ((stage_v_312_2 + pub_r000032_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((stage_v_178_1 + pub_r000032_16_1) + 6) & 127;
  int stage_v_316_2 = ((stage_v_178_2 + pub_r000032_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((stage_v_89_1 + pub_r000032_11_1) + 34) & 127;
  int stage_v_317_2 = ((stage_v_89_2 + pub_r000032_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((stage_v_171_1 + pub_r000032_15_1) + 7) & 127;
  int stage_v_318_2 = ((stage_v_171_2 + pub_r000032_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((sec_r000032_0_1 + pub_r000032_7_1) + 31) & 127;
  int stage_v_319_2 = ((sec_r000032_0_2 + pub_r000032_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((stage_v_280_1 + pub_r000032_1_1) + 15) & 127;
  int stage_v_320_2 = ((stage_v_280_2 + pub_r000032_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((sec_r000032_11_1 + pub_r000032_0_1) + 38) & 127;
  int stage_v_321_2 = ((sec_r000032_11_2 + pub_r000032_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((stage_v_122_1 + pub_r000032_2_1) + 20) & 127;
  int stage_v_322_2 = ((stage_v_122_2 + pub_r000032_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((stage_v_305_1 + pub_r000032_3_1) + 32) & 127;
  int stage_v_323_2 = ((stage_v_305_2 + pub_r000032_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((stage_v_77_1 + pub_r000032_5_1) + 17) & 127;
  int stage_v_324_2 = ((stage_v_77_2 + pub_r000032_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((stage_v_27_1 + pub_r000032_3_1) + 17) & 127;
  int stage_v_325_2 = ((stage_v_27_2 + pub_r000032_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((sec_r000032_16_1 + pub_r000032_0_1) + 19) & 127;
  int stage_v_326_2 = ((sec_r000032_16_2 + pub_r000032_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((sec_r000032_10_1 + pub_r000032_15_1) + 5) & 127;
  int stage_v_327_2 = ((sec_r000032_10_2 + pub_r000032_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((stage_v_284_1 + pub_r000032_9_1) + 30) & 127;
  int stage_v_328_2 = ((stage_v_284_2 + pub_r000032_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((sec_r000032_18_1 + pub_r000032_2_1) + 12) & 127;
  int stage_v_329_2 = ((sec_r000032_18_2 + pub_r000032_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((stage_v_132_1 + pub_r000032_5_1) + 46) & 127;
  int stage_v_330_2 = ((stage_v_132_2 + pub_r000032_5_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((stage_v_228_1 + pub_r000032_14_1) + 42) & 127;
  int stage_v_331_2 = ((stage_v_228_2 + pub_r000032_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((stage_v_121_1 + pub_r000032_15_1) + 7) & 127;
  int stage_v_332_2 = ((stage_v_121_2 + pub_r000032_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((stage_v_147_1 + pub_r000032_15_1) + 15) & 127;
  int stage_v_333_2 = ((stage_v_147_2 + pub_r000032_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((sec_r000032_8_1 + pub_r000032_5_1) + 24) & 127;
  int stage_v_334_2 = ((sec_r000032_8_2 + pub_r000032_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((sec_r000032_10_1 + pub_r000032_3_1) + 24) & 127;
  int stage_v_335_2 = ((sec_r000032_10_2 + pub_r000032_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((stage_v_117_1 + pub_r000032_6_1) + 39) & 127;
  int stage_v_336_2 = ((stage_v_117_2 + pub_r000032_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((stage_v_302_1 + pub_r000032_3_1) + 35) & 127;
  int stage_v_337_2 = ((stage_v_302_2 + pub_r000032_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((stage_v_156_1 + pub_r000032_9_1) + 4) & 127;
  int stage_v_338_2 = ((stage_v_156_2 + pub_r000032_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((sec_r000032_9_1 + pub_r000032_5_1) + 26) & 127;
  int stage_v_339_2 = ((sec_r000032_9_2 + pub_r000032_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((stage_v_161_1 + pub_r000032_4_1) + 21) & 127;
  int stage_v_340_2 = ((stage_v_161_2 + pub_r000032_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((sec_r000032_3_1 + pub_r000032_12_1) + 35) & 127;
  int stage_v_341_2 = ((sec_r000032_3_2 + pub_r000032_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((stage_v_327_1 + pub_r000032_14_1) + 46) & 127;
  int stage_v_342_2 = ((stage_v_327_2 + pub_r000032_14_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((stage_v_249_1 + pub_r000032_16_1) + 26) & 127;
  int stage_v_343_2 = ((stage_v_249_2 + pub_r000032_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((stage_v_334_1 + pub_r000032_14_1) + 3) & 127;
  int stage_v_344_2 = ((stage_v_334_2 + pub_r000032_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((stage_v_273_1 + pub_r000032_13_1) + 20) & 127;
  int stage_v_345_2 = ((stage_v_273_2 + pub_r000032_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((stage_v_82_1 + pub_r000032_13_1) + 41) & 127;
  int stage_v_346_2 = ((stage_v_82_2 + pub_r000032_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((stage_v_61_1 + pub_r000032_5_1) + 38) & 127;
  int stage_v_347_2 = ((stage_v_61_2 + pub_r000032_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((stage_v_95_1 + pub_r000032_11_1) + 32) & 127;
  int stage_v_348_2 = ((stage_v_95_2 + pub_r000032_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((sec_r000032_15_1 + pub_r000032_0_1) + 17) & 127;
  int stage_v_349_2 = ((sec_r000032_15_2 + pub_r000032_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((sec_r000032_2_1 + pub_r000032_12_1) + 8) & 127;
  int stage_v_350_2 = ((sec_r000032_2_2 + pub_r000032_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((stage_v_90_1 + pub_r000032_5_1) + 48) & 127;
  int stage_v_351_2 = ((stage_v_90_2 + pub_r000032_5_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((stage_v_161_1 + pub_r000032_11_1) + 31) & 127;
  int stage_v_352_2 = ((stage_v_161_2 + pub_r000032_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((stage_v_232_1 + pub_r000032_15_1) + 41) & 127;
  int stage_v_353_2 = ((stage_v_232_2 + pub_r000032_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((stage_v_254_1 + pub_r000032_6_1) + 40) & 127;
  int stage_v_354_2 = ((stage_v_254_2 + pub_r000032_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((stage_v_228_1 + pub_r000032_1_1) + 21) & 127;
  int stage_v_355_2 = ((stage_v_228_2 + pub_r000032_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((stage_v_78_1 + pub_r000032_2_1) + 32) & 127;
  int stage_v_356_2 = ((stage_v_78_2 + pub_r000032_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((stage_v_236_1 + pub_r000032_2_1) + 39) & 127;
  int stage_v_357_2 = ((stage_v_236_2 + pub_r000032_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((stage_v_206_1 + pub_r000032_4_1) + 27) & 127;
  int stage_v_358_2 = ((stage_v_206_2 + pub_r000032_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((sec_r000032_11_1 + pub_r000032_2_1) + 43) & 127;
  int stage_v_359_2 = ((sec_r000032_11_2 + pub_r000032_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((sec_r000032_7_1 + pub_r000032_6_1) + 21) & 127;
  int stage_v_360_2 = ((sec_r000032_7_2 + pub_r000032_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((sec_r000032_18_1 + pub_r000032_4_1) + 5) & 127;
  int stage_v_361_2 = ((sec_r000032_18_2 + pub_r000032_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((stage_v_240_1 + pub_r000032_4_1) + 45) & 127;
  int stage_v_362_2 = ((stage_v_240_2 + pub_r000032_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((stage_v_143_1 + pub_r000032_5_1) + 41) & 127;
  int stage_v_363_2 = ((stage_v_143_2 + pub_r000032_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((sec_r000032_11_1 + pub_r000032_1_1) + 8) & 127;
  int stage_v_364_2 = ((sec_r000032_11_2 + pub_r000032_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((stage_v_164_1 + pub_r000032_8_1) + 19) & 127;
  int stage_v_365_2 = ((stage_v_164_2 + pub_r000032_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((stage_v_168_1 + pub_r000032_2_1) + 21) & 127;
  int stage_v_366_2 = ((stage_v_168_2 + pub_r000032_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((sec_r000032_7_1 + pub_r000032_7_1) + 26) & 127;
  int stage_v_367_2 = ((sec_r000032_7_2 + pub_r000032_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((sec_r000032_14_1 + pub_r000032_6_1) + 21) & 127;
  int stage_v_368_2 = ((sec_r000032_14_2 + pub_r000032_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((stage_v_270_1 + pub_r000032_12_1) + 36) & 127;
  int stage_v_369_2 = ((stage_v_270_2 + pub_r000032_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((stage_v_247_1 + pub_r000032_13_1) + 36) & 127;
  int stage_v_370_2 = ((stage_v_247_2 + pub_r000032_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((stage_v_92_1 + pub_r000032_8_1) + 7) & 127;
  int stage_v_371_2 = ((stage_v_92_2 + pub_r000032_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((stage_v_203_1 + pub_r000032_14_1) + 32) & 127;
  int stage_v_372_2 = ((stage_v_203_2 + pub_r000032_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((stage_v_36_1 + pub_r000032_13_1) + 43) & 127;
  int stage_v_373_2 = ((stage_v_36_2 + pub_r000032_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((sec_r000032_0_1 + pub_r000032_11_1) + 30) & 127;
  int stage_v_374_2 = ((sec_r000032_0_2 + pub_r000032_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((sec_r000032_15_1 + pub_r000032_2_1) + 4) & 127;
  int stage_v_375_2 = ((sec_r000032_15_2 + pub_r000032_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((stage_v_304_1 + pub_r000032_9_1) + 24) & 127;
  int stage_v_376_2 = ((stage_v_304_2 + pub_r000032_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((sec_r000032_2_1 + pub_r000032_3_1) + 35) & 127;
  int stage_v_377_2 = ((sec_r000032_2_2 + pub_r000032_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((sec_r000032_17_1 + pub_r000032_11_1) + 39) & 127;
  int stage_v_378_2 = ((sec_r000032_17_2 + pub_r000032_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((stage_v_288_1 + pub_r000032_6_1) + 5) & 127;
  int stage_v_379_2 = ((stage_v_288_2 + pub_r000032_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((sec_r000032_7_1 + pub_r000032_9_1) + 5) & 127;
  int stage_v_380_2 = ((sec_r000032_7_2 + pub_r000032_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((stage_v_32_1 + pub_r000032_0_1) + 4) & 127;
  int stage_v_381_2 = ((stage_v_32_2 + pub_r000032_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((sec_r000032_12_1 + pub_r000032_15_1) + 35) & 127;
  int stage_v_382_2 = ((sec_r000032_12_2 + pub_r000032_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((stage_v_220_1 + pub_r000032_4_1) + 37) & 127;
  int stage_v_383_2 = ((stage_v_220_2 + pub_r000032_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((sec_r000032_14_1 + pub_r000032_16_1) + 10) & 127;
  int stage_v_384_2 = ((sec_r000032_14_2 + pub_r000032_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((stage_v_361_1 + pub_r000032_7_1) + 21) & 127;
  int stage_v_385_2 = ((stage_v_361_2 + pub_r000032_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((stage_v_120_1 + pub_r000032_1_1) + 5) & 127;
  int stage_v_386_2 = ((stage_v_120_2 + pub_r000032_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((stage_v_175_1 + pub_r000032_7_1) + 26) & 127;
  int stage_v_387_2 = ((stage_v_175_2 + pub_r000032_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((stage_v_229_1 + pub_r000032_8_1) + 49) & 127;
  int stage_v_388_2 = ((stage_v_229_2 + pub_r000032_8_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((stage_v_340_1 + pub_r000032_15_1) + 45) & 127;
  int stage_v_389_2 = ((stage_v_340_2 + pub_r000032_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((sec_r000032_18_1 + pub_r000032_2_1) + 15) & 127;
  int stage_v_390_2 = ((sec_r000032_18_2 + pub_r000032_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((stage_v_227_1 + pub_r000032_1_1) + 12) & 127;
  int stage_v_391_2 = ((stage_v_227_2 + pub_r000032_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((stage_v_239_1 + pub_r000032_11_1) + 44) & 127;
  int stage_v_392_2 = ((stage_v_239_2 + pub_r000032_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((sec_r000032_14_1 + pub_r000032_10_1) + 39) & 127;
  int stage_v_393_2 = ((sec_r000032_14_2 + pub_r000032_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((stage_v_298_1 + pub_r000032_10_1) + 16) & 127;
  int stage_v_394_2 = ((stage_v_298_2 + pub_r000032_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  int stage_v_395_1 = ((stage_v_380_1 + pub_r000032_16_1) + 21) & 127;
  int stage_v_395_2 = ((stage_v_380_2 + pub_r000032_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_395_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_395_2) & 255;
  int stage_v_396_1 = ((stage_v_343_1 + pub_r000032_6_1) + 25) & 127;
  int stage_v_396_2 = ((stage_v_343_2 + pub_r000032_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_396_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_396_2) & 255;
  int stage_v_397_1 = ((sec_r000032_7_1 + pub_r000032_8_1) + 30) & 127;
  int stage_v_397_2 = ((sec_r000032_7_2 + pub_r000032_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_397_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_397_2) & 255;
  int stage_v_398_1 = ((sec_r000032_14_1 + pub_r000032_13_1) + 36) & 127;
  int stage_v_398_2 = ((sec_r000032_14_2 + pub_r000032_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_398_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_398_2) & 255;
  int stage_v_399_1 = ((stage_v_58_1 + pub_r000032_13_1) + 31) & 127;
  int stage_v_399_2 = ((stage_v_58_2 + pub_r000032_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_399_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_399_2) & 255;
  int stage_v_400_1 = ((stage_v_34_1 + pub_r000032_5_1) + 16) & 127;
  int stage_v_400_2 = ((stage_v_34_2 + pub_r000032_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_400_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_400_2) & 255;
  int stage_v_401_1 = ((sec_r000032_15_1 + pub_r000032_12_1) + 6) & 127;
  int stage_v_401_2 = ((sec_r000032_15_2 + pub_r000032_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_401_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_401_2) & 255;
  int stage_v_402_1 = ((stage_v_59_1 + pub_r000032_13_1) + 22) & 127;
  int stage_v_402_2 = ((stage_v_59_2 + pub_r000032_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_402_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_402_2) & 255;
  int stage_v_403_1 = ((stage_v_153_1 + pub_r000032_7_1) + 43) & 127;
  int stage_v_403_2 = ((stage_v_153_2 + pub_r000032_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_403_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_403_2) & 255;
  int stage_v_404_1 = ((sec_r000032_14_1 + pub_r000032_11_1) + 47) & 127;
  int stage_v_404_2 = ((sec_r000032_14_2 + pub_r000032_11_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_404_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_404_2) & 255;
  int stage_v_405_1 = ((stage_v_347_1 + pub_r000032_4_1) + 30) & 127;
  int stage_v_405_2 = ((stage_v_347_2 + pub_r000032_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_405_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_405_2) & 255;
  int stage_v_406_1 = ((sec_r000032_16_1 + pub_r000032_12_1) + 43) & 127;
  int stage_v_406_2 = ((sec_r000032_16_2 + pub_r000032_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_406_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_406_2) & 255;
  int stage_v_407_1 = ((sec_r000032_9_1 + pub_r000032_8_1) + 10) & 127;
  int stage_v_407_2 = ((sec_r000032_9_2 + pub_r000032_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_407_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_407_2) & 255;
  int stage_v_408_1 = ((sec_r000032_10_1 + pub_r000032_1_1) + 12) & 127;
  int stage_v_408_2 = ((sec_r000032_10_2 + pub_r000032_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_408_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_408_2) & 255;
  int stage_v_409_1 = ((stage_v_377_1 + pub_r000032_12_1) + 18) & 127;
  int stage_v_409_2 = ((stage_v_377_2 + pub_r000032_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_409_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_409_2) & 255;
  int stage_v_410_1 = ((stage_v_144_1 + pub_r000032_1_1) + 25) & 127;
  int stage_v_410_2 = ((stage_v_144_2 + pub_r000032_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_410_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_410_2) & 255;
  int stage_v_411_1 = ((stage_v_211_1 + pub_r000032_7_1) + 35) & 127;
  int stage_v_411_2 = ((stage_v_211_2 + pub_r000032_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_411_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_411_2) & 255;
  int stage_v_412_1 = ((stage_v_400_1 + pub_r000032_12_1) + 36) & 127;
  int stage_v_412_2 = ((stage_v_400_2 + pub_r000032_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_412_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_412_2) & 255;
  int stage_v_413_1 = ((stage_v_114_1 + pub_r000032_8_1) + 32) & 127;
  int stage_v_413_2 = ((stage_v_114_2 + pub_r000032_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_413_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_413_2) & 255;
  int stage_v_414_1 = ((sec_r000032_0_1 + pub_r000032_14_1) + 8) & 127;
  int stage_v_414_2 = ((sec_r000032_0_2 + pub_r000032_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_414_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_414_2) & 255;
  int stage_v_415_1 = ((sec_r000032_4_1 + pub_r000032_3_1) + 28) & 127;
  int stage_v_415_2 = ((sec_r000032_4_2 + pub_r000032_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_415_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_415_2) & 255;
  int stage_v_416_1 = ((sec_r000032_10_1 + pub_r000032_1_1) + 6) & 127;
  int stage_v_416_2 = ((sec_r000032_10_2 + pub_r000032_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_416_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_416_2) & 255;
  int stage_v_417_1 = ((stage_v_77_1 + pub_r000032_15_1) + 28) & 127;
  int stage_v_417_2 = ((stage_v_77_2 + pub_r000032_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_417_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_417_2) & 255;
  int stage_v_418_1 = ((stage_v_268_1 + pub_r000032_8_1) + 11) & 127;
  int stage_v_418_2 = ((stage_v_268_2 + pub_r000032_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_418_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_418_2) & 255;
  int stage_v_419_1 = ((stage_v_298_1 + pub_r000032_15_1) + 10) & 127;
  int stage_v_419_2 = ((stage_v_298_2 + pub_r000032_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_419_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_419_2) & 255;
  int stage_v_420_1 = ((stage_v_65_1 + pub_r000032_14_1) + 17) & 127;
  int stage_v_420_2 = ((stage_v_65_2 + pub_r000032_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_420_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_420_2) & 255;
  int stage_v_421_1 = ((stage_v_145_1 + pub_r000032_14_1) + 10) & 127;
  int stage_v_421_2 = ((stage_v_145_2 + pub_r000032_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_421_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_421_2) & 255;
  int stage_v_422_1 = ((sec_r000032_10_1 + pub_r000032_1_1) + 32) & 127;
  int stage_v_422_2 = ((sec_r000032_10_2 + pub_r000032_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_422_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_422_2) & 255;
  int stage_v_423_1 = ((stage_v_126_1 + pub_r000032_14_1) + 4) & 127;
  int stage_v_423_2 = ((stage_v_126_2 + pub_r000032_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_423_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_423_2) & 255;
  int stage_v_424_1 = ((sec_r000032_12_1 + pub_r000032_14_1) + 27) & 127;
  int stage_v_424_2 = ((sec_r000032_12_2 + pub_r000032_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_424_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_424_2) & 255;
  int stage_v_425_1 = ((sec_r000032_9_1 + pub_r000032_12_1) + 36) & 127;
  int stage_v_425_2 = ((sec_r000032_9_2 + pub_r000032_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_425_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_425_2) & 255;
  int stage_v_426_1 = ((sec_r000032_16_1 + pub_r000032_12_1) + 17) & 127;
  int stage_v_426_2 = ((sec_r000032_16_2 + pub_r000032_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_426_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_426_2) & 255;
  int stage_v_427_1 = ((stage_v_296_1 + pub_r000032_7_1) + 18) & 127;
  int stage_v_427_2 = ((stage_v_296_2 + pub_r000032_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_427_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_427_2) & 255;
  int stage_v_428_1 = ((stage_v_264_1 + pub_r000032_5_1) + 16) & 127;
  int stage_v_428_2 = ((stage_v_264_2 + pub_r000032_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_428_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_428_2) & 255;
  int stage_v_429_1 = ((stage_v_417_1 + pub_r000032_0_1) + 11) & 127;
  int stage_v_429_2 = ((stage_v_417_2 + pub_r000032_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_429_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_429_2) & 255;
  int stage_v_430_1 = ((stage_v_94_1 + pub_r000032_13_1) + 46) & 127;
  int stage_v_430_2 = ((stage_v_94_2 + pub_r000032_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_430_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_430_2) & 255;
  int stage_v_431_1 = ((stage_v_292_1 + pub_r000032_15_1) + 12) & 127;
  int stage_v_431_2 = ((stage_v_292_2 + pub_r000032_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_431_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_431_2) & 255;
  int stage_v_432_1 = ((sec_r000032_0_1 + pub_r000032_12_1) + 6) & 127;
  int stage_v_432_2 = ((sec_r000032_0_2 + pub_r000032_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_432_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_432_2) & 255;
  int stage_v_433_1 = ((sec_r000032_5_1 + pub_r000032_12_1) + 3) & 127;
  int stage_v_433_2 = ((sec_r000032_5_2 + pub_r000032_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_433_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_433_2) & 255;
  int stage_v_434_1 = ((sec_r000032_3_1 + pub_r000032_13_1) + 36) & 127;
  int stage_v_434_2 = ((sec_r000032_3_2 + pub_r000032_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_434_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_434_2) & 255;
  int stage_v_435_1 = ((stage_v_371_1 + pub_r000032_14_1) + 36) & 127;
  int stage_v_435_2 = ((stage_v_371_2 + pub_r000032_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_435_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_435_2) & 255;
  int stage_v_436_1 = ((stage_v_361_1 + pub_r000032_14_1) + 40) & 127;
  int stage_v_436_2 = ((stage_v_361_2 + pub_r000032_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_436_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_436_2) & 255;
  int stage_v_437_1 = ((stage_v_280_1 + pub_r000032_15_1) + 33) & 127;
  int stage_v_437_2 = ((stage_v_280_2 + pub_r000032_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_437_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_437_2) & 255;
  int stage_v_438_1 = ((stage_v_93_1 + pub_r000032_9_1) + 44) & 127;
  int stage_v_438_2 = ((stage_v_93_2 + pub_r000032_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_438_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_438_2) & 255;
  int stage_v_439_1 = ((stage_v_167_1 + pub_r000032_4_1) + 21) & 127;
  int stage_v_439_2 = ((stage_v_167_2 + pub_r000032_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_439_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_439_2) & 255;
  int stage_v_440_1 = ((stage_v_376_1 + pub_r000032_2_1) + 25) & 127;
  int stage_v_440_2 = ((stage_v_376_2 + pub_r000032_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_440_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_440_2) & 255;
  int stage_v_441_1 = ((stage_v_426_1 + pub_r000032_14_1) + 35) & 127;
  int stage_v_441_2 = ((stage_v_426_2 + pub_r000032_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_441_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_441_2) & 255;
  int stage_v_442_1 = ((stage_v_216_1 + pub_r000032_15_1) + 49) & 127;
  int stage_v_442_2 = ((stage_v_216_2 + pub_r000032_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_442_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_442_2) & 255;
  int stage_v_443_1 = ((sec_r000032_1_1 + pub_r000032_1_1) + 34) & 127;
  int stage_v_443_2 = ((sec_r000032_1_2 + pub_r000032_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_443_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_443_2) & 255;
  int stage_v_444_1 = ((sec_r000032_2_1 + pub_r000032_6_1) + 6) & 127;
  int stage_v_444_2 = ((sec_r000032_2_2 + pub_r000032_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_444_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_444_2) & 255;
  int stage_v_445_1 = ((stage_v_356_1 + pub_r000032_8_1) + 40) & 127;
  int stage_v_445_2 = ((stage_v_356_2 + pub_r000032_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_445_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_445_2) & 255;
  int stage_v_446_1 = ((sec_r000032_7_1 + pub_r000032_12_1) + 30) & 127;
  int stage_v_446_2 = ((sec_r000032_7_2 + pub_r000032_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_446_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_446_2) & 255;
  int stage_v_447_1 = ((sec_r000032_1_1 + pub_r000032_12_1) + 23) & 127;
  int stage_v_447_2 = ((sec_r000032_1_2 + pub_r000032_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_447_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_447_2) & 255;
  int stage_v_448_1 = ((stage_v_442_1 + pub_r000032_3_1) + 33) & 127;
  int stage_v_448_2 = ((stage_v_442_2 + pub_r000032_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_448_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_448_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000032_4_1 == pub_r000032_4_2);
  __CPROVER_assume(sec_r000032_2_1 != sec_r000032_2_2);
  __CPROVER_assume(sec_r000032_18_1 != sec_r000032_18_2);
  __CPROVER_assume(pub_r000032_9_1 == pub_r000032_9_2);
  __CPROVER_assume(pub_r000032_10_1 == pub_r000032_10_2);
  __CPROVER_assume(pub_r000032_11_1 == pub_r000032_11_2);
  __CPROVER_assume(sec_r000032_6_1 != sec_r000032_6_2);
  __CPROVER_assume(sec_r000032_0_1 != sec_r000032_0_2);
  __CPROVER_assume(pub_r000032_12_1 == pub_r000032_12_2);
  __CPROVER_assume(sec_r000032_10_1 != sec_r000032_10_2);
  __CPROVER_assume(sec_r000032_16_1 != sec_r000032_16_2);
  __CPROVER_assume(sec_r000032_17_1 != sec_r000032_17_2);
  __CPROVER_assume(pub_r000032_3_1 == pub_r000032_3_2);
  __CPROVER_assume(sec_r000032_9_1 != sec_r000032_9_2);
  __CPROVER_assume(pub_r000032_14_1 == pub_r000032_14_2);
  __CPROVER_assume(sec_r000032_15_1 != sec_r000032_15_2);
  __CPROVER_assume(pub_r000032_7_1 == pub_r000032_7_2);
  __CPROVER_assume(sec_r000032_4_1 != sec_r000032_4_2);
  __CPROVER_assume(sec_r000032_12_1 != sec_r000032_12_2);
  __CPROVER_assume(sec_r000032_3_1 != sec_r000032_3_2);
  __CPROVER_assume(pub_r000032_8_1 == pub_r000032_8_2);
  __CPROVER_assume(sec_r000032_13_1 != sec_r000032_13_2);
  __CPROVER_assume(sec_r000032_1_1 != sec_r000032_1_2);
  __CPROVER_assume(pub_r000032_1_1 == pub_r000032_1_2);
  __CPROVER_assume(sec_r000032_7_1 != sec_r000032_7_2);
  __CPROVER_assume(sec_r000032_5_1 != sec_r000032_5_2);
  __CPROVER_assume(pub_r000032_16_1 == pub_r000032_16_2);
  __CPROVER_assume(sec_r000032_11_1 != sec_r000032_11_2);
  __CPROVER_assume(pub_r000032_6_1 == pub_r000032_6_2);
  __CPROVER_assume(pub_r000032_0_1 == pub_r000032_0_2);
  __CPROVER_assume(pub_r000032_13_1 == pub_r000032_13_2);
  __CPROVER_assume(sec_r000032_14_1 != sec_r000032_14_2);
  __CPROVER_assume(pub_r000032_5_1 == pub_r000032_5_2);
  __CPROVER_assume(pub_r000032_15_1 == pub_r000032_15_2);
  __CPROVER_assume(pub_r000032_2_1 == pub_r000032_2_2);
  __CPROVER_assume(sec_r000032_8_1 != sec_r000032_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.code == st_var_3_2.code);
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
}


