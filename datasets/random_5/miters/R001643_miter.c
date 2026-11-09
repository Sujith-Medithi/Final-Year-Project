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
struct SensorNode_R001643_4313_0
{
  short offset;
  unsigned char status;
  int reading;
  int buffer[3];
};
struct StreamBuffer_R001643_4313_1
{
  int head;
  short capacity;
  short watermark;
  int buffer[3];
};
struct EventLog_R001643_4313_2
{
  int facility;
  unsigned char code;
  int timestamp;
  int buffer[3];
};
struct AudioFrame_R001643_4313_3
{
  short envelope;
  int sample_rate;
  unsigned char channels;
  int peak;
  int gain;
  int buffer[3];
};
union PacketPayload_R001643_4313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001643_4313_1
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
void fn_R001643_4313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st_1 = {0};
  struct EventLog_R001643_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tally_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_83_1) & 63;
  aux_2 = (aux_2 + tally_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_35_1 = 0;
  int quantum_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_35_1 = ((quantum_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_35_2 = ((quantum_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_35_1) & 127;
    acc_2 = (acc_2 + quantum_35_2) & 127;
  }

  int damping_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_48_1)
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

  switch (damping_48_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_83_1 == tally_83_2);
  assert(quantum_35_1 == quantum_35_2);
  assert(damping_48_1 == damping_48_2);
}

int fn_R001643_4313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tally_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_83) & 63;
  acc ^= aux;
  int quantum_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_35 = ((quantum_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_35) & 127;
  }

  int damping_48 = (aux + st.buffer[1]) & 3;
  switch (damping_48)
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

void fn_R001643_4313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_94_1 > 44)
  {
    acc_1 = ((acc_1 + (tally_94_1 * 2)) + 5) & 127;
    aux_1 ^= tally_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_94_2 > 44)
  {
    acc_2 = ((acc_2 + (tally_94_2 * 2)) + 5) & 127;
    aux_2 ^= tally_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_47_1 = 0;
  int anchor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_47_1 = ((anchor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_47_2 = ((anchor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_47_1) & 127;
    acc_2 = (acc_2 + anchor_47_2) & 127;
  }

  int quantum_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_22_1)
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

  switch (quantum_22_2)
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

  int index_reg_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_12_1) & 63;
  aux_2 = (aux_2 + index_reg_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_94_1 == tally_94_2);
  assert(anchor_47_1 == anchor_47_2);
  assert(quantum_22_1 == quantum_22_2);
  assert(index_reg_12_1 == index_reg_12_2);
}

int fn_R001643_4313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_94 > 44)
  {
    acc = ((acc + (tally_94 * 2)) + 5) & 127;
    aux ^= tally_94 & 15;
  }
  else
  {
    acc = ((acc - tally_94) + 11) & 127;
    aux += 3;
  }
  int anchor_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_47 = ((anchor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_47) & 127;
  }

  int quantum_22 = (aux + st.buffer[1]) & 3;
  switch (quantum_22)
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

  int index_reg_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001643_4313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st_1 = {0};
  struct EventLog_R001643_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_95_1 = 0;
  int factor_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_95_1 = ((factor_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_95_2 = ((factor_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_95_1) & 127;
    acc_2 = (acc_2 + factor_95_2) & 127;
  }

  int offset_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_16_1) & 63;
  aux_2 = (aux_2 + offset_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_95_1 == factor_95_2);
  assert(offset_16_1 == offset_16_2);
}

int fn_R001643_4313_2(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_95 = ((factor_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_95) & 127;
  }

  int offset_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_37_1 = 0;
  int quotient_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_37_1 = ((quotient_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_37_2 = ((quotient_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_37_1) & 127;
    acc_2 = (acc_2 + quotient_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_89_1) & 63;
  aux_2 = (aux_2 + checksum_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_44_1)
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

  switch (bound_44_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_37_1 == quotient_37_2);
  assert(checksum_89_1 == checksum_89_2);
  assert(bound_44_1 == bound_44_2);
}

int fn_R001643_4313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_37 = ((quotient_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_89) & 63;
  acc ^= aux;
  int bound_44 = (aux + st.buffer[1]) & 3;
  switch (bound_44)
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

void fn_R001643_4313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st_1 = {0};
  struct EventLog_R001643_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_78_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_78_1 * 2)) + 5) & 127;
    aux_1 ^= tally_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_78_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_78_2 * 2)) + 5) & 127;
    aux_2 ^= tally_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_51_1 = local_arr_1[aux_1 % 3];
  int coefficient_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_78_1 == tally_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_51_1 == coefficient_51_2);
}

int fn_R001643_4313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_78 > 33)
  {
    acc = ((acc + (tally_78 * 2)) + 5) & 127;
    aux ^= tally_78 & 15;
  }
  else
  {
    acc = ((acc - tally_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_51 = local_arr[aux % 3];
  acc = (acc + (coefficient_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_50_1 > 33)
  {
    acc_1 = ((acc_1 + (window_50_1 * 2)) + 5) & 127;
    aux_1 ^= window_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_50_2 > 33)
  {
    acc_2 = ((acc_2 + (window_50_2 * 2)) + 5) & 127;
    aux_2 ^= window_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_62_1 = 0;
  int damping_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_62_1 = ((damping_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_62_2 = ((damping_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_62_1) & 127;
    acc_2 = (acc_2 + damping_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_50_1 == window_50_2);
  assert(damping_62_1 == damping_62_2);
}

int fn_R001643_4313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_50 > 33)
  {
    acc = ((acc + (window_50 * 2)) + 5) & 127;
    aux ^= window_50 & 15;
  }
  else
  {
    acc = ((acc - window_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_62 = ((damping_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001643_4313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_41_1) & 63;
  aux_2 = (aux_2 + sample_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_41_1 == sample_41_2);
}

int fn_R001643_4313_6(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_74_1 = local_arr_1[aux_1 % 3];
  int bound_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_74_2 * 2)) & 127;
  int threshold_52_1 = 0;
  int threshold_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_52_1 = ((threshold_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_52_2 = ((threshold_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_52_1) & 127;
    acc_2 = (acc_2 + threshold_52_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_74_1 == bound_74_2);
  assert(threshold_52_1 == threshold_52_2);
}

int fn_R001643_4313_7(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int bound_74 = local_arr[aux % 3];
  acc = (acc + (bound_74 * 2)) & 127;
  int threshold_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_52 = ((threshold_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_52) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001643_4313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_91_1 = local_arr_1[aux_1 % 3];
  int threshold_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_91_2 * 2)) & 127;
  int coefficient_80_1 = 0;
  int coefficient_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_80_1 = ((coefficient_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_80_2 = ((coefficient_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_80_1) & 127;
    acc_2 = (acc_2 + coefficient_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_91_1 == threshold_91_2);
  assert(coefficient_80_1 == coefficient_80_2);
}

int fn_R001643_4313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int threshold_91 = local_arr[aux % 3];
  acc = (acc + (threshold_91 * 2)) & 127;
  int coefficient_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_80 = ((coefficient_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001643_4313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_71_1)
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

  switch (vector_71_2)
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
  int factor_31_1 = local_arr_1[aux_1 % 3];
  int factor_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_71_1 == vector_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_31_1 == factor_31_2);
}

int fn_R001643_4313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_71 = (aux + st.buffer[1]) & 3;
  switch (vector_71)
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
  int factor_31 = local_arr[aux % 3];
  acc = (acc + (factor_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st_1 = {0};
  struct EventLog_R001643_4313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int cursor_91_1 = 0;
  int cursor_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_91_1 = ((cursor_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_91_2 = ((cursor_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_91_1) & 127;
    acc_2 = (acc_2 + cursor_91_2) & 127;
  }

  int tally_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_96_1) & 63;
  aux_2 = (aux_2 + tally_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_37_1 > 24)
  {
    acc_1 = ((acc_1 + (sample_37_1 * 2)) + 5) & 127;
    aux_1 ^= sample_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_37_2 > 24)
  {
    acc_2 = ((acc_2 + (sample_37_2 * 2)) + 5) & 127;
    aux_2 ^= sample_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_91_1 == cursor_91_2);
  assert(tally_96_1 == tally_96_2);
  assert(sample_37_1 == sample_37_2);
}

int fn_R001643_4313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001643_4313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int cursor_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_91 = ((cursor_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_91) & 127;
  }

  int tally_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_96) & 63;
  acc ^= aux;
  int sample_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_37 > 24)
  {
    acc = ((acc + (sample_37 * 2)) + 5) & 127;
    aux ^= sample_37 & 15;
  }
  else
  {
    acc = ((acc - sample_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_94_1 = local_arr_1[aux_1 % 3];
  int quantum_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_94_2 * 2)) & 127;
  int stride_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_99_1)
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

  switch (stride_99_2)
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

  int anchor_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_92_1) & 63;
  aux_2 = (aux_2 + anchor_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_94_1 == quantum_94_2);
  assert(stride_99_1 == stride_99_2);
  assert(anchor_92_1 == anchor_92_2);
}

int fn_R001643_4313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int quantum_94 = local_arr[aux % 3];
  acc = (acc + (quantum_94 * 2)) & 127;
  int stride_99 = (aux + st.buffer[1]) & 3;
  switch (stride_99)
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

  int anchor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001643_4313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_93_1 = local_arr_1[aux_1 % 3];
  int factor_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_93_2 * 2)) & 127;
  int bound_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_89_1)
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

  switch (bound_89_2)
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

  int residue_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_79_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_79_1 * 2)) + 5) & 127;
    aux_1 ^= residue_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_79_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_79_2 * 2)) + 5) & 127;
    aux_2 ^= residue_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_99_1 = 0;
  int cursor_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_99_1 = ((cursor_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_99_2 = ((cursor_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_99_1) & 127;
    acc_2 = (acc_2 + cursor_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_93_1 == factor_93_2);
  assert(bound_89_1 == bound_89_2);
  assert(residue_79_1 == residue_79_2);
  assert(cursor_99_1 == cursor_99_2);
}

int fn_R001643_4313_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int factor_93 = local_arr[aux % 3];
  acc = (acc + (factor_93 * 2)) & 127;
  int bound_89 = (aux + st.buffer[1]) & 3;
  switch (bound_89)
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

  int residue_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_79 > 34)
  {
    acc = ((acc + (residue_79 * 2)) + 5) & 127;
    aux ^= residue_79 & 15;
  }
  else
  {
    acc = ((acc - residue_79) + 11) & 127;
    aux += 3;
  }
  int cursor_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_99 = ((cursor_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001643_4313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_47_1)
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

  switch (scale_47_2)
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
  int mask_86_1 = local_arr_1[aux_1 % 3];
  int mask_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_47_1 == scale_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_86_1 == mask_86_2);
}

int fn_R001643_4313_13(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_47 = (aux + st.buffer[1]) & 3;
  switch (scale_47)
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
  int mask_86 = local_arr[aux % 3];
  acc = (acc + (mask_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_55_1 = local_arr_1[aux_1 % 3];
  int phase_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_55_1 == phase_55_2);
}

int fn_R001643_4313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_55 = local_arr[aux % 3];
  acc = (acc + (phase_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_51_1 > 26)
  {
    acc_1 = ((acc_1 + (sample_51_1 * 2)) + 5) & 127;
    aux_1 ^= sample_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_51_2 > 26)
  {
    acc_2 = ((acc_2 + (sample_51_2 * 2)) + 5) & 127;
    aux_2 ^= sample_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_63_1 = local_arr_1[aux_1 % 3];
  int bound_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_63_2 * 2)) & 127;
  int phase_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_65_1) & 63;
  aux_2 = (aux_2 + phase_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_51_1 == sample_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_63_1 == bound_63_2);
  assert(phase_65_1 == phase_65_2);
  assert(accumulator_57_1 == accumulator_57_2);
}

