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
struct FilterState_R001457_5713_0
{
  unsigned char gain_db;
  short damping;
  unsigned char prev_out;
  short cutoff;
  unsigned char prev_in;
  short mode;
  int buffer[3];
};
struct DeviceConfig_R001457_5713_1
{
  int baud_rate;
  int port;
  short timeout;
  int stop_bits;
  unsigned char parity;
  int buffer[3];
};
struct StreamBuffer_R001457_5713_2
{
  unsigned char checksum;
  int tail;
  short watermark;
  unsigned char capacity;
  int state;
  int head;
  int buffer[3];
};
union RegisterBank_R001457_5713_0
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
void fn_R001457_5713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001457_5713_2 st_1 = {0};
  struct StreamBuffer_R001457_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_73_1)
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

  switch (weight_73_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_73_1 == weight_73_2);
}

int fn_R001457_5713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001457_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_73 = (aux + st.buffer[1]) & 3;
  switch (weight_73)
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

void fn_R001457_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_55_1)
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

  switch (offset_55_2)
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

  int quantum_33_1 = 0;
  int quantum_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_33_1 = ((quantum_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_33_2 = ((quantum_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_33_1) & 127;
    acc_2 = (acc_2 + quantum_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_55_1 == offset_55_2);
  assert(quantum_33_1 == quantum_33_2);
}

int fn_R001457_5713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_55 = (aux + st.buffer[1]) & 3;
  switch (offset_55)
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

  int quantum_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_33 = ((quantum_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001457_5713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_89_1 = local_arr_1[aux_1 % 3];
  int sample_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_89_1 == sample_89_2);
}

int fn_R001457_5713_2(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int sample_89 = local_arr[aux % 3];
  acc = (acc + (sample_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001457_5713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int phase_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_99_1 > 31)
  {
    acc_1 = ((acc_1 + (phase_99_1 * 2)) + 5) & 127;
    aux_1 ^= phase_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_99_2 > 31)
  {
    acc_2 = ((acc_2 + (phase_99_2 * 2)) + 5) & 127;
    aux_2 ^= phase_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_99_1 == phase_99_2);
}

int fn_R001457_5713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int phase_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_99 > 31)
  {
    acc = ((acc + (phase_99 * 2)) + 5) & 127;
    aux ^= phase_99 & 15;
  }
  else
  {
    acc = ((acc - phase_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001457_5713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001457_5713_2 st_1 = {0};
  struct StreamBuffer_R001457_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tally_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_41_1) & 63;
  aux_2 = (aux_2 + tally_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_83_1 > 17)
  {
    acc_1 = ((acc_1 + (segment_83_1 * 2)) + 5) & 127;
    aux_1 ^= segment_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_83_2 > 17)
  {
    acc_2 = ((acc_2 + (segment_83_2 * 2)) + 5) & 127;
    aux_2 ^= segment_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_65_1 = 0;
  int checksum_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_65_1 = ((checksum_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_65_2 = ((checksum_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_65_1) & 127;
    acc_2 = (acc_2 + checksum_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_41_1 == tally_41_2);
  assert(segment_83_1 == segment_83_2);
  assert(checksum_65_1 == checksum_65_2);
}

int fn_R001457_5713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001457_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tally_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_41) & 63;
  acc ^= aux;
  int segment_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_83 > 17)
  {
    acc = ((acc + (segment_83 * 2)) + 5) & 127;
    aux ^= segment_83 & 15;
  }
  else
  {
    acc = ((acc - segment_83) + 11) & 127;
    aux += 3;
  }
  int checksum_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_65 = ((checksum_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001457_5713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_75_1) & 63;
  aux_2 = (aux_2 + threshold_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_53_1)
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

  switch (scale_53_2)
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

  int coefficient_59_1 = 0;
  int coefficient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_59_1 = ((coefficient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_59_2 = ((coefficient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_59_1) & 127;
    acc_2 = (acc_2 + coefficient_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_75_1 == threshold_75_2);
  assert(scale_53_1 == scale_53_2);
  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R001457_5713_5(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_53 = (aux + st.buffer[1]) & 3;
  switch (scale_53)
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

  int coefficient_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_59 = ((coefficient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001457_5713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int factor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_62_1 > 25)
  {
    acc_1 = ((acc_1 + (factor_62_1 * 2)) + 5) & 127;
    aux_1 ^= factor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_62_2 > 25)
  {
    acc_2 = ((acc_2 + (factor_62_2 * 2)) + 5) & 127;
    aux_2 ^= factor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_74_1)
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

  switch (parity_74_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_62_1 == factor_62_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R001457_5713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int factor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_62 > 25)
  {
    acc = ((acc + (factor_62 * 2)) + 5) & 127;
    aux ^= factor_62 & 15;
  }
  else
  {
    acc = ((acc - factor_62) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_74 = (aux + st.buffer[1]) & 3;
  switch (parity_74)
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

void fn_R001457_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_94_1 = 0;
  int accumulator_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_94_1 = ((accumulator_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_94_2 = ((accumulator_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_94_1) & 127;
    acc_2 = (acc_2 + accumulator_94_2) & 127;
  }

  int damping_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_14_1)
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

  switch (damping_14_2)
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
  int window_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_31_1) & 63;
  aux_2 = (aux_2 + window_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_94_1 == accumulator_94_2);
  assert(damping_14_1 == damping_14_2);
  assert(window_31_1 == window_31_2);
}

int fn_R001457_5713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_94 = ((accumulator_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_94) & 127;
  }

  int damping_14 = (aux + st.buffer[1]) & 3;
  switch (damping_14)
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
  int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001457_5713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_75_1 = local_arr_1[aux_1 % 3];
  int quotient_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_75_2 * 2)) & 127;
  int damping_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_31_1)
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

  switch (damping_31_2)
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

  int margin_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_86_1) & 63;
  aux_2 = (aux_2 + margin_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_75_1 == quotient_75_2);
  assert(damping_31_1 == damping_31_2);
  assert(margin_86_1 == margin_86_2);
}

int fn_R001457_5713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int quotient_75 = local_arr[aux % 3];
  acc = (acc + (quotient_75 * 2)) & 127;
  int damping_31 = (aux + st.buffer[1]) & 3;
  switch (damping_31)
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

  int margin_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001457_5713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_60_1 = 0;
  int factor_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_60_1 = ((factor_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_60_2 = ((factor_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_60_1) & 127;
    acc_2 = (acc_2 + factor_60_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_47_1 = local_arr_1[aux_1 % 3];
  int pivot_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_47_2 * 2)) & 127;
  int stride_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_27_1)
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

  switch (stride_27_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_60_1 == factor_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_47_1 == pivot_47_2);
  assert(stride_27_1 == stride_27_2);
}

int fn_R001457_5713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_60 = ((factor_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_60) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_47 = local_arr[aux % 3];
  acc = (acc + (pivot_47 * 2)) & 127;
  int stride_27 = (aux + st.buffer[1]) & 3;
  switch (stride_27)
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
  return (acc + aux) & 255;
}

void fn_R001457_5713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_29_1)
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

  switch (offset_29_2)
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

  int accumulator_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_62_1) & 63;
  aux_2 = (aux_2 + accumulator_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_29_1 == offset_29_2);
  assert(accumulator_62_1 == accumulator_62_2);
}

int fn_R001457_5713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_29 = (aux + st.buffer[1]) & 3;
  switch (offset_29)
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

  int accumulator_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001457_5713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_27_1)
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

  switch (sample_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_36_1 = local_arr_1[aux_1 % 3];
  int mask_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_36_2 * 2)) & 127;
  int metric_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_88_1 > 10)
  {
    acc_1 = ((acc_1 + (metric_88_1 * 2)) + 5) & 127;
    aux_1 ^= metric_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_88_2 > 10)
  {
    acc_2 = ((acc_2 + (metric_88_2 * 2)) + 5) & 127;
    aux_2 ^= metric_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_27_1 == sample_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_36_1 == mask_36_2);
  assert(metric_88_1 == metric_88_2);
}

