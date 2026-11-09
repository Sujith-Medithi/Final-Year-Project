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
struct FilterState_R001860_6013_0
{
  unsigned char mode;
  unsigned char prev_out;
  int cutoff;
  int prev_in;
  int damping;
  short gain_db;
  int buffer[3];
};
struct DeviceConfig_R001860_6013_1
{
  unsigned char timeout;
  int port;
  short baud_rate;
  int buffer[3];
};
struct MatrixBlock_R001860_6013_2
{
  int stride;
  unsigned char determinant;
  short trace;
  int dim;
  unsigned char scale;
  short density;
  int buffer[3];
};
struct StreamBuffer_R001860_6013_3
{
  short checksum;
  short head;
  int watermark;
  int state;
  short capacity;
  int tail;
  int buffer[3];
};
union PacketPayload_R001860_6013_0
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
void fn_R001860_6013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int offset_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_38_1) & 63;
  aux_2 = (aux_2 + offset_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_17_1 = 0;
  int margin_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_17_1 = ((margin_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_17_2 = ((margin_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_17_1) & 127;
    acc_2 = (acc_2 + margin_17_2) & 127;
  }

  int parity_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_76_1)
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

  switch (parity_76_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_38_1 == offset_38_2);
  assert(margin_17_1 == margin_17_2);
  assert(parity_76_1 == parity_76_2);
}

int fn_R001860_6013_0(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_38) & 63;
  acc ^= aux;
  int margin_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_17 = ((margin_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_17) & 127;
  }

  int parity_76 = (aux + st.buffer[1]) & 3;
  switch (parity_76)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st_1 = {0};
  struct StreamBuffer_R001860_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_93_1) & 63;
  aux_2 = (aux_2 + window_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_67_1 = local_arr_1[aux_1 % 3];
  int window_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_93_1 == window_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_67_1 == window_67_2);
}

