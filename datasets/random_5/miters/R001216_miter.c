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
struct FilterState_R001216_1613_0
{
  int damping;
  unsigned char prev_in;
  int mode;
  short cutoff;
  int gain_db;
  int prev_out;
  int buffer[3];
};
struct SensorNode_R001216_1613_1
{
  short reading;
  int offset;
  unsigned char threshold;
  int status;
  short gain;
  int buffer[3];
};
union PacketPayload_R001216_1613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001216_1613_1
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
void fn_R001216_1613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quotient_80_1 = 0;
  int quotient_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_80_1 = ((quotient_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_80_2 = ((quotient_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_80_1) & 127;
    acc_2 = (acc_2 + quotient_80_2) & 127;
  }

  int phase_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_18_1 > 33)
  {
    acc_1 = ((acc_1 + (phase_18_1 * 2)) + 5) & 127;
    aux_1 ^= phase_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_18_2 > 33)
  {
    acc_2 = ((acc_2 + (phase_18_2 * 2)) + 5) & 127;
    aux_2 ^= phase_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_80_1 == quotient_80_2);
  assert(phase_18_1 == phase_18_2);
}

int fn_R001216_1613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quotient_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_80 = ((quotient_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_80) & 127;
  }

  int phase_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_18 > 33)
  {
    acc = ((acc + (phase_18 * 2)) + 5) & 127;
    aux ^= phase_18 & 15;
  }
  else
  {
    acc = ((acc - phase_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001216_1613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_16_1) & 63;
  aux_2 = (aux_2 + residue_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_42_1)
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

  switch (sample_42_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_16_1 == residue_16_2);
  assert(sample_42_1 == sample_42_2);
}

int fn_R001216_1613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_16) & 63;
  acc ^= aux;
  int sample_42 = (aux + st.buffer[1]) & 3;
  switch (sample_42)
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

void fn_R001216_1613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_50_1) & 63;
  aux_2 = (aux_2 + quantum_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_50_1 == quantum_50_2);
}