int fn_R001457_5713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_27 = (aux + st.buffer[1]) & 3;
  switch (sample_27)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_36 = local_arr[aux % 3];
  acc = (acc + (mask_36 * 2)) & 127;
  int metric_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_88 > 10)
  {
    acc = ((acc + (metric_88 * 2)) + 5) & 127;
    aux ^= metric_88 & 15;
  }
  else
  {
    acc = ((acc - metric_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001457_5713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_22_1 = local_arr_1[aux_1 % 3];
  int vector_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_22_1 == vector_22_2);
}

int fn_R001457_5713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int vector_22 = local_arr[aux % 3];
  acc = (acc + (vector_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001457_5713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int anchor_47_1 = 0;
  int anchor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_47_1 = ((anchor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_47_2 = ((anchor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_47_1) & 127;
    acc_2 = (acc_2 + anchor_47_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_55_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_55_1 * 2)) + 5) & 127;
    aux_1 ^= vector_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_55_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_55_2 * 2)) + 5) & 127;
    aux_2 ^= vector_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_47_1 == anchor_47_2);
  assert(vector_55_1 == vector_55_2);
}

int fn_R001457_5713_13(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int anchor_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_47 = ((anchor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_47) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_55 > 32)
  {
    acc = ((acc + (vector_55 * 2)) + 5) & 127;
    aux ^= vector_55 & 15;
  }
  else
  {
    acc = ((acc - vector_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001457_5713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_30_1 = local_arr_1[aux_1 % 3];
  int tracker_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_30_2 * 2)) & 127;
  int sample_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_68_1) & 63;
  aux_2 = (aux_2 + sample_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_72_1 > 25)
  {
    acc_1 = ((acc_1 + (window_72_1 * 2)) + 5) & 127;
    aux_1 ^= window_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_72_2 > 25)
  {
    acc_2 = ((acc_2 + (window_72_2 * 2)) + 5) & 127;
    aux_2 ^= window_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_75_1 = 0;
  int anchor_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_75_1 = ((anchor_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_75_2 = ((anchor_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_75_1) & 127;
    acc_2 = (acc_2 + anchor_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_30_1 == tracker_30_2);
  assert(sample_68_1 == sample_68_2);
  assert(window_72_1 == window_72_2);
  assert(anchor_75_1 == anchor_75_2);
}

int fn_R001457_5713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int tracker_30 = local_arr[aux % 3];
  acc = (acc + (tracker_30 * 2)) & 127;
  int sample_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_68) & 63;
  acc ^= aux;
  int window_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_72 > 25)
  {
    acc = ((acc + (window_72 * 2)) + 5) & 127;
    aux ^= window_72 & 15;
  }
  else
  {
    acc = ((acc - window_72) + 11) & 127;
    aux += 3;
  }
  int anchor_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_75 = ((anchor_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001457_5713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int vector_40_1 = 0;
  int vector_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_40_1 = ((vector_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_40_2 = ((vector_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_40_1) & 127;
    acc_2 = (acc_2 + vector_40_2) & 127;
  }

  int anchor_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_60_1) & 63;
  aux_2 = (aux_2 + anchor_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_40_1 == vector_40_2);
  assert(anchor_60_1 == anchor_60_2);
}

int fn_R001457_5713_15(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int vector_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_40 = ((vector_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_40) & 127;
  }

  int anchor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001457_5713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_56_1 > 10)
  {
    acc_1 = ((acc_1 + (phase_56_1 * 2)) + 5) & 127;
    aux_1 ^= phase_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_56_2 > 10)
  {
    acc_2 = ((acc_2 + (phase_56_2 * 2)) + 5) & 127;
    aux_2 ^= phase_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_18_1 = local_arr_1[aux_1 % 3];
  int quotient_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_56_1 == phase_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_18_1 == quotient_18_2);
}

int fn_R001457_5713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_56 > 10)
  {
    acc = ((acc + (phase_56 * 2)) + 5) & 127;
    aux ^= phase_56 & 15;
  }
  else
  {
    acc = ((acc - phase_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_18 = local_arr[aux % 3];
  acc = (acc + (quotient_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001457_5713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_96_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_96_1 * 2)) + 5) & 127;
    aux_1 ^= margin_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_96_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_96_2 * 2)) + 5) & 127;
    aux_2 ^= margin_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_30_1)
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

  switch (tracker_30_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_96_1 == margin_96_2);
  assert(tracker_30_1 == tracker_30_2);
}

int fn_R001457_5713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_96 > 24)
  {
    acc = ((acc + (margin_96 * 2)) + 5) & 127;
    aux ^= margin_96 & 15;
  }
  else
  {
    acc = ((acc - margin_96) + 11) & 127;
    aux += 3;
  }
  int tracker_30 = (aux + st.buffer[1]) & 3;
  switch (tracker_30)
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

