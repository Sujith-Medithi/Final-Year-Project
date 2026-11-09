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
struct AudioFrame_R001836_3613_0
{
  short sample_rate;
  int gain;
  unsigned char envelope;
  int rms;
  int buffer[3];
};
struct StreamBuffer_R001836_3613_1
{
  int state;
  int head;
  int checksum;
  int buffer[3];
};
struct SensorNode_R001836_3613_2
{
  int status;
  int threshold;
  int gain;
  int offset;
  int calib;
  int buffer[3];
};
union PacketPayload_R001836_3613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001836_3613_1
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
void fn_R001836_3613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_97_1 > 43)
  {
    acc_1 = ((acc_1 + (bound_97_1 * 2)) + 5) & 127;
    aux_1 ^= bound_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_97_2 > 43)
  {
    acc_2 = ((acc_2 + (bound_97_2 * 2)) + 5) & 127;
    aux_2 ^= bound_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_86_1)
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

  switch (cursor_86_2)
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
  int quantum_49_1 = local_arr_1[aux_1 % 3];
  int quantum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_49_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_97_1 == bound_97_2);
  assert(cursor_86_1 == cursor_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_49_1 == quantum_49_2);
}

int fn_R001836_3613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_97 > 43)
  {
    acc = ((acc + (bound_97 * 2)) + 5) & 127;
    aux ^= bound_97 & 15;
  }
  else
  {
    acc = ((acc - bound_97) + 11) & 127;
    aux += 3;
  }
  int cursor_86 = (aux + st.buffer[1]) & 3;
  switch (cursor_86)
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
  int quantum_49 = local_arr[aux % 3];
  acc = (acc + (quantum_49 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001836_3613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_53_1 = 0;
  int parity_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_53_1 = ((parity_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_53_2 = ((parity_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_53_1) & 127;
    acc_2 = (acc_2 + parity_53_2) & 127;
  }

  int stride_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_36_1 > 34)
  {
    acc_1 = ((acc_1 + (stride_36_1 * 2)) + 5) & 127;
    aux_1 ^= stride_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_36_2 > 34)
  {
    acc_2 = ((acc_2 + (stride_36_2 * 2)) + 5) & 127;
    aux_2 ^= stride_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_79_1) & 63;
  aux_2 = (aux_2 + window_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_53_1 == parity_53_2);
  assert(stride_36_1 == stride_36_2);
  assert(window_79_1 == window_79_2);
}

int fn_R001836_3613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_53 = ((parity_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_53) & 127;
  }

  int stride_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_36 > 34)
  {
    acc = ((acc + (stride_36 * 2)) + 5) & 127;
    aux ^= stride_36 & 15;
  }
  else
  {
    acc = ((acc - stride_36) + 11) & 127;
    aux += 3;
  }
  int window_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_43_1 = local_arr_1[aux_1 % 3];
  int factor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_43_2 * 2)) & 127;
  int stride_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_73_1) & 63;
  aux_2 = (aux_2 + stride_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_22_1 = 0;
  int factor_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_22_1 = ((factor_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_22_2 = ((factor_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_22_1) & 127;
    acc_2 = (acc_2 + factor_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_43_1 == factor_43_2);
  assert(stride_73_1 == stride_73_2);
  assert(factor_22_1 == factor_22_2);
}

int fn_R001836_3613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int factor_43 = local_arr[aux % 3];
  acc = (acc + (factor_43 * 2)) & 127;
  int stride_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_73) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_22 = ((factor_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001836_3613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st_1 = {0};
  struct AudioFrame_R001836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_33_1 = local_arr_1[aux_1 % 3];
  int tally_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_59_1)
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

  switch (quantum_59_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_33_1 == tally_33_2);
  assert(quantum_59_1 == quantum_59_2);
}

int fn_R001836_3613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int tally_33 = local_arr[aux % 3];
  acc = (acc + (tally_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_59 = (aux + st.buffer[1]) & 3;
  switch (quantum_59)
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

void fn_R001836_3613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_81_1)
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

  switch (tracker_81_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_81_1 == tracker_81_2);
}

int fn_R001836_3613_4(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_81 = (aux + st.buffer[1]) & 3;
  switch (tracker_81)
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

void fn_R001836_3613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st_1 = {0};
  struct AudioFrame_R001836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_23_1 = local_arr_1[aux_1 % 3];
  int weight_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_23_2 * 2)) & 127;
  int offset_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_16_1)
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

  switch (offset_16_2)
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

  int window_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_37_1) & 63;
  aux_2 = (aux_2 + window_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_23_1 == weight_23_2);
  assert(offset_16_1 == offset_16_2);
  assert(window_37_1 == window_37_2);
}

