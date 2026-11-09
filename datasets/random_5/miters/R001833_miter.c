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
struct CipherContext_R001833_3313_0
{
  int tag;
  int flags;
  unsigned char iv;
  short round_key;
  int buffer[3];
};
struct StreamBuffer_R001833_3313_1
{
  int capacity;
  int watermark;
  int head;
  short checksum;
  int tail;
  int state;
  int buffer[3];
};
struct FilterState_R001833_3313_2
{
  int mode;
  short gain_db;
  int damping;
  short prev_in;
  int buffer[3];
};
struct DeviceConfig_R001833_3313_3
{
  unsigned char stop_bits;
  int baud_rate;
  int port;
  int parity;
  int buffer[3];
};
union TelemetryField_R001833_3313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001833_3313_1
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
void fn_R001833_3313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_81_1 = 0;
  int offset_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_81_1 = ((offset_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_81_2 = ((offset_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_81_1) & 127;
    acc_2 = (acc_2 + offset_81_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_94_1 = local_arr_1[aux_1 % 3];
  int quotient_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_94_2 * 2)) & 127;
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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

  int parity_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_74_1) & 63;
  aux_2 = (aux_2 + parity_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_81_1 == offset_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_94_1 == quotient_94_2);
  assert(mask_92_1 == mask_92_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R001833_3313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_81 = ((offset_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_81) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_94 = local_arr[aux % 3];
  acc = (acc + (quotient_94 * 2)) & 127;
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

  int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001833_3313_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_81_1)
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

  switch (anchor_81_2)
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

  int vector_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_41_1 > 43)
  {
    acc_1 = ((acc_1 + (vector_41_1 * 2)) + 5) & 127;
    aux_1 ^= vector_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_41_2 > 43)
  {
    acc_2 = ((acc_2 + (vector_41_2 * 2)) + 5) & 127;
    aux_2 ^= vector_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_14_1 = 0;
  int metric_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_14_1 = ((metric_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_14_2 = ((metric_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_14_1) & 127;
    acc_2 = (acc_2 + metric_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_81_1 == anchor_81_2);
  assert(vector_41_1 == vector_41_2);
  assert(metric_14_1 == metric_14_2);
}

int fn_R001833_3313_1(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_81 = (aux + st.buffer[1]) & 3;
  switch (anchor_81)
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

  int vector_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_41 > 43)
  {
    acc = ((acc + (vector_41 * 2)) + 5) & 127;
    aux ^= vector_41 & 15;
  }
  else
  {
    acc = ((acc - vector_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_14 = ((metric_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001833_3313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_44_1 = local_arr_1[aux_1 % 3];
  int cursor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_44_2 * 2)) & 127;
  int residue_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_97_1) & 63;
  aux_2 = (aux_2 + residue_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_26_1 = 0;
  int cursor_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_26_1 = ((cursor_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_26_2 = ((cursor_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_26_1) & 127;
    acc_2 = (acc_2 + cursor_26_2) & 127;
  }

  int tally_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_75_1)
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

  switch (tally_75_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_44_1 == cursor_44_2);
  assert(residue_97_1 == residue_97_2);
  assert(cursor_26_1 == cursor_26_2);
  assert(tally_75_1 == tally_75_2);
}

int fn_R001833_3313_2(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int cursor_44 = local_arr[aux % 3];
  acc = (acc + (cursor_44 * 2)) & 127;
  int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_97) & 63;
  acc ^= aux;
  int cursor_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_26 = ((cursor_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_26) & 127;
  }

  int tally_75 = (aux + st.buffer[1]) & 3;
  switch (tally_75)
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

void fn_R001833_3313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_95_1) & 63;
  aux_2 = (aux_2 + damping_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_56_1 = 0;
  int segment_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_56_1 = ((segment_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_56_2 = ((segment_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_56_1) & 127;
    acc_2 = (acc_2 + segment_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_95_1 == damping_95_2);
  assert(segment_56_1 == segment_56_2);
}

int fn_R001833_3313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_95) & 63;
  acc ^= aux;
  int segment_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_56 = ((segment_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001833_3313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int stride_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_36_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_36_1 * 2)) + 5) & 127;
    aux_1 ^= stride_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_36_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_36_2 * 2)) + 5) & 127;
    aux_2 ^= stride_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_92_1 = local_arr_1[aux_1 % 3];
  int damping_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_36_1 == stride_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_92_1 == damping_92_2);
}

int fn_R001833_3313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int stride_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_36 > 13)
  {
    acc = ((acc + (stride_36 * 2)) + 5) & 127;
    aux ^= stride_36 & 15;
  }
  else
  {
    acc = ((acc - stride_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_92 = local_arr[aux % 3];
  acc = (acc + (damping_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_73_1 = local_arr_1[aux_1 % 3];
  int quantum_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_73_2 * 2)) & 127;
  int residue_39_1 = 0;
  int residue_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_39_1 = ((residue_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_39_2 = ((residue_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_39_1) & 127;
    acc_2 = (acc_2 + residue_39_2) & 127;
  }

  int residue_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_19_1)
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

  switch (residue_19_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_73_1 == quantum_73_2);
  assert(residue_39_1 == residue_39_2);
  assert(residue_19_1 == residue_19_2);
}

int fn_R001833_3313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int quantum_73 = local_arr[aux % 3];
  acc = (acc + (quantum_73 * 2)) & 127;
  int residue_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_39 = ((residue_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_39) & 127;
  }

  int residue_19 = (aux + st.buffer[1]) & 3;
  switch (residue_19)
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

void fn_R001833_3313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_52_1 = local_arr_1[aux_1 % 3];
  int phase_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_52_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_52_1 == phase_52_2);
}

int fn_R001833_3313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int phase_52 = local_arr[aux % 3];
  acc = (acc + (phase_52 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st_1 = {0};
  struct DeviceConfig_R001833_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_32_1 = local_arr_1[aux_1 % 3];
  int quotient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_32_2 * 2)) & 127;
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_55_1) & 63;
  aux_2 = (aux_2 + stride_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_32_1 == quotient_32_2);
  assert(mask_76_1 == mask_76_2);
  assert(stride_55_1 == stride_55_2);
}

int fn_R001833_3313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int quotient_32 = local_arr[aux % 3];
  acc = (acc + (quotient_32 * 2)) & 127;
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001833_3313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int coefficient_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_52_1)
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

  switch (coefficient_52_2)
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

  int metric_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_47_1 > 18)
  {
    acc_1 = ((acc_1 + (metric_47_1 * 2)) + 5) & 127;
    aux_1 ^= metric_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_47_2 > 18)
  {
    acc_2 = ((acc_2 + (metric_47_2 * 2)) + 5) & 127;
    aux_2 ^= metric_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_52_1 == coefficient_52_2);
  assert(metric_47_1 == metric_47_2);
}

int fn_R001833_3313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int coefficient_52 = (aux + st.buffer[1]) & 3;
  switch (coefficient_52)
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

  int metric_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_47 > 18)
  {
    acc = ((acc + (metric_47 * 2)) + 5) & 127;
    aux ^= metric_47 & 15;
  }
  else
  {
    acc = ((acc - metric_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001833_3313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 39)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 39)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_28_1) & 63;
  aux_2 = (aux_2 + index_reg_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_31_1 == stride_31_2);
  assert(index_reg_28_1 == index_reg_28_2);
}

