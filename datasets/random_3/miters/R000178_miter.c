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
struct AudioFrame_R000178_6807
{
  int sample_rate;
  int rms;
  int channels;
  int buffer[3];
};
struct StreamBuffer_R000178_6807
{
  int tail;
  short checksum;
  int head;
  int watermark;
  int capacity;
  int buffer[3];
};
struct DeviceConfig_R000178_6807
{
  short timeout;
  int parity;
  int baud_rate;
  int buffer[3];
};
union TelemetryField_R000178_6807
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
void fn_R000178_6807_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int bound_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_1 > 22)
  {
    acc_1 = ((acc_1 + (bound_1 * 2)) + 5) & 127;
    aux_1 ^= bound_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_2 > 22)
  {
    acc_2 = ((acc_2 + (bound_2 * 2)) + 5) & 127;
    aux_2 ^= bound_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(bound_1 == bound_2);
}

int fn_R000178_6807_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int bound = ((st.buffer[0] * 3) + aux) & 63;
  if (bound > 22)
  {
    acc = ((acc + (bound * 2)) + 5) & 127;
    aux ^= bound & 15;
  }
  else
  {
    acc = ((acc - bound) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000178_6807_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int quantum_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_1 > 30)
  {
    acc_1 = ((acc_1 + (quantum_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_2 > 30)
  {
    acc_2 = ((acc_2 + (quantum_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 3) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 3) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(quantum_1 == quantum_2);
}

int fn_R000178_6807_1(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int quantum = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum > 30)
  {
    acc = ((acc + (quantum * 2)) + 5) & 127;
    aux ^= quantum & 15;
  }
  else
  {
    acc = ((acc - quantum) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 7) & 127;
      break;

    case 1:
      acc = (acc + 14) & 127;
      break;

    case 3:
      acc = (acc + 3) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int pivot_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(pivot_1 == pivot_2);
}

int fn_R000178_6807_2(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int pivot = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot > 26)
  {
    acc = ((acc + (pivot * 2)) + 5) & 127;
    aux ^= pivot & 15;
  }
  else
  {
    acc = ((acc - pivot) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000178_6807_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_1 > 45)
  {
    acc_1 = ((acc_1 + (tally_1 * 2)) + 5) & 127;
    aux_1 ^= tally_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_2 > 45)
  {
    acc_2 = ((acc_2 + (tally_2 * 2)) + 5) & 127;
    aux_2 ^= tally_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 7) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 10) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 1:
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 7) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 10) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_1 == tally_2);
}

int fn_R000178_6807_3(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally = ((st.buffer[0] * 3) + aux) & 63;
  if (tally > 45)
  {
    acc = ((acc + (tally * 2)) + 5) & 127;
    aux ^= tally & 15;
  }
  else
  {
    acc = ((acc - tally) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 10) & 127;
      break;

    case 2:
      acc = (acc + 7) & 127;
      break;

    case 3:
      acc = (acc + 10) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 1:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000178_6807_4(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 9) & 127;
      break;

    case 3:
      acc = (acc + 12) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st_1 = {0};
  struct AudioFrame_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 1:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 17) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 1:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 17) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 3)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 3)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000178_6807_5(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  switch ((p0 + aux) & 3)
  {
    case 1:
      acc = (acc + 6) & 127;
      break;

    case 2:
      acc = (acc + 8) & 127;
      break;

    case 0:
      acc = (acc + 17) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 3)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 16) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 6) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 16) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 6) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000178_6807_6(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 16) & 127;
      break;

    case 0:
      acc = (acc + 5) & 127;
      break;

    case 3:
      acc = (acc + 6) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000178_6807_7(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int parity_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_1 > 23)
  {
    acc_1 = ((acc_1 + (parity_1 * 2)) + 5) & 127;
    aux_1 ^= parity_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_2 > 23)
  {
    acc_2 = ((acc_2 + (parity_2 * 2)) + 5) & 127;
    aux_2 ^= parity_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_2) + 11) & 127;
    aux_2 += 3;
  }
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(parity_1 == parity_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000178_6807_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int parity = ((st.buffer[0] * 3) + aux) & 63;
  if (parity > 23)
  {
    acc = ((acc + (parity * 2)) + 5) & 127;
    aux ^= parity & 15;
  }
  else
  {
    acc = ((acc - parity) + 11) & 127;
    aux += 3;
  }
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 5) & 127;
      break;

    case 2:
      acc = (acc + 14) & 127;
      break;

    case 1:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000178_6807_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st_1 = {0};
  struct AudioFrame_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 8) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 8) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000178_6807_9(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 3) & 127;
      break;

    case 0:
      acc = (acc + 8) & 127;
      break;

    case 3:
      acc = (acc + 8) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000178_6807_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int bound_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_1 > 47)
  {
    acc_1 = ((acc_1 + (bound_1 * 2)) + 5) & 127;
    aux_1 ^= bound_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_2 > 47)
  {
    acc_2 = ((acc_2 + (bound_2 * 2)) + 5) & 127;
    aux_2 ^= bound_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(bound_1 == bound_2);
}

