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
struct DeviceConfig_R000623_2313_0
{
  int timeout;
  int id;
  int port;
  int stop_bits;
  int buffer[3];
};
struct StreamBuffer_R000623_2313_1
{
  short checksum;
  int state;
  int capacity;
  int tail;
  int head;
  int watermark;
  int buffer[3];
};
struct FilterState_R000623_2313_2
{
  int damping;
  unsigned char mode;
  unsigned char prev_in;
  unsigned char cutoff;
  int prev_out;
  int buffer[3];
};
struct MatrixBlock_R000623_2313_3
{
  int scale;
  unsigned char determinant;
  unsigned char dim;
  int buffer[3];
};
union PacketPayload_R000623_2313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000623_2313_1
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
void fn_R000623_2313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st_1 = {0};
  struct FilterState_R000623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int residue_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_57_1 > 19)
  {
    acc_1 = ((acc_1 + (residue_57_1 * 2)) + 5) & 127;
    aux_1 ^= residue_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_57_2 > 19)
  {
    acc_2 = ((acc_2 + (residue_57_2 * 2)) + 5) & 127;
    aux_2 ^= residue_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_57_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_57_1 == residue_57_2);
}

int fn_R000623_2313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int residue_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_57 > 19)
  {
    acc = ((acc + (residue_57 * 2)) + 5) & 127;
    aux ^= residue_57 & 15;
  }
  else
  {
    acc = ((acc - residue_57) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_74_1) & 63;
  aux_2 = (aux_2 + bound_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_74_1 == bound_74_2);
}

int fn_R000623_2313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_17_1 > 29)
  {
    acc_1 = ((acc_1 + (stride_17_1 * 2)) + 5) & 127;
    aux_1 ^= stride_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_17_2 > 29)
  {
    acc_2 = ((acc_2 + (stride_17_2 * 2)) + 5) & 127;
    aux_2 ^= stride_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_17_1 == stride_17_2);
}

int fn_R000623_2313_2(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_17 > 29)
  {
    acc = ((acc + (stride_17 * 2)) + 5) & 127;
    aux ^= stride_17 & 15;
  }
  else
  {
    acc = ((acc - stride_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_76_1)
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

  switch (anchor_76_2)
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

  int stride_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_58_1) & 63;
  aux_2 = (aux_2 + stride_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_21_1 > 34)
  {
    acc_1 = ((acc_1 + (damping_21_1 * 2)) + 5) & 127;
    aux_1 ^= damping_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_21_2 > 34)
  {
    acc_2 = ((acc_2 + (damping_21_2 * 2)) + 5) & 127;
    aux_2 ^= damping_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_76_1 == anchor_76_2);
  assert(stride_58_1 == stride_58_2);
  assert(damping_21_1 == damping_21_2);
}

int fn_R000623_2313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_76 = (aux + st.buffer[1]) & 3;
  switch (anchor_76)
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

  int stride_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_58) & 63;
  acc ^= aux;
  int damping_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_21 > 34)
  {
    acc = ((acc + (damping_21 * 2)) + 5) & 127;
    aux ^= damping_21 & 15;
  }
  else
  {
    acc = ((acc - damping_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_52_1) & 63;
  aux_2 = (aux_2 + tally_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_52_1 == tally_52_2);
}

int fn_R000623_2313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int parity_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_45_1 > 12)
  {
    acc_1 = ((acc_1 + (parity_45_1 * 2)) + 5) & 127;
    aux_1 ^= parity_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_45_2 > 12)
  {
    acc_2 = ((acc_2 + (parity_45_2 * 2)) + 5) & 127;
    aux_2 ^= parity_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_45_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_45_1 == parity_45_2);
}

int fn_R000623_2313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int parity_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_45 > 12)
  {
    acc = ((acc + (parity_45 * 2)) + 5) & 127;
    aux ^= parity_45 & 15;
  }
  else
  {
    acc = ((acc - parity_45) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_49_1) & 63;
  aux_2 = (aux_2 + factor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_68_1 > 21)
  {
    acc_1 = ((acc_1 + (parity_68_1 * 2)) + 5) & 127;
    aux_1 ^= parity_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_68_2 > 21)
  {
    acc_2 = ((acc_2 + (parity_68_2 * 2)) + 5) & 127;
    aux_2 ^= parity_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_63_1 = local_arr_1[aux_1 % 3];
  int damping_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(parity_68_1 == parity_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_63_1 == damping_63_2);
}

int fn_R000623_2313_6(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_49) & 63;
  acc ^= aux;
  int parity_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_68 > 21)
  {
    acc = ((acc + (parity_68 * 2)) + 5) & 127;
    aux ^= parity_68 & 15;
  }
  else
  {
    acc = ((acc - parity_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_63 = local_arr[aux % 3];
  acc = (acc + (damping_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_49_1 = local_arr_1[aux_1 % 3];
  int damping_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_49_2 * 2)) & 127;
  int index_reg_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_67_1) & 63;
  aux_2 = (aux_2 + index_reg_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_84_1)
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

  switch (pivot_84_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_49_1 == damping_49_2);
  assert(index_reg_67_1 == index_reg_67_2);
  assert(pivot_84_1 == pivot_84_2);
}

int fn_R000623_2313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_49 = local_arr[aux % 3];
  acc = (acc + (damping_49 * 2)) & 127;
  int index_reg_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_67) & 63;
  acc ^= aux;
  int pivot_84 = (aux + st.buffer[1]) & 3;
  switch (pivot_84)
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

void fn_R000623_2313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_58_1)
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

  switch (anchor_58_2)
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
  int vector_94_1 = local_arr_1[aux_1 % 3];
  int vector_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_94_2 * 2)) & 127;
  int residue_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_73_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_73_1 * 2)) + 5) & 127;
    aux_1 ^= residue_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_73_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_73_2 * 2)) + 5) & 127;
    aux_2 ^= residue_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_14_1) & 63;
  aux_2 = (aux_2 + margin_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_58_1 == anchor_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_94_1 == vector_94_2);
  assert(residue_73_1 == residue_73_2);
  assert(margin_14_1 == margin_14_2);
}

int fn_R000623_2313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_58 = (aux + st.buffer[1]) & 3;
  switch (anchor_58)
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
  int vector_94 = local_arr[aux % 3];
  acc = (acc + (vector_94 * 2)) & 127;
  int residue_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_73 > 34)
  {
    acc = ((acc + (residue_73 * 2)) + 5) & 127;
    aux ^= residue_73 & 15;
  }
  else
  {
    acc = ((acc - residue_73) + 11) & 127;
    aux += 3;
  }
  int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000623_2313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_14_1 > 41)
  {
    acc_1 = ((acc_1 + (delta_14_1 * 2)) + 5) & 127;
    aux_1 ^= delta_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_14_2 > 41)
  {
    acc_2 = ((acc_2 + (delta_14_2 * 2)) + 5) & 127;
    aux_2 ^= delta_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_25_1)
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

  switch (bound_25_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_90_1 = local_arr_1[aux_1 % 3];
  int offset_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_14_1 == delta_14_2);
  assert(bound_25_1 == bound_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_90_1 == offset_90_2);
}

int fn_R000623_2313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_14 > 41)
  {
    acc = ((acc + (delta_14 * 2)) + 5) & 127;
    aux ^= delta_14 & 15;
  }
  else
  {
    acc = ((acc - delta_14) + 11) & 127;
    aux += 3;
  }
  int bound_25 = (aux + st.buffer[1]) & 3;
  switch (bound_25)
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

  int local_arr[3] = {4, 9, 15};
  int offset_90 = local_arr[aux % 3];
  acc = (acc + (offset_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tracker_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_43_1)
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

  switch (tracker_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_43_1 == tracker_43_2);
}

int fn_R000623_2313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tracker_43 = (aux + st.buffer[1]) & 3;
  switch (tracker_43)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_35_1 = local_arr_1[aux_1 % 3];
  int coefficient_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_35_2 * 2)) & 127;
  int quotient_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_40_1 > 27)
  {
    acc_1 = ((acc_1 + (quotient_40_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_40_2 > 27)
  {
    acc_2 = ((acc_2 + (quotient_40_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  assert(quotient_40_1 == quotient_40_2);
}

int fn_R000623_2313_11(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_35 = local_arr[aux % 3];
  acc = (acc + (coefficient_35 * 2)) & 127;
  int quotient_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_40 > 27)
  {
    acc = ((acc + (quotient_40 * 2)) + 5) & 127;
    aux ^= quotient_40 & 15;
  }
  else
  {
    acc = ((acc - quotient_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st_1 = {0};
  struct FilterState_R000623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_65_1) & 63;
  aux_2 = (aux_2 + factor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_74_1 > 19)
  {
    acc_1 = ((acc_1 + (scale_74_1 * 2)) + 5) & 127;
    aux_1 ^= scale_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_74_2 > 19)
  {
    acc_2 = ((acc_2 + (scale_74_2 * 2)) + 5) & 127;
    aux_2 ^= scale_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_23_1)
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

  switch (offset_23_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_65_1 == factor_65_2);
  assert(scale_74_1 == scale_74_2);
  assert(offset_23_1 == offset_23_2);
}

int fn_R000623_2313_12(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_65) & 63;
  acc ^= aux;
  int scale_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_74 > 19)
  {
    acc = ((acc + (scale_74 * 2)) + 5) & 127;
    aux ^= scale_74 & 15;
  }
  else
  {
    acc = ((acc - scale_74) + 11) & 127;
    aux += 3;
  }
  int offset_23 = (aux + st.buffer[1]) & 3;
  switch (offset_23)
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

void fn_R000623_2313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_23_1 = local_arr_1[aux_1 % 3];
  int stride_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_23_2 * 2)) & 127;
  int scale_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_55_1)
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

  switch (scale_55_2)
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

  int weight_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_27_1) & 63;
  aux_2 = (aux_2 + weight_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_23_1 == stride_23_2);
  assert(scale_55_1 == scale_55_2);
  assert(weight_27_1 == weight_27_2);
}

int fn_R000623_2313_13(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int stride_23 = local_arr[aux % 3];
  acc = (acc + (stride_23 * 2)) & 127;
  int scale_55 = (aux + st.buffer[1]) & 3;
  switch (scale_55)
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

  int weight_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000623_2313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_71_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_71_1 * 2)) + 5) & 127;
    aux_1 ^= damping_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_71_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_71_2 * 2)) + 5) & 127;
    aux_2 ^= damping_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_90_1) & 63;
  aux_2 = (aux_2 + accumulator_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_10_1 = local_arr_1[aux_1 % 3];
  int residue_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_71_1 == damping_71_2);
  assert(accumulator_90_1 == accumulator_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_10_1 == residue_10_2);
}