void fn_R001457_5713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_49_1)
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

  switch (metric_49_2)
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
  int offset_58_1 = local_arr_1[aux_1 % 3];
  int offset_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_12_1 = 0;
  int threshold_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_12_1 = ((threshold_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_12_2 = ((threshold_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_12_1) & 127;
    acc_2 = (acc_2 + threshold_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_49_1 == metric_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_58_1 == offset_58_2);
  assert(threshold_12_1 == threshold_12_2);
}

int fn_R001457_5713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_49 = (aux + st.buffer[1]) & 3;
  switch (metric_49)
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
  int offset_58 = local_arr[aux % 3];
  acc = (acc + (offset_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_12 = ((threshold_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001457_5713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st_1 = {0};
  struct FilterState_R001457_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_55_1 = 0;
  int window_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_55_1 = ((window_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_55_2 = ((window_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_55_1) & 127;
    acc_2 = (acc_2 + window_55_2) & 127;
  }

  int residue_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_98_1) & 63;
  aux_2 = (aux_2 + residue_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_21_1 > 24)
  {
    acc_1 = ((acc_1 + (coefficient_21_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_21_2 > 24)
  {
    acc_2 = ((acc_2 + (coefficient_21_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_55_1 == window_55_2);
  assert(residue_98_1 == residue_98_2);
  assert(coefficient_21_1 == coefficient_21_2);
}

int fn_R001457_5713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001457_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_55 = ((window_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_55) & 127;
  }

  int residue_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_98) & 63;
  acc ^= aux;
  int coefficient_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_21 > 24)
  {
    acc = ((acc + (coefficient_21 * 2)) + 5) & 127;
    aux ^= coefficient_21 & 15;
  }
  else
  {
    acc = ((acc - coefficient_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001457_5713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_85_1 = local_arr_1[aux_1 % 3];
  int offset_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_85_2 * 2)) & 127;
  int stride_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_89_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_89_1 * 2)) + 5) & 127;
    aux_1 ^= stride_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_89_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_89_2 * 2)) + 5) & 127;
    aux_2 ^= stride_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_39_1) & 63;
  aux_2 = (aux_2 + weight_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_85_1 == offset_85_2);
  assert(stride_89_1 == stride_89_2);
  assert(weight_39_1 == weight_39_2);
}

int fn_R001457_5713_20(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001457_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int offset_85 = local_arr[aux % 3];
  acc = (acc + (offset_85 * 2)) & 127;
  int stride_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_89 > 30)
  {
    acc = ((acc + (stride_89 * 2)) + 5) & 127;
    aux ^= stride_89 & 15;
  }
  else
  {
    acc = ((acc - stride_89) + 11) & 127;
    aux += 3;
  }
  int weight_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_39) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001457_0_1;
  int sec_r001457_0_2;
  int sec_r001457_1_1;
  int sec_r001457_1_2;
  int sec_r001457_2_1;
  int sec_r001457_2_2;
  int sec_r001457_3_1;
  int sec_r001457_3_2;
  int sec_r001457_4_1;
  int sec_r001457_4_2;
  int sec_r001457_5_1;
  int sec_r001457_5_2;
  int sec_r001457_6_1;
  int sec_r001457_6_2;
  int sec_r001457_7_1;
  int sec_r001457_7_2;
  int sec_r001457_8_1;
  int sec_r001457_8_2;
  int sec_r001457_9_1;
  int sec_r001457_9_2;
  int sec_r001457_10_1;
  int sec_r001457_10_2;
  int sec_r001457_11_1;
  int sec_r001457_11_2;
  int sec_r001457_12_1;
  int sec_r001457_12_2;
  int sec_r001457_13_1;
  int sec_r001457_13_2;
  int sec_r001457_14_1;
  int sec_r001457_14_2;
  int sec_r001457_15_1;
  int sec_r001457_15_2;
  int sec_r001457_16_1;
  int sec_r001457_16_2;
  int sec_r001457_17_1;
  int sec_r001457_17_2;
  int sec_r001457_18_1;
  int sec_r001457_18_2;
  int pub_r001457_0_1;
  int pub_r001457_0_2;
  int pub_r001457_1_1;
  int pub_r001457_1_2;
  int pub_r001457_2_1;
  int pub_r001457_2_2;
  int pub_r001457_3_1;
  int pub_r001457_3_2;
  int pub_r001457_4_1;
  int pub_r001457_4_2;
  int pub_r001457_5_1;
  int pub_r001457_5_2;
  int pub_r001457_6_1;
  int pub_r001457_6_2;
  int pub_r001457_7_1;
  int pub_r001457_7_2;
  int pub_r001457_8_1;
  int pub_r001457_8_2;
  int pub_r001457_9_1;
  int pub_r001457_9_2;
  int pub_r001457_10_1;
  int pub_r001457_10_2;
  int pub_r001457_11_1;
  int pub_r001457_11_2;
  int pub_r001457_12_1;
  int pub_r001457_12_2;
  int pub_r001457_13_1;
  int pub_r001457_13_2;
  int pub_r001457_14_1;
  int pub_r001457_14_2;
  int pub_r001457_15_1;
  int pub_r001457_15_2;
  int pub_r001457_16_1;
  int pub_r001457_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001457_0_1 >= (-100)) && (pub_r001457_0_1 <= 100));
  __CPROVER_assume((pub_r001457_0_2 >= (-100)) && (pub_r001457_0_2 <= 100));
  __CPROVER_assume((pub_r001457_1_1 >= (-100)) && (pub_r001457_1_1 <= 100));
  __CPROVER_assume((pub_r001457_1_2 >= (-100)) && (pub_r001457_1_2 <= 100));
  __CPROVER_assume((pub_r001457_2_1 >= (-100)) && (pub_r001457_2_1 <= 100));
  __CPROVER_assume((pub_r001457_2_2 >= (-100)) && (pub_r001457_2_2 <= 100));
  __CPROVER_assume((pub_r001457_3_1 >= (-100)) && (pub_r001457_3_1 <= 100));
  __CPROVER_assume((pub_r001457_3_2 >= (-100)) && (pub_r001457_3_2 <= 100));
  __CPROVER_assume((pub_r001457_4_1 >= (-100)) && (pub_r001457_4_1 <= 100));
  __CPROVER_assume((pub_r001457_4_2 >= (-100)) && (pub_r001457_4_2 <= 100));
  __CPROVER_assume((pub_r001457_5_1 >= (-100)) && (pub_r001457_5_1 <= 100));
  __CPROVER_assume((pub_r001457_5_2 >= (-100)) && (pub_r001457_5_2 <= 100));
  __CPROVER_assume((pub_r001457_6_1 >= (-100)) && (pub_r001457_6_1 <= 100));
  __CPROVER_assume((pub_r001457_6_2 >= (-100)) && (pub_r001457_6_2 <= 100));
  __CPROVER_assume((pub_r001457_7_1 >= (-100)) && (pub_r001457_7_1 <= 100));
  __CPROVER_assume((pub_r001457_7_2 >= (-100)) && (pub_r001457_7_2 <= 100));
  __CPROVER_assume((pub_r001457_8_1 >= (-100)) && (pub_r001457_8_1 <= 100));
  __CPROVER_assume((pub_r001457_8_2 >= (-100)) && (pub_r001457_8_2 <= 100));
  __CPROVER_assume((pub_r001457_9_1 >= (-100)) && (pub_r001457_9_1 <= 100));
  __CPROVER_assume((pub_r001457_9_2 >= (-100)) && (pub_r001457_9_2 <= 100));
  __CPROVER_assume((pub_r001457_10_1 >= (-100)) && (pub_r001457_10_1 <= 100));
  __CPROVER_assume((pub_r001457_10_2 >= (-100)) && (pub_r001457_10_2 <= 100));
  __CPROVER_assume((pub_r001457_11_1 >= (-100)) && (pub_r001457_11_1 <= 100));
  __CPROVER_assume((pub_r001457_11_2 >= (-100)) && (pub_r001457_11_2 <= 100));
  __CPROVER_assume((pub_r001457_12_1 >= (-100)) && (pub_r001457_12_1 <= 100));
  __CPROVER_assume((pub_r001457_12_2 >= (-100)) && (pub_r001457_12_2 <= 100));
  __CPROVER_assume((pub_r001457_13_1 >= (-100)) && (pub_r001457_13_1 <= 100));
  __CPROVER_assume((pub_r001457_13_2 >= (-100)) && (pub_r001457_13_2 <= 100));
  __CPROVER_assume((pub_r001457_14_1 >= (-100)) && (pub_r001457_14_1 <= 100));
  __CPROVER_assume((pub_r001457_14_2 >= (-100)) && (pub_r001457_14_2 <= 100));
  __CPROVER_assume((pub_r001457_15_1 >= (-100)) && (pub_r001457_15_1 <= 100));
  __CPROVER_assume((pub_r001457_15_2 >= (-100)) && (pub_r001457_15_2 <= 100));
  __CPROVER_assume((pub_r001457_16_1 >= (-100)) && (pub_r001457_16_1 <= 100));
  __CPROVER_assume((pub_r001457_16_2 >= (-100)) && (pub_r001457_16_2 <= 100));
  __CPROVER_assume((sec_r001457_0_1 >= 0) && (sec_r001457_0_1 <= 255));
  __CPROVER_assume((sec_r001457_0_2 >= 0) && (sec_r001457_0_2 <= 255));
  __CPROVER_assume((sec_r001457_1_1 >= 0) && (sec_r001457_1_1 <= 255));
  __CPROVER_assume((sec_r001457_1_2 >= 0) && (sec_r001457_1_2 <= 255));
  __CPROVER_assume((sec_r001457_2_1 >= 0) && (sec_r001457_2_1 <= 255));
  __CPROVER_assume((sec_r001457_2_2 >= 0) && (sec_r001457_2_2 <= 255));
  __CPROVER_assume((sec_r001457_3_1 >= 0) && (sec_r001457_3_1 <= 255));
  __CPROVER_assume((sec_r001457_3_2 >= 0) && (sec_r001457_3_2 <= 255));
  __CPROVER_assume((sec_r001457_4_1 >= 0) && (sec_r001457_4_1 <= 255));
  __CPROVER_assume((sec_r001457_4_2 >= 0) && (sec_r001457_4_2 <= 255));
  __CPROVER_assume((sec_r001457_5_1 >= 0) && (sec_r001457_5_1 <= 255));
  __CPROVER_assume((sec_r001457_5_2 >= 0) && (sec_r001457_5_2 <= 255));
  __CPROVER_assume((sec_r001457_6_1 >= 0) && (sec_r001457_6_1 <= 255));
  __CPROVER_assume((sec_r001457_6_2 >= 0) && (sec_r001457_6_2 <= 255));
  __CPROVER_assume((sec_r001457_7_1 >= 0) && (sec_r001457_7_1 <= 255));
  __CPROVER_assume((sec_r001457_7_2 >= 0) && (sec_r001457_7_2 <= 255));
  __CPROVER_assume((sec_r001457_8_1 >= 0) && (sec_r001457_8_1 <= 255));
  __CPROVER_assume((sec_r001457_8_2 >= 0) && (sec_r001457_8_2 <= 255));
  __CPROVER_assume((sec_r001457_9_1 >= 0) && (sec_r001457_9_1 <= 255));
  __CPROVER_assume((sec_r001457_9_2 >= 0) && (sec_r001457_9_2 <= 255));
  __CPROVER_assume((sec_r001457_10_1 >= 0) && (sec_r001457_10_1 <= 255));
  __CPROVER_assume((sec_r001457_10_2 >= 0) && (sec_r001457_10_2 <= 255));
  __CPROVER_assume((sec_r001457_11_1 >= 0) && (sec_r001457_11_1 <= 255));
  __CPROVER_assume((sec_r001457_11_2 >= 0) && (sec_r001457_11_2 <= 255));
  __CPROVER_assume((sec_r001457_12_1 >= 0) && (sec_r001457_12_1 <= 255));
  __CPROVER_assume((sec_r001457_12_2 >= 0) && (sec_r001457_12_2 <= 255));
  __CPROVER_assume((sec_r001457_13_1 >= 0) && (sec_r001457_13_1 <= 255));
  __CPROVER_assume((sec_r001457_13_2 >= 0) && (sec_r001457_13_2 <= 255));
  __CPROVER_assume((sec_r001457_14_1 >= 0) && (sec_r001457_14_1 <= 255));
  __CPROVER_assume((sec_r001457_14_2 >= 0) && (sec_r001457_14_2 <= 255));
  __CPROVER_assume((sec_r001457_15_1 >= 0) && (sec_r001457_15_1 <= 255));
  __CPROVER_assume((sec_r001457_15_2 >= 0) && (sec_r001457_15_2 <= 255));
  __CPROVER_assume((sec_r001457_16_1 >= 0) && (sec_r001457_16_1 <= 255));
  __CPROVER_assume((sec_r001457_16_2 >= 0) && (sec_r001457_16_2 <= 255));
  __CPROVER_assume((sec_r001457_17_1 >= 0) && (sec_r001457_17_1 <= 255));
  __CPROVER_assume((sec_r001457_17_2 >= 0) && (sec_r001457_17_2 <= 255));
  __CPROVER_assume((sec_r001457_18_1 >= 0) && (sec_r001457_18_1 <= 255));
  __CPROVER_assume((sec_r001457_18_2 >= 0) && (sec_r001457_18_2 <= 255));
  struct FilterState_R001457_5713_0 st_var_0_1 = {0};
  struct FilterState_R001457_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001457_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001457_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001457_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001457_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001457_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001457_0_2 + 7) & 15;
  struct DeviceConfig_R001457_5713_1 st_var_1_1 = {0};
  struct DeviceConfig_R001457_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001457_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001457_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001457_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001457_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001457_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001457_0_2 + 9) & 15;
  struct StreamBuffer_R001457_5713_2 st_var_2_1 = {0};
  struct StreamBuffer_R001457_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001457_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001457_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001457_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001457_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001457_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001457_0_2 + 11) & 15;
  union RegisterBank_R001457_5713_0 u_var_1;
  union RegisterBank_R001457_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001457_5713_0(sec_r001457_0_1, sec_r001457_1_1, pub_r001457_2_1);
  int helper_flow_0_2 = fn_R001457_5713_0(sec_r001457_0_2, sec_r001457_1_2, pub_r001457_2_2);
  fn_R001457_5713_0_2(sec_r001457_0_1, sec_r001457_1_1, pub_r001457_2_1, sec_r001457_0_2, sec_r001457_1_2, pub_r001457_2_2);
  int helper_flow_1_1 = fn_R001457_5713_1(sec_r001457_1_1, pub_r001457_2_1, pub_r001457_3_1, pub_r001457_4_1, pub_r001457_5_1);
  int helper_flow_1_2 = fn_R001457_5713_1(sec_r001457_1_2, pub_r001457_2_2, pub_r001457_3_2, pub_r001457_4_2, pub_r001457_5_2);
  fn_R001457_5713_1_2(sec_r001457_1_1, pub_r001457_2_1, pub_r001457_3_1, pub_r001457_4_1, pub_r001457_5_1, sec_r001457_1_2, pub_r001457_2_2, pub_r001457_3_2, pub_r001457_4_2, pub_r001457_5_2);
  int helper_flow_2_1 = fn_R001457_5713_2(sec_r001457_2_1, pub_r001457_3_1);
  int helper_flow_2_2 = fn_R001457_5713_2(sec_r001457_2_2, pub_r001457_3_2);
  fn_R001457_5713_2_2(sec_r001457_2_1, pub_r001457_3_1, sec_r001457_2_2, pub_r001457_3_2);
  int helper_flow_3_1 = fn_R001457_5713_3(sec_r001457_3_1, pub_r001457_4_1, pub_r001457_5_1, pub_r001457_6_1, pub_r001457_7_1);
  int helper_flow_3_2 = fn_R001457_5713_3(sec_r001457_3_2, pub_r001457_4_2, pub_r001457_5_2, pub_r001457_6_2, pub_r001457_7_2);
  fn_R001457_5713_3_2(sec_r001457_3_1, pub_r001457_4_1, pub_r001457_5_1, pub_r001457_6_1, pub_r001457_7_1, sec_r001457_3_2, pub_r001457_4_2, pub_r001457_5_2, pub_r001457_6_2, pub_r001457_7_2);
  int helper_flow_4_1 = fn_R001457_5713_4(sec_r001457_4_1, pub_r001457_5_1, pub_r001457_6_1, pub_r001457_7_1, pub_r001457_8_1);
  int helper_flow_4_2 = fn_R001457_5713_4(sec_r001457_4_2, pub_r001457_5_2, pub_r001457_6_2, pub_r001457_7_2, pub_r001457_8_2);
  fn_R001457_5713_4_2(sec_r001457_4_1, pub_r001457_5_1, pub_r001457_6_1, pub_r001457_7_1, pub_r001457_8_1, sec_r001457_4_2, pub_r001457_5_2, pub_r001457_6_2, pub_r001457_7_2, pub_r001457_8_2);
  int helper_flow_5_1 = fn_R001457_5713_5(sec_r001457_5_1, sec_r001457_6_1);
  int helper_flow_5_2 = fn_R001457_5713_5(sec_r001457_5_2, sec_r001457_6_2);
  fn_R001457_5713_5_2(sec_r001457_5_1, sec_r001457_6_1, sec_r001457_5_2, sec_r001457_6_2);
  int helper_flow_6_1 = fn_R001457_5713_6(sec_r001457_6_1, sec_r001457_7_1, pub_r001457_8_1);
  int helper_flow_6_2 = fn_R001457_5713_6(sec_r001457_6_2, sec_r001457_7_2, pub_r001457_8_2);
  fn_R001457_5713_6_2(sec_r001457_6_1, sec_r001457_7_1, pub_r001457_8_1, sec_r001457_6_2, sec_r001457_7_2, pub_r001457_8_2);
  int stage_v_0_1 = ((pub_r001457_3_1 * 2) + 5) & 63;
  int stage_v_0_2 = ((pub_r001457_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001457_16_1 * 2) + 15) & 63;
  int stage_v_1_2 = ((pub_r001457_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001457_2_1 * 2) + 9) & 63;
  int stage_v_2_2 = ((pub_r001457_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (sec_r001457_1_1 ^ pub_r001457_2_1) & 63;
  int stage_v_3_2 = (sec_r001457_1_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001457_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((sec_r001457_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = ((pub_r001457_4_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001457_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001457_13_1 * 2) + 46) & 63;
  int stage_v_5_2 = ((pub_r001457_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (sec_r001457_6_1 ^ pub_r001457_4_1) & 63;
  int stage_v_6_2 = (sec_r001457_6_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001457_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001457_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001457_10_1 ^ pub_r001457_13_1) & 63;
  int stage_v_7_2 = (sec_r001457_10_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001457_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001457_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001457_5_1 * 2) + 26) & 63;
  int stage_v_8_2 = ((pub_r001457_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001457_11_1 ^ pub_r001457_8_1) & 63;
  int stage_v_9_2 = (sec_r001457_11_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001457_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001457_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (sec_r001457_15_1 ^ pub_r001457_15_1) & 63;
  int stage_v_10_2 = (sec_r001457_15_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = (helper_flow_6_1 ^ pub_r001457_5_1) & 63;
  int stage_v_11_2 = (helper_flow_6_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = (sec_r001457_3_1 ^ pub_r001457_8_1) & 63;
  int stage_v_12_2 = (sec_r001457_3_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001457_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r001457_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (stage_v_6_1 ^ pub_r001457_15_1) & 63;
  int stage_v_13_2 = (stage_v_6_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001457_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001457_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (sec_r001457_12_1 ^ pub_r001457_15_1) & 63;
  int stage_v_14_2 = (sec_r001457_12_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = ((pub_r001457_3_1 * 2) + 21) & 63;
  int stage_v_15_2 = ((pub_r001457_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (stage_v_12_1 ^ pub_r001457_1_1) & 63;
  int stage_v_16_2 = (stage_v_12_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = ((pub_r001457_0_1 * 2) + 20) & 63;
  int stage_v_17_2 = ((pub_r001457_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (sec_r001457_9_1 ^ pub_r001457_2_1) & 63;
  int stage_v_18_2 = (sec_r001457_9_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001457_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r001457_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = (sec_r001457_0_1 ^ pub_r001457_8_1) & 63;
  int stage_v_19_2 = (sec_r001457_0_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (sec_r001457_3_1 ^ pub_r001457_14_1) & 63;
  int stage_v_20_2 = (sec_r001457_3_2 ^ pub_r001457_14_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = (sec_r001457_12_1 ^ pub_r001457_14_1) & 63;
  int stage_v_21_2 = (sec_r001457_12_2 ^ pub_r001457_14_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001457_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r001457_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (sec_r001457_0_1 ^ pub_r001457_13_1) & 63;
  int stage_v_22_2 = (sec_r001457_0_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = ((pub_r001457_10_1 * 2) + 12) & 63;
  int stage_v_23_2 = ((pub_r001457_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (sec_r001457_10_1 ^ pub_r001457_6_1) & 63;
  int stage_v_24_2 = (sec_r001457_10_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001457_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r001457_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (helper_flow_2_1 ^ pub_r001457_6_1) & 63;
  int stage_v_25_2 = (helper_flow_2_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r001457_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r001457_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (sec_r001457_12_1 ^ pub_r001457_3_1) & 63;
  int stage_v_26_2 = (sec_r001457_12_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001457_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001457_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = ((pub_r001457_10_1 * 2) + 13) & 63;
  int stage_v_27_2 = ((pub_r001457_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (sec_r001457_1_1 ^ pub_r001457_2_1) & 63;
  int stage_v_28_2 = (sec_r001457_1_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001457_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r001457_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = ((pub_r001457_7_1 * 2) + 13) & 63;
  int stage_v_29_2 = ((pub_r001457_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (stage_v_11_1 ^ pub_r001457_2_1) & 63;
  int stage_v_30_2 = (stage_v_11_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r001457_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r001457_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (stage_v_9_1 ^ pub_r001457_2_1) & 63;
  int stage_v_31_2 = (stage_v_9_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (stage_v_19_1 ^ pub_r001457_4_1) & 63;
  int stage_v_32_2 = (stage_v_19_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r001457_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r001457_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (sec_r001457_5_1 ^ pub_r001457_13_1) & 63;
  int stage_v_33_2 = (sec_r001457_5_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = (sec_r001457_13_1 ^ pub_r001457_4_1) & 63;
  int stage_v_34_2 = (sec_r001457_13_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001457_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r001457_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = (sec_r001457_14_1 ^ pub_r001457_0_1) & 63;
  int stage_v_35_2 = (sec_r001457_14_2 ^ pub_r001457_0_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (helper_flow_2_1 ^ pub_r001457_9_1) & 63;
  int stage_v_36_2 = (helper_flow_2_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (sec_r001457_18_1 ^ pub_r001457_6_1) & 63;
  int stage_v_37_2 = (sec_r001457_18_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001457_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r001457_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (stage_v_28_1 ^ pub_r001457_2_1) & 63;
  int stage_v_38_2 = (stage_v_28_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r001457_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r001457_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = (stage_v_3_1 ^ pub_r001457_3_1) & 63;
  int stage_v_39_2 = (stage_v_3_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (stage_v_13_1 ^ pub_r001457_5_1) & 63;
  int stage_v_40_2 = (stage_v_13_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = (stage_v_16_1 ^ pub_r001457_5_1) & 63;
  int stage_v_41_2 = (stage_v_16_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  }
  int stage_v_42_1 = ((pub_r001457_12_1 * 2) + 22) & 63;
  int stage_v_42_2 = ((pub_r001457_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (helper_flow_4_1 ^ pub_r001457_4_1) & 63;
  int stage_v_43_2 = (helper_flow_4_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r001457_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r001457_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  }
  int stage_v_44_1 = (helper_flow_3_1 ^ pub_r001457_8_1) & 63;
  int stage_v_44_2 = (helper_flow_3_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_41_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((stage_v_41_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (stage_v_38_1 ^ pub_r001457_16_1) & 63;
  int stage_v_45_2 = (stage_v_38_2 ^ pub_r001457_16_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = ((pub_r001457_11_1 * 2) + 27) & 63;
  int stage_v_46_2 = ((pub_r001457_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (stage_v_6_1 ^ pub_r001457_3_1) & 63;
  int stage_v_47_2 = (stage_v_6_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r001457_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r001457_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = (stage_v_44_1 ^ pub_r001457_7_1) & 63;
  int stage_v_48_2 = (stage_v_44_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001457_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r001457_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (sec_r001457_3_1 ^ pub_r001457_12_1) & 63;
  int stage_v_49_2 = (sec_r001457_3_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r001457_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r001457_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = (stage_v_30_1 ^ pub_r001457_2_1) & 63;
  int stage_v_50_2 = (stage_v_30_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_49_1 ^ pub_r001457_9_1) & 63;
  int stage_v_51_2 = (stage_v_49_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (helper_flow_1_1 ^ pub_r001457_14_1) & 63;
  int stage_v_52_2 = (helper_flow_1_2 ^ pub_r001457_14_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = ((pub_r001457_4_1 * 2) + 19) & 63;
  int stage_v_53_2 = ((pub_r001457_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (helper_flow_4_1 ^ pub_r001457_14_1) & 63;
  int stage_v_54_2 = (helper_flow_4_2 ^ pub_r001457_14_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r001457_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r001457_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (sec_r001457_3_1 ^ pub_r001457_15_1) & 63;
  int stage_v_55_2 = (sec_r001457_3_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (stage_v_55_1 ^ pub_r001457_12_1) & 63;
  int stage_v_56_2 = (stage_v_55_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (stage_v_34_1 ^ pub_r001457_3_1) & 63;
  int stage_v_57_2 = (stage_v_34_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = ((pub_r001457_3_1 * 2) + 26) & 63;
  int stage_v_58_2 = ((pub_r001457_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001457_0_1 * 2) + 33) & 63;
  int stage_v_59_2 = ((pub_r001457_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (stage_v_11_1 ^ pub_r001457_7_1) & 63;
  int stage_v_60_2 = (stage_v_11_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r001457_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r001457_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (stage_v_35_1 ^ pub_r001457_2_1) & 63;
  int stage_v_61_2 = (stage_v_35_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = ((pub_r001457_7_1 * 2) + 34) & 63;
  int stage_v_62_2 = ((pub_r001457_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001457_12_1 * 2) + 10) & 63;
  int stage_v_63_2 = ((pub_r001457_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_35_1 ^ pub_r001457_7_1) & 63;
  int stage_v_64_2 = (stage_v_35_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r001457_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r001457_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = ((pub_r001457_2_1 * 2) + 34) & 63;
  int stage_v_65_2 = ((pub_r001457_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (helper_flow_1_1 ^ pub_r001457_10_1) & 63;
  int stage_v_66_2 = (helper_flow_1_2 ^ pub_r001457_10_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = (stage_v_57_1 ^ pub_r001457_13_1) & 63;
  int stage_v_67_2 = (stage_v_57_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (stage_v_43_1 ^ pub_r001457_11_1) & 63;
  int stage_v_68_2 = (stage_v_43_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001457_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r001457_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (helper_flow_1_1 ^ pub_r001457_9_1) & 63;
  int stage_v_69_2 = (helper_flow_1_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (stage_v_31_1 ^ pub_r001457_3_1) & 63;
  int stage_v_70_2 = (stage_v_31_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (stage_v_40_1 ^ pub_r001457_12_1) & 63;
  int stage_v_71_2 = (stage_v_40_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (sec_r001457_17_1 ^ pub_r001457_1_1) & 63;
  int stage_v_72_2 = (sec_r001457_17_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r001457_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r001457_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (sec_r001457_2_1 ^ pub_r001457_8_1) & 63;
  int stage_v_73_2 = (sec_r001457_2_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001457_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r001457_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = (sec_r001457_0_1 ^ pub_r001457_5_1) & 63;
  int stage_v_74_2 = (sec_r001457_0_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r001457_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r001457_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = ((pub_r001457_15_1 * 2) + 24) & 63;
  int stage_v_75_2 = ((pub_r001457_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001457_13_1 * 2) + 46) & 63;
  int stage_v_76_2 = ((pub_r001457_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (stage_v_39_1 ^ pub_r001457_2_1) & 63;
  int stage_v_77_2 = (stage_v_39_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (helper_flow_6_1 ^ pub_r001457_6_1) & 63;
  int stage_v_78_2 = (helper_flow_6_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = ((pub_r001457_4_1 * 2) + 38) & 63;
  int stage_v_79_2 = ((pub_r001457_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001457_7_1 * 2) + 11) & 63;
  int stage_v_80_2 = ((pub_r001457_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (helper_flow_3_1 ^ pub_r001457_13_1) & 63;
  int stage_v_81_2 = (helper_flow_3_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (stage_v_20_1 ^ pub_r001457_7_1) & 63;
  int stage_v_82_2 = (stage_v_20_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (helper_flow_0_1 ^ pub_r001457_8_1) & 63;
  int stage_v_83_2 = (helper_flow_0_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((stage_v_77_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_43_1 ^ pub_r001457_9_1) & 63;
  int stage_v_84_2 = (stage_v_43_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = (stage_v_37_1 ^ pub_r001457_10_1) & 63;
  int stage_v_85_2 = (stage_v_37_2 ^ pub_r001457_10_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = ((pub_r001457_16_1 * 2) + 25) & 63;
  int stage_v_86_2 = ((pub_r001457_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001457_2_1 * 2) + 50) & 63;
  int stage_v_87_2 = ((pub_r001457_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (sec_r001457_4_1 ^ pub_r001457_15_1) & 63;
  int stage_v_88_2 = (sec_r001457_4_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = (stage_v_77_1 ^ pub_r001457_8_1) & 63;
  int stage_v_89_2 = (stage_v_77_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (stage_v_60_1 ^ pub_r001457_5_1) & 63;
  int stage_v_90_2 = (stage_v_60_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = (stage_v_24_1 ^ pub_r001457_13_1) & 63;
  int stage_v_91_2 = (stage_v_24_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r001457_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r001457_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = (sec_r001457_4_1 ^ pub_r001457_3_1) & 63;
  int stage_v_92_2 = (sec_r001457_4_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = ((pub_r001457_8_1 * 2) + 34) & 63;
  int stage_v_93_2 = ((pub_r001457_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001457_5_1 * 2) + 18) & 63;
  int stage_v_94_2 = ((pub_r001457_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (sec_r001457_7_1 ^ pub_r001457_7_1) & 63;
  int stage_v_95_2 = (sec_r001457_7_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (sec_r001457_15_1 ^ pub_r001457_15_1) & 63;
  int stage_v_96_2 = (sec_r001457_15_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = ((pub_r001457_12_1 * 2) + 23) & 63;
  int stage_v_97_2 = ((pub_r001457_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (stage_v_36_1 ^ pub_r001457_8_1) & 63;
  int stage_v_98_2 = (stage_v_36_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = ((pub_r001457_13_1 * 2) + 24) & 63;
  int stage_v_99_2 = ((pub_r001457_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001457_7_1 * 2) + 15) & 63;
  int stage_v_100_2 = ((pub_r001457_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (stage_v_85_1 ^ pub_r001457_2_1) & 63;
  int stage_v_101_2 = (stage_v_85_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r001457_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r001457_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = (stage_v_44_1 ^ pub_r001457_9_1) & 63;
  int stage_v_102_2 = (stage_v_44_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = ((pub_r001457_7_1 * 2) + 26) & 63;
  int stage_v_103_2 = ((pub_r001457_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (stage_v_60_1 ^ pub_r001457_0_1) & 63;
  int stage_v_104_2 = (stage_v_60_2 ^ pub_r001457_0_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = ((pub_r001457_3_1 * 2) + 33) & 63;
  int stage_v_105_2 = ((pub_r001457_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (stage_v_78_1 ^ pub_r001457_15_1) & 63;
  int stage_v_106_2 = (stage_v_78_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001457_8_1 * 2) + 36) & 63;
  int stage_v_107_2 = ((pub_r001457_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (stage_v_25_1 ^ pub_r001457_16_1) & 63;
  int stage_v_108_2 = (stage_v_25_2 ^ pub_r001457_16_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (stage_v_69_1 ^ pub_r001457_1_1) & 63;
  int stage_v_109_2 = (stage_v_69_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = ((pub_r001457_8_1 * 2) + 28) & 63;
  int stage_v_110_2 = ((pub_r001457_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001457_3_1 * 2) + 11) & 63;
  int stage_v_111_2 = ((pub_r001457_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (stage_v_7_1 ^ pub_r001457_7_1) & 63;
  int stage_v_112_2 = (stage_v_7_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r001457_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r001457_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = (stage_v_101_1 ^ pub_r001457_1_1) & 63;
  int stage_v_113_2 = (stage_v_101_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (stage_v_70_1 ^ pub_r001457_15_1) & 63;
  int stage_v_114_2 = (stage_v_70_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = ((pub_r001457_12_1 * 2) + 28) & 63;
  int stage_v_115_2 = ((pub_r001457_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (stage_v_82_1 ^ pub_r001457_11_1) & 63;
  int stage_v_116_2 = (stage_v_82_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = (sec_r001457_11_1 ^ pub_r001457_12_1) & 63;
  int stage_v_117_2 = (sec_r001457_11_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = (stage_v_60_1 ^ pub_r001457_7_1) & 63;
  int stage_v_118_2 = (stage_v_60_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = (sec_r001457_8_1 ^ pub_r001457_16_1) & 63;
  int stage_v_119_2 = (sec_r001457_8_2 ^ pub_r001457_16_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = (stage_v_78_1 ^ pub_r001457_7_1) & 63;
  int stage_v_120_2 = (stage_v_78_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_109_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = ((pub_r001457_9_1 * 2) + 16) & 63;
  int stage_v_121_2 = ((pub_r001457_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (stage_v_41_1 ^ pub_r001457_6_1) & 63;
  int stage_v_122_2 = (stage_v_41_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (stage_v_13_1 ^ pub_r001457_11_1) & 63;
  int stage_v_123_2 = (stage_v_13_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_33_1 ^ pub_r001457_8_1) & 63;
  int stage_v_124_2 = (stage_v_33_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((stage_v_66_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (stage_v_112_1 ^ pub_r001457_9_1) & 63;
  int stage_v_125_2 = (stage_v_112_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = (stage_v_88_1 ^ pub_r001457_16_1) & 63;
  int stage_v_126_2 = (stage_v_88_2 ^ pub_r001457_16_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = (stage_v_33_1 ^ pub_r001457_13_1) & 63;
  int stage_v_127_2 = (stage_v_33_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = (stage_v_70_1 ^ pub_r001457_5_1) & 63;
  int stage_v_128_2 = (stage_v_70_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = ((pub_r001457_5_1 * 2) + 39) & 63;
  int stage_v_129_2 = ((pub_r001457_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (sec_r001457_5_1 ^ pub_r001457_9_1) & 63;
  int stage_v_130_2 = (sec_r001457_5_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = ((pub_r001457_9_1 * 2) + 29) & 63;
  int stage_v_131_2 = ((pub_r001457_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (stage_v_26_1 ^ pub_r001457_2_1) & 63;
  int stage_v_132_2 = (stage_v_26_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_24_1 ^ pub_r001457_4_1) & 63;
  int stage_v_133_2 = (stage_v_24_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001457_13_1 * 2) + 16) & 63;
  int stage_v_134_2 = ((pub_r001457_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (stage_v_64_1 ^ pub_r001457_3_1) & 63;
  int stage_v_135_2 = (stage_v_64_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = (stage_v_126_1 ^ pub_r001457_6_1) & 63;
  int stage_v_136_2 = (stage_v_126_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (sec_r001457_18_1 ^ pub_r001457_11_1) & 63;
  int stage_v_137_2 = (sec_r001457_18_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (stage_v_120_1 ^ pub_r001457_6_1) & 63;
  int stage_v_138_2 = (stage_v_120_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (sec_r001457_15_1 ^ pub_r001457_4_1) & 63;
  int stage_v_139_2 = (sec_r001457_15_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r001457_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r001457_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = (stage_v_22_1 ^ pub_r001457_6_1) & 63;
  int stage_v_140_2 = (stage_v_22_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = ((pub_r001457_0_1 * 2) + 9) & 63;
  int stage_v_141_2 = ((pub_r001457_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001457_4_1 * 2) + 10) & 63;
  int stage_v_142_2 = ((pub_r001457_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (stage_v_13_1 ^ pub_r001457_5_1) & 63;
  int stage_v_143_2 = (stage_v_13_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_89_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (stage_v_119_1 ^ pub_r001457_12_1) & 63;
  int stage_v_144_2 = (stage_v_119_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_68_1 ^ pub_r001457_8_1) & 63;
  int stage_v_145_2 = (stage_v_68_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (stage_v_143_1 ^ pub_r001457_3_1) & 63;
  int stage_v_146_2 = (stage_v_143_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r001457_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((sec_r001457_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = ((pub_r001457_13_1 * 2) + 8) & 63;
  int stage_v_147_2 = ((pub_r001457_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (sec_r001457_11_1 ^ pub_r001457_3_1) & 63;
  int stage_v_148_2 = (sec_r001457_11_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = (stage_v_37_1 ^ pub_r001457_2_1) & 63;
  int stage_v_149_2 = (stage_v_37_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (stage_v_18_1 ^ pub_r001457_16_1) & 63;
  int stage_v_150_2 = (stage_v_18_2 ^ pub_r001457_16_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r001457_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r001457_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = ((pub_r001457_13_1 * 2) + 6) & 63;
  int stage_v_151_2 = ((pub_r001457_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001457_14_1 * 2) + 16) & 63;
  int stage_v_152_2 = ((pub_r001457_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001457_16_1 * 2) + 20) & 63;
  int stage_v_153_2 = ((pub_r001457_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001457_7_1 * 2) + 32) & 63;
  int stage_v_154_2 = ((pub_r001457_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001457_14_1 * 2) + 30) & 63;
  int stage_v_155_2 = ((pub_r001457_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (stage_v_41_1 ^ pub_r001457_7_1) & 63;
  int stage_v_156_2 = (stage_v_41_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = ((pub_r001457_13_1 * 2) + 48) & 63;
  int stage_v_157_2 = ((pub_r001457_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (stage_v_149_1 ^ pub_r001457_6_1) & 63;
  int stage_v_158_2 = (stage_v_149_2 ^ pub_r001457_6_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = ((pub_r001457_12_1 * 2) + 36) & 63;
  int stage_v_159_2 = ((pub_r001457_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001457_1_1 * 2) + 43) & 63;
  int stage_v_160_2 = ((pub_r001457_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001457_8_1 * 2) + 33) & 63;
  int stage_v_161_2 = ((pub_r001457_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (stage_v_138_1 ^ pub_r001457_10_1) & 63;
  int stage_v_162_2 = (stage_v_138_2 ^ pub_r001457_10_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_133_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_133_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = ((pub_r001457_15_1 * 2) + 15) & 63;
  int stage_v_163_2 = ((pub_r001457_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (sec_r001457_6_1 ^ pub_r001457_12_1) & 63;
  int stage_v_164_2 = (sec_r001457_6_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_36_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_34_1 ^ pub_r001457_1_1) & 63;
  int stage_v_165_2 = (stage_v_34_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_78_1 ^ pub_r001457_1_1) & 63;
  int stage_v_166_2 = (stage_v_78_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_112_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_60_1 ^ pub_r001457_4_1) & 63;
  int stage_v_167_2 = (stage_v_60_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = (sec_r001457_10_1 ^ pub_r001457_11_1) & 63;
  int stage_v_168_2 = (sec_r001457_10_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_38_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (stage_v_36_1 ^ pub_r001457_13_1) & 63;
  int stage_v_169_2 = (stage_v_36_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((sec_r001457_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((sec_r001457_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = (stage_v_16_1 ^ pub_r001457_12_1) & 63;
  int stage_v_170_2 = (stage_v_16_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (stage_v_83_1 ^ pub_r001457_3_1) & 63;
  int stage_v_171_2 = (stage_v_83_2 ^ pub_r001457_3_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = (helper_flow_1_1 ^ pub_r001457_13_1) & 63;
  int stage_v_172_2 = (helper_flow_1_2 ^ pub_r001457_13_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = (stage_v_127_1 ^ pub_r001457_4_1) & 63;
  int stage_v_173_2 = (stage_v_127_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((sec_r001457_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((sec_r001457_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = (stage_v_125_1 ^ pub_r001457_1_1) & 63;
  int stage_v_174_2 = (stage_v_125_2 ^ pub_r001457_1_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = ((pub_r001457_8_1 * 2) + 6) & 63;
  int stage_v_175_2 = ((pub_r001457_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001457_12_1 * 2) + 34) & 63;
  int stage_v_176_2 = ((pub_r001457_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001457_12_1 * 2) + 24) & 63;
  int stage_v_177_2 = ((pub_r001457_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001457_5_1 * 2) + 29) & 63;
  int stage_v_178_2 = ((pub_r001457_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (stage_v_173_1 ^ pub_r001457_11_1) & 63;
  int stage_v_179_2 = (stage_v_173_2 ^ pub_r001457_11_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((sec_r001457_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((sec_r001457_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001457_11_1 * 2) + 20) & 63;
  int stage_v_180_2 = ((pub_r001457_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (helper_flow_5_1 ^ pub_r001457_0_1) & 63;
  int stage_v_181_2 = (helper_flow_5_2 ^ pub_r001457_0_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = (stage_v_168_1 ^ pub_r001457_8_1) & 63;
  int stage_v_182_2 = (stage_v_168_2 ^ pub_r001457_8_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_7_1 ^ pub_r001457_10_1) & 63;
  int stage_v_183_2 = (stage_v_7_2 ^ pub_r001457_10_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = (stage_v_150_1 ^ pub_r001457_2_1) & 63;
  int stage_v_184_2 = (stage_v_150_2 ^ pub_r001457_2_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_128_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((stage_v_128_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = ((pub_r001457_14_1 * 2) + 29) & 63;
  int stage_v_185_2 = ((pub_r001457_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (sec_r001457_1_1 ^ pub_r001457_5_1) & 63;
  int stage_v_186_2 = (sec_r001457_1_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_116_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((stage_v_116_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = (stage_v_146_1 ^ pub_r001457_7_1) & 63;
  int stage_v_187_2 = (stage_v_146_2 ^ pub_r001457_7_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  }
  if ((stage_v_187_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  }
  int stage_v_188_1 = ((pub_r001457_12_1 * 2) + 36) & 63;
  int stage_v_188_2 = ((pub_r001457_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (helper_flow_0_1 ^ pub_r001457_5_1) & 63;
  int stage_v_189_2 = (helper_flow_0_2 ^ pub_r001457_5_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  }
  if ((stage_v_189_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  }
  int stage_v_190_1 = (stage_v_109_1 ^ pub_r001457_12_1) & 63;
  int stage_v_190_2 = (stage_v_109_2 ^ pub_r001457_12_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  }
  if ((stage_v_190_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  }
  int stage_v_191_1 = (stage_v_43_1 ^ pub_r001457_9_1) & 63;
  int stage_v_191_2 = (stage_v_43_2 ^ pub_r001457_9_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_156_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((stage_v_156_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = (stage_v_48_1 ^ pub_r001457_15_1) & 63;
  int stage_v_192_2 = (stage_v_48_2 ^ pub_r001457_15_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((sec_r001457_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((sec_r001457_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  int stage_v_193_1 = (sec_r001457_1_1 ^ pub_r001457_4_1) & 63;
  int stage_v_193_2 = (sec_r001457_1_2 ^ pub_r001457_4_2) & 63;
  if ((stage_v_193_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  }
  if ((stage_v_193_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001457_13_1 == pub_r001457_13_2);
  __CPROVER_assume(pub_r001457_11_1 == pub_r001457_11_2);
  __CPROVER_assume(pub_r001457_16_1 == pub_r001457_16_2);
  __CPROVER_assume(sec_r001457_18_1 != sec_r001457_18_2);
  __CPROVER_assume(pub_r001457_15_1 == pub_r001457_15_2);
  __CPROVER_assume(sec_r001457_8_1 != sec_r001457_8_2);
  __CPROVER_assume(sec_r001457_5_1 != sec_r001457_5_2);
  __CPROVER_assume(sec_r001457_11_1 != sec_r001457_11_2);
  __CPROVER_assume(pub_r001457_4_1 == pub_r001457_4_2);
  __CPROVER_assume(pub_r001457_8_1 == pub_r001457_8_2);
  __CPROVER_assume(sec_r001457_16_1 != sec_r001457_16_2);
  __CPROVER_assume(sec_r001457_3_1 != sec_r001457_3_2);
  __CPROVER_assume(pub_r001457_10_1 == pub_r001457_10_2);
  __CPROVER_assume(pub_r001457_2_1 == pub_r001457_2_2);
  __CPROVER_assume(sec_r001457_12_1 != sec_r001457_12_2);
  __CPROVER_assume(sec_r001457_1_1 != sec_r001457_1_2);
  __CPROVER_assume(sec_r001457_4_1 != sec_r001457_4_2);
  __CPROVER_assume(pub_r001457_1_1 == pub_r001457_1_2);
  __CPROVER_assume(pub_r001457_0_1 == pub_r001457_0_2);
  __CPROVER_assume(pub_r001457_14_1 == pub_r001457_14_2);
  __CPROVER_assume(sec_r001457_14_1 != sec_r001457_14_2);
  __CPROVER_assume(sec_r001457_13_1 != sec_r001457_13_2);
  __CPROVER_assume(sec_r001457_7_1 != sec_r001457_7_2);
  __CPROVER_assume(pub_r001457_3_1 == pub_r001457_3_2);
  __CPROVER_assume(sec_r001457_6_1 != sec_r001457_6_2);
  __CPROVER_assume(pub_r001457_6_1 == pub_r001457_6_2);
  __CPROVER_assume(sec_r001457_9_1 != sec_r001457_9_2);
  __CPROVER_assume(pub_r001457_9_1 == pub_r001457_9_2);
  __CPROVER_assume(pub_r001457_7_1 == pub_r001457_7_2);
  __CPROVER_assume(sec_r001457_10_1 != sec_r001457_10_2);
  __CPROVER_assume(sec_r001457_0_1 != sec_r001457_0_2);
  __CPROVER_assume(sec_r001457_2_1 != sec_r001457_2_2);
  __CPROVER_assume(pub_r001457_5_1 == pub_r001457_5_2);
  __CPROVER_assume(sec_r001457_15_1 != sec_r001457_15_2);
  __CPROVER_assume(sec_r001457_17_1 != sec_r001457_17_2);
  __CPROVER_assume(pub_r001457_12_1 == pub_r001457_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
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
}