int fn_R001833_3313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 39)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  int index_reg_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001833_3313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_67_1 > 45)
  {
    acc_1 = ((acc_1 + (accumulator_67_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_67_2 > 45)
  {
    acc_2 = ((acc_2 + (accumulator_67_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_45_1 = local_arr_1[aux_1 % 3];
  int parity_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_45_2 * 2)) & 127;
  int vector_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_10_1)
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

  switch (vector_10_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_67_1 == accumulator_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_45_1 == parity_45_2);
  assert(vector_10_1 == vector_10_2);
}

int fn_R001833_3313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_67 > 45)
  {
    acc = ((acc + (accumulator_67 * 2)) + 5) & 127;
    aux ^= accumulator_67 & 15;
  }
  else
  {
    acc = ((acc - accumulator_67) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_45 = local_arr[aux % 3];
  acc = (acc + (parity_45 * 2)) & 127;
  int vector_10 = (aux + st.buffer[1]) & 3;
  switch (vector_10)
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

void fn_R001833_3313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_61_1 = 0;
  int residue_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_61_1 = ((residue_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_61_2 = ((residue_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_61_1) & 127;
    acc_2 = (acc_2 + residue_61_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_61_1 == residue_61_2);
}

int fn_R001833_3313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_61 = ((residue_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_61) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st_1 = {0};
  struct DeviceConfig_R001833_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_41_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_41_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_41_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_41_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_53_1) & 63;
  aux_2 = (aux_2 + mask_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_24_1 = local_arr_1[aux_1 % 3];
  int tracker_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_24_2 * 2)) & 127;
  int coefficient_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_82_1)
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

  switch (coefficient_82_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_41_1 == threshold_41_2);
  assert(mask_53_1 == mask_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_24_1 == tracker_24_2);
  assert(coefficient_82_1 == coefficient_82_2);
}

int fn_R001833_3313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_41 > 31)
  {
    acc = ((acc + (threshold_41 * 2)) + 5) & 127;
    aux ^= threshold_41 & 15;
  }
  else
  {
    acc = ((acc - threshold_41) + 11) & 127;
    aux += 3;
  }
  int mask_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_53) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_24 = local_arr[aux % 3];
  acc = (acc + (tracker_24 * 2)) & 127;
  int coefficient_82 = (aux + st.buffer[1]) & 3;
  switch (coefficient_82)
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

void fn_R001833_3313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_45_1)
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

  switch (stride_45_2)
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

  int tally_64_1 = 0;
  int tally_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_64_1 = ((tally_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_64_2 = ((tally_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_64_1) & 127;
    acc_2 = (acc_2 + tally_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_45_1 == stride_45_2);
  assert(tally_64_1 == tally_64_2);
}

int fn_R001833_3313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_45 = (aux + st.buffer[1]) & 3;
  switch (stride_45)
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

  int tally_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_64 = ((tally_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001833_3313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int phase_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_14_1)
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

  switch (phase_14_2)
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
  int threshold_29_1 = local_arr_1[aux_1 % 3];
  int threshold_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_14_1 == phase_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_29_1 == threshold_29_2);
}

int fn_R001833_3313_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int phase_14 = (aux + st.buffer[1]) & 3;
  switch (phase_14)
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
  int threshold_29 = local_arr[aux % 3];
  acc = (acc + (threshold_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st_1 = {0};
  struct DeviceConfig_R001833_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_58_1) & 63;
  aux_2 = (aux_2 + vector_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_45_1 > 16)
  {
    acc_1 = ((acc_1 + (checksum_45_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_45_2 > 16)
  {
    acc_2 = ((acc_2 + (checksum_45_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_37_1 = local_arr_1[aux_1 % 3];
  int accumulator_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_58_1 == vector_58_2);
  assert(checksum_45_1 == checksum_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_37_1 == accumulator_37_2);
}

int fn_R001833_3313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_58) & 63;
  acc ^= aux;
  int checksum_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_45 > 16)
  {
    acc = ((acc + (checksum_45 * 2)) + 5) & 127;
    aux ^= checksum_45 & 15;
  }
  else
  {
    acc = ((acc - checksum_45) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_37 = local_arr[aux % 3];
  acc = (acc + (accumulator_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quotient_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_15_1) & 63;
  aux_2 = (aux_2 + quotient_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_29_1 = 0;
  int factor_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_29_1 = ((factor_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_29_2 = ((factor_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_29_1) & 127;
    acc_2 = (acc_2 + factor_29_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_18_1)
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

  switch (factor_18_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_15_1 == quotient_15_2);
  assert(factor_29_1 == factor_29_2);
  assert(factor_18_1 == factor_18_2);
}

int fn_R001833_3313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_15) & 63;
  acc ^= aux;
  int factor_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_29 = ((factor_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_29) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_18 = (aux + st.buffer[1]) & 3;
  switch (factor_18)
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

void fn_R001833_3313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st_1 = {0};
  struct FilterState_R001833_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_24_1 = local_arr_1[aux_1 % 3];
  int phase_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_24_2 * 2)) & 127;
  int anchor_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_98_1) & 63;
  aux_2 = (aux_2 + anchor_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_43_1)
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

  switch (margin_43_2)
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

  int margin_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_70_1 > 44)
  {
    acc_1 = ((acc_1 + (margin_70_1 * 2)) + 5) & 127;
    aux_1 ^= margin_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_70_2 > 44)
  {
    acc_2 = ((acc_2 + (margin_70_2 * 2)) + 5) & 127;
    aux_2 ^= margin_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_24_1 == phase_24_2);
  assert(anchor_98_1 == anchor_98_2);
  assert(margin_43_1 == margin_43_2);
  assert(margin_70_1 == margin_70_2);
}

int fn_R001833_3313_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001833_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int phase_24 = local_arr[aux % 3];
  acc = (acc + (phase_24 * 2)) & 127;
  int anchor_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_98) & 63;
  acc ^= aux;
  int margin_43 = (aux + st.buffer[1]) & 3;
  switch (margin_43)
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

  int margin_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_70 > 44)
  {
    acc = ((acc + (margin_70 * 2)) + 5) & 127;
    aux ^= margin_70 & 15;
  }
  else
  {
    acc = ((acc - margin_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001833_3313_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_97_1 = local_arr_1[aux_1 % 3];
  int accumulator_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_97_2 * 2)) & 127;
  int metric_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_28_1) & 63;
  aux_2 = (aux_2 + metric_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_68_1 > 48)
  {
    acc_1 = ((acc_1 + (tracker_68_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_68_2 > 48)
  {
    acc_2 = ((acc_2 + (tracker_68_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_97_1 == accumulator_97_2);
  assert(metric_28_1 == metric_28_2);
  assert(tracker_68_1 == tracker_68_2);
}

int fn_R001833_3313_18(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int accumulator_97 = local_arr[aux % 3];
  acc = (acc + (accumulator_97 * 2)) & 127;
  int metric_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_28) & 63;
  acc ^= aux;
  int tracker_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_68 > 48)
  {
    acc = ((acc + (tracker_68 * 2)) + 5) & 127;
    aux ^= tracker_68 & 15;
  }
  else
  {
    acc = ((acc - tracker_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001833_3313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st_1 = {0};
  struct DeviceConfig_R001833_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_15_1 > 27)
  {
    acc_1 = ((acc_1 + (accumulator_15_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_15_2 > 27)
  {
    acc_2 = ((acc_2 + (accumulator_15_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_19_1) & 63;
  aux_2 = (aux_2 + margin_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_15_1 == accumulator_15_2);
  assert(margin_19_1 == margin_19_2);
}

int fn_R001833_3313_19(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001833_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_15 > 27)
  {
    acc = ((acc + (accumulator_15 * 2)) + 5) & 127;
    aux ^= accumulator_15 & 15;
  }
  else
  {
    acc = ((acc - accumulator_15) + 11) & 127;
    aux += 3;
  }
  int margin_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_67_1 = local_arr_1[aux_1 % 3];
  int quotient_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_67_1 == quotient_67_2);
}

int fn_R001833_3313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_67 = local_arr[aux % 3];
  acc = (acc + (quotient_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001833_3313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st_1 = {0};
  struct CipherContext_R001833_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_19_1 = local_arr_1[aux_1 % 3];
  int phase_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_19_2 * 2)) & 127;
  int scale_36_1 = 0;
  int scale_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_36_1 = ((scale_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_36_2 = ((scale_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_36_1) & 127;
    acc_2 = (acc_2 + scale_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_19_1 == phase_19_2);
  assert(scale_36_1 == scale_36_2);
}

int fn_R001833_3313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001833_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int phase_19 = local_arr[aux % 3];
  acc = (acc + (phase_19 * 2)) & 127;
  int scale_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_36 = ((scale_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001833_3313_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_12_1 > 14)
  {
    acc_1 = ((acc_1 + (accumulator_12_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_12_2 > 14)
  {
    acc_2 = ((acc_2 + (accumulator_12_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_91_1 = 0;
  int index_reg_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_91_1 = ((index_reg_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_91_2 = ((index_reg_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_91_1) & 127;
    acc_2 = (acc_2 + index_reg_91_2) & 127;
  }

  int residue_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_93_1)
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

  switch (residue_93_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_12_1 == accumulator_12_2);
  assert(index_reg_91_1 == index_reg_91_2);
  assert(residue_93_1 == residue_93_2);
}

int fn_R001833_3313_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001833_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_12 > 14)
  {
    acc = ((acc + (accumulator_12 * 2)) + 5) & 127;
    aux ^= accumulator_12 & 15;
  }
  else
  {
    acc = ((acc - accumulator_12) + 11) & 127;
    aux += 3;
  }
  int index_reg_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_91 = ((index_reg_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_91) & 127;
  }

  int residue_93 = (aux + st.buffer[1]) & 3;
  switch (residue_93)
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

void main()
{
  int sec_r001833_0_1;
  int sec_r001833_0_2;
  int sec_r001833_1_1;
  int sec_r001833_1_2;
  int sec_r001833_2_1;
  int sec_r001833_2_2;
  int sec_r001833_3_1;
  int sec_r001833_3_2;
  int sec_r001833_4_1;
  int sec_r001833_4_2;
  int sec_r001833_5_1;
  int sec_r001833_5_2;
  int sec_r001833_6_1;
  int sec_r001833_6_2;
  int sec_r001833_7_1;
  int sec_r001833_7_2;
  int sec_r001833_8_1;
  int sec_r001833_8_2;
  int sec_r001833_9_1;
  int sec_r001833_9_2;
  int sec_r001833_10_1;
  int sec_r001833_10_2;
  int sec_r001833_11_1;
  int sec_r001833_11_2;
  int sec_r001833_12_1;
  int sec_r001833_12_2;
  int sec_r001833_13_1;
  int sec_r001833_13_2;
  int sec_r001833_14_1;
  int sec_r001833_14_2;
  int sec_r001833_15_1;
  int sec_r001833_15_2;
  int sec_r001833_16_1;
  int sec_r001833_16_2;
  int sec_r001833_17_1;
  int sec_r001833_17_2;
  int sec_r001833_18_1;
  int sec_r001833_18_2;
  int sec_r001833_19_1;
  int sec_r001833_19_2;
  int sec_r001833_20_1;
  int sec_r001833_20_2;
  int sec_r001833_21_1;
  int sec_r001833_21_2;
  int sec_r001833_22_1;
  int sec_r001833_22_2;
  int sec_r001833_23_1;
  int sec_r001833_23_2;
  int pub_r001833_0_1;
  int pub_r001833_0_2;
  int pub_r001833_1_1;
  int pub_r001833_1_2;
  int pub_r001833_2_1;
  int pub_r001833_2_2;
  int pub_r001833_3_1;
  int pub_r001833_3_2;
  int pub_r001833_4_1;
  int pub_r001833_4_2;
  int pub_r001833_5_1;
  int pub_r001833_5_2;
  int pub_r001833_6_1;
  int pub_r001833_6_2;
  int pub_r001833_7_1;
  int pub_r001833_7_2;
  int pub_r001833_8_1;
  int pub_r001833_8_2;
  int pub_r001833_9_1;
  int pub_r001833_9_2;
  int pub_r001833_10_1;
  int pub_r001833_10_2;
  int pub_r001833_11_1;
  int pub_r001833_11_2;
  int pub_r001833_12_1;
  int pub_r001833_12_2;
  int pub_r001833_13_1;
  int pub_r001833_13_2;
  int pub_r001833_14_1;
  int pub_r001833_14_2;
  int pub_r001833_15_1;
  int pub_r001833_15_2;
  int pub_r001833_16_1;
  int pub_r001833_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001833_0_1 >= (-100)) && (pub_r001833_0_1 <= 100));
  __CPROVER_assume((pub_r001833_0_2 >= (-100)) && (pub_r001833_0_2 <= 100));
  __CPROVER_assume((pub_r001833_1_1 >= (-100)) && (pub_r001833_1_1 <= 100));
  __CPROVER_assume((pub_r001833_1_2 >= (-100)) && (pub_r001833_1_2 <= 100));
  __CPROVER_assume((pub_r001833_2_1 >= (-100)) && (pub_r001833_2_1 <= 100));
  __CPROVER_assume((pub_r001833_2_2 >= (-100)) && (pub_r001833_2_2 <= 100));
  __CPROVER_assume((pub_r001833_3_1 >= (-100)) && (pub_r001833_3_1 <= 100));
  __CPROVER_assume((pub_r001833_3_2 >= (-100)) && (pub_r001833_3_2 <= 100));
  __CPROVER_assume((pub_r001833_4_1 >= (-100)) && (pub_r001833_4_1 <= 100));
  __CPROVER_assume((pub_r001833_4_2 >= (-100)) && (pub_r001833_4_2 <= 100));
  __CPROVER_assume((pub_r001833_5_1 >= (-100)) && (pub_r001833_5_1 <= 100));
  __CPROVER_assume((pub_r001833_5_2 >= (-100)) && (pub_r001833_5_2 <= 100));
  __CPROVER_assume((pub_r001833_6_1 >= (-100)) && (pub_r001833_6_1 <= 100));
  __CPROVER_assume((pub_r001833_6_2 >= (-100)) && (pub_r001833_6_2 <= 100));
  __CPROVER_assume((pub_r001833_7_1 >= (-100)) && (pub_r001833_7_1 <= 100));
  __CPROVER_assume((pub_r001833_7_2 >= (-100)) && (pub_r001833_7_2 <= 100));
  __CPROVER_assume((pub_r001833_8_1 >= (-100)) && (pub_r001833_8_1 <= 100));
  __CPROVER_assume((pub_r001833_8_2 >= (-100)) && (pub_r001833_8_2 <= 100));
  __CPROVER_assume((pub_r001833_9_1 >= (-100)) && (pub_r001833_9_1 <= 100));
  __CPROVER_assume((pub_r001833_9_2 >= (-100)) && (pub_r001833_9_2 <= 100));
  __CPROVER_assume((pub_r001833_10_1 >= (-100)) && (pub_r001833_10_1 <= 100));
  __CPROVER_assume((pub_r001833_10_2 >= (-100)) && (pub_r001833_10_2 <= 100));
  __CPROVER_assume((pub_r001833_11_1 >= (-100)) && (pub_r001833_11_1 <= 100));
  __CPROVER_assume((pub_r001833_11_2 >= (-100)) && (pub_r001833_11_2 <= 100));
  __CPROVER_assume((pub_r001833_12_1 >= (-100)) && (pub_r001833_12_1 <= 100));
  __CPROVER_assume((pub_r001833_12_2 >= (-100)) && (pub_r001833_12_2 <= 100));
  __CPROVER_assume((pub_r001833_13_1 >= (-100)) && (pub_r001833_13_1 <= 100));
  __CPROVER_assume((pub_r001833_13_2 >= (-100)) && (pub_r001833_13_2 <= 100));
  __CPROVER_assume((pub_r001833_14_1 >= (-100)) && (pub_r001833_14_1 <= 100));
  __CPROVER_assume((pub_r001833_14_2 >= (-100)) && (pub_r001833_14_2 <= 100));
  __CPROVER_assume((pub_r001833_15_1 >= (-100)) && (pub_r001833_15_1 <= 100));
  __CPROVER_assume((pub_r001833_15_2 >= (-100)) && (pub_r001833_15_2 <= 100));
  __CPROVER_assume((pub_r001833_16_1 >= (-100)) && (pub_r001833_16_1 <= 100));
  __CPROVER_assume((pub_r001833_16_2 >= (-100)) && (pub_r001833_16_2 <= 100));
  __CPROVER_assume((sec_r001833_0_1 >= 0) && (sec_r001833_0_1 <= 255));
  __CPROVER_assume((sec_r001833_0_2 >= 0) && (sec_r001833_0_2 <= 255));
  __CPROVER_assume((sec_r001833_1_1 >= 0) && (sec_r001833_1_1 <= 255));
  __CPROVER_assume((sec_r001833_1_2 >= 0) && (sec_r001833_1_2 <= 255));
  __CPROVER_assume((sec_r001833_2_1 >= 0) && (sec_r001833_2_1 <= 255));
  __CPROVER_assume((sec_r001833_2_2 >= 0) && (sec_r001833_2_2 <= 255));
  __CPROVER_assume((sec_r001833_3_1 >= 0) && (sec_r001833_3_1 <= 255));
  __CPROVER_assume((sec_r001833_3_2 >= 0) && (sec_r001833_3_2 <= 255));
  __CPROVER_assume((sec_r001833_4_1 >= 0) && (sec_r001833_4_1 <= 255));
  __CPROVER_assume((sec_r001833_4_2 >= 0) && (sec_r001833_4_2 <= 255));
  __CPROVER_assume((sec_r001833_5_1 >= 0) && (sec_r001833_5_1 <= 255));
  __CPROVER_assume((sec_r001833_5_2 >= 0) && (sec_r001833_5_2 <= 255));
  __CPROVER_assume((sec_r001833_6_1 >= 0) && (sec_r001833_6_1 <= 255));
  __CPROVER_assume((sec_r001833_6_2 >= 0) && (sec_r001833_6_2 <= 255));
  __CPROVER_assume((sec_r001833_7_1 >= 0) && (sec_r001833_7_1 <= 255));
  __CPROVER_assume((sec_r001833_7_2 >= 0) && (sec_r001833_7_2 <= 255));
  __CPROVER_assume((sec_r001833_8_1 >= 0) && (sec_r001833_8_1 <= 255));
  __CPROVER_assume((sec_r001833_8_2 >= 0) && (sec_r001833_8_2 <= 255));
  __CPROVER_assume((sec_r001833_9_1 >= 0) && (sec_r001833_9_1 <= 255));
  __CPROVER_assume((sec_r001833_9_2 >= 0) && (sec_r001833_9_2 <= 255));
  __CPROVER_assume((sec_r001833_10_1 >= 0) && (sec_r001833_10_1 <= 255));
  __CPROVER_assume((sec_r001833_10_2 >= 0) && (sec_r001833_10_2 <= 255));
  __CPROVER_assume((sec_r001833_11_1 >= 0) && (sec_r001833_11_1 <= 255));
  __CPROVER_assume((sec_r001833_11_2 >= 0) && (sec_r001833_11_2 <= 255));
  __CPROVER_assume((sec_r001833_12_1 >= 0) && (sec_r001833_12_1 <= 255));
  __CPROVER_assume((sec_r001833_12_2 >= 0) && (sec_r001833_12_2 <= 255));
  __CPROVER_assume((sec_r001833_13_1 >= 0) && (sec_r001833_13_1 <= 255));
  __CPROVER_assume((sec_r001833_13_2 >= 0) && (sec_r001833_13_2 <= 255));
  __CPROVER_assume((sec_r001833_14_1 >= 0) && (sec_r001833_14_1 <= 255));
  __CPROVER_assume((sec_r001833_14_2 >= 0) && (sec_r001833_14_2 <= 255));
  __CPROVER_assume((sec_r001833_15_1 >= 0) && (sec_r001833_15_1 <= 255));
  __CPROVER_assume((sec_r001833_15_2 >= 0) && (sec_r001833_15_2 <= 255));
  __CPROVER_assume((sec_r001833_16_1 >= 0) && (sec_r001833_16_1 <= 255));
  __CPROVER_assume((sec_r001833_16_2 >= 0) && (sec_r001833_16_2 <= 255));
  __CPROVER_assume((sec_r001833_17_1 >= 0) && (sec_r001833_17_1 <= 255));
  __CPROVER_assume((sec_r001833_17_2 >= 0) && (sec_r001833_17_2 <= 255));
  __CPROVER_assume((sec_r001833_18_1 >= 0) && (sec_r001833_18_1 <= 255));
  __CPROVER_assume((sec_r001833_18_2 >= 0) && (sec_r001833_18_2 <= 255));
  __CPROVER_assume((sec_r001833_19_1 >= 0) && (sec_r001833_19_1 <= 255));
  __CPROVER_assume((sec_r001833_19_2 >= 0) && (sec_r001833_19_2 <= 255));
  __CPROVER_assume((sec_r001833_20_1 >= 0) && (sec_r001833_20_1 <= 255));
  __CPROVER_assume((sec_r001833_20_2 >= 0) && (sec_r001833_20_2 <= 255));
  __CPROVER_assume((sec_r001833_21_1 >= 0) && (sec_r001833_21_1 <= 255));
  __CPROVER_assume((sec_r001833_21_2 >= 0) && (sec_r001833_21_2 <= 255));
  __CPROVER_assume((sec_r001833_22_1 >= 0) && (sec_r001833_22_1 <= 255));
  __CPROVER_assume((sec_r001833_22_2 >= 0) && (sec_r001833_22_2 <= 255));
  __CPROVER_assume((sec_r001833_23_1 >= 0) && (sec_r001833_23_1 <= 255));
  __CPROVER_assume((sec_r001833_23_2 >= 0) && (sec_r001833_23_2 <= 255));
  struct CipherContext_R001833_3313_0 st_var_0_1 = {0};
  struct CipherContext_R001833_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001833_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001833_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001833_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001833_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001833_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001833_0_2 + 7) & 15;
  struct StreamBuffer_R001833_3313_1 st_var_1_1 = {0};
  struct StreamBuffer_R001833_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001833_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001833_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001833_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001833_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001833_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001833_0_2 + 9) & 15;
  struct FilterState_R001833_3313_2 st_var_2_1 = {0};
  struct FilterState_R001833_3313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001833_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001833_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001833_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001833_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001833_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001833_0_2 + 11) & 15;
  struct DeviceConfig_R001833_3313_3 st_var_3_1 = {0};
  struct DeviceConfig_R001833_3313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001833_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001833_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001833_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001833_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001833_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001833_0_2 + 13) & 15;
  union TelemetryField_R001833_3313_0 u_var_1;
  union TelemetryField_R001833_3313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001833_3313_0(sec_r001833_0_1, sec_r001833_1_1, pub_r001833_2_1);
  int helper_flow_0_2 = fn_R001833_3313_0(sec_r001833_0_2, sec_r001833_1_2, pub_r001833_2_2);
  fn_R001833_3313_0_2(sec_r001833_0_1, sec_r001833_1_1, pub_r001833_2_1, sec_r001833_0_2, sec_r001833_1_2, pub_r001833_2_2);
  int helper_flow_1_1 = fn_R001833_3313_1(sec_r001833_1_1, sec_r001833_2_1);
  int helper_flow_1_2 = fn_R001833_3313_1(sec_r001833_1_2, sec_r001833_2_2);
  fn_R001833_3313_1_2(sec_r001833_1_1, sec_r001833_2_1, sec_r001833_1_2, sec_r001833_2_2);
  int helper_flow_2_1 = fn_R001833_3313_2(sec_r001833_2_1, sec_r001833_3_1);
  int helper_flow_2_2 = fn_R001833_3313_2(sec_r001833_2_2, sec_r001833_3_2);
  fn_R001833_3313_2_2(sec_r001833_2_1, sec_r001833_3_1, sec_r001833_2_2, sec_r001833_3_2);
  int helper_flow_3_1 = fn_R001833_3313_3(sec_r001833_3_1, sec_r001833_4_1, pub_r001833_5_1);
  int helper_flow_3_2 = fn_R001833_3313_3(sec_r001833_3_2, sec_r001833_4_2, pub_r001833_5_2);
  fn_R001833_3313_3_2(sec_r001833_3_1, sec_r001833_4_1, pub_r001833_5_1, sec_r001833_3_2, sec_r001833_4_2, pub_r001833_5_2);
  int helper_flow_4_1 = fn_R001833_3313_4(sec_r001833_4_1, pub_r001833_5_1, pub_r001833_6_1, pub_r001833_7_1, pub_r001833_8_1);
  int helper_flow_4_2 = fn_R001833_3313_4(sec_r001833_4_2, pub_r001833_5_2, pub_r001833_6_2, pub_r001833_7_2, pub_r001833_8_2);
  fn_R001833_3313_4_2(sec_r001833_4_1, pub_r001833_5_1, pub_r001833_6_1, pub_r001833_7_1, pub_r001833_8_1, sec_r001833_4_2, pub_r001833_5_2, pub_r001833_6_2, pub_r001833_7_2, pub_r001833_8_2);
  int helper_flow_5_1 = fn_R001833_3313_5(sec_r001833_5_1, pub_r001833_6_1, pub_r001833_7_1, pub_r001833_8_1);
  int helper_flow_5_2 = fn_R001833_3313_5(sec_r001833_5_2, pub_r001833_6_2, pub_r001833_7_2, pub_r001833_8_2);
  fn_R001833_3313_5_2(sec_r001833_5_1, pub_r001833_6_1, pub_r001833_7_1, pub_r001833_8_1, sec_r001833_5_2, pub_r001833_6_2, pub_r001833_7_2, pub_r001833_8_2);
  int helper_flow_6_1 = fn_R001833_3313_6(sec_r001833_6_1, sec_r001833_7_1, pub_r001833_8_1);
  int helper_flow_6_2 = fn_R001833_3313_6(sec_r001833_6_2, sec_r001833_7_2, pub_r001833_8_2);
  fn_R001833_3313_6_2(sec_r001833_6_1, sec_r001833_7_1, pub_r001833_8_1, sec_r001833_6_2, sec_r001833_7_2, pub_r001833_8_2);
  int stage_v_0_1 = (((sec_r001833_22_1 * 3) + pub_r001833_16_1) + 45) & 127;
  int stage_v_0_2 = (((sec_r001833_22_2 * 3) + pub_r001833_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001833_13_1 * 2) + 34) & 63;
  int stage_v_1_2 = ((pub_r001833_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001833_13_1 * 2) + 26) & 63;
  int stage_v_2_2 = ((pub_r001833_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001833_2_1 * 2) + 17) & 63;
  int stage_v_3_2 = ((pub_r001833_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001833_4_1 * 2) + 10) & 63;
  int stage_v_4_2 = ((pub_r001833_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001833_4_1 * 2) + 19) & 63;
  int stage_v_5_2 = ((pub_r001833_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001833_11_1 * 2) + 24) & 63;
  int stage_v_6_2 = ((pub_r001833_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001833_12_1 * 3) + pub_r001833_5_1) + 16) & 127;
  int stage_v_7_2 = (((sec_r001833_12_2 * 3) + pub_r001833_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001833_2_1 * 2) + 25) & 63;
  int stage_v_8_2 = ((pub_r001833_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001833_16_1 * 3) + pub_r001833_13_1) + 26) & 127;
  int stage_v_9_2 = (((sec_r001833_16_2 * 3) + pub_r001833_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001833_15_1 * 2) + 36) & 63;
  int stage_v_10_2 = ((pub_r001833_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((stage_v_9_1 * 3) + pub_r001833_0_1) + 23) & 127;
  int stage_v_11_2 = (((stage_v_9_2 * 3) + pub_r001833_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001833_12_1 * 3) + pub_r001833_14_1) + 3) & 127;
  int stage_v_12_2 = (((sec_r001833_12_2 * 3) + pub_r001833_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((helper_flow_5_1 * 3) + pub_r001833_11_1) + 34) & 127;
  int stage_v_13_2 = (((helper_flow_5_2 * 3) + pub_r001833_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001833_19_1 * 3) + pub_r001833_9_1) + 23) & 127;
  int stage_v_14_2 = (((sec_r001833_19_2 * 3) + pub_r001833_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001833_6_1 * 3) + pub_r001833_2_1) + 35) & 127;
  int stage_v_15_2 = (((sec_r001833_6_2 * 3) + pub_r001833_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001833_8_1 * 2) + 29) & 63;
  int stage_v_16_2 = ((pub_r001833_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((helper_flow_4_1 * 3) + pub_r001833_11_1) + 26) & 127;
  int stage_v_17_2 = (((helper_flow_4_2 * 3) + pub_r001833_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001833_3_1 * 2) + 8) & 63;
  int stage_v_18_2 = ((pub_r001833_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001833_10_1 * 2) + 19) & 63;
  int stage_v_19_2 = ((pub_r001833_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001833_4_1 * 2) + 14) & 63;
  int stage_v_20_2 = ((pub_r001833_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_11_1 * 3) + pub_r001833_7_1) + 22) & 127;
  int stage_v_21_2 = (((stage_v_11_2 * 3) + pub_r001833_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((sec_r001833_5_1 * 3) + pub_r001833_5_1) + 44) & 127;
  int stage_v_22_2 = (((sec_r001833_5_2 * 3) + pub_r001833_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001833_11_1 * 2) + 10) & 63;
  int stage_v_23_2 = ((pub_r001833_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001833_13_1 * 3) + pub_r001833_0_1) + 36) & 127;
  int stage_v_24_2 = (((sec_r001833_13_2 * 3) + pub_r001833_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((stage_v_11_1 * 3) + pub_r001833_5_1) + 14) & 127;
  int stage_v_25_2 = (((stage_v_11_2 * 3) + pub_r001833_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((stage_v_25_1 * 3) + pub_r001833_0_1) + 5) & 127;
  int stage_v_26_2 = (((stage_v_25_2 * 3) + pub_r001833_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001833_16_1 * 2) + 46) & 63;
  int stage_v_27_2 = ((pub_r001833_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001833_0_1 * 2) + 50) & 63;
  int stage_v_28_2 = ((pub_r001833_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((sec_r001833_17_1 * 3) + pub_r001833_6_1) + 31) & 127;
  int stage_v_29_2 = (((sec_r001833_17_2 * 3) + pub_r001833_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((sec_r001833_5_1 * 3) + pub_r001833_7_1) + 7) & 127;
  int stage_v_30_2 = (((sec_r001833_5_2 * 3) + pub_r001833_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001833_1_1 * 2) + 35) & 63;
  int stage_v_31_2 = ((pub_r001833_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001833_14_1 * 2) + 5) & 63;
  int stage_v_32_2 = ((pub_r001833_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((sec_r001833_5_1 * 3) + pub_r001833_13_1) + 18) & 127;
  int stage_v_33_2 = (((sec_r001833_5_2 * 3) + pub_r001833_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_29_1 * 3) + pub_r001833_3_1) + 38) & 127;
  int stage_v_34_2 = (((stage_v_29_2 * 3) + pub_r001833_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((sec_r001833_6_1 * 3) + pub_r001833_16_1) + 6) & 127;
  int stage_v_35_2 = (((sec_r001833_6_2 * 3) + pub_r001833_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_26_1 * 3) + pub_r001833_9_1) + 29) & 127;
  int stage_v_36_2 = (((stage_v_26_2 * 3) + pub_r001833_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001833_14_1 * 2) + 8) & 63;
  int stage_v_37_2 = ((pub_r001833_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001833_8_1 * 3) + pub_r001833_3_1) + 3) & 127;
  int stage_v_38_2 = (((sec_r001833_8_2 * 3) + pub_r001833_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001833_6_1 * 2) + 15) & 63;
  int stage_v_39_2 = ((pub_r001833_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001833_21_1 * 3) + pub_r001833_10_1) + 26) & 127;
  int stage_v_40_2 = (((sec_r001833_21_2 * 3) + pub_r001833_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001833_14_1 * 2) + 6) & 63;
  int stage_v_41_2 = ((pub_r001833_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((stage_v_24_1 * 3) + pub_r001833_13_1) + 10) & 127;
  int stage_v_42_2 = (((stage_v_24_2 * 3) + pub_r001833_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001833_9_1 * 2) + 12) & 63;
  int stage_v_43_2 = ((pub_r001833_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001833_13_1 * 2) + 50) & 63;
  int stage_v_44_2 = ((pub_r001833_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_34_1 * 3) + pub_r001833_12_1) + 7) & 127;
  int stage_v_45_2 = (((stage_v_34_2 * 3) + pub_r001833_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((sec_r001833_12_1 * 3) + pub_r001833_8_1) + 20) & 127;
  int stage_v_46_2 = (((sec_r001833_12_2 * 3) + pub_r001833_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001833_5_1 * 2) + 34) & 63;
  int stage_v_47_2 = ((pub_r001833_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001833_6_1 * 2) + 48) & 63;
  int stage_v_48_2 = ((pub_r001833_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001833_8_1 * 2) + 30) & 63;
  int stage_v_49_2 = ((pub_r001833_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001833_8_1 * 2) + 38) & 63;
  int stage_v_50_2 = ((pub_r001833_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001833_9_1 * 2) + 41) & 63;
  int stage_v_51_2 = ((pub_r001833_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001833_12_1 * 3) + pub_r001833_12_1) + 38) & 127;
  int stage_v_52_2 = (((sec_r001833_12_2 * 3) + pub_r001833_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((stage_v_38_1 * 3) + pub_r001833_0_1) + 34) & 127;
  int stage_v_53_2 = (((stage_v_38_2 * 3) + pub_r001833_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((stage_v_24_1 * 3) + pub_r001833_9_1) + 8) & 127;
  int stage_v_54_2 = (((stage_v_24_2 * 3) + pub_r001833_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((sec_r001833_22_1 * 3) + pub_r001833_2_1) + 20) & 127;
  int stage_v_55_2 = (((sec_r001833_22_2 * 3) + pub_r001833_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_54_1 * 3) + pub_r001833_3_1) + 8) & 127;
  int stage_v_56_2 = (((stage_v_54_2 * 3) + pub_r001833_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001833_8_1 * 3) + pub_r001833_2_1) + 4) & 127;
  int stage_v_57_2 = (((sec_r001833_8_2 * 3) + pub_r001833_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001833_11_1 * 2) + 43) & 63;
  int stage_v_58_2 = ((pub_r001833_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_53_1 * 3) + pub_r001833_0_1) + 14) & 127;
  int stage_v_59_2 = (((stage_v_53_2 * 3) + pub_r001833_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001833_10_1 * 2) + 40) & 63;
  int stage_v_60_2 = ((pub_r001833_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001833_4_1 * 3) + pub_r001833_12_1) + 42) & 127;
  int stage_v_61_2 = (((sec_r001833_4_2 * 3) + pub_r001833_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((sec_r001833_17_1 * 3) + pub_r001833_12_1) + 28) & 127;
  int stage_v_62_2 = (((sec_r001833_17_2 * 3) + pub_r001833_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001833_23_1 * 3) + pub_r001833_1_1) + 5) & 127;
  int stage_v_63_2 = (((sec_r001833_23_2 * 3) + pub_r001833_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001833_15_1 * 2) + 35) & 63;
  int stage_v_64_2 = ((pub_r001833_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001833_11_1 * 2) + 11) & 63;
  int stage_v_65_2 = ((pub_r001833_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001833_11_1 * 2) + 36) & 63;
  int stage_v_66_2 = ((pub_r001833_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001833_6_1 * 2) + 39) & 63;
  int stage_v_67_2 = ((pub_r001833_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((helper_flow_2_1 * 3) + pub_r001833_2_1) + 24) & 127;
  int stage_v_68_2 = (((helper_flow_2_2 * 3) + pub_r001833_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((sec_r001833_19_1 * 3) + pub_r001833_15_1) + 36) & 127;
  int stage_v_69_2 = (((sec_r001833_19_2 * 3) + pub_r001833_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001833_7_1 * 2) + 35) & 63;
  int stage_v_70_2 = ((pub_r001833_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001833_3_1 * 2) + 30) & 63;
  int stage_v_71_2 = ((pub_r001833_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001833_22_1 * 3) + pub_r001833_4_1) + 10) & 127;
  int stage_v_72_2 = (((sec_r001833_22_2 * 3) + pub_r001833_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001833_11_1 * 2) + 11) & 63;
  int stage_v_73_2 = ((pub_r001833_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001833_3_1 * 2) + 30) & 63;
  int stage_v_74_2 = ((pub_r001833_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001833_11_1 * 2) + 45) & 63;
  int stage_v_75_2 = ((pub_r001833_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001833_8_1 * 2) + 39) & 63;
  int stage_v_76_2 = ((pub_r001833_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((helper_flow_0_1 * 3) + pub_r001833_10_1) + 31) & 127;
  int stage_v_77_2 = (((helper_flow_0_2 * 3) + pub_r001833_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001833_11_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001833_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001833_12_1 * 2) + 33) & 63;
  int stage_v_79_2 = ((pub_r001833_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001833_8_1 * 2) + 43) & 63;
  int stage_v_80_2 = ((pub_r001833_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001833_21_1 * 3) + pub_r001833_5_1) + 3) & 127;
  int stage_v_81_2 = (((sec_r001833_21_2 * 3) + pub_r001833_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((sec_r001833_2_1 * 3) + pub_r001833_14_1) + 43) & 127;
  int stage_v_82_2 = (((sec_r001833_2_2 * 3) + pub_r001833_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001833_8_1 * 2) + 32) & 63;
  int stage_v_83_2 = ((pub_r001833_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001833_2_1 * 2) + 16) & 63;
  int stage_v_84_2 = ((pub_r001833_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((sec_r001833_17_1 * 3) + pub_r001833_7_1) + 15) & 127;
  int stage_v_85_2 = (((sec_r001833_17_2 * 3) + pub_r001833_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001833_13_1 * 2) + 5) & 63;
  int stage_v_86_2 = ((pub_r001833_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001833_6_1 * 2) + 46) & 63;
  int stage_v_87_2 = ((pub_r001833_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001833_9_1 * 2) + 32) & 63;
  int stage_v_88_2 = ((pub_r001833_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_62_1 * 3) + pub_r001833_5_1) + 31) & 127;
  int stage_v_89_2 = (((stage_v_62_2 * 3) + pub_r001833_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_36_1 * 3) + pub_r001833_15_1) + 45) & 127;
  int stage_v_90_2 = (((stage_v_36_2 * 3) + pub_r001833_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001833_10_1 * 2) + 35) & 63;
  int stage_v_91_2 = ((pub_r001833_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001833_15_1 * 2) + 45) & 63;
  int stage_v_92_2 = ((pub_r001833_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001833_14_1 * 2) + 37) & 63;
  int stage_v_93_2 = ((pub_r001833_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001833_11_1 * 2) + 47) & 63;
  int stage_v_94_2 = ((pub_r001833_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001833_15_1 * 2) + 7) & 63;
  int stage_v_95_2 = ((pub_r001833_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001833_8_1 * 2) + 37) & 63;
  int stage_v_96_2 = ((pub_r001833_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001833_9_1 * 2) + 41) & 63;
  int stage_v_97_2 = ((pub_r001833_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_42_1 * 3) + pub_r001833_10_1) + 16) & 127;
  int stage_v_98_2 = (((stage_v_42_2 * 3) + pub_r001833_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((sec_r001833_9_1 * 3) + pub_r001833_12_1) + 11) & 127;
  int stage_v_99_2 = (((sec_r001833_9_2 * 3) + pub_r001833_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((sec_r001833_0_1 * 3) + pub_r001833_15_1) + 42) & 127;
  int stage_v_100_2 = (((sec_r001833_0_2 * 3) + pub_r001833_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_35_1 * 3) + pub_r001833_5_1) + 16) & 127;
  int stage_v_101_2 = (((stage_v_35_2 * 3) + pub_r001833_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001833_16_1 * 2) + 29) & 63;
  int stage_v_102_2 = ((pub_r001833_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001833_7_1 * 2) + 18) & 63;
  int stage_v_103_2 = ((pub_r001833_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_72_1 * 3) + pub_r001833_15_1) + 5) & 127;
  int stage_v_104_2 = (((stage_v_72_2 * 3) + pub_r001833_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001833_7_1 * 2) + 6) & 63;
  int stage_v_105_2 = ((pub_r001833_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001833_10_1 * 3) + pub_r001833_2_1) + 40) & 127;
  int stage_v_106_2 = (((sec_r001833_10_2 * 3) + pub_r001833_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((sec_r001833_7_1 * 3) + pub_r001833_2_1) + 29) & 127;
  int stage_v_107_2 = (((sec_r001833_7_2 * 3) + pub_r001833_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_11_1 * 3) + pub_r001833_3_1) + 34) & 127;
  int stage_v_108_2 = (((stage_v_11_2 * 3) + pub_r001833_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_57_1 * 3) + pub_r001833_10_1) + 12) & 127;
  int stage_v_109_2 = (((stage_v_57_2 * 3) + pub_r001833_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_98_1 * 3) + pub_r001833_12_1) + 38) & 127;
  int stage_v_110_2 = (((stage_v_98_2 * 3) + pub_r001833_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_61_1 * 3) + pub_r001833_5_1) + 32) & 127;
  int stage_v_111_2 = (((stage_v_61_2 * 3) + pub_r001833_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001833_11_1 * 2) + 10) & 63;
  int stage_v_112_2 = ((pub_r001833_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_53_1 * 3) + pub_r001833_3_1) + 6) & 127;
  int stage_v_113_2 = (((stage_v_53_2 * 3) + pub_r001833_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_109_1 * 3) + pub_r001833_6_1) + 19) & 127;
  int stage_v_114_2 = (((stage_v_109_2 * 3) + pub_r001833_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001833_9_1 * 2) + 35) & 63;
  int stage_v_115_2 = ((pub_r001833_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_68_1 * 3) + pub_r001833_13_1) + 45) & 127;
  int stage_v_116_2 = (((stage_v_68_2 * 3) + pub_r001833_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001833_0_1 * 2) + 21) & 63;
  int stage_v_117_2 = ((pub_r001833_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001833_8_1 * 2) + 41) & 63;
  int stage_v_118_2 = ((pub_r001833_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_61_1 * 3) + pub_r001833_2_1) + 34) & 127;
  int stage_v_119_2 = (((stage_v_61_2 * 3) + pub_r001833_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001833_5_1 * 2) + 39) & 63;
  int stage_v_120_2 = ((pub_r001833_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001833_2_1 * 2) + 37) & 63;
  int stage_v_121_2 = ((pub_r001833_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_15_1 * 3) + pub_r001833_13_1) + 24) & 127;
  int stage_v_122_2 = (((stage_v_15_2 * 3) + pub_r001833_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001833_3_1 * 2) + 10) & 63;
  int stage_v_123_2 = ((pub_r001833_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_42_1 * 3) + pub_r001833_10_1) + 23) & 127;
  int stage_v_124_2 = (((stage_v_42_2 * 3) + pub_r001833_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((sec_r001833_17_1 * 3) + pub_r001833_6_1) + 36) & 127;
  int stage_v_125_2 = (((sec_r001833_17_2 * 3) + pub_r001833_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001833_3_1 * 2) + 19) & 63;
  int stage_v_126_2 = ((pub_r001833_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_62_1 * 3) + pub_r001833_10_1) + 31) & 127;
  int stage_v_127_2 = (((stage_v_62_2 * 3) + pub_r001833_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_34_1 * 3) + pub_r001833_7_1) + 9) & 127;
  int stage_v_128_2 = (((stage_v_34_2 * 3) + pub_r001833_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001833_4_1 * 2) + 35) & 63;
  int stage_v_129_2 = ((pub_r001833_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((helper_flow_1_1 * 3) + pub_r001833_6_1) + 27) & 127;
  int stage_v_130_2 = (((helper_flow_1_2 * 3) + pub_r001833_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001833_11_1 * 2) + 16) & 63;
  int stage_v_131_2 = ((pub_r001833_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_122_1 * 3) + pub_r001833_10_1) + 8) & 127;
  int stage_v_132_2 = (((stage_v_122_2 * 3) + pub_r001833_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_33_1 * 3) + pub_r001833_6_1) + 12) & 127;
  int stage_v_133_2 = (((stage_v_33_2 * 3) + pub_r001833_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_72_1 * 3) + pub_r001833_1_1) + 20) & 127;
  int stage_v_134_2 = (((stage_v_72_2 * 3) + pub_r001833_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_100_1 * 3) + pub_r001833_16_1) + 8) & 127;
  int stage_v_135_2 = (((stage_v_100_2 * 3) + pub_r001833_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_68_1 * 3) + pub_r001833_9_1) + 15) & 127;
  int stage_v_136_2 = (((stage_v_68_2 * 3) + pub_r001833_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001833_1_1 * 2) + 47) & 63;
  int stage_v_137_2 = ((pub_r001833_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_38_1 * 3) + pub_r001833_3_1) + 17) & 127;
  int stage_v_138_2 = (((stage_v_38_2 * 3) + pub_r001833_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001833_14_1 * 2) + 6) & 63;
  int stage_v_139_2 = ((pub_r001833_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001833_15_1 * 2) + 12) & 63;
  int stage_v_140_2 = ((pub_r001833_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001833_5_1 * 2) + 30) & 63;
  int stage_v_141_2 = ((pub_r001833_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((sec_r001833_8_1 * 3) + pub_r001833_12_1) + 19) & 127;
  int stage_v_142_2 = (((sec_r001833_8_2 * 3) + pub_r001833_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001833_16_1 * 2) + 37) & 63;
  int stage_v_143_2 = ((pub_r001833_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001833_15_1 * 2) + 24) & 63;
  int stage_v_144_2 = ((pub_r001833_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001833_0_1 * 2) + 49) & 63;
  int stage_v_145_2 = ((pub_r001833_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((helper_flow_5_1 * 3) + pub_r001833_13_1) + 10) & 127;
  int stage_v_146_2 = (((helper_flow_5_2 * 3) + pub_r001833_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001833_8_1 * 2) + 43) & 63;
  int stage_v_147_2 = ((pub_r001833_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001833_2_1 * 2) + 32) & 63;
  int stage_v_148_2 = ((pub_r001833_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001833_16_1 * 2) + 49) & 63;
  int stage_v_149_2 = ((pub_r001833_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001833_14_1 * 2) + 19) & 63;
  int stage_v_150_2 = ((pub_r001833_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_13_1 * 3) + pub_r001833_12_1) + 11) & 127;
  int stage_v_151_2 = (((stage_v_13_2 * 3) + pub_r001833_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((sec_r001833_21_1 * 3) + pub_r001833_14_1) + 39) & 127;
  int stage_v_152_2 = (((sec_r001833_21_2 * 3) + pub_r001833_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001833_5_1 * 2) + 39) & 63;
  int stage_v_153_2 = ((pub_r001833_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001833_13_1 * 2) + 31) & 63;
  int stage_v_154_2 = ((pub_r001833_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001833_7_1 * 2) + 50) & 63;
  int stage_v_155_2 = ((pub_r001833_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_13_1 * 3) + pub_r001833_14_1) + 18) & 127;
  int stage_v_156_2 = (((stage_v_13_2 * 3) + pub_r001833_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001833_21_1 * 3) + pub_r001833_9_1) + 32) & 127;
  int stage_v_157_2 = (((sec_r001833_21_2 * 3) + pub_r001833_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_0_1 * 3) + pub_r001833_16_1) + 41) & 127;
  int stage_v_158_2 = (((stage_v_0_2 * 3) + pub_r001833_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((helper_flow_2_1 * 3) + pub_r001833_15_1) + 28) & 127;
  int stage_v_159_2 = (((helper_flow_2_2 * 3) + pub_r001833_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001833_7_1 * 2) + 11) & 63;
  int stage_v_160_2 = ((pub_r001833_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001833_16_1 * 2) + 41) & 63;
  int stage_v_161_2 = ((pub_r001833_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_125_1 * 3) + pub_r001833_4_1) + 43) & 127;
  int stage_v_162_2 = (((stage_v_125_2 * 3) + pub_r001833_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001833_5_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001833_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_17_1 * 3) + pub_r001833_1_1) + 27) & 127;
  int stage_v_164_2 = (((stage_v_17_2 * 3) + pub_r001833_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001833_9_1 * 2) + 46) & 63;
  int stage_v_165_2 = ((pub_r001833_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001833_15_1 * 2) + 16) & 63;
  int stage_v_166_2 = ((pub_r001833_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_59_1 * 3) + pub_r001833_6_1) + 38) & 127;
  int stage_v_167_2 = (((stage_v_59_2 * 3) + pub_r001833_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001833_3_1 * 2) + 37) & 63;
  int stage_v_168_2 = ((pub_r001833_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_159_1 * 3) + pub_r001833_15_1) + 30) & 127;
  int stage_v_169_2 = (((stage_v_159_2 * 3) + pub_r001833_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_158_1 * 3) + pub_r001833_4_1) + 38) & 127;
  int stage_v_170_2 = (((stage_v_158_2 * 3) + pub_r001833_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((sec_r001833_0_1 * 3) + pub_r001833_16_1) + 4) & 127;
  int stage_v_171_2 = (((sec_r001833_0_2 * 3) + pub_r001833_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((helper_flow_6_1 * 3) + pub_r001833_2_1) + 17) & 127;
  int stage_v_172_2 = (((helper_flow_6_2 * 3) + pub_r001833_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_135_1 * 3) + pub_r001833_8_1) + 5) & 127;
  int stage_v_173_2 = (((stage_v_135_2 * 3) + pub_r001833_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_81_1 * 3) + pub_r001833_0_1) + 13) & 127;
  int stage_v_174_2 = (((stage_v_81_2 * 3) + pub_r001833_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001833_3_1 * 2) + 17) & 63;
  int stage_v_175_2 = ((pub_r001833_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_26_1 * 3) + pub_r001833_16_1) + 7) & 127;
  int stage_v_176_2 = (((stage_v_26_2 * 3) + pub_r001833_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001833_4_1 * 2) + 44) & 63;
  int stage_v_177_2 = ((pub_r001833_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001833_2_1 * 3) + pub_r001833_7_1) + 11) & 127;
  int stage_v_178_2 = (((sec_r001833_2_2 * 3) + pub_r001833_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_34_1 * 3) + pub_r001833_12_1) + 10) & 127;
  int stage_v_179_2 = (((stage_v_34_2 * 3) + pub_r001833_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((helper_flow_4_1 * 3) + pub_r001833_5_1) + 20) & 127;
  int stage_v_180_2 = (((helper_flow_4_2 * 3) + pub_r001833_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001833_7_1 * 2) + 31) & 63;
  int stage_v_181_2 = ((pub_r001833_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((sec_r001833_2_1 * 3) + pub_r001833_0_1) + 28) & 127;
  int stage_v_182_2 = (((sec_r001833_2_2 * 3) + pub_r001833_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_90_1 * 3) + pub_r001833_6_1) + 16) & 127;
  int stage_v_183_2 = (((stage_v_90_2 * 3) + pub_r001833_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_125_1 * 3) + pub_r001833_8_1) + 43) & 127;
  int stage_v_184_2 = (((stage_v_125_2 * 3) + pub_r001833_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001833_13_1 * 2) + 18) & 63;
  int stage_v_185_2 = ((pub_r001833_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001833_14_1 * 2) + 19) & 63;
  int stage_v_186_2 = ((pub_r001833_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((sec_r001833_15_1 * 3) + pub_r001833_3_1) + 4) & 127;
  int stage_v_187_2 = (((sec_r001833_15_2 * 3) + pub_r001833_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_98_1 * 3) + pub_r001833_9_1) + 38) & 127;
  int stage_v_188_2 = (((stage_v_98_2 * 3) + pub_r001833_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_101_1 * 3) + pub_r001833_13_1) + 36) & 127;
  int stage_v_189_2 = (((stage_v_101_2 * 3) + pub_r001833_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_130_1 * 3) + pub_r001833_6_1) + 14) & 127;
  int stage_v_190_2 = (((stage_v_130_2 * 3) + pub_r001833_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001833_7_1 * 2) + 10) & 63;
  int stage_v_191_2 = ((pub_r001833_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001833_2_1 * 2) + 16) & 63;
  int stage_v_192_2 = ((pub_r001833_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001833_12_1 * 2) + 33) & 63;
  int stage_v_193_2 = ((pub_r001833_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001833_2_1 * 2) + 32) & 63;
  int stage_v_194_2 = ((pub_r001833_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_29_1 * 3) + pub_r001833_14_1) + 30) & 127;
  int stage_v_195_2 = (((stage_v_29_2 * 3) + pub_r001833_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001833_7_1 * 2) + 49) & 63;
  int stage_v_196_2 = ((pub_r001833_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001833_0_1 * 2) + 50) & 63;
  int stage_v_197_2 = ((pub_r001833_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001833_0_1 * 2) + 38) & 63;
  int stage_v_198_2 = ((pub_r001833_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_133_1 * 3) + pub_r001833_7_1) + 41) & 127;
  int stage_v_199_2 = (((stage_v_133_2 * 3) + pub_r001833_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001833_0_1 * 2) + 46) & 63;
  int stage_v_200_2 = ((pub_r001833_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001833_4_1 * 2) + 14) & 63;
  int stage_v_201_2 = ((pub_r001833_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001833_13_1 * 2) + 32) & 63;
  int stage_v_202_2 = ((pub_r001833_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_46_1 * 3) + pub_r001833_0_1) + 24) & 127;
  int stage_v_203_2 = (((stage_v_46_2 * 3) + pub_r001833_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001833_9_1 * 2) + 26) & 63;
  int stage_v_204_2 = ((pub_r001833_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001833_6_1 * 2) + 40) & 63;
  int stage_v_205_2 = ((pub_r001833_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((sec_r001833_13_1 * 3) + pub_r001833_13_1) + 10) & 127;
  int stage_v_206_2 = (((sec_r001833_13_2 * 3) + pub_r001833_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_109_1 * 3) + pub_r001833_16_1) + 19) & 127;
  int stage_v_207_2 = (((stage_v_109_2 * 3) + pub_r001833_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001833_1_1 * 2) + 24) & 63;
  int stage_v_208_2 = ((pub_r001833_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001833_15_1 * 2) + 37) & 63;
  int stage_v_209_2 = ((pub_r001833_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_125_1 * 3) + pub_r001833_8_1) + 28) & 127;
  int stage_v_210_2 = (((stage_v_125_2 * 3) + pub_r001833_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_107_1 * 3) + pub_r001833_1_1) + 26) & 127;
  int stage_v_211_2 = (((stage_v_107_2 * 3) + pub_r001833_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((sec_r001833_22_1 * 3) + pub_r001833_16_1) + 41) & 127;
  int stage_v_212_2 = (((sec_r001833_22_2 * 3) + pub_r001833_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_26_1 * 3) + pub_r001833_0_1) + 26) & 127;
  int stage_v_213_2 = (((stage_v_26_2 * 3) + pub_r001833_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_53_1 * 3) + pub_r001833_11_1) + 26) & 127;
  int stage_v_214_2 = (((stage_v_53_2 * 3) + pub_r001833_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((sec_r001833_7_1 * 3) + pub_r001833_8_1) + 42) & 127;
  int stage_v_215_2 = (((sec_r001833_7_2 * 3) + pub_r001833_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_68_1 * 3) + pub_r001833_9_1) + 42) & 127;
  int stage_v_216_2 = (((stage_v_68_2 * 3) + pub_r001833_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001833_1_1 * 2) + 21) & 63;
  int stage_v_217_2 = ((pub_r001833_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_122_1 * 3) + pub_r001833_5_1) + 30) & 127;
  int stage_v_218_2 = (((stage_v_122_2 * 3) + pub_r001833_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((helper_flow_5_1 * 3) + pub_r001833_16_1) + 43) & 127;
  int stage_v_219_2 = (((helper_flow_5_2 * 3) + pub_r001833_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_100_1 * 3) + pub_r001833_15_1) + 30) & 127;
  int stage_v_220_2 = (((stage_v_100_2 * 3) + pub_r001833_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_89_1 * 3) + pub_r001833_2_1) + 6) & 127;
  int stage_v_221_2 = (((stage_v_89_2 * 3) + pub_r001833_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_68_1 * 3) + pub_r001833_4_1) + 24) & 127;
  int stage_v_222_2 = (((stage_v_68_2 * 3) + pub_r001833_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_0_1 * 3) + pub_r001833_15_1) + 9) & 127;
  int stage_v_223_2 = (((stage_v_0_2 * 3) + pub_r001833_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_15_1 * 3) + pub_r001833_4_1) + 18) & 127;
  int stage_v_224_2 = (((stage_v_15_2 * 3) + pub_r001833_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_24_1 * 3) + pub_r001833_10_1) + 36) & 127;
  int stage_v_225_2 = (((stage_v_24_2 * 3) + pub_r001833_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((sec_r001833_10_1 * 3) + pub_r001833_1_1) + 42) & 127;
  int stage_v_226_2 = (((sec_r001833_10_2 * 3) + pub_r001833_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((sec_r001833_4_1 * 3) + pub_r001833_13_1) + 3) & 127;
  int stage_v_227_2 = (((sec_r001833_4_2 * 3) + pub_r001833_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001833_13_1 * 2) + 6) & 63;
  int stage_v_228_2 = ((pub_r001833_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_219_1 * 3) + pub_r001833_9_1) + 11) & 127;
  int stage_v_229_2 = (((stage_v_219_2 * 3) + pub_r001833_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001833_12_1 * 2) + 6) & 63;
  int stage_v_230_2 = ((pub_r001833_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_156_1 * 3) + pub_r001833_15_1) + 19) & 127;
  int stage_v_231_2 = (((stage_v_156_2 * 3) + pub_r001833_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001833_13_1 * 2) + 47) & 63;
  int stage_v_232_2 = ((pub_r001833_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001833_9_1 * 2) + 26) & 63;
  int stage_v_233_2 = ((pub_r001833_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001833_3_1 * 2) + 42) & 63;
  int stage_v_234_2 = ((pub_r001833_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001833_13_1 * 2) + 44) & 63;
  int stage_v_235_2 = ((pub_r001833_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((sec_r001833_19_1 * 3) + pub_r001833_15_1) + 12) & 127;
  int stage_v_236_2 = (((sec_r001833_19_2 * 3) + pub_r001833_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001833_8_1 * 2) + 32) & 63;
  int stage_v_237_2 = ((pub_r001833_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_178_1 * 3) + pub_r001833_13_1) + 33) & 127;
  int stage_v_238_2 = (((stage_v_178_2 * 3) + pub_r001833_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((stage_v_35_1 * 3) + pub_r001833_11_1) + 11) & 127;
  int stage_v_239_2 = (((stage_v_35_2 * 3) + pub_r001833_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_100_1 * 3) + pub_r001833_10_1) + 13) & 127;
  int stage_v_240_2 = (((stage_v_100_2 * 3) + pub_r001833_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_100_1 * 3) + pub_r001833_6_1) + 26) & 127;
  int stage_v_241_2 = (((stage_v_100_2 * 3) + pub_r001833_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((sec_r001833_1_1 * 3) + pub_r001833_13_1) + 22) & 127;
  int stage_v_242_2 = (((sec_r001833_1_2 * 3) + pub_r001833_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001833_5_1 * 2) + 34) & 63;
  int stage_v_243_2 = ((pub_r001833_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_77_1 * 3) + pub_r001833_13_1) + 8) & 127;
  int stage_v_244_2 = (((stage_v_77_2 * 3) + pub_r001833_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_101_1 * 3) + pub_r001833_14_1) + 20) & 127;
  int stage_v_245_2 = (((stage_v_101_2 * 3) + pub_r001833_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001833_5_1 * 2) + 14) & 63;
  int stage_v_246_2 = ((pub_r001833_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_42_1 * 3) + pub_r001833_4_1) + 8) & 127;
  int stage_v_247_2 = (((stage_v_42_2 * 3) + pub_r001833_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001833_7_1 * 2) + 19) & 63;
  int stage_v_248_2 = ((pub_r001833_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_56_1 * 3) + pub_r001833_14_1) + 7) & 127;
  int stage_v_249_2 = (((stage_v_56_2 * 3) + pub_r001833_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001833_8_1 * 2) + 33) & 63;
  int stage_v_250_2 = ((pub_r001833_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001833_10_1 * 2) + 21) & 63;
  int stage_v_251_2 = ((pub_r001833_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((helper_flow_0_1 * 3) + pub_r001833_15_1) + 30) & 127;
  int stage_v_252_2 = (((helper_flow_0_2 * 3) + pub_r001833_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_195_1 * 3) + pub_r001833_2_1) + 12) & 127;
  int stage_v_253_2 = (((stage_v_195_2 * 3) + pub_r001833_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_26_1 * 3) + pub_r001833_2_1) + 32) & 127;
  int stage_v_254_2 = (((stage_v_26_2 * 3) + pub_r001833_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_61_1 * 3) + pub_r001833_9_1) + 43) & 127;
  int stage_v_255_2 = (((stage_v_61_2 * 3) + pub_r001833_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_85_1 * 3) + pub_r001833_15_1) + 9) & 127;
  int stage_v_256_2 = (((stage_v_85_2 * 3) + pub_r001833_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001833_9_1 * 2) + 12) & 63;
  int stage_v_257_2 = ((pub_r001833_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001833_11_1 * 2) + 21) & 63;
  int stage_v_258_2 = ((pub_r001833_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_46_1 * 3) + pub_r001833_15_1) + 28) & 127;
  int stage_v_259_2 = (((stage_v_46_2 * 3) + pub_r001833_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001833_2_1 * 2) + 16) & 63;
  int stage_v_260_2 = ((pub_r001833_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_0_1 * 3) + pub_r001833_11_1) + 38) & 127;
  int stage_v_261_2 = (((stage_v_0_2 * 3) + pub_r001833_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001833_6_1 * 2) + 16) & 63;
  int stage_v_262_2 = ((pub_r001833_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_178_1 * 3) + pub_r001833_1_1) + 30) & 127;
  int stage_v_263_2 = (((stage_v_178_2 * 3) + pub_r001833_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001833_3_1 * 2) + 27) & 63;
  int stage_v_264_2 = ((pub_r001833_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_15_1 * 3) + pub_r001833_14_1) + 39) & 127;
  int stage_v_265_2 = (((stage_v_15_2 * 3) + pub_r001833_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_184_1 * 3) + pub_r001833_0_1) + 11) & 127;
  int stage_v_266_2 = (((stage_v_184_2 * 3) + pub_r001833_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((sec_r001833_8_1 * 3) + pub_r001833_1_1) + 3) & 127;
  int stage_v_267_2 = (((sec_r001833_8_2 * 3) + pub_r001833_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_239_1 * 3) + pub_r001833_3_1) + 32) & 127;
  int stage_v_268_2 = (((stage_v_239_2 * 3) + pub_r001833_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_178_1 * 3) + pub_r001833_11_1) + 22) & 127;
  int stage_v_269_2 = (((stage_v_178_2 * 3) + pub_r001833_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001833_15_1 * 2) + 17) & 63;
  int stage_v_270_2 = ((pub_r001833_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001833_12_1 * 2) + 17) & 63;
  int stage_v_271_2 = ((pub_r001833_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_12_1 * 3) + pub_r001833_8_1) + 33) & 127;
  int stage_v_272_2 = (((stage_v_12_2 * 3) + pub_r001833_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001833_1_1 * 2) + 31) & 63;
  int stage_v_273_2 = ((pub_r001833_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_225_1 * 3) + pub_r001833_13_1) + 21) & 127;
  int stage_v_274_2 = (((stage_v_225_2 * 3) + pub_r001833_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001833_0_1 * 2) + 25) & 63;
  int stage_v_275_2 = ((pub_r001833_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_176_1 * 3) + pub_r001833_12_1) + 26) & 127;
  int stage_v_276_2 = (((stage_v_176_2 * 3) + pub_r001833_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_249_1 * 3) + pub_r001833_2_1) + 10) & 127;
  int stage_v_277_2 = (((stage_v_249_2 * 3) + pub_r001833_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_110_1 * 3) + pub_r001833_7_1) + 20) & 127;
  int stage_v_278_2 = (((stage_v_110_2 * 3) + pub_r001833_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_68_1 * 3) + pub_r001833_11_1) + 37) & 127;
  int stage_v_279_2 = (((stage_v_68_2 * 3) + pub_r001833_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((helper_flow_0_1 * 3) + pub_r001833_0_1) + 45) & 127;
  int stage_v_280_2 = (((helper_flow_0_2 * 3) + pub_r001833_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_136_1 * 3) + pub_r001833_10_1) + 36) & 127;
  int stage_v_281_2 = (((stage_v_136_2 * 3) + pub_r001833_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001833_8_1 * 2) + 37) & 63;
  int stage_v_282_2 = ((pub_r001833_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_244_1 * 3) + pub_r001833_14_1) + 36) & 127;
  int stage_v_283_2 = (((stage_v_244_2 * 3) + pub_r001833_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((sec_r001833_18_1 * 3) + pub_r001833_11_1) + 5) & 127;
  int stage_v_284_2 = (((sec_r001833_18_2 * 3) + pub_r001833_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_12_1 * 3) + pub_r001833_15_1) + 14) & 127;
  int stage_v_285_2 = (((stage_v_12_2 * 3) + pub_r001833_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001833_13_1 * 2) + 46) & 63;
  int stage_v_286_2 = ((pub_r001833_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_124_1 * 3) + pub_r001833_16_1) + 37) & 127;
  int stage_v_287_2 = (((stage_v_124_2 * 3) + pub_r001833_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_125_1 * 3) + pub_r001833_7_1) + 31) & 127;
  int stage_v_288_2 = (((stage_v_125_2 * 3) + pub_r001833_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001833_12_1 * 2) + 12) & 63;
  int stage_v_289_2 = ((pub_r001833_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001833_15_1 * 2) + 18) & 63;
  int stage_v_290_2 = ((pub_r001833_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001833_8_1 * 2) + 5) & 63;
  int stage_v_291_2 = ((pub_r001833_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001833_9_1 * 2) + 45) & 63;
  int stage_v_292_2 = ((pub_r001833_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001833_10_1 * 2) + 49) & 63;
  int stage_v_293_2 = ((pub_r001833_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_189_1 * 3) + pub_r001833_8_1) + 10) & 127;
  int stage_v_294_2 = (((stage_v_189_2 * 3) + pub_r001833_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_182_1 * 3) + pub_r001833_15_1) + 29) & 127;
  int stage_v_295_2 = (((stage_v_182_2 * 3) + pub_r001833_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_134_1 * 3) + pub_r001833_11_1) + 26) & 127;
  int stage_v_296_2 = (((stage_v_134_2 * 3) + pub_r001833_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001833_6_1 * 2) + 28) & 63;
  int stage_v_297_2 = ((pub_r001833_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_159_1 * 3) + pub_r001833_16_1) + 8) & 127;
  int stage_v_298_2 = (((stage_v_159_2 * 3) + pub_r001833_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001833_2_1 * 2) + 20) & 63;
  int stage_v_299_2 = ((pub_r001833_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_7_1 * 3) + pub_r001833_14_1) + 35) & 127;
  int stage_v_300_2 = (((stage_v_7_2 * 3) + pub_r001833_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_174_1 * 3) + pub_r001833_11_1) + 12) & 127;
  int stage_v_301_2 = (((stage_v_174_2 * 3) + pub_r001833_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001833_4_1 * 2) + 36) & 63;
  int stage_v_302_2 = ((pub_r001833_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_159_1 * 3) + pub_r001833_13_1) + 16) & 127;
  int stage_v_303_2 = (((stage_v_159_2 * 3) + pub_r001833_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001833_14_1 * 2) + 46) & 63;
  int stage_v_304_2 = ((pub_r001833_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_215_1 * 3) + pub_r001833_16_1) + 45) & 127;
  int stage_v_305_2 = (((stage_v_215_2 * 3) + pub_r001833_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001833_1_1 * 2) + 12) & 63;
  int stage_v_306_2 = ((pub_r001833_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001833_14_1 * 2) + 41) & 63;
  int stage_v_307_2 = ((pub_r001833_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((sec_r001833_19_1 * 3) + pub_r001833_4_1) + 19) & 127;
  int stage_v_308_2 = (((sec_r001833_19_2 * 3) + pub_r001833_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_211_1 * 3) + pub_r001833_4_1) + 14) & 127;
  int stage_v_309_2 = (((stage_v_211_2 * 3) + pub_r001833_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((sec_r001833_12_1 * 3) + pub_r001833_14_1) + 18) & 127;
  int stage_v_310_2 = (((sec_r001833_12_2 * 3) + pub_r001833_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_127_1 * 3) + pub_r001833_3_1) + 24) & 127;
  int stage_v_311_2 = (((stage_v_127_2 * 3) + pub_r001833_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001833_12_1 * 2) + 47) & 63;
  int stage_v_312_2 = ((pub_r001833_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001833_15_1 * 2) + 24) & 63;
  int stage_v_313_2 = ((pub_r001833_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001833_7_1 * 2) + 10) & 63;
  int stage_v_314_2 = ((pub_r001833_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_171_1 * 3) + pub_r001833_0_1) + 14) & 127;
  int stage_v_315_2 = (((stage_v_171_2 * 3) + pub_r001833_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_229_1 * 3) + pub_r001833_0_1) + 21) & 127;
  int stage_v_316_2 = (((stage_v_229_2 * 3) + pub_r001833_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_253_1 * 3) + pub_r001833_11_1) + 43) & 127;
  int stage_v_317_2 = (((stage_v_253_2 * 3) + pub_r001833_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_72_1 * 3) + pub_r001833_2_1) + 28) & 127;
  int stage_v_318_2 = (((stage_v_72_2 * 3) + pub_r001833_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_156_1 * 3) + pub_r001833_3_1) + 27) & 127;
  int stage_v_319_2 = (((stage_v_156_2 * 3) + pub_r001833_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_221_1 * 3) + pub_r001833_1_1) + 25) & 127;
  int stage_v_320_2 = (((stage_v_221_2 * 3) + pub_r001833_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_25_1 * 3) + pub_r001833_14_1) + 16) & 127;
  int stage_v_321_2 = (((stage_v_25_2 * 3) + pub_r001833_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_151_1 * 3) + pub_r001833_2_1) + 39) & 127;
  int stage_v_322_2 = (((stage_v_151_2 * 3) + pub_r001833_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001833_0_1 * 2) + 49) & 63;
  int stage_v_323_2 = ((pub_r001833_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_133_1 * 3) + pub_r001833_8_1) + 6) & 127;
  int stage_v_324_2 = (((stage_v_133_2 * 3) + pub_r001833_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001833_3_1 * 2) + 43) & 63;
  int stage_v_325_2 = ((pub_r001833_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001833_13_1 * 2) + 21) & 63;
  int stage_v_326_2 = ((pub_r001833_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001833_14_1 * 2) + 40) & 63;
  int stage_v_327_2 = ((pub_r001833_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001833_1_1 * 2) + 22) & 63;
  int stage_v_328_2 = ((pub_r001833_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001833_11_1 * 2) + 15) & 63;
  int stage_v_329_2 = ((pub_r001833_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001833_14_1 * 2) + 21) & 63;
  int stage_v_330_2 = ((pub_r001833_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_29_1 * 3) + pub_r001833_1_1) + 42) & 127;
  int stage_v_331_2 = (((stage_v_29_2 * 3) + pub_r001833_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_30_1 * 3) + pub_r001833_13_1) + 22) & 127;
  int stage_v_332_2 = (((stage_v_30_2 * 3) + pub_r001833_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001833_1_1 * 2) + 20) & 63;
  int stage_v_333_2 = ((pub_r001833_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001833_14_1 * 2) + 47) & 63;
  int stage_v_334_2 = ((pub_r001833_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001833_4_1 * 2) + 47) & 63;
  int stage_v_335_2 = ((pub_r001833_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001833_5_1 * 2) + 28) & 63;
  int stage_v_336_2 = ((pub_r001833_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001833_16_1 * 2) + 25) & 63;
  int stage_v_337_2 = ((pub_r001833_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001833_3_1 * 2) + 6) & 63;
  int stage_v_338_2 = ((pub_r001833_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001833_12_1 * 2) + 49) & 63;
  int stage_v_339_2 = ((pub_r001833_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_61_1 * 3) + pub_r001833_14_1) + 38) & 127;
  int stage_v_340_2 = (((stage_v_61_2 * 3) + pub_r001833_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((helper_flow_5_1 * 3) + pub_r001833_1_1) + 6) & 127;
  int stage_v_341_2 = (((helper_flow_5_2 * 3) + pub_r001833_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_288_1 * 3) + pub_r001833_9_1) + 33) & 127;
  int stage_v_342_2 = (((stage_v_288_2 * 3) + pub_r001833_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((helper_flow_4_1 * 3) + pub_r001833_11_1) + 40) & 127;
  int stage_v_343_2 = (((helper_flow_4_2 * 3) + pub_r001833_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001833_6_1 * 2) + 26) & 63;
  int stage_v_344_2 = ((pub_r001833_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_34_1 * 3) + pub_r001833_3_1) + 35) & 127;
  int stage_v_345_2 = (((stage_v_34_2 * 3) + pub_r001833_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_213_1 * 3) + pub_r001833_13_1) + 21) & 127;
  int stage_v_346_2 = (((stage_v_213_2 * 3) + pub_r001833_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001833_8_1 * 2) + 7) & 63;
  int stage_v_347_2 = ((pub_r001833_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_85_1 * 3) + pub_r001833_4_1) + 41) & 127;
  int stage_v_348_2 = (((stage_v_85_2 * 3) + pub_r001833_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001833_16_1 * 2) + 21) & 63;
  int stage_v_349_2 = ((pub_r001833_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_99_1 * 3) + pub_r001833_14_1) + 17) & 127;
  int stage_v_350_2 = (((stage_v_99_2 * 3) + pub_r001833_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001833_15_1 * 2) + 8) & 63;
  int stage_v_351_2 = ((pub_r001833_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001833_7_1 * 2) + 9) & 63;
  int stage_v_352_2 = ((pub_r001833_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001833_15_1 * 2) + 9) & 63;
  int stage_v_353_2 = ((pub_r001833_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_324_1 * 3) + pub_r001833_16_1) + 45) & 127;
  int stage_v_354_2 = (((stage_v_324_2 * 3) + pub_r001833_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_22_1 * 3) + pub_r001833_15_1) + 5) & 127;
  int stage_v_355_2 = (((stage_v_22_2 * 3) + pub_r001833_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_183_1 * 3) + pub_r001833_5_1) + 42) & 127;
  int stage_v_356_2 = (((stage_v_183_2 * 3) + pub_r001833_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001833_7_1 * 2) + 14) & 63;
  int stage_v_357_2 = ((pub_r001833_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_231_1 * 3) + pub_r001833_13_1) + 39) & 127;
  int stage_v_358_2 = (((stage_v_231_2 * 3) + pub_r001833_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001833_7_1 * 2) + 25) & 63;
  int stage_v_359_2 = ((pub_r001833_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_269_1 * 3) + pub_r001833_0_1) + 40) & 127;
  int stage_v_360_2 = (((stage_v_269_2 * 3) + pub_r001833_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((sec_r001833_23_1 * 3) + pub_r001833_12_1) + 14) & 127;
  int stage_v_361_2 = (((sec_r001833_23_2 * 3) + pub_r001833_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001833_3_1 * 2) + 11) & 63;
  int stage_v_362_2 = ((pub_r001833_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_57_1 * 3) + pub_r001833_0_1) + 7) & 127;
  int stage_v_363_2 = (((stage_v_57_2 * 3) + pub_r001833_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001833_2_1 * 2) + 9) & 63;
  int stage_v_364_2 = ((pub_r001833_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001833_7_1 * 2) + 26) & 63;
  int stage_v_365_2 = ((pub_r001833_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_169_1 * 3) + pub_r001833_4_1) + 30) & 127;
  int stage_v_366_2 = (((stage_v_169_2 * 3) + pub_r001833_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_350_1 * 3) + pub_r001833_1_1) + 38) & 127;
  int stage_v_367_2 = (((stage_v_350_2 * 3) + pub_r001833_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001833_13_1 * 2) + 23) & 63;
  int stage_v_368_2 = ((pub_r001833_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_56_1 * 3) + pub_r001833_10_1) + 45) & 127;
  int stage_v_369_2 = (((stage_v_56_2 * 3) + pub_r001833_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_348_1 * 3) + pub_r001833_6_1) + 19) & 127;
  int stage_v_370_2 = (((stage_v_348_2 * 3) + pub_r001833_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_285_1 * 3) + pub_r001833_5_1) + 11) & 127;
  int stage_v_371_2 = (((stage_v_285_2 * 3) + pub_r001833_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_239_1 * 3) + pub_r001833_3_1) + 25) & 127;
  int stage_v_372_2 = (((stage_v_239_2 * 3) + pub_r001833_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_315_1 * 3) + pub_r001833_0_1) + 18) & 127;
  int stage_v_373_2 = (((stage_v_315_2 * 3) + pub_r001833_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_369_1 * 3) + pub_r001833_10_1) + 26) & 127;
  int stage_v_374_2 = (((stage_v_369_2 * 3) + pub_r001833_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = ((pub_r001833_16_1 * 2) + 28) & 63;
  int stage_v_375_2 = ((pub_r001833_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = (((stage_v_229_1 * 3) + pub_r001833_0_1) + 5) & 127;
  int stage_v_376_2 = (((stage_v_229_2 * 3) + pub_r001833_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_169_1 * 3) + pub_r001833_11_1) + 41) & 127;
  int stage_v_377_2 = (((stage_v_169_2 * 3) + pub_r001833_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_253_1 * 3) + pub_r001833_13_1) + 4) & 127;
  int stage_v_378_2 = (((stage_v_253_2 * 3) + pub_r001833_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((helper_flow_1_1 * 3) + pub_r001833_14_1) + 19) & 127;
  int stage_v_379_2 = (((helper_flow_1_2 * 3) + pub_r001833_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_195_1 * 3) + pub_r001833_16_1) + 45) & 127;
  int stage_v_380_2 = (((stage_v_195_2 * 3) + pub_r001833_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001833_16_1 * 2) + 24) & 63;
  int stage_v_381_2 = ((pub_r001833_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_315_1 * 3) + pub_r001833_5_1) + 15) & 127;
  int stage_v_382_2 = (((stage_v_315_2 * 3) + pub_r001833_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_107_1 * 3) + pub_r001833_11_1) + 8) & 127;
  int stage_v_383_2 = (((stage_v_107_2 * 3) + pub_r001833_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001833_8_1 * 2) + 40) & 63;
  int stage_v_384_2 = ((pub_r001833_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001833_2_1 * 2) + 16) & 63;
  int stage_v_385_2 = ((pub_r001833_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_14_1 * 3) + pub_r001833_14_1) + 14) & 127;
  int stage_v_386_2 = (((stage_v_14_2 * 3) + pub_r001833_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = ((pub_r001833_8_1 * 2) + 46) & 63;
  int stage_v_387_2 = ((pub_r001833_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001833_3_1 * 2) + 32) & 63;
  int stage_v_388_2 = ((pub_r001833_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_89_1 * 3) + pub_r001833_8_1) + 43) & 127;
  int stage_v_389_2 = (((stage_v_89_2 * 3) + pub_r001833_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001833_16_1 * 2) + 29) & 63;
  int stage_v_390_2 = ((pub_r001833_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001833_16_1 * 2) + 28) & 63;
  int stage_v_391_2 = ((pub_r001833_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001833_9_1 * 2) + 8) & 63;
  int stage_v_392_2 = ((pub_r001833_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001833_2_1 * 2) + 25) & 63;
  int stage_v_393_2 = ((pub_r001833_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001833_4_1 * 2) + 41) & 63;
  int stage_v_394_2 = ((pub_r001833_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_61_1 * 3) + pub_r001833_4_1) + 31) & 127;
  int stage_v_395_2 = (((stage_v_61_2 * 3) + pub_r001833_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001833_7_1 == pub_r001833_7_2);
  __CPROVER_assume(pub_r001833_13_1 == pub_r001833_13_2);
  __CPROVER_assume(sec_r001833_4_1 != sec_r001833_4_2);
  __CPROVER_assume(sec_r001833_5_1 != sec_r001833_5_2);
  __CPROVER_assume(sec_r001833_20_1 != sec_r001833_20_2);
  __CPROVER_assume(pub_r001833_16_1 == pub_r001833_16_2);
  __CPROVER_assume(sec_r001833_14_1 != sec_r001833_14_2);
  __CPROVER_assume(sec_r001833_22_1 != sec_r001833_22_2);
  __CPROVER_assume(sec_r001833_1_1 != sec_r001833_1_2);
  __CPROVER_assume(sec_r001833_15_1 != sec_r001833_15_2);
  __CPROVER_assume(pub_r001833_5_1 == pub_r001833_5_2);
  __CPROVER_assume(sec_r001833_9_1 != sec_r001833_9_2);
  __CPROVER_assume(sec_r001833_10_1 != sec_r001833_10_2);
  __CPROVER_assume(pub_r001833_0_1 == pub_r001833_0_2);
  __CPROVER_assume(pub_r001833_12_1 == pub_r001833_12_2);
  __CPROVER_assume(sec_r001833_23_1 != sec_r001833_23_2);
  __CPROVER_assume(sec_r001833_6_1 != sec_r001833_6_2);
  __CPROVER_assume(sec_r001833_19_1 != sec_r001833_19_2);
  __CPROVER_assume(sec_r001833_21_1 != sec_r001833_21_2);
  __CPROVER_assume(pub_r001833_2_1 == pub_r001833_2_2);
  __CPROVER_assume(pub_r001833_14_1 == pub_r001833_14_2);
  __CPROVER_assume(pub_r001833_10_1 == pub_r001833_10_2);
  __CPROVER_assume(pub_r001833_8_1 == pub_r001833_8_2);
  __CPROVER_assume(pub_r001833_15_1 == pub_r001833_15_2);
  __CPROVER_assume(sec_r001833_12_1 != sec_r001833_12_2);
  __CPROVER_assume(pub_r001833_3_1 == pub_r001833_3_2);
  __CPROVER_assume(sec_r001833_16_1 != sec_r001833_16_2);
  __CPROVER_assume(sec_r001833_11_1 != sec_r001833_11_2);
  __CPROVER_assume(sec_r001833_0_1 != sec_r001833_0_2);
  __CPROVER_assume(pub_r001833_9_1 == pub_r001833_9_2);
  __CPROVER_assume(sec_r001833_8_1 != sec_r001833_8_2);
  __CPROVER_assume(sec_r001833_7_1 != sec_r001833_7_2);
  __CPROVER_assume(pub_r001833_4_1 == pub_r001833_4_2);
  __CPROVER_assume(sec_r001833_18_1 != sec_r001833_18_2);
  __CPROVER_assume(sec_r001833_17_1 != sec_r001833_17_2);
  __CPROVER_assume(pub_r001833_6_1 == pub_r001833_6_2);
  __CPROVER_assume(sec_r001833_2_1 != sec_r001833_2_2);
  __CPROVER_assume(sec_r001833_13_1 != sec_r001833_13_2);
  __CPROVER_assume(sec_r001833_3_1 != sec_r001833_3_2);
  __CPROVER_assume(pub_r001833_1_1 == pub_r001833_1_2);
  __CPROVER_assume(pub_r001833_11_1 == pub_r001833_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.state == st_var_1_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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
}


