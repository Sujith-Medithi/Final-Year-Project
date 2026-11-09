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
struct AudioFrame_R001066_6613_0
{
  unsigned char envelope;
  short channels;
  int rms;
  int sample_rate;
  short peak;
  int buffer[3];
};
struct DeviceConfig_R001066_6613_1
{
  unsigned char port;
  short baud_rate;
  unsigned char parity;
  short stop_bits;
  int id;
  unsigned char timeout;
  int buffer[3];
};
union PacketPayload_R001066_6613_0
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
void fn_R001066_6613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_94_1)
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

  switch (quotient_94_2)
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
  int cursor_98_1 = local_arr_1[aux_1 % 3];
  int cursor_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_94_1 == quotient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_98_1 == cursor_98_2);
}

int fn_R001066_6613_0(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_94 = (aux + st.buffer[1]) & 3;
  switch (quotient_94)
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
  int cursor_98 = local_arr[aux % 3];
  acc = (acc + (cursor_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001066_6613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_60_1 > 48)
  {
    acc_1 = ((acc_1 + (phase_60_1 * 2)) + 5) & 127;
    aux_1 ^= phase_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_60_2 > 48)
  {
    acc_2 = ((acc_2 + (phase_60_2 * 2)) + 5) & 127;
    aux_2 ^= phase_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_85_1) & 63;
  aux_2 = (aux_2 + scale_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_60_1 == phase_60_2);
  assert(scale_85_1 == scale_85_2);
}

int fn_R001066_6613_1(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_60 > 48)
  {
    acc = ((acc + (phase_60 * 2)) + 5) & 127;
    aux ^= phase_60 & 15;
  }
  else
  {
    acc = ((acc - phase_60) + 11) & 127;
    aux += 3;
  }
  int scale_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001066_6613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_25_1) & 63;
  aux_2 = (aux_2 + checksum_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_65_1)
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

  switch (sample_65_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_18_1 = local_arr_1[aux_1 % 3];
  int mask_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_25_1 == checksum_25_2);
  assert(sample_65_1 == sample_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_18_1 == mask_18_2);
}

int fn_R001066_6613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_25) & 63;
  acc ^= aux;
  int sample_65 = (aux + st.buffer[1]) & 3;
  switch (sample_65)
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

  int local_arr[3] = {4, 9, 15};
  int mask_18 = local_arr[aux % 3];
  acc = (acc + (mask_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001066_6613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_57_1 > 17)
  {
    acc_1 = ((acc_1 + (residue_57_1 * 2)) + 5) & 127;
    aux_1 ^= residue_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_57_2 > 17)
  {
    acc_2 = ((acc_2 + (residue_57_2 * 2)) + 5) & 127;
    aux_2 ^= residue_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_51_1 = local_arr_1[aux_1 % 3];
  int anchor_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_51_2 * 2)) & 127;
  int pivot_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_47_1) & 63;
  aux_2 = (aux_2 + pivot_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_57_1 == residue_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_51_1 == anchor_51_2);
  assert(pivot_47_1 == pivot_47_2);
}

int fn_R001066_6613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_57 > 17)
  {
    acc = ((acc + (residue_57 * 2)) + 5) & 127;
    aux ^= residue_57 & 15;
  }
  else
  {
    acc = ((acc - residue_57) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_51 = local_arr[aux % 3];
  acc = (acc + (anchor_51 * 2)) & 127;
  int pivot_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001066_6613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_58_1 = 0;
  int segment_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_58_1 = ((segment_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_58_2 = ((segment_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_58_1) & 127;
    acc_2 = (acc_2 + segment_58_2) & 127;
  }

  int checksum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_79_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_79_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_79_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_79_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_49_1)
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

  switch (anchor_49_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(checksum_79_1 == checksum_79_2);
  assert(anchor_49_1 == anchor_49_2);
}

int fn_R001066_6613_4(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_58 = ((segment_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_58) & 127;
  }

  int checksum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_79 > 30)
  {
    acc = ((acc + (checksum_79 * 2)) + 5) & 127;
    aux ^= checksum_79 & 15;
  }
  else
  {
    acc = ((acc - checksum_79) + 11) & 127;
    aux += 3;
  }
  int anchor_49 = (aux + st.buffer[1]) & 3;
  switch (anchor_49)
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

void fn_R001066_6613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_40_1 = local_arr_1[aux_1 % 3];
  int parity_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_40_2 * 2)) & 127;
  int anchor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_57_1)
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

  switch (anchor_57_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_40_1 == parity_40_2);
  assert(anchor_57_1 == anchor_57_2);
}

int fn_R001066_6613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_40 = local_arr[aux % 3];
  acc = (acc + (parity_40 * 2)) & 127;
  int anchor_57 = (aux + st.buffer[1]) & 3;
  switch (anchor_57)
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

void fn_R001066_6613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int margin_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_64_1) & 63;
  aux_2 = (aux_2 + margin_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_28_1)
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

  switch (parity_28_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_64_1 == margin_64_2);
  assert(parity_28_1 == parity_28_2);
}

int fn_R001066_6613_6(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_64) & 63;
  acc ^= aux;
  int parity_28 = (aux + st.buffer[1]) & 3;
  switch (parity_28)
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

