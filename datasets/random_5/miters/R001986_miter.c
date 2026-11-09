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
struct Vector3D_R001986_8613_0
{
  int coord_z;
  int coord_x;
  int coord_y;
  int norm_sq;
  int heading;
  short pitch;
  int buffer[3];
};
struct EventLog_R001986_8613_1
{
  short code;
  int signature;
  int seq;
  int severity;
  int buffer[3];
};
struct CipherContext_R001986_8613_2
{
  int iv;
  short tag;
  unsigned char nonce;
  int buffer[3];
};
union PacketPayload_R001986_8613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001986_8613_1
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
void fn_R001986_8613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tracker_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_29_1) & 63;
  aux_2 = (aux_2 + tracker_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_88_1 = 0;
  int mask_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_88_1 = ((mask_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_88_2 = ((mask_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_88_1) & 127;
    acc_2 = (acc_2 + mask_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_29_1 == tracker_29_2);
  assert(mask_88_1 == mask_88_2);
}

int fn_R001986_8613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tracker_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_29) & 63;
  acc ^= aux;
  int mask_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_88 = ((mask_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001986_8613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quantum_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_78_1) & 63;
  aux_2 = (aux_2 + quantum_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_68_1 = 0;
  int offset_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_68_1 = ((offset_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_68_2 = ((offset_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_68_1) & 127;
    acc_2 = (acc_2 + offset_68_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_78_1 == quantum_78_2);
  assert(offset_68_1 == offset_68_2);
}

int fn_R001986_8613_1(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quantum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_78) & 63;
  acc ^= aux;
  int offset_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_68 = ((offset_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_68) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001986_8613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_60_1 = 0;
  int parity_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_60_1 = ((parity_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_60_2 = ((parity_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_60_1) & 127;
    acc_2 = (acc_2 + parity_60_2) & 127;
  }

  int metric_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_58_1) & 63;
  aux_2 = (aux_2 + metric_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_53_1)
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

  switch (index_reg_53_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_60_1 == parity_60_2);
  assert(metric_58_1 == metric_58_2);
  assert(index_reg_53_1 == index_reg_53_2);
}

int fn_R001986_8613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_60 = ((parity_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_60) & 127;
  }

  int metric_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_58) & 63;
  acc ^= aux;
  int index_reg_53 = (aux + st.buffer[1]) & 3;
  switch (index_reg_53)
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

void fn_R001986_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_49_1 > 37)
  {
    acc_1 = ((acc_1 + (stride_49_1 * 2)) + 5) & 127;
    aux_1 ^= stride_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_49_2 > 37)
  {
    acc_2 = ((acc_2 + (stride_49_2 * 2)) + 5) & 127;
    aux_2 ^= stride_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_97_1)
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

  switch (offset_97_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_49_1 == stride_49_2);
  assert(offset_97_1 == offset_97_2);
}

int fn_R001986_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_49 > 37)
  {
    acc = ((acc + (stride_49 * 2)) + 5) & 127;
    aux ^= stride_49 & 15;
  }
  else
  {
    acc = ((acc - stride_49) + 11) & 127;
    aux += 3;
  }
  int offset_97 = (aux + st.buffer[1]) & 3;
  switch (offset_97)
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

void fn_R001986_8613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_84_1) & 63;
  aux_2 = (aux_2 + anchor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_84_1 == anchor_84_2);
}

int fn_R001986_8613_4(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_84) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001986_8613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_21_1)
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

  switch (anchor_21_2)
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

  int parity_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_64_1) & 63;
  aux_2 = (aux_2 + parity_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
  assert(parity_64_1 == parity_64_2);
}

int fn_R001986_8613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_21 = (aux + st.buffer[1]) & 3;
  switch (anchor_21)
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

  int parity_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001986_8613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_14_1)
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

  switch (scale_14_2)
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

  int bound_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_35_1) & 63;
  aux_2 = (aux_2 + bound_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_14_1 == scale_14_2);
  assert(bound_35_1 == bound_35_2);
}

int fn_R001986_8613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_14 = (aux + st.buffer[1]) & 3;
  switch (scale_14)
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

  int bound_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001986_8613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_61_1)
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

  switch (quantum_61_2)
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

  int weight_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_62_1) & 63;
  aux_2 = (aux_2 + weight_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_73_1 > 46)
  {
    acc_1 = ((acc_1 + (bound_73_1 * 2)) + 5) & 127;
    aux_1 ^= bound_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_73_2 > 46)
  {
    acc_2 = ((acc_2 + (bound_73_2 * 2)) + 5) & 127;
    aux_2 ^= bound_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_61_1 == quantum_61_2);
  assert(weight_62_1 == weight_62_2);
  assert(bound_73_1 == bound_73_2);
}

int fn_R001986_8613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_61 = (aux + st.buffer[1]) & 3;
  switch (quantum_61)
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

  int weight_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_62) & 63;
  acc ^= aux;
  int bound_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_73 > 46)
  {
    acc = ((acc + (bound_73 * 2)) + 5) & 127;
    aux ^= bound_73 & 15;
  }
  else
  {
    acc = ((acc - bound_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001986_8613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_66_1 = local_arr_1[aux_1 % 3];
  int quantum_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_66_2 * 2)) & 127;
  int quotient_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_49_1) & 63;
  aux_2 = (aux_2 + quotient_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_94_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_94_1 * 2)) + 5) & 127;
    aux_1 ^= margin_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_94_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_94_2 * 2)) + 5) & 127;
    aux_2 ^= margin_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_66_1 == quantum_66_2);
  assert(quotient_49_1 == quotient_49_2);
  assert(margin_94_1 == margin_94_2);
}