int fn_R001836_3613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int weight_23 = local_arr[aux % 3];
  acc = (acc + (weight_23 * 2)) & 127;
  int offset_16 = (aux + st.buffer[1]) & 3;
  switch (offset_16)
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

  int window_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_67_1 = local_arr_1[aux_1 % 3];
  int phase_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_67_2 * 2)) & 127;
  int threshold_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_76_1 > 19)
  {
    acc_1 = ((acc_1 + (threshold_76_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_76_2 > 19)
  {
    acc_2 = ((acc_2 + (threshold_76_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_67_1 == phase_67_2);
  assert(threshold_76_1 == threshold_76_2);
}

int fn_R001836_3613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_67 = local_arr[aux % 3];
  acc = (acc + (phase_67 * 2)) & 127;
  int threshold_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_76 > 19)
  {
    acc = ((acc + (threshold_76 * 2)) + 5) & 127;
    aux ^= threshold_76 & 15;
  }
  else
  {
    acc = ((acc - threshold_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001836_3613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_24_1 = local_arr_1[aux_1 % 3];
  int anchor_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_24_2 * 2)) & 127;
  int pivot_45_1 = 0;
  int pivot_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_45_1 = ((pivot_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_45_2 = ((pivot_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_45_1) & 127;
    acc_2 = (acc_2 + pivot_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_24_1 == anchor_24_2);
  assert(pivot_45_1 == pivot_45_2);
}

int fn_R001836_3613_7(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_24 = local_arr[aux % 3];
  acc = (acc + (anchor_24 * 2)) & 127;
  int pivot_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_45 = ((pivot_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_45) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001836_3613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_11_1)
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

  switch (weight_11_2)
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

  int tally_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_62_1 > 48)
  {
    acc_1 = ((acc_1 + (tally_62_1 * 2)) + 5) & 127;
    aux_1 ^= tally_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_62_2 > 48)
  {
    acc_2 = ((acc_2 + (tally_62_2 * 2)) + 5) & 127;
    aux_2 ^= tally_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_94_1 = 0;
  int sample_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_94_1 = ((sample_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_94_2 = ((sample_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_94_1) & 127;
    acc_2 = (acc_2 + sample_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_11_1 == weight_11_2);
  assert(tally_62_1 == tally_62_2);
  assert(sample_94_1 == sample_94_2);
}

int fn_R001836_3613_8(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_11 = (aux + st.buffer[1]) & 3;
  switch (weight_11)
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

  int tally_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_62 > 48)
  {
    acc = ((acc + (tally_62 * 2)) + 5) & 127;
    aux ^= tally_62 & 15;
  }
  else
  {
    acc = ((acc - tally_62) + 11) & 127;
    aux += 3;
  }
  int sample_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_94 = ((sample_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001836_3613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st_1 = {0};
  struct AudioFrame_R001836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_73_1 = 0;
  int residue_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_73_1 = ((residue_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_73_2 = ((residue_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_73_1) & 127;
    acc_2 = (acc_2 + residue_73_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_10_1 = local_arr_1[aux_1 % 3];
  int mask_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_10_2 * 2)) & 127;
  int anchor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_97_1 > 25)
  {
    acc_1 = ((acc_1 + (anchor_97_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_97_2 > 25)
  {
    acc_2 = ((acc_2 + (anchor_97_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_38_1)
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

  switch (phase_38_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_73_1 == residue_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_10_1 == mask_10_2);
  assert(anchor_97_1 == anchor_97_2);
  assert(phase_38_1 == phase_38_2);
}

int fn_R001836_3613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_73 = ((residue_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_73) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_10 = local_arr[aux % 3];
  acc = (acc + (mask_10 * 2)) & 127;
  int anchor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_97 > 25)
  {
    acc = ((acc + (anchor_97 * 2)) + 5) & 127;
    aux ^= anchor_97 & 15;
  }
  else
  {
    acc = ((acc - anchor_97) + 11) & 127;
    aux += 3;
  }
  int phase_38 = (aux + st.buffer[1]) & 3;
  switch (phase_38)
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

void fn_R001836_3613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_12_1 = local_arr_1[aux_1 % 3];
  int checksum_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_12_2 * 2)) & 127;
  int scale_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_20_1)
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

  switch (scale_20_2)
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

  int vector_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_46_1) & 63;
  aux_2 = (aux_2 + vector_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_12_1 == checksum_12_2);
  assert(scale_20_1 == scale_20_2);
  assert(vector_46_1 == vector_46_2);
}

int fn_R001836_3613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int checksum_12 = local_arr[aux % 3];
  acc = (acc + (checksum_12 * 2)) & 127;
  int scale_20 = (aux + st.buffer[1]) & 3;
  switch (scale_20)
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

  int vector_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_27_1 = local_arr_1[aux_1 % 3];
  int checksum_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_27_2 * 2)) & 127;
  int damping_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_36_1)
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

  switch (damping_36_2)
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

  int segment_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_12_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_12_1 * 2)) + 5) & 127;
    aux_1 ^= segment_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_12_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_12_2 * 2)) + 5) & 127;
    aux_2 ^= segment_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_27_1) & 63;
  aux_2 = (aux_2 + phase_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_27_1 == checksum_27_2);
  assert(damping_36_1 == damping_36_2);
  assert(segment_12_1 == segment_12_2);
  assert(phase_27_1 == phase_27_2);
}

int fn_R001836_3613_11(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int checksum_27 = local_arr[aux % 3];
  acc = (acc + (checksum_27 * 2)) & 127;
  int damping_36 = (aux + st.buffer[1]) & 3;
  switch (damping_36)
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

  int segment_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_12 > 24)
  {
    acc = ((acc + (segment_12 * 2)) + 5) & 127;
    aux ^= segment_12 & 15;
  }
  else
  {
    acc = ((acc - segment_12) + 11) & 127;
    aux += 3;
  }
  int phase_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_54_1 = 0;
  int segment_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_54_1 = ((segment_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_54_2 = ((segment_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_54_1) & 127;
    acc_2 = (acc_2 + segment_54_2) & 127;
  }

  int stride_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_48_1) & 63;
  aux_2 = (aux_2 + stride_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_60_1)
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

  switch (weight_60_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_54_1 == segment_54_2);
  assert(stride_48_1 == stride_48_2);
  assert(weight_60_1 == weight_60_2);
}

int fn_R001836_3613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_54 = ((segment_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_54) & 127;
  }

  int stride_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_48) & 63;
  acc ^= aux;
  int weight_60 = (aux + st.buffer[1]) & 3;
  switch (weight_60)
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

void fn_R001836_3613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_41_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_41_1 * 2)) + 5) & 127;
    aux_1 ^= mask_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_41_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_41_2 * 2)) + 5) & 127;
    aux_2 ^= mask_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_66_1) & 63;
  aux_2 = (aux_2 + pivot_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_41_1 == mask_41_2);
  assert(pivot_66_1 == pivot_66_2);
}

int fn_R001836_3613_13(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_41 > 47)
  {
    acc = ((acc + (mask_41 * 2)) + 5) & 127;
    aux ^= mask_41 & 15;
  }
  else
  {
    acc = ((acc - mask_41) + 11) & 127;
    aux += 3;
  }
  int pivot_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int margin_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_31_1)
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

  switch (margin_31_2)
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
  int pivot_45_1 = local_arr_1[aux_1 % 3];
  int pivot_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_31_1 == margin_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_45_1 == pivot_45_2);
}

int fn_R001836_3613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int margin_31 = (aux + st.buffer[1]) & 3;
  switch (margin_31)
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
  int pivot_45 = local_arr[aux % 3];
  acc = (acc + (pivot_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001836_3613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st_1 = {0};
  struct AudioFrame_R001836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_26_1 = local_arr_1[aux_1 % 3];
  int offset_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_26_2 * 2)) & 127;
  int factor_75_1 = 0;
  int factor_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_75_1 = ((factor_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_75_2 = ((factor_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_75_1) & 127;
    acc_2 = (acc_2 + factor_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_26_1 == offset_26_2);
  assert(factor_75_1 == factor_75_2);
}

int fn_R001836_3613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_26 = local_arr[aux % 3];
  acc = (acc + (offset_26 * 2)) & 127;
  int factor_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_75 = ((factor_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001836_3613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_39_1 > 21)
  {
    acc_1 = ((acc_1 + (sample_39_1 * 2)) + 5) & 127;
    aux_1 ^= sample_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_39_2 > 21)
  {
    acc_2 = ((acc_2 + (sample_39_2 * 2)) + 5) & 127;
    aux_2 ^= sample_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_32_1 = local_arr_1[aux_1 % 3];
  int parity_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_32_2 * 2)) & 127;
  int quantum_51_1 = 0;
  int quantum_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_51_1 = ((quantum_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_51_2 = ((quantum_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_51_1) & 127;
    acc_2 = (acc_2 + quantum_51_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_39_1 == sample_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_32_1 == parity_32_2);
  assert(quantum_51_1 == quantum_51_2);
}

int fn_R001836_3613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_39 > 21)
  {
    acc = ((acc + (sample_39 * 2)) + 5) & 127;
    aux ^= sample_39 & 15;
  }
  else
  {
    acc = ((acc - sample_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_32 = local_arr[aux % 3];
  acc = (acc + (parity_32 * 2)) & 127;
  int quantum_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_51 = ((quantum_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_51) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001836_3613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st_1 = {0};
  struct AudioFrame_R001836_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_42_1 = 0;
  int tally_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_42_1 = ((tally_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_42_2 = ((tally_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_42_1) & 127;
    acc_2 = (acc_2 + tally_42_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_41_1 = local_arr_1[aux_1 % 3];
  int pivot_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_41_2 * 2)) & 127;
  int sample_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_79_1 > 19)
  {
    acc_1 = ((acc_1 + (sample_79_1 * 2)) + 5) & 127;
    aux_1 ^= sample_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_79_2 > 19)
  {
    acc_2 = ((acc_2 + (sample_79_2 * 2)) + 5) & 127;
    aux_2 ^= sample_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_42_1 == tally_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_41_1 == pivot_41_2);
  assert(sample_79_1 == sample_79_2);
}

int fn_R001836_3613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001836_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_42 = ((tally_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_42) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_41 = local_arr[aux % 3];
  acc = (acc + (pivot_41 * 2)) & 127;
  int sample_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_79 > 19)
  {
    acc = ((acc + (sample_79 * 2)) + 5) & 127;
    aux ^= sample_79 & 15;
  }
  else
  {
    acc = ((acc - sample_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001836_3613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_94_1 = local_arr_1[aux_1 % 3];
  int phase_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_94_2 * 2)) & 127;
  int sample_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_23_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_23_1 * 2)) + 5) & 127;
    aux_1 ^= sample_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_23_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_23_2 * 2)) + 5) & 127;
    aux_2 ^= sample_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_82_1) & 63;
  aux_2 = (aux_2 + stride_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_94_1 == phase_94_2);
  assert(sample_23_1 == sample_23_2);
  assert(stride_82_1 == stride_82_2);
}