int fn_R001643_4313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_51 > 26)
  {
    acc = ((acc + (sample_51 * 2)) + 5) & 127;
    aux ^= sample_51 & 15;
  }
  else
  {
    acc = ((acc - sample_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_63 = local_arr[aux % 3];
  acc = (acc + (bound_63 * 2)) & 127;
  int phase_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_65) & 63;
  acc ^= aux;
  int accumulator_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001643_4313_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_23_1) & 63;
  aux_2 = (aux_2 + tracker_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_50_1)
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

  switch (margin_50_2)
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

  int scale_68_1 = 0;
  int scale_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_68_1 = ((scale_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_68_2 = ((scale_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_68_1) & 127;
    acc_2 = (acc_2 + scale_68_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_23_1 == tracker_23_2);
  assert(margin_50_1 == margin_50_2);
  assert(scale_68_1 == scale_68_2);
}

int fn_R001643_4313_16(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_23) & 63;
  acc ^= aux;
  int margin_50 = (aux + st.buffer[1]) & 3;
  switch (margin_50)
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

  int scale_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_68 = ((scale_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_68) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_68_1 = local_arr_1[aux_1 % 3];
  int margin_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_68_2 * 2)) & 127;
  int factor_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_58_1 > 38)
  {
    acc_1 = ((acc_1 + (factor_58_1 * 2)) + 5) & 127;
    aux_1 ^= factor_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_58_2 > 38)
  {
    acc_2 = ((acc_2 + (factor_58_2 * 2)) + 5) & 127;
    aux_2 ^= factor_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_90_1 = 0;
  int accumulator_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_90_1 = ((accumulator_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_90_2 = ((accumulator_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_90_1) & 127;
    acc_2 = (acc_2 + accumulator_90_2) & 127;
  }

  int quantum_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_56_1)
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

  switch (quantum_56_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_68_1 == margin_68_2);
  assert(factor_58_1 == factor_58_2);
  assert(accumulator_90_1 == accumulator_90_2);
  assert(quantum_56_1 == quantum_56_2);
}

int fn_R001643_4313_17(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int margin_68 = local_arr[aux % 3];
  acc = (acc + (margin_68 * 2)) & 127;
  int factor_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_58 > 38)
  {
    acc = ((acc + (factor_58 * 2)) + 5) & 127;
    aux ^= factor_58 & 15;
  }
  else
  {
    acc = ((acc - factor_58) + 11) & 127;
    aux += 3;
  }
  int accumulator_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_90 = ((accumulator_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_90) & 127;
  }

  int quantum_56 = (aux + st.buffer[1]) & 3;
  switch (quantum_56)
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

void fn_R001643_4313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st_1 = {0};
  struct SensorNode_R001643_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_24_1)
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

  switch (delta_24_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_24_1 == delta_24_2);
}

int fn_R001643_4313_18(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001643_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_24 = (aux + st.buffer[1]) & 3;
  switch (delta_24)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001643_4313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_36_1 = local_arr_1[aux_1 % 3];
  int tally_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_36_2 * 2)) & 127;
  int sample_54_1 = 0;
  int sample_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_54_1 = ((sample_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_54_2 = ((sample_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_54_1) & 127;
    acc_2 = (acc_2 + sample_54_2) & 127;
  }

  int quotient_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_86_1)
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

  switch (quotient_86_2)
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

  int damping_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_35_1) & 63;
  aux_2 = (aux_2 + damping_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_36_1 == tally_36_2);
  assert(sample_54_1 == sample_54_2);
  assert(quotient_86_1 == quotient_86_2);
  assert(damping_35_1 == damping_35_2);
}

int fn_R001643_4313_19(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int tally_36 = local_arr[aux % 3];
  acc = (acc + (tally_36 * 2)) & 127;
  int sample_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_54 = ((sample_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_54) & 127;
  }

  int quotient_86 = (aux + st.buffer[1]) & 3;
  switch (quotient_86)
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

  int damping_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001643_4313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st_1 = {0};
  struct AudioFrame_R001643_4313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_29_1) & 63;
  aux_2 = (aux_2 + margin_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_29_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_29_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_29_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_29_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_29_1 == margin_29_2);
  assert(checksum_29_1 == checksum_29_2);
}

int fn_R001643_4313_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001643_4313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_29) & 63;
  acc ^= aux;
  int checksum_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_29 > 30)
  {
    acc = ((acc + (checksum_29 * 2)) + 5) & 127;
    aux ^= checksum_29 & 15;
  }
  else
  {
    acc = ((acc - checksum_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001643_4313_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_15_1) & 63;
  aux_2 = (aux_2 + quotient_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_43_1)
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

  switch (sample_43_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_15_1 == quotient_15_2);
  assert(sample_43_1 == sample_43_2);
}

int fn_R001643_4313_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_15) & 63;
  acc ^= aux;
  int sample_43 = (aux + st.buffer[1]) & 3;
  switch (sample_43)
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