int fn_R000178_6807_10(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int bound = ((st.buffer[0] * 3) + aux) & 63;
  if (bound > 47)
  {
    acc = ((acc + (bound * 2)) + 5) & 127;
    aux ^= bound & 15;
  }
  else
  {
    acc = ((acc - bound) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000178_6807_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000178_6807_11(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 4)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 17) & 127;
      break;

    case 3:
      acc = (acc + 3) & 127;
      break;

    case 0:
      acc = (acc + 4) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 12) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 9) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 9) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 0:
      acc_2 = (acc_2 + 12) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 9) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 9) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int index_reg_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_1 > 27)
  {
    acc_1 = ((acc_1 + (index_reg_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_2 > 27)
  {
    acc_2 = ((acc_2 + (index_reg_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_2) + 11) & 127;
    aux_2 += 3;
  }
  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_1 == index_reg_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000178_6807_12(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 12) & 127;
      break;

    case 2:
      acc = (acc + 9) & 127;
      break;

    case 3:
      acc = (acc + 9) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int index_reg = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg > 27)
  {
    acc = ((acc + (index_reg * 2)) + 5) & 127;
    aux ^= index_reg & 15;
  }
  else
  {
    acc = ((acc - index_reg) + 11) & 127;
    aux += 3;
  }
  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000178_6807_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st_1 = {0};
  struct StreamBuffer_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_1 > 12)
  {
    acc_1 = ((acc_1 + (damping_1 * 2)) + 5) & 127;
    aux_1 ^= damping_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_2 > 12)
  {
    acc_2 = ((acc_2 + (damping_2 * 2)) + 5) & 127;
    aux_2 ^= damping_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_2) + 11) & 127;
    aux_2 += 3;
  }
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  switch ((p0_1 + aux_1) & 3)
  {
    case 0:
      acc_1 = (acc_1 + 14) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 11) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 13) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 0:
      acc_2 = (acc_2 + 14) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 11) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 13) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_1 == damping_2);
  assert(loop_ctr_1 == loop_ctr_2);
}