int fn_R001216_1613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001216_1613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_61_1)
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

  switch (quotient_61_2)
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

  int threshold_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_51_1) & 63;
  aux_2 = (aux_2 + threshold_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_93_1 = 0;
  int stride_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_93_1 = ((stride_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_93_2 = ((stride_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_93_1) & 127;
    acc_2 = (acc_2 + stride_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_61_1 == quotient_61_2);
  assert(threshold_51_1 == threshold_51_2);
  assert(stride_93_1 == stride_93_2);
}

int fn_R001216_1613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_61 = (aux + st.buffer[1]) & 3;
  switch (quotient_61)
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

  int threshold_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_51) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_93 = ((stride_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001216_1613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_33_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_33_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_33_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_33_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_20_1 = 0;
  int tracker_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_20_1 = ((tracker_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_20_2 = ((tracker_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_20_1) & 127;
    acc_2 = (acc_2 + tracker_20_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_97_1 = local_arr_1[aux_1 % 3];
  int quotient_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_33_1 == checksum_33_2);
  assert(tracker_20_1 == tracker_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_97_1 == quotient_97_2);
}

int fn_R001216_1613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_33 > 21)
  {
    acc = ((acc + (checksum_33 * 2)) + 5) & 127;
    aux ^= checksum_33 & 15;
  }
  else
  {
    acc = ((acc - checksum_33) + 11) & 127;
    aux += 3;
  }
  int tracker_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_20 = ((tracker_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_20) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_97 = local_arr[aux % 3];
  acc = (acc + (quotient_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001216_1613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int index_reg_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_84_1)
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

  switch (index_reg_84_2)
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
  int window_96_1 = local_arr_1[aux_1 % 3];
  int window_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_96_2 * 2)) & 127;
  int threshold_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_71_1 > 49)
  {
    acc_1 = ((acc_1 + (threshold_71_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_71_2 > 49)
  {
    acc_2 = ((acc_2 + (threshold_71_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_96_1 == window_96_2);
  assert(threshold_71_1 == threshold_71_2);
}

int fn_R001216_1613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int index_reg_84 = (aux + st.buffer[1]) & 3;
  switch (index_reg_84)
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
  int window_96 = local_arr[aux % 3];
  acc = (acc + (window_96 * 2)) & 127;
  int threshold_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_71 > 49)
  {
    acc = ((acc + (threshold_71 * 2)) + 5) & 127;
    aux ^= threshold_71 & 15;
  }
  else
  {
    acc = ((acc - threshold_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001216_1613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_87_1 = local_arr_1[aux_1 % 3];
  int phase_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_87_2 * 2)) & 127;
  int vector_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_13_1) & 63;
  aux_2 = (aux_2 + vector_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_87_1 == phase_87_2);
  assert(vector_13_1 == vector_13_2);
}

int fn_R001216_1613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int phase_87 = local_arr[aux % 3];
  acc = (acc + (phase_87 * 2)) & 127;
  int vector_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_13) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001216_1613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_13_1 > 21)
  {
    acc_1 = ((acc_1 + (quotient_13_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_13_2 > 21)
  {
    acc_2 = ((acc_2 + (quotient_13_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_47_1) & 63;
  aux_2 = (aux_2 + quotient_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_56_1)
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

  switch (tracker_56_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_13_1 == quotient_13_2);
  assert(quotient_47_1 == quotient_47_2);
  assert(tracker_56_1 == tracker_56_2);
}

int fn_R001216_1613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_13 > 21)
  {
    acc = ((acc + (quotient_13 * 2)) + 5) & 127;
    aux ^= quotient_13 & 15;
  }
  else
  {
    acc = ((acc - quotient_13) + 11) & 127;
    aux += 3;
  }
  int quotient_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_47) & 63;
  acc ^= aux;
  int tracker_56 = (aux + st.buffer[1]) & 3;
  switch (tracker_56)
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

void fn_R001216_1613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_41_1) & 63;
  aux_2 = (aux_2 + phase_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_86_1 = local_arr_1[aux_1 % 3];
  int factor_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_41_1 == phase_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_86_1 == factor_86_2);
}

int fn_R001216_1613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_86 = local_arr[aux % 3];
  acc = (acc + (factor_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001216_1613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_13_1)
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

  switch (metric_13_2)
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

  int damping_25_1 = 0;
  int damping_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_25_1 = ((damping_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_25_2 = ((damping_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_25_1) & 127;
    acc_2 = (acc_2 + damping_25_2) & 127;
  }

  int stride_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_45_1) & 63;
  aux_2 = (aux_2 + stride_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_13_1 == metric_13_2);
  assert(damping_25_1 == damping_25_2);
  assert(stride_45_1 == stride_45_2);
}

int fn_R001216_1613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_13 = (aux + st.buffer[1]) & 3;
  switch (metric_13)
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

  int damping_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_25 = ((damping_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_25) & 127;
  }

  int stride_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001216_1613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_40_1 = local_arr_1[aux_1 % 3];
  int cursor_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_80_1) & 63;
  aux_2 = (aux_2 + vector_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_40_1 == cursor_40_2);
  assert(vector_80_1 == vector_80_2);
}

int fn_R001216_1613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int cursor_40 = local_arr[aux % 3];
  acc = (acc + (cursor_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001216_1613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_94_1 > 31)
  {
    acc_1 = ((acc_1 + (factor_94_1 * 2)) + 5) & 127;
    aux_1 ^= factor_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_94_2 > 31)
  {
    acc_2 = ((acc_2 + (factor_94_2 * 2)) + 5) & 127;
    aux_2 ^= factor_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_94_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_94_1 == factor_94_2);
}

int fn_R001216_1613_11(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_94 > 31)
  {
    acc = ((acc + (factor_94 * 2)) + 5) & 127;
    aux ^= factor_94 & 15;
  }
  else
  {
    acc = ((acc - factor_94) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001216_1613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quantum_77_1 = 0;
  int quantum_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_77_1 = ((quantum_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_77_2 = ((quantum_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_77_1) & 127;
    acc_2 = (acc_2 + quantum_77_2) & 127;
  }

  int mask_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_11_1 > 45)
  {
    acc_1 = ((acc_1 + (mask_11_1 * 2)) + 5) & 127;
    aux_1 ^= mask_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_11_2 > 45)
  {
    acc_2 = ((acc_2 + (mask_11_2 * 2)) + 5) & 127;
    aux_2 ^= mask_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_58_1) & 63;
  aux_2 = (aux_2 + bound_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_77_1 == quantum_77_2);
  assert(mask_11_1 == mask_11_2);
  assert(bound_58_1 == bound_58_2);
}

int fn_R001216_1613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quantum_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_77 = ((quantum_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_77) & 127;
  }

  int mask_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_11 > 45)
  {
    acc = ((acc + (mask_11 * 2)) + 5) & 127;
    aux ^= mask_11 & 15;
  }
  else
  {
    acc = ((acc - mask_11) + 11) & 127;
    aux += 3;
  }
  int bound_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001216_1613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st_1 = {0};
  struct SensorNode_R001216_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tracker_75_1 = 0;
  int tracker_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_75_1 = ((tracker_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_75_2 = ((tracker_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_75_1) & 127;
    acc_2 = (acc_2 + tracker_75_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_68_1 = local_arr_1[aux_1 % 3];
  int tally_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_68_2 * 2)) & 127;
  int pivot_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_67_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_67_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_67_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_67_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_75_1 == tracker_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_68_1 == tally_68_2);
  assert(pivot_67_1 == pivot_67_2);
}

int fn_R001216_1613_13(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001216_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tracker_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_75 = ((tracker_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_75) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_68 = local_arr[aux % 3];
  acc = (acc + (tally_68 * 2)) & 127;
  int pivot_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_67 > 28)
  {
    acc = ((acc + (pivot_67 * 2)) + 5) & 127;
    aux ^= pivot_67 & 15;
  }
  else
  {
    acc = ((acc - pivot_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001216_1613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st_1 = {0};
  struct FilterState_R001216_1613_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_91_1 = local_arr_1[aux_1 % 3];
  int coefficient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_91_2 * 2)) & 127;
  int margin_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_68_1)
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

  switch (margin_68_2)
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

  int threshold_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_54_1) & 63;
  aux_2 = (aux_2 + threshold_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(margin_68_1 == margin_68_2);
  assert(threshold_54_1 == threshold_54_2);
}

int fn_R001216_1613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001216_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_91 = local_arr[aux % 3];
  acc = (acc + (coefficient_91 * 2)) & 127;
  int margin_68 = (aux + st.buffer[1]) & 3;
  switch (margin_68)
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

  int threshold_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001216_0_1;
  int sec_r001216_0_2;
  int sec_r001216_1_1;
  int sec_r001216_1_2;
  int sec_r001216_2_1;
  int sec_r001216_2_2;
  int sec_r001216_3_1;
  int sec_r001216_3_2;
  int sec_r001216_4_1;
  int sec_r001216_4_2;
  int sec_r001216_5_1;
  int sec_r001216_5_2;
  int sec_r001216_6_1;
  int sec_r001216_6_2;
  int sec_r001216_7_1;
  int sec_r001216_7_2;
  int sec_r001216_8_1;
  int sec_r001216_8_2;
  int sec_r001216_9_1;
  int sec_r001216_9_2;
  int sec_r001216_10_1;
  int sec_r001216_10_2;
  int sec_r001216_11_1;
  int sec_r001216_11_2;
  int sec_r001216_12_1;
  int sec_r001216_12_2;
  int sec_r001216_13_1;
  int sec_r001216_13_2;
  int sec_r001216_14_1;
  int sec_r001216_14_2;
  int sec_r001216_15_1;
  int sec_r001216_15_2;
  int sec_r001216_16_1;
  int sec_r001216_16_2;
  int sec_r001216_17_1;
  int sec_r001216_17_2;
  int sec_r001216_18_1;
  int sec_r001216_18_2;
  int sec_r001216_19_1;
  int sec_r001216_19_2;
  int sec_r001216_20_1;
  int sec_r001216_20_2;
  int pub_r001216_0_1;
  int pub_r001216_0_2;
  int pub_r001216_1_1;
  int pub_r001216_1_2;
  int pub_r001216_2_1;
  int pub_r001216_2_2;
  int pub_r001216_3_1;
  int pub_r001216_3_2;
  int pub_r001216_4_1;
  int pub_r001216_4_2;
  int pub_r001216_5_1;
  int pub_r001216_5_2;
  int pub_r001216_6_1;
  int pub_r001216_6_2;
  int pub_r001216_7_1;
  int pub_r001216_7_2;
  int pub_r001216_8_1;
  int pub_r001216_8_2;
  int pub_r001216_9_1;
  int pub_r001216_9_2;
  int pub_r001216_10_1;
  int pub_r001216_10_2;
  int pub_r001216_11_1;
  int pub_r001216_11_2;
  int pub_r001216_12_1;
  int pub_r001216_12_2;
  int pub_r001216_13_1;
  int pub_r001216_13_2;
  int pub_r001216_14_1;
  int pub_r001216_14_2;
  int pub_r001216_15_1;
  int pub_r001216_15_2;
  int pub_r001216_16_1;
  int pub_r001216_16_2;
  int pub_r001216_17_1;
  int pub_r001216_17_2;
  int pub_r001216_18_1;
  int pub_r001216_18_2;
  int pub_r001216_19_1;
  int pub_r001216_19_2;
  int pub_r001216_20_1;
  int pub_r001216_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001216_0_1 >= (-100)) && (pub_r001216_0_1 <= 100));
  __CPROVER_assume((pub_r001216_0_2 >= (-100)) && (pub_r001216_0_2 <= 100));
  __CPROVER_assume((pub_r001216_1_1 >= (-100)) && (pub_r001216_1_1 <= 100));
  __CPROVER_assume((pub_r001216_1_2 >= (-100)) && (pub_r001216_1_2 <= 100));
  __CPROVER_assume((pub_r001216_2_1 >= (-100)) && (pub_r001216_2_1 <= 100));
  __CPROVER_assume((pub_r001216_2_2 >= (-100)) && (pub_r001216_2_2 <= 100));
  __CPROVER_assume((pub_r001216_3_1 >= (-100)) && (pub_r001216_3_1 <= 100));
  __CPROVER_assume((pub_r001216_3_2 >= (-100)) && (pub_r001216_3_2 <= 100));
  __CPROVER_assume((pub_r001216_4_1 >= (-100)) && (pub_r001216_4_1 <= 100));
  __CPROVER_assume((pub_r001216_4_2 >= (-100)) && (pub_r001216_4_2 <= 100));
  __CPROVER_assume((pub_r001216_5_1 >= (-100)) && (pub_r001216_5_1 <= 100));
  __CPROVER_assume((pub_r001216_5_2 >= (-100)) && (pub_r001216_5_2 <= 100));
  __CPROVER_assume((pub_r001216_6_1 >= (-100)) && (pub_r001216_6_1 <= 100));
  __CPROVER_assume((pub_r001216_6_2 >= (-100)) && (pub_r001216_6_2 <= 100));
  __CPROVER_assume((pub_r001216_7_1 >= (-100)) && (pub_r001216_7_1 <= 100));
  __CPROVER_assume((pub_r001216_7_2 >= (-100)) && (pub_r001216_7_2 <= 100));
  __CPROVER_assume((pub_r001216_8_1 >= (-100)) && (pub_r001216_8_1 <= 100));
  __CPROVER_assume((pub_r001216_8_2 >= (-100)) && (pub_r001216_8_2 <= 100));
  __CPROVER_assume((pub_r001216_9_1 >= (-100)) && (pub_r001216_9_1 <= 100));
  __CPROVER_assume((pub_r001216_9_2 >= (-100)) && (pub_r001216_9_2 <= 100));
  __CPROVER_assume((pub_r001216_10_1 >= (-100)) && (pub_r001216_10_1 <= 100));
  __CPROVER_assume((pub_r001216_10_2 >= (-100)) && (pub_r001216_10_2 <= 100));
  __CPROVER_assume((pub_r001216_11_1 >= (-100)) && (pub_r001216_11_1 <= 100));
  __CPROVER_assume((pub_r001216_11_2 >= (-100)) && (pub_r001216_11_2 <= 100));
  __CPROVER_assume((pub_r001216_12_1 >= (-100)) && (pub_r001216_12_1 <= 100));
  __CPROVER_assume((pub_r001216_12_2 >= (-100)) && (pub_r001216_12_2 <= 100));
  __CPROVER_assume((pub_r001216_13_1 >= (-100)) && (pub_r001216_13_1 <= 100));
  __CPROVER_assume((pub_r001216_13_2 >= (-100)) && (pub_r001216_13_2 <= 100));
  __CPROVER_assume((pub_r001216_14_1 >= (-100)) && (pub_r001216_14_1 <= 100));
  __CPROVER_assume((pub_r001216_14_2 >= (-100)) && (pub_r001216_14_2 <= 100));
  __CPROVER_assume((pub_r001216_15_1 >= (-100)) && (pub_r001216_15_1 <= 100));
  __CPROVER_assume((pub_r001216_15_2 >= (-100)) && (pub_r001216_15_2 <= 100));
  __CPROVER_assume((pub_r001216_16_1 >= (-100)) && (pub_r001216_16_1 <= 100));
  __CPROVER_assume((pub_r001216_16_2 >= (-100)) && (pub_r001216_16_2 <= 100));
  __CPROVER_assume((pub_r001216_17_1 >= (-100)) && (pub_r001216_17_1 <= 100));
  __CPROVER_assume((pub_r001216_17_2 >= (-100)) && (pub_r001216_17_2 <= 100));
  __CPROVER_assume((pub_r001216_18_1 >= (-100)) && (pub_r001216_18_1 <= 100));
  __CPROVER_assume((pub_r001216_18_2 >= (-100)) && (pub_r001216_18_2 <= 100));
  __CPROVER_assume((pub_r001216_19_1 >= (-100)) && (pub_r001216_19_1 <= 100));
  __CPROVER_assume((pub_r001216_19_2 >= (-100)) && (pub_r001216_19_2 <= 100));
  __CPROVER_assume((pub_r001216_20_1 >= (-100)) && (pub_r001216_20_1 <= 100));
  __CPROVER_assume((pub_r001216_20_2 >= (-100)) && (pub_r001216_20_2 <= 100));
  __CPROVER_assume((sec_r001216_0_1 >= 0) && (sec_r001216_0_1 <= 255));
  __CPROVER_assume((sec_r001216_0_2 >= 0) && (sec_r001216_0_2 <= 255));
  __CPROVER_assume((sec_r001216_1_1 >= 0) && (sec_r001216_1_1 <= 255));
  __CPROVER_assume((sec_r001216_1_2 >= 0) && (sec_r001216_1_2 <= 255));
  __CPROVER_assume((sec_r001216_2_1 >= 0) && (sec_r001216_2_1 <= 255));
  __CPROVER_assume((sec_r001216_2_2 >= 0) && (sec_r001216_2_2 <= 255));
  __CPROVER_assume((sec_r001216_3_1 >= 0) && (sec_r001216_3_1 <= 255));
  __CPROVER_assume((sec_r001216_3_2 >= 0) && (sec_r001216_3_2 <= 255));
  __CPROVER_assume((sec_r001216_4_1 >= 0) && (sec_r001216_4_1 <= 255));
  __CPROVER_assume((sec_r001216_4_2 >= 0) && (sec_r001216_4_2 <= 255));
  __CPROVER_assume((sec_r001216_5_1 >= 0) && (sec_r001216_5_1 <= 255));
  __CPROVER_assume((sec_r001216_5_2 >= 0) && (sec_r001216_5_2 <= 255));
  __CPROVER_assume((sec_r001216_6_1 >= 0) && (sec_r001216_6_1 <= 255));
  __CPROVER_assume((sec_r001216_6_2 >= 0) && (sec_r001216_6_2 <= 255));
  __CPROVER_assume((sec_r001216_7_1 >= 0) && (sec_r001216_7_1 <= 255));
  __CPROVER_assume((sec_r001216_7_2 >= 0) && (sec_r001216_7_2 <= 255));
  __CPROVER_assume((sec_r001216_8_1 >= 0) && (sec_r001216_8_1 <= 255));
  __CPROVER_assume((sec_r001216_8_2 >= 0) && (sec_r001216_8_2 <= 255));
  __CPROVER_assume((sec_r001216_9_1 >= 0) && (sec_r001216_9_1 <= 255));
  __CPROVER_assume((sec_r001216_9_2 >= 0) && (sec_r001216_9_2 <= 255));
  __CPROVER_assume((sec_r001216_10_1 >= 0) && (sec_r001216_10_1 <= 255));
  __CPROVER_assume((sec_r001216_10_2 >= 0) && (sec_r001216_10_2 <= 255));
  __CPROVER_assume((sec_r001216_11_1 >= 0) && (sec_r001216_11_1 <= 255));
  __CPROVER_assume((sec_r001216_11_2 >= 0) && (sec_r001216_11_2 <= 255));
  __CPROVER_assume((sec_r001216_12_1 >= 0) && (sec_r001216_12_1 <= 255));
  __CPROVER_assume((sec_r001216_12_2 >= 0) && (sec_r001216_12_2 <= 255));
  __CPROVER_assume((sec_r001216_13_1 >= 0) && (sec_r001216_13_1 <= 255));
  __CPROVER_assume((sec_r001216_13_2 >= 0) && (sec_r001216_13_2 <= 255));
  __CPROVER_assume((sec_r001216_14_1 >= 0) && (sec_r001216_14_1 <= 255));
  __CPROVER_assume((sec_r001216_14_2 >= 0) && (sec_r001216_14_2 <= 255));
  __CPROVER_assume((sec_r001216_15_1 >= 0) && (sec_r001216_15_1 <= 255));
  __CPROVER_assume((sec_r001216_15_2 >= 0) && (sec_r001216_15_2 <= 255));
  __CPROVER_assume((sec_r001216_16_1 >= 0) && (sec_r001216_16_1 <= 255));
  __CPROVER_assume((sec_r001216_16_2 >= 0) && (sec_r001216_16_2 <= 255));
  __CPROVER_assume((sec_r001216_17_1 >= 0) && (sec_r001216_17_1 <= 255));
  __CPROVER_assume((sec_r001216_17_2 >= 0) && (sec_r001216_17_2 <= 255));
  __CPROVER_assume((sec_r001216_18_1 >= 0) && (sec_r001216_18_1 <= 255));
  __CPROVER_assume((sec_r001216_18_2 >= 0) && (sec_r001216_18_2 <= 255));
  __CPROVER_assume((sec_r001216_19_1 >= 0) && (sec_r001216_19_1 <= 255));
  __CPROVER_assume((sec_r001216_19_2 >= 0) && (sec_r001216_19_2 <= 255));
  __CPROVER_assume((sec_r001216_20_1 >= 0) && (sec_r001216_20_1 <= 255));
  __CPROVER_assume((sec_r001216_20_2 >= 0) && (sec_r001216_20_2 <= 255));
  struct FilterState_R001216_1613_0 st_var_0_1 = {0};
  struct FilterState_R001216_1613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001216_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001216_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001216_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001216_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001216_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001216_0_2 + 7) & 15;
  struct SensorNode_R001216_1613_1 st_var_1_1 = {0};
  struct SensorNode_R001216_1613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001216_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001216_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001216_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001216_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001216_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001216_0_2 + 9) & 15;
  union PacketPayload_R001216_1613_0 u_var_1;
  union PacketPayload_R001216_1613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001216_1613_0(sec_r001216_0_1, pub_r001216_1_1, pub_r001216_2_1);
  int helper_flow_0_2 = fn_R001216_1613_0(sec_r001216_0_2, pub_r001216_1_2, pub_r001216_2_2);
  fn_R001216_1613_0_2(sec_r001216_0_1, pub_r001216_1_1, pub_r001216_2_1, sec_r001216_0_2, pub_r001216_1_2, pub_r001216_2_2);
  int helper_flow_1_1 = fn_R001216_1613_1(sec_r001216_1_1, pub_r001216_2_1, pub_r001216_3_1);
  int helper_flow_1_2 = fn_R001216_1613_1(sec_r001216_1_2, pub_r001216_2_2, pub_r001216_3_2);
  fn_R001216_1613_1_2(sec_r001216_1_1, pub_r001216_2_1, pub_r001216_3_1, sec_r001216_1_2, pub_r001216_2_2, pub_r001216_3_2);
  int helper_flow_2_1 = fn_R001216_1613_2(sec_r001216_2_1, sec_r001216_3_1, pub_r001216_4_1, pub_r001216_5_1, pub_r001216_6_1);
  int helper_flow_2_2 = fn_R001216_1613_2(sec_r001216_2_2, sec_r001216_3_2, pub_r001216_4_2, pub_r001216_5_2, pub_r001216_6_2);
  fn_R001216_1613_2_2(sec_r001216_2_1, sec_r001216_3_1, pub_r001216_4_1, pub_r001216_5_1, pub_r001216_6_1, sec_r001216_2_2, sec_r001216_3_2, pub_r001216_4_2, pub_r001216_5_2, pub_r001216_6_2);
  int helper_flow_3_1 = fn_R001216_1613_3(sec_r001216_3_1, pub_r001216_4_1, pub_r001216_5_1);
  int helper_flow_3_2 = fn_R001216_1613_3(sec_r001216_3_2, pub_r001216_4_2, pub_r001216_5_2);
  fn_R001216_1613_3_2(sec_r001216_3_1, pub_r001216_4_1, pub_r001216_5_1, sec_r001216_3_2, pub_r001216_4_2, pub_r001216_5_2);
  int helper_flow_4_1 = fn_R001216_1613_4(sec_r001216_4_1, pub_r001216_5_1, pub_r001216_6_1, pub_r001216_7_1);
  int helper_flow_4_2 = fn_R001216_1613_4(sec_r001216_4_2, pub_r001216_5_2, pub_r001216_6_2, pub_r001216_7_2);
  fn_R001216_1613_4_2(sec_r001216_4_1, pub_r001216_5_1, pub_r001216_6_1, pub_r001216_7_1, sec_r001216_4_2, pub_r001216_5_2, pub_r001216_6_2, pub_r001216_7_2);
  int helper_flow_5_1 = fn_R001216_1613_5(sec_r001216_5_1, pub_r001216_6_1, pub_r001216_7_1, pub_r001216_8_1);
  int helper_flow_5_2 = fn_R001216_1613_5(sec_r001216_5_2, pub_r001216_6_2, pub_r001216_7_2, pub_r001216_8_2);
  fn_R001216_1613_5_2(sec_r001216_5_1, pub_r001216_6_1, pub_r001216_7_1, pub_r001216_8_1, sec_r001216_5_2, pub_r001216_6_2, pub_r001216_7_2, pub_r001216_8_2);
  int helper_flow_6_1 = fn_R001216_1613_6(sec_r001216_6_1, pub_r001216_7_1, pub_r001216_8_1);
  int helper_flow_6_2 = fn_R001216_1613_6(sec_r001216_6_2, pub_r001216_7_2, pub_r001216_8_2);
  fn_R001216_1613_6_2(sec_r001216_6_1, pub_r001216_7_1, pub_r001216_8_1, sec_r001216_6_2, pub_r001216_7_2, pub_r001216_8_2);
  int helper_flow_7_1 = fn_R001216_1613_7(sec_r001216_7_1, pub_r001216_8_1, pub_r001216_9_1, pub_r001216_10_1, pub_r001216_11_1);
  int helper_flow_7_2 = fn_R001216_1613_7(sec_r001216_7_2, pub_r001216_8_2, pub_r001216_9_2, pub_r001216_10_2, pub_r001216_11_2);
  fn_R001216_1613_7_2(sec_r001216_7_1, pub_r001216_8_1, pub_r001216_9_1, pub_r001216_10_1, pub_r001216_11_1, sec_r001216_7_2, pub_r001216_8_2, pub_r001216_9_2, pub_r001216_10_2, pub_r001216_11_2);
  int helper_flow_8_1 = fn_R001216_1613_8(sec_r001216_8_1, sec_r001216_9_1, pub_r001216_10_1);
  int helper_flow_8_2 = fn_R001216_1613_8(sec_r001216_8_2, sec_r001216_9_2, pub_r001216_10_2);
  fn_R001216_1613_8_2(sec_r001216_8_1, sec_r001216_9_1, pub_r001216_10_1, sec_r001216_8_2, sec_r001216_9_2, pub_r001216_10_2);
  int helper_flow_9_1 = fn_R001216_1613_9(sec_r001216_9_1, pub_r001216_10_1, pub_r001216_11_1);
  int helper_flow_9_2 = fn_R001216_1613_9(sec_r001216_9_2, pub_r001216_10_2, pub_r001216_11_2);
  fn_R001216_1613_9_2(sec_r001216_9_1, pub_r001216_10_1, pub_r001216_11_1, sec_r001216_9_2, pub_r001216_10_2, pub_r001216_11_2);
  int helper_flow_10_1 = fn_R001216_1613_10(sec_r001216_10_1, sec_r001216_11_1, pub_r001216_12_1, pub_r001216_13_1);
  int helper_flow_10_2 = fn_R001216_1613_10(sec_r001216_10_2, sec_r001216_11_2, pub_r001216_12_2, pub_r001216_13_2);
  fn_R001216_1613_10_2(sec_r001216_10_1, sec_r001216_11_1, pub_r001216_12_1, pub_r001216_13_1, sec_r001216_10_2, sec_r001216_11_2, pub_r001216_12_2, pub_r001216_13_2);
  int stage_v_0_1 = ((pub_r001216_16_1 * 2) + 29) & 63;
  int stage_v_0_2 = ((pub_r001216_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001216_0_1 * 2) + 48) & 63;
  int stage_v_1_2 = ((pub_r001216_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001216_10_1 + (pub_r001216_1_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001216_10_2 + (pub_r001216_1_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001216_1_1 * 2) + 44) & 63;
  int stage_v_3_2 = ((pub_r001216_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001216_18_1 + (pub_r001216_11_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001216_18_2 + (pub_r001216_11_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001216_9_1 + (pub_r001216_15_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001216_9_2 + (pub_r001216_15_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001216_10_1 + (pub_r001216_7_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001216_10_2 + (pub_r001216_7_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((helper_flow_6_1 + (pub_r001216_3_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_6_2 + (pub_r001216_3_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001216_8_1 * 2) + 27) & 63;
  int stage_v_8_2 = ((pub_r001216_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001216_5_1 * 2) + 18) & 63;
  int stage_v_9_2 = ((pub_r001216_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((helper_flow_10_1 + (pub_r001216_5_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_10_2 + (pub_r001216_5_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001216_0_1 * 2) + 11) & 63;
  int stage_v_11_2 = ((pub_r001216_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((helper_flow_7_1 + (pub_r001216_12_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_7_2 + (pub_r001216_12_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001216_20_1 + (pub_r001216_8_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001216_20_2 + (pub_r001216_8_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001216_12_1 + (pub_r001216_15_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001216_12_2 + (pub_r001216_15_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_7_1 + (pub_r001216_18_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_7_2 + (pub_r001216_18_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001216_11_1 * 2) + 6) & 63;
  int stage_v_16_2 = ((pub_r001216_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001216_9_1 + (pub_r001216_5_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001216_9_2 + (pub_r001216_5_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((stage_v_14_1 + (pub_r001216_8_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_14_2 + (pub_r001216_8_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001216_4_1 * 2) + 8) & 63;
  int stage_v_19_2 = ((pub_r001216_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((sec_r001216_20_1 + (pub_r001216_8_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001216_20_2 + (pub_r001216_8_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001216_20_1 + (pub_r001216_1_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001216_20_2 + (pub_r001216_1_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001216_19_1 * 2) + 37) & 63;
  int stage_v_22_2 = ((pub_r001216_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001216_9_1 * 2) + 11) & 63;
  int stage_v_23_2 = ((pub_r001216_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001216_15_1 + (pub_r001216_3_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001216_15_2 + (pub_r001216_3_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_13_1 + (pub_r001216_15_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_13_2 + (pub_r001216_15_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_1_1 + (pub_r001216_18_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_1_2 + (pub_r001216_18_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_18_1 + (pub_r001216_0_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_18_2 + (pub_r001216_0_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_17_1 + (pub_r001216_19_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_17_2 + (pub_r001216_19_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_14_1 + (pub_r001216_5_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_14_2 + (pub_r001216_5_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001216_12_1 * 2) + 45) & 63;
  int stage_v_30_2 = ((pub_r001216_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_28_1 + (pub_r001216_16_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_28_2 + (pub_r001216_16_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_13_1 + (pub_r001216_8_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_13_2 + (pub_r001216_8_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_32_1 + (pub_r001216_5_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_32_2 + (pub_r001216_5_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001216_1_1 + (pub_r001216_9_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001216_1_2 + (pub_r001216_9_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001216_10_1 + (pub_r001216_18_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001216_10_2 + (pub_r001216_18_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_34_1 + (pub_r001216_12_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_34_2 + (pub_r001216_12_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001216_16_1 * 2) + 24) & 63;
  int stage_v_37_2 = ((pub_r001216_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001216_4_1 * 2) + 41) & 63;
  int stage_v_38_2 = ((pub_r001216_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((helper_flow_1_1 + (pub_r001216_11_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((helper_flow_1_2 + (pub_r001216_11_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001216_7_1 * 2) + 31) & 63;
  int stage_v_40_2 = ((pub_r001216_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_36_1 + (pub_r001216_5_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_36_2 + (pub_r001216_5_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_4_1 + (pub_r001216_3_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_4_2 + (pub_r001216_3_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001216_20_1 * 2) + 5) & 63;
  int stage_v_43_2 = ((pub_r001216_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001216_5_1 * 2) + 33) & 63;
  int stage_v_44_2 = ((pub_r001216_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001216_1_1 * 2) + 12) & 63;
  int stage_v_45_2 = ((pub_r001216_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((helper_flow_5_1 + (pub_r001216_15_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((helper_flow_5_2 + (pub_r001216_15_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_20_1 + (pub_r001216_13_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_20_2 + (pub_r001216_13_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001216_0_1 * 2) + 37) & 63;
  int stage_v_48_2 = ((pub_r001216_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001216_7_1 * 2) + 20) & 63;
  int stage_v_49_2 = ((pub_r001216_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((sec_r001216_12_1 + (pub_r001216_3_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001216_12_2 + (pub_r001216_3_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((sec_r001216_10_1 + (pub_r001216_20_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001216_10_2 + (pub_r001216_20_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001216_6_1 * 2) + 34) & 63;
  int stage_v_52_2 = ((pub_r001216_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_5_1 + (pub_r001216_0_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_5_2 + (pub_r001216_0_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001216_9_1 + (pub_r001216_12_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001216_9_2 + (pub_r001216_12_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001216_8_1 + (pub_r001216_19_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001216_8_2 + (pub_r001216_19_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((sec_r001216_0_1 + (pub_r001216_5_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((sec_r001216_0_2 + (pub_r001216_5_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_41_1 + (pub_r001216_9_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_41_2 + (pub_r001216_9_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_47_1 + (pub_r001216_10_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_47_2 + (pub_r001216_10_2 * 2)) + 179) & 127;
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
  int stage_v_59_1 = ((stage_v_36_1 + (pub_r001216_2_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_36_2 + (pub_r001216_2_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_57_1 + (pub_r001216_12_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_57_2 + (pub_r001216_12_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((sec_r001216_2_1 + (pub_r001216_14_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001216_2_2 + (pub_r001216_14_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((helper_flow_4_1 + (pub_r001216_6_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((helper_flow_4_2 + (pub_r001216_6_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001216_15_1 * 2) + 30) & 63;
  int stage_v_63_2 = ((pub_r001216_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_28_1 + (pub_r001216_9_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_28_2 + (pub_r001216_9_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_10_1 + (pub_r001216_9_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_10_2 + (pub_r001216_9_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((helper_flow_8_1 + (pub_r001216_13_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((helper_flow_8_2 + (pub_r001216_13_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001216_6_1 * 2) + 47) & 63;
  int stage_v_67_2 = ((pub_r001216_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((sec_r001216_2_1 + (pub_r001216_9_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((sec_r001216_2_2 + (pub_r001216_9_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001216_9_1 + (pub_r001216_3_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001216_9_2 + (pub_r001216_3_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((sec_r001216_18_1 + (pub_r001216_7_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001216_18_2 + (pub_r001216_7_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_62_1 + (pub_r001216_10_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_62_2 + (pub_r001216_10_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001216_16_1 + (pub_r001216_8_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001216_16_2 + (pub_r001216_8_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_25_1 + (pub_r001216_12_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_25_2 + (pub_r001216_12_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001216_2_1 * 2) + 48) & 63;
  int stage_v_74_2 = ((pub_r001216_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_46_1 + (pub_r001216_20_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_46_2 + (pub_r001216_20_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001216_1_1 * 2) + 28) & 63;
  int stage_v_76_2 = ((pub_r001216_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((sec_r001216_3_1 + (pub_r001216_1_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001216_3_2 + (pub_r001216_1_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001216_6_1 * 2) + 42) & 63;
  int stage_v_78_2 = ((pub_r001216_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_58_1 + (pub_r001216_5_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_58_2 + (pub_r001216_5_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_47_1 + (pub_r001216_3_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_47_2 + (pub_r001216_3_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_64_1 + (pub_r001216_11_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_64_2 + (pub_r001216_11_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((sec_r001216_1_1 + (pub_r001216_1_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001216_1_2 + (pub_r001216_1_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((pub_r001216_1_1 * 2) + 45) & 63;
  int stage_v_83_2 = ((pub_r001216_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001216_12_1 * 2) + 44) & 63;
  int stage_v_84_2 = ((pub_r001216_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_28_1 + (pub_r001216_5_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_28_2 + (pub_r001216_5_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001216_11_1 * 2) + 13) & 63;
  int stage_v_86_2 = ((pub_r001216_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((sec_r001216_7_1 + (pub_r001216_9_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((sec_r001216_7_2 + (pub_r001216_9_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((helper_flow_1_1 + (pub_r001216_8_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((helper_flow_1_2 + (pub_r001216_8_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_77_1 + (pub_r001216_7_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_77_2 + (pub_r001216_7_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_62_1 + (pub_r001216_1_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_62_2 + (pub_r001216_1_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_31_1 + (pub_r001216_17_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_31_2 + (pub_r001216_17_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_62_1 + (pub_r001216_19_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_62_2 + (pub_r001216_19_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_62_1 + (pub_r001216_8_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_62_2 + (pub_r001216_8_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_2_1 + (pub_r001216_0_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_2_2 + (pub_r001216_0_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_31_1 + (pub_r001216_4_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_31_2 + (pub_r001216_4_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_13_1 + (pub_r001216_1_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_13_2 + (pub_r001216_1_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_21_1 + (pub_r001216_15_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_21_2 + (pub_r001216_15_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_62_1 + (pub_r001216_8_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_62_2 + (pub_r001216_8_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_26_1 + (pub_r001216_19_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_26_2 + (pub_r001216_19_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_21_1 + (pub_r001216_5_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_21_2 + (pub_r001216_5_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001216_6_1 * 2) + 24) & 63;
  int stage_v_101_2 = ((pub_r001216_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_79_1 + (pub_r001216_13_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_79_2 + (pub_r001216_13_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_15_1 + (pub_r001216_7_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_15_2 + (pub_r001216_7_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001216_7_1 * 2) + 38) & 63;
  int stage_v_104_2 = ((pub_r001216_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_69_1 + (pub_r001216_8_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_69_2 + (pub_r001216_8_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((helper_flow_0_1 + (pub_r001216_8_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((helper_flow_0_2 + (pub_r001216_8_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((helper_flow_9_1 + (pub_r001216_7_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((helper_flow_9_2 + (pub_r001216_7_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_41_1 + (pub_r001216_5_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_41_2 + (pub_r001216_5_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_57_1 + (pub_r001216_11_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_57_2 + (pub_r001216_11_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_39_1 + (pub_r001216_8_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_39_2 + (pub_r001216_8_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_28_1 + (pub_r001216_10_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_28_2 + (pub_r001216_10_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((helper_flow_10_1 + (pub_r001216_6_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((helper_flow_10_2 + (pub_r001216_6_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001216_20_1 * 2) + 16) & 63;
  int stage_v_113_2 = ((pub_r001216_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_33_1 + (pub_r001216_3_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_33_2 + (pub_r001216_3_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((helper_flow_0_1 + (pub_r001216_17_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((helper_flow_0_2 + (pub_r001216_17_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_34_1 + (pub_r001216_14_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_34_2 + (pub_r001216_14_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001216_13_1 * 2) + 34) & 63;
  int stage_v_117_2 = ((pub_r001216_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_28_1 + (pub_r001216_0_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_28_2 + (pub_r001216_0_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_66_1 + (pub_r001216_3_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_66_2 + (pub_r001216_3_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001216_9_1 + (pub_r001216_8_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001216_9_2 + (pub_r001216_8_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_34_1 + (pub_r001216_16_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_34_2 + (pub_r001216_16_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_31_1 + (pub_r001216_19_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_31_2 + (pub_r001216_19_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_88_1 + (pub_r001216_10_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_88_2 + (pub_r001216_10_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001216_4_1 * 2) + 23) & 63;
  int stage_v_124_2 = ((pub_r001216_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((helper_flow_9_1 + (pub_r001216_5_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((helper_flow_9_2 + (pub_r001216_5_2 * 2)) + 380) & 127;
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
  int stage_v_126_1 = ((stage_v_6_1 + (pub_r001216_10_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_6_2 + (pub_r001216_10_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_96_1 + (pub_r001216_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_96_2 + (pub_r001216_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_89_1 + (pub_r001216_19_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_89_2 + (pub_r001216_19_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((sec_r001216_18_1 + (pub_r001216_8_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001216_18_2 + (pub_r001216_8_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_36_1 + (pub_r001216_18_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_36_2 + (pub_r001216_18_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001216_8_1 * 2) + 17) & 63;
  int stage_v_131_2 = ((pub_r001216_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_27_1 + (pub_r001216_14_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_27_2 + (pub_r001216_14_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_114_1 + (pub_r001216_0_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_114_2 + (pub_r001216_0_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_72_1 + (pub_r001216_8_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_72_2 + (pub_r001216_8_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((sec_r001216_6_1 + (pub_r001216_15_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((sec_r001216_6_2 + (pub_r001216_15_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001216_12_1 * 2) + 21) & 63;
  int stage_v_136_2 = ((pub_r001216_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_112_1 + (pub_r001216_20_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_112_2 + (pub_r001216_20_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_126_1 + (pub_r001216_6_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_126_2 + (pub_r001216_6_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001216_0_1 * 2) + 17) & 63;
  int stage_v_139_2 = ((pub_r001216_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((sec_r001216_16_1 + (pub_r001216_11_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001216_16_2 + (pub_r001216_11_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001216_13_1 * 2) + 14) & 63;
  int stage_v_141_2 = ((pub_r001216_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_128_1 + (pub_r001216_11_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_128_2 + (pub_r001216_11_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_103_1 + (pub_r001216_6_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_103_2 + (pub_r001216_6_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_94_1 + (pub_r001216_13_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_94_2 + (pub_r001216_13_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001216_12_1 * 2) + 49) & 63;
  int stage_v_145_2 = ((pub_r001216_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_66_1 + (pub_r001216_10_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_66_2 + (pub_r001216_10_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001216_6_1 * 2) + 41) & 63;
  int stage_v_147_2 = ((pub_r001216_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_129_1 + (pub_r001216_13_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_129_2 + (pub_r001216_13_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001216_19_1 * 2) + 48) & 63;
  int stage_v_149_2 = ((pub_r001216_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001216_7_1 * 2) + 35) & 63;
  int stage_v_150_2 = ((pub_r001216_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_98_1 + (pub_r001216_2_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_98_2 + (pub_r001216_2_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_13_1 + (pub_r001216_6_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_13_2 + (pub_r001216_6_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001216_19_1 * 2) + 22) & 63;
  int stage_v_153_2 = ((pub_r001216_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001216_10_1 * 2) + 30) & 63;
  int stage_v_154_2 = ((pub_r001216_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001216_15_1 * 2) + 33) & 63;
  int stage_v_155_2 = ((pub_r001216_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_111_1 + (pub_r001216_20_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_111_2 + (pub_r001216_20_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001216_14_1 * 2) + 47) & 63;
  int stage_v_157_2 = ((pub_r001216_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001216_14_1 * 2) + 45) & 63;
  int stage_v_158_2 = ((pub_r001216_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001216_13_1 * 2) + 40) & 63;
  int stage_v_159_2 = ((pub_r001216_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((stage_v_93_1 + (pub_r001216_18_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_93_2 + (pub_r001216_18_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001216_14_1 * 2) + 14) & 63;
  int stage_v_161_2 = ((pub_r001216_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_29_1 + (pub_r001216_12_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_29_2 + (pub_r001216_12_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001216_20_1 * 2) + 36) & 63;
  int stage_v_163_2 = ((pub_r001216_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_123_1 + (pub_r001216_0_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_123_2 + (pub_r001216_0_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_106_1 + (pub_r001216_4_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_106_2 + (pub_r001216_4_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_34_1 + (pub_r001216_8_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_34_2 + (pub_r001216_8_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_88_1 + (pub_r001216_17_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_88_2 + (pub_r001216_17_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((pub_r001216_20_1 * 2) + 7) & 63;
  int stage_v_168_2 = ((pub_r001216_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001216_4_1 * 2) + 39) & 63;
  int stage_v_169_2 = ((pub_r001216_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_112_1 + (pub_r001216_1_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_112_2 + (pub_r001216_1_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((sec_r001216_4_1 + (pub_r001216_4_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((sec_r001216_4_2 + (pub_r001216_4_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((sec_r001216_20_1 + (pub_r001216_4_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((sec_r001216_20_2 + (pub_r001216_4_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001216_14_1 * 2) + 34) & 63;
  int stage_v_173_2 = ((pub_r001216_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((sec_r001216_10_1 + (pub_r001216_20_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((sec_r001216_10_2 + (pub_r001216_20_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_71_1 + (pub_r001216_4_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_71_2 + (pub_r001216_4_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_135_1 + (pub_r001216_8_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_135_2 + (pub_r001216_8_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001216_1_1 * 2) + 49) & 63;
  int stage_v_177_2 = ((pub_r001216_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001216_2_1 * 2) + 20) & 63;
  int stage_v_178_2 = ((pub_r001216_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_140_1 + (pub_r001216_13_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_140_2 + (pub_r001216_13_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_98_1 + (pub_r001216_4_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_98_2 + (pub_r001216_4_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_114_1 + (pub_r001216_3_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_114_2 + (pub_r001216_3_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_107_1 + (pub_r001216_2_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_107_2 + (pub_r001216_2_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001216_5_1 * 2) + 11) & 63;
  int stage_v_183_2 = ((pub_r001216_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_143_1 + (pub_r001216_0_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_143_2 + (pub_r001216_0_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_81_1 + (pub_r001216_6_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_81_2 + (pub_r001216_6_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_26_1 + (pub_r001216_14_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_26_2 + (pub_r001216_14_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_4_1 + (pub_r001216_20_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_4_2 + (pub_r001216_20_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001216_15_1 * 2) + 49) & 63;
  int stage_v_188_2 = ((pub_r001216_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_103_1 + (pub_r001216_7_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_103_2 + (pub_r001216_7_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001216_18_1 * 2) + 34) & 63;
  int stage_v_190_2 = ((pub_r001216_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001216_0_1 * 2) + 47) & 63;
  int stage_v_191_2 = ((pub_r001216_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001216_18_1 * 2) + 13) & 63;
  int stage_v_192_2 = ((pub_r001216_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001216_20_1 * 2) + 18) & 63;
  int stage_v_193_2 = ((pub_r001216_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_20_1 + (pub_r001216_5_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_20_2 + (pub_r001216_5_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_108_1 + (pub_r001216_17_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_108_2 + (pub_r001216_17_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_99_1 + (pub_r001216_6_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_99_2 + (pub_r001216_6_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_70_1 + (pub_r001216_12_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_70_2 + (pub_r001216_12_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_118_1 + (pub_r001216_19_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_118_2 + (pub_r001216_19_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_137_1 + (pub_r001216_20_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_137_2 + (pub_r001216_20_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001216_0_1 * 2) + 11) & 63;
  int stage_v_200_2 = ((pub_r001216_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_115_1 + (pub_r001216_16_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_115_2 + (pub_r001216_16_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_121_1 + (pub_r001216_3_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_121_2 + (pub_r001216_3_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001216_19_1 * 2) + 26) & 63;
  int stage_v_203_2 = ((pub_r001216_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001216_20_1 * 2) + 22) & 63;
  int stage_v_204_2 = ((pub_r001216_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((sec_r001216_0_1 + (pub_r001216_7_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((sec_r001216_0_2 + (pub_r001216_7_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001216_3_1 * 2) + 24) & 63;
  int stage_v_206_2 = ((pub_r001216_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001216_4_1 * 2) + 25) & 63;
  int stage_v_207_2 = ((pub_r001216_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_24_1 + (pub_r001216_12_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_24_2 + (pub_r001216_12_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_39_1 + (pub_r001216_13_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_39_2 + (pub_r001216_13_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001216_19_1 * 2) + 25) & 63;
  int stage_v_210_2 = ((pub_r001216_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((helper_flow_5_1 + (pub_r001216_16_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_5_2 + (pub_r001216_16_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001216_5_1 * 2) + 28) & 63;
  int stage_v_212_2 = ((pub_r001216_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((helper_flow_5_1 + (pub_r001216_9_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((helper_flow_5_2 + (pub_r001216_9_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_125_1 + (pub_r001216_18_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_125_2 + (pub_r001216_18_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001216_1_1 * 2) + 44) & 63;
  int stage_v_215_2 = ((pub_r001216_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((helper_flow_6_1 + (pub_r001216_18_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((helper_flow_6_2 + (pub_r001216_18_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((pub_r001216_3_1 * 2) + 24) & 63;
  int stage_v_217_2 = ((pub_r001216_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_13_1 + (pub_r001216_5_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_13_2 + (pub_r001216_5_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_29_1 + (pub_r001216_8_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_29_2 + (pub_r001216_8_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001216_17_1 * 2) + 35) & 63;
  int stage_v_220_2 = ((pub_r001216_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001216_7_1 * 2) + 40) & 63;
  int stage_v_221_2 = ((pub_r001216_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_110_1 + (pub_r001216_2_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_110_2 + (pub_r001216_2_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_179_1 + (pub_r001216_17_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_179_2 + (pub_r001216_17_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_89_1 + (pub_r001216_3_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_89_2 + (pub_r001216_3_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_107_1 + (pub_r001216_15_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_107_2 + (pub_r001216_15_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_66_1 + (pub_r001216_14_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_66_2 + (pub_r001216_14_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001216_4_1 * 2) + 38) & 63;
  int stage_v_227_2 = ((pub_r001216_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((stage_v_160_1 + (pub_r001216_4_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_160_2 + (pub_r001216_4_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((pub_r001216_2_1 * 2) + 12) & 63;
  int stage_v_229_2 = ((pub_r001216_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001216_3_1 * 2) + 42) & 63;
  int stage_v_230_2 = ((pub_r001216_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_108_1 + (pub_r001216_12_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_108_2 + (pub_r001216_12_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001216_19_1 * 2) + 26) & 63;
  int stage_v_232_2 = ((pub_r001216_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((helper_flow_1_1 + (pub_r001216_8_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((helper_flow_1_2 + (pub_r001216_8_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001216_15_1 * 2) + 11) & 63;
  int stage_v_234_2 = ((pub_r001216_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((helper_flow_1_1 + (pub_r001216_20_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((helper_flow_1_2 + (pub_r001216_20_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_179_1 + (pub_r001216_5_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_179_2 + (pub_r001216_5_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((sec_r001216_9_1 + (pub_r001216_11_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((sec_r001216_9_2 + (pub_r001216_11_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((pub_r001216_1_1 * 2) + 12) & 63;
  int stage_v_238_2 = ((pub_r001216_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001216_18_1 * 2) + 49) & 63;
  int stage_v_239_2 = ((pub_r001216_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_29_1 + (pub_r001216_9_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_29_2 + (pub_r001216_9_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_198_1 + (pub_r001216_9_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_198_2 + (pub_r001216_9_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((pub_r001216_19_1 * 2) + 8) & 63;
  int stage_v_242_2 = ((pub_r001216_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_201_1 + (pub_r001216_18_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_201_2 + (pub_r001216_18_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((pub_r001216_7_1 * 2) + 37) & 63;
  int stage_v_244_2 = ((pub_r001216_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001216_6_1 * 2) + 19) & 63;
  int stage_v_245_2 = ((pub_r001216_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001216_7_1 * 2) + 25) & 63;
  int stage_v_246_2 = ((pub_r001216_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_60_1 + (pub_r001216_13_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_60_2 + (pub_r001216_13_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((stage_v_54_1 + (pub_r001216_11_1 * 2)) + 749) & 127;
  int stage_v_248_2 = ((stage_v_54_2 + (pub_r001216_11_2 * 2)) + 749) & 127;
  if (stage_v_248_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_248_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_248_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_248_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_249_1 = ((stage_v_93_1 + (pub_r001216_16_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_93_2 + (pub_r001216_16_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((stage_v_143_1 + (pub_r001216_7_1 * 2)) + 755) & 127;
  int stage_v_250_2 = ((stage_v_143_2 + (pub_r001216_7_2 * 2)) + 755) & 127;
  if (stage_v_250_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_250_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_250_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_250_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_251_1 = ((stage_v_62_1 + (pub_r001216_3_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((stage_v_62_2 + (pub_r001216_3_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((helper_flow_5_1 + (pub_r001216_5_1 * 2)) + 761) & 127;
  int stage_v_252_2 = ((helper_flow_5_2 + (pub_r001216_5_2 * 2)) + 761) & 127;
  if (stage_v_252_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_252_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_252_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_252_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_253_1 = ((helper_flow_2_1 + (pub_r001216_2_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((helper_flow_2_2 + (pub_r001216_2_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001216_20_1 != sec_r001216_20_2);
  __CPROVER_assume(pub_r001216_10_1 == pub_r001216_10_2);
  __CPROVER_assume(sec_r001216_5_1 != sec_r001216_5_2);
  __CPROVER_assume(sec_r001216_18_1 != sec_r001216_18_2);
  __CPROVER_assume(pub_r001216_2_1 == pub_r001216_2_2);
  __CPROVER_assume(sec_r001216_3_1 != sec_r001216_3_2);
  __CPROVER_assume(sec_r001216_16_1 != sec_r001216_16_2);
  __CPROVER_assume(sec_r001216_0_1 != sec_r001216_0_2);
  __CPROVER_assume(pub_r001216_9_1 == pub_r001216_9_2);
  __CPROVER_assume(sec_r001216_15_1 != sec_r001216_15_2);
  __CPROVER_assume(pub_r001216_6_1 == pub_r001216_6_2);
  __CPROVER_assume(sec_r001216_1_1 != sec_r001216_1_2);
  __CPROVER_assume(sec_r001216_10_1 != sec_r001216_10_2);
  __CPROVER_assume(sec_r001216_2_1 != sec_r001216_2_2);
  __CPROVER_assume(pub_r001216_12_1 == pub_r001216_12_2);
  __CPROVER_assume(pub_r001216_8_1 == pub_r001216_8_2);
  __CPROVER_assume(sec_r001216_19_1 != sec_r001216_19_2);
  __CPROVER_assume(sec_r001216_12_1 != sec_r001216_12_2);
  __CPROVER_assume(sec_r001216_6_1 != sec_r001216_6_2);
  __CPROVER_assume(pub_r001216_5_1 == pub_r001216_5_2);
  __CPROVER_assume(pub_r001216_3_1 == pub_r001216_3_2);
  __CPROVER_assume(sec_r001216_4_1 != sec_r001216_4_2);
  __CPROVER_assume(sec_r001216_13_1 != sec_r001216_13_2);
  __CPROVER_assume(sec_r001216_7_1 != sec_r001216_7_2);
  __CPROVER_assume(pub_r001216_19_1 == pub_r001216_19_2);
  __CPROVER_assume(pub_r001216_16_1 == pub_r001216_16_2);
  __CPROVER_assume(pub_r001216_0_1 == pub_r001216_0_2);
  __CPROVER_assume(sec_r001216_11_1 != sec_r001216_11_2);
  __CPROVER_assume(sec_r001216_14_1 != sec_r001216_14_2);
  __CPROVER_assume(pub_r001216_13_1 == pub_r001216_13_2);
  __CPROVER_assume(pub_r001216_14_1 == pub_r001216_14_2);
  __CPROVER_assume(pub_r001216_11_1 == pub_r001216_11_2);
  __CPROVER_assume(pub_r001216_20_1 == pub_r001216_20_2);
  __CPROVER_assume(pub_r001216_17_1 == pub_r001216_17_2);
  __CPROVER_assume(pub_r001216_4_1 == pub_r001216_4_2);
  __CPROVER_assume(pub_r001216_18_1 == pub_r001216_18_2);
  __CPROVER_assume(sec_r001216_8_1 != sec_r001216_8_2);
  __CPROVER_assume(pub_r001216_7_1 == pub_r001216_7_2);
  __CPROVER_assume(pub_r001216_15_1 == pub_r001216_15_2);
  __CPROVER_assume(pub_r001216_1_1 == pub_r001216_1_2);
  __CPROVER_assume(sec_r001216_17_1 != sec_r001216_17_2);
  __CPROVER_assume(sec_r001216_9_1 != sec_r001216_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.gain == st_var_1_2.gain);
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
  assert(stage_v_247_1 == stage_v_247_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(stage_v_253_1 == stage_v_253_2);
}