void fn_R001643_4313_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_98_1) & 63;
  aux_2 = (aux_2 + weight_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_33_1 = 0;
  int stride_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_33_1 = ((stride_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_33_2 = ((stride_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_33_1) & 127;
    acc_2 = (acc_2 + stride_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_42_1)
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

  switch (vector_42_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_98_1 == weight_98_2);
  assert(stride_33_1 == stride_33_2);
  assert(vector_42_1 == vector_42_2);
}

int fn_R001643_4313_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001643_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_98) & 63;
  acc ^= aux;
  int stride_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_33 = ((stride_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_42 = (aux + st.buffer[1]) & 3;
  switch (vector_42)
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

void main()
{
  int sec_r001643_0_1;
  int sec_r001643_0_2;
  int sec_r001643_1_1;
  int sec_r001643_1_2;
  int sec_r001643_2_1;
  int sec_r001643_2_2;
  int sec_r001643_3_1;
  int sec_r001643_3_2;
  int sec_r001643_4_1;
  int sec_r001643_4_2;
  int sec_r001643_5_1;
  int sec_r001643_5_2;
  int sec_r001643_6_1;
  int sec_r001643_6_2;
  int sec_r001643_7_1;
  int sec_r001643_7_2;
  int sec_r001643_8_1;
  int sec_r001643_8_2;
  int sec_r001643_9_1;
  int sec_r001643_9_2;
  int sec_r001643_10_1;
  int sec_r001643_10_2;
  int sec_r001643_11_1;
  int sec_r001643_11_2;
  int sec_r001643_12_1;
  int sec_r001643_12_2;
  int sec_r001643_13_1;
  int sec_r001643_13_2;
  int sec_r001643_14_1;
  int sec_r001643_14_2;
  int sec_r001643_15_1;
  int sec_r001643_15_2;
  int sec_r001643_16_1;
  int sec_r001643_16_2;
  int sec_r001643_17_1;
  int sec_r001643_17_2;
  int pub_r001643_0_1;
  int pub_r001643_0_2;
  int pub_r001643_1_1;
  int pub_r001643_1_2;
  int pub_r001643_2_1;
  int pub_r001643_2_2;
  int pub_r001643_3_1;
  int pub_r001643_3_2;
  int pub_r001643_4_1;
  int pub_r001643_4_2;
  int pub_r001643_5_1;
  int pub_r001643_5_2;
  int pub_r001643_6_1;
  int pub_r001643_6_2;
  int pub_r001643_7_1;
  int pub_r001643_7_2;
  int pub_r001643_8_1;
  int pub_r001643_8_2;
  int pub_r001643_9_1;
  int pub_r001643_9_2;
  int pub_r001643_10_1;
  int pub_r001643_10_2;
  int pub_r001643_11_1;
  int pub_r001643_11_2;
  int pub_r001643_12_1;
  int pub_r001643_12_2;
  int pub_r001643_13_1;
  int pub_r001643_13_2;
  int pub_r001643_14_1;
  int pub_r001643_14_2;
  int pub_r001643_15_1;
  int pub_r001643_15_2;
  int pub_r001643_16_1;
  int pub_r001643_16_2;
  int pub_r001643_17_1;
  int pub_r001643_17_2;
  int pub_r001643_18_1;
  int pub_r001643_18_2;
  int pub_r001643_19_1;
  int pub_r001643_19_2;
  int pub_r001643_20_1;
  int pub_r001643_20_2;
  int pub_r001643_21_1;
  int pub_r001643_21_2;
  int pub_r001643_22_1;
  int pub_r001643_22_2;
  int pub_r001643_23_1;
  int pub_r001643_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001643_0_1 >= (-100)) && (pub_r001643_0_1 <= 100));
  __CPROVER_assume((pub_r001643_0_2 >= (-100)) && (pub_r001643_0_2 <= 100));
  __CPROVER_assume((pub_r001643_1_1 >= (-100)) && (pub_r001643_1_1 <= 100));
  __CPROVER_assume((pub_r001643_1_2 >= (-100)) && (pub_r001643_1_2 <= 100));
  __CPROVER_assume((pub_r001643_2_1 >= (-100)) && (pub_r001643_2_1 <= 100));
  __CPROVER_assume((pub_r001643_2_2 >= (-100)) && (pub_r001643_2_2 <= 100));
  __CPROVER_assume((pub_r001643_3_1 >= (-100)) && (pub_r001643_3_1 <= 100));
  __CPROVER_assume((pub_r001643_3_2 >= (-100)) && (pub_r001643_3_2 <= 100));
  __CPROVER_assume((pub_r001643_4_1 >= (-100)) && (pub_r001643_4_1 <= 100));
  __CPROVER_assume((pub_r001643_4_2 >= (-100)) && (pub_r001643_4_2 <= 100));
  __CPROVER_assume((pub_r001643_5_1 >= (-100)) && (pub_r001643_5_1 <= 100));
  __CPROVER_assume((pub_r001643_5_2 >= (-100)) && (pub_r001643_5_2 <= 100));
  __CPROVER_assume((pub_r001643_6_1 >= (-100)) && (pub_r001643_6_1 <= 100));
  __CPROVER_assume((pub_r001643_6_2 >= (-100)) && (pub_r001643_6_2 <= 100));
  __CPROVER_assume((pub_r001643_7_1 >= (-100)) && (pub_r001643_7_1 <= 100));
  __CPROVER_assume((pub_r001643_7_2 >= (-100)) && (pub_r001643_7_2 <= 100));
  __CPROVER_assume((pub_r001643_8_1 >= (-100)) && (pub_r001643_8_1 <= 100));
  __CPROVER_assume((pub_r001643_8_2 >= (-100)) && (pub_r001643_8_2 <= 100));
  __CPROVER_assume((pub_r001643_9_1 >= (-100)) && (pub_r001643_9_1 <= 100));
  __CPROVER_assume((pub_r001643_9_2 >= (-100)) && (pub_r001643_9_2 <= 100));
  __CPROVER_assume((pub_r001643_10_1 >= (-100)) && (pub_r001643_10_1 <= 100));
  __CPROVER_assume((pub_r001643_10_2 >= (-100)) && (pub_r001643_10_2 <= 100));
  __CPROVER_assume((pub_r001643_11_1 >= (-100)) && (pub_r001643_11_1 <= 100));
  __CPROVER_assume((pub_r001643_11_2 >= (-100)) && (pub_r001643_11_2 <= 100));
  __CPROVER_assume((pub_r001643_12_1 >= (-100)) && (pub_r001643_12_1 <= 100));
  __CPROVER_assume((pub_r001643_12_2 >= (-100)) && (pub_r001643_12_2 <= 100));
  __CPROVER_assume((pub_r001643_13_1 >= (-100)) && (pub_r001643_13_1 <= 100));
  __CPROVER_assume((pub_r001643_13_2 >= (-100)) && (pub_r001643_13_2 <= 100));
  __CPROVER_assume((pub_r001643_14_1 >= (-100)) && (pub_r001643_14_1 <= 100));
  __CPROVER_assume((pub_r001643_14_2 >= (-100)) && (pub_r001643_14_2 <= 100));
  __CPROVER_assume((pub_r001643_15_1 >= (-100)) && (pub_r001643_15_1 <= 100));
  __CPROVER_assume((pub_r001643_15_2 >= (-100)) && (pub_r001643_15_2 <= 100));
  __CPROVER_assume((pub_r001643_16_1 >= (-100)) && (pub_r001643_16_1 <= 100));
  __CPROVER_assume((pub_r001643_16_2 >= (-100)) && (pub_r001643_16_2 <= 100));
  __CPROVER_assume((pub_r001643_17_1 >= (-100)) && (pub_r001643_17_1 <= 100));
  __CPROVER_assume((pub_r001643_17_2 >= (-100)) && (pub_r001643_17_2 <= 100));
  __CPROVER_assume((pub_r001643_18_1 >= (-100)) && (pub_r001643_18_1 <= 100));
  __CPROVER_assume((pub_r001643_18_2 >= (-100)) && (pub_r001643_18_2 <= 100));
  __CPROVER_assume((pub_r001643_19_1 >= (-100)) && (pub_r001643_19_1 <= 100));
  __CPROVER_assume((pub_r001643_19_2 >= (-100)) && (pub_r001643_19_2 <= 100));
  __CPROVER_assume((pub_r001643_20_1 >= (-100)) && (pub_r001643_20_1 <= 100));
  __CPROVER_assume((pub_r001643_20_2 >= (-100)) && (pub_r001643_20_2 <= 100));
  __CPROVER_assume((pub_r001643_21_1 >= (-100)) && (pub_r001643_21_1 <= 100));
  __CPROVER_assume((pub_r001643_21_2 >= (-100)) && (pub_r001643_21_2 <= 100));
  __CPROVER_assume((pub_r001643_22_1 >= (-100)) && (pub_r001643_22_1 <= 100));
  __CPROVER_assume((pub_r001643_22_2 >= (-100)) && (pub_r001643_22_2 <= 100));
  __CPROVER_assume((pub_r001643_23_1 >= (-100)) && (pub_r001643_23_1 <= 100));
  __CPROVER_assume((pub_r001643_23_2 >= (-100)) && (pub_r001643_23_2 <= 100));
  __CPROVER_assume((sec_r001643_0_1 >= 0) && (sec_r001643_0_1 <= 255));
  __CPROVER_assume((sec_r001643_0_2 >= 0) && (sec_r001643_0_2 <= 255));
  __CPROVER_assume((sec_r001643_1_1 >= 0) && (sec_r001643_1_1 <= 255));
  __CPROVER_assume((sec_r001643_1_2 >= 0) && (sec_r001643_1_2 <= 255));
  __CPROVER_assume((sec_r001643_2_1 >= 0) && (sec_r001643_2_1 <= 255));
  __CPROVER_assume((sec_r001643_2_2 >= 0) && (sec_r001643_2_2 <= 255));
  __CPROVER_assume((sec_r001643_3_1 >= 0) && (sec_r001643_3_1 <= 255));
  __CPROVER_assume((sec_r001643_3_2 >= 0) && (sec_r001643_3_2 <= 255));
  __CPROVER_assume((sec_r001643_4_1 >= 0) && (sec_r001643_4_1 <= 255));
  __CPROVER_assume((sec_r001643_4_2 >= 0) && (sec_r001643_4_2 <= 255));
  __CPROVER_assume((sec_r001643_5_1 >= 0) && (sec_r001643_5_1 <= 255));
  __CPROVER_assume((sec_r001643_5_2 >= 0) && (sec_r001643_5_2 <= 255));
  __CPROVER_assume((sec_r001643_6_1 >= 0) && (sec_r001643_6_1 <= 255));
  __CPROVER_assume((sec_r001643_6_2 >= 0) && (sec_r001643_6_2 <= 255));
  __CPROVER_assume((sec_r001643_7_1 >= 0) && (sec_r001643_7_1 <= 255));
  __CPROVER_assume((sec_r001643_7_2 >= 0) && (sec_r001643_7_2 <= 255));
  __CPROVER_assume((sec_r001643_8_1 >= 0) && (sec_r001643_8_1 <= 255));
  __CPROVER_assume((sec_r001643_8_2 >= 0) && (sec_r001643_8_2 <= 255));
  __CPROVER_assume((sec_r001643_9_1 >= 0) && (sec_r001643_9_1 <= 255));
  __CPROVER_assume((sec_r001643_9_2 >= 0) && (sec_r001643_9_2 <= 255));
  __CPROVER_assume((sec_r001643_10_1 >= 0) && (sec_r001643_10_1 <= 255));
  __CPROVER_assume((sec_r001643_10_2 >= 0) && (sec_r001643_10_2 <= 255));
  __CPROVER_assume((sec_r001643_11_1 >= 0) && (sec_r001643_11_1 <= 255));
  __CPROVER_assume((sec_r001643_11_2 >= 0) && (sec_r001643_11_2 <= 255));
  __CPROVER_assume((sec_r001643_12_1 >= 0) && (sec_r001643_12_1 <= 255));
  __CPROVER_assume((sec_r001643_12_2 >= 0) && (sec_r001643_12_2 <= 255));
  __CPROVER_assume((sec_r001643_13_1 >= 0) && (sec_r001643_13_1 <= 255));
  __CPROVER_assume((sec_r001643_13_2 >= 0) && (sec_r001643_13_2 <= 255));
  __CPROVER_assume((sec_r001643_14_1 >= 0) && (sec_r001643_14_1 <= 255));
  __CPROVER_assume((sec_r001643_14_2 >= 0) && (sec_r001643_14_2 <= 255));
  __CPROVER_assume((sec_r001643_15_1 >= 0) && (sec_r001643_15_1 <= 255));
  __CPROVER_assume((sec_r001643_15_2 >= 0) && (sec_r001643_15_2 <= 255));
  __CPROVER_assume((sec_r001643_16_1 >= 0) && (sec_r001643_16_1 <= 255));
  __CPROVER_assume((sec_r001643_16_2 >= 0) && (sec_r001643_16_2 <= 255));
  __CPROVER_assume((sec_r001643_17_1 >= 0) && (sec_r001643_17_1 <= 255));
  __CPROVER_assume((sec_r001643_17_2 >= 0) && (sec_r001643_17_2 <= 255));
  struct SensorNode_R001643_4313_0 st_var_0_1 = {0};
  struct SensorNode_R001643_4313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001643_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001643_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001643_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001643_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001643_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001643_0_2 + 7) & 15;
  struct StreamBuffer_R001643_4313_1 st_var_1_1 = {0};
  struct StreamBuffer_R001643_4313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001643_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001643_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001643_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001643_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001643_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001643_0_2 + 9) & 15;
  struct EventLog_R001643_4313_2 st_var_2_1 = {0};
  struct EventLog_R001643_4313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001643_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001643_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001643_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001643_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001643_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001643_0_2 + 11) & 15;
  struct AudioFrame_R001643_4313_3 st_var_3_1 = {0};
  struct AudioFrame_R001643_4313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001643_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001643_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001643_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001643_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001643_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001643_0_2 + 13) & 15;
  union PacketPayload_R001643_4313_0 u_var_1;
  union PacketPayload_R001643_4313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001643_4313_0(sec_r001643_0_1, pub_r001643_1_1, pub_r001643_2_1, pub_r001643_3_1);
  int helper_flow_0_2 = fn_R001643_4313_0(sec_r001643_0_2, pub_r001643_1_2, pub_r001643_2_2, pub_r001643_3_2);
  fn_R001643_4313_0_2(sec_r001643_0_1, pub_r001643_1_1, pub_r001643_2_1, pub_r001643_3_1, sec_r001643_0_2, pub_r001643_1_2, pub_r001643_2_2, pub_r001643_3_2);
  int helper_flow_1_1 = fn_R001643_4313_1(sec_r001643_1_1, pub_r001643_2_1, pub_r001643_3_1, pub_r001643_4_1);
  int helper_flow_1_2 = fn_R001643_4313_1(sec_r001643_1_2, pub_r001643_2_2, pub_r001643_3_2, pub_r001643_4_2);
  fn_R001643_4313_1_2(sec_r001643_1_1, pub_r001643_2_1, pub_r001643_3_1, pub_r001643_4_1, sec_r001643_1_2, pub_r001643_2_2, pub_r001643_3_2, pub_r001643_4_2);
  int helper_flow_2_1 = fn_R001643_4313_2(sec_r001643_2_1, pub_r001643_3_1);
  int helper_flow_2_2 = fn_R001643_4313_2(sec_r001643_2_2, pub_r001643_3_2);
  fn_R001643_4313_2_2(sec_r001643_2_1, pub_r001643_3_1, sec_r001643_2_2, pub_r001643_3_2);
  int helper_flow_3_1 = fn_R001643_4313_3(sec_r001643_3_1, pub_r001643_4_1, pub_r001643_5_1);
  int helper_flow_3_2 = fn_R001643_4313_3(sec_r001643_3_2, pub_r001643_4_2, pub_r001643_5_2);
  fn_R001643_4313_3_2(sec_r001643_3_1, pub_r001643_4_1, pub_r001643_5_1, sec_r001643_3_2, pub_r001643_4_2, pub_r001643_5_2);
  int helper_flow_4_1 = fn_R001643_4313_4(sec_r001643_4_1, sec_r001643_5_1, pub_r001643_6_1, pub_r001643_7_1);
  int helper_flow_4_2 = fn_R001643_4313_4(sec_r001643_4_2, sec_r001643_5_2, pub_r001643_6_2, pub_r001643_7_2);
  fn_R001643_4313_4_2(sec_r001643_4_1, sec_r001643_5_1, pub_r001643_6_1, pub_r001643_7_1, sec_r001643_4_2, sec_r001643_5_2, pub_r001643_6_2, pub_r001643_7_2);
  int helper_flow_5_1 = fn_R001643_4313_5(sec_r001643_5_1, pub_r001643_6_1, pub_r001643_7_1, pub_r001643_8_1, pub_r001643_9_1);
  int helper_flow_5_2 = fn_R001643_4313_5(sec_r001643_5_2, pub_r001643_6_2, pub_r001643_7_2, pub_r001643_8_2, pub_r001643_9_2);
  fn_R001643_4313_5_2(sec_r001643_5_1, pub_r001643_6_1, pub_r001643_7_1, pub_r001643_8_1, pub_r001643_9_1, sec_r001643_5_2, pub_r001643_6_2, pub_r001643_7_2, pub_r001643_8_2, pub_r001643_9_2);
  int helper_flow_6_1 = fn_R001643_4313_6(sec_r001643_6_1, pub_r001643_7_1);
  int helper_flow_6_2 = fn_R001643_4313_6(sec_r001643_6_2, pub_r001643_7_2);
  fn_R001643_4313_6_2(sec_r001643_6_1, pub_r001643_7_1, sec_r001643_6_2, pub_r001643_7_2);
  int helper_flow_7_1 = fn_R001643_4313_7(sec_r001643_7_1, pub_r001643_8_1);
  int helper_flow_7_2 = fn_R001643_4313_7(sec_r001643_7_2, pub_r001643_8_2);
  fn_R001643_4313_7_2(sec_r001643_7_1, pub_r001643_8_1, sec_r001643_7_2, pub_r001643_8_2);
  int stage_v_0_1 = ((pub_r001643_20_1 * 2) + 14) & 63;
  int stage_v_0_2 = ((pub_r001643_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001643_19_1 * 2) + 25) & 63;
  int stage_v_1_2 = ((pub_r001643_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001643_5_1 * 2) + 24) & 63;
  int stage_v_2_2 = ((pub_r001643_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001643_15_1 * 3) + pub_r001643_7_1) + 12) & 127;
  int stage_v_3_2 = (((sec_r001643_15_2 * 3) + pub_r001643_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((helper_flow_0_1 * 3) + pub_r001643_13_1) + 29) & 127;
  int stage_v_4_2 = (((helper_flow_0_2 * 3) + pub_r001643_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001643_13_1 * 2) + 23) & 63;
  int stage_v_5_2 = ((pub_r001643_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_0_1 * 3) + pub_r001643_4_1) + 3) & 127;
  int stage_v_6_2 = (((helper_flow_0_2 * 3) + pub_r001643_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001643_11_1 * 2) + 43) & 63;
  int stage_v_7_2 = ((pub_r001643_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001643_14_1 * 3) + pub_r001643_11_1) + 8) & 127;
  int stage_v_8_2 = (((sec_r001643_14_2 * 3) + pub_r001643_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001643_6_1 * 2) + 8) & 63;
  int stage_v_9_2 = ((pub_r001643_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001643_3_1 * 3) + pub_r001643_7_1) + 26) & 127;
  int stage_v_10_2 = (((sec_r001643_3_2 * 3) + pub_r001643_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001643_11_1 * 2) + 13) & 63;
  int stage_v_11_2 = ((pub_r001643_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001643_22_1 * 2) + 35) & 63;
  int stage_v_12_2 = ((pub_r001643_22_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((helper_flow_5_1 * 3) + pub_r001643_16_1) + 17) & 127;
  int stage_v_13_2 = (((helper_flow_5_2 * 3) + pub_r001643_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001643_14_1 * 2) + 48) & 63;
  int stage_v_14_2 = ((pub_r001643_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001643_11_1 * 3) + pub_r001643_11_1) + 5) & 127;
  int stage_v_15_2 = (((sec_r001643_11_2 * 3) + pub_r001643_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_7_1 * 3) + pub_r001643_2_1) + 41) & 127;
  int stage_v_16_2 = (((helper_flow_7_2 * 3) + pub_r001643_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001643_1_1 * 2) + 31) & 63;
  int stage_v_17_2 = ((pub_r001643_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001643_3_1 * 2) + 9) & 63;
  int stage_v_18_2 = ((pub_r001643_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((helper_flow_0_1 * 3) + pub_r001643_2_1) + 10) & 127;
  int stage_v_19_2 = (((helper_flow_0_2 * 3) + pub_r001643_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001643_11_1 * 3) + pub_r001643_5_1) + 7) & 127;
  int stage_v_20_2 = (((sec_r001643_11_2 * 3) + pub_r001643_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((sec_r001643_3_1 * 3) + pub_r001643_12_1) + 36) & 127;
  int stage_v_21_2 = (((sec_r001643_3_2 * 3) + pub_r001643_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_21_1 * 3) + pub_r001643_13_1) + 20) & 127;
  int stage_v_22_2 = (((stage_v_21_2 * 3) + pub_r001643_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((sec_r001643_16_1 * 3) + pub_r001643_0_1) + 29) & 127;
  int stage_v_23_2 = (((sec_r001643_16_2 * 3) + pub_r001643_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001643_12_1 * 3) + pub_r001643_18_1) + 35) & 127;
  int stage_v_24_2 = (((sec_r001643_12_2 * 3) + pub_r001643_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001643_12_1 * 3) + pub_r001643_6_1) + 33) & 127;
  int stage_v_25_2 = (((sec_r001643_12_2 * 3) + pub_r001643_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001643_4_1 * 3) + pub_r001643_3_1) + 40) & 127;
  int stage_v_26_2 = (((sec_r001643_4_2 * 3) + pub_r001643_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((sec_r001643_13_1 * 3) + pub_r001643_4_1) + 43) & 127;
  int stage_v_27_2 = (((sec_r001643_13_2 * 3) + pub_r001643_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((sec_r001643_10_1 * 3) + pub_r001643_16_1) + 35) & 127;
  int stage_v_28_2 = (((sec_r001643_10_2 * 3) + pub_r001643_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001643_1_1 * 3) + pub_r001643_4_1) + 8) & 127;
  int stage_v_29_2 = (((sec_r001643_1_2 * 3) + pub_r001643_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((stage_v_23_1 * 3) + pub_r001643_18_1) + 16) & 127;
  int stage_v_30_2 = (((stage_v_23_2 * 3) + pub_r001643_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001643_22_1 * 2) + 8) & 63;
  int stage_v_31_2 = ((pub_r001643_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001643_21_1 * 2) + 36) & 63;
  int stage_v_32_2 = ((pub_r001643_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001643_0_1 * 2) + 41) & 63;
  int stage_v_33_2 = ((pub_r001643_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001643_16_1 * 2) + 5) & 63;
  int stage_v_34_2 = ((pub_r001643_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_6_1 * 3) + pub_r001643_19_1) + 24) & 127;
  int stage_v_35_2 = (((stage_v_6_2 * 3) + pub_r001643_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001643_8_1 * 2) + 24) & 63;
  int stage_v_36_2 = ((pub_r001643_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((stage_v_27_1 * 3) + pub_r001643_15_1) + 31) & 127;
  int stage_v_37_2 = (((stage_v_27_2 * 3) + pub_r001643_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001643_9_1 * 2) + 14) & 63;
  int stage_v_38_2 = ((pub_r001643_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((stage_v_23_1 * 3) + pub_r001643_6_1) + 15) & 127;
  int stage_v_39_2 = (((stage_v_23_2 * 3) + pub_r001643_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001643_6_1 * 3) + pub_r001643_16_1) + 40) & 127;
  int stage_v_40_2 = (((sec_r001643_6_2 * 3) + pub_r001643_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_19_1 * 3) + pub_r001643_8_1) + 35) & 127;
  int stage_v_41_2 = (((stage_v_19_2 * 3) + pub_r001643_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001643_3_1 * 2) + 9) & 63;
  int stage_v_42_2 = ((pub_r001643_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_29_1 * 3) + pub_r001643_17_1) + 4) & 127;
  int stage_v_43_2 = (((stage_v_29_2 * 3) + pub_r001643_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001643_6_1 * 3) + pub_r001643_6_1) + 3) & 127;
  int stage_v_44_2 = (((sec_r001643_6_2 * 3) + pub_r001643_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_4_1 * 3) + pub_r001643_6_1) + 33) & 127;
  int stage_v_45_2 = (((stage_v_4_2 * 3) + pub_r001643_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((helper_flow_6_1 * 3) + pub_r001643_12_1) + 4) & 127;
  int stage_v_46_2 = (((helper_flow_6_2 * 3) + pub_r001643_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001643_0_1 * 3) + pub_r001643_11_1) + 24) & 127;
  int stage_v_47_2 = (((sec_r001643_0_2 * 3) + pub_r001643_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001643_6_1 * 2) + 26) & 63;
  int stage_v_48_2 = ((pub_r001643_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001643_8_1 * 3) + pub_r001643_6_1) + 9) & 127;
  int stage_v_49_2 = (((sec_r001643_8_2 * 3) + pub_r001643_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((helper_flow_5_1 * 3) + pub_r001643_5_1) + 22) & 127;
  int stage_v_50_2 = (((helper_flow_5_2 * 3) + pub_r001643_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001643_17_1 * 2) + 7) & 63;
  int stage_v_51_2 = ((pub_r001643_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001643_17_1 * 3) + pub_r001643_9_1) + 22) & 127;
  int stage_v_52_2 = (((sec_r001643_17_2 * 3) + pub_r001643_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001643_12_1 * 3) + pub_r001643_17_1) + 18) & 127;
  int stage_v_53_2 = (((sec_r001643_12_2 * 3) + pub_r001643_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((sec_r001643_2_1 * 3) + pub_r001643_10_1) + 16) & 127;
  int stage_v_54_2 = (((sec_r001643_2_2 * 3) + pub_r001643_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_35_1 * 3) + pub_r001643_14_1) + 37) & 127;
  int stage_v_55_2 = (((stage_v_35_2 * 3) + pub_r001643_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_15_1 * 3) + pub_r001643_9_1) + 3) & 127;
  int stage_v_56_2 = (((stage_v_15_2 * 3) + pub_r001643_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001643_14_1 * 2) + 25) & 63;
  int stage_v_57_2 = ((pub_r001643_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001643_13_1 * 2) + 36) & 63;
  int stage_v_58_2 = ((pub_r001643_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001643_0_1 * 3) + pub_r001643_3_1) + 13) & 127;
  int stage_v_59_2 = (((sec_r001643_0_2 * 3) + pub_r001643_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001643_5_1 * 2) + 44) & 63;
  int stage_v_60_2 = ((pub_r001643_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_46_1 * 3) + pub_r001643_17_1) + 31) & 127;
  int stage_v_61_2 = (((stage_v_46_2 * 3) + pub_r001643_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001643_4_1 * 2) + 34) & 63;
  int stage_v_62_2 = ((pub_r001643_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001643_3_1 * 3) + pub_r001643_22_1) + 5) & 127;
  int stage_v_63_2 = (((sec_r001643_3_2 * 3) + pub_r001643_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_49_1 * 3) + pub_r001643_9_1) + 23) & 127;
  int stage_v_64_2 = (((stage_v_49_2 * 3) + pub_r001643_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_47_1 * 3) + pub_r001643_4_1) + 28) & 127;
  int stage_v_65_2 = (((stage_v_47_2 * 3) + pub_r001643_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001643_8_1 * 2) + 35) & 63;
  int stage_v_66_2 = ((pub_r001643_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_59_1 * 3) + pub_r001643_8_1) + 15) & 127;
  int stage_v_67_2 = (((stage_v_59_2 * 3) + pub_r001643_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_54_1 * 3) + pub_r001643_18_1) + 39) & 127;
  int stage_v_68_2 = (((stage_v_54_2 * 3) + pub_r001643_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001643_10_1 * 2) + 41) & 63;
  int stage_v_69_2 = ((pub_r001643_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_40_1 * 3) + pub_r001643_4_1) + 44) & 127;
  int stage_v_70_2 = (((stage_v_40_2 * 3) + pub_r001643_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001643_12_1 * 3) + pub_r001643_1_1) + 21) & 127;
  int stage_v_71_2 = (((sec_r001643_12_2 * 3) + pub_r001643_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001643_7_1 * 2) + 7) & 63;
  int stage_v_72_2 = ((pub_r001643_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_50_1 * 3) + pub_r001643_23_1) + 3) & 127;
  int stage_v_73_2 = (((stage_v_50_2 * 3) + pub_r001643_23_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001643_14_1 * 2) + 6) & 63;
  int stage_v_74_2 = ((pub_r001643_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_70_1 * 3) + pub_r001643_0_1) + 7) & 127;
  int stage_v_75_2 = (((stage_v_70_2 * 3) + pub_r001643_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_39_1 * 3) + pub_r001643_10_1) + 44) & 127;
  int stage_v_76_2 = (((stage_v_39_2 * 3) + pub_r001643_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001643_9_1 * 2) + 11) & 63;
  int stage_v_77_2 = ((pub_r001643_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001643_13_1 * 2) + 30) & 63;
  int stage_v_78_2 = ((pub_r001643_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_63_1 * 3) + pub_r001643_11_1) + 42) & 127;
  int stage_v_79_2 = (((stage_v_63_2 * 3) + pub_r001643_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((sec_r001643_10_1 * 3) + pub_r001643_14_1) + 26) & 127;
  int stage_v_80_2 = (((sec_r001643_10_2 * 3) + pub_r001643_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((sec_r001643_12_1 * 3) + pub_r001643_22_1) + 37) & 127;
  int stage_v_81_2 = (((sec_r001643_12_2 * 3) + pub_r001643_22_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001643_8_1 * 2) + 21) & 63;
  int stage_v_82_2 = ((pub_r001643_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_81_1 * 3) + pub_r001643_3_1) + 5) & 127;
  int stage_v_83_2 = (((stage_v_81_2 * 3) + pub_r001643_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((helper_flow_1_1 * 3) + pub_r001643_21_1) + 45) & 127;
  int stage_v_84_2 = (((helper_flow_1_2 * 3) + pub_r001643_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_71_1 * 3) + pub_r001643_12_1) + 24) & 127;
  int stage_v_85_2 = (((stage_v_71_2 * 3) + pub_r001643_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001643_23_1 * 2) + 40) & 63;
  int stage_v_86_2 = ((pub_r001643_23_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_47_1 * 3) + pub_r001643_13_1) + 8) & 127;
  int stage_v_87_2 = (((stage_v_47_2 * 3) + pub_r001643_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((sec_r001643_4_1 * 3) + pub_r001643_3_1) + 20) & 127;
  int stage_v_88_2 = (((sec_r001643_4_2 * 3) + pub_r001643_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_27_1 * 3) + pub_r001643_4_1) + 31) & 127;
  int stage_v_89_2 = (((stage_v_27_2 * 3) + pub_r001643_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001643_14_1 * 3) + pub_r001643_20_1) + 6) & 127;
  int stage_v_90_2 = (((sec_r001643_14_2 * 3) + pub_r001643_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001643_1_1 * 2) + 31) & 63;
  int stage_v_91_2 = ((pub_r001643_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_64_1 * 3) + pub_r001643_21_1) + 31) & 127;
  int stage_v_92_2 = (((stage_v_64_2 * 3) + pub_r001643_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((sec_r001643_0_1 * 3) + pub_r001643_14_1) + 25) & 127;
  int stage_v_93_2 = (((sec_r001643_0_2 * 3) + pub_r001643_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((sec_r001643_12_1 * 3) + pub_r001643_13_1) + 9) & 127;
  int stage_v_94_2 = (((sec_r001643_12_2 * 3) + pub_r001643_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001643_2_1 * 3) + pub_r001643_20_1) + 39) & 127;
  int stage_v_95_2 = (((sec_r001643_2_2 * 3) + pub_r001643_20_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001643_1_1 * 2) + 25) & 63;
  int stage_v_96_2 = ((pub_r001643_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_84_1 * 3) + pub_r001643_16_1) + 6) & 127;
  int stage_v_97_2 = (((stage_v_84_2 * 3) + pub_r001643_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_21_1 * 3) + pub_r001643_22_1) + 22) & 127;
  int stage_v_98_2 = (((stage_v_21_2 * 3) + pub_r001643_22_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001643_3_1 * 2) + 50) & 63;
  int stage_v_99_2 = ((pub_r001643_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001643_10_1 * 2) + 11) & 63;
  int stage_v_100_2 = ((pub_r001643_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_6_1 * 3) + pub_r001643_12_1) + 22) & 127;
  int stage_v_101_2 = (((stage_v_6_2 * 3) + pub_r001643_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((stage_v_79_1 * 3) + pub_r001643_15_1) + 26) & 127;
  int stage_v_102_2 = (((stage_v_79_2 * 3) + pub_r001643_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001643_9_1 * 2) + 45) & 63;
  int stage_v_103_2 = ((pub_r001643_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_102_1 * 3) + pub_r001643_5_1) + 25) & 127;
  int stage_v_104_2 = (((stage_v_102_2 * 3) + pub_r001643_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001643_17_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001643_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_76_1 * 3) + pub_r001643_11_1) + 43) & 127;
  int stage_v_106_2 = (((stage_v_76_2 * 3) + pub_r001643_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001643_16_1 * 2) + 18) & 63;
  int stage_v_107_2 = ((pub_r001643_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001643_13_1 * 2) + 39) & 63;
  int stage_v_108_2 = ((pub_r001643_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001643_8_1 * 2) + 7) & 63;
  int stage_v_109_2 = ((pub_r001643_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001643_23_1 * 2) + 19) & 63;
  int stage_v_110_2 = ((pub_r001643_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001643_2_1 * 2) + 23) & 63;
  int stage_v_111_2 = ((pub_r001643_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_93_1 * 3) + pub_r001643_3_1) + 45) & 127;
  int stage_v_112_2 = (((stage_v_93_2 * 3) + pub_r001643_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001643_22_1 * 2) + 17) & 63;
  int stage_v_113_2 = ((pub_r001643_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_21_1 * 3) + pub_r001643_7_1) + 33) & 127;
  int stage_v_114_2 = (((stage_v_21_2 * 3) + pub_r001643_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001643_5_1 * 2) + 19) & 63;
  int stage_v_115_2 = ((pub_r001643_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((sec_r001643_4_1 * 3) + pub_r001643_11_1) + 4) & 127;
  int stage_v_116_2 = (((sec_r001643_4_2 * 3) + pub_r001643_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001643_0_1 * 2) + 15) & 63;
  int stage_v_117_2 = ((pub_r001643_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001643_12_1 * 2) + 44) & 63;
  int stage_v_118_2 = ((pub_r001643_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001643_8_1 * 2) + 25) & 63;
  int stage_v_119_2 = ((pub_r001643_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001643_9_1 * 2) + 7) & 63;
  int stage_v_120_2 = ((pub_r001643_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_92_1 * 3) + pub_r001643_14_1) + 11) & 127;
  int stage_v_121_2 = (((stage_v_92_2 * 3) + pub_r001643_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001643_0_1 * 2) + 36) & 63;
  int stage_v_122_2 = ((pub_r001643_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_40_1 * 3) + pub_r001643_19_1) + 23) & 127;
  int stage_v_123_2 = (((stage_v_40_2 * 3) + pub_r001643_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_43_1 * 3) + pub_r001643_0_1) + 37) & 127;
  int stage_v_124_2 = (((stage_v_43_2 * 3) + pub_r001643_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_56_1 * 3) + pub_r001643_11_1) + 40) & 127;
  int stage_v_125_2 = (((stage_v_56_2 * 3) + pub_r001643_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001643_4_1 * 2) + 50) & 63;
  int stage_v_126_2 = ((pub_r001643_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001643_3_1 * 2) + 33) & 63;
  int stage_v_127_2 = ((pub_r001643_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001643_22_1 * 2) + 40) & 63;
  int stage_v_128_2 = ((pub_r001643_22_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001643_8_1 * 2) + 14) & 63;
  int stage_v_129_2 = ((pub_r001643_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_23_1 * 3) + pub_r001643_19_1) + 45) & 127;
  int stage_v_130_2 = (((stage_v_23_2 * 3) + pub_r001643_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_43_1 * 3) + pub_r001643_8_1) + 3) & 127;
  int stage_v_131_2 = (((stage_v_43_2 * 3) + pub_r001643_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001643_10_1 * 2) + 42) & 63;
  int stage_v_132_2 = ((pub_r001643_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((helper_flow_5_1 * 3) + pub_r001643_13_1) + 17) & 127;
  int stage_v_133_2 = (((helper_flow_5_2 * 3) + pub_r001643_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001643_13_1 * 2) + 14) & 63;
  int stage_v_134_2 = ((pub_r001643_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((sec_r001643_3_1 * 3) + pub_r001643_4_1) + 6) & 127;
  int stage_v_135_2 = (((sec_r001643_3_2 * 3) + pub_r001643_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((sec_r001643_6_1 * 3) + pub_r001643_6_1) + 42) & 127;
  int stage_v_136_2 = (((sec_r001643_6_2 * 3) + pub_r001643_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001643_12_1 * 2) + 19) & 63;
  int stage_v_137_2 = ((pub_r001643_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_10_1 * 3) + pub_r001643_18_1) + 26) & 127;
  int stage_v_138_2 = (((stage_v_10_2 * 3) + pub_r001643_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_68_1 * 3) + pub_r001643_20_1) + 44) & 127;
  int stage_v_139_2 = (((stage_v_68_2 * 3) + pub_r001643_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_102_1 * 3) + pub_r001643_23_1) + 19) & 127;
  int stage_v_140_2 = (((stage_v_102_2 * 3) + pub_r001643_23_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001643_5_1 * 2) + 24) & 63;
  int stage_v_141_2 = ((pub_r001643_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_93_1 * 3) + pub_r001643_15_1) + 3) & 127;
  int stage_v_142_2 = (((stage_v_93_2 * 3) + pub_r001643_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_46_1 * 3) + pub_r001643_15_1) + 32) & 127;
  int stage_v_143_2 = (((stage_v_46_2 * 3) + pub_r001643_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001643_13_1 * 2) + 15) & 63;
  int stage_v_144_2 = ((pub_r001643_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001643_20_1 * 2) + 44) & 63;
  int stage_v_145_2 = ((pub_r001643_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_142_1 * 3) + pub_r001643_12_1) + 7) & 127;
  int stage_v_146_2 = (((stage_v_142_2 * 3) + pub_r001643_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001643_9_1 * 2) + 47) & 63;
  int stage_v_147_2 = ((pub_r001643_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_25_1 * 3) + pub_r001643_22_1) + 7) & 127;
  int stage_v_148_2 = (((stage_v_25_2 * 3) + pub_r001643_22_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001643_12_1 * 3) + pub_r001643_10_1) + 29) & 127;
  int stage_v_149_2 = (((sec_r001643_12_2 * 3) + pub_r001643_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001643_21_1 * 2) + 44) & 63;
  int stage_v_150_2 = ((pub_r001643_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001643_7_1 * 2) + 31) & 63;
  int stage_v_151_2 = ((pub_r001643_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001643_7_1 * 2) + 37) & 63;
  int stage_v_152_2 = ((pub_r001643_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_44_1 * 3) + pub_r001643_15_1) + 34) & 127;
  int stage_v_153_2 = (((stage_v_44_2 * 3) + pub_r001643_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001643_16_1 * 2) + 47) & 63;
  int stage_v_154_2 = ((pub_r001643_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001643_21_1 * 2) + 32) & 63;
  int stage_v_155_2 = ((pub_r001643_21_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_135_1 * 3) + pub_r001643_18_1) + 25) & 127;
  int stage_v_156_2 = (((stage_v_135_2 * 3) + pub_r001643_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001643_6_1 * 3) + pub_r001643_13_1) + 3) & 127;
  int stage_v_157_2 = (((sec_r001643_6_2 * 3) + pub_r001643_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001643_10_1 * 2) + 48) & 63;
  int stage_v_158_2 = ((pub_r001643_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((sec_r001643_4_1 * 3) + pub_r001643_2_1) + 19) & 127;
  int stage_v_159_2 = (((sec_r001643_4_2 * 3) + pub_r001643_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001643_18_1 * 2) + 32) & 63;
  int stage_v_160_2 = ((pub_r001643_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001643_12_1 * 2) + 30) & 63;
  int stage_v_161_2 = ((pub_r001643_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_45_1 * 3) + pub_r001643_8_1) + 11) & 127;
  int stage_v_162_2 = (((stage_v_45_2 * 3) + pub_r001643_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_40_1 * 3) + pub_r001643_17_1) + 43) & 127;
  int stage_v_163_2 = (((stage_v_40_2 * 3) + pub_r001643_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_94_1 * 3) + pub_r001643_11_1) + 17) & 127;
  int stage_v_164_2 = (((stage_v_94_2 * 3) + pub_r001643_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_83_1 * 3) + pub_r001643_13_1) + 42) & 127;
  int stage_v_165_2 = (((stage_v_83_2 * 3) + pub_r001643_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001643_10_1 * 2) + 23) & 63;
  int stage_v_166_2 = ((pub_r001643_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_73_1 * 3) + pub_r001643_16_1) + 20) & 127;
  int stage_v_167_2 = (((stage_v_73_2 * 3) + pub_r001643_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((helper_flow_0_1 * 3) + pub_r001643_6_1) + 35) & 127;
  int stage_v_168_2 = (((helper_flow_0_2 * 3) + pub_r001643_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((sec_r001643_15_1 * 3) + pub_r001643_1_1) + 28) & 127;
  int stage_v_169_2 = (((sec_r001643_15_2 * 3) + pub_r001643_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_101_1 * 3) + pub_r001643_12_1) + 6) & 127;
  int stage_v_170_2 = (((stage_v_101_2 * 3) + pub_r001643_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001643_11_1 * 2) + 15) & 63;
  int stage_v_171_2 = ((pub_r001643_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001643_5_1 * 2) + 29) & 63;
  int stage_v_172_2 = ((pub_r001643_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001643_15_1 * 2) + 14) & 63;
  int stage_v_173_2 = ((pub_r001643_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001643_4_1 * 2) + 22) & 63;
  int stage_v_174_2 = ((pub_r001643_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_167_1 * 3) + pub_r001643_3_1) + 14) & 127;
  int stage_v_175_2 = (((stage_v_167_2 * 3) + pub_r001643_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001643_17_1 * 2) + 17) & 63;
  int stage_v_176_2 = ((pub_r001643_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001643_3_1 * 2) + 49) & 63;
  int stage_v_177_2 = ((pub_r001643_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001643_7_1 * 2) + 34) & 63;
  int stage_v_178_2 = ((pub_r001643_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((sec_r001643_12_1 * 3) + pub_r001643_17_1) + 25) & 127;
  int stage_v_179_2 = (((sec_r001643_12_2 * 3) + pub_r001643_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_133_1 * 3) + pub_r001643_5_1) + 8) & 127;
  int stage_v_180_2 = (((stage_v_133_2 * 3) + pub_r001643_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((sec_r001643_15_1 * 3) + pub_r001643_0_1) + 35) & 127;
  int stage_v_181_2 = (((sec_r001643_15_2 * 3) + pub_r001643_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_55_1 * 3) + pub_r001643_1_1) + 15) & 127;
  int stage_v_182_2 = (((stage_v_55_2 * 3) + pub_r001643_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001643_12_1 * 2) + 22) & 63;
  int stage_v_183_2 = ((pub_r001643_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_29_1 * 3) + pub_r001643_3_1) + 32) & 127;
  int stage_v_184_2 = (((stage_v_29_2 * 3) + pub_r001643_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_93_1 * 3) + pub_r001643_14_1) + 18) & 127;
  int stage_v_185_2 = (((stage_v_93_2 * 3) + pub_r001643_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001643_22_1 * 2) + 41) & 63;
  int stage_v_186_2 = ((pub_r001643_22_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001643_13_1 * 2) + 41) & 63;
  int stage_v_187_2 = ((pub_r001643_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_90_1 * 3) + pub_r001643_11_1) + 40) & 127;
  int stage_v_188_2 = (((stage_v_90_2 * 3) + pub_r001643_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_165_1 * 3) + pub_r001643_19_1) + 8) & 127;
  int stage_v_189_2 = (((stage_v_165_2 * 3) + pub_r001643_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_63_1 * 3) + pub_r001643_22_1) + 10) & 127;
  int stage_v_190_2 = (((stage_v_63_2 * 3) + pub_r001643_22_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_37_1 * 3) + pub_r001643_16_1) + 45) & 127;
  int stage_v_191_2 = (((stage_v_37_2 * 3) + pub_r001643_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_43_1 * 3) + pub_r001643_21_1) + 6) & 127;
  int stage_v_192_2 = (((stage_v_43_2 * 3) + pub_r001643_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001643_5_1 * 2) + 28) & 63;
  int stage_v_193_2 = ((pub_r001643_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_68_1 * 3) + pub_r001643_8_1) + 40) & 127;
  int stage_v_194_2 = (((stage_v_68_2 * 3) + pub_r001643_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_25_1 * 3) + pub_r001643_14_1) + 37) & 127;
  int stage_v_195_2 = (((stage_v_25_2 * 3) + pub_r001643_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001643_5_1 * 2) + 41) & 63;
  int stage_v_196_2 = ((pub_r001643_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_93_1 * 3) + pub_r001643_17_1) + 39) & 127;
  int stage_v_197_2 = (((stage_v_93_2 * 3) + pub_r001643_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((sec_r001643_11_1 * 3) + pub_r001643_13_1) + 35) & 127;
  int stage_v_198_2 = (((sec_r001643_11_2 * 3) + pub_r001643_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001643_11_1 * 2) + 35) & 63;
  int stage_v_199_2 = ((pub_r001643_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_81_1 * 3) + pub_r001643_4_1) + 15) & 127;
  int stage_v_200_2 = (((stage_v_81_2 * 3) + pub_r001643_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_71_1 * 3) + pub_r001643_2_1) + 6) & 127;
  int stage_v_201_2 = (((stage_v_71_2 * 3) + pub_r001643_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_67_1 * 3) + pub_r001643_5_1) + 34) & 127;
  int stage_v_202_2 = (((stage_v_67_2 * 3) + pub_r001643_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((sec_r001643_7_1 * 3) + pub_r001643_20_1) + 34) & 127;
  int stage_v_203_2 = (((sec_r001643_7_2 * 3) + pub_r001643_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_168_1 * 3) + pub_r001643_10_1) + 45) & 127;
  int stage_v_204_2 = (((stage_v_168_2 * 3) + pub_r001643_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_153_1 * 3) + pub_r001643_10_1) + 37) & 127;
  int stage_v_205_2 = (((stage_v_153_2 * 3) + pub_r001643_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001643_9_1 * 2) + 26) & 63;
  int stage_v_206_2 = ((pub_r001643_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_81_1 * 3) + pub_r001643_0_1) + 32) & 127;
  int stage_v_207_2 = (((stage_v_81_2 * 3) + pub_r001643_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001643_11_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001643_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((helper_flow_5_1 * 3) + pub_r001643_21_1) + 11) & 127;
  int stage_v_209_2 = (((helper_flow_5_2 * 3) + pub_r001643_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001643_17_1 * 2) + 34) & 63;
  int stage_v_210_2 = ((pub_r001643_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((sec_r001643_16_1 * 3) + pub_r001643_18_1) + 12) & 127;
  int stage_v_211_2 = (((sec_r001643_16_2 * 3) + pub_r001643_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001643_13_1 * 2) + 28) & 63;
  int stage_v_212_2 = ((pub_r001643_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001643_6_1 * 2) + 19) & 63;
  int stage_v_213_2 = ((pub_r001643_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001643_22_1 * 2) + 42) & 63;
  int stage_v_214_2 = ((pub_r001643_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001643_0_1 * 3) + pub_r001643_11_1) + 38) & 127;
  int stage_v_215_2 = (((sec_r001643_0_2 * 3) + pub_r001643_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_140_1 * 3) + pub_r001643_12_1) + 19) & 127;
  int stage_v_216_2 = (((stage_v_140_2 * 3) + pub_r001643_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((stage_v_203_1 * 3) + pub_r001643_4_1) + 11) & 127;
  int stage_v_217_2 = (((stage_v_203_2 * 3) + pub_r001643_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((sec_r001643_6_1 * 3) + pub_r001643_15_1) + 3) & 127;
  int stage_v_218_2 = (((sec_r001643_6_2 * 3) + pub_r001643_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_49_1 * 3) + pub_r001643_5_1) + 20) & 127;
  int stage_v_219_2 = (((stage_v_49_2 * 3) + pub_r001643_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_180_1 * 3) + pub_r001643_16_1) + 13) & 127;
  int stage_v_220_2 = (((stage_v_180_2 * 3) + pub_r001643_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001643_19_1 * 2) + 23) & 63;
  int stage_v_221_2 = ((pub_r001643_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001643_18_1 * 2) + 17) & 63;
  int stage_v_222_2 = ((pub_r001643_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_180_1 * 3) + pub_r001643_22_1) + 4) & 127;
  int stage_v_223_2 = (((stage_v_180_2 * 3) + pub_r001643_22_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_88_1 * 3) + pub_r001643_12_1) + 30) & 127;
  int stage_v_224_2 = (((stage_v_88_2 * 3) + pub_r001643_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_101_1 * 3) + pub_r001643_14_1) + 24) & 127;
  int stage_v_225_2 = (((stage_v_101_2 * 3) + pub_r001643_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001643_21_1 * 2) + 33) & 63;
  int stage_v_226_2 = ((pub_r001643_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_29_1 * 3) + pub_r001643_0_1) + 41) & 127;
  int stage_v_227_2 = (((stage_v_29_2 * 3) + pub_r001643_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_102_1 * 3) + pub_r001643_15_1) + 18) & 127;
  int stage_v_228_2 = (((stage_v_102_2 * 3) + pub_r001643_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001643_22_1 * 2) + 32) & 63;
  int stage_v_229_2 = ((pub_r001643_22_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_25_1 * 3) + pub_r001643_10_1) + 34) & 127;
  int stage_v_230_2 = (((stage_v_25_2 * 3) + pub_r001643_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001643_16_1 * 2) + 48) & 63;
  int stage_v_231_2 = ((pub_r001643_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((sec_r001643_17_1 * 3) + pub_r001643_13_1) + 14) & 127;
  int stage_v_232_2 = (((sec_r001643_17_2 * 3) + pub_r001643_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_45_1 * 3) + pub_r001643_22_1) + 9) & 127;
  int stage_v_233_2 = (((stage_v_45_2 * 3) + pub_r001643_22_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_65_1 * 3) + pub_r001643_7_1) + 18) & 127;
  int stage_v_234_2 = (((stage_v_65_2 * 3) + pub_r001643_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001643_5_1 * 2) + 48) & 63;
  int stage_v_235_2 = ((pub_r001643_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001643_3_1 * 2) + 27) & 63;
  int stage_v_236_2 = ((pub_r001643_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001643_17_1 * 2) + 37) & 63;
  int stage_v_237_2 = ((pub_r001643_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001643_3_1 * 2) + 9) & 63;
  int stage_v_238_2 = ((pub_r001643_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001643_21_1 * 2) + 6) & 63;
  int stage_v_239_2 = ((pub_r001643_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_22_1 * 3) + pub_r001643_16_1) + 11) & 127;
  int stage_v_240_2 = (((stage_v_22_2 * 3) + pub_r001643_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((sec_r001643_15_1 * 3) + pub_r001643_20_1) + 19) & 127;
  int stage_v_241_2 = (((sec_r001643_15_2 * 3) + pub_r001643_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_26_1 * 3) + pub_r001643_21_1) + 44) & 127;
  int stage_v_242_2 = (((stage_v_26_2 * 3) + pub_r001643_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_164_1 * 3) + pub_r001643_19_1) + 26) & 127;
  int stage_v_243_2 = (((stage_v_164_2 * 3) + pub_r001643_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001643_6_1 * 2) + 20) & 63;
  int stage_v_244_2 = ((pub_r001643_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_21_1 * 3) + pub_r001643_3_1) + 36) & 127;
  int stage_v_245_2 = (((stage_v_21_2 * 3) + pub_r001643_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001643_22_1 * 2) + 42) & 63;
  int stage_v_246_2 = ((pub_r001643_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((helper_flow_6_1 * 3) + pub_r001643_7_1) + 21) & 127;
  int stage_v_247_2 = (((helper_flow_6_2 * 3) + pub_r001643_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001643_8_1 * 2) + 33) & 63;
  int stage_v_248_2 = ((pub_r001643_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001643_16_1 * 2) + 14) & 63;
  int stage_v_249_2 = ((pub_r001643_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001643_22_1 * 2) + 37) & 63;
  int stage_v_250_2 = ((pub_r001643_22_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_140_1 * 3) + pub_r001643_11_1) + 45) & 127;
  int stage_v_251_2 = (((stage_v_140_2 * 3) + pub_r001643_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001643_0_1 * 2) + 12) & 63;
  int stage_v_252_2 = ((pub_r001643_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001643_2_1 * 2) + 8) & 63;
  int stage_v_253_2 = ((pub_r001643_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001643_15_1 * 2) + 7) & 63;
  int stage_v_254_2 = ((pub_r001643_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((stage_v_182_1 * 3) + pub_r001643_19_1) + 34) & 127;
  int stage_v_255_2 = (((stage_v_182_2 * 3) + pub_r001643_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001643_22_1 * 2) + 19) & 63;
  int stage_v_256_2 = ((pub_r001643_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001643_7_1 * 2) + 22) & 63;
  int stage_v_257_2 = ((pub_r001643_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001643_8_1 * 2) + 6) & 63;
  int stage_v_258_2 = ((pub_r001643_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_218_1 * 3) + pub_r001643_9_1) + 18) & 127;
  int stage_v_259_2 = (((stage_v_218_2 * 3) + pub_r001643_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001643_8_1 * 2) + 39) & 63;
  int stage_v_260_2 = ((pub_r001643_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_87_1 * 3) + pub_r001643_20_1) + 11) & 127;
  int stage_v_261_2 = (((stage_v_87_2 * 3) + pub_r001643_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_261_1 * 3) + pub_r001643_1_1) + 11) & 127;
  int stage_v_262_2 = (((stage_v_261_2 * 3) + pub_r001643_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_8_1 * 3) + pub_r001643_17_1) + 15) & 127;
  int stage_v_263_2 = (((stage_v_8_2 * 3) + pub_r001643_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_40_1 * 3) + pub_r001643_13_1) + 6) & 127;
  int stage_v_264_2 = (((stage_v_40_2 * 3) + pub_r001643_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001643_7_1 * 2) + 15) & 63;
  int stage_v_265_2 = ((pub_r001643_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001643_4_1 * 2) + 14) & 63;
  int stage_v_266_2 = ((pub_r001643_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001643_8_1 * 2) + 29) & 63;
  int stage_v_267_2 = ((pub_r001643_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001643_6_1 * 2) + 20) & 63;
  int stage_v_268_2 = ((pub_r001643_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_47_1 * 3) + pub_r001643_0_1) + 28) & 127;
  int stage_v_269_2 = (((stage_v_47_2 * 3) + pub_r001643_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001643_9_1 * 2) + 26) & 63;
  int stage_v_270_2 = ((pub_r001643_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_124_1 * 3) + pub_r001643_10_1) + 34) & 127;
  int stage_v_271_2 = (((stage_v_124_2 * 3) + pub_r001643_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001643_23_1 * 2) + 45) & 63;
  int stage_v_272_2 = ((pub_r001643_23_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001643_8_1 * 2) + 27) & 63;
  int stage_v_273_2 = ((pub_r001643_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_75_1 * 3) + pub_r001643_4_1) + 42) & 127;
  int stage_v_274_2 = (((stage_v_75_2 * 3) + pub_r001643_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001643_4_1 * 2) + 50) & 63;
  int stage_v_275_2 = ((pub_r001643_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001643_19_1 * 2) + 46) & 63;
  int stage_v_276_2 = ((pub_r001643_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_274_1 * 3) + pub_r001643_4_1) + 8) & 127;
  int stage_v_277_2 = (((stage_v_274_2 * 3) + pub_r001643_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_207_1 * 3) + pub_r001643_1_1) + 7) & 127;
  int stage_v_278_2 = (((stage_v_207_2 * 3) + pub_r001643_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_179_1 * 3) + pub_r001643_10_1) + 7) & 127;
  int stage_v_279_2 = (((stage_v_179_2 * 3) + pub_r001643_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((sec_r001643_5_1 * 3) + pub_r001643_10_1) + 26) & 127;
  int stage_v_280_2 = (((sec_r001643_5_2 * 3) + pub_r001643_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_8_1 * 3) + pub_r001643_2_1) + 28) & 127;
  int stage_v_281_2 = (((stage_v_8_2 * 3) + pub_r001643_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001643_1_1 * 2) + 19) & 63;
  int stage_v_282_2 = ((pub_r001643_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_263_1 * 3) + pub_r001643_17_1) + 19) & 127;
  int stage_v_283_2 = (((stage_v_263_2 * 3) + pub_r001643_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001643_16_1 * 2) + 16) & 63;
  int stage_v_284_2 = ((pub_r001643_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_189_1 * 3) + pub_r001643_17_1) + 24) & 127;
  int stage_v_285_2 = (((stage_v_189_2 * 3) + pub_r001643_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_55_1 * 3) + pub_r001643_9_1) + 38) & 127;
  int stage_v_286_2 = (((stage_v_55_2 * 3) + pub_r001643_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((sec_r001643_10_1 * 3) + pub_r001643_7_1) + 39) & 127;
  int stage_v_287_2 = (((sec_r001643_10_2 * 3) + pub_r001643_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001643_4_1 * 2) + 38) & 63;
  int stage_v_288_2 = ((pub_r001643_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_106_1 * 3) + pub_r001643_17_1) + 16) & 127;
  int stage_v_289_2 = (((stage_v_106_2 * 3) + pub_r001643_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_198_1 * 3) + pub_r001643_16_1) + 35) & 127;
  int stage_v_290_2 = (((stage_v_198_2 * 3) + pub_r001643_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_70_1 * 3) + pub_r001643_11_1) + 44) & 127;
  int stage_v_291_2 = (((stage_v_70_2 * 3) + pub_r001643_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001643_22_1 * 2) + 6) & 63;
  int stage_v_292_2 = ((pub_r001643_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_63_1 * 3) + pub_r001643_10_1) + 11) & 127;
  int stage_v_293_2 = (((stage_v_63_2 * 3) + pub_r001643_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001643_4_1 * 2) + 48) & 63;
  int stage_v_294_2 = ((pub_r001643_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001643_1_1 * 2) + 40) & 63;
  int stage_v_295_2 = ((pub_r001643_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001643_16_1 * 2) + 48) & 63;
  int stage_v_296_2 = ((pub_r001643_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((sec_r001643_7_1 * 3) + pub_r001643_18_1) + 39) & 127;
  int stage_v_297_2 = (((sec_r001643_7_2 * 3) + pub_r001643_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001643_23_1 * 2) + 19) & 63;
  int stage_v_298_2 = ((pub_r001643_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_139_1 * 3) + pub_r001643_19_1) + 35) & 127;
  int stage_v_299_2 = (((stage_v_139_2 * 3) + pub_r001643_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001643_23_1 * 2) + 24) & 63;
  int stage_v_300_2 = ((pub_r001643_23_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001643_2_1 * 2) + 22) & 63;
  int stage_v_301_2 = ((pub_r001643_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_130_1 * 3) + pub_r001643_2_1) + 9) & 127;
  int stage_v_302_2 = (((stage_v_130_2 * 3) + pub_r001643_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((sec_r001643_16_1 * 3) + pub_r001643_4_1) + 10) & 127;
  int stage_v_303_2 = (((sec_r001643_16_2 * 3) + pub_r001643_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001643_6_1 * 2) + 48) & 63;
  int stage_v_304_2 = ((pub_r001643_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001643_19_1 * 2) + 25) & 63;
  int stage_v_305_2 = ((pub_r001643_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001643_4_1 * 2) + 50) & 63;
  int stage_v_306_2 = ((pub_r001643_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001643_7_1 * 2) + 12) & 63;
  int stage_v_307_2 = ((pub_r001643_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001643_22_1 * 2) + 16) & 63;
  int stage_v_308_2 = ((pub_r001643_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001643_19_1 * 2) + 9) & 63;
  int stage_v_309_2 = ((pub_r001643_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001643_3_1 * 2) + 43) & 63;
  int stage_v_310_2 = ((pub_r001643_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_201_1 * 3) + pub_r001643_5_1) + 27) & 127;
  int stage_v_311_2 = (((stage_v_201_2 * 3) + pub_r001643_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001643_23_1 * 2) + 46) & 63;
  int stage_v_312_2 = ((pub_r001643_23_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001643_23_1 * 2) + 28) & 63;
  int stage_v_313_2 = ((pub_r001643_23_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_4_1 * 3) + pub_r001643_13_1) + 3) & 127;
  int stage_v_314_2 = (((stage_v_4_2 * 3) + pub_r001643_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001643_6_1 * 2) + 44) & 63;
  int stage_v_315_2 = ((pub_r001643_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001643_5_1 * 2) + 38) & 63;
  int stage_v_316_2 = ((pub_r001643_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001643_14_1 * 2) + 28) & 63;
  int stage_v_317_2 = ((pub_r001643_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_216_1 * 3) + pub_r001643_11_1) + 20) & 127;
  int stage_v_318_2 = (((stage_v_216_2 * 3) + pub_r001643_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_279_1 * 3) + pub_r001643_20_1) + 29) & 127;
  int stage_v_319_2 = (((stage_v_279_2 * 3) + pub_r001643_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001643_1_1 * 2) + 16) & 63;
  int stage_v_320_2 = ((pub_r001643_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001643_11_1 * 2) + 38) & 63;
  int stage_v_321_2 = ((pub_r001643_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_168_1 * 3) + pub_r001643_6_1) + 33) & 127;
  int stage_v_322_2 = (((stage_v_168_2 * 3) + pub_r001643_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_55_1 * 3) + pub_r001643_2_1) + 41) & 127;
  int stage_v_323_2 = (((stage_v_55_2 * 3) + pub_r001643_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_63_1 * 3) + pub_r001643_5_1) + 34) & 127;
  int stage_v_324_2 = (((stage_v_63_2 * 3) + pub_r001643_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((sec_r001643_3_1 * 3) + pub_r001643_11_1) + 12) & 127;
  int stage_v_325_2 = (((sec_r001643_3_2 * 3) + pub_r001643_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_97_1 * 3) + pub_r001643_1_1) + 35) & 127;
  int stage_v_326_2 = (((stage_v_97_2 * 3) + pub_r001643_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001643_10_1 * 2) + 13) & 63;
  int stage_v_327_2 = ((pub_r001643_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001643_21_1 * 2) + 14) & 63;
  int stage_v_328_2 = ((pub_r001643_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001643_3_1 * 2) + 16) & 63;
  int stage_v_329_2 = ((pub_r001643_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_143_1 * 3) + pub_r001643_21_1) + 23) & 127;
  int stage_v_330_2 = (((stage_v_143_2 * 3) + pub_r001643_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001643_15_1 * 2) + 15) & 63;
  int stage_v_331_2 = ((pub_r001643_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_271_1 * 3) + pub_r001643_1_1) + 3) & 127;
  int stage_v_332_2 = (((stage_v_271_2 * 3) + pub_r001643_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_325_1 * 3) + pub_r001643_9_1) + 25) & 127;
  int stage_v_333_2 = (((stage_v_325_2 * 3) + pub_r001643_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_290_1 * 3) + pub_r001643_22_1) + 11) & 127;
  int stage_v_334_2 = (((stage_v_290_2 * 3) + pub_r001643_22_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_54_1 * 3) + pub_r001643_17_1) + 3) & 127;
  int stage_v_335_2 = (((stage_v_54_2 * 3) + pub_r001643_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001643_11_1 * 2) + 37) & 63;
  int stage_v_336_2 = ((pub_r001643_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_19_1 * 3) + pub_r001643_21_1) + 37) & 127;
  int stage_v_337_2 = (((stage_v_19_2 * 3) + pub_r001643_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_70_1 * 3) + pub_r001643_10_1) + 28) & 127;
  int stage_v_338_2 = (((stage_v_70_2 * 3) + pub_r001643_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001643_12_1 * 2) + 30) & 63;
  int stage_v_339_2 = ((pub_r001643_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((helper_flow_5_1 * 3) + pub_r001643_6_1) + 32) & 127;
  int stage_v_340_2 = (((helper_flow_5_2 * 3) + pub_r001643_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001643_1_1 * 2) + 46) & 63;
  int stage_v_341_2 = ((pub_r001643_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((helper_flow_0_1 * 3) + pub_r001643_16_1) + 9) & 127;
  int stage_v_342_2 = (((helper_flow_0_2 * 3) + pub_r001643_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_322_1 * 3) + pub_r001643_17_1) + 15) & 127;
  int stage_v_343_2 = (((stage_v_322_2 * 3) + pub_r001643_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_131_1 * 3) + pub_r001643_17_1) + 20) & 127;
  int stage_v_344_2 = (((stage_v_131_2 * 3) + pub_r001643_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001643_15_1 * 2) + 49) & 63;
  int stage_v_345_2 = ((pub_r001643_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_24_1 * 3) + pub_r001643_1_1) + 33) & 127;
  int stage_v_346_2 = (((stage_v_24_2 * 3) + pub_r001643_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((helper_flow_5_1 * 3) + pub_r001643_0_1) + 39) & 127;
  int stage_v_347_2 = (((helper_flow_5_2 * 3) + pub_r001643_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_90_1 * 3) + pub_r001643_16_1) + 10) & 127;
  int stage_v_348_2 = (((stage_v_90_2 * 3) + pub_r001643_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_340_1 * 3) + pub_r001643_14_1) + 7) & 127;
  int stage_v_349_2 = (((stage_v_340_2 * 3) + pub_r001643_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001643_18_1 * 2) + 26) & 63;
  int stage_v_350_2 = ((pub_r001643_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_45_1 * 3) + pub_r001643_16_1) + 19) & 127;
  int stage_v_351_2 = (((stage_v_45_2 * 3) + pub_r001643_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_227_1 * 3) + pub_r001643_7_1) + 6) & 127;
  int stage_v_352_2 = (((stage_v_227_2 * 3) + pub_r001643_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001643_5_1 * 2) + 24) & 63;
  int stage_v_353_2 = ((pub_r001643_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001643_20_1 * 2) + 40) & 63;
  int stage_v_354_2 = ((pub_r001643_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_262_1 * 3) + pub_r001643_1_1) + 7) & 127;
  int stage_v_355_2 = (((stage_v_262_2 * 3) + pub_r001643_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_8_1 * 3) + pub_r001643_19_1) + 25) & 127;
  int stage_v_356_2 = (((stage_v_8_2 * 3) + pub_r001643_19_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_102_1 * 3) + pub_r001643_14_1) + 32) & 127;
  int stage_v_357_2 = (((stage_v_102_2 * 3) + pub_r001643_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001643_0_1 * 2) + 17) & 63;
  int stage_v_358_2 = ((pub_r001643_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_71_1 * 3) + pub_r001643_8_1) + 42) & 127;
  int stage_v_359_2 = (((stage_v_71_2 * 3) + pub_r001643_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_299_1 * 3) + pub_r001643_4_1) + 16) & 127;
  int stage_v_360_2 = (((stage_v_299_2 * 3) + pub_r001643_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_40_1 * 3) + pub_r001643_14_1) + 42) & 127;
  int stage_v_361_2 = (((stage_v_40_2 * 3) + pub_r001643_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001643_11_1 * 2) + 17) & 63;
  int stage_v_362_2 = ((pub_r001643_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001643_1_1 * 2) + 36) & 63;
  int stage_v_363_2 = ((pub_r001643_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001643_23_1 * 2) + 9) & 63;
  int stage_v_364_2 = ((pub_r001643_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001643_15_1 * 2) + 20) & 63;
  int stage_v_365_2 = ((pub_r001643_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_293_1 * 3) + pub_r001643_11_1) + 20) & 127;
  int stage_v_366_2 = (((stage_v_293_2 * 3) + pub_r001643_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_148_1 * 3) + pub_r001643_10_1) + 34) & 127;
  int stage_v_367_2 = (((stage_v_148_2 * 3) + pub_r001643_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001643_9_1 * 2) + 22) & 63;
  int stage_v_368_2 = ((pub_r001643_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001643_13_1 * 2) + 44) & 63;
  int stage_v_369_2 = ((pub_r001643_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_53_1 * 3) + pub_r001643_8_1) + 15) & 127;
  int stage_v_370_2 = (((stage_v_53_2 * 3) + pub_r001643_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_28_1 * 3) + pub_r001643_8_1) + 43) & 127;
  int stage_v_371_2 = (((stage_v_28_2 * 3) + pub_r001643_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001643_9_1 * 2) + 42) & 63;
  int stage_v_372_2 = ((pub_r001643_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_121_1 * 3) + pub_r001643_23_1) + 11) & 127;
  int stage_v_373_2 = (((stage_v_121_2 * 3) + pub_r001643_23_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_143_1 * 3) + pub_r001643_5_1) + 39) & 127;
  int stage_v_374_2 = (((stage_v_143_2 * 3) + pub_r001643_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_194_1 * 3) + pub_r001643_20_1) + 23) & 127;
  int stage_v_375_2 = (((stage_v_194_2 * 3) + pub_r001643_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001643_18_1 * 2) + 35) & 63;
  int stage_v_376_2 = ((pub_r001643_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001643_14_1 * 2) + 28) & 63;
  int stage_v_377_2 = ((pub_r001643_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001643_10_1 * 2) + 49) & 63;
  int stage_v_378_2 = ((pub_r001643_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_159_1 * 3) + pub_r001643_21_1) + 42) & 127;
  int stage_v_379_2 = (((stage_v_159_2 * 3) + pub_r001643_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((sec_r001643_3_1 * 3) + pub_r001643_16_1) + 33) & 127;
  int stage_v_380_2 = (((sec_r001643_3_2 * 3) + pub_r001643_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001643_6_1 * 2) + 48) & 63;
  int stage_v_381_2 = ((pub_r001643_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_371_1 * 3) + pub_r001643_14_1) + 5) & 127;
  int stage_v_382_2 = (((stage_v_371_2 * 3) + pub_r001643_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_35_1 * 3) + pub_r001643_17_1) + 40) & 127;
  int stage_v_383_2 = (((stage_v_35_2 * 3) + pub_r001643_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_277_1 * 3) + pub_r001643_20_1) + 43) & 127;
  int stage_v_384_2 = (((stage_v_277_2 * 3) + pub_r001643_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_234_1 * 3) + pub_r001643_10_1) + 11) & 127;
  int stage_v_385_2 = (((stage_v_234_2 * 3) + pub_r001643_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001643_2_1 * 2) + 6) & 63;
  int stage_v_386_2 = ((pub_r001643_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_280_1 * 3) + pub_r001643_12_1) + 29) & 127;
  int stage_v_387_2 = (((stage_v_280_2 * 3) + pub_r001643_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_233_1 * 3) + pub_r001643_12_1) + 4) & 127;
  int stage_v_388_2 = (((stage_v_233_2 * 3) + pub_r001643_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_46_1 * 3) + pub_r001643_13_1) + 3) & 127;
  int stage_v_389_2 = (((stage_v_46_2 * 3) + pub_r001643_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_241_1 * 3) + pub_r001643_3_1) + 28) & 127;
  int stage_v_390_2 = (((stage_v_241_2 * 3) + pub_r001643_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_261_1 * 3) + pub_r001643_7_1) + 25) & 127;
  int stage_v_391_2 = (((stage_v_261_2 * 3) + pub_r001643_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_289_1 * 3) + pub_r001643_1_1) + 18) & 127;
  int stage_v_392_2 = (((stage_v_289_2 * 3) + pub_r001643_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001643_17_1 * 2) + 30) & 63;
  int stage_v_393_2 = ((pub_r001643_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_271_1 * 3) + pub_r001643_3_1) + 31) & 127;
  int stage_v_394_2 = (((stage_v_271_2 * 3) + pub_r001643_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_382_1 * 3) + pub_r001643_0_1) + 24) & 127;
  int stage_v_395_2 = (((stage_v_382_2 * 3) + pub_r001643_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_303_1 * 3) + pub_r001643_11_1) + 31) & 127;
  int stage_v_396_2 = (((stage_v_303_2 * 3) + pub_r001643_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001643_19_1 * 2) + 50) & 63;
  int stage_v_397_2 = ((pub_r001643_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_370_1 * 3) + pub_r001643_6_1) + 6) & 127;
  int stage_v_398_2 = (((stage_v_370_2 * 3) + pub_r001643_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001643_8_1 * 2) + 13) & 63;
  int stage_v_399_2 = ((pub_r001643_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001643_4_1 == pub_r001643_4_2);
  __CPROVER_assume(sec_r001643_6_1 != sec_r001643_6_2);
  __CPROVER_assume(sec_r001643_4_1 != sec_r001643_4_2);
  __CPROVER_assume(pub_r001643_17_1 == pub_r001643_17_2);
  __CPROVER_assume(pub_r001643_21_1 == pub_r001643_21_2);
  __CPROVER_assume(pub_r001643_12_1 == pub_r001643_12_2);
  __CPROVER_assume(sec_r001643_3_1 != sec_r001643_3_2);
  __CPROVER_assume(sec_r001643_8_1 != sec_r001643_8_2);
  __CPROVER_assume(pub_r001643_5_1 == pub_r001643_5_2);
  __CPROVER_assume(pub_r001643_6_1 == pub_r001643_6_2);
  __CPROVER_assume(pub_r001643_22_1 == pub_r001643_22_2);
  __CPROVER_assume(pub_r001643_2_1 == pub_r001643_2_2);
  __CPROVER_assume(pub_r001643_10_1 == pub_r001643_10_2);
  __CPROVER_assume(pub_r001643_14_1 == pub_r001643_14_2);
  __CPROVER_assume(pub_r001643_8_1 == pub_r001643_8_2);
  __CPROVER_assume(pub_r001643_18_1 == pub_r001643_18_2);
  __CPROVER_assume(sec_r001643_0_1 != sec_r001643_0_2);
  __CPROVER_assume(sec_r001643_5_1 != sec_r001643_5_2);
  __CPROVER_assume(pub_r001643_16_1 == pub_r001643_16_2);
  __CPROVER_assume(sec_r001643_12_1 != sec_r001643_12_2);
  __CPROVER_assume(sec_r001643_14_1 != sec_r001643_14_2);
  __CPROVER_assume(pub_r001643_23_1 == pub_r001643_23_2);
  __CPROVER_assume(pub_r001643_1_1 == pub_r001643_1_2);
  __CPROVER_assume(pub_r001643_13_1 == pub_r001643_13_2);
  __CPROVER_assume(sec_r001643_2_1 != sec_r001643_2_2);
  __CPROVER_assume(sec_r001643_17_1 != sec_r001643_17_2);
  __CPROVER_assume(pub_r001643_9_1 == pub_r001643_9_2);
  __CPROVER_assume(pub_r001643_3_1 == pub_r001643_3_2);
  __CPROVER_assume(pub_r001643_19_1 == pub_r001643_19_2);
  __CPROVER_assume(sec_r001643_7_1 != sec_r001643_7_2);
  __CPROVER_assume(sec_r001643_9_1 != sec_r001643_9_2);
  __CPROVER_assume(sec_r001643_10_1 != sec_r001643_10_2);
  __CPROVER_assume(pub_r001643_20_1 == pub_r001643_20_2);
  __CPROVER_assume(sec_r001643_11_1 != sec_r001643_11_2);
  __CPROVER_assume(sec_r001643_16_1 != sec_r001643_16_2);
  __CPROVER_assume(sec_r001643_1_1 != sec_r001643_1_2);
  __CPROVER_assume(sec_r001643_13_1 != sec_r001643_13_2);
  __CPROVER_assume(pub_r001643_7_1 == pub_r001643_7_2);
  __CPROVER_assume(pub_r001643_11_1 == pub_r001643_11_2);
  __CPROVER_assume(sec_r001643_15_1 != sec_r001643_15_2);
  __CPROVER_assume(pub_r001643_0_1 == pub_r001643_0_2);
  __CPROVER_assume(pub_r001643_15_1 == pub_r001643_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
}