int fn_R001836_3613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_94 = local_arr[aux % 3];
  acc = (acc + (phase_94 * 2)) & 127;
  int sample_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_23 > 23)
  {
    acc = ((acc + (sample_23 * 2)) + 5) & 127;
    aux ^= sample_23 & 15;
  }
  else
  {
    acc = ((acc - sample_23) + 11) & 127;
    aux += 3;
  }
  int stride_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_80_1)
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

  switch (phase_80_2)
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

  int phase_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_44_1) & 63;
  aux_2 = (aux_2 + phase_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_80_1 == phase_80_2);
  assert(phase_44_1 == phase_44_2);
}

int fn_R001836_3613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_80 = (aux + st.buffer[1]) & 3;
  switch (phase_80)
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

  int phase_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001836_3613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int segment_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_75_1 > 33)
  {
    acc_1 = ((acc_1 + (segment_75_1 * 2)) + 5) & 127;
    aux_1 ^= segment_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_75_2 > 33)
  {
    acc_2 = ((acc_2 + (segment_75_2 * 2)) + 5) & 127;
    aux_2 ^= segment_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_39_1 = 0;
  int vector_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_39_1 = ((vector_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_39_2 = ((vector_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_39_1) & 127;
    acc_2 = (acc_2 + vector_39_2) & 127;
  }

  int offset_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_68_1) & 63;
  aux_2 = (aux_2 + offset_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_86_1)
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

  switch (pivot_86_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_75_1 == segment_75_2);
  assert(vector_39_1 == vector_39_2);
  assert(offset_68_1 == offset_68_2);
  assert(pivot_86_1 == pivot_86_2);
}

int fn_R001836_3613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int segment_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_75 > 33)
  {
    acc = ((acc + (segment_75 * 2)) + 5) & 127;
    aux ^= segment_75 & 15;
  }
  else
  {
    acc = ((acc - segment_75) + 11) & 127;
    aux += 3;
  }
  int vector_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_39 = ((vector_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_39) & 127;
  }

  int offset_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_68) & 63;
  acc ^= aux;
  int pivot_86 = (aux + st.buffer[1]) & 3;
  switch (pivot_86)
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

void fn_R001836_3613_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_38_1 > 38)
  {
    acc_1 = ((acc_1 + (parity_38_1 * 2)) + 5) & 127;
    aux_1 ^= parity_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_38_2 > 38)
  {
    acc_2 = ((acc_2 + (parity_38_2 * 2)) + 5) & 127;
    aux_2 ^= parity_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_38_1 == parity_38_2);
}

int fn_R001836_3613_21(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_38 > 38)
  {
    acc = ((acc + (parity_38 * 2)) + 5) & 127;
    aux ^= parity_38 & 15;
  }
  else
  {
    acc = ((acc - parity_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001836_3613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int mask_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_15_1) & 63;
  aux_2 = (aux_2 + mask_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_90_1)
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

  switch (segment_90_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_15_1 == mask_15_2);
  assert(segment_90_1 == segment_90_2);
}

int fn_R001836_3613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001836_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int mask_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_15) & 63;
  acc ^= aux;
  int segment_90 = (aux + st.buffer[1]) & 3;
  switch (segment_90)
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

