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
struct CipherContext_R000742_4213_0
{
  int iv;
  short nonce;
  short tag;
  int counter;
  int flags;
  int round_key;
  int buffer[3];
};
struct SensorNode_R000742_4213_1
{
  int status;
  short gain;
  short reading;
  int threshold;
  int buffer[3];
};
struct StreamBuffer_R000742_4213_2
{
  int tail;
  int checksum;
  unsigned char state;
  short head;
  int buffer[3];
};
struct AudioFrame_R000742_4213_3
{
  int sample_rate;
  int peak;
  short envelope;
  int channels;
  int buffer[3];
};
union PacketPayload_R000742_4213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000742_4213_1
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
void fn_R000742_4213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_24_1 = local_arr_1[aux_1 % 3];
  int weight_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_24_2 * 2)) & 127;
  int checksum_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_85_1) & 63;
  aux_2 = (aux_2 + checksum_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_24_1 == weight_24_2);
  assert(checksum_85_1 == checksum_85_2);
}

int fn_R000742_4213_0(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int weight_24 = local_arr[aux % 3];
  acc = (acc + (weight_24 * 2)) & 127;
  int checksum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_96_1)
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

  switch (margin_96_2)
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

  int offset_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_79_1 > 17)
  {
    acc_1 = ((acc_1 + (offset_79_1 * 2)) + 5) & 127;
    aux_1 ^= offset_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_79_2 > 17)
  {
    acc_2 = ((acc_2 + (offset_79_2 * 2)) + 5) & 127;
    aux_2 ^= offset_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_90_1) & 63;
  aux_2 = (aux_2 + threshold_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_96_1 == margin_96_2);
  assert(offset_79_1 == offset_79_2);
  assert(threshold_90_1 == threshold_90_2);
}

int fn_R000742_4213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_96 = (aux + st.buffer[1]) & 3;
  switch (margin_96)
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

  int offset_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_79 > 17)
  {
    acc = ((acc + (offset_79 * 2)) + 5) & 127;
    aux ^= offset_79 & 15;
  }
  else
  {
    acc = ((acc - offset_79) + 11) & 127;
    aux += 3;
  }
  int threshold_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000742_4213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st_1 = {0};
  struct AudioFrame_R000742_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_53_1 = local_arr_1[aux_1 % 3];
  int residue_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_53_2 * 2)) & 127;
  int pivot_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_12_1 > 40)
  {
    acc_1 = ((acc_1 + (pivot_12_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_12_2 > 40)
  {
    acc_2 = ((acc_2 + (pivot_12_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_86_1 == scale_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_53_1 == residue_53_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R000742_4213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_53 = local_arr[aux % 3];
  acc = (acc + (residue_53 * 2)) & 127;
  int pivot_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_12 > 40)
  {
    acc = ((acc + (pivot_12 * 2)) + 5) & 127;
    aux ^= pivot_12 & 15;
  }
  else
  {
    acc = ((acc - pivot_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000742_4213_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st_1 = {0};
  struct CipherContext_R000742_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_74_1 > 23)
  {
    acc_1 = ((acc_1 + (residue_74_1 * 2)) + 5) & 127;
    aux_1 ^= residue_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_74_2 > 23)
  {
    acc_2 = ((acc_2 + (residue_74_2 * 2)) + 5) & 127;
    aux_2 ^= residue_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_12_1) & 63;
  aux_2 = (aux_2 + anchor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_77_1 = local_arr_1[aux_1 % 3];
  int parity_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(anchor_12_1 == anchor_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_77_1 == parity_77_2);
}

int fn_R000742_4213_3(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_74 > 23)
  {
    acc = ((acc + (residue_74 * 2)) + 5) & 127;
    aux ^= residue_74 & 15;
  }
  else
  {
    acc = ((acc - residue_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_77 = local_arr[aux % 3];
  acc = (acc + (parity_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_35_1 > 45)
  {
    acc_1 = ((acc_1 + (coefficient_35_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_35_2 > 45)
  {
    acc_2 = ((acc_2 + (coefficient_35_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_23_1)
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

  switch (window_23_2)
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

  int tracker_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_17_1) & 63;
  aux_2 = (aux_2 + tracker_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  assert(window_23_1 == window_23_2);
  assert(tracker_17_1 == tracker_17_2);
}

int fn_R000742_4213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_35 > 45)
  {
    acc = ((acc + (coefficient_35 * 2)) + 5) & 127;
    aux ^= coefficient_35 & 15;
  }
  else
  {
    acc = ((acc - coefficient_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_23 = (aux + st.buffer[1]) & 3;
  switch (window_23)
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

  int tracker_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000742_4213_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st_1 = {0};
  struct AudioFrame_R000742_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int weight_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_80_1) & 63;
  aux_2 = (aux_2 + weight_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_89_1)
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

  switch (coefficient_89_2)
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
  int index_reg_95_1 = local_arr_1[aux_1 % 3];
  int index_reg_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_80_1 == weight_80_2);
  assert(coefficient_89_1 == coefficient_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_95_1 == index_reg_95_2);
}

int fn_R000742_4213_5(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int weight_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_80) & 63;
  acc ^= aux;
  int coefficient_89 = (aux + st.buffer[1]) & 3;
  switch (coefficient_89)
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
  int index_reg_95 = local_arr[aux % 3];
  acc = (acc + (index_reg_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int vector_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_27_1) & 63;
  aux_2 = (aux_2 + vector_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_77_1 = local_arr_1[aux_1 % 3];
  int residue_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_77_2 * 2)) & 127;
  int scale_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_89_1 > 22)
  {
    acc_1 = ((acc_1 + (scale_89_1 * 2)) + 5) & 127;
    aux_1 ^= scale_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_89_2 > 22)
  {
    acc_2 = ((acc_2 + (scale_89_2 * 2)) + 5) & 127;
    aux_2 ^= scale_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_27_1 == vector_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(scale_89_1 == scale_89_2);
}

int fn_R000742_4213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int vector_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_27) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_77 = local_arr[aux % 3];
  acc = (acc + (residue_77 * 2)) & 127;
  int scale_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_89 > 22)
  {
    acc = ((acc + (scale_89 * 2)) + 5) & 127;
    aux ^= scale_89 & 15;
  }
  else
  {
    acc = ((acc - scale_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000742_4213_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st_1 = {0};
  struct CipherContext_R000742_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_87_1 = local_arr_1[aux_1 % 3];
  int residue_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_87_2 * 2)) & 127;
  int stride_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_66_1)
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

  switch (stride_66_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_87_1 == residue_87_2);
  assert(stride_66_1 == stride_66_2);
}

int fn_R000742_4213_7(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int residue_87 = local_arr[aux % 3];
  acc = (acc + (residue_87 * 2)) & 127;
  int stride_66 = (aux + st.buffer[1]) & 3;
  switch (stride_66)
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

void fn_R000742_4213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_2 = {0};
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
  int window_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_59_1)
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

  switch (window_59_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_59_1 == window_59_2);
}

int fn_R000742_4213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_59 = (aux + st.buffer[1]) & 3;
  switch (window_59)
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

void fn_R000742_4213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_92_1 > 41)
  {
    acc_1 = ((acc_1 + (factor_92_1 * 2)) + 5) & 127;
    aux_1 ^= factor_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_92_2 > 41)
  {
    acc_2 = ((acc_2 + (factor_92_2 * 2)) + 5) & 127;
    aux_2 ^= factor_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_93_1 = local_arr_1[aux_1 % 3];
  int weight_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_43_1) & 63;
  aux_2 = (aux_2 + window_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_92_1 == factor_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_93_1 == weight_93_2);
  assert(window_43_1 == window_43_2);
}

int fn_R000742_4213_9(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_92 > 41)
  {
    acc = ((acc + (factor_92 * 2)) + 5) & 127;
    aux ^= factor_92 & 15;
  }
  else
  {
    acc = ((acc - factor_92) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_93 = local_arr[aux % 3];
  acc = (acc + (weight_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000742_4213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st_1 = {0};
  struct AudioFrame_R000742_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_69_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_69_1 * 2)) + 5) & 127;
    aux_1 ^= metric_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_69_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_69_2 * 2)) + 5) & 127;
    aux_2 ^= metric_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_19_1) & 63;
  aux_2 = (aux_2 + quotient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_98_1)
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

  switch (accumulator_98_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_69_1 == metric_69_2);
  assert(quotient_19_1 == quotient_19_2);
  assert(accumulator_98_1 == accumulator_98_2);
}

int fn_R000742_4213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_69 > 34)
  {
    acc = ((acc + (metric_69 * 2)) + 5) & 127;
    aux ^= metric_69 & 15;
  }
  else
  {
    acc = ((acc - metric_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_19) & 63;
  acc ^= aux;
  int accumulator_98 = (aux + st.buffer[1]) & 3;
  switch (accumulator_98)
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

void fn_R000742_4213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_56_1)
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

  switch (stride_56_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_71_1 = local_arr_1[aux_1 % 3];
  int sample_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_56_1 == stride_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_71_1 == sample_71_2);
}

int fn_R000742_4213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_56 = (aux + st.buffer[1]) & 3;
  switch (stride_56)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_71 = local_arr[aux % 3];
  acc = (acc + (sample_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_52_1) & 63;
  aux_2 = (aux_2 + coefficient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_52_1 == coefficient_52_2);
}

int fn_R000742_4213_12(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_49_1)
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

  switch (coefficient_49_2)
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

  int tally_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_67_1 > 39)
  {
    acc_1 = ((acc_1 + (tally_67_1 * 2)) + 5) & 127;
    aux_1 ^= tally_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_67_2 > 39)
  {
    acc_2 = ((acc_2 + (tally_67_2 * 2)) + 5) & 127;
    aux_2 ^= tally_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_67_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_49_1 == coefficient_49_2);
  assert(tally_67_1 == tally_67_2);
}

int fn_R000742_4213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_49 = (aux + st.buffer[1]) & 3;
  switch (coefficient_49)
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

  int tally_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_67 > 39)
  {
    acc = ((acc + (tally_67 * 2)) + 5) & 127;
    aux ^= tally_67 & 15;
  }
  else
  {
    acc = ((acc - tally_67) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_84_1)
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

  switch (window_84_2)
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
  int weight_49_1 = local_arr_1[aux_1 % 3];
  int weight_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_49_2 * 2)) & 127;
  int delta_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_72_1 > 25)
  {
    acc_1 = ((acc_1 + (delta_72_1 * 2)) + 5) & 127;
    aux_1 ^= delta_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_72_2 > 25)
  {
    acc_2 = ((acc_2 + (delta_72_2 * 2)) + 5) & 127;
    aux_2 ^= delta_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_84_1 == window_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_49_1 == weight_49_2);
  assert(delta_72_1 == delta_72_2);
}

