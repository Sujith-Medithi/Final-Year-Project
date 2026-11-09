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
struct EventLog_R001045_4513_0
{
  int timestamp;
  int severity;
  int code;
  int buffer[3];
};
struct AudioFrame_R001045_4513_1
{
  unsigned char rms;
  int peak;
  short gain;
  unsigned char sample_rate;
  int envelope;
  int buffer[3];
};
struct SensorNode_R001045_4513_2
{
  int threshold;
  int offset;
  unsigned char status;
  int gain;
  unsigned char reading;
  unsigned char calib;
  int buffer[3];
};
struct CipherContext_R001045_4513_3
{
  int tag;
  int nonce;
  short counter;
  int flags;
  int iv;
  int buffer[3];
};
union PacketPayload_R001045_4513_0
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
void fn_R001045_4513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quantum_14_1 = 0;
  int quantum_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_14_1 = ((quantum_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_14_2 = ((quantum_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_14_1) & 127;
    acc_2 = (acc_2 + quantum_14_2) & 127;
  }

  int factor_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_72_1 > 23)
  {
    acc_1 = ((acc_1 + (factor_72_1 * 2)) + 5) & 127;
    aux_1 ^= factor_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_72_2 > 23)
  {
    acc_2 = ((acc_2 + (factor_72_2 * 2)) + 5) & 127;
    aux_2 ^= factor_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_14_1 == quantum_14_2);
  assert(factor_72_1 == factor_72_2);
}