void fn_R001836_3613_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st_1 = {0};
  struct SensorNode_R001836_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_19_1 > 22)
  {
    acc_1 = ((acc_1 + (cursor_19_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_19_2 > 22)
  {
    acc_2 = ((acc_2 + (cursor_19_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_28_1)
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

  switch (checksum_28_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_19_1 == cursor_19_2);
  assert(checksum_28_1 == checksum_28_2);
}

int fn_R001836_3613_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001836_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_19 > 22)
  {
    acc = ((acc + (cursor_19 * 2)) + 5) & 127;
    aux ^= cursor_19 & 15;
  }
  else
  {
    acc = ((acc - cursor_19) + 11) & 127;
    aux += 3;
  }
  int checksum_28 = (aux + st.buffer[1]) & 3;
  switch (checksum_28)
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
  int sec_r001836_0_1;
  int sec_r001836_0_2;
  int sec_r001836_1_1;
  int sec_r001836_1_2;
  int sec_r001836_2_1;
  int sec_r001836_2_2;
  int sec_r001836_3_1;
  int sec_r001836_3_2;
  int sec_r001836_4_1;
  int sec_r001836_4_2;
  int sec_r001836_5_1;
  int sec_r001836_5_2;
  int sec_r001836_6_1;
  int sec_r001836_6_2;
  int sec_r001836_7_1;
  int sec_r001836_7_2;
  int sec_r001836_8_1;
  int sec_r001836_8_2;
  int sec_r001836_9_1;
  int sec_r001836_9_2;
  int sec_r001836_10_1;
  int sec_r001836_10_2;
  int sec_r001836_11_1;
  int sec_r001836_11_2;
  int sec_r001836_12_1;
  int sec_r001836_12_2;
  int sec_r001836_13_1;
  int sec_r001836_13_2;
  int sec_r001836_14_1;
  int sec_r001836_14_2;
  int sec_r001836_15_1;
  int sec_r001836_15_2;
  int pub_r001836_0_1;
  int pub_r001836_0_2;
  int pub_r001836_1_1;
  int pub_r001836_1_2;
  int pub_r001836_2_1;
  int pub_r001836_2_2;
  int pub_r001836_3_1;
  int pub_r001836_3_2;
  int pub_r001836_4_1;
  int pub_r001836_4_2;
  int pub_r001836_5_1;
  int pub_r001836_5_2;
  int pub_r001836_6_1;
  int pub_r001836_6_2;
  int pub_r001836_7_1;
  int pub_r001836_7_2;
  int pub_r001836_8_1;
  int pub_r001836_8_2;
  int pub_r001836_9_1;
  int pub_r001836_9_2;
  int pub_r001836_10_1;
  int pub_r001836_10_2;
  int pub_r001836_11_1;
  int pub_r001836_11_2;
  int pub_r001836_12_1;
  int pub_r001836_12_2;
  int pub_r001836_13_1;
  int pub_r001836_13_2;
  int pub_r001836_14_1;
  int pub_r001836_14_2;
  int pub_r001836_15_1;
  int pub_r001836_15_2;
  int pub_r001836_16_1;
  int pub_r001836_16_2;
  int pub_r001836_17_1;
  int pub_r001836_17_2;
  int pub_r001836_18_1;
  int pub_r001836_18_2;
  int pub_r001836_19_1;
  int pub_r001836_19_2;
  int pub_r001836_20_1;
  int pub_r001836_20_2;
  int pub_r001836_21_1;
  int pub_r001836_21_2;
  int pub_r001836_22_1;
  int pub_r001836_22_2;
  int pub_r001836_23_1;
  int pub_r001836_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001836_0_1 >= (-100)) && (pub_r001836_0_1 <= 100));
  __CPROVER_assume((pub_r001836_0_2 >= (-100)) && (pub_r001836_0_2 <= 100));
  __CPROVER_assume((pub_r001836_1_1 >= (-100)) && (pub_r001836_1_1 <= 100));
  __CPROVER_assume((pub_r001836_1_2 >= (-100)) && (pub_r001836_1_2 <= 100));
  __CPROVER_assume((pub_r001836_2_1 >= (-100)) && (pub_r001836_2_1 <= 100));
  __CPROVER_assume((pub_r001836_2_2 >= (-100)) && (pub_r001836_2_2 <= 100));
  __CPROVER_assume((pub_r001836_3_1 >= (-100)) && (pub_r001836_3_1 <= 100));
  __CPROVER_assume((pub_r001836_3_2 >= (-100)) && (pub_r001836_3_2 <= 100));
  __CPROVER_assume((pub_r001836_4_1 >= (-100)) && (pub_r001836_4_1 <= 100));
  __CPROVER_assume((pub_r001836_4_2 >= (-100)) && (pub_r001836_4_2 <= 100));
  __CPROVER_assume((pub_r001836_5_1 >= (-100)) && (pub_r001836_5_1 <= 100));
  __CPROVER_assume((pub_r001836_5_2 >= (-100)) && (pub_r001836_5_2 <= 100));
  __CPROVER_assume((pub_r001836_6_1 >= (-100)) && (pub_r001836_6_1 <= 100));
  __CPROVER_assume((pub_r001836_6_2 >= (-100)) && (pub_r001836_6_2 <= 100));
  __CPROVER_assume((pub_r001836_7_1 >= (-100)) && (pub_r001836_7_1 <= 100));
  __CPROVER_assume((pub_r001836_7_2 >= (-100)) && (pub_r001836_7_2 <= 100));
  __CPROVER_assume((pub_r001836_8_1 >= (-100)) && (pub_r001836_8_1 <= 100));
  __CPROVER_assume((pub_r001836_8_2 >= (-100)) && (pub_r001836_8_2 <= 100));
  __CPROVER_assume((pub_r001836_9_1 >= (-100)) && (pub_r001836_9_1 <= 100));
  __CPROVER_assume((pub_r001836_9_2 >= (-100)) && (pub_r001836_9_2 <= 100));
  __CPROVER_assume((pub_r001836_10_1 >= (-100)) && (pub_r001836_10_1 <= 100));
  __CPROVER_assume((pub_r001836_10_2 >= (-100)) && (pub_r001836_10_2 <= 100));
  __CPROVER_assume((pub_r001836_11_1 >= (-100)) && (pub_r001836_11_1 <= 100));
  __CPROVER_assume((pub_r001836_11_2 >= (-100)) && (pub_r001836_11_2 <= 100));
  __CPROVER_assume((pub_r001836_12_1 >= (-100)) && (pub_r001836_12_1 <= 100));
  __CPROVER_assume((pub_r001836_12_2 >= (-100)) && (pub_r001836_12_2 <= 100));
  __CPROVER_assume((pub_r001836_13_1 >= (-100)) && (pub_r001836_13_1 <= 100));
  __CPROVER_assume((pub_r001836_13_2 >= (-100)) && (pub_r001836_13_2 <= 100));
  __CPROVER_assume((pub_r001836_14_1 >= (-100)) && (pub_r001836_14_1 <= 100));
  __CPROVER_assume((pub_r001836_14_2 >= (-100)) && (pub_r001836_14_2 <= 100));
  __CPROVER_assume((pub_r001836_15_1 >= (-100)) && (pub_r001836_15_1 <= 100));
  __CPROVER_assume((pub_r001836_15_2 >= (-100)) && (pub_r001836_15_2 <= 100));
  __CPROVER_assume((pub_r001836_16_1 >= (-100)) && (pub_r001836_16_1 <= 100));
  __CPROVER_assume((pub_r001836_16_2 >= (-100)) && (pub_r001836_16_2 <= 100));
  __CPROVER_assume((pub_r001836_17_1 >= (-100)) && (pub_r001836_17_1 <= 100));
  __CPROVER_assume((pub_r001836_17_2 >= (-100)) && (pub_r001836_17_2 <= 100));
  __CPROVER_assume((pub_r001836_18_1 >= (-100)) && (pub_r001836_18_1 <= 100));
  __CPROVER_assume((pub_r001836_18_2 >= (-100)) && (pub_r001836_18_2 <= 100));
  __CPROVER_assume((pub_r001836_19_1 >= (-100)) && (pub_r001836_19_1 <= 100));
  __CPROVER_assume((pub_r001836_19_2 >= (-100)) && (pub_r001836_19_2 <= 100));
  __CPROVER_assume((pub_r001836_20_1 >= (-100)) && (pub_r001836_20_1 <= 100));
  __CPROVER_assume((pub_r001836_20_2 >= (-100)) && (pub_r001836_20_2 <= 100));
  __CPROVER_assume((pub_r001836_21_1 >= (-100)) && (pub_r001836_21_1 <= 100));
  __CPROVER_assume((pub_r001836_21_2 >= (-100)) && (pub_r001836_21_2 <= 100));
  __CPROVER_assume((pub_r001836_22_1 >= (-100)) && (pub_r001836_22_1 <= 100));
  __CPROVER_assume((pub_r001836_22_2 >= (-100)) && (pub_r001836_22_2 <= 100));
  __CPROVER_assume((pub_r001836_23_1 >= (-100)) && (pub_r001836_23_1 <= 100));
  __CPROVER_assume((pub_r001836_23_2 >= (-100)) && (pub_r001836_23_2 <= 100));
  __CPROVER_assume((sec_r001836_0_1 >= 0) && (sec_r001836_0_1 <= 255));
  __CPROVER_assume((sec_r001836_0_2 >= 0) && (sec_r001836_0_2 <= 255));
  __CPROVER_assume((sec_r001836_1_1 >= 0) && (sec_r001836_1_1 <= 255));
  __CPROVER_assume((sec_r001836_1_2 >= 0) && (sec_r001836_1_2 <= 255));
  __CPROVER_assume((sec_r001836_2_1 >= 0) && (sec_r001836_2_1 <= 255));
  __CPROVER_assume((sec_r001836_2_2 >= 0) && (sec_r001836_2_2 <= 255));
  __CPROVER_assume((sec_r001836_3_1 >= 0) && (sec_r001836_3_1 <= 255));
  __CPROVER_assume((sec_r001836_3_2 >= 0) && (sec_r001836_3_2 <= 255));
  __CPROVER_assume((sec_r001836_4_1 >= 0) && (sec_r001836_4_1 <= 255));
  __CPROVER_assume((sec_r001836_4_2 >= 0) && (sec_r001836_4_2 <= 255));
  __CPROVER_assume((sec_r001836_5_1 >= 0) && (sec_r001836_5_1 <= 255));
  __CPROVER_assume((sec_r001836_5_2 >= 0) && (sec_r001836_5_2 <= 255));
  __CPROVER_assume((sec_r001836_6_1 >= 0) && (sec_r001836_6_1 <= 255));
  __CPROVER_assume((sec_r001836_6_2 >= 0) && (sec_r001836_6_2 <= 255));
  __CPROVER_assume((sec_r001836_7_1 >= 0) && (sec_r001836_7_1 <= 255));
  __CPROVER_assume((sec_r001836_7_2 >= 0) && (sec_r001836_7_2 <= 255));
  __CPROVER_assume((sec_r001836_8_1 >= 0) && (sec_r001836_8_1 <= 255));
  __CPROVER_assume((sec_r001836_8_2 >= 0) && (sec_r001836_8_2 <= 255));
  __CPROVER_assume((sec_r001836_9_1 >= 0) && (sec_r001836_9_1 <= 255));
  __CPROVER_assume((sec_r001836_9_2 >= 0) && (sec_r001836_9_2 <= 255));
  __CPROVER_assume((sec_r001836_10_1 >= 0) && (sec_r001836_10_1 <= 255));
  __CPROVER_assume((sec_r001836_10_2 >= 0) && (sec_r001836_10_2 <= 255));
  __CPROVER_assume((sec_r001836_11_1 >= 0) && (sec_r001836_11_1 <= 255));
  __CPROVER_assume((sec_r001836_11_2 >= 0) && (sec_r001836_11_2 <= 255));
  __CPROVER_assume((sec_r001836_12_1 >= 0) && (sec_r001836_12_1 <= 255));
  __CPROVER_assume((sec_r001836_12_2 >= 0) && (sec_r001836_12_2 <= 255));
  __CPROVER_assume((sec_r001836_13_1 >= 0) && (sec_r001836_13_1 <= 255));
  __CPROVER_assume((sec_r001836_13_2 >= 0) && (sec_r001836_13_2 <= 255));
  __CPROVER_assume((sec_r001836_14_1 >= 0) && (sec_r001836_14_1 <= 255));
  __CPROVER_assume((sec_r001836_14_2 >= 0) && (sec_r001836_14_2 <= 255));
  __CPROVER_assume((sec_r001836_15_1 >= 0) && (sec_r001836_15_1 <= 255));
  __CPROVER_assume((sec_r001836_15_2 >= 0) && (sec_r001836_15_2 <= 255));
  struct AudioFrame_R001836_3613_0 st_var_0_1 = {0};
  struct AudioFrame_R001836_3613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001836_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001836_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001836_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001836_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001836_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001836_0_2 + 7) & 15;
  struct StreamBuffer_R001836_3613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001836_3613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001836_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001836_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001836_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001836_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001836_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001836_0_2 + 9) & 15;
  struct SensorNode_R001836_3613_2 st_var_2_1 = {0};
  struct SensorNode_R001836_3613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001836_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001836_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001836_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001836_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001836_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001836_0_2 + 11) & 15;
  union PacketPayload_R001836_3613_0 u_var_1;
  union PacketPayload_R001836_3613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001836_3613_0(sec_r001836_0_1, sec_r001836_1_1, pub_r001836_2_1);
  int helper_flow_0_2 = fn_R001836_3613_0(sec_r001836_0_2, sec_r001836_1_2, pub_r001836_2_2);
  fn_R001836_3613_0_2(sec_r001836_0_1, sec_r001836_1_1, pub_r001836_2_1, sec_r001836_0_2, sec_r001836_1_2, pub_r001836_2_2);
  int helper_flow_1_1 = fn_R001836_3613_1(sec_r001836_1_1, pub_r001836_2_1, pub_r001836_3_1, pub_r001836_4_1, pub_r001836_5_1);
  int helper_flow_1_2 = fn_R001836_3613_1(sec_r001836_1_2, pub_r001836_2_2, pub_r001836_3_2, pub_r001836_4_2, pub_r001836_5_2);
  fn_R001836_3613_1_2(sec_r001836_1_1, pub_r001836_2_1, pub_r001836_3_1, pub_r001836_4_1, pub_r001836_5_1, sec_r001836_1_2, pub_r001836_2_2, pub_r001836_3_2, pub_r001836_4_2, pub_r001836_5_2);
  int helper_flow_2_1 = fn_R001836_3613_2(sec_r001836_2_1, sec_r001836_3_1, pub_r001836_4_1);
  int helper_flow_2_2 = fn_R001836_3613_2(sec_r001836_2_2, sec_r001836_3_2, pub_r001836_4_2);
  fn_R001836_3613_2_2(sec_r001836_2_1, sec_r001836_3_1, pub_r001836_4_1, sec_r001836_2_2, sec_r001836_3_2, pub_r001836_4_2);
  int helper_flow_3_1 = fn_R001836_3613_3(sec_r001836_3_1, sec_r001836_4_1, pub_r001836_5_1, pub_r001836_6_1);
  int helper_flow_3_2 = fn_R001836_3613_3(sec_r001836_3_2, sec_r001836_4_2, pub_r001836_5_2, pub_r001836_6_2);
  fn_R001836_3613_3_2(sec_r001836_3_1, sec_r001836_4_1, pub_r001836_5_1, pub_r001836_6_1, sec_r001836_3_2, sec_r001836_4_2, pub_r001836_5_2, pub_r001836_6_2);
  int helper_flow_4_1 = fn_R001836_3613_4(sec_r001836_4_1, sec_r001836_5_1);
  int helper_flow_4_2 = fn_R001836_3613_4(sec_r001836_4_2, sec_r001836_5_2);
  fn_R001836_3613_4_2(sec_r001836_4_1, sec_r001836_5_1, sec_r001836_4_2, sec_r001836_5_2);
  int helper_flow_5_1 = fn_R001836_3613_5(sec_r001836_5_1, sec_r001836_6_1, pub_r001836_7_1, pub_r001836_8_1, pub_r001836_9_1);
  int helper_flow_5_2 = fn_R001836_3613_5(sec_r001836_5_2, sec_r001836_6_2, pub_r001836_7_2, pub_r001836_8_2, pub_r001836_9_2);
  fn_R001836_3613_5_2(sec_r001836_5_1, sec_r001836_6_1, pub_r001836_7_1, pub_r001836_8_1, pub_r001836_9_1, sec_r001836_5_2, sec_r001836_6_2, pub_r001836_7_2, pub_r001836_8_2, pub_r001836_9_2);
  int helper_flow_6_1 = fn_R001836_3613_6(sec_r001836_6_1, sec_r001836_7_1, pub_r001836_8_1);
  int helper_flow_6_2 = fn_R001836_3613_6(sec_r001836_6_2, sec_r001836_7_2, pub_r001836_8_2);
  fn_R001836_3613_6_2(sec_r001836_6_1, sec_r001836_7_1, pub_r001836_8_1, sec_r001836_6_2, sec_r001836_7_2, pub_r001836_8_2);
  int stage_v_0_1 = ((helper_flow_4_1 + (pub_r001836_4_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_4_2 + (pub_r001836_4_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001836_21_1 * 2) + 26) & 63;
  int stage_v_1_2 = ((pub_r001836_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001836_7_1 * 2) + 44) & 63;
  int stage_v_2_2 = ((pub_r001836_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((helper_flow_2_1 + (pub_r001836_4_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_2_2 + (pub_r001836_4_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001836_8_1 * 2) + 30) & 63;
  int stage_v_4_2 = ((pub_r001836_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_6_1 + (pub_r001836_23_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_6_2 + (pub_r001836_23_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001836_2_1 + (pub_r001836_15_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001836_2_2 + (pub_r001836_15_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001836_14_1 + (pub_r001836_12_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001836_14_2 + (pub_r001836_12_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((stage_v_3_1 + (pub_r001836_18_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((stage_v_3_2 + (pub_r001836_18_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001836_3_1 + (pub_r001836_6_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001836_3_2 + (pub_r001836_6_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001836_5_1 + (pub_r001836_13_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001836_5_2 + (pub_r001836_13_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001836_8_1 * 2) + 47) & 63;
  int stage_v_11_2 = ((pub_r001836_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((helper_flow_3_1 + (pub_r001836_2_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_3_2 + (pub_r001836_2_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001836_9_1 * 2) + 22) & 63;
  int stage_v_13_2 = ((pub_r001836_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((stage_v_5_1 + (pub_r001836_21_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_5_2 + (pub_r001836_21_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001836_12_1 * 2) + 15) & 63;
  int stage_v_15_2 = ((pub_r001836_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001836_8_1 * 2) + 47) & 63;
  int stage_v_16_2 = ((pub_r001836_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((helper_flow_5_1 + (pub_r001836_0_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_5_2 + (pub_r001836_0_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_0_1 + (pub_r001836_0_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_0_2 + (pub_r001836_0_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001836_12_1 * 2) + 47) & 63;
  int stage_v_19_2 = ((pub_r001836_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((helper_flow_6_1 + (pub_r001836_21_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_6_2 + (pub_r001836_21_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001836_14_1 + (pub_r001836_7_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001836_14_2 + (pub_r001836_7_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001836_4_1 * 2) + 30) & 63;
  int stage_v_22_2 = ((pub_r001836_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((sec_r001836_4_1 + (pub_r001836_17_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001836_4_2 + (pub_r001836_17_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((helper_flow_1_1 + (pub_r001836_9_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((helper_flow_1_2 + (pub_r001836_9_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001836_23_1 * 2) + 7) & 63;
  int stage_v_25_2 = ((pub_r001836_23_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001836_6_1 + (pub_r001836_2_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001836_6_2 + (pub_r001836_2_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((helper_flow_3_1 + (pub_r001836_11_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((helper_flow_3_2 + (pub_r001836_11_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001836_6_1 + (pub_r001836_12_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001836_6_2 + (pub_r001836_12_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001836_16_1 * 2) + 29) & 63;
  int stage_v_29_2 = ((pub_r001836_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001836_5_1 * 2) + 9) & 63;
  int stage_v_30_2 = ((pub_r001836_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001836_0_1 + (pub_r001836_2_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001836_0_2 + (pub_r001836_2_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001836_9_1 * 2) + 31) & 63;
  int stage_v_32_2 = ((pub_r001836_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001836_4_1 * 2) + 31) & 63;
  int stage_v_33_2 = ((pub_r001836_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((stage_v_9_1 + (pub_r001836_3_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_9_2 + (pub_r001836_3_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((pub_r001836_16_1 * 2) + 35) & 63;
  int stage_v_35_2 = ((pub_r001836_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001836_14_1 * 2) + 31) & 63;
  int stage_v_36_2 = ((pub_r001836_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((helper_flow_0_1 + (pub_r001836_7_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_0_2 + (pub_r001836_7_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((sec_r001836_9_1 + (pub_r001836_18_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001836_9_2 + (pub_r001836_18_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((sec_r001836_11_1 + (pub_r001836_13_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001836_11_2 + (pub_r001836_13_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001836_19_1 * 2) + 40) & 63;
  int stage_v_40_2 = ((pub_r001836_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001836_16_1 * 2) + 20) & 63;
  int stage_v_41_2 = ((pub_r001836_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_23_1 + (pub_r001836_4_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_23_2 + (pub_r001836_4_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001836_1_1 * 2) + 13) & 63;
  int stage_v_43_2 = ((pub_r001836_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((sec_r001836_14_1 + (pub_r001836_14_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001836_14_2 + (pub_r001836_14_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001836_0_1 * 2) + 20) & 63;
  int stage_v_45_2 = ((pub_r001836_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_26_1 + (pub_r001836_2_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_26_2 + (pub_r001836_2_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001836_8_1 * 2) + 6) & 63;
  int stage_v_47_2 = ((pub_r001836_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001836_10_1 * 2) + 10) & 63;
  int stage_v_48_2 = ((pub_r001836_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001836_4_1 * 2) + 49) & 63;
  int stage_v_49_2 = ((pub_r001836_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((stage_v_21_1 + (pub_r001836_12_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_21_2 + (pub_r001836_12_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001836_3_1 * 2) + 36) & 63;
  int stage_v_51_2 = ((pub_r001836_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001836_9_1 * 2) + 48) & 63;
  int stage_v_52_2 = ((pub_r001836_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001836_7_1 * 2) + 25) & 63;
  int stage_v_53_2 = ((pub_r001836_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_8_1 + (pub_r001836_21_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_8_2 + (pub_r001836_21_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001836_13_1 + (pub_r001836_10_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001836_13_2 + (pub_r001836_10_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_37_1 + (pub_r001836_1_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_37_2 + (pub_r001836_1_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((sec_r001836_13_1 + (pub_r001836_8_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001836_13_2 + (pub_r001836_8_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_54_1 + (pub_r001836_18_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_54_2 + (pub_r001836_18_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_6_1 + (pub_r001836_20_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_6_2 + (pub_r001836_20_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001836_13_1 * 2) + 14) & 63;
  int stage_v_60_2 = ((pub_r001836_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001836_1_1 * 2) + 47) & 63;
  int stage_v_61_2 = ((pub_r001836_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((sec_r001836_7_1 + (pub_r001836_17_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((sec_r001836_7_2 + (pub_r001836_17_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001836_21_1 * 2) + 24) & 63;
  int stage_v_63_2 = ((pub_r001836_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_39_1 + (pub_r001836_21_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_39_2 + (pub_r001836_21_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_5_1 + (pub_r001836_21_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_5_2 + (pub_r001836_21_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((sec_r001836_12_1 + (pub_r001836_15_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001836_12_2 + (pub_r001836_15_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_50_1 + (pub_r001836_0_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_50_2 + (pub_r001836_0_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((helper_flow_6_1 + (pub_r001836_19_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((helper_flow_6_2 + (pub_r001836_19_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_64_1 + (pub_r001836_1_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_64_2 + (pub_r001836_1_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_31_1 + (pub_r001836_19_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_31_2 + (pub_r001836_19_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((helper_flow_2_1 + (pub_r001836_2_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((helper_flow_2_2 + (pub_r001836_2_2 * 2)) + 218) & 127;
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
  int stage_v_72_1 = ((helper_flow_5_1 + (pub_r001836_9_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((helper_flow_5_2 + (pub_r001836_9_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_34_1 + (pub_r001836_0_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_34_2 + (pub_r001836_0_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001836_11_1 * 2) + 37) & 63;
  int stage_v_74_2 = ((pub_r001836_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001836_1_1 * 2) + 42) & 63;
  int stage_v_75_2 = ((pub_r001836_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_57_1 + (pub_r001836_8_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_57_2 + (pub_r001836_8_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((helper_flow_4_1 + (pub_r001836_14_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_4_2 + (pub_r001836_14_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_72_1 + (pub_r001836_12_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_72_2 + (pub_r001836_12_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001836_17_1 * 2) + 6) & 63;
  int stage_v_79_2 = ((pub_r001836_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((sec_r001836_13_1 + (pub_r001836_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001836_13_2 + (pub_r001836_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001836_3_1 * 2) + 28) & 63;
  int stage_v_81_2 = ((pub_r001836_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001836_5_1 * 2) + 17) & 63;
  int stage_v_82_2 = ((pub_r001836_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001836_0_1 * 2) + 19) & 63;
  int stage_v_83_2 = ((pub_r001836_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_38_1 + (pub_r001836_14_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_38_2 + (pub_r001836_14_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_57_1 + (pub_r001836_22_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_57_2 + (pub_r001836_22_2 * 2)) + 260) & 127;
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
  int stage_v_86_1 = ((stage_v_76_1 + (pub_r001836_8_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_76_2 + (pub_r001836_8_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((pub_r001836_12_1 * 2) + 18) & 63;
  int stage_v_87_2 = ((pub_r001836_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001836_0_1 * 2) + 17) & 63;
  int stage_v_88_2 = ((pub_r001836_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001836_11_1 * 2) + 35) & 63;
  int stage_v_89_2 = ((pub_r001836_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001836_23_1 * 2) + 44) & 63;
  int stage_v_90_2 = ((pub_r001836_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_55_1 + (pub_r001836_10_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_55_2 + (pub_r001836_10_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001836_19_1 * 2) + 5) & 63;
  int stage_v_92_2 = ((pub_r001836_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_72_1 + (pub_r001836_9_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_72_2 + (pub_r001836_9_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_85_1 + (pub_r001836_1_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_85_2 + (pub_r001836_1_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_34_1 + (pub_r001836_2_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_34_2 + (pub_r001836_2_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_94_1 + (pub_r001836_11_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_94_2 + (pub_r001836_11_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((sec_r001836_0_1 + (pub_r001836_16_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((sec_r001836_0_2 + (pub_r001836_16_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001836_17_1 * 2) + 31) & 63;
  int stage_v_98_2 = ((pub_r001836_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001836_13_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001836_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001836_14_1 * 2) + 12) & 63;
  int stage_v_100_2 = ((pub_r001836_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_84_1 + (pub_r001836_10_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_84_2 + (pub_r001836_10_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001836_11_1 * 2) + 6) & 63;
  int stage_v_102_2 = ((pub_r001836_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_14_1 + (pub_r001836_9_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_14_2 + (pub_r001836_9_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_94_1 + (pub_r001836_2_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_94_2 + (pub_r001836_2_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001836_13_1 * 2) + 26) & 63;
  int stage_v_105_2 = ((pub_r001836_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001836_9_1 * 2) + 50) & 63;
  int stage_v_106_2 = ((pub_r001836_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001836_0_1 * 2) + 9) & 63;
  int stage_v_107_2 = ((pub_r001836_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_57_1 + (pub_r001836_23_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_57_2 + (pub_r001836_23_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_21_1 + (pub_r001836_18_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_21_2 + (pub_r001836_18_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_55_1 + (pub_r001836_8_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_55_2 + (pub_r001836_8_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_28_1 + (pub_r001836_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_28_2 + (pub_r001836_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001836_1_1 + (pub_r001836_10_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001836_1_2 + (pub_r001836_10_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_77_1 + (pub_r001836_21_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_77_2 + (pub_r001836_21_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_34_1 + (pub_r001836_21_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_34_2 + (pub_r001836_21_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((pub_r001836_21_1 * 2) + 42) & 63;
  int stage_v_115_2 = ((pub_r001836_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_69_1 + (pub_r001836_21_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_69_2 + (pub_r001836_21_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001836_20_1 * 2) + 44) & 63;
  int stage_v_117_2 = ((pub_r001836_20_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001836_6_1 * 2) + 50) & 63;
  int stage_v_118_2 = ((pub_r001836_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((stage_v_23_1 + (pub_r001836_0_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_23_2 + (pub_r001836_0_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001836_10_1 * 2) + 33) & 63;
  int stage_v_120_2 = ((pub_r001836_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_20_1 + (pub_r001836_20_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_20_2 + (pub_r001836_20_2 * 2)) + 368) & 127;
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
  int stage_v_122_1 = ((sec_r001836_2_1 + (pub_r001836_12_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001836_2_2 + (pub_r001836_12_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((sec_r001836_10_1 + (pub_r001836_7_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((sec_r001836_10_2 + (pub_r001836_7_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001836_22_1 * 2) + 29) & 63;
  int stage_v_124_2 = ((pub_r001836_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_23_1 + (pub_r001836_18_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_23_2 + (pub_r001836_18_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001836_22_1 * 2) + 16) & 63;
  int stage_v_126_2 = ((pub_r001836_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_123_1 + (pub_r001836_10_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_123_2 + (pub_r001836_10_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((helper_flow_5_1 + (pub_r001836_15_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((helper_flow_5_2 + (pub_r001836_15_2 * 2)) + 389) & 127;
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
  int stage_v_129_1 = ((stage_v_119_1 + (pub_r001836_1_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_119_2 + (pub_r001836_1_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_23_1 + (pub_r001836_19_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_23_2 + (pub_r001836_19_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_21_1 + (pub_r001836_7_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_21_2 + (pub_r001836_7_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001836_14_1 + (pub_r001836_20_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001836_14_2 + (pub_r001836_20_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001836_12_1 * 2) + 31) & 63;
  int stage_v_133_2 = ((pub_r001836_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_132_1 + (pub_r001836_2_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_132_2 + (pub_r001836_2_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001836_23_1 * 2) + 44) & 63;
  int stage_v_135_2 = ((pub_r001836_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((sec_r001836_5_1 + (pub_r001836_6_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((sec_r001836_5_2 + (pub_r001836_6_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001836_16_1 * 2) + 39) & 63;
  int stage_v_137_2 = ((pub_r001836_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((sec_r001836_0_1 + (pub_r001836_16_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((sec_r001836_0_2 + (pub_r001836_16_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_122_1 + (pub_r001836_18_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_122_2 + (pub_r001836_18_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((pub_r001836_5_1 * 2) + 20) & 63;
  int stage_v_140_2 = ((pub_r001836_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_21_1 + (pub_r001836_5_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_21_2 + (pub_r001836_5_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_17_1 + (pub_r001836_1_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_17_2 + (pub_r001836_1_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((sec_r001836_1_1 + (pub_r001836_0_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((sec_r001836_1_2 + (pub_r001836_0_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((helper_flow_5_1 + (pub_r001836_0_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((helper_flow_5_2 + (pub_r001836_0_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_94_1 + (pub_r001836_6_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_94_2 + (pub_r001836_6_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((sec_r001836_3_1 + (pub_r001836_12_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((sec_r001836_3_2 + (pub_r001836_12_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_128_1 + (pub_r001836_21_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_128_2 + (pub_r001836_21_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001836_1_1 * 2) + 28) & 63;
  int stage_v_148_2 = ((pub_r001836_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001836_17_1 * 2) + 21) & 63;
  int stage_v_149_2 = ((pub_r001836_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001836_6_1 * 2) + 10) & 63;
  int stage_v_150_2 = ((pub_r001836_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_44_1 + (pub_r001836_20_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_44_2 + (pub_r001836_20_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_72_1 + (pub_r001836_6_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_72_2 + (pub_r001836_6_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_27_1 + (pub_r001836_22_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_27_2 + (pub_r001836_22_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001836_21_1 * 2) + 50) & 63;
  int stage_v_154_2 = ((pub_r001836_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001836_1_1 * 2) + 9) & 63;
  int stage_v_155_2 = ((pub_r001836_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((helper_flow_1_1 + (pub_r001836_16_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((helper_flow_1_2 + (pub_r001836_16_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_70_1 + (pub_r001836_3_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_70_2 + (pub_r001836_3_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_9_1 + (pub_r001836_21_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_9_2 + (pub_r001836_21_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001836_3_1 * 2) + 48) & 63;
  int stage_v_159_2 = ((pub_r001836_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((stage_v_97_1 + (pub_r001836_20_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_97_2 + (pub_r001836_20_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001836_18_1 * 2) + 45) & 63;
  int stage_v_161_2 = ((pub_r001836_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((helper_flow_5_1 + (pub_r001836_23_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((helper_flow_5_2 + (pub_r001836_23_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001836_5_1 * 2) + 22) & 63;
  int stage_v_163_2 = ((pub_r001836_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001836_5_1 * 2) + 23) & 63;
  int stage_v_164_2 = ((pub_r001836_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((helper_flow_1_1 + (pub_r001836_14_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((helper_flow_1_2 + (pub_r001836_14_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_31_1 + (pub_r001836_6_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_31_2 + (pub_r001836_6_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_84_1 + (pub_r001836_2_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_84_2 + (pub_r001836_2_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_112_1 + (pub_r001836_17_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_112_2 + (pub_r001836_17_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((helper_flow_5_1 + (pub_r001836_12_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((helper_flow_5_2 + (pub_r001836_12_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_168_1 + (pub_r001836_20_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_168_2 + (pub_r001836_20_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_78_1 + (pub_r001836_19_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_78_2 + (pub_r001836_19_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001836_0_1 * 2) + 47) & 63;
  int stage_v_172_2 = ((pub_r001836_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_85_1 + (pub_r001836_1_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_85_2 + (pub_r001836_1_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_113_1 + (pub_r001836_1_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_113_2 + (pub_r001836_1_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_121_1 + (pub_r001836_12_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_121_2 + (pub_r001836_12_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_77_1 + (pub_r001836_7_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_77_2 + (pub_r001836_7_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001836_5_1 * 2) + 50) & 63;
  int stage_v_177_2 = ((pub_r001836_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((sec_r001836_1_1 + (pub_r001836_15_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((sec_r001836_1_2 + (pub_r001836_15_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_145_1 + (pub_r001836_8_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_145_2 + (pub_r001836_8_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_125_1 + (pub_r001836_1_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_125_2 + (pub_r001836_1_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_176_1 + (pub_r001836_11_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_176_2 + (pub_r001836_11_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_12_1 + (pub_r001836_19_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_12_2 + (pub_r001836_19_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_70_1 + (pub_r001836_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_70_2 + (pub_r001836_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_96_1 + (pub_r001836_4_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_96_2 + (pub_r001836_4_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_84_1 + (pub_r001836_22_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_84_2 + (pub_r001836_22_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_101_1 + (pub_r001836_20_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_101_2 + (pub_r001836_20_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((helper_flow_5_1 + (pub_r001836_2_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((helper_flow_5_2 + (pub_r001836_2_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001836_16_1 * 2) + 34) & 63;
  int stage_v_188_2 = ((pub_r001836_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001836_16_1 * 2) + 11) & 63;
  int stage_v_189_2 = ((pub_r001836_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((stage_v_132_1 + (pub_r001836_18_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_132_2 + (pub_r001836_18_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_165_1 + (pub_r001836_7_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_165_2 + (pub_r001836_7_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_169_1 + (pub_r001836_16_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_169_2 + (pub_r001836_16_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001836_14_1 * 2) + 15) & 63;
  int stage_v_193_2 = ((pub_r001836_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_73_1 + (pub_r001836_0_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_73_2 + (pub_r001836_0_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_101_1 + (pub_r001836_8_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_101_2 + (pub_r001836_8_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001836_13_1 == pub_r001836_13_2);
  __CPROVER_assume(sec_r001836_6_1 != sec_r001836_6_2);
  __CPROVER_assume(pub_r001836_6_1 == pub_r001836_6_2);
  __CPROVER_assume(sec_r001836_3_1 != sec_r001836_3_2);
  __CPROVER_assume(pub_r001836_1_1 == pub_r001836_1_2);
  __CPROVER_assume(pub_r001836_9_1 == pub_r001836_9_2);
  __CPROVER_assume(pub_r001836_14_1 == pub_r001836_14_2);
  __CPROVER_assume(pub_r001836_12_1 == pub_r001836_12_2);
  __CPROVER_assume(pub_r001836_23_1 == pub_r001836_23_2);
  __CPROVER_assume(sec_r001836_5_1 != sec_r001836_5_2);
  __CPROVER_assume(sec_r001836_1_1 != sec_r001836_1_2);
  __CPROVER_assume(sec_r001836_0_1 != sec_r001836_0_2);
  __CPROVER_assume(sec_r001836_11_1 != sec_r001836_11_2);
  __CPROVER_assume(pub_r001836_3_1 == pub_r001836_3_2);
  __CPROVER_assume(pub_r001836_18_1 == pub_r001836_18_2);
  __CPROVER_assume(sec_r001836_15_1 != sec_r001836_15_2);
  __CPROVER_assume(pub_r001836_22_1 == pub_r001836_22_2);
  __CPROVER_assume(sec_r001836_12_1 != sec_r001836_12_2);
  __CPROVER_assume(sec_r001836_13_1 != sec_r001836_13_2);
  __CPROVER_assume(sec_r001836_9_1 != sec_r001836_9_2);
  __CPROVER_assume(pub_r001836_21_1 == pub_r001836_21_2);
  __CPROVER_assume(pub_r001836_16_1 == pub_r001836_16_2);
  __CPROVER_assume(pub_r001836_10_1 == pub_r001836_10_2);
  __CPROVER_assume(pub_r001836_20_1 == pub_r001836_20_2);
  __CPROVER_assume(pub_r001836_4_1 == pub_r001836_4_2);
  __CPROVER_assume(sec_r001836_4_1 != sec_r001836_4_2);
  __CPROVER_assume(pub_r001836_7_1 == pub_r001836_7_2);
  __CPROVER_assume(pub_r001836_2_1 == pub_r001836_2_2);
  __CPROVER_assume(sec_r001836_14_1 != sec_r001836_14_2);
  __CPROVER_assume(pub_r001836_17_1 == pub_r001836_17_2);
  __CPROVER_assume(pub_r001836_5_1 == pub_r001836_5_2);
  __CPROVER_assume(sec_r001836_7_1 != sec_r001836_7_2);
  __CPROVER_assume(sec_r001836_10_1 != sec_r001836_10_2);
  __CPROVER_assume(pub_r001836_19_1 == pub_r001836_19_2);
  __CPROVER_assume(pub_r001836_0_1 == pub_r001836_0_2);
  __CPROVER_assume(sec_r001836_8_1 != sec_r001836_8_2);
  __CPROVER_assume(sec_r001836_2_1 != sec_r001836_2_2);
  __CPROVER_assume(pub_r001836_15_1 == pub_r001836_15_2);
  __CPROVER_assume(pub_r001836_8_1 == pub_r001836_8_2);
  __CPROVER_assume(pub_r001836_11_1 == pub_r001836_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.calib == st_var_2_2.calib);
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
}