int fn_R000742_4213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_84 = (aux + st.buffer[1]) & 3;
  switch (window_84)
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
  int weight_49 = local_arr[aux % 3];
  acc = (acc + (weight_49 * 2)) & 127;
  int delta_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_72 > 25)
  {
    acc = ((acc + (delta_72 * 2)) + 5) & 127;
    aux ^= delta_72 & 15;
  }
  else
  {
    acc = ((acc - delta_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000742_4213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int bound_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_84_1) & 63;
  aux_2 = (aux_2 + bound_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_91_1 = local_arr_1[aux_1 % 3];
  int coefficient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_91_2 * 2)) & 127;
  int damping_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_61_1 > 27)
  {
    acc_1 = ((acc_1 + (damping_61_1 * 2)) + 5) & 127;
    aux_1 ^= damping_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_61_2 > 27)
  {
    acc_2 = ((acc_2 + (damping_61_2 * 2)) + 5) & 127;
    aux_2 ^= damping_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_84_1 == bound_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(damping_61_1 == damping_61_2);
}

int fn_R000742_4213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int bound_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_91 = local_arr[aux % 3];
  acc = (acc + (coefficient_91 * 2)) & 127;
  int damping_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_61 > 27)
  {
    acc = ((acc + (damping_61 * 2)) + 5) & 127;
    aux ^= damping_61 & 15;
  }
  else
  {
    acc = ((acc - damping_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000742_4213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_36_1) & 63;
  aux_2 = (aux_2 + tracker_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_99_1)
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

  switch (vector_99_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_36_1 == tracker_36_2);
  assert(vector_99_1 == vector_99_2);
}

int fn_R000742_4213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000742_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_36) & 63;
  acc ^= aux;
  int vector_99 = (aux + st.buffer[1]) & 3;
  switch (vector_99)
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

void fn_R000742_4213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_62_1)
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

  switch (factor_62_2)
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
  int segment_17_1 = local_arr_1[aux_1 % 3];
  int segment_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_62_1 == factor_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_17_1 == segment_17_2);
}

int fn_R000742_4213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_62 = (aux + st.buffer[1]) & 3;
  switch (factor_62)
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
  int segment_17 = local_arr[aux % 3];
  acc = (acc + (segment_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000742_4213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st_1 = {0};
  struct SensorNode_R000742_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_73_1) & 63;
  aux_2 = (aux_2 + scale_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_69_1)
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

  switch (damping_69_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_73_1 == scale_73_2);
  assert(damping_69_1 == damping_69_2);
}

int fn_R000742_4213_18(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000742_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_73) & 63;
  acc ^= aux;
  int damping_69 = (aux + st.buffer[1]) & 3;
  switch (damping_69)
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

void fn_R000742_4213_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st_1 = {0};
  struct CipherContext_R000742_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int index_reg_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_35_1) & 63;
  aux_2 = (aux_2 + index_reg_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_46_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_46_1 * 2)) + 5) & 127;
    aux_1 ^= stride_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_46_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_46_2 * 2)) + 5) & 127;
    aux_2 ^= stride_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_19_1)
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

  switch (anchor_19_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_35_1 == index_reg_35_2);
  assert(stride_46_1 == stride_46_2);
  assert(anchor_19_1 == anchor_19_2);
}

int fn_R000742_4213_19(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000742_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_35) & 63;
  acc ^= aux;
  int stride_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_46 > 16)
  {
    acc = ((acc + (stride_46 * 2)) + 5) & 127;
    aux ^= stride_46 & 15;
  }
  else
  {
    acc = ((acc - stride_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_19 = (aux + st.buffer[1]) & 3;
  switch (anchor_19)
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

void fn_R000742_4213_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st_1 = {0};
  struct AudioFrame_R000742_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 37)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 37)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_35_1 == checksum_35_2);
}

