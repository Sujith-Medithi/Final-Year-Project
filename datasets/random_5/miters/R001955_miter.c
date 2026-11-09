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
struct Transaction_R001955_5513_0
{
  short fee;
  int account_id;
  short rate;
  int auth_code;
  int status;
  int buffer[3];
};
struct StreamBuffer_R001955_5513_1
{
  int watermark;
  int head;
  short capacity;
  short tail;
  int buffer[3];
};
struct CipherContext_R001955_5513_2
{
  unsigned char counter;
  short nonce;
  int tag;
  unsigned char flags;
  int buffer[3];
};
union RegisterBank_R001955_5513_0
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
void fn_R001955_5513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_23_1 = local_arr_1[aux_1 % 3];
  int stride_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_23_2 * 2)) & 127;
  int scale_42_1 = 0;
  int scale_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_42_1 = ((scale_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_42_2 = ((scale_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_42_1) & 127;
    acc_2 = (acc_2 + scale_42_2) & 127;
  }

  int damping_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_53_1 > 49)
  {
    acc_1 = ((acc_1 + (damping_53_1 * 2)) + 5) & 127;
    aux_1 ^= damping_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_53_2 > 49)
  {
    acc_2 = ((acc_2 + (damping_53_2 * 2)) + 5) & 127;
    aux_2 ^= damping_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_23_1 == stride_23_2);
  assert(scale_42_1 == scale_42_2);
  assert(damping_53_1 == damping_53_2);
}

