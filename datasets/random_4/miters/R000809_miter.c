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
struct SensorNode_R000809_913_0
{
  short offset;
  short status;
  short threshold;
  int buffer[3];
};
struct FilterState_R000809_913_1
{
  unsigned char damping;
  short mode;
  unsigned char prev_out;
  unsigned char cutoff;
  short gain_db;
  int prev_in;
  int buffer[3];
};
union TelemetryField_R000809_913_0
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
void fn_R000809_913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_33_1 = local_arr_1[aux_1 % 3];
  int scale_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_41_1) & 63;
  aux_2 = (aux_2 + margin_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_39_1 = 0;
  int anchor_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_39_1 = ((anchor_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_39_2 = ((anchor_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_39_1) & 127;
    acc_2 = (acc_2 + anchor_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_33_1 == scale_33_2);
  assert(margin_41_1 == margin_41_2);
  assert(anchor_39_1 == anchor_39_2);
}

int fn_R000809_913_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int scale_33 = local_arr[aux % 3];
  acc = (acc + (scale_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_41) & 63;
  acc ^= aux;
  int anchor_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_39 = ((anchor_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000809_913_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_70_1)
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

  switch (margin_70_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_62_1 = local_arr_1[aux_1 % 3];
  int quantum_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_70_1 == margin_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_62_1 == quantum_62_2);
}

int fn_R000809_913_1(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_70 = (aux + st.buffer[1]) & 3;
  switch (margin_70)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_62 = local_arr[aux % 3];
  acc = (acc + (quantum_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int checksum_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_86_1) & 63;
  aux_2 = (aux_2 + checksum_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_19_1 = local_arr_1[aux_1 % 3];
  int window_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_19_2 * 2)) & 127;
  int window_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_89_1)
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

  switch (window_89_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_86_1 == checksum_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_19_1 == window_19_2);
  assert(window_89_1 == window_89_2);
}

int fn_R000809_913_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int checksum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_19 = local_arr[aux % 3];
  acc = (acc + (window_19 * 2)) & 127;
  int window_89 = (aux + st.buffer[1]) & 3;
  switch (window_89)
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

void fn_R000809_913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_24_1 = 0;
  int checksum_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_24_1 = ((checksum_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_24_2 = ((checksum_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_24_1) & 127;
    acc_2 = (acc_2 + checksum_24_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_50_1 = local_arr_1[aux_1 % 3];
  int bound_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_50_2 * 2)) & 127;
  int checksum_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_83_1) & 63;
  aux_2 = (aux_2 + checksum_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_67_1)
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

  switch (tracker_67_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_24_1 == checksum_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_50_1 == bound_50_2);
  assert(checksum_83_1 == checksum_83_2);
  assert(tracker_67_1 == tracker_67_2);
}

int fn_R000809_913_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_24 = ((checksum_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_24) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_50 = local_arr[aux % 3];
  acc = (acc + (bound_50 * 2)) & 127;
  int checksum_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_83) & 63;
  acc ^= aux;
  int tracker_67 = (aux + st.buffer[1]) & 3;
  switch (tracker_67)
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

void fn_R000809_913_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_47_1) & 63;
  aux_2 = (aux_2 + sample_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_61_1 > 49)
  {
    acc_1 = ((acc_1 + (quotient_61_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_61_2 > 49)
  {
    acc_2 = ((acc_2 + (quotient_61_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_73_1 = 0;
  int bound_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_73_1 = ((bound_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_73_2 = ((bound_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_73_1) & 127;
    acc_2 = (acc_2 + bound_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_47_1 == sample_47_2);
  assert(quotient_61_1 == quotient_61_2);
  assert(bound_73_1 == bound_73_2);
}

int fn_R000809_913_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_47) & 63;
  acc ^= aux;
  int quotient_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_61 > 49)
  {
    acc = ((acc + (quotient_61 * 2)) + 5) & 127;
    aux ^= quotient_61 & 15;
  }
  else
  {
    acc = ((acc - quotient_61) + 11) & 127;
    aux += 3;
  }
  int bound_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_73 = ((bound_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000809_913_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_41_1 = 0;
  int segment_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_41_1 = ((segment_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_41_2 = ((segment_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_41_1) & 127;
    acc_2 = (acc_2 + segment_41_2) & 127;
  }

  int damping_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_54_1 > 25)
  {
    acc_1 = ((acc_1 + (damping_54_1 * 2)) + 5) & 127;
    aux_1 ^= damping_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_54_2 > 25)
  {
    acc_2 = ((acc_2 + (damping_54_2 * 2)) + 5) & 127;
    aux_2 ^= damping_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_34_1) & 63;
  aux_2 = (aux_2 + delta_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_41_1 == segment_41_2);
  assert(damping_54_1 == damping_54_2);
  assert(delta_34_1 == delta_34_2);
}

int fn_R000809_913_5(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_41 = ((segment_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_41) & 127;
  }

  int damping_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_54 > 25)
  {
    acc = ((acc + (damping_54 * 2)) + 5) & 127;
    aux ^= damping_54 & 15;
  }
  else
  {
    acc = ((acc - damping_54) + 11) & 127;
    aux += 3;
  }
  int delta_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000809_913_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_90_1 = local_arr_1[aux_1 % 3];
  int index_reg_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_90_2 * 2)) & 127;
  int pivot_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_30_1 > 10)
  {
    acc_1 = ((acc_1 + (pivot_30_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_30_2 > 10)
  {
    acc_2 = ((acc_2 + (pivot_30_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_90_1) & 63;
  aux_2 = (aux_2 + checksum_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
  assert(pivot_30_1 == pivot_30_2);
  assert(checksum_90_1 == checksum_90_2);
}

int fn_R000809_913_6(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int index_reg_90 = local_arr[aux % 3];
  acc = (acc + (index_reg_90 * 2)) & 127;
  int pivot_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_30 > 10)
  {
    acc = ((acc + (pivot_30 * 2)) + 5) & 127;
    aux ^= pivot_30 & 15;
  }
  else
  {
    acc = ((acc - pivot_30) + 11) & 127;
    aux += 3;
  }
  int checksum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_90) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_59_1)
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

  switch (anchor_59_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_23_1 = local_arr_1[aux_1 % 3];
  int scale_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_59_1 == anchor_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_23_1 == scale_23_2);
}

int fn_R000809_913_7(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_59 = (aux + st.buffer[1]) & 3;
  switch (anchor_59)
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

  int local_arr[3] = {4, 9, 15};
  int scale_23 = local_arr[aux % 3];
  acc = (acc + (scale_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_63_1 > 19)
  {
    acc_1 = ((acc_1 + (coefficient_63_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_63_2 > 19)
  {
    acc_2 = ((acc_2 + (coefficient_63_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_10_1 = 0;
  int stride_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_10_1 = ((stride_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_10_2 = ((stride_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_10_1) & 127;
    acc_2 = (acc_2 + stride_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_63_1 == coefficient_63_2);
  assert(stride_10_1 == stride_10_2);
}

int fn_R000809_913_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_63 > 19)
  {
    acc = ((acc + (coefficient_63 * 2)) + 5) & 127;
    aux ^= coefficient_63 & 15;
  }
  else
  {
    acc = ((acc - coefficient_63) + 11) & 127;
    aux += 3;
  }
  int stride_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_10 = ((stride_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000809_913_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int bound_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_24_1) & 63;
  aux_2 = (aux_2 + bound_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_53_1)
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

  switch (quantum_53_2)
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

  int checksum_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_61_1 > 13)
  {
    acc_1 = ((acc_1 + (checksum_61_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_61_2 > 13)
  {
    acc_2 = ((acc_2 + (checksum_61_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_61_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_24_1 == bound_24_2);
  assert(quantum_53_1 == quantum_53_2);
  assert(checksum_61_1 == checksum_61_2);
}

int fn_R000809_913_9(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int bound_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_24) & 63;
  acc ^= aux;
  int quantum_53 = (aux + st.buffer[1]) & 3;
  switch (quantum_53)
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

  int checksum_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_61 > 13)
  {
    acc = ((acc + (checksum_61 * 2)) + 5) & 127;
    aux ^= checksum_61 & 15;
  }
  else
  {
    acc = ((acc - checksum_61) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_58_1 = 0;
  int segment_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_58_1 = ((segment_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_58_2 = ((segment_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_58_1) & 127;
    acc_2 = (acc_2 + segment_58_2) & 127;
  }

  int bound_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_93_1)
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

  switch (bound_93_2)
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
  int offset_24_1 = local_arr_1[aux_1 % 3];
  int offset_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(bound_93_1 == bound_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_24_1 == offset_24_2);
}

int fn_R000809_913_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_58 = ((segment_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_58) & 127;
  }

  int bound_93 = (aux + st.buffer[1]) & 3;
  switch (bound_93)
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
  int offset_24 = local_arr[aux % 3];
  acc = (acc + (offset_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int coefficient_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_76_1 > 28)
  {
    acc_1 = ((acc_1 + (coefficient_76_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_76_2 > 28)
  {
    acc_2 = ((acc_2 + (coefficient_76_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_76_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_48_1) & 63;
  aux_2 = (aux_2 + phase_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_76_1 == coefficient_76_2);
  assert(phase_48_1 == phase_48_2);
}

int fn_R000809_913_11(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int coefficient_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_76 > 28)
  {
    acc = ((acc + (coefficient_76 * 2)) + 5) & 127;
    aux ^= coefficient_76 & 15;
  }
  else
  {
    acc = ((acc - coefficient_76) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000809_913_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_92_1)
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

  switch (coefficient_92_2)
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

  int index_reg_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_67_1 > 31)
  {
    acc_1 = ((acc_1 + (index_reg_67_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_67_2 > 31)
  {
    acc_2 = ((acc_2 + (index_reg_67_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  assert(index_reg_67_1 == index_reg_67_2);
}

int fn_R000809_913_12(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_92 = (aux + st.buffer[1]) & 3;
  switch (coefficient_92)
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

  int index_reg_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_67 > 31)
  {
    acc = ((acc + (index_reg_67 * 2)) + 5) & 127;
    aux ^= index_reg_67 & 15;
  }
  else
  {
    acc = ((acc - index_reg_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000809_913_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st_1 = {0};
  struct FilterState_R000809_913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int bound_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_44_1 > 29)
  {
    acc_1 = ((acc_1 + (bound_44_1 * 2)) + 5) & 127;
    aux_1 ^= bound_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_44_2 > 29)
  {
    acc_2 = ((acc_2 + (bound_44_2 * 2)) + 5) & 127;
    aux_2 ^= bound_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_51_1 = local_arr_1[aux_1 % 3];
  int tally_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_51_1 == tally_51_2);
}

int fn_R000809_913_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000809_913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int bound_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_44 > 29)
  {
    acc = ((acc + (bound_44 * 2)) + 5) & 127;
    aux ^= bound_44 & 15;
  }
  else
  {
    acc = ((acc - bound_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_51 = local_arr[aux % 3];
  acc = (acc + (tally_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000809_913_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st_1 = {0};
  struct SensorNode_R000809_913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_79_1 = 0;
  int bound_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_79_1 = ((bound_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_79_2 = ((bound_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_79_1) & 127;
    acc_2 = (acc_2 + bound_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_79_1 == bound_79_2);
}

int fn_R000809_913_14(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000809_913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_79 = ((bound_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_79) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000809_0_1;
  int sec_r000809_0_2;
  int sec_r000809_1_1;
  int sec_r000809_1_2;
  int sec_r000809_2_1;
  int sec_r000809_2_2;
  int sec_r000809_3_1;
  int sec_r000809_3_2;
  int sec_r000809_4_1;
  int sec_r000809_4_2;
  int sec_r000809_5_1;
  int sec_r000809_5_2;
  int sec_r000809_6_1;
  int sec_r000809_6_2;
  int sec_r000809_7_1;
  int sec_r000809_7_2;
  int sec_r000809_8_1;
  int sec_r000809_8_2;
  int sec_r000809_9_1;
  int sec_r000809_9_2;
  int sec_r000809_10_1;
  int sec_r000809_10_2;
  int sec_r000809_11_1;
  int sec_r000809_11_2;
  int sec_r000809_12_1;
  int sec_r000809_12_2;
  int sec_r000809_13_1;
  int sec_r000809_13_2;
  int sec_r000809_14_1;
  int sec_r000809_14_2;
  int sec_r000809_15_1;
  int sec_r000809_15_2;
  int sec_r000809_16_1;
  int sec_r000809_16_2;
  int sec_r000809_17_1;
  int sec_r000809_17_2;
  int pub_r000809_0_1;
  int pub_r000809_0_2;
  int pub_r000809_1_1;
  int pub_r000809_1_2;
  int pub_r000809_2_1;
  int pub_r000809_2_2;
  int pub_r000809_3_1;
  int pub_r000809_3_2;
  int pub_r000809_4_1;
  int pub_r000809_4_2;
  int pub_r000809_5_1;
  int pub_r000809_5_2;
  int pub_r000809_6_1;
  int pub_r000809_6_2;
  int pub_r000809_7_1;
  int pub_r000809_7_2;
  int pub_r000809_8_1;
  int pub_r000809_8_2;
  int pub_r000809_9_1;
  int pub_r000809_9_2;
  int pub_r000809_10_1;
  int pub_r000809_10_2;
  int pub_r000809_11_1;
  int pub_r000809_11_2;
  int pub_r000809_12_1;
  int pub_r000809_12_2;
  int pub_r000809_13_1;
  int pub_r000809_13_2;
  int pub_r000809_14_1;
  int pub_r000809_14_2;
  int pub_r000809_15_1;
  int pub_r000809_15_2;
  int pub_r000809_16_1;
  int pub_r000809_16_2;
  int pub_r000809_17_1;
  int pub_r000809_17_2;
  int pub_r000809_18_1;
  int pub_r000809_18_2;
  int pub_r000809_19_1;
  int pub_r000809_19_2;
  int pub_r000809_20_1;
  int pub_r000809_20_2;
  int pub_r000809_21_1;
  int pub_r000809_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000809_0_1 >= (-100)) && (pub_r000809_0_1 <= 100));
  __CPROVER_assume((pub_r000809_0_2 >= (-100)) && (pub_r000809_0_2 <= 100));
  __CPROVER_assume((pub_r000809_1_1 >= (-100)) && (pub_r000809_1_1 <= 100));
  __CPROVER_assume((pub_r000809_1_2 >= (-100)) && (pub_r000809_1_2 <= 100));
  __CPROVER_assume((pub_r000809_2_1 >= (-100)) && (pub_r000809_2_1 <= 100));
  __CPROVER_assume((pub_r000809_2_2 >= (-100)) && (pub_r000809_2_2 <= 100));
  __CPROVER_assume((pub_r000809_3_1 >= (-100)) && (pub_r000809_3_1 <= 100));
  __CPROVER_assume((pub_r000809_3_2 >= (-100)) && (pub_r000809_3_2 <= 100));
  __CPROVER_assume((pub_r000809_4_1 >= (-100)) && (pub_r000809_4_1 <= 100));
  __CPROVER_assume((pub_r000809_4_2 >= (-100)) && (pub_r000809_4_2 <= 100));
  __CPROVER_assume((pub_r000809_5_1 >= (-100)) && (pub_r000809_5_1 <= 100));
  __CPROVER_assume((pub_r000809_5_2 >= (-100)) && (pub_r000809_5_2 <= 100));
  __CPROVER_assume((pub_r000809_6_1 >= (-100)) && (pub_r000809_6_1 <= 100));
  __CPROVER_assume((pub_r000809_6_2 >= (-100)) && (pub_r000809_6_2 <= 100));
  __CPROVER_assume((pub_r000809_7_1 >= (-100)) && (pub_r000809_7_1 <= 100));
  __CPROVER_assume((pub_r000809_7_2 >= (-100)) && (pub_r000809_7_2 <= 100));
  __CPROVER_assume((pub_r000809_8_1 >= (-100)) && (pub_r000809_8_1 <= 100));
  __CPROVER_assume((pub_r000809_8_2 >= (-100)) && (pub_r000809_8_2 <= 100));
  __CPROVER_assume((pub_r000809_9_1 >= (-100)) && (pub_r000809_9_1 <= 100));
  __CPROVER_assume((pub_r000809_9_2 >= (-100)) && (pub_r000809_9_2 <= 100));
  __CPROVER_assume((pub_r000809_10_1 >= (-100)) && (pub_r000809_10_1 <= 100));
  __CPROVER_assume((pub_r000809_10_2 >= (-100)) && (pub_r000809_10_2 <= 100));
  __CPROVER_assume((pub_r000809_11_1 >= (-100)) && (pub_r000809_11_1 <= 100));
  __CPROVER_assume((pub_r000809_11_2 >= (-100)) && (pub_r000809_11_2 <= 100));
  __CPROVER_assume((pub_r000809_12_1 >= (-100)) && (pub_r000809_12_1 <= 100));
  __CPROVER_assume((pub_r000809_12_2 >= (-100)) && (pub_r000809_12_2 <= 100));
  __CPROVER_assume((pub_r000809_13_1 >= (-100)) && (pub_r000809_13_1 <= 100));
  __CPROVER_assume((pub_r000809_13_2 >= (-100)) && (pub_r000809_13_2 <= 100));
  __CPROVER_assume((pub_r000809_14_1 >= (-100)) && (pub_r000809_14_1 <= 100));
  __CPROVER_assume((pub_r000809_14_2 >= (-100)) && (pub_r000809_14_2 <= 100));
  __CPROVER_assume((pub_r000809_15_1 >= (-100)) && (pub_r000809_15_1 <= 100));
  __CPROVER_assume((pub_r000809_15_2 >= (-100)) && (pub_r000809_15_2 <= 100));
  __CPROVER_assume((pub_r000809_16_1 >= (-100)) && (pub_r000809_16_1 <= 100));
  __CPROVER_assume((pub_r000809_16_2 >= (-100)) && (pub_r000809_16_2 <= 100));
  __CPROVER_assume((pub_r000809_17_1 >= (-100)) && (pub_r000809_17_1 <= 100));
  __CPROVER_assume((pub_r000809_17_2 >= (-100)) && (pub_r000809_17_2 <= 100));
  __CPROVER_assume((pub_r000809_18_1 >= (-100)) && (pub_r000809_18_1 <= 100));
  __CPROVER_assume((pub_r000809_18_2 >= (-100)) && (pub_r000809_18_2 <= 100));
  __CPROVER_assume((pub_r000809_19_1 >= (-100)) && (pub_r000809_19_1 <= 100));
  __CPROVER_assume((pub_r000809_19_2 >= (-100)) && (pub_r000809_19_2 <= 100));
  __CPROVER_assume((pub_r000809_20_1 >= (-100)) && (pub_r000809_20_1 <= 100));
  __CPROVER_assume((pub_r000809_20_2 >= (-100)) && (pub_r000809_20_2 <= 100));
  __CPROVER_assume((pub_r000809_21_1 >= (-100)) && (pub_r000809_21_1 <= 100));
  __CPROVER_assume((pub_r000809_21_2 >= (-100)) && (pub_r000809_21_2 <= 100));
  __CPROVER_assume((sec_r000809_0_1 >= 0) && (sec_r000809_0_1 <= 255));
  __CPROVER_assume((sec_r000809_0_2 >= 0) && (sec_r000809_0_2 <= 255));
  __CPROVER_assume((sec_r000809_1_1 >= 0) && (sec_r000809_1_1 <= 255));
  __CPROVER_assume((sec_r000809_1_2 >= 0) && (sec_r000809_1_2 <= 255));
  __CPROVER_assume((sec_r000809_2_1 >= 0) && (sec_r000809_2_1 <= 255));
  __CPROVER_assume((sec_r000809_2_2 >= 0) && (sec_r000809_2_2 <= 255));
  __CPROVER_assume((sec_r000809_3_1 >= 0) && (sec_r000809_3_1 <= 255));
  __CPROVER_assume((sec_r000809_3_2 >= 0) && (sec_r000809_3_2 <= 255));
  __CPROVER_assume((sec_r000809_4_1 >= 0) && (sec_r000809_4_1 <= 255));
  __CPROVER_assume((sec_r000809_4_2 >= 0) && (sec_r000809_4_2 <= 255));
  __CPROVER_assume((sec_r000809_5_1 >= 0) && (sec_r000809_5_1 <= 255));
  __CPROVER_assume((sec_r000809_5_2 >= 0) && (sec_r000809_5_2 <= 255));
  __CPROVER_assume((sec_r000809_6_1 >= 0) && (sec_r000809_6_1 <= 255));
  __CPROVER_assume((sec_r000809_6_2 >= 0) && (sec_r000809_6_2 <= 255));
  __CPROVER_assume((sec_r000809_7_1 >= 0) && (sec_r000809_7_1 <= 255));
  __CPROVER_assume((sec_r000809_7_2 >= 0) && (sec_r000809_7_2 <= 255));
  __CPROVER_assume((sec_r000809_8_1 >= 0) && (sec_r000809_8_1 <= 255));
  __CPROVER_assume((sec_r000809_8_2 >= 0) && (sec_r000809_8_2 <= 255));
  __CPROVER_assume((sec_r000809_9_1 >= 0) && (sec_r000809_9_1 <= 255));
  __CPROVER_assume((sec_r000809_9_2 >= 0) && (sec_r000809_9_2 <= 255));
  __CPROVER_assume((sec_r000809_10_1 >= 0) && (sec_r000809_10_1 <= 255));
  __CPROVER_assume((sec_r000809_10_2 >= 0) && (sec_r000809_10_2 <= 255));
  __CPROVER_assume((sec_r000809_11_1 >= 0) && (sec_r000809_11_1 <= 255));
  __CPROVER_assume((sec_r000809_11_2 >= 0) && (sec_r000809_11_2 <= 255));
  __CPROVER_assume((sec_r000809_12_1 >= 0) && (sec_r000809_12_1 <= 255));
  __CPROVER_assume((sec_r000809_12_2 >= 0) && (sec_r000809_12_2 <= 255));
  __CPROVER_assume((sec_r000809_13_1 >= 0) && (sec_r000809_13_1 <= 255));
  __CPROVER_assume((sec_r000809_13_2 >= 0) && (sec_r000809_13_2 <= 255));
  __CPROVER_assume((sec_r000809_14_1 >= 0) && (sec_r000809_14_1 <= 255));
  __CPROVER_assume((sec_r000809_14_2 >= 0) && (sec_r000809_14_2 <= 255));
  __CPROVER_assume((sec_r000809_15_1 >= 0) && (sec_r000809_15_1 <= 255));
  __CPROVER_assume((sec_r000809_15_2 >= 0) && (sec_r000809_15_2 <= 255));
  __CPROVER_assume((sec_r000809_16_1 >= 0) && (sec_r000809_16_1 <= 255));
  __CPROVER_assume((sec_r000809_16_2 >= 0) && (sec_r000809_16_2 <= 255));
  __CPROVER_assume((sec_r000809_17_1 >= 0) && (sec_r000809_17_1 <= 255));
  __CPROVER_assume((sec_r000809_17_2 >= 0) && (sec_r000809_17_2 <= 255));
  struct SensorNode_R000809_913_0 st_var_0_1 = {0};
  struct SensorNode_R000809_913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000809_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000809_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000809_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000809_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000809_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000809_0_2 + 7) & 15;
  struct FilterState_R000809_913_1 st_var_1_1 = {0};
  struct FilterState_R000809_913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000809_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000809_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000809_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000809_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000809_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000809_0_2 + 9) & 15;
  union TelemetryField_R000809_913_0 u_var_1;
  union TelemetryField_R000809_913_0 u_var_2;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (st_var_0_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_0_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 39)
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
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 39)
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
  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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
  int stage_v_14_1 = (st_var_0_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_0_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 33)
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
  if (stage_v_15_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 33)
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
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 25)
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
  if (stage_v_24_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 25)
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
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (st_var_1_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_1_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 45)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 45)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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
  int stage_v_35_1 = ((st_var_1_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_1_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 38)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 38)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 31)
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
  if (stage_v_41_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 31)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = ((st_var_0_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_0_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 52)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 52)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = ((st_var_1_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_1_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 40)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 40)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 52) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
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
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 35)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 35)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_0_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_0_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 43)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 43)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 72) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_75_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (80 & 31);
  int stage_v_75_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (80 & 31);
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= (stage_v_75_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_75_2 << 1) & 127;
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = (st_var_1_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_1_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((st_var_1_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_1_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 49)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 49)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 81) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (st_var_0_1.buffer[0] ^ 91) & 3;
  int stage_v_88_2 = (st_var_0_2.buffer[0] ^ 91) & 3;
  switch (stage_v_88_1)
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

  switch (stage_v_88_2)
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

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_91_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_92_1 = table_1[0];
  int stage_v_92_2 = table_2[0];
  table_1[0] = (table_1[1] + 185) & 63;
  table_2[0] = (table_2[1] + 185) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (st_var_1_1.buffer[0] ^ 96) & 3;
  int stage_v_93_2 = (st_var_1_2.buffer[0] ^ 96) & 3;
  switch (stage_v_93_1)
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

  switch (stage_v_93_2)
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

  int stage_v_94_1 = ((st_var_0_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_0_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 49)
    {
      chk_sum_1 ^= stage_v_94_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_94_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 49)
    {
      chk_sum_2 ^= stage_v_94_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_95_1 = ((st_var_1_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_1_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 27)
    {
      chk_sum_1 ^= stage_v_95_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_95_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 27)
    {
      chk_sum_2 ^= stage_v_95_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_96_1 = table_1[0];
  int stage_v_96_2 = table_2[0];
  table_1[0] = (table_1[1] + 193) & 63;
  table_2[0] = (table_2[1] + 193) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 99) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 99) & 15;
  int stage_v_98_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_98_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= stage_v_98_1;
  chk_sum_2 ^= stage_v_98_2;
  int stage_v_99_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (104 & 31);
  int stage_v_99_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (104 & 31);
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= (stage_v_99_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_99_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 101) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 102) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_103_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_104_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_104_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_105_1 = (st_var_1_1.buffer[0] ^ 108) & 3;
  int stage_v_105_2 = (st_var_1_2.buffer[0] ^ 108) & 3;
  switch (stage_v_105_1)
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

  switch (stage_v_105_2)
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

  int stage_v_106_1 = (st_var_0_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_0_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (113 & 31);
  int stage_v_108_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (113 & 31);
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= (stage_v_108_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_108_2 << 1) & 127;
  int stage_v_109_1 = table_1[1];
  int stage_v_109_2 = table_2[1];
  table_1[1] = (table_1[2] + 219) & 63;
  table_2[1] = (table_2[2] + 219) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((st_var_1_1.buffer[0] * 2) + 340) & 63;
  int stage_v_111_2 = ((st_var_1_2.buffer[0] * 2) + 340) & 63;
  if (stage_v_111_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_111_1) - 5) & 255;
    if (stage_v_111_1 > 30)
    {
      chk_sum_1 ^= stage_v_111_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_111_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_111_2) - 5) & 255;
    if (stage_v_111_2 > 30)
    {
      chk_sum_2 ^= stage_v_111_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 114) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 114) & 15;
  int stage_v_113_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_113_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= stage_v_113_1;
  chk_sum_2 ^= stage_v_113_2;
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  int stage_v_116_1 = ((st_var_0_1.buffer[2] * 2) + 355) & 63;
  int stage_v_116_2 = ((st_var_0_2.buffer[2] * 2) + 355) & 63;
  if (stage_v_116_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_116_1) - 5) & 255;
    if (stage_v_116_1 > 47)
    {
      chk_sum_1 ^= stage_v_116_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_116_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_116_2) - 5) & 255;
    if (stage_v_116_2 > 47)
    {
      chk_sum_2 ^= stage_v_116_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_119_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (st_var_0_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_0_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = table_1[3];
  int stage_v_123_2 = table_2[3];
  table_1[3] = (table_1[0] + 247) & 63;
  table_2[3] = (table_2[0] + 247) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 37)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 37)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 130) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 130) & 15;
  int stage_v_129_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_129_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= stage_v_129_1;
  chk_sum_2 ^= stage_v_129_2;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 132) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (st_var_1_1.buffer[0] ^ 136) & 3;
  int stage_v_133_2 = (st_var_1_2.buffer[0] ^ 136) & 3;
  switch (stage_v_133_1)
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

  switch (stage_v_133_2)
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

  int stage_v_134_1 = ((st_var_0_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_0_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 48)
    {
      chk_sum_1 ^= stage_v_134_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_134_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 48)
    {
      chk_sum_2 ^= stage_v_134_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_135_1 = (st_var_1_1.buffer[0] ^ 138) & 3;
  int stage_v_135_2 = (st_var_1_2.buffer[0] ^ 138) & 3;
  switch (stage_v_135_1)
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

  switch (stage_v_135_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 137) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 137) & 15;
  int stage_v_136_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_136_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= stage_v_136_1;
  chk_sum_2 ^= stage_v_136_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 138) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = ((st_var_0_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_0_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 36)
    {
      chk_sum_1 ^= stage_v_140_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_140_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 36)
    {
      chk_sum_2 ^= stage_v_140_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((st_var_0_1.buffer[1] * 2) + 433) & 63;
  int stage_v_142_2 = ((st_var_0_2.buffer[1] * 2) + 433) & 63;
  if (stage_v_142_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_142_1) - 5) & 255;
    if (stage_v_142_1 > 42)
    {
      chk_sum_1 ^= stage_v_142_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_142_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_142_2) - 5) & 255;
    if (stage_v_142_2 > 42)
    {
      chk_sum_2 ^= stage_v_142_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 144) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 144) & 15;
  int stage_v_143_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_143_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= stage_v_143_1;
  chk_sum_2 ^= stage_v_143_2;
  int stage_v_144_1 = (st_var_0_1.buffer[0] ^ 147) & 3;
  int stage_v_144_2 = (st_var_0_2.buffer[0] ^ 147) & 3;
  switch (stage_v_144_1)
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

  switch (stage_v_144_2)
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

  int stage_v_145_1 = table_1[1];
  int stage_v_145_2 = table_2[1];
  table_1[1] = (table_1[2] + 291) & 63;
  table_2[1] = (table_2[2] + 291) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 147) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 147) & 15;
  int stage_v_146_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_146_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= stage_v_146_1;
  chk_sum_2 ^= stage_v_146_2;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_149_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 151) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((st_var_0_1.buffer[2] * 2) + 463) & 63;
  int stage_v_152_2 = ((st_var_0_2.buffer[2] * 2) + 463) & 63;
  if (stage_v_152_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_152_1) - 5) & 255;
    if (stage_v_152_1 > 26)
    {
      chk_sum_1 ^= stage_v_152_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_152_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_152_2) - 5) & 255;
    if (stage_v_152_2 > 26)
    {
      chk_sum_2 ^= stage_v_152_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((st_var_0_1.buffer[1] * 2) + 469) & 63;
  int stage_v_154_2 = ((st_var_0_2.buffer[1] * 2) + 469) & 63;
  if (stage_v_154_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_154_1) - 5) & 255;
    if (stage_v_154_1 > 26)
    {
      chk_sum_1 ^= stage_v_154_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_154_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_154_2) - 5) & 255;
    if (stage_v_154_2 > 26)
    {
      chk_sum_2 ^= stage_v_154_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 156) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 50)
    {
      chk_sum_1 ^= stage_v_157_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_157_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 50)
    {
      chk_sum_2 ^= stage_v_157_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_158_1 = (st_var_0_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_0_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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

  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_161_1 = (st_var_1_1.buffer[0] ^ 164) & 3;
  int stage_v_161_2 = (st_var_1_2.buffer[0] ^ 164) & 3;
  switch (stage_v_161_1)
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

  switch (stage_v_161_2)
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

  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_164_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 168) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 169) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 169) & 15;
  int stage_v_168_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_168_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= stage_v_168_1;
  chk_sum_2 ^= stage_v_168_2;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_171_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_172_1 = (st_var_0_1.buffer[0] ^ 175) & 3;
  int stage_v_172_2 = (st_var_0_2.buffer[0] ^ 175) & 3;
  switch (stage_v_172_1)
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

  switch (stage_v_172_2)
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

  int stage_v_173_1 = ((st_var_1_1.buffer[2] * 2) + 526) & 63;
  int stage_v_173_2 = ((st_var_1_2.buffer[2] * 2) + 526) & 63;
  if (stage_v_173_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_173_1) - 5) & 255;
    if (stage_v_173_1 > 25)
    {
      chk_sum_1 ^= stage_v_173_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_173_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_173_2) - 5) & 255;
    if (stage_v_173_2 > 25)
    {
      chk_sum_2 ^= stage_v_173_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = table_1[3];
  int stage_v_175_2 = table_2[3];
  table_1[3] = (table_1[0] + 351) & 63;
  table_2[3] = (table_2[0] + 351) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 27)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 27)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_177_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_177_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_178_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (183 & 31);
  int stage_v_178_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (183 & 31);
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= (stage_v_178_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_178_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 180) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 180) & 15;
  int stage_v_179_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_179_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= stage_v_179_1;
  chk_sum_2 ^= stage_v_179_2;
  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 182) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 182) & 15;
  int stage_v_181_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_181_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  chk_sum_1 ^= stage_v_181_1;
  chk_sum_2 ^= stage_v_181_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 183) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 183) & 15;
  int stage_v_182_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_182_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= stage_v_182_1;
  chk_sum_2 ^= stage_v_182_2;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((st_var_0_1.buffer[1] * 2) + 559) & 63;
  int stage_v_184_2 = ((st_var_0_2.buffer[1] * 2) + 559) & 63;
  if (stage_v_184_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_184_1) - 5) & 255;
    if (stage_v_184_1 > 47)
    {
      chk_sum_1 ^= stage_v_184_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_184_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_184_2) - 5) & 255;
    if (stage_v_184_2 > 47)
    {
      chk_sum_2 ^= stage_v_184_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_185_1 = table_1[1];
  int stage_v_185_2 = table_2[1];
  table_1[1] = (table_1[2] + 371) & 63;
  table_2[1] = (table_2[2] + 371) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((st_var_0_1.buffer[0] * 2) + 565) & 63;
  int stage_v_186_2 = ((st_var_0_2.buffer[0] * 2) + 565) & 63;
  if (stage_v_186_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_186_1) - 5) & 255;
    if (stage_v_186_1 > 26)
    {
      chk_sum_1 ^= stage_v_186_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_186_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_186_2) - 5) & 255;
    if (stage_v_186_2 > 26)
    {
      chk_sum_2 ^= stage_v_186_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_187_1 = table_1[3];
  int stage_v_187_2 = table_2[3];
  table_1[3] = (table_1[0] + 375) & 63;
  table_2[3] = (table_2[0] + 375) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 189) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 189) & 15;
  int stage_v_188_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_188_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  chk_sum_1 ^= stage_v_188_1;
  chk_sum_2 ^= stage_v_188_2;
  int stage_v_189_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (194 & 31);
  int stage_v_189_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (194 & 31);
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= (stage_v_189_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_189_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 191) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 191) & 15;
  int stage_v_190_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_190_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  chk_sum_1 ^= stage_v_190_1;
  chk_sum_2 ^= stage_v_190_2;
  int s_lut_1[4] = {11, 40, 40, 39};
  int s_lut_2[4] = {11, 40, 40, 39};
  int s_idx_1 = sec_r000809_7_1 & 3;
  int s_idx_2 = sec_r000809_7_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000809_16_1 == pub_r000809_16_2);
  __CPROVER_assume(pub_r000809_18_1 == pub_r000809_18_2);
  __CPROVER_assume(pub_r000809_21_1 == pub_r000809_21_2);
  __CPROVER_assume(sec_r000809_7_1 != sec_r000809_7_2);
  __CPROVER_assume(pub_r000809_5_1 == pub_r000809_5_2);
  __CPROVER_assume(pub_r000809_14_1 == pub_r000809_14_2);
  __CPROVER_assume(pub_r000809_10_1 == pub_r000809_10_2);
  __CPROVER_assume(sec_r000809_3_1 != sec_r000809_3_2);
  __CPROVER_assume(sec_r000809_6_1 != sec_r000809_6_2);
  __CPROVER_assume(pub_r000809_1_1 == pub_r000809_1_2);
  __CPROVER_assume(pub_r000809_17_1 == pub_r000809_17_2);
  __CPROVER_assume(sec_r000809_17_1 != sec_r000809_17_2);
  __CPROVER_assume(sec_r000809_15_1 != sec_r000809_15_2);
  __CPROVER_assume(sec_r000809_13_1 != sec_r000809_13_2);
  __CPROVER_assume(pub_r000809_12_1 == pub_r000809_12_2);
  __CPROVER_assume(sec_r000809_1_1 != sec_r000809_1_2);
  __CPROVER_assume(sec_r000809_2_1 != sec_r000809_2_2);
  __CPROVER_assume(pub_r000809_4_1 == pub_r000809_4_2);
  __CPROVER_assume(pub_r000809_7_1 == pub_r000809_7_2);
  __CPROVER_assume(pub_r000809_11_1 == pub_r000809_11_2);
  __CPROVER_assume(sec_r000809_16_1 != sec_r000809_16_2);
  __CPROVER_assume(sec_r000809_11_1 != sec_r000809_11_2);
  __CPROVER_assume(sec_r000809_14_1 != sec_r000809_14_2);
  __CPROVER_assume(sec_r000809_10_1 != sec_r000809_10_2);
  __CPROVER_assume(sec_r000809_8_1 != sec_r000809_8_2);
  __CPROVER_assume(sec_r000809_5_1 != sec_r000809_5_2);
  __CPROVER_assume(sec_r000809_12_1 != sec_r000809_12_2);
  __CPROVER_assume(pub_r000809_13_1 == pub_r000809_13_2);
  __CPROVER_assume(pub_r000809_8_1 == pub_r000809_8_2);
  __CPROVER_assume(pub_r000809_0_1 == pub_r000809_0_2);
  __CPROVER_assume(pub_r000809_2_1 == pub_r000809_2_2);
  __CPROVER_assume(pub_r000809_15_1 == pub_r000809_15_2);
  __CPROVER_assume(sec_r000809_0_1 != sec_r000809_0_2);
  __CPROVER_assume(pub_r000809_9_1 == pub_r000809_9_2);
  __CPROVER_assume(pub_r000809_3_1 == pub_r000809_3_2);
  __CPROVER_assume(pub_r000809_6_1 == pub_r000809_6_2);
  __CPROVER_assume(pub_r000809_19_1 == pub_r000809_19_2);
  __CPROVER_assume(pub_r000809_20_1 == pub_r000809_20_2);
  __CPROVER_assume(sec_r000809_9_1 != sec_r000809_9_2);
  __CPROVER_assume(sec_r000809_4_1 != sec_r000809_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


