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
struct MatrixBlock_R001402_213_0
{
  int trace;
  int stride;
  unsigned char scale;
  unsigned char density;
  int determinant;
  int buffer[3];
};
struct StreamBuffer_R001402_213_1
{
  short state;
  int watermark;
  int tail;
  unsigned char capacity;
  int head;
  int checksum;
  int buffer[3];
};
struct DeviceConfig_R001402_213_2
{
  unsigned char baud_rate;
  unsigned char timeout;
  int id;
  int buffer[3];
};
union PacketPayload_R001402_213_0
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
void fn_R001402_213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_46_1 = 0;
  int damping_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_46_1 = ((damping_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_46_2 = ((damping_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_46_1) & 127;
    acc_2 = (acc_2 + damping_46_2) & 127;
  }

  int bound_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_57_1)
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

  switch (bound_57_2)
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
  int phase_61_1 = local_arr_1[aux_1 % 3];
  int phase_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_46_1 == damping_46_2);
  assert(bound_57_1 == bound_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_61_1 == phase_61_2);
}

int fn_R001402_213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_46 = ((damping_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_46) & 127;
  }

  int bound_57 = (aux + st.buffer[1]) & 3;
  switch (bound_57)
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
  int phase_61 = local_arr[aux % 3];
  acc = (acc + (phase_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st_1 = {0};
  struct MatrixBlock_R001402_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_57_1) & 63;
  aux_2 = (aux_2 + sample_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_85_1 > 10)
  {
    acc_1 = ((acc_1 + (checksum_85_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_85_2 > 10)
  {
    acc_2 = ((acc_2 + (checksum_85_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_94_1 = 0;
  int tally_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_94_1 = ((tally_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_94_2 = ((tally_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_94_1) & 127;
    acc_2 = (acc_2 + tally_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_57_1 == sample_57_2);
  assert(checksum_85_1 == checksum_85_2);
  assert(tally_94_1 == tally_94_2);
}

int fn_R001402_213_1(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_57) & 63;
  acc ^= aux;
  int checksum_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_85 > 10)
  {
    acc = ((acc + (checksum_85 * 2)) + 5) & 127;
    aux ^= checksum_85 & 15;
  }
  else
  {
    acc = ((acc - checksum_85) + 11) & 127;
    aux += 3;
  }
  int tally_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_94 = ((tally_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001402_213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int parity_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_19_1) & 63;
  aux_2 = (aux_2 + parity_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_16_1 > 29)
  {
    acc_1 = ((acc_1 + (residue_16_1 * 2)) + 5) & 127;
    aux_1 ^= residue_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_16_2 > 29)
  {
    acc_2 = ((acc_2 + (residue_16_2 * 2)) + 5) & 127;
    aux_2 ^= residue_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_19_1 == parity_19_2);
  assert(residue_16_1 == residue_16_2);
}

int fn_R001402_213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int parity_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_19) & 63;
  acc ^= aux;
  int residue_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_16 > 29)
  {
    acc = ((acc + (residue_16 * 2)) + 5) & 127;
    aux ^= residue_16 & 15;
  }
  else
  {
    acc = ((acc - residue_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001402_213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st_1 = {0};
  struct MatrixBlock_R001402_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quotient_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_21_1) & 63;
  aux_2 = (aux_2 + quotient_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_93_1 > 38)
  {
    acc_1 = ((acc_1 + (segment_93_1 * 2)) + 5) & 127;
    aux_1 ^= segment_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_93_2 > 38)
  {
    acc_2 = ((acc_2 + (segment_93_2 * 2)) + 5) & 127;
    aux_2 ^= segment_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_92_1 = 0;
  int factor_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_92_1 = ((factor_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_92_2 = ((factor_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_92_1) & 127;
    acc_2 = (acc_2 + factor_92_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_21_1 == quotient_21_2);
  assert(segment_93_1 == segment_93_2);
  assert(factor_92_1 == factor_92_2);
}

int fn_R001402_213_3(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quotient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_21) & 63;
  acc ^= aux;
  int segment_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_93 > 38)
  {
    acc = ((acc + (segment_93 * 2)) + 5) & 127;
    aux ^= segment_93 & 15;
  }
  else
  {
    acc = ((acc - segment_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_92 = ((factor_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_92) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001402_213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int phase_82_1 = 0;
  int phase_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_82_1 = ((phase_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_82_2 = ((phase_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_82_1) & 127;
    acc_2 = (acc_2 + phase_82_2) & 127;
  }

  int checksum_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_55_1)
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

  switch (checksum_55_2)
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
  int stride_27_1 = local_arr_1[aux_1 % 3];
  int stride_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_27_2 * 2)) & 127;
  int parity_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_25_1 > 12)
  {
    acc_1 = ((acc_1 + (parity_25_1 * 2)) + 5) & 127;
    aux_1 ^= parity_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_25_2 > 12)
  {
    acc_2 = ((acc_2 + (parity_25_2 * 2)) + 5) & 127;
    aux_2 ^= parity_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_82_1 == phase_82_2);
  assert(checksum_55_1 == checksum_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_27_1 == stride_27_2);
  assert(parity_25_1 == parity_25_2);
}

int fn_R001402_213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int phase_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_82 = ((phase_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_82) & 127;
  }

  int checksum_55 = (aux + st.buffer[1]) & 3;
  switch (checksum_55)
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
  int stride_27 = local_arr[aux % 3];
  acc = (acc + (stride_27 * 2)) & 127;
  int parity_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_25 > 12)
  {
    acc = ((acc + (parity_25 * 2)) + 5) & 127;
    aux ^= parity_25 & 15;
  }
  else
  {
    acc = ((acc - parity_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001402_213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_33_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_33_1 * 2)) + 5) & 127;
    aux_1 ^= stride_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_33_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_33_2 * 2)) + 5) & 127;
    aux_2 ^= stride_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_15_1 = local_arr_1[aux_1 % 3];
  int cursor_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_33_1 == stride_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_15_1 == cursor_15_2);
}

int fn_R001402_213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_33 > 30)
  {
    acc = ((acc + (stride_33 * 2)) + 5) & 127;
    aux ^= stride_33 & 15;
  }
  else
  {
    acc = ((acc - stride_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_15 = local_arr[aux % 3];
  acc = (acc + (cursor_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_45_1)
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

  switch (accumulator_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_45_1 == accumulator_45_2);
}

int fn_R001402_213_6(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_45 = (aux + st.buffer[1]) & 3;
  switch (accumulator_45)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_24_1)
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

  switch (scale_24_2)
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

  int pivot_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_95_1) & 63;
  aux_2 = (aux_2 + pivot_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_98_1 = local_arr_1[aux_1 % 3];
  int checksum_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_98_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_24_1 == scale_24_2);
  assert(pivot_95_1 == pivot_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_98_1 == checksum_98_2);
}

int fn_R001402_213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_24 = (aux + st.buffer[1]) & 3;
  switch (scale_24)
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

  int pivot_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_98 = local_arr[aux % 3];
  acc = (acc + (checksum_98 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st_1 = {0};
  struct MatrixBlock_R001402_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_61_1)
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

  switch (mask_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_61_1 == mask_61_2);
}

int fn_R001402_213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_61 = (aux + st.buffer[1]) & 3;
  switch (mask_61)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_82_1) & 63;
  aux_2 = (aux_2 + sample_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_82_1 == sample_82_2);
}

int fn_R001402_213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_65_1) & 63;
  aux_2 = (aux_2 + scale_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_12_1 = local_arr_1[aux_1 % 3];
  int phase_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_12_2 * 2)) & 127;
  int margin_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_47_1)
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

  switch (margin_47_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_65_1 == scale_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_12_1 == phase_12_2);
  assert(margin_47_1 == margin_47_2);
}

int fn_R001402_213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_12 = local_arr[aux % 3];
  acc = (acc + (phase_12 * 2)) & 127;
  int margin_47 = (aux + st.buffer[1]) & 3;
  switch (margin_47)
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