int fn_R001955_5513_0(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int stride_23 = local_arr[aux % 3];
  acc = (acc + (stride_23 * 2)) & 127;
  int scale_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_42 = ((scale_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_42) & 127;
  }

  int damping_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_53 > 49)
  {
    acc = ((acc + (damping_53 * 2)) + 5) & 127;
    aux ^= damping_53 & 15;
  }
  else
  {
    acc = ((acc - damping_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st_1 = {0};
  struct CipherContext_R001955_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_56_1 > 38)
  {
    acc_1 = ((acc_1 + (coefficient_56_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_56_2 > 38)
  {
    acc_2 = ((acc_2 + (coefficient_56_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_49_1) & 63;
  aux_2 = (aux_2 + mask_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_98_1 = 0;
  int tracker_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_98_1 = ((tracker_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_98_2 = ((tracker_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_98_1) & 127;
    acc_2 = (acc_2 + tracker_98_2) & 127;
  }

  int tracker_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_45_1)
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

  switch (tracker_45_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_56_1 == coefficient_56_2);
  assert(mask_49_1 == mask_49_2);
  assert(tracker_98_1 == tracker_98_2);
  assert(tracker_45_1 == tracker_45_2);
}

int fn_R001955_5513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_56 > 38)
  {
    acc = ((acc + (coefficient_56 * 2)) + 5) & 127;
    aux ^= coefficient_56 & 15;
  }
  else
  {
    acc = ((acc - coefficient_56) + 11) & 127;
    aux += 3;
  }
  int mask_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_49) & 63;
  acc ^= aux;
  int tracker_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_98 = ((tracker_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_98) & 127;
  }

  int tracker_45 = (aux + st.buffer[1]) & 3;
  switch (tracker_45)
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

void fn_R001955_5513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_22_1 = local_arr_1[aux_1 % 3];
  int weight_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_22_2 * 2)) & 127;
  int anchor_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_34_1 > 42)
  {
    acc_1 = ((acc_1 + (anchor_34_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_34_2 > 42)
  {
    acc_2 = ((acc_2 + (anchor_34_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_14_1 = 0;
  int quantum_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_14_1 = ((quantum_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_14_2 = ((quantum_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_14_1) & 127;
    acc_2 = (acc_2 + quantum_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_22_1 == weight_22_2);
  assert(anchor_34_1 == anchor_34_2);
  assert(quantum_14_1 == quantum_14_2);
}

int fn_R001955_5513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_22 = local_arr[aux % 3];
  acc = (acc + (weight_22 * 2)) & 127;
  int anchor_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_34 > 42)
  {
    acc = ((acc + (anchor_34 * 2)) + 5) & 127;
    aux ^= anchor_34 & 15;
  }
  else
  {
    acc = ((acc - anchor_34) + 11) & 127;
    aux += 3;
  }
  int quantum_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_14 = ((quantum_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001955_5513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_76_1 > 20)
  {
    acc_1 = ((acc_1 + (quantum_76_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_76_2 > 20)
  {
    acc_2 = ((acc_2 + (quantum_76_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_52_1 = local_arr_1[aux_1 % 3];
  int residue_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_76_1 == quantum_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_52_1 == residue_52_2);
}

int fn_R001955_5513_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_76 > 20)
  {
    acc = ((acc + (quantum_76 * 2)) + 5) & 127;
    aux ^= quantum_76 & 15;
  }
  else
  {
    acc = ((acc - quantum_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_52 = local_arr[aux % 3];
  acc = (acc + (residue_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st_1 = {0};
  struct Transaction_R001955_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_91_1 > 49)
  {
    acc_1 = ((acc_1 + (tally_91_1 * 2)) + 5) & 127;
    aux_1 ^= tally_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_91_2 > 49)
  {
    acc_2 = ((acc_2 + (tally_91_2 * 2)) + 5) & 127;
    aux_2 ^= tally_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_16_1 = local_arr_1[aux_1 % 3];
  int coefficient_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_16_2 * 2)) & 127;
  int quotient_24_1 = 0;
  int quotient_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_24_1 = ((quotient_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_24_2 = ((quotient_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_24_1) & 127;
    acc_2 = (acc_2 + quotient_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_91_1 == tally_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_16_1 == coefficient_16_2);
  assert(quotient_24_1 == quotient_24_2);
}

int fn_R001955_5513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_91 > 49)
  {
    acc = ((acc + (tally_91 * 2)) + 5) & 127;
    aux ^= tally_91 & 15;
  }
  else
  {
    acc = ((acc - tally_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_16 = local_arr[aux % 3];
  acc = (acc + (coefficient_16 * 2)) & 127;
  int quotient_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_24 = ((quotient_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001955_5513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st_1 = {0};
  struct Transaction_R001955_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int bound_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_55_1) & 63;
  aux_2 = (aux_2 + bound_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_41_1)
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

  switch (coefficient_41_2)
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

  int delta_12_1 = 0;
  int delta_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_12_1 = ((delta_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_12_2 = ((delta_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_12_1) & 127;
    acc_2 = (acc_2 + delta_12_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_34_1 = local_arr_1[aux_1 % 3];
  int margin_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_55_1 == bound_55_2);
  assert(coefficient_41_1 == coefficient_41_2);
  assert(delta_12_1 == delta_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_34_1 == margin_34_2);
}

int fn_R001955_5513_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int bound_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_55) & 63;
  acc ^= aux;
  int coefficient_41 = (aux + st.buffer[1]) & 3;
  switch (coefficient_41)
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

  int delta_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_12 = ((delta_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_12) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int margin_34 = local_arr[aux % 3];
  acc = (acc + (margin_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int index_reg_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_44_1 > 42)
  {
    acc_1 = ((acc_1 + (index_reg_44_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_44_2 > 42)
  {
    acc_2 = ((acc_2 + (index_reg_44_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_13_1 = local_arr_1[aux_1 % 3];
  int factor_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_44_1 == index_reg_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_13_1 == factor_13_2);
}

int fn_R001955_5513_6(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int index_reg_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_44 > 42)
  {
    acc = ((acc + (index_reg_44 * 2)) + 5) & 127;
    aux ^= index_reg_44 & 15;
  }
  else
  {
    acc = ((acc - index_reg_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_13 = local_arr[aux % 3];
  acc = (acc + (factor_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_41_1 = 0;
  int weight_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_41_1 = ((weight_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_41_2 = ((weight_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_41_1) & 127;
    acc_2 = (acc_2 + weight_41_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_36_1 = local_arr_1[aux_1 % 3];
  int sample_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_36_2 * 2)) & 127;
  int tally_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_77_1) & 63;
  aux_2 = (aux_2 + tally_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_41_1 == weight_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_36_1 == sample_36_2);
  assert(tally_77_1 == tally_77_2);
}

int fn_R001955_5513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_41 = ((weight_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_41) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_36 = local_arr[aux % 3];
  acc = (acc + (sample_36 * 2)) & 127;
  int tally_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001955_5513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st_1 = {0};
  struct Transaction_R001955_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_17_1 = local_arr_1[aux_1 % 3];
  int scale_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_17_2 * 2)) & 127;
  int mask_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_82_1 > 20)
  {
    acc_1 = ((acc_1 + (mask_82_1 * 2)) + 5) & 127;
    aux_1 ^= mask_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_82_2 > 20)
  {
    acc_2 = ((acc_2 + (mask_82_2 * 2)) + 5) & 127;
    aux_2 ^= mask_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_59_1)
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

  switch (parity_59_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_17_1 == scale_17_2);
  assert(mask_82_1 == mask_82_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R001955_5513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int scale_17 = local_arr[aux % 3];
  acc = (acc + (scale_17 * 2)) & 127;
  int mask_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_82 > 20)
  {
    acc = ((acc + (mask_82 * 2)) + 5) & 127;
    aux ^= mask_82 & 15;
  }
  else
  {
    acc = ((acc - mask_82) + 11) & 127;
    aux += 3;
  }
  int parity_59 = (aux + st.buffer[1]) & 3;
  switch (parity_59)
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

void fn_R001955_5513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st_1 = {0};
  struct Transaction_R001955_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_37_1 > 22)
  {
    acc_1 = ((acc_1 + (accumulator_37_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_37_2 > 22)
  {
    acc_2 = ((acc_2 + (accumulator_37_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_31_1 = 0;
  int coefficient_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_31_1 = ((coefficient_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_31_2 = ((coefficient_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_31_1) & 127;
    acc_2 = (acc_2 + coefficient_31_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_32_1 = local_arr_1[aux_1 % 3];
  int metric_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_37_1 == accumulator_37_2);
  assert(coefficient_31_1 == coefficient_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_32_1 == metric_32_2);
}

int fn_R001955_5513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_37 > 22)
  {
    acc = ((acc + (accumulator_37 * 2)) + 5) & 127;
    aux ^= accumulator_37 & 15;
  }
  else
  {
    acc = ((acc - accumulator_37) + 11) & 127;
    aux += 3;
  }
  int coefficient_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_31 = ((coefficient_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_31) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_32 = local_arr[aux % 3];
  acc = (acc + (metric_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st_1 = {0};
  struct CipherContext_R001955_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int bound_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_55_1)
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

  switch (bound_55_2)
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

  int anchor_42_1 = 0;
  int anchor_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_42_1 = ((anchor_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_42_2 = ((anchor_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_42_1) & 127;
    acc_2 = (acc_2 + anchor_42_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_75_1) & 63;
  aux_2 = (aux_2 + accumulator_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_55_1 == bound_55_2);
  assert(anchor_42_1 == anchor_42_2);
  assert(accumulator_75_1 == accumulator_75_2);
}

int fn_R001955_5513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int bound_55 = (aux + st.buffer[1]) & 3;
  switch (bound_55)
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

  int anchor_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_42 = ((anchor_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_42) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001955_5513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_53_1) & 63;
  aux_2 = (aux_2 + vector_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_53_1 == vector_53_2);
}

int fn_R001955_5513_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001955_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st_1 = {0};
  struct CipherContext_R001955_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_23_1 = 0;
  int damping_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_23_1 = ((damping_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_23_2 = ((damping_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_23_1) & 127;
    acc_2 = (acc_2 + damping_23_2) & 127;
  }

  int tally_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_63_1) & 63;
  aux_2 = (aux_2 + tally_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_50_1 > 42)
  {
    acc_1 = ((acc_1 + (damping_50_1 * 2)) + 5) & 127;
    aux_1 ^= damping_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_50_2 > 42)
  {
    acc_2 = ((acc_2 + (damping_50_2 * 2)) + 5) & 127;
    aux_2 ^= damping_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_23_1 == damping_23_2);
  assert(tally_63_1 == tally_63_2);
  assert(damping_50_1 == damping_50_2);
}

int fn_R001955_5513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_23 = ((damping_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_23) & 127;
  }

  int tally_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_50 > 42)
  {
    acc = ((acc + (damping_50 * 2)) + 5) & 127;
    aux ^= damping_50 & 15;
  }
  else
  {
    acc = ((acc - damping_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001955_5513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st_1 = {0};
  struct CipherContext_R001955_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_57_1) & 63;
  aux_2 = (aux_2 + delta_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_36_1 = local_arr_1[aux_1 % 3];
  int metric_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_57_1 == delta_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_36_1 == metric_36_2);
}

int fn_R001955_5513_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_57) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_36 = local_arr[aux % 3];
  acc = (acc + (metric_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001955_5513_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st_1 = {0};
  struct CipherContext_R001955_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_97_1 = local_arr_1[aux_1 % 3];
  int metric_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_97_2 * 2)) & 127;
  int bound_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_63_1)
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

  switch (bound_63_2)
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

  int offset_14_1 = 0;
  int offset_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_14_1 = ((offset_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_14_2 = ((offset_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_14_1) & 127;
    acc_2 = (acc_2 + offset_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_97_1 == metric_97_2);
  assert(bound_63_1 == bound_63_2);
  assert(offset_14_1 == offset_14_2);
}

int fn_R001955_5513_14(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001955_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_97 = local_arr[aux % 3];
  acc = (acc + (metric_97 * 2)) & 127;
  int bound_63 = (aux + st.buffer[1]) & 3;
  switch (bound_63)
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

  int offset_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_14 = ((offset_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001955_5513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st_1 = {0};
  struct Transaction_R001955_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int checksum_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_63_1 > 39)
  {
    acc_1 = ((acc_1 + (checksum_63_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_63_2 > 39)
  {
    acc_2 = ((acc_2 + (checksum_63_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_80_1)
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

  switch (threshold_80_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(threshold_80_1 == threshold_80_2);
}

int fn_R001955_5513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001955_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int checksum_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_63 > 39)
  {
    acc = ((acc + (checksum_63 * 2)) + 5) & 127;
    aux ^= checksum_63 & 15;
  }
  else
  {
    acc = ((acc - checksum_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_80 = (aux + st.buffer[1]) & 3;
  switch (threshold_80)
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
  int sec_r001955_0_1;
  int sec_r001955_0_2;
  int sec_r001955_1_1;
  int sec_r001955_1_2;
  int sec_r001955_2_1;
  int sec_r001955_2_2;
  int sec_r001955_3_1;
  int sec_r001955_3_2;
  int sec_r001955_4_1;
  int sec_r001955_4_2;
  int sec_r001955_5_1;
  int sec_r001955_5_2;
  int sec_r001955_6_1;
  int sec_r001955_6_2;
  int sec_r001955_7_1;
  int sec_r001955_7_2;
  int sec_r001955_8_1;
  int sec_r001955_8_2;
  int sec_r001955_9_1;
  int sec_r001955_9_2;
  int sec_r001955_10_1;
  int sec_r001955_10_2;
  int sec_r001955_11_1;
  int sec_r001955_11_2;
  int sec_r001955_12_1;
  int sec_r001955_12_2;
  int sec_r001955_13_1;
  int sec_r001955_13_2;
  int sec_r001955_14_1;
  int sec_r001955_14_2;
  int sec_r001955_15_1;
  int sec_r001955_15_2;
  int sec_r001955_16_1;
  int sec_r001955_16_2;
  int sec_r001955_17_1;
  int sec_r001955_17_2;
  int pub_r001955_0_1;
  int pub_r001955_0_2;
  int pub_r001955_1_1;
  int pub_r001955_1_2;
  int pub_r001955_2_1;
  int pub_r001955_2_2;
  int pub_r001955_3_1;
  int pub_r001955_3_2;
  int pub_r001955_4_1;
  int pub_r001955_4_2;
  int pub_r001955_5_1;
  int pub_r001955_5_2;
  int pub_r001955_6_1;
  int pub_r001955_6_2;
  int pub_r001955_7_1;
  int pub_r001955_7_2;
  int pub_r001955_8_1;
  int pub_r001955_8_2;
  int pub_r001955_9_1;
  int pub_r001955_9_2;
  int pub_r001955_10_1;
  int pub_r001955_10_2;
  int pub_r001955_11_1;
  int pub_r001955_11_2;
  int pub_r001955_12_1;
  int pub_r001955_12_2;
  int pub_r001955_13_1;
  int pub_r001955_13_2;
  int pub_r001955_14_1;
  int pub_r001955_14_2;
  int pub_r001955_15_1;
  int pub_r001955_15_2;
  int pub_r001955_16_1;
  int pub_r001955_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001955_0_1 >= (-100)) && (pub_r001955_0_1 <= 100));
  __CPROVER_assume((pub_r001955_0_2 >= (-100)) && (pub_r001955_0_2 <= 100));
  __CPROVER_assume((pub_r001955_1_1 >= (-100)) && (pub_r001955_1_1 <= 100));
  __CPROVER_assume((pub_r001955_1_2 >= (-100)) && (pub_r001955_1_2 <= 100));
  __CPROVER_assume((pub_r001955_2_1 >= (-100)) && (pub_r001955_2_1 <= 100));
  __CPROVER_assume((pub_r001955_2_2 >= (-100)) && (pub_r001955_2_2 <= 100));
  __CPROVER_assume((pub_r001955_3_1 >= (-100)) && (pub_r001955_3_1 <= 100));
  __CPROVER_assume((pub_r001955_3_2 >= (-100)) && (pub_r001955_3_2 <= 100));
  __CPROVER_assume((pub_r001955_4_1 >= (-100)) && (pub_r001955_4_1 <= 100));
  __CPROVER_assume((pub_r001955_4_2 >= (-100)) && (pub_r001955_4_2 <= 100));
  __CPROVER_assume((pub_r001955_5_1 >= (-100)) && (pub_r001955_5_1 <= 100));
  __CPROVER_assume((pub_r001955_5_2 >= (-100)) && (pub_r001955_5_2 <= 100));
  __CPROVER_assume((pub_r001955_6_1 >= (-100)) && (pub_r001955_6_1 <= 100));
  __CPROVER_assume((pub_r001955_6_2 >= (-100)) && (pub_r001955_6_2 <= 100));
  __CPROVER_assume((pub_r001955_7_1 >= (-100)) && (pub_r001955_7_1 <= 100));
  __CPROVER_assume((pub_r001955_7_2 >= (-100)) && (pub_r001955_7_2 <= 100));
  __CPROVER_assume((pub_r001955_8_1 >= (-100)) && (pub_r001955_8_1 <= 100));
  __CPROVER_assume((pub_r001955_8_2 >= (-100)) && (pub_r001955_8_2 <= 100));
  __CPROVER_assume((pub_r001955_9_1 >= (-100)) && (pub_r001955_9_1 <= 100));
  __CPROVER_assume((pub_r001955_9_2 >= (-100)) && (pub_r001955_9_2 <= 100));
  __CPROVER_assume((pub_r001955_10_1 >= (-100)) && (pub_r001955_10_1 <= 100));
  __CPROVER_assume((pub_r001955_10_2 >= (-100)) && (pub_r001955_10_2 <= 100));
  __CPROVER_assume((pub_r001955_11_1 >= (-100)) && (pub_r001955_11_1 <= 100));
  __CPROVER_assume((pub_r001955_11_2 >= (-100)) && (pub_r001955_11_2 <= 100));
  __CPROVER_assume((pub_r001955_12_1 >= (-100)) && (pub_r001955_12_1 <= 100));
  __CPROVER_assume((pub_r001955_12_2 >= (-100)) && (pub_r001955_12_2 <= 100));
  __CPROVER_assume((pub_r001955_13_1 >= (-100)) && (pub_r001955_13_1 <= 100));
  __CPROVER_assume((pub_r001955_13_2 >= (-100)) && (pub_r001955_13_2 <= 100));
  __CPROVER_assume((pub_r001955_14_1 >= (-100)) && (pub_r001955_14_1 <= 100));
  __CPROVER_assume((pub_r001955_14_2 >= (-100)) && (pub_r001955_14_2 <= 100));
  __CPROVER_assume((pub_r001955_15_1 >= (-100)) && (pub_r001955_15_1 <= 100));
  __CPROVER_assume((pub_r001955_15_2 >= (-100)) && (pub_r001955_15_2 <= 100));
  __CPROVER_assume((pub_r001955_16_1 >= (-100)) && (pub_r001955_16_1 <= 100));
  __CPROVER_assume((pub_r001955_16_2 >= (-100)) && (pub_r001955_16_2 <= 100));
  __CPROVER_assume((sec_r001955_0_1 >= 0) && (sec_r001955_0_1 <= 255));
  __CPROVER_assume((sec_r001955_0_2 >= 0) && (sec_r001955_0_2 <= 255));
  __CPROVER_assume((sec_r001955_1_1 >= 0) && (sec_r001955_1_1 <= 255));
  __CPROVER_assume((sec_r001955_1_2 >= 0) && (sec_r001955_1_2 <= 255));
  __CPROVER_assume((sec_r001955_2_1 >= 0) && (sec_r001955_2_1 <= 255));
  __CPROVER_assume((sec_r001955_2_2 >= 0) && (sec_r001955_2_2 <= 255));
  __CPROVER_assume((sec_r001955_3_1 >= 0) && (sec_r001955_3_1 <= 255));
  __CPROVER_assume((sec_r001955_3_2 >= 0) && (sec_r001955_3_2 <= 255));
  __CPROVER_assume((sec_r001955_4_1 >= 0) && (sec_r001955_4_1 <= 255));
  __CPROVER_assume((sec_r001955_4_2 >= 0) && (sec_r001955_4_2 <= 255));
  __CPROVER_assume((sec_r001955_5_1 >= 0) && (sec_r001955_5_1 <= 255));
  __CPROVER_assume((sec_r001955_5_2 >= 0) && (sec_r001955_5_2 <= 255));
  __CPROVER_assume((sec_r001955_6_1 >= 0) && (sec_r001955_6_1 <= 255));
  __CPROVER_assume((sec_r001955_6_2 >= 0) && (sec_r001955_6_2 <= 255));
  __CPROVER_assume((sec_r001955_7_1 >= 0) && (sec_r001955_7_1 <= 255));
  __CPROVER_assume((sec_r001955_7_2 >= 0) && (sec_r001955_7_2 <= 255));
  __CPROVER_assume((sec_r001955_8_1 >= 0) && (sec_r001955_8_1 <= 255));
  __CPROVER_assume((sec_r001955_8_2 >= 0) && (sec_r001955_8_2 <= 255));
  __CPROVER_assume((sec_r001955_9_1 >= 0) && (sec_r001955_9_1 <= 255));
  __CPROVER_assume((sec_r001955_9_2 >= 0) && (sec_r001955_9_2 <= 255));
  __CPROVER_assume((sec_r001955_10_1 >= 0) && (sec_r001955_10_1 <= 255));
  __CPROVER_assume((sec_r001955_10_2 >= 0) && (sec_r001955_10_2 <= 255));
  __CPROVER_assume((sec_r001955_11_1 >= 0) && (sec_r001955_11_1 <= 255));
  __CPROVER_assume((sec_r001955_11_2 >= 0) && (sec_r001955_11_2 <= 255));
  __CPROVER_assume((sec_r001955_12_1 >= 0) && (sec_r001955_12_1 <= 255));
  __CPROVER_assume((sec_r001955_12_2 >= 0) && (sec_r001955_12_2 <= 255));
  __CPROVER_assume((sec_r001955_13_1 >= 0) && (sec_r001955_13_1 <= 255));
  __CPROVER_assume((sec_r001955_13_2 >= 0) && (sec_r001955_13_2 <= 255));
  __CPROVER_assume((sec_r001955_14_1 >= 0) && (sec_r001955_14_1 <= 255));
  __CPROVER_assume((sec_r001955_14_2 >= 0) && (sec_r001955_14_2 <= 255));
  __CPROVER_assume((sec_r001955_15_1 >= 0) && (sec_r001955_15_1 <= 255));
  __CPROVER_assume((sec_r001955_15_2 >= 0) && (sec_r001955_15_2 <= 255));
  __CPROVER_assume((sec_r001955_16_1 >= 0) && (sec_r001955_16_1 <= 255));
  __CPROVER_assume((sec_r001955_16_2 >= 0) && (sec_r001955_16_2 <= 255));
  __CPROVER_assume((sec_r001955_17_1 >= 0) && (sec_r001955_17_1 <= 255));
  __CPROVER_assume((sec_r001955_17_2 >= 0) && (sec_r001955_17_2 <= 255));
  struct Transaction_R001955_5513_0 st_var_0_1 = {0};
  struct Transaction_R001955_5513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001955_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001955_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001955_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001955_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001955_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001955_0_2 + 7) & 15;
  struct StreamBuffer_R001955_5513_1 st_var_1_1 = {0};
  struct StreamBuffer_R001955_5513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001955_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001955_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001955_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001955_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001955_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001955_0_2 + 9) & 15;
  struct CipherContext_R001955_5513_2 st_var_2_1 = {0};
  struct CipherContext_R001955_5513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001955_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001955_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001955_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001955_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001955_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001955_0_2 + 11) & 15;
  union RegisterBank_R001955_5513_0 u_var_1;
  union RegisterBank_R001955_5513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001955_5513_0(sec_r001955_0_1, sec_r001955_1_1);
  int helper_flow_0_2 = fn_R001955_5513_0(sec_r001955_0_2, sec_r001955_1_2);
  fn_R001955_5513_0_2(sec_r001955_0_1, sec_r001955_1_1, sec_r001955_0_2, sec_r001955_1_2);
  int helper_flow_1_1 = fn_R001955_5513_1(sec_r001955_1_1, pub_r001955_2_1, pub_r001955_3_1, pub_r001955_4_1, pub_r001955_5_1);
  int helper_flow_1_2 = fn_R001955_5513_1(sec_r001955_1_2, pub_r001955_2_2, pub_r001955_3_2, pub_r001955_4_2, pub_r001955_5_2);
  fn_R001955_5513_1_2(sec_r001955_1_1, pub_r001955_2_1, pub_r001955_3_1, pub_r001955_4_1, pub_r001955_5_1, sec_r001955_1_2, pub_r001955_2_2, pub_r001955_3_2, pub_r001955_4_2, pub_r001955_5_2);
  int helper_flow_2_1 = fn_R001955_5513_2(sec_r001955_2_1, sec_r001955_3_1, pub_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1);
  int helper_flow_2_2 = fn_R001955_5513_2(sec_r001955_2_2, sec_r001955_3_2, pub_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2);
  fn_R001955_5513_2_2(sec_r001955_2_1, sec_r001955_3_1, pub_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1, sec_r001955_2_2, sec_r001955_3_2, pub_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2);
  int helper_flow_3_1 = fn_R001955_5513_3(sec_r001955_3_1, sec_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1, pub_r001955_7_1);
  int helper_flow_3_2 = fn_R001955_5513_3(sec_r001955_3_2, sec_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2, pub_r001955_7_2);
  fn_R001955_5513_3_2(sec_r001955_3_1, sec_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1, pub_r001955_7_1, sec_r001955_3_2, sec_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2, pub_r001955_7_2);
  int helper_flow_4_1 = fn_R001955_5513_4(sec_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1, pub_r001955_7_1, pub_r001955_8_1);
  int helper_flow_4_2 = fn_R001955_5513_4(sec_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2, pub_r001955_7_2, pub_r001955_8_2);
  fn_R001955_5513_4_2(sec_r001955_4_1, pub_r001955_5_1, pub_r001955_6_1, pub_r001955_7_1, pub_r001955_8_1, sec_r001955_4_2, pub_r001955_5_2, pub_r001955_6_2, pub_r001955_7_2, pub_r001955_8_2);
  int helper_flow_5_1 = fn_R001955_5513_5(sec_r001955_5_1, sec_r001955_6_1, pub_r001955_7_1, pub_r001955_8_1, pub_r001955_9_1);
  int helper_flow_5_2 = fn_R001955_5513_5(sec_r001955_5_2, sec_r001955_6_2, pub_r001955_7_2, pub_r001955_8_2, pub_r001955_9_2);
  fn_R001955_5513_5_2(sec_r001955_5_1, sec_r001955_6_1, pub_r001955_7_1, pub_r001955_8_1, pub_r001955_9_1, sec_r001955_5_2, sec_r001955_6_2, pub_r001955_7_2, pub_r001955_8_2, pub_r001955_9_2);
  int helper_flow_6_1 = fn_R001955_5513_6(sec_r001955_6_1, pub_r001955_7_1);
  int helper_flow_6_2 = fn_R001955_5513_6(sec_r001955_6_2, pub_r001955_7_2);
  fn_R001955_5513_6_2(sec_r001955_6_1, pub_r001955_7_1, sec_r001955_6_2, pub_r001955_7_2);
  int stage_v_0_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((helper_flow_0_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_1_2 = ((helper_flow_0_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((sec_r001955_8_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001955_8_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001955_14_1 * 2) + 13) & 63;
  int stage_v_3_2 = ((pub_r001955_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001955_7_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001955_7_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((sec_r001955_4_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_5_2 = ((sec_r001955_4_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((pub_r001955_14_1 * 2) + 47) & 63;
  int stage_v_6_2 = ((pub_r001955_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001955_3_1 * 2) + 7) & 63;
  int stage_v_7_2 = ((pub_r001955_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001955_1_1 * 2) + 47) & 63;
  int stage_v_8_2 = ((pub_r001955_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001955_3_1 * 2) + 18) & 63;
  int stage_v_9_2 = ((pub_r001955_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001955_6_1 * 2) + 6) & 63;
  int stage_v_10_2 = ((pub_r001955_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001955_10_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001955_10_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((pub_r001955_12_1 * 2) + 31) & 63;
  int stage_v_12_2 = ((pub_r001955_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001955_7_1 * 2) + 50) & 63;
  int stage_v_13_2 = ((pub_r001955_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001955_11_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001955_11_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((helper_flow_2_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_15_2 = ((helper_flow_2_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001955_10_1 * 2) + 28) & 63;
  int stage_v_16_2 = ((pub_r001955_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((helper_flow_1_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_17_2 = ((helper_flow_1_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((pub_r001955_1_1 * 2) + 45) & 63;
  int stage_v_18_2 = ((pub_r001955_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((sec_r001955_11_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_19_2 = ((sec_r001955_11_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((pub_r001955_5_1 * 2) + 23) & 63;
  int stage_v_20_2 = ((pub_r001955_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001955_2_1 * 2) + 11) & 63;
  int stage_v_21_2 = ((pub_r001955_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_2_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_22_2 = ((helper_flow_2_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((sec_r001955_13_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_23_2 = ((sec_r001955_13_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((stage_v_0_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_24_2 = ((stage_v_0_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((stage_v_5_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_25_2 = ((stage_v_5_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((stage_v_11_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_26_2 = ((stage_v_11_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((sec_r001955_14_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_27_2 = ((sec_r001955_14_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001955_5_1 * 2) + 20) & 63;
  int stage_v_28_2 = ((pub_r001955_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001955_7_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001955_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((stage_v_11_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_30_2 = ((stage_v_11_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((pub_r001955_2_1 * 2) + 34) & 63;
  int stage_v_31_2 = ((pub_r001955_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001955_11_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001955_11_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((pub_r001955_7_1 * 2) + 18) & 63;
  int stage_v_33_2 = ((pub_r001955_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001955_4_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001955_4_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001955_3_1 * 2) + 14) & 63;
  int stage_v_35_2 = ((pub_r001955_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001955_13_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001955_13_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_37_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((stage_v_25_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_38_2 = ((stage_v_25_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((pub_r001955_1_1 * 2) + 15) & 63;
  int stage_v_39_2 = ((pub_r001955_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001955_2_1 * 2) + 41) & 63;
  int stage_v_40_2 = ((pub_r001955_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_17_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_17_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((pub_r001955_16_1 * 2) + 5) & 63;
  int stage_v_42_2 = ((pub_r001955_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((sec_r001955_1_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_43_2 = ((sec_r001955_1_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_27_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_27_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001955_12_1 * 2) + 38) & 63;
  int stage_v_45_2 = ((pub_r001955_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_0_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_0_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001955_2_1 * 2) + 10) & 63;
  int stage_v_47_2 = ((pub_r001955_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001955_0_1 * 2) + 26) & 63;
  int stage_v_48_2 = ((pub_r001955_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001955_2_1 * 2) + 31) & 63;
  int stage_v_49_2 = ((pub_r001955_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001955_12_1 * 2) + 49) & 63;
  int stage_v_50_2 = ((pub_r001955_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001955_15_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_51_2 = ((sec_r001955_15_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((sec_r001955_10_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001955_10_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001955_13_1 * 2) + 34) & 63;
  int stage_v_53_2 = ((pub_r001955_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((sec_r001955_6_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_54_2 = ((sec_r001955_6_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001955_0_1 * 2) + 49) & 63;
  int stage_v_55_2 = ((pub_r001955_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((helper_flow_5_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_56_2 = ((helper_flow_5_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((pub_r001955_9_1 * 2) + 49) & 63;
  int stage_v_57_2 = ((pub_r001955_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((sec_r001955_3_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_58_2 = ((sec_r001955_3_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((pub_r001955_4_1 * 2) + 35) & 63;
  int stage_v_59_2 = ((pub_r001955_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((sec_r001955_9_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_60_2 = ((sec_r001955_9_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_44_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_44_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((pub_r001955_4_1 * 2) + 44) & 63;
  int stage_v_62_2 = ((pub_r001955_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001955_4_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_63_2 = ((sec_r001955_4_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((sec_r001955_5_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_64_2 = ((sec_r001955_5_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((stage_v_24_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_24_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001955_12_1 * 2) + 16) & 63;
  int stage_v_66_2 = ((pub_r001955_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001955_3_1 * 2) + 19) & 63;
  int stage_v_67_2 = ((pub_r001955_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001955_15_1 * 2) + 40) & 63;
  int stage_v_68_2 = ((pub_r001955_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_17_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_17_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((sec_r001955_9_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_70_2 = ((sec_r001955_9_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001955_7_1 * 2) + 38) & 63;
  int stage_v_71_2 = ((pub_r001955_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001955_14_1 * 2) + 40) & 63;
  int stage_v_72_2 = ((pub_r001955_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001955_3_1 * 2) + 46) & 63;
  int stage_v_73_2 = ((pub_r001955_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001955_2_1 * 2) + 36) & 63;
  int stage_v_74_2 = ((pub_r001955_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001955_12_1 * 2) + 33) & 63;
  int stage_v_75_2 = ((pub_r001955_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_51_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_51_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((sec_r001955_2_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_77_2 = ((sec_r001955_2_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001955_14_1 * 2) + 24) & 63;
  int stage_v_78_2 = ((pub_r001955_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001955_0_1 * 2) + 27) & 63;
  int stage_v_79_2 = ((pub_r001955_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001955_0_1 * 2) + 38) & 63;
  int stage_v_80_2 = ((pub_r001955_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001955_12_1 * 2) + 22) & 63;
  int stage_v_81_2 = ((pub_r001955_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001955_12_1 * 2) + 36) & 63;
  int stage_v_82_2 = ((pub_r001955_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_30_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_83_2 = ((stage_v_30_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((stage_v_2_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_2_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((stage_v_37_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_37_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((pub_r001955_13_1 * 2) + 37) & 63;
  int stage_v_86_2 = ((pub_r001955_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001955_11_1 * 2) + 8) & 63;
  int stage_v_87_2 = ((pub_r001955_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001955_7_1 * 2) + 39) & 63;
  int stage_v_88_2 = ((pub_r001955_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_19_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_19_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((stage_v_43_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_43_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((stage_v_4_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_91_2 = ((stage_v_4_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((stage_v_26_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_26_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((stage_v_90_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_90_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((stage_v_25_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_25_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((sec_r001955_2_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_95_2 = ((sec_r001955_2_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((pub_r001955_10_1 * 2) + 17) & 63;
  int stage_v_96_2 = ((pub_r001955_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_54_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_54_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((pub_r001955_16_1 * 2) + 15) & 63;
  int stage_v_98_2 = ((pub_r001955_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_19_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_19_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((stage_v_2_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_2_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((pub_r001955_10_1 * 2) + 26) & 63;
  int stage_v_101_2 = ((pub_r001955_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_100_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_100_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((sec_r001955_12_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_103_2 = ((sec_r001955_12_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((stage_v_93_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_93_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((stage_v_54_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_105_2 = ((stage_v_54_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((sec_r001955_3_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_106_2 = ((sec_r001955_3_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((stage_v_91_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_91_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001955_12_1 * 2) + 49) & 63;
  int stage_v_108_2 = ((pub_r001955_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_25_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_25_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((stage_v_77_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_77_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((stage_v_85_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_85_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((stage_v_54_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_112_2 = ((stage_v_54_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_4_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_4_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((stage_v_104_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_114_2 = ((stage_v_104_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_89_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_89_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001955_9_1 * 2) + 37) & 63;
  int stage_v_116_2 = ((pub_r001955_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((sec_r001955_5_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001955_5_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((stage_v_117_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_117_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((pub_r001955_10_1 * 2) + 42) & 63;
  int stage_v_119_2 = ((pub_r001955_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_22_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_22_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((pub_r001955_9_1 * 2) + 26) & 63;
  int stage_v_121_2 = ((pub_r001955_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001955_15_1 * 2) + 16) & 63;
  int stage_v_122_2 = ((pub_r001955_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((sec_r001955_8_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_123_2 = ((sec_r001955_8_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((stage_v_105_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_105_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((stage_v_14_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_14_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_54_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_54_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((pub_r001955_6_1 * 2) + 28) & 63;
  int stage_v_127_2 = ((pub_r001955_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_99_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_99_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_43_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_43_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001955_0_1 * 2) + 14) & 63;
  int stage_v_130_2 = ((pub_r001955_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_0_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_0_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((helper_flow_5_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_132_2 = ((helper_flow_5_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((stage_v_26_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_26_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001955_10_1 * 2) + 14) & 63;
  int stage_v_134_2 = ((pub_r001955_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001955_16_1 * 2) + 33) & 63;
  int stage_v_135_2 = ((pub_r001955_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_104_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_104_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001955_14_1 * 2) + 8) & 63;
  int stage_v_137_2 = ((pub_r001955_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001955_14_1 * 2) + 12) & 63;
  int stage_v_138_2 = ((pub_r001955_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_76_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_76_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((pub_r001955_5_1 * 2) + 29) & 63;
  int stage_v_140_2 = ((pub_r001955_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_128_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_128_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_64_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_64_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((stage_v_105_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_143_2 = ((stage_v_105_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_144_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_84_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_84_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_23_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_23_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((sec_r001955_15_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_147_2 = ((sec_r001955_15_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((sec_r001955_15_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_148_2 = ((sec_r001955_15_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((pub_r001955_14_1 * 2) + 30) & 63;
  int stage_v_149_2 = ((pub_r001955_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_90_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_90_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((stage_v_15_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_15_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((stage_v_41_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_41_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((stage_v_92_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_92_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((stage_v_114_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_114_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_15_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_15_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001955_7_1 * 2) + 19) & 63;
  int stage_v_156_2 = ((pub_r001955_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001955_9_1 * 2) + 31) & 63;
  int stage_v_157_2 = ((pub_r001955_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001955_6_1 * 2) + 8) & 63;
  int stage_v_158_2 = ((pub_r001955_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_51_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_51_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001955_4_1 * 2) + 20) & 63;
  int stage_v_160_2 = ((pub_r001955_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_15_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_15_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((stage_v_0_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_0_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001955_2_1 * 2) + 29) & 63;
  int stage_v_163_2 = ((pub_r001955_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_114_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_114_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((stage_v_11_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_11_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_139_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_139_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_27_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_27_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((stage_v_106_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_106_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((helper_flow_3_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_169_2 = ((helper_flow_3_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_104_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_104_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001955_3_1 * 2) + 37) & 63;
  int stage_v_171_2 = ((pub_r001955_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001955_5_1 * 2) + 48) & 63;
  int stage_v_172_2 = ((pub_r001955_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001955_10_1 * 2) + 6) & 63;
  int stage_v_173_2 = ((pub_r001955_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_69_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_69_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_167_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_167_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((pub_r001955_1_1 * 2) + 16) & 63;
  int stage_v_176_2 = ((pub_r001955_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_30_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_177_2 = ((stage_v_30_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((helper_flow_6_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_178_2 = ((helper_flow_6_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_154_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_154_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((pub_r001955_3_1 * 2) + 48) & 63;
  int stage_v_180_2 = ((pub_r001955_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001955_3_1 * 2) + 42) & 63;
  int stage_v_181_2 = ((pub_r001955_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001955_13_1 * 2) + 47) & 63;
  int stage_v_182_2 = ((pub_r001955_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_107_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_107_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001955_5_1 * 2) + 29) & 63;
  int stage_v_184_2 = ((pub_r001955_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_114_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_114_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001955_6_1 * 2) + 38) & 63;
  int stage_v_186_2 = ((pub_r001955_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001955_2_1 * 2) + 9) & 63;
  int stage_v_187_2 = ((pub_r001955_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((stage_v_51_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_51_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((helper_flow_1_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_189_2 = ((helper_flow_1_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_189_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_189_2 + 1) & 15;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = ((stage_v_166_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_190_2 = ((stage_v_166_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_179_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_179_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_192_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((stage_v_44_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_44_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_194_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001955_7_1 * 2) + 10) & 63;
  int stage_v_195_2 = ((pub_r001955_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_15_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_15_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((sec_r001955_16_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_197_2 = ((sec_r001955_16_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((stage_v_185_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_185_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((pub_r001955_11_1 * 2) + 24) & 63;
  int stage_v_199_2 = ((pub_r001955_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_15_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_15_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((stage_v_70_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_70_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_179_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_179_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((stage_v_189_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_189_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((stage_v_113_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_113_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((pub_r001955_11_1 * 2) + 7) & 63;
  int stage_v_205_2 = ((pub_r001955_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001955_12_1 * 2) + 33) & 63;
  int stage_v_206_2 = ((pub_r001955_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001955_5_1 * 2) + 34) & 63;
  int stage_v_207_2 = ((pub_r001955_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001955_3_1 * 2) + 21) & 63;
  int stage_v_208_2 = ((pub_r001955_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_104_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_104_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((stage_v_37_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_37_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_192_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_192_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001955_16_1 * 2) + 33) & 63;
  int stage_v_212_2 = ((pub_r001955_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_107_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_107_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001955_5_1 * 2) + 10) & 63;
  int stage_v_214_2 = ((pub_r001955_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001955_13_1 * 2) + 19) & 63;
  int stage_v_215_2 = ((pub_r001955_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001955_12_1 * 2) + 9) & 63;
  int stage_v_216_2 = ((pub_r001955_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001955_13_1 * 2) + 21) & 63;
  int stage_v_217_2 = ((pub_r001955_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_2_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_2_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((stage_v_54_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_54_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001955_12_1 * 2) + 41) & 63;
  int stage_v_220_2 = ((pub_r001955_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001955_10_1 * 2) + 34) & 63;
  int stage_v_221_2 = ((pub_r001955_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001955_7_1 * 2) + 50) & 63;
  int stage_v_222_2 = ((pub_r001955_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001955_3_1 * 2) + 41) & 63;
  int stage_v_223_2 = ((pub_r001955_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_84_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_84_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((stage_v_0_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_0_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001955_12_1 * 2) + 40) & 63;
  int stage_v_226_2 = ((pub_r001955_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_24_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_24_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((pub_r001955_8_1 * 2) + 44) & 63;
  int stage_v_228_2 = ((pub_r001955_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001955_6_1 * 2) + 27) & 63;
  int stage_v_229_2 = ((pub_r001955_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001955_0_1 * 2) + 45) & 63;
  int stage_v_230_2 = ((pub_r001955_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_61_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_61_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((stage_v_107_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_107_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((pub_r001955_15_1 * 2) + 9) & 63;
  int stage_v_233_2 = ((pub_r001955_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001955_15_1 * 2) + 17) & 63;
  int stage_v_234_2 = ((pub_r001955_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001955_8_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_235_2 = ((sec_r001955_8_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((pub_r001955_12_1 * 2) + 48) & 63;
  int stage_v_236_2 = ((pub_r001955_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((sec_r001955_9_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_237_2 = ((sec_r001955_9_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((pub_r001955_10_1 * 2) + 17) & 63;
  int stage_v_238_2 = ((pub_r001955_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001955_9_1 * 2) + 15) & 63;
  int stage_v_239_2 = ((pub_r001955_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((sec_r001955_10_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_240_2 = ((sec_r001955_10_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((sec_r001955_12_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_241_2 = ((sec_r001955_12_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001955_4_1 * 2) + 37) & 63;
  int stage_v_242_2 = ((pub_r001955_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_235_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_235_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001955_12_1 * 2) + 17) & 63;
  int stage_v_244_2 = ((pub_r001955_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001955_8_1 * 2) + 50) & 63;
  int stage_v_245_2 = ((pub_r001955_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((helper_flow_2_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_246_2 = ((helper_flow_2_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((pub_r001955_8_1 * 2) + 21) & 63;
  int stage_v_247_2 = ((pub_r001955_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001955_7_1 * 2) + 48) & 63;
  int stage_v_248_2 = ((pub_r001955_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_91_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_91_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((sec_r001955_16_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_250_2 = ((sec_r001955_16_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((pub_r001955_5_1 * 2) + 37) & 63;
  int stage_v_251_2 = ((pub_r001955_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001955_16_1 * 2) + 40) & 63;
  int stage_v_252_2 = ((pub_r001955_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001955_15_1 * 2) + 34) & 63;
  int stage_v_253_2 = ((pub_r001955_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((stage_v_178_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_178_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((pub_r001955_5_1 * 2) + 17) & 63;
  int stage_v_255_2 = ((pub_r001955_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((sec_r001955_5_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_256_2 = ((sec_r001955_5_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_91_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_91_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_243_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_243_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((stage_v_1_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_1_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_200_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_200_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((stage_v_126_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_126_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((sec_r001955_9_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_262_2 = ((sec_r001955_9_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((pub_r001955_16_1 * 2) + 11) & 63;
  int stage_v_263_2 = ((pub_r001955_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_19_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_19_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_237_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_237_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001955_16_1 * 2) + 9) & 63;
  int stage_v_266_2 = ((pub_r001955_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001955_8_1 * 2) + 12) & 63;
  int stage_v_267_2 = ((pub_r001955_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001955_1_1 * 2) + 8) & 63;
  int stage_v_268_2 = ((pub_r001955_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_41_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_41_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((pub_r001955_12_1 * 2) + 41) & 63;
  int stage_v_270_2 = ((pub_r001955_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((stage_v_106_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_106_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((stage_v_52_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_52_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_14_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_14_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001955_1_1 * 2) + 21) & 63;
  int stage_v_274_2 = ((pub_r001955_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((sec_r001955_0_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_275_2 = ((sec_r001955_0_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((sec_r001955_14_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_276_2 = ((sec_r001955_14_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_120_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_120_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((stage_v_84_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_84_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((stage_v_38_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_38_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((stage_v_178_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_178_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001955_2_1 * 2) + 10) & 63;
  int stage_v_281_2 = ((pub_r001955_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001955_12_1 * 2) + 14) & 63;
  int stage_v_282_2 = ((pub_r001955_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001955_2_1 * 2) + 13) & 63;
  int stage_v_283_2 = ((pub_r001955_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((stage_v_56_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_56_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001955_8_1 * 2) + 25) & 63;
  int stage_v_285_2 = ((pub_r001955_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001955_15_1 * 2) + 35) & 63;
  int stage_v_286_2 = ((pub_r001955_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001955_6_1 * 2) + 25) & 63;
  int stage_v_287_2 = ((pub_r001955_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001955_0_1 * 2) + 18) & 63;
  int stage_v_288_2 = ((pub_r001955_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_26_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_26_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((sec_r001955_3_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_290_2 = ((sec_r001955_3_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((helper_flow_2_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_291_2 = ((helper_flow_2_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((stage_v_24_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_24_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((pub_r001955_0_1 * 2) + 27) & 63;
  int stage_v_293_2 = ((pub_r001955_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((stage_v_167_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_167_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((sec_r001955_12_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_295_2 = ((sec_r001955_12_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((helper_flow_6_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_296_2 = ((helper_flow_6_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((pub_r001955_0_1 * 2) + 35) & 63;
  int stage_v_297_2 = ((pub_r001955_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001955_3_1 * 2) + 25) & 63;
  int stage_v_298_2 = ((pub_r001955_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001955_3_1 * 2) + 10) & 63;
  int stage_v_299_2 = ((pub_r001955_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((stage_v_150_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_150_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001955_4_1 * 2) + 25) & 63;
  int stage_v_301_2 = ((pub_r001955_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001955_2_1 * 2) + 41) & 63;
  int stage_v_302_2 = ((pub_r001955_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((stage_v_105_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_105_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001955_6_1 * 2) + 15) & 63;
  int stage_v_304_2 = ((pub_r001955_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((stage_v_225_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_225_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((sec_r001955_5_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_306_2 = ((sec_r001955_5_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001955_12_1 * 2) + 40) & 63;
  int stage_v_307_2 = ((pub_r001955_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_153_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_153_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001955_3_1 * 2) + 50) & 63;
  int stage_v_309_2 = ((pub_r001955_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001955_5_1 * 2) + 15) & 63;
  int stage_v_310_2 = ((pub_r001955_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((stage_v_125_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_125_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_249_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_249_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_129_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_129_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((stage_v_65_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_314_2 = ((stage_v_65_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_314_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_314_2 + 1) & 15;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = ((stage_v_65_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_65_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((pub_r001955_6_1 * 2) + 21) & 63;
  int stage_v_316_2 = ((pub_r001955_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((stage_v_300_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_300_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_100_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_100_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_305_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_305_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((sec_r001955_17_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_320_2 = ((sec_r001955_17_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((stage_v_188_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_188_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((stage_v_4_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_4_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_191_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_191_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001955_4_1 * 2) + 39) & 63;
  int stage_v_324_2 = ((pub_r001955_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((stage_v_165_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_165_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((stage_v_311_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_311_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((pub_r001955_1_1 * 2) + 49) & 63;
  int stage_v_327_2 = ((pub_r001955_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((stage_v_84_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_84_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((stage_v_262_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_262_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((stage_v_104_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_104_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001955_14_1 * 2) + 13) & 63;
  int stage_v_331_2 = ((pub_r001955_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001955_5_1 * 2) + 42) & 63;
  int stage_v_332_2 = ((pub_r001955_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((helper_flow_2_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_333_2 = ((helper_flow_2_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((pub_r001955_12_1 * 2) + 31) & 63;
  int stage_v_334_2 = ((pub_r001955_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_164_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_164_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001955_16_1 * 2) + 18) & 63;
  int stage_v_336_2 = ((pub_r001955_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001955_13_1 * 2) + 41) & 63;
  int stage_v_337_2 = ((pub_r001955_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_169_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_169_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((stage_v_218_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_218_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((sec_r001955_4_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_340_2 = ((sec_r001955_4_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_147_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_147_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((stage_v_200_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_200_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((sec_r001955_2_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_343_2 = ((sec_r001955_2_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001955_2_1 * 2) + 38) & 63;
  int stage_v_344_2 = ((pub_r001955_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((stage_v_128_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_128_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((pub_r001955_0_1 * 2) + 27) & 63;
  int stage_v_346_2 = ((pub_r001955_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((stage_v_317_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_317_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((pub_r001955_1_1 * 2) + 33) & 63;
  int stage_v_348_2 = ((pub_r001955_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001955_2_1 * 2) + 36) & 63;
  int stage_v_349_2 = ((pub_r001955_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((sec_r001955_16_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_350_2 = ((sec_r001955_16_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_312_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_312_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((pub_r001955_1_1 * 2) + 17) & 63;
  int stage_v_352_2 = ((pub_r001955_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((stage_v_147_1 << 1) ^ (pub_r001955_5_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_147_2 << 1) ^ (pub_r001955_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((pub_r001955_11_1 * 2) + 11) & 63;
  int stage_v_354_2 = ((pub_r001955_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((sec_r001955_5_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_355_2 = ((sec_r001955_5_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((stage_v_280_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_280_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((stage_v_129_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_129_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001955_10_1 * 2) + 17) & 63;
  int stage_v_358_2 = ((pub_r001955_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001955_14_1 * 2) + 25) & 63;
  int stage_v_359_2 = ((pub_r001955_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((sec_r001955_2_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_360_2 = ((sec_r001955_2_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001955_8_1 * 2) + 14) & 63;
  int stage_v_361_2 = ((pub_r001955_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_23_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_23_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_271_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_271_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_120_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_120_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_142_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_142_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((pub_r001955_0_1 * 2) + 16) & 63;
  int stage_v_366_2 = ((pub_r001955_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((stage_v_112_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_112_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((stage_v_200_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_200_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((stage_v_141_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_141_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((pub_r001955_1_1 * 2) + 38) & 63;
  int stage_v_370_2 = ((pub_r001955_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((stage_v_83_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_83_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((pub_r001955_12_1 * 2) + 46) & 63;
  int stage_v_372_2 = ((pub_r001955_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((stage_v_193_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_193_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_192_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_192_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001955_15_1 * 2) + 6) & 63;
  int stage_v_375_2 = ((pub_r001955_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_84_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_84_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((pub_r001955_10_1 * 2) + 5) & 63;
  int stage_v_377_2 = ((pub_r001955_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((sec_r001955_13_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_378_2 = ((sec_r001955_13_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((helper_flow_5_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_379_2 = ((helper_flow_5_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_150_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_150_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((pub_r001955_6_1 * 2) + 35) & 63;
  int stage_v_381_2 = ((pub_r001955_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001955_16_1 * 2) + 43) & 63;
  int stage_v_382_2 = ((pub_r001955_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001955_0_1 * 2) + 26) & 63;
  int stage_v_383_2 = ((pub_r001955_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001955_13_1 * 2) + 21) & 63;
  int stage_v_384_2 = ((pub_r001955_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001955_14_1 * 2) + 38) & 63;
  int stage_v_385_2 = ((pub_r001955_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((stage_v_185_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_185_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((sec_r001955_3_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_387_2 = ((sec_r001955_3_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((pub_r001955_2_1 * 2) + 27) & 63;
  int stage_v_388_2 = ((pub_r001955_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_213_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_213_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001955_10_1 * 2) + 19) & 63;
  int stage_v_390_2 = ((pub_r001955_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_210_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_210_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((pub_r001955_12_1 * 2) + 45) & 63;
  int stage_v_392_2 = ((pub_r001955_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001955_13_1 * 2) + 38) & 63;
  int stage_v_393_2 = ((pub_r001955_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((stage_v_320_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_394_2 = ((stage_v_320_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001955_7_1 * 2) + 14) & 63;
  int stage_v_395_2 = ((pub_r001955_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_32_1 << 1) ^ (pub_r001955_2_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_32_2 << 1) ^ (pub_r001955_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((stage_v_367_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_367_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((stage_v_231_1 << 1) ^ (pub_r001955_11_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_231_2 << 1) ^ (pub_r001955_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((sec_r001955_13_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_399_2 = ((sec_r001955_13_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((stage_v_23_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_23_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((stage_v_117_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_117_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((pub_r001955_13_1 * 2) + 6) & 63;
  int stage_v_402_2 = ((pub_r001955_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((stage_v_275_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_275_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_240_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_240_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001955_2_1 * 2) + 17) & 63;
  int stage_v_405_2 = ((pub_r001955_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((helper_flow_5_1 << 1) ^ (pub_r001955_10_1 >> 1)) & 127;
  int stage_v_406_2 = ((helper_flow_5_2 << 1) ^ (pub_r001955_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((stage_v_257_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_407_2 = ((stage_v_257_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((stage_v_264_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_264_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((pub_r001955_16_1 * 2) + 5) & 63;
  int stage_v_409_2 = ((pub_r001955_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001955_14_1 * 2) + 41) & 63;
  int stage_v_410_2 = ((pub_r001955_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001955_1_1 * 2) + 21) & 63;
  int stage_v_411_2 = ((pub_r001955_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_43_1 << 1) ^ (pub_r001955_16_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_43_2 << 1) ^ (pub_r001955_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((stage_v_76_1 << 1) ^ (pub_r001955_14_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_76_2 << 1) ^ (pub_r001955_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((stage_v_356_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_356_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((stage_v_52_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_52_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((sec_r001955_11_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_416_2 = ((sec_r001955_11_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((stage_v_341_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_417_2 = ((stage_v_341_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_417_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_417_2 + 1) & 15;
  out_sink_1 ^= stage_v_417_1 & 63;
  out_sink_2 ^= stage_v_417_2 & 63;
  int stage_v_418_1 = ((pub_r001955_11_1 * 2) + 26) & 63;
  int stage_v_418_2 = ((pub_r001955_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((stage_v_51_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_51_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_343_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_343_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_326_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_326_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((sec_r001955_10_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_422_2 = ((sec_r001955_10_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((sec_r001955_6_1 << 1) ^ (pub_r001955_0_1 >> 1)) & 127;
  int stage_v_423_2 = ((sec_r001955_6_2 << 1) ^ (pub_r001955_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((pub_r001955_9_1 * 2) + 37) & 63;
  int stage_v_424_2 = ((pub_r001955_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_259_1 << 1) ^ (pub_r001955_13_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_259_2 << 1) ^ (pub_r001955_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  int stage_v_426_1 = ((pub_r001955_5_1 * 2) + 23) & 63;
  int stage_v_426_2 = ((pub_r001955_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((stage_v_422_1 << 1) ^ (pub_r001955_6_1 >> 1)) & 127;
  int stage_v_427_2 = ((stage_v_422_2 << 1) ^ (pub_r001955_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((stage_v_118_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_428_2 = ((stage_v_118_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_428_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_428_2 + 1) & 15;
  out_sink_1 ^= stage_v_428_1 & 63;
  out_sink_2 ^= stage_v_428_2 & 63;
  int stage_v_429_1 = ((stage_v_271_1 << 1) ^ (pub_r001955_12_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_271_2 << 1) ^ (pub_r001955_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((stage_v_401_1 << 1) ^ (pub_r001955_1_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_401_2 << 1) ^ (pub_r001955_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((pub_r001955_0_1 * 2) + 43) & 63;
  int stage_v_431_2 = ((pub_r001955_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001955_7_1 * 2) + 36) & 63;
  int stage_v_432_2 = ((pub_r001955_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((stage_v_413_1 << 1) ^ (pub_r001955_8_1 >> 1)) & 127;
  int stage_v_433_2 = ((stage_v_413_2 << 1) ^ (pub_r001955_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_433_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_433_2 + 1) & 15;
  out_sink_1 ^= stage_v_433_1 & 63;
  out_sink_2 ^= stage_v_433_2 & 63;
  int stage_v_434_1 = ((stage_v_2_1 << 1) ^ (pub_r001955_7_1 >> 1)) & 127;
  int stage_v_434_2 = ((stage_v_2_2 << 1) ^ (pub_r001955_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_434_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_434_2 + 1) & 15;
  out_sink_1 ^= stage_v_434_1 & 63;
  out_sink_2 ^= stage_v_434_2 & 63;
  int stage_v_435_1 = ((pub_r001955_0_1 * 2) + 43) & 63;
  int stage_v_435_2 = ((pub_r001955_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001955_4_1 * 2) + 30) & 63;
  int stage_v_436_2 = ((pub_r001955_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((stage_v_61_1 << 1) ^ (pub_r001955_4_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_61_2 << 1) ^ (pub_r001955_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((stage_v_328_1 << 1) ^ (pub_r001955_9_1 >> 1)) & 127;
  int stage_v_438_2 = ((stage_v_328_2 << 1) ^ (pub_r001955_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_438_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_438_2 + 1) & 15;
  out_sink_1 ^= stage_v_438_1 & 63;
  out_sink_2 ^= stage_v_438_2 & 63;
  int stage_v_439_1 = ((pub_r001955_1_1 * 2) + 11) & 63;
  int stage_v_439_2 = ((pub_r001955_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001955_16_1 * 2) + 8) & 63;
  int stage_v_440_2 = ((pub_r001955_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((stage_v_105_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_441_2 = ((stage_v_105_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_441_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_441_2 + 1) & 15;
  out_sink_1 ^= stage_v_441_1 & 63;
  out_sink_2 ^= stage_v_441_2 & 63;
  int stage_v_442_1 = ((stage_v_231_1 << 1) ^ (pub_r001955_15_1 >> 1)) & 127;
  int stage_v_442_2 = ((stage_v_231_2 << 1) ^ (pub_r001955_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_442_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_442_2 + 1) & 15;
  out_sink_1 ^= stage_v_442_1 & 63;
  out_sink_2 ^= stage_v_442_2 & 63;
  int stage_v_443_1 = ((pub_r001955_13_1 * 2) + 9) & 63;
  int stage_v_443_2 = ((pub_r001955_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001955_6_1 * 2) + 25) & 63;
  int stage_v_444_2 = ((pub_r001955_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((stage_v_441_1 << 1) ^ (pub_r001955_3_1 >> 1)) & 127;
  int stage_v_445_2 = ((stage_v_441_2 << 1) ^ (pub_r001955_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_445_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_445_2 + 1) & 15;
  out_sink_1 ^= stage_v_445_1 & 63;
  out_sink_2 ^= stage_v_445_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001955_13_1 == pub_r001955_13_2);
  __CPROVER_assume(sec_r001955_1_1 != sec_r001955_1_2);
  __CPROVER_assume(sec_r001955_3_1 != sec_r001955_3_2);
  __CPROVER_assume(pub_r001955_0_1 == pub_r001955_0_2);
  __CPROVER_assume(sec_r001955_9_1 != sec_r001955_9_2);
  __CPROVER_assume(pub_r001955_2_1 == pub_r001955_2_2);
  __CPROVER_assume(sec_r001955_2_1 != sec_r001955_2_2);
  __CPROVER_assume(sec_r001955_12_1 != sec_r001955_12_2);
  __CPROVER_assume(pub_r001955_1_1 == pub_r001955_1_2);
  __CPROVER_assume(sec_r001955_17_1 != sec_r001955_17_2);
  __CPROVER_assume(pub_r001955_7_1 == pub_r001955_7_2);
  __CPROVER_assume(pub_r001955_3_1 == pub_r001955_3_2);
  __CPROVER_assume(pub_r001955_5_1 == pub_r001955_5_2);
  __CPROVER_assume(sec_r001955_16_1 != sec_r001955_16_2);
  __CPROVER_assume(pub_r001955_12_1 == pub_r001955_12_2);
  __CPROVER_assume(pub_r001955_16_1 == pub_r001955_16_2);
  __CPROVER_assume(sec_r001955_7_1 != sec_r001955_7_2);
  __CPROVER_assume(pub_r001955_6_1 == pub_r001955_6_2);
  __CPROVER_assume(sec_r001955_14_1 != sec_r001955_14_2);
  __CPROVER_assume(pub_r001955_8_1 == pub_r001955_8_2);
  __CPROVER_assume(pub_r001955_14_1 == pub_r001955_14_2);
  __CPROVER_assume(sec_r001955_5_1 != sec_r001955_5_2);
  __CPROVER_assume(sec_r001955_6_1 != sec_r001955_6_2);
  __CPROVER_assume(pub_r001955_9_1 == pub_r001955_9_2);
  __CPROVER_assume(sec_r001955_15_1 != sec_r001955_15_2);
  __CPROVER_assume(pub_r001955_15_1 == pub_r001955_15_2);
  __CPROVER_assume(pub_r001955_10_1 == pub_r001955_10_2);
  __CPROVER_assume(sec_r001955_13_1 != sec_r001955_13_2);
  __CPROVER_assume(sec_r001955_11_1 != sec_r001955_11_2);
  __CPROVER_assume(sec_r001955_8_1 != sec_r001955_8_2);
  __CPROVER_assume(sec_r001955_4_1 != sec_r001955_4_2);
  __CPROVER_assume(sec_r001955_0_1 != sec_r001955_0_2);
  __CPROVER_assume(pub_r001955_11_1 == pub_r001955_11_2);
  __CPROVER_assume(sec_r001955_10_1 != sec_r001955_10_2);
  __CPROVER_assume(pub_r001955_4_1 == pub_r001955_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.flags == st_var_2_2.flags);
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
}