int fn_R000742_4213_20(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000742_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 37)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000742_0_1;
  int sec_r000742_0_2;
  int sec_r000742_1_1;
  int sec_r000742_1_2;
  int sec_r000742_2_1;
  int sec_r000742_2_2;
  int sec_r000742_3_1;
  int sec_r000742_3_2;
  int sec_r000742_4_1;
  int sec_r000742_4_2;
  int sec_r000742_5_1;
  int sec_r000742_5_2;
  int sec_r000742_6_1;
  int sec_r000742_6_2;
  int sec_r000742_7_1;
  int sec_r000742_7_2;
  int sec_r000742_8_1;
  int sec_r000742_8_2;
  int sec_r000742_9_1;
  int sec_r000742_9_2;
  int sec_r000742_10_1;
  int sec_r000742_10_2;
  int sec_r000742_11_1;
  int sec_r000742_11_2;
  int sec_r000742_12_1;
  int sec_r000742_12_2;
  int sec_r000742_13_1;
  int sec_r000742_13_2;
  int sec_r000742_14_1;
  int sec_r000742_14_2;
  int sec_r000742_15_1;
  int sec_r000742_15_2;
  int sec_r000742_16_1;
  int sec_r000742_16_2;
  int sec_r000742_17_1;
  int sec_r000742_17_2;
  int pub_r000742_0_1;
  int pub_r000742_0_2;
  int pub_r000742_1_1;
  int pub_r000742_1_2;
  int pub_r000742_2_1;
  int pub_r000742_2_2;
  int pub_r000742_3_1;
  int pub_r000742_3_2;
  int pub_r000742_4_1;
  int pub_r000742_4_2;
  int pub_r000742_5_1;
  int pub_r000742_5_2;
  int pub_r000742_6_1;
  int pub_r000742_6_2;
  int pub_r000742_7_1;
  int pub_r000742_7_2;
  int pub_r000742_8_1;
  int pub_r000742_8_2;
  int pub_r000742_9_1;
  int pub_r000742_9_2;
  int pub_r000742_10_1;
  int pub_r000742_10_2;
  int pub_r000742_11_1;
  int pub_r000742_11_2;
  int pub_r000742_12_1;
  int pub_r000742_12_2;
  int pub_r000742_13_1;
  int pub_r000742_13_2;
  int pub_r000742_14_1;
  int pub_r000742_14_2;
  int pub_r000742_15_1;
  int pub_r000742_15_2;
  int pub_r000742_16_1;
  int pub_r000742_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000742_0_1 >= (-100)) && (pub_r000742_0_1 <= 100));
  __CPROVER_assume((pub_r000742_0_2 >= (-100)) && (pub_r000742_0_2 <= 100));
  __CPROVER_assume((pub_r000742_1_1 >= (-100)) && (pub_r000742_1_1 <= 100));
  __CPROVER_assume((pub_r000742_1_2 >= (-100)) && (pub_r000742_1_2 <= 100));
  __CPROVER_assume((pub_r000742_2_1 >= (-100)) && (pub_r000742_2_1 <= 100));
  __CPROVER_assume((pub_r000742_2_2 >= (-100)) && (pub_r000742_2_2 <= 100));
  __CPROVER_assume((pub_r000742_3_1 >= (-100)) && (pub_r000742_3_1 <= 100));
  __CPROVER_assume((pub_r000742_3_2 >= (-100)) && (pub_r000742_3_2 <= 100));
  __CPROVER_assume((pub_r000742_4_1 >= (-100)) && (pub_r000742_4_1 <= 100));
  __CPROVER_assume((pub_r000742_4_2 >= (-100)) && (pub_r000742_4_2 <= 100));
  __CPROVER_assume((pub_r000742_5_1 >= (-100)) && (pub_r000742_5_1 <= 100));
  __CPROVER_assume((pub_r000742_5_2 >= (-100)) && (pub_r000742_5_2 <= 100));
  __CPROVER_assume((pub_r000742_6_1 >= (-100)) && (pub_r000742_6_1 <= 100));
  __CPROVER_assume((pub_r000742_6_2 >= (-100)) && (pub_r000742_6_2 <= 100));
  __CPROVER_assume((pub_r000742_7_1 >= (-100)) && (pub_r000742_7_1 <= 100));
  __CPROVER_assume((pub_r000742_7_2 >= (-100)) && (pub_r000742_7_2 <= 100));
  __CPROVER_assume((pub_r000742_8_1 >= (-100)) && (pub_r000742_8_1 <= 100));
  __CPROVER_assume((pub_r000742_8_2 >= (-100)) && (pub_r000742_8_2 <= 100));
  __CPROVER_assume((pub_r000742_9_1 >= (-100)) && (pub_r000742_9_1 <= 100));
  __CPROVER_assume((pub_r000742_9_2 >= (-100)) && (pub_r000742_9_2 <= 100));
  __CPROVER_assume((pub_r000742_10_1 >= (-100)) && (pub_r000742_10_1 <= 100));
  __CPROVER_assume((pub_r000742_10_2 >= (-100)) && (pub_r000742_10_2 <= 100));
  __CPROVER_assume((pub_r000742_11_1 >= (-100)) && (pub_r000742_11_1 <= 100));
  __CPROVER_assume((pub_r000742_11_2 >= (-100)) && (pub_r000742_11_2 <= 100));
  __CPROVER_assume((pub_r000742_12_1 >= (-100)) && (pub_r000742_12_1 <= 100));
  __CPROVER_assume((pub_r000742_12_2 >= (-100)) && (pub_r000742_12_2 <= 100));
  __CPROVER_assume((pub_r000742_13_1 >= (-100)) && (pub_r000742_13_1 <= 100));
  __CPROVER_assume((pub_r000742_13_2 >= (-100)) && (pub_r000742_13_2 <= 100));
  __CPROVER_assume((pub_r000742_14_1 >= (-100)) && (pub_r000742_14_1 <= 100));
  __CPROVER_assume((pub_r000742_14_2 >= (-100)) && (pub_r000742_14_2 <= 100));
  __CPROVER_assume((pub_r000742_15_1 >= (-100)) && (pub_r000742_15_1 <= 100));
  __CPROVER_assume((pub_r000742_15_2 >= (-100)) && (pub_r000742_15_2 <= 100));
  __CPROVER_assume((pub_r000742_16_1 >= (-100)) && (pub_r000742_16_1 <= 100));
  __CPROVER_assume((pub_r000742_16_2 >= (-100)) && (pub_r000742_16_2 <= 100));
  __CPROVER_assume((sec_r000742_0_1 >= 0) && (sec_r000742_0_1 <= 255));
  __CPROVER_assume((sec_r000742_0_2 >= 0) && (sec_r000742_0_2 <= 255));
  __CPROVER_assume((sec_r000742_1_1 >= 0) && (sec_r000742_1_1 <= 255));
  __CPROVER_assume((sec_r000742_1_2 >= 0) && (sec_r000742_1_2 <= 255));
  __CPROVER_assume((sec_r000742_2_1 >= 0) && (sec_r000742_2_1 <= 255));
  __CPROVER_assume((sec_r000742_2_2 >= 0) && (sec_r000742_2_2 <= 255));
  __CPROVER_assume((sec_r000742_3_1 >= 0) && (sec_r000742_3_1 <= 255));
  __CPROVER_assume((sec_r000742_3_2 >= 0) && (sec_r000742_3_2 <= 255));
  __CPROVER_assume((sec_r000742_4_1 >= 0) && (sec_r000742_4_1 <= 255));
  __CPROVER_assume((sec_r000742_4_2 >= 0) && (sec_r000742_4_2 <= 255));
  __CPROVER_assume((sec_r000742_5_1 >= 0) && (sec_r000742_5_1 <= 255));
  __CPROVER_assume((sec_r000742_5_2 >= 0) && (sec_r000742_5_2 <= 255));
  __CPROVER_assume((sec_r000742_6_1 >= 0) && (sec_r000742_6_1 <= 255));
  __CPROVER_assume((sec_r000742_6_2 >= 0) && (sec_r000742_6_2 <= 255));
  __CPROVER_assume((sec_r000742_7_1 >= 0) && (sec_r000742_7_1 <= 255));
  __CPROVER_assume((sec_r000742_7_2 >= 0) && (sec_r000742_7_2 <= 255));
  __CPROVER_assume((sec_r000742_8_1 >= 0) && (sec_r000742_8_1 <= 255));
  __CPROVER_assume((sec_r000742_8_2 >= 0) && (sec_r000742_8_2 <= 255));
  __CPROVER_assume((sec_r000742_9_1 >= 0) && (sec_r000742_9_1 <= 255));
  __CPROVER_assume((sec_r000742_9_2 >= 0) && (sec_r000742_9_2 <= 255));
  __CPROVER_assume((sec_r000742_10_1 >= 0) && (sec_r000742_10_1 <= 255));
  __CPROVER_assume((sec_r000742_10_2 >= 0) && (sec_r000742_10_2 <= 255));
  __CPROVER_assume((sec_r000742_11_1 >= 0) && (sec_r000742_11_1 <= 255));
  __CPROVER_assume((sec_r000742_11_2 >= 0) && (sec_r000742_11_2 <= 255));
  __CPROVER_assume((sec_r000742_12_1 >= 0) && (sec_r000742_12_1 <= 255));
  __CPROVER_assume((sec_r000742_12_2 >= 0) && (sec_r000742_12_2 <= 255));
  __CPROVER_assume((sec_r000742_13_1 >= 0) && (sec_r000742_13_1 <= 255));
  __CPROVER_assume((sec_r000742_13_2 >= 0) && (sec_r000742_13_2 <= 255));
  __CPROVER_assume((sec_r000742_14_1 >= 0) && (sec_r000742_14_1 <= 255));
  __CPROVER_assume((sec_r000742_14_2 >= 0) && (sec_r000742_14_2 <= 255));
  __CPROVER_assume((sec_r000742_15_1 >= 0) && (sec_r000742_15_1 <= 255));
  __CPROVER_assume((sec_r000742_15_2 >= 0) && (sec_r000742_15_2 <= 255));
  __CPROVER_assume((sec_r000742_16_1 >= 0) && (sec_r000742_16_1 <= 255));
  __CPROVER_assume((sec_r000742_16_2 >= 0) && (sec_r000742_16_2 <= 255));
  __CPROVER_assume((sec_r000742_17_1 >= 0) && (sec_r000742_17_1 <= 255));
  __CPROVER_assume((sec_r000742_17_2 >= 0) && (sec_r000742_17_2 <= 255));
  struct CipherContext_R000742_4213_0 st_var_0_1 = {0};
  struct CipherContext_R000742_4213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000742_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000742_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000742_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000742_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000742_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000742_0_2 + 7) & 15;
  struct SensorNode_R000742_4213_1 st_var_1_1 = {0};
  struct SensorNode_R000742_4213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000742_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000742_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000742_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000742_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000742_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000742_0_2 + 9) & 15;
  struct StreamBuffer_R000742_4213_2 st_var_2_1 = {0};
  struct StreamBuffer_R000742_4213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000742_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000742_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000742_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000742_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000742_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000742_0_2 + 11) & 15;
  struct AudioFrame_R000742_4213_3 st_var_3_1 = {0};
  struct AudioFrame_R000742_4213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000742_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000742_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000742_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000742_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000742_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000742_0_2 + 13) & 15;
  union PacketPayload_R000742_4213_0 u_var_1;
  union PacketPayload_R000742_4213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 53)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 53)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 27)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 27)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 29)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 29)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
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
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 40)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 40)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = ((sec_r000742_8_1 + pub_r000742_0_1) + 16) & 127;
  int stage_v_19_2 = ((sec_r000742_8_2 + pub_r000742_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((sec_r000742_1_1 + pub_r000742_1_1) + 19) & 127;
  int stage_v_20_2 = ((sec_r000742_1_2 + pub_r000742_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((sec_r000742_11_1 + pub_r000742_11_1) + 18) & 127;
  int stage_v_21_2 = ((sec_r000742_11_2 + pub_r000742_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((stage_v_19_1 + pub_r000742_2_1) + 39) & 127;
  int stage_v_22_2 = ((stage_v_19_2 + pub_r000742_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((sec_r000742_12_1 + pub_r000742_13_1) + 34) & 127;
  int stage_v_23_2 = ((sec_r000742_12_2 + pub_r000742_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((sec_r000742_1_1 + pub_r000742_13_1) + 19) & 127;
  int stage_v_24_2 = ((sec_r000742_1_2 + pub_r000742_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((sec_r000742_4_1 + pub_r000742_15_1) + 23) & 127;
  int stage_v_25_2 = ((sec_r000742_4_2 + pub_r000742_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((stage_v_24_1 + pub_r000742_13_1) + 8) & 127;
  int stage_v_26_2 = ((stage_v_24_2 + pub_r000742_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((stage_v_19_1 + pub_r000742_4_1) + 23) & 127;
  int stage_v_27_2 = ((stage_v_19_2 + pub_r000742_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((sec_r000742_7_1 + pub_r000742_11_1) + 44) & 127;
  int stage_v_28_2 = ((sec_r000742_7_2 + pub_r000742_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((sec_r000742_16_1 + pub_r000742_16_1) + 16) & 127;
  int stage_v_29_2 = ((sec_r000742_16_2 + pub_r000742_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_23_1 + pub_r000742_7_1) + 17) & 127;
  int stage_v_30_2 = ((stage_v_23_2 + pub_r000742_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((stage_v_22_1 + pub_r000742_12_1) + 35) & 127;
  int stage_v_31_2 = ((stage_v_22_2 + pub_r000742_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((stage_v_29_1 + pub_r000742_4_1) + 15) & 127;
  int stage_v_32_2 = ((stage_v_29_2 + pub_r000742_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((stage_v_31_1 + pub_r000742_8_1) + 23) & 127;
  int stage_v_33_2 = ((stage_v_31_2 + pub_r000742_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((stage_v_31_1 + pub_r000742_11_1) + 44) & 127;
  int stage_v_34_2 = ((stage_v_31_2 + pub_r000742_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((stage_v_27_1 + pub_r000742_5_1) + 13) & 127;
  int stage_v_35_2 = ((stage_v_27_2 + pub_r000742_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((stage_v_23_1 + pub_r000742_6_1) + 14) & 127;
  int stage_v_36_2 = ((stage_v_23_2 + pub_r000742_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((stage_v_33_1 + pub_r000742_15_1) + 7) & 127;
  int stage_v_37_2 = ((stage_v_33_2 + pub_r000742_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((sec_r000742_15_1 + pub_r000742_2_1) + 44) & 127;
  int stage_v_38_2 = ((sec_r000742_15_2 + pub_r000742_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((stage_v_21_1 + pub_r000742_3_1) + 30) & 127;
  int stage_v_39_2 = ((stage_v_21_2 + pub_r000742_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((stage_v_25_1 + pub_r000742_11_1) + 45) & 127;
  int stage_v_40_2 = ((stage_v_25_2 + pub_r000742_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_20_1 + pub_r000742_1_1) + 36) & 127;
  int stage_v_41_2 = ((stage_v_20_2 + pub_r000742_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((stage_v_25_1 + pub_r000742_3_1) + 46) & 127;
  int stage_v_42_2 = ((stage_v_25_2 + pub_r000742_3_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((sec_r000742_2_1 + pub_r000742_7_1) + 46) & 127;
  int stage_v_43_2 = ((sec_r000742_2_2 + pub_r000742_7_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((sec_r000742_17_1 + pub_r000742_7_1) + 34) & 127;
  int stage_v_44_2 = ((sec_r000742_17_2 + pub_r000742_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((stage_v_28_1 + pub_r000742_11_1) + 4) & 127;
  int stage_v_45_2 = ((stage_v_28_2 + pub_r000742_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_38_1 + pub_r000742_14_1) + 8) & 127;
  int stage_v_46_2 = ((stage_v_38_2 + pub_r000742_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((stage_v_31_1 + pub_r000742_1_1) + 14) & 127;
  int stage_v_47_2 = ((stage_v_31_2 + pub_r000742_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((sec_r000742_0_1 + pub_r000742_11_1) + 31) & 127;
  int stage_v_48_2 = ((sec_r000742_0_2 + pub_r000742_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((stage_v_48_1 + pub_r000742_15_1) + 29) & 127;
  int stage_v_49_2 = ((stage_v_48_2 + pub_r000742_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((stage_v_28_1 + pub_r000742_10_1) + 35) & 127;
  int stage_v_50_2 = ((stage_v_28_2 + pub_r000742_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_32_1 + pub_r000742_6_1) + 7) & 127;
  int stage_v_51_2 = ((stage_v_32_2 + pub_r000742_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((stage_v_51_1 + pub_r000742_0_1) + 40) & 127;
  int stage_v_52_2 = ((stage_v_51_2 + pub_r000742_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_37_1 + pub_r000742_14_1) + 17) & 127;
  int stage_v_53_2 = ((stage_v_37_2 + pub_r000742_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_41_1 + pub_r000742_10_1) + 48) & 127;
  int stage_v_54_2 = ((stage_v_41_2 + pub_r000742_10_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((sec_r000742_6_1 + pub_r000742_1_1) + 13) & 127;
  int stage_v_55_2 = ((sec_r000742_6_2 + pub_r000742_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((sec_r000742_16_1 + pub_r000742_0_1) + 31) & 127;
  int stage_v_56_2 = ((sec_r000742_16_2 + pub_r000742_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_21_1 + pub_r000742_9_1) + 25) & 127;
  int stage_v_57_2 = ((stage_v_21_2 + pub_r000742_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_32_1 + pub_r000742_2_1) + 27) & 127;
  int stage_v_58_2 = ((stage_v_32_2 + pub_r000742_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((sec_r000742_16_1 + pub_r000742_15_1) + 37) & 127;
  int stage_v_59_2 = ((sec_r000742_16_2 + pub_r000742_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((sec_r000742_16_1 + pub_r000742_0_1) + 26) & 127;
  int stage_v_60_2 = ((sec_r000742_16_2 + pub_r000742_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((sec_r000742_4_1 + pub_r000742_16_1) + 12) & 127;
  int stage_v_61_2 = ((sec_r000742_4_2 + pub_r000742_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_41_1 + pub_r000742_2_1) + 15) & 127;
  int stage_v_62_2 = ((stage_v_41_2 + pub_r000742_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((sec_r000742_17_1 + pub_r000742_6_1) + 7) & 127;
  int stage_v_63_2 = ((sec_r000742_17_2 + pub_r000742_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_59_1 + pub_r000742_8_1) + 17) & 127;
  int stage_v_64_2 = ((stage_v_59_2 + pub_r000742_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_47_1 + pub_r000742_12_1) + 29) & 127;
  int stage_v_65_2 = ((stage_v_47_2 + pub_r000742_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_22_1 + pub_r000742_12_1) + 29) & 127;
  int stage_v_66_2 = ((stage_v_22_2 + pub_r000742_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_65_1 + pub_r000742_15_1) + 25) & 127;
  int stage_v_67_2 = ((stage_v_65_2 + pub_r000742_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000742_9_1 + pub_r000742_4_1) + 25) & 127;
  int stage_v_68_2 = ((sec_r000742_9_2 + pub_r000742_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((sec_r000742_13_1 + pub_r000742_4_1) + 42) & 127;
  int stage_v_69_2 = ((sec_r000742_13_2 + pub_r000742_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_34_1 + pub_r000742_1_1) + 42) & 127;
  int stage_v_70_2 = ((stage_v_34_2 + pub_r000742_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_60_1 + pub_r000742_1_1) + 30) & 127;
  int stage_v_71_2 = ((stage_v_60_2 + pub_r000742_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((sec_r000742_6_1 + pub_r000742_7_1) + 35) & 127;
  int stage_v_72_2 = ((sec_r000742_6_2 + pub_r000742_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((stage_v_61_1 + pub_r000742_6_1) + 35) & 127;
  int stage_v_73_2 = ((stage_v_61_2 + pub_r000742_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((sec_r000742_2_1 + pub_r000742_10_1) + 3) & 127;
  int stage_v_74_2 = ((sec_r000742_2_2 + pub_r000742_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000742_1_1 + pub_r000742_6_1) + 26) & 127;
  int stage_v_75_2 = ((sec_r000742_1_2 + pub_r000742_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_67_1 + pub_r000742_7_1) + 48) & 127;
  int stage_v_76_2 = ((stage_v_67_2 + pub_r000742_7_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_28_1 + pub_r000742_11_1) + 44) & 127;
  int stage_v_77_2 = ((stage_v_28_2 + pub_r000742_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((sec_r000742_4_1 + pub_r000742_10_1) + 4) & 127;
  int stage_v_78_2 = ((sec_r000742_4_2 + pub_r000742_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((sec_r000742_15_1 + pub_r000742_7_1) + 27) & 127;
  int stage_v_79_2 = ((sec_r000742_15_2 + pub_r000742_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_31_1 + pub_r000742_16_1) + 38) & 127;
  int stage_v_80_2 = ((stage_v_31_2 + pub_r000742_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_19_1 + pub_r000742_9_1) + 49) & 127;
  int stage_v_81_2 = ((stage_v_19_2 + pub_r000742_9_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((sec_r000742_16_1 + pub_r000742_6_1) + 30) & 127;
  int stage_v_82_2 = ((sec_r000742_16_2 + pub_r000742_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_26_1 + pub_r000742_12_1) + 32) & 127;
  int stage_v_83_2 = ((stage_v_26_2 + pub_r000742_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_37_1 + pub_r000742_16_1) + 42) & 127;
  int stage_v_84_2 = ((stage_v_37_2 + pub_r000742_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((sec_r000742_3_1 + pub_r000742_4_1) + 36) & 127;
  int stage_v_85_2 = ((sec_r000742_3_2 + pub_r000742_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((sec_r000742_14_1 + pub_r000742_13_1) + 42) & 127;
  int stage_v_86_2 = ((sec_r000742_14_2 + pub_r000742_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((sec_r000742_8_1 + pub_r000742_1_1) + 30) & 127;
  int stage_v_87_2 = ((sec_r000742_8_2 + pub_r000742_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_32_1 + pub_r000742_16_1) + 8) & 127;
  int stage_v_88_2 = ((stage_v_32_2 + pub_r000742_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_59_1 + pub_r000742_6_1) + 21) & 127;
  int stage_v_89_2 = ((stage_v_59_2 + pub_r000742_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((sec_r000742_3_1 + pub_r000742_8_1) + 25) & 127;
  int stage_v_90_2 = ((sec_r000742_3_2 + pub_r000742_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_58_1 + pub_r000742_9_1) + 14) & 127;
  int stage_v_91_2 = ((stage_v_58_2 + pub_r000742_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_28_1 + pub_r000742_1_1) + 12) & 127;
  int stage_v_92_2 = ((stage_v_28_2 + pub_r000742_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_23_1 + pub_r000742_10_1) + 43) & 127;
  int stage_v_93_2 = ((stage_v_23_2 + pub_r000742_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000742_14_1 + pub_r000742_11_1) + 38) & 127;
  int stage_v_94_2 = ((sec_r000742_14_2 + pub_r000742_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_81_1 + pub_r000742_8_1) + 5) & 127;
  int stage_v_95_2 = ((stage_v_81_2 + pub_r000742_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_59_1 + pub_r000742_12_1) + 3) & 127;
  int stage_v_96_2 = ((stage_v_59_2 + pub_r000742_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_63_1 + pub_r000742_5_1) + 14) & 127;
  int stage_v_97_2 = ((stage_v_63_2 + pub_r000742_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000742_2_1 + pub_r000742_15_1) + 16) & 127;
  int stage_v_98_2 = ((sec_r000742_2_2 + pub_r000742_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_22_1 + pub_r000742_4_1) + 4) & 127;
  int stage_v_99_2 = ((stage_v_22_2 + pub_r000742_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_69_1 + pub_r000742_6_1) + 8) & 127;
  int stage_v_100_2 = ((stage_v_69_2 + pub_r000742_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_28_1 + pub_r000742_3_1) + 40) & 127;
  int stage_v_101_2 = ((stage_v_28_2 + pub_r000742_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000742_3_1 + pub_r000742_10_1) + 43) & 127;
  int stage_v_102_2 = ((sec_r000742_3_2 + pub_r000742_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_71_1 + pub_r000742_6_1) + 17) & 127;
  int stage_v_103_2 = ((stage_v_71_2 + pub_r000742_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_54_1 + pub_r000742_6_1) + 41) & 127;
  int stage_v_104_2 = ((stage_v_54_2 + pub_r000742_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((sec_r000742_15_1 + pub_r000742_12_1) + 46) & 127;
  int stage_v_105_2 = ((sec_r000742_15_2 + pub_r000742_12_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((sec_r000742_1_1 + pub_r000742_15_1) + 49) & 127;
  int stage_v_106_2 = ((sec_r000742_1_2 + pub_r000742_15_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_68_1 + pub_r000742_14_1) + 29) & 127;
  int stage_v_107_2 = ((stage_v_68_2 + pub_r000742_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((sec_r000742_2_1 + pub_r000742_5_1) + 36) & 127;
  int stage_v_108_2 = ((sec_r000742_2_2 + pub_r000742_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000742_2_1 + pub_r000742_4_1) + 33) & 127;
  int stage_v_109_2 = ((sec_r000742_2_2 + pub_r000742_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_22_1 + pub_r000742_11_1) + 20) & 127;
  int stage_v_110_2 = ((stage_v_22_2 + pub_r000742_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_53_1 + pub_r000742_9_1) + 8) & 127;
  int stage_v_111_2 = ((stage_v_53_2 + pub_r000742_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000742_4_1 + pub_r000742_4_1) + 7) & 127;
  int stage_v_112_2 = ((sec_r000742_4_2 + pub_r000742_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_36_1 + pub_r000742_1_1) + 33) & 127;
  int stage_v_113_2 = ((stage_v_36_2 + pub_r000742_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_57_1 + pub_r000742_9_1) + 6) & 127;
  int stage_v_114_2 = ((stage_v_57_2 + pub_r000742_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((sec_r000742_16_1 + pub_r000742_5_1) + 22) & 127;
  int stage_v_115_2 = ((sec_r000742_16_2 + pub_r000742_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_62_1 + pub_r000742_9_1) + 38) & 127;
  int stage_v_116_2 = ((stage_v_62_2 + pub_r000742_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_96_1 + pub_r000742_3_1) + 15) & 127;
  int stage_v_117_2 = ((stage_v_96_2 + pub_r000742_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_100_1 + pub_r000742_8_1) + 8) & 127;
  int stage_v_118_2 = ((stage_v_100_2 + pub_r000742_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_75_1 + pub_r000742_0_1) + 24) & 127;
  int stage_v_119_2 = ((stage_v_75_2 + pub_r000742_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000742_9_1 + pub_r000742_1_1) + 3) & 127;
  int stage_v_120_2 = ((sec_r000742_9_2 + pub_r000742_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_36_1 + pub_r000742_11_1) + 40) & 127;
  int stage_v_121_2 = ((stage_v_36_2 + pub_r000742_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((sec_r000742_17_1 + pub_r000742_4_1) + 11) & 127;
  int stage_v_122_2 = ((sec_r000742_17_2 + pub_r000742_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_88_1 + pub_r000742_6_1) + 4) & 127;
  int stage_v_123_2 = ((stage_v_88_2 + pub_r000742_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_39_1 + pub_r000742_5_1) + 18) & 127;
  int stage_v_124_2 = ((stage_v_39_2 + pub_r000742_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_102_1 + pub_r000742_2_1) + 18) & 127;
  int stage_v_125_2 = ((stage_v_102_2 + pub_r000742_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((sec_r000742_10_1 + pub_r000742_9_1) + 32) & 127;
  int stage_v_126_2 = ((sec_r000742_10_2 + pub_r000742_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((sec_r000742_3_1 + pub_r000742_7_1) + 12) & 127;
  int stage_v_127_2 = ((sec_r000742_3_2 + pub_r000742_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((sec_r000742_11_1 + pub_r000742_1_1) + 12) & 127;
  int stage_v_128_2 = ((sec_r000742_11_2 + pub_r000742_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000742_7_1 + pub_r000742_1_1) + 17) & 127;
  int stage_v_129_2 = ((sec_r000742_7_2 + pub_r000742_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_107_1 + pub_r000742_3_1) + 19) & 127;
  int stage_v_130_2 = ((stage_v_107_2 + pub_r000742_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_96_1 + pub_r000742_0_1) + 17) & 127;
  int stage_v_131_2 = ((stage_v_96_2 + pub_r000742_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_30_1 + pub_r000742_14_1) + 36) & 127;
  int stage_v_132_2 = ((stage_v_30_2 + pub_r000742_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_69_1 + pub_r000742_9_1) + 18) & 127;
  int stage_v_133_2 = ((stage_v_69_2 + pub_r000742_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000742_15_1 + pub_r000742_6_1) + 32) & 127;
  int stage_v_134_2 = ((sec_r000742_15_2 + pub_r000742_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_40_1 + pub_r000742_6_1) + 42) & 127;
  int stage_v_135_2 = ((stage_v_40_2 + pub_r000742_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_51_1 + pub_r000742_3_1) + 43) & 127;
  int stage_v_136_2 = ((stage_v_51_2 + pub_r000742_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((sec_r000742_17_1 + pub_r000742_11_1) + 31) & 127;
  int stage_v_137_2 = ((sec_r000742_17_2 + pub_r000742_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_47_1 + pub_r000742_8_1) + 32) & 127;
  int stage_v_138_2 = ((stage_v_47_2 + pub_r000742_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((sec_r000742_5_1 + pub_r000742_10_1) + 27) & 127;
  int stage_v_139_2 = ((sec_r000742_5_2 + pub_r000742_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((sec_r000742_11_1 + pub_r000742_11_1) + 46) & 127;
  int stage_v_140_2 = ((sec_r000742_11_2 + pub_r000742_11_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000742_11_1 + pub_r000742_0_1) + 18) & 127;
  int stage_v_141_2 = ((sec_r000742_11_2 + pub_r000742_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_71_1 + pub_r000742_2_1) + 19) & 127;
  int stage_v_142_2 = ((stage_v_71_2 + pub_r000742_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((sec_r000742_14_1 + pub_r000742_5_1) + 26) & 127;
  int stage_v_143_2 = ((sec_r000742_14_2 + pub_r000742_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000742_16_1 + pub_r000742_0_1) + 18) & 127;
  int stage_v_144_2 = ((sec_r000742_16_2 + pub_r000742_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((sec_r000742_15_1 + pub_r000742_2_1) + 31) & 127;
  int stage_v_145_2 = ((sec_r000742_15_2 + pub_r000742_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_40_1 + pub_r000742_5_1) + 26) & 127;
  int stage_v_146_2 = ((stage_v_40_2 + pub_r000742_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000742_15_1 + pub_r000742_16_1) + 22) & 127;
  int stage_v_147_2 = ((sec_r000742_15_2 + pub_r000742_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_40_1 + pub_r000742_1_1) + 9) & 127;
  int stage_v_148_2 = ((stage_v_40_2 + pub_r000742_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_25_1 + pub_r000742_1_1) + 40) & 127;
  int stage_v_149_2 = ((stage_v_25_2 + pub_r000742_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((sec_r000742_12_1 + pub_r000742_10_1) + 12) & 127;
  int stage_v_150_2 = ((sec_r000742_12_2 + pub_r000742_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_109_1 + pub_r000742_15_1) + 24) & 127;
  int stage_v_151_2 = ((stage_v_109_2 + pub_r000742_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_118_1 + pub_r000742_16_1) + 10) & 127;
  int stage_v_152_2 = ((stage_v_118_2 + pub_r000742_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_135_1 + pub_r000742_10_1) + 13) & 127;
  int stage_v_153_2 = ((stage_v_135_2 + pub_r000742_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_149_1 + pub_r000742_13_1) + 39) & 127;
  int stage_v_154_2 = ((stage_v_149_2 + pub_r000742_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((sec_r000742_2_1 + pub_r000742_2_1) + 32) & 127;
  int stage_v_155_2 = ((sec_r000742_2_2 + pub_r000742_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_55_1 + pub_r000742_3_1) + 37) & 127;
  int stage_v_156_2 = ((stage_v_55_2 + pub_r000742_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((stage_v_154_1 + pub_r000742_1_1) + 34) & 127;
  int stage_v_157_2 = ((stage_v_154_2 + pub_r000742_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_70_1 + pub_r000742_15_1) + 47) & 127;
  int stage_v_158_2 = ((stage_v_70_2 + pub_r000742_15_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000742_0_1 + pub_r000742_15_1) + 34) & 127;
  int stage_v_159_2 = ((sec_r000742_0_2 + pub_r000742_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((sec_r000742_11_1 + pub_r000742_8_1) + 25) & 127;
  int stage_v_160_2 = ((sec_r000742_11_2 + pub_r000742_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_158_1 + pub_r000742_8_1) + 6) & 127;
  int stage_v_161_2 = ((stage_v_158_2 + pub_r000742_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_72_1 + pub_r000742_7_1) + 48) & 127;
  int stage_v_162_2 = ((stage_v_72_2 + pub_r000742_7_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_107_1 + pub_r000742_0_1) + 32) & 127;
  int stage_v_163_2 = ((stage_v_107_2 + pub_r000742_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_144_1 + pub_r000742_3_1) + 18) & 127;
  int stage_v_164_2 = ((stage_v_144_2 + pub_r000742_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000742_14_1 + pub_r000742_8_1) + 35) & 127;
  int stage_v_165_2 = ((sec_r000742_14_2 + pub_r000742_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000742_3_1 + pub_r000742_11_1) + 38) & 127;
  int stage_v_166_2 = ((sec_r000742_3_2 + pub_r000742_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_105_1 + pub_r000742_4_1) + 48) & 127;
  int stage_v_167_2 = ((stage_v_105_2 + pub_r000742_4_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_147_1 + pub_r000742_13_1) + 26) & 127;
  int stage_v_168_2 = ((stage_v_147_2 + pub_r000742_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((sec_r000742_1_1 + pub_r000742_9_1) + 41) & 127;
  int stage_v_169_2 = ((sec_r000742_1_2 + pub_r000742_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_168_1 + pub_r000742_7_1) + 4) & 127;
  int stage_v_170_2 = ((stage_v_168_2 + pub_r000742_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_26_1 + pub_r000742_9_1) + 11) & 127;
  int stage_v_171_2 = ((stage_v_26_2 + pub_r000742_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_62_1 + pub_r000742_7_1) + 13) & 127;
  int stage_v_172_2 = ((stage_v_62_2 + pub_r000742_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_112_1 + pub_r000742_2_1) + 10) & 127;
  int stage_v_173_2 = ((stage_v_112_2 + pub_r000742_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_121_1 + pub_r000742_10_1) + 43) & 127;
  int stage_v_174_2 = ((stage_v_121_2 + pub_r000742_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_133_1 + pub_r000742_15_1) + 32) & 127;
  int stage_v_175_2 = ((stage_v_133_2 + pub_r000742_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_171_1 + pub_r000742_15_1) + 17) & 127;
  int stage_v_176_2 = ((stage_v_171_2 + pub_r000742_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000742_8_1 + pub_r000742_16_1) + 10) & 127;
  int stage_v_177_2 = ((sec_r000742_8_2 + pub_r000742_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000742_5_1 + pub_r000742_6_1) + 9) & 127;
  int stage_v_178_2 = ((sec_r000742_5_2 + pub_r000742_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((sec_r000742_1_1 + pub_r000742_2_1) + 41) & 127;
  int stage_v_179_2 = ((sec_r000742_1_2 + pub_r000742_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((sec_r000742_16_1 + pub_r000742_5_1) + 29) & 127;
  int stage_v_180_2 = ((sec_r000742_16_2 + pub_r000742_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000742_0_1 + pub_r000742_0_1) + 45) & 127;
  int stage_v_181_2 = ((sec_r000742_0_2 + pub_r000742_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_38_1 + pub_r000742_7_1) + 22) & 127;
  int stage_v_182_2 = ((stage_v_38_2 + pub_r000742_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_100_1 + pub_r000742_1_1) + 5) & 127;
  int stage_v_183_2 = ((stage_v_100_2 + pub_r000742_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((sec_r000742_3_1 + pub_r000742_4_1) + 13) & 127;
  int stage_v_184_2 = ((sec_r000742_3_2 + pub_r000742_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_148_1 + pub_r000742_15_1) + 31) & 127;
  int stage_v_185_2 = ((stage_v_148_2 + pub_r000742_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_61_1 + pub_r000742_2_1) + 37) & 127;
  int stage_v_186_2 = ((stage_v_61_2 + pub_r000742_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_180_1 + pub_r000742_6_1) + 39) & 127;
  int stage_v_187_2 = ((stage_v_180_2 + pub_r000742_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((sec_r000742_11_1 + pub_r000742_6_1) + 43) & 127;
  int stage_v_188_2 = ((sec_r000742_11_2 + pub_r000742_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_104_1 + pub_r000742_9_1) + 46) & 127;
  int stage_v_189_2 = ((stage_v_104_2 + pub_r000742_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((sec_r000742_1_1 + pub_r000742_3_1) + 29) & 127;
  int stage_v_190_2 = ((sec_r000742_1_2 + pub_r000742_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_63_1 + pub_r000742_2_1) + 5) & 127;
  int stage_v_191_2 = ((stage_v_63_2 + pub_r000742_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000742_17_1 + pub_r000742_10_1) + 11) & 127;
  int stage_v_192_2 = ((sec_r000742_17_2 + pub_r000742_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_91_1 + pub_r000742_11_1) + 19) & 127;
  int stage_v_193_2 = ((stage_v_91_2 + pub_r000742_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_177_1 + pub_r000742_10_1) + 42) & 127;
  int stage_v_194_2 = ((stage_v_177_2 + pub_r000742_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_48_1 + pub_r000742_14_1) + 48) & 127;
  int stage_v_195_2 = ((stage_v_48_2 + pub_r000742_14_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_135_1 + pub_r000742_13_1) + 27) & 127;
  int stage_v_196_2 = ((stage_v_135_2 + pub_r000742_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((stage_v_67_1 + pub_r000742_5_1) + 19) & 127;
  int stage_v_197_2 = ((stage_v_67_2 + pub_r000742_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_144_1 + pub_r000742_13_1) + 41) & 127;
  int stage_v_198_2 = ((stage_v_144_2 + pub_r000742_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_62_1 + pub_r000742_15_1) + 40) & 127;
  int stage_v_199_2 = ((stage_v_62_2 + pub_r000742_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_78_1 + pub_r000742_10_1) + 40) & 127;
  int stage_v_200_2 = ((stage_v_78_2 + pub_r000742_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_73_1 + pub_r000742_7_1) + 6) & 127;
  int stage_v_201_2 = ((stage_v_73_2 + pub_r000742_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((sec_r000742_17_1 + pub_r000742_9_1) + 47) & 127;
  int stage_v_202_2 = ((sec_r000742_17_2 + pub_r000742_9_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((stage_v_42_1 + pub_r000742_10_1) + 35) & 127;
  int stage_v_203_2 = ((stage_v_42_2 + pub_r000742_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((sec_r000742_15_1 + pub_r000742_1_1) + 15) & 127;
  int stage_v_204_2 = ((sec_r000742_15_2 + pub_r000742_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((stage_v_40_1 + pub_r000742_10_1) + 38) & 127;
  int stage_v_205_2 = ((stage_v_40_2 + pub_r000742_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_131_1 + pub_r000742_11_1) + 9) & 127;
  int stage_v_206_2 = ((stage_v_131_2 + pub_r000742_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((sec_r000742_9_1 + pub_r000742_10_1) + 24) & 127;
  int stage_v_207_2 = ((sec_r000742_9_2 + pub_r000742_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000742_8_1 + pub_r000742_4_1) + 22) & 127;
  int stage_v_208_2 = ((sec_r000742_8_2 + pub_r000742_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((sec_r000742_15_1 + pub_r000742_14_1) + 28) & 127;
  int stage_v_209_2 = ((sec_r000742_15_2 + pub_r000742_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((sec_r000742_7_1 + pub_r000742_11_1) + 8) & 127;
  int stage_v_210_2 = ((sec_r000742_7_2 + pub_r000742_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_120_1 + pub_r000742_13_1) + 5) & 127;
  int stage_v_211_2 = ((stage_v_120_2 + pub_r000742_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_148_1 + pub_r000742_13_1) + 32) & 127;
  int stage_v_212_2 = ((stage_v_148_2 + pub_r000742_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((stage_v_125_1 + pub_r000742_16_1) + 6) & 127;
  int stage_v_213_2 = ((stage_v_125_2 + pub_r000742_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((sec_r000742_13_1 + pub_r000742_9_1) + 43) & 127;
  int stage_v_214_2 = ((sec_r000742_13_2 + pub_r000742_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_182_1 + pub_r000742_3_1) + 29) & 127;
  int stage_v_215_2 = ((stage_v_182_2 + pub_r000742_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_198_1 + pub_r000742_3_1) + 12) & 127;
  int stage_v_216_2 = ((stage_v_198_2 + pub_r000742_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((sec_r000742_16_1 + pub_r000742_12_1) + 19) & 127;
  int stage_v_217_2 = ((sec_r000742_16_2 + pub_r000742_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000742_12_1 + pub_r000742_3_1) + 38) & 127;
  int stage_v_218_2 = ((sec_r000742_12_2 + pub_r000742_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_30_1 + pub_r000742_8_1) + 5) & 127;
  int stage_v_219_2 = ((stage_v_30_2 + pub_r000742_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_183_1 + pub_r000742_6_1) + 43) & 127;
  int stage_v_220_2 = ((stage_v_183_2 + pub_r000742_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_203_1 + pub_r000742_4_1) + 30) & 127;
  int stage_v_221_2 = ((stage_v_203_2 + pub_r000742_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000742_11_1 + pub_r000742_5_1) + 17) & 127;
  int stage_v_222_2 = ((sec_r000742_11_2 + pub_r000742_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_20_1 + pub_r000742_15_1) + 14) & 127;
  int stage_v_223_2 = ((stage_v_20_2 + pub_r000742_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_50_1 + pub_r000742_7_1) + 7) & 127;
  int stage_v_224_2 = ((stage_v_50_2 + pub_r000742_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_181_1 + pub_r000742_8_1) + 23) & 127;
  int stage_v_225_2 = ((stage_v_181_2 + pub_r000742_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_99_1 + pub_r000742_14_1) + 23) & 127;
  int stage_v_226_2 = ((stage_v_99_2 + pub_r000742_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_190_1 + pub_r000742_9_1) + 49) & 127;
  int stage_v_227_2 = ((stage_v_190_2 + pub_r000742_9_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_100_1 + pub_r000742_14_1) + 44) & 127;
  int stage_v_228_2 = ((stage_v_100_2 + pub_r000742_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((stage_v_97_1 + pub_r000742_16_1) + 47) & 127;
  int stage_v_229_2 = ((stage_v_97_2 + pub_r000742_16_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((sec_r000742_8_1 + pub_r000742_14_1) + 23) & 127;
  int stage_v_230_2 = ((sec_r000742_8_2 + pub_r000742_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000742_12_1 + pub_r000742_16_1) + 46) & 127;
  int stage_v_231_2 = ((sec_r000742_12_2 + pub_r000742_16_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((sec_r000742_0_1 + pub_r000742_9_1) + 41) & 127;
  int stage_v_232_2 = ((sec_r000742_0_2 + pub_r000742_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((stage_v_24_1 + pub_r000742_1_1) + 7) & 127;
  int stage_v_233_2 = ((stage_v_24_2 + pub_r000742_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_72_1 + pub_r000742_2_1) + 28) & 127;
  int stage_v_234_2 = ((stage_v_72_2 + pub_r000742_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((stage_v_143_1 + pub_r000742_0_1) + 20) & 127;
  int stage_v_235_2 = ((stage_v_143_2 + pub_r000742_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((sec_r000742_15_1 + pub_r000742_13_1) + 38) & 127;
  int stage_v_236_2 = ((sec_r000742_15_2 + pub_r000742_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((sec_r000742_5_1 + pub_r000742_11_1) + 20) & 127;
  int stage_v_237_2 = ((sec_r000742_5_2 + pub_r000742_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((sec_r000742_9_1 + pub_r000742_14_1) + 37) & 127;
  int stage_v_238_2 = ((sec_r000742_9_2 + pub_r000742_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_136_1 + pub_r000742_14_1) + 14) & 127;
  int stage_v_239_2 = ((stage_v_136_2 + pub_r000742_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((stage_v_142_1 + pub_r000742_4_1) + 5) & 127;
  int stage_v_240_2 = ((stage_v_142_2 + pub_r000742_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((stage_v_144_1 + pub_r000742_3_1) + 16) & 127;
  int stage_v_241_2 = ((stage_v_144_2 + pub_r000742_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((sec_r000742_11_1 + pub_r000742_6_1) + 3) & 127;
  int stage_v_242_2 = ((sec_r000742_11_2 + pub_r000742_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((sec_r000742_10_1 + pub_r000742_8_1) + 10) & 127;
  int stage_v_243_2 = ((sec_r000742_10_2 + pub_r000742_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((sec_r000742_0_1 + pub_r000742_16_1) + 39) & 127;
  int stage_v_244_2 = ((sec_r000742_0_2 + pub_r000742_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((sec_r000742_12_1 + pub_r000742_7_1) + 49) & 127;
  int stage_v_245_2 = ((sec_r000742_12_2 + pub_r000742_7_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((sec_r000742_0_1 + pub_r000742_11_1) + 25) & 127;
  int stage_v_246_2 = ((sec_r000742_0_2 + pub_r000742_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((sec_r000742_7_1 + pub_r000742_6_1) + 28) & 127;
  int stage_v_247_2 = ((sec_r000742_7_2 + pub_r000742_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((sec_r000742_17_1 + pub_r000742_2_1) + 38) & 127;
  int stage_v_248_2 = ((sec_r000742_17_2 + pub_r000742_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((sec_r000742_11_1 + pub_r000742_13_1) + 25) & 127;
  int stage_v_249_2 = ((sec_r000742_11_2 + pub_r000742_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((sec_r000742_12_1 + pub_r000742_11_1) + 48) & 127;
  int stage_v_250_2 = ((sec_r000742_12_2 + pub_r000742_11_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((stage_v_158_1 + pub_r000742_8_1) + 20) & 127;
  int stage_v_251_2 = ((stage_v_158_2 + pub_r000742_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_87_1 + pub_r000742_4_1) + 7) & 127;
  int stage_v_252_2 = ((stage_v_87_2 + pub_r000742_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((stage_v_124_1 + pub_r000742_3_1) + 49) & 127;
  int stage_v_253_2 = ((stage_v_124_2 + pub_r000742_3_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_207_1 + pub_r000742_4_1) + 14) & 127;
  int stage_v_254_2 = ((stage_v_207_2 + pub_r000742_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((sec_r000742_14_1 + pub_r000742_10_1) + 46) & 127;
  int stage_v_255_2 = ((sec_r000742_14_2 + pub_r000742_10_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((stage_v_229_1 + pub_r000742_2_1) + 22) & 127;
  int stage_v_256_2 = ((stage_v_229_2 + pub_r000742_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((sec_r000742_14_1 + pub_r000742_9_1) + 22) & 127;
  int stage_v_257_2 = ((sec_r000742_14_2 + pub_r000742_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((sec_r000742_3_1 + pub_r000742_15_1) + 6) & 127;
  int stage_v_258_2 = ((sec_r000742_3_2 + pub_r000742_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((stage_v_108_1 + pub_r000742_8_1) + 11) & 127;
  int stage_v_259_2 = ((stage_v_108_2 + pub_r000742_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((sec_r000742_11_1 + pub_r000742_8_1) + 12) & 127;
  int stage_v_260_2 = ((sec_r000742_11_2 + pub_r000742_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((sec_r000742_6_1 + pub_r000742_1_1) + 16) & 127;
  int stage_v_261_2 = ((sec_r000742_6_2 + pub_r000742_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_109_1 + pub_r000742_5_1) + 15) & 127;
  int stage_v_262_2 = ((stage_v_109_2 + pub_r000742_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((stage_v_161_1 + pub_r000742_0_1) + 33) & 127;
  int stage_v_263_2 = ((stage_v_161_2 + pub_r000742_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((sec_r000742_14_1 + pub_r000742_11_1) + 4) & 127;
  int stage_v_264_2 = ((sec_r000742_14_2 + pub_r000742_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((sec_r000742_17_1 + pub_r000742_5_1) + 42) & 127;
  int stage_v_265_2 = ((sec_r000742_17_2 + pub_r000742_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((sec_r000742_17_1 + pub_r000742_13_1) + 19) & 127;
  int stage_v_266_2 = ((sec_r000742_17_2 + pub_r000742_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000742_13_1 + pub_r000742_5_1) + 8) & 127;
  int stage_v_267_2 = ((sec_r000742_13_2 + pub_r000742_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((sec_r000742_1_1 + pub_r000742_1_1) + 16) & 127;
  int stage_v_268_2 = ((sec_r000742_1_2 + pub_r000742_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_135_1 + pub_r000742_1_1) + 46) & 127;
  int stage_v_269_2 = ((stage_v_135_2 + pub_r000742_1_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((sec_r000742_4_1 + pub_r000742_16_1) + 19) & 127;
  int stage_v_270_2 = ((sec_r000742_4_2 + pub_r000742_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((sec_r000742_11_1 + pub_r000742_6_1) + 42) & 127;
  int stage_v_271_2 = ((sec_r000742_11_2 + pub_r000742_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((stage_v_84_1 + pub_r000742_2_1) + 40) & 127;
  int stage_v_272_2 = ((stage_v_84_2 + pub_r000742_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((sec_r000742_12_1 + pub_r000742_5_1) + 45) & 127;
  int stage_v_273_2 = ((sec_r000742_12_2 + pub_r000742_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((sec_r000742_5_1 + pub_r000742_14_1) + 5) & 127;
  int stage_v_274_2 = ((sec_r000742_5_2 + pub_r000742_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((stage_v_47_1 + pub_r000742_3_1) + 38) & 127;
  int stage_v_275_2 = ((stage_v_47_2 + pub_r000742_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((sec_r000742_15_1 + pub_r000742_11_1) + 15) & 127;
  int stage_v_276_2 = ((sec_r000742_15_2 + pub_r000742_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_273_1 + pub_r000742_4_1) + 20) & 127;
  int stage_v_277_2 = ((stage_v_273_2 + pub_r000742_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((sec_r000742_13_1 + pub_r000742_7_1) + 13) & 127;
  int stage_v_278_2 = ((sec_r000742_13_2 + pub_r000742_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((sec_r000742_0_1 + pub_r000742_7_1) + 24) & 127;
  int stage_v_279_2 = ((sec_r000742_0_2 + pub_r000742_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((sec_r000742_1_1 + pub_r000742_11_1) + 46) & 127;
  int stage_v_280_2 = ((sec_r000742_1_2 + pub_r000742_11_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((sec_r000742_6_1 + pub_r000742_4_1) + 47) & 127;
  int stage_v_281_2 = ((sec_r000742_6_2 + pub_r000742_4_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((stage_v_183_1 + pub_r000742_1_1) + 4) & 127;
  int stage_v_282_2 = ((stage_v_183_2 + pub_r000742_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((sec_r000742_12_1 + pub_r000742_5_1) + 26) & 127;
  int stage_v_283_2 = ((sec_r000742_12_2 + pub_r000742_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((stage_v_104_1 + pub_r000742_6_1) + 18) & 127;
  int stage_v_284_2 = ((stage_v_104_2 + pub_r000742_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((sec_r000742_3_1 + pub_r000742_13_1) + 26) & 127;
  int stage_v_285_2 = ((sec_r000742_3_2 + pub_r000742_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((stage_v_209_1 + pub_r000742_12_1) + 29) & 127;
  int stage_v_286_2 = ((stage_v_209_2 + pub_r000742_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_193_1 + pub_r000742_3_1) + 35) & 127;
  int stage_v_287_2 = ((stage_v_193_2 + pub_r000742_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((stage_v_222_1 + pub_r000742_13_1) + 46) & 127;
  int stage_v_288_2 = ((stage_v_222_2 + pub_r000742_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((sec_r000742_4_1 + pub_r000742_5_1) + 9) & 127;
  int stage_v_289_2 = ((sec_r000742_4_2 + pub_r000742_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((stage_v_271_1 + pub_r000742_16_1) + 34) & 127;
  int stage_v_290_2 = ((stage_v_271_2 + pub_r000742_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((stage_v_145_1 + pub_r000742_2_1) + 6) & 127;
  int stage_v_291_2 = ((stage_v_145_2 + pub_r000742_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_105_1 + pub_r000742_0_1) + 43) & 127;
  int stage_v_292_2 = ((stage_v_105_2 + pub_r000742_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_141_1 + pub_r000742_1_1) + 17) & 127;
  int stage_v_293_2 = ((stage_v_141_2 + pub_r000742_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((sec_r000742_13_1 + pub_r000742_15_1) + 43) & 127;
  int stage_v_294_2 = ((sec_r000742_13_2 + pub_r000742_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((sec_r000742_2_1 + pub_r000742_7_1) + 49) & 127;
  int stage_v_295_2 = ((sec_r000742_2_2 + pub_r000742_7_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_175_1 + pub_r000742_6_1) + 27) & 127;
  int stage_v_296_2 = ((stage_v_175_2 + pub_r000742_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_233_1 + pub_r000742_7_1) + 13) & 127;
  int stage_v_297_2 = ((stage_v_233_2 + pub_r000742_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((sec_r000742_9_1 + pub_r000742_7_1) + 3) & 127;
  int stage_v_298_2 = ((sec_r000742_9_2 + pub_r000742_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_101_1 + pub_r000742_5_1) + 3) & 127;
  int stage_v_299_2 = ((stage_v_101_2 + pub_r000742_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((stage_v_91_1 + pub_r000742_15_1) + 4) & 127;
  int stage_v_300_2 = ((stage_v_91_2 + pub_r000742_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((stage_v_224_1 + pub_r000742_10_1) + 11) & 127;
  int stage_v_301_2 = ((stage_v_224_2 + pub_r000742_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_257_1 + pub_r000742_16_1) + 37) & 127;
  int stage_v_302_2 = ((stage_v_257_2 + pub_r000742_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((sec_r000742_7_1 + pub_r000742_9_1) + 23) & 127;
  int stage_v_303_2 = ((sec_r000742_7_2 + pub_r000742_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((sec_r000742_13_1 + pub_r000742_9_1) + 45) & 127;
  int stage_v_304_2 = ((sec_r000742_13_2 + pub_r000742_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_181_1 + pub_r000742_4_1) + 47) & 127;
  int stage_v_305_2 = ((stage_v_181_2 + pub_r000742_4_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((stage_v_176_1 + pub_r000742_7_1) + 9) & 127;
  int stage_v_306_2 = ((stage_v_176_2 + pub_r000742_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((stage_v_43_1 + pub_r000742_8_1) + 9) & 127;
  int stage_v_307_2 = ((stage_v_43_2 + pub_r000742_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((sec_r000742_2_1 + pub_r000742_2_1) + 29) & 127;
  int stage_v_308_2 = ((sec_r000742_2_2 + pub_r000742_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((stage_v_251_1 + pub_r000742_6_1) + 16) & 127;
  int stage_v_309_2 = ((stage_v_251_2 + pub_r000742_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((stage_v_136_1 + pub_r000742_6_1) + 6) & 127;
  int stage_v_310_2 = ((stage_v_136_2 + pub_r000742_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((stage_v_276_1 + pub_r000742_5_1) + 33) & 127;
  int stage_v_311_2 = ((stage_v_276_2 + pub_r000742_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((stage_v_202_1 + pub_r000742_16_1) + 15) & 127;
  int stage_v_312_2 = ((stage_v_202_2 + pub_r000742_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((sec_r000742_3_1 + pub_r000742_13_1) + 14) & 127;
  int stage_v_313_2 = ((sec_r000742_3_2 + pub_r000742_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((sec_r000742_1_1 + pub_r000742_15_1) + 19) & 127;
  int stage_v_314_2 = ((sec_r000742_1_2 + pub_r000742_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((sec_r000742_12_1 + pub_r000742_16_1) + 40) & 127;
  int stage_v_315_2 = ((sec_r000742_12_2 + pub_r000742_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((stage_v_159_1 + pub_r000742_14_1) + 15) & 127;
  int stage_v_316_2 = ((stage_v_159_2 + pub_r000742_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((stage_v_221_1 + pub_r000742_15_1) + 5) & 127;
  int stage_v_317_2 = ((stage_v_221_2 + pub_r000742_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((stage_v_195_1 + pub_r000742_10_1) + 45) & 127;
  int stage_v_318_2 = ((stage_v_195_2 + pub_r000742_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((sec_r000742_5_1 + pub_r000742_4_1) + 4) & 127;
  int stage_v_319_2 = ((sec_r000742_5_2 + pub_r000742_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((stage_v_209_1 + pub_r000742_16_1) + 4) & 127;
  int stage_v_320_2 = ((stage_v_209_2 + pub_r000742_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((sec_r000742_0_1 + pub_r000742_3_1) + 8) & 127;
  int stage_v_321_2 = ((sec_r000742_0_2 + pub_r000742_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((stage_v_221_1 + pub_r000742_3_1) + 37) & 127;
  int stage_v_322_2 = ((stage_v_221_2 + pub_r000742_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((stage_v_28_1 + pub_r000742_3_1) + 26) & 127;
  int stage_v_323_2 = ((stage_v_28_2 + pub_r000742_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((sec_r000742_17_1 + pub_r000742_10_1) + 27) & 127;
  int stage_v_324_2 = ((sec_r000742_17_2 + pub_r000742_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((sec_r000742_12_1 + pub_r000742_7_1) + 16) & 127;
  int stage_v_325_2 = ((sec_r000742_12_2 + pub_r000742_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((sec_r000742_1_1 + pub_r000742_13_1) + 46) & 127;
  int stage_v_326_2 = ((sec_r000742_1_2 + pub_r000742_13_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((stage_v_281_1 + pub_r000742_2_1) + 36) & 127;
  int stage_v_327_2 = ((stage_v_281_2 + pub_r000742_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((sec_r000742_5_1 + pub_r000742_12_1) + 36) & 127;
  int stage_v_328_2 = ((sec_r000742_5_2 + pub_r000742_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((sec_r000742_9_1 + pub_r000742_12_1) + 27) & 127;
  int stage_v_329_2 = ((sec_r000742_9_2 + pub_r000742_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((sec_r000742_0_1 + pub_r000742_16_1) + 34) & 127;
  int stage_v_330_2 = ((sec_r000742_0_2 + pub_r000742_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((sec_r000742_7_1 + pub_r000742_9_1) + 31) & 127;
  int stage_v_331_2 = ((sec_r000742_7_2 + pub_r000742_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((sec_r000742_15_1 + pub_r000742_1_1) + 4) & 127;
  int stage_v_332_2 = ((sec_r000742_15_2 + pub_r000742_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((sec_r000742_14_1 + pub_r000742_5_1) + 35) & 127;
  int stage_v_333_2 = ((sec_r000742_14_2 + pub_r000742_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((stage_v_166_1 + pub_r000742_15_1) + 44) & 127;
  int stage_v_334_2 = ((stage_v_166_2 + pub_r000742_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((stage_v_111_1 + pub_r000742_3_1) + 35) & 127;
  int stage_v_335_2 = ((stage_v_111_2 + pub_r000742_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((sec_r000742_10_1 + pub_r000742_10_1) + 49) & 127;
  int stage_v_336_2 = ((sec_r000742_10_2 + pub_r000742_10_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000742_13_1 != sec_r000742_13_2);
  __CPROVER_assume(sec_r000742_17_1 != sec_r000742_17_2);
  __CPROVER_assume(pub_r000742_13_1 == pub_r000742_13_2);
  __CPROVER_assume(sec_r000742_10_1 != sec_r000742_10_2);
  __CPROVER_assume(sec_r000742_9_1 != sec_r000742_9_2);
  __CPROVER_assume(sec_r000742_7_1 != sec_r000742_7_2);
  __CPROVER_assume(pub_r000742_15_1 == pub_r000742_15_2);
  __CPROVER_assume(pub_r000742_7_1 == pub_r000742_7_2);
  __CPROVER_assume(pub_r000742_3_1 == pub_r000742_3_2);
  __CPROVER_assume(pub_r000742_5_1 == pub_r000742_5_2);
  __CPROVER_assume(sec_r000742_0_1 != sec_r000742_0_2);
  __CPROVER_assume(sec_r000742_12_1 != sec_r000742_12_2);
  __CPROVER_assume(pub_r000742_1_1 == pub_r000742_1_2);
  __CPROVER_assume(sec_r000742_6_1 != sec_r000742_6_2);
  __CPROVER_assume(sec_r000742_8_1 != sec_r000742_8_2);
  __CPROVER_assume(sec_r000742_1_1 != sec_r000742_1_2);
  __CPROVER_assume(sec_r000742_2_1 != sec_r000742_2_2);
  __CPROVER_assume(sec_r000742_5_1 != sec_r000742_5_2);
  __CPROVER_assume(pub_r000742_0_1 == pub_r000742_0_2);
  __CPROVER_assume(pub_r000742_2_1 == pub_r000742_2_2);
  __CPROVER_assume(sec_r000742_4_1 != sec_r000742_4_2);
  __CPROVER_assume(pub_r000742_9_1 == pub_r000742_9_2);
  __CPROVER_assume(sec_r000742_15_1 != sec_r000742_15_2);
  __CPROVER_assume(pub_r000742_12_1 == pub_r000742_12_2);
  __CPROVER_assume(sec_r000742_16_1 != sec_r000742_16_2);
  __CPROVER_assume(pub_r000742_16_1 == pub_r000742_16_2);
  __CPROVER_assume(pub_r000742_4_1 == pub_r000742_4_2);
  __CPROVER_assume(pub_r000742_14_1 == pub_r000742_14_2);
  __CPROVER_assume(pub_r000742_10_1 == pub_r000742_10_2);
  __CPROVER_assume(pub_r000742_8_1 == pub_r000742_8_2);
  __CPROVER_assume(pub_r000742_6_1 == pub_r000742_6_2);
  __CPROVER_assume(sec_r000742_11_1 != sec_r000742_11_2);
  __CPROVER_assume(sec_r000742_14_1 != sec_r000742_14_2);
  __CPROVER_assume(sec_r000742_3_1 != sec_r000742_3_2);
  __CPROVER_assume(pub_r000742_11_1 == pub_r000742_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.channels == st_var_3_2.channels);
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
}