int fn_R000178_6807_13(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping = ((st.buffer[0] * 3) + aux) & 63;
  if (damping > 12)
  {
    acc = ((acc + (damping * 2)) + 5) & 127;
    aux ^= damping & 15;
  }
  else
  {
    acc = ((acc - damping) + 11) & 127;
    aux += 3;
  }
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  switch ((p0 + aux) & 3)
  {
    case 0:
      acc = (acc + 14) & 127;
      break;

    case 3:
      acc = (acc + 11) & 127;
      break;

    case 1:
      acc = (acc + 13) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void fn_R000178_6807_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  switch ((p0_1 + aux_1) & 3)
  {
    case 3:
      acc_1 = (acc_1 + 10) & 127;
      break;

    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 2:
      acc_1 = (acc_1 + 7) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 3:
      acc_2 = (acc_2 + 10) & 127;
      break;

    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 2:
      acc_2 = (acc_2 + 7) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(b_step_1 == b_step_2);
  assert(loop_ctr_1 == loop_ctr_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000178_6807_14(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  switch ((p0 + aux) & 3)
  {
    case 3:
      acc = (acc + 10) & 127;
      break;

    case 0:
      acc = (acc + 6) & 127;
      break;

    case 2:
      acc = (acc + 7) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  return (acc + aux) & 127;
}

void fn_R000178_6807_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st_1 = {0};
  struct AudioFrame_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 2) && (loop_ctr_2 < 2))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int coefficient_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_1 > 25)
  {
    acc_1 = ((acc_1 + (coefficient_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_2 > 25)
  {
    acc_2 = ((acc_2 + (coefficient_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(coefficient_1 == coefficient_2);
}

int fn_R000178_6807_15(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int loop_ctr = 0;
  while (loop_ctr < 2)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int coefficient = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient > 25)
  {
    acc = ((acc + (coefficient * 2)) + 5) & 127;
    aux ^= coefficient & 15;
  }
  else
  {
    acc = ((acc - coefficient) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000178_6807_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 2)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 2)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int loop_ctr_1 = 0;
  int loop_ctr_2 = 0;
  while ((loop_ctr_1 < 3) && (loop_ctr_2 < 3))
  {
    acc_1 = ((acc_1 + (loop_ctr_1 * 4)) + 7) & 127;
    acc_2 = ((acc_2 + (loop_ctr_2 * 4)) + 7) & 127;
    loop_ctr_1++;
    loop_ctr_2++;
  }

  int b_step_1 = ((aux_1 << 1) ^ (acc_1 >> 1)) & 63;
  int b_step_2 = ((aux_2 << 1) ^ (acc_2 >> 1)) & 63;
  acc_1 = (acc_1 + (b_step_1 * 3)) & 127;
  acc_2 = (acc_2 + (b_step_2 * 3)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

  assert(loop_ctr_1 == loop_ctr_2);
  assert(b_step_1 == b_step_2);
}

int fn_R000178_6807_16(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 2)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int loop_ctr = 0;
  while (loop_ctr < 3)
  {
    acc = ((acc + (loop_ctr * 4)) + 7) & 127;
    loop_ctr++;
  }

  int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
  acc = (acc + (b_step * 3)) & 127;
  return (acc + aux) & 127;
}

void fn_R000178_6807_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    aux_1 = ((aux_1 + (k_1 * 5)) + st_1.buffer[k_1 % 3]) & 63;
    aux_2 = ((aux_2 + (k_2 * 5)) + st_2.buffer[k_2 % 3]) & 63;
    acc_1 = (acc_1 ^ (aux_1 + k_1)) & 127;
    acc_2 = (acc_2 ^ (aux_2 + k_2)) & 127;
  }

  int weight_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_1 > 35)
  {
    acc_1 = ((acc_1 + (weight_1 * 2)) + 5) & 127;
    aux_1 ^= weight_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_2 > 35)
  {
    acc_2 = ((acc_2 + (weight_2 * 2)) + 5) & 127;
    aux_2 ^= weight_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_1 == weight_2);
}

int fn_R000178_6807_17(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  for (int k = 0; k < 2; k++)
  {
    aux = ((aux + (k * 5)) + st.buffer[k % 3]) & 63;
    acc = (acc ^ (aux + k)) & 127;
  }

  int weight = ((st.buffer[0] * 3) + aux) & 63;
  if (weight > 35)
  {
    acc = ((acc + (weight * 2)) + 5) & 127;
    aux ^= weight & 15;
  }
  else
  {
    acc = ((acc - weight) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 127;
}

void fn_R000178_6807_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st_1 = {0};
  struct DeviceConfig_R000178_6807 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int loc_tab_1[3];
  int loc_tab_2[3];
  loc_tab_1[0] = (p0_1 & 15) + 2;
  loc_tab_2[0] = (p0_2 & 15) + 2;
  loc_tab_1[1] = (p1_1 & 15) + 4;
  loc_tab_2[1] = (p1_2 & 15) + 4;
  loc_tab_1[2] = (aux_1 & 15) + 6;
  loc_tab_2[2] = (aux_2 & 15) + 6;
  acc_1 = (acc_1 + loc_tab_1[aux_1 % 3]) & 127;
  acc_2 = (acc_2 + loc_tab_2[aux_2 % 3]) & 127;
  switch ((p0_1 + aux_1) & 3)
  {
    case 2:
      acc_1 = (acc_1 + 17) & 127;
      break;

    case 3:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      acc_1 = (acc_1 + 10) & 127;
      break;

    default:
      acc_1 ^= 0x1F;
      break;

  }

  switch ((p0_2 + aux_2) & 3)
  {
    case 2:
      acc_2 = (acc_2 + 17) & 127;
      break;

    case 3:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      acc_2 = (acc_2 + 10) & 127;
      break;

    default:
      acc_2 ^= 0x1F;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(loc_tab_1[i_0] == loc_tab_2[i_0]);
  }

}

int fn_R000178_6807_18(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000178_6807 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int loc_tab[3];
  loc_tab[0] = (p0 & 15) + 2;
  loc_tab[1] = (p1 & 15) + 4;
  loc_tab[2] = (aux & 15) + 6;
  acc = (acc + loc_tab[aux % 3]) & 127;
  switch ((p0 + aux) & 3)
  {
    case 2:
      acc = (acc + 17) & 127;
      break;

    case 3:
      acc = (acc + 4) & 127;
      break;

    case 1:
      acc = (acc + 10) & 127;
      break;

    default:
      acc ^= 0x1F;
      break;

  }

  return (acc + aux) & 127;
}

void main()
{
  int sec_r000178_0_1;
  int sec_r000178_0_2;
  int pub_r000178_0_1;
  int pub_r000178_0_2;
  int pub_r000178_1_1;
  int pub_r000178_1_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  struct AudioFrame_R000178_6807 st_var_0_1 = {0};
  struct AudioFrame_R000178_6807 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000178_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000178_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000178_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000178_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = 7;
  st_var_0_2.buffer[2] = 7;
  struct StreamBuffer_R000178_6807 st_var_1_1 = {0};
  struct StreamBuffer_R000178_6807 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000178_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000178_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000178_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000178_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = 8;
  st_var_1_2.buffer[2] = 8;
  struct DeviceConfig_R000178_6807 st_var_2_1 = {0};
  struct DeviceConfig_R000178_6807 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000178_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000178_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000178_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000178_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = 9;
  st_var_2_2.buffer[2] = 9;
  union TelemetryField_R000178_6807 u_var_1 = {0};
  union TelemetryField_R000178_6807 u_var_2 = {0};
  u_var_1.word = (pub_r000178_0_1 + 0x42) & 255;
  u_var_2.word = (pub_r000178_0_2 + 0x42) & 255;
  int table_1[4] = {7, 13, 29, 41};
  int table_2[4] = {7, 13, 29, 41};
  int res_0_1 = fn_R000178_6807_0(7, 8, 9, 10);
  int res_0_2 = fn_R000178_6807_0(7, 8, 9, 10);
  fn_R000178_6807_0_2(7, 8, 9, 10, 7, 8, 9, 10);
  out_sink_1 = (out_sink_1 + res_0_1) & 255;
  out_sink_2 = (out_sink_2 + res_0_2) & 255;
  chk_sum_1 ^= (res_0_1 << 1) & 127;
  chk_sum_2 ^= (res_0_2 << 1) & 127;
  int res_1_1 = fn_R000178_6807_1(9, 11);
  int res_1_2 = fn_R000178_6807_1(9, 11);
  fn_R000178_6807_1_2(9, 11, 9, 11);
  out_sink_1 = (out_sink_1 + res_1_1) & 255;
  out_sink_2 = (out_sink_2 + res_1_2) & 255;
  chk_sum_1 ^= (res_1_1 << 1) & 127;
  chk_sum_2 ^= (res_1_2 << 1) & 127;
  int res_2_1 = fn_R000178_6807_2(11, 14);
  int res_2_2 = fn_R000178_6807_2(11, 14);
  fn_R000178_6807_2_2(11, 14, 11, 14);
  out_sink_1 = (out_sink_1 + res_2_1) & 255;
  out_sink_2 = (out_sink_2 + res_2_2) & 255;
  chk_sum_1 ^= (res_2_1 << 1) & 127;
  chk_sum_2 ^= (res_2_2 << 1) & 127;
  int res_3_1 = fn_R000178_6807_3(13, 17, 21);
  int res_3_2 = fn_R000178_6807_3(13, 17, 21);
  fn_R000178_6807_3_2(13, 17, 21, 13, 17, 21);
  out_sink_1 = (out_sink_1 + res_3_1) & 255;
  out_sink_2 = (out_sink_2 + res_3_2) & 255;
  chk_sum_1 ^= (res_3_1 << 1) & 127;
  chk_sum_2 ^= (res_3_2 << 1) & 127;
  int res_4_1 = fn_R000178_6807_4(15, 20, 25);
  int res_4_2 = fn_R000178_6807_4(15, 20, 25);
  fn_R000178_6807_4_2(15, 20, 25, 15, 20, 25);
  out_sink_1 = (out_sink_1 + res_4_1) & 255;
  out_sink_2 = (out_sink_2 + res_4_2) & 255;
  chk_sum_1 ^= (res_4_1 << 1) & 127;
  chk_sum_2 ^= (res_4_2 << 1) & 127;
  int res_5_1 = fn_R000178_6807_5(17, 23, 29);
  int res_5_2 = fn_R000178_6807_5(17, 23, 29);
  fn_R000178_6807_5_2(17, 23, 29, 17, 23, 29);
  out_sink_1 = (out_sink_1 + res_5_1) & 255;
  out_sink_2 = (out_sink_2 + res_5_2) & 255;
  chk_sum_1 ^= (res_5_1 << 1) & 127;
  chk_sum_2 ^= (res_5_2 << 1) & 127;
  int res_6_1 = fn_R000178_6807_6(19, 26, 33);
  int res_6_2 = fn_R000178_6807_6(19, 26, 33);
  fn_R000178_6807_6_2(19, 26, 33, 19, 26, 33);
  out_sink_1 = (out_sink_1 + res_6_1) & 255;
  out_sink_2 = (out_sink_2 + res_6_2) & 255;
  chk_sum_1 ^= (res_6_1 << 1) & 127;
  chk_sum_2 ^= (res_6_2 << 1) & 127;
  int res_7_1 = fn_R000178_6807_7(21, 29);
  int res_7_2 = fn_R000178_6807_7(21, 29);
  fn_R000178_6807_7_2(21, 29, 21, 29);
  out_sink_1 = (out_sink_1 + res_7_1) & 255;
  out_sink_2 = (out_sink_2 + res_7_2) & 255;
  chk_sum_1 ^= (res_7_1 << 1) & 127;
  chk_sum_2 ^= (res_7_2 << 1) & 127;
  int res_8_1 = fn_R000178_6807_8(23, 32, 41, 50);
  int res_8_2 = fn_R000178_6807_8(23, 32, 41, 50);
  fn_R000178_6807_8_2(23, 32, 41, 50, 23, 32, 41, 50);
  out_sink_1 = (out_sink_1 + res_8_1) & 255;
  out_sink_2 = (out_sink_2 + res_8_2) & 255;
  chk_sum_1 ^= (res_8_1 << 1) & 127;
  chk_sum_2 ^= (res_8_2 << 1) & 127;
  int res_9_1 = fn_R000178_6807_9(25, 35, 45);
  int res_9_2 = fn_R000178_6807_9(25, 35, 45);
  fn_R000178_6807_9_2(25, 35, 45, 25, 35, 45);
  out_sink_1 = (out_sink_1 + res_9_1) & 255;
  out_sink_2 = (out_sink_2 + res_9_2) & 255;
  chk_sum_1 ^= (res_9_1 << 1) & 127;
  chk_sum_2 ^= (res_9_2 << 1) & 127;
  int res_10_1 = fn_R000178_6807_10(27, 38);
  int res_10_2 = fn_R000178_6807_10(27, 38);
  fn_R000178_6807_10_2(27, 38, 27, 38);
  out_sink_1 = (out_sink_1 + res_10_1) & 255;
  out_sink_2 = (out_sink_2 + res_10_2) & 255;
  chk_sum_1 ^= (res_10_1 << 1) & 127;
  chk_sum_2 ^= (res_10_2 << 1) & 127;
  int res_11_1 = fn_R000178_6807_11(29, 41, 53);
  int res_11_2 = fn_R000178_6807_11(29, 41, 53);
  fn_R000178_6807_11_2(29, 41, 53, 29, 41, 53);
  out_sink_1 = (out_sink_1 + res_11_1) & 255;
  out_sink_2 = (out_sink_2 + res_11_2) & 255;
  chk_sum_1 ^= (res_11_1 << 1) & 127;
  chk_sum_2 ^= (res_11_2 << 1) & 127;
  int res_12_1 = fn_R000178_6807_12(31, 44, 57);
  int res_12_2 = fn_R000178_6807_12(31, 44, 57);
  fn_R000178_6807_12_2(31, 44, 57, 31, 44, 57);
  out_sink_1 = (out_sink_1 + res_12_1) & 255;
  out_sink_2 = (out_sink_2 + res_12_2) & 255;
  chk_sum_1 ^= (res_12_1 << 1) & 127;
  chk_sum_2 ^= (res_12_2 << 1) & 127;
  int res_13_1 = fn_R000178_6807_13(33, 47);
  int res_13_2 = fn_R000178_6807_13(33, 47);
  fn_R000178_6807_13_2(33, 47, 33, 47);
  out_sink_1 = (out_sink_1 + res_13_1) & 255;
  out_sink_2 = (out_sink_2 + res_13_2) & 255;
  chk_sum_1 ^= (res_13_1 << 1) & 127;
  chk_sum_2 ^= (res_13_2 << 1) & 127;
  int res_14_1 = fn_R000178_6807_14(35, 50);
  int res_14_2 = fn_R000178_6807_14(35, 50);
  fn_R000178_6807_14_2(35, 50, 35, 50);
  out_sink_1 = (out_sink_1 + res_14_1) & 255;
  out_sink_2 = (out_sink_2 + res_14_2) & 255;
  chk_sum_1 ^= (res_14_1 << 1) & 127;
  chk_sum_2 ^= (res_14_2 << 1) & 127;
  int res_15_1 = fn_R000178_6807_15(37, 53);
  int res_15_2 = fn_R000178_6807_15(37, 53);
  fn_R000178_6807_15_2(37, 53, 37, 53);
  out_sink_1 = (out_sink_1 + res_15_1) & 255;
  out_sink_2 = (out_sink_2 + res_15_2) & 255;
  chk_sum_1 ^= (res_15_1 << 1) & 127;
  chk_sum_2 ^= (res_15_2 << 1) & 127;
  int res_16_1 = fn_R000178_6807_16(39, 56);
  int res_16_2 = fn_R000178_6807_16(39, 56);
  fn_R000178_6807_16_2(39, 56, 39, 56);
  out_sink_1 = (out_sink_1 + res_16_1) & 255;
  out_sink_2 = (out_sink_2 + res_16_2) & 255;
  chk_sum_1 ^= (res_16_1 << 1) & 127;
  chk_sum_2 ^= (res_16_2 << 1) & 127;
  int res_17_1 = fn_R000178_6807_17(41, 59);
  int res_17_2 = fn_R000178_6807_17(41, 59);
  fn_R000178_6807_17_2(41, 59, 41, 59);
  out_sink_1 = (out_sink_1 + res_17_1) & 255;
  out_sink_2 = (out_sink_2 + res_17_2) & 255;
  chk_sum_1 ^= (res_17_1 << 1) & 127;
  chk_sum_2 ^= (res_17_2 << 1) & 127;
  int res_18_1 = fn_R000178_6807_18(43, 62, 81);
  int res_18_2 = fn_R000178_6807_18(43, 62, 81);
  fn_R000178_6807_18_2(43, 62, 81, 43, 62, 81);
  out_sink_1 = (out_sink_1 + res_18_1) & 255;
  out_sink_2 = (out_sink_2 + res_18_2) & 255;
  chk_sum_1 ^= (res_18_1 << 1) & 127;
  chk_sum_2 ^= (res_18_2 << 1) & 127;
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 38)
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
  if (stage_v_3_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 38)
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
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 43)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 43)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 45)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 45)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 53)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 53)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = ((st_var_2_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_2_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 30)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 30)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 30)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 30)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 38)
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
  if (stage_v_28_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 38)
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
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 33)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 33)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (st_var_1_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_1_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 29)
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
  if (stage_v_37_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 29)
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
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((st_var_0_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_0_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 44)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 44)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = (st_var_2_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_2_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((st_var_1_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_1_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 50)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 50)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 38)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 38)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((st_var_0_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_0_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 40)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 40)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = (st_var_1_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_1_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 46)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 46)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((st_var_2_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_2_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 48)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 48)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  if (stage_v_79_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 28)
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
  if (stage_v_79_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 28)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 81) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (st_var_1_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_1_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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

  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 89) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (st_var_1_1.buffer[0] ^ 94) & 3;
  int stage_v_91_2 = (st_var_1_2.buffer[0] ^ 94) & 3;
  switch (stage_v_91_1)
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

  switch (stage_v_91_2)
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

  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (99 & 31);
  int stage_v_94_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (99 & 31);
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= (stage_v_94_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_94_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 96) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 96) & 15;
  int stage_v_95_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_95_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= stage_v_95_1;
  chk_sum_2 ^= stage_v_95_2;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 40)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 40)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = ((st_var_1_1.buffer[1] * 2) + 298) & 63;
  int stage_v_97_2 = ((st_var_1_2.buffer[1] * 2) + 298) & 63;
  if (stage_v_97_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_97_1) - 5) & 255;
    if (stage_v_97_1 > 35)
    {
      chk_sum_1 ^= stage_v_97_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_97_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_97_2) - 5) & 255;
    if (stage_v_97_2 > 35)
    {
      chk_sum_2 ^= stage_v_97_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 99) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 99) & 15;
  int stage_v_98_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_98_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= stage_v_98_1;
  chk_sum_2 ^= stage_v_98_2;
  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 26)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 26)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = (st_var_2_1.buffer[0] ^ 104) & 3;
  int stage_v_101_2 = (st_var_2_2.buffer[0] ^ 104) & 3;
  switch (stage_v_101_1)
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

  switch (stage_v_101_2)
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

  int stage_v_102_1 = ((st_var_0_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_0_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 48)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 48)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (st_var_0_1.buffer[0] ^ 108) & 3;
  int stage_v_105_2 = (st_var_0_2.buffer[0] ^ 108) & 3;
  switch (stage_v_105_1)
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

  switch (stage_v_105_2)
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

  int stage_v_106_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (111 & 31);
  int stage_v_106_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (111 & 31);
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= (stage_v_106_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_106_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 108) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 44)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 44)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = (st_var_2_1.buffer[0] ^ 113) & 3;
  int stage_v_110_2 = (st_var_2_2.buffer[0] ^ 113) & 3;
  switch (stage_v_110_1)
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

  switch (stage_v_110_2)
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

  int stage_v_111_1 = (st_var_0_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_0_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = ((st_var_1_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_1_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 29)
    {
      chk_sum_1 ^= stage_v_112_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_112_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 29)
    {
      chk_sum_2 ^= stage_v_112_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_113_1 = ((st_var_2_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_2_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 36)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 36)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = table_1[1];
  int stage_v_117_2 = table_2[1];
  table_1[1] = (table_1[2] + 235) & 63;
  table_2[1] = (table_2[2] + 235) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_119_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_119_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_121_1 = (st_var_1_1.buffer[0] ^ 124) & 3;
  int stage_v_121_2 = (st_var_1_2.buffer[0] ^ 124) & 3;
  switch (stage_v_121_1)
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

  switch (stage_v_121_2)
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

  int stage_v_122_1 = table_1[2];
  int stage_v_122_2 = table_2[2];
  table_1[2] = (table_1[3] + 245) & 63;
  table_2[2] = (table_2[3] + 245) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (st_var_0_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_0_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 125) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  int stage_v_125_1 = ((st_var_2_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_2_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 51)
    {
      chk_sum_1 ^= stage_v_125_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_125_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 51)
    {
      chk_sum_2 ^= stage_v_125_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = ((st_var_1_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_1_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 36)
    {
      chk_sum_1 ^= stage_v_127_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_127_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 36)
    {
      chk_sum_2 ^= stage_v_127_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (136 & 31);
  int stage_v_131_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (136 & 31);
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= (stage_v_131_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_131_2 << 1) & 127;
  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = (st_var_2_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_2_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((st_var_2_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_2_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 55)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 55)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_138_1 = ((st_var_0_1.buffer[0] * 2) + 421) & 63;
  int stage_v_138_2 = ((st_var_0_2.buffer[0] * 2) + 421) & 63;
  if (stage_v_138_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_138_1) - 5) & 255;
    if (stage_v_138_1 > 32)
    {
      chk_sum_1 ^= stage_v_138_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_138_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_138_2) - 5) & 255;
    if (stage_v_138_2 > 32)
    {
      chk_sum_2 ^= stage_v_138_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 46)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 46)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 142) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 143) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = ((st_var_0_1.buffer[0] * 2) + 448) & 63;
  int stage_v_147_2 = ((st_var_0_2.buffer[0] * 2) + 448) & 63;
  if (stage_v_147_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_147_1) - 5) & 255;
    if (stage_v_147_1 > 50)
    {
      chk_sum_1 ^= stage_v_147_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_147_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_147_2) - 5) & 255;
    if (stage_v_147_2 > 50)
    {
      chk_sum_2 ^= stage_v_147_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_148_1 = table_1[0];
  int stage_v_148_2 = table_2[0];
  table_1[0] = (table_1[1] + 297) & 63;
  table_2[0] = (table_2[1] + 297) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 47)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 47)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 151) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 155) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 155) & 15;
  int stage_v_154_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_154_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= stage_v_154_1;
  chk_sum_2 ^= stage_v_154_2;
  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = (st_var_2_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_2_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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

  int stage_v_159_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_159_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_160_1 = ((st_var_1_1.buffer[1] * 2) + 487) & 63;
  int stage_v_160_2 = ((st_var_1_2.buffer[1] * 2) + 487) & 63;
  if (stage_v_160_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_160_1) - 5) & 255;
    if (stage_v_160_1 > 28)
    {
      chk_sum_1 ^= stage_v_160_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_160_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_160_2) - 5) & 255;
    if (stage_v_160_2 > 28)
    {
      chk_sum_2 ^= stage_v_160_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_162_1 = ((st_var_0_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_0_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 43)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 43)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = ((st_var_2_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_2_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 32)
    {
      chk_sum_1 ^= stage_v_164_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_164_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 32)
    {
      chk_sum_2 ^= stage_v_164_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_165_1 = (st_var_0_1.buffer[0] ^ 168) & 3;
  int stage_v_165_2 = (st_var_0_2.buffer[0] ^ 168) & 3;
  switch (stage_v_165_1)
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

  switch (stage_v_165_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 167) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 167) & 15;
  int stage_v_166_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_166_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= stage_v_166_1;
  chk_sum_2 ^= stage_v_166_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 168) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  int l_bound_1 = (sec_r000178_0_1 & 1) + 1;
  int l_bound_2 = (sec_r000178_0_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_1) && (it_2 < l_bound_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 4;
    out_sink_2 += (it_2 * 3) + 4;
  }

  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000178_0_1 != sec_r000178_0_2);
  __CPROVER_assume(pub_r000178_0_1 == pub_r000178_0_2);
  __CPROVER_assume(pub_r000178_1_1 == pub_r000178_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
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

  assert(res_0_1 == res_0_2);
  assert(res_1_1 == res_1_2);
  assert(res_2_1 == res_2_2);
  assert(res_3_1 == res_3_2);
  assert(res_4_1 == res_4_2);
  assert(res_5_1 == res_5_2);
  assert(res_6_1 == res_6_2);
  assert(res_7_1 == res_7_2);
  assert(res_8_1 == res_8_2);
  assert(res_9_1 == res_9_2);
  assert(res_10_1 == res_10_2);
  assert(res_11_1 == res_11_2);
  assert(res_12_1 == res_12_2);
  assert(res_13_1 == res_13_2);
  assert(res_14_1 == res_14_2);
  assert(res_15_1 == res_15_2);
  assert(res_16_1 == res_16_2);
  assert(res_17_1 == res_17_2);
  assert(res_18_1 == res_18_2);
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
  assert(l_bound_1 == l_bound_2);
}