void fn_R001066_6613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_13_1 > 18)
  {
    acc_1 = ((acc_1 + (segment_13_1 * 2)) + 5) & 127;
    aux_1 ^= segment_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_13_2 > 18)
  {
    acc_2 = ((acc_2 + (segment_13_2 * 2)) + 5) & 127;
    aux_2 ^= segment_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_22_1 = 0;
  int quantum_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_22_1 = ((quantum_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_22_2 = ((quantum_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_22_1) & 127;
    acc_2 = (acc_2 + quantum_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_13_1 == segment_13_2);
  assert(quantum_22_1 == quantum_22_2);
}

int fn_R001066_6613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_13 > 18)
  {
    acc = ((acc + (segment_13 * 2)) + 5) & 127;
    aux ^= segment_13 & 15;
  }
  else
  {
    acc = ((acc - segment_13) + 11) & 127;
    aux += 3;
  }
  int quantum_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_22 = ((quantum_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001066_6613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_94_1 = 0;
  int scale_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_94_1 = ((scale_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_94_2 = ((scale_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_94_1) & 127;
    acc_2 = (acc_2 + scale_94_2) & 127;
  }

  int pivot_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_50_1 > 25)
  {
    acc_1 = ((acc_1 + (pivot_50_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_50_2 > 25)
  {
    acc_2 = ((acc_2 + (pivot_50_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_94_1 == scale_94_2);
  assert(pivot_50_1 == pivot_50_2);
}

int fn_R001066_6613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_94 = ((scale_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_94) & 127;
  }

  int pivot_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_50 > 25)
  {
    acc = ((acc + (pivot_50 * 2)) + 5) & 127;
    aux ^= pivot_50 & 15;
  }
  else
  {
    acc = ((acc - pivot_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001066_6613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_28_1) & 63;
  aux_2 = (aux_2 + sample_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_87_1)
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

  switch (accumulator_87_2)
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

  int delta_79_1 = 0;
  int delta_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_79_1 = ((delta_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_79_2 = ((delta_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_79_1) & 127;
    acc_2 = (acc_2 + delta_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_75_1 = local_arr_1[aux_1 % 3];
  int weight_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_28_1 == sample_28_2);
  assert(accumulator_87_1 == accumulator_87_2);
  assert(delta_79_1 == delta_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_75_1 == weight_75_2);
}

int fn_R001066_6613_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_28) & 63;
  acc ^= aux;
  int accumulator_87 = (aux + st.buffer[1]) & 3;
  switch (accumulator_87)
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

  int delta_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_79 = ((delta_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int weight_75 = local_arr[aux % 3];
  acc = (acc + (weight_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001066_6613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_37_1 = local_arr_1[aux_1 % 3];
  int offset_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_37_2 * 2)) & 127;
  int bound_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_58_1)
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

  switch (bound_58_2)
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

  int quantum_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_29_1 > 47)
  {
    acc_1 = ((acc_1 + (quantum_29_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_29_2 > 47)
  {
    acc_2 = ((acc_2 + (quantum_29_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_37_1 == offset_37_2);
  assert(bound_58_1 == bound_58_2);
  assert(quantum_29_1 == quantum_29_2);
}

int fn_R001066_6613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int offset_37 = local_arr[aux % 3];
  acc = (acc + (offset_37 * 2)) & 127;
  int bound_58 = (aux + st.buffer[1]) & 3;
  switch (bound_58)
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

  int quantum_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_29 > 47)
  {
    acc = ((acc + (quantum_29 * 2)) + 5) & 127;
    aux ^= quantum_29 & 15;
  }
  else
  {
    acc = ((acc - quantum_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001066_6613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_12_1 = local_arr_1[aux_1 % 3];
  int parity_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_12_2 * 2)) & 127;
  int scale_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_61_1) & 63;
  aux_2 = (aux_2 + scale_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(scale_61_1 == scale_61_2);
}

int fn_R001066_6613_11(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int parity_12 = local_arr[aux % 3];
  acc = (acc + (parity_12 * 2)) & 127;
  int scale_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001066_6613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_54_1 > 25)
  {
    acc_1 = ((acc_1 + (factor_54_1 * 2)) + 5) & 127;
    aux_1 ^= factor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_54_2 > 25)
  {
    acc_2 = ((acc_2 + (factor_54_2 * 2)) + 5) & 127;
    aux_2 ^= factor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_50_1) & 63;
  aux_2 = (aux_2 + mask_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_94_1)
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

  switch (tracker_94_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_54_1 == factor_54_2);
  assert(mask_50_1 == mask_50_2);
  assert(tracker_94_1 == tracker_94_2);
}

int fn_R001066_6613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_54 > 25)
  {
    acc = ((acc + (factor_54 * 2)) + 5) & 127;
    aux ^= factor_54 & 15;
  }
  else
  {
    acc = ((acc - factor_54) + 11) & 127;
    aux += 3;
  }
  int mask_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_50) & 63;
  acc ^= aux;
  int tracker_94 = (aux + st.buffer[1]) & 3;
  switch (tracker_94)
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

void fn_R001066_6613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_91_1)
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

  switch (bound_91_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_16_1 > 27)
  {
    acc_1 = ((acc_1 + (anchor_16_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_16_2 > 27)
  {
    acc_2 = ((acc_2 + (anchor_16_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_91_1 == bound_91_2);
  assert(anchor_16_1 == anchor_16_2);
}

int fn_R001066_6613_13(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_91 = (aux + st.buffer[1]) & 3;
  switch (bound_91)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_16 > 27)
  {
    acc = ((acc + (anchor_16 * 2)) + 5) & 127;
    aux ^= anchor_16 & 15;
  }
  else
  {
    acc = ((acc - anchor_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001066_6613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_99_1)
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

  switch (cursor_99_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_99_1 == cursor_99_2);
}

int fn_R001066_6613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_99 = (aux + st.buffer[1]) & 3;
  switch (cursor_99)
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

void fn_R001066_6613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_21_1 = local_arr_1[aux_1 % 3];
  int weight_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_21_2 * 2)) & 127;
  int bound_37_1 = 0;
  int bound_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_37_1 = ((bound_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_37_2 = ((bound_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_37_1) & 127;
    acc_2 = (acc_2 + bound_37_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_21_1 == weight_21_2);
  assert(bound_37_1 == bound_37_2);
}

int fn_R001066_6613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_21 = local_arr[aux % 3];
  acc = (acc + (weight_21 * 2)) & 127;
  int bound_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_37 = ((bound_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_37) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001066_6613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_67_1) & 63;
  aux_2 = (aux_2 + pivot_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_79_1 = 0;
  int coefficient_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_79_1 = ((coefficient_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_79_2 = ((coefficient_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_79_1) & 127;
    acc_2 = (acc_2 + coefficient_79_2) & 127;
  }

  int weight_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_94_1 > 44)
  {
    acc_1 = ((acc_1 + (weight_94_1 * 2)) + 5) & 127;
    aux_1 ^= weight_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_94_2 > 44)
  {
    acc_2 = ((acc_2 + (weight_94_2 * 2)) + 5) & 127;
    aux_2 ^= weight_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_67_1 == pivot_67_2);
  assert(coefficient_79_1 == coefficient_79_2);
  assert(weight_94_1 == weight_94_2);
}

int fn_R001066_6613_16(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001066_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_67) & 63;
  acc ^= aux;
  int coefficient_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_79 = ((coefficient_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_79) & 127;
  }

  int weight_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_94 > 44)
  {
    acc = ((acc + (weight_94 * 2)) + 5) & 127;
    aux ^= weight_94 & 15;
  }
  else
  {
    acc = ((acc - weight_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001066_6613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_72_1 = 0;
  int sample_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_72_1 = ((sample_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_72_2 = ((sample_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_72_1) & 127;
    acc_2 = (acc_2 + sample_72_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_10_1) & 63;
  aux_2 = (aux_2 + window_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_73_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_73_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_73_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_73_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_72_1 == sample_72_2);
  assert(window_10_1 == window_10_2);
  assert(quotient_73_1 == quotient_73_2);
}

int fn_R001066_6613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_72 = ((sample_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_72) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_10) & 63;
  acc ^= aux;
  int quotient_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_73 > 13)
  {
    acc = ((acc + (quotient_73 * 2)) + 5) & 127;
    aux ^= quotient_73 & 15;
  }
  else
  {
    acc = ((acc - quotient_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001066_6613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st_1 = {0};
  struct AudioFrame_R001066_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_21_1 = local_arr_1[aux_1 % 3];
  int tally_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_21_2 * 2)) & 127;
  int margin_21_1 = 0;
  int margin_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_21_1 = ((margin_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_21_2 = ((margin_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_21_1) & 127;
    acc_2 = (acc_2 + margin_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_21_1 == tally_21_2);
  assert(margin_21_1 == margin_21_2);
}

int fn_R001066_6613_18(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001066_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tally_21 = local_arr[aux % 3];
  acc = (acc + (tally_21 * 2)) & 127;
  int margin_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_21 = ((margin_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_21) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001066_0_1;
  int sec_r001066_0_2;
  int sec_r001066_1_1;
  int sec_r001066_1_2;
  int sec_r001066_2_1;
  int sec_r001066_2_2;
  int sec_r001066_3_1;
  int sec_r001066_3_2;
  int sec_r001066_4_1;
  int sec_r001066_4_2;
  int sec_r001066_5_1;
  int sec_r001066_5_2;
  int sec_r001066_6_1;
  int sec_r001066_6_2;
  int sec_r001066_7_1;
  int sec_r001066_7_2;
  int sec_r001066_8_1;
  int sec_r001066_8_2;
  int sec_r001066_9_1;
  int sec_r001066_9_2;
  int sec_r001066_10_1;
  int sec_r001066_10_2;
  int sec_r001066_11_1;
  int sec_r001066_11_2;
  int sec_r001066_12_1;
  int sec_r001066_12_2;
  int sec_r001066_13_1;
  int sec_r001066_13_2;
  int sec_r001066_14_1;
  int sec_r001066_14_2;
  int sec_r001066_15_1;
  int sec_r001066_15_2;
  int sec_r001066_16_1;
  int sec_r001066_16_2;
  int pub_r001066_0_1;
  int pub_r001066_0_2;
  int pub_r001066_1_1;
  int pub_r001066_1_2;
  int pub_r001066_2_1;
  int pub_r001066_2_2;
  int pub_r001066_3_1;
  int pub_r001066_3_2;
  int pub_r001066_4_1;
  int pub_r001066_4_2;
  int pub_r001066_5_1;
  int pub_r001066_5_2;
  int pub_r001066_6_1;
  int pub_r001066_6_2;
  int pub_r001066_7_1;
  int pub_r001066_7_2;
  int pub_r001066_8_1;
  int pub_r001066_8_2;
  int pub_r001066_9_1;
  int pub_r001066_9_2;
  int pub_r001066_10_1;
  int pub_r001066_10_2;
  int pub_r001066_11_1;
  int pub_r001066_11_2;
  int pub_r001066_12_1;
  int pub_r001066_12_2;
  int pub_r001066_13_1;
  int pub_r001066_13_2;
  int pub_r001066_14_1;
  int pub_r001066_14_2;
  int pub_r001066_15_1;
  int pub_r001066_15_2;
  int pub_r001066_16_1;
  int pub_r001066_16_2;
  int pub_r001066_17_1;
  int pub_r001066_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001066_0_1 >= (-100)) && (pub_r001066_0_1 <= 100));
  __CPROVER_assume((pub_r001066_0_2 >= (-100)) && (pub_r001066_0_2 <= 100));
  __CPROVER_assume((pub_r001066_1_1 >= (-100)) && (pub_r001066_1_1 <= 100));
  __CPROVER_assume((pub_r001066_1_2 >= (-100)) && (pub_r001066_1_2 <= 100));
  __CPROVER_assume((pub_r001066_2_1 >= (-100)) && (pub_r001066_2_1 <= 100));
  __CPROVER_assume((pub_r001066_2_2 >= (-100)) && (pub_r001066_2_2 <= 100));
  __CPROVER_assume((pub_r001066_3_1 >= (-100)) && (pub_r001066_3_1 <= 100));
  __CPROVER_assume((pub_r001066_3_2 >= (-100)) && (pub_r001066_3_2 <= 100));
  __CPROVER_assume((pub_r001066_4_1 >= (-100)) && (pub_r001066_4_1 <= 100));
  __CPROVER_assume((pub_r001066_4_2 >= (-100)) && (pub_r001066_4_2 <= 100));
  __CPROVER_assume((pub_r001066_5_1 >= (-100)) && (pub_r001066_5_1 <= 100));
  __CPROVER_assume((pub_r001066_5_2 >= (-100)) && (pub_r001066_5_2 <= 100));
  __CPROVER_assume((pub_r001066_6_1 >= (-100)) && (pub_r001066_6_1 <= 100));
  __CPROVER_assume((pub_r001066_6_2 >= (-100)) && (pub_r001066_6_2 <= 100));
  __CPROVER_assume((pub_r001066_7_1 >= (-100)) && (pub_r001066_7_1 <= 100));
  __CPROVER_assume((pub_r001066_7_2 >= (-100)) && (pub_r001066_7_2 <= 100));
  __CPROVER_assume((pub_r001066_8_1 >= (-100)) && (pub_r001066_8_1 <= 100));
  __CPROVER_assume((pub_r001066_8_2 >= (-100)) && (pub_r001066_8_2 <= 100));
  __CPROVER_assume((pub_r001066_9_1 >= (-100)) && (pub_r001066_9_1 <= 100));
  __CPROVER_assume((pub_r001066_9_2 >= (-100)) && (pub_r001066_9_2 <= 100));
  __CPROVER_assume((pub_r001066_10_1 >= (-100)) && (pub_r001066_10_1 <= 100));
  __CPROVER_assume((pub_r001066_10_2 >= (-100)) && (pub_r001066_10_2 <= 100));
  __CPROVER_assume((pub_r001066_11_1 >= (-100)) && (pub_r001066_11_1 <= 100));
  __CPROVER_assume((pub_r001066_11_2 >= (-100)) && (pub_r001066_11_2 <= 100));
  __CPROVER_assume((pub_r001066_12_1 >= (-100)) && (pub_r001066_12_1 <= 100));
  __CPROVER_assume((pub_r001066_12_2 >= (-100)) && (pub_r001066_12_2 <= 100));
  __CPROVER_assume((pub_r001066_13_1 >= (-100)) && (pub_r001066_13_1 <= 100));
  __CPROVER_assume((pub_r001066_13_2 >= (-100)) && (pub_r001066_13_2 <= 100));
  __CPROVER_assume((pub_r001066_14_1 >= (-100)) && (pub_r001066_14_1 <= 100));
  __CPROVER_assume((pub_r001066_14_2 >= (-100)) && (pub_r001066_14_2 <= 100));
  __CPROVER_assume((pub_r001066_15_1 >= (-100)) && (pub_r001066_15_1 <= 100));
  __CPROVER_assume((pub_r001066_15_2 >= (-100)) && (pub_r001066_15_2 <= 100));
  __CPROVER_assume((pub_r001066_16_1 >= (-100)) && (pub_r001066_16_1 <= 100));
  __CPROVER_assume((pub_r001066_16_2 >= (-100)) && (pub_r001066_16_2 <= 100));
  __CPROVER_assume((pub_r001066_17_1 >= (-100)) && (pub_r001066_17_1 <= 100));
  __CPROVER_assume((pub_r001066_17_2 >= (-100)) && (pub_r001066_17_2 <= 100));
  __CPROVER_assume((sec_r001066_0_1 >= 0) && (sec_r001066_0_1 <= 255));
  __CPROVER_assume((sec_r001066_0_2 >= 0) && (sec_r001066_0_2 <= 255));
  __CPROVER_assume((sec_r001066_1_1 >= 0) && (sec_r001066_1_1 <= 255));
  __CPROVER_assume((sec_r001066_1_2 >= 0) && (sec_r001066_1_2 <= 255));
  __CPROVER_assume((sec_r001066_2_1 >= 0) && (sec_r001066_2_1 <= 255));
  __CPROVER_assume((sec_r001066_2_2 >= 0) && (sec_r001066_2_2 <= 255));
  __CPROVER_assume((sec_r001066_3_1 >= 0) && (sec_r001066_3_1 <= 255));
  __CPROVER_assume((sec_r001066_3_2 >= 0) && (sec_r001066_3_2 <= 255));
  __CPROVER_assume((sec_r001066_4_1 >= 0) && (sec_r001066_4_1 <= 255));
  __CPROVER_assume((sec_r001066_4_2 >= 0) && (sec_r001066_4_2 <= 255));
  __CPROVER_assume((sec_r001066_5_1 >= 0) && (sec_r001066_5_1 <= 255));
  __CPROVER_assume((sec_r001066_5_2 >= 0) && (sec_r001066_5_2 <= 255));
  __CPROVER_assume((sec_r001066_6_1 >= 0) && (sec_r001066_6_1 <= 255));
  __CPROVER_assume((sec_r001066_6_2 >= 0) && (sec_r001066_6_2 <= 255));
  __CPROVER_assume((sec_r001066_7_1 >= 0) && (sec_r001066_7_1 <= 255));
  __CPROVER_assume((sec_r001066_7_2 >= 0) && (sec_r001066_7_2 <= 255));
  __CPROVER_assume((sec_r001066_8_1 >= 0) && (sec_r001066_8_1 <= 255));
  __CPROVER_assume((sec_r001066_8_2 >= 0) && (sec_r001066_8_2 <= 255));
  __CPROVER_assume((sec_r001066_9_1 >= 0) && (sec_r001066_9_1 <= 255));
  __CPROVER_assume((sec_r001066_9_2 >= 0) && (sec_r001066_9_2 <= 255));
  __CPROVER_assume((sec_r001066_10_1 >= 0) && (sec_r001066_10_1 <= 255));
  __CPROVER_assume((sec_r001066_10_2 >= 0) && (sec_r001066_10_2 <= 255));
  __CPROVER_assume((sec_r001066_11_1 >= 0) && (sec_r001066_11_1 <= 255));
  __CPROVER_assume((sec_r001066_11_2 >= 0) && (sec_r001066_11_2 <= 255));
  __CPROVER_assume((sec_r001066_12_1 >= 0) && (sec_r001066_12_1 <= 255));
  __CPROVER_assume((sec_r001066_12_2 >= 0) && (sec_r001066_12_2 <= 255));
  __CPROVER_assume((sec_r001066_13_1 >= 0) && (sec_r001066_13_1 <= 255));
  __CPROVER_assume((sec_r001066_13_2 >= 0) && (sec_r001066_13_2 <= 255));
  __CPROVER_assume((sec_r001066_14_1 >= 0) && (sec_r001066_14_1 <= 255));
  __CPROVER_assume((sec_r001066_14_2 >= 0) && (sec_r001066_14_2 <= 255));
  __CPROVER_assume((sec_r001066_15_1 >= 0) && (sec_r001066_15_1 <= 255));
  __CPROVER_assume((sec_r001066_15_2 >= 0) && (sec_r001066_15_2 <= 255));
  __CPROVER_assume((sec_r001066_16_1 >= 0) && (sec_r001066_16_1 <= 255));
  __CPROVER_assume((sec_r001066_16_2 >= 0) && (sec_r001066_16_2 <= 255));
  struct AudioFrame_R001066_6613_0 st_var_0_1 = {0};
  struct AudioFrame_R001066_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001066_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001066_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001066_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001066_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001066_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001066_0_2 + 7) & 15;
  struct DeviceConfig_R001066_6613_1 st_var_1_1 = {0};
  struct DeviceConfig_R001066_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001066_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001066_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001066_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001066_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001066_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001066_0_2 + 9) & 15;
  union PacketPayload_R001066_6613_0 u_var_1;
  union PacketPayload_R001066_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001066_6613_0(sec_r001066_0_1, pub_r001066_1_1);
  int helper_flow_0_2 = fn_R001066_6613_0(sec_r001066_0_2, pub_r001066_1_2);
  fn_R001066_6613_0_2(sec_r001066_0_1, pub_r001066_1_1, sec_r001066_0_2, pub_r001066_1_2);
  int helper_flow_1_1 = fn_R001066_6613_1(sec_r001066_1_1, pub_r001066_2_1);
  int helper_flow_1_2 = fn_R001066_6613_1(sec_r001066_1_2, pub_r001066_2_2);
  fn_R001066_6613_1_2(sec_r001066_1_1, pub_r001066_2_1, sec_r001066_1_2, pub_r001066_2_2);
  int helper_flow_2_1 = fn_R001066_6613_2(sec_r001066_2_1, sec_r001066_3_1, pub_r001066_4_1);
  int helper_flow_2_2 = fn_R001066_6613_2(sec_r001066_2_2, sec_r001066_3_2, pub_r001066_4_2);
  fn_R001066_6613_2_2(sec_r001066_2_1, sec_r001066_3_1, pub_r001066_4_1, sec_r001066_2_2, sec_r001066_3_2, pub_r001066_4_2);
  int helper_flow_3_1 = fn_R001066_6613_3(sec_r001066_3_1, pub_r001066_4_1, pub_r001066_5_1);
  int helper_flow_3_2 = fn_R001066_6613_3(sec_r001066_3_2, pub_r001066_4_2, pub_r001066_5_2);
  fn_R001066_6613_3_2(sec_r001066_3_1, pub_r001066_4_1, pub_r001066_5_1, sec_r001066_3_2, pub_r001066_4_2, pub_r001066_5_2);
  int helper_flow_4_1 = fn_R001066_6613_4(sec_r001066_4_1, pub_r001066_5_1);
  int helper_flow_4_2 = fn_R001066_6613_4(sec_r001066_4_2, pub_r001066_5_2);
  fn_R001066_6613_4_2(sec_r001066_4_1, pub_r001066_5_1, sec_r001066_4_2, pub_r001066_5_2);
  int helper_flow_5_1 = fn_R001066_6613_5(sec_r001066_5_1, pub_r001066_6_1, pub_r001066_7_1, pub_r001066_8_1, pub_r001066_9_1);
  int helper_flow_5_2 = fn_R001066_6613_5(sec_r001066_5_2, pub_r001066_6_2, pub_r001066_7_2, pub_r001066_8_2, pub_r001066_9_2);
  fn_R001066_6613_5_2(sec_r001066_5_1, pub_r001066_6_1, pub_r001066_7_1, pub_r001066_8_1, pub_r001066_9_1, sec_r001066_5_2, pub_r001066_6_2, pub_r001066_7_2, pub_r001066_8_2, pub_r001066_9_2);
  int helper_flow_6_1 = fn_R001066_6613_6(sec_r001066_6_1, sec_r001066_7_1);
  int helper_flow_6_2 = fn_R001066_6613_6(sec_r001066_6_2, sec_r001066_7_2);
  fn_R001066_6613_6_2(sec_r001066_6_1, sec_r001066_7_1, sec_r001066_6_2, sec_r001066_7_2);
  int helper_flow_7_1 = fn_R001066_6613_7(sec_r001066_7_1, pub_r001066_8_1, pub_r001066_9_1, pub_r001066_10_1, pub_r001066_11_1);
  int helper_flow_7_2 = fn_R001066_6613_7(sec_r001066_7_2, pub_r001066_8_2, pub_r001066_9_2, pub_r001066_10_2, pub_r001066_11_2);
  fn_R001066_6613_7_2(sec_r001066_7_1, pub_r001066_8_1, pub_r001066_9_1, pub_r001066_10_1, pub_r001066_11_1, sec_r001066_7_2, pub_r001066_8_2, pub_r001066_9_2, pub_r001066_10_2, pub_r001066_11_2);
  int helper_flow_8_1 = fn_R001066_6613_8(sec_r001066_8_1, pub_r001066_9_1, pub_r001066_10_1);
  int helper_flow_8_2 = fn_R001066_6613_8(sec_r001066_8_2, pub_r001066_9_2, pub_r001066_10_2);
  fn_R001066_6613_8_2(sec_r001066_8_1, pub_r001066_9_1, pub_r001066_10_1, sec_r001066_8_2, pub_r001066_9_2, pub_r001066_10_2);
  int helper_flow_9_1 = fn_R001066_6613_9(sec_r001066_9_1, pub_r001066_10_1);
  int helper_flow_9_2 = fn_R001066_6613_9(sec_r001066_9_2, pub_r001066_10_2);
  fn_R001066_6613_9_2(sec_r001066_9_1, pub_r001066_10_1, sec_r001066_9_2, pub_r001066_10_2);
  int stage_v_0_1 = ((sec_r001066_0_1 + (pub_r001066_2_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001066_0_2 + (pub_r001066_2_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001066_0_1 + (pub_r001066_6_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001066_0_2 + (pub_r001066_6_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001066_10_1 * 2) + 17) & 63;
  int stage_v_2_2 = ((pub_r001066_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((helper_flow_6_1 + (pub_r001066_1_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_6_2 + (pub_r001066_1_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001066_8_1 * 2) + 33) & 63;
  int stage_v_4_2 = ((pub_r001066_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001066_7_1 + (pub_r001066_8_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001066_7_2 + (pub_r001066_8_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001066_12_1 * 2) + 38) & 63;
  int stage_v_6_2 = ((pub_r001066_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001066_3_1 + (pub_r001066_2_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001066_3_2 + (pub_r001066_2_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001066_5_1 * 2) + 24) & 63;
  int stage_v_8_2 = ((pub_r001066_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((stage_v_1_1 + (pub_r001066_12_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_1_2 + (pub_r001066_12_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001066_15_1 * 2) + 40) & 63;
  int stage_v_10_2 = ((pub_r001066_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((stage_v_0_1 + (pub_r001066_8_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((stage_v_0_2 + (pub_r001066_8_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001066_0_1 * 2) + 39) & 63;
  int stage_v_12_2 = ((pub_r001066_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001066_13_1 + (pub_r001066_10_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001066_13_2 + (pub_r001066_10_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001066_15_1 + (pub_r001066_5_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001066_15_2 + (pub_r001066_5_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((helper_flow_4_1 + (pub_r001066_0_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((helper_flow_4_2 + (pub_r001066_0_2 * 2)) + 50) & 127;
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
  int stage_v_16_1 = ((helper_flow_0_1 + (pub_r001066_14_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((helper_flow_0_2 + (pub_r001066_14_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((pub_r001066_13_1 * 2) + 28) & 63;
  int stage_v_17_2 = ((pub_r001066_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((sec_r001066_0_1 + (pub_r001066_1_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001066_0_2 + (pub_r001066_1_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((helper_flow_5_1 + (pub_r001066_15_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((helper_flow_5_2 + (pub_r001066_15_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001066_0_1 * 2) + 16) & 63;
  int stage_v_20_2 = ((pub_r001066_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((helper_flow_4_1 + (pub_r001066_11_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_4_2 + (pub_r001066_11_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((helper_flow_5_1 + (pub_r001066_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((helper_flow_5_2 + (pub_r001066_14_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((sec_r001066_0_1 + (pub_r001066_16_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001066_0_2 + (pub_r001066_16_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((sec_r001066_2_1 + (pub_r001066_8_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001066_2_2 + (pub_r001066_8_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((helper_flow_5_1 + (pub_r001066_2_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((helper_flow_5_2 + (pub_r001066_2_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((sec_r001066_16_1 + (pub_r001066_0_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001066_16_2 + (pub_r001066_0_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_23_1 + (pub_r001066_4_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_23_2 + (pub_r001066_4_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_0_1 + (pub_r001066_6_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_0_2 + (pub_r001066_6_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001066_0_1 + (pub_r001066_12_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001066_0_2 + (pub_r001066_12_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((helper_flow_7_1 + (pub_r001066_17_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((helper_flow_7_2 + (pub_r001066_17_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((helper_flow_2_1 + (pub_r001066_17_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((helper_flow_2_2 + (pub_r001066_17_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((helper_flow_0_1 + (pub_r001066_12_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((helper_flow_0_2 + (pub_r001066_12_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_32_1 + (pub_r001066_1_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_32_2 + (pub_r001066_1_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001066_3_1 * 2) + 26) & 63;
  int stage_v_34_2 = ((pub_r001066_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((helper_flow_7_1 + (pub_r001066_9_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_7_2 + (pub_r001066_9_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001066_5_1 * 2) + 13) & 63;
  int stage_v_36_2 = ((pub_r001066_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001066_4_1 * 2) + 22) & 63;
  int stage_v_37_2 = ((pub_r001066_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_19_1 + (pub_r001066_14_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_19_2 + (pub_r001066_14_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((stage_v_18_1 + (pub_r001066_8_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((stage_v_18_2 + (pub_r001066_8_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((helper_flow_5_1 + (pub_r001066_2_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((helper_flow_5_2 + (pub_r001066_2_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_30_1 + (pub_r001066_1_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_30_2 + (pub_r001066_1_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_9_1 + (pub_r001066_12_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_9_2 + (pub_r001066_12_2 * 2)) + 131) & 127;
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
  int stage_v_43_1 = ((pub_r001066_0_1 * 2) + 13) & 63;
  int stage_v_43_2 = ((pub_r001066_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((helper_flow_8_1 + (pub_r001066_0_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((helper_flow_8_2 + (pub_r001066_0_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((helper_flow_8_1 + (pub_r001066_14_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((helper_flow_8_2 + (pub_r001066_14_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001066_17_1 * 2) + 43) & 63;
  int stage_v_46_2 = ((pub_r001066_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_33_1 + (pub_r001066_7_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_33_2 + (pub_r001066_7_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001066_9_1 * 2) + 43) & 63;
  int stage_v_48_2 = ((pub_r001066_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001066_14_1 + (pub_r001066_17_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001066_14_2 + (pub_r001066_17_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((sec_r001066_13_1 + (pub_r001066_12_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001066_13_2 + (pub_r001066_12_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001066_11_1 * 2) + 27) & 63;
  int stage_v_51_2 = ((pub_r001066_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001066_1_1 * 2) + 8) & 63;
  int stage_v_52_2 = ((pub_r001066_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_39_1 + (pub_r001066_13_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_39_2 + (pub_r001066_13_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_32_1 + (pub_r001066_13_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_32_2 + (pub_r001066_13_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_38_1 + (pub_r001066_0_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_38_2 + (pub_r001066_0_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_1_1 + (pub_r001066_3_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_1_2 + (pub_r001066_3_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001066_2_1 * 2) + 21) & 63;
  int stage_v_57_2 = ((pub_r001066_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001066_15_1 * 2) + 28) & 63;
  int stage_v_58_2 = ((pub_r001066_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((helper_flow_6_1 + (pub_r001066_2_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((helper_flow_6_2 + (pub_r001066_2_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((sec_r001066_6_1 + (pub_r001066_11_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001066_6_2 + (pub_r001066_11_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_35_1 + (pub_r001066_15_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_35_2 + (pub_r001066_15_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001066_12_1 * 2) + 22) & 63;
  int stage_v_62_2 = ((pub_r001066_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001066_0_1 * 2) + 20) & 63;
  int stage_v_63_2 = ((pub_r001066_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001066_12_1 * 2) + 11) & 63;
  int stage_v_64_2 = ((pub_r001066_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001066_0_1 * 2) + 20) & 63;
  int stage_v_65_2 = ((pub_r001066_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001066_16_1 * 2) + 6) & 63;
  int stage_v_66_2 = ((pub_r001066_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001066_8_1 * 2) + 47) & 63;
  int stage_v_67_2 = ((pub_r001066_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((sec_r001066_11_1 + (pub_r001066_15_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((sec_r001066_11_2 + (pub_r001066_15_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_30_1 + (pub_r001066_15_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_30_2 + (pub_r001066_15_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_68_1 + (pub_r001066_3_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_68_2 + (pub_r001066_3_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((pub_r001066_9_1 * 2) + 41) & 63;
  int stage_v_71_2 = ((pub_r001066_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((helper_flow_3_1 + (pub_r001066_12_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((helper_flow_3_2 + (pub_r001066_12_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001066_5_1 * 2) + 16) & 63;
  int stage_v_73_2 = ((pub_r001066_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((sec_r001066_3_1 + (pub_r001066_9_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((sec_r001066_3_2 + (pub_r001066_9_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((sec_r001066_14_1 + (pub_r001066_7_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001066_14_2 + (pub_r001066_7_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_49_1 + (pub_r001066_7_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_49_2 + (pub_r001066_7_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_19_1 + (pub_r001066_15_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_19_2 + (pub_r001066_15_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_5_1 + (pub_r001066_13_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_5_2 + (pub_r001066_13_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_74_1 + (pub_r001066_0_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_74_2 + (pub_r001066_0_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((pub_r001066_17_1 * 2) + 28) & 63;
  int stage_v_80_2 = ((pub_r001066_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((helper_flow_7_1 + (pub_r001066_9_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((helper_flow_7_2 + (pub_r001066_9_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_24_1 + (pub_r001066_2_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_24_2 + (pub_r001066_2_2 * 2)) + 251) & 127;
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
  int stage_v_83_1 = ((stage_v_38_1 + (pub_r001066_11_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_38_2 + (pub_r001066_11_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((helper_flow_9_1 + (pub_r001066_2_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((helper_flow_9_2 + (pub_r001066_2_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001066_13_1 * 2) + 43) & 63;
  int stage_v_85_2 = ((pub_r001066_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((sec_r001066_1_1 + (pub_r001066_8_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((sec_r001066_1_2 + (pub_r001066_8_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((pub_r001066_11_1 * 2) + 27) & 63;
  int stage_v_87_2 = ((pub_r001066_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001066_7_1 * 2) + 16) & 63;
  int stage_v_88_2 = ((pub_r001066_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001066_7_1 * 2) + 27) & 63;
  int stage_v_89_2 = ((pub_r001066_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_0_1 + (pub_r001066_14_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_0_2 + (pub_r001066_14_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((helper_flow_4_1 + (pub_r001066_1_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((helper_flow_4_2 + (pub_r001066_1_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_68_1 + (pub_r001066_6_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_68_2 + (pub_r001066_6_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_7_1 + (pub_r001066_8_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_7_2 + (pub_r001066_8_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_0_1 + (pub_r001066_7_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_0_2 + (pub_r001066_7_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_11_1 + (pub_r001066_10_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_11_2 + (pub_r001066_10_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_19_1 + (pub_r001066_3_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_19_2 + (pub_r001066_3_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001066_4_1 * 2) + 35) & 63;
  int stage_v_97_2 = ((pub_r001066_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_82_1 + (pub_r001066_12_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_82_2 + (pub_r001066_12_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_1_1 + (pub_r001066_8_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_1_2 + (pub_r001066_8_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_99_1 + (pub_r001066_4_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_99_2 + (pub_r001066_4_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_55_1 + (pub_r001066_10_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_55_2 + (pub_r001066_10_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001066_17_1 * 2) + 40) & 63;
  int stage_v_102_2 = ((pub_r001066_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_56_1 + (pub_r001066_8_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_56_2 + (pub_r001066_8_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((helper_flow_0_1 + (pub_r001066_11_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((helper_flow_0_2 + (pub_r001066_11_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001066_12_1 * 2) + 31) & 63;
  int stage_v_105_2 = ((pub_r001066_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((helper_flow_2_1 + (pub_r001066_8_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((helper_flow_2_2 + (pub_r001066_8_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_103_1 + (pub_r001066_14_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_103_2 + (pub_r001066_14_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001066_8_1 * 2) + 9) & 63;
  int stage_v_108_2 = ((pub_r001066_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001066_12_1 * 2) + 17) & 63;
  int stage_v_109_2 = ((pub_r001066_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001066_12_1 * 2) + 25) & 63;
  int stage_v_110_2 = ((pub_r001066_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_82_1 + (pub_r001066_17_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_82_2 + (pub_r001066_17_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_18_1 + (pub_r001066_2_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_18_2 + (pub_r001066_2_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001066_16_1 * 2) + 28) & 63;
  int stage_v_113_2 = ((pub_r001066_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001066_6_1 * 2) + 26) & 63;
  int stage_v_114_2 = ((pub_r001066_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001066_4_1 * 2) + 21) & 63;
  int stage_v_115_2 = ((pub_r001066_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((helper_flow_2_1 + (pub_r001066_1_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((helper_flow_2_2 + (pub_r001066_1_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001066_5_1 * 2) + 16) & 63;
  int stage_v_117_2 = ((pub_r001066_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_15_1 + (pub_r001066_8_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_15_2 + (pub_r001066_8_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_0_1 + (pub_r001066_8_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_0_2 + (pub_r001066_8_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001066_2_1 + (pub_r001066_13_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001066_2_2 + (pub_r001066_13_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001066_4_1 * 2) + 7) & 63;
  int stage_v_121_2 = ((pub_r001066_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001066_12_1 * 2) + 36) & 63;
  int stage_v_122_2 = ((pub_r001066_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001066_1_1 * 2) + 48) & 63;
  int stage_v_123_2 = ((pub_r001066_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_60_1 + (pub_r001066_16_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_60_2 + (pub_r001066_16_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_106_1 + (pub_r001066_11_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_106_2 + (pub_r001066_11_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_38_1 + (pub_r001066_14_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_38_2 + (pub_r001066_14_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001066_1_1 * 2) + 31) & 63;
  int stage_v_127_2 = ((pub_r001066_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001066_1_1 * 2) + 22) & 63;
  int stage_v_128_2 = ((pub_r001066_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((sec_r001066_3_1 + (pub_r001066_0_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001066_3_2 + (pub_r001066_0_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001066_7_1 * 2) + 41) & 63;
  int stage_v_130_2 = ((pub_r001066_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_91_1 + (pub_r001066_11_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_91_2 + (pub_r001066_11_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_38_1 + (pub_r001066_0_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_38_2 + (pub_r001066_0_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001066_5_1 * 2) + 11) & 63;
  int stage_v_133_2 = ((pub_r001066_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_19_1 + (pub_r001066_10_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_19_2 + (pub_r001066_10_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_50_1 + (pub_r001066_17_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_50_2 + (pub_r001066_17_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_38_1 + (pub_r001066_14_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_38_2 + (pub_r001066_14_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_0_1 + (pub_r001066_6_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_0_2 + (pub_r001066_6_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_106_1 + (pub_r001066_2_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_106_2 + (pub_r001066_2_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((sec_r001066_2_1 + (pub_r001066_8_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001066_2_2 + (pub_r001066_8_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_106_1 + (pub_r001066_17_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_106_2 + (pub_r001066_17_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_100_1 + (pub_r001066_9_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_100_2 + (pub_r001066_9_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_95_1 + (pub_r001066_5_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_95_2 + (pub_r001066_5_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((sec_r001066_11_1 + (pub_r001066_5_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((sec_r001066_11_2 + (pub_r001066_5_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((sec_r001066_11_1 + (pub_r001066_6_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((sec_r001066_11_2 + (pub_r001066_6_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((sec_r001066_13_1 + (pub_r001066_17_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((sec_r001066_13_2 + (pub_r001066_17_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((sec_r001066_7_1 + (pub_r001066_7_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((sec_r001066_7_2 + (pub_r001066_7_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_78_1 + (pub_r001066_3_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_78_2 + (pub_r001066_3_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((sec_r001066_13_1 + (pub_r001066_5_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((sec_r001066_13_2 + (pub_r001066_5_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001066_8_1 * 2) + 27) & 63;
  int stage_v_149_2 = ((pub_r001066_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_79_1 + (pub_r001066_2_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_79_2 + (pub_r001066_2_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_38_1 + (pub_r001066_13_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_38_2 + (pub_r001066_13_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001066_15_1 * 2) + 25) & 63;
  int stage_v_152_2 = ((pub_r001066_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((sec_r001066_14_1 + (pub_r001066_0_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((sec_r001066_14_2 + (pub_r001066_0_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001066_9_1 * 2) + 15) & 63;
  int stage_v_154_2 = ((pub_r001066_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_7_1 + (pub_r001066_16_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_7_2 + (pub_r001066_16_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((helper_flow_5_1 + (pub_r001066_14_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((helper_flow_5_2 + (pub_r001066_14_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((helper_flow_1_1 + (pub_r001066_17_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((helper_flow_1_2 + (pub_r001066_17_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_151_1 + (pub_r001066_2_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_151_2 + (pub_r001066_2_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_135_1 + (pub_r001066_6_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_135_2 + (pub_r001066_6_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((sec_r001066_13_1 + (pub_r001066_5_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((sec_r001066_13_2 + (pub_r001066_5_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001066_4_1 * 2) + 49) & 63;
  int stage_v_161_2 = ((pub_r001066_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001066_16_1 * 2) + 36) & 63;
  int stage_v_162_2 = ((pub_r001066_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001066_9_1 * 2) + 48) & 63;
  int stage_v_163_2 = ((pub_r001066_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001066_9_1 * 2) + 18) & 63;
  int stage_v_164_2 = ((pub_r001066_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_91_1 + (pub_r001066_16_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_91_2 + (pub_r001066_16_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_159_1 + (pub_r001066_5_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_159_2 + (pub_r001066_5_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_77_1 + (pub_r001066_9_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_77_2 + (pub_r001066_9_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_33_1 + (pub_r001066_16_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_33_2 + (pub_r001066_16_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_126_1 + (pub_r001066_6_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_126_2 + (pub_r001066_6_2 * 2)) + 512) & 127;
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
  int stage_v_170_1 = ((pub_r001066_11_1 * 2) + 23) & 63;
  int stage_v_170_2 = ((pub_r001066_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001066_1_1 * 2) + 31) & 63;
  int stage_v_171_2 = ((pub_r001066_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001066_10_1 * 2) + 21) & 63;
  int stage_v_172_2 = ((pub_r001066_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001066_7_1 * 2) + 17) & 63;
  int stage_v_173_2 = ((pub_r001066_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_74_1 + (pub_r001066_2_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_74_2 + (pub_r001066_2_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_33_1 + (pub_r001066_14_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_33_2 + (pub_r001066_14_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((helper_flow_3_1 + (pub_r001066_8_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((helper_flow_3_2 + (pub_r001066_8_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_148_1 + (pub_r001066_5_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_148_2 + (pub_r001066_5_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001066_6_1 * 2) + 20) & 63;
  int stage_v_178_2 = ((pub_r001066_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001066_9_1 * 2) + 27) & 63;
  int stage_v_179_2 = ((pub_r001066_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_0_1 + (pub_r001066_15_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_0_2 + (pub_r001066_15_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001066_12_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001066_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_30_1 + (pub_r001066_9_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_30_2 + (pub_r001066_9_2 * 2)) + 551) & 127;
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
  int stage_v_183_1 = ((stage_v_167_1 + (pub_r001066_15_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_167_2 + (pub_r001066_15_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_3_1 + (pub_r001066_1_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_3_2 + (pub_r001066_1_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001066_5_1 * 2) + 38) & 63;
  int stage_v_185_2 = ((pub_r001066_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_38_1 + (pub_r001066_4_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_38_2 + (pub_r001066_4_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_112_1 + (pub_r001066_2_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_112_2 + (pub_r001066_2_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001066_12_1 * 2) + 20) & 63;
  int stage_v_188_2 = ((pub_r001066_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((sec_r001066_12_1 + (pub_r001066_6_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((sec_r001066_12_2 + (pub_r001066_6_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_174_1 + (pub_r001066_7_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_174_2 + (pub_r001066_7_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_27_1 + (pub_r001066_12_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_27_2 + (pub_r001066_12_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_134_1 + (pub_r001066_2_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_134_2 + (pub_r001066_2_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_146_1 + (pub_r001066_4_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_146_2 + (pub_r001066_4_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_134_1 + (pub_r001066_5_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_134_2 + (pub_r001066_5_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001066_5_1 * 2) + 30) & 63;
  int stage_v_195_2 = ((pub_r001066_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_31_1 + (pub_r001066_10_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_31_2 + (pub_r001066_10_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_5_1 + (pub_r001066_8_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_5_2 + (pub_r001066_8_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((sec_r001066_4_1 + (pub_r001066_16_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001066_4_2 + (pub_r001066_16_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_111_1 + (pub_r001066_12_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_111_2 + (pub_r001066_12_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_146_1 + (pub_r001066_2_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_146_2 + (pub_r001066_2_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001066_7_1 * 2) + 33) & 63;
  int stage_v_201_2 = ((pub_r001066_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_28_1 + (pub_r001066_9_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_28_2 + (pub_r001066_9_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((helper_flow_6_1 + (pub_r001066_13_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((helper_flow_6_2 + (pub_r001066_13_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_55_1 + (pub_r001066_13_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_55_2 + (pub_r001066_13_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001066_9_1 * 2) + 11) & 63;
  int stage_v_205_2 = ((pub_r001066_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((stage_v_78_1 + (pub_r001066_4_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_78_2 + (pub_r001066_4_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001066_15_1 * 2) + 19) & 63;
  int stage_v_207_2 = ((pub_r001066_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001066_0_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001066_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001066_0_1 * 2) + 49) & 63;
  int stage_v_209_2 = ((pub_r001066_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001066_9_1 * 2) + 35) & 63;
  int stage_v_210_2 = ((pub_r001066_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_90_1 + (pub_r001066_1_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_90_2 + (pub_r001066_1_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_160_1 + (pub_r001066_7_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_160_2 + (pub_r001066_7_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_165_1 + (pub_r001066_14_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_165_2 + (pub_r001066_14_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_86_1 + (pub_r001066_4_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_86_2 + (pub_r001066_4_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001066_11_1 * 2) + 43) & 63;
  int stage_v_215_2 = ((pub_r001066_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((sec_r001066_14_1 + (pub_r001066_13_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((sec_r001066_14_2 + (pub_r001066_13_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_76_1 + (pub_r001066_10_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_76_2 + (pub_r001066_10_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_132_1 + (pub_r001066_11_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_132_2 + (pub_r001066_11_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_77_1 + (pub_r001066_2_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_77_2 + (pub_r001066_2_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001066_9_1 * 2) + 27) & 63;
  int stage_v_220_2 = ((pub_r001066_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_94_1 + (pub_r001066_13_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_94_2 + (pub_r001066_13_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_5_1 + (pub_r001066_5_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_5_2 + (pub_r001066_5_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((sec_r001066_8_1 + (pub_r001066_14_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((sec_r001066_8_2 + (pub_r001066_14_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_182_1 + (pub_r001066_15_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_182_2 + (pub_r001066_15_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001066_2_1 * 2) + 24) & 63;
  int stage_v_225_2 = ((pub_r001066_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_19_1 + (pub_r001066_9_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_19_2 + (pub_r001066_9_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001066_9_1 * 2) + 40) & 63;
  int stage_v_227_2 = ((pub_r001066_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001066_16_1 * 2) + 43) & 63;
  int stage_v_228_2 = ((pub_r001066_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001066_8_1 * 2) + 29) & 63;
  int stage_v_229_2 = ((pub_r001066_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_77_1 + (pub_r001066_5_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_77_2 + (pub_r001066_5_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((pub_r001066_7_1 * 2) + 15) & 63;
  int stage_v_231_2 = ((pub_r001066_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_190_1 + (pub_r001066_4_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_190_2 + (pub_r001066_4_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((sec_r001066_7_1 + (pub_r001066_6_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((sec_r001066_7_2 + (pub_r001066_6_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001066_10_1 * 2) + 49) & 63;
  int stage_v_234_2 = ((pub_r001066_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_44_1 + (pub_r001066_6_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_44_2 + (pub_r001066_6_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001066_9_1 * 2) + 31) & 63;
  int stage_v_236_2 = ((pub_r001066_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((stage_v_70_1 + (pub_r001066_13_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_70_2 + (pub_r001066_13_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((pub_r001066_11_1 * 2) + 50) & 63;
  int stage_v_238_2 = ((pub_r001066_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_150_1 + (pub_r001066_0_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_150_2 + (pub_r001066_0_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((pub_r001066_16_1 * 2) + 14) & 63;
  int stage_v_240_2 = ((pub_r001066_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001066_12_1 * 2) + 46) & 63;
  int stage_v_241_2 = ((pub_r001066_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((sec_r001066_5_1 + (pub_r001066_8_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((sec_r001066_5_2 + (pub_r001066_8_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((stage_v_204_1 + (pub_r001066_1_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_204_2 + (pub_r001066_1_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((helper_flow_8_1 + (pub_r001066_16_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((helper_flow_8_2 + (pub_r001066_16_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((pub_r001066_14_1 * 2) + 11) & 63;
  int stage_v_245_2 = ((pub_r001066_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_33_1 + (pub_r001066_2_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_33_2 + (pub_r001066_2_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((stage_v_26_1 + (pub_r001066_6_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_26_2 + (pub_r001066_6_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((pub_r001066_5_1 * 2) + 37) & 63;
  int stage_v_248_2 = ((pub_r001066_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001066_0_1 * 2) + 12) & 63;
  int stage_v_249_2 = ((pub_r001066_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((sec_r001066_3_1 + (pub_r001066_15_1 * 2)) + 755) & 127;
  int stage_v_250_2 = ((sec_r001066_3_2 + (pub_r001066_15_2 * 2)) + 755) & 127;
  if (stage_v_250_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_250_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_250_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_250_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_251_1 = ((pub_r001066_7_1 * 2) + 22) & 63;
  int stage_v_251_2 = ((pub_r001066_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001066_7_1 * 2) + 41) & 63;
  int stage_v_252_2 = ((pub_r001066_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_175_1 + (pub_r001066_13_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((stage_v_175_2 + (pub_r001066_13_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_254_1 = ((stage_v_100_1 + (pub_r001066_10_1 * 2)) + 767) & 127;
  int stage_v_254_2 = ((stage_v_100_2 + (pub_r001066_10_2 * 2)) + 767) & 127;
  if (stage_v_254_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_254_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_254_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_254_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_255_1 = ((stage_v_120_1 + (pub_r001066_11_1 * 2)) + 770) & 127;
  int stage_v_255_2 = ((stage_v_120_2 + (pub_r001066_11_2 * 2)) + 770) & 127;
  if (stage_v_255_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_255_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_255_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_255_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_256_1 = ((stage_v_243_1 + (pub_r001066_5_1 * 2)) + 773) & 127;
  int stage_v_256_2 = ((stage_v_243_2 + (pub_r001066_5_2 * 2)) + 773) & 127;
  if (stage_v_256_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_256_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_256_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_256_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_256_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_256_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_256_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_256_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_257_1 = ((pub_r001066_15_1 * 2) + 25) & 63;
  int stage_v_257_2 = ((pub_r001066_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((stage_v_146_1 + (pub_r001066_8_1 * 2)) + 779) & 127;
  int stage_v_258_2 = ((stage_v_146_2 + (pub_r001066_8_2 * 2)) + 779) & 127;
  if (stage_v_258_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_258_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_258_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_258_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_259_1 = ((stage_v_138_1 + (pub_r001066_2_1 * 2)) + 782) & 127;
  int stage_v_259_2 = ((stage_v_138_2 + (pub_r001066_2_2 * 2)) + 782) & 127;
  if (stage_v_259_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_259_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_259_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_259_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_259_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_259_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_259_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_259_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_260_1 = ((stage_v_39_1 + (pub_r001066_15_1 * 2)) + 785) & 127;
  int stage_v_260_2 = ((stage_v_39_2 + (pub_r001066_15_2 * 2)) + 785) & 127;
  if (stage_v_260_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_260_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_260_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_260_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_260_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_260_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_260_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_260_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001066_9_1 != sec_r001066_9_2);
  __CPROVER_assume(sec_r001066_16_1 != sec_r001066_16_2);
  __CPROVER_assume(pub_r001066_16_1 == pub_r001066_16_2);
  __CPROVER_assume(sec_r001066_8_1 != sec_r001066_8_2);
  __CPROVER_assume(sec_r001066_1_1 != sec_r001066_1_2);
  __CPROVER_assume(pub_r001066_13_1 == pub_r001066_13_2);
  __CPROVER_assume(pub_r001066_14_1 == pub_r001066_14_2);
  __CPROVER_assume(sec_r001066_6_1 != sec_r001066_6_2);
  __CPROVER_assume(sec_r001066_2_1 != sec_r001066_2_2);
  __CPROVER_assume(sec_r001066_12_1 != sec_r001066_12_2);
  __CPROVER_assume(sec_r001066_13_1 != sec_r001066_13_2);
  __CPROVER_assume(pub_r001066_8_1 == pub_r001066_8_2);
  __CPROVER_assume(sec_r001066_15_1 != sec_r001066_15_2);
  __CPROVER_assume(pub_r001066_17_1 == pub_r001066_17_2);
  __CPROVER_assume(sec_r001066_4_1 != sec_r001066_4_2);
  __CPROVER_assume(sec_r001066_11_1 != sec_r001066_11_2);
  __CPROVER_assume(sec_r001066_14_1 != sec_r001066_14_2);
  __CPROVER_assume(sec_r001066_0_1 != sec_r001066_0_2);
  __CPROVER_assume(pub_r001066_6_1 == pub_r001066_6_2);
  __CPROVER_assume(pub_r001066_7_1 == pub_r001066_7_2);
  __CPROVER_assume(pub_r001066_11_1 == pub_r001066_11_2);
  __CPROVER_assume(pub_r001066_5_1 == pub_r001066_5_2);
  __CPROVER_assume(pub_r001066_0_1 == pub_r001066_0_2);
  __CPROVER_assume(pub_r001066_1_1 == pub_r001066_1_2);
  __CPROVER_assume(sec_r001066_10_1 != sec_r001066_10_2);
  __CPROVER_assume(pub_r001066_10_1 == pub_r001066_10_2);
  __CPROVER_assume(pub_r001066_4_1 == pub_r001066_4_2);
  __CPROVER_assume(sec_r001066_7_1 != sec_r001066_7_2);
  __CPROVER_assume(pub_r001066_15_1 == pub_r001066_15_2);
  __CPROVER_assume(sec_r001066_5_1 != sec_r001066_5_2);
  __CPROVER_assume(pub_r001066_3_1 == pub_r001066_3_2);
  __CPROVER_assume(sec_r001066_3_1 != sec_r001066_3_2);
  __CPROVER_assume(pub_r001066_2_1 == pub_r001066_2_2);
  __CPROVER_assume(pub_r001066_9_1 == pub_r001066_9_2);
  __CPROVER_assume(pub_r001066_12_1 == pub_r001066_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
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
}