void fn_R001402_213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int mask_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_93_1)
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

  switch (mask_93_2)
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

  int tracker_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_35_1 > 34)
  {
    acc_1 = ((acc_1 + (tracker_35_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_35_2 > 34)
  {
    acc_2 = ((acc_2 + (tracker_35_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_93_1 == mask_93_2);
  assert(tracker_35_1 == tracker_35_2);
}

int fn_R001402_213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int mask_93 = (aux + st.buffer[1]) & 3;
  switch (mask_93)
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

  int tracker_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_35 > 34)
  {
    acc = ((acc + (tracker_35 * 2)) + 5) & 127;
    aux ^= tracker_35 & 15;
  }
  else
  {
    acc = ((acc - tracker_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001402_213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st_1 = {0};
  struct DeviceConfig_R001402_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int index_reg_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_61_1)
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

  switch (index_reg_61_2)
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

  int parity_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_35_1) & 63;
  aux_2 = (aux_2 + parity_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  assert(parity_35_1 == parity_35_2);
}

int fn_R001402_213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001402_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int index_reg_61 = (aux + st.buffer[1]) & 3;
  switch (index_reg_61)
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

  int parity_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001402_213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st_1 = {0};
  struct MatrixBlock_R001402_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_30_1)
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

  switch (weight_30_2)
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

  int damping_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_46_1 > 41)
  {
    acc_1 = ((acc_1 + (damping_46_1 * 2)) + 5) & 127;
    aux_1 ^= damping_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_46_2 > 41)
  {
    acc_2 = ((acc_2 + (damping_46_2 * 2)) + 5) & 127;
    aux_2 ^= damping_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_30_1 == weight_30_2);
  assert(damping_46_1 == damping_46_2);
}

int fn_R001402_213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_30 = (aux + st.buffer[1]) & 3;
  switch (weight_30)
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

  int damping_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_46 > 41)
  {
    acc = ((acc + (damping_46 * 2)) + 5) & 127;
    aux ^= damping_46 & 15;
  }
  else
  {
    acc = ((acc - damping_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001402_213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_98_1 > 19)
  {
    acc_1 = ((acc_1 + (checksum_98_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_98_2 > 19)
  {
    acc_2 = ((acc_2 + (checksum_98_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_38_1)
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

  switch (cursor_38_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(cursor_38_1 == cursor_38_2);
}

int fn_R001402_213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_98 > 19)
  {
    acc = ((acc + (checksum_98 * 2)) + 5) & 127;
    aux ^= checksum_98 & 15;
  }
  else
  {
    acc = ((acc - checksum_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_38 = (aux + st.buffer[1]) & 3;
  switch (cursor_38)
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

void fn_R001402_213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_18_1 = local_arr_1[aux_1 % 3];
  int margin_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_18_2 * 2)) & 127;
  int sample_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_27_1 > 46)
  {
    acc_1 = ((acc_1 + (sample_27_1 * 2)) + 5) & 127;
    aux_1 ^= sample_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_27_2 > 46)
  {
    acc_2 = ((acc_2 + (sample_27_2 * 2)) + 5) & 127;
    aux_2 ^= sample_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
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

  assert(margin_18_1 == margin_18_2);
  assert(sample_27_1 == sample_27_2);
}

int fn_R001402_213_15(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int margin_18 = local_arr[aux % 3];
  acc = (acc + (margin_18 * 2)) & 127;
  int sample_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_27 > 46)
  {
    acc = ((acc + (sample_27 * 2)) + 5) & 127;
    aux ^= sample_27 & 15;
  }
  else
  {
    acc = ((acc - sample_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001402_213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st_1 = {0};
  struct MatrixBlock_R001402_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_38_1 = 0;
  int stride_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_38_1 = ((stride_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_38_2 = ((stride_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_38_1) & 127;
    acc_2 = (acc_2 + stride_38_2) & 127;
  }

  int bound_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_86_1) & 63;
  aux_2 = (aux_2 + bound_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_38_1 == stride_38_2);
  assert(bound_86_1 == bound_86_2);
}

int fn_R001402_213_16(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001402_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_38 = ((stride_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_38) & 127;
  }

  int bound_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001402_213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int cursor_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_96_1)
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

  switch (cursor_96_2)
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
  if (metric_47_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_47_1 * 2)) + 5) & 127;
    aux_1 ^= metric_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_47_2 > 34)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_96_1 == cursor_96_2);
  assert(metric_47_1 == metric_47_2);
}

int fn_R001402_213_17(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int cursor_96 = (aux + st.buffer[1]) & 3;
  switch (cursor_96)
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
  if (metric_47 > 34)
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

void fn_R001402_213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st_1 = {0};
  struct StreamBuffer_R001402_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_55_1)
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

  switch (tracker_55_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_58_1 = local_arr_1[aux_1 % 3];
  int phase_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_55_1 == tracker_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_58_1 == phase_58_2);
}

int fn_R001402_213_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001402_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_55 = (aux + st.buffer[1]) & 3;
  switch (tracker_55)
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

  int local_arr[3] = {4, 9, 15};
  int phase_58 = local_arr[aux % 3];
  acc = (acc + (phase_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001402_0_1;
  int sec_r001402_0_2;
  int sec_r001402_1_1;
  int sec_r001402_1_2;
  int sec_r001402_2_1;
  int sec_r001402_2_2;
  int sec_r001402_3_1;
  int sec_r001402_3_2;
  int sec_r001402_4_1;
  int sec_r001402_4_2;
  int sec_r001402_5_1;
  int sec_r001402_5_2;
  int sec_r001402_6_1;
  int sec_r001402_6_2;
  int sec_r001402_7_1;
  int sec_r001402_7_2;
  int sec_r001402_8_1;
  int sec_r001402_8_2;
  int sec_r001402_9_1;
  int sec_r001402_9_2;
  int sec_r001402_10_1;
  int sec_r001402_10_2;
  int sec_r001402_11_1;
  int sec_r001402_11_2;
  int sec_r001402_12_1;
  int sec_r001402_12_2;
  int sec_r001402_13_1;
  int sec_r001402_13_2;
  int sec_r001402_14_1;
  int sec_r001402_14_2;
  int sec_r001402_15_1;
  int sec_r001402_15_2;
  int sec_r001402_16_1;
  int sec_r001402_16_2;
  int sec_r001402_17_1;
  int sec_r001402_17_2;
  int sec_r001402_18_1;
  int sec_r001402_18_2;
  int sec_r001402_19_1;
  int sec_r001402_19_2;
  int sec_r001402_20_1;
  int sec_r001402_20_2;
  int pub_r001402_0_1;
  int pub_r001402_0_2;
  int pub_r001402_1_1;
  int pub_r001402_1_2;
  int pub_r001402_2_1;
  int pub_r001402_2_2;
  int pub_r001402_3_1;
  int pub_r001402_3_2;
  int pub_r001402_4_1;
  int pub_r001402_4_2;
  int pub_r001402_5_1;
  int pub_r001402_5_2;
  int pub_r001402_6_1;
  int pub_r001402_6_2;
  int pub_r001402_7_1;
  int pub_r001402_7_2;
  int pub_r001402_8_1;
  int pub_r001402_8_2;
  int pub_r001402_9_1;
  int pub_r001402_9_2;
  int pub_r001402_10_1;
  int pub_r001402_10_2;
  int pub_r001402_11_1;
  int pub_r001402_11_2;
  int pub_r001402_12_1;
  int pub_r001402_12_2;
  int pub_r001402_13_1;
  int pub_r001402_13_2;
  int pub_r001402_14_1;
  int pub_r001402_14_2;
  int pub_r001402_15_1;
  int pub_r001402_15_2;
  int pub_r001402_16_1;
  int pub_r001402_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001402_0_1 >= (-100)) && (pub_r001402_0_1 <= 100));
  __CPROVER_assume((pub_r001402_0_2 >= (-100)) && (pub_r001402_0_2 <= 100));
  __CPROVER_assume((pub_r001402_1_1 >= (-100)) && (pub_r001402_1_1 <= 100));
  __CPROVER_assume((pub_r001402_1_2 >= (-100)) && (pub_r001402_1_2 <= 100));
  __CPROVER_assume((pub_r001402_2_1 >= (-100)) && (pub_r001402_2_1 <= 100));
  __CPROVER_assume((pub_r001402_2_2 >= (-100)) && (pub_r001402_2_2 <= 100));
  __CPROVER_assume((pub_r001402_3_1 >= (-100)) && (pub_r001402_3_1 <= 100));
  __CPROVER_assume((pub_r001402_3_2 >= (-100)) && (pub_r001402_3_2 <= 100));
  __CPROVER_assume((pub_r001402_4_1 >= (-100)) && (pub_r001402_4_1 <= 100));
  __CPROVER_assume((pub_r001402_4_2 >= (-100)) && (pub_r001402_4_2 <= 100));
  __CPROVER_assume((pub_r001402_5_1 >= (-100)) && (pub_r001402_5_1 <= 100));
  __CPROVER_assume((pub_r001402_5_2 >= (-100)) && (pub_r001402_5_2 <= 100));
  __CPROVER_assume((pub_r001402_6_1 >= (-100)) && (pub_r001402_6_1 <= 100));
  __CPROVER_assume((pub_r001402_6_2 >= (-100)) && (pub_r001402_6_2 <= 100));
  __CPROVER_assume((pub_r001402_7_1 >= (-100)) && (pub_r001402_7_1 <= 100));
  __CPROVER_assume((pub_r001402_7_2 >= (-100)) && (pub_r001402_7_2 <= 100));
  __CPROVER_assume((pub_r001402_8_1 >= (-100)) && (pub_r001402_8_1 <= 100));
  __CPROVER_assume((pub_r001402_8_2 >= (-100)) && (pub_r001402_8_2 <= 100));
  __CPROVER_assume((pub_r001402_9_1 >= (-100)) && (pub_r001402_9_1 <= 100));
  __CPROVER_assume((pub_r001402_9_2 >= (-100)) && (pub_r001402_9_2 <= 100));
  __CPROVER_assume((pub_r001402_10_1 >= (-100)) && (pub_r001402_10_1 <= 100));
  __CPROVER_assume((pub_r001402_10_2 >= (-100)) && (pub_r001402_10_2 <= 100));
  __CPROVER_assume((pub_r001402_11_1 >= (-100)) && (pub_r001402_11_1 <= 100));
  __CPROVER_assume((pub_r001402_11_2 >= (-100)) && (pub_r001402_11_2 <= 100));
  __CPROVER_assume((pub_r001402_12_1 >= (-100)) && (pub_r001402_12_1 <= 100));
  __CPROVER_assume((pub_r001402_12_2 >= (-100)) && (pub_r001402_12_2 <= 100));
  __CPROVER_assume((pub_r001402_13_1 >= (-100)) && (pub_r001402_13_1 <= 100));
  __CPROVER_assume((pub_r001402_13_2 >= (-100)) && (pub_r001402_13_2 <= 100));
  __CPROVER_assume((pub_r001402_14_1 >= (-100)) && (pub_r001402_14_1 <= 100));
  __CPROVER_assume((pub_r001402_14_2 >= (-100)) && (pub_r001402_14_2 <= 100));
  __CPROVER_assume((pub_r001402_15_1 >= (-100)) && (pub_r001402_15_1 <= 100));
  __CPROVER_assume((pub_r001402_15_2 >= (-100)) && (pub_r001402_15_2 <= 100));
  __CPROVER_assume((pub_r001402_16_1 >= (-100)) && (pub_r001402_16_1 <= 100));
  __CPROVER_assume((pub_r001402_16_2 >= (-100)) && (pub_r001402_16_2 <= 100));
  __CPROVER_assume((sec_r001402_0_1 >= 0) && (sec_r001402_0_1 <= 255));
  __CPROVER_assume((sec_r001402_0_2 >= 0) && (sec_r001402_0_2 <= 255));
  __CPROVER_assume((sec_r001402_1_1 >= 0) && (sec_r001402_1_1 <= 255));
  __CPROVER_assume((sec_r001402_1_2 >= 0) && (sec_r001402_1_2 <= 255));
  __CPROVER_assume((sec_r001402_2_1 >= 0) && (sec_r001402_2_1 <= 255));
  __CPROVER_assume((sec_r001402_2_2 >= 0) && (sec_r001402_2_2 <= 255));
  __CPROVER_assume((sec_r001402_3_1 >= 0) && (sec_r001402_3_1 <= 255));
  __CPROVER_assume((sec_r001402_3_2 >= 0) && (sec_r001402_3_2 <= 255));
  __CPROVER_assume((sec_r001402_4_1 >= 0) && (sec_r001402_4_1 <= 255));
  __CPROVER_assume((sec_r001402_4_2 >= 0) && (sec_r001402_4_2 <= 255));
  __CPROVER_assume((sec_r001402_5_1 >= 0) && (sec_r001402_5_1 <= 255));
  __CPROVER_assume((sec_r001402_5_2 >= 0) && (sec_r001402_5_2 <= 255));
  __CPROVER_assume((sec_r001402_6_1 >= 0) && (sec_r001402_6_1 <= 255));
  __CPROVER_assume((sec_r001402_6_2 >= 0) && (sec_r001402_6_2 <= 255));
  __CPROVER_assume((sec_r001402_7_1 >= 0) && (sec_r001402_7_1 <= 255));
  __CPROVER_assume((sec_r001402_7_2 >= 0) && (sec_r001402_7_2 <= 255));
  __CPROVER_assume((sec_r001402_8_1 >= 0) && (sec_r001402_8_1 <= 255));
  __CPROVER_assume((sec_r001402_8_2 >= 0) && (sec_r001402_8_2 <= 255));
  __CPROVER_assume((sec_r001402_9_1 >= 0) && (sec_r001402_9_1 <= 255));
  __CPROVER_assume((sec_r001402_9_2 >= 0) && (sec_r001402_9_2 <= 255));
  __CPROVER_assume((sec_r001402_10_1 >= 0) && (sec_r001402_10_1 <= 255));
  __CPROVER_assume((sec_r001402_10_2 >= 0) && (sec_r001402_10_2 <= 255));
  __CPROVER_assume((sec_r001402_11_1 >= 0) && (sec_r001402_11_1 <= 255));
  __CPROVER_assume((sec_r001402_11_2 >= 0) && (sec_r001402_11_2 <= 255));
  __CPROVER_assume((sec_r001402_12_1 >= 0) && (sec_r001402_12_1 <= 255));
  __CPROVER_assume((sec_r001402_12_2 >= 0) && (sec_r001402_12_2 <= 255));
  __CPROVER_assume((sec_r001402_13_1 >= 0) && (sec_r001402_13_1 <= 255));
  __CPROVER_assume((sec_r001402_13_2 >= 0) && (sec_r001402_13_2 <= 255));
  __CPROVER_assume((sec_r001402_14_1 >= 0) && (sec_r001402_14_1 <= 255));
  __CPROVER_assume((sec_r001402_14_2 >= 0) && (sec_r001402_14_2 <= 255));
  __CPROVER_assume((sec_r001402_15_1 >= 0) && (sec_r001402_15_1 <= 255));
  __CPROVER_assume((sec_r001402_15_2 >= 0) && (sec_r001402_15_2 <= 255));
  __CPROVER_assume((sec_r001402_16_1 >= 0) && (sec_r001402_16_1 <= 255));
  __CPROVER_assume((sec_r001402_16_2 >= 0) && (sec_r001402_16_2 <= 255));
  __CPROVER_assume((sec_r001402_17_1 >= 0) && (sec_r001402_17_1 <= 255));
  __CPROVER_assume((sec_r001402_17_2 >= 0) && (sec_r001402_17_2 <= 255));
  __CPROVER_assume((sec_r001402_18_1 >= 0) && (sec_r001402_18_1 <= 255));
  __CPROVER_assume((sec_r001402_18_2 >= 0) && (sec_r001402_18_2 <= 255));
  __CPROVER_assume((sec_r001402_19_1 >= 0) && (sec_r001402_19_1 <= 255));
  __CPROVER_assume((sec_r001402_19_2 >= 0) && (sec_r001402_19_2 <= 255));
  __CPROVER_assume((sec_r001402_20_1 >= 0) && (sec_r001402_20_1 <= 255));
  __CPROVER_assume((sec_r001402_20_2 >= 0) && (sec_r001402_20_2 <= 255));
  struct MatrixBlock_R001402_213_0 st_var_0_1 = {0};
  struct MatrixBlock_R001402_213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001402_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001402_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001402_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001402_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001402_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001402_0_2 + 7) & 15;
  struct StreamBuffer_R001402_213_1 st_var_1_1 = {0};
  struct StreamBuffer_R001402_213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001402_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001402_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001402_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001402_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001402_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001402_0_2 + 9) & 15;
  struct DeviceConfig_R001402_213_2 st_var_2_1 = {0};
  struct DeviceConfig_R001402_213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001402_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001402_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001402_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001402_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001402_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001402_0_2 + 11) & 15;
  union PacketPayload_R001402_213_0 u_var_1;
  union PacketPayload_R001402_213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001402_213_0(sec_r001402_0_1, sec_r001402_1_1, pub_r001402_2_1);
  int helper_flow_0_2 = fn_R001402_213_0(sec_r001402_0_2, sec_r001402_1_2, pub_r001402_2_2);
  fn_R001402_213_0_2(sec_r001402_0_1, sec_r001402_1_1, pub_r001402_2_1, sec_r001402_0_2, sec_r001402_1_2, pub_r001402_2_2);
  int helper_flow_1_1 = fn_R001402_213_1(sec_r001402_1_1, sec_r001402_2_1);
  int helper_flow_1_2 = fn_R001402_213_1(sec_r001402_1_2, sec_r001402_2_2);
  fn_R001402_213_1_2(sec_r001402_1_1, sec_r001402_2_1, sec_r001402_1_2, sec_r001402_2_2);
  int helper_flow_2_1 = fn_R001402_213_2(sec_r001402_2_1, sec_r001402_3_1, pub_r001402_4_1, pub_r001402_5_1);
  int helper_flow_2_2 = fn_R001402_213_2(sec_r001402_2_2, sec_r001402_3_2, pub_r001402_4_2, pub_r001402_5_2);
  fn_R001402_213_2_2(sec_r001402_2_1, sec_r001402_3_1, pub_r001402_4_1, pub_r001402_5_1, sec_r001402_2_2, sec_r001402_3_2, pub_r001402_4_2, pub_r001402_5_2);
  int helper_flow_3_1 = fn_R001402_213_3(sec_r001402_3_1, pub_r001402_4_1);
  int helper_flow_3_2 = fn_R001402_213_3(sec_r001402_3_2, pub_r001402_4_2);
  fn_R001402_213_3_2(sec_r001402_3_1, pub_r001402_4_1, sec_r001402_3_2, pub_r001402_4_2);
  int helper_flow_4_1 = fn_R001402_213_4(sec_r001402_4_1, sec_r001402_5_1, pub_r001402_6_1);
  int helper_flow_4_2 = fn_R001402_213_4(sec_r001402_4_2, sec_r001402_5_2, pub_r001402_6_2);
  fn_R001402_213_4_2(sec_r001402_4_1, sec_r001402_5_1, pub_r001402_6_1, sec_r001402_4_2, sec_r001402_5_2, pub_r001402_6_2);
  int helper_flow_5_1 = fn_R001402_213_5(sec_r001402_5_1, pub_r001402_6_1, pub_r001402_7_1);
  int helper_flow_5_2 = fn_R001402_213_5(sec_r001402_5_2, pub_r001402_6_2, pub_r001402_7_2);
  fn_R001402_213_5_2(sec_r001402_5_1, pub_r001402_6_1, pub_r001402_7_1, sec_r001402_5_2, pub_r001402_6_2, pub_r001402_7_2);
  int stage_v_0_1 = (((sec_r001402_20_1 * 3) + pub_r001402_2_1) + 36) & 127;
  int stage_v_0_2 = (((sec_r001402_20_2 * 3) + pub_r001402_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001402_11_1 * 3) + pub_r001402_13_1) + 6) & 127;
  int stage_v_1_2 = (((sec_r001402_11_2 * 3) + pub_r001402_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001402_0_1 * 3) + pub_r001402_1_1) + 6) & 127;
  int stage_v_2_2 = (((sec_r001402_0_2 * 3) + pub_r001402_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001402_4_1 * 3) + pub_r001402_10_1) + 6) & 127;
  int stage_v_3_2 = (((sec_r001402_4_2 * 3) + pub_r001402_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((helper_flow_4_1 * 3) + pub_r001402_12_1) + 15) & 127;
  int stage_v_4_2 = (((helper_flow_4_2 * 3) + pub_r001402_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((helper_flow_2_1 * 3) + pub_r001402_14_1) + 4) & 127;
  int stage_v_5_2 = (((helper_flow_2_2 * 3) + pub_r001402_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001402_1_1 * 2) + 38) & 63;
  int stage_v_6_2 = ((pub_r001402_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_2_1 * 3) + pub_r001402_9_1) + 19) & 127;
  int stage_v_7_2 = (((helper_flow_2_2 * 3) + pub_r001402_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001402_0_1 * 2) + 47) & 63;
  int stage_v_8_2 = ((pub_r001402_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001402_11_1 * 2) + 26) & 63;
  int stage_v_9_2 = ((pub_r001402_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_4_1 * 3) + pub_r001402_1_1) + 22) & 127;
  int stage_v_10_2 = (((stage_v_4_2 * 3) + pub_r001402_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001402_16_1 * 2) + 17) & 63;
  int stage_v_11_2 = ((pub_r001402_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001402_5_1 * 3) + pub_r001402_13_1) + 27) & 127;
  int stage_v_12_2 = (((sec_r001402_5_2 * 3) + pub_r001402_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_1_1 * 3) + pub_r001402_2_1) + 42) & 127;
  int stage_v_13_2 = (((stage_v_1_2 * 3) + pub_r001402_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001402_11_1 * 2) + 28) & 63;
  int stage_v_14_2 = ((pub_r001402_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((helper_flow_0_1 * 3) + pub_r001402_5_1) + 18) & 127;
  int stage_v_15_2 = (((helper_flow_0_2 * 3) + pub_r001402_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((stage_v_12_1 * 3) + pub_r001402_1_1) + 18) & 127;
  int stage_v_16_2 = (((stage_v_12_2 * 3) + pub_r001402_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001402_0_1 * 2) + 28) & 63;
  int stage_v_17_2 = ((pub_r001402_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001402_8_1 * 2) + 18) & 63;
  int stage_v_18_2 = ((pub_r001402_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001402_13_1 * 2) + 28) & 63;
  int stage_v_19_2 = ((pub_r001402_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((stage_v_5_1 * 3) + pub_r001402_1_1) + 29) & 127;
  int stage_v_20_2 = (((stage_v_5_2 * 3) + pub_r001402_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001402_7_1 * 2) + 44) & 63;
  int stage_v_21_2 = ((pub_r001402_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001402_14_1 * 2) + 23) & 63;
  int stage_v_22_2 = ((pub_r001402_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_20_1 * 3) + pub_r001402_8_1) + 3) & 127;
  int stage_v_23_2 = (((stage_v_20_2 * 3) + pub_r001402_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_0_1 * 3) + pub_r001402_14_1) + 12) & 127;
  int stage_v_24_2 = (((stage_v_0_2 * 3) + pub_r001402_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001402_2_1 * 2) + 20) & 63;
  int stage_v_25_2 = ((pub_r001402_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001402_13_1 * 2) + 42) & 63;
  int stage_v_26_2 = ((pub_r001402_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001402_6_1 * 2) + 47) & 63;
  int stage_v_27_2 = ((pub_r001402_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001402_6_1 * 2) + 38) & 63;
  int stage_v_28_2 = ((pub_r001402_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001402_5_1 * 2) + 36) & 63;
  int stage_v_29_2 = ((pub_r001402_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001402_10_1 * 3) + pub_r001402_12_1) + 8) & 127;
  int stage_v_30_2 = (((sec_r001402_10_2 * 3) + pub_r001402_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001402_2_1 * 3) + pub_r001402_12_1) + 35) & 127;
  int stage_v_31_2 = (((sec_r001402_2_2 * 3) + pub_r001402_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001402_5_1 * 2) + 24) & 63;
  int stage_v_32_2 = ((pub_r001402_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_16_1 * 3) + pub_r001402_15_1) + 33) & 127;
  int stage_v_33_2 = (((stage_v_16_2 * 3) + pub_r001402_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001402_1_1 * 2) + 18) & 63;
  int stage_v_34_2 = ((pub_r001402_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001402_10_1 * 2) + 25) & 63;
  int stage_v_35_2 = ((pub_r001402_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001402_6_1 * 2) + 46) & 63;
  int stage_v_36_2 = ((pub_r001402_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001402_0_1 * 2) + 13) & 63;
  int stage_v_37_2 = ((pub_r001402_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001402_8_1 * 2) + 29) & 63;
  int stage_v_38_2 = ((pub_r001402_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((stage_v_16_1 * 3) + pub_r001402_8_1) + 8) & 127;
  int stage_v_39_2 = (((stage_v_16_2 * 3) + pub_r001402_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001402_7_1 * 2) + 25) & 63;
  int stage_v_40_2 = ((pub_r001402_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001402_12_1 * 2) + 27) & 63;
  int stage_v_41_2 = ((pub_r001402_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001402_1_1 * 2) + 42) & 63;
  int stage_v_42_2 = ((pub_r001402_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001402_15_1 * 2) + 30) & 63;
  int stage_v_43_2 = ((pub_r001402_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001402_12_1 * 3) + pub_r001402_5_1) + 41) & 127;
  int stage_v_44_2 = (((sec_r001402_12_2 * 3) + pub_r001402_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001402_8_1 * 2) + 31) & 63;
  int stage_v_45_2 = ((pub_r001402_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001402_16_1 * 2) + 42) & 63;
  int stage_v_46_2 = ((pub_r001402_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001402_1_1 * 2) + 7) & 63;
  int stage_v_47_2 = ((pub_r001402_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001402_10_1 * 2) + 11) & 63;
  int stage_v_48_2 = ((pub_r001402_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001402_14_1 * 3) + pub_r001402_7_1) + 18) & 127;
  int stage_v_49_2 = (((sec_r001402_14_2 * 3) + pub_r001402_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((sec_r001402_3_1 * 3) + pub_r001402_8_1) + 36) & 127;
  int stage_v_50_2 = (((sec_r001402_3_2 * 3) + pub_r001402_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001402_0_1 * 2) + 9) & 63;
  int stage_v_51_2 = ((pub_r001402_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001402_1_1 * 2) + 29) & 63;
  int stage_v_52_2 = ((pub_r001402_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001402_8_1 * 2) + 34) & 63;
  int stage_v_53_2 = ((pub_r001402_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_13_1 * 3) + pub_r001402_14_1) + 29) & 127;
  int stage_v_54_2 = (((stage_v_13_2 * 3) + pub_r001402_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((sec_r001402_11_1 * 3) + pub_r001402_1_1) + 16) & 127;
  int stage_v_55_2 = (((sec_r001402_11_2 * 3) + pub_r001402_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_4_1 * 3) + pub_r001402_5_1) + 36) & 127;
  int stage_v_56_2 = (((stage_v_4_2 * 3) + pub_r001402_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_10_1 * 3) + pub_r001402_10_1) + 14) & 127;
  int stage_v_57_2 = (((stage_v_10_2 * 3) + pub_r001402_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001402_15_1 * 2) + 47) & 63;
  int stage_v_58_2 = ((pub_r001402_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001402_12_1 * 2) + 36) & 63;
  int stage_v_59_2 = ((pub_r001402_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001402_18_1 * 3) + pub_r001402_3_1) + 10) & 127;
  int stage_v_60_2 = (((sec_r001402_18_2 * 3) + pub_r001402_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((helper_flow_3_1 * 3) + pub_r001402_3_1) + 19) & 127;
  int stage_v_61_2 = (((helper_flow_3_2 * 3) + pub_r001402_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001402_10_1 * 2) + 15) & 63;
  int stage_v_62_2 = ((pub_r001402_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001402_5_1 * 2) + 34) & 63;
  int stage_v_63_2 = ((pub_r001402_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001402_16_1 * 2) + 36) & 63;
  int stage_v_64_2 = ((pub_r001402_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001402_9_1 * 2) + 43) & 63;
  int stage_v_65_2 = ((pub_r001402_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001402_16_1 * 2) + 14) & 63;
  int stage_v_66_2 = ((pub_r001402_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001402_14_1 * 2) + 26) & 63;
  int stage_v_67_2 = ((pub_r001402_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001402_13_1 * 2) + 43) & 63;
  int stage_v_68_2 = ((pub_r001402_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001402_6_1 * 2) + 17) & 63;
  int stage_v_69_2 = ((pub_r001402_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001402_4_1 * 2) + 17) & 63;
  int stage_v_70_2 = ((pub_r001402_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001402_14_1 * 2) + 37) & 63;
  int stage_v_71_2 = ((pub_r001402_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001402_4_1 * 2) + 40) & 63;
  int stage_v_72_2 = ((pub_r001402_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001402_8_1 * 2) + 42) & 63;
  int stage_v_73_2 = ((pub_r001402_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001402_8_1 * 3) + pub_r001402_2_1) + 34) & 127;
  int stage_v_74_2 = (((sec_r001402_8_2 * 3) + pub_r001402_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = ((pub_r001402_5_1 * 2) + 7) & 63;
  int stage_v_75_2 = ((pub_r001402_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001402_2_1 * 2) + 18) & 63;
  int stage_v_76_2 = ((pub_r001402_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_2_1 * 3) + pub_r001402_2_1) + 45) & 127;
  int stage_v_77_2 = (((stage_v_2_2 * 3) + pub_r001402_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001402_15_1 * 3) + pub_r001402_2_1) + 30) & 127;
  int stage_v_78_2 = (((sec_r001402_15_2 * 3) + pub_r001402_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001402_10_1 * 2) + 14) & 63;
  int stage_v_79_2 = ((pub_r001402_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001402_3_1 * 2) + 28) & 63;
  int stage_v_80_2 = ((pub_r001402_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001402_3_1 * 2) + 16) & 63;
  int stage_v_81_2 = ((pub_r001402_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001402_15_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001402_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001402_11_1 * 3) + pub_r001402_8_1) + 8) & 127;
  int stage_v_83_2 = (((sec_r001402_11_2 * 3) + pub_r001402_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((sec_r001402_1_1 * 3) + pub_r001402_3_1) + 27) & 127;
  int stage_v_84_2 = (((sec_r001402_1_2 * 3) + pub_r001402_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001402_14_1 * 2) + 38) & 63;
  int stage_v_85_2 = ((pub_r001402_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001402_0_1 * 2) + 43) & 63;
  int stage_v_86_2 = ((pub_r001402_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001402_0_1 * 2) + 41) & 63;
  int stage_v_87_2 = ((pub_r001402_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001402_6_1 * 2) + 33) & 63;
  int stage_v_88_2 = ((pub_r001402_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001402_0_1 * 2) + 7) & 63;
  int stage_v_89_2 = ((pub_r001402_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_0_1 * 3) + pub_r001402_3_1) + 36) & 127;
  int stage_v_90_2 = (((stage_v_0_2 * 3) + pub_r001402_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001402_11_1 * 2) + 33) & 63;
  int stage_v_91_2 = ((pub_r001402_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001402_9_1 * 2) + 38) & 63;
  int stage_v_92_2 = ((pub_r001402_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((sec_r001402_7_1 * 3) + pub_r001402_4_1) + 40) & 127;
  int stage_v_93_2 = (((sec_r001402_7_2 * 3) + pub_r001402_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001402_3_1 * 2) + 6) & 63;
  int stage_v_94_2 = ((pub_r001402_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((sec_r001402_7_1 * 3) + pub_r001402_10_1) + 14) & 127;
  int stage_v_95_2 = (((sec_r001402_7_2 * 3) + pub_r001402_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_12_1 * 3) + pub_r001402_15_1) + 19) & 127;
  int stage_v_96_2 = (((stage_v_12_2 * 3) + pub_r001402_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001402_0_1 * 2) + 32) & 63;
  int stage_v_97_2 = ((pub_r001402_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001402_14_1 * 2) + 31) & 63;
  int stage_v_98_2 = ((pub_r001402_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001402_0_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001402_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001402_1_1 * 2) + 35) & 63;
  int stage_v_100_2 = ((pub_r001402_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((sec_r001402_20_1 * 3) + pub_r001402_14_1) + 32) & 127;
  int stage_v_101_2 = (((sec_r001402_20_2 * 3) + pub_r001402_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001402_13_1 * 2) + 5) & 63;
  int stage_v_102_2 = ((pub_r001402_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_24_1 * 3) + pub_r001402_7_1) + 27) & 127;
  int stage_v_103_2 = (((stage_v_24_2 * 3) + pub_r001402_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001402_12_1 * 2) + 25) & 63;
  int stage_v_104_2 = ((pub_r001402_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_103_1 * 3) + pub_r001402_3_1) + 34) & 127;
  int stage_v_105_2 = (((stage_v_103_2 * 3) + pub_r001402_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_49_1 * 3) + pub_r001402_7_1) + 7) & 127;
  int stage_v_106_2 = (((stage_v_49_2 * 3) + pub_r001402_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001402_16_1 * 2) + 21) & 63;
  int stage_v_107_2 = ((pub_r001402_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_0_1 * 3) + pub_r001402_0_1) + 31) & 127;
  int stage_v_108_2 = (((stage_v_0_2 * 3) + pub_r001402_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001402_1_1 * 2) + 31) & 63;
  int stage_v_109_2 = ((pub_r001402_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_0_1 * 3) + pub_r001402_5_1) + 30) & 127;
  int stage_v_110_2 = (((stage_v_0_2 * 3) + pub_r001402_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001402_4_1 * 2) + 34) & 63;
  int stage_v_111_2 = ((pub_r001402_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001402_12_1 * 2) + 42) & 63;
  int stage_v_112_2 = ((pub_r001402_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001402_8_1 * 2) + 38) & 63;
  int stage_v_113_2 = ((pub_r001402_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001402_3_1 * 2) + 37) & 63;
  int stage_v_114_2 = ((pub_r001402_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001402_3_1 * 2) + 14) & 63;
  int stage_v_115_2 = ((pub_r001402_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((sec_r001402_0_1 * 3) + pub_r001402_2_1) + 26) & 127;
  int stage_v_116_2 = (((sec_r001402_0_2 * 3) + pub_r001402_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001402_10_1 * 2) + 22) & 63;
  int stage_v_117_2 = ((pub_r001402_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001402_12_1 * 2) + 25) & 63;
  int stage_v_118_2 = ((pub_r001402_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001402_1_1 * 2) + 43) & 63;
  int stage_v_119_2 = ((pub_r001402_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001402_7_1 * 3) + pub_r001402_1_1) + 40) & 127;
  int stage_v_120_2 = (((sec_r001402_7_2 * 3) + pub_r001402_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001402_0_1 * 2) + 30) & 63;
  int stage_v_121_2 = ((pub_r001402_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001402_5_1 * 2) + 10) & 63;
  int stage_v_122_2 = ((pub_r001402_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001402_14_1 * 2) + 13) & 63;
  int stage_v_123_2 = ((pub_r001402_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001402_10_1 * 2) + 49) & 63;
  int stage_v_124_2 = ((pub_r001402_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_116_1 * 3) + pub_r001402_1_1) + 28) & 127;
  int stage_v_125_2 = (((stage_v_116_2 * 3) + pub_r001402_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_77_1 * 3) + pub_r001402_8_1) + 33) & 127;
  int stage_v_126_2 = (((stage_v_77_2 * 3) + pub_r001402_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001402_5_1 * 2) + 19) & 63;
  int stage_v_127_2 = ((pub_r001402_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((sec_r001402_1_1 * 3) + pub_r001402_10_1) + 3) & 127;
  int stage_v_128_2 = (((sec_r001402_1_2 * 3) + pub_r001402_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_13_1 * 3) + pub_r001402_16_1) + 6) & 127;
  int stage_v_129_2 = (((stage_v_13_2 * 3) + pub_r001402_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_31_1 * 3) + pub_r001402_9_1) + 38) & 127;
  int stage_v_130_2 = (((stage_v_31_2 * 3) + pub_r001402_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001402_12_1 * 2) + 10) & 63;
  int stage_v_131_2 = ((pub_r001402_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001402_5_1 * 2) + 45) & 63;
  int stage_v_132_2 = ((pub_r001402_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001402_7_1 * 3) + pub_r001402_9_1) + 7) & 127;
  int stage_v_133_2 = (((sec_r001402_7_2 * 3) + pub_r001402_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001402_5_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001402_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001402_5_1 * 2) + 44) & 63;
  int stage_v_135_2 = ((pub_r001402_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001402_12_1 * 2) + 45) & 63;
  int stage_v_136_2 = ((pub_r001402_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_30_1 * 3) + pub_r001402_16_1) + 23) & 127;
  int stage_v_137_2 = (((stage_v_30_2 * 3) + pub_r001402_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_74_1 * 3) + pub_r001402_0_1) + 17) & 127;
  int stage_v_138_2 = (((stage_v_74_2 * 3) + pub_r001402_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001402_8_1 * 2) + 12) & 63;
  int stage_v_139_2 = ((pub_r001402_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((helper_flow_5_1 * 3) + pub_r001402_3_1) + 3) & 127;
  int stage_v_140_2 = (((helper_flow_5_2 * 3) + pub_r001402_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001402_5_1 * 2) + 17) & 63;
  int stage_v_141_2 = ((pub_r001402_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001402_11_1 * 2) + 29) & 63;
  int stage_v_142_2 = ((pub_r001402_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_57_1 * 3) + pub_r001402_6_1) + 3) & 127;
  int stage_v_143_2 = (((stage_v_57_2 * 3) + pub_r001402_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001402_16_1 * 2) + 26) & 63;
  int stage_v_144_2 = ((pub_r001402_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_57_1 * 3) + pub_r001402_13_1) + 39) & 127;
  int stage_v_145_2 = (((stage_v_57_2 * 3) + pub_r001402_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((helper_flow_2_1 * 3) + pub_r001402_6_1) + 36) & 127;
  int stage_v_146_2 = (((helper_flow_2_2 * 3) + pub_r001402_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = (((sec_r001402_6_1 * 3) + pub_r001402_2_1) + 22) & 127;
  int stage_v_147_2 = (((sec_r001402_6_2 * 3) + pub_r001402_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001402_15_1 * 2) + 17) & 63;
  int stage_v_148_2 = ((pub_r001402_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001402_13_1 * 2) + 47) & 63;
  int stage_v_149_2 = ((pub_r001402_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_50_1 * 3) + pub_r001402_8_1) + 27) & 127;
  int stage_v_150_2 = (((stage_v_50_2 * 3) + pub_r001402_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_3_1 * 3) + pub_r001402_14_1) + 35) & 127;
  int stage_v_151_2 = (((stage_v_3_2 * 3) + pub_r001402_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001402_15_1 * 2) + 38) & 63;
  int stage_v_152_2 = ((pub_r001402_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001402_14_1 * 2) + 18) & 63;
  int stage_v_153_2 = ((pub_r001402_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((helper_flow_1_1 * 3) + pub_r001402_1_1) + 20) & 127;
  int stage_v_154_2 = (((helper_flow_1_2 * 3) + pub_r001402_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001402_15_1 * 2) + 32) & 63;
  int stage_v_155_2 = ((pub_r001402_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((sec_r001402_10_1 * 3) + pub_r001402_8_1) + 42) & 127;
  int stage_v_156_2 = (((sec_r001402_10_2 * 3) + pub_r001402_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001402_0_1 * 2) + 14) & 63;
  int stage_v_157_2 = ((pub_r001402_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001402_10_1 * 2) + 31) & 63;
  int stage_v_158_2 = ((pub_r001402_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001402_0_1 * 2) + 22) & 63;
  int stage_v_159_2 = ((pub_r001402_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001402_5_1 * 2) + 17) & 63;
  int stage_v_160_2 = ((pub_r001402_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_78_1 * 3) + pub_r001402_4_1) + 6) & 127;
  int stage_v_161_2 = (((stage_v_78_2 * 3) + pub_r001402_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001402_13_1 * 2) + 43) & 63;
  int stage_v_162_2 = ((pub_r001402_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_0_1 * 3) + pub_r001402_7_1) + 5) & 127;
  int stage_v_163_2 = (((stage_v_0_2 * 3) + pub_r001402_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001402_0_1 * 2) + 46) & 63;
  int stage_v_164_2 = ((pub_r001402_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_126_1 * 3) + pub_r001402_15_1) + 30) & 127;
  int stage_v_165_2 = (((stage_v_126_2 * 3) + pub_r001402_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001402_10_1 * 2) + 15) & 63;
  int stage_v_166_2 = ((pub_r001402_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((sec_r001402_15_1 * 3) + pub_r001402_9_1) + 42) & 127;
  int stage_v_167_2 = (((sec_r001402_15_2 * 3) + pub_r001402_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001402_14_1 * 2) + 50) & 63;
  int stage_v_168_2 = ((pub_r001402_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001402_9_1 * 2) + 25) & 63;
  int stage_v_169_2 = ((pub_r001402_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001402_0_1 * 2) + 50) & 63;
  int stage_v_170_2 = ((pub_r001402_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001402_4_1 * 2) + 35) & 63;
  int stage_v_171_2 = ((pub_r001402_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001402_2_1 * 2) + 7) & 63;
  int stage_v_172_2 = ((pub_r001402_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001402_15_1 * 2) + 42) & 63;
  int stage_v_173_2 = ((pub_r001402_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001402_13_1 * 2) + 41) & 63;
  int stage_v_174_2 = ((pub_r001402_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_49_1 * 3) + pub_r001402_6_1) + 29) & 127;
  int stage_v_175_2 = (((stage_v_49_2 * 3) + pub_r001402_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001402_8_1 * 3) + pub_r001402_15_1) + 19) & 127;
  int stage_v_176_2 = (((sec_r001402_8_2 * 3) + pub_r001402_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_167_1 * 3) + pub_r001402_15_1) + 6) & 127;
  int stage_v_177_2 = (((stage_v_167_2 * 3) + pub_r001402_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_56_1 * 3) + pub_r001402_4_1) + 33) & 127;
  int stage_v_178_2 = (((stage_v_56_2 * 3) + pub_r001402_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001402_0_1 * 2) + 41) & 63;
  int stage_v_179_2 = ((pub_r001402_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001402_2_1 * 2) + 41) & 63;
  int stage_v_180_2 = ((pub_r001402_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001402_16_1 * 2) + 8) & 63;
  int stage_v_181_2 = ((pub_r001402_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_116_1 * 3) + pub_r001402_10_1) + 5) & 127;
  int stage_v_182_2 = (((stage_v_116_2 * 3) + pub_r001402_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001402_10_1 * 2) + 8) & 63;
  int stage_v_183_2 = ((pub_r001402_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001402_13_1 * 2) + 22) & 63;
  int stage_v_184_2 = ((pub_r001402_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001402_1_1 * 2) + 37) & 63;
  int stage_v_185_2 = ((pub_r001402_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_2_1 * 3) + pub_r001402_9_1) + 16) & 127;
  int stage_v_186_2 = (((stage_v_2_2 * 3) + pub_r001402_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001402_7_1 * 2) + 47) & 63;
  int stage_v_187_2 = ((pub_r001402_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_56_1 * 3) + pub_r001402_9_1) + 27) & 127;
  int stage_v_188_2 = (((stage_v_56_2 * 3) + pub_r001402_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_120_1 * 3) + pub_r001402_1_1) + 26) & 127;
  int stage_v_189_2 = (((stage_v_120_2 * 3) + pub_r001402_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001402_0_1 * 2) + 37) & 63;
  int stage_v_190_2 = ((pub_r001402_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001402_3_1 * 2) + 29) & 63;
  int stage_v_191_2 = ((pub_r001402_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001402_16_1 * 2) + 33) & 63;
  int stage_v_192_2 = ((pub_r001402_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_133_1 * 3) + pub_r001402_16_1) + 33) & 127;
  int stage_v_193_2 = (((stage_v_133_2 * 3) + pub_r001402_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001402_13_1 * 2) + 12) & 63;
  int stage_v_194_2 = ((pub_r001402_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001402_14_1 * 2) + 29) & 63;
  int stage_v_195_2 = ((pub_r001402_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001402_14_1 * 2) + 7) & 63;
  int stage_v_196_2 = ((pub_r001402_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001402_4_1 * 2) + 48) & 63;
  int stage_v_197_2 = ((pub_r001402_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_54_1 * 3) + pub_r001402_1_1) + 17) & 127;
  int stage_v_198_2 = (((stage_v_54_2 * 3) + pub_r001402_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001402_14_1 * 2) + 46) & 63;
  int stage_v_199_2 = ((pub_r001402_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001402_10_1 * 2) + 13) & 63;
  int stage_v_200_2 = ((pub_r001402_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001402_1_1 * 2) + 46) & 63;
  int stage_v_201_2 = ((pub_r001402_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((sec_r001402_8_1 * 3) + pub_r001402_15_1) + 20) & 127;
  int stage_v_202_2 = (((sec_r001402_8_2 * 3) + pub_r001402_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001402_2_1 * 2) + 20) & 63;
  int stage_v_203_2 = ((pub_r001402_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001402_3_1 * 2) + 23) & 63;
  int stage_v_204_2 = ((pub_r001402_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001402_16_1 * 2) + 39) & 63;
  int stage_v_205_2 = ((pub_r001402_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001402_2_1 * 2) + 40) & 63;
  int stage_v_206_2 = ((pub_r001402_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_167_1 * 3) + pub_r001402_9_1) + 25) & 127;
  int stage_v_207_2 = (((stage_v_167_2 * 3) + pub_r001402_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((helper_flow_4_1 * 3) + pub_r001402_16_1) + 42) & 127;
  int stage_v_208_2 = (((helper_flow_4_2 * 3) + pub_r001402_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001402_3_1 * 2) + 20) & 63;
  int stage_v_209_2 = ((pub_r001402_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001402_16_1 * 2) + 14) & 63;
  int stage_v_210_2 = ((pub_r001402_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_49_1 * 3) + pub_r001402_13_1) + 15) & 127;
  int stage_v_211_2 = (((stage_v_49_2 * 3) + pub_r001402_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001402_10_1 * 2) + 21) & 63;
  int stage_v_212_2 = ((pub_r001402_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001402_12_1 * 2) + 43) & 63;
  int stage_v_213_2 = ((pub_r001402_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((helper_flow_0_1 * 3) + pub_r001402_13_1) + 3) & 127;
  int stage_v_214_2 = (((helper_flow_0_2 * 3) + pub_r001402_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = ((pub_r001402_12_1 * 2) + 38) & 63;
  int stage_v_215_2 = ((pub_r001402_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001402_14_1 * 2) + 39) & 63;
  int stage_v_216_2 = ((pub_r001402_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001402_6_1 * 2) + 33) & 63;
  int stage_v_217_2 = ((pub_r001402_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001402_2_1 * 2) + 44) & 63;
  int stage_v_218_2 = ((pub_r001402_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((helper_flow_5_1 * 3) + pub_r001402_2_1) + 9) & 127;
  int stage_v_219_2 = (((helper_flow_5_2 * 3) + pub_r001402_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001402_10_1 * 2) + 36) & 63;
  int stage_v_220_2 = ((pub_r001402_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001402_8_1 * 2) + 43) & 63;
  int stage_v_221_2 = ((pub_r001402_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001402_2_1 * 2) + 42) & 63;
  int stage_v_222_2 = ((pub_r001402_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001402_16_1 * 2) + 24) & 63;
  int stage_v_223_2 = ((pub_r001402_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001402_8_1 * 2) + 41) & 63;
  int stage_v_224_2 = ((pub_r001402_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001402_7_1 * 2) + 43) & 63;
  int stage_v_225_2 = ((pub_r001402_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001402_5_1 * 2) + 42) & 63;
  int stage_v_226_2 = ((pub_r001402_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001402_8_1 * 2) + 38) & 63;
  int stage_v_227_2 = ((pub_r001402_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001402_2_1 * 2) + 12) & 63;
  int stage_v_228_2 = ((pub_r001402_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001402_8_1 * 2) + 44) & 63;
  int stage_v_229_2 = ((pub_r001402_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001402_7_1 * 2) + 45) & 63;
  int stage_v_230_2 = ((pub_r001402_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001402_2_1 * 2) + 37) & 63;
  int stage_v_231_2 = ((pub_r001402_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_74_1 * 3) + pub_r001402_14_1) + 26) & 127;
  int stage_v_232_2 = (((stage_v_74_2 * 3) + pub_r001402_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001402_14_1 * 2) + 34) & 63;
  int stage_v_233_2 = ((pub_r001402_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001402_16_1 * 2) + 33) & 63;
  int stage_v_234_2 = ((pub_r001402_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001402_15_1 * 2) + 44) & 63;
  int stage_v_235_2 = ((pub_r001402_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001402_7_1 * 2) + 35) & 63;
  int stage_v_236_2 = ((pub_r001402_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001402_11_1 * 2) + 16) & 63;
  int stage_v_237_2 = ((pub_r001402_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001402_2_1 * 2) + 49) & 63;
  int stage_v_238_2 = ((pub_r001402_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001402_5_1 * 2) + 21) & 63;
  int stage_v_239_2 = ((pub_r001402_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001402_7_1 * 2) + 38) & 63;
  int stage_v_240_2 = ((pub_r001402_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_4_1 * 3) + pub_r001402_16_1) + 19) & 127;
  int stage_v_241_2 = (((stage_v_4_2 * 3) + pub_r001402_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001402_6_1 * 2) + 31) & 63;
  int stage_v_242_2 = ((pub_r001402_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001402_2_1 * 2) + 49) & 63;
  int stage_v_243_2 = ((pub_r001402_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_7_1 * 3) + pub_r001402_5_1) + 21) & 127;
  int stage_v_244_2 = (((stage_v_7_2 * 3) + pub_r001402_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001402_7_1 * 2) + 23) & 63;
  int stage_v_245_2 = ((pub_r001402_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_55_1 * 3) + pub_r001402_3_1) + 27) & 127;
  int stage_v_246_2 = (((stage_v_55_2 * 3) + pub_r001402_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001402_2_1 * 2) + 33) & 63;
  int stage_v_247_2 = ((pub_r001402_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001402_5_1 * 2) + 16) & 63;
  int stage_v_248_2 = ((pub_r001402_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_10_1 * 3) + pub_r001402_5_1) + 8) & 127;
  int stage_v_249_2 = (((stage_v_10_2 * 3) + pub_r001402_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001402_16_1 * 2) + 9) & 63;
  int stage_v_250_2 = ((pub_r001402_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((sec_r001402_13_1 * 3) + pub_r001402_13_1) + 12) & 127;
  int stage_v_251_2 = (((sec_r001402_13_2 * 3) + pub_r001402_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((sec_r001402_7_1 * 3) + pub_r001402_7_1) + 34) & 127;
  int stage_v_252_2 = (((sec_r001402_7_2 * 3) + pub_r001402_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_55_1 * 3) + pub_r001402_14_1) + 45) & 127;
  int stage_v_253_2 = (((stage_v_55_2 * 3) + pub_r001402_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001402_14_1 * 2) + 45) & 63;
  int stage_v_254_2 = ((pub_r001402_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001402_4_1 * 2) + 43) & 63;
  int stage_v_255_2 = ((pub_r001402_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_83_1 * 3) + pub_r001402_14_1) + 17) & 127;
  int stage_v_256_2 = (((stage_v_83_2 * 3) + pub_r001402_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((stage_v_33_1 * 3) + pub_r001402_16_1) + 32) & 127;
  int stage_v_257_2 = (((stage_v_33_2 * 3) + pub_r001402_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_16_1 * 3) + pub_r001402_4_1) + 25) & 127;
  int stage_v_258_2 = (((stage_v_16_2 * 3) + pub_r001402_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_186_1 * 3) + pub_r001402_10_1) + 45) & 127;
  int stage_v_259_2 = (((stage_v_186_2 * 3) + pub_r001402_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((sec_r001402_12_1 * 3) + pub_r001402_12_1) + 18) & 127;
  int stage_v_260_2 = (((sec_r001402_12_2 * 3) + pub_r001402_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_154_1 * 3) + pub_r001402_6_1) + 27) & 127;
  int stage_v_261_2 = (((stage_v_154_2 * 3) + pub_r001402_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001402_3_1 * 2) + 23) & 63;
  int stage_v_262_2 = ((pub_r001402_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_244_1 * 3) + pub_r001402_13_1) + 25) & 127;
  int stage_v_263_2 = (((stage_v_244_2 * 3) + pub_r001402_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001402_16_1 * 2) + 6) & 63;
  int stage_v_264_2 = ((pub_r001402_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001402_5_1 * 2) + 24) & 63;
  int stage_v_265_2 = ((pub_r001402_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001402_14_1 * 2) + 50) & 63;
  int stage_v_266_2 = ((pub_r001402_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001402_4_1 * 2) + 43) & 63;
  int stage_v_267_2 = ((pub_r001402_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_16_1 * 3) + pub_r001402_16_1) + 24) & 127;
  int stage_v_268_2 = (((stage_v_16_2 * 3) + pub_r001402_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001402_16_1 * 2) + 31) & 63;
  int stage_v_269_2 = ((pub_r001402_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_1_1 * 3) + pub_r001402_13_1) + 26) & 127;
  int stage_v_270_2 = (((stage_v_1_2 * 3) + pub_r001402_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001402_3_1 * 2) + 36) & 63;
  int stage_v_271_2 = ((pub_r001402_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001402_14_1 * 2) + 28) & 63;
  int stage_v_272_2 = ((pub_r001402_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001402_2_1 * 2) + 35) & 63;
  int stage_v_273_2 = ((pub_r001402_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001402_12_1 * 2) + 34) & 63;
  int stage_v_274_2 = ((pub_r001402_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001402_16_1 * 2) + 44) & 63;
  int stage_v_275_2 = ((pub_r001402_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001402_5_1 * 2) + 18) & 63;
  int stage_v_276_2 = ((pub_r001402_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001402_3_1 * 2) + 18) & 63;
  int stage_v_277_2 = ((pub_r001402_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001402_6_1 * 2) + 37) & 63;
  int stage_v_278_2 = ((pub_r001402_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001402_11_1 * 2) + 40) & 63;
  int stage_v_279_2 = ((pub_r001402_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001402_11_1 * 2) + 17) & 63;
  int stage_v_280_2 = ((pub_r001402_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001402_2_1 * 2) + 10) & 63;
  int stage_v_281_2 = ((pub_r001402_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_74_1 * 3) + pub_r001402_3_1) + 39) & 127;
  int stage_v_282_2 = (((stage_v_74_2 * 3) + pub_r001402_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001402_6_1 * 2) + 40) & 63;
  int stage_v_283_2 = ((pub_r001402_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001402_9_1 * 2) + 50) & 63;
  int stage_v_284_2 = ((pub_r001402_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001402_7_1 * 2) + 41) & 63;
  int stage_v_285_2 = ((pub_r001402_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001402_1_1 * 2) + 21) & 63;
  int stage_v_286_2 = ((pub_r001402_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001402_14_1 * 2) + 12) & 63;
  int stage_v_287_2 = ((pub_r001402_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001402_11_1 * 2) + 19) & 63;
  int stage_v_288_2 = ((pub_r001402_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_10_1 * 3) + pub_r001402_6_1) + 3) & 127;
  int stage_v_289_2 = (((stage_v_10_2 * 3) + pub_r001402_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_116_1 * 3) + pub_r001402_0_1) + 28) & 127;
  int stage_v_290_2 = (((stage_v_116_2 * 3) + pub_r001402_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_95_1 * 3) + pub_r001402_15_1) + 19) & 127;
  int stage_v_291_2 = (((stage_v_95_2 * 3) + pub_r001402_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001402_6_1 * 2) + 42) & 63;
  int stage_v_292_2 = ((pub_r001402_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001402_3_1 * 2) + 21) & 63;
  int stage_v_293_2 = ((pub_r001402_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001402_11_1 * 2) + 32) & 63;
  int stage_v_294_2 = ((pub_r001402_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001402_7_1 * 2) + 48) & 63;
  int stage_v_295_2 = ((pub_r001402_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001402_0_1 * 2) + 14) & 63;
  int stage_v_296_2 = ((pub_r001402_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001402_6_1 * 2) + 30) & 63;
  int stage_v_297_2 = ((pub_r001402_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_211_1 * 3) + pub_r001402_9_1) + 24) & 127;
  int stage_v_298_2 = (((stage_v_211_2 * 3) + pub_r001402_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001402_12_1 * 2) + 38) & 63;
  int stage_v_299_2 = ((pub_r001402_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_154_1 * 3) + pub_r001402_9_1) + 6) & 127;
  int stage_v_300_2 = (((stage_v_154_2 * 3) + pub_r001402_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001402_12_1 * 2) + 5) & 63;
  int stage_v_301_2 = ((pub_r001402_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001402_5_1 * 2) + 5) & 63;
  int stage_v_302_2 = ((pub_r001402_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_198_1 * 3) + pub_r001402_1_1) + 43) & 127;
  int stage_v_303_2 = (((stage_v_198_2 * 3) + pub_r001402_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((sec_r001402_7_1 * 3) + pub_r001402_3_1) + 23) & 127;
  int stage_v_304_2 = (((sec_r001402_7_2 * 3) + pub_r001402_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001402_9_1 * 2) + 12) & 63;
  int stage_v_305_2 = ((pub_r001402_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001402_2_1 * 2) + 14) & 63;
  int stage_v_306_2 = ((pub_r001402_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001402_9_1 * 2) + 10) & 63;
  int stage_v_307_2 = ((pub_r001402_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001402_5_1 * 2) + 47) & 63;
  int stage_v_308_2 = ((pub_r001402_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001402_4_1 * 2) + 15) & 63;
  int stage_v_309_2 = ((pub_r001402_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((sec_r001402_16_1 * 3) + pub_r001402_0_1) + 10) & 127;
  int stage_v_310_2 = (((sec_r001402_16_2 * 3) + pub_r001402_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001402_2_1 * 2) + 44) & 63;
  int stage_v_311_2 = ((pub_r001402_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001402_8_1 * 2) + 36) & 63;
  int stage_v_312_2 = ((pub_r001402_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001402_9_1 * 2) + 43) & 63;
  int stage_v_313_2 = ((pub_r001402_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_126_1 * 3) + pub_r001402_6_1) + 19) & 127;
  int stage_v_314_2 = (((stage_v_126_2 * 3) + pub_r001402_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_211_1 * 3) + pub_r001402_12_1) + 27) & 127;
  int stage_v_315_2 = (((stage_v_211_2 * 3) + pub_r001402_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001402_0_1 * 2) + 50) & 63;
  int stage_v_316_2 = ((pub_r001402_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001402_9_1 * 2) + 36) & 63;
  int stage_v_317_2 = ((pub_r001402_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001402_3_1 * 2) + 49) & 63;
  int stage_v_318_2 = ((pub_r001402_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001402_5_1 * 2) + 49) & 63;
  int stage_v_319_2 = ((pub_r001402_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((sec_r001402_8_1 * 3) + pub_r001402_7_1) + 3) & 127;
  int stage_v_320_2 = (((sec_r001402_8_2 * 3) + pub_r001402_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001402_15_1 * 2) + 17) & 63;
  int stage_v_321_2 = ((pub_r001402_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001402_8_1 * 2) + 7) & 63;
  int stage_v_322_2 = ((pub_r001402_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_15_1 * 3) + pub_r001402_12_1) + 18) & 127;
  int stage_v_323_2 = (((stage_v_15_2 * 3) + pub_r001402_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((sec_r001402_9_1 * 3) + pub_r001402_9_1) + 6) & 127;
  int stage_v_324_2 = (((sec_r001402_9_2 * 3) + pub_r001402_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_244_1 * 3) + pub_r001402_10_1) + 43) & 127;
  int stage_v_325_2 = (((stage_v_244_2 * 3) + pub_r001402_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001402_10_1 * 2) + 39) & 63;
  int stage_v_326_2 = ((pub_r001402_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001402_1_1 * 2) + 42) & 63;
  int stage_v_327_2 = ((pub_r001402_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001402_6_1 * 2) + 45) & 63;
  int stage_v_328_2 = ((pub_r001402_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001402_5_1 * 2) + 44) & 63;
  int stage_v_329_2 = ((pub_r001402_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001402_4_1 * 2) + 27) & 63;
  int stage_v_330_2 = ((pub_r001402_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001402_10_1 * 2) + 24) & 63;
  int stage_v_331_2 = ((pub_r001402_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001402_9_1 * 2) + 6) & 63;
  int stage_v_332_2 = ((pub_r001402_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001402_14_1 * 2) + 45) & 63;
  int stage_v_333_2 = ((pub_r001402_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_257_1 * 3) + pub_r001402_16_1) + 38) & 127;
  int stage_v_334_2 = (((stage_v_257_2 * 3) + pub_r001402_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_133_1 * 3) + pub_r001402_15_1) + 20) & 127;
  int stage_v_335_2 = (((stage_v_133_2 * 3) + pub_r001402_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001402_9_1 * 2) + 6) & 63;
  int stage_v_336_2 = ((pub_r001402_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_145_1 * 3) + pub_r001402_15_1) + 20) & 127;
  int stage_v_337_2 = (((stage_v_145_2 * 3) + pub_r001402_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001402_3_1 * 2) + 28) & 63;
  int stage_v_338_2 = ((pub_r001402_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_167_1 * 3) + pub_r001402_2_1) + 42) & 127;
  int stage_v_339_2 = (((stage_v_167_2 * 3) + pub_r001402_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_44_1 * 3) + pub_r001402_12_1) + 44) & 127;
  int stage_v_340_2 = (((stage_v_44_2 * 3) + pub_r001402_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_244_1 * 3) + pub_r001402_15_1) + 14) & 127;
  int stage_v_341_2 = (((stage_v_244_2 * 3) + pub_r001402_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((sec_r001402_14_1 * 3) + pub_r001402_6_1) + 42) & 127;
  int stage_v_342_2 = (((sec_r001402_14_2 * 3) + pub_r001402_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001402_1_1 * 2) + 19) & 63;
  int stage_v_343_2 = ((pub_r001402_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_270_1 * 3) + pub_r001402_7_1) + 14) & 127;
  int stage_v_344_2 = (((stage_v_270_2 * 3) + pub_r001402_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001402_6_1 * 2) + 10) & 63;
  int stage_v_345_2 = ((pub_r001402_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001402_10_1 * 2) + 35) & 63;
  int stage_v_346_2 = ((pub_r001402_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001402_15_1 * 2) + 44) & 63;
  int stage_v_347_2 = ((pub_r001402_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_116_1 * 3) + pub_r001402_15_1) + 18) & 127;
  int stage_v_348_2 = (((stage_v_116_2 * 3) + pub_r001402_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001402_0_1 * 2) + 6) & 63;
  int stage_v_349_2 = ((pub_r001402_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_24_1 * 3) + pub_r001402_4_1) + 24) & 127;
  int stage_v_350_2 = (((stage_v_24_2 * 3) + pub_r001402_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001402_6_1 * 2) + 30) & 63;
  int stage_v_351_2 = ((pub_r001402_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001402_4_1 * 2) + 38) & 63;
  int stage_v_352_2 = ((pub_r001402_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001402_0_1 * 2) + 25) & 63;
  int stage_v_353_2 = ((pub_r001402_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001402_12_1 * 2) + 38) & 63;
  int stage_v_354_2 = ((pub_r001402_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001402_3_1 * 2) + 8) & 63;
  int stage_v_355_2 = ((pub_r001402_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001402_12_1 * 2) + 21) & 63;
  int stage_v_356_2 = ((pub_r001402_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001402_9_1 * 2) + 34) & 63;
  int stage_v_357_2 = ((pub_r001402_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001402_16_1 * 2) + 21) & 63;
  int stage_v_358_2 = ((pub_r001402_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001402_11_1 * 2) + 45) & 63;
  int stage_v_359_2 = ((pub_r001402_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001402_15_1 * 2) + 37) & 63;
  int stage_v_360_2 = ((pub_r001402_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_126_1 * 3) + pub_r001402_11_1) + 41) & 127;
  int stage_v_361_2 = (((stage_v_126_2 * 3) + pub_r001402_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001402_2_1 * 2) + 15) & 63;
  int stage_v_362_2 = ((pub_r001402_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_54_1 * 3) + pub_r001402_2_1) + 38) & 127;
  int stage_v_363_2 = (((stage_v_54_2 * 3) + pub_r001402_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001402_10_1 * 2) + 49) & 63;
  int stage_v_364_2 = ((pub_r001402_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001402_1_1 * 2) + 41) & 63;
  int stage_v_365_2 = ((pub_r001402_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001402_10_1 * 2) + 20) & 63;
  int stage_v_366_2 = ((pub_r001402_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_163_1 * 3) + pub_r001402_6_1) + 32) & 127;
  int stage_v_367_2 = (((stage_v_163_2 * 3) + pub_r001402_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_2_1 * 3) + pub_r001402_11_1) + 42) & 127;
  int stage_v_368_2 = (((stage_v_2_2 * 3) + pub_r001402_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001402_16_1 * 2) + 45) & 63;
  int stage_v_369_2 = ((pub_r001402_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001402_10_1 * 2) + 39) & 63;
  int stage_v_370_2 = ((pub_r001402_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001402_0_1 * 2) + 48) & 63;
  int stage_v_371_2 = ((pub_r001402_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001402_2_1 * 2) + 44) & 63;
  int stage_v_372_2 = ((pub_r001402_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_55_1 * 3) + pub_r001402_1_1) + 9) & 127;
  int stage_v_373_2 = (((stage_v_55_2 * 3) + pub_r001402_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001402_13_1 * 2) + 15) & 63;
  int stage_v_374_2 = ((pub_r001402_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001402_1_1 * 2) + 13) & 63;
  int stage_v_375_2 = ((pub_r001402_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001402_7_1 * 2) + 11) & 63;
  int stage_v_376_2 = ((pub_r001402_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001402_1_1 * 2) + 35) & 63;
  int stage_v_377_2 = ((pub_r001402_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((sec_r001402_12_1 * 3) + pub_r001402_12_1) + 33) & 127;
  int stage_v_378_2 = (((sec_r001402_12_2 * 3) + pub_r001402_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_105_1 * 3) + pub_r001402_15_1) + 18) & 127;
  int stage_v_379_2 = (((stage_v_105_2 * 3) + pub_r001402_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001402_8_1 * 2) + 6) & 63;
  int stage_v_380_2 = ((pub_r001402_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((sec_r001402_18_1 * 3) + pub_r001402_9_1) + 11) & 127;
  int stage_v_381_2 = (((sec_r001402_18_2 * 3) + pub_r001402_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001402_4_1 * 2) + 33) & 63;
  int stage_v_382_2 = ((pub_r001402_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001402_9_1 * 2) + 26) & 63;
  int stage_v_383_2 = ((pub_r001402_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001402_1_1 * 2) + 37) & 63;
  int stage_v_384_2 = ((pub_r001402_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001402_9_1 * 2) + 49) & 63;
  int stage_v_385_2 = ((pub_r001402_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001402_12_1 * 2) + 46) & 63;
  int stage_v_386_2 = ((pub_r001402_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_10_1 * 3) + pub_r001402_6_1) + 23) & 127;
  int stage_v_387_2 = (((stage_v_10_2 * 3) + pub_r001402_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001402_11_1 * 2) + 8) & 63;
  int stage_v_388_2 = ((pub_r001402_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_137_1 * 3) + pub_r001402_9_1) + 12) & 127;
  int stage_v_389_2 = (((stage_v_137_2 * 3) + pub_r001402_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001402_9_1 * 2) + 47) & 63;
  int stage_v_390_2 = ((pub_r001402_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001402_6_1 * 2) + 13) & 63;
  int stage_v_391_2 = ((pub_r001402_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001402_7_1 * 2) + 16) & 63;
  int stage_v_392_2 = ((pub_r001402_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((sec_r001402_11_1 * 3) + pub_r001402_16_1) + 33) & 127;
  int stage_v_393_2 = (((sec_r001402_11_2 * 3) + pub_r001402_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001402_8_1 * 2) + 40) & 63;
  int stage_v_394_2 = ((pub_r001402_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001402_6_1 * 2) + 26) & 63;
  int stage_v_395_2 = ((pub_r001402_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001402_6_1 * 2) + 12) & 63;
  int stage_v_396_2 = ((pub_r001402_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001402_5_1 * 2) + 46) & 63;
  int stage_v_397_2 = ((pub_r001402_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001402_1_1 * 2) + 34) & 63;
  int stage_v_398_2 = ((pub_r001402_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001402_13_1 * 2) + 5) & 63;
  int stage_v_399_2 = ((pub_r001402_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001402_8_1 * 2) + 26) & 63;
  int stage_v_400_2 = ((pub_r001402_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((helper_flow_3_1 * 3) + pub_r001402_11_1) + 11) & 127;
  int stage_v_401_2 = (((helper_flow_3_2 * 3) + pub_r001402_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001402_1_1 * 2) + 41) & 63;
  int stage_v_402_2 = ((pub_r001402_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001402_15_1 * 2) + 21) & 63;
  int stage_v_403_2 = ((pub_r001402_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001402_4_1 * 2) + 5) & 63;
  int stage_v_404_2 = ((pub_r001402_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001402_2_1 * 2) + 47) & 63;
  int stage_v_405_2 = ((pub_r001402_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001402_8_1 * 2) + 19) & 63;
  int stage_v_406_2 = ((pub_r001402_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001402_13_1 * 2) + 47) & 63;
  int stage_v_407_2 = ((pub_r001402_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001402_4_1 * 2) + 15) & 63;
  int stage_v_408_2 = ((pub_r001402_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001402_15_1 * 2) + 47) & 63;
  int stage_v_409_2 = ((pub_r001402_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001402_16_1 * 2) + 9) & 63;
  int stage_v_410_2 = ((pub_r001402_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001402_16_1 * 2) + 37) & 63;
  int stage_v_411_2 = ((pub_r001402_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001402_14_1 * 2) + 49) & 63;
  int stage_v_412_2 = ((pub_r001402_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001402_14_1 * 2) + 44) & 63;
  int stage_v_413_2 = ((pub_r001402_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001402_5_1 * 2) + 6) & 63;
  int stage_v_414_2 = ((pub_r001402_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_186_1 * 3) + pub_r001402_16_1) + 31) & 127;
  int stage_v_415_2 = (((stage_v_186_2 * 3) + pub_r001402_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001402_13_1 * 2) + 46) & 63;
  int stage_v_416_2 = ((pub_r001402_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001402_8_1 * 2) + 11) & 63;
  int stage_v_417_2 = ((pub_r001402_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001402_3_1 * 2) + 9) & 63;
  int stage_v_418_2 = ((pub_r001402_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((sec_r001402_1_1 * 3) + pub_r001402_15_1) + 44) & 127;
  int stage_v_419_2 = (((sec_r001402_1_2 * 3) + pub_r001402_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001402_2_1 * 2) + 46) & 63;
  int stage_v_420_2 = ((pub_r001402_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((sec_r001402_12_1 * 3) + pub_r001402_1_1) + 42) & 127;
  int stage_v_421_2 = (((sec_r001402_12_2 * 3) + pub_r001402_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_50_1 * 3) + pub_r001402_0_1) + 3) & 127;
  int stage_v_422_2 = (((stage_v_50_2 * 3) + pub_r001402_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001402_10_1 * 2) + 9) & 63;
  int stage_v_423_2 = ((pub_r001402_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001402_7_1 * 2) + 48) & 63;
  int stage_v_424_2 = ((pub_r001402_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001402_3_1 * 2) + 8) & 63;
  int stage_v_425_2 = ((pub_r001402_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001402_16_1 * 2) + 29) & 63;
  int stage_v_426_2 = ((pub_r001402_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001402_16_1 * 2) + 30) & 63;
  int stage_v_427_2 = ((pub_r001402_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_147_1 * 3) + pub_r001402_13_1) + 27) & 127;
  int stage_v_428_2 = (((stage_v_147_2 * 3) + pub_r001402_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = ((pub_r001402_12_1 * 2) + 42) & 63;
  int stage_v_429_2 = ((pub_r001402_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001402_8_1 * 2) + 36) & 63;
  int stage_v_430_2 = ((pub_r001402_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001402_14_1 * 2) + 11) & 63;
  int stage_v_431_2 = ((pub_r001402_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_151_1 * 3) + pub_r001402_16_1) + 7) & 127;
  int stage_v_432_2 = (((stage_v_151_2 * 3) + pub_r001402_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001402_11_1 * 2) + 23) & 63;
  int stage_v_433_2 = ((pub_r001402_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((stage_v_401_1 * 3) + pub_r001402_14_1) + 24) & 127;
  int stage_v_434_2 = (((stage_v_401_2 * 3) + pub_r001402_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = (((stage_v_126_1 * 3) + pub_r001402_16_1) + 35) & 127;
  int stage_v_435_2 = (((stage_v_126_2 * 3) + pub_r001402_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = (((stage_v_298_1 * 3) + pub_r001402_14_1) + 31) & 127;
  int stage_v_436_2 = (((stage_v_298_2 * 3) + pub_r001402_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_31_1 * 3) + pub_r001402_3_1) + 24) & 127;
  int stage_v_437_2 = (((stage_v_31_2 * 3) + pub_r001402_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001402_6_1 * 2) + 48) & 63;
  int stage_v_438_2 = ((pub_r001402_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001402_6_1 * 2) + 5) & 63;
  int stage_v_439_2 = ((pub_r001402_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_24_1 * 3) + pub_r001402_7_1) + 16) & 127;
  int stage_v_440_2 = (((stage_v_24_2 * 3) + pub_r001402_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = ((pub_r001402_9_1 * 2) + 42) & 63;
  int stage_v_441_2 = ((pub_r001402_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001402_5_1 * 2) + 22) & 63;
  int stage_v_442_2 = ((pub_r001402_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001402_0_1 * 2) + 29) & 63;
  int stage_v_443_2 = ((pub_r001402_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001402_16_1 * 2) + 43) & 63;
  int stage_v_444_2 = ((pub_r001402_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001402_8_1 * 2) + 15) & 63;
  int stage_v_445_2 = ((pub_r001402_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001402_2_1 * 2) + 31) & 63;
  int stage_v_446_2 = ((pub_r001402_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001402_12_1 * 2) + 13) & 63;
  int stage_v_447_2 = ((pub_r001402_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001402_8_1 * 2) + 19) & 63;
  int stage_v_448_2 = ((pub_r001402_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001402_16_1 * 2) + 13) & 63;
  int stage_v_449_2 = ((pub_r001402_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001402_14_1 * 2) + 33) & 63;
  int stage_v_450_2 = ((pub_r001402_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_291_1 * 3) + pub_r001402_15_1) + 35) & 127;
  int stage_v_451_2 = (((stage_v_291_2 * 3) + pub_r001402_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001402_4_1 * 2) + 28) & 63;
  int stage_v_452_2 = ((pub_r001402_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001402_13_1 * 2) + 39) & 63;
  int stage_v_453_2 = ((pub_r001402_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((sec_r001402_3_1 * 3) + pub_r001402_6_1) + 31) & 127;
  int stage_v_454_2 = (((sec_r001402_3_2 * 3) + pub_r001402_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = ((pub_r001402_3_1 * 2) + 24) & 63;
  int stage_v_455_2 = ((pub_r001402_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_337_1 * 3) + pub_r001402_2_1) + 22) & 127;
  int stage_v_456_2 = (((stage_v_337_2 * 3) + pub_r001402_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001402_13_1 * 2) + 32) & 63;
  int stage_v_457_2 = ((pub_r001402_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001402_3_1 * 2) + 48) & 63;
  int stage_v_458_2 = ((pub_r001402_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001402_13_1 * 2) + 36) & 63;
  int stage_v_459_2 = ((pub_r001402_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001402_13_1 * 2) + 17) & 63;
  int stage_v_460_2 = ((pub_r001402_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001402_6_1 * 2) + 5) & 63;
  int stage_v_461_2 = ((pub_r001402_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001402_7_1 * 2) + 39) & 63;
  int stage_v_462_2 = ((pub_r001402_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((stage_v_110_1 * 3) + pub_r001402_1_1) + 29) & 127;
  int stage_v_463_2 = (((stage_v_110_2 * 3) + pub_r001402_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((stage_v_57_1 * 3) + pub_r001402_14_1) + 8) & 127;
  int stage_v_464_2 = (((stage_v_57_2 * 3) + pub_r001402_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = ((pub_r001402_13_1 * 2) + 24) & 63;
  int stage_v_465_2 = ((pub_r001402_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((sec_r001402_2_1 * 3) + pub_r001402_13_1) + 22) & 127;
  int stage_v_466_2 = (((sec_r001402_2_2 * 3) + pub_r001402_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001402_6_1 * 2) + 29) & 63;
  int stage_v_467_2 = ((pub_r001402_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((sec_r001402_9_1 * 3) + pub_r001402_15_1) + 33) & 127;
  int stage_v_468_2 = (((sec_r001402_9_2 * 3) + pub_r001402_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001402_9_1 * 2) + 50) & 63;
  int stage_v_469_2 = ((pub_r001402_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001402_9_1 * 2) + 9) & 63;
  int stage_v_470_2 = ((pub_r001402_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001402_6_1 * 2) + 48) & 63;
  int stage_v_471_2 = ((pub_r001402_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001402_0_1 * 2) + 44) & 63;
  int stage_v_472_2 = ((pub_r001402_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001402_1_1 * 2) + 29) & 63;
  int stage_v_473_2 = ((pub_r001402_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001402_10_1 * 2) + 26) & 63;
  int stage_v_474_2 = ((pub_r001402_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001402_2_1 * 2) + 26) & 63;
  int stage_v_475_2 = ((pub_r001402_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001402_11_1 * 2) + 30) & 63;
  int stage_v_476_2 = ((pub_r001402_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = (((sec_r001402_20_1 * 3) + pub_r001402_7_1) + 36) & 127;
  int stage_v_477_2 = (((sec_r001402_20_2 * 3) + pub_r001402_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001402_11_1 * 2) + 29) & 63;
  int stage_v_478_2 = ((pub_r001402_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = (((stage_v_83_1 * 3) + pub_r001402_11_1) + 38) & 127;
  int stage_v_479_2 = (((stage_v_83_2 * 3) + pub_r001402_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = ((pub_r001402_16_1 * 2) + 33) & 63;
  int stage_v_480_2 = ((pub_r001402_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001402_2_1 * 2) + 11) & 63;
  int stage_v_481_2 = ((pub_r001402_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001402_15_1 * 2) + 33) & 63;
  int stage_v_482_2 = ((pub_r001402_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = (((helper_flow_4_1 * 3) + pub_r001402_12_1) + 41) & 127;
  int stage_v_483_2 = (((helper_flow_4_2 * 3) + pub_r001402_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_483_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_483_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_483_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_483_2 * 2)) & 255;
  int stage_v_484_1 = ((pub_r001402_16_1 * 2) + 28) & 63;
  int stage_v_484_2 = ((pub_r001402_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((pub_r001402_4_1 * 2) + 18) & 63;
  int stage_v_485_2 = ((pub_r001402_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = (((stage_v_381_1 * 3) + pub_r001402_5_1) + 5) & 127;
  int stage_v_486_2 = (((stage_v_381_2 * 3) + pub_r001402_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = ((pub_r001402_15_1 * 2) + 9) & 63;
  int stage_v_487_2 = ((pub_r001402_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((pub_r001402_5_1 * 2) + 26) & 63;
  int stage_v_488_2 = ((pub_r001402_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001402_0_1 * 2) + 5) & 63;
  int stage_v_489_2 = ((pub_r001402_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = (((sec_r001402_20_1 * 3) + pub_r001402_2_1) + 44) & 127;
  int stage_v_490_2 = (((sec_r001402_20_2 * 3) + pub_r001402_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = (((stage_v_268_1 * 3) + pub_r001402_7_1) + 30) & 127;
  int stage_v_491_2 = (((stage_v_268_2 * 3) + pub_r001402_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_491_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_491_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_491_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_491_2 * 2)) & 255;
  int stage_v_492_1 = ((pub_r001402_3_1 * 2) + 7) & 63;
  int stage_v_492_2 = ((pub_r001402_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = ((pub_r001402_5_1 * 2) + 49) & 63;
  int stage_v_493_2 = ((pub_r001402_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001402_5_1 == pub_r001402_5_2);
  __CPROVER_assume(sec_r001402_4_1 != sec_r001402_4_2);
  __CPROVER_assume(sec_r001402_1_1 != sec_r001402_1_2);
  __CPROVER_assume(sec_r001402_8_1 != sec_r001402_8_2);
  __CPROVER_assume(pub_r001402_6_1 == pub_r001402_6_2);
  __CPROVER_assume(sec_r001402_0_1 != sec_r001402_0_2);
  __CPROVER_assume(sec_r001402_14_1 != sec_r001402_14_2);
  __CPROVER_assume(sec_r001402_7_1 != sec_r001402_7_2);
  __CPROVER_assume(pub_r001402_9_1 == pub_r001402_9_2);
  __CPROVER_assume(pub_r001402_8_1 == pub_r001402_8_2);
  __CPROVER_assume(pub_r001402_0_1 == pub_r001402_0_2);
  __CPROVER_assume(pub_r001402_3_1 == pub_r001402_3_2);
  __CPROVER_assume(sec_r001402_16_1 != sec_r001402_16_2);
  __CPROVER_assume(pub_r001402_11_1 == pub_r001402_11_2);
  __CPROVER_assume(pub_r001402_13_1 == pub_r001402_13_2);
  __CPROVER_assume(sec_r001402_17_1 != sec_r001402_17_2);
  __CPROVER_assume(sec_r001402_2_1 != sec_r001402_2_2);
  __CPROVER_assume(sec_r001402_15_1 != sec_r001402_15_2);
  __CPROVER_assume(pub_r001402_16_1 == pub_r001402_16_2);
  __CPROVER_assume(sec_r001402_10_1 != sec_r001402_10_2);
  __CPROVER_assume(sec_r001402_5_1 != sec_r001402_5_2);
  __CPROVER_assume(pub_r001402_7_1 == pub_r001402_7_2);
  __CPROVER_assume(pub_r001402_2_1 == pub_r001402_2_2);
  __CPROVER_assume(sec_r001402_9_1 != sec_r001402_9_2);
  __CPROVER_assume(pub_r001402_4_1 == pub_r001402_4_2);
  __CPROVER_assume(sec_r001402_13_1 != sec_r001402_13_2);
  __CPROVER_assume(sec_r001402_19_1 != sec_r001402_19_2);
  __CPROVER_assume(sec_r001402_20_1 != sec_r001402_20_2);
  __CPROVER_assume(pub_r001402_15_1 == pub_r001402_15_2);
  __CPROVER_assume(sec_r001402_12_1 != sec_r001402_12_2);
  __CPROVER_assume(sec_r001402_3_1 != sec_r001402_3_2);
  __CPROVER_assume(pub_r001402_10_1 == pub_r001402_10_2);
  __CPROVER_assume(sec_r001402_6_1 != sec_r001402_6_2);
  __CPROVER_assume(pub_r001402_12_1 == pub_r001402_12_2);
  __CPROVER_assume(pub_r001402_1_1 == pub_r001402_1_2);
  __CPROVER_assume(sec_r001402_18_1 != sec_r001402_18_2);
  __CPROVER_assume(pub_r001402_14_1 == pub_r001402_14_2);
  __CPROVER_assume(sec_r001402_11_1 != sec_r001402_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.id == st_var_2_2.id);
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
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
}