int fn_R001045_4513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quantum_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_14 = ((quantum_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_14) & 127;
  }

  int factor_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_72 > 23)
  {
    acc = ((acc + (factor_72 * 2)) + 5) & 127;
    aux ^= factor_72 & 15;
  }
  else
  {
    acc = ((acc - factor_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001045_4513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st_1 = {0};
  struct AudioFrame_R001045_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_24_1)
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

  switch (metric_24_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_88_1 = 0;
  int weight_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_88_1 = ((weight_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_88_2 = ((weight_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_88_1) & 127;
    acc_2 = (acc_2 + weight_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_24_1 == metric_24_2);
  assert(weight_88_1 == weight_88_2);
}

int fn_R001045_4513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric_24 = (aux + st.buffer[1]) & 3;
  switch (metric_24)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_88 = ((weight_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001045_4513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_43_1 = 0;
  int damping_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_43_1 = ((damping_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_43_2 = ((damping_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_43_1) & 127;
    acc_2 = (acc_2 + damping_43_2) & 127;
  }

  int mask_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_62_1)
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

  switch (mask_62_2)
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
  int pivot_87_1 = local_arr_1[aux_1 % 3];
  int pivot_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_87_2 * 2)) & 127;
  int residue_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_96_1) & 63;
  aux_2 = (aux_2 + residue_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_43_1 == damping_43_2);
  assert(mask_62_1 == mask_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_87_1 == pivot_87_2);
  assert(residue_96_1 == residue_96_2);
}

int fn_R001045_4513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_43 = ((damping_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_43) & 127;
  }

  int mask_62 = (aux + st.buffer[1]) & 3;
  switch (mask_62)
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
  int pivot_87 = local_arr[aux % 3];
  acc = (acc + (pivot_87 * 2)) & 127;
  int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001045_4513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st_1 = {0};
  struct EventLog_R001045_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_87_1 = 0;
  int damping_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_87_1 = ((damping_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_87_2 = ((damping_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_87_1) & 127;
    acc_2 = (acc_2 + damping_87_2) & 127;
  }

  int checksum_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_58_1 > 33)
  {
    acc_1 = ((acc_1 + (checksum_58_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_58_2 > 33)
  {
    acc_2 = ((acc_2 + (checksum_58_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_87_1 == damping_87_2);
  assert(checksum_58_1 == checksum_58_2);
}

int fn_R001045_4513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_87 = ((damping_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_87) & 127;
  }

  int checksum_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_58 > 33)
  {
    acc = ((acc + (checksum_58 * 2)) + 5) & 127;
    aux ^= checksum_58 & 15;
  }
  else
  {
    acc = ((acc - checksum_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001045_4513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int metric_74_1 = 0;
  int metric_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_74_1 = ((metric_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_74_2 = ((metric_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_74_1) & 127;
    acc_2 = (acc_2 + metric_74_2) & 127;
  }

  int window_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_54_1)
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

  switch (window_54_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_74_1 == metric_74_2);
  assert(window_54_1 == window_54_2);
}

int fn_R001045_4513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int metric_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_74 = ((metric_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_74) & 127;
  }

  int window_54 = (aux + st.buffer[1]) & 3;
  switch (window_54)
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

void fn_R001045_4513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_80_1)
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

  switch (quantum_80_2)
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

  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 39)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 39)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_12_1 = 0;
  int sample_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_12_1 = ((sample_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_12_2 = ((sample_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_12_1) & 127;
    acc_2 = (acc_2 + sample_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_80_1 == quantum_80_2);
  assert(checksum_35_1 == checksum_35_2);
  assert(sample_12_1 == sample_12_2);
}

int fn_R001045_4513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_80 = (aux + st.buffer[1]) & 3;
  switch (quantum_80)
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

  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 39)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  int sample_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_12 = ((sample_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001045_4513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_11_1 > 34)
  {
    acc_1 = ((acc_1 + (stride_11_1 * 2)) + 5) & 127;
    aux_1 ^= stride_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_11_2 > 34)
  {
    acc_2 = ((acc_2 + (stride_11_2 * 2)) + 5) & 127;
    aux_2 ^= stride_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_14_1 = 0;
  int stride_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_14_1 = ((stride_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_14_2 = ((stride_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_14_1) & 127;
    acc_2 = (acc_2 + stride_14_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_68_1 = local_arr_1[aux_1 % 3];
  int quotient_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_68_2 * 2)) & 127;
  int accumulator_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_29_1)
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

  switch (accumulator_29_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_11_1 == stride_11_2);
  assert(stride_14_1 == stride_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_68_1 == quotient_68_2);
  assert(accumulator_29_1 == accumulator_29_2);
}

int fn_R001045_4513_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_11 > 34)
  {
    acc = ((acc + (stride_11 * 2)) + 5) & 127;
    aux ^= stride_11 & 15;
  }
  else
  {
    acc = ((acc - stride_11) + 11) & 127;
    aux += 3;
  }
  int stride_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_14 = ((stride_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_14) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_68 = local_arr[aux % 3];
  acc = (acc + (quotient_68 * 2)) & 127;
  int accumulator_29 = (aux + st.buffer[1]) & 3;
  switch (accumulator_29)
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

void fn_R001045_4513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_68_1 = 0;
  int damping_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_68_1 = ((damping_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_68_2 = ((damping_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_68_1) & 127;
    acc_2 = (acc_2 + damping_68_2) & 127;
  }

  int window_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_18_1 > 40)
  {
    acc_1 = ((acc_1 + (window_18_1 * 2)) + 5) & 127;
    aux_1 ^= window_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_18_2 > 40)
  {
    acc_2 = ((acc_2 + (window_18_2 * 2)) + 5) & 127;
    aux_2 ^= window_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_68_1 == damping_68_2);
  assert(window_18_1 == window_18_2);
}

int fn_R001045_4513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_68 = ((damping_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_68) & 127;
  }

  int window_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_18 > 40)
  {
    acc = ((acc + (window_18 * 2)) + 5) & 127;
    aux ^= window_18 & 15;
  }
  else
  {
    acc = ((acc - window_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001045_4513_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quantum_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_64_1)
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

  switch (quantum_64_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_17_1 = local_arr_1[aux_1 % 3];
  int index_reg_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_17_2 * 2)) & 127;
  int residue_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_61_1) & 63;
  aux_2 = (aux_2 + residue_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_64_1 == quantum_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_17_1 == index_reg_17_2);
  assert(residue_61_1 == residue_61_2);
}

int fn_R001045_4513_8(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quantum_64 = (aux + st.buffer[1]) & 3;
  switch (quantum_64)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_17 = local_arr[aux % 3];
  acc = (acc + (index_reg_17 * 2)) & 127;
  int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001045_4513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int anchor_56_1 = 0;
  int anchor_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_56_1 = ((anchor_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_56_2 = ((anchor_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_56_1) & 127;
    acc_2 = (acc_2 + anchor_56_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_40_1 = local_arr_1[aux_1 % 3];
  int coefficient_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_40_2 * 2)) & 127;
  int pivot_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_25_1 > 45)
  {
    acc_1 = ((acc_1 + (pivot_25_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_25_2 > 45)
  {
    acc_2 = ((acc_2 + (pivot_25_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_56_1 == anchor_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_40_1 == coefficient_40_2);
  assert(pivot_25_1 == pivot_25_2);
}

int fn_R001045_4513_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int anchor_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_56 = ((anchor_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_56) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_40 = local_arr[aux % 3];
  acc = (acc + (coefficient_40 * 2)) & 127;
  int pivot_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_25 > 45)
  {
    acc = ((acc + (pivot_25 * 2)) + 5) & 127;
    aux ^= pivot_25 & 15;
  }
  else
  {
    acc = ((acc - pivot_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001045_4513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st_1 = {0};
  struct EventLog_R001045_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_51_1 = local_arr_1[aux_1 % 3];
  int weight_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_51_2 * 2)) & 127;
  int coefficient_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_97_1)
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

  switch (coefficient_97_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_51_1 == weight_51_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R001045_4513_10(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int weight_51 = local_arr[aux % 3];
  acc = (acc + (weight_51 * 2)) & 127;
  int coefficient_97 = (aux + st.buffer[1]) & 3;
  switch (coefficient_97)
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

void fn_R001045_4513_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st_1 = {0};
  struct AudioFrame_R001045_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_50_1 = local_arr_1[aux_1 % 3];
  int delta_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_50_2 * 2)) & 127;
  int stride_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_19_1)
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

  switch (stride_19_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_50_1 == delta_50_2);
  assert(stride_19_1 == stride_19_2);
}

int fn_R001045_4513_11(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int delta_50 = local_arr[aux % 3];
  acc = (acc + (delta_50 * 2)) & 127;
  int stride_19 = (aux + st.buffer[1]) & 3;
  switch (stride_19)
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

void fn_R001045_4513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st_1 = {0};
  struct EventLog_R001045_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_43_1 > 45)
  {
    acc_1 = ((acc_1 + (window_43_1 * 2)) + 5) & 127;
    aux_1 ^= window_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_43_2 > 45)
  {
    acc_2 = ((acc_2 + (window_43_2 * 2)) + 5) & 127;
    aux_2 ^= window_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_95_1 = local_arr_1[aux_1 % 3];
  int offset_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_95_1 == offset_95_2);
}

int fn_R001045_4513_12(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_43 > 45)
  {
    acc = ((acc + (window_43 * 2)) + 5) & 127;
    aux ^= window_43 & 15;
  }
  else
  {
    acc = ((acc - window_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_95 = local_arr[aux % 3];
  acc = (acc + (offset_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001045_4513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st_1 = {0};
  struct AudioFrame_R001045_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_28_1 = local_arr_1[aux_1 % 3];
  int parity_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_28_2 * 2)) & 127;
  int window_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_81_1)
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

  switch (window_81_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_28_1 == parity_28_2);
  assert(window_81_1 == window_81_2);
}

int fn_R001045_4513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int parity_28 = local_arr[aux % 3];
  acc = (acc + (parity_28 * 2)) & 127;
  int window_81 = (aux + st.buffer[1]) & 3;
  switch (window_81)
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

void fn_R001045_4513_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st_1 = {0};
  struct AudioFrame_R001045_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_54_1 = 0;
  int stride_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_54_1 = ((stride_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_54_2 = ((stride_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_54_1) & 127;
    acc_2 = (acc_2 + stride_54_2) & 127;
  }

  int pivot_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_51_1) & 63;
  aux_2 = (aux_2 + pivot_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_54_1 == stride_54_2);
  assert(pivot_51_1 == pivot_51_2);
}

int fn_R001045_4513_14(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_54 = ((stride_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_54) & 127;
  }

  int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001045_4513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st_1 = {0};
  struct AudioFrame_R001045_4513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_74_1)
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

  switch (delta_74_2)
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

  int mask_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_65_1) & 63;
  aux_2 = (aux_2 + mask_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_14_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_14_1 * 2)) + 5) & 127;
    aux_1 ^= margin_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_14_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_14_2 * 2)) + 5) & 127;
    aux_2 ^= margin_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_74_1 = local_arr_1[aux_1 % 3];
  int accumulator_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_74_1 == delta_74_2);
  assert(mask_65_1 == mask_65_2);
  assert(margin_14_1 == margin_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_74_1 == accumulator_74_2);
}

int fn_R001045_4513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001045_4513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_74 = (aux + st.buffer[1]) & 3;
  switch (delta_74)
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

  int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_65) & 63;
  acc ^= aux;
  int margin_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_14 > 24)
  {
    acc = ((acc + (margin_14 * 2)) + 5) & 127;
    aux ^= margin_14 & 15;
  }
  else
  {
    acc = ((acc - margin_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_74 = local_arr[aux % 3];
  acc = (acc + (accumulator_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001045_4513_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_54_1 = local_arr_1[aux_1 % 3];
  int cursor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_54_2 * 2)) & 127;
  int accumulator_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_90_1)
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

  switch (accumulator_90_2)
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

  int window_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_62_1 > 49)
  {
    acc_1 = ((acc_1 + (window_62_1 * 2)) + 5) & 127;
    aux_1 ^= window_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_62_2 > 49)
  {
    acc_2 = ((acc_2 + (window_62_2 * 2)) + 5) & 127;
    aux_2 ^= window_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_54_1 == cursor_54_2);
  assert(accumulator_90_1 == accumulator_90_2);
  assert(window_62_1 == window_62_2);
}

int fn_R001045_4513_16(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int cursor_54 = local_arr[aux % 3];
  acc = (acc + (cursor_54 * 2)) & 127;
  int accumulator_90 = (aux + st.buffer[1]) & 3;
  switch (accumulator_90)
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

  int window_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_62 > 49)
  {
    acc = ((acc + (window_62 * 2)) + 5) & 127;
    aux ^= window_62 & 15;
  }
  else
  {
    acc = ((acc - window_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001045_4513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st_1 = {0};
  struct EventLog_R001045_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_32_1)
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

  switch (margin_32_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_32_1 == margin_32_2);
}

int fn_R001045_4513_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_32 = (aux + st.buffer[1]) & 3;
  switch (margin_32)
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

void fn_R001045_4513_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st_1 = {0};
  struct SensorNode_R001045_4513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_10_1 > 38)
  {
    acc_1 = ((acc_1 + (scale_10_1 * 2)) + 5) & 127;
    aux_1 ^= scale_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_10_2 > 38)
  {
    acc_2 = ((acc_2 + (scale_10_2 * 2)) + 5) & 127;
    aux_2 ^= scale_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_97_1 = local_arr_1[aux_1 % 3];
  int tracker_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_10_1 == scale_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_97_1 == tracker_97_2);
}

int fn_R001045_4513_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001045_4513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_10 > 38)
  {
    acc = ((acc + (scale_10 * 2)) + 5) & 127;
    aux ^= scale_10 & 15;
  }
  else
  {
    acc = ((acc - scale_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tracker_97 = local_arr[aux % 3];
  acc = (acc + (tracker_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001045_4513_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_29_1)
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

  switch (parity_29_2)
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

  int mask_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_54_1 > 14)
  {
    acc_1 = ((acc_1 + (mask_54_1 * 2)) + 5) & 127;
    aux_1 ^= mask_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_54_2 > 14)
  {
    acc_2 = ((acc_2 + (mask_54_2 * 2)) + 5) & 127;
    aux_2 ^= mask_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_52_1) & 63;
  aux_2 = (aux_2 + pivot_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_29_1 == parity_29_2);
  assert(mask_54_1 == mask_54_2);
  assert(pivot_52_1 == pivot_52_2);
}

int fn_R001045_4513_19(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_29 = (aux + st.buffer[1]) & 3;
  switch (parity_29)
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

  int mask_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_54 > 14)
  {
    acc = ((acc + (mask_54 * 2)) + 5) & 127;
    aux ^= mask_54 & 15;
  }
  else
  {
    acc = ((acc - mask_54) + 11) & 127;
    aux += 3;
  }
  int pivot_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001045_4513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
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
  int pivot_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_62_1) & 63;
  aux_2 = (aux_2 + pivot_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_86_1 > 19)
  {
    acc_1 = ((acc_1 + (stride_86_1 * 2)) + 5) & 127;
    aux_1 ^= stride_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_86_2 > 19)
  {
    acc_2 = ((acc_2 + (stride_86_2 * 2)) + 5) & 127;
    aux_2 ^= stride_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(stride_86_1 == stride_86_2);
}

int fn_R001045_4513_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_62) & 63;
  acc ^= aux;
  int stride_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_86 > 19)
  {
    acc = ((acc + (stride_86 * 2)) + 5) & 127;
    aux ^= stride_86 & 15;
  }
  else
  {
    acc = ((acc - stride_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001045_4513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st_1 = {0};
  struct EventLog_R001045_4513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_71_1 = local_arr_1[aux_1 % 3];
  int delta_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_71_2 * 2)) & 127;
  int sample_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_86_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_86_1 * 2)) + 5) & 127;
    aux_1 ^= sample_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_86_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_86_2 * 2)) + 5) & 127;
    aux_2 ^= sample_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_39_1 = 0;
  int stride_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_39_1 = ((stride_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_39_2 = ((stride_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_39_1) & 127;
    acc_2 = (acc_2 + stride_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_71_1 == delta_71_2);
  assert(sample_86_1 == sample_86_2);
  assert(stride_39_1 == stride_39_2);
}

int fn_R001045_4513_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001045_4513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int delta_71 = local_arr[aux % 3];
  acc = (acc + (delta_71 * 2)) & 127;
  int sample_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_86 > 30)
  {
    acc = ((acc + (sample_86 * 2)) + 5) & 127;
    aux ^= sample_86 & 15;
  }
  else
  {
    acc = ((acc - sample_86) + 11) & 127;
    aux += 3;
  }
  int stride_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_39 = ((stride_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001045_4513_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st_1 = {0};
  struct CipherContext_R001045_4513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_90_1) & 63;
  aux_2 = (aux_2 + index_reg_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_40_1 > 42)
  {
    acc_1 = ((acc_1 + (damping_40_1 * 2)) + 5) & 127;
    aux_1 ^= damping_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_40_2 > 42)
  {
    acc_2 = ((acc_2 + (damping_40_2 * 2)) + 5) & 127;
    aux_2 ^= damping_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
  assert(damping_40_1 == damping_40_2);
}

int fn_R001045_4513_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001045_4513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_90) & 63;
  acc ^= aux;
  int damping_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_40 > 42)
  {
    acc = ((acc + (damping_40 * 2)) + 5) & 127;
    aux ^= damping_40 & 15;
  }
  else
  {
    acc = ((acc - damping_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001045_0_1;
  int sec_r001045_0_2;
  int sec_r001045_1_1;
  int sec_r001045_1_2;
  int sec_r001045_2_1;
  int sec_r001045_2_2;
  int sec_r001045_3_1;
  int sec_r001045_3_2;
  int sec_r001045_4_1;
  int sec_r001045_4_2;
  int sec_r001045_5_1;
  int sec_r001045_5_2;
  int sec_r001045_6_1;
  int sec_r001045_6_2;
  int sec_r001045_7_1;
  int sec_r001045_7_2;
  int sec_r001045_8_1;
  int sec_r001045_8_2;
  int sec_r001045_9_1;
  int sec_r001045_9_2;
  int sec_r001045_10_1;
  int sec_r001045_10_2;
  int sec_r001045_11_1;
  int sec_r001045_11_2;
  int sec_r001045_12_1;
  int sec_r001045_12_2;
  int sec_r001045_13_1;
  int sec_r001045_13_2;
  int sec_r001045_14_1;
  int sec_r001045_14_2;
  int sec_r001045_15_1;
  int sec_r001045_15_2;
  int sec_r001045_16_1;
  int sec_r001045_16_2;
  int sec_r001045_17_1;
  int sec_r001045_17_2;
  int sec_r001045_18_1;
  int sec_r001045_18_2;
  int sec_r001045_19_1;
  int sec_r001045_19_2;
  int sec_r001045_20_1;
  int sec_r001045_20_2;
  int sec_r001045_21_1;
  int sec_r001045_21_2;
  int sec_r001045_22_1;
  int sec_r001045_22_2;
  int sec_r001045_23_1;
  int sec_r001045_23_2;
  int pub_r001045_0_1;
  int pub_r001045_0_2;
  int pub_r001045_1_1;
  int pub_r001045_1_2;
  int pub_r001045_2_1;
  int pub_r001045_2_2;
  int pub_r001045_3_1;
  int pub_r001045_3_2;
  int pub_r001045_4_1;
  int pub_r001045_4_2;
  int pub_r001045_5_1;
  int pub_r001045_5_2;
  int pub_r001045_6_1;
  int pub_r001045_6_2;
  int pub_r001045_7_1;
  int pub_r001045_7_2;
  int pub_r001045_8_1;
  int pub_r001045_8_2;
  int pub_r001045_9_1;
  int pub_r001045_9_2;
  int pub_r001045_10_1;
  int pub_r001045_10_2;
  int pub_r001045_11_1;
  int pub_r001045_11_2;
  int pub_r001045_12_1;
  int pub_r001045_12_2;
  int pub_r001045_13_1;
  int pub_r001045_13_2;
  int pub_r001045_14_1;
  int pub_r001045_14_2;
  int pub_r001045_15_1;
  int pub_r001045_15_2;
  int pub_r001045_16_1;
  int pub_r001045_16_2;
  int pub_r001045_17_1;
  int pub_r001045_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001045_0_1 >= (-100)) && (pub_r001045_0_1 <= 100));
  __CPROVER_assume((pub_r001045_0_2 >= (-100)) && (pub_r001045_0_2 <= 100));
  __CPROVER_assume((pub_r001045_1_1 >= (-100)) && (pub_r001045_1_1 <= 100));
  __CPROVER_assume((pub_r001045_1_2 >= (-100)) && (pub_r001045_1_2 <= 100));
  __CPROVER_assume((pub_r001045_2_1 >= (-100)) && (pub_r001045_2_1 <= 100));
  __CPROVER_assume((pub_r001045_2_2 >= (-100)) && (pub_r001045_2_2 <= 100));
  __CPROVER_assume((pub_r001045_3_1 >= (-100)) && (pub_r001045_3_1 <= 100));
  __CPROVER_assume((pub_r001045_3_2 >= (-100)) && (pub_r001045_3_2 <= 100));
  __CPROVER_assume((pub_r001045_4_1 >= (-100)) && (pub_r001045_4_1 <= 100));
  __CPROVER_assume((pub_r001045_4_2 >= (-100)) && (pub_r001045_4_2 <= 100));
  __CPROVER_assume((pub_r001045_5_1 >= (-100)) && (pub_r001045_5_1 <= 100));
  __CPROVER_assume((pub_r001045_5_2 >= (-100)) && (pub_r001045_5_2 <= 100));
  __CPROVER_assume((pub_r001045_6_1 >= (-100)) && (pub_r001045_6_1 <= 100));
  __CPROVER_assume((pub_r001045_6_2 >= (-100)) && (pub_r001045_6_2 <= 100));
  __CPROVER_assume((pub_r001045_7_1 >= (-100)) && (pub_r001045_7_1 <= 100));
  __CPROVER_assume((pub_r001045_7_2 >= (-100)) && (pub_r001045_7_2 <= 100));
  __CPROVER_assume((pub_r001045_8_1 >= (-100)) && (pub_r001045_8_1 <= 100));
  __CPROVER_assume((pub_r001045_8_2 >= (-100)) && (pub_r001045_8_2 <= 100));
  __CPROVER_assume((pub_r001045_9_1 >= (-100)) && (pub_r001045_9_1 <= 100));
  __CPROVER_assume((pub_r001045_9_2 >= (-100)) && (pub_r001045_9_2 <= 100));
  __CPROVER_assume((pub_r001045_10_1 >= (-100)) && (pub_r001045_10_1 <= 100));
  __CPROVER_assume((pub_r001045_10_2 >= (-100)) && (pub_r001045_10_2 <= 100));
  __CPROVER_assume((pub_r001045_11_1 >= (-100)) && (pub_r001045_11_1 <= 100));
  __CPROVER_assume((pub_r001045_11_2 >= (-100)) && (pub_r001045_11_2 <= 100));
  __CPROVER_assume((pub_r001045_12_1 >= (-100)) && (pub_r001045_12_1 <= 100));
  __CPROVER_assume((pub_r001045_12_2 >= (-100)) && (pub_r001045_12_2 <= 100));
  __CPROVER_assume((pub_r001045_13_1 >= (-100)) && (pub_r001045_13_1 <= 100));
  __CPROVER_assume((pub_r001045_13_2 >= (-100)) && (pub_r001045_13_2 <= 100));
  __CPROVER_assume((pub_r001045_14_1 >= (-100)) && (pub_r001045_14_1 <= 100));
  __CPROVER_assume((pub_r001045_14_2 >= (-100)) && (pub_r001045_14_2 <= 100));
  __CPROVER_assume((pub_r001045_15_1 >= (-100)) && (pub_r001045_15_1 <= 100));
  __CPROVER_assume((pub_r001045_15_2 >= (-100)) && (pub_r001045_15_2 <= 100));
  __CPROVER_assume((pub_r001045_16_1 >= (-100)) && (pub_r001045_16_1 <= 100));
  __CPROVER_assume((pub_r001045_16_2 >= (-100)) && (pub_r001045_16_2 <= 100));
  __CPROVER_assume((pub_r001045_17_1 >= (-100)) && (pub_r001045_17_1 <= 100));
  __CPROVER_assume((pub_r001045_17_2 >= (-100)) && (pub_r001045_17_2 <= 100));
  __CPROVER_assume((sec_r001045_0_1 >= 0) && (sec_r001045_0_1 <= 255));
  __CPROVER_assume((sec_r001045_0_2 >= 0) && (sec_r001045_0_2 <= 255));
  __CPROVER_assume((sec_r001045_1_1 >= 0) && (sec_r001045_1_1 <= 255));
  __CPROVER_assume((sec_r001045_1_2 >= 0) && (sec_r001045_1_2 <= 255));
  __CPROVER_assume((sec_r001045_2_1 >= 0) && (sec_r001045_2_1 <= 255));
  __CPROVER_assume((sec_r001045_2_2 >= 0) && (sec_r001045_2_2 <= 255));
  __CPROVER_assume((sec_r001045_3_1 >= 0) && (sec_r001045_3_1 <= 255));
  __CPROVER_assume((sec_r001045_3_2 >= 0) && (sec_r001045_3_2 <= 255));
  __CPROVER_assume((sec_r001045_4_1 >= 0) && (sec_r001045_4_1 <= 255));
  __CPROVER_assume((sec_r001045_4_2 >= 0) && (sec_r001045_4_2 <= 255));
  __CPROVER_assume((sec_r001045_5_1 >= 0) && (sec_r001045_5_1 <= 255));
  __CPROVER_assume((sec_r001045_5_2 >= 0) && (sec_r001045_5_2 <= 255));
  __CPROVER_assume((sec_r001045_6_1 >= 0) && (sec_r001045_6_1 <= 255));
  __CPROVER_assume((sec_r001045_6_2 >= 0) && (sec_r001045_6_2 <= 255));
  __CPROVER_assume((sec_r001045_7_1 >= 0) && (sec_r001045_7_1 <= 255));
  __CPROVER_assume((sec_r001045_7_2 >= 0) && (sec_r001045_7_2 <= 255));
  __CPROVER_assume((sec_r001045_8_1 >= 0) && (sec_r001045_8_1 <= 255));
  __CPROVER_assume((sec_r001045_8_2 >= 0) && (sec_r001045_8_2 <= 255));
  __CPROVER_assume((sec_r001045_9_1 >= 0) && (sec_r001045_9_1 <= 255));
  __CPROVER_assume((sec_r001045_9_2 >= 0) && (sec_r001045_9_2 <= 255));
  __CPROVER_assume((sec_r001045_10_1 >= 0) && (sec_r001045_10_1 <= 255));
  __CPROVER_assume((sec_r001045_10_2 >= 0) && (sec_r001045_10_2 <= 255));
  __CPROVER_assume((sec_r001045_11_1 >= 0) && (sec_r001045_11_1 <= 255));
  __CPROVER_assume((sec_r001045_11_2 >= 0) && (sec_r001045_11_2 <= 255));
  __CPROVER_assume((sec_r001045_12_1 >= 0) && (sec_r001045_12_1 <= 255));
  __CPROVER_assume((sec_r001045_12_2 >= 0) && (sec_r001045_12_2 <= 255));
  __CPROVER_assume((sec_r001045_13_1 >= 0) && (sec_r001045_13_1 <= 255));
  __CPROVER_assume((sec_r001045_13_2 >= 0) && (sec_r001045_13_2 <= 255));
  __CPROVER_assume((sec_r001045_14_1 >= 0) && (sec_r001045_14_1 <= 255));
  __CPROVER_assume((sec_r001045_14_2 >= 0) && (sec_r001045_14_2 <= 255));
  __CPROVER_assume((sec_r001045_15_1 >= 0) && (sec_r001045_15_1 <= 255));
  __CPROVER_assume((sec_r001045_15_2 >= 0) && (sec_r001045_15_2 <= 255));
  __CPROVER_assume((sec_r001045_16_1 >= 0) && (sec_r001045_16_1 <= 255));
  __CPROVER_assume((sec_r001045_16_2 >= 0) && (sec_r001045_16_2 <= 255));
  __CPROVER_assume((sec_r001045_17_1 >= 0) && (sec_r001045_17_1 <= 255));
  __CPROVER_assume((sec_r001045_17_2 >= 0) && (sec_r001045_17_2 <= 255));
  __CPROVER_assume((sec_r001045_18_1 >= 0) && (sec_r001045_18_1 <= 255));
  __CPROVER_assume((sec_r001045_18_2 >= 0) && (sec_r001045_18_2 <= 255));
  __CPROVER_assume((sec_r001045_19_1 >= 0) && (sec_r001045_19_1 <= 255));
  __CPROVER_assume((sec_r001045_19_2 >= 0) && (sec_r001045_19_2 <= 255));
  __CPROVER_assume((sec_r001045_20_1 >= 0) && (sec_r001045_20_1 <= 255));
  __CPROVER_assume((sec_r001045_20_2 >= 0) && (sec_r001045_20_2 <= 255));
  __CPROVER_assume((sec_r001045_21_1 >= 0) && (sec_r001045_21_1 <= 255));
  __CPROVER_assume((sec_r001045_21_2 >= 0) && (sec_r001045_21_2 <= 255));
  __CPROVER_assume((sec_r001045_22_1 >= 0) && (sec_r001045_22_1 <= 255));
  __CPROVER_assume((sec_r001045_22_2 >= 0) && (sec_r001045_22_2 <= 255));
  __CPROVER_assume((sec_r001045_23_1 >= 0) && (sec_r001045_23_1 <= 255));
  __CPROVER_assume((sec_r001045_23_2 >= 0) && (sec_r001045_23_2 <= 255));
  struct EventLog_R001045_4513_0 st_var_0_1 = {0};
  struct EventLog_R001045_4513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001045_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001045_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001045_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001045_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001045_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001045_0_2 + 7) & 15;
  struct AudioFrame_R001045_4513_1 st_var_1_1 = {0};
  struct AudioFrame_R001045_4513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001045_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001045_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001045_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001045_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001045_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001045_0_2 + 9) & 15;
  struct SensorNode_R001045_4513_2 st_var_2_1 = {0};
  struct SensorNode_R001045_4513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001045_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001045_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001045_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001045_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001045_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001045_0_2 + 11) & 15;
  struct CipherContext_R001045_4513_3 st_var_3_1 = {0};
  struct CipherContext_R001045_4513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001045_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001045_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001045_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001045_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001045_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001045_0_2 + 13) & 15;
  union PacketPayload_R001045_4513_0 u_var_1;
  union PacketPayload_R001045_4513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001045_4513_0(sec_r001045_0_1, sec_r001045_1_1, pub_r001045_2_1);
  int helper_flow_0_2 = fn_R001045_4513_0(sec_r001045_0_2, sec_r001045_1_2, pub_r001045_2_2);
  fn_R001045_4513_0_2(sec_r001045_0_1, sec_r001045_1_1, pub_r001045_2_1, sec_r001045_0_2, sec_r001045_1_2, pub_r001045_2_2);
  int helper_flow_1_1 = fn_R001045_4513_1(sec_r001045_1_1, pub_r001045_2_1, pub_r001045_3_1, pub_r001045_4_1);
  int helper_flow_1_2 = fn_R001045_4513_1(sec_r001045_1_2, pub_r001045_2_2, pub_r001045_3_2, pub_r001045_4_2);
  fn_R001045_4513_1_2(sec_r001045_1_1, pub_r001045_2_1, pub_r001045_3_1, pub_r001045_4_1, sec_r001045_1_2, pub_r001045_2_2, pub_r001045_3_2, pub_r001045_4_2);
  int helper_flow_2_1 = fn_R001045_4513_2(sec_r001045_2_1, sec_r001045_3_1, pub_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1);
  int helper_flow_2_2 = fn_R001045_4513_2(sec_r001045_2_2, sec_r001045_3_2, pub_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2);
  fn_R001045_4513_2_2(sec_r001045_2_1, sec_r001045_3_1, pub_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1, sec_r001045_2_2, sec_r001045_3_2, pub_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2);
  int helper_flow_3_1 = fn_R001045_4513_3(sec_r001045_3_1, pub_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1);
  int helper_flow_3_2 = fn_R001045_4513_3(sec_r001045_3_2, pub_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2);
  fn_R001045_4513_3_2(sec_r001045_3_1, pub_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1, sec_r001045_3_2, pub_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2);
  int helper_flow_4_1 = fn_R001045_4513_4(sec_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1, pub_r001045_7_1, pub_r001045_8_1);
  int helper_flow_4_2 = fn_R001045_4513_4(sec_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2, pub_r001045_7_2, pub_r001045_8_2);
  fn_R001045_4513_4_2(sec_r001045_4_1, pub_r001045_5_1, pub_r001045_6_1, pub_r001045_7_1, pub_r001045_8_1, sec_r001045_4_2, pub_r001045_5_2, pub_r001045_6_2, pub_r001045_7_2, pub_r001045_8_2);
  int helper_flow_5_1 = fn_R001045_4513_5(sec_r001045_5_1, sec_r001045_6_1, pub_r001045_7_1, pub_r001045_8_1);
  int helper_flow_5_2 = fn_R001045_4513_5(sec_r001045_5_2, sec_r001045_6_2, pub_r001045_7_2, pub_r001045_8_2);
  fn_R001045_4513_5_2(sec_r001045_5_1, sec_r001045_6_1, pub_r001045_7_1, pub_r001045_8_1, sec_r001045_5_2, sec_r001045_6_2, pub_r001045_7_2, pub_r001045_8_2);
  int helper_flow_6_1 = fn_R001045_4513_6(sec_r001045_6_1, sec_r001045_7_1);
  int helper_flow_6_2 = fn_R001045_4513_6(sec_r001045_6_2, sec_r001045_7_2);
  fn_R001045_4513_6_2(sec_r001045_6_1, sec_r001045_7_1, sec_r001045_6_2, sec_r001045_7_2);
  int helper_flow_7_1 = fn_R001045_4513_7(sec_r001045_7_1, sec_r001045_8_1, pub_r001045_9_1);
  int helper_flow_7_2 = fn_R001045_4513_7(sec_r001045_7_2, sec_r001045_8_2, pub_r001045_9_2);
  fn_R001045_4513_7_2(sec_r001045_7_1, sec_r001045_8_1, pub_r001045_9_1, sec_r001045_7_2, sec_r001045_8_2, pub_r001045_9_2);
  int helper_flow_8_1 = fn_R001045_4513_8(sec_r001045_8_1, sec_r001045_9_1);
  int helper_flow_8_2 = fn_R001045_4513_8(sec_r001045_8_2, sec_r001045_9_2);
  fn_R001045_4513_8_2(sec_r001045_8_1, sec_r001045_9_1, sec_r001045_8_2, sec_r001045_9_2);
  int stage_v_0_1 = ((pub_r001045_11_1 * 2) + 10) & 63;
  int stage_v_0_2 = ((pub_r001045_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001045_0_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001045_0_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((pub_r001045_13_1 * 2) + 48) & 63;
  int stage_v_2_2 = ((pub_r001045_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001045_22_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001045_22_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((pub_r001045_15_1 * 2) + 16) & 63;
  int stage_v_4_2 = ((pub_r001045_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_5_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((helper_flow_8_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_6_2 = ((helper_flow_8_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((sec_r001045_0_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_7_2 = ((sec_r001045_0_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((pub_r001045_11_1 * 2) + 35) & 63;
  int stage_v_8_2 = ((pub_r001045_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001045_5_1 * 2) + 18) & 63;
  int stage_v_9_2 = ((pub_r001045_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001045_3_1 * 2) + 37) & 63;
  int stage_v_10_2 = ((pub_r001045_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001045_7_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001045_7_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((sec_r001045_14_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001045_14_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((helper_flow_1_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_13_2 = ((helper_flow_1_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((sec_r001045_3_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001045_3_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001045_9_1 * 2) + 15) & 63;
  int stage_v_16_2 = ((pub_r001045_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001045_11_1 * 2) + 23) & 63;
  int stage_v_17_2 = ((pub_r001045_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001045_3_1 * 2) + 50) & 63;
  int stage_v_18_2 = ((pub_r001045_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001045_15_1 * 2) + 33) & 63;
  int stage_v_19_2 = ((pub_r001045_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_7_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_7_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((sec_r001045_14_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_21_2 = ((sec_r001045_14_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((stage_v_11_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_22_2 = ((stage_v_11_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_23_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((sec_r001045_7_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001045_7_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((sec_r001045_21_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001045_21_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((stage_v_24_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_26_2 = ((stage_v_24_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((pub_r001045_0_1 * 2) + 22) & 63;
  int stage_v_27_2 = ((pub_r001045_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001045_8_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001045_8_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001045_12_1 * 2) + 12) & 63;
  int stage_v_29_2 = ((pub_r001045_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((sec_r001045_19_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_30_2 = ((sec_r001045_19_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((stage_v_11_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_31_2 = ((stage_v_11_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((helper_flow_3_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_32_2 = ((helper_flow_3_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((helper_flow_7_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_33_2 = ((helper_flow_7_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((pub_r001045_5_1 * 2) + 43) & 63;
  int stage_v_34_2 = ((pub_r001045_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001045_9_1 * 2) + 13) & 63;
  int stage_v_35_2 = ((pub_r001045_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_15_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_15_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((sec_r001045_14_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_37_2 = ((sec_r001045_14_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((pub_r001045_0_1 * 2) + 44) & 63;
  int stage_v_38_2 = ((pub_r001045_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((stage_v_25_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_25_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((helper_flow_6_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_40_2 = ((helper_flow_6_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((sec_r001045_7_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_41_2 = ((sec_r001045_7_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((sec_r001045_12_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_42_2 = ((sec_r001045_12_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((sec_r001045_18_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_43_2 = ((sec_r001045_18_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_11_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_11_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001045_5_1 * 2) + 11) & 63;
  int stage_v_45_2 = ((pub_r001045_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_21_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_21_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001045_10_1 * 2) + 33) & 63;
  int stage_v_47_2 = ((pub_r001045_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001045_5_1 * 2) + 9) & 63;
  int stage_v_48_2 = ((pub_r001045_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001045_6_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001045_6_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((stage_v_31_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_50_2 = ((stage_v_31_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((stage_v_14_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_51_2 = ((stage_v_14_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((pub_r001045_13_1 * 2) + 8) & 63;
  int stage_v_52_2 = ((pub_r001045_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((sec_r001045_13_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001045_13_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((stage_v_14_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_14_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001045_8_1 * 2) + 13) & 63;
  int stage_v_55_2 = ((pub_r001045_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001045_6_1 * 2) + 9) & 63;
  int stage_v_56_2 = ((pub_r001045_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_51_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_51_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((stage_v_32_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_32_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((pub_r001045_1_1 * 2) + 39) & 63;
  int stage_v_59_2 = ((pub_r001045_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001045_3_1 * 2) + 7) & 63;
  int stage_v_60_2 = ((pub_r001045_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((stage_v_22_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_22_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((pub_r001045_4_1 * 2) + 40) & 63;
  int stage_v_62_2 = ((pub_r001045_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001045_6_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_63_2 = ((sec_r001045_6_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((pub_r001045_4_1 * 2) + 16) & 63;
  int stage_v_64_2 = ((pub_r001045_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001045_7_1 * 2) + 7) & 63;
  int stage_v_65_2 = ((pub_r001045_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((helper_flow_8_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_66_2 = ((helper_flow_8_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((pub_r001045_5_1 * 2) + 43) & 63;
  int stage_v_67_2 = ((pub_r001045_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001045_13_1 * 2) + 44) & 63;
  int stage_v_68_2 = ((pub_r001045_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_31_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_31_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((stage_v_30_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_30_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001045_15_1 * 2) + 19) & 63;
  int stage_v_71_2 = ((pub_r001045_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_12_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_12_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001045_10_1 * 2) + 33) & 63;
  int stage_v_73_2 = ((pub_r001045_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001045_10_1 * 2) + 42) & 63;
  int stage_v_74_2 = ((pub_r001045_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001045_2_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_75_2 = ((sec_r001045_2_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((sec_r001045_16_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_76_2 = ((sec_r001045_16_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((sec_r001045_6_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_77_2 = ((sec_r001045_6_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((stage_v_26_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_78_2 = ((stage_v_26_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((pub_r001045_9_1 * 2) + 27) & 63;
  int stage_v_79_2 = ((pub_r001045_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001045_17_1 * 2) + 16) & 63;
  int stage_v_80_2 = ((pub_r001045_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001045_7_1 * 2) + 32) & 63;
  int stage_v_81_2 = ((pub_r001045_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_22_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_22_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((pub_r001045_5_1 * 2) + 50) & 63;
  int stage_v_83_2 = ((pub_r001045_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_1_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_1_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((pub_r001045_5_1 * 2) + 44) & 63;
  int stage_v_85_2 = ((pub_r001045_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001045_12_1 * 2) + 20) & 63;
  int stage_v_86_2 = ((pub_r001045_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001045_8_1 * 2) + 13) & 63;
  int stage_v_87_2 = ((pub_r001045_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((sec_r001045_16_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_88_2 = ((sec_r001045_16_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((pub_r001045_3_1 * 2) + 44) & 63;
  int stage_v_89_2 = ((pub_r001045_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001045_15_1 * 2) + 5) & 63;
  int stage_v_90_2 = ((pub_r001045_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001045_12_1 * 2) + 21) & 63;
  int stage_v_91_2 = ((pub_r001045_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_22_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_22_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((stage_v_1_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_1_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((sec_r001045_10_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_94_2 = ((sec_r001045_10_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((pub_r001045_7_1 * 2) + 6) & 63;
  int stage_v_95_2 = ((pub_r001045_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001045_8_1 * 2) + 30) & 63;
  int stage_v_96_2 = ((pub_r001045_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001045_8_1 * 2) + 45) & 63;
  int stage_v_97_2 = ((pub_r001045_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((helper_flow_0_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_98_2 = ((helper_flow_0_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001045_6_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001045_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_46_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_46_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((stage_v_93_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_93_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((sec_r001045_13_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_102_2 = ((sec_r001045_13_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((stage_v_76_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_76_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((stage_v_72_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_72_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001045_17_1 * 2) + 25) & 63;
  int stage_v_105_2 = ((pub_r001045_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001045_5_1 * 2) + 50) & 63;
  int stage_v_106_2 = ((pub_r001045_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001045_12_1 * 2) + 14) & 63;
  int stage_v_107_2 = ((pub_r001045_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001045_12_1 * 2) + 12) & 63;
  int stage_v_108_2 = ((pub_r001045_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((sec_r001045_19_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_109_2 = ((sec_r001045_19_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((stage_v_15_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_15_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((pub_r001045_14_1 * 2) + 34) & 63;
  int stage_v_111_2 = ((pub_r001045_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001045_16_1 * 2) + 40) & 63;
  int stage_v_112_2 = ((pub_r001045_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001045_6_1 * 2) + 40) & 63;
  int stage_v_113_2 = ((pub_r001045_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001045_12_1 * 2) + 10) & 63;
  int stage_v_114_2 = ((pub_r001045_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_13_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_13_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((stage_v_40_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_40_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((sec_r001045_2_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001045_2_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((pub_r001045_7_1 * 2) + 6) & 63;
  int stage_v_118_2 = ((pub_r001045_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_72_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_119_2 = ((stage_v_72_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001045_7_1 * 2) + 16) & 63;
  int stage_v_120_2 = ((pub_r001045_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_78_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_78_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((sec_r001045_22_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_122_2 = ((sec_r001045_22_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_102_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_102_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((stage_v_6_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_6_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((stage_v_103_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_103_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((pub_r001045_3_1 * 2) + 6) & 63;
  int stage_v_126_2 = ((pub_r001045_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_75_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_75_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_53_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_53_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001045_5_1 * 2) + 43) & 63;
  int stage_v_129_2 = ((pub_r001045_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_63_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_63_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((stage_v_78_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_78_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001045_6_1 * 2) + 17) & 63;
  int stage_v_132_2 = ((pub_r001045_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001045_9_1 * 2) + 19) & 63;
  int stage_v_133_2 = ((pub_r001045_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_69_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_134_2 = ((stage_v_69_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((sec_r001045_20_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_135_2 = ((sec_r001045_20_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_13_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_13_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001045_16_1 * 2) + 35) & 63;
  int stage_v_137_2 = ((pub_r001045_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001045_17_1 * 2) + 46) & 63;
  int stage_v_138_2 = ((pub_r001045_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_125_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_125_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((stage_v_70_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_70_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((stage_v_33_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_33_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((sec_r001045_1_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_142_2 = ((sec_r001045_1_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((stage_v_28_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_143_2 = ((stage_v_28_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((stage_v_11_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_11_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((pub_r001045_4_1 * 2) + 38) & 63;
  int stage_v_145_2 = ((pub_r001045_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001045_1_1 * 2) + 13) & 63;
  int stage_v_146_2 = ((pub_r001045_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_63_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_63_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001045_12_1 * 2) + 35) & 63;
  int stage_v_148_2 = ((pub_r001045_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((stage_v_5_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_149_2 = ((stage_v_5_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((stage_v_51_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_51_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((stage_v_24_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_24_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_152_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001045_14_1 * 2) + 7) & 63;
  int stage_v_153_2 = ((pub_r001045_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001045_7_1 * 2) + 23) & 63;
  int stage_v_154_2 = ((pub_r001045_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_28_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_28_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001045_4_1 * 2) + 23) & 63;
  int stage_v_156_2 = ((pub_r001045_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_92_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_92_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_121_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_121_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((pub_r001045_11_1 * 2) + 32) & 63;
  int stage_v_159_2 = ((pub_r001045_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((stage_v_158_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_158_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((pub_r001045_11_1 * 2) + 15) & 63;
  int stage_v_161_2 = ((pub_r001045_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001045_6_1 * 2) + 46) & 63;
  int stage_v_162_2 = ((pub_r001045_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001045_13_1 * 2) + 24) & 63;
  int stage_v_163_2 = ((pub_r001045_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_41_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_41_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001045_10_1 * 2) + 48) & 63;
  int stage_v_165_2 = ((pub_r001045_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001045_7_1 * 2) + 19) & 63;
  int stage_v_166_2 = ((pub_r001045_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001045_15_1 * 2) + 48) & 63;
  int stage_v_167_2 = ((pub_r001045_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001045_10_1 * 2) + 21) & 63;
  int stage_v_168_2 = ((pub_r001045_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_22_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_22_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((pub_r001045_2_1 * 2) + 18) & 63;
  int stage_v_170_2 = ((pub_r001045_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_31_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_31_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((sec_r001045_22_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_172_2 = ((sec_r001045_22_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((pub_r001045_15_1 * 2) + 9) & 63;
  int stage_v_173_2 = ((pub_r001045_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_102_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_102_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_13_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_13_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((pub_r001045_3_1 * 2) + 26) & 63;
  int stage_v_176_2 = ((pub_r001045_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001045_15_1 * 2) + 47) & 63;
  int stage_v_177_2 = ((pub_r001045_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_164_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_164_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((pub_r001045_1_1 * 2) + 37) & 63;
  int stage_v_179_2 = ((pub_r001045_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_180_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001045_9_1 * 2) + 24) & 63;
  int stage_v_181_2 = ((pub_r001045_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001045_17_1 * 2) + 15) & 63;
  int stage_v_182_2 = ((pub_r001045_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_94_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_94_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001045_5_1 * 2) + 36) & 63;
  int stage_v_184_2 = ((pub_r001045_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((sec_r001045_22_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_185_2 = ((sec_r001045_22_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001045_10_1 * 2) + 8) & 63;
  int stage_v_186_2 = ((pub_r001045_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001045_1_1 * 2) + 24) & 63;
  int stage_v_187_2 = ((pub_r001045_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001045_1_1 * 2) + 38) & 63;
  int stage_v_188_2 = ((pub_r001045_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_20_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_189_2 = ((stage_v_20_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((pub_r001045_11_1 * 2) + 11) & 63;
  int stage_v_190_2 = ((pub_r001045_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_92_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_92_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((pub_r001045_17_1 * 2) + 44) & 63;
  int stage_v_192_2 = ((pub_r001045_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_66_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_66_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001045_17_1 * 2) + 31) & 63;
  int stage_v_194_2 = ((pub_r001045_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((sec_r001045_21_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_195_2 = ((sec_r001045_21_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((pub_r001045_2_1 * 2) + 41) & 63;
  int stage_v_196_2 = ((pub_r001045_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_98_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_98_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001045_16_1 * 2) + 48) & 63;
  int stage_v_198_2 = ((pub_r001045_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001045_0_1 * 2) + 11) & 63;
  int stage_v_199_2 = ((pub_r001045_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_109_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_109_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((stage_v_1_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_1_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_37_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_37_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001045_7_1 * 2) + 6) & 63;
  int stage_v_203_2 = ((pub_r001045_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001045_10_1 * 2) + 8) & 63;
  int stage_v_204_2 = ((pub_r001045_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_171_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_171_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((stage_v_100_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_206_2 = ((stage_v_100_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001045_15_1 * 2) + 12) & 63;
  int stage_v_207_2 = ((pub_r001045_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_88_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_88_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_202_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_202_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((pub_r001045_17_1 * 2) + 48) & 63;
  int stage_v_210_2 = ((pub_r001045_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001045_1_1 * 2) + 39) & 63;
  int stage_v_211_2 = ((pub_r001045_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_185_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_185_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((sec_r001045_21_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_213_2 = ((sec_r001045_21_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_136_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_136_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001045_17_1 * 2) + 48) & 63;
  int stage_v_215_2 = ((pub_r001045_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001045_11_1 * 2) + 46) & 63;
  int stage_v_216_2 = ((pub_r001045_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001045_10_1 * 2) + 33) & 63;
  int stage_v_217_2 = ((pub_r001045_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_57_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_57_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((stage_v_174_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_174_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001045_0_1 * 2) + 33) & 63;
  int stage_v_220_2 = ((pub_r001045_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_175_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_175_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_94_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_94_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001045_9_1 * 2) + 36) & 63;
  int stage_v_223_2 = ((pub_r001045_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_25_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_25_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((stage_v_93_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_93_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((stage_v_116_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_226_2 = ((stage_v_116_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((stage_v_143_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_143_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_84_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_84_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((stage_v_157_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_157_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((stage_v_121_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_121_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((pub_r001045_8_1 * 2) + 48) & 63;
  int stage_v_231_2 = ((pub_r001045_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001045_2_1 * 2) + 5) & 63;
  int stage_v_232_2 = ((pub_r001045_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001045_1_1 * 2) + 35) & 63;
  int stage_v_233_2 = ((pub_r001045_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_98_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_98_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_158_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_158_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_128_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_128_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001045_6_1 * 2) + 13) & 63;
  int stage_v_237_2 = ((pub_r001045_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001045_14_1 * 2) + 19) & 63;
  int stage_v_238_2 = ((pub_r001045_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((helper_flow_1_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_239_2 = ((helper_flow_1_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_131_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_131_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001045_0_1 * 2) + 32) & 63;
  int stage_v_241_2 = ((pub_r001045_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001045_2_1 * 2) + 35) & 63;
  int stage_v_242_2 = ((pub_r001045_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001045_7_1 * 2) + 19) & 63;
  int stage_v_243_2 = ((pub_r001045_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_92_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_92_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001045_1_1 * 2) + 29) & 63;
  int stage_v_245_2 = ((pub_r001045_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001045_17_1 * 2) + 46) & 63;
  int stage_v_246_2 = ((pub_r001045_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001045_6_1 * 2) + 45) & 63;
  int stage_v_247_2 = ((pub_r001045_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001045_16_1 * 2) + 37) & 63;
  int stage_v_248_2 = ((pub_r001045_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001045_9_1 * 2) + 9) & 63;
  int stage_v_249_2 = ((pub_r001045_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001045_14_1 * 2) + 28) & 63;
  int stage_v_250_2 = ((pub_r001045_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_76_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_76_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((pub_r001045_2_1 * 2) + 32) & 63;
  int stage_v_252_2 = ((pub_r001045_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((sec_r001045_16_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_253_2 = ((sec_r001045_16_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001045_8_1 * 2) + 10) & 63;
  int stage_v_254_2 = ((pub_r001045_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001045_4_1 * 2) + 45) & 63;
  int stage_v_255_2 = ((pub_r001045_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_20_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_20_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_164_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_164_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_189_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_189_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((pub_r001045_10_1 * 2) + 18) & 63;
  int stage_v_259_2 = ((pub_r001045_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((stage_v_20_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_20_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((stage_v_150_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_150_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((stage_v_201_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_201_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((stage_v_13_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_13_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001045_7_1 * 2) + 12) & 63;
  int stage_v_264_2 = ((pub_r001045_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((stage_v_134_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_134_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_144_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_144_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((pub_r001045_0_1 * 2) + 18) & 63;
  int stage_v_267_2 = ((pub_r001045_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001045_14_1 * 2) + 6) & 63;
  int stage_v_268_2 = ((pub_r001045_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001045_3_1 * 2) + 20) & 63;
  int stage_v_269_2 = ((pub_r001045_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((stage_v_84_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_84_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001045_8_1 * 2) + 18) & 63;
  int stage_v_271_2 = ((pub_r001045_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_75_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_75_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_235_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_235_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001045_6_1 * 2) + 44) & 63;
  int stage_v_274_2 = ((pub_r001045_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001045_17_1 * 2) + 14) & 63;
  int stage_v_275_2 = ((pub_r001045_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((stage_v_265_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_265_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_141_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_141_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001045_13_1 * 2) + 14) & 63;
  int stage_v_278_2 = ((pub_r001045_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((stage_v_178_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_178_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((stage_v_158_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_158_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001045_8_1 * 2) + 13) & 63;
  int stage_v_281_2 = ((pub_r001045_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_261_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_261_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((sec_r001045_19_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_283_2 = ((sec_r001045_19_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_76_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_76_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001045_0_1 * 2) + 41) & 63;
  int stage_v_285_2 = ((pub_r001045_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_100_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_100_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((stage_v_41_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_41_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001045_5_1 * 2) + 20) & 63;
  int stage_v_288_2 = ((pub_r001045_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_134_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_134_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((stage_v_229_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_229_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((stage_v_150_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_150_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((stage_v_3_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_3_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((pub_r001045_13_1 * 2) + 27) & 63;
  int stage_v_293_2 = ((pub_r001045_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001045_9_1 * 2) + 12) & 63;
  int stage_v_294_2 = ((pub_r001045_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((stage_v_258_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_258_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((sec_r001045_3_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_296_2 = ((sec_r001045_3_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((pub_r001045_10_1 * 2) + 31) & 63;
  int stage_v_297_2 = ((pub_r001045_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((stage_v_272_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_272_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_93_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_93_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((pub_r001045_6_1 * 2) + 39) & 63;
  int stage_v_300_2 = ((pub_r001045_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001045_0_1 * 2) + 42) & 63;
  int stage_v_301_2 = ((pub_r001045_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001045_16_1 * 2) + 48) & 63;
  int stage_v_302_2 = ((pub_r001045_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((stage_v_280_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_280_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((stage_v_66_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_66_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((pub_r001045_4_1 * 2) + 37) & 63;
  int stage_v_305_2 = ((pub_r001045_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_175_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_175_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001045_4_1 * 2) + 35) & 63;
  int stage_v_307_2 = ((pub_r001045_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001045_13_1 * 2) + 50) & 63;
  int stage_v_308_2 = ((pub_r001045_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((stage_v_13_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_13_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_282_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_282_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((stage_v_240_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_240_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_103_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_103_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((pub_r001045_7_1 * 2) + 40) & 63;
  int stage_v_313_2 = ((pub_r001045_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001045_15_1 * 2) + 31) & 63;
  int stage_v_314_2 = ((pub_r001045_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((stage_v_7_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_7_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((pub_r001045_1_1 * 2) + 46) & 63;
  int stage_v_316_2 = ((pub_r001045_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((stage_v_21_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_21_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_239_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_239_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_104_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_104_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((pub_r001045_11_1 * 2) + 34) & 63;
  int stage_v_320_2 = ((pub_r001045_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((stage_v_26_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_26_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((pub_r001045_4_1 * 2) + 24) & 63;
  int stage_v_322_2 = ((pub_r001045_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001045_5_1 * 2) + 44) & 63;
  int stage_v_323_2 = ((pub_r001045_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((stage_v_225_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_225_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((pub_r001045_1_1 * 2) + 20) & 63;
  int stage_v_325_2 = ((pub_r001045_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((stage_v_6_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_6_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((helper_flow_2_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_327_2 = ((helper_flow_2_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((pub_r001045_16_1 * 2) + 15) & 63;
  int stage_v_328_2 = ((pub_r001045_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((stage_v_265_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_265_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((stage_v_324_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_324_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_32_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_32_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((sec_r001045_17_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_332_2 = ((sec_r001045_17_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((stage_v_287_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_287_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((stage_v_287_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_287_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((pub_r001045_10_1 * 2) + 19) & 63;
  int stage_v_335_2 = ((pub_r001045_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((stage_v_115_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_115_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001045_10_1 * 2) + 8) & 63;
  int stage_v_337_2 = ((pub_r001045_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_236_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_236_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((sec_r001045_14_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_339_2 = ((sec_r001045_14_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((pub_r001045_5_1 * 2) + 11) & 63;
  int stage_v_340_2 = ((pub_r001045_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001045_9_1 * 2) + 29) & 63;
  int stage_v_341_2 = ((pub_r001045_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_332_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_332_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((stage_v_44_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_44_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001045_1_1 * 2) + 24) & 63;
  int stage_v_344_2 = ((pub_r001045_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((stage_v_283_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_283_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((helper_flow_8_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_346_2 = ((helper_flow_8_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001045_2_1 * 2) + 45) & 63;
  int stage_v_347_2 = ((pub_r001045_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((sec_r001045_12_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_348_2 = ((sec_r001045_12_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((pub_r001045_3_1 * 2) + 46) & 63;
  int stage_v_349_2 = ((pub_r001045_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_311_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_311_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001045_11_1 * 2) + 22) & 63;
  int stage_v_351_2 = ((pub_r001045_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001045_13_1 * 2) + 40) & 63;
  int stage_v_352_2 = ((pub_r001045_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001045_2_1 * 2) + 19) & 63;
  int stage_v_353_2 = ((pub_r001045_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001045_14_1 * 2) + 48) & 63;
  int stage_v_354_2 = ((pub_r001045_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001045_17_1 * 2) + 28) & 63;
  int stage_v_355_2 = ((pub_r001045_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((sec_r001045_12_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_356_2 = ((sec_r001045_12_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((stage_v_144_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_144_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((stage_v_127_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_127_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((stage_v_345_1 << 1) ^ (pub_r001045_8_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_345_2 << 1) ^ (pub_r001045_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((stage_v_263_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_263_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001045_6_1 * 2) + 34) & 63;
  int stage_v_361_2 = ((pub_r001045_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_49_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_49_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((sec_r001045_4_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_363_2 = ((sec_r001045_4_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((pub_r001045_8_1 * 2) + 47) & 63;
  int stage_v_364_2 = ((pub_r001045_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001045_15_1 * 2) + 6) & 63;
  int stage_v_365_2 = ((pub_r001045_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((stage_v_20_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_20_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((sec_r001045_0_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_367_2 = ((sec_r001045_0_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((sec_r001045_8_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_368_2 = ((sec_r001045_8_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001045_9_1 * 2) + 46) & 63;
  int stage_v_369_2 = ((pub_r001045_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_142_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_142_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001045_11_1 * 2) + 17) & 63;
  int stage_v_371_2 = ((pub_r001045_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((sec_r001045_22_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_372_2 = ((sec_r001045_22_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((stage_v_103_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_103_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_122_1 << 1) ^ (pub_r001045_5_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_122_2 << 1) ^ (pub_r001045_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001045_7_1 * 2) + 34) & 63;
  int stage_v_375_2 = ((pub_r001045_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001045_13_1 * 2) + 23) & 63;
  int stage_v_376_2 = ((pub_r001045_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001045_16_1 * 2) + 34) & 63;
  int stage_v_377_2 = ((pub_r001045_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_214_1 << 1) ^ (pub_r001045_4_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_214_2 << 1) ^ (pub_r001045_4_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_78_1 << 1) ^ (pub_r001045_3_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_78_2 << 1) ^ (pub_r001045_3_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((helper_flow_4_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_380_2 = ((helper_flow_4_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((pub_r001045_9_1 * 2) + 19) & 63;
  int stage_v_381_2 = ((pub_r001045_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((stage_v_92_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_92_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((stage_v_36_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_36_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((pub_r001045_15_1 * 2) + 12) & 63;
  int stage_v_384_2 = ((pub_r001045_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((stage_v_280_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_280_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((pub_r001045_8_1 * 2) + 30) & 63;
  int stage_v_386_2 = ((pub_r001045_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((stage_v_94_1 << 1) ^ (pub_r001045_1_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_94_2 << 1) ^ (pub_r001045_1_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001045_14_1 * 2) + 27) & 63;
  int stage_v_388_2 = ((pub_r001045_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_202_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_202_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001045_5_1 * 2) + 34) & 63;
  int stage_v_390_2 = ((pub_r001045_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_70_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_70_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_298_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_298_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((stage_v_228_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_228_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((stage_v_357_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_357_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001045_1_1 * 2) + 38) & 63;
  int stage_v_395_2 = ((pub_r001045_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001045_0_1 * 2) + 41) & 63;
  int stage_v_396_2 = ((pub_r001045_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001045_6_1 * 2) + 28) & 63;
  int stage_v_397_2 = ((pub_r001045_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001045_17_1 * 2) + 28) & 63;
  int stage_v_398_2 = ((pub_r001045_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001045_13_1 * 2) + 42) & 63;
  int stage_v_399_2 = ((pub_r001045_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001045_3_1 * 2) + 30) & 63;
  int stage_v_400_2 = ((pub_r001045_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_379_1 << 1) ^ (pub_r001045_11_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_379_2 << 1) ^ (pub_r001045_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_205_1 << 1) ^ (pub_r001045_17_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_205_2 << 1) ^ (pub_r001045_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((pub_r001045_15_1 * 2) + 31) & 63;
  int stage_v_403_2 = ((pub_r001045_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001045_12_1 * 2) + 27) & 63;
  int stage_v_404_2 = ((pub_r001045_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001045_16_1 * 2) + 11) & 63;
  int stage_v_405_2 = ((pub_r001045_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001045_1_1 * 2) + 27) & 63;
  int stage_v_406_2 = ((pub_r001045_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((stage_v_143_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_143_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_125_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_125_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((stage_v_57_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_57_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((stage_v_282_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_282_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((stage_v_78_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_411_2 = ((stage_v_78_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_411_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_411_2 + 1) & 15;
  out_sink_1 ^= stage_v_411_1 & 63;
  out_sink_2 ^= stage_v_411_2 & 63;
  int stage_v_412_1 = ((pub_r001045_7_1 * 2) + 39) & 63;
  int stage_v_412_2 = ((pub_r001045_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((stage_v_39_1 << 1) ^ (pub_r001045_2_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_39_2 << 1) ^ (pub_r001045_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((sec_r001045_9_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_414_2 = ((sec_r001045_9_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((pub_r001045_15_1 * 2) + 16) & 63;
  int stage_v_415_2 = ((pub_r001045_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001045_0_1 * 2) + 22) & 63;
  int stage_v_416_2 = ((pub_r001045_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((sec_r001045_15_1 << 1) ^ (pub_r001045_15_1 >> 1)) & 127;
  int stage_v_417_2 = ((sec_r001045_15_2 << 1) ^ (pub_r001045_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_417_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_417_2 + 1) & 15;
  out_sink_1 ^= stage_v_417_1 & 63;
  out_sink_2 ^= stage_v_417_2 & 63;
  int stage_v_418_1 = ((stage_v_101_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_101_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((stage_v_15_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_15_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_41_1 << 1) ^ (pub_r001045_6_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_41_2 << 1) ^ (pub_r001045_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_374_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_374_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((pub_r001045_6_1 * 2) + 30) & 63;
  int stage_v_422_2 = ((pub_r001045_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((stage_v_127_1 << 1) ^ (pub_r001045_10_1 >> 1)) & 127;
  int stage_v_423_2 = ((stage_v_127_2 << 1) ^ (pub_r001045_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((stage_v_379_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_424_2 = ((stage_v_379_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_424_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_424_2 + 1) & 15;
  out_sink_1 ^= stage_v_424_1 & 63;
  out_sink_2 ^= stage_v_424_2 & 63;
  int stage_v_425_1 = ((pub_r001045_12_1 * 2) + 38) & 63;
  int stage_v_425_2 = ((pub_r001045_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((stage_v_104_1 << 1) ^ (pub_r001045_9_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_104_2 << 1) ^ (pub_r001045_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((stage_v_82_1 << 1) ^ (pub_r001045_14_1 >> 1)) & 127;
  int stage_v_427_2 = ((stage_v_82_2 << 1) ^ (pub_r001045_14_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((pub_r001045_15_1 * 2) + 14) & 63;
  int stage_v_428_2 = ((pub_r001045_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001045_16_1 * 2) + 49) & 63;
  int stage_v_429_2 = ((pub_r001045_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((helper_flow_3_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_430_2 = ((helper_flow_3_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((stage_v_144_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_431_2 = ((stage_v_144_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((pub_r001045_13_1 * 2) + 48) & 63;
  int stage_v_432_2 = ((pub_r001045_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((stage_v_359_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_433_2 = ((stage_v_359_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_433_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_433_2 + 1) & 15;
  out_sink_1 ^= stage_v_433_1 & 63;
  out_sink_2 ^= stage_v_433_2 & 63;
  int stage_v_434_1 = ((pub_r001045_16_1 * 2) + 49) & 63;
  int stage_v_434_2 = ((pub_r001045_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001045_11_1 * 2) + 49) & 63;
  int stage_v_435_2 = ((pub_r001045_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((stage_v_282_1 << 1) ^ (pub_r001045_0_1 >> 1)) & 127;
  int stage_v_436_2 = ((stage_v_282_2 << 1) ^ (pub_r001045_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_436_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_436_2 + 1) & 15;
  out_sink_1 ^= stage_v_436_1 & 63;
  out_sink_2 ^= stage_v_436_2 & 63;
  int stage_v_437_1 = ((stage_v_291_1 << 1) ^ (pub_r001045_7_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_291_2 << 1) ^ (pub_r001045_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((stage_v_401_1 << 1) ^ (pub_r001045_13_1 >> 1)) & 127;
  int stage_v_438_2 = ((stage_v_401_2 << 1) ^ (pub_r001045_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_438_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_438_2 + 1) & 15;
  out_sink_1 ^= stage_v_438_1 & 63;
  out_sink_2 ^= stage_v_438_2 & 63;
  int stage_v_439_1 = ((stage_v_178_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_439_2 = ((stage_v_178_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((pub_r001045_17_1 * 2) + 38) & 63;
  int stage_v_440_2 = ((pub_r001045_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((stage_v_292_1 << 1) ^ (pub_r001045_16_1 >> 1)) & 127;
  int stage_v_441_2 = ((stage_v_292_2 << 1) ^ (pub_r001045_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_441_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_441_2 + 1) & 15;
  out_sink_1 ^= stage_v_441_1 & 63;
  out_sink_2 ^= stage_v_441_2 & 63;
  int stage_v_442_1 = ((pub_r001045_6_1 * 2) + 47) & 63;
  int stage_v_442_2 = ((pub_r001045_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((sec_r001045_18_1 << 1) ^ (pub_r001045_12_1 >> 1)) & 127;
  int stage_v_443_2 = ((sec_r001045_18_2 << 1) ^ (pub_r001045_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_443_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_443_2 + 1) & 15;
  out_sink_1 ^= stage_v_443_1 & 63;
  out_sink_2 ^= stage_v_443_2 & 63;
  int stage_v_444_1 = ((pub_r001045_0_1 * 2) + 32) & 63;
  int stage_v_444_2 = ((pub_r001045_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001045_10_1 != sec_r001045_10_2);
  __CPROVER_assume(sec_r001045_16_1 != sec_r001045_16_2);
  __CPROVER_assume(pub_r001045_7_1 == pub_r001045_7_2);
  __CPROVER_assume(pub_r001045_17_1 == pub_r001045_17_2);
  __CPROVER_assume(sec_r001045_6_1 != sec_r001045_6_2);
  __CPROVER_assume(pub_r001045_14_1 == pub_r001045_14_2);
  __CPROVER_assume(pub_r001045_13_1 == pub_r001045_13_2);
  __CPROVER_assume(pub_r001045_15_1 == pub_r001045_15_2);
  __CPROVER_assume(sec_r001045_5_1 != sec_r001045_5_2);
  __CPROVER_assume(pub_r001045_12_1 == pub_r001045_12_2);
  __CPROVER_assume(sec_r001045_3_1 != sec_r001045_3_2);
  __CPROVER_assume(sec_r001045_20_1 != sec_r001045_20_2);
  __CPROVER_assume(sec_r001045_19_1 != sec_r001045_19_2);
  __CPROVER_assume(pub_r001045_4_1 == pub_r001045_4_2);
  __CPROVER_assume(sec_r001045_21_1 != sec_r001045_21_2);
  __CPROVER_assume(sec_r001045_14_1 != sec_r001045_14_2);
  __CPROVER_assume(sec_r001045_4_1 != sec_r001045_4_2);
  __CPROVER_assume(pub_r001045_10_1 == pub_r001045_10_2);
  __CPROVER_assume(sec_r001045_2_1 != sec_r001045_2_2);
  __CPROVER_assume(sec_r001045_23_1 != sec_r001045_23_2);
  __CPROVER_assume(sec_r001045_18_1 != sec_r001045_18_2);
  __CPROVER_assume(pub_r001045_1_1 == pub_r001045_1_2);
  __CPROVER_assume(pub_r001045_8_1 == pub_r001045_8_2);
  __CPROVER_assume(sec_r001045_8_1 != sec_r001045_8_2);
  __CPROVER_assume(sec_r001045_17_1 != sec_r001045_17_2);
  __CPROVER_assume(pub_r001045_6_1 == pub_r001045_6_2);
  __CPROVER_assume(pub_r001045_11_1 == pub_r001045_11_2);
  __CPROVER_assume(sec_r001045_0_1 != sec_r001045_0_2);
  __CPROVER_assume(pub_r001045_5_1 == pub_r001045_5_2);
  __CPROVER_assume(sec_r001045_15_1 != sec_r001045_15_2);
  __CPROVER_assume(pub_r001045_9_1 == pub_r001045_9_2);
  __CPROVER_assume(sec_r001045_22_1 != sec_r001045_22_2);
  __CPROVER_assume(pub_r001045_0_1 == pub_r001045_0_2);
  __CPROVER_assume(sec_r001045_7_1 != sec_r001045_7_2);
  __CPROVER_assume(sec_r001045_12_1 != sec_r001045_12_2);
  __CPROVER_assume(pub_r001045_2_1 == pub_r001045_2_2);
  __CPROVER_assume(pub_r001045_16_1 == pub_r001045_16_2);
  __CPROVER_assume(sec_r001045_9_1 != sec_r001045_9_2);
  __CPROVER_assume(pub_r001045_3_1 == pub_r001045_3_2);
  __CPROVER_assume(sec_r001045_11_1 != sec_r001045_11_2);
  __CPROVER_assume(sec_r001045_1_1 != sec_r001045_1_2);
  __CPROVER_assume(sec_r001045_13_1 != sec_r001045_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.code == st_var_0_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.counter == st_var_3_2.counter);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.iv == st_var_3_2.iv);
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
}