int fn_R000623_2313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_71 > 22)
  {
    acc = ((acc + (damping_71 * 2)) + 5) & 127;
    aux ^= damping_71 & 15;
  }
  else
  {
    acc = ((acc - damping_71) + 11) & 127;
    aux += 3;
  }
  int accumulator_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_10 = local_arr[aux % 3];
  acc = (acc + (residue_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_39_1 = local_arr_1[aux_1 % 3];
  int tally_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_39_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_42_1)
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

  switch (pivot_42_2)
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

  int coefficient_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_44_1 > 21)
  {
    acc_1 = ((acc_1 + (coefficient_44_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_44_2 > 21)
  {
    acc_2 = ((acc_2 + (coefficient_44_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_39_1 == tally_39_2);
  assert(pivot_42_1 == pivot_42_2);
  assert(coefficient_44_1 == coefficient_44_2);
}

int fn_R000623_2313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tally_39 = local_arr[aux % 3];
  acc = (acc + (tally_39 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_42 = (aux + st.buffer[1]) & 3;
  switch (pivot_42)
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

  int coefficient_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_44 > 21)
  {
    acc = ((acc + (coefficient_44 * 2)) + 5) & 127;
    aux ^= coefficient_44 & 15;
  }
  else
  {
    acc = ((acc - coefficient_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_62_1 > 14)
  {
    acc_1 = ((acc_1 + (cursor_62_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_62_2 > 14)
  {
    acc_2 = ((acc_2 + (cursor_62_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_81_1) & 63;
  aux_2 = (aux_2 + offset_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_62_1 == cursor_62_2);
  assert(offset_81_1 == offset_81_2);
}

int fn_R000623_2313_16(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_62 > 14)
  {
    acc = ((acc + (cursor_62 * 2)) + 5) & 127;
    aux ^= cursor_62 & 15;
  }
  else
  {
    acc = ((acc - cursor_62) + 11) & 127;
    aux += 3;
  }
  int offset_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000623_2313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_97_1)
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

  switch (quantum_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_97_1 == quantum_97_2);
}

int fn_R000623_2313_17(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_97 = (aux + st.buffer[1]) & 3;
  switch (quantum_97)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_10_1) & 63;
  aux_2 = (aux_2 + window_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_91_1 = local_arr_1[aux_1 % 3];
  int offset_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_91_2 * 2)) & 127;
  int anchor_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_93_1 > 50)
  {
    acc_1 = ((acc_1 + (anchor_93_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_93_2 > 50)
  {
    acc_2 = ((acc_2 + (anchor_93_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_10_1 == window_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_91_1 == offset_91_2);
  assert(anchor_93_1 == anchor_93_2);
}

int fn_R000623_2313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_91 = local_arr[aux % 3];
  acc = (acc + (offset_91 * 2)) & 127;
  int anchor_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_93 > 50)
  {
    acc = ((acc + (anchor_93 * 2)) + 5) & 127;
    aux ^= anchor_93 & 15;
  }
  else
  {
    acc = ((acc - anchor_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st_1 = {0};
  struct FilterState_R000623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tracker_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_85_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_85_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_85_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_85_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_62_1)
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

  switch (factor_62_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_85_1 == tracker_85_2);
  assert(factor_62_1 == factor_62_2);
}

int fn_R000623_2313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tracker_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_85 > 47)
  {
    acc = ((acc + (tracker_85 * 2)) + 5) & 127;
    aux ^= tracker_85 & 15;
  }
  else
  {
    acc = ((acc - tracker_85) + 11) & 127;
    aux += 3;
  }
  int factor_62 = (aux + st.buffer[1]) & 3;
  switch (factor_62)
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

void fn_R000623_2313_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int damping_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_81_1)
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

  switch (damping_81_2)
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

  int margin_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_77_1 > 43)
  {
    acc_1 = ((acc_1 + (margin_77_1 * 2)) + 5) & 127;
    aux_1 ^= margin_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_77_2 > 43)
  {
    acc_2 = ((acc_2 + (margin_77_2 * 2)) + 5) & 127;
    aux_2 ^= margin_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_81_1 == damping_81_2);
  assert(margin_77_1 == margin_77_2);
}

int fn_R000623_2313_20(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int damping_81 = (aux + st.buffer[1]) & 3;
  switch (damping_81)
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

  int margin_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_77 > 43)
  {
    acc = ((acc + (margin_77 * 2)) + 5) & 127;
    aux ^= margin_77 & 15;
  }
  else
  {
    acc = ((acc - margin_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int bound_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_88_1)
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

  switch (bound_88_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_76_1) & 63;
  aux_2 = (aux_2 + sample_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_95_1 > 44)
  {
    acc_1 = ((acc_1 + (offset_95_1 * 2)) + 5) & 127;
    aux_1 ^= offset_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_95_2 > 44)
  {
    acc_2 = ((acc_2 + (offset_95_2 * 2)) + 5) & 127;
    aux_2 ^= offset_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_88_1 == bound_88_2);
  assert(sample_76_1 == sample_76_2);
  assert(offset_95_1 == offset_95_2);
}

int fn_R000623_2313_21(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int bound_88 = (aux + st.buffer[1]) & 3;
  switch (bound_88)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_76) & 63;
  acc ^= aux;
  int offset_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_95 > 44)
  {
    acc = ((acc + (offset_95 * 2)) + 5) & 127;
    aux ^= offset_95 & 15;
  }
  else
  {
    acc = ((acc - offset_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000623_2313_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_21_1 > 43)
  {
    acc_1 = ((acc_1 + (factor_21_1 * 2)) + 5) & 127;
    aux_1 ^= factor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_21_2 > 43)
  {
    acc_2 = ((acc_2 + (factor_21_2 * 2)) + 5) & 127;
    aux_2 ^= factor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_44_1) & 63;
  aux_2 = (aux_2 + tracker_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_30_1 = local_arr_1[aux_1 % 3];
  int bound_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(tracker_44_1 == tracker_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_30_1 == bound_30_2);
}

int fn_R000623_2313_22(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_21 > 43)
  {
    acc = ((acc + (factor_21 * 2)) + 5) & 127;
    aux ^= factor_21 & 15;
  }
  else
  {
    acc = ((acc - factor_21) + 11) & 127;
    aux += 3;
  }
  int tracker_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_30 = local_arr[aux % 3];
  acc = (acc + (bound_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000623_2313_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_25_1)
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

  switch (bound_25_2)
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
  int segment_54_1 = local_arr_1[aux_1 % 3];
  int segment_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_25_1 == bound_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_54_1 == segment_54_2);
}

int fn_R000623_2313_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_25 = (aux + st.buffer[1]) & 3;
  switch (bound_25)
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
  int segment_54 = local_arr[aux % 3];
  acc = (acc + (segment_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000623_0_1;
  int sec_r000623_0_2;
  int sec_r000623_1_1;
  int sec_r000623_1_2;
  int sec_r000623_2_1;
  int sec_r000623_2_2;
  int sec_r000623_3_1;
  int sec_r000623_3_2;
  int sec_r000623_4_1;
  int sec_r000623_4_2;
  int sec_r000623_5_1;
  int sec_r000623_5_2;
  int sec_r000623_6_1;
  int sec_r000623_6_2;
  int sec_r000623_7_1;
  int sec_r000623_7_2;
  int sec_r000623_8_1;
  int sec_r000623_8_2;
  int sec_r000623_9_1;
  int sec_r000623_9_2;
  int sec_r000623_10_1;
  int sec_r000623_10_2;
  int sec_r000623_11_1;
  int sec_r000623_11_2;
  int sec_r000623_12_1;
  int sec_r000623_12_2;
  int sec_r000623_13_1;
  int sec_r000623_13_2;
  int sec_r000623_14_1;
  int sec_r000623_14_2;
  int sec_r000623_15_1;
  int sec_r000623_15_2;
  int sec_r000623_16_1;
  int sec_r000623_16_2;
  int sec_r000623_17_1;
  int sec_r000623_17_2;
  int sec_r000623_18_1;
  int sec_r000623_18_2;
  int sec_r000623_19_1;
  int sec_r000623_19_2;
  int sec_r000623_20_1;
  int sec_r000623_20_2;
  int sec_r000623_21_1;
  int sec_r000623_21_2;
  int sec_r000623_22_1;
  int sec_r000623_22_2;
  int pub_r000623_0_1;
  int pub_r000623_0_2;
  int pub_r000623_1_1;
  int pub_r000623_1_2;
  int pub_r000623_2_1;
  int pub_r000623_2_2;
  int pub_r000623_3_1;
  int pub_r000623_3_2;
  int pub_r000623_4_1;
  int pub_r000623_4_2;
  int pub_r000623_5_1;
  int pub_r000623_5_2;
  int pub_r000623_6_1;
  int pub_r000623_6_2;
  int pub_r000623_7_1;
  int pub_r000623_7_2;
  int pub_r000623_8_1;
  int pub_r000623_8_2;
  int pub_r000623_9_1;
  int pub_r000623_9_2;
  int pub_r000623_10_1;
  int pub_r000623_10_2;
  int pub_r000623_11_1;
  int pub_r000623_11_2;
  int pub_r000623_12_1;
  int pub_r000623_12_2;
  int pub_r000623_13_1;
  int pub_r000623_13_2;
  int pub_r000623_14_1;
  int pub_r000623_14_2;
  int pub_r000623_15_1;
  int pub_r000623_15_2;
  int pub_r000623_16_1;
  int pub_r000623_16_2;
  int pub_r000623_17_1;
  int pub_r000623_17_2;
  int pub_r000623_18_1;
  int pub_r000623_18_2;
  int pub_r000623_19_1;
  int pub_r000623_19_2;
  int pub_r000623_20_1;
  int pub_r000623_20_2;
  int pub_r000623_21_1;
  int pub_r000623_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000623_0_1 >= (-100)) && (pub_r000623_0_1 <= 100));
  __CPROVER_assume((pub_r000623_0_2 >= (-100)) && (pub_r000623_0_2 <= 100));
  __CPROVER_assume((pub_r000623_1_1 >= (-100)) && (pub_r000623_1_1 <= 100));
  __CPROVER_assume((pub_r000623_1_2 >= (-100)) && (pub_r000623_1_2 <= 100));
  __CPROVER_assume((pub_r000623_2_1 >= (-100)) && (pub_r000623_2_1 <= 100));
  __CPROVER_assume((pub_r000623_2_2 >= (-100)) && (pub_r000623_2_2 <= 100));
  __CPROVER_assume((pub_r000623_3_1 >= (-100)) && (pub_r000623_3_1 <= 100));
  __CPROVER_assume((pub_r000623_3_2 >= (-100)) && (pub_r000623_3_2 <= 100));
  __CPROVER_assume((pub_r000623_4_1 >= (-100)) && (pub_r000623_4_1 <= 100));
  __CPROVER_assume((pub_r000623_4_2 >= (-100)) && (pub_r000623_4_2 <= 100));
  __CPROVER_assume((pub_r000623_5_1 >= (-100)) && (pub_r000623_5_1 <= 100));
  __CPROVER_assume((pub_r000623_5_2 >= (-100)) && (pub_r000623_5_2 <= 100));
  __CPROVER_assume((pub_r000623_6_1 >= (-100)) && (pub_r000623_6_1 <= 100));
  __CPROVER_assume((pub_r000623_6_2 >= (-100)) && (pub_r000623_6_2 <= 100));
  __CPROVER_assume((pub_r000623_7_1 >= (-100)) && (pub_r000623_7_1 <= 100));
  __CPROVER_assume((pub_r000623_7_2 >= (-100)) && (pub_r000623_7_2 <= 100));
  __CPROVER_assume((pub_r000623_8_1 >= (-100)) && (pub_r000623_8_1 <= 100));
  __CPROVER_assume((pub_r000623_8_2 >= (-100)) && (pub_r000623_8_2 <= 100));
  __CPROVER_assume((pub_r000623_9_1 >= (-100)) && (pub_r000623_9_1 <= 100));
  __CPROVER_assume((pub_r000623_9_2 >= (-100)) && (pub_r000623_9_2 <= 100));
  __CPROVER_assume((pub_r000623_10_1 >= (-100)) && (pub_r000623_10_1 <= 100));
  __CPROVER_assume((pub_r000623_10_2 >= (-100)) && (pub_r000623_10_2 <= 100));
  __CPROVER_assume((pub_r000623_11_1 >= (-100)) && (pub_r000623_11_1 <= 100));
  __CPROVER_assume((pub_r000623_11_2 >= (-100)) && (pub_r000623_11_2 <= 100));
  __CPROVER_assume((pub_r000623_12_1 >= (-100)) && (pub_r000623_12_1 <= 100));
  __CPROVER_assume((pub_r000623_12_2 >= (-100)) && (pub_r000623_12_2 <= 100));
  __CPROVER_assume((pub_r000623_13_1 >= (-100)) && (pub_r000623_13_1 <= 100));
  __CPROVER_assume((pub_r000623_13_2 >= (-100)) && (pub_r000623_13_2 <= 100));
  __CPROVER_assume((pub_r000623_14_1 >= (-100)) && (pub_r000623_14_1 <= 100));
  __CPROVER_assume((pub_r000623_14_2 >= (-100)) && (pub_r000623_14_2 <= 100));
  __CPROVER_assume((pub_r000623_15_1 >= (-100)) && (pub_r000623_15_1 <= 100));
  __CPROVER_assume((pub_r000623_15_2 >= (-100)) && (pub_r000623_15_2 <= 100));
  __CPROVER_assume((pub_r000623_16_1 >= (-100)) && (pub_r000623_16_1 <= 100));
  __CPROVER_assume((pub_r000623_16_2 >= (-100)) && (pub_r000623_16_2 <= 100));
  __CPROVER_assume((pub_r000623_17_1 >= (-100)) && (pub_r000623_17_1 <= 100));
  __CPROVER_assume((pub_r000623_17_2 >= (-100)) && (pub_r000623_17_2 <= 100));
  __CPROVER_assume((pub_r000623_18_1 >= (-100)) && (pub_r000623_18_1 <= 100));
  __CPROVER_assume((pub_r000623_18_2 >= (-100)) && (pub_r000623_18_2 <= 100));
  __CPROVER_assume((pub_r000623_19_1 >= (-100)) && (pub_r000623_19_1 <= 100));
  __CPROVER_assume((pub_r000623_19_2 >= (-100)) && (pub_r000623_19_2 <= 100));
  __CPROVER_assume((pub_r000623_20_1 >= (-100)) && (pub_r000623_20_1 <= 100));
  __CPROVER_assume((pub_r000623_20_2 >= (-100)) && (pub_r000623_20_2 <= 100));
  __CPROVER_assume((pub_r000623_21_1 >= (-100)) && (pub_r000623_21_1 <= 100));
  __CPROVER_assume((pub_r000623_21_2 >= (-100)) && (pub_r000623_21_2 <= 100));
  __CPROVER_assume((sec_r000623_0_1 >= 0) && (sec_r000623_0_1 <= 255));
  __CPROVER_assume((sec_r000623_0_2 >= 0) && (sec_r000623_0_2 <= 255));
  __CPROVER_assume((sec_r000623_1_1 >= 0) && (sec_r000623_1_1 <= 255));
  __CPROVER_assume((sec_r000623_1_2 >= 0) && (sec_r000623_1_2 <= 255));
  __CPROVER_assume((sec_r000623_2_1 >= 0) && (sec_r000623_2_1 <= 255));
  __CPROVER_assume((sec_r000623_2_2 >= 0) && (sec_r000623_2_2 <= 255));
  __CPROVER_assume((sec_r000623_3_1 >= 0) && (sec_r000623_3_1 <= 255));
  __CPROVER_assume((sec_r000623_3_2 >= 0) && (sec_r000623_3_2 <= 255));
  __CPROVER_assume((sec_r000623_4_1 >= 0) && (sec_r000623_4_1 <= 255));
  __CPROVER_assume((sec_r000623_4_2 >= 0) && (sec_r000623_4_2 <= 255));
  __CPROVER_assume((sec_r000623_5_1 >= 0) && (sec_r000623_5_1 <= 255));
  __CPROVER_assume((sec_r000623_5_2 >= 0) && (sec_r000623_5_2 <= 255));
  __CPROVER_assume((sec_r000623_6_1 >= 0) && (sec_r000623_6_1 <= 255));
  __CPROVER_assume((sec_r000623_6_2 >= 0) && (sec_r000623_6_2 <= 255));
  __CPROVER_assume((sec_r000623_7_1 >= 0) && (sec_r000623_7_1 <= 255));
  __CPROVER_assume((sec_r000623_7_2 >= 0) && (sec_r000623_7_2 <= 255));
  __CPROVER_assume((sec_r000623_8_1 >= 0) && (sec_r000623_8_1 <= 255));
  __CPROVER_assume((sec_r000623_8_2 >= 0) && (sec_r000623_8_2 <= 255));
  __CPROVER_assume((sec_r000623_9_1 >= 0) && (sec_r000623_9_1 <= 255));
  __CPROVER_assume((sec_r000623_9_2 >= 0) && (sec_r000623_9_2 <= 255));
  __CPROVER_assume((sec_r000623_10_1 >= 0) && (sec_r000623_10_1 <= 255));
  __CPROVER_assume((sec_r000623_10_2 >= 0) && (sec_r000623_10_2 <= 255));
  __CPROVER_assume((sec_r000623_11_1 >= 0) && (sec_r000623_11_1 <= 255));
  __CPROVER_assume((sec_r000623_11_2 >= 0) && (sec_r000623_11_2 <= 255));
  __CPROVER_assume((sec_r000623_12_1 >= 0) && (sec_r000623_12_1 <= 255));
  __CPROVER_assume((sec_r000623_12_2 >= 0) && (sec_r000623_12_2 <= 255));
  __CPROVER_assume((sec_r000623_13_1 >= 0) && (sec_r000623_13_1 <= 255));
  __CPROVER_assume((sec_r000623_13_2 >= 0) && (sec_r000623_13_2 <= 255));
  __CPROVER_assume((sec_r000623_14_1 >= 0) && (sec_r000623_14_1 <= 255));
  __CPROVER_assume((sec_r000623_14_2 >= 0) && (sec_r000623_14_2 <= 255));
  __CPROVER_assume((sec_r000623_15_1 >= 0) && (sec_r000623_15_1 <= 255));
  __CPROVER_assume((sec_r000623_15_2 >= 0) && (sec_r000623_15_2 <= 255));
  __CPROVER_assume((sec_r000623_16_1 >= 0) && (sec_r000623_16_1 <= 255));
  __CPROVER_assume((sec_r000623_16_2 >= 0) && (sec_r000623_16_2 <= 255));
  __CPROVER_assume((sec_r000623_17_1 >= 0) && (sec_r000623_17_1 <= 255));
  __CPROVER_assume((sec_r000623_17_2 >= 0) && (sec_r000623_17_2 <= 255));
  __CPROVER_assume((sec_r000623_18_1 >= 0) && (sec_r000623_18_1 <= 255));
  __CPROVER_assume((sec_r000623_18_2 >= 0) && (sec_r000623_18_2 <= 255));
  __CPROVER_assume((sec_r000623_19_1 >= 0) && (sec_r000623_19_1 <= 255));
  __CPROVER_assume((sec_r000623_19_2 >= 0) && (sec_r000623_19_2 <= 255));
  __CPROVER_assume((sec_r000623_20_1 >= 0) && (sec_r000623_20_1 <= 255));
  __CPROVER_assume((sec_r000623_20_2 >= 0) && (sec_r000623_20_2 <= 255));
  __CPROVER_assume((sec_r000623_21_1 >= 0) && (sec_r000623_21_1 <= 255));
  __CPROVER_assume((sec_r000623_21_2 >= 0) && (sec_r000623_21_2 <= 255));
  __CPROVER_assume((sec_r000623_22_1 >= 0) && (sec_r000623_22_1 <= 255));
  __CPROVER_assume((sec_r000623_22_2 >= 0) && (sec_r000623_22_2 <= 255));
  struct DeviceConfig_R000623_2313_0 st_var_0_1 = {0};
  struct DeviceConfig_R000623_2313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000623_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000623_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000623_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000623_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000623_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000623_0_2 + 7) & 15;
  struct StreamBuffer_R000623_2313_1 st_var_1_1 = {0};
  struct StreamBuffer_R000623_2313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000623_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000623_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000623_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000623_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000623_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000623_0_2 + 9) & 15;
  struct FilterState_R000623_2313_2 st_var_2_1 = {0};
  struct FilterState_R000623_2313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000623_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000623_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000623_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000623_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000623_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000623_0_2 + 11) & 15;
  struct MatrixBlock_R000623_2313_3 st_var_3_1 = {0};
  struct MatrixBlock_R000623_2313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000623_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000623_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000623_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000623_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000623_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000623_0_2 + 13) & 15;
  union PacketPayload_R000623_2313_0 u_var_1;
  union PacketPayload_R000623_2313_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 34)
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
  if (stage_v_3_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 34)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
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
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
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

  switch (stage_v_14_2)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
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
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
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
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 51)
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
  if (stage_v_37_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 51)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
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
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 46)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 46)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
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
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
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
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 29)
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
  if (stage_v_52_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 29)
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
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 45)
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
  if (stage_v_56_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 45)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (st_var_3_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_3_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 45)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 45)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (st_var_2_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_2_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 68) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int sub_step_69_1 = ((sec_r000623_6_1 + pub_r000623_20_1) + 24) & 127;
  int sub_step_69_2 = ((sec_r000623_6_2 + pub_r000623_20_2) + 24) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000623_12_2) & 127;
  st_var_1_1.buffer[0] = stage_v_69_1 & 15;
  st_var_1_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((sub_step_69_1 + pub_r000623_2_1) + 5) & 127;
  int sub_step_70_2 = ((sub_step_69_2 + pub_r000623_2_2) + 5) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_70_1 & 15;
  st_var_2_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((sub_step_69_1 + pub_r000623_3_1) + 20) & 127;
  int sub_step_71_2 = ((sub_step_69_2 + pub_r000623_3_2) + 20) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000623_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_71_1 & 15;
  st_var_3_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((sec_r000623_13_1 + pub_r000623_18_1) + 11) & 127;
  int sub_step_72_2 = ((sec_r000623_13_2 + pub_r000623_18_2) + 11) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000623_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sub_step_69_1 + pub_r000623_10_1) + 30) & 127;
  int sub_step_73_2 = ((sub_step_69_2 + pub_r000623_10_2) + 30) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000623_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sec_r000623_4_1 + pub_r000623_11_1) + 29) & 127;
  int sub_step_74_2 = ((sec_r000623_4_2 + pub_r000623_11_2) + 29) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000623_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((stage_v_71_1 + pub_r000623_13_1) + 33) & 127;
  int sub_step_75_2 = ((stage_v_71_2 + pub_r000623_13_2) + 33) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000623_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_75_1 & 15;
  st_var_3_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((sec_r000623_21_1 + pub_r000623_8_1) + 14) & 127;
  int sub_step_76_2 = ((sec_r000623_21_2 + pub_r000623_8_2) + 14) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000623_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_76_1 & 15;
  st_var_0_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((stage_v_76_1 + pub_r000623_2_1) + 31) & 127;
  int sub_step_77_2 = ((stage_v_76_2 + pub_r000623_2_2) + 31) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000623_1_2) & 127;
  st_var_1_1.buffer[2] = stage_v_77_1 & 15;
  st_var_1_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((stage_v_71_1 + pub_r000623_17_1) + 7) & 127;
  int sub_step_78_2 = ((stage_v_71_2 + pub_r000623_17_2) + 7) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000623_12_2) & 127;
  st_var_2_1.buffer[0] = stage_v_78_1 & 15;
  st_var_2_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((sub_step_78_1 + pub_r000623_14_1) + 30) & 127;
  int sub_step_79_2 = ((sub_step_78_2 + pub_r000623_14_2) + 30) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000623_20_2) & 127;
  st_var_3_1.buffer[1] = stage_v_79_1 & 15;
  st_var_3_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sec_r000623_5_1 + pub_r000623_10_1) + 19) & 127;
  int sub_step_80_2 = ((sec_r000623_5_2 + pub_r000623_10_2) + 19) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000623_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_80_1 & 15;
  st_var_0_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sec_r000623_7_1 + pub_r000623_12_1) + 13) & 127;
  int sub_step_81_2 = ((sec_r000623_7_2 + pub_r000623_12_2) + 13) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000623_16_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000623_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_81_1 & 15;
  st_var_1_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((stage_v_79_1 + pub_r000623_11_1) + 24) & 127;
  int sub_step_82_2 = ((stage_v_79_2 + pub_r000623_11_2) + 24) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000623_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_82_1 & 15;
  st_var_2_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((stage_v_78_1 + pub_r000623_2_1) + 13) & 127;
  int sub_step_83_2 = ((stage_v_78_2 + pub_r000623_2_2) + 13) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000623_7_2) & 127;
  st_var_3_1.buffer[2] = stage_v_83_1 & 15;
  st_var_3_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((sec_r000623_0_1 + pub_r000623_0_1) + 21) & 127;
  int sub_step_84_2 = ((sec_r000623_0_2 + pub_r000623_0_2) + 21) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000623_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sub_step_75_1 + pub_r000623_7_1) + 35) & 127;
  int sub_step_85_2 = ((sub_step_75_2 + pub_r000623_7_2) + 35) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000623_6_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000623_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sec_r000623_18_1 + pub_r000623_21_1) + 26) & 127;
  int sub_step_86_2 = ((sec_r000623_18_2 + pub_r000623_21_2) + 26) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000623_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((sub_step_69_1 + pub_r000623_9_1) + 18) & 127;
  int sub_step_87_2 = ((sub_step_69_2 + pub_r000623_9_2) + 18) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000623_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sec_r000623_2_1 + pub_r000623_4_1) + 8) & 127;
  int sub_step_88_2 = ((sec_r000623_2_2 + pub_r000623_4_2) + 8) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000623_12_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sec_r000623_0_1 + pub_r000623_18_1) + 7) & 127;
  int sub_step_89_2 = ((sec_r000623_0_2 + pub_r000623_18_2) + 7) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000623_19_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sub_step_73_1 + pub_r000623_15_1) + 15) & 127;
  int sub_step_90_2 = ((sub_step_73_2 + pub_r000623_15_2) + 15) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000623_11_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sec_r000623_16_1 + pub_r000623_13_1) + 27) & 127;
  int sub_step_91_2 = ((sec_r000623_16_2 + pub_r000623_13_2) + 27) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sub_step_70_1 + pub_r000623_3_1) + 11) & 127;
  int sub_step_92_2 = ((sub_step_70_2 + pub_r000623_3_2) + 11) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000623_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((stage_v_77_1 + pub_r000623_13_1) + 6) & 127;
  int sub_step_93_2 = ((stage_v_77_2 + pub_r000623_13_2) + 6) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000623_2_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_78_1 + pub_r000623_13_1) + 11) & 127;
  int sub_step_94_2 = ((stage_v_78_2 + pub_r000623_13_2) + 11) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000623_19_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_83_1 + pub_r000623_4_1) + 9) & 127;
  int sub_step_95_2 = ((sub_step_83_2 + pub_r000623_4_2) + 9) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000623_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sub_step_76_1 + pub_r000623_8_1) + 15) & 127;
  int sub_step_96_2 = ((sub_step_76_2 + pub_r000623_8_2) + 15) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000623_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((stage_v_96_1 + pub_r000623_6_1) + 29) & 127;
  int sub_step_97_2 = ((stage_v_96_2 + pub_r000623_6_2) + 29) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000623_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((stage_v_90_1 + pub_r000623_3_1) + 21) & 127;
  int sub_step_98_2 = ((stage_v_90_2 + pub_r000623_3_2) + 21) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000623_20_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sec_r000623_9_1 + pub_r000623_1_1) + 30) & 127;
  int sub_step_99_2 = ((sec_r000623_9_2 + pub_r000623_1_2) + 30) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000623_13_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((sec_r000623_19_1 + pub_r000623_18_1) + 27) & 127;
  int sub_step_100_2 = ((sec_r000623_19_2 + pub_r000623_18_2) + 27) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000623_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((stage_v_90_1 + pub_r000623_17_1) + 31) & 127;
  int sub_step_101_2 = ((stage_v_90_2 + pub_r000623_17_2) + 31) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000623_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((stage_v_80_1 + pub_r000623_6_1) + 16) & 127;
  int sub_step_102_2 = ((stage_v_80_2 + pub_r000623_6_2) + 16) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000623_4_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((stage_v_99_1 + pub_r000623_16_1) + 35) & 127;
  int sub_step_103_2 = ((stage_v_99_2 + pub_r000623_16_2) + 35) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000623_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sub_step_74_1 + pub_r000623_14_1) + 18) & 127;
  int sub_step_104_2 = ((sub_step_74_2 + pub_r000623_14_2) + 18) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000623_15_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((stage_v_92_1 + pub_r000623_13_1) + 22) & 127;
  int sub_step_105_2 = ((stage_v_92_2 + pub_r000623_13_2) + 22) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000623_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sec_r000623_20_1 + pub_r000623_19_1) + 14) & 127;
  int sub_step_106_2 = ((sec_r000623_20_2 + pub_r000623_19_2) + 14) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000623_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000623_13_1 + pub_r000623_18_1) + 21) & 127;
  int sub_step_107_2 = ((sec_r000623_13_2 + pub_r000623_18_2) + 21) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000623_14_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sub_step_99_1 + pub_r000623_16_1) + 11) & 127;
  int sub_step_108_2 = ((sub_step_99_2 + pub_r000623_16_2) + 11) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000623_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sub_step_90_1 + pub_r000623_15_1) + 11) & 127;
  int sub_step_109_2 = ((sub_step_90_2 + pub_r000623_15_2) + 11) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000623_21_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000623_21_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000623_14_1 + pub_r000623_16_1) + 14) & 127;
  int sub_step_110_2 = ((sec_r000623_14_2 + pub_r000623_16_2) + 14) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000623_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sec_r000623_11_1 + pub_r000623_2_1) + 24) & 127;
  int sub_step_111_2 = ((sec_r000623_11_2 + pub_r000623_2_2) + 24) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000623_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sub_step_96_1 + pub_r000623_11_1) + 35) & 127;
  int sub_step_112_2 = ((sub_step_96_2 + pub_r000623_11_2) + 35) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000623_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sec_r000623_6_1 + pub_r000623_20_1) + 35) & 127;
  int sub_step_113_2 = ((sec_r000623_6_2 + pub_r000623_20_2) + 35) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000623_9_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((stage_v_82_1 + pub_r000623_6_1) + 32) & 127;
  int sub_step_114_2 = ((stage_v_82_2 + pub_r000623_6_2) + 32) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000623_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sec_r000623_16_1 + pub_r000623_6_1) + 29) & 127;
  int sub_step_115_2 = ((sec_r000623_16_2 + pub_r000623_6_2) + 29) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sec_r000623_14_1 + pub_r000623_0_1) + 20) & 127;
  int sub_step_116_2 = ((sec_r000623_14_2 + pub_r000623_0_2) + 20) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000623_3_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000623_6_1 + pub_r000623_10_1) + 5) & 127;
  int sub_step_117_2 = ((sec_r000623_6_2 + pub_r000623_10_2) + 5) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000623_6_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000623_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sub_step_97_1 + pub_r000623_10_1) + 8) & 127;
  int sub_step_118_2 = ((sub_step_97_2 + pub_r000623_10_2) + 8) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000623_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sec_r000623_7_1 + pub_r000623_12_1) + 33) & 127;
  int sub_step_119_2 = ((sec_r000623_7_2 + pub_r000623_12_2) + 33) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((stage_v_94_1 + pub_r000623_17_1) + 28) & 127;
  int sub_step_120_2 = ((stage_v_94_2 + pub_r000623_17_2) + 28) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000623_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sub_step_88_1 + pub_r000623_21_1) + 31) & 127;
  int sub_step_121_2 = ((sub_step_88_2 + pub_r000623_21_2) + 31) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000623_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000623_1_1 + pub_r000623_12_1) + 10) & 127;
  int sub_step_122_2 = ((sec_r000623_1_2 + pub_r000623_12_2) + 10) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000623_20_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sub_step_116_1 + pub_r000623_0_1) + 24) & 127;
  int sub_step_123_2 = ((sub_step_116_2 + pub_r000623_0_2) + 24) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000623_18_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((stage_v_118_1 + pub_r000623_14_1) + 22) & 127;
  int sub_step_124_2 = ((stage_v_118_2 + pub_r000623_14_2) + 22) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000623_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sub_step_99_1 + pub_r000623_2_1) + 5) & 127;
  int sub_step_125_2 = ((sub_step_99_2 + pub_r000623_2_2) + 5) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000623_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_112_1 + pub_r000623_14_1) + 21) & 127;
  int sub_step_126_2 = ((stage_v_112_2 + pub_r000623_14_2) + 21) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sec_r000623_18_1 + pub_r000623_5_1) + 31) & 127;
  int sub_step_127_2 = ((sec_r000623_18_2 + pub_r000623_5_2) + 31) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000623_21_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000623_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((sec_r000623_15_1 + pub_r000623_21_1) + 27) & 127;
  int sub_step_128_2 = ((sec_r000623_15_2 + pub_r000623_21_2) + 27) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000623_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((stage_v_71_1 + pub_r000623_19_1) + 23) & 127;
  int sub_step_129_2 = ((stage_v_71_2 + pub_r000623_19_2) + 23) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000623_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_123_1 + pub_r000623_14_1) + 23) & 127;
  int sub_step_130_2 = ((sub_step_123_2 + pub_r000623_14_2) + 23) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sec_r000623_11_1 + pub_r000623_19_1) + 28) & 127;
  int sub_step_131_2 = ((sec_r000623_11_2 + pub_r000623_19_2) + 28) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000623_20_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((sub_step_104_1 + pub_r000623_18_1) + 8) & 127;
  int sub_step_132_2 = ((sub_step_104_2 + pub_r000623_18_2) + 8) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000623_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000623_15_1 + pub_r000623_5_1) + 35) & 127;
  int sub_step_133_2 = ((sec_r000623_15_2 + pub_r000623_5_2) + 35) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000623_20_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000623_3_1 + pub_r000623_8_1) + 6) & 127;
  int sub_step_134_2 = ((sec_r000623_3_2 + pub_r000623_8_2) + 6) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000623_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sec_r000623_12_1 + pub_r000623_3_1) + 23) & 127;
  int sub_step_135_2 = ((sec_r000623_12_2 + pub_r000623_3_2) + 23) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000623_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_112_1 + pub_r000623_2_1) + 30) & 127;
  int sub_step_136_2 = ((sub_step_112_2 + pub_r000623_2_2) + 30) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000623_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((stage_v_70_1 + pub_r000623_17_1) + 15) & 127;
  int sub_step_137_2 = ((stage_v_70_2 + pub_r000623_17_2) + 15) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000623_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((stage_v_97_1 + pub_r000623_16_1) + 15) & 127;
  int sub_step_138_2 = ((stage_v_97_2 + pub_r000623_16_2) + 15) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000623_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sec_r000623_9_1 + pub_r000623_2_1) + 5) & 127;
  int sub_step_139_2 = ((sec_r000623_9_2 + pub_r000623_2_2) + 5) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000623_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((stage_v_99_1 + pub_r000623_4_1) + 26) & 127;
  int sub_step_140_2 = ((stage_v_99_2 + pub_r000623_4_2) + 26) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000623_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_92_1 + pub_r000623_19_1) + 24) & 127;
  int sub_step_141_2 = ((sub_step_92_2 + pub_r000623_19_2) + 24) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000623_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sec_r000623_16_1 + pub_r000623_14_1) + 11) & 127;
  int sub_step_142_2 = ((sec_r000623_16_2 + pub_r000623_14_2) + 11) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000623_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sec_r000623_0_1 + pub_r000623_7_1) + 31) & 127;
  int sub_step_143_2 = ((sec_r000623_0_2 + pub_r000623_7_2) + 31) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000623_13_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sub_step_75_1 + pub_r000623_10_1) + 13) & 127;
  int sub_step_144_2 = ((sub_step_75_2 + pub_r000623_10_2) + 13) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000623_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sub_step_83_1 + pub_r000623_1_1) + 17) & 127;
  int sub_step_145_2 = ((sub_step_83_2 + pub_r000623_1_2) + 17) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000623_16_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000623_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((stage_v_132_1 + pub_r000623_12_1) + 18) & 127;
  int sub_step_146_2 = ((stage_v_132_2 + pub_r000623_12_2) + 18) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000623_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((stage_v_82_1 + pub_r000623_9_1) + 17) & 127;
  int sub_step_147_2 = ((stage_v_82_2 + pub_r000623_9_2) + 17) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((stage_v_135_1 + pub_r000623_15_1) + 16) & 127;
  int sub_step_148_2 = ((stage_v_135_2 + pub_r000623_15_2) + 16) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000623_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sec_r000623_15_1 + pub_r000623_12_1) + 14) & 127;
  int sub_step_149_2 = ((sec_r000623_15_2 + pub_r000623_12_2) + 14) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000623_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_81_1 + pub_r000623_3_1) + 30) & 127;
  int sub_step_150_2 = ((stage_v_81_2 + pub_r000623_3_2) + 30) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000623_12_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((stage_v_94_1 + pub_r000623_9_1) + 10) & 127;
  int sub_step_151_2 = ((stage_v_94_2 + pub_r000623_9_2) + 10) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000623_12_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sub_step_96_1 + pub_r000623_21_1) + 5) & 127;
  int sub_step_152_2 = ((sub_step_96_2 + pub_r000623_21_2) + 5) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000623_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sub_step_141_1 + pub_r000623_10_1) + 16) & 127;
  int sub_step_153_2 = ((sub_step_141_2 + pub_r000623_10_2) + 16) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000623_14_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sub_step_133_1 + pub_r000623_7_1) + 22) & 127;
  int sub_step_154_2 = ((sub_step_133_2 + pub_r000623_7_2) + 22) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000623_9_1 + pub_r000623_1_1) + 18) & 127;
  int sub_step_155_2 = ((sec_r000623_9_2 + pub_r000623_1_2) + 18) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000623_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_146_1 + pub_r000623_18_1) + 20) & 127;
  int sub_step_156_2 = ((stage_v_146_2 + pub_r000623_18_2) + 20) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000623_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sub_step_93_1 + pub_r000623_7_1) + 32) & 127;
  int sub_step_157_2 = ((sub_step_93_2 + pub_r000623_7_2) + 32) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000623_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sub_step_157_1 + pub_r000623_8_1) + 8) & 127;
  int sub_step_158_2 = ((sub_step_157_2 + pub_r000623_8_2) + 8) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((stage_v_136_1 + pub_r000623_9_1) + 24) & 127;
  int sub_step_159_2 = ((stage_v_136_2 + pub_r000623_9_2) + 24) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000623_18_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((stage_v_119_1 + pub_r000623_14_1) + 35) & 127;
  int sub_step_160_2 = ((stage_v_119_2 + pub_r000623_14_2) + 35) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000623_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((stage_v_82_1 + pub_r000623_20_1) + 5) & 127;
  int sub_step_161_2 = ((stage_v_82_2 + pub_r000623_20_2) + 5) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000623_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000623_11_1 + pub_r000623_2_1) + 6) & 127;
  int sub_step_162_2 = ((sec_r000623_11_2 + pub_r000623_2_2) + 6) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000623_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sec_r000623_17_1 + pub_r000623_7_1) + 29) & 127;
  int sub_step_163_2 = ((sec_r000623_17_2 + pub_r000623_7_2) + 29) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((stage_v_158_1 + pub_r000623_3_1) + 15) & 127;
  int sub_step_164_2 = ((stage_v_158_2 + pub_r000623_3_2) + 15) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000623_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((sub_step_140_1 + pub_r000623_19_1) + 17) & 127;
  int sub_step_165_2 = ((sub_step_140_2 + pub_r000623_19_2) + 17) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000623_5_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((stage_v_163_1 + pub_r000623_21_1) + 26) & 127;
  int sub_step_166_2 = ((stage_v_163_2 + pub_r000623_21_2) + 26) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000623_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((stage_v_92_1 + pub_r000623_7_1) + 27) & 127;
  int sub_step_167_2 = ((stage_v_92_2 + pub_r000623_7_2) + 27) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sec_r000623_21_1 + pub_r000623_10_1) + 23) & 127;
  int sub_step_168_2 = ((sec_r000623_21_2 + pub_r000623_10_2) + 23) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000623_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sub_step_136_1 + pub_r000623_18_1) + 20) & 127;
  int sub_step_169_2 = ((sub_step_136_2 + pub_r000623_18_2) + 20) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000623_6_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000623_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sub_step_137_1 + pub_r000623_13_1) + 12) & 127;
  int sub_step_170_2 = ((sub_step_137_2 + pub_r000623_13_2) + 12) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000623_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sub_step_160_1 + pub_r000623_20_1) + 11) & 127;
  int sub_step_171_2 = ((sub_step_160_2 + pub_r000623_20_2) + 11) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000623_17_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_82_1 + pub_r000623_14_1) + 31) & 127;
  int sub_step_172_2 = ((sub_step_82_2 + pub_r000623_14_2) + 31) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000623_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sec_r000623_20_1 + pub_r000623_17_1) + 12) & 127;
  int sub_step_173_2 = ((sec_r000623_20_2 + pub_r000623_17_2) + 12) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000623_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sec_r000623_10_1 + pub_r000623_2_1) + 32) & 127;
  int sub_step_174_2 = ((sec_r000623_10_2 + pub_r000623_2_2) + 32) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000623_3_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((stage_v_170_1 + pub_r000623_14_1) + 32) & 127;
  int sub_step_175_2 = ((stage_v_170_2 + pub_r000623_14_2) + 32) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000623_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sub_step_167_1 + pub_r000623_4_1) + 15) & 127;
  int sub_step_176_2 = ((sub_step_167_2 + pub_r000623_4_2) + 15) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000623_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_104_1 + pub_r000623_17_1) + 14) & 127;
  int sub_step_177_2 = ((stage_v_104_2 + pub_r000623_17_2) + 14) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000623_7_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((stage_v_170_1 + pub_r000623_11_1) + 23) & 127;
  int sub_step_178_2 = ((stage_v_170_2 + pub_r000623_11_2) + 23) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000623_0_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_140_1 + pub_r000623_15_1) + 32) & 127;
  int sub_step_179_2 = ((stage_v_140_2 + pub_r000623_15_2) + 32) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000623_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((stage_v_144_1 + pub_r000623_11_1) + 26) & 127;
  int sub_step_180_2 = ((stage_v_144_2 + pub_r000623_11_2) + 26) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000623_19_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((stage_v_144_1 + pub_r000623_3_1) + 14) & 127;
  int sub_step_181_2 = ((stage_v_144_2 + pub_r000623_3_2) + 14) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000623_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((stage_v_85_1 + pub_r000623_1_1) + 16) & 127;
  int sub_step_182_2 = ((stage_v_85_2 + pub_r000623_1_2) + 16) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000623_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_99_1 + pub_r000623_9_1) + 13) & 127;
  int sub_step_183_2 = ((sub_step_99_2 + pub_r000623_9_2) + 13) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_72_1 + pub_r000623_1_1) + 34) & 127;
  int sub_step_184_2 = ((sub_step_72_2 + pub_r000623_1_2) + 34) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000623_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((stage_v_163_1 + pub_r000623_5_1) + 7) & 127;
  int sub_step_185_2 = ((stage_v_163_2 + pub_r000623_5_2) + 7) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000623_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((stage_v_178_1 + pub_r000623_17_1) + 9) & 127;
  int sub_step_186_2 = ((stage_v_178_2 + pub_r000623_17_2) + 9) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000623_4_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_165_1 + pub_r000623_15_1) + 28) & 127;
  int sub_step_187_2 = ((stage_v_165_2 + pub_r000623_15_2) + 28) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000623_8_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_130_1 + pub_r000623_8_1) + 10) & 127;
  int sub_step_188_2 = ((sub_step_130_2 + pub_r000623_8_2) + 10) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000623_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((stage_v_108_1 + pub_r000623_9_1) + 8) & 127;
  int sub_step_189_2 = ((stage_v_108_2 + pub_r000623_9_2) + 8) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000623_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sec_r000623_18_1 + pub_r000623_2_1) + 26) & 127;
  int sub_step_190_2 = ((sec_r000623_18_2 + pub_r000623_2_2) + 26) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000623_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sub_step_112_1 + pub_r000623_10_1) + 5) & 127;
  int sub_step_191_2 = ((sub_step_112_2 + pub_r000623_10_2) + 5) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000623_21_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000623_21_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sec_r000623_12_1 + pub_r000623_6_1) + 12) & 127;
  int sub_step_192_2 = ((sec_r000623_12_2 + pub_r000623_6_2) + 12) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000623_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000623_14_1 + pub_r000623_8_1) + 28) & 127;
  int sub_step_193_2 = ((sec_r000623_14_2 + pub_r000623_8_2) + 28) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000623_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((sec_r000623_20_1 + pub_r000623_1_1) + 24) & 127;
  int sub_step_194_2 = ((sec_r000623_20_2 + pub_r000623_1_2) + 24) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000623_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000623_11_1 + pub_r000623_0_1) + 9) & 127;
  int sub_step_195_2 = ((sec_r000623_11_2 + pub_r000623_0_2) + 9) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sub_step_71_1 + pub_r000623_0_1) + 13) & 127;
  int sub_step_196_2 = ((sub_step_71_2 + pub_r000623_0_2) + 13) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000623_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sub_step_129_1 + pub_r000623_5_1) + 23) & 127;
  int sub_step_197_2 = ((sub_step_129_2 + pub_r000623_5_2) + 23) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000623_16_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000623_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((stage_v_87_1 + pub_r000623_11_1) + 18) & 127;
  int sub_step_198_2 = ((stage_v_87_2 + pub_r000623_11_2) + 18) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000623_19_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((sub_step_109_1 + pub_r000623_6_1) + 18) & 127;
  int sub_step_199_2 = ((sub_step_109_2 + pub_r000623_6_2) + 18) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000623_20_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((stage_v_86_1 + pub_r000623_14_1) + 12) & 127;
  int sub_step_200_2 = ((stage_v_86_2 + pub_r000623_14_2) + 12) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000623_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000623_10_1 + pub_r000623_17_1) + 6) & 127;
  int sub_step_201_2 = ((sec_r000623_10_2 + pub_r000623_17_2) + 6) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000623_6_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000623_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((stage_v_200_1 + pub_r000623_15_1) + 5) & 127;
  int sub_step_202_2 = ((stage_v_200_2 + pub_r000623_15_2) + 5) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000623_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sec_r000623_7_1 + pub_r000623_21_1) + 22) & 127;
  int sub_step_203_2 = ((sec_r000623_7_2 + pub_r000623_21_2) + 22) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000623_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_142_1 + pub_r000623_14_1) + 33) & 127;
  int sub_step_204_2 = ((stage_v_142_2 + pub_r000623_14_2) + 33) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000623_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sub_step_119_1 + pub_r000623_3_1) + 31) & 127;
  int sub_step_205_2 = ((sub_step_119_2 + pub_r000623_3_2) + 31) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000623_19_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_170_1 + pub_r000623_5_1) + 21) & 127;
  int sub_step_206_2 = ((stage_v_170_2 + pub_r000623_5_2) + 21) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000623_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((sec_r000623_4_1 + pub_r000623_21_1) + 7) & 127;
  int sub_step_207_2 = ((sec_r000623_4_2 + pub_r000623_21_2) + 7) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000623_13_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000623_13_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sec_r000623_17_1 + pub_r000623_2_1) + 15) & 127;
  int sub_step_208_2 = ((sec_r000623_17_2 + pub_r000623_2_2) + 15) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000623_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sec_r000623_18_1 + pub_r000623_16_1) + 27) & 127;
  int sub_step_209_2 = ((sec_r000623_18_2 + pub_r000623_16_2) + 27) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000623_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((stage_v_175_1 + pub_r000623_5_1) + 24) & 127;
  int sub_step_210_2 = ((stage_v_175_2 + pub_r000623_5_2) + 24) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000623_11_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sub_step_74_1 + pub_r000623_20_1) + 19) & 127;
  int sub_step_211_2 = ((sub_step_74_2 + pub_r000623_20_2) + 19) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000623_17_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sec_r000623_12_1 + pub_r000623_9_1) + 22) & 127;
  int sub_step_212_2 = ((sec_r000623_12_2 + pub_r000623_9_2) + 22) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000623_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sec_r000623_6_1 + pub_r000623_19_1) + 5) & 127;
  int sub_step_213_2 = ((sec_r000623_6_2 + pub_r000623_19_2) + 5) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000623_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_166_1 + pub_r000623_21_1) + 32) & 127;
  int sub_step_214_2 = ((stage_v_166_2 + pub_r000623_21_2) + 32) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000623_1_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sec_r000623_4_1 + pub_r000623_18_1) + 11) & 127;
  int sub_step_215_2 = ((sec_r000623_4_2 + pub_r000623_18_2) + 11) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000623_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sub_step_115_1 + pub_r000623_21_1) + 10) & 127;
  int sub_step_216_2 = ((sub_step_115_2 + pub_r000623_21_2) + 10) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000623_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sub_step_86_1 + pub_r000623_19_1) + 8) & 127;
  int sub_step_217_2 = ((sub_step_86_2 + pub_r000623_19_2) + 8) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000623_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_103_1 + pub_r000623_4_1) + 22) & 127;
  int sub_step_218_2 = ((stage_v_103_2 + pub_r000623_4_2) + 22) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000623_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sub_step_189_1 + pub_r000623_11_1) + 10) & 127;
  int sub_step_219_2 = ((sub_step_189_2 + pub_r000623_11_2) + 10) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000623_3_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000623_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sub_step_169_1 + pub_r000623_11_1) + 33) & 127;
  int sub_step_220_2 = ((sub_step_169_2 + pub_r000623_11_2) + 33) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000623_19_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sec_r000623_16_1 + pub_r000623_11_1) + 7) & 127;
  int sub_step_221_2 = ((sec_r000623_16_2 + pub_r000623_11_2) + 7) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000623_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sec_r000623_19_1 + pub_r000623_14_1) + 11) & 127;
  int sub_step_222_2 = ((sec_r000623_19_2 + pub_r000623_14_2) + 11) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000623_20_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000623_20_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sub_step_96_1 + pub_r000623_11_1) + 32) & 127;
  int sub_step_223_2 = ((sub_step_96_2 + pub_r000623_11_2) + 32) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000623_4_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((stage_v_181_1 + pub_r000623_3_1) + 30) & 127;
  int sub_step_224_2 = ((stage_v_181_2 + pub_r000623_3_2) + 30) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000623_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_163_1 + pub_r000623_16_1) + 12) & 127;
  int sub_step_225_2 = ((sub_step_163_2 + pub_r000623_16_2) + 12) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000623_15_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000623_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sec_r000623_1_1 + pub_r000623_12_1) + 16) & 127;
  int sub_step_226_2 = ((sec_r000623_1_2 + pub_r000623_12_2) + 16) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000623_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000623_19_1 + pub_r000623_19_1) + 21) & 127;
  int sub_step_227_2 = ((sec_r000623_19_2 + pub_r000623_19_2) + 21) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sec_r000623_4_1 + pub_r000623_18_1) + 12) & 127;
  int sub_step_228_2 = ((sec_r000623_4_2 + pub_r000623_18_2) + 12) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000623_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((sec_r000623_9_1 + pub_r000623_19_1) + 17) & 127;
  int sub_step_229_2 = ((sec_r000623_9_2 + pub_r000623_19_2) + 17) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000623_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sec_r000623_12_1 + pub_r000623_1_1) + 27) & 127;
  int sub_step_230_2 = ((sec_r000623_12_2 + pub_r000623_1_2) + 27) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000623_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((sub_step_106_1 + pub_r000623_15_1) + 12) & 127;
  int sub_step_231_2 = ((sub_step_106_2 + pub_r000623_15_2) + 12) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000623_2_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000623_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sec_r000623_21_1 + pub_r000623_3_1) + 9) & 127;
  int sub_step_232_2 = ((sec_r000623_21_2 + pub_r000623_3_2) + 9) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000623_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sec_r000623_1_1 + pub_r000623_16_1) + 23) & 127;
  int sub_step_233_2 = ((sec_r000623_1_2 + pub_r000623_16_2) + 23) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000623_18_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sec_r000623_22_1 + pub_r000623_21_1) + 26) & 127;
  int sub_step_234_2 = ((sec_r000623_22_2 + pub_r000623_21_2) + 26) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000623_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sub_step_111_1 + pub_r000623_6_1) + 18) & 127;
  int sub_step_235_2 = ((sub_step_111_2 + pub_r000623_6_2) + 18) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_235_1 & 15;
  st_var_3_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((sub_step_96_1 + pub_r000623_3_1) + 28) & 127;
  int sub_step_236_2 = ((sub_step_96_2 + pub_r000623_3_2) + 28) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000623_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((sub_step_157_1 + pub_r000623_20_1) + 30) & 127;
  int sub_step_237_2 = ((sub_step_157_2 + pub_r000623_20_2) + 30) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000623_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((stage_v_177_1 + pub_r000623_2_1) + 31) & 127;
  int sub_step_238_2 = ((stage_v_177_2 + pub_r000623_2_2) + 31) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000623_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_238_1 & 15;
  st_var_2_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((sec_r000623_5_1 + pub_r000623_13_1) + 7) & 127;
  int sub_step_239_2 = ((sec_r000623_5_2 + pub_r000623_13_2) + 7) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000623_10_2) & 127;
  st_var_3_1.buffer[2] = stage_v_239_1 & 15;
  st_var_3_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((stage_v_207_1 + pub_r000623_12_1) + 10) & 127;
  int sub_step_240_2 = ((stage_v_207_2 + pub_r000623_12_2) + 10) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000623_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((sub_step_114_1 + pub_r000623_15_1) + 11) & 127;
  int sub_step_241_2 = ((sub_step_114_2 + pub_r000623_15_2) + 11) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000623_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sec_r000623_4_1 + pub_r000623_1_1) + 35) & 127;
  int sub_step_242_2 = ((sec_r000623_4_2 + pub_r000623_1_2) + 35) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000623_17_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000623_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sec_r000623_18_1 + pub_r000623_19_1) + 15) & 127;
  int sub_step_243_2 = ((sec_r000623_18_2 + pub_r000623_19_2) + 15) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000623_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_243_1 & 15;
  st_var_3_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((stage_v_77_1 + pub_r000623_5_1) + 6) & 127;
  int sub_step_244_2 = ((stage_v_77_2 + pub_r000623_5_2) + 6) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000623_4_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000623_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_244_1 & 15;
  st_var_0_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sec_r000623_9_1 + pub_r000623_15_1) + 25) & 127;
  int sub_step_245_2 = ((sec_r000623_9_2 + pub_r000623_15_2) + 25) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000623_18_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000623_18_2) & 127;
  st_var_1_1.buffer[2] = stage_v_245_1 & 15;
  st_var_1_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((sub_step_155_1 + pub_r000623_7_1) + 32) & 127;
  int sub_step_246_2 = ((sub_step_155_2 + pub_r000623_7_2) + 32) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000623_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_246_1 & 15;
  st_var_2_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sec_r000623_3_1 + pub_r000623_17_1) + 23) & 127;
  int sub_step_247_2 = ((sec_r000623_3_2 + pub_r000623_17_2) + 23) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000623_7_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000623_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_247_1 & 15;
  st_var_3_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((stage_v_131_1 + pub_r000623_14_1) + 18) & 127;
  int sub_step_248_2 = ((stage_v_131_2 + pub_r000623_14_2) + 18) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000623_0_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000623_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_248_1 & 15;
  st_var_0_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int sub_step_249_1 = ((stage_v_156_1 + pub_r000623_9_1) + 10) & 127;
  int sub_step_249_2 = ((stage_v_156_2 + pub_r000623_9_2) + 10) & 127;
  int stage_v_249_1 = ((sub_step_249_1 * 2) + pub_r000623_11_1) & 127;
  int stage_v_249_2 = ((sub_step_249_2 * 2) + pub_r000623_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_249_1 & 15;
  st_var_1_2.buffer[0] = stage_v_249_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int sub_step_250_1 = ((sub_step_216_1 + pub_r000623_18_1) + 7) & 127;
  int sub_step_250_2 = ((sub_step_216_2 + pub_r000623_18_2) + 7) & 127;
  int stage_v_250_1 = ((sub_step_250_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_250_2 = ((sub_step_250_2 * 2) + pub_r000623_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_250_1 & 15;
  st_var_2_2.buffer[1] = stage_v_250_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int sub_step_251_1 = ((stage_v_178_1 + pub_r000623_21_1) + 8) & 127;
  int sub_step_251_2 = ((stage_v_178_2 + pub_r000623_21_2) + 8) & 127;
  int stage_v_251_1 = ((sub_step_251_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_251_2 = ((sub_step_251_2 * 2) + pub_r000623_12_2) & 127;
  st_var_3_1.buffer[2] = stage_v_251_1 & 15;
  st_var_3_2.buffer[2] = stage_v_251_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int sub_step_252_1 = ((sub_step_205_1 + pub_r000623_18_1) + 13) & 127;
  int sub_step_252_2 = ((sub_step_205_2 + pub_r000623_18_2) + 13) & 127;
  int stage_v_252_1 = ((sub_step_252_1 * 2) + pub_r000623_1_1) & 127;
  int stage_v_252_2 = ((sub_step_252_2 * 2) + pub_r000623_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_252_1 & 15;
  st_var_0_2.buffer[0] = stage_v_252_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int sub_step_253_1 = ((sub_step_163_1 + pub_r000623_10_1) + 5) & 127;
  int sub_step_253_2 = ((sub_step_163_2 + pub_r000623_10_2) + 5) & 127;
  int stage_v_253_1 = ((sub_step_253_1 * 2) + pub_r000623_19_1) & 127;
  int stage_v_253_2 = ((sub_step_253_2 * 2) + pub_r000623_19_2) & 127;
  st_var_1_1.buffer[1] = stage_v_253_1 & 15;
  st_var_1_2.buffer[1] = stage_v_253_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int sub_step_254_1 = ((stage_v_142_1 + pub_r000623_5_1) + 21) & 127;
  int sub_step_254_2 = ((stage_v_142_2 + pub_r000623_5_2) + 21) & 127;
  int stage_v_254_1 = ((sub_step_254_1 * 2) + pub_r000623_12_1) & 127;
  int stage_v_254_2 = ((sub_step_254_2 * 2) + pub_r000623_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_254_1 & 15;
  st_var_2_2.buffer[2] = stage_v_254_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int sub_step_255_1 = ((sec_r000623_6_1 + pub_r000623_21_1) + 29) & 127;
  int sub_step_255_2 = ((sec_r000623_6_2 + pub_r000623_21_2) + 29) & 127;
  int stage_v_255_1 = ((sub_step_255_1 * 2) + pub_r000623_9_1) & 127;
  int stage_v_255_2 = ((sub_step_255_2 * 2) + pub_r000623_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_255_1 & 15;
  st_var_3_2.buffer[0] = stage_v_255_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int sub_step_256_1 = ((sub_step_154_1 + pub_r000623_11_1) + 7) & 127;
  int sub_step_256_2 = ((sub_step_154_2 + pub_r000623_11_2) + 7) & 127;
  int stage_v_256_1 = ((sub_step_256_1 * 2) + pub_r000623_10_1) & 127;
  int stage_v_256_2 = ((sub_step_256_2 * 2) + pub_r000623_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_256_1 & 15;
  st_var_0_2.buffer[1] = stage_v_256_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int sub_step_257_1 = ((stage_v_166_1 + pub_r000623_1_1) + 24) & 127;
  int sub_step_257_2 = ((stage_v_166_2 + pub_r000623_1_2) + 24) & 127;
  int stage_v_257_1 = ((sub_step_257_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_257_2 = ((sub_step_257_2 * 2) + pub_r000623_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_257_1 & 15;
  st_var_1_2.buffer[2] = stage_v_257_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int sub_step_258_1 = ((stage_v_161_1 + pub_r000623_2_1) + 24) & 127;
  int sub_step_258_2 = ((stage_v_161_2 + pub_r000623_2_2) + 24) & 127;
  int stage_v_258_1 = ((sub_step_258_1 * 2) + pub_r000623_16_1) & 127;
  int stage_v_258_2 = ((sub_step_258_2 * 2) + pub_r000623_16_2) & 127;
  st_var_2_1.buffer[0] = stage_v_258_1 & 15;
  st_var_2_2.buffer[0] = stage_v_258_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int sub_step_259_1 = ((stage_v_241_1 + pub_r000623_5_1) + 34) & 127;
  int sub_step_259_2 = ((stage_v_241_2 + pub_r000623_5_2) + 34) & 127;
  int stage_v_259_1 = ((sub_step_259_1 * 2) + pub_r000623_5_1) & 127;
  int stage_v_259_2 = ((sub_step_259_2 * 2) + pub_r000623_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_259_1 & 15;
  st_var_3_2.buffer[1] = stage_v_259_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int sub_step_260_1 = ((sub_step_109_1 + pub_r000623_15_1) + 23) & 127;
  int sub_step_260_2 = ((sub_step_109_2 + pub_r000623_15_2) + 23) & 127;
  int stage_v_260_1 = ((sub_step_260_1 * 2) + pub_r000623_14_1) & 127;
  int stage_v_260_2 = ((sub_step_260_2 * 2) + pub_r000623_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_260_1 & 15;
  st_var_0_2.buffer[2] = stage_v_260_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int sub_step_261_1 = ((sub_step_112_1 + pub_r000623_18_1) + 25) & 127;
  int sub_step_261_2 = ((sub_step_112_2 + pub_r000623_18_2) + 25) & 127;
  int stage_v_261_1 = ((sub_step_261_1 * 2) + pub_r000623_8_1) & 127;
  int stage_v_261_2 = ((sub_step_261_2 * 2) + pub_r000623_8_2) & 127;
  st_var_1_1.buffer[0] = stage_v_261_1 & 15;
  st_var_1_2.buffer[0] = stage_v_261_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000623_4_1 == pub_r000623_4_2);
  __CPROVER_assume(pub_r000623_21_1 == pub_r000623_21_2);
  __CPROVER_assume(sec_r000623_2_1 != sec_r000623_2_2);
  __CPROVER_assume(sec_r000623_10_1 != sec_r000623_10_2);
  __CPROVER_assume(sec_r000623_5_1 != sec_r000623_5_2);
  __CPROVER_assume(pub_r000623_2_1 == pub_r000623_2_2);
  __CPROVER_assume(pub_r000623_3_1 == pub_r000623_3_2);
  __CPROVER_assume(pub_r000623_19_1 == pub_r000623_19_2);
  __CPROVER_assume(sec_r000623_19_1 != sec_r000623_19_2);
  __CPROVER_assume(pub_r000623_12_1 == pub_r000623_12_2);
  __CPROVER_assume(pub_r000623_7_1 == pub_r000623_7_2);
  __CPROVER_assume(sec_r000623_22_1 != sec_r000623_22_2);
  __CPROVER_assume(sec_r000623_17_1 != sec_r000623_17_2);
  __CPROVER_assume(sec_r000623_8_1 != sec_r000623_8_2);
  __CPROVER_assume(sec_r000623_13_1 != sec_r000623_13_2);
  __CPROVER_assume(sec_r000623_0_1 != sec_r000623_0_2);
  __CPROVER_assume(sec_r000623_4_1 != sec_r000623_4_2);
  __CPROVER_assume(pub_r000623_8_1 == pub_r000623_8_2);
  __CPROVER_assume(sec_r000623_21_1 != sec_r000623_21_2);
  __CPROVER_assume(pub_r000623_15_1 == pub_r000623_15_2);
  __CPROVER_assume(pub_r000623_10_1 == pub_r000623_10_2);
  __CPROVER_assume(pub_r000623_0_1 == pub_r000623_0_2);
  __CPROVER_assume(pub_r000623_14_1 == pub_r000623_14_2);
  __CPROVER_assume(sec_r000623_16_1 != sec_r000623_16_2);
  __CPROVER_assume(pub_r000623_13_1 == pub_r000623_13_2);
  __CPROVER_assume(pub_r000623_6_1 == pub_r000623_6_2);
  __CPROVER_assume(sec_r000623_12_1 != sec_r000623_12_2);
  __CPROVER_assume(sec_r000623_11_1 != sec_r000623_11_2);
  __CPROVER_assume(sec_r000623_14_1 != sec_r000623_14_2);
  __CPROVER_assume(sec_r000623_9_1 != sec_r000623_9_2);
  __CPROVER_assume(pub_r000623_16_1 == pub_r000623_16_2);
  __CPROVER_assume(sec_r000623_18_1 != sec_r000623_18_2);
  __CPROVER_assume(pub_r000623_20_1 == pub_r000623_20_2);
  __CPROVER_assume(sec_r000623_1_1 != sec_r000623_1_2);
  __CPROVER_assume(pub_r000623_9_1 == pub_r000623_9_2);
  __CPROVER_assume(sec_r000623_3_1 != sec_r000623_3_2);
  __CPROVER_assume(sec_r000623_7_1 != sec_r000623_7_2);
  __CPROVER_assume(pub_r000623_5_1 == pub_r000623_5_2);
  __CPROVER_assume(sec_r000623_15_1 != sec_r000623_15_2);
  __CPROVER_assume(pub_r000623_11_1 == pub_r000623_11_2);
  __CPROVER_assume(sec_r000623_6_1 != sec_r000623_6_2);
  __CPROVER_assume(pub_r000623_1_1 == pub_r000623_1_2);
  __CPROVER_assume(sec_r000623_20_1 != sec_r000623_20_2);
  __CPROVER_assume(pub_r000623_17_1 == pub_r000623_17_2);
  __CPROVER_assume(pub_r000623_18_1 == pub_r000623_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.dim == st_var_3_2.dim);
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
  assert(sub_step_69_1 == sub_step_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(sub_step_70_1 == sub_step_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(sub_step_71_1 == sub_step_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(sub_step_72_1 == sub_step_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(sub_step_73_1 == sub_step_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(sub_step_74_1 == sub_step_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(sub_step_75_1 == sub_step_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(sub_step_76_1 == sub_step_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(sub_step_77_1 == sub_step_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(sub_step_231_1 == sub_step_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(sub_step_232_1 == sub_step_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(sub_step_233_1 == sub_step_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(sub_step_234_1 == sub_step_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(sub_step_235_1 == sub_step_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(sub_step_236_1 == sub_step_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(sub_step_237_1 == sub_step_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(sub_step_238_1 == sub_step_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(sub_step_239_1 == sub_step_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(sub_step_240_1 == sub_step_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(sub_step_241_1 == sub_step_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(sub_step_242_1 == sub_step_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(sub_step_243_1 == sub_step_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(sub_step_244_1 == sub_step_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(sub_step_245_1 == sub_step_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(sub_step_246_1 == sub_step_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(sub_step_247_1 == sub_step_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(sub_step_248_1 == sub_step_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(sub_step_249_1 == sub_step_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(sub_step_250_1 == sub_step_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(sub_step_251_1 == sub_step_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(sub_step_252_1 == sub_step_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(sub_step_253_1 == sub_step_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(sub_step_254_1 == sub_step_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(sub_step_255_1 == sub_step_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(sub_step_256_1 == sub_step_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(sub_step_257_1 == sub_step_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(sub_step_258_1 == sub_step_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(sub_step_259_1 == sub_step_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(sub_step_260_1 == sub_step_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(sub_step_261_1 == sub_step_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
}