int fn_R001986_8613_8(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int quantum_66 = local_arr[aux % 3];
  acc = (acc + (quantum_66 * 2)) & 127;
  int quotient_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_49) & 63;
  acc ^= aux;
  int margin_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_94 > 45)
  {
    acc = ((acc + (margin_94 * 2)) + 5) & 127;
    aux ^= margin_94 & 15;
  }
  else
  {
    acc = ((acc - margin_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001986_8613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int checksum_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_41_1) & 63;
  aux_2 = (aux_2 + checksum_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_28_1 = 0;
  int mask_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_28_1 = ((mask_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_28_2 = ((mask_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_28_1) & 127;
    acc_2 = (acc_2 + mask_28_2) & 127;
  }

  int threshold_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_42_1 > 21)
  {
    acc_1 = ((acc_1 + (threshold_42_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_42_2 > 21)
  {
    acc_2 = ((acc_2 + (threshold_42_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_41_1 == checksum_41_2);
  assert(mask_28_1 == mask_28_2);
  assert(threshold_42_1 == threshold_42_2);
}

int fn_R001986_8613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int checksum_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_28 = ((mask_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_28) & 127;
  }

  int threshold_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_42 > 21)
  {
    acc = ((acc + (threshold_42 * 2)) + 5) & 127;
    aux ^= threshold_42 & 15;
  }
  else
  {
    acc = ((acc - threshold_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001986_8613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int sample_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_31_1)
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

  switch (sample_31_2)
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

  int index_reg_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_79_1) & 63;
  aux_2 = (aux_2 + index_reg_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_15_1 > 25)
  {
    acc_1 = ((acc_1 + (tally_15_1 * 2)) + 5) & 127;
    aux_1 ^= tally_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_15_2 > 25)
  {
    acc_2 = ((acc_2 + (tally_15_2 * 2)) + 5) & 127;
    aux_2 ^= tally_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_90_1 = local_arr_1[aux_1 % 3];
  int mask_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_31_1 == sample_31_2);
  assert(index_reg_79_1 == index_reg_79_2);
  assert(tally_15_1 == tally_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_90_1 == mask_90_2);
}

int fn_R001986_8613_10(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int sample_31 = (aux + st.buffer[1]) & 3;
  switch (sample_31)
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

  int index_reg_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_79) & 63;
  acc ^= aux;
  int tally_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_15 > 25)
  {
    acc = ((acc + (tally_15 * 2)) + 5) & 127;
    aux ^= tally_15 & 15;
  }
  else
  {
    acc = ((acc - tally_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_90 = local_arr[aux % 3];
  acc = (acc + (mask_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001986_8613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_97_1) & 63;
  aux_2 = (aux_2 + vector_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_30_1 = 0;
  int mask_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_30_1 = ((mask_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_30_2 = ((mask_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_30_1) & 127;
    acc_2 = (acc_2 + mask_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_97_1 == vector_97_2);
  assert(mask_30_1 == mask_30_2);
}

int fn_R001986_8613_11(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_97) & 63;
  acc ^= aux;
  int mask_30 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_30 = ((mask_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001986_8613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_21_1 = 0;
  int bound_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_21_1 = ((bound_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_21_2 = ((bound_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_21_1) & 127;
    acc_2 = (acc_2 + bound_21_2) & 127;
  }

  int threshold_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_34_1) & 63;
  aux_2 = (aux_2 + threshold_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_47_1)
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

  switch (cursor_47_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_21_1 == bound_21_2);
  assert(threshold_34_1 == threshold_34_2);
  assert(cursor_47_1 == cursor_47_2);
}

int fn_R001986_8613_12(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_21 = ((bound_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_21) & 127;
  }

  int threshold_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_34) & 63;
  acc ^= aux;
  int cursor_47 = (aux + st.buffer[1]) & 3;
  switch (cursor_47)
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

void fn_R001986_8613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_88_1)
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

  switch (factor_88_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_88_1 == factor_88_2);
}

int fn_R001986_8613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_88 = (aux + st.buffer[1]) & 3;
  switch (factor_88)
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

void fn_R001986_8613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_40_1 > 33)
  {
    acc_1 = ((acc_1 + (stride_40_1 * 2)) + 5) & 127;
    aux_1 ^= stride_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_40_2 > 33)
  {
    acc_2 = ((acc_2 + (stride_40_2 * 2)) + 5) & 127;
    aux_2 ^= stride_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_39_1 = local_arr_1[aux_1 % 3];
  int residue_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_39_2 * 2)) & 127;
  int margin_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_82_1)
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

  switch (margin_82_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_40_1 == stride_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_39_1 == residue_39_2);
  assert(margin_82_1 == margin_82_2);
}

int fn_R001986_8613_14(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_40 > 33)
  {
    acc = ((acc + (stride_40 * 2)) + 5) & 127;
    aux ^= stride_40 & 15;
  }
  else
  {
    acc = ((acc - stride_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_39 = local_arr[aux % 3];
  acc = (acc + (residue_39 * 2)) & 127;
  int margin_82 = (aux + st.buffer[1]) & 3;
  switch (margin_82)
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

void fn_R001986_8613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
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
  int weight_42_1 = 0;
  int weight_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_42_1 = ((weight_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_42_2 = ((weight_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_42_1) & 127;
    acc_2 = (acc_2 + weight_42_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_25_1 = local_arr_1[aux_1 % 3];
  int margin_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_25_2 * 2)) & 127;
  int bound_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_96_1) & 63;
  aux_2 = (aux_2 + bound_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_42_1 == weight_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_25_1 == margin_25_2);
  assert(bound_96_1 == bound_96_2);
}

int fn_R001986_8613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_42 = ((weight_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_42) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int margin_25 = local_arr[aux % 3];
  acc = (acc + (margin_25 * 2)) & 127;
  int bound_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001986_8613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_25_1) & 63;
  aux_2 = (aux_2 + residue_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_86_1 = 0;
  int mask_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_86_1 = ((mask_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_86_2 = ((mask_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_86_1) & 127;
    acc_2 = (acc_2 + mask_86_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_77_1 = local_arr_1[aux_1 % 3];
  int threshold_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_77_2 * 2)) & 127;
  int sample_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_34_1 > 22)
  {
    acc_1 = ((acc_1 + (sample_34_1 * 2)) + 5) & 127;
    aux_1 ^= sample_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_34_2 > 22)
  {
    acc_2 = ((acc_2 + (sample_34_2 * 2)) + 5) & 127;
    aux_2 ^= sample_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_25_1 == residue_25_2);
  assert(mask_86_1 == mask_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_77_1 == threshold_77_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001986_8613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_25) & 63;
  acc ^= aux;
  int mask_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_86 = ((mask_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_86) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_77 = local_arr[aux % 3];
  acc = (acc + (threshold_77 * 2)) & 127;
  int sample_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_34 > 22)
  {
    acc = ((acc + (sample_34 * 2)) + 5) & 127;
    aux ^= sample_34 & 15;
  }
  else
  {
    acc = ((acc - sample_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001986_8613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_63_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_63_1 * 2)) + 5) & 127;
    aux_1 ^= delta_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_63_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_63_2 * 2)) + 5) & 127;
    aux_2 ^= delta_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_23_1)
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

  switch (scale_23_2)
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
  int quantum_46_1 = local_arr_1[aux_1 % 3];
  int quantum_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_63_1 == delta_63_2);
  assert(scale_23_1 == scale_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_46_1 == quantum_46_2);
}

int fn_R001986_8613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_63 > 19)
  {
    acc = ((acc + (delta_63 * 2)) + 5) & 127;
    aux ^= delta_63 & 15;
  }
  else
  {
    acc = ((acc - delta_63) + 11) & 127;
    aux += 3;
  }
  int scale_23 = (aux + st.buffer[1]) & 3;
  switch (scale_23)
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
  int quantum_46 = local_arr[aux % 3];
  acc = (acc + (quantum_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001986_8613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_21_1 = 0;
  int anchor_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_21_1 = ((anchor_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_21_2 = ((anchor_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_21_1) & 127;
    acc_2 = (acc_2 + anchor_21_2) & 127;
  }

  int segment_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_24_1) & 63;
  aux_2 = (aux_2 + segment_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
  assert(segment_24_1 == segment_24_2);
}

int fn_R001986_8613_18(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_21 = ((anchor_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_21) & 127;
  }

  int segment_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001986_8613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_70_1)
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

  switch (stride_70_2)
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

  int tally_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_27_1 > 48)
  {
    acc_1 = ((acc_1 + (tally_27_1 * 2)) + 5) & 127;
    aux_1 ^= tally_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_27_2 > 48)
  {
    acc_2 = ((acc_2 + (tally_27_2 * 2)) + 5) & 127;
    aux_2 ^= tally_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_48_1) & 63;
  aux_2 = (aux_2 + delta_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_70_1 == stride_70_2);
  assert(tally_27_1 == tally_27_2);
  assert(delta_48_1 == delta_48_2);
}

int fn_R001986_8613_19(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_70 = (aux + st.buffer[1]) & 3;
  switch (stride_70)
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

  int tally_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_27 > 48)
  {
    acc = ((acc + (tally_27 * 2)) + 5) & 127;
    aux ^= tally_27 & 15;
  }
  else
  {
    acc = ((acc - tally_27) + 11) & 127;
    aux += 3;
  }
  int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001986_8613_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st_1 = {0};
  struct Vector3D_R001986_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_56_1 = local_arr_1[aux_1 % 3];
  int tally_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_56_2 * 2)) & 127;
  int threshold_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_45_1)
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

  switch (threshold_45_2)
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

  int phase_80_1 = 0;
  int phase_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_80_1 = ((phase_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_80_2 = ((phase_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_80_1) & 127;
    acc_2 = (acc_2 + phase_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_56_1 == tally_56_2);
  assert(threshold_45_1 == threshold_45_2);
  assert(phase_80_1 == phase_80_2);
}

int fn_R001986_8613_20(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001986_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int tally_56 = local_arr[aux % 3];
  acc = (acc + (tally_56 * 2)) & 127;
  int threshold_45 = (aux + st.buffer[1]) & 3;
  switch (threshold_45)
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

  int phase_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_80 = ((phase_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001986_8613_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st_1 = {0};
  struct CipherContext_R001986_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_95_1 = 0;
  int bound_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_95_1 = ((bound_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_95_2 = ((bound_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_95_1) & 127;
    acc_2 = (acc_2 + bound_95_2) & 127;
  }

  int damping_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_71_1 > 19)
  {
    acc_1 = ((acc_1 + (damping_71_1 * 2)) + 5) & 127;
    aux_1 ^= damping_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_71_2 > 19)
  {
    acc_2 = ((acc_2 + (damping_71_2 * 2)) + 5) & 127;
    aux_2 ^= damping_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_26_1) & 63;
  aux_2 = (aux_2 + delta_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_95_1 == bound_95_2);
  assert(damping_71_1 == damping_71_2);
  assert(delta_26_1 == delta_26_2);
}

int fn_R001986_8613_21(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001986_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_95 = ((bound_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_95) & 127;
  }

  int damping_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_71 > 19)
  {
    acc = ((acc + (damping_71 * 2)) + 5) & 127;
    aux ^= damping_71 & 15;
  }
  else
  {
    acc = ((acc - damping_71) + 11) & 127;
    aux += 3;
  }
  int delta_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001986_8613_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st_1 = {0};
  struct EventLog_R001986_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_72_1 = local_arr_1[aux_1 % 3];
  int coefficient_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_72_2 * 2)) & 127;
  int scale_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_34_1)
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

  switch (scale_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_72_1 = 0;
  int weight_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_72_1 = ((weight_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_72_2 = ((weight_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_72_1) & 127;
    acc_2 = (acc_2 + weight_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_72_1 == coefficient_72_2);
  assert(scale_34_1 == scale_34_2);
  assert(weight_72_1 == weight_72_2);
}

int fn_R001986_8613_22(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001986_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int coefficient_72 = local_arr[aux % 3];
  acc = (acc + (coefficient_72 * 2)) & 127;
  int scale_34 = (aux + st.buffer[1]) & 3;
  switch (scale_34)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_72 = ((weight_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_72) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001986_0_1;
  int sec_r001986_0_2;
  int sec_r001986_1_1;
  int sec_r001986_1_2;
  int sec_r001986_2_1;
  int sec_r001986_2_2;
  int sec_r001986_3_1;
  int sec_r001986_3_2;
  int sec_r001986_4_1;
  int sec_r001986_4_2;
  int sec_r001986_5_1;
  int sec_r001986_5_2;
  int sec_r001986_6_1;
  int sec_r001986_6_2;
  int sec_r001986_7_1;
  int sec_r001986_7_2;
  int sec_r001986_8_1;
  int sec_r001986_8_2;
  int sec_r001986_9_1;
  int sec_r001986_9_2;
  int sec_r001986_10_1;
  int sec_r001986_10_2;
  int sec_r001986_11_1;
  int sec_r001986_11_2;
  int sec_r001986_12_1;
  int sec_r001986_12_2;
  int sec_r001986_13_1;
  int sec_r001986_13_2;
  int sec_r001986_14_1;
  int sec_r001986_14_2;
  int sec_r001986_15_1;
  int sec_r001986_15_2;
  int sec_r001986_16_1;
  int sec_r001986_16_2;
  int pub_r001986_0_1;
  int pub_r001986_0_2;
  int pub_r001986_1_1;
  int pub_r001986_1_2;
  int pub_r001986_2_1;
  int pub_r001986_2_2;
  int pub_r001986_3_1;
  int pub_r001986_3_2;
  int pub_r001986_4_1;
  int pub_r001986_4_2;
  int pub_r001986_5_1;
  int pub_r001986_5_2;
  int pub_r001986_6_1;
  int pub_r001986_6_2;
  int pub_r001986_7_1;
  int pub_r001986_7_2;
  int pub_r001986_8_1;
  int pub_r001986_8_2;
  int pub_r001986_9_1;
  int pub_r001986_9_2;
  int pub_r001986_10_1;
  int pub_r001986_10_2;
  int pub_r001986_11_1;
  int pub_r001986_11_2;
  int pub_r001986_12_1;
  int pub_r001986_12_2;
  int pub_r001986_13_1;
  int pub_r001986_13_2;
  int pub_r001986_14_1;
  int pub_r001986_14_2;
  int pub_r001986_15_1;
  int pub_r001986_15_2;
  int pub_r001986_16_1;
  int pub_r001986_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001986_0_1 >= (-100)) && (pub_r001986_0_1 <= 100));
  __CPROVER_assume((pub_r001986_0_2 >= (-100)) && (pub_r001986_0_2 <= 100));
  __CPROVER_assume((pub_r001986_1_1 >= (-100)) && (pub_r001986_1_1 <= 100));
  __CPROVER_assume((pub_r001986_1_2 >= (-100)) && (pub_r001986_1_2 <= 100));
  __CPROVER_assume((pub_r001986_2_1 >= (-100)) && (pub_r001986_2_1 <= 100));
  __CPROVER_assume((pub_r001986_2_2 >= (-100)) && (pub_r001986_2_2 <= 100));
  __CPROVER_assume((pub_r001986_3_1 >= (-100)) && (pub_r001986_3_1 <= 100));
  __CPROVER_assume((pub_r001986_3_2 >= (-100)) && (pub_r001986_3_2 <= 100));
  __CPROVER_assume((pub_r001986_4_1 >= (-100)) && (pub_r001986_4_1 <= 100));
  __CPROVER_assume((pub_r001986_4_2 >= (-100)) && (pub_r001986_4_2 <= 100));
  __CPROVER_assume((pub_r001986_5_1 >= (-100)) && (pub_r001986_5_1 <= 100));
  __CPROVER_assume((pub_r001986_5_2 >= (-100)) && (pub_r001986_5_2 <= 100));
  __CPROVER_assume((pub_r001986_6_1 >= (-100)) && (pub_r001986_6_1 <= 100));
  __CPROVER_assume((pub_r001986_6_2 >= (-100)) && (pub_r001986_6_2 <= 100));
  __CPROVER_assume((pub_r001986_7_1 >= (-100)) && (pub_r001986_7_1 <= 100));
  __CPROVER_assume((pub_r001986_7_2 >= (-100)) && (pub_r001986_7_2 <= 100));
  __CPROVER_assume((pub_r001986_8_1 >= (-100)) && (pub_r001986_8_1 <= 100));
  __CPROVER_assume((pub_r001986_8_2 >= (-100)) && (pub_r001986_8_2 <= 100));
  __CPROVER_assume((pub_r001986_9_1 >= (-100)) && (pub_r001986_9_1 <= 100));
  __CPROVER_assume((pub_r001986_9_2 >= (-100)) && (pub_r001986_9_2 <= 100));
  __CPROVER_assume((pub_r001986_10_1 >= (-100)) && (pub_r001986_10_1 <= 100));
  __CPROVER_assume((pub_r001986_10_2 >= (-100)) && (pub_r001986_10_2 <= 100));
  __CPROVER_assume((pub_r001986_11_1 >= (-100)) && (pub_r001986_11_1 <= 100));
  __CPROVER_assume((pub_r001986_11_2 >= (-100)) && (pub_r001986_11_2 <= 100));
  __CPROVER_assume((pub_r001986_12_1 >= (-100)) && (pub_r001986_12_1 <= 100));
  __CPROVER_assume((pub_r001986_12_2 >= (-100)) && (pub_r001986_12_2 <= 100));
  __CPROVER_assume((pub_r001986_13_1 >= (-100)) && (pub_r001986_13_1 <= 100));
  __CPROVER_assume((pub_r001986_13_2 >= (-100)) && (pub_r001986_13_2 <= 100));
  __CPROVER_assume((pub_r001986_14_1 >= (-100)) && (pub_r001986_14_1 <= 100));
  __CPROVER_assume((pub_r001986_14_2 >= (-100)) && (pub_r001986_14_2 <= 100));
  __CPROVER_assume((pub_r001986_15_1 >= (-100)) && (pub_r001986_15_1 <= 100));
  __CPROVER_assume((pub_r001986_15_2 >= (-100)) && (pub_r001986_15_2 <= 100));
  __CPROVER_assume((pub_r001986_16_1 >= (-100)) && (pub_r001986_16_1 <= 100));
  __CPROVER_assume((pub_r001986_16_2 >= (-100)) && (pub_r001986_16_2 <= 100));
  __CPROVER_assume((sec_r001986_0_1 >= 0) && (sec_r001986_0_1 <= 255));
  __CPROVER_assume((sec_r001986_0_2 >= 0) && (sec_r001986_0_2 <= 255));
  __CPROVER_assume((sec_r001986_1_1 >= 0) && (sec_r001986_1_1 <= 255));
  __CPROVER_assume((sec_r001986_1_2 >= 0) && (sec_r001986_1_2 <= 255));
  __CPROVER_assume((sec_r001986_2_1 >= 0) && (sec_r001986_2_1 <= 255));
  __CPROVER_assume((sec_r001986_2_2 >= 0) && (sec_r001986_2_2 <= 255));
  __CPROVER_assume((sec_r001986_3_1 >= 0) && (sec_r001986_3_1 <= 255));
  __CPROVER_assume((sec_r001986_3_2 >= 0) && (sec_r001986_3_2 <= 255));
  __CPROVER_assume((sec_r001986_4_1 >= 0) && (sec_r001986_4_1 <= 255));
  __CPROVER_assume((sec_r001986_4_2 >= 0) && (sec_r001986_4_2 <= 255));
  __CPROVER_assume((sec_r001986_5_1 >= 0) && (sec_r001986_5_1 <= 255));
  __CPROVER_assume((sec_r001986_5_2 >= 0) && (sec_r001986_5_2 <= 255));
  __CPROVER_assume((sec_r001986_6_1 >= 0) && (sec_r001986_6_1 <= 255));
  __CPROVER_assume((sec_r001986_6_2 >= 0) && (sec_r001986_6_2 <= 255));
  __CPROVER_assume((sec_r001986_7_1 >= 0) && (sec_r001986_7_1 <= 255));
  __CPROVER_assume((sec_r001986_7_2 >= 0) && (sec_r001986_7_2 <= 255));
  __CPROVER_assume((sec_r001986_8_1 >= 0) && (sec_r001986_8_1 <= 255));
  __CPROVER_assume((sec_r001986_8_2 >= 0) && (sec_r001986_8_2 <= 255));
  __CPROVER_assume((sec_r001986_9_1 >= 0) && (sec_r001986_9_1 <= 255));
  __CPROVER_assume((sec_r001986_9_2 >= 0) && (sec_r001986_9_2 <= 255));
  __CPROVER_assume((sec_r001986_10_1 >= 0) && (sec_r001986_10_1 <= 255));
  __CPROVER_assume((sec_r001986_10_2 >= 0) && (sec_r001986_10_2 <= 255));
  __CPROVER_assume((sec_r001986_11_1 >= 0) && (sec_r001986_11_1 <= 255));
  __CPROVER_assume((sec_r001986_11_2 >= 0) && (sec_r001986_11_2 <= 255));
  __CPROVER_assume((sec_r001986_12_1 >= 0) && (sec_r001986_12_1 <= 255));
  __CPROVER_assume((sec_r001986_12_2 >= 0) && (sec_r001986_12_2 <= 255));
  __CPROVER_assume((sec_r001986_13_1 >= 0) && (sec_r001986_13_1 <= 255));
  __CPROVER_assume((sec_r001986_13_2 >= 0) && (sec_r001986_13_2 <= 255));
  __CPROVER_assume((sec_r001986_14_1 >= 0) && (sec_r001986_14_1 <= 255));
  __CPROVER_assume((sec_r001986_14_2 >= 0) && (sec_r001986_14_2 <= 255));
  __CPROVER_assume((sec_r001986_15_1 >= 0) && (sec_r001986_15_1 <= 255));
  __CPROVER_assume((sec_r001986_15_2 >= 0) && (sec_r001986_15_2 <= 255));
  __CPROVER_assume((sec_r001986_16_1 >= 0) && (sec_r001986_16_1 <= 255));
  __CPROVER_assume((sec_r001986_16_2 >= 0) && (sec_r001986_16_2 <= 255));
  struct Vector3D_R001986_8613_0 st_var_0_1 = {0};
  struct Vector3D_R001986_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001986_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001986_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001986_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001986_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001986_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001986_0_2 + 7) & 15;
  struct EventLog_R001986_8613_1 st_var_1_1 = {0};
  struct EventLog_R001986_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001986_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001986_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001986_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001986_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001986_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001986_0_2 + 9) & 15;
  struct CipherContext_R001986_8613_2 st_var_2_1 = {0};
  struct CipherContext_R001986_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001986_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001986_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001986_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001986_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001986_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001986_0_2 + 11) & 15;
  union PacketPayload_R001986_8613_0 u_var_1;
  union PacketPayload_R001986_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001986_8613_0(sec_r001986_0_1, pub_r001986_1_1, pub_r001986_2_1, pub_r001986_3_1);
  int helper_flow_0_2 = fn_R001986_8613_0(sec_r001986_0_2, pub_r001986_1_2, pub_r001986_2_2, pub_r001986_3_2);
  fn_R001986_8613_0_2(sec_r001986_0_1, pub_r001986_1_1, pub_r001986_2_1, pub_r001986_3_1, sec_r001986_0_2, pub_r001986_1_2, pub_r001986_2_2, pub_r001986_3_2);
  int helper_flow_1_1 = fn_R001986_8613_1(sec_r001986_1_1, pub_r001986_2_1);
  int helper_flow_1_2 = fn_R001986_8613_1(sec_r001986_1_2, pub_r001986_2_2);
  fn_R001986_8613_1_2(sec_r001986_1_1, pub_r001986_2_1, sec_r001986_1_2, pub_r001986_2_2);
  int helper_flow_2_1 = fn_R001986_8613_2(sec_r001986_2_1, pub_r001986_3_1, pub_r001986_4_1, pub_r001986_5_1);
  int helper_flow_2_2 = fn_R001986_8613_2(sec_r001986_2_2, pub_r001986_3_2, pub_r001986_4_2, pub_r001986_5_2);
  fn_R001986_8613_2_2(sec_r001986_2_1, pub_r001986_3_1, pub_r001986_4_1, pub_r001986_5_1, sec_r001986_2_2, pub_r001986_3_2, pub_r001986_4_2, pub_r001986_5_2);
  int helper_flow_3_1 = fn_R001986_8613_3(sec_r001986_3_1, pub_r001986_4_1, pub_r001986_5_1, pub_r001986_6_1, pub_r001986_7_1);
  int helper_flow_3_2 = fn_R001986_8613_3(sec_r001986_3_2, pub_r001986_4_2, pub_r001986_5_2, pub_r001986_6_2, pub_r001986_7_2);
  fn_R001986_8613_3_2(sec_r001986_3_1, pub_r001986_4_1, pub_r001986_5_1, pub_r001986_6_1, pub_r001986_7_1, sec_r001986_3_2, pub_r001986_4_2, pub_r001986_5_2, pub_r001986_6_2, pub_r001986_7_2);
  int helper_flow_4_1 = fn_R001986_8613_4(sec_r001986_4_1, sec_r001986_5_1);
  int helper_flow_4_2 = fn_R001986_8613_4(sec_r001986_4_2, sec_r001986_5_2);
  fn_R001986_8613_4_2(sec_r001986_4_1, sec_r001986_5_1, sec_r001986_4_2, sec_r001986_5_2);
  int helper_flow_5_1 = fn_R001986_8613_5(sec_r001986_5_1, sec_r001986_6_1, pub_r001986_7_1, pub_r001986_8_1);
  int helper_flow_5_2 = fn_R001986_8613_5(sec_r001986_5_2, sec_r001986_6_2, pub_r001986_7_2, pub_r001986_8_2);
  fn_R001986_8613_5_2(sec_r001986_5_1, sec_r001986_6_1, pub_r001986_7_1, pub_r001986_8_1, sec_r001986_5_2, sec_r001986_6_2, pub_r001986_7_2, pub_r001986_8_2);
  int helper_flow_6_1 = fn_R001986_8613_6(sec_r001986_6_1, pub_r001986_7_1, pub_r001986_8_1, pub_r001986_9_1, pub_r001986_10_1);
  int helper_flow_6_2 = fn_R001986_8613_6(sec_r001986_6_2, pub_r001986_7_2, pub_r001986_8_2, pub_r001986_9_2, pub_r001986_10_2);
  fn_R001986_8613_6_2(sec_r001986_6_1, pub_r001986_7_1, pub_r001986_8_1, pub_r001986_9_1, pub_r001986_10_1, sec_r001986_6_2, pub_r001986_7_2, pub_r001986_8_2, pub_r001986_9_2, pub_r001986_10_2);
  int helper_flow_7_1 = fn_R001986_8613_7(sec_r001986_7_1, sec_r001986_8_1, pub_r001986_9_1, pub_r001986_10_1);
  int helper_flow_7_2 = fn_R001986_8613_7(sec_r001986_7_2, sec_r001986_8_2, pub_r001986_9_2, pub_r001986_10_2);
  fn_R001986_8613_7_2(sec_r001986_7_1, sec_r001986_8_1, pub_r001986_9_1, pub_r001986_10_1, sec_r001986_7_2, sec_r001986_8_2, pub_r001986_9_2, pub_r001986_10_2);
  int helper_flow_8_1 = fn_R001986_8613_8(sec_r001986_8_1, pub_r001986_9_1);
  int helper_flow_8_2 = fn_R001986_8613_8(sec_r001986_8_2, pub_r001986_9_2);
  fn_R001986_8613_8_2(sec_r001986_8_1, pub_r001986_9_1, sec_r001986_8_2, pub_r001986_9_2);
  int stage_v_0_1 = ((helper_flow_7_1 + (pub_r001986_10_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_7_2 + (pub_r001986_10_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_8_1 + (pub_r001986_2_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_8_2 + (pub_r001986_2_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001986_1_1 * 2) + 44) & 63;
  int stage_v_2_2 = ((pub_r001986_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001986_5_1 * 2) + 17) & 63;
  int stage_v_3_2 = ((pub_r001986_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001986_16_1 + (pub_r001986_11_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001986_16_2 + (pub_r001986_11_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((stage_v_1_1 + (pub_r001986_10_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((stage_v_1_2 + (pub_r001986_10_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((stage_v_1_1 + (pub_r001986_0_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((stage_v_1_2 + (pub_r001986_0_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001986_15_1 + (pub_r001986_14_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001986_15_2 + (pub_r001986_14_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001986_5_1 * 2) + 28) & 63;
  int stage_v_8_2 = ((pub_r001986_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001986_14_1 * 2) + 12) & 63;
  int stage_v_9_2 = ((pub_r001986_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001986_10_1 * 2) + 48) & 63;
  int stage_v_10_2 = ((pub_r001986_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001986_5_1 * 2) + 36) & 63;
  int stage_v_11_2 = ((pub_r001986_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001986_4_1 * 2) + 9) & 63;
  int stage_v_12_2 = ((pub_r001986_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001986_10_1 + (pub_r001986_6_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001986_10_2 + (pub_r001986_6_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001986_4_1 * 2) + 35) & 63;
  int stage_v_14_2 = ((pub_r001986_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001986_2_1 * 2) + 34) & 63;
  int stage_v_15_2 = ((pub_r001986_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001986_8_1 * 2) + 31) & 63;
  int stage_v_16_2 = ((pub_r001986_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((helper_flow_3_1 + (pub_r001986_10_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_3_2 + (pub_r001986_10_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001986_12_1 * 2) + 37) & 63;
  int stage_v_18_2 = ((pub_r001986_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((helper_flow_7_1 + (pub_r001986_16_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_7_2 + (pub_r001986_16_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_13_1 + (pub_r001986_16_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_13_2 + (pub_r001986_16_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001986_4_1 + (pub_r001986_6_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001986_4_2 + (pub_r001986_6_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001986_3_1 + (pub_r001986_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001986_3_2 + (pub_r001986_14_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((sec_r001986_4_1 + (pub_r001986_11_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001986_4_2 + (pub_r001986_11_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((helper_flow_0_1 + (pub_r001986_13_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((helper_flow_0_2 + (pub_r001986_13_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((sec_r001986_12_1 + (pub_r001986_15_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001986_12_2 + (pub_r001986_15_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((sec_r001986_4_1 + (pub_r001986_5_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001986_4_2 + (pub_r001986_5_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001986_3_1 + (pub_r001986_12_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001986_3_2 + (pub_r001986_12_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_1_1 + (pub_r001986_15_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_1_2 + (pub_r001986_15_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001986_0_1 * 2) + 17) & 63;
  int stage_v_29_2 = ((pub_r001986_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((stage_v_4_1 + (pub_r001986_7_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_4_2 + (pub_r001986_7_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((helper_flow_8_1 + (pub_r001986_9_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((helper_flow_8_2 + (pub_r001986_9_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001986_1_1 * 2) + 11) & 63;
  int stage_v_32_2 = ((pub_r001986_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001986_15_1 * 2) + 23) & 63;
  int stage_v_33_2 = ((pub_r001986_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((stage_v_23_1 + (pub_r001986_14_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_23_2 + (pub_r001986_14_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((helper_flow_0_1 + (pub_r001986_11_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_0_2 + (pub_r001986_11_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001986_0_1 * 2) + 8) & 63;
  int stage_v_36_2 = ((pub_r001986_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_0_1 + (pub_r001986_0_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_0_2 + (pub_r001986_0_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_13_1 + (pub_r001986_2_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_13_2 + (pub_r001986_2_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001986_8_1 * 2) + 35) & 63;
  int stage_v_39_2 = ((pub_r001986_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001986_6_1 * 2) + 45) & 63;
  int stage_v_40_2 = ((pub_r001986_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_23_1 + (pub_r001986_13_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_23_2 + (pub_r001986_13_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_0_1 + (pub_r001986_3_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_0_2 + (pub_r001986_3_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_30_1 + (pub_r001986_3_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_30_2 + (pub_r001986_3_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001986_5_1 * 2) + 31) & 63;
  int stage_v_44_2 = ((pub_r001986_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001986_14_1 + (pub_r001986_3_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001986_14_2 + (pub_r001986_3_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001986_2_1 * 2) + 15) & 63;
  int stage_v_46_2 = ((pub_r001986_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_42_1 + (pub_r001986_15_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_42_2 + (pub_r001986_15_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((helper_flow_7_1 + (pub_r001986_12_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((helper_flow_7_2 + (pub_r001986_12_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_37_1 + (pub_r001986_9_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_37_2 + (pub_r001986_9_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((sec_r001986_13_1 + (pub_r001986_2_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001986_13_2 + (pub_r001986_2_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001986_11_1 * 2) + 11) & 63;
  int stage_v_51_2 = ((pub_r001986_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((sec_r001986_4_1 + (pub_r001986_1_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001986_4_2 + (pub_r001986_1_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001986_14_1 * 2) + 17) & 63;
  int stage_v_53_2 = ((pub_r001986_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((helper_flow_7_1 + (pub_r001986_2_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((helper_flow_7_2 + (pub_r001986_2_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_23_1 + (pub_r001986_3_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_23_2 + (pub_r001986_3_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((sec_r001986_10_1 + (pub_r001986_10_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((sec_r001986_10_2 + (pub_r001986_10_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_41_1 + (pub_r001986_9_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_41_2 + (pub_r001986_9_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_4_1 + (pub_r001986_13_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_4_2 + (pub_r001986_13_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001986_13_1 * 2) + 9) & 63;
  int stage_v_59_2 = ((pub_r001986_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_35_1 + (pub_r001986_12_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_35_2 + (pub_r001986_12_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((sec_r001986_5_1 + (pub_r001986_14_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001986_5_2 + (pub_r001986_14_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_43_1 + (pub_r001986_12_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_43_2 + (pub_r001986_12_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_1_1 + (pub_r001986_0_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_1_2 + (pub_r001986_0_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_26_1 + (pub_r001986_4_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_26_2 + (pub_r001986_4_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((helper_flow_5_1 + (pub_r001986_11_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((helper_flow_5_2 + (pub_r001986_11_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((sec_r001986_1_1 + (pub_r001986_1_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001986_1_2 + (pub_r001986_1_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_50_1 + (pub_r001986_11_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_50_2 + (pub_r001986_11_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_64_1 + (pub_r001986_14_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_64_2 + (pub_r001986_14_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001986_2_1 + (pub_r001986_14_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001986_2_2 + (pub_r001986_14_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_20_1 + (pub_r001986_7_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_20_2 + (pub_r001986_7_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((pub_r001986_9_1 * 2) + 48) & 63;
  int stage_v_71_2 = ((pub_r001986_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_28_1 + (pub_r001986_7_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_28_2 + (pub_r001986_7_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001986_8_1 * 2) + 43) & 63;
  int stage_v_73_2 = ((pub_r001986_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_63_1 + (pub_r001986_11_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_63_2 + (pub_r001986_11_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_41_1 + (pub_r001986_16_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_41_2 + (pub_r001986_16_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001986_12_1 * 2) + 16) & 63;
  int stage_v_76_2 = ((pub_r001986_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001986_6_1 * 2) + 37) & 63;
  int stage_v_77_2 = ((pub_r001986_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_72_1 + (pub_r001986_3_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_72_2 + (pub_r001986_3_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001986_6_1 * 2) + 15) & 63;
  int stage_v_79_2 = ((pub_r001986_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001986_1_1 * 2) + 38) & 63;
  int stage_v_80_2 = ((pub_r001986_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001986_14_1 * 2) + 37) & 63;
  int stage_v_81_2 = ((pub_r001986_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001986_1_1 * 2) + 26) & 63;
  int stage_v_82_2 = ((pub_r001986_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((sec_r001986_3_1 + (pub_r001986_5_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001986_3_2 + (pub_r001986_5_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001986_16_1 * 2) + 27) & 63;
  int stage_v_84_2 = ((pub_r001986_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((sec_r001986_5_1 + (pub_r001986_13_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001986_5_2 + (pub_r001986_13_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001986_6_1 * 2) + 7) & 63;
  int stage_v_86_2 = ((pub_r001986_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_23_1 + (pub_r001986_9_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_23_2 + (pub_r001986_9_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001986_1_1 * 2) + 44) & 63;
  int stage_v_88_2 = ((pub_r001986_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001986_14_1 * 2) + 6) & 63;
  int stage_v_89_2 = ((pub_r001986_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_65_1 + (pub_r001986_1_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_65_2 + (pub_r001986_1_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((sec_r001986_5_1 + (pub_r001986_1_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001986_5_2 + (pub_r001986_1_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001986_9_1 + (pub_r001986_15_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001986_9_2 + (pub_r001986_15_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((sec_r001986_0_1 + (pub_r001986_0_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((sec_r001986_0_2 + (pub_r001986_0_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_68_1 + (pub_r001986_9_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_68_2 + (pub_r001986_9_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_90_1 + (pub_r001986_4_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_90_2 + (pub_r001986_4_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001986_14_1 * 2) + 44) & 63;
  int stage_v_96_2 = ((pub_r001986_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001986_6_1 * 2) + 29) & 63;
  int stage_v_97_2 = ((pub_r001986_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_60_1 + (pub_r001986_13_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_60_2 + (pub_r001986_13_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001986_14_1 * 2) + 12) & 63;
  int stage_v_99_2 = ((pub_r001986_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_25_1 + (pub_r001986_1_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_25_2 + (pub_r001986_1_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_26_1 + (pub_r001986_6_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_26_2 + (pub_r001986_6_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_64_1 + (pub_r001986_4_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_64_2 + (pub_r001986_4_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001986_4_1 + (pub_r001986_15_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001986_4_2 + (pub_r001986_15_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((sec_r001986_10_1 + (pub_r001986_9_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((sec_r001986_10_2 + (pub_r001986_9_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_75_1 + (pub_r001986_4_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_75_2 + (pub_r001986_4_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_83_1 + (pub_r001986_12_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_83_2 + (pub_r001986_12_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001986_15_1 * 2) + 40) & 63;
  int stage_v_107_2 = ((pub_r001986_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_41_1 + (pub_r001986_4_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_41_2 + (pub_r001986_4_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_37_1 + (pub_r001986_9_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_37_2 + (pub_r001986_9_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_104_1 + (pub_r001986_4_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_104_2 + (pub_r001986_4_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_69_1 + (pub_r001986_11_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_69_2 + (pub_r001986_11_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_21_1 + (pub_r001986_6_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_21_2 + (pub_r001986_6_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001986_4_1 * 2) + 6) & 63;
  int stage_v_113_2 = ((pub_r001986_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001986_4_1 * 2) + 24) & 63;
  int stage_v_114_2 = ((pub_r001986_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_5_1 + (pub_r001986_16_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_5_2 + (pub_r001986_16_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_0_1 + (pub_r001986_16_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_0_2 + (pub_r001986_16_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_92_1 + (pub_r001986_14_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_92_2 + (pub_r001986_14_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_103_1 + (pub_r001986_15_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_103_2 + (pub_r001986_15_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001986_16_1 * 2) + 8) & 63;
  int stage_v_119_2 = ((pub_r001986_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_45_1 + (pub_r001986_7_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_45_2 + (pub_r001986_7_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((helper_flow_4_1 + (pub_r001986_15_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((helper_flow_4_2 + (pub_r001986_15_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((helper_flow_6_1 + (pub_r001986_6_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((helper_flow_6_2 + (pub_r001986_6_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_102_1 + (pub_r001986_15_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_102_2 + (pub_r001986_15_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_69_1 + (pub_r001986_4_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_69_2 + (pub_r001986_4_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((helper_flow_7_1 + (pub_r001986_14_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((helper_flow_7_2 + (pub_r001986_14_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001986_4_1 * 2) + 29) & 63;
  int stage_v_126_2 = ((pub_r001986_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001986_14_1 * 2) + 25) & 63;
  int stage_v_127_2 = ((pub_r001986_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_13_1 + (pub_r001986_15_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_13_2 + (pub_r001986_15_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_115_1 + (pub_r001986_15_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_115_2 + (pub_r001986_15_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_38_1 + (pub_r001986_2_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_38_2 + (pub_r001986_2_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001986_15_1 * 2) + 43) & 63;
  int stage_v_131_2 = ((pub_r001986_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_17_1 + (pub_r001986_10_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_17_2 + (pub_r001986_10_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_68_1 + (pub_r001986_1_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_68_2 + (pub_r001986_1_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_133_1 + (pub_r001986_8_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_133_2 + (pub_r001986_8_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((helper_flow_7_1 + (pub_r001986_4_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((helper_flow_7_2 + (pub_r001986_4_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_13_1 + (pub_r001986_0_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_13_2 + (pub_r001986_0_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001986_11_1 * 2) + 46) & 63;
  int stage_v_137_2 = ((pub_r001986_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001986_14_1 * 2) + 42) & 63;
  int stage_v_138_2 = ((pub_r001986_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001986_8_1 * 2) + 16) & 63;
  int stage_v_139_2 = ((pub_r001986_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001986_12_1 * 2) + 24) & 63;
  int stage_v_140_2 = ((pub_r001986_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001986_16_1 * 2) + 36) & 63;
  int stage_v_141_2 = ((pub_r001986_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((sec_r001986_8_1 + (pub_r001986_8_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001986_8_2 + (pub_r001986_8_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_115_1 + (pub_r001986_2_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_115_2 + (pub_r001986_2_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001986_13_1 * 2) + 38) & 63;
  int stage_v_144_2 = ((pub_r001986_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_129_1 + (pub_r001986_13_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_129_2 + (pub_r001986_13_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_87_1 + (pub_r001986_8_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_87_2 + (pub_r001986_8_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((sec_r001986_11_1 + (pub_r001986_7_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((sec_r001986_11_2 + (pub_r001986_7_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001986_9_1 * 2) + 18) & 63;
  int stage_v_148_2 = ((pub_r001986_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001986_13_1 * 2) + 27) & 63;
  int stage_v_149_2 = ((pub_r001986_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_48_1 + (pub_r001986_5_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_48_2 + (pub_r001986_5_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((sec_r001986_8_1 + (pub_r001986_8_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((sec_r001986_8_2 + (pub_r001986_8_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_65_1 + (pub_r001986_9_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_65_2 + (pub_r001986_9_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_17_1 + (pub_r001986_10_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_17_2 + (pub_r001986_10_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001986_8_1 * 2) + 8) & 63;
  int stage_v_154_2 = ((pub_r001986_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_74_1 + (pub_r001986_10_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_74_2 + (pub_r001986_10_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_87_1 + (pub_r001986_8_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_87_2 + (pub_r001986_8_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001986_10_1 * 2) + 36) & 63;
  int stage_v_157_2 = ((pub_r001986_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001986_3_1 * 2) + 35) & 63;
  int stage_v_158_2 = ((pub_r001986_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_101_1 + (pub_r001986_9_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_101_2 + (pub_r001986_9_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_104_1 + (pub_r001986_16_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_104_2 + (pub_r001986_16_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((sec_r001986_13_1 + (pub_r001986_5_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((sec_r001986_13_2 + (pub_r001986_5_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001986_11_1 + (pub_r001986_9_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001986_11_2 + (pub_r001986_9_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_57_1 + (pub_r001986_15_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_57_2 + (pub_r001986_15_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_56_1 + (pub_r001986_14_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_56_2 + (pub_r001986_14_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_146_1 + (pub_r001986_15_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_146_2 + (pub_r001986_15_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001986_15_1 * 2) + 7) & 63;
  int stage_v_166_2 = ((pub_r001986_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_38_1 + (pub_r001986_11_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_38_2 + (pub_r001986_11_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((pub_r001986_16_1 * 2) + 37) & 63;
  int stage_v_168_2 = ((pub_r001986_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001986_12_1 * 2) + 21) & 63;
  int stage_v_169_2 = ((pub_r001986_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001986_5_1 * 2) + 27) & 63;
  int stage_v_170_2 = ((pub_r001986_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((sec_r001986_4_1 + (pub_r001986_13_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((sec_r001986_4_2 + (pub_r001986_13_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_58_1 + (pub_r001986_14_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_58_2 + (pub_r001986_14_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_31_1 + (pub_r001986_7_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_31_2 + (pub_r001986_7_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_69_1 + (pub_r001986_3_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_69_2 + (pub_r001986_3_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_102_1 + (pub_r001986_7_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_102_2 + (pub_r001986_7_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001986_8_1 * 2) + 8) & 63;
  int stage_v_176_2 = ((pub_r001986_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_27_1 + (pub_r001986_11_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_27_2 + (pub_r001986_11_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((helper_flow_1_1 + (pub_r001986_6_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((helper_flow_1_2 + (pub_r001986_6_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((sec_r001986_11_1 + (pub_r001986_7_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((sec_r001986_11_2 + (pub_r001986_7_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001986_10_1 * 2) + 36) & 63;
  int stage_v_180_2 = ((pub_r001986_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_23_1 + (pub_r001986_13_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_23_2 + (pub_r001986_13_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001986_8_1 * 2) + 41) & 63;
  int stage_v_182_2 = ((pub_r001986_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_68_1 + (pub_r001986_0_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_68_2 + (pub_r001986_0_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_110_1 + (pub_r001986_15_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_110_2 + (pub_r001986_15_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_25_1 + (pub_r001986_5_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_25_2 + (pub_r001986_5_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001986_12_1 * 2) + 20) & 63;
  int stage_v_186_2 = ((pub_r001986_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001986_0_1 * 2) + 44) & 63;
  int stage_v_187_2 = ((pub_r001986_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((stage_v_134_1 + (pub_r001986_4_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_134_2 + (pub_r001986_4_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_115_1 + (pub_r001986_0_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_115_2 + (pub_r001986_0_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((sec_r001986_0_1 + (pub_r001986_16_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((sec_r001986_0_2 + (pub_r001986_16_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001986_6_1 * 2) + 13) & 63;
  int stage_v_191_2 = ((pub_r001986_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_87_1 + (pub_r001986_8_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_87_2 + (pub_r001986_8_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001986_2_1 * 2) + 40) & 63;
  int stage_v_193_2 = ((pub_r001986_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_4_1 + (pub_r001986_14_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_4_2 + (pub_r001986_14_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001986_13_1 * 2) + 44) & 63;
  int stage_v_195_2 = ((pub_r001986_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((sec_r001986_0_1 + (pub_r001986_13_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((sec_r001986_0_2 + (pub_r001986_13_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001986_3_1 * 2) + 18) & 63;
  int stage_v_197_2 = ((pub_r001986_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_159_1 + (pub_r001986_2_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_159_2 + (pub_r001986_2_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((pub_r001986_5_1 * 2) + 7) & 63;
  int stage_v_199_2 = ((pub_r001986_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_134_1 + (pub_r001986_11_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_134_2 + (pub_r001986_11_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_54_1 + (pub_r001986_7_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_54_2 + (pub_r001986_7_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((sec_r001986_16_1 + (pub_r001986_7_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((sec_r001986_16_2 + (pub_r001986_7_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001986_12_1 * 2) + 7) & 63;
  int stage_v_203_2 = ((pub_r001986_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_135_1 + (pub_r001986_7_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_135_2 + (pub_r001986_7_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_185_1 + (pub_r001986_6_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_185_2 + (pub_r001986_6_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_94_1 + (pub_r001986_7_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_94_2 + (pub_r001986_7_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((sec_r001986_0_1 + (pub_r001986_13_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001986_0_2 + (pub_r001986_13_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_201_1 + (pub_r001986_4_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_201_2 + (pub_r001986_4_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_208_1 + (pub_r001986_8_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_208_2 + (pub_r001986_8_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001986_8_1 * 2) + 12) & 63;
  int stage_v_210_2 = ((pub_r001986_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((helper_flow_0_1 + (pub_r001986_12_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_0_2 + (pub_r001986_12_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_65_1 + (pub_r001986_1_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_65_2 + (pub_r001986_1_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001986_12_1 * 2) + 34) & 63;
  int stage_v_213_2 = ((pub_r001986_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_172_1 + (pub_r001986_12_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_172_2 + (pub_r001986_12_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_150_1 + (pub_r001986_4_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_150_2 + (pub_r001986_4_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((sec_r001986_5_1 + (pub_r001986_4_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((sec_r001986_5_2 + (pub_r001986_4_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001986_16_1 == pub_r001986_16_2);
  __CPROVER_assume(sec_r001986_0_1 != sec_r001986_0_2);
  __CPROVER_assume(pub_r001986_3_1 == pub_r001986_3_2);
  __CPROVER_assume(pub_r001986_7_1 == pub_r001986_7_2);
  __CPROVER_assume(pub_r001986_8_1 == pub_r001986_8_2);
  __CPROVER_assume(pub_r001986_14_1 == pub_r001986_14_2);
  __CPROVER_assume(pub_r001986_5_1 == pub_r001986_5_2);
  __CPROVER_assume(pub_r001986_1_1 == pub_r001986_1_2);
  __CPROVER_assume(sec_r001986_10_1 != sec_r001986_10_2);
  __CPROVER_assume(pub_r001986_11_1 == pub_r001986_11_2);
  __CPROVER_assume(pub_r001986_12_1 == pub_r001986_12_2);
  __CPROVER_assume(sec_r001986_16_1 != sec_r001986_16_2);
  __CPROVER_assume(sec_r001986_2_1 != sec_r001986_2_2);
  __CPROVER_assume(sec_r001986_11_1 != sec_r001986_11_2);
  __CPROVER_assume(sec_r001986_12_1 != sec_r001986_12_2);
  __CPROVER_assume(sec_r001986_3_1 != sec_r001986_3_2);
  __CPROVER_assume(sec_r001986_14_1 != sec_r001986_14_2);
  __CPROVER_assume(pub_r001986_0_1 == pub_r001986_0_2);
  __CPROVER_assume(sec_r001986_9_1 != sec_r001986_9_2);
  __CPROVER_assume(pub_r001986_10_1 == pub_r001986_10_2);
  __CPROVER_assume(pub_r001986_4_1 == pub_r001986_4_2);
  __CPROVER_assume(sec_r001986_5_1 != sec_r001986_5_2);
  __CPROVER_assume(sec_r001986_4_1 != sec_r001986_4_2);
  __CPROVER_assume(pub_r001986_6_1 == pub_r001986_6_2);
  __CPROVER_assume(sec_r001986_6_1 != sec_r001986_6_2);
  __CPROVER_assume(sec_r001986_8_1 != sec_r001986_8_2);
  __CPROVER_assume(sec_r001986_7_1 != sec_r001986_7_2);
  __CPROVER_assume(pub_r001986_15_1 == pub_r001986_15_2);
  __CPROVER_assume(sec_r001986_13_1 != sec_r001986_13_2);
  __CPROVER_assume(pub_r001986_2_1 == pub_r001986_2_2);
  __CPROVER_assume(pub_r001986_9_1 == pub_r001986_9_2);
  __CPROVER_assume(sec_r001986_15_1 != sec_r001986_15_2);
  __CPROVER_assume(pub_r001986_13_1 == pub_r001986_13_2);
  __CPROVER_assume(sec_r001986_1_1 != sec_r001986_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
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
}