int fn_R001860_6013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_93) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_67 = local_arr[aux % 3];
  acc = (acc + (window_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int margin_36_1 = 0;
  int margin_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_36_1 = ((margin_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_36_2 = ((margin_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_36_1) & 127;
    acc_2 = (acc_2 + margin_36_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_71_1 = local_arr_1[aux_1 % 3];
  int window_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_36_1 == margin_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_71_1 == window_71_2);
}

int fn_R001860_6013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int margin_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_36 = ((margin_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_36) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_71 = local_arr[aux % 3];
  acc = (acc + (window_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
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
  int tally_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_99_1 > 18)
  {
    acc_1 = ((acc_1 + (tally_99_1 * 2)) + 5) & 127;
    aux_1 ^= tally_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_99_2 > 18)
  {
    acc_2 = ((acc_2 + (tally_99_2 * 2)) + 5) & 127;
    aux_2 ^= tally_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_82_1) & 63;
  aux_2 = (aux_2 + checksum_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_84_1 = 0;
  int weight_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_84_1 = ((weight_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_84_2 = ((weight_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_84_1) & 127;
    acc_2 = (acc_2 + weight_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_99_1 == tally_99_2);
  assert(checksum_82_1 == checksum_82_2);
  assert(weight_84_1 == weight_84_2);
}

int fn_R001860_6013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_99 > 18)
  {
    acc = ((acc + (tally_99 * 2)) + 5) & 127;
    aux ^= tally_99 & 15;
  }
  else
  {
    acc = ((acc - tally_99) + 11) & 127;
    aux += 3;
  }
  int checksum_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_82) & 63;
  acc ^= aux;
  int weight_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_84 = ((weight_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001860_6013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001860_6013_2 st_1 = {0};
  struct MatrixBlock_R001860_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int vector_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_75_1)
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

  switch (vector_75_2)
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

  int tally_49_1 = 0;
  int tally_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_49_1 = ((tally_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_49_2 = ((tally_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_49_1) & 127;
    acc_2 = (acc_2 + tally_49_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_75_1 == vector_75_2);
  assert(tally_49_1 == tally_49_2);
}

int fn_R001860_6013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001860_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int vector_75 = (aux + st.buffer[1]) & 3;
  switch (vector_75)
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

  int tally_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_49 = ((tally_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_49) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001860_6013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st_1 = {0};
  struct FilterState_R001860_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_82_1)
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

  switch (metric_82_2)
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

  int stride_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_90_1) & 63;
  aux_2 = (aux_2 + stride_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_82_1 == metric_82_2);
  assert(stride_90_1 == stride_90_2);
}

int fn_R001860_6013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_82 = (aux + st.buffer[1]) & 3;
  switch (metric_82)
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

  int stride_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_90) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st_1 = {0};
  struct FilterState_R001860_6013_0 st_2 = {0};
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
  int residue_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_57_1) & 63;
  aux_2 = (aux_2 + residue_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_70_1 = local_arr_1[aux_1 % 3];
  int bound_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_70_2 * 2)) & 127;
  int coefficient_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_80_1)
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

  switch (coefficient_80_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_57_1 == residue_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_70_1 == bound_70_2);
  assert(coefficient_80_1 == coefficient_80_2);
}

int fn_R001860_6013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_57) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_70 = local_arr[aux % 3];
  acc = (acc + (bound_70 * 2)) & 127;
  int coefficient_80 = (aux + st.buffer[1]) & 3;
  switch (coefficient_80)
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

void fn_R001860_6013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_36_1 = local_arr_1[aux_1 % 3];
  int sample_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_36_2 * 2)) & 127;
  int threshold_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_79_1)
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

  switch (threshold_79_2)
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

  int metric_41_1 = 0;
  int metric_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_41_1 = ((metric_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_41_2 = ((metric_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_41_1) & 127;
    acc_2 = (acc_2 + metric_41_2) & 127;
  }

  int factor_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_93_1 > 49)
  {
    acc_1 = ((acc_1 + (factor_93_1 * 2)) + 5) & 127;
    aux_1 ^= factor_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_93_2 > 49)
  {
    acc_2 = ((acc_2 + (factor_93_2 * 2)) + 5) & 127;
    aux_2 ^= factor_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(sample_36_1 == sample_36_2);
  assert(threshold_79_1 == threshold_79_2);
  assert(metric_41_1 == metric_41_2);
  assert(factor_93_1 == factor_93_2);
}

int fn_R001860_6013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int sample_36 = local_arr[aux % 3];
  acc = (acc + (sample_36 * 2)) & 127;
  int threshold_79 = (aux + st.buffer[1]) & 3;
  switch (threshold_79)
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

  int metric_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_41 = ((metric_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_41) & 127;
  }

  int factor_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_93 > 49)
  {
    acc = ((acc + (factor_93 * 2)) + 5) & 127;
    aux ^= factor_93 & 15;
  }
  else
  {
    acc = ((acc - factor_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001860_6013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st_1 = {0};
  struct FilterState_R001860_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int checksum_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_98_1 > 31)
  {
    acc_1 = ((acc_1 + (checksum_98_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_98_2 > 31)
  {
    acc_2 = ((acc_2 + (checksum_98_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_75_1 = 0;
  int sample_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_75_1 = ((sample_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_75_2 = ((sample_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_75_1) & 127;
    acc_2 = (acc_2 + sample_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(sample_75_1 == sample_75_2);
}

int fn_R001860_6013_8(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int checksum_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_98 > 31)
  {
    acc = ((acc + (checksum_98 * 2)) + 5) & 127;
    aux ^= checksum_98 & 15;
  }
  else
  {
    acc = ((acc - checksum_98) + 11) & 127;
    aux += 3;
  }
  int sample_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_75 = ((sample_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001860_6013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st_1 = {0};
  struct FilterState_R001860_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_22_1)
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

  switch (damping_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_28_1) & 63;
  aux_2 = (aux_2 + phase_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_22_1 == damping_22_2);
  assert(phase_28_1 == phase_28_2);
}

int fn_R001860_6013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001860_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_22 = (aux + st.buffer[1]) & 3;
  switch (damping_22)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001860_6013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st_1 = {0};
  struct StreamBuffer_R001860_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_98_1 > 29)
  {
    acc_1 = ((acc_1 + (vector_98_1 * 2)) + 5) & 127;
    aux_1 ^= vector_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_98_2 > 29)
  {
    acc_2 = ((acc_2 + (vector_98_2 * 2)) + 5) & 127;
    aux_2 ^= vector_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_98_1 == vector_98_2);
}

int fn_R001860_6013_10(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_98 > 29)
  {
    acc = ((acc + (vector_98 * 2)) + 5) & 127;
    aux ^= vector_98 & 15;
  }
  else
  {
    acc = ((acc - vector_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_58_1 = 0;
  int factor_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_58_1 = ((factor_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_58_2 = ((factor_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_58_1) & 127;
    acc_2 = (acc_2 + factor_58_2) & 127;
  }

  int stride_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_41_1 > 47)
  {
    acc_1 = ((acc_1 + (stride_41_1 * 2)) + 5) & 127;
    aux_1 ^= stride_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_41_2 > 47)
  {
    acc_2 = ((acc_2 + (stride_41_2 * 2)) + 5) & 127;
    aux_2 ^= stride_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_83_1 = local_arr_1[aux_1 % 3];
  int metric_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_83_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_58_1 == factor_58_2);
  assert(stride_41_1 == stride_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_83_1 == metric_83_2);
}

int fn_R001860_6013_11(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_58 = ((factor_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_58) & 127;
  }

  int stride_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_41 > 47)
  {
    acc = ((acc + (stride_41 * 2)) + 5) & 127;
    aux ^= stride_41 & 15;
  }
  else
  {
    acc = ((acc - stride_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_83 = local_arr[aux % 3];
  acc = (acc + (metric_83 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001860_6013_2 st_1 = {0};
  struct MatrixBlock_R001860_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_26_1 = local_arr_1[aux_1 % 3];
  int coefficient_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_26_2 * 2)) & 127;
  int pivot_12_1 = 0;
  int pivot_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_12_1 = ((pivot_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_12_2 = ((pivot_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_12_1) & 127;
    acc_2 = (acc_2 + pivot_12_2) & 127;
  }

  int phase_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_20_1)
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

  switch (phase_20_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_26_1 == coefficient_26_2);
  assert(pivot_12_1 == pivot_12_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R001860_6013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001860_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int coefficient_26 = local_arr[aux % 3];
  acc = (acc + (coefficient_26 * 2)) & 127;
  int pivot_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_12 = ((pivot_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_12) & 127;
  }

  int phase_20 = (aux + st.buffer[1]) & 3;
  switch (phase_20)
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

  return (acc + aux) & 255;
}

void fn_R001860_6013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_55_1 = 0;
  int damping_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_55_1 = ((damping_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_55_2 = ((damping_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_55_1) & 127;
    acc_2 = (acc_2 + damping_55_2) & 127;
  }

  int delta_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_83_1) & 63;
  aux_2 = (aux_2 + delta_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_23_1 = local_arr_1[aux_1 % 3];
  int offset_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_55_1 == damping_55_2);
  assert(delta_83_1 == delta_83_2);
  assert(quantum_97_1 == quantum_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_23_1 == offset_23_2);
}

int fn_R001860_6013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001860_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_55 = ((damping_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_55) & 127;
  }

  int delta_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_83) & 63;
  acc ^= aux;
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

  int local_arr[3] = {4, 9, 15};
  int offset_23 = local_arr[aux % 3];
  acc = (acc + (offset_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001860_6013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st_1 = {0};
  struct StreamBuffer_R001860_6013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_35_1) & 63;
  aux_2 = (aux_2 + delta_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_23_1 == offset_23_2);
  assert(delta_35_1 == delta_35_2);
}

int fn_R001860_6013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001860_6013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001860_0_1;
  int sec_r001860_0_2;
  int sec_r001860_1_1;
  int sec_r001860_1_2;
  int sec_r001860_2_1;
  int sec_r001860_2_2;
  int sec_r001860_3_1;
  int sec_r001860_3_2;
  int sec_r001860_4_1;
  int sec_r001860_4_2;
  int sec_r001860_5_1;
  int sec_r001860_5_2;
  int sec_r001860_6_1;
  int sec_r001860_6_2;
  int sec_r001860_7_1;
  int sec_r001860_7_2;
  int sec_r001860_8_1;
  int sec_r001860_8_2;
  int sec_r001860_9_1;
  int sec_r001860_9_2;
  int sec_r001860_10_1;
  int sec_r001860_10_2;
  int sec_r001860_11_1;
  int sec_r001860_11_2;
  int sec_r001860_12_1;
  int sec_r001860_12_2;
  int sec_r001860_13_1;
  int sec_r001860_13_2;
  int sec_r001860_14_1;
  int sec_r001860_14_2;
  int sec_r001860_15_1;
  int sec_r001860_15_2;
  int sec_r001860_16_1;
  int sec_r001860_16_2;
  int sec_r001860_17_1;
  int sec_r001860_17_2;
  int sec_r001860_18_1;
  int sec_r001860_18_2;
  int sec_r001860_19_1;
  int sec_r001860_19_2;
  int pub_r001860_0_1;
  int pub_r001860_0_2;
  int pub_r001860_1_1;
  int pub_r001860_1_2;
  int pub_r001860_2_1;
  int pub_r001860_2_2;
  int pub_r001860_3_1;
  int pub_r001860_3_2;
  int pub_r001860_4_1;
  int pub_r001860_4_2;
  int pub_r001860_5_1;
  int pub_r001860_5_2;
  int pub_r001860_6_1;
  int pub_r001860_6_2;
  int pub_r001860_7_1;
  int pub_r001860_7_2;
  int pub_r001860_8_1;
  int pub_r001860_8_2;
  int pub_r001860_9_1;
  int pub_r001860_9_2;
  int pub_r001860_10_1;
  int pub_r001860_10_2;
  int pub_r001860_11_1;
  int pub_r001860_11_2;
  int pub_r001860_12_1;
  int pub_r001860_12_2;
  int pub_r001860_13_1;
  int pub_r001860_13_2;
  int pub_r001860_14_1;
  int pub_r001860_14_2;
  int pub_r001860_15_1;
  int pub_r001860_15_2;
  int pub_r001860_16_1;
  int pub_r001860_16_2;
  int pub_r001860_17_1;
  int pub_r001860_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001860_0_1 >= (-100)) && (pub_r001860_0_1 <= 100));
  __CPROVER_assume((pub_r001860_0_2 >= (-100)) && (pub_r001860_0_2 <= 100));
  __CPROVER_assume((pub_r001860_1_1 >= (-100)) && (pub_r001860_1_1 <= 100));
  __CPROVER_assume((pub_r001860_1_2 >= (-100)) && (pub_r001860_1_2 <= 100));
  __CPROVER_assume((pub_r001860_2_1 >= (-100)) && (pub_r001860_2_1 <= 100));
  __CPROVER_assume((pub_r001860_2_2 >= (-100)) && (pub_r001860_2_2 <= 100));
  __CPROVER_assume((pub_r001860_3_1 >= (-100)) && (pub_r001860_3_1 <= 100));
  __CPROVER_assume((pub_r001860_3_2 >= (-100)) && (pub_r001860_3_2 <= 100));
  __CPROVER_assume((pub_r001860_4_1 >= (-100)) && (pub_r001860_4_1 <= 100));
  __CPROVER_assume((pub_r001860_4_2 >= (-100)) && (pub_r001860_4_2 <= 100));
  __CPROVER_assume((pub_r001860_5_1 >= (-100)) && (pub_r001860_5_1 <= 100));
  __CPROVER_assume((pub_r001860_5_2 >= (-100)) && (pub_r001860_5_2 <= 100));
  __CPROVER_assume((pub_r001860_6_1 >= (-100)) && (pub_r001860_6_1 <= 100));
  __CPROVER_assume((pub_r001860_6_2 >= (-100)) && (pub_r001860_6_2 <= 100));
  __CPROVER_assume((pub_r001860_7_1 >= (-100)) && (pub_r001860_7_1 <= 100));
  __CPROVER_assume((pub_r001860_7_2 >= (-100)) && (pub_r001860_7_2 <= 100));
  __CPROVER_assume((pub_r001860_8_1 >= (-100)) && (pub_r001860_8_1 <= 100));
  __CPROVER_assume((pub_r001860_8_2 >= (-100)) && (pub_r001860_8_2 <= 100));
  __CPROVER_assume((pub_r001860_9_1 >= (-100)) && (pub_r001860_9_1 <= 100));
  __CPROVER_assume((pub_r001860_9_2 >= (-100)) && (pub_r001860_9_2 <= 100));
  __CPROVER_assume((pub_r001860_10_1 >= (-100)) && (pub_r001860_10_1 <= 100));
  __CPROVER_assume((pub_r001860_10_2 >= (-100)) && (pub_r001860_10_2 <= 100));
  __CPROVER_assume((pub_r001860_11_1 >= (-100)) && (pub_r001860_11_1 <= 100));
  __CPROVER_assume((pub_r001860_11_2 >= (-100)) && (pub_r001860_11_2 <= 100));
  __CPROVER_assume((pub_r001860_12_1 >= (-100)) && (pub_r001860_12_1 <= 100));
  __CPROVER_assume((pub_r001860_12_2 >= (-100)) && (pub_r001860_12_2 <= 100));
  __CPROVER_assume((pub_r001860_13_1 >= (-100)) && (pub_r001860_13_1 <= 100));
  __CPROVER_assume((pub_r001860_13_2 >= (-100)) && (pub_r001860_13_2 <= 100));
  __CPROVER_assume((pub_r001860_14_1 >= (-100)) && (pub_r001860_14_1 <= 100));
  __CPROVER_assume((pub_r001860_14_2 >= (-100)) && (pub_r001860_14_2 <= 100));
  __CPROVER_assume((pub_r001860_15_1 >= (-100)) && (pub_r001860_15_1 <= 100));
  __CPROVER_assume((pub_r001860_15_2 >= (-100)) && (pub_r001860_15_2 <= 100));
  __CPROVER_assume((pub_r001860_16_1 >= (-100)) && (pub_r001860_16_1 <= 100));
  __CPROVER_assume((pub_r001860_16_2 >= (-100)) && (pub_r001860_16_2 <= 100));
  __CPROVER_assume((pub_r001860_17_1 >= (-100)) && (pub_r001860_17_1 <= 100));
  __CPROVER_assume((pub_r001860_17_2 >= (-100)) && (pub_r001860_17_2 <= 100));
  __CPROVER_assume((sec_r001860_0_1 >= 0) && (sec_r001860_0_1 <= 255));
  __CPROVER_assume((sec_r001860_0_2 >= 0) && (sec_r001860_0_2 <= 255));
  __CPROVER_assume((sec_r001860_1_1 >= 0) && (sec_r001860_1_1 <= 255));
  __CPROVER_assume((sec_r001860_1_2 >= 0) && (sec_r001860_1_2 <= 255));
  __CPROVER_assume((sec_r001860_2_1 >= 0) && (sec_r001860_2_1 <= 255));
  __CPROVER_assume((sec_r001860_2_2 >= 0) && (sec_r001860_2_2 <= 255));
  __CPROVER_assume((sec_r001860_3_1 >= 0) && (sec_r001860_3_1 <= 255));
  __CPROVER_assume((sec_r001860_3_2 >= 0) && (sec_r001860_3_2 <= 255));
  __CPROVER_assume((sec_r001860_4_1 >= 0) && (sec_r001860_4_1 <= 255));
  __CPROVER_assume((sec_r001860_4_2 >= 0) && (sec_r001860_4_2 <= 255));
  __CPROVER_assume((sec_r001860_5_1 >= 0) && (sec_r001860_5_1 <= 255));
  __CPROVER_assume((sec_r001860_5_2 >= 0) && (sec_r001860_5_2 <= 255));
  __CPROVER_assume((sec_r001860_6_1 >= 0) && (sec_r001860_6_1 <= 255));
  __CPROVER_assume((sec_r001860_6_2 >= 0) && (sec_r001860_6_2 <= 255));
  __CPROVER_assume((sec_r001860_7_1 >= 0) && (sec_r001860_7_1 <= 255));
  __CPROVER_assume((sec_r001860_7_2 >= 0) && (sec_r001860_7_2 <= 255));
  __CPROVER_assume((sec_r001860_8_1 >= 0) && (sec_r001860_8_1 <= 255));
  __CPROVER_assume((sec_r001860_8_2 >= 0) && (sec_r001860_8_2 <= 255));
  __CPROVER_assume((sec_r001860_9_1 >= 0) && (sec_r001860_9_1 <= 255));
  __CPROVER_assume((sec_r001860_9_2 >= 0) && (sec_r001860_9_2 <= 255));
  __CPROVER_assume((sec_r001860_10_1 >= 0) && (sec_r001860_10_1 <= 255));
  __CPROVER_assume((sec_r001860_10_2 >= 0) && (sec_r001860_10_2 <= 255));
  __CPROVER_assume((sec_r001860_11_1 >= 0) && (sec_r001860_11_1 <= 255));
  __CPROVER_assume((sec_r001860_11_2 >= 0) && (sec_r001860_11_2 <= 255));
  __CPROVER_assume((sec_r001860_12_1 >= 0) && (sec_r001860_12_1 <= 255));
  __CPROVER_assume((sec_r001860_12_2 >= 0) && (sec_r001860_12_2 <= 255));
  __CPROVER_assume((sec_r001860_13_1 >= 0) && (sec_r001860_13_1 <= 255));
  __CPROVER_assume((sec_r001860_13_2 >= 0) && (sec_r001860_13_2 <= 255));
  __CPROVER_assume((sec_r001860_14_1 >= 0) && (sec_r001860_14_1 <= 255));
  __CPROVER_assume((sec_r001860_14_2 >= 0) && (sec_r001860_14_2 <= 255));
  __CPROVER_assume((sec_r001860_15_1 >= 0) && (sec_r001860_15_1 <= 255));
  __CPROVER_assume((sec_r001860_15_2 >= 0) && (sec_r001860_15_2 <= 255));
  __CPROVER_assume((sec_r001860_16_1 >= 0) && (sec_r001860_16_1 <= 255));
  __CPROVER_assume((sec_r001860_16_2 >= 0) && (sec_r001860_16_2 <= 255));
  __CPROVER_assume((sec_r001860_17_1 >= 0) && (sec_r001860_17_1 <= 255));
  __CPROVER_assume((sec_r001860_17_2 >= 0) && (sec_r001860_17_2 <= 255));
  __CPROVER_assume((sec_r001860_18_1 >= 0) && (sec_r001860_18_1 <= 255));
  __CPROVER_assume((sec_r001860_18_2 >= 0) && (sec_r001860_18_2 <= 255));
  __CPROVER_assume((sec_r001860_19_1 >= 0) && (sec_r001860_19_1 <= 255));
  __CPROVER_assume((sec_r001860_19_2 >= 0) && (sec_r001860_19_2 <= 255));
  struct FilterState_R001860_6013_0 st_var_0_1 = {0};
  struct FilterState_R001860_6013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001860_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001860_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001860_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001860_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001860_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001860_0_2 + 7) & 15;
  struct DeviceConfig_R001860_6013_1 st_var_1_1 = {0};
  struct DeviceConfig_R001860_6013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001860_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001860_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001860_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001860_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001860_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001860_0_2 + 9) & 15;
  struct MatrixBlock_R001860_6013_2 st_var_2_1 = {0};
  struct MatrixBlock_R001860_6013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001860_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001860_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001860_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001860_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001860_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001860_0_2 + 11) & 15;
  struct StreamBuffer_R001860_6013_3 st_var_3_1 = {0};
  struct StreamBuffer_R001860_6013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001860_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001860_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001860_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001860_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001860_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001860_0_2 + 13) & 15;
  union PacketPayload_R001860_6013_0 u_var_1;
  union PacketPayload_R001860_6013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001860_6013_0(sec_r001860_0_1, pub_r001860_1_1);
  int helper_flow_0_2 = fn_R001860_6013_0(sec_r001860_0_2, pub_r001860_1_2);
  fn_R001860_6013_0_2(sec_r001860_0_1, pub_r001860_1_1, sec_r001860_0_2, pub_r001860_1_2);
  int helper_flow_1_1 = fn_R001860_6013_1(sec_r001860_1_1, pub_r001860_2_1, pub_r001860_3_1);
  int helper_flow_1_2 = fn_R001860_6013_1(sec_r001860_1_2, pub_r001860_2_2, pub_r001860_3_2);
  fn_R001860_6013_1_2(sec_r001860_1_1, pub_r001860_2_1, pub_r001860_3_1, sec_r001860_1_2, pub_r001860_2_2, pub_r001860_3_2);
  int helper_flow_2_1 = fn_R001860_6013_2(sec_r001860_2_1, pub_r001860_3_1, pub_r001860_4_1, pub_r001860_5_1);
  int helper_flow_2_2 = fn_R001860_6013_2(sec_r001860_2_2, pub_r001860_3_2, pub_r001860_4_2, pub_r001860_5_2);
  fn_R001860_6013_2_2(sec_r001860_2_1, pub_r001860_3_1, pub_r001860_4_1, pub_r001860_5_1, sec_r001860_2_2, pub_r001860_3_2, pub_r001860_4_2, pub_r001860_5_2);
  int helper_flow_3_1 = fn_R001860_6013_3(sec_r001860_3_1, sec_r001860_4_1, pub_r001860_5_1);
  int helper_flow_3_2 = fn_R001860_6013_3(sec_r001860_3_2, sec_r001860_4_2, pub_r001860_5_2);
  fn_R001860_6013_3_2(sec_r001860_3_1, sec_r001860_4_1, pub_r001860_5_1, sec_r001860_3_2, sec_r001860_4_2, pub_r001860_5_2);
  int helper_flow_4_1 = fn_R001860_6013_4(sec_r001860_4_1, sec_r001860_5_1, pub_r001860_6_1);
  int helper_flow_4_2 = fn_R001860_6013_4(sec_r001860_4_2, sec_r001860_5_2, pub_r001860_6_2);
  fn_R001860_6013_4_2(sec_r001860_4_1, sec_r001860_5_1, pub_r001860_6_1, sec_r001860_4_2, sec_r001860_5_2, pub_r001860_6_2);
  int helper_flow_5_1 = fn_R001860_6013_5(sec_r001860_5_1, pub_r001860_6_1, pub_r001860_7_1, pub_r001860_8_1);
  int helper_flow_5_2 = fn_R001860_6013_5(sec_r001860_5_2, pub_r001860_6_2, pub_r001860_7_2, pub_r001860_8_2);
  fn_R001860_6013_5_2(sec_r001860_5_1, pub_r001860_6_1, pub_r001860_7_1, pub_r001860_8_1, sec_r001860_5_2, pub_r001860_6_2, pub_r001860_7_2, pub_r001860_8_2);
  int helper_flow_6_1 = fn_R001860_6013_6(sec_r001860_6_1, pub_r001860_7_1, pub_r001860_8_1);
  int helper_flow_6_2 = fn_R001860_6013_6(sec_r001860_6_2, pub_r001860_7_2, pub_r001860_8_2);
  fn_R001860_6013_6_2(sec_r001860_6_1, pub_r001860_7_1, pub_r001860_8_1, sec_r001860_6_2, pub_r001860_7_2, pub_r001860_8_2);
  int helper_flow_7_1 = fn_R001860_6013_7(sec_r001860_7_1, pub_r001860_8_1, pub_r001860_9_1);
  int helper_flow_7_2 = fn_R001860_6013_7(sec_r001860_7_2, pub_r001860_8_2, pub_r001860_9_2);
  fn_R001860_6013_7_2(sec_r001860_7_1, pub_r001860_8_1, pub_r001860_9_1, sec_r001860_7_2, pub_r001860_8_2, pub_r001860_9_2);
  int helper_flow_8_1 = fn_R001860_6013_8(sec_r001860_8_1, pub_r001860_9_1);
  int helper_flow_8_2 = fn_R001860_6013_8(sec_r001860_8_2, pub_r001860_9_2);
  fn_R001860_6013_8_2(sec_r001860_8_1, pub_r001860_9_1, sec_r001860_8_2, pub_r001860_9_2);
  int stage_v_0_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_0_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_0_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_1_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_1_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((pub_r001860_6_1 * 2) + 27) & 63;
  int stage_v_2_2 = ((pub_r001860_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_3_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_3_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((pub_r001860_16_1 * 2) + 30) & 63;
  int stage_v_4_2 = ((pub_r001860_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_5_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_5_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001860_1_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_6_2 = (((sec_r001860_1_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_6_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001860_11_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_7_2 = (((sec_r001860_11_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_7_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((pub_r001860_6_1 * 2) + 39) & 63;
  int stage_v_8_2 = ((pub_r001860_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001860_3_1 * 2) + 39) & 63;
  int stage_v_9_2 = ((pub_r001860_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001860_13_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_10_2 = (((sec_r001860_13_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_10_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_11_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_11_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001860_9_1 * 2) + 9) & 63;
  int stage_v_12_2 = ((pub_r001860_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001860_8_1 * 2) + 27) & 63;
  int stage_v_13_2 = ((pub_r001860_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001860_19_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_14_2 = (((sec_r001860_19_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_14_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001860_6_1 * 2) + 8) & 63;
  int stage_v_15_2 = ((pub_r001860_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_16_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_16_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((pub_r001860_17_1 * 2) + 33) & 63;
  int stage_v_17_2 = ((pub_r001860_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((sec_r001860_19_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_18_2 = (((sec_r001860_19_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_18_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001860_10_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_19_2 = (((sec_r001860_10_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_19_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_20_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_20_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_21_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_21_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001860_13_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_22_2 = (((sec_r001860_13_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_22_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_23_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_23_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_24_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_24_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_25_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_25_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_26_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_26_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_27_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_27_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_28_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_28_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001860_18_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_29_2 = (((sec_r001860_18_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_29_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_30_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_30_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((pub_r001860_3_1 * 2) + 47) & 63;
  int stage_v_31_2 = ((pub_r001860_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001860_2_1 * 2) + 5) & 63;
  int stage_v_32_2 = ((pub_r001860_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_33_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_33_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_34_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((sec_r001860_4_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_35_2 = (((sec_r001860_4_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
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
  int stage_v_36_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_36_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_36_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_37_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_37_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_38_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_38_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001860_8_1 * 2) + 41) & 63;
  int stage_v_39_2 = ((pub_r001860_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001860_4_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_40_2 = (((sec_r001860_4_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_40_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001860_10_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_41_2 = (((sec_r001860_10_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_41_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001860_12_1 * 2) + 37) & 63;
  int stage_v_42_2 = ((pub_r001860_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001860_12_1 * 2) + 17) & 63;
  int stage_v_43_2 = ((pub_r001860_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001860_14_1 * 2) + 11) & 63;
  int stage_v_44_2 = ((pub_r001860_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_45_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_45_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_46_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_46_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_47_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_47_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_48_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_48_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_49_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_49_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_50_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_50_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((pub_r001860_10_1 * 2) + 25) & 63;
  int stage_v_51_2 = ((pub_r001860_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001860_4_1) & 127;
  int stage_v_52_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001860_4_2) & 127;
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
  int stage_v_53_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_53_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_53_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_54_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_54_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_55_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_55_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001860_11_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_56_2 = (((sec_r001860_11_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_56_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_57_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_57_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001860_17_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_58_2 = (((sec_r001860_17_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_58_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_59_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_59_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_60_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_60_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((pub_r001860_4_1 * 2) + 43) & 63;
  int stage_v_61_2 = ((pub_r001860_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_62_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_62_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_63_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_63_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_64_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_64_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_65_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_65_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001860_1_1 * 2) + 25) & 63;
  int stage_v_66_2 = ((pub_r001860_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001860_7_1 * 2) + 41) & 63;
  int stage_v_67_2 = ((pub_r001860_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001860_6_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_68_2 = (((sec_r001860_6_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_68_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_69_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_69_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_70_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_70_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001860_1_1 * 2) + 33) & 63;
  int stage_v_71_2 = ((pub_r001860_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001860_14_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_72_2 = (((sec_r001860_14_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_72_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_73_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_73_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001860_9_1 * 2) + 23) & 63;
  int stage_v_74_2 = ((pub_r001860_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_75_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_75_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((pub_r001860_4_1 * 2) + 46) & 63;
  int stage_v_76_2 = ((pub_r001860_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001860_7_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_77_2 = (((sec_r001860_7_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_77_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_78_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_78_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001860_5_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_79_2 = (((sec_r001860_5_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_79_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_80_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_80_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_81_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_81_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((sec_r001860_0_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_82_2 = (((sec_r001860_0_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_82_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001860_2_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_83_2 = (((sec_r001860_2_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_83_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((pub_r001860_16_1 * 2) + 32) & 63;
  int stage_v_84_2 = ((pub_r001860_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_85_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_85_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_86_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_86_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_87_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_87_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_88_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_88_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_89_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_89_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((sec_r001860_16_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_90_2 = (((sec_r001860_16_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_90_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_91_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_91_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((pub_r001860_3_1 * 2) + 23) & 63;
  int stage_v_92_2 = ((pub_r001860_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_93_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_93_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_94_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_94_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_95_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_95_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_96_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_96_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_97_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_97_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_98_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_98_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001860_4_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_99_2 = (((sec_r001860_4_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_99_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_100_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_100_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_101_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_101_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_102_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_102_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_103_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_103_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_104_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_104_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_105_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_105_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((pub_r001860_17_1 * 2) + 47) & 63;
  int stage_v_106_2 = ((pub_r001860_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_107_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_107_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_108_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_108_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_109_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_109_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_110_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_110_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_111_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_111_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((sec_r001860_12_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_112_2 = (((sec_r001860_12_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_112_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_113_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_113_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_114_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_114_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_115_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_115_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_116_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_116_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((sec_r001860_2_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_117_2 = (((sec_r001860_2_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_117_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_118_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_118_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_119_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_119_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001860_4_1) & 127;
  int stage_v_120_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001860_4_2) & 127;
  if (stage_v_120_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001860_3_1 * 2) + 48) & 63;
  int stage_v_121_2 = ((pub_r001860_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_122_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_122_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((pub_r001860_14_1 * 2) + 32) & 63;
  int stage_v_123_2 = ((pub_r001860_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_124_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_124_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_125_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_125_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001860_5_1 * 2) + 26) & 63;
  int stage_v_126_2 = ((pub_r001860_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_127_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_127_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((sec_r001860_6_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_128_2 = (((sec_r001860_6_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_128_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_129_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_129_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_130_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_130_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001860_1_1 * 2) + 30) & 63;
  int stage_v_131_2 = ((pub_r001860_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001860_15_1 * 2) + 49) & 63;
  int stage_v_132_2 = ((pub_r001860_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_133_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_133_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_134_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_134_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001860_17_1 * 2) + 8) & 63;
  int stage_v_135_2 = ((pub_r001860_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_136_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_136_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((sec_r001860_14_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_137_2 = (((sec_r001860_14_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_137_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_138_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_138_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_139_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_139_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_140_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_140_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_141_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_141_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_142_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_142_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_143_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_143_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_144_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_144_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001860_13_1 * 2) + 21) & 63;
  int stage_v_145_2 = ((pub_r001860_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_146_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_146_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_147_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_147_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((pub_r001860_11_1 * 2) + 12) & 63;
  int stage_v_148_2 = ((pub_r001860_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_149_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_149_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001860_13_1) & 127;
  int stage_v_150_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001860_13_2) & 127;
  if (stage_v_150_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001860_7_1 * 2) + 45) & 63;
  int stage_v_151_2 = ((pub_r001860_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_152_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_152_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_153_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_153_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_154_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_154_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_155_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_155_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((pub_r001860_0_1 * 2) + 46) & 63;
  int stage_v_156_2 = ((pub_r001860_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001860_2_1 * 2) + 5) & 63;
  int stage_v_157_2 = ((pub_r001860_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_158_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_158_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((pub_r001860_12_1 * 2) + 43) & 63;
  int stage_v_159_2 = ((pub_r001860_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_160_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_160_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((sec_r001860_14_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_161_2 = (((sec_r001860_14_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_161_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_162_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_162_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_163_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_163_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_164_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_164_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_165_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_165_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_166_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_166_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_167_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_167_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001860_10_1 * 2) + 29) & 63;
  int stage_v_168_2 = ((pub_r001860_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_169_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_169_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001860_3_1) & 127;
  int stage_v_170_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001860_3_2) & 127;
  if (stage_v_170_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_171_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_171_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001860_5_1 * 2) + 46) & 63;
  int stage_v_172_2 = ((pub_r001860_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001860_10_1 * 2) + 31) & 63;
  int stage_v_173_2 = ((pub_r001860_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_174_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_174_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001860_0_1 * 2) + 46) & 63;
  int stage_v_175_2 = ((pub_r001860_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_176_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_176_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_177_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_177_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_178_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_178_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_179_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_179_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_180_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_180_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_181_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_181_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001860_10_1 * 2) + 23) & 63;
  int stage_v_182_2 = ((pub_r001860_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_183_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_183_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_184_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_184_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001860_4_1 * 2) + 45) & 63;
  int stage_v_185_2 = ((pub_r001860_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_186_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_186_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001860_10_1 * 2) + 38) & 63;
  int stage_v_187_2 = ((pub_r001860_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_188_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_188_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((sec_r001860_18_1 ^ 0x2A) * 2) + pub_r001860_2_1) & 127;
  int stage_v_189_2 = (((sec_r001860_18_2 ^ 0x2A) * 2) + pub_r001860_2_2) & 127;
  if (stage_v_189_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((pub_r001860_11_1 * 2) + 30) & 63;
  int stage_v_190_2 = ((pub_r001860_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((sec_r001860_8_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_191_2 = (((sec_r001860_8_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
  if (stage_v_191_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((pub_r001860_7_1 * 2) + 30) & 63;
  int stage_v_192_2 = ((pub_r001860_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_193_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_193_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_194_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_194_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001860_1_1 * 2) + 13) & 63;
  int stage_v_195_2 = ((pub_r001860_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001860_6_1 * 2) + 40) & 63;
  int stage_v_196_2 = ((pub_r001860_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_197_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_197_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001860_8_1 * 2) + 20) & 63;
  int stage_v_198_2 = ((pub_r001860_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_199_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_199_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001860_9_1 * 2) + 35) & 63;
  int stage_v_200_2 = ((pub_r001860_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((sec_r001860_13_1 ^ 0x2A) * 2) + pub_r001860_10_1) & 127;
  int stage_v_201_2 = (((sec_r001860_13_2 ^ 0x2A) * 2) + pub_r001860_10_2) & 127;
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
  int stage_v_202_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001860_8_1) & 127;
  int stage_v_202_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001860_8_2) & 127;
  if (stage_v_202_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_203_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_203_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001860_0_1) & 127;
  int stage_v_204_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001860_0_2) & 127;
  if (stage_v_204_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_205_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_205_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((pub_r001860_16_1 * 2) + 42) & 63;
  int stage_v_206_2 = ((pub_r001860_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_207_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_207_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_204_1 ^ 0x2A) * 2) + pub_r001860_7_1) & 127;
  int stage_v_208_2 = (((stage_v_204_2 ^ 0x2A) * 2) + pub_r001860_7_2) & 127;
  if (stage_v_208_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_209_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_209_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001860_17_1 * 2) + 49) & 63;
  int stage_v_210_2 = ((pub_r001860_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_211_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_211_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001860_4_1) & 127;
  int stage_v_212_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001860_4_2) & 127;
  if (stage_v_212_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((pub_r001860_9_1 * 2) + 28) & 63;
  int stage_v_213_2 = ((pub_r001860_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001860_10_1 * 2) + 20) & 63;
  int stage_v_214_2 = ((pub_r001860_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001860_13_1 * 2) + 32) & 63;
  int stage_v_215_2 = ((pub_r001860_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001860_11_1) & 127;
  int stage_v_216_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001860_11_2) & 127;
  if (stage_v_216_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_217_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
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
  int stage_v_218_1 = ((pub_r001860_10_1 * 2) + 17) & 63;
  int stage_v_218_2 = ((pub_r001860_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001860_17_1) & 127;
  int stage_v_219_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001860_17_2) & 127;
  if (stage_v_219_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001860_15_1) & 127;
  int stage_v_220_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001860_15_2) & 127;
  if (stage_v_220_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_174_1 ^ 0x2A) * 2) + pub_r001860_5_1) & 127;
  int stage_v_221_2 = (((stage_v_174_2 ^ 0x2A) * 2) + pub_r001860_5_2) & 127;
  if (stage_v_221_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_197_1 ^ 0x2A) * 2) + pub_r001860_4_1) & 127;
  int stage_v_222_2 = (((stage_v_197_2 ^ 0x2A) * 2) + pub_r001860_4_2) & 127;
  if (stage_v_222_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001860_14_1) & 127;
  int stage_v_223_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001860_14_2) & 127;
  if (stage_v_223_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001860_12_1) & 127;
  int stage_v_224_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001860_12_2) & 127;
  if (stage_v_224_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((pub_r001860_7_1 * 2) + 15) & 63;
  int stage_v_225_2 = ((pub_r001860_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001860_6_1) & 127;
  int stage_v_226_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001860_6_2) & 127;
  if (stage_v_226_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001860_16_1) & 127;
  int stage_v_227_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001860_16_2) & 127;
  if (stage_v_227_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((sec_r001860_13_1 ^ 0x2A) * 2) + pub_r001860_1_1) & 127;
  int stage_v_228_2 = (((sec_r001860_13_2 ^ 0x2A) * 2) + pub_r001860_1_2) & 127;
  if (stage_v_228_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001860_9_1) & 127;
  int stage_v_229_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001860_9_2) & 127;
  if (stage_v_229_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001860_0_1 != sec_r001860_0_2);
  __CPROVER_assume(sec_r001860_3_1 != sec_r001860_3_2);
  __CPROVER_assume(sec_r001860_11_1 != sec_r001860_11_2);
  __CPROVER_assume(pub_r001860_11_1 == pub_r001860_11_2);
  __CPROVER_assume(sec_r001860_9_1 != sec_r001860_9_2);
  __CPROVER_assume(sec_r001860_4_1 != sec_r001860_4_2);
  __CPROVER_assume(pub_r001860_12_1 == pub_r001860_12_2);
  __CPROVER_assume(sec_r001860_7_1 != sec_r001860_7_2);
  __CPROVER_assume(sec_r001860_8_1 != sec_r001860_8_2);
  __CPROVER_assume(pub_r001860_14_1 == pub_r001860_14_2);
  __CPROVER_assume(pub_r001860_0_1 == pub_r001860_0_2);
  __CPROVER_assume(sec_r001860_16_1 != sec_r001860_16_2);
  __CPROVER_assume(pub_r001860_17_1 == pub_r001860_17_2);
  __CPROVER_assume(pub_r001860_7_1 == pub_r001860_7_2);
  __CPROVER_assume(pub_r001860_15_1 == pub_r001860_15_2);
  __CPROVER_assume(pub_r001860_6_1 == pub_r001860_6_2);
  __CPROVER_assume(sec_r001860_5_1 != sec_r001860_5_2);
  __CPROVER_assume(sec_r001860_14_1 != sec_r001860_14_2);
  __CPROVER_assume(pub_r001860_2_1 == pub_r001860_2_2);
  __CPROVER_assume(pub_r001860_16_1 == pub_r001860_16_2);
  __CPROVER_assume(sec_r001860_18_1 != sec_r001860_18_2);
  __CPROVER_assume(sec_r001860_12_1 != sec_r001860_12_2);
  __CPROVER_assume(sec_r001860_19_1 != sec_r001860_19_2);
  __CPROVER_assume(pub_r001860_3_1 == pub_r001860_3_2);
  __CPROVER_assume(pub_r001860_4_1 == pub_r001860_4_2);
  __CPROVER_assume(pub_r001860_10_1 == pub_r001860_10_2);
  __CPROVER_assume(sec_r001860_1_1 != sec_r001860_1_2);
  __CPROVER_assume(sec_r001860_10_1 != sec_r001860_10_2);
  __CPROVER_assume(sec_r001860_13_1 != sec_r001860_13_2);
  __CPROVER_assume(sec_r001860_2_1 != sec_r001860_2_2);
  __CPROVER_assume(pub_r001860_5_1 == pub_r001860_5_2);
  __CPROVER_assume(sec_r001860_6_1 != sec_r001860_6_2);
  __CPROVER_assume(pub_r001860_8_1 == pub_r001860_8_2);
  __CPROVER_assume(pub_r001860_9_1 == pub_r001860_9_2);
  __CPROVER_assume(pub_r001860_13_1 == pub_r001860_13_2);
  __CPROVER_assume(pub_r001860_1_1 == pub_r001860_1_2);
  __CPROVER_assume(sec_r001860_17_1 != sec_r001860_17_2);
  __CPROVER_assume(sec_r001860_15_1 != sec_r001860_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.checksum == st_var_3_2.checksum);
  assert(st_var_3_1.head == st_var_3_2.head);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.capacity == st_var_3_2.capacity);
  assert(st_var_3_1.tail == st_var_3_2.tail);
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
}


